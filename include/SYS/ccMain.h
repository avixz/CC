//---------------------------------------------------------------------------
// ccMain.h
//---------------------------------------------------------------------------

extern int ccMain();

#ifdef WIN32
#include <windows.h>

//---------------------------------------------------------------------------
int WINAPI WinMain( HINSTANCE hInstance,  HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
    ccMain();
}
#elif ANDROID
#include "SYS/android_native_app_glue.h"
//---------------------------------------------------------------------------
void android_main(struct android_app* app)
{
    app_dummy();
    ccMain();
}
#elif EMSC
#include "emscripten/emscripten.h"
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    ccMain();
}
#else
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    ccMain();
}
#endif

