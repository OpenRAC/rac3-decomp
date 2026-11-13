#include "common.h"

/* declared by functions of L39_005DC4C0.c, which this file was cut from */
extern u8 *D_L39_0024BF5C;
extern void func_L01_00451388(u8 *, s32 *, s32 *);
typedef struct {
    u8 pad[136];
    s32 f88[2];
} S_005DD258;
extern S_005DD258 *D_L39_00352B4C[];
typedef struct {
    u8 pad40[0x40];
    s32 f40[8];
    s32 f60[8];
    u8 pad80[0x28];
    s32 fA8[8];
} S_005DD290_e;
typedef struct {
    u8 pad[0x20C];
    S_005DD290_e *f20C;
} S_005DD290_t;
typedef struct {
    u8 pad[0xC60];
    s32 fC60;
    s32 fC64;
} S_005DD290_g;
extern S_005DD290_t D_L39_00352940;
extern long func_L39_005DD258(u8 *);

INCLUDE_ASM("asm/levels", func_L39_005DD3C0);

INCLUDE_ASM("asm/levels", func_L39_005DD810);
