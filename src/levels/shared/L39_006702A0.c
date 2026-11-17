#include "common.h"

/* localdecomp:start func_L39_006702A0 */
typedef struct { u8 pad[0x1A8]; s32 f1A8; } S_006702A0;

extern s32 D_L39_0024BD18;
extern s32 D_L39_0024CFA0;
extern S_006702A0 D_L39_00352940;
extern char D_L39_00352B58[][0x30];
extern s32 func_00120884(char *);
extern void func_0038E7E8(f32, f32, unsigned long, char *, s32, f32, f32, s32, s32, unsigned long, f32, f32);

s32 func_L39_006702A0(void) {
    s32 i;
    if (D_L39_0024BD18 != 0) {
        return 0;
    }
    for (i = 0; i < D_L39_0024CFA0; i++) {
        f32 y = 0x186 - (D_L39_00352940.f1A8 + i) * 15;
        func_0038E7E8(15.0f, y, 0xB080FFFF, D_L39_00352B58[i], func_00120884(D_L39_00352B58[i]), 1.0f, 1.0f, 0, 0, 0x80000000, 0.0f, 0.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_006702A0 */

/* localdecomp:start func_L39_006703B0 */
extern char D_L39_00352B58[][0x30];
extern s32 D_L39_0024CFA0;
extern s32 D_L39_0024CF80[] __attribute__((section(".sdata")));
extern s32 func_00381FF0(s32);
extern s32 func_00120048(char *, char *, ...);

void func_L39_006703B0(s32 arg0) {
    func_00120048(D_L39_00352B58[D_L39_0024CFA0], (char *)func_00381FF0(0x1877), arg0);
    D_L39_0024CF80[D_L39_0024CFA0] = 0x708;
    D_L39_0024CFA0++;
}
/* localdecomp:end func_L39_006703B0 */

/* localdecomp:start func_L39_00670438 */
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

extern S_00670438 D_L39_00352940_00670438;
extern u8 D_L39_00352B58_00670438[][0x30];
extern s32 D_L39_0024CF80[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CFA0;
extern s32 *D_L39_00241120;
extern Q_00670438 *D_L39_00241640_00670438;
extern P_00670438 D_001A5CD0;
extern s32 D_001A5E40[];
extern f32 D_001A6A4C[];
__asm__(".extern D_L39_002463C0, 1");
extern s32 D_L39_00241440;
extern s32 D_L39_00242914;
extern u8 D_L39_002463C0;
extern Z_00670438 *D_L39_0024CE20[] __attribute__((section(".sdata")));

extern X_00670438 *func_L39_0061BF38(s32);
extern void func_L01_003F1F60(s32);
extern void func_L01_00404AD8(void (*)(void), s32);
extern void func_L39_0066FF08(void);
extern s32 func_L39_006702A0(void);
extern void func_L39_0066FC08(void);
extern void func_L39_0059A578(s32, s32);
extern void func_001206F4(u8 *, u8 *);
extern void func_L39_0066F948(s32);
extern void func_L39_00670C50(s32);
extern void func_L39_00672248(void);

void func_L39_00670438(void) {
    s32 i;
    if (D_L39_00352940_00670438.f1B8[2].f10 != 0) {
        for (i = 0; i < *D_L39_00241120; i++) {
            func_L01_003F1F60(func_L39_0061BF38(i)->f2534);
        }
        do { D_L39_00352940_00670438.f1B8[2].f10++; } while (0);
        func_L01_00404AD8(func_L39_0066FF08, func_L39_0061BF38(0)->f2524);
        if (D_L39_00352940_00670438.f1B8[2].f10 >= 250) {
            do {
                if (D_001A5E40[0] != 0) { D_L39_00241440 = 3; } else { D_L39_00241440 = 4; }
                D_L39_00242914 = 0;
            } while (0);
            func_L39_0059A578(0x27, 1);
        }
        return;
    }
    if (D_L39_0024CFA0 != 0) {
        for (i = 0; i < D_L39_0024CFA0; i++) {
            if (--D_L39_0024CF80[i] == 0) {
                s32 n = D_L39_0024CFA0 - 1;
                D_L39_0024CFA0 = n;
                if (i < n) {
                    D_L39_0024CF80[i] = D_L39_0024CF80[n];
                    func_001206F4(D_L39_00352B58_00670438[i], D_L39_00352B58_00670438[n]);
                }
            }
        }
        func_L01_00404AD8((void (*)(void))func_L39_006702A0, 0);
    }
    D_L39_00352940_00670438.fC = D_001A5CD0.f12C;
    if (D_L39_00352940_00670438.f4 == -1) {
        D_L39_00352940_00670438.f4 = D_001A5CD0.f128;
        D_L39_00352940_00670438.f8 = 1;
        if (D_001A5CD0.b168 != 0) {
            func_L39_0066F948(-1);
        }
    }
    if (D_L39_002463C0 != 0 || (D_L39_00352940_00670438.f0 != -1 && D_001A5CD0.f128 - D_L39_00352940_00670438.f4 >= D_L39_00352940_00670438.f0)) {
        func_L39_00670C50(1);
    }
    {
        s32 d = D_001A5CD0.f128 - D_L39_00352940_00670438.f4;
        if (D_001A5CD0.bBC == 0 && d > 0 && D_001A6A4C[0] * 1000.0f < (f32)d) {
            func_L39_00672248();
        }
    }
    if (D_001A5CD0.b168 != 0 && D_L39_00352940_00670438.f1B8[2].f10 == 0) {
        switch (D_L39_00241640_00670438->f180) {
        case 0:
            if (D_L39_00352940_00670438.f10 != -1) {
                func_L39_00670C50(3);
            }
            break;
        case 1: {
            s32 n = D_L39_00241640_00670438->b198;
            if (n > 0) {
                s32 *r = D_L39_00352940_00670438.f210;
                if (r[2] >= n) {
                    D_L39_00352940_00670438.f10 = 0;
                } else {
                    if (r[3] < n) {
                        break;
                    }
                    D_L39_00352940_00670438.f10 = 1;
                }
                func_L39_00670C50(4);
            }
            break;
        }
        case 2:
            if (D_L39_00241640_00670438 != 0 && D_L39_00241640_00670438->b197 > 0) {
                s32 i;
                for (i = 0; i < 8; i++) {
                    if (D_L39_00241640_00670438->b19D != 0) {
                        s32 sum = 0;
                        s32 j;
                        for (j = 0; j < 8; j++) {
                            if (D_L39_00241640_00670438->hE0[j] != -1 && D_L39_00241640_00670438->hD0[j] == i) {
                                sum += D_L39_00352940_00670438.f18[j].a - D_L39_00352940_00670438.f198[j];
                            }
                        }
                        if (sum >= D_L39_00241640_00670438->b197) {
                            D_L39_00352940_00670438.f10 = i;
                            func_L39_00670C50(2);
                            break;
                        }
                    } else if (D_L39_00241640_00670438->hE0[i] != -1 && D_L39_00352940_00670438.f18[i].a - D_L39_00352940_00670438.f198[i] >= D_L39_00241640_00670438->b197) {
                        D_L39_00352940_00670438.f10 = D_L39_0024CE20[i]->f2558->f4->f40;
                        func_L39_00670C50(2);
                        break;
                    }
                }
            }
            break;
        }
    }
    if (D_L39_00352940_00670438.f1A8 != 0 && D_L39_00241640_00670438 != 0) {
        s32 k;
        func_L01_00404AD8(func_L39_0066FC08, 0);
        for (k = 0; k < 3; k++) {
            if (D_L39_00352940_00670438.f1B8[k].b != 0) {
                D_L39_00352940_00670438.f1B8[k].b--;
            } else if (D_L39_00352940_00670438.f1B8[k].a != 0) {
                if (--D_L39_00352940_00670438.f1B8[k].a == 0) {
                    D_L39_00352940_00670438.f1A8--;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_00670438 */
