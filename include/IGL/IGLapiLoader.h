//---------------------------------------------------------------------------
// IGLapiLoader.h
//---------------------------------------------------------------------------

#pragma once

#include "IGL/IGLapi.h"

namespace cc
{
    class IGLapiLoader
    {
    public:
        virtual void GetAPI(IGLAPI* api) const = 0;
    };
};
