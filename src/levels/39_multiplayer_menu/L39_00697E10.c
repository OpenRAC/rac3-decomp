#include "common.h"

/* declared by functions of L39_006979B0.c, which this file was cut from */
typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_00697B28_inner;
typedef struct {
    char pad[0x38];
    S_00697B28_inner *f38;
} S_00697B28_outer;
extern S_00697B28_outer *D_L39_0024D760;

INCLUDE_ASM("asm/levels", func_L39_00697E10);

INCLUDE_ASM("asm/levels", func_L39_006980F8);

INCLUDE_ASM("asm/levels", func_L39_006983B8);

LINKER_REMNANT("asm/levels", func_L39_00698C18);

INCLUDE_ASM("asm/levels", func_L39_00698C28);

LINKER_REMNANT("asm/levels", func_L39_00698F48);
