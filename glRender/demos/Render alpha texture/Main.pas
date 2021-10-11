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
  end;

var
  MainForm: TMainForm;
  Texture : Integer;
//----------------------------------------------------------------------------------------------------------------------

implementation


{$R *.DFM}


//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.GLControlRender(Sender: TObject);
const
 W = 160 ;      H = 70;
 Cx= 160 *0.5 ; Cy= 70 * 0.5;
 var
  Size:Single;
begin
//glcontrol1.Background := rgb(random(255),random(255),random(255));
  with Sender as TGLRender do
  begin
    SetProjection( true );
    BindTexture(Texture,0);
    AlphaTest(true);
    Size := abs(Sin(GetTickCount *0.0005)*4);
      Draw2DSprite( Sin(GetTickCount *0.001)*100+ClientWidth*0.5, Cos(GetTickCount *0.0005)*100 +ClientHeight*0.5,
                   // Увеличиваем размер :D
                   Cx * Size,Cy * Size,
                    W * Size,H * Size
                   ,-Fangle );

      Draw2DSprite( MPOS[0],MPOS[1], 80,35,160,70,Fangle );
    AlphaTest(false);
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
    Texture := LoadTexture( MediaDir+'OpenGL.bmp', true , RGB(255,255,255), 50);
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

