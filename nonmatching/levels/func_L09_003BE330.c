/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003BCAB8, the NTSC-U twin of func_L09_003BE330, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (PAL line lacks @ps2as)" (src/levels/09_tyhrranosis/L09_003B8580.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L09_003BCAB8 */
extern s32 func_003883C8(void *);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BEA80(void *, void *);
extern void func_00389018(void *, s32, f32);

s32 func_L09_003BCAB8(u8 *o, void *a) {
    u8 *st = *(u8 **)(o + 0x68);

    if (st[0xD41] == 0) {
        st[0xD41] = 2;
        *(s16 *)(st + 0xD3A) = 0x3C;
        *(f32 *)(st + 0xD3C) = 0.016666668f;
    }
    if (func_003883C8(st + 0xD3A) != 0 || st[0xD41] == 1) {
        st[0xD41] = 1;
        return 1;
    }
    if (st[0xD41] == 2) {
        *(f32 *)(st + 0xC30) = func_003BE6A8(-(*(f32 *)(o + 0x18) - 332.0f + -2.0f), 0.0f, (f32)*(s16 *)(st + 0xD3A) * *(f32 *)(st + 0xD3C));
        func_003886E8(st + 0xC30, st + 0xC30, 1024.0f);
        if (a != 0) {
            func_003BEA80(st + 0xC50, a);
        } else {
            func_00389018(st + 0xC50, 1, -0.017453292f);
        }
    }
    return 0;
}
/* localdecomp:end func_L09_003BCAB8 */
