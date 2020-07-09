#ifndef _SETTING_H_
#define _SETTING_H_

#include <windows.h>
#include <string>

#define REG_DATA_LENGTH SIZE_MAX

using namespace std;

namespace UltraEd
{
    enum class BuildCart { _64drive, EverDrive };

    enum class VideoMode { NTSC, PAL };

    class Settings
    {
    public:
        static void SetBuildCart(BuildCart cart);
        static BuildCart GetBuildCart();
        static void SetVideoMode(VideoMode mode);
        static VideoMode GetVideoMode();
    };
}

#endif
