unit Main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  GLControl, ExtCtrls, StdCtrls;

type
  TMainForm = class(TForm)
    GLRender: TGLRender;
    GLTimer1: TGLTimer;
    procedure GLTimer1Timer(Sender: TObject; LagCount: Integer);
    procedure GLRenderClick(Sender: TObject);
    procedure GLRenderMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure GLControlRender(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure GLControlSetup(Sender: TObject);
    procedure OnCLick(Sender: TObject);
  private
    FFrame: Single;
    FColor: Array [0..2] of byte;
    MPOS  : Array [0..1] of single;
    procedure DrawSpr(const x,y,sizeW,SizeH,frame : Single;
     Symbols,
     SymbolsW,SymbolsH,
     TextureW, TextureH:Integer);
  end;

  TVec3f = record
    x,y,z:single;
  end;
  TVec2f = record
    x,y:single;
  end;

const
  ExploCount = 100-1;

var
  MainForm: TMainForm;
  Anim  : Array [0..1] of record
   ImageWidth ,
   ImageHeight,
   FrameWidth ,
   FrameHeight,
   FrameCount ,
   FrameCountX,
   GL_ID      : Integer;

  end;

  Explosions : Array [0..ExploCount] of record
   POS  : TVec3f;
   SizeW,
   SizeH  : single;
   AnimID,
   State,Count : Integer;
   Frame,
   Speed : Single;
   used  : boolean;
  end;

  FrameTime,
  LastTime  : Integer;

//----------------------------------------------------------------------------------------------------------------------

implementation

{$R *.DFM}


function Vec2f(x,y:single):TVec2f;
begin
  result.x:=x; result.y:=y;
end;

function Vec3f(x,y,z:single):TVec3f;
begin
  result.x:=x; result.y:=y; result.z:=z;
end;

procedure TMainForm.DrawSpr;
var s : Integer;
    YY,xx,
    pixelx,pixely,
    TexW,TexH   : Single;
    Vertex  : array [0..3] of TVec3f;
    TexCoord: array [0..3] of TVec2f;
begin
with glrender do
begin
  pushmatrix;
  Translate(x - SizeW *0.5, y - SizeH *0.5,0.4);

      S     := Trunc(Frame);
      TexW  := 1 / TextureW;
      TexH  := 1 / TextureH;

      pixelX:=  SymbolsW * TexW;
      pixelY:=  SymbolsH * TexH;
      xx    :=  SymbolsW * ( s mod Symbols) * TexW;
      yy    :=  SymbolsH * ( s div Symbols) * TexH;

      TexCoord[0] := vec2f(xx       ,yy);
      TexCoord[1] := vec2f(xx+pixelx,yy);
      TexCoord[2] := vec2f(xx+pixelx,yy+pixely);
      TexCoord[3] := vec2f(xx       ,yy+pixely);


        Vertex[0] := Vec3f( 0    ,     0, 0);
        Vertex[1] := Vec3f( sizeW,     0, 0);
        Vertex[2] := Vec3f( sizeW, sizeH, 0);
        Vertex[3] := Vec3f( 0    , sizeH, 0);
      DrawPoly(Length(vertex),GL_Quads,@Vertex,@TexCoord,nil);
 PopMatrix;
end;


end;


//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.GLControlRender(Sender: TObject);
  Procedure RenderA;
  var i,texid :integer;
  begin
   texid :=-1;
  with Sender as TGLRender do
      for I := 0 to high(Explosions) do
        with Explosions[i] do
        if used then
        begin

          if texid <> Anim[ animid ].GL_ID then
          begin
              BindTexture(Anim[ animid ].GL_ID,0);
                 texid := Anim[ animid ].GL_ID;
          end;
          DrawSpr( pos.x,pos.y, sizeW, sizeH, Frame, Anim[ animid ].FrameCountX,
            Anim[ animid ].FrameWidth, Anim[ animid ].FrameHeight,
            Anim[ animid ].ImageWidth, Anim[ animid ].ImageHeight);
        end;
  end;



begin
  with Sender as TGLRender do
  begin
    SetProjection( true );

      Blend(true);
      BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      RenderA;


      blend(false);


  end;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.Timer1Timer(Sender: TObject);
begin
end;

//----------------------------------------------------------------------------------------------------------------------
procedure TMainForm.OnCLick(Sender: TObject);
begin
 MessageBox(0,'','',0);
end;

procedure TMainForm.FormCreate(Sender: TObject);

begin
  GLRender.Align      := ALClient;
  GLRender.Background := clblack;
  GLRender.OnSetup    := GLControlSetup;
  GLRender.OnRender   := GLControlRender;
  Randomize;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.GLControlSetup(Sender: TObject);
var
 appdir,
 mediadir:string;
 function GetUpDir(dir:string):string;
 var i :integer;
 begin
  for i := Length(dir)-1 downto 1 do
  if dir[i] = '\' then
  begin
   result:= copy(dir,0,i);
   exit;
  end;
 end;
begin
 appdir  :=extractfilepath(paramstr(0));
 mediadir:= getupdir(appdir) + 'media\';



  // Create the base display list if not yet done.
  with TGLRender(Sender) do
  begin
    DepthTest(false);
    Anim[0].GL_ID := LoadTexture( MediaDir+'eats.jpg', true, 0,25);
    Anim[1].GL_ID := LoadTexture( MediaDir+'walk.jpg', true, 0,25);
    with Anim[0] do
    begin
      ImageWidth := 525;
      ImageHeight:= 560;
      FrameWidth := 175;
      FrameHeight:= 140;
      FrameCount := 12;
      FrameCountX:= 3;
    end;

    with Anim[1] do
    begin
      ImageWidth := 492;
      ImageHeight:= 262;
      FrameWidth := 164;
      FrameHeight:= 131;
      FrameCount := 6;
      FrameCountX:= 3;
    end;

    fcolor[0] := 255;
    fcolor[1] := 255;
    fcolor[2] := 255;
  end

end;

procedure TMainForm.GLRenderClick(Sender: TObject);
begin
          fcolor[0]:= random(127)+128;
          fcolor[1]:= random(127)+128;
          fcolor[2]:= random(127)+128;
end;

procedure TMainForm.GLRenderMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
  MPOS[0]:=x;
  MPOS[1]:=y;
end;

procedure TMainForm.GLTimer1Timer(Sender: TObject; LagCount: Integer);
var i :integer;
    s : single;

begin
    FFrame := FFrame + FrameTime *0.01;
    if FFrame > 16 then
       FFrame := 0;

  GLRender.Invalidate;
  if getasynckeystate(vk_escape) <> 0 then application.Terminate;

        for I := 0 to high(Explosions) do
        with Explosions[i] do
        if not used then
        begin

          pos := vec3f( random( clientwidth ) ,
                        random( clientheight) , 0);
          Count :=0;
          Frame:=0;
          Speed:= (Random(50) + 50) *0.1;
          AnimID:=1;// random(19) div 10;

               S:= (Random(96)+96) / 192;
                 if random(10) >5 then S:= -S;
          SizeW := Anim[AnimID].FrameWidth * S;

                 if random(10) >5 then S:= -S;
          SizeH := Anim[AnimID].FrameHeight * S;
          State := 0;
          used:=true;
        end else
        begin

          { Logic B }
          frame := frame + Speed*FrameTime*0.002;

          case State of
          0 :
               begin
              if SizeW >0 then
              pos.x:= pos.x - Speed * FrameTime *0.02 else
              pos.x:= pos.x + Speed * FrameTime *0.02;

              if pos.x-SizeW*0.5 <0 then begin
              Pos.x:=+SizeW*0.5;
                   State := 1;
                   Frame := 0;
                  end;
              if pos.x >Width+SizeW*0.5 then begin
                   Pos.x:=Width+SizeW*0.5;
                   Frame:= 0;
                   State:=1;
                  end;
               end;
          1 :
            begin
              AnimID := 0;
                if frame > Anim[ animid ].FrameCount*10 then
                Begin
                   AnimID:=1;
                   Frame :=0;
                   SizeW := -SizeW;
                   Speed := (Random(50) + 50) *0.1;
                   State := 0;

               S:= (Random(96)+96) / 192;
                 if random(10) >5 then S:= -S;
          SizeW := Anim[AnimID].FrameWidth * S;

                 if random(10) >5 then S:= -S;
          SizeH := Anim[AnimID].FrameHeight * S;
                 inc(count);
                 if count > 2 then
                   used:=false;
                end;

            end;
              Else used:=false;
          end;

        end;

  FrameTime := GLTimer1.FrameTime;
  LastTime  := GetTickCount;
  Caption := 'FPS:'+Inttostr(GLTimer1.FrameRate);
end;

//----------------------------------------------------------------------------------------------------------------------

end.

