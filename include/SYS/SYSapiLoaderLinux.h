//---------------------------------------------------------------------------
// SYSapiLoaderLinux.h
//---------------------------------------------------------------------------

#pragma once

#include <X11/Xlib.h>
#include "GL/gl3.h"
#include <GL/glx.h>
#include "IGL/IGLapiLoader.h"

#define IGL_CALL

namespace cc
{
    class SYSapiLoaderLinux : public IGLapiLoader
    {
    public:
        void GetAPI(IGLAPI* api) const;
    };
};

