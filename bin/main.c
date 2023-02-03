#include <stdlib.h>
#include <stdio.h>
#include "../include/systeminfo.h"

int main(int argc, char *argv[])
{
    char *osName = getOsName();
    printf("%s\n", osName);
    free(osName);
}
