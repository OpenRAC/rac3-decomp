#include "common.h"
#include "vu0.h"

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

/* localdecomp:start func_L17_003BEC30 */
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00470668(void *, void *, s32, f32);

void func_L17_003BEC30(S_003BED98 *p, s32 n, f32 speed, f32 unused, f32 spread, f32 up, f32 upvar, f32 size) {
    u8 *m = (u8 *)p;
    vu0_v4 w, pos, v;
    s32 i;

    for (i = 0; i < n; i++) {
        pos = *(vu0_v4 *)(m + 0x10);
        v = *(vu0_v4 *)(m + 0xE0);
        func_0038CF68(&v, &v, *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * speed);
        vec_add_ab(&pos, &pos, &v);
        w = *(vu0_v4 *)(m + 0xE0);
        w.x += func_003824E0(-spread, spread);
        w.y += func_003824E0(-spread, spread);
        func_0038CE20(&w, &w, (up + func_003824E0(0.0f, upvar)) * 0.020000001f);
        func_L01_00470668(&pos, &w, 0x32, size * 0.00040000002f);
    }
}
/* localdecomp:end func_L17_003BEC30 */

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
