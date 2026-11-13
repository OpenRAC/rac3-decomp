#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B0F10 */
extern void func_0038D308(void *, void *);
extern void func_L03_003B11A8(u8 *a0);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_L03_003B1018(u8 *);

void func_L03_003B0F10(u8 *a0) {
    u8 *m;
    vu0_v4 d;
    f32 a;

    m = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        func_0038D308(a0 + 0xC0, a0 + 0xF0);
        *(vu0_q *)(m + 0x20) = *(vu0_q *)(a0 + 0xC0);
        func_L03_003B11A8(a0);
        if (*(s16 *)(a0 + 0xAA) == 0x1DD1) {
            *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.25f;
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        vec_sub_ba(&d, m + 0x10, a0 + 0x10);
        a = func_0038D160(d.x, d.y);
        func_L01_00448890(a0 + 0xF8, a, m, 0.0012566372f, 0.0025132743f, 0.14660767f, 0);
        func_0038D308(a0 + 0xC0, a0 + 0xF0);
        func_L03_003B1018(a0);
        break;
    }
}
/* localdecomp:end func_L03_003B0F10 */

/* localdecomp:start func_L03_003B1018 */
extern u8 D_001A4BE0[];
extern f32 func_0038CE68(void *, void *);
extern f32 func_L03_00435A08(f32 *x, f32 *y, f32 a, f32 b, f32 c);
extern void func_0038D890(void *, void *, void *, f32);

void func_L03_003B1018(u8 *a0) {
    u8 *m;
    vu0_v4 d;
    vu0_v4 e;
    f32 x;
    u8 *h;

    h = D_001A4BE0;
    m = *(u8 **)(a0 + 0x68);
    if (*(u8 **)(h + 0x35C) == a0 && *(s32 *)(h + 0x360) != 0) {
        vec_sub_ba(&d, h + 0x80, a0 + 0x10);
        x = func_0038CE68(&d, a0 + 0xC0) * 0.34906584f;
        if (*(s32 *)(m + 8) != 0 && x < 0.08726646f && -0.08726646f < x) {
            *(s32 *)(m + 8) = 0;
            *(f32 *)(m + 4) = (0.0f < x) ? 0.013962635f : -0.013962635f;
        }
        x = func_L03_00435A08((f32 *)(a0 + 0xF4), (f32 *)(m + 4), x, 1.0f, 0.96f);
        vec_sub_ba(&e, D_001A4BE0 + 0x80, a0 + 0x10);
        func_0038D890(&e, &e, a0 + 0xD0, x);
        vec_add_ba(D_001A4BE0 + 0x80, &e, a0 + 0x10);
    } else {
        func_L03_00435A08((f32 *)(a0 + 0xF4), (f32 *)(m + 4), 0.0f, 1.0f, 0.96f);
        *(s32 *)(m + 8) = 1;
    }
}
/* localdecomp:end func_L03_003B1018 */
