/* NTSC-U draft (Claude wave K): C of func_L13_003B60D0, the NTSC-U twin of func_L13_003B8010, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 127 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_003B60D0", whose code is not the PAL one).
 * Worker's note: 33 words off (127 diff); needs vu0 flag; lui hi of D_L13_001DF140 gets CSE'd into s2 (retail reloads it, no s2), float const 0.017453292f comes from gp slot in ours vs lui/ori in retail; 2 divs rows
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L13_003B60D0 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_00142CBD[];
extern u8 D_001A4C60[];
extern u8 *D_L13_001DF61C;
extern u8 *D_L13_001DF700;
typedef struct W_003B60D0 {
    s32 w0;
    s32 w4;
    s32 w8;
} W_003B60D0;

extern W_003B60D0 D_L13_001DF140;

extern void func_003BD360(void *);
extern s32 func_0037E0F0(void *, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00438430(s32);
extern f32 func_003BEB48(f32, f32, f32);
extern void *func_L13_0034B6C0(s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L13_0034B798(void *, void *, void *);

void func_L13_003B60D0(u8 *o) {
    u8 *p;
    f32 t[4];
    u128_t a;
    f32 b[4];
    void *obj;
    f32 f;
    s32 v;
    s32 k;

    p = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        if (*(s32 *)(p + 0x24) != 0 && D_00142CBD[0] != 0) {
            func_003BD360(o);
            return;
        }
        if (func_0037E0F0(D_001A4C60, *(s32 *)p, 0) != 0) {
            func_L01_00441FB8(o, 1, -1);
        }
        if (*(s32 *)(p + 0x28) >= 0) {
            k = *(s32 *)(p + 0x10);
            if (k == -1 || D_L13_001DF61C[k * 256 + 0x20] == 0xFE || D_L13_001DF61C[k * 256 + 0x20] == 0xFD) {
                func_L01_00438430(*(s32 *)(p + 0x28));
            }
        }
    }
    if (o[0x20] != 1) {
        return;
    }
    if (func_0037E0F0(D_001A4C60, *(s32 *)p, t) == 0) {
        func_L01_00441FB8(o, 0, -1);
        return;
    }
    f = func_003BEB48(*(f32 *)(p + 8), *(f32 *)(p + 0xC), (t[2] + 1.0f) * 0.5f);
    v = *(s32 *)(p + 0x14) + (s32)(60.0f / f);
    if (!(v < D_L13_001DF140.w0)) {
        return;
    }
    obj = func_L13_0034B6C0(*(s32 *)(p + 4));
    if (obj != 0) {
        f32 ang;

        ang = func_00388A28(t[0], t[1]);
        ang = func_00389380(ang, func_L01_00440918(0.0f, *(f32 *)(p + 0x20) * 0.017453292f));
        a = *(u128_t *)(D_L13_001DF700 + *(s32 *)(p + 0x18) * 128 + 0x30);
        b[0] = func_00388960(ang) * *(f32 *)(p + 0x1C);
        b[1] = func_00388978(ang) * *(f32 *)(p + 0x1C);
        b[2] = 0.0f;
        vec_add_ab(b, &a, b);
        func_L13_0034B798(obj, &a, b);
        *(s32 *)(p + 0x14) = D_L13_001DF140.w0;
    }
}
/* localdecomp:end func_L13_003B60D0 */
