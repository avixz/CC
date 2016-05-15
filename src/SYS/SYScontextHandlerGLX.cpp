//---------------------------------------------------------------------------
// SYScontextHandlerGLX.cpp
//---------------------------------------------------------------------------

#include <iostream>
#include <X11/Xlib.h>
#include "GL/gl3.h"
#include <GL/glx.h>
#include "IGL/IGLapi.h"
#include "SYS/SYScontextHandlerGLX.h"

namespace cc
{

SYScontextHandlerGLX::SYScontextHandlerGLX(IGLAPI* api):
m_api(api),
m_display(0),
m_rootWindow(0),
m_window(0),
m_context(0)
{
}

void SYScontextHandlerGLX::CreateContext()
{
    m_display = XOpenDisplay(NULL);

    if(m_display == NULL)
    {
        std::cout << "Cannot connect to X server!" << std::endl;
    }

    // Get a handle to the root window
    m_rootWindow = DefaultRootWindow(m_display);

    // Ask for a visual with the needed capabilities
    GLint att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
    XVisualInfo* visual = glXChooseVisual(m_display, 0, att);

    if(visual == NULL)
    {
        std::cout << "No appropiate visual found" << std::endl;
    }
    else {
        std::cout << "Visual " << (void *)visual->visualid << " selected"
            << std::endl;
    }

    // Create colormap
    Colormap cmap = XCreateColormap(m_display, m_rootWindow, visual->visual,
        AllocNone);

    // Set window attributes
    XSetWindowAttributes swa;
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;

    // Create window, set title and display it
    m_window = XCreateWindow(m_display, m_rootWindow, 0, 0, 600, 600, 0,
        visual->depth, InputOutput, visual->visual, CWColormap | CWEventMask,
        &swa);
    XMapWindow(m_display, m_window);
    XStoreName(m_display, m_window, "Hello, World!");

    // Create the GL context and bind it to the window
    m_context = glXCreateContext(m_display, visual, NULL, GL_TRUE);
    glXMakeCurrent(m_display, m_window, m_context);
}

void SYScontextHandlerGLX::DeleteContext()
{
}

void SYScontextHandlerGLX::MakeCurrent()
{
}

void SYScontextHandlerGLX::SwapBuffers()
{
    glXSwapBuffers(m_display, m_window);
}

}

