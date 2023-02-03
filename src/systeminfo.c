#define __STDC_WANT_LIB_EXT2__ 1 // Defina que você deseja extensões TR 24731-2:2010 que adicionam funções de manipulação de cadeia de caracteres e manipulação de memória.

#include "../include/systeminfo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32

#include <windows.h>
#include <VersionHelpers.h>

#elif __linux__

#include <unistd.h>
#include <sys/utsname.h>

#endif

char *getOsName()
{
#ifdef _WIN32

    char osName[512];
    if (IsWindows10OrGreater())
    {
        sprintf(osName, "Windows 10 %d.%d.%d",
                (int)LOBYTE(LOWORD(GetVersion())),
                (int)HIBYTE(LOWORD(GetVersion())),
                (int)HIWORD(GetVersion()));
    }
    else if (IsWindows8Point1OrGreater())
    {
        sprintf(osName, "Windows 8.1 %d.%d.%d",
                (int)LOBYTE(LOWORD(GetVersion())),
                (int)HIBYTE(LOWORD(GetVersion())),
                (int)HIWORD(GetVersion()));
    }
    else if (IsWindows8OrGreater())
    {
        sprintf(osName, "Windows 8 %d.%d.%d",
                (int)LOBYTE(LOWORD(GetVersion())),
                (int)HIBYTE(LOWORD(GetVersion())),
                (int)HIWORD(GetVersion()));
    }
    else
    {
        sprintf(osName, "Windows %d.%d.%d",
                (int)LOBYTE(LOWORD(GetVersion())),
                (int)HIBYTE(LOWORD(GetVersion())),
                (int)HIWORD(GetVersion()));
    }
    char *osNamePointer = (char *)malloc(sizeof(osName));
    strcpy(osNamePointer, osName);
    return osNamePointer;

#elif __linux__

    struct utsname osInfo;
    uname(&osInfo);
    char *osNamePointer;
    asprintf(&osNamePointer, "%s %s", osInfo.sysname, osInfo.release);
    char *returnValue = strdup(osNamePointer);
    free(osNamePointer);
    return returnValue;

#endif
}