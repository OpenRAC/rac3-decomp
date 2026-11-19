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

/* localdecomp:start func_L39_00670AE0 */
typedef struct {
    u16 h0;
    u16 h2;
} H_00670AE0;

typedef struct {
    u8 pad0[0x18];
    H_00670AE0 f18[24];
    H_00670AE0 f78[8][9];
    u16 f198[16];
    u8 pad1B8[0x1F0 - 0x1B8];
    s32 f1F0;
} G_00670AE0;

typedef struct {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s8 b4;
    u8 pad5[3];
    u32 w8;
} E_00670AE0;

typedef struct {
    u8 pad0[0x1A14];
    u8 b1A14;
} Q_00670AE0;

extern G_00670AE0 D_L39_00352940_00670AE0;
extern Q_00670AE0 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern s32 func_L39_00672118(s32);
extern void func_L39_00629550(Q_00670AE0 *, E_00670AE0 *);
extern void func_L39_00670968(s32, s32, s32);
extern void func_L39_00670930(void);

void func_L39_00670AE0(E_00670AE0 *p) {
    s32 v = func_L39_00672118(p->b3);
    Q_00670AE0 *q;
    if (D_L39_00352940_00670AE0.f1F0 != 0) {
        return;
    }
    if (p->b0 >= 0) {
        D_L39_00352940_00670AE0.f18[p->b0].h0++;
        q = D_L39_0024CE20[p->b0];
        if (q != 0 && q->b1A14 != 0) {
            func_L39_00629550(q, p);
        }
        if (v >= 0) {
            D_L39_00352940_00670AE0.f78[p->b0][v].h0++;
        }
    }
    if (p->b2 >= 0) {
        D_L39_00352940_00670AE0.f18[p->b2].h2++;
        if (v >= 0) {
            D_L39_00352940_00670AE0.f78[p->b2][v].h2++;
        }
        if (p->w8 == 0xFFFFFFFF) {
            D_L39_00352940_00670AE0.f198[p->b2]++;
        }
    }
    func_L39_00670968(p->b0, p->b2, p->b4);
    func_L39_00670930();
}
/* localdecomp:end func_L39_00670AE0 */

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

/* localdecomp:start func_L39_00670D90 */
typedef struct Q_00670D90 {
    u8 pad0[0x88];
    s32 f88;
    u8 pad8C[0x7C];
    f32 f108;
    f32 f10C;
} Q_00670D90;

typedef struct R_00670D90 {
    u8 pad0[8];
    s32 f8;
    s32 fC;
} R_00670D90;

typedef struct M_00670D90 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[4];
    s32 f10;
    u8 pad14[4];
    struct { u16 a; u16 b; } f18[8];
    u8 f38[8];
    u8 f40[8];
    u8 f48[8];
    u8 f50[8];
    f32 f58[8];
    u8 f78[0x120];
    s16 f198[8];
    u8 pad1A8[0x44];
    s32 f1EC;
    s32 f1F0;
    u8 pad1F4[0xC];
    s32 f200;
    s32 f204;
    s32 f208;
    Q_00670D90 *f20C;
    R_00670D90 *f210;
} M_00670D90;

typedef struct T_00670D90 {
    s32 idx[8];
    f32 a[8];
    f32 b[8];
    u8 pad[0x8C - 0x60];
    s32 cnt;
    u8 pad90[0x14];
} T_00670D90;

typedef struct C_00670D90 {
    s32 cnt;
    u8 pad4[0xA0];
} C_00670D90;

typedef struct D_00670D90 {
    u8 names[8][0x20];
    s32 f100[8];
    s32 f120[8];
    s16 f140[8][2];
    u8 f160[8];
    u8 f168[8];
    u8 f170[8];
    u8 f178[8];
    f32 f180[8];
    f32 f1A0;
    f32 f1A4;
    s32 f1A8;
    s32 f1AC;
    u8 pad1B0[8];
    s16 f1B8[8];
    u8 f1C8[0x120];
    T_00670D90 teams[8];
    s32 f808;
    s32 f80C;
    s32 f810;
    s32 f814;
    s32 f818;
    s32 f81C;
    s32 f820;
    s32 f824;
    s32 f828;
} D_00670D90;

typedef struct G_00670D90 {
    u8 names[8][0x10];
    u8 pad80[0x50];
    s16 fD0[8];
    s16 fE0[8];
    u8 padF0[0x20];
    f32 f110[8];
    f32 f130[8];
    u8 pad150[0x30];
    s32 f180;
    s32 f184;
    u8 pad188[0x10];
    s8 f198;
    u8 pad199[4];
    s8 f19D;
} G_00670D90;

typedef struct P_00670D90 {
    u8 pad0[0x1A14];
    u8 f1A14;
    u8 pad1A15[0xB1F];
    s32 f2534;
    u8 pad2538[0x10];
    s32 f2548;
    u8 pad254C[0x4];
    s32 f2550;
} P_00670D90;

typedef struct N_00670D90 {
    u8 pad0[0x128];
    s32 f128;
} N_00670D90;

typedef struct B_00670D90 {
    u8 b[0x120];
} B_00670D90;

typedef struct Z_00670D90 {
    u8 pad0[0x2524];
    s32 f2524;
} Z_00670D90;

extern M_00670D90 D_L39_00352940_00670D90;
extern D_00670D90 D_001FD7E8;
extern N_00670D90 D_001A5CD0_00670D90;
__asm__(".extern D_L39_00241640, 16");
extern G_00670D90 *D_L39_00241640;
extern G_00670D90 *D_001D5F30_sda;
extern P_00670D90 *D_L39_0024CE20_00670D90[8] __attribute__((section(".sdata")));
extern void func_L39_00672400(void);
extern void *func_0011D534(void *, s32, s32);
extern void func_001206F4(void *, void *);
extern void func_L01_003F1F60(s32);
extern void func_L01_00404AD8(void *, s32);
extern void func_L39_0066FF08(void);

void func_L39_00670D90(s32 arg0) {
    s32 i;

    D_L39_00352940_00670D90.f8 = 2;
    D_L39_00352940_00670D90.f1F0 = 1;
    D_L39_00352940_00670D90.f1EC = arg0;
    func_L39_00672400();
    func_0011D534(&D_001FD7E8, 0, 0x82C);
    D_001FD7E8.f80C = D_L39_00241640->f180;
    D_001FD7E8.f808 = D_L39_00241640->f184;
    D_001FD7E8.f828 = D_L39_00241640->f19D;
    D_001FD7E8.f818 = arg0;
    if (D_L39_00352940_00670D90.f20C->f88 == 0) {
        D_001FD7E8.f1A0 = D_L39_00352940_00670D90.f20C->f108;
        D_001FD7E8.f1A4 = D_L39_00352940_00670D90.f20C->f10C;
    } else {
        D_001FD7E8.f1A4 = D_L39_00352940_00670D90.f20C->f108;
        D_001FD7E8.f1A0 = D_L39_00352940_00670D90.f20C->f10C;
    }
    if (D_L39_00352940_00670D90.f210 != 0) {
        D_001FD7E8.f1AC = D_001D5F30_sda->f198;
    }
    *(B_00670D90 *)D_001FD7E8.f1C8 = *(B_00670D90 *)D_L39_00352940_00670D90.f78;
    D_001FD7E8.f81C = D_L39_00352940_00670D90.f200;
    D_001FD7E8.f820 = D_L39_00352940_00670D90.f204;
    D_001FD7E8.f824 = D_L39_00352940_00670D90.f208;
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640 != 0 && D_L39_00241640->names[i][0] != 0) {
            func_001206F4(D_001FD7E8.names[i], D_L39_00241640->names[i]);
        } else {
            D_001FD7E8.names[i][0] = 0;
        }
        D_001FD7E8.f100[i] = 0;
        if (D_L39_0024CE20_00670D90[i] != 0) {
            s32 n;
            if (D_L39_0024CE20_00670D90[i]->f1A14 != 0) {
                D_001FD7E8.f100[i] = 1;
                func_L01_003F1F60(D_L39_0024CE20_00670D90[i]->f2534);
            }
            D_001FD7E8.f120[i] = D_L39_0024CE20_00670D90[i]->f2548;
            n = D_001FD7E8.teams[D_L39_0024CE20_00670D90[i]->f2548].cnt;
            D_001FD7E8.teams[D_L39_0024CE20_00670D90[i]->f2548].a[n] = D_L39_00241640->f110[i];
            D_001FD7E8.teams[D_L39_0024CE20_00670D90[i]->f2548].b[n] = D_L39_00241640->f130[i];
            D_001FD7E8.teams[D_L39_0024CE20_00670D90[i]->f2548].idx[n] = i;
            D_001FD7E8.teams[D_L39_0024CE20_00670D90[i]->f2548].cnt++;
        }
        D_001FD7E8.f140[i][0] = D_L39_00352940_00670D90.f18[i].a;
        D_001FD7E8.f140[i][1] = D_L39_00352940_00670D90.f18[i].b;
        D_001FD7E8.f160[i] = D_L39_00352940_00670D90.f38[i];
        D_001FD7E8.f168[i] = D_L39_00352940_00670D90.f40[i];
        D_001FD7E8.f180[i] = D_L39_00352940_00670D90.f58[i];
        D_001FD7E8.f170[i] = D_L39_00352940_00670D90.f48[i];
        D_001FD7E8.f178[i] = D_L39_00352940_00670D90.f50[i];
        D_001FD7E8.f1B8[i] = D_L39_00352940_00670D90.f198[i];
    }
    D_001FD7E8.f814 = D_001A5CD0_00670D90.f128 - D_L39_00352940_00670D90.f4;
    if (D_L39_00352940_00670D90.f0 != -1) {
        D_001FD7E8.f814 = (D_001FD7E8.f814 < D_L39_00352940_00670D90.f0) ? D_001FD7E8.f814 : D_L39_00352940_00670D90.f0;
    }
    switch (arg0) {
    case 1:
    case 5:
        if (D_001FD7E8.f80C == 2) {
            if (D_L39_00241640->f19D != 0) {
                s32 t;
                s32 bestIdx = -1;
                s32 best1 = -1;
                s32 best2 = -1;
                s32 tie = 0;
                for (t = 0; t < 8; t++) {
                    s32 j;
                    s32 sum1 = 0;
                    s32 sum2 = 0;
                    for (j = 0; j < 8; j++) {
                        if (D_L39_00241640->fE0[j] != -1 && D_L39_00241640->fD0[j] == t) {
                            sum1 += D_001FD7E8.f140[j][0] - D_001FD7E8.f1B8[j];
                            sum2 += D_001FD7E8.f140[j][1];
                        }
                    }
                    if (best1 < sum1 || (sum1 == best1 && sum2 < best2)) {
                        best1 = sum1;
                        best2 = sum2;
                        bestIdx = t;
                        tie = 0;
                    } else if (sum1 == best1 && sum2 == best2) {
                        tie = 1;
                    }
                }
                if (tie == 0) {
                    D_001FD7E8.f1A8 = bestIdx;
                } else {
                    D_001FD7E8.f1A8 = -1;
                }
            } else {
                s32 j;
                s32 bestIdx = -1;
                s32 best1 = -1;
                s32 tie = 0;
                for (j = 0; j < 8; j++) {
                    if (D_L39_00241640->fE0[j] != -1) {
                        s32 d = D_001FD7E8.f140[j][0] - D_001FD7E8.f1B8[j];
                        if (best1 < d) {
                            best1 = d;
                            bestIdx = j;
                        } else if (d == best1) {
                            if (D_001FD7E8.f140[j][1] < D_001FD7E8.f140[bestIdx][1]) {
                                best1 = d;
                                bestIdx = j;
                                tie = 0;
                            } else if (D_001FD7E8.f140[j][1] == D_001FD7E8.f140[bestIdx][1]) {
                                tie = 1;
                            }
                        }
                    }
                }
                if (tie == 0) {
                    D_001FD7E8.f1A8 = D_001FD7E8.f120[bestIdx];
                } else {
                    D_001FD7E8.f1A8 = -1;
                }
            }
        } else if (D_001FD7E8.f80C == 1) {
            if (D_L39_00352940_00670D90.f210->f8 > D_L39_00352940_00670D90.f210->fC) {
                D_001FD7E8.f1A8 = 0;
            } else if (D_L39_00352940_00670D90.f210->fC > D_L39_00352940_00670D90.f210->f8) {
                D_001FD7E8.f1A8 = 1;
            } else {
                D_001FD7E8.f1A8 = -1;
            }
        } else if (D_001FD7E8.f80C == 0) {
            D_001FD7E8.f1A8 = -1;
        }
        break;
    case 2:
    case 3:
    case 4:
        do {
            D_001FD7E8.f1A8 = D_L39_00352940_00670D90.f10;
        } while (0);
        break;
    }
    func_L01_00404AD8(func_L39_0066FF08, ((Z_00670D90 *)func_L39_0061BF38(0))->f2524);
}
/* localdecomp:end func_L39_00670D90 */

INCLUDE_ASM("asm/levels", func_L39_00671448);
