//---------------------------------------------------------------------------
// SYSapiLoaderEmscripten.h
//---------------------------------------------------------------------------

#pragma once

#include "IGL/IGLapiLoader.h"

namespace cc
{
    class SYSapiLoaderEmscripten : public IGLapiLoader
    {
    public:
        void GetAPI(IGLAPI* api) const;
    };
};

