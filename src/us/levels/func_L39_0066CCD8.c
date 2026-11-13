#include "common.h"

/* NTSC-U counterpart of func_L39_0066F628 (src/levels/shared/L39_0066E378.c) */
/* localdecomp:start func_L39_0066CCD8 */
typedef struct {
    char pad0[0x40];
    s32 f40[8];
    s32 f60[8];
    s32 f80;
    s32 f84;
    s32 f88[8];
    s32 fA8[8];
    s32 fC8[8];
    s32 fE8[8];
    s32 f108;
    char pad10C[0x168 - 0x10C];
    s32 f168;
} S_0066F628_A;

typedef struct {
    s32 f0[64];
    s32 f100;
    s32 f104;
    s32 f108;
} S_0066F628_B;

typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    u16 f18[8][2];
    u8 f38[8];
    u8 f40[8];
    u8 f48[8];
    u8 f50[8];
    s32 f58[8];
    char f78[0x120];
    u16 f198[8];
    s32 f1A8;
    struct { s32 a, b, c, d, e; } e[3];
    s32 f1E8, f1EC, f1F0, f1F4;
    s32 f1F8[2];
    s32 f200, f204, f208;
    S_0066F628_A *f20C;
    s32 f210;
    S_0066F628_B *f214;
} S_0066F628_G;

typedef struct { char pad[0xB8]; u8 fB8; } S_0066F628_C;

extern S_0066F628_G D_L39_00352A40;
extern s32 D_L39_0024D0A0;
extern S_0066F628_C D_001A5E50;
extern s32 D_L39_0024145C;
extern void func_0011D534(void *, s32, s32);

void func_L39_0066CCD8(s32 a0, S_0066F628_A *a1, s32 a2, S_0066F628_B *a3) {
    s32 i, j, k, l, m, n, lim, v;
    D_L39_00352A40.f0 = a0;
    D_L39_00352A40.f4 = -1;
    D_L39_00352A40.f10 = -1;
    D_L39_00352A40.f1A8 = 0;
    D_L39_00352A40.f1E8 = 0;
    D_L39_00352A40.f1EC = 0;
    D_L39_00352A40.fC = 0;
    D_L39_00352A40.f14 = 0;
    D_L39_00352A40.f1F0 = 0;
    D_L39_00352A40.f1F4 = 0;
    D_L39_0024D0A0 = 0;
    for (j = 2; j >= 0; j--) D_L39_00352A40.e[j].d = 0;
    for (k = 0; k < 8; k++) {
        if (a1->f60[k] != -1) D_L39_00352A40.f1F4++;
    }
    for (l = 1; l >= 0; l--) D_L39_00352A40.f1F8[l] = 0;
    for (i = 0; i < 8; i++) {
        D_L39_00352A40.f18[i][0] = 0;
        D_L39_00352A40.f18[i][1] = 0;
        D_L39_00352A40.f58[i] = 0;
        D_L39_00352A40.f38[i] = 0;
        D_L39_00352A40.f40[i] = 0;
        D_L39_00352A40.f48[i] = 0;
        D_L39_00352A40.f50[i] = 0;
        D_L39_00352A40.f198[i] = 0;
    }
    D_001A5E50.fB8 = 0;
    D_L39_00352A40.f200 = 0;
    D_L39_00352A40.f204 = 0;
    D_L39_00352A40.f208 = 0;
    func_0011D534(D_L39_00352A40.f78, 0, 0x120);
    D_L39_00352A40.f20C = a1;
    D_L39_00352A40.f210 = a2;
    D_L39_00352A40.f214 = a3;
    for (i = 0; i < 8; i++) {
        D_L39_00352A40.f20C->f88[i] = 6;
        D_L39_00352A40.f20C->fA8[i] = -1;
        D_L39_00352A40.f20C->fE8[i] = 100;
        if (D_L39_00352A40.f20C->f40[i] != -1) D_L39_00352A40.f20C->f168++;
    }
    D_L39_00352A40.f20C->f88[D_L39_00352A40.f20C->f80] = 0;
    D_L39_00352A40.f20C->fC8[D_L39_00352A40.f20C->f80] = 0;
    D_L39_00352A40.f20C->fE8[D_L39_00352A40.f20C->f80] = 100;
    D_L39_00352A40.f20C->f88[D_L39_00352A40.f20C->f84] = 1;
    D_L39_00352A40.f20C->fC8[D_L39_00352A40.f20C->f84] = 1;
    D_L39_00352A40.f20C->fE8[D_L39_00352A40.f20C->f84] = 100;
    D_L39_00352A40.f214->f104 = 0;
    lim = 8;
    if (D_L39_00352A40.f214->f108 <= lim) {
        n = 0;
        for (m = 0; m < 64; m++) {
            if (D_L39_00352A40.f214->f0[m] != -1) n++;
        }
        if ((u32)(D_L39_0024145C - 0x2E) <= 3) lim = 4;
        v = (s32)((f32)n * 0.33f);
        D_L39_00352A40.f214->f108 = (lim < v) ? v : lim;
    }
}
/* localdecomp:end func_L39_0066CCD8 */
