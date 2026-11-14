#include "common.h"

/* NTSC-U counterpart of func_L40_00434270 (src/levels/shared/L40_00434048.c) */
/* localdecomp:start func_L40_00433708 */
extern void func_L39_0066B3C0(int, int, int, int);
extern void func_L39_006601C8(u8 *a0, void *a1, s32 a2);
extern void *func_0011D534(void *, s32, s32);
extern s32 D_001A5E50[];
extern void func_L39_0065FE10(u8 *a0);
extern s32 func_L40_004334E0(s32 *a0, u8 *a1);

typedef struct {
    s32 f0;
    s32 f4;
    s16 f8;
    u8 fA;
} S_00434270;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x8];
    u8 f20[0xC];
    u8 pad2C[0x4];
    u8 f30[0x20];
    u8 f50[0x8];
    S_00434270 f58[8];
} P_00434270;

void func_L40_00433708(u8 *a0) {
    u8 sel[16];
    u8 b[16];
    s32 w[2];
    P_00434270 *p;
    u8 *h;
    s32 r;
    s32 i;

    p = *(P_00434270 **)(a0 + 0x68);
    h = ((u8 * (*)(u8 *, s32, s32, s32))func_L39_0066B3C0)(a0, 0, 0, 0);
    func_0011D534(p->f30, 0, 0x20);
    func_0011D534(p->f20, 0, 0xC);
    func_0011D534(p->f50, 0, 8);
    p->f14 = 0;
    r = func_L40_004334E0(&w[0], sel);
    if (r != 0) {
        w[1] = w[0];
        func_L39_006601C8(h, &w[1], 4);
        b[0] = sel[0];
        func_L39_006601C8(h, b, 1);
        i = D_001A5E50[2];
        func_0011D534(&p->f58[i], 0, 0xC);
        p->f58[i].f8 = r;
        p->f58[i].f4 = 1;
        p->f58[i].f0 = 0;
        p->f58[i].fA = sel[0];
        p->f10 = 1;
        p->f14 = D_001A5E50[0x128 / 4];
    } else {
        func_L39_0065FE10(h);
    }
}
/* localdecomp:end func_L40_00433708 */
