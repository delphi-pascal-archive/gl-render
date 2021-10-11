unit l_math;
{$Warnings off}
{$Hints On}
(************************************)
(* SVSD_VAL                         *)
(* Last modify 05.03.08             *)
(************************************)
(* Site : SVSD.MirGames.ru          *)
(* mail : ValDim_05@Mail.ru         *)
(************************************)
(* Additions from Kavis             *)
(* Last modify 12.03.08             *)
(* Site : http://openglmax.narod.ru *)
(* Mail : kavi5@yandex.ru           *)
(************************************)

interface

type
 TVector2D = record
  X, Y     : single;
 end;

 TVector   = record
  X, Y, Z  : single;
 end;

 TVector4   = record
  case byte of
   0: (X, Y, Z,W  : single;);
   1: (xyzw : array [0..3] of single;);
 end;

 TFace = array [0..2] of WORD;
  TAabb        = Record
   MINS,MAXS   : TVector;
  end;

 TSphere = packed record
    POS   : TVector;
    Radius: Single;
 end;

 TShaderVertex = record
  Tangent,               // COL0
  Binormal,              // COL1
  Normal       : TVector;       // NRML
  TexCoord     : TVector2d;
  Pos          : TVector;
 end;

 TQuat     = record
  ImagPart : TVector;
  RealPart : Single;
 end;
 PMatrix4  = ^TMatrix4;
 TMatrix4  = array [0..3, 0..3] of single;

 TPlane    = record
  Normal   : TVector;
  V        : TVector;
  D        : single;
 end;

 TDistBool = record
  Point,Vector: TVector;
  Dist        : Single;
  Return      : Boolean;
 end;


const
 PI                            = 3.14159265358979323846;
 PI2                           = pi*2;
 RAD2DEG                       = 180/PI;
 DEG2RAD                       = PI/180;
 ELASTICITY                    = 0.05;
 FRICTION                      = 0.05;
 MATCH_FACTOR                  = 0.999;
 M_ANGLE                       = MATCH_FACTOR*(2*PI);

 EPSILON_ZERO                  = 0.0;
 EPSILON                       = 0.0001;
 EPSILON_ON_SIDE               = 0.1;
 EPSILON_VECTOR_COMPARE        = 0.00001;
 EPSILON_30                    = 1E-30;
 EPSILON_SNAP_PLANE_NORMAL     = 0.00001;
 EPSILON_SNAP_PLANE_DIST       = 0.01;

 // Identity's
 V_Identity  : TVector         = (x:0;y:0;z:0);
 V_mIdentity : TVector         = (x:1;y:1;z:1);

 P_Identity  : TPlane          = (Normal  :(x:0;y:0;z:0); V:(x:0;y:0;z:0); D: 0);
 DB_Identity : TDistBool       = (Point   :(x:0;y:0;z:0); Vector:(x:0;y:0;z:0); Dist: 0;Return:false);
 Q_Identity  : TQuat           = (ImagPart:(x:0;y:0;z:0); RealPart: 1);
 M_Identity  : TMatrix4        = ((1, 0, 0, 0), (0, 1, 0, 0), (0, 0, 1, 0), (0, 0, 0, 1));

 v_Gravity                     = 8*0.001;
 Byte2GL                       = 1/255;

  function max(const x, y: single): single;
  function min(const x, y: single): single;

 // Math
  function ArcTan2(const Y, X: single): single;
  function ArcCos (const X: single): single;
  function Tan    (const X: Extended): Extended;
  procedure SinCos(const Theta: Single; var Sin, Cos: Single); register;
  function Vector4(const X, Y, Z,W: single): TVector4;
  function v_ADD4(const V1, v2 : TVector4): TVector4;

 // 3D Vector's
  function  Vector      (const X, Y, Z: single): TVector;

  function v_Add        (const v1, v2 : TVector): TVector;
  function v_Sub        (const v1, v2 : TVector): TVector;
  function v_Mult       (const v: TVector; const d: single): TVector;
  function v_Div        (const v: TVector; const d: single): TVector;
  function v_DivV       (const v1, v2 : TVector): TVector;
  function v_MultV      (const v1, v2 : TVector): TVector;
  function v_Dist       (const v1, v2 : TVector): single;
  function v_Distq      (const v1, v2 : TVector): single;
  function v_Length     (const v: TVector): single;
  function v_Norm       (const v: TVector): Single;
  function v_Normalize  (const v: TVector): TVector;
  function v_Normalizesafe(const inv: TVector; out outv: TVector): Single;
  Function v_Negate     (const V: TVector): TVector;
  function v_Dot        (const v1, v2 : TVector): single;
  function v_Cross      (const v1, v2 : TVector): TVector;
  function v_Angle      (const v1, v2 : TVector) : real;
  function v_Angle2     (const V1, v2 : TVector): Single;
  function v_Interpolate(const v1, v2 : TVector; const k: single): TVector;
  function v_combine    (const v1, v2 : TVector; const scale : Single): TVector;
  function v_spacing    (const v1, v2 : TVector): Single;

  function v_RotateX    (const V : TVector; const ang : Single): TVector;
  function v_RotateY    (const V : TVector; const ang : Single): TVector;
  function v_RotateZ    (const V : TVector; const ang : Single): TVector;
  function v_Rotate     (const V,Rot: TVector): TVector;
  function v_Reflect    (const V,N  : TVector): TVector;

  function v_Offset     (const V1,V2:TVector):TVector;
  function v_CreateOffset(const Heading,Tilt:Single):TVector;


// 2D Vector's
  function Vector2D     (const X, Y: single): TVector2D;
  function v_Rotate2D   (const v: TVector2D; const ang: single): TVector2D;
  Function V_Length2d(V:TVector2d):Single;
  Function V_sub2d(V,v2:TVector2d):TVector2D;
  Function V_add2d(V,v2:TVector2d):TVector2D;
// Plane
  function P_Normal     (const v1, v2, v3: TVector): TVector;
  function P_Plane      (const v1, v2, v3: TVector): TPlane;
  function P_Plane2     (const Normal,v1: TVector): TPlane;
  function P_Dist       (const Pos: TVector; const Plane: TPlane): single;
  function P_Classify   (const plane: TPlane; const p: TVector): Single;
  function p_evaluate   (const plane: TPlane; const p: TVector): Single; register;
  function p_offset     (const Plane: TPlane; const Pos: TVector): TPlane;
  function P_InsideTri  (const v, v1, v2, v3: TVector): boolean;
  function P_Intersection   (const plane: TPlane; const LineStart, LineEnd: TVector): boolean;
  function P_GetIntersection(const plane: TPlane; const LineStart, LineEnd: TVector): TVector;
  function P_Angle          (const V1, V2, V3: TVector): Single;
  Function P_Determine      (const Normal: TVector): integer; //0 - Xy, 1 - Yz, 2- xZ
///////
  function EdgeSphereCollision(const Center,v1, v2, v3: TVector; const Radius: Single): Boolean;
  function ClosestPointOnLine (const vA, vB, Point: TVector): TVector;
///////
  function v_Min        (const v1,v2 : TVector): boolean;
  Function VAABBMax     (const V1,v2 : TVector): TVector;
  Function VAABBMin     (const V1,v2 : TVector): TVector;
  function v_nan        (const V ,v2 : TVector): TVector;
  function IsNaN        (const v : single) : boolean;
  Function ChangeAcc(const Acc,Normal: TVector): TVector;

  ////////////////////////////////
  // QUATERNION ROUTINES
  function Quaternion   (const X, Y, Z, W: single): TQuat;
  function Q_Matrix     (const q: TQuat): TMatrix4;
  function q_Magnitude  (const Quat: TQuat): Single;
  function q_Normalize  (const Quat: TQuat):TQuat;
  function Q_Mult       (const qL, qR: TQuat): TQuat;
  function Q_FromPoints (const V1, V2: TVector): TQuat;
  function Q_FromVector (const v: TVector; const Angle: single): TQuat;
  function Q_ToMatrix   (const Q: TQuat): TMatrix4;
  function Q_interpolate(const QStart, QEnd: TQuat; const Spin: Integer; const tx: Single): TQuat;

  ////////////////////////////////
  // MATRIX ROUTINES
  function m_CreateScaleMatrix    (const Scale : TVector): TMatrix4; overload;
  function m_CreateScaleMatrix    (const Scale : Single): TMatrix4; overload;
  function m_CreateRotationMatrixZ(const Angle : Single): TMatrix4;
  function m_CreateRotationMatrixY(const Angle : Single): TMatrix4;
  function m_CreateRotationMatrixX(const Angle : Single): TMatrix4;
  function m_CreateRotationMatrix (const Angles: TVector): TMatrix4;
  function m_SetTranslation       (const M: PMatrix4; const Translation: TVector): TMatrix4;
  function m_FromQuaternion       (const Q: TQuat): TMatrix4;
  function m_transpose            (const M: PMatrix4): TMatrix4;
  function m_TransformVector      (const V: TVector; const M: TMatrix4): TVector;
  function M_Rotation             (const v: TVector; const Angle: single): TMatrix4;
  function M_MultM                (const a, b: TMatrix4): TMatrix4;
  function M_MultV                (const m: PMatrix4; const v: TVector): TVector;
  function M_Determinant          (const M: PMatrix4): Single;
  Function M_Scale                (const M: pMatrix4; const Factor: Single): TMatrix4; register;
  Function M_Adjoint              (const M: PMatrix4): TMatrix4;
  function M_DetInternal          (const a1, a2, a3, b1, b2, b3, c1, c2, c3: Single): Single;
////////////////////////////////

  function  LineVsPolygon (const v1,v2,v3, LB,LE,vNormal : TVector):boolean;
  function  LineVsPolygon2(const v1,v2,v3, LB,LE,vNormal : TVector;Var vInt : TVector):boolean;

  function  LineInsideTri (const PointPlane1,PointPlane2,PointPlane3,BeginPoint,EndPoint: TVector): TDistBool;
  function  LineInsideTri2(const PointPlane1,PointPlane2,PointPlane3,BeginPoint,EndPoint: TVector): boolean;
  function  MinDistToLine(const Point,LinePoint1,LinePoint2: TVector): TDistBool;
  function  CollEllipsToTr(var Center: TVector; const Radius,PointPlane1,PointPlane2,PointPlane3: TVector): TDistBool;

  function uSphereFromAABB(const aabb: TAABB): TSphere;
  Function uCubeVsPoint   (const Box,Point : TVector; Size:Single):Boolean;
  Function uBoxVsPoint    (const Box,BoxSize,Point : TVector):Boolean;
  function uAABBVsPoint   (const Minx,Maxx,Pos : TVector): boolean;
  function uBoxVsBox      (const Box1,Box2, Box1Size,Box2Size : TVector): boolean;
  Function uAABBVsAABB    (const Minx1,Maxx1,Minx2,Maxx2: TVector): boolean;
  function uAABBVsSphere  (const Minx,Maxx,Pos : TVector;R:Single): boolean;
  function uCubeVsLine    (const BP,LBEGIN,LEND : TVector;BS :single): boolean;
  function uAABBVsLine    (const Mins,Maxs,StartPoint, EndPoint : TVector): boolean;
  function uSphereVsPoint (const Sphere ,Point : TVector; R: Single): boolean;
  Function uSphereVsSphere(const Sphere1,Sphere2 : TVector; R1,R2 : Single) : boolean;
  function uSphereVsLine  (const Sphere ,LB,LE : TVector;R: Single): boolean;
  function uSphereVsLine2 (const Sphere, P1,P2 : TVector;R: Single): boolean;

///////////////
  // Shaders //
  procedure CalculateTandB      (var T, B: TVector; const st1, st2: TVector2d; const P, Q: TVector);
  procedure CalculateTangents   (var v1, v2, v3: TShaderVertex);
  Procedure CreateTangentVectorSpace(const v1, v2, v3 : TVector; Const T1,T2,T3:TVector2D; Var tangent, binormal,normal:TVector);
  function  dotVecLengthSquared3(v: TVector): Single;
  procedure dotVecNormalize3    (var v: TVector);


  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //   Additions from Kavis                                                    /
  //   kavi5@yandex.ru                                                         /
  //   http://openglmax.narod.ru                                               /
  //   12.03.08 23:50                                                          /
  //////////////////////////////////////////////////////////////////////////////
  Function V_VectorLen(var V: TVector; newLen: Single): Single;
  Function FindIntersection(P1, P2, P3: TVector; P: TVector; V: TVector; var I: TVector): single;

  //SVSD_VAL
  procedure ComputeNormalsTrianglesStrip(var NA: array of TVector; Const VA: array of TVector; const IA:array of TFace);
  Function  FindFastAngle      (Const Pos,Target:TVector;Const Heading:Single):Single;

implementation


function ArcSin(const X: Extended): Extended;
begin
  Result := ArcTan2(X, Sqrt(1 - X * X))
end;

function RadToDeg(const Radians: Extended): Extended;  { Degrees := Radians * 180 / PI }
begin
  Result := Radians * (180 / PI);
end;

Function GetAngle(POS1,POS2:TVector):Single;
var
  VLeng,Cosns,Sins,ArCos: Single;
begin
  VLeng:=Sqrt(Sqr(POS2.x-POS1.x)+Sqr(POS2.z-POS1.z));
  if VLeng <> 0 then
  VLeng:= 1 / VLeng;
  Cosns:=(POS2.x-POS1.x)*VLeng;
  Sins :=(POS2.z-POS1.z)*VLeng;
  ArCos:=ArcCos(Cosns);
  if Sins<0 then Result:=360-RadToDeg(ArCos) else Result:=RadToDeg(ArCos);
end;

Function   FindFastAngle      (Const Pos,Target:TVector;Const Heading:Single):Single;
var
 Ran,RealRan,
 rr,rr2,rr3 : Single;
begin
          // Получаем угол
          RealRan  := - GetAngle(Pos,Target)+180;
          Ran      := Heading;

       // Выравниваем его чтоб он унас был в пределах 360
       if abs(Ran) > 360 then Ran := Ran - trunc(Ran / 360)*360;

          // Получаем на сколько её повернуть
          rr3   :=      RealRan - Ran;
          rr2   := (360+RealRan)- Ran;

          // Выбираем к какому из них легче повернуть
          if ABS(RR2) > abs(rr3) then
           rr := rr3 else rr := rr2;

          // тепер переделываем всё под наши нужды
          if Abs(rr) > 180 then rr := -(360-rr);
 // Возвращаем то что нам надо
 Result:=RR;
end;


procedure ComputeNormalsTrianglesStrip(var NA: array of TVector; Const VA: array of TVector; const IA:array of TFace);
var
  i: Integer;
  Normal: TVector;
begin
  for i:=0 to High(IA)-2 do
  begin
//    if (IA[i][0]=IA[i][1]) or (IA[i][0]=IA[i][2]) or (IA[i][1]=IA[i][2]) then Continue;
    Normal:=P_Normal(VA[IA[i][0]], VA[IA[i][1]], VA[IA[i][2]]);
    if i mod 2 = 1 then v_mult(Normal,- 1);

    NA[IA[i][0]] :=V_Add(VA[IA[i][0]], V_Mult(Normal, P_Angle(VA[IA[i][0]], VA[IA[i][1]], VA[IA[i][2]]) ) );
    NA[IA[i][1]] :=V_Add(VA[IA[i][1]], V_Mult(Normal, P_Angle(VA[IA[i][1]], VA[IA[i][2]], VA[IA[i][0]]) ) );
    NA[IA[i][2]] :=V_Add(VA[IA[i][2]], V_Mult(Normal, P_Angle(VA[IA[i][2]], VA[IA[i][0]], VA[IA[i][1]]) ) );


  end;
  for i:=0 to High(VA) do NA[i]:=V_Normalize(NA[i]);
end;

function V_CreateOffset(const Heading,Tilt:Single):TVector;
var
HD,TL  :Single;
begin
HD     := (Heading-90)*(pi/180);
TL     :=  Tilt*(pi/180);
Result := vector(cos(hd) * cos(tl),
                 sin(-tl),
                 sin(hd) * cos(tl));

end;

function V_Offset(const V1,V2:TVector):TVector;
begin
Result:= V_div(V_sub(V2,V1),
               V_DIST(V1,V2));
end;

Function ChangeAcc(const Acc,Normal: TVector): TVector;
Var
D    : Single;
VN,VT: TVector;
begin

D := (acc.x * Normal.x) + (acc.y * Normal.y) + (acc.z * Normal.z);
     Vn := v_Mult(Normal,D-0.05);
     Vt := v_Sub (Acc,Vn);
 Result := v_add (v_mult(Vt ,(1.0 - Friction) ),v_mult(Vn, -Elasticity) );
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
function Vector(const X, Y, Z: single): TVector;
begin
Result.X := X;
Result.Y := Y;
Result.Z := Z;
end;

function Vector4(const X, Y, Z,W: single): TVector4;
begin
Result.X := X;
Result.Y := Y;
Result.Z := Z;
Result.W := W;
end;

{
Function v_Clear: TVector;
asm
  mov [edx  ], 0
  mov [edx+4], 0
  mov [edx+8], 0
end;

procedure v_clear2(var v: TVector);
asm
  XOR EDX, EDX
  MOV [EAX], EDX
  MOV [EAX+4], EDX
  MOV [EAX+8], EDX
end;
}
{------------------------------------------------------------------------------}
function v_Min(const v1,v2 : TVector): boolean;
begin
if (v1.X < v2.X) and
   (v1.Y < v2.Y) and
   (v1.Z < v2.Z) then result:=true else result:=false;
end;

Function VAABBMin(const V1,v2 : TVector): TVector;
begin
if (v1.x < v2.X) then result.x := v1.X else result.x := v2.X;
if (v1.y < v2.y) then result.y := v1.y else result.y := v2.y;
if (v1.z < v2.z) then result.z := v1.z else result.z := v2.z;
end;

Function VAABBMax(const V1,v2 : TVector): TVector;
begin
if (v1.x > v2.X) then result.x := v1.X else result.x := v2.X;
if (v1.y > v2.y) then result.y := v1.y else result.y := v2.y;
if (v1.z > v2.z) then result.z := v1.z else result.z := v2.z;
end;

function v_nan(const V,v2 : TVector): TVector;
begin
    asm
      mov [ecx  ], 0
      mov [ecx+4], 0
      mov [ecx+8], 0
    end;
if not isnan(v.x) then result.x :=v.x else result.x :=v2.x;
if not isnan(v.y) then result.y :=v.y else result.y :=v2.y;
if not isnan(v.z) then result.z :=v.z else result.z :=v2.z;
end;
{------------------------------------------------------------------------------}

function v_Sub(const V1, v2 : TVector): TVector; assembler; register;
{Result.X := V1.X-V2.X;
 Result.Y := V1.Y-V2.Y;
 Result.Z := V1.Z-V2.Z;}
asm
      FLD DWORD PTR [EAX]    // V1.X
      FSUB DWORD PTR [EDX]   // - V2.X
      FSTP DWORD PTR [ECX]   // Result :=
      FLD DWORD PTR [EAX + 4]
      FSUB DWORD PTR [EDX + 4]
      FSTP DWORD PTR [ECX + 4]
      FLD DWORD PTR [EAX + 8]
      FSUB DWORD PTR [EDX + 8]
      FSTP DWORD PTR [ECX + 8]
end;

function v_ADD4(const V1, v2 : TVector4): TVector4;
begin
 Result.X := V1.X+V2.X;
 Result.Y := V1.Y+V2.Y;
 Result.Z := V1.Z+V2.Z;
 Result.w := 1;
end;


function v_ADD(const V1, v2 : TVector): TVector; assembler; register;
{Result.X := V1.X+V2.X;
 Result.Y := V1.Y+V2.Y;
 Result.Z := V1.Z+V2.Z;}
asm

      FLD DWORD PTR [EAX]
      FADD DWORD PTR [EDX]
      FSTP DWORD PTR [ECX]
      FLD DWORD PTR [EAX + 4]
      FADD DWORD PTR [EDX + 4]
      FSTP DWORD PTR [ECX + 4]
      FLD DWORD PTR [EAX + 8]
      FADD DWORD PTR [EDX + 8]
      FSTP DWORD PTR [ECX + 8]
end;
function v_mult(const v: TVector; const D: Single): TVector;
{Result.X := V.X*D;
 Result.Y := V.Y*D;
 Result.Z := V.Z*D;}
asm
      FLD  DWORD PTR [EAX]
      FMUL DWORD PTR [EBP+8]
      FSTP DWORD PTR [EDX]
      FLD  DWORD PTR [EAX+4]
      FMUL DWORD PTR [EBP+8]
      FSTP DWORD PTR [EDX+4]
      FLD  DWORD PTR [EAX+8]
      FMUL DWORD PTR [EBP+8]
      FSTP DWORD PTR [EDX+8]
end;

function v_MultV(const v1, v2 : TVector): TVector; assembler; register;
{Result.X := A.X*B.X;
 Result.Y := A.Y*B.Y;
 Result.Z := A.Z*B.Z;}
asm
      FLD DWORD PTR [EAX]
      FMul DWORD PTR [EDX]
      FSTP DWORD PTR [ECX]
      FLD DWORD PTR [EAX + 4]
      FMul DWORD PTR [EDX + 4]
      FSTP DWORD PTR [ECX + 4]
      FLD DWORD PTR [EAX + 8]
      FMul DWORD PTR [EDX + 8]
      FSTP DWORD PTR [ECX + 8]
end;
function v_dot(const v1, v2 : TVector): Single;
// EAX contains address of V1 что то пробило меня на ремарки :D
// EDX contains address of V2
// ST(0) contains the result
{Result := v1.X * v2.X + v1.Y * v2.Y + v1.Z * v2.Z;}
asm

      FLD DWORD PTR [EAX]
      FMUL DWORD PTR [EDX]
      FLD DWORD PTR [EAX + 4]
      FMUL DWORD PTR [EDX + 4]
      FADDP
      FLD DWORD PTR [EAX + 8]
      FMUL DWORD PTR [EDX + 8]
      FADDP
end;

function v_DivV(const v1, v2 : TVector): TVector; assembler; register;
{Result.X := A.X*B.X;
 Result.Y := A.Y*B.Y;
 Result.Z := A.Z*B.Z;}
asm
      FLD DWORD PTR [EAX]
      fdiv DWORD PTR [EDX]
      FSTP DWORD PTR [ECX]
      FLD DWORD PTR [EAX + 4]
      Fdiv DWORD PTR [EDX + 4]
      FSTP DWORD PTR [ECX + 4]
      FLD DWORD PTR [EAX + 8]
      Fdiv DWORD PTR [EDX + 8]
      FSTP DWORD PTR [ECX + 8]
end;

function v_Div(Const V: TVector;Const D:Single): TVector; assembler; register;
{if d=0 then exit;
 Result.X := V.X/D;
 Result.Y := V.Y/D;
 Result.Z := V.Z/D;}
asm
      mov [edx  ], 0
      mov [edx+4], 0
      mov [edx+8], 0
      cmp [ebp+8],0
          jz @@exit1

      FLD  DWORD PTR [EAX]
      Fdiv DWORD PTR [EBP+8]
      FSTP DWORD PTR [EDX]
      FLD  DWORD PTR [EAX+4]
      Fdiv DWORD PTR [EBP+8]
      FSTP DWORD PTR [EDX+4]
      FLD  DWORD PTR [EAX+8]
      Fdiv DWORD PTR [EBP+8]
      FSTP DWORD PTR [EDX+8]
 @@exit1:
end;

function v_Cross(Const V1, v2 : TVector): TVector; //Векторное произведение векторов
{Result.X := v1.Y * v2.Z - v1.Z * v2.Y;
 Result.Y := v1.Z * v2.X - v1.X * v2.Z;
 Result.Z := v1.X * v2.Y - v1.Y * v2.X;}
var Temp: TVector;
asm

      PUSH EBX                      // сохраняем EBX, всї должно бvть восстановлено в оригинальнуі величину
      LEA EBX, [Temp]
      FLD DWORD PTR [EDX + 8]       // Cперва загружаем все вектора в регистры FPU
      FLD DWORD PTR [EDX + 4]
      FLD DWORD PTR [EDX + 0]
      FLD DWORD PTR [EAX + 8]
      FLD DWORD PTR [EAX + 4]
      FLD DWORD PTR [EAX + 0]

      FLD ST(1)                     // ST(0) := V1.Y
      FMUL ST, ST(6)                // ST(0) := V1.Y * V2.Z
      FLD ST(3)                     // ST(0) := V1.Z
      FMUL ST, ST(6)                // ST(0) := V1.Z * V2.Y
      FSUBP ST(1), ST               // ST(0) := ST(1)-ST(0)
      FSTP DWORD [EBX]              // Temp.X := ST(0)
      FLD ST(2)                     // ST(0) := V1.Z
      FMUL ST, ST(4)                // ST(0) := V1.Z * V2.X
      FLD ST(1)                     // ST(0) := V1.X
      FMUL ST, ST(7)                // ST(0) := V1.X * V2.Z
      FSUBP ST(1), ST               // ST(0) := ST(1)-ST(0)
      FSTP DWORD [EBX + 4]          // Temp.Y := ST(0)
      FLD ST                        // ST(0) := V1.X
      FMUL ST, ST(5)                // ST(0) := V1.X * V2.Y
      FLD ST(2)                     // ST(0) := V1.Y
      FMUL ST, ST(5)                // ST(0) := V1.Y * V2.X
      FSUBP ST(1), ST               // ST(0) := ST(1)-ST(0)
      FSTP DWORD [EBX + 8]          // Temp.Z := ST(0)
      FSTP ST(0)                    // чистим регистры FPU
      FSTP ST(0)
      FSTP ST(0)
      FSTP ST(0)
      FSTP ST(0)
      FSTP ST(0)
      MOV EAX, [EBX]                // переносим всё с Temp в Result
      MOV [ECX], EAX
      MOV EAX, [EBX + 4]
      MOV [ECX + 4], EAX
      MOV EAX, [EBX + 8]
      MOV [ECX + 8], EAX
      POP EBX
end;
(* эх показываю вам два экземпляра второй быстрее ибо нет лопов
function v_Length(Const V: tvector): Single; assembler;
{Result := sqrt(sqr(v.X) + sqr(v.Y) + sqr(v.Z));}
asm
        mov edx, 2
        FLDZ
@@Loop: FLD  DWORD PTR [EAX  +  4 * EDX]
        FMUL ST, ST
        FADDP
        SUB  EDX, 1
        JNL  @@Loop
        FSQRT
end;
*)

function v_length(const v: TVector): Single;
// EAX contains address of V
// result is passed in ST(0)
{Result := sqrt(sqr(v.X) + sqr(v.Y) + sqr(v.Z));}
asm
      FLD  DWORD PTR [EAX]
      FMUL ST, ST
      FLD  DWORD PTR [EAX+4]
      FMUL ST, ST
      FADDP
      FLD  DWORD PTR [EAX+8]
      FMUL ST, ST
      FADDP
      FSQRT
end;

function v_norm(const v: TVector): Single;
// EAX contains address of V
// result is passed in ST(0)
{Result := sqr(v.X) + sqr(v.Y) + sqr(v.Z);}
asm
      FLD  DWORD PTR [EAX]
      FMUL ST, ST
      FLD  DWORD PTR [EAX+4]
      FMUL ST, ST
      FADDP
      FLD  DWORD PTR [EAX+8]
      FMUL ST, ST
      FADDP
end;

// Расстояние между двумя точками
function v_Dist(const v1, v2 : TVector): single;
// EAX contains address of v1
// EDX contains highest of v2
// Result  is passed on the stack
// Result := sqrt(sqr(v2.X - v1.X) + sqr(v2.Y - v1.Y) +sqr(v2.Z - v1.Z));
asm
      FLD  DWORD PTR [EAX]
      FSUB DWORD PTR [EDX]
      FMUL ST, ST
      FLD  DWORD PTR [EAX+4]
      FSUB DWORD PTR [EDX+4]
      FMUL ST, ST
      FADD
      FLD  DWORD PTR [EAX+8]
      FSUB DWORD PTR [EDX+8]
      FMUL ST, ST
      FADD
      FSQRT
end;


// Квадрат расстояния между двумя точками
// Расстояние между двумя точками
function v_Distq(const v1, v2 : TVector): single;
// EAX contains address of v1
// EDX contains highest of v2
// Result  is passed on the stack
// Result := sqr(v2.X - v1.X) + sqr(v2.Y - v1.Y) +sqr(v2.Z - v1.Z);
asm
      FLD  DWORD PTR [EAX]
      FSUB DWORD PTR [EDX]
      FMUL ST, ST
      FLD  DWORD PTR [EAX+4]
      FSUB DWORD PTR [EDX+4]
      FMUL ST, ST
      FADD
      FLD  DWORD PTR [EAX+8]
      FSUB DWORD PTR [EDX+8]
      FMUL ST, ST
      FADD
end;


function v_spacing(const v1, v2 : TVector): Single;
// EAX contains address of v1
// EDX contains highest of v2
// Result  is passed on the stack
// Result:=Abs(v2.x-v1.x)+Abs(v2.y-v1.y)+Abs(v2.z-v1.z);
asm
      FLD  DWORD PTR [EAX]
      FSUB DWORD PTR [EDX]
      FABS
      FLD  DWORD PTR [EAX+4]
      FSUB DWORD PTR [EDX+4]
      FABS
      FADD
      FLD  DWORD PTR [EAX+8]
      FSUB DWORD PTR [EDX+8]
      FABS
      FADD
end;

function v_combine(const v1, v2 : TVector; const scale : Single): TVector;
// EAX contains address of v1
// EDX contains address of v2
// EBP+8 contains address of scale
// ECX contains address of Result
asm
      FLD  DWORD PTR [EDX]
      FMUL DWORD PTR [EBP+8]
      FADD DWORD PTR [EAX]
      FSTP DWORD PTR [ECX]

      FLD  DWORD PTR [EDX+4]
      FMUL DWORD PTR [EBP+8]
      FADD DWORD PTR [EAX+4]
      FSTP DWORD PTR [ECX+4]

      FLD  DWORD PTR [EDX+8]
      FMUL DWORD PTR [EBP+8]
      FADD DWORD PTR [EAX+8]
      FSTP DWORD PTR [ECX+8]
end;

function v_Normalize(const v: TVector): TVector;
// EAX contains address of V1
// EDX contains the result
{
var s : Extended;
begin
s :=  1 / sqrt(sqr(v.X) + sqr(v.Y) + sqr(v.Z));

Result.x := v.x * s;
Result.y := v.y * s;
Result.z := v.z * s;
end;
}
asm
      // V_Length
      FLD  DWORD PTR [EAX]
      FMUL ST, ST
      FLD  DWORD PTR [EAX+4]
      FMUL ST, ST
      FADD
      FLD  DWORD PTR [EAX+8]
      FMUL ST, ST
      FADD
      FSQRT
      // if V_length(v) = 0 then jump to exit;
      // push eax
      mov ecx , eax // незделаем это хана умножению :)
      FTST
      FSTSW AX
      Sahf
      mov eax , ecx
      // pop eax
      jz @@Exit

      // V_Mult
      FLD1
      FDIVR
      FLD  ST
      FMUL DWORD PTR [EAX]
      FSTP DWORD PTR [EDX]
      FLD  ST
      FMUL DWORD PTR [EAX+4]
      FSTP DWORD PTR [EDX+4]
      FMUL DWORD PTR [EAX+8]
      FSTP DWORD PTR [EDX+8]

      jmp @@exit2

      @@Exit:
      //result:=vector(0,0,0);
      FST  DWORD PTR [EDX]
      FST  DWORD PTR [EDX+4]
      FSTP DWORD PTR [EDX+8]
      @@exit2:
end;

function v_Angle2(const V1, v2 : TVector): Single;  //Скалярное произведение векторов
// Result = v_Dot(V1, V2) / (v_Length(V1) * v_Length(V2))
asm
      FLD DWORD PTR [EAX]           // V1.x
      FLD ST                        // double V1.x
      FMUL ST, ST                   // V1.x^2 (prep. for divisor)
      FLD DWORD PTR [EDX]           // V2.x
      FMUL ST(2), ST                // ST(2) := V1.x * V2.x
      FMUL ST, ST                   // V2.x^2 (prep. for divisor)
      FLD DWORD PTR [EAX + 4]       // V1.y
      FLD ST                        // double V1.y
      FMUL ST, ST                   // ST(0) := V1.y^2
      FADDP ST(3), ST               // ST(2) := V1.x^2 + V1.y *  * 2
      FLD DWORD PTR [EDX + 4]       // V2.y
      FMUL ST(1), ST                // ST(1) := V1.y * V2.y
      FMUL ST, ST                   // ST(0) := V2.y^2
      FADDP ST(2), ST               // ST(1) := V2.x^2 + V2.y^2
      FADDP ST(3), ST               // ST(2) := V1.x * V2.x + V1.y * V2.y
      FLD DWORD PTR [EAX + 8]       // load V2.y
      FLD ST                        // same calcs go here
      FMUL ST, ST                   // (compare above)
      FADDP ST(3), ST
      FLD DWORD PTR [EDX + 8]
      FMUL ST(1), ST
      FMUL ST, ST
      FADDP ST(2), ST
      FADDP ST(3), ST
      FMULP                         // ST(0) := (V1.x^2 + V1.y^2 + V1.z) *
                                    //          (V2.x^2 + V2.y^2 + V2.z)
      FSQRT                         // sqrt(ST(0))
      FDIVP                         // ST(0) := Result := ST(1) / ST(0)
                                    // the result is expected in ST(0), if it's invalid, an error is raised
end;

function v_Reflect(const V, N: TVector): TVector;
  {     Dot := v_Dot(V, N);
   Result.X := V.X-2 * Dot * N.X;
   Result.Y := V.Y-2 * Dot * N.Y;
   Result.Z := V.Z-2 * Dot * N.Z;}
asm
      CALL v_Dot                    // dot is now in ST(0)
      FCHS                          // -dot
      FADD ST, ST                   // -dot * 2
      FLD DWORD PTR [EDX]           // ST := N.x
      FMUL ST, ST(1)                // ST := -2 * dot * N.x
      FADD DWORD PTR[EAX]           // ST := V.x - 2 * dot * N.x
      FSTP DWORD PTR [ECX]          // store result
      FLD DWORD PTR [EDX + 4]       // etc.
      FMUL ST, ST(1)
      FADD DWORD PTR[EAX + 4]
      FSTP DWORD PTR [ECX + 4]
      FLD DWORD PTR [EDX + 8]
      FMUL ST, ST(1)
      FADD DWORD PTR[EAX + 8]
      FSTP DWORD PTR [ECX + 8]
      FSTP ST                       // clean FPU stack
end;

Function v_Negate(const V: TVector): TVector;
 {V.X := -V.X;
  V.Y := -V.Y;
  V.Z := -V.Z;}
asm
  FLD DWORD PTR [EAX]
  FCHS // WAIT
  FSTP DWORD PTR [EDX]
  FLD DWORD PTR [EAX+4]
  FCHS // WAIT
  FSTP DWORD PTR [EDX+4]
  FLD DWORD PTR [EAX+8]
  FCHS // WAIT
  FSTP DWORD PTR [EDX+8]
end;

function v_normalizesafe(const inv: TVector; out outv: TVector): Single;
var len: Single;
begin
  len := v_length(inv);
  if len = 0 then
  begin
    outv := v_Identity;
    Result := 0;
    Exit;
  end;

  Result := len;
  len    := 1/len;
  outv   := v_mult(inv,len);
end;

function v_Angle(const v1, v2 : TVector) : real;
{Result := ArcCos(v_Dot( v_Normalize(v1), v_Normalize(v2)));}
var
  Dot,VectorsMagnitude : Single;
begin
  Dot := v_Dot(v1,v2);
  VectorsMagnitude := v_Length(v1) * v_Length(v2);
 if Dot>=VectorsMagnitude then Result:=0 else Result := arccos( Dot / VectorsMagnitude );
end;


Function V_RadAngleY(const V1 , V2 : TVector):Single;
var
Angle,
 p : TVector;

begin
// Угол отсносительно Y
if v_dist(V1,V2)<1 then exit;
p.X := V2.X - V1.X;
p.Y := 0;
p.Z := V2.Z - V1.Z;
Angle.Y := V_Angle(Vector(1, 0, 0), p);
if p.Z < 0 then Angle.Y := 2 * pi - Angle.Y;
if (Angle.Y) > pi then Angle.Y := Angle.Y + pi * 2;

// Угол относительно X
p.Y := V2.Y - V1.Y;
Angle.X := V_Angle(Vector(p.X, 0, p.Z), p);
if p.Y < 0 then Angle.X := 2 * pi - Angle.X;
if (Angle.X) > pi then Angle.X := Angle.X + pi * 2;
end;


function v_Interpolate(const v1, v2 : TVector; const k: single): TVector;
var x:single;
begin
     x := 1/k;
Result := v_add(v1 , v_mult(v_sub(v2,v1),x));
end;

Function v_RotateX(const V : TVector; const ang : Single): TVector;
var
  radAng : Single;
begin
  radAng := ang * DEG2RAD;

  Result.x := v.x;
  Result.y := (v.y * cos(radAng)) - (v.z * sin(radAng));
  Result.z := (v.y * sin(radAng)) + (v.z * cos(radAng));
end;

Function v_RotateY(const V : TVector; const ang : Single): TVector;
var
  radAng : Single;
begin
  radAng := ang * DEG2RAD;

  Result.x := (v.x * cos(radAng)) - (v.z * sin(radAng));
  Result.y :=  v.y;
  Result.z := (v.z * sin(radAng)) + (v.x * cos(radAng));
end;

Function v_RotateZ(const V : TVector; const ang : Single): TVector;
var
  radAng : Single;
begin
  radAng := ang * DEG2RAD;

  Result.x := (v.x * cos(radAng)) - (v.y * sin(radAng));
  Result.y := (v.y * sin(radAng)) + (v.x * cos(radAng));
  Result.z :=  v.z;
end;

function v_Rotate(const V,Rot: TVector): TVector;
var
  radAng : Single;
  Ran    : array [0..2] of TVector2D;
  R      : TVector;
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

// 2D Vector's
function Vector2D(const X, Y: single): TVector2D;
begin
Result.X := X;
Result.Y := Y;
end;

Function V_add2d(V,v2:TVector2d):TVector2D;
begin
  Result.x := v.x + v2.x;
  Result.y := v.y + v2.y;
end;

Function V_sub2d(V,v2:TVector2d):TVector2D;
begin
  Result.x := v.x - v2.x;
  Result.y := v.y - v2.y;
end;

Function V_Length2d(V:TVector2d):Single;
begin
  Result := sqrt(sqr(v.X) + sqr(v.Y));
end;

function v_Rotate2D(const v: TVector2D; const ang: single): TVector2D;
var
 l : single;
begin
l := sqrt(sqr(v.X) + sqr(v.Y));
  Result.X := cos(ang) * l;
  Result.Y := sin(ang) * l;
end;


// Plane
function P_Normal(const v1, v2, v3: TVector): TVector;
begin
Result := v_Normalize( v_Cross( v_Sub(v3, v2), v_Sub(v2, v1) )) ;
end;

function P_Plane(const v1, v2, v3: TVector): TPlane;
begin
Result.Normal := P_Normal(v1, v2, v3);
Result.D      := -v_Dot(Result.Normal, v1);
Result.V      := v1;
end;

function P_Plane2(const Normal,v1: TVector): TPlane;
begin
result.Normal := Normal;
result.d      := -v_Dot(Normal, v1);
Result.V      := v1;
end;

function P_Dist(const Pos: TVector; const Plane: TPlane): single;
begin
Result := (v_Dot(Plane.Normal, Pos) + Plane.D);
end;

function P_Classify(const plane: TPlane; const p: TVector): Single;
begin
Result := Plane.Normal.X * (p.x - plane.V.x) + Plane.Normal.Y * (p.y - plane.V.y) + Plane.Normal.Z * (p.z - plane.V.z);
//Result := v_Dot(Plane.Normal, v_Sub(Pos, Plane.V));
end;

function p_evaluate(const plane: TPlane; const p: TVector): Single; register;
// EAX contains address of plane
// EDX contains address of point
// result is stored in ST(0)
asm
  FLD DWORD PTR [EAX]
  FMUL DWORD PTR [EDX]
  FLD DWORD PTR [EAX + 4]
  FMUL DWORD PTR [EDX + 4]
  FADDP
  FLD DWORD PTR [EAX + 8]
  FMUL DWORD PTR [EDX + 8]
  FADDP
  FLD DWORD PTR [EAX + 16]
  FADDP
end;

function p_offset(const Plane: TPlane; const Pos: TVector): TPlane;
begin
  Result.Normal := Plane.Normal;
  Result.D := -(Plane.D + v_dot(Plane.Normal, Pos));
end;

function P_Angle(const V1, V2, V3: TVector): Single;
var v,vv:TVector;
begin
  V:=V_Sub(V1, V2);
  Vv:=V_Sub(V1, V3);
  Result:=arccos(V_Dot(V, Vv)/(V_length(V)*V_Length(Vv)));
end;

Function  P_Intersection(const plane: TPlane; const LineStart, LineEnd: TVector): boolean;
var
	Sign , Sign1 : Single;
begin
	sign  := P_Dist( LineStart , plane);
	sign1 := P_Dist( LineEnd   , plane);
	result := ( ((sign < 0) and (sign1 > 0)) or ((sign > 0) and (sign1 <=0)) );
end;

Function  P_GetIntersection(const plane: TPlane; const LineStart, LineEnd: TVector): TVector;
var
  ptDirection : TVector;
  denominator : single;
  D           : single;
begin
	ptDirection := v_sub( LineEnd, LineStart );
	denominator := v_Dot( plane.Normal, ptDirection );
        Result:=LineEnd;

	if denominator = 0 then exit;

	D := ( plane.D - v_Dot( plane.normal, LineStart )) / denominator;
	ptDirection := v_mult( ptDirection,  D);
	result      := v_add(LineStart, ptDirection);
end;

Function P_Determine(const Normal: TVector): integer; //0 - Xy, 1 - Yz, 2- xZ
begin
  Result := -1;
  if (abs(Normal.x) >= abs(Normal.y)) and (abs(Normal.x) >= abs(normal.z)) then  Result := 1; //YZ plane
  if (abs(Normal.y) >= abs(Normal.x)) and (abs(Normal.y) >= abs(normal.z)) then  Result := 2; //XZ Plane
  if (abs(Normal.z) >= abs(Normal.x)) and (abs(Normal.z) >= abs(normal.y)) then  Result := 0; //XY Plane

end;


function P_InsideTri(const v, v1, v2, v3: TVector): boolean;
var
 i      : Integer;
 Angle  : Double;
 vec    : array [0..2] of TVector;
begin
Result := False;
vec[0] := v_Sub(v1, v);
vec[1] := v_Sub(v2, v);
vec[2] := v_Sub(v3, v);
Angle := 0;
for i := 0 to 2 do
 Angle := Angle + v_Angle(vec[i], vec[(i + 1) mod 3]);
	if(Angle >= M_angle )	then
 Result := true;
end;

////////////////////////////////////////////////////////////////////////////////

// 3D Vector's & Martix's
//------------------------------------------------------------------------------
// QUATERNION ROUTINES
//------------------------------------------------------------------------------
function Quaternion(const X, Y, Z, W: single): TQuat;
begin
Result.ImagPart.X := X;
Result.ImagPart.Y := Y;
Result.ImagPart.Z := Z;
Result.RealPart   := W;
end;

function Q_Matrix(const q: TQuat): TMatrix4;
var
 wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2 : single;
 m : Tmatrix4;
begin
with q.ImagPart do
 begin
 x2 := x + x;   y2 := y + y;   z2 := z + z;
 xx := x * x2;  xy := x * y2;  xz := x * z2;
 yy := y * y2;  yz := y * z2;  zz := z * z2;
 end;

 wx := q.RealPart * x2;  wy := q.RealPart * y2;  wz := q.RealPart * z2;

m[0][0] := 1 - (yy + zz);  m[0][1] := xy + wz;        m[0][2] := xz - wy;
m[1][0] := xy - wz;        m[1][1] := 1 - (xx + zz);  m[1][2] := yz + wx;
m[2][0] := xz + wy;        m[2][1] := yz - wx;        m[2][2] := 1 - (xx + yy);

m[0][3] := 0;
m[1][3] := 0;
m[2][3] := 0;
m[3][0] := 0;
m[3][1] := 0;
m[3][2] := 0;
m[3][3] := 1;
result  := m;
end;

function q_Magnitude(const Quat: TQuat): Single;
begin
  Result := Sqrt(v_dot(Quat.ImagPart, Quat.ImagPart) + Sqr(Quat.RealPart));
end;

function q_Normalize(const Quat: TQuat):TQuat;
var m, f: Single;
begin
  m := q_Magnitude(Quat);

  if m > EPSILON_30 then
  begin
    f := 1 / m;
    Result.ImagPart := v_mult(Quat.ImagPart, f);
    Result.RealPart := Quat.RealPart * f;
  end
  else
    Result := Q_Identity;
end;

function Q_Mult(const qL, qR: TQuat): TQuat;
var Temp : TQuat;
begin
  Temp.RealPart := qL.RealPart * qR.RealPart - qL.ImagPart.x * qR.ImagPart.x -
                   qL.ImagPart.y * qR.ImagPart.y - qL.ImagPart.z * qR.ImagPart.z;
  Temp.ImagPart.x := qL.RealPart * qR.ImagPart.x + qL.ImagPart.x * qR.RealPart +
                      qL.ImagPart.y * qR.ImagPart.z - qL.ImagPart.z * qR.ImagPart.y;
  Temp.ImagPart.y := qL.RealPart * qR.ImagPart.y + qL.ImagPart.y * qR.RealPart +
                      qL.ImagPart.z * qR.ImagPart.x - qL.ImagPart.x * qR.ImagPart.z;
  Temp.ImagPart.z := qL.RealPart * qR.ImagPart.z + qL.ImagPart.z * qR.RealPart +
                      qL.ImagPart.x * qR.ImagPart.y - qL.ImagPart.y * qR.ImagPart.x;
  Result := Temp;
end;

function Q_ToMatrix(const Q: TQuat): TMatrix4;
// Constructs rotation matrix from (possibly non-unit) quaternion.
// Assumes matrix is used to multiply column vector on the left:
// vnew = mat vold.  Works correctly for right-handed coordinate system
// and right-handed rotations.
var
  V : TVector;
  SinA, CosA,
  A, B, C: Single;

begin
  V := Q.ImagPart;
  V := V_Normalize(V);
  SinCos(Q.RealPart / 2, SinA, CosA);
  A := V.x * SinA;
  B := V.y * SinA;
  C := V.z * SinA;

  Result := M_Identity;
  Result[0, 0] := 1 - 2 * B * B - 2 * C * C;
  Result[0, 1] := 2 * A * B - 2 * CosA * C;
  Result[0, 2] := 2 * A * C + 2 * CosA * B;

  Result[1, 0] := 2 * A * B + 2 * CosA * C;
  Result[1, 1] := 1 - 2 * A * A - 2 * C * C;
  Result[1, 2] := 2 * B * C - 2 * CosA * A;

  Result[2, 0] := 2 * A * C - 2 * CosA * B;
  Result[2, 1] := 2 * B * C + 2 * CosA * A;
  Result[2, 2] := 1 - 2 * A * A - 2 * B * B;
end;

function Q_FromVector(const v: TVector; const Angle: single): TQuat;
var
 s, c : single;
begin
c := Angle*0.5;
s := sin(c);
Result.ImagPart.X := v.X * s;
Result.ImagPart.Y := v.Y * s;
Result.ImagPart.Z := v.Z * s;
Result.RealPart   := cos(c);
end;

function Q_FromPoints(const V1, V2: TVector): TQuat;
// constructs a unit quaternion from two points on unit sphere
// EAX contains address of V1
// ECX contains address to result
// EDX contains address of V2
asm
  {Result.ImagPart := V_Cross(V1, V2);
   Result.RealPart :=  Sqrt((V_Dot(V1, V2) + 1)/2);}
              PUSH EAX
              CALL V_Cross                  // determine axis to rotate about
              POP EAX
              FLD1                          // prepare next calculation
              Call V_Dot                    // calculate cos(angle between V1 and V2)
              FADD ST, ST(1)                // transform angle to angle/2 by: cos(a/2)=sqrt((1 + cos(a))/2)
              FXCH ST(1)
              FADD ST, ST
              FDIVP ST(1), ST
              FSQRT
              FSTP DWORD PTR [ECX + 12]     // Result.RealPart := ST(0)
end;

function Q_interpolate(const QStart, QEnd: TQuat; const Spin: Integer; const tx: Single): TQuat;

// spherical linear interpolation of unit quaternions with spins
// QStart, QEnd - start and end unit quaternions
// t            - interpolation parameter (0 to 1)
// Spin         - number of extra spin rotations to involve

var beta,                   // complementary interp parameter
    theta,                  // Angle between A and B
    sint, cost,             // sine, cosine of theta
    phi,t: Single;            // theta plus spins
    bflip: Boolean;         // use negativ t?


begin
  // cosine theta
  cost := V_Angle(QStart.ImagPart, QEnd.ImagPart);
  t    :=tx;

  // if QEnd is on opposite hemisphere from QStart, use -QEnd instead
  if cost < 0 then
  begin
    cost := -cost;
    bflip := True;
  end
  else bflip := False;

  // if QEnd is (within precision limits) the same as QStart,
  // just linear interpolate between QStart and QEnd.
  // Can't do spins, since we don't know what direction to spin.

  if (1 - cost) < EPSILON then beta := 1 - t
                          else
  begin
    // normal case
    theta := arccos(cost);
    phi := theta + Spin * Pi;
    sint := sin(theta);
    beta := sin(theta - t * phi) / sint;
    t := sin(t * phi) / sint;
  end;

  if bflip then t := -t;

  // interpolate
  Result.ImagPart.X := beta * QStart.ImagPart.X + t * QEnd.ImagPart.X;
  Result.ImagPart.Y := beta * QStart.ImagPart.Y + t * QEnd.ImagPart.Y;
  Result.ImagPart.Z := beta * QStart.ImagPart.Z + t * QEnd.ImagPart.Z;
  Result.RealPart := beta * QStart.RealPart + t * QEnd.RealPart;
end;

////////////////////////////////////////////////////////////////////////////////

function M_MultV(const m: PMatrix4; const v: TVector): TVector;
begin
Result.X := m[0, 0] * v.X + m[1, 0] * v.Y + m[2, 0] * v.Z + m[3, 0];
Result.Y := m[0, 1] * v.X + m[1, 1] * v.Y + m[2, 1] * v.Z + m[3, 1];
Result.Z := m[0, 2] * v.X + m[1, 2] * v.Y + m[2, 2] * v.Z + m[3, 2];
end;

function M_MultM(const a, b: TMatrix4): TMatrix4;
begin
Result[0, 0] := a[0, 0] * b[0, 0] + a[0, 1] * b[1, 0] + a[0, 2] * b[2, 0] + a[0, 3] * b[3, 0];
Result[1, 0] := a[1, 0] * b[0, 0] + a[1, 1] * b[1, 0] + a[1, 2] * b[2, 0] + a[1, 3] * b[3, 0];
Result[2, 0] := a[2, 0] * b[0, 0] + a[2, 1] * b[1, 0] + a[2, 2] * b[2, 0] + a[2, 3] * b[3, 0];
Result[3, 0] := a[3, 0] * b[0, 0] + a[3, 1] * b[1, 0] + a[3, 2] * b[2, 0] + a[3, 3] * b[3, 0];
Result[0, 1] := a[0, 0] * b[0, 1] + a[0, 1] * b[1, 1] + a[0, 2] * b[2, 1] + a[0, 3] * b[3, 1];
Result[1, 1] := a[1, 0] * b[0, 1] + a[1, 1] * b[1, 1] + a[1, 2] * b[2, 1] + a[1, 3] * b[3, 1];
Result[2, 1] := a[2, 0] * b[0, 1] + a[2, 1] * b[1, 1] + a[2, 2] * b[2, 1] + a[2, 3] * b[3, 1];
Result[3, 1] := a[3, 0] * b[0, 1] + a[3, 1] * b[1, 1] + a[3, 2] * b[2, 1] + a[3, 3] * b[3, 1];
Result[0, 2] := a[0, 0] * b[0, 2] + a[0, 1] * b[1, 2] + a[0, 2] * b[2, 2] + a[0, 3] * b[3, 2];
Result[1, 2] := a[1, 0] * b[0, 2] + a[1, 1] * b[1, 2] + a[1, 2] * b[2, 2] + a[1, 3] * b[3, 2];
Result[2, 2] := a[2, 0] * b[0, 2] + a[2, 1] * b[1, 2] + a[2, 2] * b[2, 2] + a[2, 3] * b[3, 2];
Result[3, 2] := a[3, 0] * b[0, 2] + a[3, 1] * b[1, 2] + a[3, 2] * b[2, 2] + a[3, 3] * b[3, 2];
Result[0, 3] := a[0, 0] * b[0, 3] + a[0, 1] * b[1, 3] + a[0, 2] * b[2, 3] + a[0, 3] * b[3, 3];
Result[1, 3] := a[1, 0] * b[0, 3] + a[1, 1] * b[1, 3] + a[1, 2] * b[2, 3] + a[1, 3] * b[3, 3];
Result[2, 3] := a[2, 0] * b[0, 3] + a[2, 1] * b[1, 3] + a[2, 2] * b[2, 3] + a[2, 3] * b[3, 3];
Result[3, 3] := a[3, 0] * b[0, 3] + a[3, 1] * b[1, 3] + a[3, 2] * b[2, 3] + a[3, 3] * b[3, 3];
end;

function M_Rotation(const v: TVector; const Angle: single): TMatrix4;
var
 s, c, inv_c : single;
begin
s := sin(Angle);
c := cos(Angle);
inv_c := 1 - c;

Result[0][0] := (inv_c * v.X * v.X) + c;
Result[0][1] := (inv_c * v.X * v.Y) - (v.Z * s);
Result[0][2] := (inv_c * v.Z * v.X) + (v.Y * s);

Result[1][0] := (inv_c * v.X * v.Y) + (v.Z * s);
Result[1][1] := (inv_c * v.Y * v.Y) + c;
Result[1][2] := (inv_c * v.Y * v.Z) - (v.X * s);

Result[2][0] := (inv_c * v.Z * v.X) - (v.Y * s);
Result[2][1] := (inv_c * v.Y * v.Z) + (v.X * s);
Result[2][2] := (inv_c * v.Z * v.Z) + c;

Result[3, 0] := 0;
Result[3, 1] := 0;
Result[3, 2] := 0;
Result[0, 3] := 0;
Result[1, 3] := 0;
Result[2, 3] := 0;
Result[3, 3] := 1;
end;

//------------------------------------------------------------------------------
// MATRIX ROUTINES
//------------------------------------------------------------------------------
function m_transpose(const M: PMatrix4): TMatrix4;
var
  f : Single;
begin
  f:=M[0, 1]; Result[0, 1]:=M[1, 0]; Result[1, 0]:=f;
  f:=M[0, 2]; Result[0, 2]:=M[2, 0]; Result[2, 0]:=f;
  f:=M[0, 3]; Result[0, 3]:=M[3, 0]; Result[3, 0]:=f;
  f:=M[1, 2]; Result[1, 2]:=M[2, 1]; Result[2, 1]:=f;
  f:=M[1, 3]; Result[1, 3]:=M[3, 1]; Result[3, 1]:=f;
  f:=M[2, 3]; Result[2, 3]:=M[3, 2]; Result[3, 2]:=f;
end;

function m_FromQuaternion(const Q: TQuat): TMatrix4;
var
  x, y, z, w, xx, xy, xz, xw, yy, yz, yw, zz, zw: Single;
  Quat: TQuat;
begin
  Quat := q_Normalize(q);

  x := Quat.ImagPart.x;
  y := Quat.ImagPart.y;
  z := Quat.ImagPart.z;
  w := Quat.RealPart;

  xx := x * x;
  xy := x * y;
  xz := x * z;
  xw := x * w;
  yy := y * y;
  yz := y * z;
  yw := y * w;
  zz := z * z;
  zw := z * w;

  Result[0, 0] := 1 - 2 * ( yy + zz );
  Result[1, 0] :=     2 * ( xy - zw );
  Result[2, 0] :=     2 * ( xz + yw );
  Result[3, 0] := 0;
  Result[0, 1] :=     2 * ( xy + zw );
  Result[1, 1] := 1 - 2 * ( xx + zz );
  Result[2, 1] :=     2 * ( yz - xw );
  Result[3, 1] := 0;
  Result[0, 2] :=     2 * ( xz - yw );
  Result[1, 2] :=     2 * ( yz + xw );
  Result[2, 2] := 1 - 2 * ( xx + yy );
  Result[3, 2] := 0;
  Result[0, 3] := 0;
  Result[1, 3] := 0;
  Result[2, 3] := 0;
  Result[3, 3] := 1;
end;

function m_SetTranslation(const M: PMatrix4; const Translation: TVector): TMatrix4;
begin
  Result       :=M^;
  Result[3, 0] := Translation.x;
  Result[3, 1] := Translation.y;
  Result[3, 2] := Translation.z;
end;

function m_TransformVector(const V: TVector; const M: TMatrix4): TVector;
begin
  Result.x:=V.x * M[0, 0] + V.y * M[1, 0] + V.z * M[2, 0] + M[3, 0];
  Result.y:=V.x * M[0, 1] + V.y * M[1, 1] + V.z * M[2, 1] + M[3, 1];
  Result.z:=V.x * M[0, 2] + V.y * M[1, 2] + V.z * M[2, 2] + M[3, 2];
end;

function m_CreateRotationMatrix(const Angles: TVector): TMatrix4;
var cx, sx, cy, sy, cz, sz: Single;
begin
  SinCos(angles.x, sx, cx);
  SinCos(angles.y, sy, cy);
  SinCos(angles.z, sz, cz);

  Result[0, 0] := cy * cz;
  Result[0, 1] := cy * sz;
  Result[0, 2] :=-sy;
  Result[0, 3] := 0;

  Result[1, 0] := sx * sy * cz - cx * sz;
  Result[1, 1] := sx * sy * sz + cx * cz;
  Result[1, 2] := sx * cy;
  Result[1, 3] := 0;

  Result[2, 0] := cx * sy * cz + sx * sz;
  Result[2, 1] := cx * sy * sz - sx * cz;
  Result[2, 2] := cx * cy;
  Result[2, 3] := 0;

  Result[3, 0] := 0;
  Result[3, 1] := 0;
  Result[3, 2] := 0;
  Result[3, 3] := 1;
end;

function m_CreateRotationMatrixX(const Angle: Single): TMatrix4;
var sine, cosine: Single;
begin
  SinCos(Angle, sine, cosine);

  Result[0, 0] := 1;
  Result[0, 1] := 0;
  Result[0, 2] := 0;
  Result[0, 3] := 0;

  Result[1, 0] := 0;
  Result[1, 1] := cosine;
  Result[1, 2] := sine;
  Result[1, 3] := 0;

  Result[2, 0] := 0;
  Result[2, 1] := -sine;
  Result[2, 2] := cosine;
  Result[2, 3] := 0;

  Result[3, 0] := 0;
  Result[3, 1] := 0;
  Result[3, 2] := 0;
  Result[3, 3] := 1;
end;

function m_CreateRotationMatrixY(const Angle: Single): TMatrix4;
var sine, cosine: Single;
begin
  SinCos(Angle, sine, cosine);

  Result[0, 0] := cosine;
  Result[0, 1] := 0;
  Result[0, 2] := -sine;
  Result[0, 3] := 0;

  Result[1, 0] := 0;
  Result[1, 1] := 1;
  Result[1, 2] := 0;
  Result[1, 3] := 0;

  Result[2, 0] := sine;
  Result[2, 1] := 0;
  Result[2, 2] := cosine;
  Result[2, 3] := 0;

  Result[3, 0] := 0;
  Result[3, 1] := 0;
  Result[3, 2] := 0;
  Result[3, 3] := 1;
end;

function m_CreateRotationMatrixZ(const Angle: Single): TMatrix4;
var sine, cosine: Single;
begin
  SinCos(Angle, sine, cosine);

  Result[0, 0] := cosine;
  Result[0, 1] := sine;
  Result[0, 2] := 0;
  Result[0, 3] := 0;

  Result[1, 0] := -sine;
  Result[1, 1] := cosine;
  Result[1, 2] := 0;
  Result[1, 3] := 0;

  Result[2, 0] := 0;
  Result[2, 1] := 0;
  Result[2, 2] := 1;
  Result[2, 3] := 0;

  Result[3, 0] := 0;
  Result[3, 1] := 0;
  Result[3, 2] := 0;
  Result[3, 3] := 1;
end;

function m_CreateScaleMatrix(const Scale: Single): TMatrix4; overload;
begin
  Result:=m_Identity;

  Result[0, 0] := Scale;
  Result[1, 1] := Scale;
  Result[2, 2] := Scale;
end;

function m_CreateScaleMatrix(const Scale: TVector): TMatrix4; overload;
begin
  Result:=m_Identity;

  Result[0, 0] := Scale.x;
  Result[1, 1] := Scale.y;
  Result[2, 2] := Scale.z;
end;

function M_DetInternal(const a1, a2, a3, b1, b2, b3, c1, c2, c3: Single): Single;
// internal version for the determinant of a 3x3 matrix
begin
  Result := a1 * (b2 * c3 - b3 * c2) -
            b1 * (a2 * c3 - a3 * c2) +
            c1 * (a2 * b3 - a3 * b2);
end;

//----------------------------------------------------------------------------------------------------------------------

Function M_Adjoint(const M: PMatrix4): TMatrix4;
// Adjoint of a 4x4 matrix - used in the computation of the inverse
// of a 4x4 matrix
var a1, a2, a3, a4,
    b1, b2, b3, b4,
    c1, c2, c3, c4,
    d1, d2, d3, d4: Single;
begin
    a1 :=  M[0, 0]; b1 :=  M[0, 1];
    c1 :=  M[0, 2]; d1 :=  M[0, 3];
    a2 :=  M[1, 0]; b2 :=  M[1, 1];
    c2 :=  M[1, 2]; d2 :=  M[1, 3];
    a3 :=  M[2, 0]; b3 :=  M[2, 1];
    c3 :=  M[2, 2]; d3 :=  M[2, 3];
    a4 :=  M[3, 0]; b4 :=  M[3, 1];
    c4 :=  M[3, 2]; d4 :=  M[3, 3];
    //)---</
    // row column labeling reversed since we transpose rows & columns
    Result[0, 0] :=  M_DetInternal(b2, b3, b4, c2, c3, c4, d2, d3, d4);
    Result[1, 0] := -M_DetInternal(a2, a3, a4, c2, c3, c4, d2, d3, d4);
    Result[2, 0] :=  M_DetInternal(a2, a3, a4, b2, b3, b4, d2, d3, d4);
    Result[3, 0] := -M_DetInternal(a2, a3, a4, b2, b3, b4, c2, c3, c4);

    Result[0, 1] := -M_DetInternal(b1, b3, b4, c1, c3, c4, d1, d3, d4);
    Result[1, 1] :=  M_DetInternal(a1, a3, a4, c1, c3, c4, d1, d3, d4);
    Result[2, 1] := -M_DetInternal(a1, a3, a4, b1, b3, b4, d1, d3, d4);
    Result[3, 1] :=  M_DetInternal(a1, a3, a4, b1, b3, b4, c1, c3, c4);

    Result[0, 2] :=  M_DetInternal(b1, b2, b4, c1, c2, c4, d1, d2, d4);
    Result[1, 2] := -M_DetInternal(a1, a2, a4, c1, c2, c4, d1, d2, d4);
    Result[2, 2] :=  M_DetInternal(a1, a2, a4, b1, b2, b4, d1, d2, d4);
    Result[3, 2] := -M_DetInternal(a1, a2, a4, b1, b2, b4, c1, c2, c4);

    Result[0, 3] := -M_DetInternal(b1, b2, b3, c1, c2, c3, d1, d2, d3);
    Result[1, 3] :=  M_DetInternal(a1, a2, a3, c1, c2, c3, d1, d2, d3);
    Result[2, 3] := -M_DetInternal(a1, a2, a3, b1, b2, b3, d1, d2, d3);
    Result[3, 3] :=  M_DetInternal(a1, a2, a3, b1, b2, b3, c1, c2, c3);
end;

//----------------------------------------------------------------------------------------------------------------------

function M_Determinant(const M: PMatrix4): Single;

// Determinant of a 4x4 matrix

var a1, a2, a3, a4,
    b1, b2, b3, b4,
    c1, c2, c3, c4,
    d1, d2, d3, d4  : Single;

begin
  a1 := M[0, 0];  b1 := M[0, 1];  c1 := M[0, 2];  d1 := M[0, 3];
  a2 := M[1, 0];  b2 := M[1, 1];  c2 := M[1, 2];  d2 := M[1, 3];
  a3 := M[2, 0];  b3 := M[2, 1];  c3 := M[2, 2];  d3 := M[2, 3];
  a4 := M[3, 0];  b4 := M[3, 1];  c4 := M[3, 2];  d4 := M[3, 3];

  Result := a1 * M_DetInternal(b2, b3, b4, c2, c3, c4, d2, d3, d4) -
            b1 * M_DetInternal(a2, a3, a4, c2, c3, c4, d2, d3, d4) +
            c1 * M_DetInternal(a2, a3, a4, b2, b3, b4, d2, d3, d4) -
            d1 * M_DetInternal(a2, a3, a4, b2, b3, b4, c2, c3, c4);
end;

//----------------------------------------------------------------------------------------------------------------------

Function M_Scale(const M: PMatrix4; const Factor: Single): TMatrix4; register;
// multiplies all elements of a 4x4 matrix with a factor
var I, J: Integer;
begin
  for I := 0 to 3 do
    for J := 0 to 3 do Result[I, J] := M[I, J] * Factor;
end;


////////////
////////////////////////////////////////////////////////////////////////////////

function ClosestPointOnLine(const vA, vB, Point: TVector): TVector;
var
 Vector1, Vector2, Vector3: TVector;
 d, t: double;
begin
Vector1 := v_Sub(Point, vA);
Vector2 := v_Normalize(v_Sub(vB, vA));
d := v_Dist(vA, vB);
t := v_Dot(Vector2, Vector1);

if t <= 0 then
 begin
 Result := vA;
 Exit;
 end;

if t >= d then
 begin
 Result := vB;
 Exit;
 end;

Vector3 := v_Mult(Vector2, t);
Result := v_Add(vA, Vector3);
end;

function EdgeSphereCollision(const Center,v1, v2, v3: TVector; const Radius: Single): Boolean;
var i: Integer;
    Point: TVector;
    Distance: Single;
 v : array [0..2] of TVector;
begin
v[0] := v1;
v[1] := v2;
v[2] := v3;
for i := 0 to 2 do
 begin
 Point := ClosestPointOnLine(v[i], v[(i + 1) mod 3], Center);
 Distance := v_Dist(Point, Center);
 if Distance < Radius then
  begin
  Result := true;
  Exit;
  end;
 end;
Result := false;
end;

function LineVsPolygon(const v1,v2,v3, LB,LE,vNormal : TVector):boolean;
var
  vIntersection : TVector;
  originDistance : Extended;
  distance1 : Extended;
  distance2 : Extended;
  vVector1 : TVector;
  vVector2 : TVector;
  vPoint : TVector;
  vLineDir : TVector;
  Numerator : Extended;
  Denominator : Extended;
  dist : Extended;
  Angle,tempangle : Extended; // Initialize the angle
	vA, vB : TVector;						// Create temp vectors
  I : integer;
  dotProduct : Extended;
  vectorsMagnitude : Extended;
  vPoly            : array [0..2] of TVector;
  verticeCount : integer;
begin
  vPoint  := vector(0,0,0);
  vLineDir:= vector(0,0,0);
  Angle := 0;
  vpoly[0] := v1;
  vpoly[1] := v2;
  vpoly[2] := v3;
  verticeCount:=3;

  vVector1 := v_sub(vPoly[2],vPoly[0]);
  vVector2 := v_sub(vPoly[1],vPoly[0]);

  originDistance := -1 * v_Dot(vNormal,vPoly[0]);

	distance1 := v_Dot(vNormal,lb) + originDistance;// Cz + D
	distance2 := v_Dot(vNormal,le) + originDistance;// Cz + D
	if(distance1 * distance2 >= 0) then
  begin
	  result := false;
    exit;
  end;
  vLineDir := v_sub(le,lb);    // Get the X value of our new vector
  v_normalize(vLineDir);
	Numerator := -1 * (v_Dot(vNormal,lb) + originDistance);
	Denominator := v_Dot(vNormal,vLineDir);

	if( Denominator = 0) then	 // Check so we don't divide by zero
  begin
		vIntersection := lb; // Return an arbitrary point on the line
  end
  else
  begin

  	dist := Numerator / Denominator;
  	vPoint := v_ADD(lb,v_Mult(vLineDir,dist));
  	vIntersection := vPoint;								// Return the intersection point
  end;

  // Go in a circle to each vertex and get the angle between
  for i := 0 to verticeCount-1 do
  begin

    vA := v_sub(vPoly[i],vIntersection);
    vB := v_sub(vPoly[(i + 1) mod verticeCount],vIntersection);

    dotProduct       := v_Dot(vA,vB);
	  vectorsMagnitude := v_Length(VA)* v_Length(VB);
    tempangle        := arccos( dotProduct / vectorsMagnitude );
	  if(isnan(tempangle)) then
  		tempangle := 0;
	  Angle := Angle + tempangle;
  end;

	if(Angle >= (M_Angle) ) then
  begin
		result := TRUE;
    exit;
  end;

	result := false; // There was no collision, so return false
end;

function LineVsPolygon2(const v1,v2,v3, LB,LE,vNormal : TVector;Var vInt : TVector):boolean;
var
  vIntersection : TVector;
  originDistance : Extended;
  distance1 : Extended;
  distance2 : Extended;
  vVector1 : TVector;
  vVector2 : TVector;
  vPoint : TVector;
  vLineDir : TVector;
  Numerator : Extended;
  Denominator : Extended;
  dist : Extended;
  Angle,tempangle : Extended; // Initialize the angle
	vA, vB : TVector;						// Create temp vectors
  I : integer;
  dotProduct : Extended;
  vectorsMagnitude : Extended;
  vPoly            : array [0..2] of TVector;
  verticeCount : integer;
begin
  vint:=vector(0,0,0);
  vPoint  := vector(0,0,0);
  vLineDir:= vector(0,0,0);
  Angle := 0;
  vpoly[0] := v1;
  vpoly[1] := v2;
  vpoly[2] := v3;
  verticeCount:=3;

  vVector1 := v_sub(vPoly[2],vPoly[0]);
  vVector2 := v_sub(vPoly[1],vPoly[0]);

  originDistance := -1 * v_Dot(vNormal,vPoly[0]);

	distance1 := v_Dot(vNormal,lb) + originDistance;// Cz + D
	distance2 := v_Dot(vNormal,le) + originDistance;// Cz + D
	if(distance1 * distance2 >= 0) then
  begin
	  result := false;
    exit;
  end;
  vLineDir := v_sub(le,lb);    // Get the X value of our new vector
  v_normalize(vLineDir);
	Numerator := -1 * (v_Dot(vNormal,lb) + originDistance);
	Denominator := v_Dot(vNormal,vLineDir);

	if( Denominator = 0) then	 // Check so we don't divide by zero
  begin
		vIntersection := lb; // Return an arbitrary point on the line
  end
  else
  begin

  	dist := Numerator / Denominator;
  	vPoint := v_ADD(lb,v_Mult(vLineDir,dist));
  	vIntersection := vPoint;								// Return the intersection point
//  vint := vIntersection;
  end;

  // Go in a circle to each vertex and get the angle between
  for i := 0 to verticeCount-1 do
  begin

    vA := v_sub(vPoly[i],vIntersection);
    vB := v_sub(vPoly[(i + 1) mod verticeCount],vIntersection);

    dotProduct       := v_Dot(vA,vB);
	  vectorsMagnitude := v_Length(VA)* v_Length(VB);
    tempangle        := arccos( dotProduct / vectorsMagnitude );
	  if(isnan(tempangle)) then
  		tempangle := 0;
	  Angle := Angle + tempangle;
  end;

	if(Angle >= (M_Angle) ) then
  begin
		result := TRUE;
    vint := vIntersection;
    exit;
  end;
  vInt := vector(0,0,0);
	result := false; // There was no collision, so return false
end;

////////////////////////////// LINE POLYGON COLLISION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

/////////////////////////// ELIPSOID POLYGON COLLISION \\\\\\\\\\\\\\\\\\\\\\\\\\*
// Создано на основе проверки столкновения :
// Сергея Бехтера Email : killerman1985@mail.ru
function LineInsideTri(const PointPlane1,PointPlane2,PointPlane3,BeginPoint,EndPoint: TVector): TDistBool;
var p1,p2,p3,p4: TVector;
    t,u,v,det: Single;
begin
 Result := DB_Identity;
p1:=v_sub(BeginPoint , PointPlane1);
p2:=v_sub(BeginPoint , EndPoint);
p3:=v_sub(PointPlane2, PointPlane1);
p4:=v_sub(PointPlane3, PointPlane1);

 det:=v_Dot(p2,v_Cross(p3,p4));
 if det=0 then Exit;

 t:=v_Dot(p1,v_Cross(p3,p4))/det;
 if (t<0) or (t>1) then Exit;

 u:=v_Dot(p2,v_Cross(p1,p4))/det;
 if (u<0) or (u>1) then Exit;

 v:=v_Dot(p2,v_Cross(p3,p1))/det;
 if (v<0) or (v>1) then Exit;

 if (u+v)>1 then Exit;

 Result.Point.X:= PointPlane1.X+p3.X*u+p4.X*v;
 Result.Point.Y:= PointPlane1.Y+p3.Y*u+p4.Y*v;
 Result.Point.Z:= PointPlane1.Z+p3.Z*u+p4.Z*v;
 Result.Vector := v_normalize( V_Negate(p2) );
 Result.Dist   := v_dist(Result.Point,BeginPoint);
 Result.Return := True;
end;

function LineInsideTri2(const PointPlane1,PointPlane2,PointPlane3,BeginPoint,EndPoint: TVector): boolean;
var p1,p2,p3,p4: TVector;
    t,u,v,det: Single;
begin
 Result := False;
p1:=v_sub(BeginPoint , PointPlane1);
p2:=v_sub(BeginPoint , EndPoint);
p3:=v_sub(PointPlane2, PointPlane1);
p4:=v_sub(PointPlane3, PointPlane1);

 det:=v_Dot(p2,v_Cross(p3,p4));
 if det=0 then Exit;

 t:=v_Dot(p1,v_Cross(p3,p4))/det;
 if (t<0) or (t>1) then Exit;

 u:=v_Dot(p2,v_Cross(p1,p4))/det;
 if (u<0) or (u>1) then Exit;

 v:=v_Dot(p2,v_Cross(p3,p1))/det;
 if (v<0) or (v>1) then Exit;

 if (u+v)>1 then Exit;
 Result:= True;
end;




function MinDistToLine(const Point,LinePoint1,LinePoint2: TVector): TDistBool;
var
d,t: Single;
V1,V2,V3: TVector;
begin
V1  := v_sub (Point,LinePoint1);
V2  := v_normalize( v_sub(LinePoint2,LinePoint1) );
d   := v_dist(LinePoint1,LinePoint2);
t   := v_Dot(V1,V2);
if t<=0 then
 begin
   Result.Point := LinePoint1;
   Result.Vector:= v_Normalize(v1);
   Result.Dist  := v_dist(Point,LinePoint1);
 end
 else
  if t>=d then
   begin
     Result.Point  :=LinePoint2;
     Result.Vector :=v_normalize(v_sub(Point,LinePoint2));
     Result.Dist   :=v_dist(Point,LinePoint2);
   end
   else
   begin
     V3:= v_add ( v_mult(V2,t) ,LinePoint1);
     Result.Point := V3;
     Result.Dist  := v_dist(Point , V3);
     Result.Vector:=v_normalize( v_sub(Point,V3));
   end;

end;

function CollEllipsToTr(var Center: TVector; const Radius,PointPlane1,PointPlane2,PointPlane3: TVector): TDistBool;
var Normal,EndPoint,IntP,EdCent,VectEl,
    TrP1,TrP2,TrP3 ,VDiv: TVector;
    Intersect           : TDistBool;
    RadEl,DistToP       : Single;
    Label GoEnd;
begin
Result := DB_Identity;
vdiv := v_divv(V_mIdentity,radius);

//Переводим координаты вершин треугольника в эллипсойдные
TrP1:= v_multv( v_sub(PointPlane1,Center) ,vdiv);
TrP2:= v_multv( v_sub(PointPlane2,Center) ,vdiv);
TrP3:= v_multv( v_sub(PointPlane3,Center) ,vdiv);
//Проверяем пересечение плоскости треугольника с ед сферой
    Normal := V_Negate(P_Normal(TrP1,TrP2,TrP3));
    EdCent := V_Identity;
 if -v_dot(Normal,EdCent) >1 then Exit;

    EndPoint := V_Negate(Normal);

    Intersect:= LineInsideTri(TrP1,TrP2,TrP3,EdCent,EndPoint);

     if Intersect.Return then
     goto GoEnd;

   /// проверяем первую грань треугольника///
   Intersect:=MinDistToLine(EdCent,TrP1,TrP2);
    if Intersect.Dist<1 then
     goto GoEnd;

   /// проверяем вторую грань треугольника///
   Intersect:=MinDistToLine(EdCent,TrP2,TrP3);
    if Intersect.Dist<1 then
     goto GoEnd;


   /// проверяем третью грань треугольника///
   Intersect:=MinDistToLine(EdCent,TrP3,TrP1);
    if Intersect.Dist<1 then
     goto GoEnd;

/// Выходим пересечения небыло///
Exit;
/// Есть пересечение ///
GoEnd:
     VectEl       := v_multv (Intersect.Vector,radius);
     RadEl        := v_length(VectEl);
     IntP         := v_multv (Intersect.Point,radius);
     IntP         := v_add   (intp,Center);
     DistToP      := v_dist  (Center,IntP);

     Result.Vector:= VectEl;
     Result.Point := IntP;
     Result.Dist  := DistToP;
     Result.Return:= True;


     Center.X     :=IntP.X-(IntP.X-Center.X)*(RadEl/DistToP);
     Center.Y     :=IntP.Y-(IntP.Y-Center.Y)*(RadEl/DistToP);
     Center.Z     :=IntP.Z-(IntP.Z-Center.Z)*(RadEl/DistToP);
end;

/////////////////////////// ELIPSOID POLYGON COLLISION \\\\\\\\\\\\\\\\\\\\\\\\\\*

//--------------------------------
function uSphereFromAABB(const aabb: TAABB): TSphere;
var v: TVector;
begin
  v := v_add(aabb.Mins, aabb.Maxs);
  Result.POS := v_mult(v, 0.5);
  Result.Radius := v_dist(Result.Pos, aabb.Maxs);
end;

Function uCubeVsPoint(const Box,Point : TVector; Size:Single):Boolean;
Begin
  If (abs(Point.x - Box.x)< Size) And
     (abs(Point.y - Box.y)< Size) And
     (abs(Point.z - Box.z)< Size) Then Result := True Else Result := False;
end;

Function uBoxVsPoint(const Box,BoxSize,Point : TVector):Boolean;
Begin
  IF (abs(Point.x - Box.x)< BoxSize.x) And
     (abs(Point.y - Box.y)< BoxSize.y) And
     (abs(Point.z - Box.z)< BoxSize.z) Then Result := True Else Result := False;
end;


function uAABBVsPoint(const Minx,Maxx,Pos : TVector): boolean;
begin
IF (Pos.X >= Minx.X) and (Pos.X <= Maxx.X) and
   (Pos.y >= Minx.y) and (Pos.y <= Maxx.y) and
   (Pos.z >= Minx.z) and (Pos.z <= Maxx.z) then result := true else result:=false;
end;

function uBoxVsBox(const Box1,Box2,
                    Box1Size,Box2Size : TVector): boolean;
begin
 if (box1.X + box1size.X < Box2.X) or
    (box1.y + box1size.y < Box2.y) or
    (box1.z + box1size.z < Box2.z) or

    (Box2.x + box2size.X < box1.X) or
    (Box2.y + box2size.y < box1.y) or
    (Box2.z + box2size.z < box1.z) then
     Result:=false else result:=true;
end;

Function uAABBVsAABB(const Minx1,Maxx1,Minx2,Maxx2: TVector): boolean;
begin
result:=true;
		if (Minx1.x > Maxx2.x) or (Maxx1.x < Minx2.x) or (Minx1.y > Maxx2.y) or
  		 (Maxx1.y < Minx2.y) or (Minx1.z > Maxx2.z) or (Maxx1.z < Minx2.z) then result:=false;
end;


function uAABBVsSphere(const Minx,Maxx,Pos : TVector;R:Single): boolean;
var
d :single;
begin
   d := 0;

      // если центр сферы лежит перед AABB,
      if (Pos.x < Minx.x) then
         // то вычисляем расстояние по этой оси
         d:=d+ abs(Pos.x - Minx.x);

      // если центр сферы лежит после AABB,
      if (pos.x > Maxx.x) then
          // то вычисляем расстояние по этой оси
          d:=d+ abs(Pos.x - Maxx.x);

(******************************************************************************)
      if (Pos.y < Minx.y) then d :=d + abs(Pos.y - Minx.y);
      if (pos.y > Maxx.y) then d :=d + abs(Pos.y - Maxx.y);
(******************************************************************************)
      if (Pos.z < Minx.z) then d :=d + abs(Pos.z - Minx.z);
      if (pos.z > Maxx.z) then d :=d + abs(Pos.z - Maxx.z);
(******************************************************************************)

   result := (d  <=  R);

end;


function uCubeVsLine(const BP,LBEGIN,LEND: TVector;BS :single): boolean;
Var
  MID,
  DIR,
  T   : TVector;
  HL,
  R   : Single;

begin
  // Получаем центр
  Mid.x := lbegin.x+(lend.x-lbegin.x)*0.5;
  Mid.y := lbegin.y+(lend.y-lbegin.y)*0.5;
  Mid.z := lbegin.z+(lend.z-lbegin.z)*0.5;

  // Получаем направление
  dir.x := (lend.x-lbegin.x);
  dir.y := (lend.y-lbegin.y);
  dir.z := (lend.z-lbegin.z);

  // Получаем длину
  hl := sqrt(sqr(dir.x)+sqr(dir.y)+sqr(dir.z));
  // Нормализуем её
  if hl <> 0 then
  begin
         r:= 1/hl;
    dir.x := dir.x * r;
    dir.y := dir.y * r;
    dir.z := dir.z * r;

    hl    := hl * 0.5;
  end;

  // Получаем позицию куба относительно середины линии
   t.x := BP.x -mid.x;
   t.y := BP.y -mid.y;
   t.z := BP.z -mid.z;

    // проверяем, является ли одна из осей X,Y,Z разделяющей
   if ( (abs(T.x) > BS + hl*abs(dir.x)) or
        (abs(T.y) > BS + hl*abs(dir.y)) or
        (abs(T.z) > BS + hl*abs(dir.z)) ) then begin result := false ; exit; end;

   // проверяем X ^ dir
    r := BS*abs(dir.z) + BS*abs(dir.y);
    if ( abs(T.y*dir.z - T.z*dir.y) > r ) then begin result := false ; exit; end;

   // проверяем Y ^ dir
    r := BS* abs(dir.z) + BS* abs(dir.x);
    if ( abs(T.z*dir.x - T.x*dir.z) > r ) then begin result := false ; exit; end;

   // проверяем Z ^ dir
    r := BS*abs(dir.y) + BS*abs(dir.x);
    if ( abs(T.x*dir.y - T.y*dir.x) > r ) then begin result := false ; exit; end;

   result := true;

end;

function uAABBVsLine(const Mins,Maxs,StartPoint, EndPoint : TVector): boolean;
var
  dir, lineDir, ld, lineCenter, center, extents, cross: TVector;
begin
  Result := False;

  center := v_mult(v_add(Mins, Maxs), 0.5);
  extents := v_sub(Maxs, center);
  lineDir := v_mult(v_sub(EndPoint, StartPoint), 0.5);
  lineCenter := v_add(StartPoint, lineDir);
  dir := v_sub(lineCenter, center);

  ld.x := Abs(lineDir.x);
  if Abs(dir.x) > (extents.x + ld.x) then Exit;

  ld.y := Abs(lineDir.y);
  if Abs(dir.y) > (extents.y + ld.y) then Exit;

  ld.z := Abs(lineDir.z);
  if Abs(dir.z) > (extents.z + ld.z) then Exit;

  cross := v_cross(lineDir, dir);

  if Abs(cross.x) > ((extents.y * ld.z) + (extents.z * ld.y)) then Exit;
  if Abs(cross.y) > ((extents.x * ld.z) + (extents.z * ld.x)) then Exit;
  if Abs(cross.z) > ((extents.x * ld.y) + (extents.y * ld.x)) then Exit;

  Result := True;
end;


function uSphereVsPoint(const Sphere,Point : TVector; R: Single): boolean;
Var
  dist: Single;
begin
// Получение дистанции мужду двумя точками
  dist:=sqrt(sqr(Sphere.X-Point.X)+sqr(Sphere.Y-Point.Y)+sqr(Sphere.Z-Point.Z));
// Если она меньше радиуса сферы то есть столкновение
  if dist<=R then result:=true else result:=false;
end;

Function uSphereVsSphere(const Sphere1,Sphere2 : TVector; R1,R2 : Single) : boolean;
Var
R,RR  : Single;
X,Y,Z : Single;
begin
  R:= (R1 + R2);
  //Получем центр и радиус
  X := Sphere2.x - Sphere1.X;
  Y := Sphere2.Y - Sphere1.Y;
  Z := Sphere2.Z - Sphere1.Z;

  rr := sqrt(x*x +y*y +z*z);
  if rr < r then Result := True else Result := false;
  // если r больше rr то нет столкновения
end;

function uSphereVsLine(const Sphere, LB,LE : TVector;R: Single): boolean;
var
 Point,
 Vector1,
 Vector2,
 Dir    : TVector;
 D, T   : Single;
begin
Result  :=false;

// Узнаём положение сферы относительно начала линии
Vector1 := v_sub(Sphere,Lb);
// Узнаём направление
Dir     := v_sub(Le,Lb);
// Узнаём длину
D       := v_length(dir);
// Нормализируем её
if d >0 then
  begin
    Vector2  := v_mult(Dir, 1/d);
  end;

// Узнаём дистанцию между началом и концом линии
d := v_dist(Lb,le);

// Перемножаем их и получаем приделы линии где может быть сфера
t := (Vector1.X * Vector2.X) + (Vector1.Y * Vector2.Y) + (Vector1.Z * Vector2.Z);

// Вышли за приделы линии
if t+r <= 0 then  Exit;
if t-r >= d then  Exit;

// Получаем местоположение сферы относительно линии
Point := v_adD(lb,v_mult(Vector2,t));
// Получаем дистанцию между сферой и точкой ..
// Если она меньше радиуса сферы то есть столкновение
  if v_dist(sphere,point) <=R then
Result := true;
end;

function uSphereVsLine2(const Sphere, P1,P2 : TVector;R: Single): boolean;
var
  v, dir: TVector;
  d, len: Single;
begin
  dir := v_sub(p2, p1);
  len := v_normalizesafe(dir, dir);

  v := v_sub(Sphere, p1);
  d := v_dot(v, dir);

  Result := False;

  if d > len + R then Exit;
  if d < -R then Exit;

  len := v_dist(v_combine(p1, dir, d), sphere);

  if len > R then Exit;

  Result := True;
end;




///////////////////////////////////////////////////////////////////////////////
//Shaders//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
procedure CalculateTandB(var T, B: TVector; const st1, st2: TVector2d; const P, Q: TVector);
var
  s: Single;
  st: array [0..1, 0..1] of Single;
  pq: array [0..2, 0..1] of Single;
begin

  // Calculate tangent and binormal for a triangle with the given edges P and Q.
  s := 1 / ((st1.x * st2.y) - (st2.x * st1.y));

  st[0,0] := st2.y;   st[1,0] := -st1.y;
  st[0,1] := -st2.x;  st[1,1] := st1.x;

  pq[0,0] := P.X;   pq[1,0] := P.Y;   pq[2,0] := P.Z;
  pq[0,1] := Q.X;   pq[1,1] := Q.Y;   pq[2,1] := Q.Z;

  T.X := s * (st[0,0]*pq[0,0] + st[1,0]*pq[0,1]);
  T.Y := s * (st[0,0]*pq[1,0] + st[1,0]*pq[1,1]);
  T.Z := s * (st[0,0]*pq[2,0] + st[1,0]*pq[2,1]);

  B.X := s * (st[0,1]*pq[0,0] + st[1,1]*pq[0,1]);
  B.Y := s * (st[0,1]*pq[1,0] + st[1,1]*pq[1,1]);
  B.Z := s * (st[0,1]*pq[2,0] + st[1,1]*pq[2,1]);
 t:=v_normalize(t);

end;

procedure CalculateTangents(var v1, v2, v3: TShaderVertex);
var
  P, Q: TVector;
  st1, st2: TVector2d;
  T, B: TVector;
begin

  // Calculate triangle's edges:
  P.X := v2.Pos.X - v1.Pos.X;
  P.Y := v2.Pos.Y - v1.Pos.Y;
  P.Z := v2.Pos.Z - v1.Pos.Z;

  Q.X := v3.Pos.X - v1.Pos.X;
  Q.Y := v3.Pos.Y - v1.Pos.Y;
  Q.Z := v3.Pos.Z - v1.Pos.Z;

  // Calculate S and T vectors:
  st1.x := v2.TexCoord.x - v1.TexCoord.x;
  st1.y := v2.TexCoord.y - v1.TexCoord.y;

  st2.x := v3.TexCoord.x - v1.TexCoord.x;
  st2.y := v3.TexCoord.y - v1.TexCoord.y;

  // Calculate the tangent and binormal:
  CalculateTandB(T, B, st1, st2, P, Q);
//  N := V_Cross(T, B);
  v1.Tangent.X := v1.Tangent.X + T.X;     v1.Binormal.X := v1.Binormal.X + B.X;
  v1.Tangent.Y := v1.Tangent.Y + T.Y;     v1.Binormal.Y := v1.Binormal.Y + B.Y;
  v1.Tangent.Z := v1.Tangent.Z + T.Z;     v1.Binormal.Z := v1.Binormal.Z + B.Z;
  v2.Tangent.X := v2.Tangent.X + T.X;     v2.Binormal.X := v2.Binormal.X + B.X;
  v2.Tangent.Y := v2.Tangent.Y + T.Y;     v2.Binormal.Y := v2.Binormal.Y + B.Y;
  v2.Tangent.Z := v2.Tangent.Z + T.Z;     v2.Binormal.Z := v2.Binormal.Z + B.Z;

  v3.Tangent.X := v3.Tangent.X + T.X;     v3.Binormal.X := v3.Binormal.X + B.X;
  v3.Tangent.Y := v3.Tangent.Y + T.Y;     v3.Binormal.Y := v3.Binormal.Y + B.Y;
  v3.Tangent.Z := v3.Tangent.Z + T.Z;     v3.Binormal.Z := v3.Binormal.Z + B.Z;
end;

function dotVecLengthSquared3(v: TVector): Single;
begin
  Result := v.x*v.x + v.y*v.y + v.z*v.z;
end;

procedure dotVecNormalize3(var v: TVector);
var
  L: Single;
const
  DOT_ORIGIN3: TVector = (x: 0; y: 0; z: 0);
begin

  L := dotVecLengthSquared3(v);
  if L = 0 then v := DOT_ORIGIN3
  else begin
    L := sqrt(L);
    v.x := v.x / L;
    v.y := v.y / L;
    v.z := v.z / L;
  end;

end;


Procedure CreateTangentVectorSpace;//(const v1, v2, v3 : TVector; Const T1,T2,T3:TVector2D; Var tangent, binormal:TVector);
var
T, B, N,
P, Q : TVector;

st1, st2: TVector2d;

denominator, scale , scale2 : Single;

begin
   P := v_sub(v2 , v1);
   Q := v_sub(v3 , v1);

   st1.x := t2.x - t1.x;
   st1.y := t2.y - t1.y;

   st2.x := t3.x - t1.x;
   st2.y := t3.y - t1.y;

   denominator := st1.x * st2.y -
                       st2.x * st1.y;

   if denominator= 0 then
   begin
        tangent.x  := 1.0;
        tangent.y  := 0.0;
        tangent.z  := 0.0;

        binormal.x := 0.0;
        binormal.y := 1.0;
        binormal.z := 0.0;
        normal     := P_normal(v1,v2,v3);
   end
   else
   begin

      scale := 1.0 / denominator;

      T.x := (st2.y * P.x  - st1.y * Q.x ) * scale;
      T.y := (st2.y * P.y  - st1.y * Q.y ) * scale;
      T.z := (st2.y * P.z  - st1.y * Q.z ) * scale;

      B.x := (-st2.x * P.x  + st1.x * Q.x ) * scale;
      B.y := (-st2.x * P.y  + st1.x * Q.y ) * scale;
      B.z := (-st2.x * P.z  + st1.x * Q.z ) * scale;

      N := V_Cross(T, B);

      scale2 := 1.0 / ((T.x  * B.y * N.z - T.z * B.y * N.x) +
                       (B.x  * N.y * T.z - B.z * N.y * T.x) +
                       (N.x  * T.y * B.z - N.z * T.y * B.x));

      tangent.x :=   V_Cross(B, N).x  * scale2;
      tangent.y :=   V_Cross(v_negate(N), T).x  * scale2;
      tangent.z :=   V_Cross(T, B).x  * scale2;
      tangent   :=v_Normalize(tangent);

      binormal.x :=   v_Cross(v_negate(B), N).y * scale2;
      binormal.y :=   v_Cross(N, T).y * scale2;
      binormal.z :=   v_Cross(v_negate(T), B).y * scale2;
      binormal   :=v_Normalize(binormal);
        normal     := P_normal(v1,v2,v3);
{
      normal.x   :=   v_Cross(B, N).z * scale2;
      normal.y   :=   v_Cross(v_negate(N), T).z * scale2;
      normal.z   :=   v_Cross(T, B).z * scale2;
      normal   :=v_Normalize(normal);
}
   end;
end;


////////////////////////////////////////////////////////////////////////////////
//   Additions from Kavis                                                      /
//   kavi5@yandex.ru                                                           /
//   http://openglmax.narod.ru                                                 /
////////////////////////////////////////////////////////////////////////////////
(*Function V_VectorLen(var V: TVector; newLen: Single): Single;
Begin //Установить нужную длину вектора. Возвращает старую длину.
{}result:=sqrt(sqr(V.x)+sqr(V.y)+sqr(V.z));
{}if result>0 then begin
{}{}V.x:=V.x/result*newLen; V.y:=V.y/result*newLen; V.z:=V.z/result*newLen;
{}end;
End;    *)

Function V_VectorLen(var V: TVector; newLen: Single): Single;
Begin //Установить нужную длину вектора. Возвращает старую длину.
{}result:=v_length(v);
{}if result>0 then
{}//v:= v_div(v,result*newLen);
begin
V.x:=V.x/result*newLen; V.y:=V.y/result*newLen; V.z:=V.z/result*newLen;
end
End;



Function VectorPlusVectorK(const V1,V2: TVector; k: single): TVector;
Begin //Вектор плюс вектор, умноженный на число
result := V_ADD(V1,v_mult(V2, k) );
End;

Function VectorQuad(const V: TVector): single;
var
V2: TVector;
Begin //Возведение вектора в квадрат
V2:=V_MultV(V,V);
result:=V2.X + V2.Y +V2.Z;
End;

Function FindIntersection(P1, P2, P3: TVector; P: TVector; V: TVector; var I: TVector): single;
{}//Нахождение пересечения луча P,V с треугольником P1,P2,P3.
{}//Возвращает отрицательное число, если пересечения не было, либо
{}// неотрицательное число, если пересечение было.
{}//Точка пересечения I=P+V*result. Чем меньше result, тем раньше произошло пересечение.
Var
{}V1,V2: TVector; //Образующие векторы треугольника
{}N: TVector; //Нормаль к треугольнику
{}k: single; //Вспомогателный коэффициент
{}T: TVector; //Вектор из P1 в I
{}c1,c2: single; //Координаты T в базисе V1,V2
{}v1v1,v1v2,v2v2,v1t,v2t: single; //Значения различных скалярных произведений
Begin
{}I:=P;

{}V1:=V_Sub(P2,P1); V2:=V_Sub(P3,P1);
{}N:=V_Cross(V1,V2);

{}k:=v_dot(V,N);
{}//Луч лежит в плоскости треугольника, либо параллелен ей:
{}If k=0 Then Begin result:=-1; exit; End;

{}result:=v_dot(V_Sub(P1,P),N)/k;
{}//Луч не пересекается с плоскостью треугольника
{}If result<0 Then exit;

{}I:=VectorPlusVectorK(P,V,result); //Точка пересечения.
{}T:=V_Sub(I,P1);

{}v1v1:=VectorQuad(V1); v1v2:=v_dot(V1,V2); v2v2:=VectorQuad(V2);
{}v1t:=v_dot(V1,T); v2t:=v_dot(V2,T);

{}k:=v1v1*v2v2-sqr(v1v2);
{}c1:=(v1t*v2v2-v2t*v1v2)/k;
{}c2:=(v2t*v1v1-v1t*v1v2)/k;

{}If (c1<0) or (c2<0) or ((c1+c2)>1) Then result:=-1; //Луч не пересёкся с треугольником
End;

end.
