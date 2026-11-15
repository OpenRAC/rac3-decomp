#include "common.h"

/* declared by functions of L34_003515A0.c, which this file was cut from */
void func_L01_004450F0(s32, s32, s32);
extern u8 D_001A30B0[];
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_0038CAD0(void *);
extern void func_003A4F28(s32);

/* localdecomp:start func_L34_00352718 */
typedef struct S_00352718 {
    s32 period;
    f32 f4;
    f32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 sound;
    u8 pad1C[4];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
} S_00352718;

extern s32 D_001DF340;
extern s32 func_0038CAD0(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L34_00352430(void *, f32, f32);

void func_L34_00352718(u8 *moby) {
    S_00352718 *pv = *(S_00352718 **)(moby + 0x68);
    f32 t = (f32)(D_001DF340 % pv->period) / (f32)pv->period;
    u8 *e;
    s32 n;
    f32 a;
    f32 b;

    switch (moby[0x20]) {
    case 0:
        pv->f2C = 0;
        pv->f20 = 0;
        pv->f24 = 0;
        pv->f28 = 0;
        pv->sound = -1;
        func_L01_004450F0((s32)moby, 1, -1);
        break;
    case 1:
        if (func_0038CAD0(&pv->f10) == 0 || func_0038CAD0(&pv->f14) == 0) {
            func_L34_00352430(moby, (f32)pv->f10 * 0.125f, (f32)pv->f14 / 18.0f);
            if (pv->sound != -1) {
                e = D_001A30B0 + (pv->sound << 7);
                if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                    goto check1;
                }
            }
            pv->sound = func_003A52A0(0, 4, moby);
        } else {
            if (pv->sound != -1) {
                e = D_001A30B0 + (pv->sound << 7);
                if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                    func_003A4F28(pv->sound);
                }
            }
            pv->sound = -1;
        }
    check1:
        if (t < pv->f8 && pv->f4 < t) {
            pv->fC = 0;
            pv->f10 = 0;
            func_L01_004450F0((s32)moby, 2, -1);
        }
        break;
    case 2:
        n = ++pv->fC;
        a = 1.0f;
        b = a;
        if (n < 17) {
            a = (f32)n / 17.0f;
        }
        if (n < 46) {
            b = (f32)n / 46.0f;
        }
        func_L34_00352430(moby, a, b);
        if (pv->sound != -1) {
            e = D_001A30B0 + (pv->sound << 7);
            if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                goto check2;
            }
        }
        pv->sound = func_003A52A0(0, 4, moby);
    check2:
        if (pv->f8 < t || t < pv->f4) {
            pv->f10 = 8;
            pv->f14 = 18;
            func_L01_004450F0((s32)moby, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L34_00352718 */
