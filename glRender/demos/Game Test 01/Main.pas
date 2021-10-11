unit Main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  GLControl, ExtCtrls, StdCtrls,math,l_math;

type
  TMainForm = class(TForm)
    GLRender: TGLRender;
    GLTimer1: TGLTimer;
    procedure GLTimer1Timer(Sender: TObject; LagCount: Integer);
    procedure GLRenderClick(Sender: TObject);
    procedure GLRenderMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure GLControlRender(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure GLControlSetup(Sender: TObject);
    procedure OnCLick(Sender: TObject);
  private
    FFrame: Single;
    FColor: Array [0..2] of byte;
    MPOS  : Array [0..1] of single;
    procedure DrawStr(const size,frame : Single; const Symbols, SymbolsSize,TextureSize : Integer );
  end;



var
  MainForm  : TMainForm;
  TexDirt,
  Texblood,
  TexMan,
  TexRough,
  TexTree   : Integer;




  Player  : record
    acc,
    pos   : TVector;
    Angle,
    Frame : Single;
  end;
  FrameTime,
  LastTime  : Integer;
  Frust: TFrustum;

//----------------------------------------------------------------------------------------------------------------------

implementation
uses land;

{$R *.DFM}



procedure TMainForm.DrawStr(const Size,frame : Single; const Symbols, SymbolsSize,TextureSize : Integer );
var s : Integer;
    YY,xx,
    pixel   : Single;
    TexSize : Single;
    Vertex  : array [0..3] of TVector;
    TexCoord: array [0..3] of TVector2d;

begin
with glrender do
begin
  TexSize := 1 / TextureSize;
      S     := Trunc(Frame);
      pixel :=  SymbolsSize * TexSize;
      xx    :=  SymbolsSize * ( s mod Symbols) * TexSize;
      yy    :=  SymbolsSize * ( s div Symbols) * TexSize;

      TexCoord[0] := vector2d(xx      ,yy);
      TexCoord[1] := vector2d(xx+pixel,yy);
      TexCoord[2] := vector2d(xx+pixel,yy+pixel);
      TexCoord[3] := vector2d(xx      ,yy+pixel);
        Vertex[0] := vector( 0   ,    0, 0);
        Vertex[1] := vector( size,    0, 0);
        Vertex[2] := vector( size, size, 0);
        Vertex[3] := vector( 0   , size, 0);
      DrawPoly(2,GL_Polygon,@Vertex,@TexCoord,nil);
end;


end;


procedure DrawTrees();
var i : Integer;
    YY,xx,
    pixel   : Single;
    vVertex  : array [0..4*3-1] of TVector;
    vClr     : array [0..4*3-1] of TVector4;
    vTexCoord: array [0..4*3-1] of TVector2d;
    K : Array [0..3] of single;

    const
    Symbols     = 2;
    SymbolsSize = 128;
    TexSize     = 1/256;
    offset : TVector = (X:-15; Y:-10; Z:0);
    var
    time:single;
begin

with mainform.glrender do
begin

      BindTexture(TexTree,0);
      vClr[0]:= Vector4(0,0,0,0.5);
      vClr[1]:= Vector4(0,0,0,0.5);
      vClr[2]:= Vector4(0,0,0,0.5);
      vClr[3]:= Vector4(0,0,0,0.5);
      vClr[8 ]:= Vector4(1,1,1,1);
      vClr[9 ]:= Vector4(1,1,1,1);
      vClr[10]:= Vector4(1,1,1,1);
      vClr[11]:= Vector4(1,1,1,1);

  for i := 0 to high(trees) do
  with trees[i] do
  if frust.PointInFrustum(@pos) then

  begin
      vClr[4 ]:= Vector4(clr.x,clr.y,clr.z,1);
      vClr[5 ]:= Vector4(clr.x,clr.y,clr.z,1);
      vClr[6 ]:= Vector4(clr.x,clr.y,clr.z,1);
      vClr[7 ]:= Vector4(clr.x,clr.y,clr.z,1);


  time:= GetTickCount *0.005;
              K[0] := 0.34 * Sin(pos.x + pos.y + time );
              K[1] := 0.34 * Sin(pos.x + pos.y + time + 1.3);
              K[2] := 0.34 * Sin(pos.x - pos.y + time - 0.3);
              K[3] := 0.34 * Sin(pos.x - pos.y + time + 2.2);


      pixel :=  SymbolsSize * TexSize;
      xx    :=  SymbolsSize * ( Frame mod Symbols) * TexSize;
      yy    :=  SymbolsSize * ( Frame div Symbols) * TexSize;
      vTexCoord[0] := vector2d(xx      ,yy);
      vTexCoord[1] := vector2d(xx+pixel,yy);
      vTexCoord[2] := vector2d(xx+pixel,yy+pixel);
      vTexCoord[3] := vector2d(xx      ,yy+pixel);
      Move(vTexCoord[0], vTexCoord[4], 4*8);
      Move(vTexCoord[0], vTexCoord[8], 4*8);
        vVertex[ 0] := vector( pos.x+ k[0] - size +offset.x , pos.y + k[3] - size + offset.y, 0);
        vVertex[ 1] := vector( pos.x+ k[1] + size +offset.x , pos.y + k[0] - size + offset.y, 0);
        vVertex[ 2] := vector( pos.x+ k[2] + size +offset.x , pos.y + k[1] + size + offset.y, 0);
        vVertex[ 3] := vector( pos.x+ k[3] - size +offset.x , pos.y + k[2] + size + offset.y, 0);
        vVertex[4 ] := vector( pos.x+ k[0] - size           , pos.y + k[3] - size , 0);
        vVertex[5 ] := vector( pos.x+ k[1] + size           , pos.y + k[0] - size , 0);
        vVertex[6 ] := vector( pos.x+ k[2] + size           , pos.y + k[1] + size , 0);
        vVertex[7 ] := vector( pos.x+ k[3] - size           , pos.y + k[2] + size , 0);
        vVertex[ 8] := vector( pos.x+ k[1] - size*0.7       , pos.y + k[0] - size*0.7 , 0);
        vVertex[ 9] := vector( pos.x+ k[2] + size*0.7       , pos.y + k[1] - size*0.7 , 0);
        vVertex[10] := vector( pos.x+ k[3] + size*0.7       , pos.y + k[2] + size*0.7 , 0);
        vVertex[11] := vector( pos.x+ k[0] - size*0.7       , pos.y + k[3] + size*0.7 , 0);
        DrawElement  (length(vvertex),GL_Quads,@vVertex,@vTexCoord,nil,nil,@Vclr[0]);
   end;
      Color4f(1,1,1,1);
end;


end;


//----------------------------------------------------------------------------------------------------------------------

procedure TMainForm.GLControlRender(Sender: TObject);
begin
  with Sender as TGLRender do
  begin
    SetProjection( true);
    Frust.CalculateFrustum;

      BindTexture(TexDirt,0);
      with ground do
      DrawElement( Length(vertex) ,GL_QUADS,@Vertex[0],@TexCoord[0],nil,nil,@color[0]);

      Blend(true);
      BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      BindTexture(TexMan,0);
      Color4f(1,1,1,1);
      with player do
      begin
      PushMatrix;
      Translate(pos.x,pos.y,0);
           Rotate(Angle,0,0,1);
        Translate(-32,-32,0);

          DrawStr(64,FFrame, 8, 64, 512);
          DrawStr(64,FFrame+16, 8, 64, 512);
      PopMatrix;
      end;

      DrawTrees;
      Blend(false);




  end;
end;

//----------------------------------------------------------------------------------------------------------------------
Function GetAngle(POS1,POS2:TVector):Single;
var
  VLeng,Cosns,Sins,ArCos: Single;
const
 Rad2Deg = (180 / PI);
begin
     VLeng := Sqrt(Sqr(POS2.x-POS1.x)+Sqr(POS2.y-POS1.y));
  if VLeng <> 0 then
     VLeng := 1 / VLeng;
     Cosns := (POS2.x-POS1.x)*VLeng;
     Sins  := (POS2.y-POS1.y)*VLeng;
     ArCos := ArcCos(Cosns);
  if Sins<0 then Result:=360-ArCos * Rad2Deg else
                 Result:=    ArCos * Rad2Deg;
end;


//----------------------------------------------------------------------------------------------------------------------
procedure TMainForm.OnCLick(Sender: TObject);
begin
 MessageBox(0,'','',0);
end;

procedure TMainForm.GLTimer1Timer(Sender: TObject; LagCount: Integer);
const
 DEG2RAD = PI/180;
begin

  GLRender.Invalidate;
  if getasynckeystate(vk_escape) <> 0 then application.Terminate;


  With Player do
  begin
       Angle := GetAngle(pos, vector(mpos[0], mpos[1],0)) + 90 ;
       Acc := vector(0,0,0);

      if getasynckeystate( ord('W') ) <> 0 then  acc:= v_add(acc, vector( 0, -1, 0));
      if getasynckeystate( ord('S') ) <> 0 then  acc:= v_add(acc, vector( 0, 1, 0));
      if getasynckeystate( ord('D') ) <> 0 then  acc:= v_add(acc, vector( 1, 0, 0));
      if getasynckeystate( ord('A') ) <> 0 then  acc:= v_add(acc, vector( -1, 0, 0));
       acc := v_mult(acc, frametime *0.1);

       pos := v_add(pos,acc);
       if pos.x < 0 then pos.x :=0;
       if pos.y < 0 then pos.y :=0;

       if pos.x > ground.W * ground.BlockSize then pos.x := ground.W * ground.BlockSize;
       if pos.y > ground.H * ground.BlockSize then pos.y := ground.h * ground.BlockSize;

       if v_Length(acc) > 0 then
       begin
          FFrame := FFrame + v_Length(acc)*FrameTime *0.02;
       if FFrame > 15 then
          FFrame := 0;
       end;
  end;

  FrameTime := GLTimer1.FrameTime;
  caption := inttostr( GLTimer1.FrameRate ) + ' ' + inttostr( GLTimer1.FrameTime );
end;

procedure TMainForm.FormCreate(Sender: TObject);
begin
  GLTimer1.Enabled    := false;
  GLRender.Align      := ALClient;
  GLRender.Background := clblack;
  GLRender.OnSetup    := GLControlSetup;
  GLRender.OnRender   := GLControlRender;

  if MessageBox(0,'Full Screen ?','start in fullscreen mode ?',MB_YESNO) = 6 then
  begin
  BorderStyle := BSNone;
  GLTimer1.Interval := 33;
  top:=0;
  left:=0;
  Width := 1024;
  Height:= 768;
{  GLRender.Top :=0;
  GLRender.Left:=0;
  GLRender.Width := Width;
  GLRender.Height:= Height;}
  GLRender.bpp        := 32;
  GLRender.dpp        := 16;
  GLRender.FullScreen := true;
  end;


  Randomize;
  InitLand;
  Frust:= TFrustum.Create(nil);

  Player.pos := vector( 200,200, 0);
  GLTimer1.Enabled    := true;
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
    TexDirt  := LoadTexture( MediaDir+'\game\dirt.jpg');
//    Texblood := LoadTexture( MediaDir+'\game\blood.bmp');
    TexMan   := LoadTexture( MediaDir+'\game\man.jpg', MediaDir+'\game\man_a.jpg');
//    TexRough := LoadTexture( MediaDir+'\game\Rough.bmp');
    TexTree  := LoadTexture( MediaDir+'\game\Tree.jpg',MediaDir+'\game\Tree_A.jpg');

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

