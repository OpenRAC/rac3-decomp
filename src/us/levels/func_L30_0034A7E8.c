#include "common.h"

/* NTSC-U counterpart of func_L30_0034B688 (src/levels/30_vidcomic_unnamed/L30_00349390.c) */
/* localdecomp:start func_L30_0034A7E8 */
typedef struct {
    char p0[0x60];
    f32 f60;
    char p64[0xA4 - 0x64];
    f32 fA4;
    f32 fA8;
    f32 fAC;
} P_0034A7E8;
typedef struct {
    char p0[0x34];
    u16 f34;
    char p36[0x68 - 0x36];
    P_0034A7E8 *f68;
} Q_0034A7E8;

extern f32 D_001DD480_sda;
__asm__(".extern D_001DD480_sda, 4");
extern f32 D_001DD484_sda;
__asm__(".extern D_001DD484_sda, 4");
extern f32 D_001DD488_sda;
__asm__(".extern D_001DD488_sda, 4");
extern void func_L01_00441FB8(void *, s32, s32);

void func_L30_0034A7E8(Q_0034A7E8 *a0) {
    P_0034A7E8 *p = a0->f68;

    p->f60 = 0.75f;
    p->fA4 = D_001DD480_sda * 0.017453292f * 0.00027777778f;
    p->fA8 = D_001DD484_sda * 0.017453292f * 0.00027777778f;
    p->fAC = D_001DD488_sda * 0.017453292f * 0.016666668f;
    a0->f34 |= 0x100;
    func_L01_00441FB8(a0, 1, -1);
}
/* localdecomp:end func_L30_0034A7E8 */
