#define __STDC_WANT_LIB_EXT2__ 1 // Defina que você deseja extensões TR 24731-2:2010 que adicionam funções de manipulação de cadeia de caracteres e manipulação de memória.

#include "../include/systeminfo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

char *getOsName()
{
    struct utsname osInfo;
    uname(&osInfo);
    char *osNamePointer;
    asprintf(&osNamePointer, "%s %s", osInfo.sysname, osInfo.release);
    char *returnValue = strdup(osNamePointer);
    free(osNamePointer);
    return returnValue;
}