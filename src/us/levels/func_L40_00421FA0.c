#include "common.h"

/* NTSC-U counterpart of func_L40_00422870 (src/levels/shared/L40_00420998.c) */
extern s32 func_L40_00421C70(u8 *a0);

/* localdecomp:start func_L40_00421FA0 */
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L39_0066B3C0(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L40_00421C70(u8 *a0);
extern s32 func_L40_005432E0(void);
extern s32 func_L39_0066F8B8(s32);
extern s32 func_0019D650(void);
extern s32 func_L39_0066F7C8(u32);
extern s32 func_L39_0066F840(s32);
extern void func_L39_006601C8(s32 a0, void *a1, s32 a2);
extern u8 *D_L40_002494B0[8] __attribute__((section(".sdata")));
extern u8 *D_L40_002417C0;

void func_L40_00421FA0(u8 *self, u8 *other) {
    s32 r = 0;
    s32 i;
    s32 j;
    u8 *p;
    s32 h;
    u8 bits;
    s32 k;
    s32 n;
    s32 me;
    u8 buf[1];

    if (other == 0 || !(func_L01_0040C018(other + 0xA0, self + 0x10) < 4.0f)) {
        r = 250;
    } else {
        for (i = 0; i < 8; i++) {
            p = D_L40_002494B0[i];
            if (p != 0 && p != other && func_L01_0040C018(other + 0xA0, p + 0xA0) < 20.0f) {
                r = 250;
                break;
            }
        }
    }
    h = func_L39_0066B3C0((s32)self, 0, 0, r);
    if (func_L40_00421C70(self) != 0) {
        bits = D_L40_002417C0[0x199];
        k = 0;
        n = func_L40_005432E0();
        if (func_L39_0066F8B8(1) != 0) {
            n--;
        }
        if (n >= 2) {
            k = func_0019D650() % n;
        }
        me = func_L39_0066F7C8(1);
        for (j = 0; j < 8; j++) {
            if (j != me && ((bits >> j) & 1)) {
                if (k == 0) {
                    break;
                }
                k--;
            }
        }
        buf[0] = func_L39_0066F840(j);
        func_L39_006601C8(h, buf, 1);
    }
}
/* localdecomp:end func_L40_00421FA0 */
