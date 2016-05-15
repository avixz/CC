//---------------------------------------------------------------------------
// IGLapiLoaderFactory.cpp
//---------------------------------------------------------------------------

#include "IGL/IGLapi.h"
#include "IGL/IGLapiLoaderFactory.h"

#ifdef LINUX
    #include "SYS/SYSapiLoaderLinux.h"
#elif WINDOWS
    #include "SYS/SYSapiLoaderWindows.h"
#elif EMSC
    #include "SYS/SYSapiLoaderEmscripten.h"
#elif ANDROID
    #include "SYS/SYSapiLoaderAndroid.h"
#endif

namespace cc
{

//---------------------------------------------------------------------------
IGLapiLoaderFactory::IGLapiLoaderFactory()
{
}

//---------------------------------------------------------------------------
IGLapiLoader* IGLapiLoaderFactory::CreateLoader()
{
#ifdef LINUX
    return new SYSapiLoaderLinux();
#elif WINDOWS
    return new SYSapiLoaderWindows();
#elif EMSC
    return new SYSapiLoaderEmscripten();
#elif ANDROID
    return new SYSapiLoaderAndroid();
#endif
}

};
