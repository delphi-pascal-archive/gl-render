unit l_math;
{$Warnings off}
{$Hints On}
(************)
(* SVSD_VAL *)
(************)

interface

type
 TVec2f = record
  X, Y     : single;
 end;

 TVec3f   = record
  X, Y, Z  : single;
 end;

 TVec4f   = record
  case byte of
   0: (X, Y, Z,W  : single;);
   1: (xyzw : array [0..3] of single;);
 end;

const
 PI       = 3.14159265358979323846;
 PI2      = pi*2;
 RAD2DEG  = 180/PI;
 DEG2RAD  = PI/180;
 EPSILON  = 0.1;

  function max(const x, y: single): single;
  function min(const x, y: single): single;

  function ArcTan2(const Y, X: single): single;
  function ArcCos (const X: single): single;
  function Tan    (const X: Extended): Extended;
  procedure SinCos(const Theta: Single; var Sin, Cos: Single); register;
  function IsNaN  (const v : single) : boolean;

  function Vec4(const X, Y, Z,W: single): TVec4f;
  function v_ADD4(const V1, v2 : TVec4f): TVec4f;
  // 3D Vec3f's
  function  Vec3f       (const X, Y, Z: single): TVec3f;

  procedure v_clear     (var v: TVec3f);
  function v_Add        (const v1, v2 : TVec3f): TVec3f;
  function v_Sub        (const v1, v2 : TVec3f): TVec3f;
  function v_Mult       (const v: TVec3f; const d: single): TVec3f;
  function v_Div        (const v: TVec3f; const d: single): TVec3f;
  function v_MultV      (const v1, v2 : TVec3f): TVec3f;
  function v_Dist       (const v1, v2 : TVec3f): single;
  function v_Distq      (const v1, v2 : TVec3f): single;
  function v_Length     (const v: TVec3f): single;
  function v_Normalize  (const v: TVec3f): TVec3f;
  function v_Normalizesafe(const inv: TVec3f; out outv: TVec3f): Single;
  Function v_Negative   (const V: TVec3f): TVec3f;
  function v_Dot        (const v1, v2 : TVec3f): single;
  function v_Cross      (const v1, v2 : TVec3f): TVec3f;
  function v_Angle      (const v1, v2 : TVec3f) : Single; overload;
  Function V_Angle      (const V:TVec3f):Single; overload;
  function v_Interpolate(const v1, v2 : TVec3f; const k: single): TVec3f;

  function v_RotateX    (const V : TVec3f; const ang : Single): TVec3f;
  function v_RotateY    (const V : TVec3f; const ang : Single): TVec3f;
  function v_RotateZ    (const V : TVec3f; const ang : Single): TVec3f;
  function v_Rotate     (const V,Rot: TVec3f): TVec3f;
  function V_Offset     (const Heading:Single):TVec3f;

  function v_Rotate2D   (const v: TVec2f; const ang: single): TVec2f;
  Function V_Length2d   (const v:TVec2f):Single;
  Function V_sub2d      (const v,v2:TVec2f):TVec2f;
  Function V_add2d      (const v,v2:TVec2f):TVec2f;
  function Vec2f        (const X, Y: single): TVec2f;


implementation


function ArcSin(const X: Extended): Extended;
begin
  Result := ArcTan2(X, Sqrt(1 - X * X))
end;

function RadToDeg(const Radians: Extended): Extended;  { Degrees := Radians * 180 / PI }
begin
  Result := Radians * (180 / PI);
end;

function IsNaN(const v : single) : boolean;
asm
  fld   dword ptr v    // 0: v
  fxam                 // see what we've got, C0 set if NaN
  fstsw ax             // store C0-C3 in ax,
  sahf                 //   then in EFLAGS register: C0 -> CF
  mov   Result,0       // assume false
  jae   @NoNaN         // jump if CF not set
  mov   Result,1       // set result to true
@NoNaN:
  ffree st(0)          // clear FPU register
end;

function max(const x, y: single): single;
begin
if x > y then
 Result := x
else
 Result := y;
end;

function min(const x, y: single): single;
begin
if x < y then
 Result := x
else
 Result := y;
end;

function Tan(const X: Extended): Extended;
{  Tan := Sin(X) / Cos(X) }
asm
        FLD    X
        FPTAN
        FSTP   ST(0)      { FPTAN pushes 1.0 after result }
        FWAIT
end;

(***   Тригонометрия   ***)
function ArcTan2(const Y, X: single): single;
asm
 FLD     Y
 FLD     X
 FPATAN
 FWAIT
end;

function ArcCos(const X: single): single;
asm
{
Result := ArcTan2(Sqrt(1 - X * X), X);
}
       FLD     X
       fmul    ST(0),ST(0)
       FLD1
       FSub    st(0), st(1)
       FSQRT
       FLD     X
       FPATAN
       FWAIT
       FSTP ST(1)
end;

(***   Векторы   ***)

procedure SinCos(const Theta: Single; var Sin, Cos: Single); register;
asm
  fld theta
  fsincos
  fstp dword ptr [edx]
  fstp dword ptr [eax]
end;


// Построить вектор
function Vec3f(const X, Y, Z: single): TVec3f;
begin
Result.X := X;
Result.Y := Y;
Result.Z := Z;
end;

function Vec4(const X, Y, Z,W: single): TVec4f;
begin
Result.X := X;
Result.Y := Y;
Result.Z := Z;
Result.W := W;
end;

procedure v_clear(var v: TVec3f);
asm
  XOR EDX, EDX
  MOV [EAX], EDX
  MOV [EAX+4], EDX
  MOV [EAX+8], EDX
end;

{------------------------------------------------------------------------------}

function v_Sub(const V1, v2 : TVec3f): TVec3f; assembler; register;
begin
 Result.X := V1.X-V2.X;
 Result.Y := V1.Y-V2.Y;
 Result.Z := V1.Z-V2.Z;
end;

function v_ADD4(const V1, v2 : TVec4f): TVec4f;
begin
 Result.X := V1.X+V2.X;
 Result.Y := V1.Y+V2.Y;
 Result.Z := V1.Z+V2.Z;
 Result.w := 1;
end;


function v_ADD(const V1, v2 : TVec3f): TVec3f; assembler; register;
begin
 Result.X := V1.X+V2.X;
 Result.Y := V1.Y+V2.Y;
 Result.Z := V1.Z+V2.Z;
end;
function v_mult(const v: TVec3f; const D: Single): TVec3f;
begin
 Result.X := V.X*D;
 Result.Y := V.Y*D;
 Result.Z := V.Z*D;
end;

function v_MultV(const v1, v2 : TVec3f): TVec3f; assembler; register;
begin
 Result.X := V1.X* v2.X;
 Result.Y := v1.Y* v2.Y;
 Result.Z := v1.Z* v2.Z;
end;

function v_dot(const v1, v2 : TVec3f): Single;
begin
Result := v1.X * v2.X + v1.Y * v2.Y + v1.Z * v2.Z;
end;

function v_Div(Const V: TVec3f;Const D:Single): TVec3f; assembler; register;
var M : Single;
begin
 if D =0 then
    M:=0 else M := 1 / D;

 Result.X := V.X *M;
 Result.Y := V.Y *M;
 Result.Z := V.Z *M;
end;

function v_Cross(Const V1, v2 : TVec3f): TVec3f; //Векторное произведение векторов
begin
 Result.X := v1.Y * v2.Z - v1.Z * v2.Y;
 Result.Y := v1.Z * v2.X - v1.X * v2.Z;
 Result.Z := v1.X * v2.Y - v1.Y * v2.X;
end;

function v_length(const v: TVec3f): Single;
begin
Result := sqrt(sqr(v.X) + sqr(v.Y) + sqr(v.Z));
end;

// Расстояние между двумя точками
function v_Dist(const v1, v2 : TVec3f): single;
begin
 Result := sqrt(sqr(v2.X - v1.X) + sqr(v2.Y - v1.Y) +sqr(v2.Z - v1.Z));
end;
// Квадрат расстояния между двумя точками
// Расстояние между двумя точками
function v_Distq(const v1, v2 : TVec3f): single;
begin
 Result := sqr(v2.X - v1.X) + sqr(v2.Y - v1.Y) +sqr(v2.Z - v1.Z);
end;

function v_Normalize(const v: TVec3f): TVec3f;
var s : single;
begin
  s := sqrt(sqr(v.X) + sqr(v.Y) + sqr(v.Z));
  if s <> 0 then
     s :=  1 / s;

Result.x := v.x * s;
Result.y := v.y * s;
Result.z := v.z * s;
end;

Function v_Negative(const V: TVec3f): TVec3f;
begin
  result.X := -V.X;
  result.Y := -V.Y;
  result.Z := -V.Z;
end;

function v_normalizesafe(const inv: TVec3f; out outv: TVec3f): Single;
var len: Single;
begin
  len := v_length(inv);
  if len = 0 then
  begin
    v_clear(outv);
    Result := 0;
    Exit;
  end;

  Result := len;
  len    := 1/len;
  outv   := v_mult(inv,len);
end;

function v_Angle(const v1, v2 : TVec3f) : Single;
{Result := ArcCos(v_Dot( v_Normalize(v1), v_Normalize(v2)));}
var
  Dot,Vec3fsMagnitude : Single;
begin
  Dot := v_Dot(v1,v2);
  Vec3fsMagnitude := v_Length(v1) * v_Length(v2);
 if Dot>=Vec3fsMagnitude then Result:=0 else Result := arccos( Dot / Vec3fsMagnitude );
end;

Function V_Angle(const V:TVec3f):Single;
var
  vn   : TVec3f;
  ArCos: Single;
begin
     vn := v_normalize(v);
  ArCos := ArcCos(vn.x);
  if vn.y<0 then Result:=   -ArCos * Rad2Deg else
                 Result:=    ArCos * Rad2Deg;
end;


function v_Interpolate(const v1, v2 : TVec3f; const k: single): TVec3f;
var x:single;
begin
     x := 1/k;
Result := v_add(v1 , v_mult(v_sub(v2,v1),x));
end;

Function v_RotateX(const V : TVec3f; const ang : Single): TVec3f;
var
  radAng : Single;
begin
  radAng := ang * DEG2RAD;

  Result.x := v.x;
  Result.y := (v.y * cos(radAng)) - (v.z * sin(radAng));
  Result.z := (v.y * sin(radAng)) + (v.z * cos(radAng));
end;

Function v_RotateY(const V : TVec3f; const ang : Single): TVec3f;
var
  radAng : Single;
begin
  radAng := ang * DEG2RAD;

  Result.x := (v.x * cos(radAng)) - (v.z * sin(radAng));
  Result.y :=  v.y;
  Result.z := (v.z * sin(radAng)) + (v.x * cos(radAng));
end;

Function v_RotateZ(const V : TVec3f; const ang : Single): TVec3f;
var
  radAng : Single;
begin
  radAng := ang * DEG2RAD;

  Result.x := (v.x * cos(radAng)) - (v.y * sin(radAng));
  Result.y := (v.y * sin(radAng)) + (v.x * cos(radAng));
  Result.z :=  v.z;
end;

function v_Rotate(const V,Rot: TVec3f): TVec3f;
var
  radAng : Single;
  Ran    : array [0..2] of TVec2f;
  R      : TVec3f;
begin
//Такая форма записи хорошая но увы медленная
{ Result := v_RotateZ(v_RotateY(v_RotateX(V,Rot.x),rot.y),rot.z);}
  radAng   := Rot.x * DEG2RAD;  Ran[0].x := cos(radAng);  Ran[0].Y := sin(radang);
  radAng   := Rot.y * DEG2RAD;  Ran[1].x := cos(radAng);  Ran[1].Y := sin(radang);
  radAng   := Rot.z * DEG2RAD;  Ran[2].x := cos(radAng);  Ran[2].Y := sin(radang);

  R   := V;
  // Rotate X
  R.y := (r.y * Ran[0].x) - (r.z * Ran[0].y);
  R.z := (r.y * Ran[0].y) + (r.z * Ran[0].x);
  // Rotate Y
  R.x := (r.x * Ran[1].x) - (r.z * Ran[1].y);
  R.z := (r.z * Ran[1].y) + (r.x * Ran[1].x);
  // Rotate Z
  R.x := (r.x * Ran[2].x) - (r.y * Ran[2].y);
  R.y := (r.y * Ran[2].y) + (r.x * Ran[2].x);
  Result:=r;

end;

function V_Offset(const Heading:Single):TVec3f;
var
HD : Single;
begin
 HD       := Heading*Deg2Rad;
 Result.x := sin(hd);
 Result.y := cos(hd);
 Result.z := 0;
end;


// 2D vector's
function Vec2f(const X, Y: single): TVec2f;
begin
Result.X := X;
Result.Y := Y;
end;

Function V_add2d(const V,v2:TVec2f):TVec2f;
begin
  Result.x := v.x + v2.x;
  Result.y := v.y + v2.y;
end;

Function V_sub2d(const V,v2:TVec2f):TVec2f;
begin
  Result.x := v.x - v2.x;
  Result.y := v.y - v2.y;
end;

Function V_Length2d(const V:TVec2f):Single;
begin
  Result := sqrt(sqr(v.X) + sqr(v.Y));
end;

function v_Rotate2D(const v: TVec2f; const ang: single): TVec2f;
var
 l : single;
begin
l := sqrt(sqr(v.X) + sqr(v.Y));
  Result.X := cos(ang) * l;
  Result.Y := sin(ang) * l;
end;

end.
