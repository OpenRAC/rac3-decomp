#include "common.h"

/* localdecomp:start func_L39_004B5960 */
extern u32 D_L39_003E4384[];
extern u32 D_L39_003E4388[];
extern u32 D_L39_003E4390[];
extern u32 D_L39_003E43A0[];
extern u32 D_L39_003E43A4[];
extern u32 D_L39_003E43A8[];
extern u32 D_L39_003E43B0[];

u32 func_L39_004B5960(u32 arg0) {
    u32 cur = D_L39_003E4388[0];
    u32 next = cur + (arg0 << D_L39_003E4390[0]);
    u32 t;

    if (next > D_L39_003E4384[0]) {
        return 0;
    }
    D_L39_003E4388[0] = next;
    t = ((next + D_L39_003E43A0[0]) >> D_L39_003E4390[0]) - D_L39_003E43A4[0];
    D_L39_003E43A8[0] = t - 1;
    return t < D_L39_003E43B0[0] ? cur : 0;
}
/* localdecomp:end func_L39_004B5960 */

INCLUDE_ASM("asm/levels", func_L39_004B59D8);

INCLUDE_ASM("asm/levels", func_L39_004B5BE8);

INCLUDE_ASM("asm/levels", func_L39_004B5F68);

INCLUDE_ASM("asm/levels", func_L39_004B6108);

INCLUDE_ASM("asm/levels", func_L39_004B6808);

INCLUDE_ASM("asm/levels", func_L39_004B7418);

/* localdecomp:start func_L39_004B76F8 */
extern s32 D_L39_004646F0;
extern s32 D_L39_003E4398;
void func_00126270(s32);
void func_L39_004B76F8(void) {
    if (--D_L39_004646F0 == 0) {
        func_00126270(D_L39_003E4398);
    }
}
/* localdecomp:end func_L39_004B76F8 */

INCLUDE_ASM("asm/levels", func_L39_004B7748);

INCLUDE_ASM("asm/levels", func_L39_004B7A80);

INCLUDE_ASM("asm/levels", func_L39_004B7C20);

INCLUDE_ASM("asm/levels", func_L39_004B7FF0);

/* localdecomp:start func_L39_004B80D8 */
typedef struct S_004B80D8 {
    u8 pad0[0x410];
    long x410;
    u8 pad418[0x106F8 - 0x418];
    s32 x106F8;
} S_004B80D8;
typedef struct S2_004B80D8 {
    s32 id;
    s32 pad[3];
} S2_004B80D8;
extern S_004B80D8 D_L39_00453FB0;
extern S2_004B80D8 D_L39_00464784;
extern s32 D_L39_004B80A0[];
extern s32 func_0012E2B8(long, void *, s32);

s32 func_L39_004B80D8(void) {
    S_004B80D8 *g = &D_L39_00453FB0;
    S2_004B80D8 *p;

    if (g->x410 != 0) {
        p = &D_L39_00464784;
        if (p->id < 0 && g->x106F8 == 0) {
            return p->id = func_0012E2B8(g->x410, D_L39_004B80A0, 0);
        }
    }
    return -1;
}
/* localdecomp:end func_L39_004B80D8 */

INCLUDE_ASM("asm/levels", func_L39_004B8150);

INCLUDE_ASM("asm/levels", func_L39_004B8190);

INCLUDE_ASM("asm/levels", func_L39_004B87B0);

/* localdecomp:start func_L39_004B9160 */
extern s32 func_L39_004C3D20(void *, u8 *, s32);
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);

s32 func_L39_004B9160(void *arg0, u8 *arg1, s32 arg2) {
    s32 n;
    s32 r;

    for (n = arg2; n > 0; n -= r, arg1 += r) {
        r = func_L39_004C3D20(arg0, arg1, n);
        if (r < 0) {
            if (*func_L01_003E4008() == 0x71) {
                return func_L39_004B95C0(*func_L01_003E4008());
            }
            return -0x262;
        }
        if (r == 0) {
            break;
        }
    }
    return arg2 - n;
}
/* localdecomp:end func_L39_004B9160 */

INCLUDE_ASM("asm/levels", func_L39_004B9218);

INCLUDE_ASM("asm/levels", func_L39_004B9350);

INCLUDE_ASM("asm/levels", func_L39_004B95C0);

INCLUDE_ASM("asm/levels", func_L39_004B9640);

INCLUDE_ASM("asm/levels", func_L39_004B9720);

INCLUDE_ASM("asm/levels", func_L39_004BA760);

/* localdecomp:start func_L39_004BB368 */
extern s32 D_L39_00464798[];
extern s32 D_L39_00464794[];

s32 func_L39_004BB368(void) {
    s32 i;
    s32 n;

    n = D_L39_00464798[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
    n = D_L39_00464794[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
}
/* localdecomp:end func_L39_004BB368 */
