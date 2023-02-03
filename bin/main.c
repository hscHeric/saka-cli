#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/systeminfo.h"

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "s")) != -1)
    {
        switch (opt)
        {
        case 's':
            char *osName = getOsName();
            printf("%s\n", osName);
            free(osName);
            break;
        default:
            break;
        }
    }

    if (argc == 1)
    {
        fprintf(stderr, "Usage: %s [-s] \n", argv[0]);
        return 1;
    }

    return 0;
}