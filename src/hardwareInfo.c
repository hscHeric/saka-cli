#include "../include/hardwareInfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *getProcessorInfo()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *processorInfo = (char *)malloc(100 * sizeof(char));
    fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (strstr(line, "model name") != NULL)
        {
            strcpy(processorInfo, line);
            break;
        }
    }
    fclose(fp);
    if (line)
    {
        free(line);
    }
    return processorInfo;
}

char* getRamInfo()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *ramInfo = (char *)malloc(100 * sizeof(char));
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (strstr(line, "MemTotal") != NULL)
        {
            unsigned long long totalMemory = 0;
            sscanf(line, "MemTotal: %llu kB", &totalMemory);
            totalMemory /= 1024;
            totalMemory /= 1024;
            sprintf(ramInfo, " %llu GB\n", totalMemory);
            break;
        }
    }
    fclose(fp);
    if (line)
    {
        free(line);
    }
    return ramInfo;
}