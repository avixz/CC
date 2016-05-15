//---------------------------------------------------------------------------
// SYSapiLoaderEmscripten.cpp
//---------------------------------------------------------------------------

#include "SYS/SYSapiLoaderEmscripten.h"

namespace cc
{

IGL_CALL void Emulate_glClearDepth( double Depth )
{
	glClearDepthf( static_cast<float>( Depth ) );
}

IGL_CALL void Emulate_glPolygonMode( GLenum, GLenum )
{
	// not supported
}

IGL_CALL void Emulate_glPatchParameteri( GLenum, GLint )
{
	// not supported
}

IGL_CALL void Emulate_glDisablei( GLenum mode, GLuint )
{
	glDisable( mode );
}

IGL_CALL void Emulate_glEnablei( GLenum mode, GLuint )
{
	glEnable( mode );
}

IGL_CALL void Emulate_glBindFragDataLocation( GLuint, GLuint, const GLchar* )
{
	// not supported
}

IGL_CALL void Emulate_glProgramParameteri( GLuint, GLenum, GLint )
{
	// not supported
}

IGL_CALL void Emulate_glGetTexLevelParameteriv( GLenum, GLint, GLenum, GLint* )
{
	// not supported
}

void SYSapiLoaderEmscripten::GetAPI(IGLAPI* api) const
{
	api->glActiveTexture = &glActiveTexture;
	api->glAttachShader = &glAttachShader;
	api->glBindAttribLocation = &glBindAttribLocation;
	api->glBindBuffer = &glBindBuffer;
	api->glBindFragDataLocation = &Emulate_glBindFragDataLocation;
	api->glBindFramebuffer = &glBindFramebuffer;
	api->glBindTexture = &glBindTexture;
	api->glBlendFunc = &glBlendFunc;
	api->glBufferData = &glBufferData;
	api->glBufferSubData = &glBufferSubData;
	api->glCheckFramebufferStatus = &glCheckFramebufferStatus;
	api->glClear = &glClear;
	api->glClearColor = &glClearColor;
	api->glClearDepth = &Emulate_glClearDepth;
	api->glClearStencil = &glClearStencil;
	api->glColorMask = &glColorMask;
	api->glCompileShader = &glCompileShader;
	api->glCreateProgram = &glCreateProgram;
	api->glCreateShader = &glCreateShader;
	api->glCullFace = &glCullFace;
	api->glDeleteBuffers = &glDeleteBuffers;
	api->glDeleteFramebuffers = &glDeleteFramebuffers;
	api->glDeleteProgram = &glDeleteProgram;
	api->glDeleteShader = &glDeleteShader;
	api->glDeleteTextures = &glDeleteTextures;
	api->glDepthMask = &glDepthMask;
	api->glDisable = &glDisable;
	api->glDisablei = &Emulate_glDisablei;
	api->glDisableVertexAttribArray = &glDisableVertexAttribArray;
	api->glDrawArrays = &glDrawArrays;
	api->glDrawElements = &glDrawElements;
	api->glEnable = &glEnable;
	api->glEnablei = &Emulate_glEnablei;
	api->glEnableVertexAttribArray = &glEnableVertexAttribArray;
	api->glFinish = &glFinish;
	api->glFlush = &glFlush;
	api->glFramebufferTexture2D = &glFramebufferTexture2D;
	api->glGenBuffers = &glGenBuffers;
	api->glGenerateMipmap = &glGenerateMipmap;
	api->glGenFramebuffers = &glGenFramebuffers;
	api->glGenTextures = &glGenTextures;
	api->glGetActiveAttrib = &glGetActiveAttrib;
	api->glGetActiveUniform = &glGetActiveUniform;
	api->glGetAttribLocation = &glGetAttribLocation;
	api->glGetError = &glGetError;
	api->glGetIntegerv = &glGetIntegerv;
	api->glGetProgramInfoLog = &glGetProgramInfoLog;
	api->glGetProgramiv = &glGetProgramiv;
	api->glGetShaderInfoLog = &glGetShaderInfoLog;
	api->glGetShaderiv = &glGetShaderiv;
	api->glGetString = ( PFNGLGETSTRINGPROC )&glGetString;
	api->glGetTexLevelParameteriv = &Emulate_glGetTexLevelParameteriv;
	api->glGetUniformLocation = &glGetUniformLocation;
	api->glIsProgram = &glIsProgram;
	api->glIsShader = &glIsShader;
	api->glLinkProgram = &glLinkProgram;
	api->glPatchParameteri = &Emulate_glPatchParameteri;
	api->glPixelStorei = &glPixelStorei;
	api->glPolygonMode = &Emulate_glPolygonMode;
	api->glScissor = &glScissor;
	api->glProgramParameteri = &Emulate_glProgramParameteri;
	api->glReadPixels = &glReadPixels;
	// OpenGL ES 2 and OpenGL ES 3 have different "const" in prototype of glShaderSource
	api->glShaderSource = ( PFNGLSHADERSOURCEPROC )&glShaderSource;
	api->glTexSubImage2D = &glTexSubImage2D;
	api->glTexImage2D = &glTexImage2D;
	api->glTexParameterf = &glTexParameterf;
	api->glTexParameteri = &glTexParameteri;
	api->glUniform1f = &glUniform1f;
	api->glUniform1fv = &glUniform1fv;
	api->glUniform1i = &glUniform1i;
	api->glUniform1iv = &glUniform1iv;
	api->glUniform3fv = &glUniform3fv;
	api->glUniform4fv = &glUniform4fv;
	api->glUniformMatrix3fv = &glUniformMatrix3fv;
	api->glUniformMatrix4fv = &glUniformMatrix4fv;
	api->glUseProgram = &glUseProgram;
	api->glValidateProgram = &glValidateProgram;
	api->glVertexAttribPointer = &glVertexAttribPointer;
	api->glViewport = &glViewport;
}

}

