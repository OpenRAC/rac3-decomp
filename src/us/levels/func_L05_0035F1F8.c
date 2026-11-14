#include "common.h"

/* NTSC-U counterpart of func_L05_00360448 (src/levels/05_daxx/L05_0035F360.c): 0.0558505 -> 0.0465421 */
#include "vu0.h"
extern f32 func_00389380(f32, f32);

/* localdecomp:start func_L05_0035F1F8 */
extern vu0_v4 D_L05_001E2780;
extern f32 func_00388960(f32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00389380(f32, f32);
extern void func_L01_00409EF0(void *, s32, s32, s32, s32, s32, s32, f32, f32);

void func_L05_0035F1F8(u8 *o) {
    vu0_v4 q[4];
    vu0_v4 e;
    u8 *v;
    f32 t;
    f32 sz;
    s32 n;
    s32 al;
    s32 col;

    v = *(u8 **)(o + 0x68);
    t = 1.0f - __builtin_fabsf(1.0f - (f32)(*(s16 *)(v + 0xBE) - 1) * 2.0f / (f32)(*(s16 *)(v + 0xBC) - 2));
    if (t < 0.0f) {
        return;
    }
    t = (1.0f - func_00388960(t * 3.1415927f)) * 0.5f;
    n = (f32)(*(s16 *)(v + 0xBC) - 2) * 0.5f;
    sz = t * 0.6f;
    if (v[0xCE] != 0 && n >= *(s16 *)(v + 0xBE)) {
        if (v[0xCE] == 2) {
            *(u16 *)(o + 0x34) &= 0xFFBE;
            *(u16 *)(o + 0x34) |= *(u16 *)(*(u8 **)(o + 0x24) + 0x44) & 0x1000;
            *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        } else {
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(o, 1);
        }
        v[0xCE] = 0;
    }
    vec_sub_ab(&q[0], &D_L05_001E2780, o + 0x10);
    func_00388830(&q[0], &q[0], *(f32 *)(o + 0x2C) * 15.5f + 2.0f);
    func_00388830(&q[2], o + 0xE0, *(f32 *)(o + 0x2C) * 12.0f + 2.0f);
    func_00388758(&q[1], &q[2], &q[0]);
    func_00388830(&q[1], &q[1], *(f32 *)(o + 0x2C) * 26.0f + 2.0f);
    func_00388830(&e, &q[2], -1.8f);
    vec_add_ba(&q[3], o + 0x10, &e);
    func_003886E8(&q[0], &q[0], 0.5f);
    vec_add_ab(&q[3], &q[3], &q[0]);
    *(f32 *)(v + 0xC0) = func_00389380(*(f32 *)(v + 0xC0), 0.0465421155f);
    if (t < 0.05f) {
        al = (u8)(s32)(t * 20.0f * 127.0f);
    } else {
        al = 0x7F;
    }
    col = (al << 24) | 0x808080;
    func_L01_00409EF0(q, 0x40, col, col, col, 0x4D, -1, sz, *(f32 *)(v + 0xC0));
}
/* localdecomp:end func_L05_0035F1F8 */
