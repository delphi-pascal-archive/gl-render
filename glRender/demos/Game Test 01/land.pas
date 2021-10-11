Unit Land;

Interface

uses l_math;

Var
  Trees  : Array of Record
    POS,
    Clr  : TVector;
    Size : Single;
    Frame: Integer;
  end;


  Ground : Record
    Size,
    W,H,
    BlockSize: Word;
    Vertex   : Array of TVector;
    TexCoord : Array of TVector2d;
    Color    : Array of TVector4;
    light    : Array of Byte;
  end;

Procedure InitLand;

Implementation

Procedure InitLand;

var i,X,Y,N:Integer;
    Function GetColor(X,Y:Integer):TVector4;
    var c: single;
    begin
     with Ground do
      c   :=( Light[(X   +  Y      * W)]+
               Light[(X+1 +  Y      * W)]+
               Light[(X   + (Y + 1) * W)]+
               Light[(X+1 + (Y + 1) * W)]) div 4 / 255;
      Result := vector4(c,c,c,1);
    end;

var   c:single;
const
      v=1/255;
begin
  with Ground do
  begin
    W    := 16;
    H    := 16;

    Size := W*H;
    BlockSize := 64;
    SetLength ( Vertex  , Size * 4 );
    SetLength ( TexCoord, Size * 4 );
    SetLength ( Color   , Size * 4 );

    SetLength ( light   , Size );
    for I := 0 to Size-1 do
    Light[i] := 60 + Random(255 - 60);

    for I := 0 to Size-1 do
            begin
              X := I MOD W;
              Y := I DIV W;
              N := (X + Y * W) * 4;
              Vertex[n+ 0] := vector( X    * BlockSize  ,  Y    * BlockSize, 0);
              Vertex[n+ 1] := vector((X+1) * BlockSize  ,  Y    * BlockSize, 0);
              Vertex[n+ 2] := vector((X+1) * BlockSize  , (Y+1) * BlockSize, 0);
              Vertex[n+ 3] := vector( X    * BlockSize  , (Y+1) * BlockSize, 0);
              TexCoord[n+0] := vector2d( X    * 0.2,  Y    * 0.2);
              TexCoord[n+1] := vector2d((X+1) * 0.2,  Y    * 0.2);
              TexCoord[n+2] := vector2d((X+1) * 0.2, (Y+1) * 0.2);
              TexCoord[n+3] := vector2d( X    * 0.2, (Y+1) * 0.2);
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
      Pos   := Vector( Random( ground.W * ground.BlockSize), Random( ground.h * ground.BlockSize) , 0);
      c     := GetColor( trunc(pos.x / ground.BlockSize)  , trunc(pos.y / ground.BlockSize) ).x+0.2;

      Clr   := v_mult(Vector( Random(32)+196, Random(32)+196 , Random(32)+196), c*v) ;
      Size:= Random(32)+48;
      Frame:= Random(39) div 10; // 0 1 2 3
    end;
end;


end.