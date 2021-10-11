{
unit DirectSound9;

interface

uses
  Windows,
  MMSystem;
 }
const
  dsounddllname = 'DSound.dll';

var
  DSoundDLL : HMODULE = 0;

const
  DIRECTSOUND_VERSION = $0900;

type
  TDXVector = Record
   X,y,z:Single;
   end;
  TD3DValue = Single;

  PDS3DBuffer = ^TDS3DBuffer;
  TDS3DBuffer = packed record
    Size              : LongWord;
    Position          : TDXVector;
    Velocity          : TDXVector;
    InsideConeAngle   : LongWord;
    OutsideConeAngle  : LongWord;
    ConeOrientation   : TDXVector;
    ConeOutsideVolume : LongInt;
    MinDistance       : TD3DValue;
    MaxDistance       : TD3DValue;
    Mode              : LongWord;
  end;
  TCDS3DBuffer = ^TDS3DBuffer;

  PDS3DListener = ^TDS3DListener;
  TDS3DListener = packed record
    Size           : LongWord;
    Position       : TDXVector;
    Velocity       : TDXVector;
    OrientFront    : TDXVector;
    OrientTop      : TDXVector;
    DistanceFactor : TD3DValue;
    RolloffFactor  : TD3DValue;
    DopplerFactor  : TD3DValue;
  end;
  PCDS3DListener = ^TDS3DListener;

  PDSBCaps = ^TDSBCaps;
  TDSBCaps = packed record
    Size               : LongWord;
    Flags              : LongWord;
    BufferBytes        : LongWord;
    UnlockTransferRate : LongWord;
    PlayCpuOverhead    : LongWord;
  end;
  PCDSBCaps = ^TDSBCaps;

  PDSBPositionNotify = ^TDSBPositionNotify;
  TDSBPositionNotify = packed record
    Offset      : LongWord;
    EventNotify : THandle;
  end;
  PCDSBPositionNotify = ^TDSBPositionNotify;

  PDSBufferDesc = ^TDSBufferDesc;
  TDSBufferDesc = packed record
    Size            : LongWord;
    Flags           : LongWord;
    BufferBytes     : LongWord;
    Reserved        : LongWord;
    WaveFormatEx    : PWaveFormatEx;
    Guid3DAlgorithm : TGUID;
  end;
  PCDSBufferDesc = PDSBufferDesc;

  PDSCaps = ^TDSCaps;
  TDSCaps = packed record
    Size                        : LongWord;
    Flags                       : LongWord;
    MinSecondarySampleRate      : LongWord;
    MaxSecondarySampleRate      : LongWord;
    PrimaryBuffers              : LongWord;
    MaxHwMixingAllBuffers       : LongWord;
    MaxHwMixingStaticBuffers    : LongWord;
    MaxHwMixingStreamingBuffers : LongWord;
    FreeHwMixingAllBuffers      : LongWord;
    FreeHwMixingStaticBuffers   : LongWord;
    FreeHwMixingStreamingBuffers: LongWord;
    MaxHw3DAllBuffers           : LongWord;
    MaxHw3DStaticBuffers        : LongWord;
    MaxHw3DStreamingBuffers     : LongWord;
    FreeHw3DAllBuffers          : LongWord;
    FreeHw3DStaticBuffers       : LongWord;
    FreeHw3DStreamingBuffers    : LongWord;
    TotalHwMemBytes             : LongWord;
    FreeHwMemBytes              : LongWord;
    MaxContigFreeHwMemBytes     : LongWord;
    UnlockTransferRateHwBuffers : LongWord;
    PlayCpuOverheadSwBuffers    : LongWord;
    Reserved1                   : LongWord;
    Reserved2                   : LongWord;
  end;
  PCDSCaps = ^TDSCaps;

  PDSCBCaps = ^TDSCBCaps;
  TDSCBCaps = packed record
    Size        : LongWord;
    Flags       : LongWord;
    BufferBytes : LongWord;
    Reserved    : LongWord;
  end;
  PCDSCBCaps = ^TDSCBCaps;

  PDSCEffectDesc = ^TDSCEffectDesc;
  TDSCEffectDesc = packed record
    Size              : LongWord;
    Flags             : LongWord;
    GuidDSCFXClass    : TGUID;
    GuidDSCFXInstance : TGUID;
    Reserved1         : LongWord;
    Reserved2         : LongWord;
  end;
  TCDSCEffectDesc = PDSCEffectDesc;

  PDSCBufferDesc = ^TDSCBufferDesc;
  TDSCBufferDesc = packed record
    Size         : LongWord;
    Flags        : LongWord;
    BufferBytes  : LongWord;
    Reserved     : LongWord;
    WaveFormatEx : PWaveFormatEx;
    FXCount      : LongWord;
    DSCFXDesc    : PDSCEffectDesc;
  end;
  PCDSCBufferDesc = ^TDSCBufferDesc;

  PDSCCaps = ^TDSCCaps;
  TDSCCaps = packed record
    Size     : LongWord;
    Flags    : LongWord;
    Formats  : LongWord;
    Channels : LongWord;
  end;
  PCDSCCaps = ^TDSCCaps;

  PDSCFXAec = ^TDSCFXAec;
  TDSCFXAec = packed record
    Enable    : BOOL;
    NoiseFill : BOOL;
    Mode      : LongWord;
  end;
  PCDSCFXAec = ^TDSCFXAec;

  PDSCFXNoiseSuppress = ^TDSCFXNoiseSuppress;
  TDSCFXNoiseSuppress = packed record
    Enable : BOOL;
  end;
  PCDSCFXNoiseSuppress = ^TDSCFXNoiseSuppress;

  PDSEffectDesc = ^TDSEffectDesc;
  TDSEffectDesc = packed record
    Size          : LongWord;
    Flags         : LongWord;
    GuidDSFXClass : TGUID;
    Reserved1     : LongWord;
    Reserved2     : LongWord;
  end;
  PCDSEffectDesc = ^TDSEffectDesc;

  PDSFXI3DL2Reverb = ^TDSFXI3DL2Reverb;
  TDSFXI3DL2Reverb = packed record
    Room              : Longint;    // [-10000, 0]      default: -1000 mB
    RoomHF            : Longint;    // [-10000, 0]      default: 0 mB
    RoomRolloffFactor : Single;     // [0.0, 10.0]      default: 0.0
    DecayTime         : Single;     // [0.1, 20.0]      default: 1.49s
    DecayHFRatio      : Single;     // [0.1, 2.0]       default: 0.83
    Reflections       : Longint;    // [-10000, 1000]   default: -2602 mB
    ReflectionsDelay  : Single;     // [0.0, 0.3]       default: 0.007 s
    Reverb            : Longint;    // [-10000, 2000]   default: 200 mB
    ReverbDelay       : Single;     // [0.0, 0.1]       default: 0.011 s
    Diffusion         : Single;     // [0.0, 100.0]     default: 100.0 %
    Density           : Single;     // [0.0, 100.0]     default: 100.0 %
    HFReference       : Single;     // [20.0, 20000.0]  default: 5000.0 Hz
  end;
  PCDSFXI3DL2Reverb = ^TDSFXI3DL2Reverb;

  PDSFXChorus = ^TDSFXChorus;
  TDSFXChorus = packed record
    WetDryMix : Single;
    Depth     : Single;
    Feedback  : Single;
    Frequency : Single;
    Waveform  : Longint;          // LFO shape; DSFXCHORUS_WAVE_xxx
    Delay     : Single;
    Phase     : Longint;
  end;
  PCDSFXChorus = ^TDSFXChorus;

  PDSFXCompressor = ^TDSFXCompressor;
  TDSFXCompressor = packed record
    Gain      : Single;
    Attack    : Single;
    Release   : Single;
    Threshold : Single;
    Ratio     : Single;
    Predelay  : Single;
  end;
  PCDSFXCompressor = ^TDSFXCompressor;

  PDSFXDistortion = ^TDSFXDistortion;
  TDSFXDistortion = packed record
    Gain                  : Single;
    Edge                  : Single;
    PostEQCenterFrequency : Single;
    PostEQBandwidth       : Single;
    PreLowpassCutoff      : Single;
  end;
  PCDSFXDistortion = ^TDSFXDistortion;

  PDSFXEcho = ^TDSFXEcho;
  TDSFXEcho = packed record
    WetDryMix  : Single;
    Feedback   : Single;
    LeftDelay  : Single;
    RightDelay : Single;
    PanDelay   : Longint;
  end;
  PCDSFXEcho = ^TDSFXEcho;

  PDSFXFlanger = ^TDSFXFlanger;
  TDSFXFlanger = packed record
    WetDryMix : Single;
    Depth     : Single;
    Feedback  : Single;
    Frequency : Single;
    Waveform  : Longint;
    Delay     : Single;
    Phase     : Longint;
  end;
  PCDSFXFlanger = ^TDSFXFlanger;

  PDSFXGargle = ^TDSFXGargle;
  TDSFXGargle = packed record
    RateHz    : LongWord;            // Rate of modulation in hz
    WaveShape : LongWord;            // DSFXGARGLE_WAVE_xxx
  end;
  PCDSFXGargle = ^TDSFXGargle;

  PDSFXParamEq = ^TDSFXParamEq;
  TDSFXParamEq = packed record
    Center    : Single;
    Bandwidth : Single;
    Gain      : Single;
  end;
  PCDSFXParamEq = ^TDSFXParamEq;

  PDSFXWavesReverb = ^TDSFXWavesReverb;
  TDSFXWavesReverb = packed record
    InGain          : Single;       // [-96.0,0.0]            default: 0.0 dB
    ReverbMix       : Single;       // [-96.0,0.0]            default: 0.0 db
    ReverbTime      : Single;       // [0.001,3000.0]         default: 1000.0 ms
    HighFreqRTRatio : Single;       // [0.001,0.999]          default: 0.001
  end;
  PCDSFXWavesReverb = ^TDSFXWavesReverb;

  TDSFXI3DL2EnvironmentPreset = (
    DSFX_I3DL2_ENVIRONMENT_PRESET_DEFAULT,
    DSFX_I3DL2_ENVIRONMENT_PRESET_GENERIC,
    DSFX_I3DL2_ENVIRONMENT_PRESET_PADDEDCELL,
    DSFX_I3DL2_ENVIRONMENT_PRESET_ROOM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_BATHROOM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_LIVINGROOM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_STONEROOM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_AUDITORIUM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_CONCERTHALL,
    DSFX_I3DL2_ENVIRONMENT_PRESET_CAVE,
    DSFX_I3DL2_ENVIRONMENT_PRESET_ARENA,
    DSFX_I3DL2_ENVIRONMENT_PRESET_HANGAR,
    DSFX_I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY,
    DSFX_I3DL2_ENVIRONMENT_PRESET_HALLWAY,
    DSFX_I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR,
    DSFX_I3DL2_ENVIRONMENT_PRESET_ALLEY,
    DSFX_I3DL2_ENVIRONMENT_PRESET_FOREST,
    DSFX_I3DL2_ENVIRONMENT_PRESET_CITY,
    DSFX_I3DL2_ENVIRONMENT_PRESET_MOUNTAINS,
    DSFX_I3DL2_ENVIRONMENT_PRESET_QUARRY,
    DSFX_I3DL2_ENVIRONMENT_PRESET_PLAIN,
    DSFX_I3DL2_ENVIRONMENT_PRESET_PARKINGLOT,
    DSFX_I3DL2_ENVIRONMENT_PRESET_SEWERPIPE,
    DSFX_I3DL2_ENVIRONMENT_PRESET_UNDERWATER,
    DSFX_I3DL2_ENVIRONMENT_PRESET_SMALLROOM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEROOM,
    DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL,
    DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEHALL,
    DSFX_I3DL2_ENVIRONMENT_PRESET_PLATE
  );

  TDSFXI3DL2MaterialPreset = (
    DSFX_I3DL2_MATERIAL_PRESET_SINGLEWINDOW,
    DSFX_I3DL2_MATERIAL_PRESET_DOUBLEWINDOW,
    DSFX_I3DL2_MATERIAL_PRESET_THINDOOR,
    DSFX_I3DL2_MATERIAL_PRESET_THICKDOOR,
    DSFX_I3DL2_MATERIAL_PRESET_WOODWALL,
    DSFX_I3DL2_MATERIAL_PRESET_BRICKWALL,
    DSFX_I3DL2_MATERIAL_PRESET_STONEWALL,
    DSFX_I3DL2_MATERIAL_PRESET_CURTAIN
  );

(*)
 * DirectSound API
(*)
  TDSEnumCallbackW = function (Guid : PGUID; Description : PWideChar; Module : PWideChar; Context : Pointer) : BOOL; stdcall;
  TDSEnumCallbackA = function (Guid : PGUID; Description : PAnsiChar; Module : PAnsiChar; Context : Pointer) : BOOL; stdcall;
  TDSEnumCallback = TDSEnumCallbackA;

const
  CLSID_DirectSound            : TGUID = '{47D4D946-62E8-11CF-93BC-444553540000}';
  CLSID_DirectSound8           : TGUID = '{3901CC3F-84B5-4FA4-BA35-AA8172B8A09B}';
  CLSID_DirectSoundCapture     : TGUID = '{B0210780-89CD-11D0-AF08-00A0C925CD16}';
  CLSID_DirectSoundCapture8    : TGUID = '{E4BCAC13-7F99-4908-9A8E-74E3BF24B6E1}';
  CLSID_DirectSoundFullDuplex  : TGUID = '{FEA4300C-7959-4147-B26A-2377B9E7A91D}';
  DSDEVID_DefaultPlayback      : TGUID = '{DEF00000-9C6D-47ED-AAF1-4DDA8F2B5C03}';
  DSDEVID_DefaultCapture       : TGUID = '{DEF00001-9C6D-47ED-AAF1-4DDA8F2B5C03}';
  DSDEVID_DefaultVoicePlayback : TGUID = '{DEF00002-9C6D-47ED-AAF1-4DDA8F2B5C03}';
  DSDEVID_DefaultVoiceCapture  : TGUID = '{DEF00003-9C6D-47ED-AAF1-4DDA8F2B5C03}';

type
  IDirectSound = interface;
  IDirectSoundBuffer = interface;
  IDirectSound3DListener = interface;
  IDirectSound3DBuffer = interface;
  IDirectSoundCapture = interface;
  IDirectSoundCaptureBuffer = interface;
  IDirectSoundNotify = interface;
  IKsPropertySet = interface;

  IDirectSound8 = interface;
  IDirectSoundBuffer8 = interface;
  IDirectSoundCaptureBuffer8 = interface;
  IDirectSoundCaptureFXAec8 = interface;
  IDirectSoundCaptureFXNoiseSuppress8 = interface;
  IDirectSoundFullDuplex8 = interface;
  IDirectSoundFXGargle8 = interface;
  IDirectSoundFXChorus8 = interface;
  IDirectSoundFXFlanger8 = interface;
  IDirectSoundFXEcho8 = interface;
  IDirectSoundFXDistortion8 = interface;
  IDirectSoundFXCompressor8 = interface;
  IDirectSoundFXParamEq8 = interface;
  IDirectSoundFXWavesReverb8 = interface;
  IDirectSoundFXI3DL2Reverb8 = interface;


(*)
 * IDirectSound
(*)

  PIDirectSound = ^IDirectSound;
  IDirectSound = interface (IUnknown)
    ['{279AFA83-4981-11CE-A521-0020AF0BE560}']
    (*** IDirectSound methods ***)
    function CreateSoundBuffer(const DSBufferDesc : TDSBufferDesc; out IDirectSoundBuffer : IDirectSoundBuffer; UnkOuter : IUnknown) : HResult; stdcall;
    function GetCaps(out lpDSCaps : TDSCaps) : HResult; stdcall;
    function DuplicateSoundBuffer(DSBOriginal : IDirectSoundBuffer; out DSBDuplicate : IDirectSoundBuffer) : HResult; stdcall;
    function SetCooperativeLevel(hwnd : HWND; Level : LongWord) : HResult; stdcall;
    function Compact : HResult; stdcall;
    function GetSpeakerConfig(out SpeakerConfig : LongWord) : HResult; stdcall;
    function SetSpeakerConfig(SpeakerConfig : LongWord) : HResult; stdcall;
    function Initialize(Guid : PGUID) : HResult; stdcall;
  end;

(*)
 * IDirectSound8
(*)

  IDirectSound8 = interface (IDirectSound)
    ['{C50A7E93-F395-4834-9EF6-7FA99DE50966}']
    (*** IDirectSound8 methods ***)
    function VerifyCertification(out Certified : LongWord) : HResult; stdcall;
  end;

(*)
 * IDirectSoundBuffer
(*)

  IDirectSoundBuffer = interface (IUnknown)
    ['{279AFA85-4981-11CE-A521-0020AF0BE560}']
    (*** IDirectSoundBuffer methods ***)
    function GetCaps(out DSCaps : TDSBCaps) : HResult; stdcall;
    function GetCurrentPosition(PlayPosition, ReadPosition : PLongWord) : HResult; stdcall;
    function GetFormat(WaveFormatEx : PWaveFormatEx; SizeAllocated : LongWord; SizeWritten : PLongWord) : HResult; stdcall;
    function GetVolume(out Volume : Integer) : HResult; stdcall;
    function GetPan(out Pan : Integer) : HResult; stdcall;
    function GetFrequency(out Frequency : LongWord) : HResult; stdcall;
    function GetStatus(out Status : LongWord) : HResult; stdcall;
    function Initialize(lpDirectSound : IDirectSound; const DSBufferDesc : TDSBufferDesc) : HResult; stdcall;
    function Lock(Offset, Bytes : LongWord; out AudioPtr1 : Pointer; out AudioBytes1 : LongWord; out AudioPtr2 : Pointer; out AudioBytes2 : LongWord; Flags : LongWord) : HResult; stdcall;
    function Play(Reserved1, Reserved2, Flags : LongWord) : HResult; stdcall;
    function SetCurrentPosition(Position : LongWord) : HResult; stdcall;
    function SetFormat(var WaveFormatEx : TWaveFormatEx) : HResult; stdcall;
    function SetVolume(Volume : Integer) : HResult; stdcall;
    function SetPan(Pan : Integer) : HResult; stdcall;
    function SetFrequency(Frequency : LongWord) : HResult; stdcall;
    function Stop : HResult; stdcall;
    function Unlock(AudioPtr1 : Pointer; AudioBytes1 : LongWord; AudioPtr2 : Pointer; AudioBytes2 : LongWord) : HResult; stdcall;
    function Restore : HResult; stdcall;
  end;

(*)
 * IDirectSoundBuffer8
(*)

  IDirectSoundBuffer8 = interface (IDirectSoundBuffer)
    ['{6825A449-7524-4D82-920F-50E36AB3AB1E}']
    (*** IDirectSoundBuffer8 methods ***)
    function SetFX(dwEffectsCount : LongWord; DSFXDesc : PDSEffectDesc; ResultCodes : PLongWord) : HResult; stdcall;
    function AcquireResources(Flags, EffectsCount : LongWord; ResultCodes : PLongWord) : HResult; stdcall;
    function GetObjectInPath(const ObjectGUID : TGUID; Index : LongWord; const InterfaceGUID : TGUID; out OutObject) : HResult; stdcall;
  end;

(*)
 * IDirectSound3DListener
(*)

  IDirectSound3DListener = interface (IUnknown)
    ['{279AFA84-4981-11CE-A521-0020AF0BE560}']
    (*** IDirectSound3DListener methods ***)
    function GetAllParameters(out Listener : TDS3DListener) : HResult; stdcall;
    function GetDistanceFactor(out DistanceFactor : TD3DValue) : HResult; stdcall;
    function GetDopplerFactor(out DopplerFactor : TD3DValue) : HResult; stdcall;
    function GetOrientation(out OrientFront, OrientTop : TDXVector) : HResult; stdcall;
    function GetPosition(out Position : TDXVector) : HResult; stdcall;
    function GetRolloffFactor(out RolloffFactor : TD3DValue) : HResult; stdcall;
    function GetVelocity(out Velocity : TDXVector) : HResult; stdcall;
    function SetAllParameters(const Listener : TDS3DListener; Apply : LongWord) : HResult; stdcall;
    function SetDistanceFactor(DistanceFactor : TD3DValue; Apply: LongWord) : HResult; stdcall;
    function SetDopplerFactor(DopplerFactor : TD3DValue; Apply: LongWord) : HResult; stdcall;
    function SetOrientation(xFront, yFront, zFront, xTop, yTop, zTop : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function SetPosition(x, y, z : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function SetRolloffFactor(RolloffFactor : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function SetVelocity(x, y, z : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function CommitDeferredSettings : HResult; stdcall;
  end;

(*)
 * IDirectSound3DListener8
(*)

  IDirectSound3DListener8 = IDirectSound3DListener;

(*)
 * IDirectSound3DBuffer
(*)

  IDirectSound3DBuffer = interface (IUnknown)
    ['{279AFA86-4981-11CE-A521-0020AF0BE560}']
    (*** IDirectSoundBuffer3D methods ***)
    function GetAllParameters(out DS3DBuffer : TDS3DBuffer) : HResult; stdcall;
    function GetConeAngles(out InsideConeAngle, OutsideConeAngle : LongWord) : HResult; stdcall;
    function GetConeOrientation(out Orientation : TDXVector) : HResult; stdcall;
    function GetConeOutsideVolume(out ConeOutsideVolume : Integer) : HResult; stdcall;
    function GetMaxDistance(out MaxDistance : TD3DValue) : HResult; stdcall;
    function GetMinDistance(out MinDistance : TD3DValue) : HResult; stdcall;
    function GetMode(out Mode : LongWord) : HResult; stdcall;
    function GetPosition(out Position : TDXVector) : HResult; stdcall;
    function GetVelocity(out Velocity : TDXVector) : HResult; stdcall;
    function SetAllParameters(const DS3DBuffer: TDS3DBuffer; Apply : LongWord) : HResult; stdcall;
    function SetConeAngles(InsideConeAngle, OutsideConeAngle, Apply : LongWord) : HResult; stdcall;
    function SetConeOrientation(x, y, z : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function SetConeOutsideVolume(ConeOutsideVolume : LongInt; Apply : LongWord) : HResult; stdcall;
    function SetMaxDistance(MaxDistance : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function SetMinDistance(MinDistance : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function SetMode(Mode : LongWord; Apply : LongWord) : HResult; stdcall;
    function SetPosition(x, y, z : TD3DValue; Apply : LongWord) : HResult; stdcall;
    function SetVelocity(x, y, z : TD3DValue; Apply : LongWord) : HResult; stdcall;
  end;

(*)
 * IDirectSound3DBuffer8
(*)

  IDirectSound3DBuffer8 = IDirectSound3DBuffer;

(*)
 * IDirectSoundCapture
(*)

  IDirectSoundCapture = interface (IUnknown)
    ['{b0210781-89cd-11d0-af08-00a0c925cd16}']
    (*** IDirectSoundCapture methods ***)
    function CreateCaptureBuffer(const DSCBufferDesc : TDSCBufferDesc; out DirectSoundCaptureBuffer : IDirectSoundCaptureBuffer; UnkOuter : IUnknown) : HResult; stdcall;
    function GetCaps(out Caps : TDSCCaps) : HResult; stdcall;
    function Initialize(Guid: PGUID) : HResult; stdcall;
  end;

(*)
 * IDirectSoundCapture8
(*)

  IDirectSoundCapture8 = IDirectSoundCapture;

(*)
 * IDirectSoundCaptureBuffer
(*)

  IDirectSoundCaptureBuffer = interface (IUnknown)
    ['{b0210782-89cd-11d0-af08-00a0c925cd16}']
    (*** IDirectSoundCaptureBuffer methods ***)
    function GetCaps(out Caps : TDSCBCaps) : HResult; stdcall;
    function GetCurrentPosition(CapturePosition, ReadPosition : PLongWord) : HResult; stdcall;
    function GetFormat(WaveFormatEx : PWaveFormatEx; SizeAllocated : LongWord; SizeWritten : PLongWord) : HResult; stdcall;
    function GetStatus(out Status : LongWord) : HResult; stdcall;
    function Initialize(DirectSoundCapture : IDirectSoundCapture; const DSBufferDesc : TDSCBufferDesc) : HResult; stdcall;
    function Lock(ReadCursor, ReadBytes : LongWord; out AudioPtr1 : Pointer; out AudioBytes1 : LongWord; out AudioPtr2 : Pointer; out AudioBytes2 : LongWord; Flags : LongWord) : HResult; stdcall;
    function Start(Flags : LongWord) : HResult; stdcall;
    function Stop : HResult; stdcall;
    function Unlock(lpvAudioPtr1: Pointer; dwAudioBytes1: LongWord; AudioPtr2 : Pointer; AudioBytes2 : LongWord) : HResult; stdcall;
  end;

(*)
 * IDirectSoundCaptureBuffer8
(*)

  IDirectSoundCaptureBuffer8 = interface (IDirectSoundCaptureBuffer)
    ['{00990df4-0dbb-4872-833e-6d303e80aeb6}']
    (*** IDirectSoundCaptureBuffer8 methods ***)
    function GetObjectInPath(const ObjectGuid : TGUID; Index : LongWord; const InterfaceGuid : TGUID; out OutObject) : HResult; stdcall;
    function GetFXStatus(FXCount : LongWord; FXStatus : PLongWord): HResult; stdcall;
  end;

(*)
 * IDirectSoundCaptureFXAec8
(*)

  IDirectSoundCaptureFXAec8 = interface (IUnknown)
    ['{AD74143D-903D-4AB7-8066-28D363036D65}']
    (*** IDirectSoundCaptureFXAec8 methods ***)
    function SetAllParameters(const DSCFXAec : TDSCFXAec) : HResult; stdcall;
    function GetAllParameters(out DSCFXAec : TDSCFXAec) : HResult; stdcall;
    function GetStatus(out Status : LongWord) : HResult; stdcall;
    function Reset : HResult; stdcall;
  end;

(*)
 * IDirectSoundCaptureFXNoiseSuppress8
(*)

  IDirectSoundCaptureFXNoiseSuppress8 = interface (IUnknown)
    ['{ED311E41-FBAE-4175-9625-CD0854F693CA}']
    (*** IDirectSoundCaptureFXNoiseSuppress8 methods ***)
    function SetAllParameters(const DSCFxNoiseSuppress : TDSCFXNoiseSuppress) : HResult; stdcall;
    function GetAllParameters(out DSCFxNoiseSuppress : TDSCFXNoiseSuppress) : HResult; stdcall;
    function Reset : HResult; stdcall;
  end;

(*)
 * IDirectSoundFullDuplex8
(*)

  IDirectSoundFullDuplex8 = interface (IUnknown)
    ['{edcb4c7a-daab-4216-a42e-6c50596ddc1d}']
    (*** IDirectSoundFullDuplex methods ***)
    function Initialize(CaptureGuid, RenderGuid : PGUID; DSCBufferDesc : PCDSCBufferDesc; DSBufferDesc : PCDSBufferDesc; hWnd : hWnd; Level : LongWord; out DirectSoundCaptureBuffer8 : IDirectSoundCaptureBuffer8; out DirectSoundBuffer8 : IDirectSoundBuffer8) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXGargle8
(*)

  IDirectSoundFXGargle8 = interface (IUnknown)
    ['{d616f352-d622-11ce-aac5-0020af0b99a3}']
    function SetAllParameters(const DSFXGargle : TDSFXGargle) : HResult; stdcall;
    function GetAllParameters(out DSFXGargle : TDSFXGargle) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXChorus8
(*)

  IDirectSoundFXChorus8 = interface (IUnknown)
    ['{880842e3-145f-43e6-a934-a71806e50547}']
    function SetAllParameters(const DSFXChorus : TDSFXChorus) : HResult; stdcall;
    function GetAllParameters(out DSFXChorus : TDSFXChorus) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXFlanger8
(*)

  IDirectSoundFXFlanger8 = interface (IUnknown)
    ['{903e9878-2c92-4072-9b2c-ea68f5396783}']
    function SetAllParameters(const DSFXFlanger : TDSFXFlanger) : HResult; stdcall;
    function GetAllParameters(out DSFXFlanger : TDSFXFlanger) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXEcho8
(*)
  IDirectSoundFXEcho8 = interface (IUnknown)
    ['{8bd28edf-50db-4e92-a2bd-445488d1ed42}']
    function SetAllParameters(const DSFXEcho : TDSFXEcho) : HResult; stdcall;
    function GetAllParameters(out DSFXEcho : TDSFXEcho) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXDistortion8
(*)
  IDirectSoundFXDistortion8 = interface (IUnknown)
    ['{8ecf4326-455f-4d8b-bda9-8d5d3e9e3e0b}']
    function SetAllParameters(const DSFXDistortion : TDSFXDistortion) : HResult; stdcall;
    function GetAllParameters(out DSFXDistortion : TDSFXDistortion) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXCompressor8
(*)
  IDirectSoundFXCompressor8 = interface (IUnknown)
    ['{4bbd1154-62f6-4e2c-a15c-d3b6c417f7a0}']
    function SetAllParameters(const DSFXCompressor : TDSFXCompressor) : HResult; stdcall;
    function GetAllParameters(out DSFXCompressor : TDSFXCompressor) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXParamEq8
(*)
  IDirectSoundFXParamEq8 = interface (IUnknown)
    ['{c03ca9fe-fe90-4204-8078-82334cd177da}']
    function SetAllParameters(const DSFXParamEq : TDSFXParamEq) : HResult; stdcall;
    function GetAllParameters(out DSFXParamEq : TDSFXParamEq) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXI3DL2Reverb8
(*)
  IDirectSoundFXI3DL2Reverb8 = interface (IUnknown)
    ['{4b166a6a-0d66-43f3-80e3-ee6280dee1a4}']
    function SetAllParameters(const DSFXI3DL2Reverb : TDSFXI3DL2Reverb) : HResult; stdcall;
    function GetAllParameters(out DSFXI3DL2Reverb : TDSFXI3DL2Reverb) : HResult; stdcall;
    function SetPreset(Preset : LongWord) : HResult; stdcall;
    function GetPreset(out Preset : LongWord) : HResult; stdcall;
    function SetQuality(Quality : Longint) : HResult; stdcall;
    function GetQuality(out Quality : Longint) : HResult; stdcall;
  end;

(*)
 * IDirectSoundFXWavesReverb8
(*)
  IDirectSoundFXWavesReverb8 = interface (IUnknown)
    ['{46858c3a-0dc6-45e3-b760-d4eef16cb325}']
    function SetAllParameters(const DSFXWavesReverb : TDSFXWavesReverb) : HResult; stdcall;
    function GetAllParameters(out DSFXWavesReverb : TDSFXWavesReverb) : HResult; stdcall;
  end;

(*)
 * IDirectSoundNotify
(*)
  IDirectSoundNotify = interface (IUnknown)
    ['{b0210783-89cd-11d0-af08-00a0c925cd16}']
    (*** IDirectSoundNotify methods ***)
    function SetNotificationPositions(PositionNotifiesCount : LongWord; PositionNotifies : PDSBPositionNotify) : HResult; stdcall;
  end;

(*)
 * IDirectSoundNotify8
(*)
  IDirectSoundNotify8 = IDirectSoundNotify;

(*)
 * IKsPropertySet
(*)
  IKsPropertySet = interface (IUnknown)
    ['{31efac30-515c-11d0-a9aa-00aa0061be93}']
    // IKsPropertySet methods
    function Get(const GuidPropSet : TGUID; Id : Cardinal; InstanceData : Pointer; InstanceLength : Cardinal; PropertyData : Pointer; DataLength : Cardinal; out BytesReturned : Cardinal) : HResult; stdcall;
    // Warning: The following method is defined as Set() in DirectX
    //          which is a reserved word in Delphi!
    function SetProperty(const GuidPropSet : TGUID; Id : Cardinal; InstanceData : Pointer; InstanceLength : Cardinal; PropertyData : Pointer; DataLength : Cardinal) : HResult; stdcall;
    function QuerySupport(const GuidPropSet : TGUID; Id : Cardinal; out TypeSupport : Cardinal) : HResult; stdcall;
  end;


const
  KSPROPERTY_SUPPORT_GET                      = $00000001;
  KSPROPERTY_SUPPORT_SET                      = $00000002;

  DSFXR_PRESENT                               = 0;
  DSFXR_LOCHARDWARE                           = 1;
  DSFXR_LOCSOFTWARE                           = 2;
  DSFXR_UNALLOCATED                           = 3;
  DSFXR_FAILED                                = 4;
  DSFXR_UNKNOWN                               = 5;
  DSFXR_SENDLOOP                              = 6;

  DSFXGARGLE_WAVE_TRIANGLE                    = 0;
  DSFXGARGLE_WAVE_SQUARE                      = 1;
  DSFXGARGLE_RATEHZ_MIN                       = 1;
  DSFXGARGLE_RATEHZ_MAX                       = 1000;

  DSFXCHORUS_WAVE_TRIANGLE                    = 0;
  DSFXCHORUS_WAVE_SIN                         = 1;

  DSFXCHORUS_WETDRYMIX_MIN                    = 0.0;
  DSFXCHORUS_WETDRYMIX_MAX                    = 100.0;
  DSFXCHORUS_DEPTH_MIN                        = 0.0;
  DSFXCHORUS_DEPTH_MAX                        = 100.0;
  DSFXCHORUS_FEEDBACK_MIN                     = -99.0;
  DSFXCHORUS_FEEDBACK_MAX                     = 99.0;
  DSFXCHORUS_FREQUENCY_MIN                    = 0.0;
  DSFXCHORUS_FREQUENCY_MAX                    = 10.0;
  DSFXCHORUS_DELAY_MIN                        = 0.0;
  DSFXCHORUS_DELAY_MAX                        = 20.0;
  DSFXCHORUS_PHASE_MIN                        = 0;
  DSFXCHORUS_PHASE_MAX                        = 4;

  DSFXCHORUS_PHASE_NEG_180                    = 0;
  DSFXCHORUS_PHASE_NEG_90                     = 1;
  DSFXCHORUS_PHASE_ZERO                       = 2;
  DSFXCHORUS_PHASE_90                         = 3;
  DSFXCHORUS_PHASE_180                        = 4;

  DSFXFLANGER_WAVE_TRIANGLE                   = 0;
  DSFXFLANGER_WAVE_SIN                        = 1;

  DSFXFLANGER_WETDRYMIX_MIN                   = 0.0;
  DSFXFLANGER_WETDRYMIX_MAX                   = 100.0;
  DSFXFLANGER_FREQUENCY_MIN                   = 0.0;
  DSFXFLANGER_FREQUENCY_MAX                   = 10.0;
  DSFXFLANGER_DEPTH_MIN                       = 0.0;
  DSFXFLANGER_DEPTH_MAX                       = 100.0;
  DSFXFLANGER_PHASE_MIN                       = 0;
  DSFXFLANGER_PHASE_MAX                       = 4;
  DSFXFLANGER_FEEDBACK_MIN                    = -99.0;
  DSFXFLANGER_FEEDBACK_MAX                    = 99.0;
  DSFXFLANGER_DELAY_MIN                       = 0.0;
  DSFXFLANGER_DELAY_MAX                       = 4.0;

  DSFXFLANGER_PHASE_NEG_180                   = 0;
  DSFXFLANGER_PHASE_NEG_90                    = 1;
  DSFXFLANGER_PHASE_ZERO                      = 2;
  DSFXFLANGER_PHASE_90                        = 3;
  DSFXFLANGER_PHASE_180                       = 4;

  DSFXECHO_WETDRYMIX_MIN                      = 0.0;
  DSFXECHO_WETDRYMIX_MAX                      = 100.0;
  DSFXECHO_FEEDBACK_MIN                       = 0.0;
  DSFXECHO_FEEDBACK_MAX                       = 100.0;
  DSFXECHO_LEFTDELAY_MIN                      = 1.0;
  DSFXECHO_LEFTDELAY_MAX                      = 2000.0;
  DSFXECHO_RIGHTDELAY_MIN                     = 1.0;
  DSFXECHO_RIGHTDELAY_MAX                     = 2000.0;
  DSFXECHO_PANDELAY_MIN                       = 0;
  DSFXECHO_PANDELAY_MAX                       = 1;

  DSFXDISTORTION_GAIN_MIN                     = -60.0;
  DSFXDISTORTION_GAIN_MAX                     = 0.0;
  DSFXDISTORTION_EDGE_MIN                     = 0.0;
  DSFXDISTORTION_EDGE_MAX                     = 100.0;
  DSFXDISTORTION_POSTEQCENTERFREQUENCY_MIN    = 100.0;
  DSFXDISTORTION_POSTEQCENTERFREQUENCY_MAX    = 8000.0;
  DSFXDISTORTION_POSTEQBANDWIDTH_MIN          = 100.0;
  DSFXDISTORTION_POSTEQBANDWIDTH_MAX          = 8000.0;
  DSFXDISTORTION_PRELOWPASSCUTOFF_MIN         = 100.0;
  DSFXDISTORTION_PRELOWPASSCUTOFF_MAX         = 8000.0;

  DSFXCOMPRESSOR_GAIN_MIN                     = -60.0;
  DSFXCOMPRESSOR_GAIN_MAX                     = 60.0;
  DSFXCOMPRESSOR_ATTACK_MIN                   = 0.01;
  DSFXCOMPRESSOR_ATTACK_MAX                   = 500.0;
  DSFXCOMPRESSOR_RELEASE_MIN                  = 50.0;
  DSFXCOMPRESSOR_RELEASE_MAX                  = 3000.0;
  DSFXCOMPRESSOR_THRESHOLD_MIN                = -60.0;
  DSFXCOMPRESSOR_THRESHOLD_MAX                = 0.0;
  DSFXCOMPRESSOR_RATIO_MIN                    = 1.0;
  DSFXCOMPRESSOR_RATIO_MAX                    = 100.0;
  DSFXCOMPRESSOR_PREDELAY_MIN                 = 0.0;
  DSFXCOMPRESSOR_PREDELAY_MAX                 = 4.0;

  DSFXPARAMEQ_CENTER_MIN                      = 80.0;
  DSFXPARAMEQ_CENTER_MAX                      = 16000.0;
  DSFXPARAMEQ_BANDWIDTH_MIN                   = 1.0;
  DSFXPARAMEQ_BANDWIDTH_MAX                   = 36.0;
  DSFXPARAMEQ_GAIN_MIN                        = -15.0;
  DSFXPARAMEQ_GAIN_MAX                        = 15.0;

  DSFX_I3DL2REVERB_ROOM_MIN                   = (-10000);
  DSFX_I3DL2REVERB_ROOM_MAX                   = 0;
  DSFX_I3DL2REVERB_ROOM_DEFAULT               = (-1000);

  DSFX_I3DL2REVERB_ROOMHF_MIN                 = (-10000);
  DSFX_I3DL2REVERB_ROOMHF_MAX                 = 0;
  DSFX_I3DL2REVERB_ROOMHF_DEFAULT             = (-100);

  DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MIN      = 0.0;
  DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MAX      = 10.0;
  DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_DEFAULT  = 0.0;

  DSFX_I3DL2REVERB_DECAYTIME_MIN              = 0.1;
  DSFX_I3DL2REVERB_DECAYTIME_MAX              = 20.0;
  DSFX_I3DL2REVERB_DECAYTIME_DEFAULT          = 1.49;

  DSFX_I3DL2REVERB_DECAYHFRATIO_MIN           = 0.1;
  DSFX_I3DL2REVERB_DECAYHFRATIO_MAX           = 2.0;
  DSFX_I3DL2REVERB_DECAYHFRATIO_DEFAULT       = 0.83;

  DSFX_I3DL2REVERB_REFLECTIONS_MIN            = (-10000);
  DSFX_I3DL2REVERB_REFLECTIONS_MAX            = 1000;
  DSFX_I3DL2REVERB_REFLECTIONS_DEFAULT        = (-2602);

  DSFX_I3DL2REVERB_REFLECTIONSDELAY_MIN       = 0.0;
  DSFX_I3DL2REVERB_REFLECTIONSDELAY_MAX       = 0.3;
  DSFX_I3DL2REVERB_REFLECTIONSDELAY_DEFAULT   = 0.007;

  DSFX_I3DL2REVERB_REVERB_MIN                 = (-10000);
  DSFX_I3DL2REVERB_REVERB_MAX                 = 2000;
  DSFX_I3DL2REVERB_REVERB_DEFAULT             = (200);

  DSFX_I3DL2REVERB_REVERBDELAY_MIN            = 0.0;
  DSFX_I3DL2REVERB_REVERBDELAY_MAX            = 0.1;
  DSFX_I3DL2REVERB_REVERBDELAY_DEFAULT        = 0.011;

  DSFX_I3DL2REVERB_DIFFUSION_MIN              = 0.0;
  DSFX_I3DL2REVERB_DIFFUSION_MAX              = 100.0;
  DSFX_I3DL2REVERB_DIFFUSION_DEFAULT          = 100.0;

  DSFX_I3DL2REVERB_DENSITY_MIN                = 0.0;
  DSFX_I3DL2REVERB_DENSITY_MAX                = 100.0;
  DSFX_I3DL2REVERB_DENSITY_DEFAULT            = 100.0;

  DSFX_I3DL2REVERB_HFREFERENCE_MIN            = 20.0;
  DSFX_I3DL2REVERB_HFREFERENCE_MAX            = 20000.0;
  DSFX_I3DL2REVERB_HFREFERENCE_DEFAULT        = 5000.0;

  DSFX_I3DL2REVERB_QUALITY_MIN                = 0;
  DSFX_I3DL2REVERB_QUALITY_MAX                = 3;
  DSFX_I3DL2REVERB_QUALITY_DEFAULT            = 2;

  DSFX_WAVESREVERB_INGAIN_MIN                 = -96.0;
  DSFX_WAVESREVERB_INGAIN_MAX                 = 0.0;
  DSFX_WAVESREVERB_INGAIN_DEFAULT             = 0.0;
  DSFX_WAVESREVERB_REVERBMIX_MIN              = -96.0;
  DSFX_WAVESREVERB_REVERBMIX_MAX              = 0.0;
  DSFX_WAVESREVERB_REVERBMIX_DEFAULT          = 0.0;
  DSFX_WAVESREVERB_REVERBTIME_MIN             = 0.001;
  DSFX_WAVESREVERB_REVERBTIME_MAX             = 3000.0;
  DSFX_WAVESREVERB_REVERBTIME_DEFAULT         = 1000.0;
  DSFX_WAVESREVERB_HIGHFREQRTRATIO_MIN        = 0.001;
  DSFX_WAVESREVERB_HIGHFREQRTRATIO_MAX        = 0.999;
  DSFX_WAVESREVERB_HIGHFREQRTRATIO_DEFAULT    = 0.001;

(*)
 * GUID's for all the objects
(*)
type
  IID_IDirectSound = IDirectSound;
  IID_IDirectSoundBuffer = IDirectSoundBuffer;
  IID_IDirectSound3DListener = IDirectSound3DListener;
  IID_IDirectSound3DBuffer = IDirectSound3DBuffer;
  IID_IDirectSoundCapture = IDirectSoundCapture;
  IID_IDirectSoundCaptureBuffer = IDirectSoundCaptureBuffer;
  IID_IDirectSoundNotify = IDirectSoundNotify;
  IID_IKsPropertySet = IKsPropertySet;

  // DirectSound 8.0
  IID_IDirectSound8 = IDirectSound8;
  IID_IDirectSoundBuffer8 = IDirectSoundBuffer8;
  IID_IDirectSound3DListener8 = IDirectSound3DListener8;
  IID_IDirectSound3DBuffer8 = IDirectSound3DBuffer8;
  IID_IDirectSoundCapture8 = IDirectSoundCapture8;
  IID_IDirectSoundCaptureBuffer8 = IDirectSoundCaptureBuffer8;
  IID_IDirectSoundNotify8 = IDirectSoundNotify8;
  IID_IDirectSoundCaptureFXAec8 = IDirectSoundCaptureFXAec8;
  IID_IDirectSoundCaptureFXNoiseSuppress8 = IDirectSoundCaptureFXNoiseSuppress8;
  IID_IDirectSoundFullDuplex8 = IDirectSoundFullDuplex8;
  IID_IDirectSoundFXGargle8 = IDirectSoundFXGargle8;
  IID_IDirectSoundFXChorus8 = IDirectSoundFXChorus8;
  IID_IDirectSoundFXFlanger8 = IDirectSoundFXFlanger8;
  IID_IDirectSoundFXEcho8 = IDirectSoundFXEcho8;
  IID_IDirectSoundFXDistortion8 = IDirectSoundFXDistortion8;
  IID_IDirectSoundFXCompressor8 = IDirectSoundFXCompressor8;
  IID_IDirectSoundFXParamEq8 = IDirectSoundFXParamEq8;
  IID_IDirectSoundFXWavesReverb8 = IDirectSoundFXWavesReverb8;
  IID_IDirectSoundFXI3DL2Reverb8 = IDirectSoundFXI3DL2Reverb8;

//
// Creation Routines
//
var
    DirectSoundCreate : function (Guid : PGUID; out DirectSound : IDirectSound; UnkOuter : IUnknown) : HResult; stdcall;

    DirectSoundEnumerateW : function (DSEnumCallback: TDSEnumCallbackW; Context : Pointer) : HResult; stdcall;
    DirectSoundEnumerateA : function (DSEnumCallback : TDSEnumCallbackA; Context : Pointer) : HResult; stdcall;
    DirectSoundEnumerate : function (DSEnumCallback : TDSEnumCallback; Context : Pointer) : HResult; stdcall;

    DirectSoundCaptureCreate : function (GUID : PGUID; out DirectSoundCapture : IDirectSoundCapture; UnkOuter: IUnknown) : HResult; stdcall;

    DirectSoundCaptureEnumerateW : function (DSEnumCallback : TDSEnumCallbackW; Context : Pointer) : HResult; stdcall;
    DirectSoundCaptureEnumerateA : function (DSEnumCallback : TDSEnumCallbackA; Context : Pointer) : HResult; stdcall;
    DirectSoundCaptureEnumerate : function(DSEnumCallback : TDSEnumCallback; Context : Pointer) : HResult; stdcall;

(*)
 * DirectX 8.0
(*)

    DirectSoundCreate8 : function(GuidDevice : PGUID; out DirectSound8 : IDirectSound8; UnkOuter : IUnknown) : HResult; stdcall;
    DirectSoundCaptureCreate8 : function(GuidDevice : PGUID; out DirectSoundCapture8 : IDirectSoundCapture8; UnkOuter : IUnknown) : HResult; stdcall;
    DirectSoundFullDuplexCreate8 : function (pcGuidCaptureDevice, pcGuidRenderDevice: PGUID;  const DSCBufferDesc: TDSCBufferDesc; const DSBufferDesc: TDSBufferDesc; hWnd : hWnd; Level : LongWord; out DirectSoundFullDuplex8: IDirectSoundFullDuplex8; out DirectSoundCaptureBuffer8: IDirectSoundCaptureBuffer8; out DirectSoundBuffer8 : IDirectSoundBuffer8; UnkOuter : IUnknown): HResult; stdcall;
    GetDeviceID : function(GuidSrc, GuidDest : PGUID): HResult; stdcall;

//
// Return Values
//
const
  FLT_MIN = 1.175494351E-38;
  FLT_MAX = 3.402823466E+38;

  _FACDS = $878;
  MAKE_DSHRESULT_ = HResult($88780000);

// The function completed successfully
  DS_OK                          = S_OK;

// The call succeeded, but we had to substitute the 3D algorithm
  DS_NO_VIRTUALIZATION           = MAKE_DSHRESULT_ + 10;

// The call failed because resources (such as a priority level)
// were already being used by another caller
  DSERR_ALLOCATED                 = MAKE_DSHRESULT_ + 10;

// The control (vol, pan, etc.) requested by the caller is not available
  DSERR_CONTROLUNAVAIL            = MAKE_DSHRESULT_ + 30;

// An invalid parameter was passed to the returning function
  DSERR_INVALIDPARAM              = E_INVALIDARG;

// This call is not valid for the current state of this object
  DSERR_INVALIDCALL               = MAKE_DSHRESULT_ + 50;

// An undetermined error occurred inside the DirectSound subsystem
  DSERR_GENERIC                   = E_FAIL;

// The caller does not have the priority level required for the function to
// succeed
  DSERR_PRIOLEVELNEEDED           = MAKE_DSHRESULT_ + 70;

// Not enough free memory is available to complete the operation
  DSERR_OUTOFMEMORY               = E_OUTOFMEMORY;

// The specified WAVE format is not supported
  DSERR_BADFORMAT                 = MAKE_DSHRESULT_ + 100;

// The function called is not supported at this time
  DSERR_UNSUPPORTED               = E_NOTIMPL;

// No sound driver is available for use
  DSERR_NODRIVER                  = MAKE_DSHRESULT_ + 120;

// This object is already initialized
  DSERR_ALREADYINITIALIZED        = MAKE_DSHRESULT_ + 130;

// This object does not support aggregation
  DSERR_NOAGGREGATION             = CLASS_E_NOAGGREGATION;

// The buffer memory has been lost, and must be restored
  DSERR_BUFFERLOST                = MAKE_DSHRESULT_ + 150;

// Another app has a higher priority level, preventing this call from
// succeeding
  DSERR_OTHERAPPHASPRIO           = MAKE_DSHRESULT_ + 160;

// This object has not been initialized
  DSERR_UNINITIALIZED             = MAKE_DSHRESULT_ + 170;

// The requested COM interface is not available
  DSERR_NOINTERFACE               = E_NOINTERFACE;

// Access is denied
  DSERR_ACCESSDENIED              = E_ACCESSDENIED;

// Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds
  DSERR_BUFFERTOOSMALL            = MAKE_DSHRESULT_ + 180;

// Attempt to use DirectSound 8 functionality on an older DirectSound object
  DSERR_DS8_REQUIRED              = MAKE_DSHRESULT_ + 190;

// A circular loop of send effects was detected
  DSERR_SENDLOOP                  = MAKE_DSHRESULT_ + 200;

// The GUID specified in an audiopath file does not match a valid MIXIN buffer
  DSERR_BADSENDBUFFERGUID         = MAKE_DSHRESULT_ + 210;

// The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)
  DSERR_OBJECTNOTFOUND            = MAKE_DSHRESULT_ + 4449;

// The effects requested could not be found on the system, or they were found
// but in the wrong order, or in the wrong hardware/software locations.
  DSERR_FXUNAVAILABLE             = MAKE_DSHRESULT_ + 220;

(*)
 * Flags
(*)

  DSCAPS_PRIMARYMONO            = $00000001;
  DSCAPS_PRIMARYSTEREO          = $00000002;
  DSCAPS_PRIMARY8BIT            = $00000004;
  DSCAPS_PRIMARY16BIT           = $00000008;
  DSCAPS_CONTINUOUSRATE         = $00000010;
  DSCAPS_EMULDRIVER             = $00000020;
  DSCAPS_CERTIFIED              = $00000040;
  DSCAPS_SECONDARYMONO          = $00000100;
  DSCAPS_SECONDARYSTEREO        = $00000200;
  DSCAPS_SECONDARY8BIT          = $00000400;
  DSCAPS_SECONDARY16BIT         = $00000800;

  DSSCL_NORMAL                  = $00000001;
  DSSCL_PRIORITY                = $00000002;
  DSSCL_EXCLUSIVE               = $00000003;
  DSSCL_WRITEPRIMARY            = $00000004;

  DSSPEAKER_DIRECTOUT           = $00000000;
  DSSPEAKER_HEADPHONE           = $00000001;
  DSSPEAKER_MONO                = $00000002;
  DSSPEAKER_QUAD                = $00000003;
  DSSPEAKER_STEREO              = $00000004;
  DSSPEAKER_SURROUND            = $00000005;
  DSSPEAKER_5POINT1             = $00000006;
  DSSPEAKER_7POINT1             = $00000007;

  DSSPEAKER_GEOMETRY_MIN        = $00000005;  //   5 degrees
  DSSPEAKER_GEOMETRY_NARROW     = $0000000A;  //  10 degrees
  DSSPEAKER_GEOMETRY_WIDE       = $00000014;  //  20 degrees
  DSSPEAKER_GEOMETRY_MAX        = $000000B4;  // 180 degrees

const
  DSBCAPS_PRIMARYBUFFER         = $00000001;
  DSBCAPS_STATIC                = $00000002;
  DSBCAPS_LOCHARDWARE           = $00000004;
  DSBCAPS_LOCSOFTWARE           = $00000008;
  DSBCAPS_CTRL3D                = $00000010;
  DSBCAPS_CTRLFREQUENCY         = $00000020;
  DSBCAPS_CTRLPAN               = $00000040;
  DSBCAPS_CTRLVOLUME            = $00000080;
  DSBCAPS_CTRLPOSITIONNOTIFY    = $00000100;
  DSBCAPS_CTRLFX                = $00000200;
  DSBCAPS_STICKYFOCUS           = $00004000;
  DSBCAPS_GLOBALFOCUS           = $00008000;
  DSBCAPS_GETCURRENTPOSITION2   = $00010000;
  DSBCAPS_MUTE3DATMAXDISTANCE   = $00020000;
  DSBCAPS_LOCDEFER              = $00040000;
  DSBCAPS_CTRLDEFAULT           = $000000E0;
  DSBCAPS_CTRLALL               = $000001F0;


  DSBPLAY_LOOPING               = $00000001;
  DSBPLAY_LOCHARDWARE           = $00000002;
  DSBPLAY_LOCSOFTWARE           = $00000004;
  DSBPLAY_TERMINATEBY_TIME      = $00000008;
  DSBPLAY_TERMINATEBY_DISTANCE  = $000000010;
  DSBPLAY_TERMINATEBY_PRIORITY  = $000000020;

  DSBSTATUS_PLAYING             = $00000001;
  DSBSTATUS_BUFFERLOST          = $00000002;
  DSBSTATUS_LOOPING             = $00000004;
  DSBSTATUS_LOCHARDWARE         = $00000008;
  DSBSTATUS_LOCSOFTWARE         = $00000010;
  DSBSTATUS_TERMINATED          = $00000020;

  DSBLOCK_FROMWRITECURSOR       = $00000001;
  DSBLOCK_ENTIREBUFFER          = $00000002;

  DSBFREQUENCY_MIN              = 100;
  DSBFREQUENCY_MAX              = 200000;
  DSBFREQUENCY_ORIGINAL         = 0;

  DSBPAN_LEFT                   = -10000;
  DSBPAN_CENTER                 = 0;
  DSBPAN_RIGHT                  = 10000;

  DSBVOLUME_MIN                 = -10000;
  DSBVOLUME_MAX                 = 0;

  DSBSIZE_MIN                   = 4;
  DSBSIZE_MAX                   = $0FFFFFFF;
  DSBSIZE_FX_MIN                = 150;  // NOTE: Milliseconds, not bytes

  DS3DMODE_NORMAL               = $00000000;
  DS3DMODE_HEADRELATIVE         = $00000001;
  DS3DMODE_DISABLE              = $00000002;

  DS3D_IMMEDIATE                = $00000000;
  DS3D_DEFERRED                 = $00000001;

  DS3D_MINDISTANCEFACTOR        = FLT_MIN;
  DS3D_MAXDISTANCEFACTOR        = FLT_MAX;
  DS3D_DEFAULTDISTANCEFACTOR    = 1.0;

  DS3D_MINROLLOFFFACTOR         = 0.0;
  DS3D_MAXROLLOFFFACTOR         = 10.0;
  DS3D_DEFAULTROLLOFFFACTOR     = 1.0;

  DS3D_MINDOPPLERFACTOR         = 0.0;
  DS3D_MAXDOPPLERFACTOR         = 10.0;
  DS3D_DEFAULTDOPPLERFACTOR     = 1.0;

  DS3D_DEFAULTMINDISTANCE       = 1.0;
  DS3D_DEFAULTMAXDISTANCE       = 1000000000.0;

  DS3D_MINCONEANGLE             = 0;
  DS3D_MAXCONEANGLE             = 360;
  DS3D_DEFAULTCONEANGLE         = 360;

  DS3D_DEFAULTCONEOUTSIDEVOLUME = DSBVOLUME_MAX;

// IDirectSoundCapture attributes

  DSCCAPS_EMULDRIVER            = DSCAPS_EMULDRIVER;
  DSCCAPS_CERTIFIED             = DSCAPS_CERTIFIED;
  DSCCAPS_MULTIPLECAPTURE       = $00000001;


// IDirectSoundCaptureBuffer attributes

  DSCBCAPS_WAVEMAPPED           = $80000000;

  DSCBCAPS_CTRLFX               = $00000200;

  DSCBLOCK_ENTIREBUFFER         = $00000001;

  DSCBSTATUS_CAPTURING          = $00000001;
  DSCBSTATUS_LOOPING            = $00000002;

  DSCBSTART_LOOPING             = $00000001;

  DSBPN_OFFSETSTOP              = $FFFFFFFF;

  DS_CERTIFIED                  = $00000000;
  DS_UNCERTIFIED                = $00000001;

  DSFX_LOCHARDWARE              = $00000001;
  DSFX_LOCSOFTWARE              = $00000002;

  DSCFX_LOCHARDWARE             = $00000001;
  DSCFX_LOCSOFTWARE             = $00000002;

  DSCFXR_LOCHARDWARE            = $00000010;
  DSCFXR_LOCSOFTWARE            = $00000020;

// These match the AEC_MODE_* constants in the DDK's ksmedia.h file
  DSCFX_AEC_MODE_PASS_THROUGH                     = 0;
  DSCFX_AEC_MODE_HALF_DUPLEX                      = 1;
  DSCFX_AEC_MODE_FULL_DUPLEX                      = 2;

// These match the AEC_STATUS_* constants in ksmedia.h
  DSCFX_AEC_STATUS_HISTORY_UNINITIALIZED          = 0;
  DSCFX_AEC_STATUS_HISTORY_CONTINUOUSLY_CONVERGED = 1;
  DSCFX_AEC_STATUS_HISTORY_PREVIOUSLY_DIVERGED    = 2;
  DSCFX_AEC_STATUS_CURRENTLY_CONVERGED            = 8;

(*)
 * I3DL2 Material Presets
(*)

{
  I3DL2_MATERIAL_PRESET_SINGLEWINDOW    = -2800,0.71;
  I3DL2_MATERIAL_PRESET_DOUBLEWINDOW    = -5000,0.40;
  I3DL2_MATERIAL_PRESET_THINDOOR        = -1800,0.66;
  I3DL2_MATERIAL_PRESET_THICKDOOR       = -4400,0.64;
  I3DL2_MATERIAL_PRESET_WOODWALL        = -4000,0.50;
  I3DL2_MATERIAL_PRESET_BRICKWALL       = -5000,0.60;
  I3DL2_MATERIAL_PRESET_STONEWALL       = -6000,0.68;
  I3DL2_MATERIAL_PRESET_CURTAIN         = -1200,0.15;
}

(*)
 * I3DL2 Reverberation Presets Values
(*)

  I3DL2_ENVIRONMENT_PRESET_DEFAULT        : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -100; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.83; Reflections : -2602; ReflectionsDelay : 0.007; Reverb :  200; ReverbDelay : 0.011; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_GENERIC        : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -100; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.83; Reflections : -2602; ReflectionsDelay : 0.007; Reverb :  200; ReverbDelay : 0.011; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_PADDEDCELL     : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -6000; RoomRolloffFactor: 0.0; DecayTime :  0.17; DecayHFRatio: 0.10; Reflections : -1204; ReflectionsDelay : 0.001; Reverb :  207; ReverbDelay : 0.002; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_ROOM           : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -454; RoomRolloffFactor: 0.0; DecayTime :  0.40; DecayHFRatio: 0.83; Reflections : -1646; ReflectionsDelay : 0.002; Reverb :   53; ReverbDelay : 0.003; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_BATHROOM       : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -1200; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.54; Reflections :  -370; ReflectionsDelay : 0.007; Reverb : 1030; ReverbDelay : 0.011; Diffusion : 100.0; Density :  60.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_LIVINGROOM     : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -6000; RoomRolloffFactor: 0.0; DecayTime :  0.50; DecayHFRatio: 0.10; Reflections : -1376; ReflectionsDelay : 0.003; Reverb :-1104; ReverbDelay : 0.004; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_STONEROOM      : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -300; RoomRolloffFactor: 0.0; DecayTime :  2.31; DecayHFRatio: 0.64; Reflections :  -711; ReflectionsDelay : 0.012; Reverb :   83; ReverbDelay : 0.017; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_AUDITORIUM     : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -476; RoomRolloffFactor: 0.0; DecayTime :  4.32; DecayHFRatio: 0.59; Reflections :  -789; ReflectionsDelay : 0.020; Reverb : -289; ReverbDelay : 0.030; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_CONCERTHALL    : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -500; RoomRolloffFactor: 0.0; DecayTime :  3.92; DecayHFRatio: 0.70; Reflections : -1230; ReflectionsDelay : 0.020; Reverb :   -2; ReverbDelay : 0.029; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_CAVE           : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :     0; RoomRolloffFactor: 0.0; DecayTime :  2.91; DecayHFRatio: 1.30; Reflections :  -602; ReflectionsDelay : 0.015; Reverb : -302; ReverbDelay : 0.022; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_ARENA          : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -698; RoomRolloffFactor: 0.0; DecayTime :  7.24; DecayHFRatio: 0.33; Reflections : -1166; ReflectionsDelay : 0.020; Reverb :   16; ReverbDelay : 0.030; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_HANGAR         : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -1000; RoomRolloffFactor: 0.0; DecayTime : 10.05; DecayHFRatio: 0.23; Reflections :  -602; ReflectionsDelay : 0.020; Reverb :  198; ReverbDelay : 0.030; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY: TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -4000; RoomRolloffFactor: 0.0; DecayTime :  0.30; DecayHFRatio: 0.10; Reflections : -1831; ReflectionsDelay : 0.002; Reverb :-1630; ReverbDelay : 0.030; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_HALLWAY        : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -300; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.59; Reflections : -1219; ReflectionsDelay : 0.007; Reverb :  441; ReverbDelay : 0.011; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR  : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -237; RoomRolloffFactor: 0.0; DecayTime :  2.70; DecayHFRatio: 0.79; Reflections : -1214; ReflectionsDelay : 0.013; Reverb :  395; ReverbDelay : 0.020; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_ALLEY          : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -270; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.86; Reflections : -1204; ReflectionsDelay : 0.007; Reverb :   -4; ReverbDelay : 0.011; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_FOREST         : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -3300; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.54; Reflections : -2560; ReflectionsDelay : 0.162; Reverb : -613; ReverbDelay : 0.088; Diffusion :  79.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_CITY           : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :  -800; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.67; Reflections : -2273; ReflectionsDelay : 0.007; Reverb :-2217; ReverbDelay : 0.011; Diffusion :  50.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_MOUNTAINS      : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -2500; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.21; Reflections : -2780; ReflectionsDelay : 0.300; Reverb :-2014; ReverbDelay : 0.100; Diffusion :  27.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_QUARRY         : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -1000; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.83; Reflections :-10000; ReflectionsDelay : 0.061; Reverb :  500; ReverbDelay : 0.025; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_PLAIN          : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -2000; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.50; Reflections : -2466; ReflectionsDelay : 0.179; Reverb :-2514; ReverbDelay : 0.100; Diffusion :  21.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_PARKINGLOT     : TDSFXI3DL2Reverb = (Room : -1000; RoomHF :     0; RoomRolloffFactor: 0.0; DecayTime :  1.65; DecayHFRatio: 1.50; Reflections : -1363; ReflectionsDelay : 0.008; Reverb :-1153; ReverbDelay : 0.012; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_SEWERPIPE      : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -1000; RoomRolloffFactor: 0.0; DecayTime :  2.81; DecayHFRatio: 0.14; Reflections :   429; ReflectionsDelay : 0.014; Reverb :  648; ReverbDelay : 0.021; Diffusion :  80.0; Density :  60.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_UNDERWATER     : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -4000; RoomRolloffFactor: 0.0; DecayTime :  1.49; DecayHFRatio: 0.10; Reflections :  -449; ReflectionsDelay : 0.007; Reverb : 1700; ReverbDelay : 0.011; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);

(*)
 * Examples simulating 'musical' reverb presets
 *
 * Name       Decay time   Description
 * Small Room    1.1s      A small size room with a length of 5m or so.
 * Medium Room   1.3s      A medium size room with a length of 10m or so.
 * Large Room    1.5s      A large size room suitable for live performances.
 * Medium Hall   1.8s      A medium size concert hall.
 * Large Hall    1.8s      A large size concert hall suitable for a full orchestra.
 * Plate         1.3s      A plate reverb simulation.
(*)

  I3DL2_ENVIRONMENT_PRESET_SMALLROOM      : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -600; RoomRolloffFactor : 0.0; DecayTime : 1.10; DecayHFRatio : 0.83; Reflections :  -400; ReflectionsDelay : 0.005; Reverb :   500; ReverbDelay : 0.010; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM     : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -600; RoomRolloffFactor : 0.0; DecayTime : 1.30; DecayHFRatio : 0.83; Reflections : -1000; ReflectionsDelay : 0.010; Reverb :  -200; ReverbDelay : 0.020; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_LARGEROOM      : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -600; RoomRolloffFactor : 0.0; DecayTime : 1.50; DecayHFRatio : 0.83; Reflections : -1600; ReflectionsDelay : 0.020; Reverb : -1000; ReverbDelay : 0.040; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL     : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -600; RoomRolloffFactor : 0.0; DecayTime : 1.80; DecayHFRatio : 0.70; Reflections : -1300; ReflectionsDelay : 0.015; Reverb :  -800; ReverbDelay : 0.030; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_LARGEHALL      : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -600; RoomRolloffFactor : 0.0; DecayTime : 1.80; DecayHFRatio : 0.70; Reflections : -2000; ReflectionsDelay : 0.030; Reverb : -1400; ReverbDelay : 0.060; Diffusion : 100.0; Density : 100.0; HFReference : 5000.0);
  I3DL2_ENVIRONMENT_PRESET_PLATE          : TDSFXI3DL2Reverb = (Room : -1000; RoomHF : -200; RoomRolloffFactor : 0.0; DecayTime : 1.30; DecayHFRatio : 0.90; Reflections :     0; ReflectionsDelay : 0.002; Reverb :     0; ReverbDelay : 0.010; Diffusion : 100.0; Density :  75.0; HFReference : 5000.0);


(*)
 * DirectSound3D Algorithms
(*)

const
// Default DirectSound3D algorithm 
  DS3DALG_DEFAULT                : TGUID = '{00000000-0000-0000-0000-000000000000}';

// No virtualization
  DS3DALG_NO_VIRTUALIZATION      : TGUID = '{C241333F-1C1B-11d2-94F5-00C04FC28ACA}';

// High-quality HRTF algorithm
  DS3DALG_HRTF_FULL              : TGUID = '{C2413340-1C1B-11d2-94F5-00C04FC28ACA}';

// Lower-quality HRTF algorithm
  DS3DALG_HRTF_LIGHT             : TGUID = '{C2413342-1C1B-11d2-94F5-00C04FC28ACA}';

// Special GUID meaning "select all objects" for use in GetObjectInPath()
  GUID_All_Objects               : TGUID = '{aa114de5-c262-4169-a1c8-23d698cc73b5}';

(*)
 * DirectSound Internal Effect Algorithms
(*)
  GUID_DSFX_STANDARD_GARGLE      : TGUID = '{DAFD8210-5711-4B91-9FE3-F75B7AE279BF}';
  GUID_DSFX_STANDARD_CHORUS      : TGUID = '{EFE6629C-81F7-4281-BD91-C9D604A95AF6}';
  GUID_DSFX_STANDARD_FLANGER     : TGUID = '{EFCA3D92-DFD8-4672-A603-7420894BAD98}';
  GUID_DSFX_STANDARD_ECHO        : TGUID = '{EF3E932C-D40B-4F51-8CCF-3F98F1B29D5D}';
  GUID_DSFX_STANDARD_DISTORTION  : TGUID = '{EF114C90-CD1D-484E-96E5-09CFAF912A21}';
  GUID_DSFX_STANDARD_COMPRESSOR  : TGUID = '{EF011F79-4000-406D-87AF-BFFB3FC39D57}';
  GUID_DSFX_STANDARD_PARAMEQ     : TGUID = '{120CED89-3BF4-4173-A132-3CB406CF3231}';
  GUID_DSFX_STANDARD_I3DL2REVERB : TGUID = '{EF985E71-D5C7-42D4-BA4D-2D073E2E96F4}';
  GUID_DSFX_WAVES_REVERB         : TGUID = '{87FC0268-9A55-4360-95AA-004A1D9DE26C}';

(*)
 * DirectSound Capture Effect Algorithms
(*)
  GUID_DSCFX_CLASS_AEC           : TGUID = '{BF963D80-C559-11D0-8A2B-00A0C9255AC1}';
  GUID_DSCFX_MS_AEC              : TGUID = '{CDEBB919-379A-488a-8765-F53CFD36DE40}';
  GUID_DSCFX_SYSTEM_AEC          : TGUID = '{1C22C56D-9879-4f5b-A389-27996DDC2810}';
  GUID_DSCFX_CLASS_NS            : TGUID = '{E07F903F-62FD-4e60-8CDD-DEA7236665B5}';
  GUID_DSCFX_MS_NS               : TGUID = '{11C5C73B-66E9-4ba1-A0BA-E814C6EED92D}';
  GUID_DSCFX_SYSTEM_NS           : TGUID = '{5AB0882E-7274-4516-877D-4EEE99BA4FD0}';

(*)
 *******************************************************************************
 * Library : ksmedia.h
 *******************************************************************************
(*)

  // Speaker Positions:
  SPEAKER_FRONT_LEFT              = $1;
  SPEAKER_FRONT_RIGHT             = $2;
  SPEAKER_FRONT_CENTER            = $4;
  SPEAKER_LOW_FREQUENCY           = $8;
  SPEAKER_BACK_LEFT               = $10;
  SPEAKER_BACK_RIGHT              = $20;
  SPEAKER_FRONT_LEFT_OF_CENTER    = $40;
  SPEAKER_FRONT_RIGHT_OF_CENTER   = $80;
  SPEAKER_BACK_CENTER             = $100;
  SPEAKER_SIDE_LEFT               = $200;
  SPEAKER_SIDE_RIGHT              = $400;
  SPEAKER_TOP_CENTER              = $800;
  SPEAKER_TOP_FRONT_LEFT          = $1000;
  SPEAKER_TOP_FRONT_CENTER        = $2000;
  SPEAKER_TOP_FRONT_RIGHT         = $4000;
  SPEAKER_TOP_BACK_LEFT           = $8000;
  SPEAKER_TOP_BACK_CENTER         = $10000;
  SPEAKER_TOP_BACK_RIGHT          = $20000;

  // Bit mask locations reserved for future use
  SPEAKER_RESERVED                = $7FFC0000;

  // Used to specify that any possible permutation of speaker configurations
  SPEAKER_ALL                     = $80000000;

  WAVE_FORMAT_EXTENSIBLE          = $FFFE;

  KSDATAFORMAT_SUBTYPE_ANALOG         : TGUID = '{6dba3190-67bd-11cf-a0f7-0020afd156e4}';
  KSDATAFORMAT_SUBTYPE_PCM            : TGUID = '{00000001-0000-0010-8000-00aa00389b71}';
  KSDATAFORMAT_SUBTYPE_IEEE_FLOAT     : TGUID = '{00000003-0000-0010-8000-00aa00389b71}';
  KSDATAFORMAT_SUBTYPE_DRM            : TGUID = '{00000009-0000-0010-8000-00aa00389b71}';
  KSDATAFORMAT_SUBTYPE_ALAW           : TGUID = '{00000006-0000-0010-8000-00aa00389b71}';
  KSDATAFORMAT_SUBTYPE_MULAW          : TGUID = '{00000007-0000-0010-8000-00aa00389b71}';
  KSDATAFORMAT_SUBTYPE_ADPCM          : TGUID = '{00000002-0000-0010-8000-00aa00389b71}';
  KSDATAFORMAT_SUBTYPE_MPEG           : TGUID = '{00000050-0000-0010-8000-00aa00389b71}';
  KSDATAFORMAT_SPECIFIER_VC_ID        : TGUID = '{AD98D184-AAC3-11D0-A41C-00A0C9223196}';
  KSDATAFORMAT_SPECIFIER_WAVEFORMATEX : TGUID = '{05589f81-c356-11ce-bf01-00aa0055595a}';
  KSDATAFORMAT_SPECIFIER_DSOUND       : TGUID = '{518590a2-a184-11d0-8522-00c04fd9baf3}';

type
  PWaveFormatExtensible = ^TWaveFormatExtensible;
  TWaveFormatExtensible = packed record
    Format : TWaveFormatEx;
    case Byte of
      0: (ValidBitsPerSample : Word;      // bits of precision
          ChannelMask        : LongWord;  // which channels are present in stream
          SubFormat          : TGUID);
      1: (SamplesPerBlock    : Word);     // valid if wBitsPerSample = 0
      2: (Reserved           : Word);     // If neither applies, set to zero.
  end;

//function DSErrorString(Value : HResult) : String;

//implementation

function DSSPEAKER_COMBINED(c, g : Variant) : LongWord;
begin
  Result := Byte(c) or (Byte(g) shl 16)
end;

function DSSPEAKER_CONFIG(a : Variant) : Byte;
begin
  Result := Byte(a);
end;

function DSSPEAKER_GEOMETRY(a : Variant) : Byte;
begin
  Result := Byte(a shr 16 and $FF);
end;

function DSErrorString(Value: HResult) : string;
begin
  case Value of
    HResult(DS_OK)                    : Result := 'The request completed successfully.';
    HResult(DSERR_ALLOCATED)          : Result := 'The request failed because resources, such as a priority level, were already in use by another caller.';
    HResult(DSERR_ALREADYINITIALIZED) : Result := 'The object is already initialized.';
    HResult(DSERR_ACCESSDENIED)       : Result := 'Access is denied.';
    HResult(DSERR_BADFORMAT)          : Result := 'The specified wave format is not supported.';
    HResult(DSERR_BADSENDBUFFERGUID)  : Result := 'The GUID specified in an audiopath file does not match a valid MIXIN buffer.';
    HResult(DSERR_BUFFERLOST)         : Result := 'The buffer memory has been lost and must be restored.';
    HResult(DSERR_BUFFERTOOSMALL)     : Result := 'Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds.';
    HResult(DSERR_CONTROLUNAVAIL)     : Result := 'The control (volume, pan, and so forth) requested by the caller is not available.';
    HResult(DSERR_DS8_REQUIRED)       : Result := 'Attempt to use DirectSound 8 functionality on an older DirectSound object.';
    HResult(DSERR_GENERIC)            : Result := 'An undetermined error occurred inside the DirectSound subsystem.';
    HResult(DSERR_INVALIDCALL)        : Result := 'This function is not valid for the current state of this object.';
    HResult(DSERR_INVALIDPARAM)       : Result := 'An invalid parameter was passed to the returning function.';
    HResult(DSERR_NOAGGREGATION)      : Result := 'The object does not support aggregation.';
    HResult(DSERR_NODRIVER)           : Result := 'No sound driver is available for use.';
    HResult(DSERR_NOINTERFACE)        : Result := 'The requested COM interface is not available.';
    HResult(DSERR_OBJECTNOTFOUND)     : Result := 'The object requested was not found (numerically equal to DMUS_E_NOT_FOUND).';

    HResult(DSERR_FXUNAVAILABLE)      : Result := 'The effects requested could not be found on the system, or they were found but in the wrong order, or in the wrong hardware/software locations.';

    HResult(DSERR_OTHERAPPHASPRIO)    : Result := 'Another application has a higher priority level, preventing this call from succeeding.';
    HResult(DSERR_OUTOFMEMORY)        : Result := 'The DirectSound subsystem could not allocate sufficient memory to complete the caller´s request.';
    HResult(DSERR_PRIOLEVELNEEDED)    : Result := 'The caller does not have the priority level required for the function to succeed.';
    HResult(DSERR_SENDLOOP)           : Result := 'A circular loop of send effects was detected.';
    HResult(DSERR_UNINITIALIZED)      : Result := 'The IDirectSound::Initialize method has not been called or has not been called successfully before other methods were called.';
    HResult(DSERR_UNSUPPORTED)        : Result := 'The function called is not supported at this time.';
    else                                Result := 'Unrecognized Error';
  end;
end;

Procedure DSoundInit;
begin
  DSoundDLL := LoadLibrary(dsounddllname);
  DirectSoundCreate            := GetProcAddress(DSoundDLL, 'DirectSoundCreate');
  DirectSoundCreate8           := GetProcAddress(DSoundDLL, 'DirectSoundCreate8');
  DirectSoundFullDuplexCreate8 := GetProcAddress(DSoundDLL, 'DirectSoundFullDuplexCreate8');
  GetDeviceID                  := GetProcAddress(DSoundDLL, 'GetDeviceID');

  DirectSoundEnumerateW        := GetProcAddress(DSoundDLL, 'DirectSoundEnumerateW');
  DirectSoundEnumerateA        := GetProcAddress(DSoundDLL, 'DirectSoundEnumerateA');
  DirectSoundEnumerate         := DirectSoundEnumerateA;

  DirectSoundCaptureCreate     := GetProcAddress(DSoundDLL, 'DirectSoundCaptureCreate');
  DirectSoundCaptureCreate8    := GetProcAddress(DSoundDLL, 'DirectSoundCaptureCreate8');

  DirectSoundCaptureEnumerateW := GetProcAddress(DSoundDLL, 'DirectSoundCaptureEnumerateW');
  DirectSoundCaptureEnumerateA := GetProcAddress(DSoundDLL, 'DirectSoundCaptureEnumerateA');
  DirectSoundCaptureEnumerate  := DirectSoundCaptureEnumerateA;
end;

Procedure DSoundFree;
begin
  if DSoundDLL <> 0 then FreeLibrary(DSoundDLL);
end;

//end.
