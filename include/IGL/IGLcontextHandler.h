//---------------------------------------------------------------------------
// IGLcontextHandler.h
//---------------------------------------------------------------------------

#pragma once

namespace cc
{

class IGLcontextHandler
{
    public:
        virtual void CreateContext() = 0;
        virtual void DeleteContext() = 0;
        virtual void MakeCurrent() = 0;
        virtual void SwapBuffers() = 0;
};

};
