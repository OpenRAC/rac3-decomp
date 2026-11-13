#include "common.h"

/* declared by functions of L39_006921B8.c, which this file was cut from */
typedef struct {
    u8 pad[0x34];
    u8 on;
} M_006921E0;
typedef struct {
    u8 pad[0x38];
    M_006921E0 *mgr;
} G_006921E0;
extern G_006921E0 *D_L39_0024D760;

INCLUDE_ASM("asm/levels", func_L39_00692420);
