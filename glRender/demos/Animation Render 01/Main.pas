unit Main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  GLControl, ExtCtrls, StdCtrls;

type
  TMainForm = class(TForm)
    Timer1: TTimer;
    GLRender: TGLRender;
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
    procedure DrawStr(const x,y,size,frame : Single);
  end;

  TVec3f = record
    x,y,z:single;
  end;
  TVec2f = record
    x,y:single;
  end;

const
  ExploCount = 480-1;

var
  MainForm: TMainForm;
  Explo1,
  Explo2 : Integer;

  Explosions : Array [0..ExploCount] of record
   POS  : TVec3f;
   Size : Integer;
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

procedure TMainForm.DrawStr(const x,y,size,frame : Single);
var s : Integer;
    YY,xx,
    pixel   : Single;
    Vertex  : array [0..3] of TVec3f;
    TexCoord: array [0..3] of TVec2f;

    const
     Symbols     = 4;
     SymbolsSize = 128;
     TextureSize = 1 / 512;

begin
with glrender do
begin
  pushmatrix;
  Translate(x - Size *0.5, y - Size *0.5,0.4);

      S     := Trunc(Frame);
      pixel :=  SymbolsSize * TextureSize;
      xx    :=  SymbolsSize * ( s mod Symbols) * TextureSize;
      yy    := SymbolsSize * ( s div Symbols) * TextureSize;

      TexCoord[0] := vec2f(xx      ,yy);
      TexCoord[1] := vec2f(xx+pixel,yy);
      TexCoord[2] := vec2f(xx+pixel,yy+pixel);
      TexCoord[3] := vec2f(xx      ,yy+pixel);
        Vertex[0] := Vec3f( 0   ,    0, 0);
        Vertex[1] := Vec3f( size,    0, 0);
        Vertex[2] := Vec3f( size, size, 0);
        Vertex[3] := Vec3f( 0   , size, 0);
      DrawPoly(2,GL_Polygon,@Vertex,@TexCoord,nil);
 PopMatrix;
end;


end;


//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.GLControlRender(Sender: TObject);
var i :integer;
begin
  with Sender as TGLRender do
  begin
    SetProjection( true );

      Blend(true);
      BlendFunc(GL_ONE , GL_ONE);
      BindTexture(Explo1,0);
      for I := 0 to high(Explosions) do
        with Explosions[i] do
        if used then
        begin
          DrawStr( pos.x,pos.y, size, frame);
          frame := frame + Speed*FrameTime*0.002;
          if frame > 16 then
          used:=false;
        end;

    BindTexture(Explo2,0);
      color4ub(fcolor[0],fcolor[1],fcolor[2],255);
        DrawStr( mpos[0], mpos[1], 256, FFRame);
      Color4ub(255,255,255,255);

      blend(false);


  end;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.Timer1Timer(Sender: TObject);
var i :integer;
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
          Size:= Random(96)+96;
          pos := vec3f( random( clientwidth  +Size ) - Size *0.5 ,
                        random( clientheight +Size ) - Size *0.5 , 0);

          Frame:=0;
          Speed:= (Random(50) + 50) *0.1;
          used:=true;
        end;

  FrameTime := GetTickCount - LastTime;
  LastTime  := GetTickCount;
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
    Explo2   := LoadTexture( MediaDir+'expl2.jpg' );
    Explo1   := LoadTexture( MediaDir+'expl1.jpg');
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

//----------------------------------------------------------------------------------------------------------------------

end.

