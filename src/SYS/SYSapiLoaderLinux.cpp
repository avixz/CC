//---------------------------------------------------------------------------
// SYSapiLoaderLinux.cpp
//---------------------------------------------------------------------------

#include "SYS/SYSapiLoaderLinux.h"

namespace cc
{

void SYSapiLoaderLinux::GetAPI(IGLAPI* api) const
{
	//api->glActiveTexture = (PFNGLACTIVETEXTUREPROC)glXGetProcAddress((const GLubyte *)"glActiveTexture");
	//api->glAttachShader = glXGetProcAddress("glAttachShader");
	//api->glBindAttribLocation = glXGetProcAddress("glBindAttribLocation");
	api->glBindBuffer = (PFNGLBINDBUFFERPROC)glXGetProcAddress((const GLubyte*)"glBindBuffer");
	//api->glBindFragDataLocation = glXGetProcAddress("glBindFragDataLocation");
	//api->glBindFramebuffer = glXGetProcAddress("glBindFramebuffer");
	//api->glBindTexture = glXGetProcAddress("glBindTexture");
	//api->glBlendFunc = glXGetProcAddress("glBlendFunc");
	//api->glBufferData = glXGetProcAddress("glBufferData");
	//api->glBufferSubData = glXGetProcAddress("glBufferSubData");
	//api->glCheckFramebufferStatus = glXGetProcAddress("glCheckFramebufferStatus");
	api->glClear = (PFNGLCLEARPROC)glXGetProcAddress((const GLubyte*)"glClear");
	api->glClearColor = (PFNGLCLEARCOLORPROC)glXGetProcAddress((const GLubyte*)"glClearColor");
	//api->glClearDepth = glXGetProcAddress("glClearDepth");
	//api->glClearStencil = glXGetProcAddress("glClearStencil");
	//api->glColorMask = (PFNGLCOLORMASKPROC)GetGLProc("glColorMask");
	//api->glCompileShader = glXGetProcAddress("glCompileShader");
	api->glCreateProgram = (PFNGLCREATEPROGRAMPROC)glXGetProcAddress((const GLubyte*)"glCreateProgram");
	//api->glCreateShader = glXGetProcAddress("glCreateShader");
	//api->glCullFace = glXGetProcAddress("glCullFace");
	//api->glDeleteBuffers = glXGetProcAddress("glDeleteBuffers");
	//api->glDeleteFramebuffers = glXGetProcAddress("glDeleteFramebuffers");
	//api->glDeleteProgram = glXGetProcAddress("glDeleteProgram");
	//api->glDeleteShader = glXGetProcAddress("glDeleteShader");
	//api->glDeleteTextures = glXGetProcAddress("glDeleteTextures");
	//api->glDepthMask = glXGetProcAddress("glDepthMask");
	//api->glDisable = glXGetProcAddress("glDisable");
	//api->glDisablei = glXGetProcAddress("glDisablei");
	//api->glDisableVertexAttribArray = glXGetProcAddress("glDisableVertexAttribArray");
	//api->glDrawArrays = glXGetProcAddress("glDrawArrays");
	//api->glDrawElements = glXGetProcAddress("glDrawElements");
	api->glEnable = (PFNGLENABLEPROC)glXGetProcAddress((const GLubyte*)"glEnable");
	//api->glEnablei = glXGetProcAddress("glEnablei");
	//api->glEnableVertexAttribArray = glXGetProcAddress("glEnableVertexAttribArray");
	//api->glFinish = glXGetProcAddress("glFinish");
	//api->glFlush = glXGetProcAddress("glFlush");
	//api->glFramebufferTexture2D = glXGetProcAddress("glFramebufferTexture2D");
	api->glGenBuffers = (PFNGLGENBUFFERSPROC)glXGetProcAddress((const GLubyte*)"glGenBuffers");
	//api->glGenerateMipmap = glXGetProcAddress("glGenerateMipmap");
	//api->glGenFramebuffers = glXGetProcAddress("glGenFramebuffers");
	//api->glGenTextures = glXGetProcAddress("glGenTextures");
	//api->glGetActiveAttrib = glXGetProcAddress("glGetActiveAttrib");
	//api->glGetActiveUniform = glXGetProcAddress("glGetActiveUniform");
	//api->glGetAttribLocation = glXGetProcAddress("glGetAttribLocation");
	//api->glGetError = glXGetProcAddress("glGetError");
	//api->glGetIntegerv = glXGetProcAddress("glGetIntegerv");
	//api->glGetProgramInfoLog = glXGetProcAddress("glGetProgramInfoLog");
	//api->glGetProgramiv = glXGetProcAddress("glGetProgramiv");
	//api->glGetShaderInfoLog = glXGetProcAddress("glGetShaderInfoLog");
	//api->glGetShaderiv = glXGetProcAddress("glGetShaderiv");
	//api->glGetString = glXGetProcAddress("glGetString");
	//api->glGetStringi = glXGetProcAddress("glGetStringi");
	//api->glGetTexLevelParameteriv = glXGetProcAddress("glGetTexLevelParameteriv");
	//api->glGetUniformLocation = glXGetProcAddress("glGetUniformLocation");
	//api->glIsProgram = glXGetProcAddress("glIsProgram");
	//api->glIsShader = glXGetProcAddress("glIsShader");
	//api->glLinkProgram = glXGetProcAddress("glLinkProgram");
	//api->glPatchParameteri = glXGetProcAddress("glPatchParameteri");
	//api->glPixelStorei = glXGetProcAddress("glPixelStorei");
	//api->glPolygonMode = glXGetProcAddress("glPolygonMode");
	//api->glScissor = glXGetProcAddress("glScissor");
	//api->glProgramParameteri = glXGetProcAddress("glProgramParameteri");
	//api->glReadPixels = glXGetProcAddress("glReadPixels");
	//api->glShaderSource = glXGetProcAddress("glShaderSource");
	//api->glTexSubImage2D = glXGetProcAddress("glTexSubImage2D");
	//api->glTexImage2D = glXGetProcAddress("glTexImage2D");
	//api->glTexParameterf = glXGetProcAddress("glTexParameterf");
	//api->glTexParameteri = glXGetProcAddress("glTexParameteri");
	//api->glUniform1f = glXGetProcAddress("glUniform1f");
	//api->glUniform1fv = glXGetProcAddress("glUniform1fv");
	//api->glUniform1i = glXGetProcAddress("glUniform1i");
	//api->glUniform1iv = glXGetProcAddress("glUniform1iv");
	//api->glUniform3fv = glXGetProcAddress("glUniform3fv");
	//api->glUniform4fv = glXGetProcAddress("glUniform4fv");
	//api->glUniformMatrix3fv = glXGetProcAddress("glUniformMatrix3fv");
	//api->glUniformMatrix4fv = glXGetProcAddress("glUniformMatrix4fv");
	//api->glUseProgram = glXGetProcAddress("glUseProgram");
	//api->glValidateProgram = glXGetProcAddress("glValidateProgram");
	//api->glVertexAttribPointer = glXGetProcAddress("glVertexAttribPointer");
	//api->glViewport = glXGetProcAddress("glViewport");
}

}

