#include "common.h"

/* localdecomp:start func_L01_0045CCD8 */
#include "vu0.h"
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern u8 D_L01_001EAA00_0045CCD8[];

s32 func_L01_0045CCD8(u8 *a, u8 *b) {
    f32 p[4] __attribute__((aligned(16)));
    f32 u[4] __attribute__((aligned(16)));
    f32 t[4] __attribute__((aligned(16)));
    u8 *d;

    *(vu0_q *)t = 0;
    t[2] = *(f32 *)(b + 4) + *(f32 *)b;
    *(vu0_q *)u = *(vu0_q *)t;
    func_0038D000(u, u, a + 0xC0);
    vec_add_ba(p, a + 0x10, u);
    if (func_L01_003FB640(p, *(s32 *)(b + 0x38) & 2, a, *(f32 *)b) != 0) {
        d = D_L01_001EAA00_0045CCD8;
        *(s32 *)(b + 0x84) = *(s32 *)(d + 0x18);
        *(vu0_q *)(b + 0x60) = *(vu0_q *)(d + 0x20);
        *(vu0_q *)p = *(vu0_q *)(d + 0x30);
        vec_sub_ab(a + 0x10, p, u);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0045CCD8 */

/* localdecomp:start func_L01_0045CDA0 */
extern void func_003C5180_0045CDA0(void *, void *, s32);
extern void func_0038CF68(f32, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern f32 func_L01_00451580(void *);
extern u8 D_L01_001EAA00_0045CDA0[];

void func_L01_0045CDA0(u8 *a, u8 *b) {
    f32 v[4] __attribute__((aligned(16)));
    f32 p1[4] __attribute__((aligned(16)));
    f32 p2[4] __attribute__((aligned(16)));
    u8 *d;

    func_003C5180_0045CDA0(a + 0x10, v, 1);
    func_0038CF68(*(f32 *)(b + 8) + 0.1f, p1, v);
    func_0038CF68(-*(f32 *)(b + 0xC) - 0.1f, p2, v);
    vec_add_ba(p1, p1, a + 0x10);
    vec_add_ba(p2, p2, a + 0x10);
    if (func_003D3CB0(p1, p2, 0, a, 0) != 0) {
        *(f32 *)(b + 0x90) = func_L01_00451580(D_L01_001EAA00_0045CDA0 + 0x20);
        d = D_L01_001EAA00_0045CDA0;
        *(s32 *)(b + 0x88) = *(s32 *)(d + 0x18);
        *(s32 *)(b + 0x8C) = *(s32 *)(d + 0x1C);
        *(s32 *)(b + 0xD8) = -1;
        func_0038CF68(1.0f, b + 0x50, d + 0x40);
    } else {
        *(s32 *)(b + 0x90) = 0;
        *(s32 *)(b + 0xD8) = -1;
        *(s32 *)(b + 0x88) = 0;
        *(s32 *)(b + 0x8C) = 0;
        qzero(b + 0x50);
    }
}
/* localdecomp:end func_L01_0045CDA0 */
