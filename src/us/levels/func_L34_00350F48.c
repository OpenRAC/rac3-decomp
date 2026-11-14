#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L34_00351C68 (src/levels/34_vidcomic_3/L34_003515A0.c) */
/* localdecomp:start func_L34_00350F48 */
extern void func_L01_00437350(void *, s32, void *);
extern f32 func_00389380(f32, f32);
extern void func_003BEA80(void *, void *);

void func_L34_00350F48(u8 *a0) {
    f32 v[4] __attribute__((aligned(16)));
    u8 *d;
    f32 r;

    d = *(u8 **)(a0 + 0x68);
    if (d[0x81] == 0) {
        func_L01_00437350(a0, 0, d + 0x80);
    }
    qzero(v);
    r = func_00389380(*(f32 *)(d + 0x15C), 0.31997705f);
    *(f32 *)(d + 0x15C) = r;
    v[2] = r;
    func_003BEA80(d + 0x90, v);
    r = func_00389380(*(f32 *)(d + 0x160), 0.10762864f);
    *(f32 *)(d + 0x160) = r;
    if (d[0xC1] == 0) {
        func_L01_00437350(a0, 1, d + 0xC0);
    }
    qzero(v);
    v[1] = *(f32 *)(d + 0x160);
    func_003BEA80(d + 0xD0, v);
    if (d[0x101] == 0) {
        func_L01_00437350(a0, 2, d + 0x100);
    }
    func_003BEA80(d + 0x110, v);
}
/* localdecomp:end func_L34_00350F48 */
