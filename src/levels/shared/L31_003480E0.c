#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

INCLUDE_ASM("asm/levels", func_L31_003480E0);

INCLUDE_ASM("asm/levels", func_L31_00348BD8);

INCLUDE_ASM("asm/levels", func_L31_00348EE8);
