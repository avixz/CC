//---------------------------------------------------------------------------
// IGLcontextHandlerWGL.h
//---------------------------------------------------------------------------

#pragma once

#include <windows.h>
#include <windef.h>
#include "GL/gl3.h"
#include "GL/wglext.h"
#include "IGL/IGLapi.h"
#include "IGL/IGLcontextHandler.h"

namespace cc
{
    class SYScontextHandlerWGL : public IGLcontextHandler
    {
    public:
        SYScontextHandlerWGL(IGLAPI* api);
        void CreateContext();
        void DeleteContext();
        void MakeCurrent();
        void SwapBuffers();

    private:
        bool cc::SYScontextHandlerWGL::ChooseAndSetPixelFormat(
                                       DEVICE_CONTEXT_TYPE DeviceContext,
                                       int BitsPerPixel, int ZBufferBits,
                                       int StencilBits, int Multisample);
        void SYScontextHandlerWGL::CreateContextFull(
                                   DEVICE_CONTEXT_TYPE DeviceContext,
                                   int BitsPerPixel, int ZBufferBits,
                                   int StencilBits, int Multisample,
                                   int VersionMajor, int VersionMinor);
        IGLAPI* m_api;
        DEVICE_CONTEXT_TYPE m_deviceContext;
        GL_CONTEXT_TYPE m_renderContext;

    };
};
