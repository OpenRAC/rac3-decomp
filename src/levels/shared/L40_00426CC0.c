#include "common.h"

/* declared by functions of L40_00426B60.c, which this file was cut from */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_426250;
typedef struct {
    u8 pad0[720];
    f32 *pos;
} Q426250;
typedef struct {
    u8 pad0[9508];
    f32 *pos;
    Q426250 *q;
    u8 pad252C[9544 - 9516];
    s32 team;
} P426250;
typedef struct {
    u8 pad0[16];
    s32 f10;
} V426250;
typedef struct {
    u8 pad0[36];
    V426250 *v;
    u8 pad28[152 - 40];
    s32 f98;
} A426250;
typedef struct {
    u8 pad0[596];
    f32 range;
    u8 pad258[636 - 600];
    s32 team;
} B426250;
extern s32 func_L39_006481F8(P426250 *p);
extern f32 func_L01_0040E548(void *a, void *b);
extern s32 func_L40_00424BA0(void *a, void *b, f32 *c);

INCLUDE_ASM("asm/levels", func_L40_00426CC0);

INCLUDE_ASM("asm/levels", func_L40_00426F68);
