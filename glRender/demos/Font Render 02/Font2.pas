// ---------------------
// Unit: Font2.pas
//
// Original Author: Michael Pote
// Date: 25 Jan 2003

// Mod: SVSD_VAL
// Date: 03.03.2010
// -------------------
unit Font2;

interface

Uses Classes,GLControl;

type
      FontRect = Record
                   T1,U1,T2,U2, W, H: single;
                 end;
      PGLRender =^TGLRender;

      TFontObj = Class
                 Private
                   F : array of FontRect;
                   StartChar, FontLen, CharOffset: integer;
                   TexInd: Cardinal;
                   SpaceWidth: single;
                   FGLRender : PGLRender;
                   function LoadJPGsfromStream(Filename1, Filename2: TStream; var Texture: Cardinal): Boolean;
                   function LoadJPGs(Filename1, Filename2: String; var Texture: Cardinal): Boolean;
                   Procedure DrawQuadRT(X, Y, Wid, Hgt, Lev, Tu, Tu2, Tv,Tv2: single);

                 Public
                 Property GLRender : PGLRender read FGLRender write FGLRender;
                 Procedure Load(const Path:string);
                 Procedure LoadFromStream(Fi:TStream);//Добавленно мной :) (SVSD_VAL |SVSD.MirGames.ru
                 Procedure Draw(Const X,Y,Size: single;Const Txt:string; Lev:single);
                 Function TextLen(Const Txt: string): single;
                end;
implementation

Uses Windows, JPEG, Graphics, SysUtils;

type
     TVec3f = record
      x,y,z:single;
     end;
     TVec2f = record
      x,y:single;
     end;

function Vec2f(x,y:single):TVec2f;
begin
  result.x:=x; result.y:=y;
end;

function Vec3f(x,y,z:single):TVec3f;
begin
  result.x:=x; result.y:=y; result.z:=z;
end;


function TFontObj.LoadJPGsfromStream(Filename1, Filename2: TStream; var Texture: Cardinal): Boolean;
var
  Data : Array of Byte;
  W, Width : Integer;
  H, Height : Integer;
  BMP : TBitmap;
  JPG: TJPEGImage;
  Line : PByteArray;
  //ResStream : TResourceStream;      // used for loading from resource
begin
  result :=FALSE;
  if FGLRender = nil then exit;
  JPG:=TJPEGImage.Create;

    try
      JPG.LoadFromStream(Filename1);
    except
      MessageBox(0, PChar('Error loading jpg from stream I'), PChar('BMP Unit'), MB_OK);
      Exit;
    end;

  // Create Bitmap
  BMP:=TBitmap.Create;
  BMP.pixelformat:=pf24bit;
  BMP.width:=JPG.width;
  BMP.height:=JPG.height;
  BMP.canvas.draw(0,0,JPG);        // Copy the JPEG onto the Bitmap

  Width :=BMP.Width;
  Height :=BMP.Height;
  SetLength(Data, Width*Height*4);

  For H:=0 to Height-1 do
  Begin
    Line :=BMP.scanline[Height-H-1];   // flip JPEG
    For W:=0 to Width-1 do
    Begin

      Data[(W*4)+(H*Width*4)] := Line[W*3];
      Data[(W*4)+1+(H*Width*4)] := Line[W*3+1];
      Data[(W*4)+2+(H*Width*4)] := Line[W*3+2];

    End;
  End;

    try
      JPG.LoadFromStream(Filename2);
    except
      MessageBox(0, PChar('Error loading jpg from stream II'), PChar('BMP Unit'), MB_OK);
      Exit;
    end;
  BMP.canvas.draw(0,0,JPG);        // Copy the JPEG onto the Bitmap

  For H:=0 to Height-1 do
  Begin
    Line :=BMP.scanline[Height-H-1];   // flip JPEG
    For W:=0 to Width-1 do
    Begin

      Data[(W*4)+3+(H*Width*4)] := Line[W*3];


    End;
  End;

  BMP.free;
  JPG.free;

  Texture := FGLRender.CreateTexture(Width, Height, GL_RGBA, addr(Data[0]));
  result :=TRUE;
end;


function TFontObj.LoadJPGs(Filename1, Filename2: String; var Texture: Cardinal): Boolean;
var
  Data : Array of Byte;
  W, Width : Integer;
  H, Height : Integer;
  BMP : TBitmap;
  JPG: TJPEGImage;
  Line : PByteArray;


  //ResStream : TResourceStream;      // used for loading from resource
begin
  result :=FALSE;
  if FGLRender = nil then exit;
  JPG:=TJPEGImage.Create;

    try
      JPG.LoadFromFile(Filename1);
    except
      MessageBox(0, PChar('Couldn''t load JPG - "'+ Filename1 +'"'), PChar('BMP Unit'), MB_OK);
      Exit;
    end;

  // Create Bitmap
  BMP:=TBitmap.Create;
  BMP.pixelformat:=pf24bit;
  BMP.width:=JPG.width;
  BMP.height:=JPG.height;
  BMP.canvas.draw(0,0,JPG);        // Copy the JPEG onto the Bitmap

  Width :=BMP.Width;
  Height :=BMP.Height;
  SetLength(Data, Width*Height*4);

  For H:=0 to Height-1 do
  Begin
    Line :=BMP.scanline[Height-H-1];   // flip JPEG
    For W:=0 to Width-1 do
    Begin

      Data[(W*4)+(H*Width*4)] := Line[W*3];
      Data[(W*4)+1+(H*Width*4)] := Line[W*3+1];
      Data[(W*4)+2+(H*Width*4)] := Line[W*3+2];

    End;
  End;

    try
      JPG.LoadFromFile(Filename2);
    except
      MessageBox(0, PChar('Couldn''t load JPG - "'+ Filename2 +'"'), PChar('BMP Unit'), MB_OK);
      Exit;
    end;
  BMP.canvas.draw(0,0,JPG);        // Copy the JPEG onto the Bitmap

  For H:=0 to Height-1 do
  Begin
    Line :=BMP.scanline[Height-H-1];   // flip JPEG
    For W:=0 to Width-1 do
    Begin

      Data[(W*4)+3+(H*Width*4)] := Line[W*3];


    End;
  End;

  BMP.free;
  JPG.free;

  Texture :=FGLRender.CreateTexture(Width, Height, GL_RGBA, addr(Data[0]));
  result :=TRUE;
end;


Procedure TFontObj.DrawQuadRT(X, Y, Wid, Hgt, Lev, Tu, Tu2, Tv,Tv2: single);
var
  Vertex   :Array [0..3] of TVec3f;
  TexCoord :Array [0..3] of TVec2f;
begin
  if FGLRender = nil then exit;
  Tv := 1-Tv;
  Tv2 := 1-Tv2;
  Vertex[0] := Vec3f(X,     Y, -lev);
  Vertex[1] := Vec3f(X+wid, Y, -lev);
  Vertex[2] := Vec3f(X+wid, Y-hgt, -lev);
  Vertex[3] := Vec3f(X,     Y-hgt, -lev);
  TexCoord[3] := vec2f(Tu , Tv);
  TexCoord[2] := vec2f(Tu2, Tv);
  TexCoord[1] := vec2f(Tu2, Tv2);
  TexCoord[0] := vec2f(Tu , Tv2);
  FGLRender.DrawPoly(2,GL_Polygon,@Vertex[0],@TexCoord[0],nil);
end;

Procedure TFontObj.Load(Const Path:string);
Var Fi, F2: TfileStream;
    I, Data: integer;
    StPos, CtPos: longint;
    Other: string;
begin
  Setlength(F, 1);
  FontLen := 0;
  if Not FileExists(Path) then
  begin
     MessageBox(0, pchar(Path + ' was not found.'), 'Missing File', MB_OK or MB_ICONERROR);
     exit;
  end;
  SpaceWidth := 5;
  Other := Copy(Path, 1, length(Path)-3)+'jpg';
  Fi := TFileStream.Create(Path, $0000);
  F2 := Tfilestream.Create(Other, FmCreate or $0000);
  Fi.Seek(-(sizeof(longint)*2), soFromEnd);
  Fi.Read(Ctpos, sizeof(longint));
  Fi.Read(Stpos, sizeof(longint));
  Fi.Seek(Ctpos, soFromBeginning);
  F2.CopyFrom(Fi, StPos-CtPos-1);
  F2.Free;

  Fi.Seek(Stpos, soFromBeginning);

  Fi.Read(Data, Sizeof(integer));
  FontLen := Data;
  Fi.Read(Data, Sizeof(integer));
  StartChar := Data;
  Fi.Read(Data, Sizeof(integer));
  CharOffset := Data;

  Setlength(F, FontLen+1);
  For I := 0 to high(F) do
   begin
     Fi.Read(F[I], sizeof(FontRect));
   end;
  Fi.Free;
  LoadJpgs(Path, Other, TexInd);
  DeleteFile(Other);
end;

Procedure TFontObj.LoadFromStream(Fi:TStream);
Var F2: TMemoryStream;
    I, Data: integer;
    StPos, CtPos: longint;
begin
  Setlength(F, 1);
  FontLen := 0;
  SpaceWidth := 5;

  F2 := TMemoryStream.Create;
  Fi.Seek(-(sizeof(longint)*2), soFromEnd);
  Fi.Read(Ctpos, sizeof(longint));
  Fi.Read(Stpos, sizeof(longint));
  Fi.Seek(Ctpos, soFromBeginning);
  F2.CopyFrom(Fi, StPos-CtPos-1);

  Fi.Seek(Stpos, soFromBeginning);

  Fi.Read(Data, Sizeof(integer));
  FontLen := Data;
  Fi.Read(Data, Sizeof(integer));
  StartChar := Data;
  Fi.Read(Data, Sizeof(integer));
  CharOffset := Data;

  f2.SetSize (StPos-CtPos-1);


  Setlength(F, FontLen+1);
  For I := 0 to high(F) do
   begin
     Fi.Read(F[I], sizeof(FontRect));
   end;

  fi.Seek(0,soFromBeginning);
  f2.Seek(0,soFromBeginning);

  LoadJpgsfromstream(fi, f2, TexInd);
  Fi.Free;
  F2.Free;
end;


Function TFontObj.TextLen(Const Txt:string): single;
Var I, Let: integer;
    Len: single;
begin
   Len := 0;
   For I := 0 to length(Txt) do
   begin
      Let := Ord(Txt[I])-StartChar;
      if (Let <> -1) then
      begin
       Len := Len + F[Let].W+1-CharOffset;
      end
      else
      Len := Len + SpaceWidth;
   end;
   Result := Len;
end;

Procedure TFontObj.Draw(Const X,Y,size: single;Const Txt:string; Lev:single);
Var I, Let: integer;
    Xx: Single;
begin
  if txt = '' then exit;
  if FGLRender = nil then exit;
  Xx := X;
  glRender.Blend(true);
  glRender.BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glRender.BindTexture(TexInd,0);
  For I := 1 to length(Txt) do
  begin
     Let := Ord(Txt[I])-StartChar;
     if (Let <> -1) and not (let > FontLen) then
     begin
      DrawQuadRT(Xx,Y, {F[Let].W+1.25}Size,F[Let].H+1.25,Lev,
      F[Let].T1,F[Let].T2+0.005,

      F[Let].U1,
      F[Let].U2+0.005);
      Xx := Xx + Size*0.73{F[Let].W+1.25}{-CharOffset};
     end
     else
     Xx := Xx + Size*0.73;///SpaceWidth;
  end;
  glRender.Blend(false);
  glRender.unbindTexture(0);
end;

end.
