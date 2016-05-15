//---------------------------------------------------------------------------
// IGLcontextHandlerFactory.h
//---------------------------------------------------------------------------

#pragma once

namespace cc
{

struct IGLAPI;
class IGLcontextHandler;

class IGLcontextHandlerFactory
{
    public:
        IGLcontextHandlerFactory(IGLAPI* api);
        IGLcontextHandler* CreateContextHandler();

    private:
        IGLAPI* m_api;
};

};
