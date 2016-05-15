//---------------------------------------------------------------------------
// SYScontextHandlerGLX.h
//---------------------------------------------------------------------------

#pragma once

#include <X11/Xlib.h>
#include <GL/glx.h>
#include "IGL/IGLcontextHandler.h"

namespace cc
{

struct IGLAPI;

class SYScontextHandlerGLX : public IGLcontextHandler
{
    public:
        SYScontextHandlerGLX(IGLAPI* api);
        void CreateContext();
        void DeleteContext();
        void MakeCurrent();
        void SwapBuffers();

    private:
        IGLAPI* m_api;
        Display* m_display;
        Window m_rootWindow;
        Window m_window;
        GLXContext m_context;
};

}
