//---------------------------------------------------------------------------
// SYScontextHandlerWGL.cpp
//---------------------------------------------------------------------------

#include <iostream>
#include "IGL/IGLapi.h"
#include "GL/gl3.h"
#include "SYS/SYScontextHandlerWGL.h"

using namespace std;

static const int contextVersionMajor = 3;
static const int contextVersionMinor = 2;

namespace cc
{

//---------------------------------------------------------------------------
SYScontextHandlerWGL::SYScontextHandlerWGL(IGLAPI* api) :
m_api(api),
m_deviceContext(0),
m_renderContext(0)
{
}

//---------------------------------------------------------------------------
bool SYScontextHandlerWGL::ChooseAndSetPixelFormat(
                               DEVICE_CONTEXT_TYPE DeviceContext,
                               int BitsPerPixel, int ZBufferBits,
                               int StencilBits, int Multisample)
{
    PIXELFORMATDESCRIPTOR PFD;
    memset(&PFD, 0, sizeof(PFD));
    PFD.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    PFD.nVersion = 1;
    PFD.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |PFD_DOUBLEBUFFER;
    PFD.iPixelType = PFD_TYPE_RGBA;
    PFD.cColorBits = static_cast<BYTE>(BitsPerPixel & 0xFF);
    PFD.cDepthBits = static_cast<BYTE>(ZBufferBits  & 0xFF);
    PFD.cStencilBits = static_cast<BYTE>(StencilBits  & 0xFF);
    PFD.iLayerType = PFD_MAIN_PLANE;

    GLint PixelFormat = 0;

    if (m_api->wglChoosePixelFormatARB)
    {
        const int Attribs[] =
        {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
            WGL_DOUBLE_BUFFER_ARB, GL_TRUE, WGL_PIXEL_TYPE_ARB,
            WGL_TYPE_RGBA_ARB, WGL_COLOR_BITS_ARB, BitsPerPixel,
            WGL_DEPTH_BITS_ARB, ZBufferBits, WGL_STENCIL_BITS_ARB,
            StencilBits, WGL_SAMPLE_BUFFERS_ARB, GL_TRUE, WGL_SAMPLES_ARB,
            Multisample, 0
        };

        GLuint Count = 0;

        m_api->wglChoosePixelFormatARB(DeviceContext, Attribs, NULL, 1,
            &PixelFormat, &Count);

        if (!PixelFormat)
        {
            PixelFormat = ::ChoosePixelFormat(DeviceContext, &PFD);
        }
        return ::SetPixelFormat(DeviceContext, PixelFormat, NULL) == TRUE;
    }

    if (!PixelFormat)
    {
        PixelFormat = ::ChoosePixelFormat(DeviceContext, &PFD);
    }
    return ::SetPixelFormat(DeviceContext, PixelFormat, &PFD) == TRUE;
}

//---------------------------------------------------------------------------
void SYScontextHandlerWGL::CreateContext()
{
    if (m_api->wglCreateContextAttribsARB)
    {
        cout << "Using wglCreateContextAttribsARB()" << endl;

        const int Attribs[] =
        {
            WGL_CONTEXT_MAJOR_VERSION_ARB, contextVersionMajor,
            WGL_CONTEXT_MINOR_VERSION_ARB, contextVersionMinor,
            WGL_CONTEXT_LAYER_PLANE_ARB  , 0,
            WGL_CONTEXT_PROFILE_MASK_ARB , WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0 // end
        };

        m_renderContext = m_api->wglCreateContextAttribsARB(m_deviceContext, 0, Attribs);
    }
    else
    {
        cout << "Using glCreateContext()" << endl;

        m_renderContext = m_api->wglCreateContext(m_deviceContext);
    }
}

//---------------------------------------------------------------------------
void SYScontextHandlerWGL::CreateContextFull(DEVICE_CONTEXT_TYPE DeviceContext, int BitsPerPixel, int ZBufferBits, int StencilBits, int Multisample, int VersionMajor, int VersionMinor)
{
    bool FormatSet = ChooseAndSetPixelFormat(DeviceContext, BitsPerPixel, ZBufferBits, StencilBits, Multisample);

    if (!FormatSet)
    {
        printf("Can't set the pixel format\n");
    }

    CreateContext();

    if (!m_renderContext)
    {
        printf("Can't create an OpenGL rendering context\n");
    }

    MakeCurrent();
}

//---------------------------------------------------------------------------
void SYScontextHandlerWGL::MakeCurrent()
{
    if (!m_api->wglMakeCurrent(m_deviceContext, m_renderContext))
    {
        // Can't activate the OpenGL rendering context
    }
}

//---------------------------------------------------------------------------
void SYScontextHandlerWGL::DeleteContext()
{
    m_api->wglMakeCurrent(m_deviceContext, 0);
    m_api->wglDeleteContext(m_renderContext);
}

//---------------------------------------------------------------------------
void SYScontextHandlerWGL::SwapBuffers()
{
    // Not yet implemented
}

}
