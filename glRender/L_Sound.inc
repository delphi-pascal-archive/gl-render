{unit l_sound;
interface
uses
 Windows , DirectSound9, mmSystem, L_Math, SysUTils;
 }

 {$include DirectSound9.inc}

type
 // Элемент массива звуков
 PSample = ^TSample;
 TSample = record
  ID       : integer;
  Next     : PSample;
  flag     : boolean;
  FileName : string;
  buffer   : IDirectSoundBuffer;
 end;

 TChannel = record
  Smp_ID   : integer;
  Time     : DWORD;
  Pos      : TVec3f;
  MuteDist : Array [0..1] of single;
  Buffer   : IDirectSoundBuffer;
  Buffer3D : IDirectSound3DBuffer;
  Pos2GPOS : boolean;
 end;

 TDXSound = Class
  Private
   initialized : boolean;
   Samples     : integer;
   Channels    : integer;
   Playing     : integer;
   off         : boolean;
   h_Wnd           : HWND;

  FDistanceFactor,//... Коэффициент растояния
  FDopplerFactor,//.... Фактор Допплера
  FRolloffFactor: Single;//.... Фактор удаления
  FTop,
  FOrientation,//...... Ориентация слушателя
  FPosition,//......... Позиция слушателя
  FVelocity:TVec3f;//......... Скорость слушателя

   // Главный интерфейс устройства
   ids   : IDirectSound;
   // Первичный буфер
   idsbp : IDirectSoundBuffer;
   // слушатель
   idsl  : IDirectSound3DListener;

   // Максимальное кол-во каналов
   MaxChannels : integer;
   // Массив
   Sample  : PSample;
   Channel : array of TChannel;
   nID     : integer;
   function  GetSample            (ID: integer): PSample;
   function  ChannelExists    (Channel_ID: integer): boolean;
   function  LoadFromWAV          (Sample: PSample; FileName: string): boolean;
//   function  LoadFromStream       (Sample: PSample; Stream: TStream): boolean;
  Public
   function  Init(WND:HWND): boolean;                                                    
   procedure deInit;                                                                     
   function  Load             (const FileName: string): integer;                         
//   function  LoadFromStream   (Stream:TStream): integer;
   function  Free             (Sample_ID: integer): boolean;
   procedure BeginUpdate;
   procedure EndUpdate;
   function  Play             (Sample_ID: integer; Loop: boolean; Pos: TVec3f): integer;
   function  Stop             (var Channel_ID: integer): boolean;
   procedure StopAll          (Sound_ID: integer);
   function  SetVolume        (Channel_ID: integer; Volume: integer): boolean;
   function  SetPos           (Channel_ID: integer; Pos: TVec3f): boolean;
   procedure SetPos2GlobalPos (Channel_ID: integer; Accept:boolean);
   function  SetMuteDist      (Channel_ID: integer; MinDist, MaxDist:Single) : boolean;
   function  SetFreq          (Channel_ID: integer; Freq: DWORD): boolean;
   procedure SetVelocity      (Channel_ID: integer; Pos: TVec3f);
   procedure SetOrientation   (front, top: TVec3f);
   procedure SetDopplerFactor (factor: single);
   procedure SetRolloffFactor (factor: single);
   procedure SetDistanceFactor(Dst   : single);
   procedure SetGlobalPos     (Pos: TVec3f);
   procedure SetGlobalVelocity(V: TVec3f);
   procedure Update;
//   Procedure setcam           (POS, Rotate:TVec3f);
end;

//implementation


function TDXSound.GetSample(ID: integer): PSample;
var
 p : PSample;
begin
p := Sample;
while p <> nil do
 if p^.ID = ID then
  break
 else
  p := p^.Next;
Result := p;
end;

function TDXSound.ChannelExists(Channel_ID: integer): boolean;
begin
if (not initialized) or
   (Channel_ID < 0) or
   (Channel_ID >= MaxChannels) or
   (Channel[Channel_ID].Buffer = nil) then
 Result := false
else
 Result := true;
end;

//// Загрузка из *.wav файла ///////////////////////////
function TDXSound.LoadFromWAV(Sample: PSample; FileName: string): boolean;
var
 F : File;
 a : array [1..4] of Char;

 audio1, audio2 : Pointer;
 audiosize1, audiosize2 : DWORD;
 hr : HResult;

 bufferdesc   : TDSBufferDesc;
 waveformat   : TWaveFormatEx;
 wavedatasize : Longint;
begin
Result := false;

if not FileExists(FileName) then Exit;
// открываем файл проверяем на RIFF заголовок
AssignFile(F, FileName);
Reset(F, 1);
BlockRead(F, a, 4);
if a <> 'RIFF' then
 begin
 CloseFile(F);
 Exit;
 end;

// skip some RIFF header data
Seek(F, 8);

// check next chunk in file to be a WAVE file
BlockRead(F, a, 4);
if a <> 'WAVE' then
 begin
 CloseFile(F);
 Exit;
 end;
Seek(F, 20);

// read in some properties of the wave data in the file
with waveformat do
 begin
 // skip first bytes of WAVE header
 BlockRead(F, waveformat, SizeOf(waveformat));
 nBlockAlign     := wBitsPerSample div 8 * nChannels;
 nAvgBytesPerSec := nSamplesPerSec * nBlockAlign;
 end;

// Таких форматов не понимаем :)
if waveformat.wBitsPerSample < 8 then
 begin
 CloseFile(F);
 Exit;
 end;

While AnsiUpperCase(a) <> 'DATA' do  //Вот что изменил (ошибка была втом что сик делался на 40 а у меня 52... пусть сам ищит какой сик делать надо)
begin
Seek(F,filepos(f)-3 );
BlockRead(F, a, 4);
end;


// читаем размер данных звука
BlockRead(F, wavedatasize, 4);

// заполняем информацию о буфере
FillChar(bufferdesc, SizeOf(bufferdesc), 0);
with bufferdesc do
 begin
 Size := sizeof(bufferdesc);
 Flags :=

// DSBCAPS_CTRL3D or DSBCAPS_GLOBALFOCUS OR DSBCAPS_CTRLFREQUENCY OR DSBCAPS_GETCURRENTPOSITION2 OR DSBCAPS_CTRLVOLUME;
 DSBCAPS_CTRL3D or DSBCAPS_CTRLVOLUME or DSBCAPS_MUTE3DATMAXDISTANCE;
 {DSBCAPS_STATIC};

 BufferBytes := wavedatasize;
 WaveFormatEx := @waveformat;
 end;

// создаём буфер по той информации :)
hr := ids.CreateSoundBuffer(bufferdesc, Sample^.buffer, nil);
if hr < DS_OK then
 begin
 CloseFile(F);
 Exit;
 end;
audio2     := nil;
audiosize2 := 0;
// блокируем
hr := Sample^.buffer.Lock(0, 0,
                          audio1,
                          audiosize1,
                          audio2,
                          audiosize2,
                          DSBLOCK_ENTIREBUFFER);
if hr < DS_OK then
 begin
 CloseFile(F);
 Exit;
 end;

// заполняем
BlockRead(F, audio1^, wavedatasize);
CloseFile(F);

// разблокируем
if Sample^.buffer.Unlock(audio1, audiosize1, audio2, audiosize2) < DS_OK then
 Exit;

Result := true;
end;
////////////////////////////////////////////////////////
// Загрузка с потока Добавленно мной :) "SVSD.MirGames.ru"
//// Загрузка из *.wav файла ///////////////////////////
{
function TDXSound.LoadFromStream(Sample: PSample; Stream: TStream): boolean;
var
 a : array [1..4] of Char;

 audio1, audio2 : Pointer;
 audiosize1, audiosize2 : DWORD;
 hr : HResult;

 bufferdesc   : TDSBufferDesc;
 waveformat   : TWaveFormatEx;
 wavedatasize : Longint;
begin
Result := false;
Logwrite('Загрузка звука с потока',0);
if stream = nil then exit;
// открываем файл проверяем на RIFF заголовок
Stream.Read(a, 4);
if a <> 'RIFF' then begin logwrite('Не .Wav файл или не PCM кодек',2); exit;end;


// skip some RIFF header data
Stream.Seek(8,soFromBeginning);

// check next chunk in file to be a WAVE file
Stream.Read(a, 4);
if a <> 'WAVE' then begin logwrite('Не .Wav файл или не PCM кодек',2); Exit;end;
Stream.Seek(20,soFromBeginning);

// read in some properties of the wave data in the file
with waveformat do
 begin
 // skip first bytes of WAVE header
 Stream.Read(waveformat, SizeOf(waveformat));
 nBlockAlign     := wBitsPerSample div 8 * nChannels;
 nAvgBytesPerSec := nSamplesPerSec * nBlockAlign;
 end;

// Таких форматов не понимаем :)
if waveformat.wBitsPerSample < 8 then Exit;

While AnsiUpperCase(a) <> 'DATA' do  //Вот что изменил (ошибка была втом что сик делался на 40 а у меня 52... пусть сам ищит какой сик делать надо)
begin
Stream.Seek(Stream.Position-3,soFromBeginning);
Stream.Read(a, 4);
end;


// читаем размер данных звука
Stream.Read(wavedatasize, 4);

// заполняем информацию о буфере
FillChar(bufferdesc, SizeOf(bufferdesc), 0);
with bufferdesc do
 begin
 dwSize := sizeof(bufferdesc);
 dwFlags := DSBCAPS_STATIC or
            //DSBCAPS_GLOBALFOCUS or
//            DSBCAPS_CTRLVOLUME or
            DSBCAPS_CTRL3D or
            DSBCAPS_CTRLFREQUENCY;
 dwBufferBytes := wavedatasize;
 lpwfxFormat   := @waveformat;
 end;

// создаём буфер по той информации :)
hr := ids.CreateSoundBuffer(bufferdesc, Sample^.buffer, nil);
if hr < DS_OK then Exit;
audio2     := nil;
audiosize2 := 0;
// блокируем
hr := Sample^.buffer.Lock(0, 0,
                          audio1,
                          audiosize1,
                          audio2,
                          audiosize2,
                          DSBLOCK_ENTIREBUFFER);
if hr < DS_OK then Exit;

// заполняем
Stream.Read(audio1^, wavedatasize);

// разблокируем
if Sample^.buffer.Unlock(audio1, audiosize1, audio2, audiosize2) < DS_OK then
 Exit;

Result := true;
end;
////////////////////////////////////////////////////////
{}


///////// ИНИЦИАЛИЗАЦИЯ //////////
function TDXSound.Init(WND:HWND): boolean;
var
 dsbufferdesc : TDSBufferDesc;
// waveformat   : TWaveFormatEx;
begin
Result := false;
if initialized then Exit;
initialized := false;

H_WND := WND;
{// создание первичного буфера
if DirectSoundCreate(nil, ids, nil) <> DS_OK then
 Exit;

FDistanceFactor:=1;
volume:=255;
ids.SetCooperativeLevel(h_Wnd, DSSCL_EXCLUSIVE);
//ids.SpeakerConfig(
FillChar(dsbufferdesc, sizeof(dsbufferdesc), 0);
with dsbufferdesc do
 begin
 Size         := sizeof(dsbufferdesc);
 Flags        := DSBCAPS_CTRL3D or DSBCAPS_PRIMARYBUFFER or DSBCAPS_LOCSOFTWARE;
 BufferBytes  := 0;
 Reserved     := 0;
 WaveFormatEx := nil;
 end;

if ids.CreateSoundBuffer(dsbufferdesc, idsbp, nil) <> DS_OK then
 Exit;

// установка выходного формата
with waveformat do
 begin
 wFormatTag      := WAVE_FORMAT_PCM;
 nChannels       := 2;
 nSamplesPerSec  := 44100;
 wBitsPerSample  := 16;
 nBlockAlign     := 2;
 nAvgBytesPerSec := nSamplesPerSec * nBlockAlign;
 end;


 if idsbp.Play(0, 0, DSBPLAY_LOOPING) <> DS_OK then
 Exit;

if idsbp.QueryInterface(IID_IDirectSound3DListener,
                        idsl) = DS_OK then
 begin
 idsl.SetDistanceFactor(1, DS3D_DEFERRED);
 idsl.SetRolloffFactor (1/1024, DS3D_DEFERRED);
 idsl.SetOrientation   (0, 1, 0, 0, 0, 1, DS3D_DEFERRED);



 idsl.CommitDeferredSettings;

 end;
 }

 DirectSoundCreate(nil,IDS,nil);                  //создаем главный интерфейс
 IDS.SetCooperativeLevel(h_wnd,DSSCL_EXCLUSIVE); //устанавливаем уровень кооперации
 IDS.SetSpeakerConfig(DSSPEAKER_STEREO);          //задаем тип колонок
 // Primary buffer
 dsbufferdesc.Size         := sizeOf( dsbufferdesc );
 dsbufferdesc.Flags        := DSBCAPS_CTRL3D or DSBCAPS_PRIMARYBUFFER; //поддержка 3d и перв буффер
 dsbufferdesc.BufferBytes  := 0;
 dsbufferdesc.Reserved     := 0;
 dsbufferdesc.WaveFormatEx := nil;
 IDS.CreateSoundBuffer(dsbufferdesc,IDSBP,nil); //создаем первичный буффер
 // Listener
 IDSBP.QueryInterface(IID_IDIRECTSOUND3DLISTENER,IDSL); //создаем для него слушателя
 IDSl.SetRolloffFactor(4,DS3D_DEFERRED);   //Моё ИМХО считает, эти параметры надо подобрать сразу,
 IDSL.SetDistanceFactor(1,DS3D_DEFERRED);  //и не менять по ходу пьесы
 IDSL.CommitDeferredSettings;              //Выполнить отложенные настройки


Sample := nil;
nID    := 0;

Samples := 0;
MaxChannels := 127;
SetLength(Channel, MaxChannels);

Result := true;
initialized := true;
end;

procedure TDXSound.deInit;
var
 i : integer;
 p : PSample;
begin
for i := 0 to MaxChannels - 1 do
 begin
 Channel[i].Buffer   := nil;
 Channel[i].Buffer3D := nil;
 Channel[i].Smp_ID   := -1;
 end;

p := Sample;
while p <> nil do
 begin
 p^.buffer := nil;
 p         := p^.Next;
 end;

Samples := 0;
Sample := nil;
idsbp  := nil;
//ids    := nil;
end;

function TDXSound.Free(Sample_ID: integer): boolean;
var
 tmp, p : PSample;
 i      : integer;
begin
Result := false;
if not initialized then Exit;

tmp := GetSample(Sample_ID);
if tmp = nil then
 Exit;

for i := 0 to MaxChannels - 1 do
 if Channel[i].Smp_ID = tmp^.ID then
  with Channel[i] do
   begin
   if Buffer <> nil then
    Buffer.Stop;
   Buffer   := nil;
   Buffer3D := nil;
   Smp_ID   := -1;
   end;
tmp^.buffer := nil;

if tmp^.Next <> nil then
 tmp^ := tmp^.Next^
else
 begin
 p := Sample;
 if tmp = p then
  Sample := nil
 else
  while p <> nil do
   if p^.Next = tmp then
    begin
    p^.Next := nil;
    break;
    end
   else
    p := p^.Next;
 end;

dec(Samples);

Result := true;
end;

// Функция, возврящает идентификатор звука
function TDXSound.Load(const FileName: string): integer;
var
 tmpSample : PSample;
 p         : PSample;
 str       : string;
begin
Result := -1;
if not initialized then Exit;

str := FileName;
p := Sample;
while p <> nil do
 if p^.FileName = str then
  begin
  p^.flag := false;
  Result  := p^.ID;
  Exit;
  end
 else
  p := p^.Next;

New(tmpSample);
tmpSample^.FileName := str;
 try
  if LoadFromWAV(tmpSample, str) then
   begin
   inc(nID);

   tmpSample^.Next := Sample;
   tmpSample^.ID   := nID;
   tmpSample^.flag := false;

   Sample := tmpSample;

   inc(Samples);
   Result := nID;
   end
 except
 end;

if Result = -1 then
 Dispose(tmpSample);
end;
{
// Функция, возврящает идентификатор звука
function TDXSound.LoadFromStream(Stream:TStream): integer;
var
 tmpSample : PSample;
begin
Result := -1;
if not initialized then Exit;

New(tmpSample);
tmpSample^.FileName := 'Stream Sample';
 try
  if LoadFromStream(tmpSample, Stream) then
   begin
   inc(nID);

   tmpSample^.Next := Sample;
   tmpSample^.ID   := nID;
   tmpSample^.flag := false;

   Sample := tmpSample;

   inc(Samples);
   Result := nID;
   end
 except
 end;

if Result = -1 then
 Dispose(tmpSample);
end;
}

procedure TDXSound.BeginUpdate;
var
 p : PSample;
begin
p := Sample;
while p <> nil do
 begin
 p^.flag := true;
 p       := p^.Next;
 end;
end;

procedure TDXSound.EndUpdate;
var
 p : PSample;
 b : boolean;
begin
p := Sample;
while p <> nil do
 if p^.flag then
  begin
  b := p^.Next = nil;
  Free(p^.ID);
  if b then break;
  end
 else
  p := p^.Next;
end;

// Проигрывает звук с ID и возвращает номер канала //
function TDXSound.Play(Sample_ID: integer; Loop: boolean; Pos: TVec3f): integer;
var
 i      : integer;
 tmp    : PSample;
 Status : DWORD;

 function Play(i: integer): integer;
 var
  hr : HResult;
 begin

 Channel[i].Pos := Pos;
 Channel[i].Pos2GPOS := false;
// ids.SetCooperativeLevel(h_Wnd  , DSSCL_NORMAL);
 if Loop then
  hr := Channel[i].Buffer.Play(0, 0, DSBPLAY_LOOPING)
 else
  hr := Channel[i].Buffer.Play(0, 0, 0);
 if hr <> DS_OK then
  Result := -1
 else
  begin
  Channel[i].Time := GetTickCount;
  Result := i;
  end;

   Channel[i].buffer3D.SetPosition   (Pos.X, Pos.Y, Pos.Z, DS3D_DEFERRED);

 end;

 function Copy(i: integer): boolean;
 begin
 Result := false;
 Channel[i].Smp_ID := Sample_ID;
 // Самая тормознутая функция всей процедуры
 ids.DuplicateSoundBuffer(tmp.buffer, Channel[i].Buffer);


 if Channel[i].buffer.QueryInterface(IID_IDirectSound3DBuffer,
                                     Channel[i].buffer3D) <> DS_OK then
  begin
  Channel[i].Buffer.Restore;
  Channel[i].buffer   := nil;
  Channel[i].Buffer3D := nil;
  Exit;
  end;
 Result := true;
 end;

begin
Result := -1;
if off then Exit;
if not initialized then Exit;

tmp := GetSample(Sample_ID); // ищем сэмпл
if tmp = nil then Exit;      // нет такого

// Вдруг существует остановленный канал для этого звука
for i := 0 to MaxChannels - 1 do
 if (Channel[i].Buffer <> nil) and
    (Sample_ID = Channel[i].Smp_ID) then
  begin
  if (Channel[i].Buffer.GetStatus(Status) = DS_OK) and
     (Status and DSBSTATUS_PLAYING = 0) then
   begin
   Result := Play(i);
   Exit;
   end;
  end;

// Ну что ж придётся буфер выделять...
for i := 0 to MaxChannels - 1 do
 if Channel[i].Buffer = nil then
  begin
  if Copy(i) then
   Result := Play(i);
  Exit;
  end;

// Нет места, придётся мертвецов не нужных убирать
for i := 0 to MaxChannels - 1 do
 // Ищем мёртвый канал
 if Channel[i].Buffer <> nil then
  begin
  if not((Channel[i].Buffer.GetStatus(Status) = DS_OK) and
         (Status and DSBSTATUS_PLAYING <> 0)) then
   begin
   Channel[i].Buffer.Restore;
   Channel[i].Buffer   := nil;
   Channel[i].Buffer3D := nil;
   end
  else
   continue;

  if Copy(i) then
   Result := Play(i);
  Exit;
  end;
end;

function TDXSound.Stop(var Channel_ID: integer): boolean;
begin
Result := false;
if not ChannelExists(Channel_ID) then Exit;
Result := Channel[Channel_ID].Buffer.Stop = DS_OK;
Channel[Channel_ID].Buffer.SetCurrentPosition(0);
Channel[Channel_ID].Pos2GPos := false;
Channel_ID := -1;
end;

procedure TDXSound.StopAll(Sound_ID: integer);
var
 i : integer;
begin
if not initialized then Exit;
// Остановить проигрывание всех звуков
if Sound_ID <= 0 then
 begin
 for i := 0 to MaxChannels - 1 do
  if Channel[i].Buffer <> nil then
      begin
         Channel[i].Buffer.Stop;
         Channel[i].Pos2GPos := false;
      end;
 end
else
 // Остановить каналы этого Sound_ID
 for i := 0 to MaxChannels - 1 do
  if (Channel[i].Buffer <> nil) and
     (Channel[i].Smp_ID = Sound_ID) then
     begin
       Channel[i].Buffer.Stop;
       Channel[i].Pos2GPos := false;
     end;
end;

function TDXSound.SetVolume(Channel_ID: integer; Volume: integer): boolean;
begin
Result := false;
if off then Exit;
if not ChannelExists(Channel_ID) then Exit;
Volume := - 50 * (100 - Volume);
Result :=  Channel[Channel_ID].buffer.SetVolume(Volume) = DS_OK;
end;

function TDXSound.SetPos(Channel_ID: integer; Pos: TVec3f): boolean;
begin
Result := false;
if off then Exit;
if not ChannelExists(Channel_ID) then Exit;
          Channel[Channel_ID].Pos := Pos;
Result := Channel[Channel_ID].buffer3D.SetPosition(Pos.X, Pos.Y, Pos.Z, DS3D_DEFERRED) = DS_OK;
end;

function  TDXSound.SetMuteDist      (Channel_ID: integer; MinDist, MaxDist:Single) : boolean;
begin
  Result := false;
if off then Exit;
if not ChannelExists(Channel_ID) then Exit;
             Channel[Channel_ID].MuteDist[0] := MinDist;
             Channel[Channel_ID].MuteDist[1] := MaxDist;

  Result := true;
  Channel[Channel_ID].buffer3D.SetMinDistance(MinDist ,DS3D_DEFERRED);
  Channel[Channel_ID].buffer3D.SetMaxDistance(MaxDist ,DS3D_DEFERRED);

end;

function TDXSound.SetFreq(Channel_ID: integer; Freq: DWORD): boolean;
begin
Result := false;
if off then Exit;
if not ChannelExists(Channel_ID) then Exit;
Result := Channel[Channel_ID].buffer.SetFrequency(Freq) = DS_OK;
end;

procedure TDXSound.SetVelocity(Channel_ID: integer; Pos: TVec3f);
begin
if off then Exit;
if not ChannelExists(Channel_ID) then Exit;
Channel[Channel_ID].Buffer3D.SetVelocity(Pos.X, Pos.Y, Pos.Z, DS3D_DEFERRED);
end;

procedure TDXSound.SetPos2GlobalPos (Channel_ID: integer; Accept:boolean);
begin
if off then Exit;
if not ChannelExists(Channel_ID) then Exit;
Channel[Channel_ID].Pos2GPOS := Accept;
 if Accept then
    SetPos(Channel_ID, FPosition);
end;

procedure TDXSound.SetGlobalPos(Pos: TVec3f);
begin
if off then Exit;
if not initialized then Exit;
if idsl <> nil then
 idsl.SetPosition(Pos.X, Pos.Y, Pos.Z, DS3D_DEFERRED);
 FPosition:=Pos;
end;

//Скорость передвижения ушей
procedure TDXSound.SetGlobalVelocity(V: TVec3f);
begin
if off then Exit;
if not initialized then Exit;
if idsl <> nil then
 idsl.SetVelocity(V.X, V.Y, V.Z, DS3D_DEFERRED);
 FVelocity:=V;
end;

procedure TDXSound.SetOrientation(front, top: TVec3f);
begin
if off then Exit;
if not initialized then Exit;
if idsl <> nil then
 idsl.SetOrientation(front.X, front.Y, front.Z,
                     top.X, top.Y, top.Z,
                     DS3D_DEFERRED);
 FOrientation :=Front;
 FTop := top;
end;

procedure TDXSound.SetDopplerFactor(factor: single);
begin
if off then Exit;
if not initialized then Exit;
if idsl <> nil then
 idsl.SetDopplerFactor(factor, DS3D_DEFERRED);
 FDopplerFactor:= factor;
end;

procedure TDXSound.SetRolloffFactor(factor: single);
begin
if off then Exit;
if not initialized then Exit;
if idsl <> nil then
 idsl.SetRolloffFactor(factor, DS3D_DEFERRED);
 FRolloffFactor:=factor;
end;

procedure TDXSound.SetDistanceFactor(Dst   : single);
begin
FDistanceFactor := dst;
end;

procedure TDXSound.Update;
var
 i      : integer;
 Status : DWORD;
 t      : DWORD;
begin
if not initialized then Exit;
// idsl = nil then
Channels := 0;
Playing  := 0;

t := GetTickCount;
for i := 0 to MaxChannels - 1 do
 if Channel[i].Buffer <> nil then
  if (Channel[i].Buffer.GetStatus(Status) = DS_OK) and
     (status and DSBSTATUS_PLAYING <> 0) then
   begin
   if Channel[i].Pos2GPos then
      SetPos(i, FPosition) else
      SetPos(i, Channel[i].Pos); // не знаю почему, но иногда позиция сбивается :)

   inc(Playing);
   inc(Channels);
   end
  else
   if t - Channel[i].Time > 3000 then
    begin
    Channel[i].Buffer.Restore;
    Channel[i].buffer   := nil;
    Channel[i].Buffer3D := nil;
    Channel[i].Pos2GPos := false;
    end
   else
    inc(Channels);

 if idsbp.QueryInterface(IID_IDirectSound3DListener, idsl) = DS_OK then
  begin
  idsl.SetDopplerFactor (FDopplerFactor , DS3D_DEFERRED);
  idsl.SetDistanceFactor(FDistanceFactor, DS3D_DEFERRED);
  idsl.SetRolloffFactor (FRolloffFactor , DS3D_DEFERRED);
  idsl.SetOrientation   (FOrientation.x, FOrientation.y, FOrientation.Z, FTop.x, FTop.y, FTop.Z, DS3D_DEFERRED);
  idsl.SetPosition      (FPosition.X, FPosition.Y, FPosition.Z, DS3D_DEFERRED);


  idsl.CommitDeferredSettings;
  end;

end;



//end.


