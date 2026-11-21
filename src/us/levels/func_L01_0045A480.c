#include "common.h"

/* NTSC-U counterpart of func_L01_0045D788 (src/levels/shared/L01_0045D248.c): 0.016 -> 0.0111111 */
#include "vu0.h"
extern void func_L01_0045A480(u8 *, u8 *, u8 *, s32, void *, void *, void *);
extern void func_00388830(f32, void *, void *);
extern f32 func_00388730(void *, void *);
#include "vu0.h"
extern void func_00388830(f32, void *, void *);

/* localdecomp:start func_L01_0045A480 */

extern f32 func_L01_0045AD08_0045A480(char *, char *, vu0_v4 *, int);
extern f32 func_L01_0044E4B8_0045A480(u8 *, void *, void *);
extern f32 func_003887C8(void *, void *);
extern void func_L01_0044DDA0_0045A480(u8 *, void *, f32);
extern void func_00388830(f32, void *, void *);
extern void func_L01_0044DE28_0045A480(u8 *, void *, void *, f32, void *);
extern f32 func_00388730(void *, void *);
extern void func_003BF640(void *, f32);
extern f32 func_L01_0044DE78_0045A480(u8 *, void *, void *);
extern void func_L01_0044E108_0045A480(u8 *, void *, void *, f32);
extern f32 func_003BFB80(u8 *, u8 *, void *);
extern void func_003BEE20(f32 *, f32, f32, f32, f32);

void func_L01_0045A480(u8 *a, u8 *o, u8 *b, s32 c, void *e, void *f, void *mp) {
    vu0_v4 t;
    vu0_v4 u;
    f32 w;
    f32 d;
    f32 s;

    if (!(*(s32 *)(o + 0x38) & 0x10)) {
        func_L01_0045AD08_0045A480((char *)a, (char *)o, (vu0_v4 *)c, (int)mp);
    }
    d = 0.0f;
    if (!(*(s32 *)(o + 0x38) & 0x10)) {
        d = func_L01_0044E4B8_0045A480(a, (void *)c, mp);
    }
    if (*(f32 *)(o + 0x30) < d) {
        qzero(&t);
        *(s32 *)(o + 0x9C) |= 2;
    } else {
        *(s32 *)(o + 0x9C) &= ~2;
        *(f32 *)(o + 0xCC) = func_003887C8(a + 0x10, b);
        if (*(f32 *)(o + 0xCC) <= *(f32 *)(o + 0x34)) {
            qzero(&t);
        } else {
            s = sqrt_asm((*(f32 *)(o + 0xCC) - *(f32 *)(o + 0x34)) * 2.0f * *(f32 *)(o + 0x24));
            if (*(f32 *)(o + 0x28) < s) {
                s = *(f32 *)(o + 0x28);
            }
            func_L01_0044DDA0_0045A480(a, &t, s);
        }
        if (*(s32 *)(o + 0x38) & 0x10) {
            func_00388830(sqrt_asm((*(f32 *)(o + 0xCC) - *(f32 *)(o + 0x34)) * 2.0f * *(f32 *)(o + 0x24)), &t, (void *)c);
        }
    }
    vec_sub_ab(&u, &t, o + 0xA0);
    func_L01_0044DE28_0045A480(a, &u, &u, 0.0f, mp);
    if (0.0f < func_00388730(&t, o + 0xA0)) {
        func_003BF640(&u, *(f32 *)(o + 0x20));
    } else {
        func_003BF640(&u, *(f32 *)(o + 0x24));
    }
    vec_add_ab(o + 0xA0, o + 0xA0, &u);
    *(f32 *)(o + 0xB0) = func_L01_0044DE78_0045A480(a, o + 0xA0, mp);
    if (!(*(s32 *)(o + 0x38) & 4)) {
        if (*(f32 *)(o + 0x90) < 0.0f) {
            func_L01_0044E108_0045A480(a, o + 0xA0, o + 0xA0, *(f32 *)(o + 0x2C));
            if (*(s16 *)(o + 0xC0) == 0) {
                *(s32 *)(o + 0x94) |= 0x20;
            }
        } else {
            w = func_003BFB80(a, o + 0xA0, mp);
            if (*(f32 *)(o + 0x90) < w) {
                w = *(f32 *)(o + 0x90);
            } else if (w < 0.0f) {
                w = 0.0f;
            }
            func_003BEE20(&w, *(f32 *)(o + 0x90), 0.0111111114f, 0.0111111114f, 1.0f);
            func_L01_0044DE28_0045A480(a, o + 0xA0, o + 0xA0, w, mp);
        }
    }
}
/* localdecomp:end func_L01_0045A480 */
