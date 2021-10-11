{ ------------------------------ }
{ Original : DGLOpenGL15 - 600kb }
{ ------------------------------ }
{ Modify by -=SVSD_VAL=-         }
{ Ripped   : 270kb               }
{ SVSD_VAL WAS HERE :D           }
{ Site     : rtbt.ru             }
{ Mail     : valdim_05@mail.ru   }
{ Icq      : 223-725-915         }
{ Jabber   : svsd_val@jabber.ru  }
{ ------------------------------ }
{$IFDEF FPC}
 {$MODE Delphi}
 {$IFDEF CPUI386}
  {$DEFINE CPU386}
  {$ASMMODE INTEL}
 {$ENDIF}
 {$IFNDEF WIN32}
  {$LINKLIB c}
 {$ENDIF}
{$ENDIF}

type
  PWGLSWAP =^TWGLSWAP;
  TWGLSWAP = packed record
    hdc: Cardinal;
    uiFlags: Cardinal;
  end;

  PPointer    = ^Pointer;

  TGLenum     = Cardinal;
  TGLboolean  = BYTEBOOL;
  TGLbitfield = Cardinal;
  TGLbyte     = Shortint;
  TGLshort    = SmallInt;
  TGLint      = Integer;
  TGLsizei    = Integer;
  TGLubyte    = Byte;
  TGLushort   = Word;
  TGLuint     = Cardinal;
  TGLfloat    = Single;
  TGLclampf   = Single;
  TGLdouble   = Double;
  TGLclampd   = Double;
  TGLvoid     = Pointer;
  TGLint64    = Int64;

  GLenum      = Cardinal;
  GLboolean   = BYTEBOOL;
  GLbitfield  = Cardinal;
  GLbyte      = Shortint;
  GLshort     = SmallInt;
  GLint       = Integer;
  GLsizei     = Integer;
  GLubyte     = Byte;
  GLushort    = Word;
  GLuint      = Cardinal;
  GLfloat     = Single;
  GLclampf    = Single;
  GLdouble    = Double;
  GLclampd    = Double;
  GLvoid      = Pointer;
  GLint64     = Int64;

  PGLBoolean  = ^TGLboolean;
  PGLByte     = ^TGLbyte;
  PGLShort    = ^TGLshort;
  PGLInt      = ^TGLint;
  PGLSizei    = ^TGLsizei;
  PGLubyte    = ^TGLubyte;
  PGLushort   = ^TGLushort;
  PGLuint     = ^TGLuint;
  PGLclampf   = ^TGLclampf;
//  PGLfloat    = ^TGLfloat;
  PGLdouble   = ^TGLdouble;
  PGLclampd   = ^TGLclampd;
  PGLenum     = ^TGLenum;
  PGLvoid     = Pointer;
  PGLint64    = ^TGLint64;


  TGLVectori4 = array[0..3] of TGLInt;
  TGLVectorf4 = array[0..3] of TGLFloat;
  TGLVectord3 = array[0..2] of TGLDouble;
  TGLVectord4 = array[0..3] of TGLDouble;
  TGLVectorp4 = array[0..3] of Pointer;

  TGLArrayf4  = array [0..3] of TGLFloat;
  TGLArrayf3  = array [0..2] of TGLFloat;
  TGLArrayd3  = array [0..2] of TGLDouble;
  TGLArrayi4  = array [0..3] of TGLint;
  TGLArrayp4  = array [0..3] of Pointer;

  TGLMatrixf4 = array[0..3, 0..3] of Single;
  TGLMatrixd4 = array[0..3, 0..3] of Double;
  TGlMatrixi4 = array[0..3, 0..3] of Integer;

  // Datatypes corresponding to OpenGL12.pas for easy porting
  TVector3d = TGLVectord3;

  TVector4i = TGLVectori4;
  TVector4f = TGLVectorf4;
  TVector4p = TGLVectorp4;

  TMatrix4f = TGLMatrixf4;
  TMatrix4d = TGLMatrixd4;


  // WGL_ARB_pbuffer
  HPBUFFERARB = THandle;

  // WGL_EXT_pbuffer
  HPBUFFEREXT = THandle;

  // GL_ARB_SHADER_OBJECTS
  PGLHandleARB = ^GLHandleARB;
  GLHandleARB  = Integer;
  PPGLCharARB  = ^PChar;
  PGLCharARB   = PChar;
  GLCharARB    = Char;


var
  GL_VERSION_1_0,
  GL_VERSION_1_1,
  GL_VERSION_1_2,
  GL_VERSION_1_3,
  GL_VERSION_1_4,
  GL_VERSION_1_5,
  GLU_VERSION_1_1,
  GLU_VERSION_1_2,
  GLU_VERSION_1_3,
  GL_ARB_depth_texture,
  GL_ARB_fragment_program,
  GL_ARB_imaging,
  GL_ARB_matrix_palette,
  GL_ARB_multisample,
  GL_ARB_multitexture,
  GL_ARB_point_parameters,
  GL_ARB_shadow,
  GL_ARB_shadow_ambient,
  GL_ARB_texture_border_clamp,
  GL_ARB_texture_compression,
  GL_ARB_texture_cube_map,
  GL_ARB_texture_env_add,
  GL_ARB_texture_env_combine,
  GL_ARB_texture_env_crossbar,
  GL_ARB_texture_env_dot3,
  GL_ARB_texture_mirror_repeat,
  GL_ARB_texture_mirrored_repeat,
  GL_ARB_transpose_matrix,
  GL_ARB_vertex_blend,
  GL_ARB_vertex_buffer_object,
  GL_ARB_vertex_program,
  GL_ARB_window_pos,
  GL_ARB_shader_objects,
  GL_ARB_vertex_shader,
  GL_ARB_fragment_shader,
  GL_ARB_shading_language_100,
  GL_ARB_occlusion_query,
  GL_ARB_texture_non_power_of_two,
  GL_ARB_point_sprite,

  GL_S3_s3tc,
  GL_SGIS_detail_texture,
  GL_SGIS_fog_function,
  GL_SGIS_generate_mipmap,
  GL_SGIS_multisample,
  GL_SGIS_pixel_texture,
  GL_SGIS_point_line_texgen,
  GL_SGIS_point_parameters,
  GL_SGIS_sharpen_texture,
  GL_SGIS_texture4D,
  GL_SGIS_texture_border_clamp,
  GL_SGIS_texture_color_mask,
  GL_SGIS_texture_edge_clamp,
  GL_SGIS_texture_filter4,
  GL_SGIS_texture_lod,
  GL_SGIS_texture_select,
  WGL_ARB_buffer_region,
  WGL_ARB_extensions_string,
  WGL_ARB_make_current_read,
  WGL_ARB_multisample,
  WGL_ARB_pbuffer,
  WGL_ARB_pixel_format,
  WGL_ARB_render_texture,
  WGL_EXT_depth_float,
  WGL_EXT_display_color_table,
  WGL_EXT_extensions_string,
  WGL_EXT_make_current_read,
  WGL_EXT_multisample,
  WGL_EXT_pbuffer,
  WGL_EXT_pixel_format,
  WGL_EXT_swap_control,
  WGL_I3D_digital_video_control,
  WGL_I3D_gamma,
  WGL_I3D_genlock,
  WGL_I3D_image_buffer,
  WGL_I3D_swap_frame_lock,
  WGL_I3D_swap_frame_usage: Boolean;

const
  // GL_VERSION_1_1
  GL_ACCUM                                           = $0100;
  GL_LOAD                                            = $0101;
  GL_RETURN                                          = $0102;
  GL_MULT                                            = $0103;
  GL_ADD                                             = $0104;
  GL_NEVER                                           = $0200;
{  GL_LESS                                            = $0201;
  GL_EQUAL                                           = $0202;
  GL_LEQUAL                                          = $0203;
  GL_GREATER                                         = $0204;
  GL_NOTEQUAL                                        = $0205;
  GL_GEQUAL                                          = $0206;}
  GL_ALWAYS                                          = $0207;
  GL_CURRENT_BIT                                     = $00000001;
  GL_POINT_BIT                                       = $00000002;
  GL_LINE_BIT                                        = $00000004;
  GL_POLYGON_BIT                                     = $00000008;
  GL_POLYGON_STIPPLE_BIT                             = $00000010;
  GL_PIXEL_MODE_BIT                                  = $00000020;
  GL_LIGHTING_BIT                                    = $00000040;
  GL_FOG_BIT                                         = $00000080;
//  GL_DEPTH_BUFFER_BIT                                = $00000100;
//  GL_ACCUM_BUFFER_BIT                                = $00000200;
//  GL_STENCIL_BUFFER_BIT                              = $00000400;
  GL_VIEWPORT_BIT                                    = $00000800;
  GL_TRANSFORM_BIT                                   = $00001000;
  GL_ENABLE_BIT                                      = $00002000;
//  GL_COLOR_BUFFER_BIT                                = $00004000;
  GL_HINT_BIT                                        = $00008000;
  GL_EVAL_BIT                                        = $00010000;
  GL_LIST_BIT                                        = $00020000;
  GL_TEXTURE_BIT                                     = $00040000;
  GL_SCISSOR_BIT                                     = $00080000;
  GL_ALL_ATTRIB_BITS                                 = $000fffff;
{  GL_POINTS                                          = $0000;
  GL_LINES                                           = $0001;
  GL_LINE_LOOP                                       = $0002;
  GL_LINE_STRIP                                      = $0003;
  GL_TRIANGLES                                       = $0004;
  GL_TRIANGLE_STRIP                                  = $0005;
  GL_TRIANGLE_FAN                                    = $0006;
  GL_QUADS                                           = $0007;
  GL_QUAD_STRIP                                      = $0008;
  GL_POLYGON                                         = $0009;}
{  GL_ZERO                                            = 0;
  GL_ONE                                             = 1;
  GL_SRC_COLOR                                       = $0300;
  GL_ONE_MINUS_SRC_COLOR                             = $0301;
  GL_SRC_ALPHA                                       = $0302;
  GL_ONE_MINUS_SRC_ALPHA                             = $0303;
  GL_DST_ALPHA                                       = $0304;
  GL_ONE_MINUS_DST_ALPHA                             = $0305;
  GL_DST_COLOR                                       = $0306;
  GL_ONE_MINUS_DST_COLOR                             = $0307;
  GL_SRC_ALPHA_SATURATE                              = $0308;}
  GL_TRUE                                            = 1;
  GL_FALSE                                           = 0;
  GL_CLIP_PLANE0                                     = $3000;
  GL_CLIP_PLANE1                                     = $3001;
  GL_CLIP_PLANE2                                     = $3002;
  GL_CLIP_PLANE3                                     = $3003;
  GL_CLIP_PLANE4                                     = $3004;
  GL_CLIP_PLANE5                                     = $3005;
  GL_BYTE                                            = $1400;
  GL_UNSIGNED_BYTE                                   = $1401;
  GL_SHORT                                           = $1402;
  GL_UNSIGNED_SHORT                                  = $1403;
  GL_INT                                             = $1404;
  GL_UNSIGNED_INT                                    = $1405;
  GL_FLOAT                                           = $1406;
  GL_2_BYTES                                         = $1407;
  GL_3_BYTES                                         = $1408;
  GL_4_BYTES                                         = $1409;
  GL_DOUBLE                                          = $140A;
  GL_NONE                                            = 0;
  GL_FRONT_LEFT                                      = $0400;
  GL_FRONT_RIGHT                                     = $0401;
  GL_BACK_LEFT                                       = $0402;
  GL_BACK_RIGHT                                      = $0403;
  GL_FRONT                                           = $0404;
  GL_BACK                                            = $0405;
  GL_LEFT                                            = $0406;
  GL_RIGHT                                           = $0407;
  GL_FRONT_AND_BACK                                  = $0408;
  GL_AUX0                                            = $0409;
  GL_AUX1                                            = $040A;
  GL_AUX2                                            = $040B;
  GL_AUX3                                            = $040C;
  GL_NO_ERROR                                        = 0;
  GL_INVALID_ENUM                                    = $0500;
  GL_INVALID_VALUE                                   = $0501;
  GL_INVALID_OPERATION                               = $0502;
  GL_STACK_OVERFLOW                                  = $0503;
  GL_STACK_UNDERFLOW                                 = $0504;
  GL_OUT_OF_MEMORY                                   = $0505;
  GL_2D                                              = $0600;
  GL_3D                                              = $0601;
  GL_3D_COLOR                                        = $0602;
  GL_3D_COLOR_TEXTURE                                = $0603;
  GL_4D_COLOR_TEXTURE                                = $0604;
  GL_PASS_THROUGH_TOKEN                              = $0700;
  GL_POINT_TOKEN                                     = $0701;
  GL_LINE_TOKEN                                      = $0702;
  GL_POLYGON_TOKEN                                   = $0703;
  GL_BITMAP_TOKEN                                    = $0704;
  GL_DRAW_PIXEL_TOKEN                                = $0705;
  GL_COPY_PIXEL_TOKEN                                = $0706;
  GL_LINE_RESET_TOKEN                                = $0707;
  GL_EXP                                             = $0800;
  GL_EXP2                                            = $0801;
  GL_CW                                              = $0900;
  GL_CCW                                             = $0901;
  GL_COEFF                                           = $0A00;
  GL_ORDER                                           = $0A01;
  GL_DOMAIN                                          = $0A02;
  GL_CURRENT_COLOR                                   = $0B00;
  GL_CURRENT_INDEX                                   = $0B01;
  GL_CURRENT_NORMAL                                  = $0B02;
  GL_CURRENT_TEXTURE_COORDS                          = $0B03;
  GL_CURRENT_RASTER_COLOR                            = $0B04;
  GL_CURRENT_RASTER_INDEX                            = $0B05;
  GL_CURRENT_RASTER_TEXTURE_COORDS                   = $0B06;
  GL_CURRENT_RASTER_POSITION                         = $0B07;
  GL_CURRENT_RASTER_POSITION_VALID                   = $0B08;
  GL_CURRENT_RASTER_DISTANCE                         = $0B09;
  GL_POINT_SMOOTH                                    = $0B10;
  GL_POINT_SIZE                                      = $0B11;
  GL_POINT_SIZE_RANGE                                = $0B12;
  GL_POINT_SIZE_GRANULARITY                          = $0B13;
  GL_LINE_SMOOTH                                     = $0B20;
  GL_LINE_WIDTH                                      = $0B21;
  GL_LINE_WIDTH_RANGE                                = $0B22;
  GL_LINE_WIDTH_GRANULARITY                          = $0B23;
  GL_LINE_STIPPLE                                    = $0B24;
  GL_LINE_STIPPLE_PATTERN                            = $0B25;
  GL_LINE_STIPPLE_REPEAT                             = $0B26;
  GL_LIST_MODE                                       = $0B30;
  GL_MAX_LIST_NESTING                                = $0B31;
  GL_LIST_BASE                                       = $0B32;
  GL_LIST_INDEX                                      = $0B33;
  GL_POLYGON_MODE                                    = $0B40;
  GL_POLYGON_SMOOTH                                  = $0B41;
  GL_POLYGON_STIPPLE                                 = $0B42;
  GL_EDGE_FLAG                                       = $0B43;
  GL_CULL_FACE                                       = $0B44;
  GL_CULL_FACE_MODE                                  = $0B45;
  GL_FRONT_FACE                                      = $0B46;
  GL_LIGHTING                                        = $0B50;
  GL_LIGHT_MODEL_LOCAL_VIEWER                        = $0B51;
  GL_LIGHT_MODEL_TWO_SIDE                            = $0B52;
  GL_LIGHT_MODEL_AMBIENT                             = $0B53;
  GL_SHADE_MODEL                                     = $0B54;
  GL_COLOR_MATERIAL_FACE                             = $0B55;
  GL_COLOR_MATERIAL_PARAMETER                        = $0B56;
  GL_COLOR_MATERIAL                                  = $0B57;
  GL_FOG                                             = $0B60;
  GL_FOG_INDEX                                       = $0B61;
  GL_FOG_DENSITY                                     = $0B62;
  GL_FOG_START                                       = $0B63;
  GL_FOG_END                                         = $0B64;
  GL_FOG_MODE                                        = $0B65;
  GL_FOG_COLOR                                       = $0B66;
  GL_DEPTH_RANGE                                     = $0B70;
  GL_DEPTH_TEST                                      = $0B71;
  GL_DEPTH_WRITEMASK                                 = $0B72;
  GL_DEPTH_CLEAR_VALUE                               = $0B73;
  GL_DEPTH_FUNC                                      = $0B74;
  GL_ACCUM_CLEAR_VALUE                               = $0B80;
  GL_STENCIL_TEST                                    = $0B90;
  GL_STENCIL_CLEAR_VALUE                             = $0B91;
  GL_STENCIL_FUNC                                    = $0B92;
  GL_STENCIL_VALUE_MASK                              = $0B93;
  GL_STENCIL_FAIL                                    = $0B94;
  GL_STENCIL_PASS_DEPTH_FAIL                         = $0B95;
  GL_STENCIL_PASS_DEPTH_PASS                         = $0B96;
  GL_STENCIL_REF                                     = $0B97;
  GL_STENCIL_WRITEMASK                               = $0B98;
  GL_MATRIX_MODE                                     = $0BA0;
  GL_NORMALIZE                                       = $0BA1;
  GL_VIEWPORT                                        = $0BA2;
  GL_MODELVIEW_STACK_DEPTH                           = $0BA3;
  GL_PROJECTION_STACK_DEPTH                          = $0BA4;
  GL_TEXTURE_STACK_DEPTH                             = $0BA5;
  GL_MODELVIEW_MATRIX                                = $0BA6;
  GL_PROJECTION_MATRIX                               = $0BA7;
  GL_TEXTURE_MATRIX                                  = $0BA8;
  GL_ATTRIB_STACK_DEPTH                              = $0BB0;
  GL_CLIENT_ATTRIB_STACK_DEPTH                       = $0BB1;
  GL_ALPHA_TEST                                      = $0BC0;
  GL_ALPHA_TEST_FUNC                                 = $0BC1;
  GL_ALPHA_TEST_REF                                  = $0BC2;
  GL_DITHER                                          = $0BD0;
  GL_BLEND_DST                                       = $0BE0;
  GL_BLEND_SRC                                       = $0BE1;
  GL_BLEND                                           = $0BE2;
  GL_LOGIC_OP_MODE                                   = $0BF0;
  GL_INDEX_LOGIC_OP                                  = $0BF1;
  GL_COLOR_LOGIC_OP                                  = $0BF2;
  GL_AUX_BUFFERS                                     = $0C00;
  GL_DRAW_BUFFER                                     = $0C01;
  GL_READ_BUFFER                                     = $0C02;
  GL_SCISSOR_BOX                                     = $0C10;
  GL_SCISSOR_TEST                                    = $0C11;
  GL_INDEX_CLEAR_VALUE                               = $0C20;
  GL_INDEX_WRITEMASK                                 = $0C21;
  GL_COLOR_CLEAR_VALUE                               = $0C22;
  GL_COLOR_WRITEMASK                                 = $0C23;
  GL_INDEX_MODE                                      = $0C30;
  GL_RGBA_MODE                                       = $0C31;
  GL_DOUBLEBUFFER                                    = $0C32;
  GL_STEREO                                          = $0C33;
  GL_RENDER_MODE                                     = $0C40;
  GL_PERSPECTIVE_CORRECTION_HINT                     = $0C50;
  GL_POINT_SMOOTH_HINT                               = $0C51;
  GL_LINE_SMOOTH_HINT                                = $0C52;
  GL_POLYGON_SMOOTH_HINT                             = $0C53;
  GL_FOG_HINT                                        = $0C54;
  GL_TEXTURE_GEN_S                                   = $0C60;
  GL_TEXTURE_GEN_T                                   = $0C61;
  GL_TEXTURE_GEN_R                                   = $0C62;
  GL_TEXTURE_GEN_Q                                   = $0C63;
  GL_PIXEL_MAP_I_TO_I                                = $0C70;
  GL_PIXEL_MAP_S_TO_S                                = $0C71;
  GL_PIXEL_MAP_I_TO_R                                = $0C72;
  GL_PIXEL_MAP_I_TO_G                                = $0C73;
  GL_PIXEL_MAP_I_TO_B                                = $0C74;
  GL_PIXEL_MAP_I_TO_A                                = $0C75;
  GL_PIXEL_MAP_R_TO_R                                = $0C76;
  GL_PIXEL_MAP_G_TO_G                                = $0C77;
  GL_PIXEL_MAP_B_TO_B                                = $0C78;
  GL_PIXEL_MAP_A_TO_A                                = $0C79;
  GL_PIXEL_MAP_I_TO_I_SIZE                           = $0CB0;
  GL_PIXEL_MAP_S_TO_S_SIZE                           = $0CB1;
  GL_PIXEL_MAP_I_TO_R_SIZE                           = $0CB2;
  GL_PIXEL_MAP_I_TO_G_SIZE                           = $0CB3;
  GL_PIXEL_MAP_I_TO_B_SIZE                           = $0CB4;
  GL_PIXEL_MAP_I_TO_A_SIZE                           = $0CB5;
  GL_PIXEL_MAP_R_TO_R_SIZE                           = $0CB6;
  GL_PIXEL_MAP_G_TO_G_SIZE                           = $0CB7;
  GL_PIXEL_MAP_B_TO_B_SIZE                           = $0CB8;
  GL_PIXEL_MAP_A_TO_A_SIZE                           = $0CB9;
  GL_UNPACK_SWAP_BYTES                               = $0CF0;
  GL_UNPACK_LSB_FIRST                                = $0CF1;
  GL_UNPACK_ROW_LENGTH                               = $0CF2;
  GL_UNPACK_SKIP_ROWS                                = $0CF3;
  GL_UNPACK_SKIP_PIXELS                              = $0CF4;
  GL_UNPACK_ALIGNMENT                                = $0CF5;
  GL_PACK_SWAP_BYTES                                 = $0D00;
  GL_PACK_LSB_FIRST                                  = $0D01;
  GL_PACK_ROW_LENGTH                                 = $0D02;
  GL_PACK_SKIP_ROWS                                  = $0D03;
  GL_PACK_SKIP_PIXELS                                = $0D04;
  GL_PACK_ALIGNMENT                                  = $0D05;
  GL_MAP_COLOR                                       = $0D10;
  GL_MAP_STENCIL                                     = $0D11;
  GL_INDEX_SHIFT                                     = $0D12;
  GL_INDEX_OFFSET                                    = $0D13;
  GL_RED_SCALE                                       = $0D14;
  GL_RED_BIAS                                        = $0D15;
  GL_ZOOM_X                                          = $0D16;
  GL_ZOOM_Y                                          = $0D17;
  GL_GREEN_SCALE                                     = $0D18;
  GL_GREEN_BIAS                                      = $0D19;
  GL_BLUE_SCALE                                      = $0D1A;
  GL_BLUE_BIAS                                       = $0D1B;
  GL_ALPHA_SCALE                                     = $0D1C;
  GL_ALPHA_BIAS                                      = $0D1D;
  GL_DEPTH_SCALE                                     = $0D1E;
  GL_DEPTH_BIAS                                      = $0D1F;
  GL_MAX_EVAL_ORDER                                  = $0D30;
  GL_MAX_LIGHTS                                      = $0D31;
  GL_MAX_CLIP_PLANES                                 = $0D32;
  GL_MAX_TEXTURE_SIZE                                = $0D33;
  GL_MAX_PIXEL_MAP_TABLE                             = $0D34;
  GL_MAX_ATTRIB_STACK_DEPTH                          = $0D35;
  GL_MAX_MODELVIEW_STACK_DEPTH                       = $0D36;
  GL_MAX_NAME_STACK_DEPTH                            = $0D37;
  GL_MAX_PROJECTION_STACK_DEPTH                      = $0D38;
  GL_MAX_TEXTURE_STACK_DEPTH                         = $0D39;
  GL_MAX_VIEWPORT_DIMS                               = $0D3A;
  GL_MAX_CLIENT_ATTRIB_STACK_DEPTH                   = $0D3B;
  GL_SUBPIXEL_BITS                                   = $0D50;
  GL_INDEX_BITS                                      = $0D51;
  GL_RED_BITS                                        = $0D52;
  GL_GREEN_BITS                                      = $0D53;
  GL_BLUE_BITS                                       = $0D54;
  GL_ALPHA_BITS                                      = $0D55;
  GL_DEPTH_BITS                                      = $0D56;
  GL_STENCIL_BITS                                    = $0D57;
  GL_ACCUM_RED_BITS                                  = $0D58;
  GL_ACCUM_GREEN_BITS                                = $0D59;
  GL_ACCUM_BLUE_BITS                                 = $0D5A;
  GL_ACCUM_ALPHA_BITS                                = $0D5B;
  GL_NAME_STACK_DEPTH                                = $0D70;
  GL_AUTO_NORMAL                                     = $0D80;
  GL_MAP1_COLOR_4                                    = $0D90;
  GL_MAP1_INDEX                                      = $0D91;
  GL_MAP1_NORMAL                                     = $0D92;
  GL_MAP1_TEXTURE_COORD_1                            = $0D93;
  GL_MAP1_TEXTURE_COORD_2                            = $0D94;
  GL_MAP1_TEXTURE_COORD_3                            = $0D95;
  GL_MAP1_TEXTURE_COORD_4                            = $0D96;
  GL_MAP1_VERTEX_3                                   = $0D97;
  GL_MAP1_VERTEX_4                                   = $0D98;
  GL_MAP2_COLOR_4                                    = $0DB0;
  GL_MAP2_INDEX                                      = $0DB1;
  GL_MAP2_NORMAL                                     = $0DB2;
  GL_MAP2_TEXTURE_COORD_1                            = $0DB3;
  GL_MAP2_TEXTURE_COORD_2                            = $0DB4;
  GL_MAP2_TEXTURE_COORD_3                            = $0DB5;
  GL_MAP2_TEXTURE_COORD_4                            = $0DB6;
  GL_MAP2_VERTEX_3                                   = $0DB7;
  GL_MAP2_VERTEX_4                                   = $0DB8;
  GL_MAP1_GRID_DOMAIN                                = $0DD0;
  GL_MAP1_GRID_SEGMENTS                              = $0DD1;
  GL_MAP2_GRID_DOMAIN                                = $0DD2;
  GL_MAP2_GRID_SEGMENTS                              = $0DD3;
  GL_TEXTURE_1D                                      = $0DE0;
  GL_TEXTURE_2D                                      = $0DE1;
  GL_FEEDBACK_BUFFER_POINTER                         = $0DF0;
  GL_FEEDBACK_BUFFER_SIZE                            = $0DF1;
  GL_FEEDBACK_BUFFER_TYPE                            = $0DF2;
  GL_SELECTION_BUFFER_POINTER                        = $0DF3;
  GL_SELECTION_BUFFER_SIZE                           = $0DF4;
  GL_TEXTURE_WIDTH                                   = $1000;
  GL_TEXTURE_HEIGHT                                  = $1001;
  GL_TEXTURE_INTERNAL_FORMAT                         = $1003;
  GL_TEXTURE_BORDER_COLOR                            = $1004;
  GL_TEXTURE_BORDER                                  = $1005;
  GL_DONT_CARE                                       = $1100;
  GL_FASTEST                                         = $1101;
  GL_NICEST                                          = $1102;
  GL_LIGHT0                                          = $4000;
  GL_LIGHT1                                          = $4001;
  GL_LIGHT2                                          = $4002;
  GL_LIGHT3                                          = $4003;
  GL_LIGHT4                                          = $4004;
  GL_LIGHT5                                          = $4005;
  GL_LIGHT6                                          = $4006;
  GL_LIGHT7                                          = $4007;
  GL_AMBIENT                                         = $1200;
  GL_DIFFUSE                                         = $1201;
  GL_SPECULAR                                        = $1202;
  GL_POSITION                                        = $1203;
  GL_SPOT_DIRECTION                                  = $1204;
  GL_SPOT_                                   = $1205;
  GL_SPOT_CUTOFF                                     = $1206;
  GL_CONSTANT_ATTENUATION                            = $1207;
  GL_LINEAR_ATTENUATION                              = $1208;
  GL_QUADRATIC_ATTENUATION                           = $1209;
  GL_COMPILE                                         = $1300;
  GL_COMPILE_AND_EXECUTE                             = $1301;
  GL_CLEAR                                           = $1500;
  GL_AND                                             = $1501;
  GL_AND_REVERSE                                     = $1502;
  GL_COPY                                            = $1503;
  GL_AND_INVERTED                                    = $1504;
  GL_NOOP                                            = $1505;
  GL_XOR                                             = $1506;
  GL_OR                                              = $1507;
  GL_NOR                                             = $1508;
  GL_EQUIV                                           = $1509;
  GL_INVERT                                          = $150A;
  GL_OR_REVERSE                                      = $150B;
  GL_COPY_INVERTED                                   = $150C;
  GL_OR_INVERTED                                     = $150D;
  GL_NAND                                            = $150E;
  GL_SET                                             = $150F;
  GL_EMISSION                                        = $1600;
  GL_SHININESS                                       = $1601;
  GL_AMBIENT_AND_DIFFUSE                             = $1602;
  GL_COLOR_INDEXES                                   = $1603;
  GL_MODELVIEW                                       = $1700;
  GL_PROJECTION                                      = $1701;
  GL_TEXTURE                                         = $1702;
  GL_COLOR                                           = $1800;
  GL_DEPTH                                           = $1801;
  GL_STENCIL                                         = $1802;
  GL_COLOR_INDEX                                     = $1900;
  GL_STENCIL_INDEX                                   = $1901;
  GL_DEPTH_COMPONENT                                 = $1902;
  GL_RED                                             = $1903;
  GL_GREEN                                           = $1904;
  GL_BLUE                                            = $1905;
  GL_ALPHA                                           = $1906;
//  GL_RGB                                             = $1907;
//  GL_RGBA                                            = $1908;
//  GL_LUMINANCE                                       = $1909;
  GL_LUMINANCE_ALPHA                                 = $190A;
  GL_BITMAP                                          = $1A00;
  GL_POINT                                           = $1B00;
  GL_LINE                                            = $1B01;
  GL_FILL                                            = $1B02;
  GL_RENDER                                          = $1C00;
  GL_FEEDBACK                                        = $1C01;
  GL_SELECT                                          = $1C02;
  GL_FLAT                                            = $1D00;
  GL_SMOOTH                                          = $1D01;
  GL_KEEP                                            = $1E00;
  GL_REPLACE                                         = $1E01;
  GL_INCR                                            = $1E02;
  GL_DECR                                            = $1E03;
  GL_VENDOR                                          = $1F00;
  GL_RENDERER                                        = $1F01;
  GL_VERSION                                         = $1F02;
  GL_EXTENSIONS                                      = $1F03;
  GL_S                                               = $2000;
  GL_T                                               = $2001;
  GL_R                                               = $2002;
  GL_Q                                               = $2003;
  GL_MODULATE                                        = $2100;
  GL_DECAL                                           = $2101;
  GL_TEXTURE_ENV_MODE                                = $2200;
  GL_TEXTURE_ENV_COLOR                               = $2201;
  GL_TEXTURE_ENV                                     = $2300;
  GL_EYE_LINEAR                                      = $2400;
  GL_OBJECT_LINEAR                                   = $2401;
  GL_SPHERE_MAP                                      = $2402;
  GL_TEXTURE_GEN_MODE                                = $2500;
  GL_OBJECT_PLANE                                    = $2501;
  GL_EYE_PLANE                                       = $2502;
  GL_NEAREST                                         = $2600;
  GL_LINEAR                                          = $2601;
  GL_NEAREST_MIPMAP_NEAREST                          = $2700;
  GL_LINEAR_MIPMAP_NEAREST                           = $2701;
  GL_NEAREST_MIPMAP_LINEAR                           = $2702;
  GL_LINEAR_MIPMAP_LINEAR                            = $2703;
  GL_TEXTURE_MAG_FILTER                              = $2800;
  GL_TEXTURE_MIN_FILTER                              = $2801;
  GL_TEXTURE_WRAP_S                                  = $2802;
  GL_TEXTURE_WRAP_T                                  = $2803;
  GL_CLAMP                                           = $2900;
  GL_REPEAT                                          = $2901;
  GL_CLIENT_PIXEL_STORE_BIT                          = $00000001;
  GL_CLIENT_VERTEX_ARRAY_BIT                         = $00000002;
  GL_CLIENT_ALL_ATTRIB_BITS                          = $ffffffff;
  GL_POLYGON_OFFSET_FACTOR                           = $8038;
  GL_POLYGON_OFFSET_UNITS                            = $2A00;
  GL_POLYGON_OFFSET_POINT                            = $2A01;
  GL_POLYGON_OFFSET_LINE                             = $2A02;
  GL_POLYGON_OFFSET_FILL                             = $8037;
  GL_ALPHA4                                          = $803B;
  GL_ALPHA8                                          = $803C;
  GL_ALPHA12                                         = $803D;
  GL_ALPHA16                                         = $803E;
  GL_LUMINANCE4                                      = $803F;
  GL_LUMINANCE8                                      = $8040;
  GL_LUMINANCE12                                     = $8041;
  GL_LUMINANCE16                                     = $8042;
  GL_LUMINANCE4_ALPHA4                               = $8043;
  GL_LUMINANCE6_ALPHA2                               = $8044;
  GL_LUMINANCE8_ALPHA8                               = $8045;
  GL_LUMINANCE12_ALPHA4                              = $8046;
  GL_LUMINANCE12_ALPHA12                             = $8047;
  GL_LUMINANCE16_ALPHA16                             = $8048;
  GL_INTENSITY                                       = $8049;
  GL_INTENSITY4                                      = $804A;
  GL_INTENSITY8                                      = $804B;
  GL_INTENSITY12                                     = $804C;
  GL_INTENSITY16                                     = $804D;
  GL_R3_G3_B2                                        = $2A10;
  GL_RGB4                                            = $804F;
  GL_RGB5                                            = $8050;
  GL_RGB8                                            = $8051;
  GL_RGB10                                           = $8052;
  GL_RGB12                                           = $8053;
  GL_RGB16                                           = $8054;
  GL_RGBA2                                           = $8055;
  GL_RGBA4                                           = $8056;
  GL_RGB5_A1                                         = $8057;
  GL_RGBA8                                           = $8058;
  GL_RGB10_A2                                        = $8059;
  GL_RGBA12                                          = $805A;
  GL_RGBA16                                          = $805B;
  GL_TEXTURE_RED_SIZE                                = $805C;
  GL_TEXTURE_GREEN_SIZE                              = $805D;
  GL_TEXTURE_BLUE_SIZE                               = $805E;
  GL_TEXTURE_ALPHA_SIZE                              = $805F;
  GL_TEXTURE_LUMINANCE_SIZE                          = $8060;
  GL_TEXTURE_INTENSITY_SIZE                          = $8061;
  GL_PROXY_TEXTURE_1D                                = $8063;
  GL_PROXY_TEXTURE_2D                                = $8064;
  GL_TEXTURE_PRIORITY                                = $8066;
  GL_TEXTURE_RESIDENT                                = $8067;
  GL_TEXTURE_BINDING_1D                              = $8068;
  GL_TEXTURE_BINDING_2D                              = $8069;
  GL_VERTEX_ARRAY                                    = $8074;
  GL_NORMAL_ARRAY                                    = $8075;
  GL_COLOR_ARRAY                                     = $8076;
  GL_INDEX_ARRAY                                     = $8077;
  GL_TEXTURE_COORD_ARRAY                             = $8078;
  GL_EDGE_FLAG_ARRAY                                 = $8079;
  GL_VERTEX_ARRAY_SIZE                               = $807A;
  GL_VERTEX_ARRAY_TYPE                               = $807B;
  GL_VERTEX_ARRAY_STRIDE                             = $807C;
  GL_NORMAL_ARRAY_TYPE                               = $807E;
  GL_NORMAL_ARRAY_STRIDE                             = $807F;
  GL_COLOR_ARRAY_SIZE                                = $8081;
  GL_COLOR_ARRAY_TYPE                                = $8082;
  GL_COLOR_ARRAY_STRIDE                              = $8083;
  GL_INDEX_ARRAY_TYPE                                = $8085;
  GL_INDEX_ARRAY_STRIDE                              = $8086;
  GL_TEXTURE_COORD_ARRAY_SIZE                        = $8088;
  GL_TEXTURE_COORD_ARRAY_TYPE                        = $8089;
  GL_TEXTURE_COORD_ARRAY_STRIDE                      = $808A;
  GL_EDGE_FLAG_ARRAY_STRIDE                          = $808C;
  GL_VERTEX_ARRAY_POINTER                            = $808E;
  GL_NORMAL_ARRAY_POINTER                            = $808F;
  GL_COLOR_ARRAY_POINTER                             = $8090;
  GL_INDEX_ARRAY_POINTER                             = $8091;
  GL_TEXTURE_COORD_ARRAY_POINTER                     = $8092;
  GL_EDGE_FLAG_ARRAY_POINTER                         = $8093;
  GL_V2F                                             = $2A20;
  GL_V3F                                             = $2A21;
  GL_C4UB_V2F                                        = $2A22;
  GL_C4UB_V3F                                        = $2A23;
  GL_C3F_V3F                                         = $2A24;
  GL_N3F_V3F                                         = $2A25;
  GL_C4F_N3F_V3F                                     = $2A26;
  GL_T2F_V3F                                         = $2A27;
  GL_T4F_V4F                                         = $2A28;
  GL_T2F_C4UB_V3F                                    = $2A29;
  GL_T2F_C3F_V3F                                     = $2A2A;
  GL_T2F_N3F_V3F                                     = $2A2B;
  GL_T2F_C4F_N3F_V3F                                 = $2A2C;
  GL_T4F_C4F_N3F_V4F                                 = $2A2D;

  GL_LOGIC_OP                                        = GL_INDEX_LOGIC_OP;
  GL_TEXTURE_COMPONENTS                              = GL_TEXTURE_INTERNAL_FORMAT;

  // GL_VERSION_1_2
  GL_UNSIGNED_BYTE_3_3_2                             = $8032;
  GL_UNSIGNED_SHORT_4_4_4_4                          = $8033;
  GL_UNSIGNED_SHORT_5_5_5_1                          = $8034;
  GL_UNSIGNED_INT_8_8_8_8                            = $8035;
  GL_UNSIGNED_INT_10_10_10_2                         = $8036;
  GL_RESCALE_NORMAL                                  = $803A;
  GL_TEXTURE_BINDING_3D                              = $806A;
  GL_PACK_SKIP_IMAGES                                = $806B;
  GL_PACK_IMAGE_HEIGHT                               = $806C;
  GL_UNPACK_SKIP_IMAGES                              = $806D;
  GL_UNPACK_IMAGE_HEIGHT                             = $806E;
  GL_TEXTURE_3D                                      = $806F;
  GL_PROXY_TEXTURE_3D                                = $8070;
  GL_TEXTURE_DEPTH                                   = $8071;
  GL_TEXTURE_WRAP_R                                  = $8072;
  GL_MAX_3D_TEXTURE_SIZE                             = $8073;
  GL_UNSIGNED_BYTE_2_3_3_REV                         = $8362;
  GL_UNSIGNED_SHORT_5_6_5                            = $8363;
  GL_UNSIGNED_SHORT_5_6_5_REV                        = $8364;
  GL_UNSIGNED_SHORT_4_4_4_4_REV                      = $8365;
  GL_UNSIGNED_SHORT_1_5_5_5_REV                      = $8366;
  GL_UNSIGNED_INT_8_8_8_8_REV                        = $8367;
  GL_UNSIGNED_INT_2_10_10_10_REV                     = $8368;
//  GL_BGR                                             = $80E0;
//  GL_BGRA                                            = $80E1;
  GL_MAX_ELEMENTS_VERTICES                           = $80E8;
  GL_MAX_ELEMENTS_INDICES                            = $80E9;
  GL_CLAMP_TO_EDGE                                   = $812F;
  GL_TEXTURE_MIN_LOD                                 = $813A;
  GL_TEXTURE_MAX_LOD                                 = $813B;
  GL_TEXTURE_BASE_LEVEL                              = $813C;
  GL_TEXTURE_MAX_LEVEL                               = $813D;
  GL_LIGHT_MODEL_COLOR_CONTROL                       = $81F8;
  GL_SINGLE_COLOR                                    = $81F9;
  GL_SEPARATE_SPECULAR_COLOR                         = $81FA;
  GL_SMOOTH_POINT_SIZE_RANGE                         = $0B12;
  GL_SMOOTH_POINT_SIZE_GRANULARITY                   = $0B13;
  GL_SMOOTH_LINE_WIDTH_RANGE                         = $0B22;
  GL_SMOOTH_LINE_WIDTH_GRANULARITY                   = $0B23;
  GL_ALIASED_POINT_SIZE_RANGE                        = $846D;
  GL_ALIASED_LINE_WIDTH_RANGE                        = $846E;

  // GL_VERSION_1_3
  GL_TEXTURE0                                        = $84C0;
  GL_TEXTURE1                                        = $84C1;
  GL_TEXTURE2                                        = $84C2;
  GL_TEXTURE3                                        = $84C3;
  GL_TEXTURE4                                        = $84C4;
  GL_TEXTURE5                                        = $84C5;
  GL_TEXTURE6                                        = $84C6;
  GL_TEXTURE7                                        = $84C7;
  GL_TEXTURE8                                        = $84C8;
  GL_TEXTURE9                                        = $84C9;
  GL_TEXTURE10                                       = $84CA;
  GL_TEXTURE11                                       = $84CB;
  GL_TEXTURE12                                       = $84CC;
  GL_TEXTURE13                                       = $84CD;
  GL_TEXTURE14                                       = $84CE;
  GL_TEXTURE15                                       = $84CF;
  GL_TEXTURE16                                       = $84D0;
  GL_TEXTURE17                                       = $84D1;
  GL_TEXTURE18                                       = $84D2;
  GL_TEXTURE19                                       = $84D3;
  GL_TEXTURE20                                       = $84D4;
  GL_TEXTURE21                                       = $84D5;
  GL_TEXTURE22                                       = $84D6;
  GL_TEXTURE23                                       = $84D7;
  GL_TEXTURE24                                       = $84D8;
  GL_TEXTURE25                                       = $84D9;
  GL_TEXTURE26                                       = $84DA;
  GL_TEXTURE27                                       = $84DB;
  GL_TEXTURE28                                       = $84DC;
  GL_TEXTURE29                                       = $84DD;
  GL_TEXTURE30                                       = $84DE;
  GL_TEXTURE31                                       = $84DF;
  GL_ACTIVE_TEXTURE                                  = $84E0;
  GL_CLIENT_ACTIVE_TEXTURE                           = $84E1;
  GL_MAX_TEXTURE_UNITS                               = $84E2;
  GL_TRANSPOSE_MODELVIEW_MATRIX                      = $84E3;
  GL_TRANSPOSE_PROJECTION_MATRIX                     = $84E4;
  GL_TRANSPOSE_TEXTURE_MATRIX                        = $84E5;
  GL_TRANSPOSE_COLOR_MATRIX                          = $84E6;
  GL_MULTISAMPLE                                     = $809D;
  GL_SAMPLE_ALPHA_TO_COVERAGE                        = $809E;
  GL_SAMPLE_ALPHA_TO_ONE                             = $809F;
  GL_SAMPLE_COVERAGE                                 = $80A0;
  GL_SAMPLE_BUFFERS                                  = $80A8;
  GL_SAMPLES                                         = $80A9;
  GL_SAMPLE_COVERAGE_VALUE                           = $80AA;
  GL_SAMPLE_COVERAGE_INVERT                          = $80AB;
  GL_MULTISAMPLE_BIT                                 = $20000000;
  GL_NORMAL_MAP                                      = $8511;
  GL_REFLECTION_MAP                                  = $8512;
  GL_TEXTURE_CUBE_MAP                                = $8513;
  GL_TEXTURE_BINDING_CUBE_MAP                        = $8514;
  GL_TEXTURE_CUBE_MAP_POSITIVE_X                     = $8515;
  GL_TEXTURE_CUBE_MAP_NEGATIVE_X                     = $8516;
  GL_TEXTURE_CUBE_MAP_POSITIVE_Y                     = $8517;
  GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                     = $8518;
  GL_TEXTURE_CUBE_MAP_POSITIVE_Z                     = $8519;
  GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                     = $851A;
  GL_PROXY_TEXTURE_CUBE_MAP                          = $851B;
  GL_MAX_CUBE_MAP_TEXTURE_SIZE                       = $851C;
  GL_COMPRESSED_ALPHA                                = $84E9;
  GL_COMPRESSED_LUMINANCE                            = $84EA;
  GL_COMPRESSED_LUMINANCE_ALPHA                      = $84EB;
  GL_COMPRESSED_INTENSITY                            = $84EC;
  GL_COMPRESSED_RGB                                  = $84ED;
  GL_COMPRESSED_RGBA                                 = $84EE;
  GL_TEXTURE_COMPRESSION_HINT                        = $84EF;
  GL_TEXTURE_COMPRESSED_IMAGE_SIZE                   = $86A0;
  GL_TEXTURE_COMPRESSED                              = $86A1;
  GL_NUM_COMPRESSED_TEXTURE_FORMATS                  = $86A2;
  GL_COMPRESSED_TEXTURE_FORMATS                      = $86A3;
  GL_CLAMP_TO_BORDER                                 = $812D;
  GL_CLAMP_TO_BORDER_SGIS                            = $812D;
  GL_COMBINE                                         = $8570;
  GL_COMBINE_RGB                                     = $8571;
  GL_COMBINE_ALPHA                                   = $8572;
  GL_SOURCE0_RGB                                     = $8580;
  GL_SOURCE1_RGB                                     = $8581;
  GL_SOURCE2_RGB                                     = $8582;
  GL_SOURCE0_ALPHA                                   = $8588;
  GL_SOURCE1_ALPHA                                   = $8589;
  GL_SOURCE2_ALPHA                                   = $858A;
  GL_OPERAND0_RGB                                    = $8590;
  GL_OPERAND1_RGB                                    = $8591;
  GL_OPERAND2_RGB                                    = $8592;
  GL_OPERAND0_ALPHA                                  = $8598;
  GL_OPERAND1_ALPHA                                  = $8599;
  GL_OPERAND2_ALPHA                                  = $859A;
  GL_RGB_SCALE                                       = $8573;
  GL_ADD_SIGNED                                      = $8574;
  GL_INTERPOLATE                                     = $8575;
  GL_SUBTRACT                                        = $84E7;
  GL_CONSTANT                                        = $8576;
  GL_PRIMARY_COLOR                                   = $8577;
  GL_PREVIOUS                                        = $8578;
  GL_DOT3_RGB                                        = $86AE;
  GL_DOT3_RGBA                                       = $86AF;

  // GL_VERSION_1_4
  GL_BLEND_DST_RGB                                   = $80C8;
  GL_BLEND_SRC_RGB                                   = $80C9;
  GL_BLEND_DST_ALPHA                                 = $80CA;
  GL_BLEND_SRC_ALPHA                                 = $80CB;
  GL_POINT_SIZE_MIN                                  = $8126;
  GL_POINT_SIZE_MAX                                  = $8127;
  GL_POINT_FADE_THRESHOLD_SIZE                       = $8128;
  GL_POINT_DISTANCE_ATTENUATION                      = $8129;
  GL_GENERATE_MIPMAP                                 = $8191;
  GL_GENERATE_MIPMAP_HINT                            = $8192;
  GL_DEPTH_COMPONENT16                               = $81A5;
  GL_DEPTH_COMPONENT24                               = $81A6;
  GL_DEPTH_COMPONENT32                               = $81A7;
  GL_MIRRORED_REPEAT                                 = $8370;
  GL_FOG_COORDINATE_SOURCE                           = $8450;
  GL_FOG_COORD_SOURCE                                = $8450;
  GL_FOG_COORDINATE                                  = $8451;
  GL_FOG_COORD                                       = $8451;
  GL_FRAGMENT_DEPTH                                  = $8452;
  GL_CURRENT_FOG_COORDINATE                          = $8453;
  GL_CURRENT_FOG_COORD                               = $8453;
  GL_FOG_COORDINATE_ARRAY_TYPE                       = $8454;
  GL_FOG_COORD_ARRAY_TYPE                            = $8454;
  GL_FOG_COORDINATE_ARRAY_STRIDE                     = $8455;
  GL_FOG_COORD_ARRAY_STRIDE                          = $8455;
  GL_FOG_COORDINATE_ARRAY_POINTER                    = $8456;
  GL_FOG_COORD_ARRAY_POINTER                         = $8456;
  GL_FOG_COORDINATE_ARRAY                            = $8457;
  GL_FOG_COORD_ARRAY                                 = $8457;
  GL_COLOR_SUM                                       = $8458;
  GL_CURRENT_SECONDARY_COLOR                         = $8459;
  GL_SECONDARY_COLOR_ARRAY_SIZE                      = $845A;
  GL_SECONDARY_COLOR_ARRAY_TYPE                      = $845B;
  GL_SECONDARY_COLOR_ARRAY_STRIDE                    = $845C;
  GL_SECONDARY_COLOR_ARRAY_POINTER                   = $845D;
  GL_SECONDARY_COLOR_ARRAY                           = $845E;
  GL_MAX_TEXTURE_LOD_BIAS                            = $84FD;
  GL_TEXTURE_FILTER_CONTROL                          = $8500;
  GL_TEXTURE_LOD_BIAS                                = $8501;
  GL_INCR_WRAP                                       = $8507;
  GL_DECR_WRAP                                       = $8508;
  GL_TEXTURE_DEPTH_SIZE                              = $884A;
  GL_DEPTH_TEXTURE_MODE                              = $884B;
  GL_TEXTURE_COMPARE_MODE                            = $884C;
  GL_TEXTURE_COMPARE_FUNC                            = $884D;
  GL_COMPARE_R_TO_TEXTURE                            = $884E;

  // GL_ARB_depth_texture
  GL_DEPTH_COMPONENT16_ARB                           = $81A5;
  GL_DEPTH_COMPONENT24_ARB                           = $81A6;
  GL_DEPTH_COMPONENT32_ARB                           = $81A7;
  GL_TEXTURE_DEPTH_SIZE_ARB                          = $884A;
  GL_DEPTH_TEXTURE_MODE_ARB                          = $884B;

  // GL_ARB_fragment_program
  GL_FRAGMENT_PROGRAM_ARB                            = $8804;
  GL_PROGRAM_ALU_INSTRUCTIONS_ARB                    = $8805;
  GL_PROGRAM_TEX_INSTRUCTIONS_ARB                    = $8806;
  GL_PROGRAM_TEX_INDIRECTIONS_ARB                    = $8807;
  GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB             = $8808;
  GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB             = $8809;
  GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB             = $880A;
  GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB                = $880B;
  GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB                = $880C;
  GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB                = $880D;
  GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB         = $880E;
  GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB         = $880F;
  GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB         = $8810;
  GL_MAX_TEXTURE_COORDS_ARB                          = $8871;
  GL_MAX_TEXTURE_IMAGE_UNITS_ARB                     = $8872;

  // GL_ARB_imaging
  GL_CONSTANT_COLOR                                  = $8001;
  GL_ONE_MINUS_CONSTANT_COLOR                        = $8002;
  GL_CONSTANT_ALPHA                                  = $8003;
  GL_ONE_MINUS_CONSTANT_ALPHA                        = $8004;
  GL_BLEND_COLOR                                     = $8005;
  GL_FUNC_ADD                                        = $8006;
  GL_MIN                                             = $8007;
  GL_MAX                                             = $8008;
  GL_BLEND_EQUATION                                  = $8009;
  GL_FUNC_SUBTRACT                                   = $800A;
  GL_FUNC_REVERSE_SUBTRACT                           = $800B;
  GL_CONVOLUTION_1D                                  = $8010;
  GL_CONVOLUTION_2D                                  = $8011;
  GL_SEPARABLE_2D                                    = $8012;
  GL_CONVOLUTION_BORDER_MODE                         = $8013;
  GL_CONVOLUTION_FILTER_SCALE                        = $8014;
  GL_CONVOLUTION_FILTER_BIAS                         = $8015;
  GL_REDUCE                                          = $8016;
  GL_CONVOLUTION_FORMAT                              = $8017;
  GL_CONVOLUTION_WIDTH                               = $8018;
  GL_CONVOLUTION_HEIGHT                              = $8019;
  GL_MAX_CONVOLUTION_WIDTH                           = $801A;
  GL_MAX_CONVOLUTION_HEIGHT                          = $801B;
  GL_POST_CONVOLUTION_RED_SCALE                      = $801C;
  GL_POST_CONVOLUTION_GREEN_SCALE                    = $801D;
  GL_POST_CONVOLUTION_BLUE_SCALE                     = $801E;
  GL_POST_CONVOLUTION_ALPHA_SCALE                    = $801F;
  GL_POST_CONVOLUTION_RED_BIAS                       = $8020;
  GL_POST_CONVOLUTION_GREEN_BIAS                     = $8021;
  GL_POST_CONVOLUTION_BLUE_BIAS                      = $8022;
  GL_POST_CONVOLUTION_ALPHA_BIAS                     = $8023;
  GL_HISTOGRAM                                       = $8024;
  GL_PROXY_HISTOGRAM                                 = $8025;
  GL_HISTOGRAM_WIDTH                                 = $8026;
  GL_HISTOGRAM_FORMAT                                = $8027;
  GL_HISTOGRAM_RED_SIZE                              = $8028;
  GL_HISTOGRAM_GREEN_SIZE                            = $8029;
  GL_HISTOGRAM_BLUE_SIZE                             = $802A;
  GL_HISTOGRAM_ALPHA_SIZE                            = $802B;
  GL_HISTOGRAM_LUMINANCE_SIZE                        = $802C;
  GL_HISTOGRAM_SINK                                  = $802D;
  GL_MINMAX                                          = $802E;
  GL_MINMAX_FORMAT                                   = $802F;
  GL_MINMAX_SINK                                     = $8030;
  GL_TABLE_TOO_LARGE                                 = $8031;
  GL_COLOR_MATRIX                                    = $80B1;
  GL_COLOR_MATRIX_STACK_DEPTH                        = $80B2;
  GL_MAX_COLOR_MATRIX_STACK_DEPTH                    = $80B3;
  GL_POST_COLOR_MATRIX_RED_SCALE                     = $80B4;
  GL_POST_COLOR_MATRIX_GREEN_SCALE                   = $80B5;
  GL_POST_COLOR_MATRIX_BLUE_SCALE                    = $80B6;
  GL_POST_COLOR_MATRIX_ALPHA_SCALE                   = $80B7;
  GL_POST_COLOR_MATRIX_RED_BIAS                      = $80B8;
  GL_POST_COLOR_MATRIX_GREEN_BIAS                    = $80B9;
  GL_POST_COLOR_MATRIX_BLUE_BIAS                     = $80BA;
  GL_POST_COLOR_MATRIX_ALPHA_BIAS                    = $80BB;
  GL_COLOR_TABLE                                     = $80D0;
  GL_POST_CONVOLUTION_COLOR_TABLE                    = $80D1;
  GL_POST_COLOR_MATRIX_COLOR_TABLE                   = $80D2;
  GL_PROXY_COLOR_TABLE                               = $80D3;
  GL_PROXY_POST_CONVOLUTION_COLOR_TABLE              = $80D4;
  GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE             = $80D5;
  GL_COLOR_TABLE_SCALE                               = $80D6;
  GL_COLOR_TABLE_BIAS                                = $80D7;
  GL_COLOR_TABLE_FORMAT                              = $80D8;
  GL_COLOR_TABLE_WIDTH                               = $80D9;
  GL_COLOR_TABLE_RED_SIZE                            = $80DA;
  GL_COLOR_TABLE_GREEN_SIZE                          = $80DB;
  GL_COLOR_TABLE_BLUE_SIZE                           = $80DC;
  GL_COLOR_TABLE_ALPHA_SIZE                          = $80DD;
  GL_COLOR_TABLE_LUMINANCE_SIZE                      = $80DE;
  GL_COLOR_TABLE_INTENSITY_SIZE                      = $80DF;
  GL_CONSTANT_BORDER                                 = $8151;
  GL_REPLICATE_BORDER                                = $8153;
  GL_CONVOLUTION_BORDER_COLOR                        = $8154;

  // GL_ARB_matrix_palette
  GL_MATRIX_PALETTE_ARB                              = $8840;
  GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB              = $8841;
  GL_MAX_PALETTE_MATRICES_ARB                        = $8842;
  GL_CURRENT_PALETTE_MATRIX_ARB                      = $8843;
  GL_MATRIX_INDEX_ARRAY_ARB                          = $8844;
  GL_CURRENT_MATRIX_INDEX_ARB                        = $8845;
  GL_MATRIX_INDEX_ARRAY_SIZE_ARB                     = $8846;
  GL_MATRIX_INDEX_ARRAY_TYPE_ARB                     = $8847;
  GL_MATRIX_INDEX_ARRAY_STRIDE_ARB                   = $8848;
  GL_MATRIX_INDEX_ARRAY_POINTER_ARB                  = $8849;

  // GL_ARB_multisample
  GL_MULTISAMPLE_ARB                                 = $809D;
  GL_SAMPLE_ALPHA_TO_COVERAGE_ARB                    = $809E;
  GL_SAMPLE_ALPHA_TO_ONE_ARB                         = $809F;
  GL_SAMPLE_COVERAGE_ARB                             = $80A0;
  GL_SAMPLE_BUFFERS_ARB                              = $80A8;
  GL_SAMPLES_ARB                                     = $80A9;
  GL_SAMPLE_COVERAGE_VALUE_ARB                       = $80AA;
  GL_SAMPLE_COVERAGE_INVERT_ARB                      = $80AB;
  GL_MULTISAMPLE_BIT_ARB                             = $20000000;

  // GL_ARB_multitexture
  GL_TEXTURE0_ARB                                    = $84C0;
  GL_TEXTURE1_ARB                                    = $84C1;
  GL_TEXTURE2_ARB                                    = $84C2;
  GL_TEXTURE3_ARB                                    = $84C3;
  GL_TEXTURE4_ARB                                    = $84C4;
  GL_TEXTURE5_ARB                                    = $84C5;
  GL_TEXTURE6_ARB                                    = $84C6;
  GL_TEXTURE7_ARB                                    = $84C7;
  GL_TEXTURE8_ARB                                    = $84C8;
  GL_TEXTURE9_ARB                                    = $84C9;
  GL_TEXTURE10_ARB                                   = $84CA;
  GL_TEXTURE11_ARB                                   = $84CB;
  GL_TEXTURE12_ARB                                   = $84CC;
  GL_TEXTURE13_ARB                                   = $84CD;
  GL_TEXTURE14_ARB                                   = $84CE;
  GL_TEXTURE15_ARB                                   = $84CF;
  GL_TEXTURE16_ARB                                   = $84D0;
  GL_TEXTURE17_ARB                                   = $84D1;
  GL_TEXTURE18_ARB                                   = $84D2;
  GL_TEXTURE19_ARB                                   = $84D3;
  GL_TEXTURE20_ARB                                   = $84D4;
  GL_TEXTURE21_ARB                                   = $84D5;
  GL_TEXTURE22_ARB                                   = $84D6;
  GL_TEXTURE23_ARB                                   = $84D7;
  GL_TEXTURE24_ARB                                   = $84D8;
  GL_TEXTURE25_ARB                                   = $84D9;
  GL_TEXTURE26_ARB                                   = $84DA;
  GL_TEXTURE27_ARB                                   = $84DB;
  GL_TEXTURE28_ARB                                   = $84DC;
  GL_TEXTURE29_ARB                                   = $84DD;
  GL_TEXTURE30_ARB                                   = $84DE;
  GL_TEXTURE31_ARB                                   = $84DF;
  GL_ACTIVE_TEXTURE_ARB                              = $84E0;
  GL_CLIENT_ACTIVE_TEXTURE_ARB                       = $84E1;
  GL_MAX_TEXTURE_UNITS_ARB                           = $84E2;

  // GL_ARB_point_parameters
  GL_POINT_SIZE_MIN_ARB                              = $8126;
  GL_POINT_SIZE_MAX_ARB                              = $8127;
  GL_POINT_FADE_THRESHOLD_SIZE_ARB                   = $8128;
  GL_POINT_DISTANCE_ATTENUATION_ARB                  = $8129;

  // GL_ARB_shadow
  GL_TEXTURE_COMPARE_MODE_ARB                        = $884C;
  GL_TEXTURE_COMPARE_FUNC_ARB                        = $884D;
  GL_COMPARE_R_TO_TEXTURE_ARB                        = $884E;

  // GL_ARB_shadow_ambient
  GL_TEXTURE_COMPARE_FAIL_VALUE_ARB                  = $80BF;

  // GL_ARB_texture_border_clamp
  GL_CLAMP_TO_BORDER_ARB                             = $812D;

  // GL_ARB_texture_compression
  GL_COMPRESSED_ALPHA_ARB                            = $84E9;
  GL_COMPRESSED_LUMINANCE_ARB                        = $84EA;
  GL_COMPRESSED_LUMINANCE_ALPHA_ARB                  = $84EB;
  GL_COMPRESSED_INTENSITY_ARB                        = $84EC;
  GL_COMPRESSED_RGB_ARB                              = $84ED;
  GL_COMPRESSED_RGBA_ARB                             = $84EE;
  GL_TEXTURE_COMPRESSION_HINT_ARB                    = $84EF;
  GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB               = $86A0;
  GL_TEXTURE_COMPRESSED_ARB                          = $86A1;
  GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB              = $86A2;
  GL_COMPRESSED_TEXTURE_FORMATS_ARB                  = $86A3;

  // GL_ARB_texture_cube_map
  GL_NORMAL_MAP_ARB                                  = $8511;
  GL_REFLECTION_MAP_ARB                              = $8512;
  GL_TEXTURE_CUBE_MAP_ARB                            = $8513;
  GL_TEXTURE_BINDING_CUBE_MAP_ARB                    = $8514;
  GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                 = $8515;
  GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                 = $8516;
  GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                 = $8517;
  GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                 = $8518;
  GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                 = $8519;
  GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                 = $851A;
  GL_PROXY_TEXTURE_CUBE_MAP_ARB                      = $851B;
  GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB                   = $851C;

  // GL_ARB_texture_env_combine
  GL_COMBINE_ARB                                     = $8570;
  GL_COMBINE_RGB_ARB                                 = $8571;
  GL_COMBINE_ALPHA_ARB                               = $8572;
  GL_SOURCE0_RGB_ARB                                 = $8580;
  GL_SOURCE1_RGB_ARB                                 = $8581;
  GL_SOURCE2_RGB_ARB                                 = $8582;
  GL_SOURCE0_ALPHA_ARB                               = $8588;
  GL_SOURCE1_ALPHA_ARB                               = $8589;
  GL_SOURCE2_ALPHA_ARB                               = $858A;
  GL_OPERAND0_RGB_ARB                                = $8590;
  GL_OPERAND1_RGB_ARB                                = $8591;
  GL_OPERAND2_RGB_ARB                                = $8592;
  GL_OPERAND0_ALPHA_ARB                              = $8598;
  GL_OPERAND1_ALPHA_ARB                              = $8599;
  GL_OPERAND2_ALPHA_ARB                              = $859A;
  GL_RGB_SCALE_ARB                                   = $8573;
  GL_ADD_SIGNED_ARB                                  = $8574;
  GL_INTERPOLATE_ARB                                 = $8575;
  GL_SUBTRACT_ARB                                    = $84E7;
  GL_CONSTANT_ARB                                    = $8576;
  GL_PRIMARY_COLOR_ARB                               = $8577;
  GL_PREVIOUS_ARB                                    = $8578;

  // GL_ARB_texture_env_dot3
  GL_DOT3_RGB_ARB                                    = $86AE;
  GL_DOT3_RGBA_ARB                                   = $86AF;

  // GL_ARB_texture_mirrored_repeat
  GL_MIRRORED_REPEAT_ARB                             = $8370;

  // GL_ARB_transpose_matrix
  GL_TRANSPOSE_MODELVIEW_MATRIX_ARB                  = $84E3;
  GL_TRANSPOSE_PROJECTION_MATRIX_ARB                 = $84E4;
  GL_TRANSPOSE_TEXTURE_MATRIX_ARB                    = $84E5;
  GL_TRANSPOSE_COLOR_MATRIX_ARB                      = $84E6;

  // GL_ARB_vertex_blend
  GL_MAX_VERTEX_UNITS_ARB                            = $86A4;
  GL_ACTIVE_VERTEX_UNITS_ARB                         = $86A5;
  GL_WEIGHT_SUM_UNITY_ARB                            = $86A6;
  GL_VERTEX_BLEND_ARB                                = $86A7;
  GL_CURRENT_WEIGHT_ARB                              = $86A8;
  GL_WEIGHT_ARRAY_TYPE_ARB                           = $86A9;
  GL_WEIGHT_ARRAY_STRIDE_ARB                         = $86AA;
  GL_WEIGHT_ARRAY_SIZE_ARB                           = $86AB;
  GL_WEIGHT_ARRAY_POINTER_ARB                        = $86AC;
  GL_WEIGHT_ARRAY_ARB                                = $86AD;
  GL_MODELVIEW0_ARB                                  = $1700;
  GL_MODELVIEW1_ARB                                  = $850A;
  GL_MODELVIEW2_ARB                                  = $8722;
  GL_MODELVIEW3_ARB                                  = $8723;
  GL_MODELVIEW4_ARB                                  = $8724;
  GL_MODELVIEW5_ARB                                  = $8725;
  GL_MODELVIEW6_ARB                                  = $8726;
  GL_MODELVIEW7_ARB                                  = $8727;
  GL_MODELVIEW8_ARB                                  = $8728;
  GL_MODELVIEW9_ARB                                  = $8729;
  GL_MODELVIEW10_ARB                                 = $872A;
  GL_MODELVIEW11_ARB                                 = $872B;
  GL_MODELVIEW12_ARB                                 = $872C;
  GL_MODELVIEW13_ARB                                 = $872D;
  GL_MODELVIEW14_ARB                                 = $872E;
  GL_MODELVIEW15_ARB                                 = $872F;
  GL_MODELVIEW16_ARB                                 = $8730;
  GL_MODELVIEW17_ARB                                 = $8731;
  GL_MODELVIEW18_ARB                                 = $8732;
  GL_MODELVIEW19_ARB                                 = $8733;
  GL_MODELVIEW20_ARB                                 = $8734;
  GL_MODELVIEW21_ARB                                 = $8735;
  GL_MODELVIEW22_ARB                                 = $8736;
  GL_MODELVIEW23_ARB                                 = $8737;
  GL_MODELVIEW24_ARB                                 = $8738;
  GL_MODELVIEW25_ARB                                 = $8739;
  GL_MODELVIEW26_ARB                                 = $873A;
  GL_MODELVIEW27_ARB                                 = $873B;
  GL_MODELVIEW28_ARB                                 = $873C;
  GL_MODELVIEW29_ARB                                 = $873D;
  GL_MODELVIEW30_ARB                                 = $873E;
  GL_MODELVIEW31_ARB                                 = $873F;

  // GL_ARB_vertex_buffer_object
  GL_BUFFER_SIZE_ARB                                 = $8764;
  GL_BUFFER_USAGE_ARB                                = $8765;
  GL_ARRAY_BUFFER_ARB                                = $8892;
  GL_ELEMENT_ARRAY_BUFFER_ARB                        = $8893;
  GL_ARRAY_BUFFER_BINDING_ARB                        = $8894;
  GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB                = $8895;
  GL_VERTEX_ARRAY_BUFFER_BINDING_ARB                 = $8896;
  GL_NORMAL_ARRAY_BUFFER_BINDING_ARB                 = $8897;
  GL_COLOR_ARRAY_BUFFER_BINDING_ARB                  = $8898;
  GL_INDEX_ARRAY_BUFFER_BINDING_ARB                  = $8899;
  GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB          = $889A;
  GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB              = $889B;
  GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB        = $889C;
  GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB         = $889D;
  GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB                 = $889E;
  GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB          = $889F;
  GL_READ_ONLY_ARB                                   = $88B8;
  GL_WRITE_ONLY_ARB                                  = $88B9;
  GL_READ_WRITE_ARB                                  = $88BA;
  GL_BUFFER_ACCESS_ARB                               = $88BB;
  GL_BUFFER_MAPPED_ARB                               = $88BC;
  GL_BUFFER_MAP_POINTER_ARB                          = $88BD;
  GL_STREAM_DRAW_ARB                                 = $88E0;
  GL_STREAM_READ_ARB                                 = $88E1;
  GL_STREAM_COPY_ARB                                 = $88E2;
  GL_STATIC_DRAW_ARB                                 = $88E4;
  GL_STATIC_READ_ARB                                 = $88E5;
  GL_STATIC_COPY_ARB                                 = $88E6;
  GL_DYNAMIC_DRAW_ARB                                = $88E8;
  GL_DYNAMIC_READ_ARB                                = $88E9;
  GL_DYNAMIC_COPY_ARB                                = $88EA;

  // GL 1.5 ARB less version
  GL_BUFFER_SIZE                                 = $8764;
  GL_BUFFER_USAGE                                = $8765;
  GL_ARRAY_BUFFER                                = $8892;
  GL_ELEMENT_ARRAY_BUFFER                        = $8893;
  GL_ARRAY_BUFFER_BINDING                        = $8894;
  GL_ELEMENT_ARRAY_BUFFER_BINDING                = $8895;
  GL_VERTEX_ARRAY_BUFFER_BINDING                 = $8896;
  GL_NORMAL_ARRAY_BUFFER_BINDING                 = $8897;
  GL_COLOR_ARRAY_BUFFER_BINDING                  = $8898;
  GL_INDEX_ARRAY_BUFFER_BINDING                  = $8899;
  GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING          = $889A;
  GL_EDGE_FLAG_ARRAY_BUFFER_BINDING              = $889B;
  GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING        = $889C;
  GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING         = $889D;
  GL_WEIGHT_ARRAY_BUFFER_BINDING                 = $889E;
  GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING          = $889F;
  GL_READ_ONLY                                   = $88B8;
  GL_WRITE_ONLY                                  = $88B9;
  GL_READ_WRITE                                  = $88BA;
  GL_BUFFER_ACCESS                               = $88BB;
  GL_BUFFER_MAPPED                               = $88BC;
  GL_BUFFER_MAP_POINTER                          = $88BD;
  GL_STREAM_DRAW                                 = $88E0;
  GL_STREAM_READ                                 = $88E1;
  GL_STREAM_COPY                                 = $88E2;
  GL_STATIC_DRAW                                 = $88E4;
  GL_STATIC_READ                                 = $88E5;
  GL_STATIC_COPY                                 = $88E6;
  GL_DYNAMIC_DRAW                                = $88E8;
  GL_DYNAMIC_READ                                = $88E9;
  GL_DYNAMIC_COPY                                = $88EA;

  // GL_ARB_vertex_program
  GL_COLOR_SUM_ARB                                   = $8458;
  GL_VERTEX_PROGRAM_ARB                              = $8620;
  GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB                 = $8622;
  GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                    = $8623;
  GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB                  = $8624;
  GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                    = $8625;
  GL_CURRENT_VERTEX_ATTRIB_ARB                       = $8626;
  GL_PROGRAM_LENGTH_ARB                              = $8627;
  GL_PROGRAM_STRING_ARB                              = $8628;
  GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB              = $862E;
  GL_MAX_PROGRAM_MATRICES_ARB                        = $862F;
  GL_CURRENT_MATRIX_STACK_DEPTH_ARB                  = $8640;
  GL_CURRENT_MATRIX_ARB                              = $8641;
  GL_VERTEX_PROGRAM_POINT_SIZE_ARB                   = $8642;
  GL_VERTEX_PROGRAM_TWO_SIDE_ARB                     = $8643;
  GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB                 = $8645;
  GL_PROGRAM_ERROR_POSITION_ARB                      = $864B;
  GL_PROGRAM_BINDING_ARB                             = $8677;
  GL_MAX_VERTEX_ATTRIBS_ARB                          = $8869;
  GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB              = $886A;
  GL_PROGRAM_ERROR_STRING_ARB                        = $8874;
  GL_PROGRAM_FORMAT_ASCII_ARB                        = $8875;
  GL_PROGRAM_FORMAT_ARB                              = $8876;
  GL_PROGRAM_INSTRUCTIONS_ARB                        = $88A0;
  GL_MAX_PROGRAM_INSTRUCTIONS_ARB                    = $88A1;
  GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB                 = $88A2;
  GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB             = $88A3;
  GL_PROGRAM_TEMPORARIES_ARB                         = $88A4;
  GL_MAX_PROGRAM_TEMPORARIES_ARB                     = $88A5;
  GL_PROGRAM_NATIVE_TEMPORARIES_ARB                  = $88A6;
  GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB              = $88A7;
  GL_PROGRAM_PARAMETERS_ARB                          = $88A8;
  GL_MAX_PROGRAM_PARAMETERS_ARB                      = $88A9;
  GL_PROGRAM_NATIVE_PARAMETERS_ARB                   = $88AA;
  GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB               = $88AB;
  GL_PROGRAM_ATTRIBS_ARB                             = $88AC;
  GL_MAX_PROGRAM_ATTRIBS_ARB                         = $88AD;
  GL_PROGRAM_NATIVE_ATTRIBS_ARB                      = $88AE;
  GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB                  = $88AF;
  GL_PROGRAM_ADDRESS_REGISTERS_ARB                   = $88B0;
  GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB               = $88B1;
  GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB            = $88B2;
  GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB        = $88B3;
  GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB                = $88B4;
  GL_MAX_PROGRAM_ENV_PARAMETERS_ARB                  = $88B5;
  GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB                 = $88B6;
  GL_TRANSPOSE_CURRENT_MATRIX_ARB                    = $88B7;
  GL_MATRIX0_ARB                                     = $88C0;
  GL_MATRIX1_ARB                                     = $88C1;
  GL_MATRIX2_ARB                                     = $88C2;
  GL_MATRIX3_ARB                                     = $88C3;
  GL_MATRIX4_ARB                                     = $88C4;
  GL_MATRIX5_ARB                                     = $88C5;
  GL_MATRIX6_ARB                                     = $88C6;
  GL_MATRIX7_ARB                                     = $88C7;
  GL_MATRIX8_ARB                                     = $88C8;
  GL_MATRIX9_ARB                                     = $88C9;
  GL_MATRIX10_ARB                                    = $88CA;
  GL_MATRIX11_ARB                                    = $88CB;
  GL_MATRIX12_ARB                                    = $88CC;
  GL_MATRIX13_ARB                                    = $88CD;
  GL_MATRIX14_ARB                                    = $88CE;
  GL_MATRIX15_ARB                                    = $88CF;
  GL_MATRIX16_ARB                                    = $88D0;
  GL_MATRIX17_ARB                                    = $88D1;
  GL_MATRIX18_ARB                                    = $88D2;
  GL_MATRIX19_ARB                                    = $88D3;
  GL_MATRIX20_ARB                                    = $88D4;
  GL_MATRIX21_ARB                                    = $88D5;
  GL_MATRIX22_ARB                                    = $88D6;
  GL_MATRIX23_ARB                                    = $88D7;
  GL_MATRIX24_ARB                                    = $88D8;
  GL_MATRIX25_ARB                                    = $88D9;
  GL_MATRIX26_ARB                                    = $88DA;
  GL_MATRIX27_ARB                                    = $88DB;
  GL_MATRIX28_ARB                                    = $88DC;
  GL_MATRIX29_ARB                                    = $88DD;
  GL_MATRIX30_ARB                                    = $88DE;
  GL_MATRIX31_ARB                                    = $88DF;

  // GL_S3_s3tc
  GL_RGB_S3TC                                        = $83A0;
  GL_RGB4_S3TC                                       = $83A1;
  GL_RGBA_S3TC                                       = $83A2;
  GL_RGBA4_S3TC                                      = $83A3;

  // GL_SGIS_detail_texture
  GL_DETAIL_TEXTURE_2D_SGIS                          = $8095;
  GL_DETAIL_TEXTURE_2D_BINDING_SGIS                  = $8096;
  GL_LINEAR_DETAIL_SGIS                              = $8097;
  GL_LINEAR_DETAIL_ALPHA_SGIS                        = $8098;
  GL_LINEAR_DETAIL_COLOR_SGIS                        = $8099;
  GL_DETAIL_TEXTURE_LEVEL_SGIS                       = $809A;
  GL_DETAIL_TEXTURE_MODE_SGIS                        = $809B;
  GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS                 = $809C;

  // GL_SGIS_fog_function
  GL_FOG_FUNC_SGIS                                   = $812A;
  GL_FOG_FUNC_POINTS_SGIS                            = $812B;
  GL_MAX_FOG_FUNC_POINTS_SGIS                        = $812C;

  // GL_SGIS_generate_mipmap
  GL_GENERATE_MIPMAP_SGIS                            = $8191;
  GL_GENERATE_MIPMAP_HINT_SGIS                       = $8192;

  // GL_SGIS_multisample
  GL_MULTISAMPLE_SGIS                                = $809D;
  GL_SAMPLE_ALPHA_TO_MASK_SGIS                       = $809E;
  GL_SAMPLE_ALPHA_TO_ONE_SGIS                        = $809F;
  GL_SAMPLE_MASK_SGIS                                = $80A0;
  GL_1PASS_SGIS                                      = $80A1;
  GL_2PASS_0_SGIS                                    = $80A2;
  GL_2PASS_1_SGIS                                    = $80A3;
  GL_4PASS_0_SGIS                                    = $80A4;
  GL_4PASS_1_SGIS                                    = $80A5;
  GL_4PASS_2_SGIS                                    = $80A6;
  GL_4PASS_3_SGIS                                    = $80A7;
  GL_SAMPLE_BUFFERS_SGIS                             = $80A8;
  GL_SAMPLES_SGIS                                    = $80A9;
  GL_SAMPLE_MASK_VALUE_SGIS                          = $80AA;
  GL_SAMPLE_MASK_INVERT_SGIS                         = $80AB;
  GL_SAMPLE_PATTERN_SGIS                             = $80AC;

  // GL_SGIS_pixel_texture
  GL_PIXEL_TEXTURE_SGIS                              = $8353;
  GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS                  = $8354;
  GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS                = $8355;
  GL_PIXEL_GROUP_COLOR_SGIS                          = $8356;

  // GL_SGIS_point_line_texgen
  GL_EYE_DISTANCE_TO_POINT_SGIS                      = $81F0;
  GL_OBJECT_DISTANCE_TO_POINT_SGIS                   = $81F1;
  GL_EYE_DISTANCE_TO_LINE_SGIS                       = $81F2;
  GL_OBJECT_DISTANCE_TO_LINE_SGIS                    = $81F3;
  GL_EYE_POINT_SGIS                                  = $81F4;
  GL_OBJECT_POINT_SGIS                               = $81F5;
  GL_EYE_LINE_SGIS                                   = $81F6;
  GL_OBJECT_LINE_SGIS                                = $81F7;

  // GL_SGIS_point_parameters
  GL_POINT_SIZE_MIN_SGIS                             = $8126;
  GL_POINT_SIZE_MAX_SGIS                             = $8127;
  GL_POINT_FADE_THRESHOLD_SIZE_SGIS                  = $8128;
  GL_DISTANCE_ATTENUATION_SGIS                       = $8129;

  // GL_SGIS_sharpen_texture
  GL_LINEAR_SHARPEN_SGIS                             = $80AD;
  GL_LINEAR_SHARPEN_ALPHA_SGIS                       = $80AE;
  GL_LINEAR_SHARPEN_COLOR_SGIS                       = $80AF;
  GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS                = $80B0;

  // GL_SGIS_texture4D
  GL_PACK_SKIP_VOLUMES_SGIS                          = $8130;
  GL_PACK_IMAGE_DEPTH_SGIS                           = $8131;
  GL_UNPACK_SKIP_VOLUMES_SGIS                        = $8132;
  GL_UNPACK_IMAGE_DEPTH_SGIS                         = $8133;
  GL_TEXTURE_4D_SGIS                                 = $8134;
  GL_PROXY_TEXTURE_4D_SGIS                           = $8135;
  GL_TEXTURE_4DSIZE_SGIS                             = $8136;
  GL_TEXTURE_WRAP_Q_SGIS                             = $8137;
  GL_MAX_4D_TEXTURE_SIZE_SGIS                        = $8138;
  GL_TEXTURE_4D_BINDING_SGIS                         = $814F;

  // GL_SGIS_texture_color_mask
  GL_TEXTURE_COLOR_WRITEMASK_SGIS                    = $81EF;

  // GL_SGIS_texture_edge_clamp
  GL_CLAMP_TO_EDGE_SGIS                              = $812F;

  // GL_SGIS_texture_filter4
  GL_FILTER4_SGIS                                    = $8146;
  GL_TEXTURE_FILTER4_SIZE_SGIS                       = $8147;

  // GL_SGIS_texture_lod
  GL_TEXTURE_MIN_LOD_SGIS                            = $813A;
  GL_TEXTURE_MAX_LOD_SGIS                            = $813B;
  GL_TEXTURE_BASE_LEVEL_SGIS                         = $813C;
  GL_TEXTURE_MAX_LEVEL_SGIS                          = $813D;

  // GL_SGIS_texture_select
  GL_DUAL_ALPHA4_SGIS                                = $8110;
  GL_DUAL_ALPHA8_SGIS                                = $8111;
  GL_DUAL_ALPHA12_SGIS                               = $8112;
  GL_DUAL_ALPHA16_SGIS                               = $8113;
  GL_DUAL_LUMINANCE4_SGIS                            = $8114;
  GL_DUAL_LUMINANCE8_SGIS                            = $8115;
  GL_DUAL_LUMINANCE12_SGIS                           = $8116;
  GL_DUAL_LUMINANCE16_SGIS                           = $8117;
  GL_DUAL_INTENSITY4_SGIS                            = $8118;
  GL_DUAL_INTENSITY8_SGIS                            = $8119;
  GL_DUAL_INTENSITY12_SGIS                           = $811A;
  GL_DUAL_INTENSITY16_SGIS                           = $811B;
  GL_DUAL_LUMINANCE_ALPHA4_SGIS                      = $811C;
  GL_DUAL_LUMINANCE_ALPHA8_SGIS                      = $811D;
  GL_QUAD_ALPHA4_SGIS                                = $811E;
  GL_QUAD_ALPHA8_SGIS                                = $811F;
  GL_QUAD_LUMINANCE4_SGIS                            = $8120;
  GL_QUAD_LUMINANCE8_SGIS                            = $8121;
  GL_QUAD_INTENSITY4_SGIS                            = $8122;
  GL_QUAD_INTENSITY8_SGIS                            = $8123;
  GL_DUAL_TEXTURE_SELECT_SGIS                        = $8124;
  GL_QUAD_TEXTURE_SELECT_SGIS                        = $8125;


  // GL_SGI_color_matrix
  GL_COLOR_MATRIX_SGI                                = $80B1;
  GL_COLOR_MATRIX_STACK_DEPTH_SGI                    = $80B2;
  GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI                = $80B3;
  GL_POST_COLOR_MATRIX_RED_SCALE_SGI                 = $80B4;
  GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI               = $80B5;
  GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI                = $80B6;
  GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI               = $80B7;
  GL_POST_COLOR_MATRIX_RED_BIAS_SGI                  = $80B8;
  GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI                = $80B9;
  GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI                 = $80BA;
  GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI                = $80BB;

  // GL_SGI_color_table
  GL_COLOR_TABLE_SGI                                 = $80D0;
  GL_POST_CONVOLUTION_COLOR_TABLE_SGI                = $80D1;
  GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI               = $80D2;
  GL_PROXY_COLOR_TABLE_SGI                           = $80D3;
  GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI          = $80D4;
  GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI         = $80D5;
  GL_COLOR_TABLE_SCALE_SGI                           = $80D6;
  GL_COLOR_TABLE_BIAS_SGI                            = $80D7;
  GL_COLOR_TABLE_FORMAT_SGI                          = $80D8;
  GL_COLOR_TABLE_WIDTH_SGI                           = $80D9;
  GL_COLOR_TABLE_RED_SIZE_SGI                        = $80DA;
  GL_COLOR_TABLE_GREEN_SIZE_SGI                      = $80DB;
  GL_COLOR_TABLE_BLUE_SIZE_SGI                       = $80DC;
  GL_COLOR_TABLE_ALPHA_SIZE_SGI                      = $80DD;
  GL_COLOR_TABLE_LUMINANCE_SIZE_SGI                  = $80DE;
  GL_COLOR_TABLE_INTENSITY_SIZE_SGI                  = $80DF;

  // GL_SGI_texture_color_table
  GL_TEXTURE_COLOR_TABLE_SGI                         = $80BC;
  GL_PROXY_TEXTURE_COLOR_TABLE_SGI                   = $80BD;

  // ===== OpenGL 1.5 ==========================================================
   // GL_ARB_vertex_shader                            OpenGL 1.5
  GL_VERTEX_SHADER_ARB                               = $8B31;
  GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB               = $8B4A;
  GL_MAX_VARYING_FLOATS_ARB                          = $8B4B;
  GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB              = $8B4C;
  GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB            = $8B4D;
  GL_OBJECT_ACTIVE_ATTRIBUTES_ARB                    = $8B89;
  GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB          = $8B8A;

  // GL_ARB_fragment_shader                          OpenGL 1.5
  GL_FRAGMENT_SHADER_ARB                             = $8B30;
  GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB             = $8B49;             // 1.4
  GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB             = $8B8B;             // 1.4

  // GL_ARB_occlusion_query                          OpenGL 1.5
  GL_SAMPLES_PASSED_ARB                              = $8914;
  GL_QUERY_COUNTER_BITS_ARB                          = $8864;
  GL_CURRENT_QUERY_ARB                               = $8865;
  GL_QUERY_RESULT_ARB                                = $8866;
  GL_QUERY_RESULT_AVAILABLE_ARB                      = $8867;

  // GL_ARB_occlusion_query ARB less version         OpenGL 1.5
  GL_SAMPLES_PASSED                                  = $8914;
  GL_QUERY_COUNTER_BITS                              = $8864;
  GL_CURRENT_QUERY                                   = $8865;
  GL_QUERY_RESULT                                    = $8866;
  GL_QUERY_RESULT_AVAILABLE                          = $8867;

  // GL_ARB_point_sprite                             OpenGL 1.5
  GL_POINT_SPRITE_ARB                                = $8861;
  GL_COORD_REPLACE_ARB                               = $8862;

  // GL_ARB_shading_language_100                     OpenGL 1.5
  GL_SHADING_LANGUAGE_VERSION_ARB                    = $8B8C;             // 1.4

  // GL_ARB_SHADER_OBJECTS                           OpenGL 1.5
  GL_PROGRAM_OBJECT_ARB                              = $8B40;

  GL_OBJECT_TYPE_ARB                                 = $8B4E;
  GL_OBJECT_SUBTYPE_ARB                              = $8B4F;
  GL_OBJECT_DELETE_STATUS_ARB                        = $8B80;
  GL_OBJECT_COMPILE_STATUS_ARB                       = $8B81;
  GL_OBJECT_LINK_STATUS_ARB                          = $8B82;
  GL_OBJECT_VALIDATE_STATUS_ARB                      = $8B83;
  GL_OBJECT_INFO_LOG_LENGTH_ARB                      = $8B84;
  GL_OBJECT_ATTACHED_OBJECTS_ARB                     = $8B85;
  GL_OBJECT_ACTIVE_UNIFORMS_ARB                      = $8B86;
  GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB            = $8B87;
  GL_OBJECT_SHADER_SOURCE_LENGTH_ARB                 = $8B88;

  GL_SHADER_OBJECT_ARB                               = $8B48;

  GL_FLOAT_VEC2_ARB                                  = $8B50;
  GL_FLOAT_VEC3_ARB                                  = $8B51;
  GL_FLOAT_VEC4_ARB                                  = $8B52;
  GL_INT_VEC2_ARB                                    = $8B53;
  GL_INT_VEC3_ARB                                    = $8B54;
  GL_INT_VEC4_ARB                                    = $8B55;
  GL_BOOL_ARB                                        = $8B56;
  GL_BOOL_VEC2_ARB                                   = $8B57;
  GL_BOOL_VEC3_ARB                                   = $8B58;
  GL_BOOL_VEC4_ARB                                   = $8B59;
  GL_FLOAT_MAT2_ARB                                  = $8B5A;
  GL_FLOAT_MAT3_ARB                                  = $8B5B;
  GL_FLOAT_MAT4_ARB                                  = $8B5C;

  // Update for glsl-specification 1.10
  GL_SAMPLER_1D_ARB                                  = $8B5D;             // 1.4
  GL_SAMPLER_2D_ARB                                  = $8B5E;             // 1.4
  GL_SAMPLER_3D_ARB                                  = $8B5F;             // 1.4
  GL_SAMPLER_CUBE_ARB                                = $8B60;             // 1.4
  GL_SAMPLER_1D_SHADOW_ARB                           = $8B61;             // 1.4
  GL_SAMPLER_2D_SHADOW_ARB                           = $8B62;             // 1.4
  GL_SAMPLER_2D_RECT_ARB                             = $8B63;             // 1.4
  GL_SAMPLER_2D_RECT_SHADOW_ARB                      = $8B64;             // 1.4

  // ===== OpenGL 1.5 = End ====================================================

  // WGL_ARB_buffer_region
  WGL_FRONT_COLOR_BUFFER_BIT_ARB                     = $00000001;
  WGL_BACK_COLOR_BUFFER_BIT_ARB                      = $00000002;
  WGL_DEPTH_BUFFER_BIT_ARB                           = $00000004;
  WGL_STENCIL_BUFFER_BIT_ARB                         = $00000008;

  // WGL_ARB_make_current_read
  ERROR_INVALID_PIXEL_TYPE_ARB                       = $2043;
  ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB             = $2054;

  // WGL_ARB_multisample
  WGL_SAMPLE_BUFFERS_ARB                             = $2041;
  WGL_SAMPLES_ARB                                    = $2042;

  // WGL_ARB_pbuffer
  WGL_DRAW_TO_PBUFFER_ARB                            = $202D;
  WGL_MAX_PBUFFER_PIXELS_ARB                         = $202E;
  WGL_MAX_PBUFFER_WIDTH_ARB                          = $202F;
  WGL_MAX_PBUFFER_HEIGHT_ARB                         = $2030;
  WGL_PBUFFER_LARGEST_ARB                            = $2033;
  WGL_PBUFFER_WIDTH_ARB                              = $2034;
  WGL_PBUFFER_HEIGHT_ARB                             = $2035;
  WGL_PBUFFER_LOST_ARB                               = $2036;

  // WGL_ARB_pixel_format
  WGL_NUMBER_PIXEL_FORMATS_ARB                       = $2000;
  WGL_DRAW_TO_WINDOW_ARB                             = $2001;
  WGL_DRAW_TO_BITMAP_ARB                             = $2002;
  WGL_ACCELERATION_ARB                               = $2003;
  WGL_NEED_PALETTE_ARB                               = $2004;
  WGL_NEED_SYSTEM_PALETTE_ARB                        = $2005;
  WGL_SWAP_LAYER_BUFFERS_ARB                         = $2006;
  WGL_SWAP_METHOD_ARB                                = $2007;
  WGL_NUMBER_OVERLAYS_ARB                            = $2008;
  WGL_NUMBER_UNDERLAYS_ARB                           = $2009;
  WGL_TRANSPARENT_ARB                                = $200A;
  WGL_TRANSPARENT_RED_VALUE_ARB                      = $2037;
  WGL_TRANSPARENT_GREEN_VALUE_ARB                    = $2038;
  WGL_TRANSPARENT_BLUE_VALUE_ARB                     = $2039;
  WGL_TRANSPARENT_ALPHA_VALUE_ARB                    = $203A;
  WGL_TRANSPARENT_INDEX_VALUE_ARB                    = $203B;
  WGL_SHARE_DEPTH_ARB                                = $200C;
  WGL_SHARE_STENCIL_ARB                              = $200D;
  WGL_SHARE_ACCUM_ARB                                = $200E;
  WGL_SUPPORT_GDI_ARB                                = $200F;
  WGL_SUPPORT_OPENGL_ARB                             = $2010;
  WGL_DOUBLE_BUFFER_ARB                              = $2011;
  WGL_STEREO_ARB                                     = $2012;
  WGL_PIXEL_TYPE_ARB                                 = $2013;
  WGL_COLOR_BITS_ARB                                 = $2014;
  WGL_RED_BITS_ARB                                   = $2015;
  WGL_RED_SHIFT_ARB                                  = $2016;
  WGL_GREEN_BITS_ARB                                 = $2017;
  WGL_GREEN_SHIFT_ARB                                = $2018;
  WGL_BLUE_BITS_ARB                                  = $2019;
  WGL_BLUE_SHIFT_ARB                                 = $201A;
  WGL_ALPHA_BITS_ARB                                 = $201B;
  WGL_ALPHA_SHIFT_ARB                                = $201C;
  WGL_ACCUM_BITS_ARB                                 = $201D;
  WGL_ACCUM_RED_BITS_ARB                             = $201E;
  WGL_ACCUM_GREEN_BITS_ARB                           = $201F;
  WGL_ACCUM_BLUE_BITS_ARB                            = $2020;
  WGL_ACCUM_ALPHA_BITS_ARB                           = $2021;
  WGL_DEPTH_BITS_ARB                                 = $2022;
  WGL_STENCIL_BITS_ARB                               = $2023;
  WGL_AUX_BUFFERS_ARB                                = $2024;
  WGL_NO_ACCELERATION_ARB                            = $2025;
  WGL_GENERIC_ACCELERATION_ARB                       = $2026;
  WGL_FULL_ACCELERATION_ARB                          = $2027;
  WGL_SWAP_EXCHANGE_ARB                              = $2028;
  WGL_SWAP_COPY_ARB                                  = $2029;
  WGL_SWAP_UNDEFINED_ARB                             = $202A;
  WGL_TYPE_RGBA_ARB                                  = $202B;
  WGL_TYPE_COLORINDEX_ARB                            = $202C;

  // WGL_ARB_render_texture
  WGL_BIND_TO_TEXTURE_RGB_ARB                        = $2070;
  WGL_BIND_TO_TEXTURE_RGBA_ARB                       = $2071;
  WGL_TEXTURE_FORMAT_ARB                             = $2072;
  WGL_TEXTURE_TARGET_ARB                             = $2073;
  WGL_MIPMAP_TEXTURE_ARB                             = $2074;
  WGL_TEXTURE_RGB_ARB                                = $2075;
  WGL_TEXTURE_RGBA_ARB                               = $2076;
  WGL_NO_TEXTURE_ARB                                 = $2077;
  WGL_TEXTURE_CUBE_MAP_ARB                           = $2078;
  WGL_TEXTURE_1D_ARB                                 = $2079;
  WGL_TEXTURE_2D_ARB                                 = $207A;
  WGL_MIPMAP_LEVEL_ARB                               = $207B;
  WGL_CUBE_MAP_FACE_ARB                              = $207C;
  WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                = $207D;
  WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                = $207E;
  WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                = $207F;
  WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                = $2080;
  WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                = $2081;
  WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                = $2082;
  WGL_FRONT_LEFT_ARB                                 = $2083;
  WGL_FRONT_RIGHT_ARB                                = $2084;
  WGL_BACK_LEFT_ARB                                  = $2085;
  WGL_BACK_RIGHT_ARB                                 = $2086;
  WGL_AUX0_ARB                                       = $2087;
  WGL_AUX1_ARB                                       = $2088;
  WGL_AUX2_ARB                                       = $2089;
  WGL_AUX3_ARB                                       = $208A;
  WGL_AUX4_ARB                                       = $208B;
  WGL_AUX5_ARB                                       = $208C;
  WGL_AUX6_ARB                                       = $208D;
  WGL_AUX7_ARB                                       = $208E;
  WGL_AUX8_ARB                                       = $208F;
  WGL_AUX9_ARB                                       = $2090;

  // WGL_I3D_digital_video_control
  WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D     = $2050;
  WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D           = $2051;
  WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D              = $2052;
  WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D              = $2053;

  // WGL_I3D_gamma
  WGL_GAMMA_TABLE_SIZE_I3D                           = $204E;
  WGL_GAMMA_EXCLUDE_DESKTOP_I3D                      = $204F;

  // WGL_I3D_genlock
  WGL_GENLOCK_SOURCE_MULTIVIEW_I3D                   = $2044;
  WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D                = $2045;
  WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D               = $2046;
  WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D                 = $2047;
  WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D                = $2048;
  WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D               = $2049;
  WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D                = $204A;
  WGL_GENLOCK_SOURCE_EDGE_RISING_I3D                 = $204B;
  WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D                   = $204C;

  // WGL_I3D_image_buffer
  WGL_IMAGE_BUFFER_MIN_ACCESS_I3D                    = $00000001;
  WGL_IMAGE_BUFFER_LOCK_I3D                          = $00000002;

  // GLU
  GLU_INVALID_ENUM                                  = 100900;
  GLU_INVALID_VALUE                                 = 100901;
  GLU_OUT_OF_MEMORY                                 = 100902;
  GLU_INCOMPATIBLE_GL_VERSION                       = 100903;
  GLU_VERSION                                       = 100800;
  GLU_EXTENSIONS                                    = 100801;
  GLU_TRUE                                          = GL_TRUE;
  GLU_FALSE                                         = GL_FALSE;
  GLU_SMOOTH                                        = 100000;
  GLU_FLAT                                          = 100001;
  GLU_NONE                                          = 100002;
  GLU_POINT                                         = 100010;
  GLU_LINE                                          = 100011;
  GLU_FILL                                          = 100012;
  GLU_SILHOUETTE                                    = 100013;
  GLU_OUTSIDE                                       = 100020;
  GLU_INSIDE                                        = 100021;
  GLU_TESS_MAX_COORD                                = 1.0e150;
  GLU_TESS_WINDING_RULE                             = 100140;
  GLU_TESS_BOUNDARY_ONLY                            = 100141;
  GLU_TESS_TOLERANCE                                = 100142;
  GLU_TESS_WINDING_ODD                              = 100130;
  GLU_TESS_WINDING_NONZERO                          = 100131;
  GLU_TESS_WINDING_POSITIVE                         = 100132;
  GLU_TESS_WINDING_NEGATIVE                         = 100133;
  GLU_TESS_WINDING_ABS_GEQ_TWO                      = 100134;
  GLU_TESS_BEGIN                                    = 100100; // TGLUTessBeginProc
  GLU_TESS_VERTEX                                   = 100101; // TGLUTessVertexProc
  GLU_TESS_END                                      = 100102; // TGLUTessEndProc
  GLU_TESS_ERROR                                    = 100103; // TGLUTessErrorProc
  GLU_TESS_EDGE_FLAG                                = 100104; // TGLUTessEdgeFlagProc
  GLU_TESS_COMBINE                                  = 100105; // TGLUTessCombineProc
  GLU_TESS_BEGIN_DATA                               = 100106; // TGLUTessBeginDataProc
  GLU_TESS_VERTEX_DATA                              = 100107; // TGLUTessVertexDataProc
  GLU_TESS_END_DATA                                 = 100108; // TGLUTessEndDataProc
  GLU_TESS_ERROR_DATA                               = 100109; // TGLUTessErrorDataProc
  GLU_TESS_EDGE_FLAG_DATA                           = 100110; // TGLUTessEdgeFlagDataProc
  GLU_TESS_COMBINE_DATA                             = 100111; // TGLUTessCombineDataProc
  GLU_TESS_ERROR1                                   = 100151;
  GLU_TESS_ERROR2                                   = 100152;
  GLU_TESS_ERROR3                                   = 100153;
  GLU_TESS_ERROR4                                   = 100154;
  GLU_TESS_ERROR5                                   = 100155;
  GLU_TESS_ERROR6                                   = 100156;
  GLU_TESS_ERROR7                                   = 100157;
  GLU_TESS_ERROR8                                   = 100158;
  GLU_TESS_MISSING_BEGIN_POLYGON                    = GLU_TESS_ERROR1;
  GLU_TESS_MISSING_BEGIN_CONTOUR                    = GLU_TESS_ERROR2;
  GLU_TESS_MISSING_END_POLYGON                      = GLU_TESS_ERROR3;
  GLU_TESS_MISSING_END_CONTOUR                      = GLU_TESS_ERROR4;
  GLU_TESS_COORD_TOO_LARGE                          = GLU_TESS_ERROR5;
  GLU_TESS_NEED_COMBINE_CALLBACK                    = GLU_TESS_ERROR6;
  GLU_AUTO_LOAD_MATRIX                              = 100200;
  GLU_CULLING                                       = 100201;
  GLU_SAMPLING_TOLERANCE                            = 100203;
  GLU_DISPLAY_MODE                                  = 100204;
  GLU_PARAMETRIC_TOLERANCE                          = 100202;
  GLU_SAMPLING_METHOD                               = 100205;
  GLU_U_STEP                                        = 100206;
  GLU_V_STEP                                        = 100207;
  GLU_PATH_LENGTH                                   = 100215;
  GLU_PARAMETRIC_ERROR                              = 100216;
  GLU_DOMAIN_DISTANCE                               = 100217;
  GLU_MAP1_TRIM_2                                   = 100210;
  GLU_MAP1_TRIM_3                                   = 100211;
  GLU_OUTLINE_POLYGON                               = 100240;
  GLU_OUTLINE_PATCH                                 = 100241;
  GLU_NURBS_ERROR1                                  = 100251;
  GLU_NURBS_ERROR2                                  = 100252;
  GLU_NURBS_ERROR3                                  = 100253;
  GLU_NURBS_ERROR4                                  = 100254;
  GLU_NURBS_ERROR5                                  = 100255;
  GLU_NURBS_ERROR6                                  = 100256;
  GLU_NURBS_ERROR7                                  = 100257;
  GLU_NURBS_ERROR8                                  = 100258;
  GLU_NURBS_ERROR9                                  = 100259;
  GLU_NURBS_ERROR10                                 = 100260;
  GLU_NURBS_ERROR11                                 = 100261;
  GLU_NURBS_ERROR12                                 = 100262;
  GLU_NURBS_ERROR13                                 = 100263;
  GLU_NURBS_ERROR14                                 = 100264;
  GLU_NURBS_ERROR15                                 = 100265;
  GLU_NURBS_ERROR16                                 = 100266;
  GLU_NURBS_ERROR17                                 = 100267;
  GLU_NURBS_ERROR18                                 = 100268;
  GLU_NURBS_ERROR19                                 = 100269;
  GLU_NURBS_ERROR20                                 = 100270;
  GLU_NURBS_ERROR21                                 = 100271;
  GLU_NURBS_ERROR22                                 = 100272;
  GLU_NURBS_ERROR23                                 = 100273;
  GLU_NURBS_ERROR24                                 = 100274;
  GLU_NURBS_ERROR25                                 = 100275;
  GLU_NURBS_ERROR26                                 = 100276;
  GLU_NURBS_ERROR27                                 = 100277;
  GLU_NURBS_ERROR28                                 = 100278;
  GLU_NURBS_ERROR29                                 = 100279;
  GLU_NURBS_ERROR30                                 = 100280;
  GLU_NURBS_ERROR31                                 = 100281;
  GLU_NURBS_ERROR32                                 = 100282;
  GLU_NURBS_ERROR33                                 = 100283;
  GLU_NURBS_ERROR34                                 = 100284;
  GLU_NURBS_ERROR35                                 = 100285;
  GLU_NURBS_ERROR36                                 = 100286;
  GLU_NURBS_ERROR37                                 = 100287;
  GLU_CW                                            = 100120;
  GLU_CCW                                           = 100121;
  GLU_INTERIOR                                      = 100122;
  GLU_EXTERIOR                                      = 100123;
  GLU_UNKNOWN                                       = 100124;
  GLU_BEGIN                                         = GLU_TESS_BEGIN;
  GLU_VERTEX                                        = GLU_TESS_VERTEX;
  GLU_END                                           = GLU_TESS_END;
  GLU_ERROR                                         = GLU_TESS_ERROR;
  GLU_EDGE_FLAG                                     = GLU_TESS_EDGE_FLAG;

var
  // GL_VERSION_1_1
  glAccum: procedure(op: TGLenum; value: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glAlphaFunc: procedure(func: TGLenum; ref: TGLclampf); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glAreTexturesResident: function(n: TGLsizei; const textures: PGLuint; residences: PGLboolean): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glArrayElement: procedure(i: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBegin: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBindTexture: procedure(target: TGLenum; texture: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBitmap: procedure(width: TGLsizei; height: TGLsizei; xorig: TGLfloat; yorig: TGLfloat; xmove: TGLfloat; ymove: TGLfloat; const bitmap: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBlendFunc: procedure(sfactor: TGLenum; dfactor: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCallList: procedure(list: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCallLists: procedure(n: TGLsizei; _type: TGLenum; const lists: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClear: procedure(mask: TGLbitfield); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClearAccum: procedure(red: TGLfloat; green: TGLfloat; blue: TGLfloat; alpha: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClearColor: procedure(red: TGLclampf; green: TGLclampf; blue: TGLclampf; alpha: TGLclampf); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClearDepth: procedure(depth: TGLclampd); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClearIndex: procedure(c: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClearStencil: procedure(s: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClipPlane: procedure(plane: TGLenum; const equation: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColor3f: procedure(red: TGLfloat; green: TGLfloat; blue: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColor3fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColor4f: procedure(red: TGLfloat; green: TGLfloat; blue: TGLfloat; alpha: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColor4fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorMask: procedure(red: TGLboolean; green: TGLboolean; blue: TGLboolean; alpha: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorMaterial: procedure(face: TGLenum; mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorPointer: procedure(size: TGLint; _type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyPixels: procedure(x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei; _type: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyTexImage1D: procedure(target: TGLenum; level: TGLint; internalFormat: TGLenum; x: TGLint; y: TGLint; width: TGLsizei; border: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyTexImage2D: procedure(target: TGLenum; level: TGLint; internalFormat: TGLenum; x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei; border: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyTexSubImage1D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; x: TGLint; y: TGLint; width: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyTexSubImage2D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCullFace: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDeleteLists: procedure(list: TGLuint; range: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDeleteTextures: procedure(n: TGLsizei; const textures: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDepthFunc: procedure(func: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDepthMask: procedure(flag: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDepthRange: procedure(zNear: TGLclampd; zFar: TGLclampd); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDisable: procedure(cap: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDisableClientState: procedure(_array: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDrawArrays: procedure(mode: TGLenum; first: TGLint; count: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDrawBuffer: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDrawElements: procedure(mode: TGLenum; count: TGLsizei; _type: TGLenum; const indices: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDrawPixels: procedure(width: TGLsizei; height: TGLsizei; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEdgeFlag: procedure(flag: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEdgeFlagPointer: procedure(stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEdgeFlagv: procedure(const flag: PGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEnable: procedure(cap: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEnableClientState: procedure(_array: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEnd: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEndList: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord1d: procedure(u: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord1dv: procedure(const u: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord1f: procedure(u: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord1fv: procedure(const u: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord2d: procedure(u: TGLdouble; v: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord2dv: procedure(const u: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord2f: procedure(u: TGLfloat; v: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalCoord2fv: procedure(const u: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalMesh1: procedure(mode: TGLenum; i1: TGLint; i2: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalMesh2: procedure(mode: TGLenum; i1: TGLint; i2: TGLint; j1: TGLint; j2: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalPoint1: procedure(i: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEvalPoint2: procedure(i: TGLint; j: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFeedbackBuffer: procedure(size: TGLsizei; _type: TGLenum; buffer: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFinish: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFlush: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogf: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogfv: procedure(pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogi: procedure(pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogiv: procedure(pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFrontFace: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFrustum: procedure(left: TGLdouble; right: TGLdouble; bottom: TGLdouble; top: TGLdouble; zNear: TGLdouble; zFar: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGenLists: function(range: TGLsizei): TGLuint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGenTextures: procedure(n: TGLsizei; textures: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetBooleanv: procedure(pname: TGLenum; params: PGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetClipPlane: procedure(plane: TGLenum; equation: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetDoublev: procedure(pname: TGLenum; params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetError: function(): TGLenum; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetFloatv: procedure(pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetIntegerv: procedure(pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetLightfv: procedure(light: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetLightiv: procedure(light: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMapdv: procedure(target: TGLenum; query: TGLenum; v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMapfv: procedure(target: TGLenum; query: TGLenum; v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMapiv: procedure(target: TGLenum; query: TGLenum; v: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMaterialfv: procedure(face: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMaterialiv: procedure(face: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetPixelMapfv: procedure(map: TGLenum; values: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetPixelMapuiv: procedure(map: TGLenum; values: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetPixelMapusv: procedure(map: TGLenum; values: PGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetPointerv: procedure(pname: TGLenum; params: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetPolygonStipple: procedure(mask: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetString: function(name: TGLenum): PChar; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexEnvfv: procedure(target: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexEnviv: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexGendv: procedure(coord: TGLenum; pname: TGLenum; params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexGenfv: procedure(coord: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexGeniv: procedure(coord: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexImage: procedure(target: TGLenum; level: TGLint; format: TGLenum; _type: TGLenum; pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexLevelParameterfv: procedure(target: TGLenum; level: TGLint; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexLevelParameteriv: procedure(target: TGLenum; level: TGLint; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexParameterfv: procedure(target: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetTexParameteriv: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glHint: procedure(target: TGLenum; mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexMask: procedure(mask: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexPointer: procedure(_type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexd: procedure(c: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexdv: procedure(const c: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexf: procedure(c: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexfv: procedure(const c: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexi: procedure(c: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexiv: procedure(const c: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexs: procedure(c: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexsv: procedure(const c: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexub: procedure(c: TGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIndexubv: procedure(const c: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glInitNames: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glInterleavedArrays: procedure(format: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIsEnabled: function(cap: TGLenum): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIsList: function(list: TGLuint): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIsTexture: function(texture: TGLuint): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLightModelf: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLightModelfv: procedure(pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLightModeli: procedure(pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLightModeliv: procedure(pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLightf: procedure(light: TGLenum; pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLightfv: procedure(light: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLighti: procedure(light: TGLenum; pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLightiv: procedure(light: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLineStipple: procedure(factor: TGLint; pattern: TGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLineWidth: procedure(width: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glListBase: procedure(base: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLoadIdentity: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLoadMatrixd: procedure(const m: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLoadMatrixf: procedure(const m: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLoadName: procedure(name: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLogicOp: procedure(opcode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMap1d: procedure(target: TGLenum; u1: TGLdouble; u2: TGLdouble; stride: TGLint; order: TGLint; const points: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMap1f: procedure(target: TGLenum; u1: TGLfloat; u2: TGLfloat; stride: TGLint; order: TGLint; const points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMap2d: procedure(target: TGLenum; u1: TGLdouble; u2: TGLdouble; ustride: TGLint; uorder: TGLint; v1: TGLdouble; v2: TGLdouble; vstride: TGLint; vorder: TGLint; const points: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMap2f: procedure(target: TGLenum; u1: TGLfloat; u2: TGLfloat; ustride: TGLint; uorder: TGLint; v1: TGLfloat; v2: TGLfloat; vstride: TGLint; vorder: TGLint; const points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMapGrid1d: procedure(un: TGLint; u1: TGLdouble; u2: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMapGrid1f: procedure(un: TGLint; u1: TGLfloat; u2: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMapGrid2d: procedure(un: TGLint; u1: TGLdouble; u2: TGLdouble; vn: TGLint; v1: TGLdouble; v2: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMapGrid2f: procedure(un: TGLint; u1: TGLfloat; u2: TGLfloat; vn: TGLint; v1: TGLfloat; v2: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMaterialf: procedure(face: TGLenum; pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMaterialfv: procedure(face: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMateriali: procedure(face: TGLenum; pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMaterialiv: procedure(face: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMatrixMode: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultMatrixd: procedure(const m: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultMatrixf: procedure(const m: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glNewList: procedure(list: TGLuint; mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glNormal3f: procedure(nx: TGLfloat; ny: TGLfloat; nz: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glNormal3fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glNormalPointer: procedure(_type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glOrtho: procedure(left: TGLdouble; right: TGLdouble; bottom: TGLdouble; top: TGLdouble; zNear: TGLdouble; zFar: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPassThrough: procedure(token: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelMapfv: procedure(map: TGLenum; mapsize: TGLsizei; const values: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelMapuiv: procedure(map: TGLenum; mapsize: TGLsizei; const values: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelMapusv: procedure(map: TGLenum; mapsize: TGLsizei; const values: PGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelStoref: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelStorei: procedure(pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelTransferf: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelTransferi: procedure(pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelZoom: procedure(xfactor: TGLfloat; yfactor: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPointSize: procedure(size: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPolygonMode: procedure(face: TGLenum; mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPolygonOffset: procedure(factor: TGLfloat; units: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPolygonStipple: procedure(const mask: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPopAttrib: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPopClientAttrib: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPopMatrix: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPopName: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPrioritizeTextures: procedure(n: TGLsizei; const textures: PGLuint; const priorities: PGLclampf); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPushAttrib: procedure(mask: TGLbitfield); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPushClientAttrib: procedure(mask: TGLbitfield); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPushMatrix: procedure(); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPushName: procedure(name: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2d: procedure(x: TGLdouble; y: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2dv: procedure(const v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2f: procedure(x: TGLfloat; y: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2i: procedure(x: TGLint; y: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2iv: procedure(const v: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2s: procedure(x: TGLshort; y: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos2sv: procedure(const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3d: procedure(x: TGLdouble; y: TGLdouble; z: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3dv: procedure(const v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3f: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3i: procedure(x: TGLint; y: TGLint; z: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3iv: procedure(const v: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3s: procedure(x: TGLshort; y: TGLshort; z: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos3sv: procedure(const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4d: procedure(x: TGLdouble; y: TGLdouble; z: TGLdouble; w: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4dv: procedure(const v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4f: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat; w: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4i: procedure(x: TGLint; y: TGLint; z: TGLint; w: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4iv: procedure(const v: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4s: procedure(x: TGLshort; y: TGLshort; z: TGLshort; w: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRasterPos4sv: procedure(const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glReadBuffer: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glReadPixels: procedure(x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei; format: TGLenum; _type: TGLenum; pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRectd: procedure(x1: TGLdouble; y1: TGLdouble; x2: TGLdouble; y2: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRectdv: procedure(const v1: PGLdouble; const v2: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRectf: procedure(x1: TGLfloat; y1: TGLfloat; x2: TGLfloat; y2: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRectfv: procedure(const v1: PGLfloat; const v2: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRecti: procedure(x1: TGLint; y1: TGLint; x2: TGLint; y2: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRectiv: procedure(const v1: PGLint; const v2: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRects: procedure(x1: TGLshort; y1: TGLshort; x2: TGLshort; y2: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRectsv: procedure(const v1: PGLshort; const v2: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRenderMode: function(mode: TGLenum): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRotated: procedure(angle: TGLdouble; x: TGLdouble; y: TGLdouble; z: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glRotatef: procedure(angle: TGLfloat; x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glScaled: procedure(x: TGLdouble; y: TGLdouble; z: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glScalef: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glScissor: procedure(x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glSelectBuffer: procedure(size: TGLsizei; buffer: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glShadeModel: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glStencilFunc: procedure(func: TGLenum; ref: TGLint; mask: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glStencilMask: procedure(mask: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glStencilOp: procedure(fail: TGLenum; zfail: TGLenum; zpass: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord1f: procedure(s: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord1fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord2f: procedure(s: TGLfloat; t: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord2fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord3f: procedure(s: TGLfloat; t: TGLfloat; r: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord3fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord4f: procedure(s: TGLfloat; t: TGLfloat; r: TGLfloat; q: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoord4fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexCoordPointer: procedure(size: TGLint; _type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexEnvf: procedure(target: TGLenum; pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexEnvfv: procedure(target: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexEnvi: procedure(target: TGLenum; pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexEnviv: procedure(target: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexGend: procedure(coord: TGLenum; pname: TGLenum; param: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexGendv: procedure(coord: TGLenum; pname: TGLenum; const params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexGenf: procedure(coord: TGLenum; pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexGenfv: procedure(coord: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexGeni: procedure(coord: TGLenum; pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexGeniv: procedure(coord: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexImage1D: procedure(target: TGLenum; level: TGLint; internalformat: TGLint; width: TGLsizei; border: TGLint; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexImage2D: procedure(target: TGLenum; level: TGLint; internalformat: TGLint; width: TGLsizei; height: TGLsizei; border: TGLint; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexParameterf: procedure(target: TGLenum; pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexParameterfv: procedure(target: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexParameteri: procedure(target: TGLenum; pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexParameteriv: procedure(target: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexSubImage1D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; width: TGLsizei; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexSubImage2D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; width: TGLsizei; height: TGLsizei; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTranslated: procedure(x: TGLdouble; y: TGLdouble; z: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTranslatef: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertex2f: procedure(x: TGLfloat; y: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertex2fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertex3f: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertex3fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertex4f: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat; w: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertex4fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexPointer: procedure(size: TGLint; _type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glViewport: procedure(x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_VERSION_1_2
  glBlendColor: procedure(red: TGLclampf; green: TGLclampf; blue: TGLclampf; alpha: TGLclampf); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBlendEquation: procedure(mode: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDrawRangeElements: procedure(mode: TGLenum; start: TGLuint; _end: TGLuint; count: TGLsizei; _type: TGLenum; const indices: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorTable: procedure(target: TGLenum; internalformat: TGLenum; width: TGLsizei; format: TGLenum; _type: TGLenum; const table: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorTableParameterfv: procedure(target: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorTableParameteriv: procedure(target: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyColorTable: procedure(target: TGLenum; internalformat: TGLenum; x: TGLint; y: TGLint; width: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetColorTable: procedure(target: TGLenum; format: TGLenum; _type: TGLenum; table: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetColorTableParameterfv: procedure(target: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetColorTableParameteriv: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorSubTable: procedure(target: TGLenum; start: TGLsizei; count: TGLsizei; format: TGLenum; _type: TGLenum; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyColorSubTable: procedure(target: TGLenum; start: TGLsizei; x: TGLint; y: TGLint; width: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glConvolutionFilter1D: procedure(target: TGLenum; internalformat: TGLenum; width: TGLsizei; format: TGLenum; _type: TGLenum; const image: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glConvolutionFilter2D: procedure(target: TGLenum; internalformat: TGLenum; width: TGLsizei; height: TGLsizei; format: TGLenum; _type: TGLenum; const image: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glConvolutionParameterf: procedure(target: TGLenum; pname: TGLenum; params: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glConvolutionParameterfv: procedure(target: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glConvolutionParameteri: procedure(target: TGLenum; pname: TGLenum; params: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glConvolutionParameteriv: procedure(target: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyConvolutionFilter1D: procedure(target: TGLenum; internalformat: TGLenum; x: TGLint; y: TGLint; width: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyConvolutionFilter2D: procedure(target: TGLenum; internalformat: TGLenum; x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetConvolutionFilter: procedure(target: TGLenum; format: TGLenum; _type: TGLenum; image: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetConvolutionParameterfv: procedure(target: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetConvolutionParameteriv: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetSeparableFilter: procedure(target: TGLenum; format: TGLenum; _type: TGLenum; row: PGLvoid; column: PGLvoid; span: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glSeparableFilter2D: procedure(target: TGLenum; internalformat: TGLenum; width: TGLsizei; height: TGLsizei; format: TGLenum; _type: TGLenum; const row: PGLvoid; const column: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetHistogram: procedure(target: TGLenum; reset: TGLboolean; format: TGLenum; _type: TGLenum; values: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetHistogramParameterfv: procedure(target: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetHistogramParameteriv: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMinmax: procedure(target: TGLenum; reset: TGLboolean; format: TGLenum; _type: TGLenum; values: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMinmaxParameterfv: procedure(target: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetMinmaxParameteriv: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glHistogram: procedure(target: TGLenum; width: TGLsizei; internalformat: TGLenum; sink: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMinmax: procedure(target: TGLenum; internalformat: TGLenum; sink: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glResetHistogram: procedure(target: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glResetMinmax: procedure(target: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexImage3D: procedure(target: TGLenum; level: TGLint; internalformat: TGLint; width: TGLsizei; height: TGLsizei; depth: TGLsizei; border: TGLint; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexSubImage3D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; zoffset: TGLint; width: TGLsizei; height: TGLsizei; depth: TGLsizei; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyTexSubImage3D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; zoffset: TGLint; x: TGLint; y: TGLint; width: TGLsizei; height: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_VERSION_1_3
  glActiveTexture: procedure(texture: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClientActiveTexture: procedure(texture: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord1f: procedure(target: TGLenum; s: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord1fv: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord2f: procedure(target: TGLenum; s: TGLfloat; t: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord2fv: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord3f: procedure(target: TGLenum; s: TGLfloat; t: TGLfloat; r: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord3fv: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord4f: procedure(target: TGLenum; s: TGLfloat; t: TGLfloat; r: TGLfloat; q: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord4fv: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLoadTransposeMatrixf: procedure(const m: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLoadTransposeMatrixd: procedure(const m: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultTransposeMatrixf: procedure(const m: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultTransposeMatrixd: procedure(const m: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glSampleCoverage: procedure(value: TGLclampf; invert: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexImage3D: procedure(target: TGLenum; level: TGLint; internalformat: TGLenum; width: TGLsizei; height: TGLsizei; depth: TGLsizei; border: TGLint; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexImage2D: procedure(target: TGLenum; level: TGLint; internalformat: TGLenum; width: TGLsizei; height: TGLsizei; border: TGLint; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexImage1D: procedure(target: TGLenum; level: TGLint; internalformat: TGLenum; width: TGLsizei; border: TGLint; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexSubImage3D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; zoffset: TGLint; width: TGLsizei; height: TGLsizei; depth: TGLsizei; format: TGLenum; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexSubImage2D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; width: TGLsizei; height: TGLsizei; format: TGLenum; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexSubImage1D: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; width: TGLsizei; format: TGLenum; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetCompressedTexImage: procedure(target: TGLenum; level: TGLint; img: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_VERSION_1_4
  glBlendFuncSeparate: procedure(sfactorRGB: TGLenum; dfactorRGB: TGLenum; sfactorAlpha: TGLenum; dfactorAlpha: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogCoordf: procedure(coord: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogCoordfv: procedure(const coord: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogCoordd: procedure(coord: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogCoorddv: procedure(const coord: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glFogCoordPointer: procedure(_type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiDrawArrays: procedure(mode: TGLenum; first: PGLint; count: PGLsizei; primcount: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiDrawElements: procedure(mode: TGLenum; const count: PGLsizei; _type: TGLenum; const indices: PGLvoid; primcount: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPointParameterf: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPointParameterfv: procedure(pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPointParameteri: procedure(pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPointParameteriv: procedure(pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glSecondaryColor3f: procedure(red: TGLfloat; green: TGLfloat; blue: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glSecondaryColor3fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glSecondaryColorPointer: procedure(size: TGLint; _type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWindowPos2f: procedure(x: TGLfloat; y: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWindowPos2fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWindowPos3f: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWindowPos3fv: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_matrix_palette
  glCurrentPaletteMatrixARB: procedure(index: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMatrixIndexubvARB: procedure(size: TGLint; const indices: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMatrixIndexusvARB: procedure(size: TGLint; const indices: PGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMatrixIndexuivARB: procedure(size: TGLint; const indices: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMatrixIndexPointerARB: procedure(size: TGLint; _type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_multisample
  glSampleCoverageARB: procedure(value: TGLclampf; invert: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_multitexture
  glActiveTextureARB: procedure(texture: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glClientActiveTextureARB: procedure(texture: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord1fARB: procedure(target: TGLenum; s: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord1fvARB: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord2fARB: procedure(target: TGLenum; s: TGLfloat; t: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord2fvARB: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord3fARB: procedure(target: TGLenum; s: TGLfloat; t: TGLfloat; r: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord3fvARB: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord4fARB: procedure(target: TGLenum; s: TGLfloat; t: TGLfloat; r: TGLfloat; q: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultiTexCoord4fvARB: procedure(target: TGLenum; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_point_parameters
  glPointParameterfARB: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPointParameterfvARB: procedure(pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_texture_compression
  glCompressedTexImage3DARB: procedure(target: TGLenum; level: TGLint; internalformat: TGLenum; width: TGLsizei; height: TGLsizei; depth: TGLsizei; border: TGLint; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexImage2DARB: procedure(target: TGLenum; level: TGLint; internalformat: TGLenum; width: TGLsizei; height: TGLsizei; border: TGLint; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexImage1DARB: procedure(target: TGLenum; level: TGLint; internalformat: TGLenum; width: TGLsizei; border: TGLint; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexSubImage3DARB: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; zoffset: TGLint; width: TGLsizei; height: TGLsizei; depth: TGLsizei; format: TGLenum; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexSubImage2DARB: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; width: TGLsizei; height: TGLsizei; format: TGLenum; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCompressedTexSubImage1DARB: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; width: TGLsizei; format: TGLenum; imageSize: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetCompressedTexImageARB: procedure(target: TGLenum; level: TGLint; img: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_transpose_matrix
  glLoadTransposeMatrixfARB: procedure(const m: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glLoadTransposeMatrixdARB: procedure(const m: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultTransposeMatrixfARB: procedure(const m: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMultTransposeMatrixdARB: procedure(const m: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_vertex_blend
  glWeightbvARB: procedure(size: TGLint; const weights: PGLbyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightsvARB: procedure(size: TGLint; const weights: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightivARB: procedure(size: TGLint; const weights: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightfvARB: procedure(size: TGLint; const weights: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightdvARB: procedure(size: TGLint; const weights: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightubvARB: procedure(size: TGLint; const weights: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightusvARB: procedure(size: TGLint; const weights: PGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightuivARB: procedure(size: TGLint; const weights: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWeightPointerARB: procedure(size: TGLint; _type: TGLenum; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexBlendARB: procedure(count: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_vertex_buffer_object
  glBindBufferARB: procedure(target: TGLenum; buffer: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDeleteBuffersARB: procedure(n: TGLsizei; const buffers: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGenBuffersARB: procedure(n: TGLsizei; buffers: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIsBufferARB: function(buffer: TGLuint): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBufferDataARB: procedure(target: TGLenum; size: TGLsizei; const data: PGLvoid; usage: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBufferSubDataARB: procedure(target: TGLenum; offset: TGLsizei; size: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetBufferSubDataARB: procedure(target: TGLenum; offset: TGLsizei; size: TGLsizei; data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMapBufferARB: function(target: TGLenum; access: TGLenum): PGLvoid; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glUnmapBufferARB: function(target: TGLenum): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetBufferParameterivARB: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetBufferPointervARB: procedure(target: TGLenum; pname: TGLenum; params: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // ARB less version fo GL 1.5
  glBindBuffer: procedure(target: TGLenum; buffer: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDeleteBuffers: procedure(n: TGLsizei; const buffers: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGenBuffers: procedure(n: TGLsizei; buffers: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIsBuffer: function(buffer: TGLuint): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBufferData: procedure(target: TGLenum; size: TGLsizei; const data: PGLvoid; usage: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBufferSubData: procedure(target: TGLenum; offset: TGLsizei; size: TGLsizei; const data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetBufferSubData: procedure(target: TGLenum; offset: TGLsizei; size: TGLsizei; data: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glMapBuffer: function(target: TGLenum; access: TGLenum): PGLvoid; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glUnmapBuffer: function(target: TGLenum): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetBufferParameteriv: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetBufferPointerv: procedure(target: TGLenum; pname: TGLenum; params: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_ARB_vertex_program
  glVertexAttrib1dARB: procedure(index: TGLuint; x: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib1dvARB: procedure(index: TGLuint; const v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib1fARB: procedure(index: TGLuint; x: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib1fvARB: procedure(index: TGLuint; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib1sARB: procedure(index: TGLuint; x: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib1svARB: procedure(index: TGLuint; const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib2dARB: procedure(index: TGLuint; x: TGLdouble; y: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib2dvARB: procedure(index: TGLuint; const v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib2fARB: procedure(index: TGLuint; x: TGLfloat; y: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib2fvARB: procedure(index: TGLuint; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib2sARB: procedure(index: TGLuint; x: TGLshort; y: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib2svARB: procedure(index: TGLuint; const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib3dARB: procedure(index: TGLuint; x: TGLdouble; y: TGLdouble; z: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib3dvARB: procedure(index: TGLuint; const v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib3fARB: procedure(index: TGLuint; x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib3fvARB: procedure(index: TGLuint; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib3sARB: procedure(index: TGLuint; x: TGLshort; y: TGLshort; z: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib3svARB: procedure(index: TGLuint; const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4NbvARB: procedure(index: TGLuint; const v: PGLbyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4NivARB: procedure(index: TGLuint; const v: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4NsvARB: procedure(index: TGLuint; const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4NubARB: procedure(index: TGLuint; x: TGLubyte; y: TGLubyte; z: TGLubyte; w: TGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4NubvARB: procedure(index: TGLuint; const v: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4NuivARB: procedure(index: TGLuint; const v: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4NusvARB: procedure(index: TGLuint; const v: PGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4bvARB: procedure(index: TGLuint; const v: PGLbyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4dARB: procedure(index: TGLuint; x: TGLdouble; y: TGLdouble; z: TGLdouble; w: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4dvARB: procedure(index: TGLuint; const v: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4fARB: procedure(index: TGLuint; x: TGLfloat; y: TGLfloat; z: TGLfloat; w: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4fvARB: procedure(index: TGLuint; const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4ivARB: procedure(index: TGLuint; const v: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4sARB: procedure(index: TGLuint; x: TGLshort; y: TGLshort; z: TGLshort; w: TGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4svARB: procedure(index: TGLuint; const v: PGLshort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4ubvARB: procedure(index: TGLuint; const v: PGLubyte); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4uivARB: procedure(index: TGLuint; const v: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttrib4usvARB: procedure(index: TGLuint; const v: PGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glVertexAttribPointerARB: procedure(index: TGLuint; size: TGLint; _type: TGLenum; normalized: TGLboolean; stride: TGLsizei; const _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glEnableVertexAttribArrayARB: procedure(index: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDisableVertexAttribArrayARB: procedure(index: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramStringARB: procedure(target: TGLenum; format: TGLenum; len: TGLsizei; const _string: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glBindProgramARB: procedure(target: TGLenum; _program: TGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glDeleteProgramsARB: procedure(n: TGLsizei; const programs: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGenProgramsARB: procedure(n: TGLsizei; programs: PGLuint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramEnvParameter4dARB: procedure(target: TGLenum; index: TGLuint; x: TGLdouble; y: TGLdouble; z: TGLdouble; w: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramEnvParameter4dvARB: procedure(target: TGLenum; index: TGLuint; const params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramEnvParameter4fARB: procedure(target: TGLenum; index: TGLuint; x: TGLfloat; y: TGLfloat; z: TGLfloat; w: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramEnvParameter4fvARB: procedure(target: TGLenum; index: TGLuint; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramLocalParameter4dARB: procedure(target: TGLenum; index: TGLuint; x: TGLdouble; y: TGLdouble; z: TGLdouble; w: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramLocalParameter4dvARB: procedure(target: TGLenum; index: TGLuint; const params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramLocalParameter4fARB: procedure(target: TGLenum; index: TGLuint; x: TGLfloat; y: TGLfloat; z: TGLfloat; w: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glProgramLocalParameter4fvARB: procedure(target: TGLenum; index: TGLuint; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetProgramEnvParameterdvARB: procedure(target: TGLenum; index: TGLuint; params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetProgramEnvParameterfvARB: procedure(target: TGLenum; index: TGLuint; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetProgramLocalParameterdvARB: procedure(target: TGLenum; index: TGLuint; params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetProgramLocalParameterfvARB: procedure(target: TGLenum; index: TGLuint; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetProgramivARB: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetProgramStringARB: procedure(target: TGLenum; pname: TGLenum; _string: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetVertexAttribdvARB: procedure(index: TGLuint; pname: TGLenum; params: PGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetVertexAttribfvARB: procedure(index: TGLuint; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetVertexAttribivARB: procedure(index: TGLuint; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetVertexAttribPointervARB: procedure(index: TGLuint; pname: TGLenum; _pointer: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glIsProgramARB: function(_program: TGLuint): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  glVertexAttrib1d : procedure(index: GLuint; x: GLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib1dv : procedure(index: GLuint; const v: PGLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib1f : procedure(index: GLuint; x: GLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib1fv : procedure(index: GLuint; const v: PGLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib1s : procedure(index: GLuint; x: GLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib1sv : procedure(index: GLuint; const v: PGLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib2d : procedure(index: GLuint; x: GLdouble; y: GLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib2dv : procedure(index: GLuint; const v: PGLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib2f : procedure(index: GLuint; x: GLfloat; y: GLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib2fv : procedure(index: GLuint; const v: PGLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib2s : procedure(index: GLuint; x: GLshort; y: GLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib2sv : procedure(index: GLuint; const v: PGLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib3d : procedure(index: GLuint; x: GLdouble; y: GLdouble; z: GLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib3dv : procedure(index: GLuint; const v: PGLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib3f : procedure(index: GLuint; x: GLfloat; y: GLfloat; z: GLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib3fv : procedure(index: GLuint; const v: PGLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib3s : procedure(index: GLuint; x: GLshort; y: GLshort; z: GLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib3sv : procedure(index: GLuint; const v: PGLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4Nbv : procedure(index: GLuint; const v: PGLbyte); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4Niv : procedure(index: GLuint; const v: PGLint); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4Nsv : procedure(index: GLuint; const v: PGLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4Nub : procedure(index: GLuint; x: GLubyte; y: GLubyte; z: GLubyte; w: GLubyte); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4Nubv : procedure(index: GLuint; const v: PGLubyte); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4Nuiv : procedure(index: GLuint; const v: PGLuint); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4Nusv : procedure(index: GLuint; const v: PGLushort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4bv : procedure(index: GLuint; const v: PGLbyte); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4d : procedure(index: GLuint; x: GLdouble; y: GLdouble; z: GLdouble; w: GLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4dv : procedure(index: GLuint; const v: PGLdouble); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4f : procedure(index: GLuint; x: GLfloat; y: GLfloat; z: GLfloat; w: GLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4fv : procedure(index: GLuint; const v: PGLfloat); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4iv : procedure(index: GLuint; const v: PGLint); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4s : procedure(index: GLuint; x: GLshort; y: GLshort; z: GLshort; w: GLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4sv : procedure(index: GLuint; const v: PGLshort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4ubv : procedure(index: GLuint; const v: PGLubyte); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4uiv : procedure(index: GLuint; const v: PGLuint); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttrib4usv : procedure(index: GLuint; const v: PGLushort); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}
  glVertexAttribPointer : procedure(index: GLuint; size: GLint; _type: GLenum; normalized: GLboolean; stride: GLsizei; const _pointer: PGLvoid); {$IFNDEF CLR}{$IFDEF Win32}stdcall; {$ELSE}cdecl; {$ENDIF}{$ENDIF}

  // GL_ARB_window_pos
  glWindowPos2fARB: procedure(x: TGLfloat; y: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWindowPos2fvARB: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWindowPos3fARB: procedure(x: TGLfloat; y: TGLfloat; z: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glWindowPos3fvARB: procedure(const v: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_detail_texture
  glDetailTexFuncSGIS: procedure(target: TGLenum; n: TGLsizei; const points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetDetailTexFuncSGIS: procedure(target: TGLenum; points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_fog_function
  glFogFuncSGIS: procedure(n: TGLsizei; const points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetFogFuncSGIS: procedure(points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_multisample
  glSampleMaskSGIS: procedure(value: TGLclampf; invert: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glSamplePatternSGIS: procedure(pattern: TGLenum); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_pixel_texture
  glPixelTexGenParameteriSGIS: procedure(pname: TGLenum; param: TGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelTexGenParameterivSGIS: procedure(pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelTexGenParameterfSGIS: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPixelTexGenParameterfvSGIS: procedure(pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetPixelTexGenParameterivSGIS: procedure(pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetPixelTexGenParameterfvSGIS: procedure(pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_point_parameters
  glPointParameterfSGIS: procedure(pname: TGLenum; param: TGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glPointParameterfvSGIS: procedure(pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_sharpen_texture
  glSharpenTexFuncSGIS: procedure(target: TGLenum; n: TGLsizei; const points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetSharpenTexFuncSGIS: procedure(target: TGLenum; points: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_texture4D
  glTexImage4DSGIS: procedure(target: TGLenum; level: TGLint; internalformat: TGLenum; width: TGLsizei; height: TGLsizei; depth: TGLsizei; size4d: TGLsizei; border: TGLint; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexSubImage4DSGIS: procedure(target: TGLenum; level: TGLint; xoffset: TGLint; yoffset: TGLint; zoffset: TGLint; woffset: TGLint; width: TGLsizei; height: TGLsizei; depth: TGLsizei; size4d: TGLsizei; format: TGLenum; _type: TGLenum; const pixels: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_texture_color_mask
  glTextureColorMaskSGIS: procedure(red: TGLboolean; green: TGLboolean; blue: TGLboolean; alpha: TGLboolean); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // GL_SGIS_texture_filter4
  glGetTexFilterFuncSGIS: procedure(target: TGLenum; filter: TGLenum; weights: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glTexFilterFuncSGIS: procedure(target: TGLenum; filter: TGLenum; n: TGLsizei; const weights: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}



  // GL_SGI_color_table
  glColorTableSGI: procedure(target: TGLenum; internalformat: TGLenum; width: TGLsizei; format: TGLenum; _type: TGLenum; const table: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorTableParameterfvSGI: procedure(target: TGLenum; pname: TGLenum; const params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glColorTableParameterivSGI: procedure(target: TGLenum; pname: TGLenum; const params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glCopyColorTableSGI: procedure(target: TGLenum; internalformat: TGLenum; x: TGLint; y: TGLint; width: TGLsizei); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetColorTableSGI: procedure(target: TGLenum; format: TGLenum; _type: TGLenum; table: PGLvoid); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetColorTableParameterfvSGI: procedure(target: TGLenum; pname: TGLenum; params: PGLfloat); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  glGetColorTableParameterivSGI: procedure(target: TGLenum; pname: TGLenum; params: PGLint); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // window support functions
  {$IFDEF Win32}
  wglGetProcAddress: function(ProcName: PChar): Pointer; stdcall;
  wglCopyContext: function(p1: HGLRC; p2: HGLRC; p3: Cardinal): BOOL; stdcall;
  wglCreateContext: function(DC: HDC): HGLRC; stdcall;
  wglCreateLayerContext: function(p1: HDC; p2: Integer): HGLRC; stdcall;
  wglDeleteContext: function(p1: HGLRC): BOOL; stdcall;
  wglDescribeLayerPlane:function(p1: HDC; p2, p3: Integer; p4: Cardinal; var p5: TLayerPlaneDescriptor): BOOL; stdcall;
  wglGetCurrentContext: function: HGLRC; stdcall;
  wglGetCurrentDC: function: HDC; stdcall;
  wglGetLayerPaletteEntries: function(p1: HDC; p2, p3, p4: Integer; var pcr): Integer; stdcall;
  wglMakeCurrent: function(DC: HDC; p2: HGLRC): BOOL; stdcall;
  wglRealizeLayerPalette: function(p1: HDC; p2: Integer; p3: BOOL): BOOL; stdcall;
  wglSetLayerPaletteEntries: function(p1: HDC; p2, p3, p4: Integer; var pcr): Integer; stdcall;
  wglShareLists: function(p1, p2: HGLRC): BOOL; stdcall;
  wglSwapLayerBuffers: function(p1: HDC; p2: Cardinal): BOOL; stdcall;
  wglSwapMultipleBuffers: function(p1: UINT; const p2: PWGLSwap): DWORD; stdcall;
  wglUseFontBitmapsA: function(DC: HDC; p2, p3, p4: DWORD): BOOL; stdcall;
  wglUseFontOutlinesA: function (p1: HDC; p2, p3, p4: DWORD; p5, p6: Single; p7: Integer; p8: PGlyphMetricsFloat): BOOL; stdcall;
  wglUseFontBitmapsW: function(DC: HDC; p2, p3, p4: DWORD): BOOL; stdcall;
  wglUseFontOutlinesW: function (p1: HDC; p2, p3, p4: DWORD; p5, p6: Single; p7: Integer; p8: PGlyphMetricsFloat): BOOL; stdcall;
  wglUseFontBitmaps: function(DC: HDC; p2, p3, p4: DWORD): BOOL; stdcall;
  wglUseFontOutlines: function(p1: HDC; p2, p3, p4: DWORD; p5, p6: Single; p7: Integer; p8: PGlyphMetricsFloat): BOOL; stdcall;
  {$ENDIF}

{$IFDEF Win32}
 // Changed by bero
  // WGL_ARB_buffer_region
  wglCreateBufferRegionARB: function(hDC: HDC; iLayerPlane: TGLint; uType: TGLuint): THandle; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglDeleteBufferRegionARB: procedure(hRegion: THandle); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglSaveBufferRegionARB: function(hRegion: THandle; x: TGLint; y: TGLint; width: TGLint; height: TGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglRestoreBufferRegionARB: function(hRegion: THandle; x: TGLint; y: TGLint; width: TGLint; height: TGLint; xSrc: TGLint; ySrc: TGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_ARB_extensions_string
  wglGetExtensionsStringARB: function(hdc: HDC): PChar; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_ARB_make_current_read
  wglMakeContextCurrentARB: function(hDrawDC: HDC; hReadDC: HDC; hglrc: HGLRC): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetCurrentReadDCARB: function(): HDC; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_ARB_pbuffer
  wglCreatePbufferARB: function(hDC: HDC; iPixelFormat: TGLint; iWidth: TGLint; iHeight: TGLint; const piAttribList: PGLint): HPBUFFERARB; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetPbufferDCARB: function(hPbuffer: HPBUFFERARB): HDC; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglReleasePbufferDCARB: function(hPbuffer: HPBUFFERARB; hDC: HDC): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglDestroyPbufferARB: function(hPbuffer: HPBUFFERARB): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglQueryPbufferARB: function(hPbuffer: HPBUFFERARB; iAttribute: TGLint; piValue: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_ARB_pixel_format
  wglGetPixelFormatAttribivARB: function(hdc: HDC; iPixelFormat: TGLint; iLayerPlane: TGLint; nAttributes: TGLuint; const piAttributes: PGLint; piValues: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetPixelFormatAttribfvARB: function(hdc: HDC; iPixelFormat: TGLint; iLayerPlane: TGLint; nAttributes: TGLuint; const piAttributes: PGLint; pfValues: PGLfloat): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglChoosePixelFormatARB: function(hdc: HDC; const piAttribIList: PGLint; const pfAttribFList: PGLfloat; nMaxFormats: TGLuint; piFormats: PGLint; nNumFormats: PGLuint): BOOL; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_ARB_render_texture
  wglBindTexImageARB: function(hPbuffer: HPBUFFERARB; iBuffer: TGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglReleaseTexImageARB: function(hPbuffer: HPBUFFERARB; iBuffer: TGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglSetPbufferAttribARB: function(hPbuffer: HPBUFFERARB; const piAttribList: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_EXT_display_color_table
  wglCreateDisplayColorTableEXT: function(id: TGLushort): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglLoadDisplayColorTableEXT: function(const table: PGLushort; length: TGLuint): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglBindDisplayColorTableEXT: function(id: TGLushort): TGLboolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglDestroyDisplayColorTableEXT: procedure(id: TGLushort); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_EXT_extensions_string
  wglGetExtensionsStringEXT: function(): PChar; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_EXT_make_current_read
  wglMakeContextCurrentEXT: function(hDrawDC: HDC; hReadDC: HDC; hglrc: HGLRC): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetCurrentReadDCEXT: function(): HDC; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_EXT_pbuffer
  wglCreatePbufferEXT: function(hDC: HDC; iPixelFormat: TGLint; iWidth: TGLint; iHeight: TGLint; const piAttribList: PGLint): HPBUFFEREXT; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetPbufferDCEXT: function(hPbuffer: HPBUFFEREXT): HDC; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglReleasePbufferDCEXT: function(hPbuffer: HPBUFFEREXT; hDC: HDC): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglDestroyPbufferEXT: function(hPbuffer: HPBUFFEREXT): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglQueryPbufferEXT: function(hPbuffer: HPBUFFEREXT; iAttribute: TGLint; piValue: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_EXT_pixel_format
  wglGetPixelFormatAttribivEXT: function(hdc: HDC; iPixelFormat: TGLint; iLayerPlane: TGLint; nAttributes: TGLuint; piAttributes: PGLint; piValues: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetPixelFormatAttribfvEXT: function(hdc: HDC; iPixelFormat: TGLint; iLayerPlane: TGLint; nAttributes: TGLuint; piAttributes: PGLint; pfValues: PGLfloat): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglChoosePixelFormatEXT: function(hdc: HDC; const piAttribIList: PGLint; const pfAttribFList: PGLfloat; nMaxFormats: TGLuint; piFormats: PGLint; nNumFormats: PGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_EXT_swap_control
  wglSwapIntervalEXT: function(interval: TGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetSwapIntervalEXT: function(): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_I3D_digital_video_control
  wglGetDigitalVideoParametersI3D: function(hDC: HDC; iAttribute: TGLint; piValue: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglSetDigitalVideoParametersI3D: function(hDC: HDC; iAttribute: TGLint; const piValue: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_I3D_gamma
  wglGetGammaTableParametersI3D: function(hDC: HDC; iAttribute: TGLint; piValue: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglSetGammaTableParametersI3D: function(hDC: HDC; iAttribute: TGLint; const piValue: PGLint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetGammaTableI3D: function(hDC: HDC; iEntries: TGLint; puRed: PGLushort; puGreen: PGLushort; puBlue: PGLushort): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglSetGammaTableI3D: function(hDC: HDC; iEntries: TGLint; const puRed: PGLushort; const puGreen: PGLushort; const puBlue: PGLushort): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_I3D_genlock
  wglEnableGenlockI3D: function(hDC: HDC): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglDisableGenlockI3D: function(hDC: HDC): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglIsEnabledGenlockI3D: function(hDC: HDC; pFlag: Boolean): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGenlockSourceI3D: function(hDC: HDC; uSource: TGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetGenlockSourceI3D: function(hDC: HDC; uSource: PGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGenlockSourceEdgeI3D: function(hDC: HDC; uEdge: TGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetGenlockSourceEdgeI3D: function(hDC: HDC; uEdge: PGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGenlockSampleRateI3D: function(hDC: HDC; uRate: TGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetGenlockSampleRateI3D: function(hDC: HDC; uRate: PGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGenlockSourceDelayI3D: function(hDC: HDC; uDelay: TGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglGetGenlockSourceDelayI3D: function(hDC: HDC; uDelay: PGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglQueryGenlockMaxSourceDelayI3D: function(hDC: HDC; uMaxLineDelay: PGLuint; uMaxPixelDelay: PGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_I3D_image_buffer
  wglCreateImageBufferI3D: function(hDC: HDC; dwSize: TGLuint; uFlags: TGLuint): TGLvoid; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglDestroyImageBufferI3D: function(hDC: HDC; pAddress: TGLvoid): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglAssociateImageBufferEventsI3D: function(hDC: HDC; const pEvent: THandle; const pAddress: PGLvoid; const pSize: PGLuint; count: TGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglReleaseImageBufferEventsI3D: function(hDC: HDC; const pAddress: PGLvoid; count: TGLuint): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_I3D_swap_frame_lock
  wglEnableFrameLockI3D: function(): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglDisableFrameLockI3D: function(): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglIsEnabledFrameLockI3D: function(pFlag: Boolean): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglQueryFrameLockMasterI3D: function(pFlag: Boolean): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

  // WGL_I3D_swap_frame_usage
  wglGetFrameUsageI3D: function(pUsage: PGLfloat): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglBeginFrameTrackingI3D: function(): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglEndFrameTrackingI3D: function(): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  wglQueryFrameTrackingI3D: function(pFrameCount: PGLuint; pMissedFrames: PGLuint; pLastMissedUsage: PGLfloat): Boolean; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}

{$ENDIF}


  // GL_ARB_vertex_shader
  glGetActiveAttribARB: procedure(programobj:GLhandleARB;index:GLuint;maxLength:GLsizei;var length:GLsizei;var size:GLint;var _type:GLenum;name:PChar);stdcall;
  glGetAttribLocationARB: function(programObj:GLhandleARB;const char:PChar):glint;stdcall;
  glBindAttribLocationARB: procedure(programObj:GLhandleARB;index:GLuint;const name:PChar);stdcall;
  //glGetVertexAttribPointervARB: procedure(index: gluint; pname: glenum; p:PPointer); stdcall;

  // GL_ARB_SHADER_OBJECTS
  glDeleteObjectARB: procedure(Obj: GLHandleARB); stdcall;
  glGetHandleARB: function(pname: GlEnum):GLHandleARB; stdcall;
  glDetachObjectARB: procedure(container, attached: GLHandleARB); stdcall;
  glCreateShaderObjectARB: function(shaderType: glenum):GLHandleARB; stdcall;
  glShaderSourceARB: procedure(shaderObj :GLHandleARB; count:glsizei; _string:PPGLCharARB; lengths:pglint);stdcall;
  glCompileShaderARB: procedure(shaderObj: GLHandleARB); stdcall;
  glCreateProgramObjectARB: function:GLHandleARB; stdcall;
  glAttachObjectARB: procedure(programObj, shaderObj:GLhandleARB); stdcall;
  glLinkProgramARB: procedure(programObj: GLHandleARB); stdcall;
  glUseProgramObjectARB: procedure(programObj:GLHandleARB); stdcall;
  glValidateProgramARB: procedure(programObj: GLhandleARB); stdcall;
  glUniform1fARB: procedure(location:glint;v0:glfloat); stdcall;
  glUniform2fARB: procedure(location:glint;v0,v1:glfloat); stdcall;
  glUniform3fARB: procedure(location:glint;v0,v1,v2:glfloat); stdcall;
  glUniform4fARB: procedure(location:glint;v0,v1,v2,v3:glfloat); stdcall;
  glUniform1iARB: procedure(location:glint;v0:glint); stdcall;
  glUniform2iARB: procedure(location:glint;v0,v1:glint); stdcall;
  glUniform3iARB: procedure(location:glint;v0,v1,v2:glint); stdcall;
  glUniform4iARB: procedure(location:glint;v0,v1,v2,v3:glint); stdcall;
  glUniform1fvARB: procedure(location:glint; count :  GLsizei; value:pglfloat); stdcall;
  glUniform2fvARB: procedure(location:glint; count :  GLsizei; value:pglfloat); stdcall;
  glUniform3fvARB: procedure(location:glint; count :  GLsizei; value:pglfloat); stdcall;
  glUniform4fvARB: procedure(location:glint; count :  GLsizei; value:pglfloat); stdcall;
  glUniform1ivARB: procedure(location:glint; count :  GLsizei; value:pglint); stdcall;
  glUniform2ivARB: procedure(location:glint; count :  GLsizei; value:pglint); stdcall;
  glUniform3ivARB: procedure(location:glint; count :  GLsizei; value:pglint); stdcall;
  glUniform4ivARB: procedure(location:glint; count :  GLsizei; value:pglint); stdcall;
  glUniformMatrix2fvARB: procedure(location:glint;count:glsizei;transpose:glboolean;value:pglfloat); stdcall;
  glUniformMatrix3fvARB: procedure(location:glint;count:glsizei;transpose:glboolean;value:pglfloat); stdcall;
  glUniformMatrix4fvARB: procedure(location:glint;count:glsizei;transpose:glboolean;value:pglfloat); stdcall;
  glGetObjectParameterfvARB: procedure(Obj:GLHandleARB; pname:GLEnum; params:PGLFloat); stdcall;
  glGetObjectParameterivARB: procedure(Obj:GLHandleARB; pname:GLEnum; params:PGLInt); stdcall;
  glGetInfoLogARB: procedure(shaderObj:GLHandleARB; maxLength:glsizei; var length:glint;infoLog:PChar); stdcall;
  glGetAttachedObjectsARB: procedure(programobj:GLhandleARB; maxCount:GLsizei; var count:GLsizei;objects:PGLhandleARB); stdcall;
  glGetUniformLocationARB: function(programObj:GLhandleARB; const char:PChar):glint; stdcall;
  glGetActiveUniformARB:procedure(programobj:GLhandleARB;index:GLuint;maxLength:GLsizei;var length:GLsizei;var size:GLint;var _type:GLenum;name:PChar); stdcall;
  glGetUniformfvARB: procedure(programObj: GLhandleARB; location:GLint; params:PGLfloat); stdcall;
  glGetUniformivARB: procedure(programObj: GLhandleARB; location:GLint; params:PGLInt); stdcall;
  glGetShaderSourceARB: procedure(shader:GLhandleARB; maxLength:GLsizei; var length:GLsizei; source:PChar); stdcall;

  // GL_ARB_Occlusion_Query
  glGenQueriesARB:procedure(n:GLsizei;ids:PGLuint);stdcall;
  glDeleteQueriesARB:procedure(n:GLsizei;const ids:PGLuint);stdcall;
  glIsQueryARB:function(id:GLuint):boolean;stdcall;
  glBeginQueryARB:procedure(target:GLenum;id:GLuint);stdcall;
  glEndQueryARB:procedure(target:GLenum);stdcall;
  glGetQueryivARB:procedure(target,pname:GLenum;params:PGLint);stdcall;
  glGetQueryObjectivARB:procedure(id:GLuint;pname:GLenum;params:PGLint);stdcall;
  glGetQueryObjectuivARB:procedure(id:GLuint;pname:GLenum;params:PGLuint);stdcall;

  // ARB less version for GL 1.5
  glGenQueries:procedure(n:GLsizei;ids:PGLuint);stdcall;
  glDeleteQueries:procedure(n:GLsizei;const ids:PGLuint);stdcall;
  glIsQuery:function(id:GLuint):boolean;stdcall;
  glBeginQuery:procedure(target:GLenum;id:GLuint);stdcall;
  glEndQuery:procedure(target:GLenum);stdcall;
  glGetQueryiv:procedure(target,pname:GLenum;params:PGLint);stdcall;
  glGetQueryObjectiv:procedure(id:GLuint;pname:GLenum;params:PGLint);stdcall;
  glGetQueryObjectuiv:procedure(id:GLuint;pname:GLenum;params:PGLuint);stdcall;

  // GL utility functions and procedures
  gluErrorString: function(errCode: TGLEnum): PChar; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluGetString: function(name: TGLEnum): PChar; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluOrtho2D: procedure(left, right, bottom, top: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluPerspective: procedure(fovy, aspect, zNear, zFar: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluPickMatrix: procedure(x, y, width, height: TGLdouble; viewport: TVector4i); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluLookAt: procedure(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz: TGLdouble); {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluProject: function(objx, objy, objz: TGLdouble; modelMatrix: TGLMatrixd4; projMatrix: TGLMatrixd4; viewport: TVector4i; winx, winy, winz: PGLdouble): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluUnProject: function(winx, winy, winz: TGLdouble; modelMatrix: TGLMatrixd4; projMatrix: TGLMatrixd4; viewport: TVector4i;   objx, objy, objz: PGLdouble): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluScaleImage: function(format: TGLEnum; widthin, heightin: TGLint; typein: TGLEnum; datain: Pointer; widthout, heightout: TGLint; typeout: TGLEnum; dataout: Pointer): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluBuild1DMipmaps: function(target: TGLEnum; components, width: TGLint; format, atype: TGLEnum; data: Pointer): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}
  gluBuild2DMipmaps: function(target: TGLEnum; components, width, height: TGLint; format, atype: TGLEnum; Data: Pointer): TGLint; {$IFDEF Win32} stdcall; {$ELSE} cdecl; {$ENDIF}


type
 TRCOptions = set of (opDoubleBuffered,opGDI,opStereo);

var
  LibHandle          : THandle = 0;
  GLULibHandle       : THandle = 0;
  LastPixelFormat    : Integer;
  ExtensionsRead     : Boolean;
  ImplementationRead : Boolean;
(*
{$IFDEF WIN32}
function InitOpenGL(LibName: String = 'OpenGL32.dll';GLULibName : String = 'GLU32.dll'): Boolean;
{$ELSE}
function InitOpenGL(LibName: String = 'libGL.so.1';GLULibName : String = 'libGLU.so.1'): Boolean;
{$ENDIF}
procedure ClearExtensions;
procedure ReadExtensions;
procedure ReadImplementationProperties;
{$IFDEF WIN32}
// =============================================================================
// Helper-Functions
// =============================================================================
function CreateRenderingContext(DC : HDC;Options : TRCOptions;ColorBits,ZBits,StencilBits,AccumBits,AuxBuffers : Integer;Layer : Integer) : HGLRC;
procedure ActivateRenderingContext(DC : HDC;RC : HGLRC);
procedure DeactivateRenderingContext;
procedure DestroyRenderingContext(RC : HGLRC);
{$ENDIF}
*)

{$IFNDEF Win32}
// Added by bero
const
  RTLD_LAZY         = $001;
  RTLD_NOW          = $002;
  RTLD_BINDING_MASK = $003;
  LibraryLib        = {$ifdef Linux}'dl'{$else}'c'{$endif};

function LoadLibraryEx(Name : PChar; Flags : LongInt) : Pointer; cdecl; external LibraryLib name 'dlopen';
function GetProcAddressEx(Lib : Pointer; Name : PChar) : Pointer; cdecl; external LibraryLib name 'dlsym';
function FreeLibraryEx(Lib : Pointer) : LongInt; cdecl; external LibraryLib name 'dlclose';

function LoadLibrary(Name : PChar) : THandle;
begin
 Result := THandle(LoadLibraryEx(Name, RTLD_LAZY));
end;

function GetProcAddress(LibHandle : THandle; ProcName : PChar) : Pointer;
begin
 Result := GetProcAddressEx(Pointer(LibHandle), ProcName);
end;

function FreeLibrary(LibHandle : THandle) : Boolean;
begin
 if LibHandle = 0 then
   Result := False
  else
   Result := FreeLibraryEx(Pointer(LibHandle)) = 0;
end;

function wglGetProcAddress(ProcName : PChar) : Pointer;
begin
 Result := GetProcAddress(LibHandle, ProcName);
end;

{$ENDIF}




