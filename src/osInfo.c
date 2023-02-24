#define __STDC_WANT_LIB_EXT2__ 1 // Define que você deseja extensões TR 24731-2:2010 que adicionam funções de manipulação de cadeia de caracteres e manipulação de memória.

#include "../include/osInfo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

char *getOsKernel()
{
    struct utsname utsname_buf;

    if (uname(&utsname_buf) != 0)
    {
        fprintf(stderr, "Error calling uname()\n");
        return NULL;
    }

    char *kernel_version = malloc(sizeof(char) * (strlen(utsname_buf.release) + 1));
    if (kernel_version == NULL)
    {
        fprintf(stderr, "Error allocating memory\n");
        return NULL;
    }

    strcpy(kernel_version, utsname_buf.release);
    return kernel_version;
}

char *getOsArch()
{
    struct utsname osInfo;
    if (uname(&osInfo) == -1)
    {
        fprintf(stderr, "Error getting OS information.\n");
        exit(EXIT_FAILURE);
    }

    char *osArchPointer;
    if (asprintf(&osArchPointer, "%s", osInfo.machine) == -1)
    {
        fprintf(stderr, "Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    char *returnValue = strdup(osArchPointer);
    free(osArchPointer);

    return returnValue;
}

char *getOsName()
{
    char *path = "/etc/os-release";
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *osNamePointer = NULL;
    while ((read = getline(&line, &len, file)) != -1)
    {
        if (strstr(line, "PRETTY_NAME") != NULL)
        {
            char *osName = strtok(line, "=");
            osName = strtok(NULL, "=");
            osName = strtok(osName, "\"");
            osNamePointer = strdup(osName);
            break;
        }
    }
    fclose(file);
    if (line)
    {
        free(line);
    }
    return osNamePointer;
}