//---------------------------------------------------------------------------
// IGLapiLoaderFactory.h
//---------------------------------------------------------------------------

#pragma once

namespace cc {

struct IGLAPI;
class IGLapiLoader;

class IGLapiLoaderFactory
{
    public:
        IGLapiLoaderFactory();
        IGLapiLoader* CreateLoader();

    private:
        IGLAPI* m_api;
};

};
