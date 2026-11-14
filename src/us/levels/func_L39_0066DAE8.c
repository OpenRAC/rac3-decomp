#include "common.h"

/* NTSC-U counterpart of func_L39_00670438 (src/levels/shared/L39_006702A0.c): 250 -> 300 */
extern s32 D_L39_0024D0A0;
extern s32 D_L39_0024D0A0;
extern s32 D_L39_0024D080[] __attribute__((section(".sdata")));

/* localdecomp:start func_L39_0066DAE8 */
typedef struct { s16 a; s16 b; } H_00670438;
typedef struct { s32 a; s32 b; s32 pad[2]; s32 f10; } E_00670438;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[4];
    H_00670438 f18[8];
    u8 pad38[0x198 - 0x38];
    s16 f198[8];
    s32 f1A8;
    u8 pad1AC[0x1B8 - 0x1AC];
    E_00670438 f1B8[3];
    u8 pad1F4[0x210 - 0x1F4];
    s32 *f210;
} S_00670438;
typedef struct {
    u8 pad0[0xD0];
    s16 hD0[8];
    s16 hE0[8];
    u8 padF0[0x180 - 0xF0];
    s32 f180;
    u8 pad184[0x197 - 0x184];
    s8 b197;
    s8 b198;
    u8 pad199[4];
    s8 b19D;
} Q_00670438;
typedef struct {
    u8 pad0[0xBC];
    u8 bBC;
    u8 padBD[0x128 - 0xBD];
    s32 f128;
    s32 f12C;
    u8 pad130[0x168 - 0x130];
    u8 b168;
} P_00670438;
typedef struct { u8 pad0[0x40]; s32 f40; } V_00670438;
typedef struct { s32 f0; V_00670438 *f4; } W_00670438;
typedef struct { u8 pad[0x2558]; W_00670438 *f2558; } Z_00670438;
typedef struct { u8 pad[0x2524]; s32 f2524; u8 pad2528[0x2534 - 0x2528]; s32 f2534; } X_00670438;

extern S_00670438 D_L39_00352A40_0066DAE8;
extern u8 D_L39_00352C58_0066DAE8[][0x30];
extern s32 D_L39_0024D080[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D0A0;
extern s32 *D_L39_002412A0;
extern Q_00670438 *D_L39_002417C0_0066DAE8;
extern P_00670438 D_001A5E50;
extern s32 D_001A5FC0[];
extern f32 D_001A6BCC[];
__asm__(".extern D_L39_00246540, 1");
extern s32 D_L39_002415C0;
extern s32 D_L39_00242A94;
extern u8 D_L39_00246540;
extern Z_00670438 *D_L39_0024CF20[] __attribute__((section(".sdata")));

extern X_00670438 *func_L39_006197C0(s32);
extern void func_L01_003F0020(s32);
extern void func_L01_00402768(void (*)(void), s32);
extern void func_L39_0066D5B8(void);
extern s32 func_L39_0066D950(void);
extern void func_L39_0066D2B8(void);
extern void func_L39_005992A8(s32, s32);
extern void func_001206F4(u8 *, u8 *);
extern void func_L39_0066CFF8(s32);
extern void func_L39_0066E300(s32);
extern void func_L39_0066F8F8(void);

void func_L39_0066DAE8(void) {
    s32 i;
    if (D_L39_00352A40_0066DAE8.f1B8[2].f10 != 0) {
        for (i = 0; i < *D_L39_002412A0; i++) {
            func_L01_003F0020(func_L39_006197C0(i)->f2534);
        }
        do { D_L39_00352A40_0066DAE8.f1B8[2].f10++; } while (0);
        func_L01_00402768(func_L39_0066D5B8, func_L39_006197C0(0)->f2524);
        if (D_L39_00352A40_0066DAE8.f1B8[2].f10 >= 300) {
            do {
                if (D_001A5FC0[0] != 0) { D_L39_002415C0 = 3; } else { D_L39_002415C0 = 4; }
                D_L39_00242A94 = 0;
            } while (0);
            func_L39_005992A8(0x27, 1);
        }
        return;
    }
    if (D_L39_0024D0A0 != 0) {
        for (i = 0; i < D_L39_0024D0A0; i++) {
            if (--D_L39_0024D080[i] == 0) {
                s32 n = D_L39_0024D0A0 - 1;
                D_L39_0024D0A0 = n;
                if (i < n) {
                    D_L39_0024D080[i] = D_L39_0024D080[n];
                    func_001206F4(D_L39_00352C58_0066DAE8[i], D_L39_00352C58_0066DAE8[n]);
                }
            }
        }
        func_L01_00402768((void (*)(void))func_L39_0066D950, 0);
    }
    D_L39_00352A40_0066DAE8.fC = D_001A5E50.f12C;
    if (D_L39_00352A40_0066DAE8.f4 == -1) {
        D_L39_00352A40_0066DAE8.f4 = D_001A5E50.f128;
        D_L39_00352A40_0066DAE8.f8 = 1;
        if (D_001A5E50.b168 != 0) {
            func_L39_0066CFF8(-1);
        }
    }
    if (D_L39_00246540 != 0 || (D_L39_00352A40_0066DAE8.f0 != -1 && D_001A5E50.f128 - D_L39_00352A40_0066DAE8.f4 >= D_L39_00352A40_0066DAE8.f0)) {
        func_L39_0066E300(1);
    }
    {
        s32 d = D_001A5E50.f128 - D_L39_00352A40_0066DAE8.f4;
        if (D_001A5E50.bBC == 0 && d > 0 && D_001A6BCC[0] * 1000.0f < (f32)d) {
            func_L39_0066F8F8();
        }
    }
    if (D_001A5E50.b168 != 0 && D_L39_00352A40_0066DAE8.f1B8[2].f10 == 0) {
        switch (D_L39_002417C0_0066DAE8->f180) {
        case 0:
            if (D_L39_00352A40_0066DAE8.f10 != -1) {
                func_L39_0066E300(3);
            }
            break;
        case 1: {
            s32 n = D_L39_002417C0_0066DAE8->b198;
            if (n > 0) {
                s32 *r = D_L39_00352A40_0066DAE8.f210;
                if (r[2] >= n) {
                    D_L39_00352A40_0066DAE8.f10 = 0;
                } else {
                    if (r[3] < n) {
                        break;
                    }
                    D_L39_00352A40_0066DAE8.f10 = 1;
                }
                func_L39_0066E300(4);
            }
            break;
        }
        case 2:
            if (D_L39_002417C0_0066DAE8 != 0 && D_L39_002417C0_0066DAE8->b197 > 0) {
                s32 i;
                for (i = 0; i < 8; i++) {
                    if (D_L39_002417C0_0066DAE8->b19D != 0) {
                        s32 sum = 0;
                        s32 j;
                        for (j = 0; j < 8; j++) {
                            if (D_L39_002417C0_0066DAE8->hE0[j] != -1 && D_L39_002417C0_0066DAE8->hD0[j] == i) {
                                sum += D_L39_00352A40_0066DAE8.f18[j].a - D_L39_00352A40_0066DAE8.f198[j];
                            }
                        }
                        if (sum >= D_L39_002417C0_0066DAE8->b197) {
                            D_L39_00352A40_0066DAE8.f10 = i;
                            func_L39_0066E300(2);
                            break;
                        }
                    } else if (D_L39_002417C0_0066DAE8->hE0[i] != -1 && D_L39_00352A40_0066DAE8.f18[i].a - D_L39_00352A40_0066DAE8.f198[i] >= D_L39_002417C0_0066DAE8->b197) {
                        D_L39_00352A40_0066DAE8.f10 = D_L39_0024CF20[i]->f2558->f4->f40;
                        func_L39_0066E300(2);
                        break;
                    }
                }
            }
            break;
        }
    }
    if (D_L39_00352A40_0066DAE8.f1A8 != 0 && D_L39_002417C0_0066DAE8 != 0) {
        s32 k;
        func_L01_00402768(func_L39_0066D2B8, 0);
        for (k = 0; k < 3; k++) {
            if (D_L39_00352A40_0066DAE8.f1B8[k].b != 0) {
                D_L39_00352A40_0066DAE8.f1B8[k].b--;
            } else if (D_L39_00352A40_0066DAE8.f1B8[k].a != 0) {
                if (--D_L39_00352A40_0066DAE8.f1B8[k].a == 0) {
                    D_L39_00352A40_0066DAE8.f1A8--;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0066DAE8 */
