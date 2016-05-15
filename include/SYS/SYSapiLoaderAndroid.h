//---------------------------------------------------------------------------
// SYSapiLoaderAndroid.h
//---------------------------------------------------------------------------

#pragma once

#pragma once

#include "IGL/IGLapiLoader.h"

namespace cc
{
    class SYSapiLoaderAndroid : public IGLapiLoader
    {
    public:
        void GetAPI(IGLAPI* api) const;
    };
};

