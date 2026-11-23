/* functional: medium. written from asm; jump table read from level ELF; unrun blocks untested; callee counts match except one merged tail */
/* reserved50 P01: 387 initial differences with current file flags; 385 after
 * shared vec_add_ba, owner-compatible prototypes, and case 1's default target;
 * 381 after sharing path-copy/radial-vector scratch storage as retail does.
 * The latter recovers retail's 0x60 frame (was 0x70). Switch destinations were
 * reread from PAL; states 13/14 share a target and state 10 precedes state 6
 * in text. Body/tail layout is not matched; retain INCLUDE_ASM in the owner. */
#include "vu0.h"
typedef int Quad_003BD1E8 __attribute__((mode(TI)));
extern u8 *D_L07_001DF41C;
extern u8 *D_L07_001DF500;
extern s32 *D_L07_0021D2C0[];

static __inline__ void add_003BD1E8(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    vec_add_ba(d, a, b);
}

void func_L07_003BD1E8(u8 *obj) {
    extern void func_L07_003BD9D0(u8 *);
    extern void func_L07_003BDC08(u8 *);
    extern void func_L07_003BDFB8(u8 *, f32 *);
    extern s32 func_L07_003BE570(void *);
    extern void func_L07_003BE3A8(void *, s32);
    extern void func_L07_003BE5F8(void *);
    extern void func_L07_003BE678(void *);
    extern void func_L07_003BE6C0(char *);
    extern void func_L07_003BE708(void *);
    extern void func_L07_003BE750(void *);
    extern void func_L07_003BE7C8(void *);
    extern void func_L07_003BE818(void *);
    extern void func_L07_003BE870(u8 *);
    extern void func_L07_003BE9B8(u8 *);
    extern void func_L07_003BEAC0(void *);
    extern s32 func_L01_004561B8(u8 *);
    extern s32 func_0038CB00(void *);
    extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_L06_004591F8(void *, s32 *, s32);
    extern s32 func_L01_0045BDE8(void *, s32);
    extern s32 func_L01_0045A9F0(void *);
    extern s32 func_L01_00454370(void *, void *);
    extern s32 func_L01_0045A748(void *, void *);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_L01_004395E0(void *);
    extern void func_L01_00404808(void (*)(void *), void *);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_00382538(void);
    u8 *s;
    Quad_003BD1E8 saved;
    union { Quad_003BD1E8 q; vu0_v4 v; } tmp;
    s32 *p;
    s32 v;
    f32 d;
    u16 t;

    if (obj[0x20] == 0) {
        func_L07_003BD9D0(obj);
    }
    func_L07_003BDC08(obj);
    saved = *(Quad_003BD1E8 *)(obj + 0x10);
    s = *(u8 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 2:
        if (func_L01_004561B8(obj) != 0) {
            *(s16 *)(s + 0x4F6) = (*(s16 *)(s + 0x4F4) * 5 + 2) / 6;
        }
        if (func_L07_003BE570(obj) != 0) {
            if (func_0038CB00(s + 0x4F6) != 0) {
                func_L07_003BE3A8(obj, 3);
            }
        }
        break;
    case 3: {
        u8 *base = D_L07_001DF41C + (*(s32 *)(s + 0x3AC) << 8);
        func_L01_00409598(obj, base + 0x10, base + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
        func_L07_003BE5F8(obj);
        break;
    }
    case 4:
        if (func_L01_004561B8(obj) != 0) {
            p = D_L07_0021D2C0[*(s32 *)(s + 0x398)];
            *(s32 **)(s + 0x214) = p;
            tmp.q = *(Quad_003BD1E8 *)(obj + 0x10);
            v = func_L06_004591F8(&tmp, p, 0);
            *(s16 *)(s + 0x218) = v;
            if ((p[0] >> 1) < (s16)v) {
                *(s16 *)(s + 0x21A) = 0;
            } else {
                *(s16 *)(s + 0x21A) = *(u16 *)p - 1;
            }
        }
        if (func_L07_003BE570(obj) != 0) {
            func_L07_003BE3A8(obj, 0xA);
        } else if (func_L01_0045BDE8(obj, *(s32 *)(s + 0x398)) != 0) {
            func_L07_003BE3A8(obj, 4);
        }
        break;
    case 5:
        func_L01_0045A9F0(obj);
        if (func_L07_003BE570(obj) != 0) {
            func_L07_003BE3A8(obj, 0xA);
        }
        break;
    case 6:
        if (func_L01_004561B8(obj) != 0) {
            p = D_L07_0021D2C0[*(s32 *)(s + 0x39C)];
            *(s32 **)(s + 0x214) = p;
            tmp.q = *(Quad_003BD1E8 *)(obj + 0x10);
            v = func_L06_004591F8(&tmp, p, 1);
            *(s16 *)(s + 0x218) = v;
            *(s16 *)(s + 0x21A) = 0;
        }
        if (func_L07_003BE570(obj) != 0) {
            func_L07_003BE3A8(obj, 0xB);
        } else if (func_L01_0045BDE8(obj, *(s32 *)(s + 0x39C)) != 0) {
            func_L07_003BE678(obj);
        }
        break;
    case 7:
        if (func_L07_003BE570(obj) != 0) {
            func_L07_003BE818(obj);
        }
        break;
    case 8:
        func_L01_0045A9F0(obj);
        if ((func_L01_00454370(obj, s + 0x70) & 2) != 0) {
            if (*(long *)(s + 0x3A0) == -1) {
                func_L07_003BE3A8(obj, 9);
            } else {
                func_L07_003BE818(obj);
            }
        }
        break;
    case 9:
        if (func_L01_004561B8(obj) != 0) {
            *(s16 *)(s + 0x4F6) = 0xFA;
        }
        if (func_L07_003BE570(obj) != 0) {
            func_L07_003BE708(obj);
        } else if (func_0038CB00(s + 0x4F6) != 0) {
            func_L07_003BE6C0(obj);
        }
        break;
    case 10:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003BE708(obj);
        }
        break;
    case 11:
        if (func_L01_004561B8(obj) != 0) {
            p = D_L07_0021D2C0[*(s32 *)(s + 0x39C)];
            *(s32 **)(s + 0x214) = p;
            tmp.q = *(Quad_003BD1E8 *)(obj + 0x10);
            v = func_L06_004591F8(&tmp, p, 1);
            *(s16 *)(s + 0x218) = v;
            *(s16 *)(s + 0x21A) = *(u16 *)p - 1;
        }
        if (func_L07_003BE570(obj) == 0) {
            func_L07_003BE3A8(obj, 9);
        } else if (func_L01_0045BDE8(obj, *(s32 *)(s + 0x39C)) != 0) {
            func_L07_003BE3A8(obj, 0xC);
        }
        break;
    case 12:
        if (func_L01_004561B8(obj) != 0) {
            *(u32 *)(s + 0x150 + 0x38) |= 0x10;
        }
        func_L01_0045A748(obj, s + 0x130);
        if (func_L07_003BE570(obj) == 0) {
            func_L07_003BE3A8(obj, 9);
        } else if (func_0038CB00(s + 0x4F8) != 0) {
            d = func_L01_0040E570(obj + 0x10, s + 0x130);
            if (d < 6.25f) {
                func_L07_003BE750(obj);
            }
        }
        break;
    case 13:
    case 14:
        func_L01_0045A9F0(obj);
        d = func_L01_004395E0(obj);
        if (d > 10.0f) {
            t = *(u16 *)(s + 0x4F6) + 1;
            *(u16 *)(s + 0x4F6) = t;
            if ((t & 1) == 0) {
                func_L07_003BE9B8(obj);
            }
            func_L01_00404808(func_L07_003BEAC0, obj);
        }
        if (d > 13.0f && d < 16.0f) {
            func_L07_003BE870(obj);
        }
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003BE7C8(obj);
        }
        break;
    case 15:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003BE3A8(obj, 0xC);
        }
        break;
    case 16:
        if (func_L01_004561B8(obj) != 0) {
            u8 *q = s + 0x150;
            *(u32 *)(q + 0x38) |= 0x10;
            *(f32 *)(q + 0x18) = 0.005026548635214567f;
            *(f32 *)(q + 0x28) = 0.10000000894069672f;
            *(f32 *)(q + 0x24) = 0.003200000151991844f;
            *(f32 *)(q + 0x1C) = 0.12566371262073517f;
            *(f32 *)(q + 0x20) = 0.003200000151991844f;
            *(f32 *)(q + 0x14) = 0.005026548635214567f;
            p = D_L07_0021D2C0[*(s32 *)(s + 0x3A0)];
            *(s32 **)(s + 0x214) = p;
            tmp.q = *(Quad_003BD1E8 *)(obj + 0x10);
            v = func_L06_004591F8(&tmp, p, 0);
            *(s16 *)(s + 0x218) = v;
            if ((p[0] >> 1) < (s16)v) {
                *(s16 *)(s + 0x21A) = 0;
            } else {
                *(s16 *)(s + 0x21A) = *(u16 *)p - 1;
            }
        }
        if (func_L07_003BE570(obj) == 0) {
            func_L07_003BE3A8(obj, 7);
        } else {
            t = *(u16 *)(s + 0x4F6) + 1;
            *(u16 *)(s + 0x4F6) = t;
            if ((t & 1) == 0) {
                func_L07_003BE9B8(obj);
            }
            func_L01_00404808(func_L07_003BEAC0, obj);
            func_L07_003BE870(obj);
            if (func_L01_0045BDE8(obj, *(s32 *)(s + 0x3A0)) != 0) {
                func_L07_003BE3A8(obj, 0x10);
            }
        }
        break;
    case 17:
        if (func_L01_004561B8(obj) != 0) {
            u8 *q = s + 0x150;
            f32 ang;
            *(u32 *)(q + 0x38) |= 0x10;
            *(f32 *)(q + 0x1C) = 0.5026548504829407f;
            *(f32 *)(q + 0x18) = 0.010053097270429134f;
            *(f32 *)(q + 0x28) = 0.20000001788139343f;
            *(f32 *)(q + 0x24) = 0.20000000298023224f;
            *(f32 *)(q + 0x20) = 0.20000000298023224f;
            *(f32 *)(q + 0x14) = 0.010053097270429134f;
            ang = func_00382538();
            tmp.v.x = func_0038D098(ang) * *(f32 *)(s + 0x3A8);
            tmp.v.y = func_0038D0B0(ang) * *(f32 *)(s + 0x3A8);
            tmp.v.z = 0.0f;
            add_003BD1E8((vu0_v4 *)(s + 0x360), (vu0_v4 *)(D_L07_001DF500 + (*(s32 *)(s + 0x3A4) << 7) + 0x30), &tmp.v);
        }
        if (func_L07_003BE570(obj) == 0) {
            func_L07_003BE3A8(obj, 7);
        } else {
            t = *(u16 *)(s + 0x4F6) + 1;
            *(u16 *)(s + 0x4F6) = t;
            if ((t & 1) == 0) {
                func_L07_003BE9B8(obj);
            }
            func_L01_00404808(func_L07_003BEAC0, obj);
            func_L07_003BE870(obj);
            if ((func_L01_0045A748(obj, s + 0x360) & 0x80) != 0) {
                func_L07_003BE3A8(obj, 0x11);
            }
        }
        break;
    case 1:
    default:
        break;
    }
    func_L07_003BDFB8(obj, (f32 *)&saved);
}
