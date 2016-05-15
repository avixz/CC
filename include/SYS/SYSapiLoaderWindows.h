//---------------------------------------------------------------------------
// SYSapiLoaderWindows.h
//---------------------------------------------------------------------------

#pragma once

#include <windows.h>
#include "GL/gl3.h"
#include "GL/wglext.h"
#include "IGL/IGLAPI.h"
#include "IGL/IGLapiLoader.h"

#define IGL_CALL

namespace cc
{
    class SYSapiLoaderWindows : public IGLapiLoader
    {
    public:
        SYSapiLoaderWindows(): libHandle(NULL) {};
        void GetAPI(IGLAPI* api) const;

    private:
        void* GetGLProc(IGLAPI* IGL3, const char* name) const;
        void* libHandle;
    };
};

