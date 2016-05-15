//---------------------------------------------------------------------------
// SYScontextHandlerEGL.cpp
//---------------------------------------------------------------------------

#include <iostream>
#include "IGL/IGLapi.h"
#include "SYS/SYScontextHandlerEGL.h"

namespace cc
{

SYScontextHandlerEGL::SYScontextHandlerEGL(IGLAPI* api):
m_api(api),
m_display(NULL),
m_surface(NULL),
m_context(NULL)
{
}

void SYScontextHandlerEGL::CreateContext()
{
    m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    if (m_display == EGL_NO_DISPLAY)
    {
        std::cout << "Cannot get display" << std::endl;
    }

    if (!eglInitialize(m_display, 0, 0))
    {
        std::cout << "Error initializing display" << std::endl;
    }

    // Find a config with the required attributes
    GLint att[] = { EGL_SURFACE_TYPE, EGL_PIXMAP_BIT, EGL_BLUE_SIZE, 8,
        EGL_GREEN_SIZE, 8, EGL_RED_SIZE, 8, EGL_NONE,
        EGL_BIND_TO_TEXTURE_RGBA, EGL_TRUE };

    int configs;
    EGLConfig conf;
    eglChooseConfig(m_display, att, &conf, 1, &configs);

    if (configs != 1)
    {
        std::cout << "Config not found" << std::endl;
    }

    // Create a main render target surface
    m_surface = eglCreateWindowSurface(m_display, conf, NULL, att);

    // Create the context and activate it
    m_context = eglCreateContext(m_display, conf, NULL, att);
    eglMakeCurrent(m_display, m_surface, m_surface, m_context);
}

void SYScontextHandlerEGL::DeleteContext()
{
}

void SYScontextHandlerEGL::MakeCurrent()
{
}

void SYScontextHandlerEGL::SwapBuffers()
{
    eglSwapBuffers(m_display, m_surface);
}

}
