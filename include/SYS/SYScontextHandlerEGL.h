//---------------------------------------------------------------------------
// SYScontextHandlerEGL.h
//---------------------------------------------------------------------------

#pragma once

#include <EGL/egl.h>
#include "IGL/IGLcontextHandler.h"

namespace cc
{

struct IGLAPI;

class SYScontextHandlerEGL : public IGLcontextHandler
{
    public:
        SYScontextHandlerEGL(IGLAPI* api);
        void CreateContext();
        void DeleteContext();
        void MakeCurrent();
        void SwapBuffers();

    private:
        IGLAPI* m_api;
        EGLDisplay m_display;
        EGLSurface m_surface;
        EGLContext m_context;
};

}
