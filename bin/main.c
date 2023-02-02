#include "../include/systeminfo.h"

#include <stdio.h>
int main(int argc, char *argv[])
{
    char *osName = getOsName();

    printf("OS Name: %s", osName);
}
