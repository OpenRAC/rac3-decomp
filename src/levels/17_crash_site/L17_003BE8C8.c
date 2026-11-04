#include "common.h"

typedef struct S_003BED98 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x75];
    u16 f96;
} S_003BED98;

INCLUDE_ASM("asm/levels", func_L17_003BE8C8);

/* localdecomp:start func_L17_003BEB98 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L17_003BE8C8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);

void func_L17_003BEB98(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L17_003BE8C8(a0, 0x7F, 0x1EAD, 1, 1, 1, 0x50202020, 0x60CC20, -1.5f, 1.0f,
                          0xFF4020, 0x7F60A0FF, 0x280000FF, 1);
    }
}
/* localdecomp:end func_L17_003BEB98 */

INCLUDE_ASM("asm/levels", func_L17_003BEC30);

/* localdecomp:start func_L17_003BED98 */
extern void func_L17_003BEC30(S_003BED98 *, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L17_003BED98(S_003BED98 *p) {
    s32 t;

    if (p->f20 == 0) {
        t = p->f96;
        if (t == 0) {
            func_L17_003BEC30(p, 3, -1.5f, 0.15f, 0.25f, -6.0f, -5.0f, 10.0f);
            if (func_00382468(10) < 9) {
                p->f96 = func_00382498(30, 250);
            } else {
                func_L01_004450F0((u8 *)p, 1, -1);
            }
        } else {
            p->f96 = t - 1;
        }
    }
}
/* localdecomp:end func_L17_003BED98 */

/* localdecomp:start func_L17_003BEE50 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L17_003BE8C8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);

void func_L17_003BEE50(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L17_003BE8C8(a0, 0x3F, 0x1EC1, 1, 1, 1, 0x802060C0, 0x2060CC, 1.5f, 3.0f, 0x20CC80, 0x80608080, 0x280000FF, 0);
    }
}
/* localdecomp:end func_L17_003BEE50 */

INCLUDE_ASM("asm/levels", func_L17_003BEEE8);

INCLUDE_ASM("asm/levels", func_L17_003BF000);
