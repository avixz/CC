//---------------------------------------------------------------------------
// IGLcontextHandlerFactory.cpp
//---------------------------------------------------------------------------

#include "IGL/IGLapi.h"
#include "IGL/IGLcontextHandler.h"
#include "IGL/IGLcontextHandlerFactory.h"

#ifdef LINUX
    #include "SYS/SYScontextHandlerGLX.h"
#elif WINDOWS
    #include "SYS/SYScontextHandlerWGL.h"
#elif ANDROID
    #include "SYS/SYScontextHandlerEGL.h"
#elif EMSC
    #include "SYS/SYScontextHandlerEGL.h"
#endif

namespace cc
{

//---------------------------------------------------------------------------
IGLcontextHandlerFactory::IGLcontextHandlerFactory(IGLAPI* api):
m_api(api) {}

//---------------------------------------------------------------------------
IGLcontextHandler* IGLcontextHandlerFactory::CreateContextHandler()
{
#ifdef LINUX
    return new SYScontextHandlerGLX(m_api);
#elif WINDOWS
    return new SYScontextHandlerWGL(m_api);
#elif EMSC
    return new SYScontextHandlerEGL(m_api);
#elif ANDROID
    return new SYScontextHandlerEGL(m_api);
#endif
}

}

