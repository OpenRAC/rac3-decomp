#include "common.h"

/* localdecomp:start func_L31_003A06D0 */
#include "vu0.h"
extern f32 D_L31_001DE740; __asm__(".extern D_L31_001DE740, 4");
extern f32 D_L31_001DE744; __asm__(".extern D_L31_001DE744, 4");
extern f32 D_L31_001DE74C; __asm__(".extern D_L31_001DE74C, 4");
extern f32 D_L31_001DE754; __asm__(".extern D_L31_001DE754, 4");
extern f32 D_L31_001DE758; __asm__(".extern D_L31_001DE758, 4");
extern s32 D_L31_001DE6E0; __asm__(".extern D_L31_001DE6E0, 4");
extern s32 D_L31_001DE6E4; __asm__(".extern D_L31_001DE6E4, 4");
extern u8 D_L31_001E9180[];
extern u8 D_001A30B0[];
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038DB48(f32);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L31_003A0D30(u8 *);
extern void func_L31_003A11E0(u8 *);
extern void func_L31_003A1270(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L31_003A0C88(u8 *);
extern s32 func_L31_003A12B0(void *m, void *a, void *b, void *c, s32 i4, s32 i5, s32 i6, s32 i7, s32 i8, f32 x, f32 y, f32 z);

void func_L31_003A06D0(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    vu0_v4 v10;
    f32 a = D_L31_001DE740;
    f32 b;
    if (*(s32 *)(s + 0x3C) == 0) {
        a *= *(f32 *)(s + 0x60);
    }
    b = D_L31_001DE744;
    if (*(s32 *)(s + 0x3C) == 0) {
        b *= *(f32 *)(s + 0x60);
    }
    switch (m[0x20]) {
    case 0:
        func_L31_003A11E0(m);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1: {
        s32 k;
        u8 *e;
        if (func_L01_00456250(m)) {
            func_L01_004450F0(m, 2, -1);
        }
        func_L31_003A0D30(m);
        *(f32 *)(m + 0xF0) = func_0038DB48(0.0f);
        *(f32 *)(m + 0xF8) = -1.5707964f;
        func_L01_0043B9E8(m, 0xFF, 0xFF, 0xFF);
        k = *(s32 *)(s + 0x34);
        if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != m || e[0xD0] == 0) {
            *(s32 *)(s + 0x34) = func_003A52A0(1, 4, m);
        }
        break;
    }
    case 2: {
        s32 k;
        u8 *e;
        if (func_L01_004561B8(m) && m[0x43] != 1) {
            func_003C3A10(m, 1, 0, 4);
        }
        *(u16 *)(m + 0x96) += 1;
        *(f32 *)(s + 0x10) += *(f32 *)(s + 0x20);
        *(f32 *)(s + 0x18) += *(f32 *)(s + 0x24);
        vec_add_ba(&v10, m + 0x10, s + 0x10);
        if (func_L01_003FB640(&v10, a, 0x12, m) != 0 || func_0038CAD0(s + 0x28) != 0) {
            u8 *g = D_L31_001E9180;
            if (*(s32 *)(g + 0x18) != 0) {
                *(s32 *)(s + 0x40) = *(s32 *)(g + 0x18);
            }
            *(vu0_q *)(m + 0x10) = *(vu0_q *)(g + 0x20);
            func_L01_004450F0(m, 3, -1);
        } else {
            *(vu0_q *)(m + 0x10) = *(vu0_q *)&v10;
        }
        if (*(s32 *)(s + 0x3C) != 0) {
            func_L01_00446780(m, m + 0x10, 1, 0, 1, 0, a, *(f32 *)(s + 0x2C), 1.0f);
        }
        func_L31_003A0D30(m);
        if (*(f32 *)(s + 0x18) == 0.0f) {
            break;
        }
        if (*(f32 *)(s + 0x10) == 0.0f) {
            *(f32 *)(m + 0xF0) = 0.0f;
        } else {
            *(f32 *)(m + 0xF0) = func_0038D160(*(f32 *)(s + 0x10), *(f32 *)(s + 0x18));
            *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0),
                                               *(f32 *)(s + 0x10) < 0.0f ? D_L31_001DE754 : D_L31_001DE758);
        }
        *(f32 *)(m + 0xF8) = -1.5707964f;
        func_L01_0043B9E8(m, 0xFF, 0xFF, 0xFF);
        k = *(s32 *)(s + 0x34);
        if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != m || e[0xD0] == 0) {
            *(s32 *)(s + 0x34) = func_003A52A0(1, 4, m);
        }
        break;
    }
    case 3: {
        vu0_v4 v20, v30, v40;
        u8 *t = 0;
        u8 *o = *(u8 **)(s + 0x40);
        s32 i;
        f32 f;
        if (o != 0 && (*(u16 *)(o + 0x34) & 0x20)) {
            t = *(u8 **)(*(u8 **)(o + 0x68) + 8);
        }
        if (func_L01_004561B8(m)) {
            if (*(s32 *)(s + 0x3C) != 0) {
                func_003A52A0(0, 0, m);
            }
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            *(s32 *)(s + 0x28) = D_L31_001DE6E4;
            if (*(s32 *)(s + 0x3C) != 0) {
                for (i = 0; i < D_L31_001DE6E0; i++) {
                    vu0_v4 *pv = &v20;
                    vu0_v4 *up = &v40;
                    *(vu0_q *)&v40 = 0;
                    v40.y = 1.0f;
                    v40.w = 1.0f;
                    func_0038CF68(pv, s + 0x10, *(f32 *)(s + 0x38));
                    f = func_003C4088(2.0420351f, 4.2411504f, (f32)i / (f32)D_L31_001DE6E0);
                    func_0038D890(pv, pv, up, f);
                    if (t != 0) {
                        vec_add_ab(pv, pv, t + 0x10);
                    }
                    func_0038CE20(&v10, pv, D_L31_001DE74C);
                    vec_add_ba(&v10, m + 0x10, &v10);
                    qzero(&v30);
                    v30.x = *(f32 *)(s + 0x20);
                    v30.z = *(f32 *)(s + 0x24);
                    func_L01_00456230((void *)func_L31_003A12B0(*(void **)(s + 0x30), pv, &v10, &v30,
                                                        *(s32 *)(s + 0x44), *(s32 *)(s + 0x48),
                                                        *(s32 *)(s + 0x4C), *(s32 *)(s + 0x50), 0,
                                                        1.0f, *(f32 *)(s + 0x38), *(f32 *)(s + 0x60)), 1);
                }
            }
        }
        if (t != 0) {
            vec_add_ab(m + 0x10, m + 0x10, t + 0x10);
            if (*(f32 *)(t + 0x18) < 0.0f) {
                *(f32 *)(m + 0x18) -= *(f32 *)(t + 0x18);
            }
        }
        f = (f32)(D_L31_001DE6E4 - *(s32 *)(s + 0x28)) / (f32)D_L31_001DE6E4;
        func_L31_003A0D30(m);
        if (*(s32 *)(s + 0x3C) != 0) {
            f = func_003C4088(a, b, 1.0f - f);
            func_L01_00446780(m, m + 0x10, 1, 0, 1, 0, f, 20.0f, 1.0f);
        }
        if (func_0038CAD0(s + 0x28)) {
            func_L01_004450F0(m, 4, -1);
        }
        break;
    }
    case 4:
        func_L31_003A1270(m);
        return;
    }
    if (*(s32 *)(s + 0x3C) > 0) {
        func_L31_003A0C88(m);
    }
}
/* localdecomp:end func_L31_003A06D0 */
