#ifndef PERSON_H
#define PERSON_H

#define LINE_SIZE (40U)

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "stdbool.h"
typedef unsigned int uint;

typedef enum {
    INTEL,
    AMD,
    ARM,
    ELBRUS
} CpuType;

typedef enum {
    EMBEDDED,
    EXTERNAL,
    VIDEO_BUS
} VideoCardType;

typedef enum {
    SAS,
    SATA
} DiskType;

typedef enum {
    LINUX,
    MAC_OS,
    WINDOWS_7,
    WINDOWS_8,
    WINDOWS_10,
    WINDOWS_11
} OperatingSystem;

typedef struct {
    char surname[LINE_SIZE]; //40
    uint cpuCount;
    CpuType cpuType;
    uint memorySize; // Gb
    VideoCardType videoCardType;
    uint videoMemorySize; // Gb
    DiskType diskType;
    uint diskCount;
    uint diskSize; // Gb
    uint externalDevicesCount;
    OperatingSystem operatingSystem;
} Person;

#endif //PERSON_H
