#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/osInfo.h"
#include "../include/hardwareInfo.h"

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "sm")) != -1)
    {
        switch (opt)
        {
        case 's':
            //Retorna infomações do sistema operacional
            char *osName = getOsName();
            printf("Name: %s\n", osName);
            free(osName);

            char *osKernel = getOsKernel();
            printf("Kernel: %s\n", osKernel);
            free(osKernel);

            char *osArch = getOsArch();
            printf("Arch: %s\n", osArch);
            free(osArch);
            break;
        case 'm':
            //Retorna informações do hardware
            char *processorInfo = getProcessorInfo();
            printf("Processor: %s\n", processorInfo);
            free(processorInfo);

            char *ramInfo = getRamInfo();
            printf("RAM: %s\n", ramInfo);
            free(ramInfo);
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