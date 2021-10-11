// Thanks Mars!
function glProcedure(ProcName : PChar) : Pointer;
begin
Result := NIL;
{$IFDEF Win32}
// Changed by bero
if Addr(wglGetProcAddress) <> NIL then
 Result := wglGetProcAddress(ProcName);
if result <> NIL then
 exit;
{$ENDIF}
Result := GetProcAddress(LibHandle, ProcName);
end;

function InitOpenGL(LibName: String; GLULibName : String): Boolean;
begin
Result       := False;
if LibHandle<>0 then FreeLibrary(LibHandle);
if GLULibHandle<>0 then FreeLibrary(GLULibHandle);
LibHandle    := LoadLibrary(PChar(LibName));
GLULibHandle := LoadLibrary(PChar(GLULibName));

{$IFDEF Win32}
 // Changed by bero
wglGetProcAddress := GetProcAddress(LibHandle, 'wglGetProcAddress');
{$ENDIF}

if (LibHandle <> 0) then
 begin
 // window support routines (WGL) ==============================================
{$IFDEF Win32}
 // Changed by bero
 wglCopyContext              := glProcedure('wglCopyContext');
 wglCreateLayerContext       := glProcedure('wglCreateLayerContext');
 wglCreateContext            := glProcedure('wglCreateContext');
 wglDeleteContext            := glProcedure('wglDeleteContext');
 wglDescribeLayerPlane       := glProcedure('wglDescribeLayerPlane');
 wglGetCurrentContext        := glProcedure('wglGetCurrentContext');
 wglGetCurrentDC             := glProcedure('wglGetCurrentDC');
 wglGetLayerPaletteEntries   := glProcedure('wglGetLayerPaletteEntries');
 wglMakeCurrent              := glProcedure('wglMakeCurrent');
 wglRealizeLayerPalette      := glProcedure('wglRealizeLayerPalette');
 wglSetLayerPaletteEntries   := glProcedure('wglSetLayerPaletteEntries');
 wglShareLists               := glProcedure('wglShareLists');
 wglSwapLayerBuffers         := glProcedure('wglSwapLayerBuffers');
 wglSwapMultipleBuffers      := glProcedure('wglSwapMultipleBuffers');
 wglUseFontBitmapsA          := glProcedure('wglUseFontBitmapsA');
 wglUseFontOutlinesA         := glProcedure('wglUseFontOutlinesA');
 wglUseFontBitmapsW          := glProcedure('wglUseFontBitmapsW');
 wglUseFontOutlinesW         := glProcedure('wglUseFontOutlinesW');
 wglUseFontBitmaps           := glProcedure('wglUseFontBitmapsA');
 wglUseFontOutlines          := glProcedure('wglUseFontOutlinesA');
{$ENDIF}
 Result := True;
 end;

if GLULibHandle <> 0 then
 begin
 // GLU ========================================================================
 gluBuild1DMipmaps           := GetProcAddress(GLULibHandle, 'gluBuild1DMipmaps');
 gluBuild2DMipmaps           := GetProcAddress(GLULibHandle, 'gluBuild2DMipmaps');
 gluErrorString              := GetProcAddress(GLULibHandle, 'gluErrorString');
 gluGetString                := GetProcAddress(GLULibHandle, 'gluGetString');
 gluLookAt                   := GetProcAddress(GLULibHandle, 'gluLookAt');
 gluOrtho2D                  := GetProcAddress(GLULibHandle, 'gluOrtho2D');
 gluPerspective              := GetProcAddress(GLULibHandle, 'gluPerspective');
 gluPickMatrix               := GetProcAddress(GLULibHandle, 'gluPickMatrix');
 gluProject                  := GetProcAddress(GLULibHandle, 'gluProject');
 gluScaleImage               := GetProcAddress(GLULibHandle, 'gluScaleImage');
 gluUnProject                := GetProcAddress(GLULibHandle, 'gluUnProject');
 end;
end;

// =============================================================================
// ClearExtensions
// =============================================================================
procedure ClearExtensions;
begin
// GL_ARB_matrix_palette
glCurrentPaletteMatrixARB := nil;
glMatrixIndexubvARB       := nil;
glMatrixIndexusvARB       := nil;
glMatrixIndexuivARB       := nil;
glMatrixIndexPointerARB   := nil;
// GL_ARB_multisample
glSampleCoverageARB := nil;
// GL_ARB_multitexture
glActiveTextureARB       := nil;
glClientActiveTextureARB := nil;
glMultiTexCoord1fARB     := nil;
glMultiTexCoord1fvARB    := nil;
glMultiTexCoord2fARB     := nil;
glMultiTexCoord2fvARB    := nil;
glMultiTexCoord3fARB     := nil;
glMultiTexCoord3fvARB    := nil;
glMultiTexCoord4fARB     := nil;
glMultiTexCoord4fvARB    := nil;
// GL_ARB_point_parameters
glPointParameterfARB  := nil;
glPointParameterfvARB := nil;
// GL_ARB_texture_compression
glCompressedTexImage3DARB    := nil;
glCompressedTexImage2DARB    := nil;
glCompressedTexImage1DARB    := nil;
glCompressedTexSubImage3DARB := nil;
glCompressedTexSubImage2DARB := nil;
glCompressedTexSubImage1DARB := nil;
glGetCompressedTexImageARB   := nil;
// GL_ARB_transpose_matrix
glLoadTransposeMatrixfARB := nil;
glLoadTransposeMatrixdARB := nil;
glMultTransposeMatrixfARB := nil;
glMultTransposeMatrixdARB := nil;
// GL_ARB_vertex_blend
glWeightbvARB      := nil;
glWeightsvARB      := nil;
glWeightivARB      := nil;
glWeightfvARB      := nil;
glWeightdvARB      := nil;
glWeightubvARB     := nil;
glWeightusvARB     := nil;
glWeightuivARB     := nil;
glWeightPointerARB := nil;
glVertexBlendARB   := nil;
// GL_ARB_vertex_buffer_object
glBindBufferARB           := nil;
glDeleteBuffersARB        := nil;
glGenBuffersARB           := nil;
glIsBufferARB             := nil;
glBufferDataARB           := nil;
glBufferSubDataARB        := nil;
glGetBufferSubDataARB     := nil;
glMapBufferARB            := nil;
glUnmapBufferARB          := nil;
glGetBufferParameterivARB := nil;
glGetBufferPointervARB    := nil;
// ARB less version fo GL 1.5
glBindBuffer           := nil;
glDeleteBuffers        := nil;
glGenBuffers           := nil;
glIsBuffer             := nil;
glBufferData           := nil;
glBufferSubData        := nil;
glGetBufferSubData     := nil;
glMapBuffer            := nil;
glUnmapBuffer          := nil;
glGetBufferParameteriv := nil;
glGetBufferPointerv    := nil;
// GL_ARB_vertex_program
glVertexAttrib1dARB             := nil;
glVertexAttrib1dvARB            := nil;
glVertexAttrib1fARB             := nil;
glVertexAttrib1fvARB            := nil;
glVertexAttrib1sARB             := nil;
glVertexAttrib1svARB            := nil;
glVertexAttrib2dARB             := nil;
glVertexAttrib2dvARB            := nil;
glVertexAttrib2fARB             := nil;
glVertexAttrib2fvARB            := nil;
glVertexAttrib2sARB             := nil;
glVertexAttrib2svARB            := nil;
glVertexAttrib3dARB             := nil;
glVertexAttrib3dvARB            := nil;
glVertexAttrib3fARB             := nil;
glVertexAttrib3fvARB            := nil;
glVertexAttrib3sARB             := nil;
glVertexAttrib3svARB            := nil;
glVertexAttrib4NbvARB           := nil;
glVertexAttrib4NivARB           := nil;
glVertexAttrib4NsvARB           := nil;
glVertexAttrib4NubARB           := nil;
glVertexAttrib4NubvARB          := nil;
glVertexAttrib4NuivARB          := nil;
glVertexAttrib4NusvARB          := nil;
glVertexAttrib4bvARB            := nil;
glVertexAttrib4dARB             := nil;
glVertexAttrib4dvARB            := nil;
glVertexAttrib4fARB             := nil;
glVertexAttrib4fvARB            := nil;
glVertexAttrib4ivARB            := nil;
glVertexAttrib4sARB             := nil;
glVertexAttrib4svARB            := nil;
glVertexAttrib4ubvARB           := nil;
glVertexAttrib4uivARB           := nil;
glVertexAttrib4usvARB           := nil;
glVertexAttribPointerARB        := nil;
glEnableVertexAttribArrayARB    := nil;
glDisableVertexAttribArrayARB   := nil;
glProgramStringARB              := nil;
glBindProgramARB                := nil;
glDeleteProgramsARB             := nil;
glGenProgramsARB                := nil;
glProgramEnvParameter4dARB      := nil;
glProgramEnvParameter4dvARB     := nil;
glProgramEnvParameter4fARB      := nil;
glProgramEnvParameter4fvARB     := nil;
glProgramLocalParameter4dARB    := nil;
glProgramLocalParameter4dvARB   := nil;
glProgramLocalParameter4fARB    := nil;
glProgramLocalParameter4fvARB   := nil;
glGetProgramEnvParameterdvARB   := nil;
glGetProgramEnvParameterfvARB   := nil;
glGetProgramLocalParameterdvARB := nil;
glGetProgramLocalParameterfvARB := nil;
glGetProgramivARB               := nil;
glGetProgramStringARB           := nil;
glGetVertexAttribdvARB          := nil;
glGetVertexAttribfvARB          := nil;
glGetVertexAttribivARB          := nil;
glGetVertexAttribPointervARB    := nil;
glIsProgramARB                  := nil;


  glVertexAttrib1d := nil;
  glVertexAttrib1dv := nil;
  glVertexAttrib1f := nil;
  glVertexAttrib1fv := nil;
  glVertexAttrib1s := nil;
  glVertexAttrib1sv := nil;
  glVertexAttrib2d := nil;
  glVertexAttrib2dv := nil;
  glVertexAttrib2f := nil;
  glVertexAttrib2fv := nil;
  glVertexAttrib2s := nil;
  glVertexAttrib2sv := nil;
  glVertexAttrib3d := nil;
  glVertexAttrib3dv := nil;
  glVertexAttrib3f := nil;
  glVertexAttrib3fv := nil;
  glVertexAttrib3s := nil;
  glVertexAttrib3sv := nil;
  glVertexAttrib4Nbv := nil;
  glVertexAttrib4Niv := nil;
  glVertexAttrib4Nsv := nil;
  glVertexAttrib4Nub := nil;
  glVertexAttrib4Nubv := nil;
  glVertexAttrib4Nuiv := nil;
  glVertexAttrib4Nusv := nil;
  glVertexAttrib4bv := nil;
  glVertexAttrib4d := nil;
  glVertexAttrib4dv := nil;
  glVertexAttrib4f := nil;
  glVertexAttrib4fv := nil;
  glVertexAttrib4iv := nil;
  glVertexAttrib4s := nil;
  glVertexAttrib4sv := nil;
  glVertexAttrib4ubv := nil;
  glVertexAttrib4uiv := nil;
  glVertexAttrib4usv := nil;
  glVertexAttribPointer := nil;

// GL_ARB_window_pos
glWindowPos2fARB  := nil;
glWindowPos2fvARB := nil;
glWindowPos3fARB  := nil;
glWindowPos3fvARB := nil;
// GL_ARB_occlusion_query
glGenQueriesARB              := nil;
glDeleteQueriesARB           := nil;
glIsQueryARB                 := nil;
glBeginQueryARB              := nil;
glEndQueryARB                := nil;
glGetQueryivARB              := nil;
glGetQueryObjectivARB        := nil;
glGetQueryObjectuivARB       := nil;

// ARB less version for GL 1.5
glGenQueries              := nil;
glDeleteQueries           := nil;
glIsQuery                 := nil;
glBeginQuery              := nil;
glEndQuery                := nil;
glGetQueryiv              := nil;
glGetQueryObjectiv        := nil;
glGetQueryObjectuiv       := nil;

  // GL_SGIS_detail_texture
  glDetailTexFuncSGIS := nil;
  glGetDetailTexFuncSGIS := nil;

  // GL_SGIS_fog_function
  glFogFuncSGIS := nil;
  glGetFogFuncSGIS := nil;

  // GL_SGIS_multisample
  glSampleMaskSGIS := nil;
  glSamplePatternSGIS := nil;

  // GL_SGIS_pixel_texture
  glPixelTexGenParameteriSGIS := nil;
  glPixelTexGenParameterivSGIS := nil;
  glPixelTexGenParameterfSGIS := nil;
  glPixelTexGenParameterfvSGIS := nil;
  glGetPixelTexGenParameterivSGIS := nil;
  glGetPixelTexGenParameterfvSGIS := nil;

  // GL_SGIS_point_parameters
  glPointParameterfSGIS := nil;
  glPointParameterfvSGIS := nil;

  // GL_SGIS_sharpen_texture
  glSharpenTexFuncSGIS := nil;
  glGetSharpenTexFuncSGIS := nil;

  // GL_SGIS_texture4D
  glTexImage4DSGIS := nil;
  glTexSubImage4DSGIS := nil;

  // GL_SGIS_texture_color_mask
  glTextureColorMaskSGIS := nil;

  // GL_SGIS_texture_filter4
  glGetTexFilterFuncSGIS := nil;
  glTexFilterFuncSGIS := nil;

  // GL_SGI_color_table
  glColorTableSGI := nil;
  glColorTableParameterfvSGI := nil;
  glColorTableParameterivSGI := nil;
  glCopyColorTableSGI := nil;
  glGetColorTableSGI := nil;
  glGetColorTableParameterfvSGI := nil;
  glGetColorTableParameterivSGI := nil;

{$IFDEF Win32}
 // Changed by bero
  // WGL_ARB_buffer_region
  wglCreateBufferRegionARB := nil;
  wglDeleteBufferRegionARB := nil;
  wglSaveBufferRegionARB := nil;
  wglRestoreBufferRegionARB := nil;

  // WGL_ARB_extensions_string
  wglGetExtensionsStringARB := nil;

  // WGL_ARB_make_current_read
  wglMakeContextCurrentARB := nil;
  wglGetCurrentReadDCARB := nil;

  // WGL_ARB_pbuffer
  wglCreatePbufferARB := nil;
  wglGetPbufferDCARB := nil;
  wglReleasePbufferDCARB := nil;
  wglDestroyPbufferARB := nil;
  wglQueryPbufferARB := nil;

  // WGL_ARB_pixel_format
  wglGetPixelFormatAttribivARB := nil;
  wglGetPixelFormatAttribfvARB := nil;
  wglChoosePixelFormatARB := nil;

  // WGL_ARB_render_texture
  wglBindTexImageARB := nil;
  wglReleaseTexImageARB := nil;
  wglSetPbufferAttribARB := nil;

  // WGL_EXT_display_color_table
  wglCreateDisplayColorTableEXT := nil;
  wglLoadDisplayColorTableEXT := nil;
  wglBindDisplayColorTableEXT := nil;
  wglDestroyDisplayColorTableEXT := nil;

  // WGL_EXT_extensions_string
  wglGetExtensionsStringEXT := nil;

  // WGL_EXT_make_current_read
  wglMakeContextCurrentEXT := nil;
  wglGetCurrentReadDCEXT := nil;

  // WGL_EXT_pbuffer
  wglCreatePbufferEXT := nil;
  wglGetPbufferDCEXT := nil;
  wglReleasePbufferDCEXT := nil;
  wglDestroyPbufferEXT := nil;
  wglQueryPbufferEXT := nil;

  // WGL_EXT_pixel_format
  wglGetPixelFormatAttribivEXT := nil;
  wglGetPixelFormatAttribfvEXT := nil;
  wglChoosePixelFormatEXT := nil;

  // WGL_EXT_swap_control
  wglSwapIntervalEXT := nil;
  wglGetSwapIntervalEXT := nil;

  // WGL_I3D_digital_video_control
  wglGetDigitalVideoParametersI3D := nil;
  wglSetDigitalVideoParametersI3D := nil;

  // WGL_I3D_gamma
  wglGetGammaTableParametersI3D := nil;
  wglSetGammaTableParametersI3D := nil;
  wglGetGammaTableI3D := nil;
  wglSetGammaTableI3D := nil;

  // WGL_I3D_genlock
  wglEnableGenlockI3D := nil;
  wglDisableGenlockI3D := nil;
  wglIsEnabledGenlockI3D := nil;
  wglGenlockSourceI3D := nil;
  wglGetGenlockSourceI3D := nil;
  wglGenlockSourceEdgeI3D := nil;
  wglGetGenlockSourceEdgeI3D := nil;
  wglGenlockSampleRateI3D := nil;
  wglGetGenlockSampleRateI3D := nil;
  wglGenlockSourceDelayI3D := nil;
  wglGetGenlockSourceDelayI3D := nil;
  wglQueryGenlockMaxSourceDelayI3D := nil;

  // WGL_I3D_image_buffer
  wglCreateImageBufferI3D := nil;
  wglDestroyImageBufferI3D := nil;
  wglAssociateImageBufferEventsI3D := nil;
  wglReleaseImageBufferEventsI3D := nil;

  // WGL_I3D_swap_frame_lock
  wglEnableFrameLockI3D := nil;
  wglDisableFrameLockI3D := nil;
  wglIsEnabledFrameLockI3D := nil;
  wglQueryFrameLockMasterI3D := nil;

  // WGL_I3D_swap_frame_usage
  wglGetFrameUsageI3D := nil;
  wglBeginFrameTrackingI3D := nil;
  wglEndFrameTrackingI3D := nil;
  wglQueryFrameTrackingI3D := nil;


{$ENDIF}

  // GLU
  gluBuild1DMipmaps := nil;
  gluBuild2DMipmaps := nil;
  gluErrorString := nil;
  gluGetString := nil;
  gluLookAt := nil;
  gluOrtho2D := nil;
  gluPerspective := nil;
  gluPickMatrix := nil;
  gluProject := nil;
  gluScaleImage := nil;
  gluUnProject := nil;

{$IFDEF Win32}
 // Changed by bero
//  wglGetProcAddress := nil;
  wglCopyContext := nil;
  wglCreateContext := nil;
  wglCreateLayerContext := nil;
  wglDeleteContext := nil;
  wglDescribeLayerPlane := nil;
  wglGetCurrentContext := nil;
  wglGetCurrentDC := nil;
  wglGetLayerPaletteEntries := nil;
  wglMakeCurrent := nil;
  wglRealizeLayerPalette := nil;
  wglSetLayerPaletteEntries := nil;
  wglShareLists := nil;
  wglSwapLayerBuffers := nil;
  wglSwapMultipleBuffers := nil;
  wglUseFontBitmapsA := nil;
  wglUseFontOutlinesA := nil;
  wglUseFontBitmapsW := nil;
  wglUseFontOutlinesW := nil;
  wglUseFontBitmaps := nil;
  wglUseFontOutlines := nil;
{$ENDIF}
end;


// =============================================================================
//  ReadExtensions
// =============================================================================
procedure ReadExtensions;
begin
  if LibHandle <> 0 then
   begin
 // GL_VERSION_1_1 =============================================================
 glAccum                     := glProcedure('glAccum');
 glAlphaFunc                 := glProcedure('glAlphaFunc');
 glAreTexturesResident       := glProcedure('glAreTexturesResident');
 glArrayElement              := glProcedure('glArrayElement');
 glBegin                     := glProcedure('glBegin');
 glBindTexture               := glProcedure('glBindTexture');
 glBitmap                    := glProcedure('glBitmap');
 glBlendFunc                 := glProcedure('glBlendFunc');
 glCallList                  := glProcedure('glCallList');
 glCallLists                 := glProcedure('glCallLists');
 glClear                     := glProcedure('glClear');
 glClearAccum                := glProcedure('glClearAccum');
 glClearColor                := glProcedure('glClearColor');
 glClearDepth                := glProcedure('glClearDepth');
 glClearIndex                := glProcedure('glClearIndex');
 glClearStencil              := glProcedure('glClearStencil');
 glClipPlane                 := glProcedure('glClipPlane');
 glColor3f                   := glProcedure('glColor3f');
 glColor3fv                  := glProcedure('glColor3fv');
 glColor4f                   := glProcedure('glColor4f');
 glColor4fv                  := glProcedure('glColor4fv');
 glColorMask                 := glProcedure('glColorMask');
 glColorMaterial             := glProcedure('glColorMaterial');
 glColorPointer              := glProcedure('glColorPointer');
 glCopyPixels                := glProcedure('glCopyPixels');
 glCopyTexImage1D            := glProcedure('glCopyTexImage1D');
 glCopyTexImage2D            := glProcedure('glCopyTexImage2D');
 glCopyTexSubImage1D         := glProcedure('glCopyTexSubImage1D');
 glCopyTexSubImage2D         := glProcedure('glCopyTexSubImage2D');
 glCullFace                  := glProcedure('glCullFace');
 glDeleteLists               := glProcedure('glDeleteLists');
 glDeleteTextures            := glProcedure('glDeleteTextures');
 glDepthFunc                 := glProcedure('glDepthFunc');
 glDepthMask                 := glProcedure('glDepthMask');
 glDepthRange                := glProcedure('glDepthRange');
 glDisable                   := glProcedure('glDisable');
 glDisableClientState        := glProcedure('glDisableClientState');
 glDrawArrays                := glProcedure('glDrawArrays');
 glDrawBuffer                := glProcedure('glDrawBuffer');
 glDrawElements              := glProcedure('glDrawElements');
 glDrawPixels                := glProcedure('glDrawPixels');
 glEdgeFlag                  := glProcedure('glEdgeFlag');
 glEdgeFlagPointer           := glProcedure('glEdgeFlagPointer');
 glEdgeFlagv                 := glProcedure('glEdgeFlagv');
 glEnable                    := glProcedure('glEnable');
 glEnableClientState         := glProcedure('glEnableClientState');
 glEnd                       := glProcedure('glEnd');
 glEndList                   := glProcedure('glEndList');
 glEvalCoord1d               := glProcedure('glEvalCoord1d');
 glEvalCoord1dv              := glProcedure('glEvalCoord1dv');
 glEvalCoord1f               := glProcedure('glEvalCoord1f');
 glEvalCoord1fv              := glProcedure('glEvalCoord1fv');
 glEvalCoord2d               := glProcedure('glEvalCoord2d');
 glEvalCoord2dv              := glProcedure('glEvalCoord2dv');
 glEvalCoord2f               := glProcedure('glEvalCoord2f');
 glEvalCoord2fv              := glProcedure('glEvalCoord2fv');
 glEvalMesh1                 := glProcedure('glEvalMesh1');
 glEvalMesh2                 := glProcedure('glEvalMesh2');
 glEvalPoint1                := glProcedure('glEvalPoint1');
 glEvalPoint2                := glProcedure('glEvalPoint2');
 glFeedbackBuffer            := glProcedure('glFeedbackBuffer');
 glFinish                    := glProcedure('glFinish');
 glFlush                     := glProcedure('glFlush');
 glFogf                      := glProcedure('glFogf');
 glFogfv                     := glProcedure('glFogfv');
 glFogi                      := glProcedure('glFogi');
 glFogiv                     := glProcedure('glFogiv');
 glFrontFace                 := glProcedure('glFrontFace');
 glFrustum                   := glProcedure('glFrustum');
 glGenLists                  := glProcedure('glGenLists');
 glGenTextures               := glProcedure('glGenTextures');
 glGetBooleanv               := glProcedure('glGetBooleanv');
 glGetClipPlane              := glProcedure('glGetClipPlane');
 glGetDoublev                := glProcedure('glGetDoublev');
 glGetError                  := glProcedure('glGetError');
 glGetFloatv                 := glProcedure('glGetFloatv');
 glGetIntegerv               := glProcedure('glGetIntegerv');
 glGetLightfv                := glProcedure('glGetLightfv');
 glGetLightiv                := glProcedure('glGetLightiv');
 glGetMapdv                  := glProcedure('glGetMapdv');
 glGetMapfv                  := glProcedure('glGetMapfv');
 glGetMapiv                  := glProcedure('glGetMapiv');
 glGetMaterialfv             := glProcedure('glGetMaterialfv');
 glGetMaterialiv             := glProcedure('glGetMaterialiv');
 glGetPixelMapfv             := glProcedure('glGetPixelMapfv');
 glGetPixelMapuiv            := glProcedure('glGetPixelMapuiv');
 glGetPixelMapusv            := glProcedure('glGetPixelMapusv');
 glGetPointerv               := glProcedure('glGetPointerv');
 glGetPolygonStipple         := glProcedure('glGetPolygonStipple');
 glGetString                 := glProcedure('glGetString');
 glGetTexEnvfv               := glProcedure('glGetTexEnvfv');
 glGetTexEnviv               := glProcedure('glGetTexEnviv');
 glGetTexGendv               := glProcedure('glGetTexGendv');
 glGetTexGenfv               := glProcedure('glGetTexGenfv');
 glGetTexGeniv               := glProcedure('glGetTexGeniv');
 glGetTexImage               := glProcedure('glGetTexImage');
 glGetTexLevelParameterfv    := glProcedure('glGetTexLevelParameterfv');
 glGetTexLevelParameteriv    := glProcedure('glGetTexLevelParameteriv');
 glGetTexParameterfv         := glProcedure('glGetTexParameterfv');
 glGetTexParameteriv         := glProcedure('glGetTexParameteriv');
 glHint                      := glProcedure('glHint');
 glIndexMask                 := glProcedure('glIndexMask');
 glIndexPointer              := glProcedure('glIndexPointer');
 glIndexd                    := glProcedure('glIndexd');
 glIndexdv                   := glProcedure('glIndexdv');
 glIndexf                    := glProcedure('glIndexf');
 glIndexfv                   := glProcedure('glIndexfv');
 glIndexi                    := glProcedure('glIndexi');
 glIndexiv                   := glProcedure('glIndexiv');
 glIndexs                    := glProcedure('glIndexs');
 glIndexsv                   := glProcedure('glIndexsv');
 glIndexub                   := glProcedure('glIndexub');
 glIndexubv                  := glProcedure('glIndexubv');
 glInitNames                 := glProcedure('glInitNames');
 glInterleavedArrays         := glProcedure('glInterleavedArrays');
 glIsEnabled                 := glProcedure('glIsEnabled');
 glIsList                    := glProcedure('glIsList');
 glIsTexture                 := glProcedure('glIsTexture');
 glLightModelf               := glProcedure('glLightModelf');
 glLightModelfv              := glProcedure('glLightModelfv');
 glLightModeli               := glProcedure('glLightModeli');
 glLightModeliv              := glProcedure('glLightModeliv');
 glLightf                    := glProcedure('glLightf');
 glLightfv                   := glProcedure('glLightfv');
 glLighti                    := glProcedure('glLighti');
 glLightiv                   := glProcedure('glLightiv');
 glLineStipple               := glProcedure('glLineStipple');
 glLineWidth                 := glProcedure('glLineWidth');
 glListBase                  := glProcedure('glListBase');
 glLoadIdentity              := glProcedure('glLoadIdentity');
 glLoadMatrixd               := glProcedure('glLoadMatrixd');
 glLoadMatrixf               := glProcedure('glLoadMatrixf');
 glLoadName                  := glProcedure('glLoadName');
 glLogicOp                   := glProcedure('glLogicOp');
 glMap1d                     := glProcedure('glMap1d');
 glMap1f                     := glProcedure('glMap1f');
 glMap2d                     := glProcedure('glMap2d');
 glMap2f                     := glProcedure('glMap2f');
 glMapGrid1d                 := glProcedure('glMapGrid1d');
 glMapGrid1f                 := glProcedure('glMapGrid1f');
 glMapGrid2d                 := glProcedure('glMapGrid2d');
 glMapGrid2f                 := glProcedure('glMapGrid2f');
 glMaterialf                 := glProcedure('glMaterialf');
 glMaterialfv                := glProcedure('glMaterialfv');
 glMateriali                 := glProcedure('glMateriali');
 glMaterialiv                := glProcedure('glMaterialiv');
 glMatrixMode                := glProcedure('glMatrixMode');
 glMultMatrixd               := glProcedure('glMultMatrixd');
 glMultMatrixf               := glProcedure('glMultMatrixf');
 glNewList                   := glProcedure('glNewList');
 glNormal3f                  := glProcedure('glNormal3f');
 glNormal3fv                 := glProcedure('glNormal3fv');
 glNormalPointer             := glProcedure('glNormalPointer');
 glOrtho                     := glProcedure('glOrtho');
 glPassThrough               := glProcedure('glPassThrough');
 glPixelMapfv                := glProcedure('glPixelMapfv');
 glPixelMapuiv               := glProcedure('glPixelMapuiv');
 glPixelMapusv               := glProcedure('glPixelMapusv');
 glPixelStoref               := glProcedure('glPixelStoref');
 glPixelStorei               := glProcedure('glPixelStorei');
 glPixelTransferf            := glProcedure('glPixelTransferf');
 glPixelTransferi            := glProcedure('glPixelTransferi');
 glPixelZoom                 := glProcedure('glPixelZoom');
 glPointSize                 := glProcedure('glPointSize');
 glPolygonMode               := glProcedure('glPolygonMode');
 glPolygonOffset             := glProcedure('glPolygonOffset');
 glPolygonStipple            := glProcedure('glPolygonStipple');
 glPopAttrib                 := glProcedure('glPopAttrib');
 glPopClientAttrib           := glProcedure('glPopClientAttrib');
 glPopMatrix                 := glProcedure('glPopMatrix');
 glPopName                   := glProcedure('glPopName');
 glPrioritizeTextures        := glProcedure('glPrioritizeTextures');
 glPushAttrib                := glProcedure('glPushAttrib');
 glPushClientAttrib          := glProcedure('glPushClientAttrib');
 glPushMatrix                := glProcedure('glPushMatrix');
 glPushName                  := glProcedure('glPushName');
 glRasterPos2d               := glProcedure('glRasterPos2d');
 glRasterPos2dv              := glProcedure('glRasterPos2dv');
 glRasterPos2f               := glProcedure('glRasterPos2f');
 glRasterPos2fv              := glProcedure('glRasterPos2fv');
 glRasterPos2i               := glProcedure('glRasterPos2i');
 glRasterPos2iv              := glProcedure('glRasterPos2iv');
 glRasterPos2s               := glProcedure('glRasterPos2s');
 glRasterPos2sv              := glProcedure('glRasterPos2sv');
 glRasterPos3d               := glProcedure('glRasterPos3d');
 glRasterPos3dv              := glProcedure('glRasterPos3dv');
 glRasterPos3f               := glProcedure('glRasterPos3f');
 glRasterPos3fv              := glProcedure('glRasterPos3fv');
 glRasterPos3i               := glProcedure('glRasterPos3i');
 glRasterPos3iv              := glProcedure('glRasterPos3iv');
 glRasterPos3s               := glProcedure('glRasterPos3s');
 glRasterPos3sv              := glProcedure('glRasterPos3sv');
 glRasterPos4d               := glProcedure('glRasterPos4d');
 glRasterPos4dv              := glProcedure('glRasterPos4dv');
 glRasterPos4f               := glProcedure('glRasterPos4f');
 glRasterPos4fv              := glProcedure('glRasterPos4fv');
 glRasterPos4i               := glProcedure('glRasterPos4i');
 glRasterPos4iv              := glProcedure('glRasterPos4iv');
 glRasterPos4s               := glProcedure('glRasterPos4s');
 glRasterPos4sv              := glProcedure('glRasterPos4sv');
 glReadBuffer                := glProcedure('glReadBuffer');
 glReadPixels                := glProcedure('glReadPixels');
 glRectd                     := glProcedure('glRectd');
 glRectdv                    := glProcedure('glRectdv');
 glRectf                     := glProcedure('glRectf');
 glRectfv                    := glProcedure('glRectfv');
 glRecti                     := glProcedure('glRecti');
 glRectiv                    := glProcedure('glRectiv');
 glRects                     := glProcedure('glRects');
 glRectsv                    := glProcedure('glRectsv');
 glRenderMode                := glProcedure('glRenderMode');
 glRotated                   := glProcedure('glRotated');
 glRotatef                   := glProcedure('glRotatef');
 glScaled                    := glProcedure('glScaled');
 glScalef                    := glProcedure('glScalef');
 glScissor                   := glProcedure('glScissor');
 glSelectBuffer              := glProcedure('glSelectBuffer');
 glShadeModel                := glProcedure('glShadeModel');
 glStencilFunc               := glProcedure('glStencilFunc');
 glStencilMask               := glProcedure('glStencilMask');
 glStencilOp                 := glProcedure('glStencilOp');
 glTexCoord1f                := glProcedure('glTexCoord1f');
 glTexCoord1fv               := glProcedure('glTexCoord1fv');
 glTexCoord2f                := glProcedure('glTexCoord2f');
 glTexCoord2fv               := glProcedure('glTexCoord2fv');
 glTexCoord3f                := glProcedure('glTexCoord3f');
 glTexCoord3fv               := glProcedure('glTexCoord3fv');
 glTexCoord4f                := glProcedure('glTexCoord4f');
 glTexCoord4fv               := glProcedure('glTexCoord4fv');
 glTexCoordPointer           := glProcedure('glTexCoordPointer');
 glTexEnvf                   := glProcedure('glTexEnvf');
 glTexEnvfv                  := glProcedure('glTexEnvfv');
 glTexEnvi                   := glProcedure('glTexEnvi');
 glTexEnviv                  := glProcedure('glTexEnviv');
 glTexGend                   := glProcedure('glTexGend');
 glTexGendv                  := glProcedure('glTexGendv');
 glTexGenf                   := glProcedure('glTexGenf');
 glTexGenfv                  := glProcedure('glTexGenfv');
 glTexGeni                   := glProcedure('glTexGeni');
 glTexGeniv                  := glProcedure('glTexGeniv');
 glTexImage1D                := glProcedure('glTexImage1D');
 glTexImage2D                := glProcedure('glTexImage2D');
 glTexParameterf             := glProcedure('glTexParameterf');
 glTexParameterfv            := glProcedure('glTexParameterfv');
 glTexParameteri             := glProcedure('glTexParameteri');
 glTexParameteriv            := glProcedure('glTexParameteriv');
 glTexSubImage1D             := glProcedure('glTexSubImage1D');
 glTexSubImage2D             := glProcedure('glTexSubImage2D');
 glTranslated                := glProcedure('glTranslated');
 glTranslatef                := glProcedure('glTranslatef');
 glVertex2f                  := glProcedure('glVertex2f');
 glVertex2fv                 := glProcedure('glVertex2fv');
 glVertex3f                  := glProcedure('glVertex3f');
 glVertex3fv                 := glProcedure('glVertex3fv');
 glVertex4f                  := glProcedure('glVertex4f');
 glVertex4fv                 := glProcedure('glVertex4fv');
 glVertexPointer             := glProcedure('glVertexPointer');
 glViewport                  := glProcedure('glViewport');
 // GL_VERSION_1_2 =============================================================
 glBlendColor                := glProcedure('glBlendColor');
 glBlendEquation             := glProcedure('glBlendEquation');
 glDrawRangeElements         := glProcedure('glDrawRangeElements');
 glColorTable                := glProcedure('glColorTable');
 glColorTableParameterfv     := glProcedure('glColorTableParameterfv');
 glColorTableParameteriv     := glProcedure('glColorTableParameteriv');
 glCopyColorTable            := glProcedure('glCopyColorTable');
 glGetColorTable             := glProcedure('glGetColorTable');
 glGetColorTableParameterfv  := glProcedure('glGetColorTableParameterfv');
 glGetColorTableParameteriv  := glProcedure('glGetColorTableParameteriv');
 glColorSubTable             := glProcedure('glColorSubTable');
 glCopyColorSubTable         := glProcedure('glCopyColorSubTable');
 glConvolutionFilter1D       := glProcedure('glConvolutionFilter1D');
 glConvolutionFilter2D       := glProcedure('glConvolutionFilter2D');
 glConvolutionParameterf     := glProcedure('glConvolutionParameterf');
 glConvolutionParameterfv    := glProcedure('glConvolutionParameterfv');
 glConvolutionParameteri     := glProcedure('glConvolutionParameteri');
 glConvolutionParameteriv    := glProcedure('glConvolutionParameteriv');
 glCopyConvolutionFilter1D   := glProcedure('glCopyConvolutionFilter1D');
 glCopyConvolutionFilter2D   := glProcedure('glCopyConvolutionFilter2D');
 glGetConvolutionFilter      := glProcedure('glGetConvolutionFilter');
 glGetConvolutionParameterfv := glProcedure('glGetConvolutionParameterfv');
 glGetConvolutionParameteriv := glProcedure('glGetConvolutionParameteriv');
 glGetSeparableFilter        := glProcedure('glGetSeparableFilter');
 glSeparableFilter2D         := glProcedure('glSeparableFilter2D');
 glGetHistogram              := glProcedure('glGetHistogram');
 glGetHistogramParameterfv   := glProcedure('glGetHistogramParameterfv');
 glGetHistogramParameteriv   := glProcedure('glGetHistogramParameteriv');
 glGetMinmax                 := glProcedure('glGetMinmax');
 glGetMinmaxParameterfv      := glProcedure('glGetMinmaxParameterfv');
 glGetMinmaxParameteriv      := glProcedure('glGetMinmaxParameteriv');
 glHistogram                 := glProcedure('glHistogram');
 glMinmax                    := glProcedure('glMinmax');
 glResetHistogram            := glProcedure('glResetHistogram');
 glResetMinmax               := glProcedure('glResetMinmax');
 glTexImage3D                := glProcedure('glTexImage3D');
 glTexSubImage3D             := glProcedure('glTexSubImage3D');
 glCopyTexSubImage3D         := glProcedure('glCopyTexSubImage3D');
 // GL_VERSION_1_3 =============================================================
 glActiveTexture             := glProcedure('glActiveTexture');
 glClientActiveTexture       := glProcedure('glClientActiveTexture');
 glMultiTexCoord1f           := glProcedure('glMultiTexCoord1f');
 glMultiTexCoord1fv          := glProcedure('glMultiTexCoord1fv');
 glMultiTexCoord2f           := glProcedure('glMultiTexCoord2f');
 glMultiTexCoord2fv          := glProcedure('glMultiTexCoord2fv');
 glMultiTexCoord3f           := glProcedure('glMultiTexCoord3f');
 glMultiTexCoord3fv          := glProcedure('glMultiTexCoord3fv');
 glMultiTexCoord4f           := glProcedure('glMultiTexCoord4f');
 glMultiTexCoord4fv          := glProcedure('glMultiTexCoord4fv');
 glLoadTransposeMatrixf      := glProcedure('glLoadTransposeMatrixf');
 glLoadTransposeMatrixd      := glProcedure('glLoadTransposeMatrixd');
 glMultTransposeMatrixf      := glProcedure('glMultTransposeMatrixf');
 glMultTransposeMatrixd      := glProcedure('glMultTransposeMatrixd');
 glSampleCoverage            := glProcedure('glSampleCoverage');
 glCompressedTexImage3D      := glProcedure('glCompressedTexImage3D');
 glCompressedTexImage2D      := glProcedure('glCompressedTexImage2D');
 glCompressedTexImage1D      := glProcedure('glCompressedTexImage1D');
 glCompressedTexSubImage3D   := glProcedure('glCompressedTexSubImage3D');
 glCompressedTexSubImage2D   := glProcedure('glCompressedTexSubImage2D');
 glCompressedTexSubImage1D   := glProcedure('glCompressedTexSubImage1D');
 glGetCompressedTexImage     := glProcedure('glGetCompressedTexImage');
 // GL_VERSION_1_4 =============================================================
 glBlendFuncSeparate         := glProcedure('glBlendFuncSeparate');
 glFogCoordf                 := glProcedure('glFogCoordf');
 glFogCoordfv                := glProcedure('glFogCoordfv');
 glFogCoordd                 := glProcedure('glFogCoordd');
 glFogCoorddv                := glProcedure('glFogCoorddv');
 glFogCoordPointer           := glProcedure('glFogCoordPointer');
 glMultiDrawArrays           := glProcedure('glMultiDrawArrays');
 glMultiDrawElements         := glProcedure('glMultiDrawElements');
 glPointParameterf           := glProcedure('glPointParameterf');
 glPointParameterfv          := glProcedure('glPointParameterfv');
 glPointParameteri           := glProcedure('glPointParameteri');
 glPointParameteriv          := glProcedure('glPointParameteriv');
 glSecondaryColor3f          := glProcedure('glSecondaryColor3f');
 glSecondaryColor3fv         := glProcedure('glSecondaryColor3fv');
 glSecondaryColorPointer     := glProcedure('glSecondaryColorPointer');
 glWindowPos2f               := glProcedure('glWindowPos2f');
 glWindowPos2fv              := glProcedure('glWindowPos2fv');
 glWindowPos3f               := glProcedure('glWindowPos3f');
 glWindowPos3fv              := glProcedure('glWindowPos3fv');

    // GL_ARB_matrix_palette ===================================================
    glCurrentPaletteMatrixARB := wglGetProcAddress('glCurrentPaletteMatrixARB');
    glMatrixIndexubvARB       := wglGetProcAddress('glMatrixIndexubvARB');
    glMatrixIndexusvARB       := wglGetProcAddress('glMatrixIndexusvARB');
    glMatrixIndexuivARB       := wglGetProcAddress('glMatrixIndexuivARB');
    glMatrixIndexPointerARB   := wglGetProcAddress('glMatrixIndexPointerARB');

    // GL_ARB_multisample ======================================================
    glSampleCoverageARB := wglGetProcAddress('glSampleCoverageARB');

    // GL_ARB_multitexture =====================================================
    glActiveTextureARB       := wglGetProcAddress('glActiveTextureARB');
    glClientActiveTextureARB := wglGetProcAddress('glClientActiveTextureARB');
    glMultiTexCoord1fARB     := wglGetProcAddress('glMultiTexCoord1fARB');
    glMultiTexCoord1fvARB    := wglGetProcAddress('glMultiTexCoord1fvARB');
    glMultiTexCoord2fARB     := wglGetProcAddress('glMultiTexCoord2fARB');
    glMultiTexCoord2fvARB    := wglGetProcAddress('glMultiTexCoord2fvARB');
    glMultiTexCoord3fARB     := wglGetProcAddress('glMultiTexCoord3fARB');
    glMultiTexCoord3fvARB    := wglGetProcAddress('glMultiTexCoord3fvARB');
    glMultiTexCoord4fARB     := wglGetProcAddress('glMultiTexCoord4fARB');
    glMultiTexCoord4fvARB    := wglGetProcAddress('glMultiTexCoord4fvARB');

    // GL_ARB_point_parameters =================================================
    glPointParameterfARB  := wglGetProcAddress('glPointParameterfARB');
    glPointParameterfvARB := wglGetProcAddress('glPointParameterfvARB');

    // GL_ARB_texture_compression ==============================================
    glCompressedTexImage3DARB    := wglGetProcAddress('glCompressedTexImage3DARB');
    glCompressedTexImage2DARB    := wglGetProcAddress('glCompressedTexImage2DARB');
    glCompressedTexImage1DARB    := wglGetProcAddress('glCompressedTexImage1DARB');
    glCompressedTexSubImage3DARB := wglGetProcAddress('glCompressedTexSubImage3DARB');
    glCompressedTexSubImage2DARB := wglGetProcAddress('glCompressedTexSubImage2DARB');
    glCompressedTexSubImage1DARB := wglGetProcAddress('glCompressedTexSubImage1DARB');
    glGetCompressedTexImageARB   := wglGetProcAddress('glGetCompressedTexImageARB');

    // GL_ARB_transpose_matrix =================================================
    glLoadTransposeMatrixfARB := wglGetProcAddress('glLoadTransposeMatrixfARB');
    glLoadTransposeMatrixdARB := wglGetProcAddress('glLoadTransposeMatrixdARB');
    glMultTransposeMatrixfARB := wglGetProcAddress('glMultTransposeMatrixfARB');
    glMultTransposeMatrixdARB := wglGetProcAddress('glMultTransposeMatrixdARB');

    // GL_ARB_vertex_blend =====================================================
    glWeightbvARB      := wglGetProcAddress('glWeightbvARB');
    glWeightsvARB      := wglGetProcAddress('glWeightsvARB');
    glWeightivARB      := wglGetProcAddress('glWeightivARB');
    glWeightfvARB      := wglGetProcAddress('glWeightfvARB');
    glWeightdvARB      := wglGetProcAddress('glWeightdvARB');
    glWeightubvARB     := wglGetProcAddress('glWeightubvARB');
    glWeightusvARB     := wglGetProcAddress('glWeightusvARB');
    glWeightuivARB     := wglGetProcAddress('glWeightuivARB');
    glWeightPointerARB := wglGetProcAddress('glWeightPointerARB');
    glVertexBlendARB   := wglGetProcAddress('glVertexBlendARB');

    // GL_ARB_vertex_buffer_object =============================================
    glBindBufferARB           := wglGetProcAddress('glBindBufferARB');
    glDeleteBuffersARB        := wglGetProcAddress('glDeleteBuffersARB');
    glGenBuffersARB           := wglGetProcAddress('glGenBuffersARB');
    glIsBufferARB             := wglGetProcAddress('glIsBufferARB');
    glBufferDataARB           := wglGetProcAddress('glBufferDataARB');
    glBufferSubDataARB        := wglGetProcAddress('glBufferSubDataARB');
    glGetBufferSubDataARB     := wglGetProcAddress('glGetBufferSubDataARB');
    glMapBufferARB            := wglGetProcAddress('glMapBufferARB');
    glUnmapBufferARB          := wglGetProcAddress('glUnmapBufferARB');
    glGetBufferParameterivARB := wglGetProcAddress('glGetBufferParameterivARB');
    glGetBufferPointervARB    := wglGetProcAddress('glGetBufferPointervARB');

    // ARB less version for GL 1.5 =============================================
    glBindBuffer           := wglGetProcAddress('glBindBuffer');
    glDeleteBuffers        := wglGetProcAddress('glDeleteBuffers');
    glGenBuffers           := wglGetProcAddress('glGenBuffers');
    glIsBuffer             := wglGetProcAddress('glIsBuffer');
    glBufferData           := wglGetProcAddress('glBufferData');
    glBufferSubData        := wglGetProcAddress('glBufferSubData');
    glGetBufferSubData     := wglGetProcAddress('glGetBufferSubData');
    glMapBuffer            := wglGetProcAddress('glMapBuffer');
    glUnmapBuffer          := wglGetProcAddress('glUnmapBuffer');
    glGetBufferParameteriv := wglGetProcAddress('glGetBufferParameteriv');
    glGetBufferPointerv    := wglGetProcAddress('glGetBufferPointerv');

    // GL_ARB_vertex_program ===================================================
    glVertexAttrib1dARB              := wglGetProcAddress( 'glVertexAttrib1dARB');
    glVertexAttrib1dvARB             := wglGetProcAddress( 'glVertexAttrib1dvARB');
    glVertexAttrib1fARB              := wglGetProcAddress( 'glVertexAttrib1fARB');
    glVertexAttrib1fvARB             := wglGetProcAddress( 'glVertexAttrib1fvARB');
    glVertexAttrib1sARB              := wglGetProcAddress( 'glVertexAttrib1sARB');
    glVertexAttrib1svARB             := wglGetProcAddress( 'glVertexAttrib1svARB');
    glVertexAttrib2dARB              := wglGetProcAddress( 'glVertexAttrib2dARB');
    glVertexAttrib2dvARB             := wglGetProcAddress( 'glVertexAttrib2dvARB');
    glVertexAttrib2fARB              := wglGetProcAddress( 'glVertexAttrib2fARB');
    glVertexAttrib2fvARB             := wglGetProcAddress( 'glVertexAttrib2fvARB');
    glVertexAttrib2sARB              := wglGetProcAddress( 'glVertexAttrib2sARB');
    glVertexAttrib2svARB             := wglGetProcAddress( 'glVertexAttrib2svARB');
    glVertexAttrib3dARB              := wglGetProcAddress( 'glVertexAttrib3dARB');
    glVertexAttrib3dvARB             := wglGetProcAddress( 'glVertexAttrib3dvARB');
    glVertexAttrib3fARB              := wglGetProcAddress( 'glVertexAttrib3fARB');
    glVertexAttrib3fvARB             := wglGetProcAddress( 'glVertexAttrib3fvARB');
    glVertexAttrib3sARB              := wglGetProcAddress( 'glVertexAttrib3sARB');
    glVertexAttrib3svARB             := wglGetProcAddress( 'glVertexAttrib3svARB');
    glVertexAttrib4NbvARB            := wglGetProcAddress( 'glVertexAttrib4NbvARB');
    glVertexAttrib4NivARB            := wglGetProcAddress( 'glVertexAttrib4NivARB');
    glVertexAttrib4NsvARB            := wglGetProcAddress( 'glVertexAttrib4NsvARB');
    glVertexAttrib4NubARB            := wglGetProcAddress( 'glVertexAttrib4NubARB');
    glVertexAttrib4NubvARB           := wglGetProcAddress( 'glVertexAttrib4NubvARB');
    glVertexAttrib4NuivARB           := wglGetProcAddress( 'glVertexAttrib4NuivARB');
    glVertexAttrib4NusvARB           := wglGetProcAddress( 'glVertexAttrib4NusvARB');
    glVertexAttrib4bvARB             := wglGetProcAddress( 'glVertexAttrib4bvARB');
    glVertexAttrib4dARB              := wglGetProcAddress( 'glVertexAttrib4dARB');
    glVertexAttrib4dvARB             := wglGetProcAddress( 'glVertexAttrib4dvARB');
    glVertexAttrib4fARB              := wglGetProcAddress( 'glVertexAttrib4fARB');
    glVertexAttrib4fvARB             := wglGetProcAddress( 'glVertexAttrib4fvARB');
    glVertexAttrib4ivARB             := wglGetProcAddress( 'glVertexAttrib4ivARB');
    glVertexAttrib4sARB              := wglGetProcAddress( 'glVertexAttrib4sARB');
    glVertexAttrib4svARB             := wglGetProcAddress( 'glVertexAttrib4svARB');
    glVertexAttrib4ubvARB            := wglGetProcAddress( 'glVertexAttrib4ubvARB');
    glVertexAttrib4uivARB            := wglGetProcAddress( 'glVertexAttrib4uivARB');
    glVertexAttrib4usvARB            := wglGetProcAddress( 'glVertexAttrib4usvARB');
    glVertexAttribPointerARB         := wglGetProcAddress( 'glVertexAttribPointerARB');
    glEnableVertexAttribArrayARB     := wglGetProcAddress( 'glEnableVertexAttribArrayARB');
    glDisableVertexAttribArrayARB    := wglGetProcAddress( 'glDisableVertexAttribArrayARB');
    glProgramStringARB               := wglGetProcAddress( 'glProgramStringARB');
    glBindProgramARB                 := wglGetProcAddress( 'glBindProgramARB');
    glDeleteProgramsARB              := wglGetProcAddress( 'glDeleteProgramsARB');
    glGenProgramsARB                 := wglGetProcAddress( 'glGenProgramsARB');
    glProgramEnvParameter4dARB       := wglGetProcAddress( 'glProgramEnvParameter4dARB');
    glProgramEnvParameter4dvARB      := wglGetProcAddress( 'glProgramEnvParameter4dvARB');
    glProgramEnvParameter4fARB       := wglGetProcAddress( 'glProgramEnvParameter4fARB');
    glProgramEnvParameter4fvARB      := wglGetProcAddress( 'glProgramEnvParameter4fvARB');
    glProgramLocalParameter4dARB     := wglGetProcAddress( 'glProgramLocalParameter4dARB');
    glProgramLocalParameter4dvARB    := wglGetProcAddress( 'glProgramLocalParameter4dvARB');
    glProgramLocalParameter4fARB     := wglGetProcAddress( 'glProgramLocalParameter4fARB');
    glProgramLocalParameter4fvARB    := wglGetProcAddress( 'glProgramLocalParameter4fvARB');
    glGetProgramEnvParameterdvARB    := wglGetProcAddress( 'glGetProgramEnvParameterdvARB');
    glGetProgramEnvParameterfvARB    := wglGetProcAddress( 'glGetProgramEnvParameterfvARB');
    glGetProgramLocalParameterdvARB  := wglGetProcAddress( 'glGetProgramLocalParameterdvARB');
    glGetProgramLocalParameterfvARB  := wglGetProcAddress( 'glGetProgramLocalParameterfvARB');
    glGetProgramivARB                := wglGetProcAddress( 'glGetProgramivARB');
    glGetProgramStringARB            := wglGetProcAddress( 'glGetProgramStringARB');
    glGetVertexAttribdvARB           := wglGetProcAddress( 'glGetVertexAttribdvARB');
    glGetVertexAttribfvARB           := wglGetProcAddress( 'glGetVertexAttribfvARB');
    glGetVertexAttribivARB           := wglGetProcAddress( 'glGetVertexAttribivARB');
    glGetVertexAttribPointervARB     := wglGetProcAddress( 'glGetVertexAttribPointervARB');
    glIsProgramARB                   := wglGetProcAddress( 'glIsProgramARB');

    glVertexAttrib1d                 := wglGetProcAddress( 'glVertexAttrib1d');
    glVertexAttrib1dv                := wglGetProcAddress( 'glVertexAttrib1dv');
    glVertexAttrib1f                 := wglGetProcAddress( 'glVertexAttrib1f');
    glVertexAttrib1fv                := wglGetProcAddress( 'glVertexAttrib1fv');
    glVertexAttrib1s                 := wglGetProcAddress( 'glVertexAttrib1s');
    glVertexAttrib1sv                := wglGetProcAddress( 'glVertexAttrib1sv');
    glVertexAttrib2d                 := wglGetProcAddress( 'glVertexAttrib2d');
    glVertexAttrib2dv                := wglGetProcAddress( 'glVertexAttrib2dv');
    glVertexAttrib2f                 := wglGetProcAddress( 'glVertexAttrib2f');
    glVertexAttrib2fv                := wglGetProcAddress( 'glVertexAttrib2fv');
    glVertexAttrib2s                 := wglGetProcAddress( 'glVertexAttrib2s');
    glVertexAttrib2sv                := wglGetProcAddress( 'glVertexAttrib2sv');
    glVertexAttrib3d                 := wglGetProcAddress( 'glVertexAttrib3d');
    glVertexAttrib3dv                := wglGetProcAddress( 'glVertexAttrib3dv');
    glVertexAttrib3f                 := wglGetProcAddress( 'glVertexAttrib3f');
    glVertexAttrib3fv                := wglGetProcAddress( 'glVertexAttrib3fv');
    glVertexAttrib3s                 := wglGetProcAddress( 'glVertexAttrib3s');
    glVertexAttrib3sv                := wglGetProcAddress( 'glVertexAttrib3sv');
    glVertexAttrib4Nbv               := wglGetProcAddress( 'glVertexAttrib4Nbv');
    glVertexAttrib4Niv               := wglGetProcAddress( 'glVertexAttrib4Niv');
    glVertexAttrib4Nsv               := wglGetProcAddress( 'glVertexAttrib4Nsv');
    glVertexAttrib4Nub               := wglGetProcAddress( 'glVertexAttrib4Nub');
    glVertexAttrib4Nubv              := wglGetProcAddress( 'glVertexAttrib4Nubv');
    glVertexAttrib4Nuiv              := wglGetProcAddress( 'glVertexAttrib4Nuiv');
    glVertexAttrib4Nusv              := wglGetProcAddress( 'glVertexAttrib4Nusv');
    glVertexAttrib4bv                := wglGetProcAddress( 'glVertexAttrib4bv');
    glVertexAttrib4d                 := wglGetProcAddress( 'glVertexAttrib4d');
    glVertexAttrib4dv                := wglGetProcAddress( 'glVertexAttrib4dv');
    glVertexAttrib4f                 := wglGetProcAddress( 'glVertexAttrib4f');
    glVertexAttrib4fv                := wglGetProcAddress( 'glVertexAttrib4fv');
    glVertexAttrib4iv                := wglGetProcAddress( 'glVertexAttrib4iv');
    glVertexAttrib4s                 := wglGetProcAddress( 'glVertexAttrib4s');
    glVertexAttrib4sv                := wglGetProcAddress( 'glVertexAttrib4sv');
    glVertexAttrib4ubv               := wglGetProcAddress( 'glVertexAttrib4ubv');
    glVertexAttrib4uiv               := wglGetProcAddress( 'glVertexAttrib4uiv');
    glVertexAttrib4usv               := wglGetProcAddress( 'glVertexAttrib4usv');



    // GL_ARB_window_pos =======================================================
    glWindowPos2fARB  := wglGetProcAddress( 'glWindowPos2fARB');
    glWindowPos2fvARB := wglGetProcAddress( 'glWindowPos2fvARB');
    glWindowPos3fARB  := wglGetProcAddress( 'glWindowPos3fARB');
    glWindowPos3fvARB := wglGetProcAddress( 'glWindowPos3fvARB');

    // GL_SGIS_detail_texture ==================================================
    glDetailTexFuncSGIS    := wglGetProcAddress( 'glDetailTexFuncSGIS');
    glGetDetailTexFuncSGIS := wglGetProcAddress( 'glGetDetailTexFuncSGIS');

    // GL_SGIS_fog_function ====================================================
    glFogFuncSGIS    := wglGetProcAddress( 'glFogFuncSGIS');
    glGetFogFuncSGIS := wglGetProcAddress( 'glGetFogFuncSGIS');

    // GL_SGIS_multisample =====================================================
    glSampleMaskSGIS    := wglGetProcAddress( 'glSampleMaskSGIS');
    glSamplePatternSGIS := wglGetProcAddress( 'glSamplePatternSGIS');

    // GL_SGIS_pixel_texture ===================================================
    glPixelTexGenParameteriSGIS     := wglGetProcAddress( 'glPixelTexGenParameteriSGIS');
    glPixelTexGenParameterivSGIS    := wglGetProcAddress( 'glPixelTexGenParameterivSGIS');
    glPixelTexGenParameterfSGIS     := wglGetProcAddress( 'glPixelTexGenParameterfSGIS');
    glPixelTexGenParameterfvSGIS    := wglGetProcAddress( 'glPixelTexGenParameterfvSGIS');
    glGetPixelTexGenParameterivSGIS := wglGetProcAddress( 'glGetPixelTexGenParameterivSGIS');
    glGetPixelTexGenParameterfvSGIS := wglGetProcAddress( 'glGetPixelTexGenParameterfvSGIS');

    // GL_SGIS_point_parameters ================================================
    glPointParameterfSGIS  := wglGetProcAddress( 'glPointParameterfSGIS');
    glPointParameterfvSGIS := wglGetProcAddress( 'glPointParameterfvSGIS');

    // GL_SGIS_sharpen_texture =================================================
    glSharpenTexFuncSGIS    := wglGetProcAddress( 'glSharpenTexFuncSGIS');
    glGetSharpenTexFuncSGIS := wglGetProcAddress( 'glGetSharpenTexFuncSGIS');

    // GL_SGIS_texture4D =======================================================
    glTexImage4DSGIS    := wglGetProcAddress( 'glTexImage4DSGIS');
    glTexSubImage4DSGIS := wglGetProcAddress( 'glTexSubImage4DSGIS');

    // GL_SGIS_texture_color_mask ==============================================
    glTextureColorMaskSGIS := wglGetProcAddress( 'glTextureColorMaskSGIS');

    // GL_SGIS_texture_filter4 =================================================
    glGetTexFilterFuncSGIS := wglGetProcAddress( 'glGetTexFilterFuncSGIS');
    glTexFilterFuncSGIS    := wglGetProcAddress( 'glTexFilterFuncSGIS');


    // GL_SGI_color_table ======================================================
    glColorTableSGI               := wglGetProcAddress( 'glColorTableSGI');
    glColorTableParameterfvSGI    := wglGetProcAddress( 'glColorTableParameterfvSGI');
    glColorTableParameterivSGI    := wglGetProcAddress( 'glColorTableParameterivSGI');
    glCopyColorTableSGI           := wglGetProcAddress( 'glCopyColorTableSGI');
    glGetColorTableSGI            := wglGetProcAddress( 'glGetColorTableSGI');
    glGetColorTableParameterfvSGI := wglGetProcAddress( 'glGetColorTableParameterfvSGI');
    glGetColorTableParameterivSGI := wglGetProcAddress( 'glGetColorTableParameterivSGI');

{$IFDEF Win32}
    // WGL_ARB_buffer_region ===================================================
    wglCreateBufferRegionARB         := wglGetProcAddress('wglCreateBufferRegionARB');
    wglDeleteBufferRegionARB         := wglGetProcAddress('wglDeleteBufferRegionARB');
    wglSaveBufferRegionARB           := wglGetProcAddress('wglSaveBufferRegionARB');
    wglRestoreBufferRegionARB        := wglGetProcAddress('wglRestoreBufferRegionARB');
    // WGL_ARB_extensions_string ===============================================
    wglGetExtensionsStringARB        := wglGetProcAddress('wglGetExtensionsStringARB');
    // WGL_ARB_make_current_read ===============================================
    wglMakeContextCurrentARB         := wglGetProcAddress('wglMakeContextCurrentARB');
    wglGetCurrentReadDCARB           := wglGetProcAddress('wglGetCurrentReadDCARB');
    // WGL_ARB_pbuffer =========================================================
    wglCreatePbufferARB              := wglGetProcAddress('wglCreatePbufferARB');
    wglGetPbufferDCARB               := wglGetProcAddress('wglGetPbufferDCARB');
    wglReleasePbufferDCARB           := wglGetProcAddress('wglReleasePbufferDCARB');
    wglDestroyPbufferARB             := wglGetProcAddress('wglDestroyPbufferARB');
    wglQueryPbufferARB               := wglGetProcAddress('wglQueryPbufferARB');
    // WGL_ARB_pixel_format ====================================================
    wglGetPixelFormatAttribivARB     := wglGetProcAddress('wglGetPixelFormatAttribivARB');
    wglGetPixelFormatAttribfvARB     := wglGetProcAddress('wglGetPixelFormatAttribfvARB');
    wglChoosePixelFormatARB          := wglGetProcAddress('wglChoosePixelFormatARB');
    // WGL_ARB_render_texture ==================================================
    wglBindTexImageARB               := wglGetProcAddress('wglBindTexImageARB');
    wglReleaseTexImageARB            := wglGetProcAddress('wglReleaseTexImageARB');
    wglSetPbufferAttribARB           := wglGetProcAddress('wglSetPbufferAttribARB');
    // WGL_EXT_display_color_table =============================================
    wglCreateDisplayColorTableEXT    := wglGetProcAddress('wglCreateDisplayColorTableEXT');
    wglLoadDisplayColorTableEXT      := wglGetProcAddress('wglLoadDisplayColorTableEXT');
    wglBindDisplayColorTableEXT      := wglGetProcAddress('wglBindDisplayColorTableEXT');
    wglDestroyDisplayColorTableEXT   := wglGetProcAddress('wglDestroyDisplayColorTableEXT');
    // WGL_EXT_extensions_string ===============================================
    wglGetExtensionsStringEXT        := wglGetProcAddress('wglGetExtensionsStringEXT');
    // WGL_EXT_make_current_read ===============================================
    wglMakeContextCurrentEXT         := wglGetProcAddress('wglMakeContextCurrentEXT');
    wglGetCurrentReadDCEXT           := wglGetProcAddress('wglGetCurrentReadDCEXT');
    // WGL_EXT_pbuffer =========================================================
    wglCreatePbufferEXT              := wglGetProcAddress('wglCreatePbufferEXT');
    wglGetPbufferDCEXT               := wglGetProcAddress('wglGetPbufferDCEXT');
    wglReleasePbufferDCEXT           := wglGetProcAddress('wglReleasePbufferDCEXT');
    wglDestroyPbufferEXT             := wglGetProcAddress('wglDestroyPbufferEXT');
    wglQueryPbufferEXT               := wglGetProcAddress('wglQueryPbufferEXT');
    // WGL_EXT_pixel_format ====================================================
    wglGetPixelFormatAttribivEXT     := wglGetProcAddress('wglGetPixelFormatAttribivEXT');
    wglGetPixelFormatAttribfvEXT     := wglGetProcAddress('wglGetPixelFormatAttribfvEXT');
    wglChoosePixelFormatEXT          := wglGetProcAddress('wglChoosePixelFormatEXT');
    // WGL_EXT_swap_control ====================================================
    wglSwapIntervalEXT               := wglGetProcAddress('wglSwapIntervalEXT');
    wglGetSwapIntervalEXT            := wglGetProcAddress('wglGetSwapIntervalEXT');
    // WGL_I3D_digital_video_control ===========================================
    wglGetDigitalVideoParametersI3D  := wglGetProcAddress('wglGetDigitalVideoParametersI3D');
    wglSetDigitalVideoParametersI3D  := wglGetProcAddress('wglSetDigitalVideoParametersI3D');
    // WGL_I3D_gamma ===========================================================
    wglGetGammaTableParametersI3D    := wglGetProcAddress('wglGetGammaTableParametersI3D');
    wglSetGammaTableParametersI3D    := wglGetProcAddress('wglSetGammaTableParametersI3D');
    wglGetGammaTableI3D              := wglGetProcAddress('wglGetGammaTableI3D');
    wglSetGammaTableI3D              := wglGetProcAddress('wglSetGammaTableI3D');
    // WGL_I3D_genlock =========================================================
    wglEnableGenlockI3D              := wglGetProcAddress('wglEnableGenlockI3D');
    wglDisableGenlockI3D             := wglGetProcAddress('wglDisableGenlockI3D');
    wglIsEnabledGenlockI3D           := wglGetProcAddress('wglIsEnabledGenlockI3D');
    wglGenlockSourceI3D              := wglGetProcAddress('wglGenlockSourceI3D');
    wglGetGenlockSourceI3D           := wglGetProcAddress('wglGetGenlockSourceI3D');
    wglGenlockSourceEdgeI3D          := wglGetProcAddress('wglGenlockSourceEdgeI3D');
    wglGetGenlockSourceEdgeI3D       := wglGetProcAddress('wglGetGenlockSourceEdgeI3D');
    wglGenlockSampleRateI3D          := wglGetProcAddress('wglGenlockSampleRateI3D');
    wglGetGenlockSampleRateI3D       := wglGetProcAddress('wglGetGenlockSampleRateI3D');
    wglGenlockSourceDelayI3D         := wglGetProcAddress('wglGenlockSourceDelayI3D');
    wglGetGenlockSourceDelayI3D      := wglGetProcAddress('wglGetGenlockSourceDelayI3D');
    wglQueryGenlockMaxSourceDelayI3D := wglGetProcAddress('wglQueryGenlockMaxSourceDelayI3D');
    // WGL_I3D_image_buffer ====================================================
    wglCreateImageBufferI3D          := wglGetProcAddress('wglCreateImageBufferI3D');
    wglDestroyImageBufferI3D         := wglGetProcAddress('wglDestroyImageBufferI3D');
    wglAssociateImageBufferEventsI3D := wglGetProcAddress('wglAssociateImageBufferEventsI3D');
    wglReleaseImageBufferEventsI3D   := wglGetProcAddress('wglReleaseImageBufferEventsI3D');
    // WGL_I3D_swap_frame_lock =================================================
    wglEnableFrameLockI3D            := wglGetProcAddress('wglEnableFrameLockI3D');
    wglDisableFrameLockI3D           := wglGetProcAddress('wglDisableFrameLockI3D');
    wglIsEnabledFrameLockI3D         := wglGetProcAddress('wglIsEnabledFrameLockI3D');
    wglQueryFrameLockMasterI3D       := wglGetProcAddress('wglQueryFrameLockMasterI3D');
    // WGL_I3D_swap_frame_usage ================================================
    wglGetFrameUsageI3D              := wglGetProcAddress('wglGetFrameUsageI3D');
    wglBeginFrameTrackingI3D         := wglGetProcAddress('wglBeginFrameTrackingI3D');
    wglEndFrameTrackingI3D           := wglGetProcAddress('wglEndFrameTrackingI3D');
    wglQueryFrameTrackingI3D         := wglGetProcAddress('wglQueryFrameTrackingI3D');

{$ENDIF}

    // ==== OpenGL 1.5 =========================================================
    // GL_ARB_Shader_Objects ===================================================
    glCreateShaderObjectARB      := wglGetProcAddress('glCreateShaderObjectARB');

    glShaderSourceARB            := wglGetProcAddress('glShaderSourceARB');
    glCompileShaderARB           := wglGetProcAddress('glCompileShaderARB');
    glDeleteObjectARB            := wglGetProcAddress('glDeleteObjectARB');
    glGetHandleARB               := wglGetProcAddress('glGetHandleARB');
    glDetachObjectARB            := wglGetProcAddress('glDetachObjectARB');
    glCreateProgramObjectARB     := wglGetProcAddress('glCreateProgramObjectARB');
    glAttachObjectARB            := wglGetProcAddress('glAttachObjectARB');
    glLinkProgramARB             := wglGetProcAddress('glLinkProgramARB');
    glUseProgramObjectARB        := wglGetProcAddress('glUseProgramObjectARB');
    glValidateProgramARB         := wglGetProcAddress('glValidateProgramARB');
    glGetObjectParameterfvARB    := wglGetProcAddress('glGetObjectParameterfvARB');
    glGetObjectParameterivARB    := wglGetProcAddress('glGetObjectParameterivARB');
    glGetActiveUniformARB        := wglGetProcAddress('glGetActiveUniformARB');
    glGetAttachedObjectsARB      := wglGetProcAddress('glGetAttachedObjectsARB');
    glGetShaderSourceARB         := wglGetProcAddress('glGetShaderSourceARB');
    glGetUniformfvARB            := wglGetProcAddress('glGetUniformfvARB');
    glGetUniformivARB            := wglGetProcAddress('glGetUniformivARB');
    glGetUniformLocationARB      := wglGetProcAddress('glGetUniformLocationARB');
    glGetInfoLogARB              := wglGetProcAddress('glGetInfoLogARB');
    glUniform1fARB               := wglGetProcAddress('glUniform1fARB');
    glUniform2fARB               := wglGetProcAddress('glUniform2fARB');
    glUniform3fARB               := wglGetProcAddress('glUniform3fARB');
    glUniform4fARB               := wglGetProcAddress('glUniform4fARB');
    glUniform1iARB               := wglGetProcAddress('glUniform1iARB');
    glUniform2iARB               := wglGetProcAddress('glUniform2iARB');
    glUniform3iARB               := wglGetProcAddress('glUniform3iARB');
    glUniform4iARB               := wglGetProcAddress('glUniform4iARB');
    glUniform1fvARB              := wglGetProcAddress('glUniform1fvARB');
    glUniform2fvARB              := wglGetProcAddress('glUniform2fvARB');
    glUniform3fvARB              := wglGetProcAddress('glUniform3fvARB');
    glUniform4fvARB              := wglGetProcAddress('glUniform4fvARB');
    glUniform1ivARB              := wglGetProcAddress('glUniform1ivARB');
    glUniform2ivARB              := wglGetProcAddress('glUniform2ivARB');
    glUniform3ivARB              := wglGetProcAddress('glUniform3ivARB');
    glUniform4ivARB              := wglGetProcAddress('glUniform4ivARB');
    glUniformMatrix2fvARB        := wglGetProcAddress('glUniformMatrix2fvARB');
    glUniformMatrix3fvARB        := wglGetProcAddress('glUniformMatrix3fvARB');
    glUniformMatrix4fvARB        := wglGetProcAddress('glUniformMatrix4fvARB');
    // GL_ARB_vertex_shader ====================================================

    glGetActiveAttribARB         := wglGetProcAddress('glGetActiveAttribARB');

    glGetAttribLocationARB       := wglGetProcAddress('glGetAttribLocationARB');

    glBindAttribLocationARB      := wglGetProcAddress('glBindAttribLocationARB');

    glGetVertexAttribPointervARB := wglGetProcAddress('glGetVertexAttribPointervARB');

    // GL_ARB_occlusion_query ==================================================
    glGenQueriesARB              := wglGetProcAddress('glGenQueriesARB');
    glDeleteQueriesARB           := wglGetProcAddress('glDeleteQueriesARB');
    glIsQueryARB                 := wglGetProcAddress('glIsQueryARB');
    glBeginQueryARB              := wglGetProcAddress('glBeginQueryARB');
    glEndQueryARB                := wglGetProcAddress('glEndQueryARB');
    glGetQueryivARB              := wglGetProcAddress('glGetQueryivARB');
    glGetQueryObjectivARB        := wglGetProcAddress('glGetQueryObjectivARB');
    glGetQueryObjectuivARB       := wglGetProcAddress('glGetQueryObjectuivARB');
    // ARB less version for GL 1.5==============================================
    glGenQueries              := wglGetProcAddress('glGenQueries');
    glDeleteQueries           := wglGetProcAddress('glDeleteQueries');
    glIsQuery                 := wglGetProcAddress('glIsQuery');
    glBeginQuery              := wglGetProcAddress('glBeginQuery');
    glEndQuery                := wglGetProcAddress('glEndQuery');
    glGetQueryiv              := wglGetProcAddress('glGetQueryiv');
    glGetQueryObjectiv        := wglGetProcAddress('glGetQueryObjectiv');
    glGetQueryObjectuiv       := wglGetProcAddress('glGetQueryObjectuiv');

    ExtensionsRead               := True;
  end;
end;



// =============================================================================
//  ReadImplementationProperties
// =============================================================================
function StrToInt(const S: string): Integer;
var
  E: Integer;
begin
  Val(S, Result, E);
  if E <> 0 then Result:=0;
end;

procedure ReadImplementationProperties;
var
 Buffer                     : string;
 MajorVersion, MinorVersion : Integer;

  procedure TrimAndSplitVersionString(Buffer: String; var Max, Min: Integer);
  // Peels out the X.Y form from the given Buffer which must contain a version string like "text Minor.Major.Build text"
  // at least however "Major.Minor".
  var
    Separator: Integer;
  begin
    try
      // There must be at least one dot to separate major and minor version number.
      Separator := Pos('.', Buffer);
      // At least one number must be before and one after the dot.
      if (Separator > 1) and (Separator < Length(Buffer)) and (Buffer[Separator - 1] in ['0'..'9']) and
        (Buffer[Separator + 1] in ['0'..'9']) then
      begin
        // OK, it's a valid version string. Now remove unnecessary parts.
        Dec(Separator);
        // Find last non-numeric character before version number.
        while (Separator > 0) and (Buffer[Separator] in ['0'..'9']) do
          Dec(Separator);
        // Delete leading characters which do not belong to the version string.
        Delete(Buffer, 1, Separator);
        Separator := Pos('.', Buffer) + 1;
        // Find first non-numeric character after version number
        while (Separator <= Length(Buffer)) and (Buffer[Separator] in ['0'..'9']) do
          Inc(Separator);
        // delete trailing characters not belonging to the version string
        Delete(Buffer, Separator, 255);
        // Now translate the numbers.
        Separator := Pos('.', Buffer); // This is necessary because the buffer length might have changed.
        Max := StrToInt(Copy(Buffer, 1, Separator - 1));
        Min := StrToInt(Copy(Buffer, Separator + 1, 255));
      end
      else;
//        Abort;
    except
      Min := 0;
      Max := 0;
    end;
  end;

  // Checks if the given Extension string is in Buffer.
  function CheckExtension(const Extension: string): Boolean;
  var
    ExtPos: Integer;
  begin
    // First find the position of the extension string as substring in Buffer.
    ExtPos := Pos(Extension, Buffer);
    Result := ExtPos > 0;
    // Now check that it isn't only a substring of another extension.
    if Result then
      Result := ((ExtPos + Length(Extension) - 1) = Length(Buffer)) or
        not (Buffer[ExtPos + Length(Extension)] in ['_', 'A'..'Z', 'a'..'z']);
  end;
begin
// determine version of implementation
// GL
Buffer := glGetString(GL_VERSION);
TrimAndSplitVersionString(Buffer, Majorversion, MinorVersion);
GL_VERSION_1_0 := True;
GL_VERSION_1_1 := False;
GL_VERSION_1_2 := False;
GL_VERSION_1_3 := False;
GL_VERSION_1_4 := False;
GL_VERSION_1_5 := False;
if MajorVersion > 0 then
 begin
 if MinorVersion >= 1 then
  begin
  GL_VERSION_1_1 := True;
  if MinorVersion >= 2
   then GL_VERSION_1_2 := True;
  if MinorVersion >= 3
   then GL_VERSION_1_3 := True;
  if MinorVersion >= 4
   then GL_VERSION_1_4 := True;
  if MinorVersion >= 5
   then GL_VERSION_1_5 := True;
  end;
 end;
// GLU
GLU_VERSION_1_1 := False;
GLU_VERSION_1_2 := False;
GLU_VERSION_1_3 := False;
// gluGetString is valid for version 1.1 or later
if Assigned(gluGetString) then
 begin
 Buffer := gluGetString(GLU_VERSION);
 TrimAndSplitVersionString(Buffer, Majorversion, MinorVersion);
 GLU_VERSION_1_1 := True;
 if MinorVersion >= 2
  then GLU_VERSION_1_2 := True;
 if MinorVersion >= 3
  then GLU_VERSION_1_3 := True;
 end;
// check supported extensions
Buffer := glGetString(GL_EXTENSIONS);
if (LibHandle<>0) then
 begin
{$IFDEF WIN32} 
 wglGetExtensionsStringEXT := glProcedure('wglGetExtensionsStringEXT');
 if Assigned(@wglGetExtensionsStringEXT) then
  Buffer := Buffer + ' ' + wglGetExtensionsStringEXT
 else
  begin
  wglGetExtensionsStringARB := glProcedure('wglGetExtensionsStringARB');
  if Assigned(@wglGetExtensionsStringARB) then
   Buffer := Buffer + ' ' + wglGetExtensionsStringARB(wglGetCurrentDC);
  end;
{$ENDIF}  
 end;
// Check all extensions
// === ARB =====================================================================
GL_ARB_depth_texture               := CheckExtension('GL_ARB_depth_texture');
GL_ARB_fragment_program            := CheckExtension('GL_ARB_fragment_program');
GL_ARB_imaging                     := CheckExtension('GL_ARB_imaging');
GL_ARB_matrix_palette              := CheckExtension('GL_ARB_matrix_palette');
GL_ARB_multisample                 := CheckExtension('GL_ARB_multisample');
GL_ARB_multitexture                := CheckExtension('GL_ARB_multitexture');
GL_ARB_point_parameters            := CheckExtension('GL_ARB_point_parameters');
GL_ARB_shadow                      := CheckExtension('GL_ARB_shadow');
GL_ARB_shadow_ambient              := CheckExtension('GL_ARB_shadow_ambient');
GL_ARB_texture_border_clamp        := CheckExtension('GL_ARB_texture_border_clamp');
GL_ARB_texture_compression         := CheckExtension('GL_ARB_texture_compression');
GL_ARB_texture_cube_map            := CheckExtension('GL_ARB_texture_cube_map');
GL_ARB_texture_env_add             := CheckExtension('GL_ARB_texture_env_add');
GL_ARB_texture_env_combine         := CheckExtension('GL_ARB_texture_env_combine');
GL_ARB_texture_env_crossbar        := CheckExtension('GL_ARB_texture_env_crossbar');
GL_ARB_texture_env_dot3            := CheckExtension('GL_ARB_texture_env_dot3');
GL_ARB_texture_mirror_repeat       := CheckExtension('GL_ARB_texture_mirror_repeat');
GL_ARB_texture_mirrored_repeat     := CheckExtension('GL_ARB_texture_mirrored_repeat');
GL_ARB_transpose_matrix            := CheckExtension('GL_ARB_transpose_matrix');
GL_ARB_vertex_blend                := CheckExtension('GL_ARB_vertex_blend');
GL_ARB_vertex_buffer_object        := CheckExtension('GL_ARB_vertex_buffer_object');
GL_ARB_vertex_program              := CheckExtension('GL_ARB_vertex_program');
GL_ARB_window_pos                  := CheckExtension('GL_ARB_window_pos');
GL_ARB_shader_objects              := CheckExtension('GL_ARB_shader_objects');
GL_ARB_vertex_shader               := CheckExtension('GL_ARB_vertex_shader');
GL_ARB_fragment_shader             := CheckExtension('GL_ARB_fragment_shader');
GL_ARB_occlusion_query             := CheckExtension('GL_ARB_occlusion_query');
GL_ARB_shading_language_100        := CheckExtension('GL_ARB_shading_language_100');
GL_ARB_point_sprite                := CheckExtension('GL_ARB_point_sprite');
GL_ARB_texture_non_power_of_two    := CheckExtension('GL_ARB_texture_non_power_of_two');
// === S3 ======================================================================
GL_S3_s3tc                         := CheckExtension('GL_S3_s3tc');
// === SGIS ====================================================================
GL_SGIS_detail_texture             := CheckExtension('GL_SGIS_detail_texture');
GL_SGIS_fog_function               := CheckExtension('GL_SGIS_fog_function');
GL_SGIS_generate_mipmap            := CheckExtension('GL_SGIS_generate_mipmap');
GL_SGIS_multisample                := CheckExtension('GL_SGIS_multisample');
GL_SGIS_pixel_texture              := CheckExtension('GL_SGIS_pixel_texture');
GL_SGIS_point_line_texgen          := CheckExtension('GL_SGIS_point_line_texgen');
GL_SGIS_point_parameters           := CheckExtension('GL_SGIS_point_parameters');
GL_SGIS_sharpen_texture            := CheckExtension('GL_SGIS_sharpen_texture');
GL_SGIS_texture4D                  := CheckExtension('GL_SGIS_texture4D');
GL_SGIS_texture_border_clamp       := CheckExtension('GL_SGIS_texture_border_clamp');
GL_SGIS_texture_color_mask         := CheckExtension('GL_SGIS_texture_color_mask');
GL_SGIS_texture_edge_clamp         := CheckExtension('GL_SGIS_texture_edge_clamp');
GL_SGIS_texture_filter4            := CheckExtension('GL_SGIS_texture_filter4');
GL_SGIS_texture_lod                := CheckExtension('GL_SGIS_texture_lod');
GL_SGIS_texture_select             := CheckExtension('GL_SGIS_texture_select');
// === WGL =====================================================================
{$IFDEF WIN32}
WGL_ARB_buffer_region              := CheckExtension('WGL_ARB_buffer_region');
WGL_ARB_extensions_string          := CheckExtension('WGL_ARB_extensions_string');
WGL_ARB_make_current_read          := CheckExtension('WGL_ARB_make_current_read');
WGL_ARB_multisample                := CheckExtension('WGL_ARB_multisample');
WGL_ARB_pbuffer                    := CheckExtension('WGL_ARB_pbuffer');
WGL_ARB_pixel_format               := CheckExtension('WGL_ARB_pixel_format');
WGL_ARB_render_texture             := CheckExtension('WGL_ARB_render_texture');
WGL_EXT_depth_float                := CheckExtension('WGL_EXT_depth_float');
WGL_EXT_display_color_table        := CheckExtension('WGL_EXT_display_color_table');
WGL_EXT_extensions_string          := CheckExtension('WGL_EXT_extensions_string');
WGL_EXT_make_current_read          := CheckExtension('WGL_EXT_make_current_read');
WGL_EXT_multisample                := CheckExtension('WGL_EXT_multisample');
WGL_EXT_pbuffer                    := CheckExtension('WGL_EXT_pbuffer');
WGL_EXT_pixel_format               := CheckExtension('WGL_EXT_pixel_format');
WGL_EXT_swap_control               := CheckExtension('WGL_EXT_swap_control');
WGL_I3D_digital_video_control      := CheckExtension('WGL_I3D_digital_video_control');
WGL_I3D_gamma                      := CheckExtension('WGL_I3D_gamma');
WGL_I3D_genlock                    := CheckExtension('WGL_I3D_genlock');
WGL_I3D_image_buffer               := CheckExtension('WGL_I3D_image_buffer');
WGL_I3D_swap_frame_lock            := CheckExtension('WGL_I3D_swap_frame_lock');
WGL_I3D_swap_frame_usage           := CheckExtension('WGL_I3D_swap_frame_usage');
{$ENDIF}
ImplementationRead                 := True;
end;

{$IFDEF WIN32}
// =============================================================================
// RaiseLastOSError
// =============================================================================
// Needed for compatibility with older Delphiversions
// =============================================================================
procedure RaiseLastOSError;
begin
{$IFDEF FPC}
// Changed by bero
//raise Exception.Create('RaiseLastOSError!'); // To-Do: find a better solution
{$ELSE}
{$IFDEF VER140}   // If Delphi 6 or later
//SysUtils.RaiseLastOSError;
{$ELSE}
//SysUtils.RaiseLastWin32Error;
{$ENDIF}
{$ENDIF}
end;

// =============================================================================
// CreateRenderingContext
// =============================================================================
function CreateRenderingContext(DC : HDC;Options : TRCOptions;ColorBits,ZBits,StencilBits,AccumBits,AuxBuffers : Integer;Layer : Integer) : HGLRC;
const
 MemoryDCs = [OBJ_MEMDC, OBJ_METADC, OBJ_ENHMETADC];
var
 PFDescriptor : TPixelFormatDescriptor;
 PixelFormat  : Integer;
 AType        : DWORD;
begin
FillChar(PFDescriptor, SizeOf(PFDescriptor), 0);
with PFDescriptor do
 begin
 nSize    := SizeOf(PFDescriptor);
 nVersion := 1;
 dwFlags  := PFD_SUPPORT_OPENGL;
 AType    := GetObjectType(DC);
 if AType = 0 then
  RaiseLastOSError;
 if AType in MemoryDCs then
  dwFlags := dwFlags or PFD_DRAW_TO_BITMAP
 else
  dwFlags := dwFlags or PFD_DRAW_TO_WINDOW;
 if opDoubleBuffered in Options then
  dwFlags := dwFlags or PFD_DOUBLEBUFFER;
 if opGDI in Options then
  dwFlags := dwFlags or PFD_SUPPORT_GDI;
 if opStereo in Options then
  dwFlags := dwFlags or PFD_STEREO;
 iPixelType   := PFD_TYPE_RGBA;
 cColorBits   := ColorBits;
 cDepthBits   := zBits;
 cStencilBits := StencilBits;
 cAccumBits   := AccumBits;
 cAuxBuffers  := AuxBuffers;
 if Layer = 0 then
  iLayerType := PFD_MAIN_PLANE
 else
  if Layer > 0 then
   iLayerType := PFD_OVERLAY_PLANE
  else
   iLayerType := Byte(PFD_UNDERLAY_PLANE);
 end;
PixelFormat := ChoosePixelFormat(DC, @PFDescriptor);
if PixelFormat = 0 then
 RaiseLastOSError;
if GetPixelFormat(DC) <> PixelFormat then
 if not SetPixelFormat(DC, PixelFormat, @PFDescriptor) then
  RaiseLastOSError;
DescribePixelFormat(DC, PixelFormat, SizeOf(PFDescriptor), PFDescriptor);
Result := wglCreateLayerContext(DC, Layer);
if Result = 0 then
 RaiseLastOSError
else
 LastPixelFormat := 0;
end;

// =============================================================================
// ActivateRenderingContext
// =============================================================================
procedure ActivateRenderingContext(DC : HDC;RC : HGLRC);
begin
Assert((DC <> 0), 'DC must not be 0');
Assert((RC <> 0), 'RC must not be 0');
wglMakeCurrent(DC, RC);
 ReadExtensions;
 ReadImplementationProperties;
end;

// =============================================================================
// DeactivateRenderingContext
// =============================================================================
procedure DeactivateRenderingContext;
begin
wglMakeCurrent(0,0);
end;

// =============================================================================
// DestroyRenderingContext
// =============================================================================
procedure DestroyRenderingContext(RC: HGLRC);
begin
wglDeleteContext(RC);
end;
{$ENDIF}

{$IFDEF FPC}
{$IFDEF CPU386}
 // Added by bero
const Default8087CW : Word = $1332;
procedure Set8087CW(NewCW : Word); Assembler;
asm
  MOV Default8087CW, AX
end;
{$ENDIF}
{$ENDIF}
