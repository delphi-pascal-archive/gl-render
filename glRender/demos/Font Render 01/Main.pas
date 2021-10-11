unit Main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  GLControl, ExtCtrls, StdCtrls;

type
  TMainForm = class(TForm)
    Timer1: TTimer;
    GLRender: TGLRender;
    procedure GLRenderMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure GLControlRender(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure GLControlSetup(Sender: TObject);
    procedure OnCLick(Sender: TObject);
  private
    FAngle: Integer;
    MPOS  : Array [0..1] of single;
    procedure DrawStr(x,y,Size : Single ; str:string);
  end;

var
  MainForm: TMainForm;
  Texture,
  TexFont : Integer;
//----------------------------------------------------------------------------------------------------------------------

implementation

{$R *.DFM}

Type

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

procedure TMainForm.DrawStr(x,y,Size : Single ; str:string);
var i,s : Integer;
    ch: char;
    YY,xx,
    pixel   : Single;
    Vertex  : array [0..3] of TVec3f;
    TexCoord: array [0..3] of TVec2f;

    const
     StartSybmol = Ord('!');
     Symbols     = 15;
     SymbolsSize = 34;
     TextureSize = 1 / 512;

begin
with glrender do
begin
  pushmatrix;
  AlphaTest(true);
  DepthMask(false);
  Blend(true);
  BlendFunc(GL_ONE_MINUS_DST_COLOR , GL_DST_ALPHA);
  BindTexture(TexFont,0);
  Translate(x-10, y,0.4);

  for i:=1 to length(str) do
  begin
     ch:=str[i];
     if  str[i] = #13 then
          Translate(-i * size, y+16, 0)
     else
     if ch<>' ' then
    begin

      S     := ord(ch) - StartSybmol;
      pixel :=  SymbolsSize * TextureSize;
      xx    :=  SymbolsSize * ( s mod Symbols) * TextureSize;
      yy    := -SymbolsSize * ( s div Symbols) * TextureSize;

      TexCoord[0] := vec2f(xx      ,yy);
      TexCoord[1] := vec2f(xx+pixel,yy);
      TexCoord[2] := vec2f(xx+pixel,yy-pixel);
      TexCoord[3] := vec2f(xx      ,yy-pixel);
        Vertex[0] := Vec3f(  i    * size,    0, 0);
        Vertex[1] := Vec3f( (i+1) * size,    0, 0);
        Vertex[2] := Vec3f( (i+1) * size, size, 0);
        Vertex[3] := Vec3f(  i    * size, size, 0);
      DrawPoly(2,GL_Polygon,@Vertex,@TexCoord,nil);
    end;
  end;

 DepthMask(true);
 blend(false);
 alphatest(false);
 PopMatrix;
end;


end;


//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.GLControlRender(Sender: TObject);
begin
  with Sender as TGLRender do
  begin
    SetProjection( true );
    BindTexture(Texture,0);
      Draw2DSprite( MPOS[0],MPOS[1], 80,35,160,70,Fangle );

      DrawStr(10,10,27,'Font Demo 01 !!' + #13 + 'Current Angle : '+ inttostr(FAngle));
  end;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.Timer1Timer(Sender: TObject);

begin
    FAngle := (FAngle + 1) mod 360;

  GLRender.Invalidate;
  if getasynckeystate(vk_escape) <> 0 then application.Terminate;

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
    Texture := LoadTexture( MediaDir+'OpenGL.bmp' );
    TexFont := LoadTexture( MediaDir+'Font.jpg', MediaDir+'font_a.jpg');
  end

end;

procedure TMainForm.GLRenderMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
  MPOS[0]:=x;
  MPOS[1]:=y;
end;

//----------------------------------------------------------------------------------------------------------------------

end.

