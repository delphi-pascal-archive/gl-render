unit Main;

interface

uses
  Windows, Messages, SysUtils, Classes,  Controls, Forms,
  GLControl, StdCtrls,l_math;

type
  TForm1 = class(TForm)
    GLRender: TGLRender;
    GLTimer1: TGLTimer;
    XMMusic1: TXMMusic;
    Frust   : TFrustum;
    procedure GLTimer1Timer(Sender: TObject; LagCount: Integer);
    procedure GLRenderMouseMove(Sender: TObject; Shift: TShiftState; X,Y: Integer);
    procedure GLControlRender(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure GLControlSetup(Sender: TObject);
  private
    MPOS  : Array [0..1] of single;
  end;

  PPlayer = ^TPlayer;
  TPlayer = record
    acc,
    pos     : TVec3f;
     Angle,
    LAngle,
    Frame   : Single;
    ID,
    OldTime : Cardinal;
  end;

  TBullet   = record
    acc,
    pos   : TVec3f;
    Angle,
    Frame : Single;
    color : TVec3f;
    used  : boolean;
    ID    : Cardinal;
  end;


var
  Form1  : TForm1;
  TexDirt,
  Texblood,
  TexMan,
  TexRough,
  TexTree,
  TexMove,
  TexVol,
  TexBullet : Integer;




  Player  : TPlayer;

  Bullet  : Array [0..50] of TBullet;

  FrameTime,
  LastTime  : Cardinal;

  vol_l,
  vol_r,
  VolMax:  Single;
  const
    PlayerIWH = 64;

//----------------------------------------------------------------------------------------------------------------------

implementation
uses land;

{$R *.DFM}

procedure UpdateMusic();
var
  vol,
  nvol_l,
  nvol_r : Integer;
  z,sz:single;
  s1,s2:single;
begin
         vol   := Form1.XMmusic1.GetStats;

        nvol_l := HiWord(vol);
        nvol_r :=   Word(vol);
            sz := VolMax*0.08;

    if vol_l < nvol_l then vol_l := nvol_l else vol_l := vol_l -sz;
    if vol_r < nvol_r then vol_r := nvol_r else vol_r := vol_r -sz;


   if nvol_r > VolMax then VolMax:=nvol_r;
   if nvol_l > VolMax then VolMax:=nvol_l;

  z:= VolMax;
  if z = 0 then exit;


  With Form1.glRender do
  begin
  BindTexture(TexVol,0);
  BlendFunc(gl_one,gl_one);
   S1:= Round((vol_l /z)*width );
   S2:= Round((vol_r /z)*width );
  color4f(1,0,0 ,0);
   Draw2DSprite( width*0.5, 15, S1 *0.5, 5,S1,10,0 );
  color4f(0,0,1 ,0);
   Draw2DSprite( width*0.5, 5, S2 *0.5, 5,S2,10,0 );
  end;

end;



procedure DrawTrees();
var i : Integer;
    YY,xx,
    pixel   : Single;
    vVertex  : array [0..4*3-1] of TVec3f;
    vClr     : array [0..4*3-1] of TVec4f;
    vTexCoord: array [0..4*3-1] of Tvec2f;
    K : Array [0..3] of single;

    const
    Symbols     = 2;
    SymbolsSize = 128;
    TexSize     = 1/256;
    offset : TVec3f = (X:-15; Y:-10; Z:0);
    var
    time:single;
begin

with Form1, glrender do
begin

      BindTexture(TexTree,0);
      vClr[0]:= Vec4(0,0,0,0.5);
      vClr[1]:= Vec4(0,0,0,0.5);
      vClr[2]:= Vec4(0,0,0,0.5);
      vClr[3]:= Vec4(0,0,0,0.5);
      vClr[8 ]:= Vec4(1,1,1,1);
      vClr[9 ]:= Vec4(1,1,1,1);
      vClr[10]:= Vec4(1,1,1,1);
      vClr[11]:= Vec4(1,1,1,1);

  for i := 0 to high(trees) do
  with trees[i] do
  if frust.SphereInFrustum(@pos, size) then
  begin
      vClr[4 ]:= Vec4(clr.x,clr.y,clr.z,1);
      vClr[5 ]:= Vec4(clr.x,clr.y,clr.z,1);
      vClr[6 ]:= Vec4(clr.x,clr.y,clr.z,1);
      vClr[7 ]:= Vec4(clr.x,clr.y,clr.z,1);


  time:= LastTime *0.005;
              K[0] := 0.34 * Sin(pos.x + pos.y + time );
              K[1] := 0.34 * Sin(pos.x + pos.y + time + 1.3);
              K[2] := 0.34 * Sin(pos.x - pos.y + time - 0.3);
              K[3] := 0.34 * Sin(pos.x - pos.y + time + 2.2);


      pixel :=  SymbolsSize * TexSize;
      xx    :=  SymbolsSize * ( Frame mod Symbols) * TexSize;
      yy    :=  SymbolsSize * ( Frame div Symbols) * TexSize;
      vTexCoord[0] := vec2f(xx      ,yy);
      vTexCoord[1] := vec2f(xx+pixel,yy);
      vTexCoord[2] := vec2f(xx+pixel,yy+pixel);
      vTexCoord[3] := vec2f(xx      ,yy+pixel);
      Move(vTexCoord[0], vTexCoord[4], 4*8);
      Move(vTexCoord[0], vTexCoord[8], 4*8);

        vVertex[ 0] := Vec3f( pos.x+ k[0] - size +offset.x , pos.y + k[3] - size + offset.y, 0);
        vVertex[ 1] := Vec3f( pos.x+ k[1] + size +offset.x , pos.y + k[0] - size + offset.y, 0);
        vVertex[ 2] := Vec3f( pos.x+ k[2] + size +offset.x , pos.y + k[1] + size + offset.y, 0);
        vVertex[ 3] := Vec3f( pos.x+ k[3] - size +offset.x , pos.y + k[2] + size + offset.y, 0);
        vVertex[4 ] := Vec3f( pos.x+ k[0] - size           , pos.y + k[3] - size , 0);
        vVertex[5 ] := Vec3f( pos.x+ k[1] + size           , pos.y + k[0] - size , 0);
        vVertex[6 ] := Vec3f( pos.x+ k[2] + size           , pos.y + k[1] + size , 0);
        vVertex[7 ] := Vec3f( pos.x+ k[3] - size           , pos.y + k[2] + size , 0);
        vVertex[ 8] := Vec3f( pos.x+ k[1] - size*0.7       , pos.y + k[0] - size*0.7 , 0);
        vVertex[ 9] := Vec3f( pos.x+ k[2] + size*0.7       , pos.y + k[1] - size*0.7 , 0);
        vVertex[10] := Vec3f( pos.x+ k[3] + size*0.7       , pos.y + k[2] + size*0.7 , 0);
        vVertex[11] := Vec3f( pos.x+ k[0] - size*0.7       , pos.y + k[3] + size*0.7 , 0);
        DrawElement  (length(vvertex),GL_Quads,@vVertex,@vTexCoord,nil,nil,@Vclr[0]);
   end;
      Color4f(1,1,1,1);
end;


end;


//----------------------------------------------------------------------------------------------------------------------

procedure TForm1.GLControlRender(Sender: TObject);
var i : integer;
begin
  with Sender as TGLRender do
  begin
    SetProjection( true);
    Cam.SetView;
    Frust.CalculateFrustum;

      BindTexture(TexDirt,0);
      with ground do
      DrawElement( Length(vertex) ,GL_QUADS,@Vertex[0],@TexCoord[0],nil,nil,@color[0]);

      Blend(true);

      Color4f(0,0.5,1,1);
      BlendFunc(GL_One, gl_one);
      BindTexture(TexMove,0);
      with player do
           Draw2DSprite(Pos.x,pos.y,32,54,64,64, LAngle);
      Color4f(1,1,1,1);

      BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      BindTexture(TexMan,0);
      with player do
      begin

      Draw2DAnimSprite(pos.x,pos.y,PlayerIWH    ,PlayerIWH,LAngle,Trunc(FRame),
                                   PlayerIWH    ,PlayerIWH,
                                   PlayerIWH div 2,PlayerIWH div 2,512,512);

      Draw2DAnimSprite(pos.x,pos.y,PlayerIWH    ,PlayerIWH, Angle,Trunc(FRame)+16,
                                   PlayerIWH    ,PlayerIWH,
                                   PlayerIWH div 2,PlayerIWH div 2,512,512);
      end;

        BindTexture(TexBullet,0);
        BlendFunc(GL_One, gl_one);

      for i := 0 to high(bullet) do
      with bullet[i] do
      if used then
      if Frust.pointinfrustum(@pos) then
      begin
        with color do Color4f(x,y,z,1);
             Draw2DSprite(Pos.x,pos.y,16,16,32,32, Angle);
      end;

      BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      DrawTrees;

      LoadIdentity;
      UpdateMusic;
      Blend(false);




  end;
end;

//----------------------------------------------------------------------------------------------------------------------

Procedure Shot( Player:PPlayer);
var i :integer;
begin

  if player.OldTime < LastTime then
  for i := 0 to high(bullet) do
  with Bullet[i] do
  if not used then
  begin
   used  := true;
   acc   := V_Offset(-player.angle+180);
   pos   := v_add(player.pos, v_mult(acc,27));
   Angle := player.Angle;
   Frame := 0;
   color := Vec3f(0,0.5,1);
   ID    := Player.ID;
   player.OldTime := LastTime + 125;
   exit;
  end;

end;


Procedure Updatebullets();
var i :integer;
begin

  for i := 0 to high(bullet) do
  with Bullet[i] do
  if used then
  begin
   pos := v_add(pos, v_mult(acc, 2*FrameTime *0.5) );
      angle:=angle + frametime *0.5;
   if angle > 180 then angle :=-180;


   if (pos.x < -100) or (pos.y < -100) or
      (pos.x > ground.W * ground.BlockSize+100) or
      (pos.y > ground.H * ground.BlockSize+100) then
               used:=false;
  end;

end;

//----------------------------------------------------------------------------------------------------------------------
procedure TForm1.GLTimer1Timer(Sender: TObject; LagCount: Integer);
const
 DEG2RAD = PI/180;
 var S : single;
begin

  GLRender.Invalidate;
  if getasynckeystate(vk_escape) <> 0 then application.Terminate;


  With Player do
  begin
       Angle := V_Angle(v_sub(Vec3f(cam.position.x+ mpos[0], cam.position.y+ mpos[1],0) , pos)) + 90 ;
       Acc   := Vec3f(0,0,0);

      if getasynckeystate( ord('W') ) <> 0 then  acc:= v_add(acc, Vec3f(  0,  -1,   0));
      if getasynckeystate( ord('S') ) <> 0 then  acc:= v_add(acc, Vec3f(  0,   1,   0));
      if getasynckeystate( ord('D') ) <> 0 then  acc:= v_add(acc, Vec3f(  1,   0,   0));
      if getasynckeystate( ord('A') ) <> 0 then  acc:= v_add(acc, Vec3f( -1,   0,   0));
      if getasynckeystate( VK_LButton ) <> 0 then Shot(@Player);

                        acc := v_mult(acc, frametime *0.1);
       pos := v_add(pos,acc);

       if pos.x < 32 then pos.x :=32;
       if pos.y < 32 then pos.y :=32;
       if pos.x > ground.W * ground.BlockSize-96 then pos.x := ground.W * ground.BlockSize - 96;
       if pos.y > ground.H * ground.BlockSize-96 then pos.y := ground.h * ground.BlockSize - 96;

       if v_Length(acc) > 0 then
       begin
                 S := V_Angle(acc) - LAngle + 90;
          if abs(S) >  180    then S := abs(S) - 360;
             LAngle := LAngle + (S)*FrameTime *0.005;
          if LAngle >  180 then LAngle := LAngle - 360;
          if LAngle < -180 then LAngle := LAngle + 360;
             Frame := Frame + v_Length(acc)*0.4;
          if Frame > 15   then Frame := 0;
       end;

    Cam.SetPosition(pos);
  end;
  Updatebullets;

  Cam.Width   := GLRender.Width;
  Cam.Height  := GLRender.Height;
  FrameTime   := GLTimer1.FrameTime;
  LastTime    := GetTickCount;
  caption     := inttostr( GLTimer1.FrameRate )+' '+GlRender.glRender +' OpenGL version:'+ GlRender.glVersion;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  GLTimer1.Enabled    := false;

  GLRender.Align      := ALClient;
  GLRender.Background := rgb(0,0,0);
  GLRender.OnSetup    := GLControlSetup;
  GLRender.OnRender   := GLControlRender;

  if MessageBox(0,'Full Screen ?','start in 1024x768 fullscreen mode ?',MB_YESNO) = 6 then
  begin
   Top                 := 0;
   Left                := 0;
   Width               := 1024;
   Height              := 768;
   BorderStyle         := BSNone;

   GLRender.bpp        := 32;
   GLRender.dpp        := 16;
   GLRender.FullScreen := true;
   GLTimer1.Interval   := 33;
  end;


  Randomize;
  InitLand;
  Player.pos := Vec3f( 200,200, 0);
  Player.ID  := 0;
  GLTimer1.Enabled    := true;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TForm1.GLControlSetup(Sender: TObject);
var
 appdir,
 mediadir:string;
 function GetUpDir(const dir:string):string;
 var i : integer;
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
    TexDirt  := LoadTexture( MediaDir+'game\dirt.jpg');
//    Texblood := LoadTexture( MediaDir+'\game\blood.jpg');
    TexMan   := LoadTexture( MediaDir+'game\man.jpg', MediaDir+'\game\man_a.jpg');
//    TexRough := LoadTexture( MediaDir+'\game\Rough.jpg');
    TexTree  := LoadTexture( MediaDir+'game\Tree.jpg',MediaDir+'\game\Tree_A.jpg');
    TexMove  := LoadTexture( MediaDir+'game\MoveVec.jpg');
    TexVol   := LoadTexture( MediaDir+'game\MusVol.jpg');
    TexBullet:= LoadTexture( MediaDir+'game\ge3.bmp');
    Cam.PRender :=@TGLRender(Sender);
  end;

    XMMusic1.LoadFromFile(MediaDir +'game\music\3.xm');
    XMMusic1.Play;


end;

procedure TForm1.GLRenderMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
  MPOS[0]:=x;
  MPOS[1]:=y;
end;

//----------------------------------------------------------------------------------------------------------------------

end.

