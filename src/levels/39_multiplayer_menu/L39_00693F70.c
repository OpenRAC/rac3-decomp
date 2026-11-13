#include "common.h"

/* declared by functions of L39_006928D0.c, which this file was cut from */
typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_006928D0_inner;
typedef struct {
    char pad[0x38];
    S_006928D0_inner *f38;
} S_006928D0_outer;
typedef struct {
    char pad[0x284];
    s32 f284;
} S_006928D0_slot;
extern S_006928D0_outer *D_L39_0024D760;
extern S_006928D0_slot *D_001DC204_sda;

INCLUDE_ASM("asm/levels", func_L39_00693F70);
