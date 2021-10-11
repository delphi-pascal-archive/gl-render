Unit Land;

Interface

uses l_math,GLControl;

type
  T2DCamera = Object
    Width,Height: integer;
    PRender  : PglRender;
    Position : TVec3f;
    Procedure SetView;
    Procedure SetPosition( P: TVec3f );
    Function  PointInCamera( P: TVec3f ): boolean;
    Function  AABBInCamera( Min,Max :TVec3f ):boolean;
  end;


Var
  Trees  : Array of Record
    POS,
    Clr  : TVec3f;
    Size : Single;
    Frame: Integer;
  end;


  Ground : Record
    Size,
    W,H,
    BlockSize: Word;
    Vertex,
    RVertex   : Array of TVec3f;
    TexCoord,
    RTexCoord : Array of TVec2f;
    Color,
    RColor    : Array of TVec4f;

    FCount    : integer;
    light     : Array of Byte;
  end;

  Cam         : T2DCamera;

Procedure InitLand;

Implementation


Procedure T2DCamera.SetView;
begin
if PRender = nil then exit;
 with Position do
     PRender.Translate( -x, -y, 0 );
end;

Procedure T2DCamera.SetPosition( P: TVec3f );
var S:TVec3f;
begin
 Position := v_sub(P, Vec3f(width*0.5,height*0.5,0));
 with Position, Ground do
 begin
     S.X := BlockSize * (W-1) - Width;
     S.Y := BlockSize * (H-1) - Height;
  if X < 0   then X:= 0;
  if Y < 0   then Y:= 0;
  if X > S.X then X:= S.X;
  if Y > S.Y then Y:= S.Y;
 end;

end;

Function  T2DCamera.PointInCamera( P: TVec3f ): boolean;
begin
  result :=   (abs(P.x - Position.x -Width  *0.5)< Width  *0.5)
          and (abs(P.y - Position.y -Height *0.5)< Height *0.5);
end;
Function  T2DCamera.AABBInCamera;
begin
Result:=not ( (Position.x > Max.x) or (Position.x+width  < Min.x)
          or  (Position.y > Max.y) or (Position.y+height < Min.y));
end;



Procedure InitLand;

var i,X,Y,N:Integer;
    Function GetColor(X,Y:Integer):TVec4f;
    var c: single;
    begin
     with Ground do
      c   :=( Light[(X   +  Y      * W)]+
               Light[(X+1 +  Y      * W)]+
               Light[(X   + (Y + 1) * W)]+
               Light[(X+1 + (Y + 1) * W)]) div 4 / 255;
      Result := vec4(c,c,c,1);
    end;

var   c:single;
const
      v=1/255;
begin
  with Ground do
  begin
    W    := 64;
    H    := 64;

    Size := W*H;
    BlockSize := 64;
    SetLength ( Vertex  , Size * 4 );
    SetLength ( TexCoord, Size * 4 );
    SetLength ( Color   , Size * 4 );

    SetLength ( rVertex  , Size * 4 );
    SetLength ( rTexCoord, Size * 4 );
    SetLength ( rColor   , Size * 4 );

    SetLength ( light   , Size );
    for I := 0 to Size-1 do
    Light[i] := 60 + Random(255 - 60);

    for I := 0 to Size-1 do
            begin
              X := I MOD W;
              Y := I DIV W;
              N := (X + Y * W) * 4;
              Vertex[n+ 0] := Vec3f( X    * BlockSize  ,  Y    * BlockSize, 0);
              Vertex[n+ 1] := Vec3f((X+1) * BlockSize  ,  Y    * BlockSize, 0);
              Vertex[n+ 2] := Vec3f((X+1) * BlockSize  , (Y+1) * BlockSize, 0);
              Vertex[n+ 3] := Vec3f( X    * BlockSize  , (Y+1) * BlockSize, 0);
              TexCoord[n+0] := vec2f( X    * 0.2,  Y    * 0.2);
              TexCoord[n+1] := vec2f((X+1) * 0.2,  Y    * 0.2);
              TexCoord[n+2] := vec2f((X+1) * 0.2, (Y+1) * 0.2);
              TexCoord[n+3] := vec2f( X    * 0.2, (Y+1) * 0.2);
              Color[n+0] := GetColor(x   , y);
              Color[n+1] := GetColor(x+1 , y);
              Color[n+2] := GetColor(x+1 , y+1);
              Color[n+3] := GetColor(x   , y+1);
            end;
  end;



  SetLength(Trees, 150);
  for i := 0 to high(trees) do
  with trees[i] do
    begin
      Pos   := Vec3f( Random( ground.W * ground.BlockSize), Random( ground.h * ground.BlockSize) , 0);
      c     := GetColor( trunc(pos.x / ground.BlockSize)  , trunc(pos.y / ground.BlockSize) ).x+0.2;

      Clr   := v_mult(Vec3f( Random(32)+196, Random(32)+196 , Random(32)+196), c*v) ;
      Size:= Random(32)+48;
      Frame:= Random(39) div 10; // 0 1 2 3
    end;
end;

end.