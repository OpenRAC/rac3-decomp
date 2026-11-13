#include "common.h"

typedef struct Loc_006DA090 {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 f30[0x40];
} Loc_006DA090;
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;

/* declared by functions of L39_006D8E90.c, which this file was cut from */
extern Obj_006DA090 *D_L39_0024D760;
s32 func_001206F4(void *, s32);
void func_001961E8(void *);
s32 func_001961F8(void);
extern u16 D_L39_00249EE8[];
void func_L39_005958A0(void *, void *, s32);
extern Obj_006DA090 *D_L39_0024D760 __attribute__((section(".data")));

INCLUDE_ASM("asm/levels", func_L39_006D9E68);
