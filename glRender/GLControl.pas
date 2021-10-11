unit GLControl;
{ By SVSD_VAL  }
{$Warnings off}
interface

uses
  Windows, Messages, SysUtils,Graphics, Classes, Controls, Forms, MMSystem;

const
  // BLEND
  GL_ZERO                                            = 0;
  GL_ONE                                             = 1;

  GL_SRC_COLOR                                       = $0300;
  GL_ONE_MINUS_SRC_COLOR                             = $0301;
  GL_SRC_ALPHA                                       = $0302;
  GL_ONE_MINUS_SRC_ALPHA                             = $0303;
  GL_DST_ALPHA                                       = $0304;
  GL_ONE_MINUS_DST_ALPHA                             = $0305;
  GL_DST_COLOR                                       = $0306;
  GL_ONE_MINUS_DST_COLOR                             = $0307;
  GL_SRC_ALPHA_SATURATE                              = $0308;
  // ALPHA
  GL_LESS                                            = $0201;
  GL_EQUAL                                           = $0202;
  GL_LEQUAL                                          = $0203;
  GL_GREATER                                         = $0204;
  GL_NOTEQUAL                                        = $0205;
  GL_GEQUAL                                          = $0206;
  // Texture type
  GL_RGB                                             = $1907;
  GL_RGBA                                            = $1908;
  GL_LUMINANCE                                       = $1909;
  GL_BGR                                             = $80E0;
  GL_BGRA                                            = $80E1;
  GL_COLOR_BUFFER_BIT                                = $00004000;
  GL_DEPTH_BUFFER_BIT                                = $00000100;
  GL_ACCUM_BUFFER_BIT                                = $00000200;
  GL_STENCIL_BUFFER_BIT                              = $00000400;
  // PolyGonMode
  GL_POINTS                                          = $0000;
  GL_LINES                                           = $0001;
  GL_LINE_LOOP                                       = $0002;
  GL_LINE_STRIP                                      = $0003;
  GL_TRIANGLES                                       = $0004;
  GL_TRIANGLE_STRIP                                  = $0005;
  GL_TRIANGLE_FAN                                    = $0006;
  GL_QUADS                                           = $0007;
  GL_QUAD_STRIP                                      = $0008;
  GL_POLYGON                                         = $0009;


type
  PGLFloat   =^Single;
  PVertex3f = ^TVertex3f;
  TVertex3f = record
   X,Y,Z:Single;
  end;
  PVertex2f = ^TVertex2f;
  TVertex2f = record
   X,Y:Single;
  end;

  TBArray = array of Byte;

	TFrustumPlane = array [0..5] of array [0..3] of single;

  PGLRender =^TGLRender;
  TGLRender = class(TWinControl)
  private
    F_RC,
    F_DC,
    F_Bpp,
    F_Dpp,
    F_Spp    : Cardinal;

    F_Fov,
    F_Z_Min,
    F_Z_Max,
    FVersion : Single;

    FViewport: Array [0..3] of integer;

    FBackground: TColor;
    FFullScreen: boolean;

    FOnRender,
    FOnSetup,
    FOnDestroy  : TNotifyEvent;
    FCanRender: Boolean;
    FGL_MIP_MAP: Boolean;
    FglExtensions,
    FglRender,
    FglVendor,
    FglVersion    : String;
    FVSync     : boolean;
    procedure WMEraseBkgnd (var Message: TWMEraseBkgnd); Message WM_ERASEBKGND;
    procedure WMPaint      (var Message: TWMPaint); Message WM_PAINT;
    procedure WMSize       (var Message: TWMSize); Message WM_SIZE;
    procedure SetBackground(const Value: TColor);
    procedure ApplyBackground;
    procedure MakeCurrent;
    procedure SetVSync( Active : Boolean);
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWnd; override;
    procedure DestroyWnd; override;
    Procedure LoadFromFile( FileName : String; Var W,H,BPP:Integer;var Data:TBArray );
  public
    constructor Create(AOwner: TComponent); override;

    procedure ClearBuffer( const Mask : Cardinal );

    procedure DisableContext;
    procedure EnableContext;
    procedure RenderScene;

    property RenderingContext: Cardinal read F_RC;

    Procedure SetProjection(const Ortho: boolean; const W :Single = 0; const H:Single = 0);
    // Texture
    Function LoadTexture( const FileName : String; const  GenerateAlphaChanel:boolean=false; const AlphaColor:TColor=0; const Epsilon : Byte=0 ): Integer; overload;
    Function LoadTexture( const FileName, AlphaFileName : String ): Integer; overload;
    function CreateTexture(const Width, Height, Format : Word; const pData : Pointer) : Integer; overload;
    function CreateTexture(const Width, Height, Format : Word) : Integer; overload;

    procedure UnBindTexture(const Channel: Integer);
    procedure BindTexture(const ID: Cardinal; const Channel: Integer);
    // Blend , Alpha test & depth test
    procedure Blend( const Enable : boolean);
    procedure AlphaTest( const Enable : boolean);

    procedure BlendFunc( const SourceFactor, DestFactor: Cardinal );
    procedure AlphaFunc( const Func, Ref: Cardinal );
    procedure DepthTest( const Enable : boolean);
    procedure DepthMask( const Enable : boolean);
    // Transforms
    procedure LoadIdentity();
    procedure PushMatrix();
    procedure PopMatrix();

    procedure ViewPort ( const X,Y,W,H: Integer );

    procedure Translate( const X,Y,Z: Single);
    procedure Rotate   ( const Angle,X,Y,Z: Single);
    procedure LookAt   (const eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz: Single);
    procedure Scale    ( const X,Y,Z: Single);
    // Color
    procedure Color4ub(const R,G,B,A: Byte);
    procedure Color4f (const R,G,B,A: single);

    procedure AssignToContext(const RenderingContext: Cardinal);
    procedure CopyToTexture(const X,Y,W,H,Format: Cardinal);

    // DrawSprite
    procedure Draw2DSprite(const X,Y,CenterX, CenterY,W,H, RotateAngle : Single);

    procedure DrawPoly(const FaceCount,FaceType: Cardinal; const PVertex3f, PTexCoord2f,PColor4f : Pointer);
    procedure DrawElement(const FaceCount,FaceType:Cardinal; const PVertex,PTexCoord,PTexCoord2,PNormal,PColor:Pointer);
    procedure Draw2DAnimSprite(const x,y,sizeW,SizeH,Angle : Single;  const Frame, FrameWidth, FrameHeight, CenterX , CenterY, TextureWidth, TextureHeight:Integer);

    Function  CreateList:Cardinal;
    Procedure EndList;
    Procedure CallList(List:Cardinal);

    procedure About;
    property Version: Single Read FVersion;

  published
    Property glExtensions : String Read FglExtensions;
    Property glRender     : String Read FglRender;
    Property glVendor     : String Read FglVendor;
    Property glVersion    : String Read FglVersion;
    Property BPP : Cardinal Read F_BPP Write F_BPP;
    Property DPP : Cardinal Read F_Dpp Write F_Dpp;
    Property SPP : Cardinal Read F_Spp Write F_Spp;
    Property Fov : Single Read F_Fov Write F_Fov;
    Property Z_Min : Single Read F_Z_Min Write F_Z_Min;
    Property Z_Max : Single Read F_Z_Max Write F_Z_Max;
    Property FullScreen : boolean read FFullScreen Write FFullScreen;
    property OnRender: TNotifyEvent read FOnRender write FOnRender;
    property OnSetup  : TNotifyEvent read FOnSetup write FOnSetup;
    property OnDestroy: TNotifyEvent read FOnDestroy write FOnDestroy;
    property Background: TColor read FBackground write SetBackground;
    property VSync : Boolean read FVSync write SetVSync;
{$region 'bla bla bla'}
    property Anchors;
    property Align;
    property Constraints;
    property DragCursor;
    property DragMode;
    property Enabled;
    property HelpContext;
    property Hint;

    property PopupMenu;
    property Visible;

    property OnClick;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
//    property OnMouseActivate;
    property OnMouseDown;
//    property OnMouseEnter;
//    property OnMouseLeave;
    property OnMouseMove;
    property OnMouseUp;
{$endregion ''}
  end;

  PShader = ^TShader;
  TShader = Class (TComponent)
  private
    shaders  : array of Integer;
    Procedure SetUniformV(uniform:Cardinal; value:PGLFloat; Size:byte);
    Procedure SetAttribV (uniform:Cardinal; value:PGLFloat; Size:byte);
    function  CheckForErrors(glObject: Integer): String;
  public
    ShaderProgramm : Integer;
    constructor Create(AOwner: TComponent); override;
    procedure Load(Filename: string; Shader_Type: Cardinal;Define:String='');
    Function  Compile : boolean;
    procedure Start;
    procedure Stop;
    procedure Free;
    function  GetInfoLog: string;
    function  GetUniform(uniform: PChar): Cardinal;
    function  GetAttrib(attrib: PChar): Cardinal;
    procedure SetUniform(uniform: Cardinal; value0: Single); overload;
    procedure SetUniform(uniform: Cardinal; value0: Integer); overload;
    procedure SetUniform(uniform: Cardinal; value0, value1: Single); overload;
    procedure SetUniform(uniform: Cardinal; value0, value1, value2: Single); overload;
    procedure SetUniform(uniform: Cardinal; value0, value1, value2, value3: Single); overload;

    procedure SetAttrib (uniform: Cardinal; value0 : Single); overload;
    procedure SetAttrib (uniform: Cardinal; value0, value1 : Single); overload;
    procedure SetAttrib (uniform: Cardinal; value0, value1, value2: Single); overload;
    procedure SetAttrib (uniform: Cardinal; value0, value1, value2,value3: Single); overload;
    procedure BindUniform(uniform:Cardinal; Value: PGLFLoat; size:byte); overload;
    procedure BindUniform(const name:string; Value: PGLFLoat; size:byte); overload;
    procedure BindAttrib(uniform:Cardinal; Value: PGLFLoat; size:Byte); overload;
    procedure BindAttrib(const name:string; Value: PGLFLoat; size:byte); overload;
  end;

  TFrustum  = Class(TComponent)
   Public
  	Frustum	: TFrustumPlane;
    DrawOBJS: Cardinal;
    proj : array [0..15] of single;	// This will hold our projection matrix
    modl : array [0..15] of single;	// This will hold our modelview matrix
    constructor Create(AOwner: TComponent); override;

    Procedure CalculateFrustum;

    function  PointInFrustum (const V:PVertex3f) : BOOLEAN;
    function  SphereInFrustum(const V:PVertex3f; const radius : single) : boolean;
    function  CubeInFrustum  (const V:PVertex3f; size : single) : boolean;
    function  BoxInFrustum   (const Min,Max:PVertex3f) : boolean;
  end;

  TCustomGLTimerEvent = procedure(Sender: TObject; LagCount: Integer) of object;
   {From Dxtimer}
  TCustomGLTimer = class(TComponent)
  private
    FActiveOnly  : Boolean;
    FEnabled     : Boolean;
    FInitialized : Boolean;
    FFrameRate   : Integer;
    FNowFrameRate: Integer;
    FFrameTime   : Cardinal;
    FInterval    : Cardinal;
    FInterval2   : Cardinal;
    FOldTime     : Cardinal;
    FOldTime2    : Cardinal;
    FOnActivate  : TNotifyEvent;
    FOnDeactivate: TNotifyEvent;
    FOnTimer     : TCustomGLTimerEvent;
    procedure AppIdle(Sender: TObject; var Done: Boolean);
    function AppProc(var Message: TMessage): Boolean;
    procedure Finalize;
    procedure Initialize;
    procedure Resume;
    procedure SetActiveOnly(Value: Boolean);
    procedure SetEnabled(Value: Boolean);
    procedure SetInterval(Value: Cardinal);
    procedure Suspend;
  protected
    procedure DoActivate; virtual;
    procedure DoDeactivate; virtual;
    procedure DoTimer(LagCount: Integer); virtual;
    procedure Loaded; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property ActiveOnly  : Boolean read FActiveOnly write SetActiveOnly;
    property Enabled     : Boolean read FEnabled write SetEnabled;
    property FrameRate   : Integer read FFrameRate;
    property Interval    : Cardinal read FInterval write SetInterval;
    property FrameTime   : Cardinal read FFrameTime;
    property OnActivate  : TNotifyEvent read FOnActivate write FOnActivate;
    property OnDeactivate: TNotifyEvent read FOnDeactivate write FOnDeactivate;
    property OnTimer     : TCustomGLTimerEvent read FOnTimer write FOnTimer;
  end;

  TGLTimer = class(TCustomGLTimer)
  published
    property ActiveOnly;
    property Enabled;
    property Interval;
    property OnActivate;
    property OnDeactivate;
    property OnTimer;
  end;

   TXMMusic = Class(TComponent)
   Private
    FTitle  : String;
    FXM     : PByteArray;
    FXMSize : Cardinal;
   Public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
      function LoadFromFile(const FileName: String) : Boolean;
      function LoadFromMem(const XM:Pointer; const Size: Cardinal) : Boolean;
      function Play:Pointer;
      procedure Jump2Pattern(pat:Cardinal);
      procedure Rewind;
      procedure Pause;
      procedure Resume;
      procedure Stop;
      function  GetStats : Cardinal;
      function  GetRowOrder : Cardinal;
      function  GetTime  : Cardinal;
      procedure SetVolume(vol:LongWord);
   published
      property  GetTitle : String read FTitle;
   end;


 TGLSound = Class(TComponent)
  Private
   DXSound : Pointer;
  Public
   constructor Create(AOwner: TComponent); override;
   destructor Destroy; override;
   function  Init(WND:HWND): boolean;
   function  Load             (const FileName: string): integer;
   function  FreeSample       (Sample_ID: integer): boolean;
   procedure BeginUpdate;
   procedure EndUpdate;
   function  Play             (Sample_ID: integer; Loop: boolean; X,Y,Z:Single ): integer;
   function  Stop             (var Channel_ID: integer): boolean;
   function  SetMuteDist      (Channel_ID: integer; Min,MAx:Single ): boolean;
   procedure StopAll          (Sound_ID: integer);
   function  SetVolume        (Channel_ID: integer; Volume: integer): boolean;
   function  SetPos           (Channel_ID: integer; X,Y,Z:Single): boolean;
   procedure SetPos2GlobalPos (Channel_ID: integer; Accept:boolean);
   function  SetFreq          (Channel_ID: integer; Freq: DWORD): boolean;
   procedure SetVelocity      (Channel_ID: integer; X,Y,Z:Single);
   procedure SetOrientation   (frontx,fronty,frontz, topx,topy,topz:Single);
   procedure SetDopplerFactor (factor: single);
   procedure SetRolloffFactor (factor: single);
   procedure SetDistanceFactor(Dst   : single);
   procedure SetGlobalPos     (X,Y,Z:Single);
   procedure SetGlobalVelocity(X,Y,Z:Single);
   procedure Update;
end;


procedure Register;

{$Include OpenGL15.inc}
implementation

{$Include OpenGL15i.inc}

//uses ufmod;
Type TVec3f = Record x,y,z:Single; end;
 Function Vec3f(x,y,z:Single): TVec3f;
 begin Result.x := x; result.y:=y; Result.z:=z; end;


{$Include Textures.inc}
{$Include ufmod.inc}
{$Include l_sound.inc}

const
  ByteToFloat = 1/255;
  CurVersion  = 0.2;
  {

  PVertex3fArray = ^TVertex3fArray;
  PVertex2fArray = ^TVertex2fArray;
  TVertex3fArray = array [0..1] of TVertex3f;
  TVertex2fArray = array [0..1] of TVertex2f;
  }
//----------------------------------------------------------------------------------------------------------------------

procedure Register;
begin
  RegisterComponents('SVSD_VAL OpenGL GraphLib',
  [TGLRender, TGLTimer
  ,TShader  , TFrustum, TXMMusic,TGLSound
   ]);
end;

//----------------- TGLRender -----------------------------------------------------------------------------------------
procedure TGLRender.About;
begin
  MessageBox(0,Pchar (
           'OpenGL Render v'+floattostr(Version)
 +#13+#10+ '-= ****** =-'
 +#13+#10+ 'By SVSD_VAL'
 +#13+#10+ 'Icq: 223-725-915'
 +#13+#10+ 'Mail: valdim_05@mail.ru'
 +#13+#10+ 'Jabber: svsd_val@jabber.ru'
 +#13+#10+ 'site: http://rtbt.ru'
 +#13+#10+ '-= ******* =-'
 +#13+#10+ '2010.03.01'
            ),nil, MB_ICONWARNING);
end;

procedure TGLRender.ClearBuffer;
begin
  glClear( Mask );
end;

procedure TGLRender.MakeCurrent;
begin
  Assert((f_DC <> 0), 'DC must not be 0');
  Assert((f_RC <> 0), 'RC must not be 0');
  wglMakeCurrent(f_DC, f_RC);
end;

//----------------------------------------------------------------------------------------------------------------------

constructor TGLRender.Create(AOwner: TComponent);

begin
  inherited;
  Width   := 150;
  Height  := 150;
  F_BPP   := 32;
  F_DPP   := 24;
  F_SPP   := 24;
  F_FOV   := 45;
  F_Z_MIN := 1;
  F_Z_MAX := 100;
  FVersion:= CurVersion;
  FFullScreen := false;
  FGL_MIP_MAP := false;
  FCanRender  := True;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.CreateParams(var Params: TCreateParams);

begin
  inherited;
  with Params do
  begin
    Style := Style or WS_CLIPCHILDREN or WS_CLIPSIBLINGS;
    WindowClass.Style :=  CS_VREDRAW or CS_HREDRAW;
  end
end;


//----------------------------------------------------------------------------------------------------------------------

Procedure TGLRender.SetProjection(const Ortho: boolean; const W :Single = 0; const H:Single = 0);
begin
  if FViewPort[3] = 0 then FViewPort[3] :=1;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if ortho then
    begin
    if (W > 0) and (h > 0) then
    glOrtho(0, W, H, 0, -100, 100) else

    glOrtho(0, FViewPort[2], FViewPort[3], 0, -10, 100)
    end
  else
    gluPerspective(F_FOV, FViewPort[2]/FViewPort[3], F_Z_MIN, F_Z_MAX);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

end;



procedure TGLRender.CreateWnd;
var
 pfd     : PIXELFORMATDESCRIPTOR;
 d       : DEVMODE;
 iFormat : integer;
begin
  inherited;

  {$IFDEF WIN32}
   InitOpenGL('OpenGL32.dll','GLU32.dll');
  {$ELSE}
   InitOpenGL('libGL.so.1','libGLU.so.1');
  {$ENDIF}

  F_DC := GetDC(Handle);
  FillChar(pfd, SizeOf(pfd), 0);
  with pfd do begin
   nSize      := SizeOf(TPIXELFORMATDESCRIPTOR);
   nVersion   := 1;
   dwFlags    := PFD_DRAW_TO_WINDOW or PFD_SUPPORT_OPENGL or PFD_DOUBLEBUFFER;
   iPixelType := PFD_TYPE_RGBA;
   cColorBits := F_BPP;
   cDepthBits := F_DPP;
   iLayerType := PFD_MAIN_PLANE ;
  end;

  if FFULLSCREEN then
  begin
    ZeroMemory(@d, SizeOf(d));
    with d do
    begin
      dmSize      := SizeOf(d);
      dmPelsWidth := width;
      dmPelsHeight:= height;
      dmBitsPerPel:= bpp;
      dmFields    := DM_PELSWIDTH or DM_PELSHEIGHT or DM_BITSPERPEL;
    end;
      ChangeDisplaySettings(d,CDS_FULLSCREEN);
  end;

 iFormat := ChoosePixelFormat(F_DC,          @pfd);
               SetPixelFormat(F_DC, iFormat, @pfd);
    F_RC :=  wglCreateContext(F_DC);
 ActivateRenderingContext(f_dc, f_rc);

 fviewport[0] := 0;
 fviewport[1] := 0;
 fviewport[2] := Self.Width;
 fviewport[3] := Self.Height;
  // Set the viewport to the entire window size.
 SetProjection(false);

 glEnable   (GL_DEPTH_TEST);
 glDepthFunc(GL_LESS);
 glHint     (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
 glEnable   (GL_TEXTURE_2D);
 glAlphaFunc(GL_GEQUAL, 0.1);
 FglExtensions := glGetString(GL_EXTENSIONS);
 FglRender     := glGetString(GL_Renderer);
 FglVendor     := glGetString(GL_VENDOR);
 FglVersion    := glGetString(GL_Version);

  if Assigned(FOnSetup) then
     FOnSetup(Self);

  ApplyBackground;
  DeactivateRenderingContext;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.DestroyWnd;

begin
  if Assigned(FOnDestroy) then
              FOnDestroy(Self);

  if FFULLSCREEN then
  If ChangeDisplaySettings(DEVMODE(nil^),0)=0 then;

  wglMakeCurrent  (F_DC,0);                         //Отключаем OGL
  wglDeleteContext(F_RC);                           //Удаляем OGL
  ReleaseDC       (handle,F_DC);                     //Освобажаем Канвас

  inherited;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.RenderScene;

// This is the actual paint routine. All initialization must already have been done.
// The event FOnRender is triggered to let the application draw whatever is needed.

begin
  MakeCurrent;

  ClearBuffer( GL_color_BUFFER_BIT or GL_DEPTH_BUFFER_BIT );
  glLoadIdentity;

  if Assigned(FOnRender) then
    FOnRender(Self);

  SwapBuffers(f_dc);
  DeactivateRenderingContext;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.ApplyBackground;
var
  Color: COLORREF;
  R, G, B: Single;
begin
  MakeCurrent;

  Color := ColorToRGB(FBackground);
  R := GetRValue(Color) / 255;
  G := GetGValue(Color) / 255;
  B := GetBValue(Color) / 255;
  glClearColor(R, G, B, 1);
  Refresh;
end;
//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.SetBackground(const Value: TColor);

begin
  if FBackground <> Value then
  begin
    FBackground := Value;
    if not (csLoading in ComponentState) then
            ApplyBackground;
  end;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.WMEraseBkgnd(var Message: TWMEraseBkgnd);

begin
  Message.Result := 1;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.WMPaint(var Message: TWMPaint);

var
  PS: TPaintStruct;

begin
  BeginPaint(Handle, PS);
  if FCanRender then
     RenderScene;
  EndPaint(Handle, PS);
  Message.Result := 0;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.WMSize(var Message: TWMSize);

begin
  // Update viewport (here always the entire window).
    FViewPort[2] := Message.Width;
    FViewPort[3] := Message.Height;
    if FViewPort[3] = 0 then
       FViewPort[3] := 1;

  if (F_RC <> 0) and  FCanRender then
  begin
    MakeCurrent;
    glViewPort(0,0, FViewPort[2], FViewPort[3]);
    SetProjection(false);
    DeactivateRenderingContext;
  end;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.DisableContext;
begin
  FCanRender := False;
end;

//----------------------------------------------------------------------------------------------------------------------

procedure TGLRender.EnableContext;

begin
   if FCanRender then exit;
      FCanRender := True;

      if F_RC <> 0 then
      begin
        MakeCurrent;
        DeactivateRenderingContext;
      end;
end;

//----------------------------------------------------------------------------------------------------------------------
{
Procedure TGLRender.LoadFromFile( FileName : String; Var W,H,BPP:Integer; var Data:PByteArray );
var
  BMP  : TBitmap;
  JPG  : TJPEGImage;
  ext  : String;
  N,
  X, Y : Integer;
  Line : ^Cardinal;
  C    :  Cardinal;
begin
Try
  JPG  := nil;
  BMP  := nil;

  if not fileexists(filename) then
  begin
    MessageBox(0,Pchar('File not found : '+#13+#10+FileName),nil,MB_ICONERROR);
    W   :=0;
    H   :=0;
    BPP :=0;
    Data:=nil;
    exit;
  end;

  ext  := copy(Uppercase(filename), length(filename)-3, 4);
  BMP  := TBitmap.Create;
  BMP.pixelformat := pf32bit;

  if ext = '.JPG' then
  begin
  JPG  := TJPEGImage.Create;
  JPG.LoadFromFile(FileName);
  BMP.pixelformat := pf32bit;
  BMP.width       := JPG.width;
  BMP.height      := JPG.height;
  BMP.canvas.draw(0,0,JPG);        // Copy the JPEG onto the Bitmap
  end else
  BMP.LoadFromFile(FileName);
  BMP.pixelformat := pf32bit;

  W   := BMP.Width;
  H   := BMP.Height;
  BPP := 3;

  GetMem(Data, W * H * BPP );

  For Y:=0 to H-1 do
  Begin
    Line := BMP.scanline[Y];   // flip JPEG
    For X:=0 to W-1 do
    Begin
//   c:=bmp.Canvas.Pixels[x,y];
      c:= Line^ and $FFFFFF; // Need to do a color swap
      n := (X+(Y*W) ) * BPP;
      Data[n    ] := GetBValue( c );
      Data[n + 1] := GetGValue( c );
      Data[n + 2] := GetRValue( c );
       inc(Line);
    End;
  End;

   bmp.Free;
 if jpg <> nil then
    jpg.Free;

  except
   MessageBox(0,Pchar('Some Error on loading texture file!!'
    +#13+#10+ 'File :' + FileName
    +#13+#10+ Inttostr(W) + ' ' + Inttostr(H)
    +#13+#10+ 'Send message to my papa , icq 223-725-915'
    ),nil, MB_ICONError);
   FreeMem(data);
   bmp.Free;
   if jpg <> nil then
      jpg.Free;
  end;

end;
}
 {
procedure SwapRGB(data : Pointer; Size : Integer);
asm
  mov ebx, eax
  mov ecx, size

@@loop :
  mov al,[ebx+0]
  mov ah,[ebx+2]
  mov [ebx+2],al
  mov [ebx+0],ah
  add ebx,3
  dec ecx
  jnz @@loop
end;
}
procedure SwapRGB(data : PbyteArray; Size,bpp : Integer);
var i : integer;
    C : Byte;
begin
    for I :=0 to Size - 1 do
    begin
      c  := Data[i*bpp+2];
            Data[i*bpp+2] := Data[i*bpp];
            Data[i*bpp  ] := c;
    end;
end;

procedure LoadBMP(FileName : String; Var W,H,BPP:Integer; var Data:PByteArray);
var
  FileHeader    : BITMAPFILEHEADER;
  InfoHeader    : BITMAPINFOHEADER;
  Palette       : array of RGBQUAD;

  F             : File Of byte;
  BitmapLength  : LongWord;
  PaletteLength : LongWord;
  ReadBytes     : LongWord;
begin
    W   :=0;
    H   :=0;
    BPP :=0;
    Data:=nil;

  if not fileexists(filename) then
  begin
    MessageBox(0,Pchar('File not found : '+#13+#10+FileName),nil,MB_ICONERROR);
    exit;
  end;

  AssignFile(F, FileName);
  Reset(F);


    Blockread(f, FileHeader, SizeOf(FileHeader));
    Blockread(f, InfoHeader, SizeOf(InfoHeader));
    if InfoHeader.biBitCount <24 then
    begin
          MessageBox(0, PChar('Поддерживается только 24, 32'), PChar('BMP Unit'), MB_OK);
          closefile(f);
          Exit;
    end;
    // Get palette
    PaletteLength := InfoHeader.biClrUsed;
    SetLength(Palette, PaletteLength);
    BlockRead(F, Palette, PaletteLength, ReadBytes);
      if (ReadBytes <> PaletteLength) then
        begin
          MessageBox(0, PChar('Error reading palette'), PChar('BMP Unit'), MB_OK);
          closefile(f);
          Exit;
        end;

    W   := InfoHeader.biWidth;
    H   := InfoHeader.biHeight;
    bpp := InfoHeader.biBitCount Div 8;
       BitmapLength := InfoHeader.biSizeImage;
    if BitmapLength  = 0 then
       BitmapLength := W * H * InfoHeader.biBitCount Div 8;

    // Get the actual pixel data
    GetMem(Data, BitmapLength);

//    GetMem(Data, W*H* bpp);

    BlockRead(f, Data[0], BitmapLength, ReadBytes);
//    SwapRGB(data,w*h,bpp);
    if (ReadBytes <> BitmapLength) then
    begin
      MessageBox(0, PChar('Error reading bitmap data'), PChar('BMP Unit'), MB_OK);
      Exit;
    end;
   CloseFile(F);;

end;



Procedure TGLRender.LoadFromFile( FileName : String; Var W,H,BPP:Integer; var Data:TBArray);
var
  ext  : String;
begin
Try

  if not fileexists(filename) then
  begin
    MessageBox(0,Pchar('File not found : '+#13+#10+FileName),nil,MB_ICONERROR);
    W   :=0;
    H   :=0;
    BPP :=0;
    SetLength(Data,0);
    exit;
  end;

  ext  := copy(Uppercase(filename), length(filename)-3, 4);
           {
  if (ext ='.BMP')  then
  begin
    LoadBMP(filename,w,h,bpp,data);
  end else}
  if (ext ='.BMP') or (ext ='.JPG') or (ext = '.GIF') then
  begin
    LoadBJG(Pchar(filename),w,h,bpp,data);
    //    SwapRGB(data,w*h,bpp);
  end else
  begin
    w:=32;
    h:=32;
    bpp:=4;
    SetLength(data,w*h*bpp);
  end;

  except
   MessageBox(0,Pchar('Some Error on loading texture file!!'
    +#13+#10+ 'File :' + FileName
    +#13+#10+ Inttostr(W) + ' ' + Inttostr(H)
    +#13+#10+ 'Send message to my papa , icq 223-725-915'
    ),nil, MB_ICONError);
   SetLength(data,0);
  end;

end;


function TGLRender.CreateTexture(const Width, Height, Format : Word; const pData : Pointer) : Integer;
begin
  glGenTextures(1, @Result );
  glBindTexture(GL_TEXTURE_2D, Result);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);      {Texture blends with object background}

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); { only first two can be used }
  if FGL_MIP_MAP then
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR) else

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); { all of the above can be used }

  case format of
   GL_RGBA,32 :
      gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, Width, Height, GL_RGBA, GL_UNSIGNED_BYTE, pData);
   GL_RGB ,24 :
      gluBuild2DMipmaps(GL_TEXTURE_2D, 3, Width, Height, GL_RGB, GL_UNSIGNED_BYTE, pData);
   GL_BGRA    :
     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, Width, Height, GL_BGRA, GL_UNSIGNED_BYTE,  pData);
   GL_RGB8    :
     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB8, Width, Height, GL_RGB , GL_UNSIGNED_BYTE,  pData);
   GL_LUMINANCE_ALPHA :
     gluBuild2DMipmaps(GL_TEXTURE_2D, 2, Width, Height, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, pData);
  end;
end;

function TGLRender.CreateTexture(const Width, Height, Format : Word) : Integer;
begin
    glGenTextures(1, @Result);
    glBindTexture(GL_TEXTURE_2D, Result);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glCopyTexImage2D(GL_TEXTURE_2D, 0, Format, 0, 0, Width, Height, 0);
end;


Function TGLRender.LoadTexture( const FileName : String; const GenerateAlphaChanel:boolean=false; const AlphaColor:TColor=0; const Epsilon:Byte = 0 ): Integer;
var
  TexData,
     Data : TBArray;
     n,n2,
     W,H,
     X,Y,
     BPP  : Integer;
     RGB  : Array [0..2] of byte;
begin
  if not fileexists(filename) then
  begin
    MessageBox(0,Pchar('File not found : '+#13+#10+FileName),nil,MB_ICONERROR);
    result:=-1;
    exit;
  end;

  LoadFromFile(FileName,W,H,BPP,TexData);

   if GenerateAlphaChanel then
      begin
        RGB[0] := GetRValue( AlphaColor );
        RGB[1] := GetGValue( AlphaColor );
        RGB[2] := GetBValue( AlphaColor );
        bpp    := 4;

        SetLength(Data, W * H * bpp );

       For Y:=0 to H-1 do
       For X:=0 to W-1 do
        Begin
          n2 := (X+(Y*W)) * 4;
          n  := (X+(Y*W)) * bpp;
          Data[n    ] :=TexData[ n2   ];
          Data[n + 1] :=TexData[ n2 +1];
          Data[n + 2] :=TexData[ n2 +2];

           if ( abs( RGB[0] - Data[n   ]) < Epsilon ) and
              ( abs( RGB[1] - Data[n +1]) < Epsilon ) and
              ( abs( RGB[2] - Data[n +2]) < Epsilon ) then
                Data[n +3] := 0 else
                Data[n +3] := 255;
        end;
        SetLength(TexData,0);
                TexData:=Data;
//   Result := CreateTexture(W,H, GL_RGBA , TexData);
     end;

     Result := CreateTexture(W,H, GL_BGRA , TexData);
     SetLength(TexData,0);
end;

Function TGLRender.LoadTexture( const FileName, AlphaFileName : String ): Integer;
var
  TexData1,
  TexData2,
     Data : TBArray;
     n,n2,n3,
     W,H, W2,H2,
     X,Y,
     BPP,bpp2,
     nbpp  : Integer;
begin
  if not fileexists(filename) then
  begin
    MessageBox(0,Pchar('File not found : '+#13+#10+FileName),nil,MB_ICONERROR);
    result:=-1;
    exit;
  end;

  if not fileexists(AlphaFileName)  then
  begin
    MessageBox(0,Pchar('File not found : '+#13+#10+AlphaFileName),nil,MB_ICONERROR);
    result:=-1;
    exit;
  end;

  LoadFromFile(FileName     ,W ,H ,BPP,TexData1);
  LoadFromFile(AlphaFileName,W2,H2,BPP2,TexData2);
  if (W <> W2) or (H <> H2) then
  begin
    SetLength(TexData1,0);
    SetLength(TexData2,0);
    MessageBox(0,Pchar('Размеры текстур не совпадают : '
          +#13+#10+FileName
          +#13+#10+AlphaFileName
          ),nil,MB_ICONERROR);
    result:=-1;
    exit;
  end;

        nbpp    := 4;
        SetLength(Data, W * H * nbpp );

       For Y:=0 to H-1 do
       For X:=0 to W-1 do
        Begin
          n2 := (X+(Y*W))* bpp;
          n3 := (X+(Y*W))* bpp2;
          n  := (X+(Y*W))* nbpp;
          Data[n    ] :=  TexData1[ n2   ];
          Data[n + 1] :=  TexData1[ n2 +1];
          Data[n + 2] :=  TexData1[ n2 +2];
          Data[n + 3] := (TexData2[ n3 +0 ] + TexData2[ n3 +1 ] + TexData2[ n3 +2 ]) div 3 ;
        end;
        SetLength(TexData1,0);
        SetLength(TexData2,0);

     Result := CreateTexture(W,H, GL_BGRA , Data);
     SetLength(Data,0);
end;


procedure TGLRender.BindTexture(const ID: Cardinal; const Channel: Integer);
begin
  glActiveTextureARB(GL_TEXTURE0_ARB + Channel);
  glEnable(GL_TEXTURE_2D);
  // если текстура не существует - включаем текстуру по умолчанию
  if not glIsTexture(ID) then
        glBindTexture(GL_TEXTURE_2D,  0) else
        glBindTexture(GL_TEXTURE_2D, ID);
end;

procedure TGLRender.UnBindTexture(const Channel: Integer);
begin
  glActiveTextureARB(GL_TEXTURE0_ARB + Channel);
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
end;

procedure TGLRender.AlphaTest( const Enable : boolean);
begin
if Enable then
    glEnable (GL_Alpha_Test) else
    glDisable(GL_Alpha_Test);

end;

procedure TGLRender.Blend( const Enable : boolean);
begin
if Enable then
    glEnable (GL_blend) else
    glDisable(GL_blend);
end;

procedure TGLRender.BlendFunc( const SourceFactor, DestFactor: Cardinal );
begin
    glBlendFunc(SourceFactor, DestFactor);
end;

procedure TGLRender.AlphaFunc( const Func, Ref: Cardinal );
begin
    glAlphaFunc(Func, Ref);
end;

procedure TGLRender.DepthTest( const Enable : boolean);
begin
if Enable then
    glEnable (GL_Depth_Test) else
    glDisable(GL_Depth_Test);
end;

procedure TGLRender.DepthMask( const Enable : boolean);
begin
  GlDepthMask(enable);
end;

procedure TGLRender.Translate( const X,Y,Z: Single);
begin
 GLTranslateF(X,Y,Z);
end;

procedure TGLRender.Rotate( const Angle,X,Y,Z: Single);
begin
 glRotateF(Angle,X,Y,Z);
end;

procedure TGLRender.Scale( const X,Y,Z: Single);
begin
 GLScaleF(X,Y,Z);
end;

procedure TGLRender.ViewPort ( const X,Y,W,H: Integer );
begin
 FViewPort[0]:=X; FViewPort[1]:=Y;
 FViewPort[2]:=W; FViewPort[3]:=H;
 glViewPort( FViewPort[0],FViewPort[1],
             FViewPort[2],FViewPort[3]);

end;

procedure TGLRender.LoadIdentity();
begin
 glLoadIdentity;
end;

procedure TGLRender.PushMatrix();
begin
 glPushMatrix;
end;

procedure TGLRender.PopMatrix();
begin
 glPopMatrix;
end;


procedure TGLRender.Color4ub(const R,G,B,A: Byte);
begin
 glColor4f(r* ByteToFloat,
           g* ByteToFloat,
           b* ByteToFloat,
           a* ByteToFloat);
end;

procedure TGLRender.Color4f(const R,G,B,A: single);
begin
 glColor4f(r,g,b,a);
end;

procedure TGLRender.LookAt(const eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz: Single);
begin
    gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
end;

procedure TGLRender.AssignToContext(const RenderingContext: Cardinal);
begin
    wglShareLists( RenderingContext, f_rc);
end;

procedure TGLRender.CopyToTexture(const X,Y,W,H,Format: Cardinal);
begin
    glCopyTexImage2D(GL_TEXTURE_2D,0,Format,X,Y,W,H,0);
end;

procedure TGLRender.Draw2DSprite(const X,Y,CenterX, CenterY,W,H, RotateAngle: Single);
begin
GLPushMatrix;
  glTranslatef(x, y, 0);                        // Переносим позицию мира
  GlRotatef( RotateAngle ,0,0,1);                        // Разворачиваем мир
  glTranslateF(-CenterX,-CenterY,0);

         glBegin(GL_QUADS);                       // Наченаем рисовать кубы
         //Устанавливем текст координады ; Ставим точку
           glTexcoord2f(1, 0); glVertex2f( W , 0);
           glTexcoord2f(0, 0); glVertex2f( 0 , 0);
           glTexcoord2f(0, 1); glVertex2f( 0 , H);
           glTexcoord2f(1, 1); glVertex2f( W , H);
         glEnd;                                   // Останавливаем рисование
GLPopMatrix;
end;

procedure TGLRender.DrawPoly(const FaceCount,FaceType: Cardinal; const PVertex3f, PTexCoord2f,PColor4f : Pointer);
var
 i      : integer;
begin
 if PVertex3f = nil then exit;
          glBegin(FaceType);                       // Наченаем рисовать кубы
           for i := 0 to FaceCount+1 do
           begin
           //Устанавливем текст координады ; Ставим точку
             if PColor4f <> nil then
             glColor4fv(Pointer( Integer(PColor4f)      + i*16 ));
             if PTexCoord2f <> nil then
             glTexcoord2fv(Pointer( Integer(PTexCoord2f)+ i*8  ));
             glVertex3fv  (Pointer( Integer(PVertex3f)  + i*12 ));
           end;
         glEnd;                                   // Останавливаем рисование
end;

procedure TGLRender.DrawElement;
begin
   if (PVertex=nil) or (FaceCount <=0) then exit;

   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer  (3, GL_FLOAT, 3*4 , PVertex  );

   if PNormal <> nil then
   begin
    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer  (   GL_FLOAT, 0, PNormal);
   end;

   if PColor <> nil then
   begin
    glEnableClientState(GL_Color_ARRAY);
    glColorPointer  (4,GL_FLOAT, 4*4, PColor);
   end;


   if PTexCoord <> nil then
   begin
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glClientActiveTextureARB(GL_TEXTURE0_ARB);
    glTexCoordPointer(2, GL_FLOAT, 0, PTexCoord);

    if PTexCoord2 <> nil then
     begin
      glClientActiveTextureARB(GL_TEXTURE1_ARB);
       glTexCoordPointer(2, GL_FLOAT, 0, PTexCoord2);
     end;                                
   end;

     glDrawArrays(FaceType,0,FaceCount);

   if PTexCoord <> nil then
     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
   if PNormal <> nil then
     glDisableClientState(GL_NORMAL_ARRAY);
   if PColor <> nil then
     glEnableClientState(GL_Color_ARRAY);

   glDisableClientState(GL_VERTEX_ARRAY);
end;


procedure TGLRender.Draw2DAnimSprite(const x,y,sizeW,SizeH,Angle : Single;
     const Frame,
     FrameWidth,FrameHeight,
     CenterX   , CenterY,
     TextureWidth, TextureHeight:Integer);
var
    YY,xx,
    pixelx,pixely,
    TexW,TexH   : Single;
    Symbols : Integer;
begin
  if (FrameWidth = 0) or (TextureWidth = 0) or (TextureHeight =0) then exit;
  glPushMatrix;
  glTranslateF(x , y , 0);
     glRotateF(Angle,0,0,1);
  glTranslateF(-centerx , -centery , 0);


      TexW    := 1 / TextureWidth;
      TexH    := 1 / TextureHeight;
      Symbols := round(TextureWidth / FrameWidth);

      pixelX:=  FrameWidth  * TexW;
      pixelY:=  FrameHeight * TexH;
      xx    :=  FrameWidth  * ( frame mod Symbols) * TexW;
      yy    :=  FrameHeight * ( frame div Symbols) * TexH;

          glBegin(GL_Quads);                       // Наченаем рисовать кубы
             glTexcoord2f (xx       ,yy);
             glVertex2f   ( 0    ,     0 );
             glTexcoord2f (xx+pixelx,yy);
             glVertex2f   ( SizeW,     0 );
             glTexcoord2f (xx+pixelx,yy+pixely);
             glVertex2f   ( SizeW, SizeH );
             glTexcoord2f (xx       ,yy+pixely);
             glVertex2f   ( 0    , SizeH );
         glEnd;                                   // Останавливаем рисование
 glPopMatrix;
end;



Function  TGLRender.CreateList:Cardinal;
begin
  Result := glGenLists(1);
  glNewList(Result, GL_COMPILE);
end;

Procedure TGLRender.EndList;
begin
  glEndList;
end;

Procedure TGLRender.CallList(List:Cardinal);
begin
    glCallList(List);
end;


procedure TGLRender.SetVSync( Active : Boolean);
begin
 if fvsync = Active then exit;
       if @wglSwapIntervalEXT <> nil then
           wglSwapIntervalEXT(Byte( Active ));
       fvsync:=active;
end;

Const
 WND_GLSL = 'GLSL 1.00 :';

function TShader.CheckForErrors(glObject: Integer): String;
 var
  blen, slen: GLInt;
  InfoLog   : PGLCharARB;
begin
 glGetObjectParameterivARB(glObject, GL_OBJECT_INFO_LOG_LENGTH_ARB, @blen);
 if blen > 1 then
 begin
  GetMem(InfoLog, blen*SizeOf(PGLCharARB));
  glGetInfoLogARB(glObject, blen , slen, InfoLog);
  Result:= PChar(InfoLog);
  Dispose(InfoLog);
 end;
end;

procedure TShader.Load(Filename: string; Shader_Type: Cardinal;Define:String='');
var
  str,tmp: string;
  F      : Text;
  source : PChar;
  shader : Cardinal;
  i,
  status : integer;
begin
  if not GL_ARB_shading_language_100 then
//  begin
//    MessageBox('Can''t initializate Shader', 1);
    exit;
 // end;

  If Not FileExists(FileName) then exit;

  str := '';
  for I := 1 to Length(Define)  do
  case Define[i] of
   '|':  str := str + #13+#10;
  else  str := str + Define[i];
  end;
//  messagebox(str +#13+#10 + 'define:'+define,0);

  AssignFile(f, Filename);
  Reset(f);
  repeat
    ReadLn(f, tmp);
    str := str + tmp + #13#10;
  until Eof(f);
  CloseFile(f);

  source := PChar(str);
  shader := glCreateShaderObjectARB(Shader_Type);
  if shader = 0 then
  begin
    MessageBox(0, 'Error creating shader object', 'Error', MB_OK);
    exit;
  end;
  glShaderSourceARB(shader, 1, @source, nil);
  glCompileShaderARB(shader);
  glGetObjectParameterivARB(shader, GL_OBJECT_COMPILE_STATUS_ARB, @status);
  if status <> 1 then
  begin
    messagebox(0,Pchar(CheckForErrors(shader) +#13+#10+filename),'',1);
    glDeleteObjectARB(shader);
    exit;
  end;
  SetLength(shaders, length(shaders)+1);
  shaders[length(shaders)-1] := shader;
end;

Function TShader.Compile : boolean;
var
  i: integer;
  status: integer;
begin
result:=false;
  if not GL_ARB_shading_language_100 then exit;

  ShaderProgramm := glCreateProgramObjectARB;
  for i := 0 to length(shaders)-1 do
    glAttachObjectARB(ShaderProgramm, shaders[i]);
  glLinkProgramARB(ShaderProgramm);

  glGetObjectParameterivARB(ShaderProgramm, GL_OBJECT_LINK_STATUS_ARB, @status);
  Result:=true;

  if status <> 1 then
  begin
    Result:=false;
    glDeleteObjectARB(ShaderProgramm);
    MessageBox(0,'Error while compiling','', 1);
    exit;
  end;
end;

procedure TShader.Start;
begin
  if not GL_ARB_shading_language_100 then exit;
  glUseProgramObjectARB(ShaderProgramm);
end;

function TShader.GetInfoLog: string;
var
  LogLen, Written: Integer;
begin
  Result:='';
  glGetObjectParameterivARB(ShaderProgramm, GL_OBJECT_INFO_LOG_LENGTH_ARB, @LogLen);
  if LogLen<1 then Exit;
  SetLength(Result, LogLen);
  glGetInfoLogARB(ShaderProgramm, LogLen, Written, PChar(Result));
  SetLength(Result, Written);
end;

procedure TShader.Stop;
begin
  if not GL_ARB_shading_language_100 then exit;
  glUseProgramObjectARB(0);
end;

procedure TShader.Free;
begin
  if not GL_ARB_shading_language_100 then exit;
  glDeleteObjectARB(ShaderProgramm);
end;

function TShader.GetUniform(uniform: PChar): Cardinal;
begin
  Result := 0;
  if not GL_ARB_shading_language_100 then exit;
  Result := glGetUniformLocationARB(ShaderProgramm, uniform);
end;

function TShader.GetAttrib(attrib: PChar): Cardinal;
begin
  Result := 0;
  if not GL_ARB_shading_language_100 then exit;
  Result := glGetAttribLocationARB(ShaderProgramm, attrib);
end;

procedure TShader.SetUniform(uniform: Cardinal; value0: Integer);
begin
  if not GL_ARB_shading_language_100 then exit;
  glUniform1iARB(uniform, value0);
end;

procedure TShader.SetUniform(uniform: Cardinal; value0: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glUniform1fARB(uniform, value0);
end;

procedure TShader.SetUniform(uniform: Cardinal; value0, value1: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glUniform2fARB(uniform, value1, value1);
end;

procedure TShader.SetUniform(uniform: Cardinal; value0, value1, value2: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glUniform3fARB(uniform, value0, value1, value2);
end;

procedure TShader.SetUniform(uniform: Cardinal; value0, value1, value2, value3: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glUniform4fARB(uniform, value0, value1, value2, value3);
end;

procedure TShader.SetAttrib(uniform: Cardinal; value0: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glVertexAttrib1f(uniform,value0);
end;

procedure TShader.SetAttrib(uniform: Cardinal; value0: Single; value1: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glVertexAttrib2f(uniform,value0,value1);
end;

procedure TShader.SetAttrib(uniform: Cardinal; value0, value1, value2: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glVertexAttrib3f(uniform,value0,value1,value2);
end;

procedure TShader.SetAttrib(uniform: Cardinal; value0, value1, value2, value3: Single);
begin
  if not GL_ARB_shading_language_100 then exit;
  glVertexAttrib4f(uniform,value0,value1,value2,value3);
end;



procedure TShader.BindUniform(uniform:Cardinal; Value: PGLFLoat; size:Byte);
begin
  if not GL_ARB_shading_language_100 then exit;
      SetUniformV(uniform,value,size);
end;


procedure TShader.BindUniform(const name:string; Value: PGLFLoat; size:Byte);
var uniform:cardinal;
begin
  if not GL_ARB_shading_language_100 then exit;
  if (ShaderProgramm = 0) then exit;

      glUseProgramObjectARB(ShaderProgramm);
      uniform := glGetUniformLocationARB(ShaderProgramm, pchar(name));
      SetUniformV(uniform,value,size);
end;

procedure TShader.BindAttrib(uniform:Cardinal; Value: PGLFLoat; size:Byte);
begin
  if not GL_ARB_shading_language_100 then exit;
      SetAttribV(uniform,value,size);
end;

procedure TShader.BindAttrib(const name:string; Value: PGLFLoat; size:Byte);
var uniform:cardinal;
begin
  if not GL_ARB_shading_language_100 then exit;
  if (ShaderProgramm = 0) then exit;

      glUseProgramObjectARB(ShaderProgramm);
      uniform := glGetUniformLocationARB(ShaderProgramm, pchar(name));
      SetAttribV(uniform,value,size);
end;

Procedure TShader.SetUniformV(uniform:Cardinal; value:PGLFloat; Size:Byte);
begin
      if      (size = 1) then glUniform1fvARB(uniform, 1, value)
      else if (size = 2) then glUniform2fvARB(uniform, 1, value)
      else if (size = 3) then glUniform3fvARB(uniform, 1, value)
      else if (size = 4) then glUniform4fvARB(uniform, 1, value)
      else if (size = 9) then glUniformMatrix3fvARB(uniform, 1, false, value)
      else if (size = 16) then glUniformMatrix4fvARB(uniform, 1, false, value);
end;

Procedure TShader.SetAttribV(uniform:Cardinal; value:PGLFloat; Size:Byte);
begin
      if      (size = 1) then glVertexAttrib1fv(uniform, value)
      else if (size = 2) then glVertexAttrib2fv(uniform, value)
      else if (size = 3) then glVertexAttrib3fv(uniform, value)
      else if (size = 4) then glVertexAttrib4fv(uniform, value)
      else if (size = 9) then glUniformMatrix3fvARB(uniform, 1, false, value)
      else if (size = 16) then glUniformMatrix4fvARB(uniform, 1, false, value);
end;

constructor TShader.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

///////////////////////////////// NORMALIZE PLANE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This normalizes a plane (A side) from a given frustum.
/////
///////////////////////////////// NORMALIZE PLANE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
const
	RIGHT 	= 0;
	LEFT  	= 1;
	BOTTOM	= 2;
	TOP   	= 3;
	BACK  	= 4;
	FRONT 	= 5;
	A	= 0;
	B	= 1;
	C	= 2;
	D	= 3;


Procedure NormalizePlane(var frustum : tfrustumplane; side : integer);
var
	magnitude	: single;
begin
	// Here we calculate the magnitude of the normal to the plane (point A B C)
	// Remember that (A, B, C) is that same thing as the normal's (X, Y, Z).
	// To calculate magnitude you use the equation:  magnitude = sqrt( x^2 + y^2 + z^2)
	magnitude := sqrt( frustum[side][A] * frustum[side][A] +
							   frustum[side][B] * frustum[side][B] +
							   frustum[side][C] * frustum[side][C] );

	// Then we divide the plane's values by it's magnitude.
	// This makes it easier to work with.
	frustum[side][A] := frustum[side][A] / magnitude;
	frustum[side][B] := frustum[side][B] / magnitude;
	frustum[side][C] := frustum[side][C] / magnitude;
	frustum[side][D] := frustum[side][D] / magnitude;
end;

///////////////////////////////// CALCULATE FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This extracts our frustum from the projection and modelview matrix.
/////
///////////////////////////////// CALCULATE FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

Procedure TFrustum.CalculateFrustum;
var
	clip	: array [0..15] of single;	// This will hold the clipping planes
begin
  DrawOBJS:=0;
	// glGetFloatv() is used to extract information about our OpenGL world.
	// Below, we pass in GL_PROJECTION_MATRIX to abstract our projection matrix.
	// It then stores the matrix into an array of [16].
	glGetFloatv( GL_PROJECTION_MATRIX, @proj );

	// By passing in GL_MODELVIEW_MATRIX, we can abstract our model view matrix.
	// This also stores it in an array of [16].
	glGetFloatv( GL_MODELVIEW_MATRIX, @modl );
//  glGetDoubleV(GL_MODELVIEW_MATRIX, @glModl);

	// Now that we have our modelview and projection matrix, if we combine these 2 matrices,
	// it will give us our clipping planes.  To combine 2 matrices, we multiply them.

	clip[ 0] := modl[ 0] * proj[ 0] + modl[ 1] * proj[ 4] + modl[ 2] * proj[ 8] + modl[ 3] * proj[12];
	clip[ 1] := modl[ 0] * proj[ 1] + modl[ 1] * proj[ 5] + modl[ 2] * proj[ 9] + modl[ 3] * proj[13];
	clip[ 2] := modl[ 0] * proj[ 2] + modl[ 1] * proj[ 6] + modl[ 2] * proj[10] + modl[ 3] * proj[14];
	clip[ 3] := modl[ 0] * proj[ 3] + modl[ 1] * proj[ 7] + modl[ 2] * proj[11] + modl[ 3] * proj[15];

	clip[ 4] := modl[ 4] * proj[ 0] + modl[ 5] * proj[ 4] + modl[ 6] * proj[ 8] + modl[ 7] * proj[12];
	clip[ 5] := modl[ 4] * proj[ 1] + modl[ 5] * proj[ 5] + modl[ 6] * proj[ 9] + modl[ 7] * proj[13];
	clip[ 6] := modl[ 4] * proj[ 2] + modl[ 5] * proj[ 6] + modl[ 6] * proj[10] + modl[ 7] * proj[14];
	clip[ 7] := modl[ 4] * proj[ 3] + modl[ 5] * proj[ 7] + modl[ 6] * proj[11] + modl[ 7] * proj[15];

	clip[ 8] := modl[ 8] * proj[ 0] + modl[ 9] * proj[ 4] + modl[10] * proj[ 8] + modl[11] * proj[12];
	clip[ 9] := modl[ 8] * proj[ 1] + modl[ 9] * proj[ 5] + modl[10] * proj[ 9] + modl[11] * proj[13];
	clip[10] := modl[ 8] * proj[ 2] + modl[ 9] * proj[ 6] + modl[10] * proj[10] + modl[11] * proj[14];
	clip[11] := modl[ 8] * proj[ 3] + modl[ 9] * proj[ 7] + modl[10] * proj[11] + modl[11] * proj[15];

	clip[12] := modl[12] * proj[ 0] + modl[13] * proj[ 4] + modl[14] * proj[ 8] + modl[15] * proj[12];
	clip[13] := modl[12] * proj[ 1] + modl[13] * proj[ 5] + modl[14] * proj[ 9] + modl[15] * proj[13];
	clip[14] := modl[12] * proj[ 2] + modl[13] * proj[ 6] + modl[14] * proj[10] + modl[15] * proj[14];
	clip[15] := modl[12] * proj[ 3] + modl[13] * proj[ 7] + modl[14] * proj[11] + modl[15] * proj[15];

	// Now we actually want to get the sides of the frustum.  To do this we take
	// the clipping planes we received above and extract the sides from them.

	// This will extract the RIGHT side of the frustum
	Frustum[RIGHT][A] := clip[ 3] - clip[ 0];
	Frustum[RIGHT][B] := clip[ 7] - clip[ 4];
	Frustum[RIGHT][C] := clip[11] - clip[ 8];
	Frustum[RIGHT][D] := clip[15] - clip[12];

	// Now that we have a normal (A,B,C) and a distance (D) to the plane,
	// we want to normalize that normal and distance.

	// Normalize the RIGHT side
	NormalizePlane(Frustum, RIGHT);

	// This will extract the LEFT side of the frustum
	Frustum[LEFT][A] := clip[ 3] + clip[ 0];
	Frustum[LEFT][B] := clip[ 7] + clip[ 4];
	Frustum[LEFT][C] := clip[11] + clip[ 8];
	Frustum[LEFT][D] := clip[15] + clip[12];

	// Normalize the LEFT side
	NormalizePlane(Frustum, LEFT);

	// This will extract the BOTTOM side of the frustum
	Frustum[BOTTOM][A] := clip[ 3] + clip[ 1];
	Frustum[BOTTOM][B] := clip[ 7] + clip[ 5];
	Frustum[BOTTOM][C] := clip[11] + clip[ 9];
	Frustum[BOTTOM][D] := clip[15] + clip[13]+15;

	// Normalize the BOTTOM side
	NormalizePlane(Frustum, BOTTOM);

	// This will extract the TOP side of the frustum
	Frustum[TOP][A] := clip[ 3] - clip[ 1];
	Frustum[TOP][B] := clip[ 7] - clip[ 5];
	Frustum[TOP][C] := clip[11] - clip[ 9];
	Frustum[TOP][D] := clip[15] - clip[13];

	// Normalize the TOP side
	NormalizePlane(Frustum, TOP);

	// This will extract the BACK side of the frustum
	Frustum[BACK][A] := clip[ 3] - clip[ 2];
	Frustum[BACK][B] := clip[ 7] - clip[ 6];
	Frustum[BACK][C] := clip[11] - clip[10];
	Frustum[BACK][D] := clip[15] - clip[14];

	// Normalize the BACK side
	NormalizePlane(Frustum, BACK);

	// This will extract the FRONT side of the frustum
	Frustum[FRONT][A] := clip[ 3] + clip[ 2];
	Frustum[FRONT][B] := clip[ 7] + clip[ 6];
	Frustum[FRONT][C] := clip[11] + clip[10];
	Frustum[FRONT][D] := clip[15] + clip[14];

	// Normalize the FRONT side
	NormalizePlane(Frustum, FRONT);
end;

// The code below will allow us to make checks within the frustum.  For example,
// if we want to see if a point, a sphere, or a cube lies inside of the frustum.
// Because all of our planes point INWARDS (The normals are all pointing inside the frustum)
// we then can assume that if a point is in FRONT of all of the planes, it's inside.

///////////////////////////////// POINT IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This determines if a point is inside of the frustum
/////
///////////////////////////////// POINT IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

function TFrustum.PointInFrustum(const V:PVertex3f ) : BOOLEAN;
var
	i	: integer;
begin
	// Go through all the sides of the frustum
	for i := 0 to 5 do
	begin
		// Calculate the plane equation and check if the point is behind a side of the frustum
		if(Frustum[i][A] * v.x + Frustum[i][B] * v.y + Frustum[i][C] * v.z + Frustum[i][D] <= 0) then
		begin
			// The point was behind a side, so it ISN'T in the frustum
			result := false; exit;
		end;
	end;

	// The point was inside of the frustum (In front of ALL the sides of the frustum)
	result := true;
  inc(DrawOBJS);
end;


///////////////////////////////// SPHERE IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This determines if a sphere is inside of our frustum by it's center and radius.
/////
///////////////////////////////// SPHERE IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

function TFrustum.SphereInFrustum(const V:PVertex3f; const radius : single) : boolean;
var
	i	: integer;
begin
	// Go through all the sides of the frustum
	for i := 0 to 5 do
	begin
		// If the center of the sphere is farther away from the plane than the radius
		if( Frustum[i][A] * v.x + Frustum[i][B] * v.y + Frustum[i][C] * v.z + Frustum[i][D] <= -radius ) then
		begin
			// The distance was greater than the radius so the sphere is outside of the frustum
			result := false; exit;
		end;
	end;

	// The sphere was inside of the frustum!
	result := true;
  inc(DrawOBJS);
end;


///////////////////////////////// CUBE IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This determines if a cube is in or around our frustum by it's center and 1/2 it's length
/////
///////////////////////////////// CUBE IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

function TFrustum.CubeInFrustum(const V:PVertex3f; size : single) : boolean;
var
	i	: integer;
begin
	// Basically, what is going on is, that we are given the center of the cube,
	// and half the length.  Think of it like a radius.  Then we checking each point
	// in the cube and seeing if it is inside the frustum.  If a point is found in front
	// of a side, then we skip to the next side.  If we get to a plane that does NOT have
	// a point in front of it, then it will return false.

	// *Note* - This will sometimes say that a cube is inside the frustum when it isn't.
	// This happens when all the corners of the bounding box are not behind any one plane.
	// This is rare and shouldn't effect the overall rendering speed.

	for i := 0 to 5 do
	begin
		if(Frustum[i][A] * (v.x - size) + Frustum[i][B] * (v.y - size) + Frustum[i][C] * (v.z - size) + Frustum[i][D] > 0) then
		   continue;
		if(Frustum[i][A] * (v.x + size) + Frustum[i][B] * (v.y - size) + Frustum[i][C] * (v.z - size) + Frustum[i][D] > 0) then
		   continue;
		if(Frustum[i][A] * (v.x - size) + Frustum[i][B] * (v.y + size) + Frustum[i][C] * (v.z - size) + Frustum[i][D] > 0) then
		   continue;
		if(Frustum[i][A] * (v.x + size) + Frustum[i][B] * (v.y + size) + Frustum[i][C] * (v.z - size) + Frustum[i][D] > 0) then
		   continue;
		if(Frustum[i][A] * (v.x - size) + Frustum[i][B] * (v.y - size) + Frustum[i][C] * (v.z + size) + Frustum[i][D] > 0) then
		   continue;
		if(Frustum[i][A] * (v.x + size) + Frustum[i][B] * (v.y - size) + Frustum[i][C] * (v.z + size) + Frustum[i][D] > 0) then
		   continue;
		if(Frustum[i][A] * (v.x - size) + Frustum[i][B] * (v.y + size) + Frustum[i][C] * (v.z + size) + Frustum[i][D] > 0) then
		   continue;
		if(Frustum[i][A] * (v.x + size) + Frustum[i][B] * (v.y + size) + Frustum[i][C] * (v.z + size) + Frustum[i][D] > 0) then
		   continue;

		// If we get here, it isn't in the frustum
		result := false; exit;
	end;

	result := true;
  inc(DrawOBJS);
end;


/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

///////////////////////////////// BOX IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This determines if a BOX is in or around our frustum by it's min and max points
/////
///////////////////////////////// BOX IN FRUSTUM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

function TFrustum.BoxInFrustum(const Min,Max:PVertex3f) : boolean;
var
	i	: integer;
begin
	// Go through all of the corners of the box and check then again each plane
	// in the frustum.  If all of them are behind one of the planes, then it most
	// like is not in the frustum.
	for i := 0 to 5 do
	begin
		if(Frustum[i][A] * Min.x + Frustum[i][B] * Min.y  + Frustum[i][C] * Min.z  + Frustum[i][D] > 0)  then continue;
		if(Frustum[i][A] * Max.x + Frustum[i][B] * Min.y  + Frustum[i][C] * Min.z  + Frustum[i][D] > 0)  then continue;
		if(Frustum[i][A] * Min.x + Frustum[i][B] * Max.y  + Frustum[i][C] * Min.z  + Frustum[i][D] > 0)  then continue;
		if(Frustum[i][A] * Max.x + Frustum[i][B] * Max.y  + Frustum[i][C] * Min.z  + Frustum[i][D] > 0)  then continue;
		if(Frustum[i][A] * Min.x + Frustum[i][B] * Min.y  + Frustum[i][C] * Max.z  + Frustum[i][D] > 0)  then continue;
		if(Frustum[i][A] * Max.x + Frustum[i][B] * Min.y  + Frustum[i][C] * Max.z  + Frustum[i][D] > 0)  then continue;
		if(Frustum[i][A] * Min.x + Frustum[i][B] * Max.y  + Frustum[i][C] * Max.z  + Frustum[i][D] > 0)  then continue;
		if(Frustum[i][A] * Max.x + Frustum[i][B] * Max.y  + Frustum[i][C] * Max.z  + Frustum[i][D] > 0)  then continue;

		// If we get here, it isn't in the frustum
		result := false; exit;
	end;

	// Return a true for the box being inside of the frustum
	result := true;
  inc(DrawOBJS);
end;

constructor TFrustum.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

function Max(Val1, Val2: Integer): Integer;
begin
  if Val1>=Val2 then Result := Val1 else Result := Val2;
end;

constructor TCustomGLTimer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FActiveOnly := True;
  FEnabled    := True;
  Interval    := 1000;
  FOldTime    := TimeGetTime;
  FOldTime2   := FOldTime;
  Application.HookMainWindow(AppProc);
end;

destructor TCustomGLTimer.Destroy;
begin
  Finalize;
  Application.UnHookMainWindow(AppProc);
  inherited Destroy;
end;

procedure TCustomGLTimer.AppIdle(Sender: TObject; var Done: Boolean);
var
  t: Cardinal;
  LagCount, i: Integer;
begin
  Done := False;

  t := TimeGetTime;
     FFrameTime := t-FOldTime;
  if FFrameTime >= FInterval then
  begin
      FOldTime  := t;

       LagCount := FFrameTime div FInterval2;
    if LagCount <1 then
       LagCount := 1;

    Inc(FNowFrameRate);

    i := Max(t-FOldTime2, 1);
    if i>=1000 then
    begin
      FFrameRate    := Round(FNowFrameRate*1000/i);
      FNowFrameRate := 0;
      FOldTime2     := t;
    end;

    DoTimer(LagCount);
  end;
end;

function TCustomGLTimer.AppProc(var Message: TMessage): Boolean;
begin
  Result := False;
  case Message.Msg of
    CM_ACTIVATE:
        begin
          DoActivate;
          if FInitialized and FActiveOnly then Resume;
        end;
    CM_DEACTIVATE:
        begin
          DoDeactivate;
          if FInitialized and FActiveOnly then Suspend;
        end;
  end;
end;

procedure TCustomGLTimer.DoActivate;
begin
  if Assigned(FOnActivate) then
     FOnActivate(Self);
end;

procedure TCustomGLTimer.DoDeactivate;
begin
  if Assigned(FOnDeactivate) then
     FOnDeactivate(Self);
end;

procedure TCustomGLTimer.DoTimer(LagCount: Integer);
begin
  if Assigned(FOnTimer) then
     FOnTimer(Self, LagCount);
end;

procedure TCustomGLTimer.Finalize;
begin
  if FInitialized then
  begin
    Suspend;
    FInitialized := False;
  end;
end;

procedure TCustomGLTimer.Initialize;
begin
  Finalize;

  if ActiveOnly then
  begin
    if Application.Active then
      Resume;
  end else
    Resume;
  FInitialized := True;
end;

procedure TCustomGLTimer.Loaded;
begin
  inherited Loaded;
  if (not (csDesigning in ComponentState)) and FEnabled then
    Initialize;
end;

procedure TCustomGLTimer.Resume;
begin
  FOldTime := TimeGetTime;
  FOldTime2 := TimeGetTime;
  Application.OnIdle := AppIdle;
end;

procedure TCustomGLTimer.SetActiveOnly(Value: Boolean);
begin
  if FActiveOnly <> Value then
  begin
     FActiveOnly := Value;

    if Application.Active and FActiveOnly then
      if FInitialized and FActiveOnly then Suspend;
  end;
end;

procedure TCustomGLTimer.SetEnabled(Value: Boolean);
begin
  if FEnabled<>Value then
  begin
    FEnabled := Value;
    if ComponentState*[csReading, csLoading]=[] then
      if FEnabled then Initialize else Finalize;
  end;
end;

procedure TCustomGLTimer.SetInterval(Value: Cardinal);
begin
  if FInterval<>Value then
  begin
    FInterval := Max(Value, 0);
    FInterval2 := Max(Value, 1);
  end;
end;

procedure TCustomGLTimer.Suspend;
begin
  Application.OnIdle := nil;
end;

constructor TXMMusic.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FXM:=nil;
end;
destructor TXMMusic.Destroy;
begin
  FreeMem(FXM);
  inherited Destroy;
end;
function TXMMusic.LoadFromFile(const FileName: String) : Boolean;
var f : file of byte;
begin
  Try
   AssignFile(F, FileName);
   Reset(F);
   FXMSize := FileSize(F);
   GetMem(FXM,FXMSize);
   BlockRead(F, FXM[0], FXMSize);
   CloseFile(F);
    result := true;
   except
    FreeMem(FXM);
    result := false;
    CloseFile(f);
   end;
end;
function TXMMusic.LoadFromMem( const XM:Pointer; const Size: Cardinal) : Boolean;
begin
 result:=true;
 if FXM <> nil then
    FreeMem(FXM);
    FXM := XM;
    FXmSize := Size;
end;
function TXMMusic.Play:Pointer;
begin
result := Ufmod_PlaySong(FXM, FXMSize, XM_MEMORY);
FTitle := Ufmod_getTitle;
end;
procedure TXMMusic.Jump2Pattern(pat:Cardinal);
begin
 UFmod_Jump2Pattern(pat);
end;
procedure TXMMusic.Rewind;
begin
 Ufmod_Rewind;
end;
procedure TXMMusic.Pause;
begin
 ufmod_pause;
end;
procedure TXMMusic.Resume;
begin
 ufmod_resume;
end;
procedure TXMMusic.Stop;
begin
 ufmod_stopsong;
end;
function  TXMMusic.GetStats : Cardinal;
begin
 result := ufmod_getstats;
end;
function  TXMMusic.GetRowOrder : Cardinal;
begin
 result := ufmod_getroworder;
end;
function  TXMMusic.GetTime  : Cardinal;
begin
 result := gettime;
end;
procedure TXMMusic.SetVolume(vol:LongWord);
begin
 ufmod_setvolume(vol);
end;

constructor TGLSound.Create(AOwner: TComponent);
begin
  inherited Create(Aowner);
  DxSound := TDXSound.Create;
end;
destructor TGLSound.Destroy;
begin
  TDxSound(DxSound).DeInit;
  inherited Destroy;
end;
function  TGLSound.Init(WND:HWND): boolean;
begin
  result := TDxSound(DxSound).Init(WND);
end;
function  TGLSound.Load             (const FileName: string): integer;
begin
  result := TDxSound(DxSound).Load(fileName);
end;
function  TGLSound.FreeSample       (Sample_ID: integer): boolean;
begin
  result := TDxSound(DxSound).Free(Sample_ID);
end;
procedure TGLSound.BeginUpdate;
begin
  TDxSound(DxSound).BeginUpdate;
end;
procedure TGLSound.EndUpdate;
begin
  TDxSound(DxSound).EndUpdate;
end;
function  TGLSound.Play             (Sample_ID: integer; Loop: boolean; X,Y,Z:Single ): integer;
begin
  result := TDxSound(DxSound).Play(Sample_ID, loop,vec3f(x,y,z));
end;

function  TGLSound.SetMuteDist      (Channel_ID: integer; Min,MAx:Single ): boolean;
begin
  result := TDxSound(DxSound).SetMuteDist(Channel_id,min,max);
end;

function  TGLSound.Stop             (var Channel_ID: integer): boolean;
begin
  result := TDxSound(DxSound).Stop(Channel_Id);
end;
procedure TGLSound.StopAll          (Sound_ID: integer);
begin
  TDxSound(DxSound).StopAll(Sound_ID);
end;
function  TGLSound.SetVolume        (Channel_ID: integer; Volume: integer): boolean;
begin
  result := TDxSound(DxSound).SetVolume(Channel_ID,Volume);
end;
function  TGLSound.SetPos           (Channel_ID: integer; X,Y,Z:Single): boolean;
begin
  result := TDxSound(DxSound).SetPos(Channel_ID, vec3f(x,y,z));
end;

procedure TGLSound.SetPos2GlobalPos (Channel_ID: integer; Accept:boolean);
begin
TDxSound(DxSound).SetPos2GlobalPos(Channel_ID, Accept);
end;

function  TGLSound.SetFreq          (Channel_ID: integer; Freq: DWORD): boolean;
begin
  result := TDxSound(DxSound).SetFreq(Channel_ID,Freq);
end;
procedure TGLSound.SetVelocity      (Channel_ID: integer; X,Y,Z:Single);
begin
  TDxSound(DxSound).SetVelocity(Channel_ID,vec3f(x,y,z));
end;
procedure TGLSound.SetOrientation   (frontx,fronty,frontz, topx,topy,topz:Single);
begin
  TDxSound(DxSound).SetOrientation(vec3f(frontx,fronty,frontz),vec3f(topx,topy,topz));
end;
procedure TGLSound.SetDopplerFactor (factor: single);
begin
  TDxSound(DxSound).SetDopplerFactor(factor);
end;
procedure TGLSound.SetRolloffFactor (factor: single);
begin
  TDxSound(DxSound).SetRolloffFactor(factor);
end;
procedure TGLSound.SetDistanceFactor(Dst   : single);
begin
  TDxSound(DxSound).SetDistanceFactor(dst);
end;
procedure TGLSound.SetGlobalPos     (X,Y,Z:Single);
begin
  TDxSound(DxSound).SetGlobalPos(vec3f(x,y,z));
end;
procedure TGLSound.SetGlobalVelocity(X,Y,Z:Single);
begin
  TDxSound(DxSound).SetGlobalVelocity(vec3f(x,y,z));
end;
procedure TGLSound.Update;
begin
  TDxSound(DxSound).Update;
end;


initialization
{$IFDEF CPU386}
 // Added by bero
 Set8087CW($133F);
{$ENDIF}
  DSoundInit;


finalization
  DSoundFree;

end.
