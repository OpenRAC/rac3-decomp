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

/* localdecomp:start func_L40_0048FF90 */
typedef int Q_0048FF90 __attribute__((mode(TI)));

typedef struct S_0048FF90 {
    Q_0048FF90 pos;
    float f10;
    float f14;
    float f18;
    int i1C;
    short h20[8];
    unsigned char pad30[0x20];
    unsigned char b50[8];
    unsigned char pad58[8];
} S_0048FF90 __attribute__((aligned(16)));

extern int D_L40_00248628;
extern char D_L40_002433B8[];
extern S_0048FF90 D_L40_002926E0[];
extern void func_L01_004A0A78_0048FF90(char *);

int func_L40_0048FF90(Q_0048FF90 *pos, int tag, float below, float above) {
    S_0048FF90 *e;
    int i;

    if (D_L40_00248628 >= 0x100) {
        func_L01_004A0A78_0048FF90(D_L40_002433B8);
    }
    e = &D_L40_002926E0[D_L40_00248628];
    e->pos = *pos;
    e->i1C = tag;
    e->f10 = -1.0f;
    e->f14 = *(float *)((char *)e + 8) - below;
    e->f18 = *(float *)((char *)e + 8) + above;
    for (i = 0; i < 8; i++) {
        e->h20[i] = -1;
        e->b50[i] = 0;
    }
    return D_L40_00248628++;
}
/* localdecomp:end func_L40_0048FF90 */
