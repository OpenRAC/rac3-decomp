#include "common.h"

/* localdecomp:start func_L39_00670968 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} E_00670968;

typedef struct {
    u8 pad0[0x1A8];
    s32 f1A8;
    E_00670968 e[3];
} G_00670968;

typedef struct {
    u8 pad0[0x2544];
    s32 f2544;
} R_00670968;

extern G_00670968 D_L39_00352940;
extern s32 *D_L39_00241120;
extern R_00670968 *func_L39_0061BF38(s32);

void func_L39_00670968(s32 arg0, s32 arg1, s32 arg2) {
    s32 best = 0;
    s32 min;
    s32 i;
    s32 id;
    R_00670968 *r;

    D_L39_00352940.f1A8++;
    min = D_L39_00352940.e[0].fC;
    if (*D_L39_00241120 < 3) {
        if (D_L39_00352940.f1A8 >= 4) {
            D_L39_00352940.f1A8 = 3;
        }
    } else {
        if (D_L39_00352940.f1A8 >= 3) {
            D_L39_00352940.f1A8 = 2;
        }
    }
    if (min > 0) {
        for (i = 0; i < (*D_L39_00241120 < 3 ? 3 : 2); i++) {
            if (D_L39_00352940.e[i].fC < min) {
                min = D_L39_00352940.e[i].fC;
                best = i;
            }
        }
    }
    id = -1;
    r = func_L39_0061BF38(0);
    if (r != 0) {
        id = r->f2544;
    }
    if (arg0 == id) {
        D_L39_00352940.e[best].f10 = 0x2D;
        D_L39_00352940.e[best].fC = 0xB4;
    } else {
        D_L39_00352940.e[best].f10 = 0xF;
        D_L39_00352940.e[best].fC = 0x78;
    }
    D_L39_00352940.e[best].f0 = arg0;
    D_L39_00352940.e[best].f4 = arg1;
    D_L39_00352940.e[best].f8 = arg2;
}
/* localdecomp:end func_L39_00670968 */

INCLUDE_ASM("asm/levels", func_L39_00670AE0);

/* localdecomp:start func_L39_00670C50 */
typedef struct { u8 b[8]; } T8_00670C50;
typedef struct { u8 b[16]; } T16_00670C50;
typedef struct { u8 b[32]; } T32_00670C50;

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[4];
    u8 bC;
    u8 pad_D[3];
    s32 f10;
    u8 pad14[4];
    T32_00670C50 f18;
    T8_00670C50 f38;
    u8 pad40[8];
    T8_00670C50 f48;
    T8_00670C50 f50;
    u8 pad58[0x198 - 0x58];
    T16_00670C50 f198;
    u8 pad1A8[0x210 - 0x1A8];
    struct { u8 pad0[8]; u16 h8; u16 hA; u16 hC; } *f210;
} G_00670C50;

typedef struct {
    u8 b0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
    u8 bC;
    u8 bD;
    u16 hE;
    u16 h10;
    u8 pad12[10];
    s32 f1C;
    T32_00670C50 f20;
    T16_00670C50 f40;
    T8_00670C50 f50;
    T8_00670C50 f58;
    T8_00670C50 f60;
} P_00670C50;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x160];
    u8 b168;
    u8 pad169[7];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_00670C50;

extern S_00670C50 D_001A5CD0;
extern G_00670C50 D_L39_00352940_00670C50;
extern s32 D_L39_002405BC;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L39_00670D90(s32);

void func_L39_00670C50(s32 arg0) {
    P_00670C50 s;
    if (D_001A5CD0.b168 != 0) {
        s.bC = 0x82;
        s.bD = D_L39_00352940_00670C50.bC;
        s.f4 = D_L39_00352940_00670C50.f0;
        s.f8 = D_L39_00352940_00670C50.f4;
        s.b0 = arg0;
        s.f1C = D_L39_00352940_00670C50.f10;
        s.h10 = D_L39_00352940_00670C50.f210->hC;
        s.hE = D_L39_00352940_00670C50.f210->h8;
        s.f20 = D_L39_00352940_00670C50.f18;
        s.f40 = D_L39_00352940_00670C50.f198;
        s.f50 = D_L39_00352940_00670C50.f38;
        s.f58 = D_L39_00352940_00670C50.f48;
        s.f60 = D_L39_00352940_00670C50.f50;
        if (D_001A5CD0.w170 == 0) {
            func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.w4, -1, D_L39_002405BC, 0x68, &s);
        }
        func_L39_00670D90(arg0);
    }
}
/* localdecomp:end func_L39_00670C50 */

INCLUDE_ASM("asm/levels", func_L39_00670D90);

INCLUDE_ASM("asm/levels", func_L39_00671448);
