#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

/* declared by functions of L39_0068B768.c, which this file was cut from */
extern s32 D_001DC3F4_sda;

INCLUDE_ASM("asm/levels", func_L39_0068B8B0);
