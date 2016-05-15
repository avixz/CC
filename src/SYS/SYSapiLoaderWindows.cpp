//---------------------------------------------------------------------------
// SYSapiLoaderWindows.cpp
//---------------------------------------------------------------------------

#include "windows.h"
#include "GL/gl3.h"
#include "GL/wglext.h"
#include "IGL/IGLapi.h"
#include "SYS/SYSapiLoaderWindows.h"

namespace cc
{

//---------------------------------------------------------------------------
void SYSapiLoaderWindows::GetAPI(IGLAPI* api) const
{
    api->glActiveTexture = (PFNGLACTIVETEXTUREPROC)GetGLProc(api, "glActiveTexture");
    api->glAttachShader = (PFNGLATTACHSHADERPROC)GetGLProc(api, "glAttachShader");
    api->glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)GetGLProc(api, "glBindAttribLocation");
    api->glBindBuffer = (PFNGLBINDBUFFERPROC)GetGLProc(api, "glBindBuffer");
    api->glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)GetGLProc(api, "glBindFragDataLocation");
    api->glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)GetGLProc(api, "glBindFramebuffer");
    api->glBindTexture = (PFNGLBINDTEXTUREPROC)GetGLProc(api, "glBindTexture");
    api->glBlendFunc = (PFNGLBLENDFUNCPROC)GetGLProc(api, "glBlendFunc");
    api->glBufferData = (PFNGLBUFFERDATAPROC)GetGLProc(api, "glBufferData");
    api->glBufferSubData = (PFNGLBUFFERSUBDATAPROC)GetGLProc(api, "glBufferSubData");
    api->glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)GetGLProc(api, "glCheckFramebufferStatus");
    api->glClear = (PFNGLCLEARPROC)GetGLProc(api, "glClear");
    api->glClearColor = (PFNGLCLEARCOLORPROC)GetGLProc(api, "glClearColor");
    api->glClearDepth = (PFNGLCLEARDEPTHPROC)GetGLProc(api, "glClearDepth");
    api->glClearStencil = (PFNGLCLEARSTENCILPROC)GetGLProc(api, "glClearStencil");
    api->glColorMask = (PFNGLCOLORMASKPROC)GetGLProc(api, "glColorMask");
    api->glCompileShader = (PFNGLCOMPILESHADERPROC)GetGLProc(api, "glCompileShader");
    api->glCreateProgram = (PFNGLCREATEPROGRAMPROC)GetGLProc(api, "glCreateProgram");
    api->glCreateShader = (PFNGLCREATESHADERPROC)GetGLProc(api, "glCreateShader");
    api->glCullFace = (PFNGLCULLFACEPROC)GetGLProc(api, "glCullFace");
    api->glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)GetGLProc(api, "glDeleteBuffers");
    api->glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)GetGLProc(api, "glDeleteFramebuffers");
    api->glDeleteProgram = (PFNGLDELETEPROGRAMPROC)GetGLProc(api, "glDeleteProgram");
    api->glDeleteShader = (PFNGLDELETESHADERPROC)GetGLProc(api, "glDeleteShader");
    api->glDeleteTextures = (PFNGLDELETETEXTURESPROC)GetGLProc(api, "glDeleteTextures");
    api->glDepthMask = (PFNGLDEPTHMASKPROC)GetGLProc(api, "glDepthMask");
    api->glDisable = (PFNGLDISABLEPROC)GetGLProc(api, "glDisable");
    api->glDisablei = (PFNGLDISABLEIPROC)GetGLProc(api, "glDisablei");
    api->glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)GetGLProc(api, "glDisableVertexAttribArray");
    api->glDrawArrays = (PFNGLDRAWARRAYSPROC)GetGLProc(api, "glDrawArrays");
    api->glDrawElements = (PFNGLDRAWELEMENTSPROC)GetGLProc(api, "glDrawElements");
    api->glEnable = (PFNGLENABLEPROC)GetGLProc(api, "glEnable");
    api->glEnablei = (PFNGLENABLEIPROC)GetGLProc(api, "glEnablei");
    api->glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)GetGLProc(api, "glEnableVertexAttribArray");
    api->glFinish = (PFNGLFINISHPROC)GetGLProc(api, "glFinish");
    api->glFlush = (PFNGLFLUSHPROC)GetGLProc(api, "glFlush");
    api->glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)GetGLProc(api, "glFramebufferTexture2D");
    api->glGenBuffers = (PFNGLGENBUFFERSPROC)GetGLProc(api, "glGenBuffers");
    api->glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)GetGLProc(api, "glGenerateMipmap");
    api->glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)GetGLProc(api, "glGenFramebuffers");
    api->glGenTextures = (PFNGLGENTEXTURESPROC)GetGLProc(api, "glGenTextures");
    api->glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)GetGLProc(api, "glGetActiveAttrib");
    api->glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)GetGLProc(api, "glGetActiveUniform");
    api->glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)GetGLProc(api, "glGetAttribLocation");
    api->glGetError = (PFNGLGETERRORPROC)GetGLProc(api, "glGetError");
    api->glGetIntegerv = (PFNGLGETINTEGERVPROC)GetGLProc(api, "glGetIntegerv");
    api->glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)GetGLProc(api, "glGetProgramInfoLog");
    api->glGetProgramiv = (PFNGLGETPROGRAMIVPROC)GetGLProc(api, "glGetProgramiv");
    api->glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)GetGLProc(api, "glGetShaderInfoLog");
    api->glGetShaderiv = (PFNGLGETSHADERIVPROC)GetGLProc(api, "glGetShaderiv");
    api->glGetString = (PFNGLGETSTRINGPROC)GetGLProc(api, "glGetString");
    api->glGetStringi = (PFNGLGETSTRINGIPROC)GetGLProc(api, "glGetStringi");
    api->glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)GetGLProc(api, "glGetTexLevelParameteriv");
    api->glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)GetGLProc(api, "glGetUniformLocation");
    api->glIsProgram = (PFNGLISPROGRAMPROC)GetGLProc(api, "glIsProgram");
    api->glIsShader = (PFNGLISSHADERPROC)GetGLProc(api, "glIsShader");
    api->glLinkProgram = (PFNGLLINKPROGRAMPROC)GetGLProc(api, "glLinkProgram");
    api->glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)GetGLProc(api, "glPatchParameteri");
    api->glPixelStorei = (PFNGLPIXELSTOREIPROC)GetGLProc(api, "glPixelStorei");
    api->glPolygonMode = (PFNGLPOLYGONMODEPROC)GetGLProc(api, "glPolygonMode");
    api->glScissor = (PFNGLSCISSORPROC)GetGLProc(api, "glScissor");
    api->glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)GetGLProc(api, "glProgramParameteri");
    api->glReadPixels = (PFNGLREADPIXELSPROC)GetGLProc(api, "glReadPixels");
    api->glShaderSource = (PFNGLSHADERSOURCEPROC)GetGLProc(api, "glShaderSource");
    api->glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)GetGLProc(api, "glTexSubImage2D");
    api->glTexImage2D = (PFNGLTEXIMAGE2DPROC)GetGLProc(api, "glTexImage2D");
    api->glTexParameterf = (PFNGLTEXPARAMETERFPROC)GetGLProc(api, "glTexParameterf");
    api->glTexParameteri = (PFNGLTEXPARAMETERIPROC)GetGLProc(api, "glTexParameteri");
    api->glUniform1f = (PFNGLUNIFORM1FPROC)GetGLProc(api, "glUniform1f");
    api->glUniform1fv = (PFNGLUNIFORM1FVPROC)GetGLProc(api, "glUniform1fv");
    api->glUniform1i = (PFNGLUNIFORM1IPROC)GetGLProc(api, "glUniform1i");
    api->glUniform1iv = (PFNGLUNIFORM1IVPROC)GetGLProc(api, "glUniform1iv");
    api->glUniform3fv = (PFNGLUNIFORM3FVPROC)GetGLProc(api, "glUniform3fv");
    api->glUniform4fv = (PFNGLUNIFORM4FVPROC)GetGLProc(api, "glUniform4fv");
    api->glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)GetGLProc(api, "glUniformMatrix3fv");
    api->glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)GetGLProc(api, "glUniformMatrix4fv");
    api->glUseProgram = (PFNGLUSEPROGRAMPROC)GetGLProc(api, "glUseProgram");
    api->glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)GetGLProc(api, "glValidateProgram");
    api->glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)GetGLProc(api, "glVertexAttribPointer");
    api->glViewport = (PFNGLVIEWPORTPROC)GetGLProc(api, "glViewport");

    api->wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)GetGLProc(api, "wglChoosePixelFormatARB");
    api->wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)GetGLProc(api, "wglCreateContextAttribsARB");
    api->wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)GetGLProc(api, "wglGetExtensionsStringARB");
}

//---------------------------------------------------------------------------
void* SYSapiLoaderWindows::GetGLProc(IGLAPI* IGL3, const char* name) const
{
    void* proc = NULL;

    if (IGL3->wglGetProcAddress)
    {
        proc = (void*)IGL3->wglGetProcAddress(name);
    }

    return proc ? proc : (libHandle ? (void*)::GetProcAddress((HMODULE)libHandle, name) : NULL);
}

};
