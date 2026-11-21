#include "common.h"

/* NTSC-U counterpart of func_L39_00670D90 (src/levels/shared/L39_00670968.c): the clock global is at 0x1A5E50 */
/* localdecomp:start func_L39_0066E440 */
typedef struct Q_0066E440 {
    u8 pad0[0x88];
    s32 f88;
    u8 pad8C[0x7C];
    f32 f108;
    f32 f10C;
} Q_0066E440;

typedef struct R_0066E440 {
    u8 pad0[8];
    s32 f8;
    s32 fC;
} R_0066E440;

typedef struct M_0066E440 {
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
    Q_0066E440 *f20C;
    R_0066E440 *f210;
} M_0066E440;

typedef struct T_0066E440 {
    s32 idx[8];
    f32 a[8];
    f32 b[8];
    u8 pad[0x8C - 0x60];
    s32 cnt;
    u8 pad90[0x14];
} T_0066E440;

typedef struct C_0066E440 {
    s32 cnt;
    u8 pad4[0xA0];
} C_0066E440;

typedef struct Res_0066E440 {
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
    T_0066E440 teams[8];
    s32 f808;
    s32 f80C;
    s32 f810;
    s32 f814;
    s32 f818;
    s32 f81C;
    s32 f820;
    s32 f824;
    s32 f828;
} Res_0066E440;

typedef struct G_0066E440 {
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
} G_0066E440;

typedef struct P_0066E440 {
    u8 pad0[0x1A14];
    u8 f1A14;
    u8 pad1A15[0xB1F];
    s32 f2534;
    u8 pad2538[0x10];
    s32 f2548;
    u8 pad254C[0x4];
    s32 f2550;
} P_0066E440;

typedef struct N_0066E440 {
    u8 pad0[0x128];
    s32 f128;
} N_0066E440;

typedef struct B_0066E440 {
    u8 b[0x120];
} B_0066E440;

typedef struct Z_0066E440 {
    u8 pad0[0x2524];
    s32 f2524;
} Z_0066E440;

extern M_0066E440 D_L39_00352A40;
extern Res_0066E440 D_L39_001FD968;
extern N_0066E440 D_001A5E50;
__asm__(".extern D_L39_002417C0, 16");
extern G_0066E440 *D_L39_002417C0;
extern G_0066E440 *D_001D5F30_sda;
extern P_0066E440 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern void func_L39_0066FAB0(void);
extern void *func_0011D534(void *, s32, s32);
extern void func_001206F4(void *, void *);
extern void func_L01_003F0020(s32);
extern void func_L01_00402768(void *, s32);
extern void func_L39_0066D5B8(void);
extern u8 *func_L39_006197C0(s32);

void func_L39_0066E440(s32 arg0) {
    s32 i;

    D_L39_00352A40.f8 = 2;
    D_L39_00352A40.f1F0 = 1;
    D_L39_00352A40.f1EC = arg0;
    func_L39_0066FAB0();
    func_0011D534(&D_L39_001FD968, 0, 0x82C);
    D_L39_001FD968.f80C = D_L39_002417C0->f180;
    D_L39_001FD968.f808 = D_L39_002417C0->f184;
    D_L39_001FD968.f828 = D_L39_002417C0->f19D;
    D_L39_001FD968.f818 = arg0;
    if (D_L39_00352A40.f20C->f88 == 0) {
        D_L39_001FD968.f1A0 = D_L39_00352A40.f20C->f108;
        D_L39_001FD968.f1A4 = D_L39_00352A40.f20C->f10C;
    } else {
        D_L39_001FD968.f1A4 = D_L39_00352A40.f20C->f108;
        D_L39_001FD968.f1A0 = D_L39_00352A40.f20C->f10C;
    }
    if (D_L39_00352A40.f210 != 0) {
        D_L39_001FD968.f1AC = D_001D5F30_sda->f198;
    }
    *(B_0066E440 *)D_L39_001FD968.f1C8 = *(B_0066E440 *)D_L39_00352A40.f78;
    D_L39_001FD968.f81C = D_L39_00352A40.f200;
    D_L39_001FD968.f820 = D_L39_00352A40.f204;
    D_L39_001FD968.f824 = D_L39_00352A40.f208;
    for (i = 0; i < 8; i++) {
        if (D_L39_002417C0 != 0 && D_L39_002417C0->names[i][0] != 0) {
            func_001206F4(D_L39_001FD968.names[i], D_L39_002417C0->names[i]);
        } else {
            D_L39_001FD968.names[i][0] = 0;
        }
        D_L39_001FD968.f100[i] = 0;
        if (D_L39_0024CF20[i] != 0) {
            s32 n;
            if (D_L39_0024CF20[i]->f1A14 != 0) {
                D_L39_001FD968.f100[i] = 1;
                func_L01_003F0020(D_L39_0024CF20[i]->f2534);
            }
            D_L39_001FD968.f120[i] = D_L39_0024CF20[i]->f2548;
            n = D_L39_001FD968.teams[D_L39_0024CF20[i]->f2548].cnt;
            D_L39_001FD968.teams[D_L39_0024CF20[i]->f2548].a[n] = D_L39_002417C0->f110[i];
            D_L39_001FD968.teams[D_L39_0024CF20[i]->f2548].b[n] = D_L39_002417C0->f130[i];
            D_L39_001FD968.teams[D_L39_0024CF20[i]->f2548].idx[n] = i;
            D_L39_001FD968.teams[D_L39_0024CF20[i]->f2548].cnt++;
        }
        D_L39_001FD968.f140[i][0] = D_L39_00352A40.f18[i].a;
        D_L39_001FD968.f140[i][1] = D_L39_00352A40.f18[i].b;
        D_L39_001FD968.f160[i] = D_L39_00352A40.f38[i];
        D_L39_001FD968.f168[i] = D_L39_00352A40.f40[i];
        D_L39_001FD968.f180[i] = D_L39_00352A40.f58[i];
        D_L39_001FD968.f170[i] = D_L39_00352A40.f48[i];
        D_L39_001FD968.f178[i] = D_L39_00352A40.f50[i];
        D_L39_001FD968.f1B8[i] = D_L39_00352A40.f198[i];
    }
    D_L39_001FD968.f814 = D_001A5E50.f128 - D_L39_00352A40.f4;
    if (D_L39_00352A40.f0 != -1) {
        D_L39_001FD968.f814 = (D_L39_001FD968.f814 < D_L39_00352A40.f0) ? D_L39_001FD968.f814 : D_L39_00352A40.f0;
    }
    switch (arg0) {
    case 1:
    case 5:
        if (D_L39_001FD968.f80C == 2) {
            if (D_L39_002417C0->f19D != 0) {
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
                        if (D_L39_002417C0->fE0[j] != -1 && D_L39_002417C0->fD0[j] == t) {
                            sum1 += D_L39_001FD968.f140[j][0] - D_L39_001FD968.f1B8[j];
                            sum2 += D_L39_001FD968.f140[j][1];
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
                    D_L39_001FD968.f1A8 = bestIdx;
                } else {
                    D_L39_001FD968.f1A8 = -1;
                }
            } else {
                s32 j;
                s32 bestIdx = -1;
                s32 best1 = -1;
                s32 tie = 0;
                for (j = 0; j < 8; j++) {
                    if (D_L39_002417C0->fE0[j] != -1) {
                        s32 d = D_L39_001FD968.f140[j][0] - D_L39_001FD968.f1B8[j];
                        if (best1 < d) {
                            best1 = d;
                            bestIdx = j;
                        } else if (d == best1) {
                            if (D_L39_001FD968.f140[j][1] < D_L39_001FD968.f140[bestIdx][1]) {
                                best1 = d;
                                bestIdx = j;
                                tie = 0;
                            } else if (D_L39_001FD968.f140[j][1] == D_L39_001FD968.f140[bestIdx][1]) {
                                tie = 1;
                            }
                        }
                    }
                }
                if (tie == 0) {
                    D_L39_001FD968.f1A8 = D_L39_001FD968.f120[bestIdx];
                } else {
                    D_L39_001FD968.f1A8 = -1;
                }
            }
        } else if (D_L39_001FD968.f80C == 1) {
            if (D_L39_00352A40.f210->f8 > D_L39_00352A40.f210->fC) {
                D_L39_001FD968.f1A8 = 0;
            } else if (D_L39_00352A40.f210->fC > D_L39_00352A40.f210->f8) {
                D_L39_001FD968.f1A8 = 1;
            } else {
                D_L39_001FD968.f1A8 = -1;
            }
        } else if (D_L39_001FD968.f80C == 0) {
            D_L39_001FD968.f1A8 = -1;
        }
        break;
    case 2:
    case 3:
    case 4:
        do {
            D_L39_001FD968.f1A8 = D_L39_00352A40.f10;
        } while (0);
        break;
    }
    func_L01_00402768(func_L39_0066D5B8, ((Z_0066E440 *)func_L39_006197C0(0))->f2524);
}
/* localdecomp:end func_L39_0066E440 */
