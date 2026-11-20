#include "common.h"

/* localdecomp:start func_L40_0048FDE8 */
typedef int u128_0048FDE8 __attribute__((mode(TI)));
typedef union {
    u128_0048FDE8 q;
    f32 f[4];
} V_0048FDE8;

typedef struct {
    u128_0048FDE8 pos;
    V_0048FDE8 *pts;
    s32 n;
    f32 x18;
    f32 x1C;
} E_0048FDE8;

typedef struct {
    u128_0048FDE8 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    s32 x1C;
} F_0048FDE8;

typedef struct {
    u128_0048FDE8 a;
    u128_0048FDE8 b;
    u8 pad20[0x10];
    s32 x30;
    u8 pad34[0xC];
} G_0048FDE8;

extern s32 D_L40_00248620;
extern s32 D_L40_00248624;
extern s32 D_L40_00248628_0048FDE8;
__asm__(".extern D_L40_00248628_0048FDE8, 4");
extern s32 D_L40_00248620_0048FDE8;
__asm__(".extern D_L40_00248620_0048FDE8, 4");
extern u8 D_L40_00243390[];
extern E_0048FDE8 D_L40_00290EE0[];
extern F_0048FDE8 D_L40_002916E0[];
extern G_0048FDE8 D_L40_002986E0[];
extern void func_L01_004A0A78_0048FDE8(u8 *);
extern void func_L40_004904B8(u8 *a0, s32 a1, u8 *a2, f32 *a3, f32 *a4);

void func_L40_0048FDE8(V_0048FDE8 **paths, s32 *counts, s32 n) {
    s32 i;
    s32 j;
    s32 k;
    f32 *zmax;
    f32 *zmin;

    D_L40_00248620 = 0;
    D_L40_00248624 = 0;
    D_L40_00248628_0048FDE8 = 0;
    if (n >= 64) {
        func_L01_004A0A78_0048FDE8(D_L40_00243390);
    }
    for (i = 0; i < n; i++) {
        D_L40_00290EE0[i].pts = paths[i];
        D_L40_00290EE0[i].n = counts[i];
        for (j = 0; j < D_L40_00290EE0[i].n; j++) {
            D_L40_00290EE0[i].pts[j].f[3] = 5.0f;
        }
        zmax = &D_L40_00290EE0[i].x18;
        zmin = &D_L40_00290EE0[i].x1C;
        func_L40_004904B8((u8 *)paths[i], counts[i], (u8 *)&D_L40_00290EE0[i], zmax, zmin);
        D_L40_00248620_0048FDE8 = D_L40_00248620 + 1;
    }
    for (k = 127; k >= 0; k--) {
        D_L40_002916E0[k].x1C = k;
    }
    for (k = 63; k >= 0; k--) {
        D_L40_002986E0[k].x30 = k;
    }
}
/* localdecomp:end func_L40_0048FDE8 */

INCLUDE_ASM("asm/levels", func_L40_0048FF90);

INCLUDE_ASM("asm/levels", func_L40_00490080);
