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
  Texture: Integer;
//  Shader : TShader;
//----------------------------------------------------------------------------------------------------------------------

implementation
uses font2;

{$R *.DFM}

var
  TheFont : TFontObj;
//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.GLControlRender(Sender: TObject);
begin
  with Sender as TGLRender do
  begin
    SetProjection( true );
    BindTexture(Texture,0);
      Draw2DSprite( MPOS[0], MPOS[1], 80,35,160,70,Fangle );

      TheFont.Draw(10,50,14,'Font Demo 2',0.1);

      TheFont.Draw(10,80,14,'OpenGL Render v'+floattostr(version),0.1);
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

 TheFont          := TFontObj.Create;
 TheFont.GLRender := @Sender;
  // Create the base display list if not yet done.
  with TGLRender(Sender) do
  begin
    DepthTest(false);
    TheFont.Load(mediadir + 'fontstudio.fnt');
    Texture := LoadTexture( MediaDir+'OpenGL.bmp' );
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

