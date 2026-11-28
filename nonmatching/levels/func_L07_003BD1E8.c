/* PAL near miss (wave 13 r28, 2026-11-28), first draft (fresh entry; from the functional C, 381 diff -> 169 with the
 * file's flags). Changed: case 10's body placed between cases 5 and 6 (retail text order; its jump to
 * func_L07_003BE708 is cross-jumped with case 9), saved copy of obj+0x10 as a union declared before tmp (0x10/0x20
 * slots), p block-local per case (case 6 keeps it in a1), case 12's flag store through q = s + 0x150, and cases 16/17
 * as if (func_L07_003BE570(obj) != 0) {...} else state 7 (retail keeps both state-7 tails). Left: the u16 counter
 * test (retail andi 0xFFFF then andi 1 on the incremented value, sh of the raw sum; every wording tried here folds to
 * one andi 1), the (s16)v compare in cases 4/16 (retail sign-extends in v0 and loads p[0] into v1, ours the reverse),
 * and the constant/store order of the flag-0x10 blocks in cases 16/17 (retail keeps source order). */
#include "common.h"

/* localdecomp:start func_L07_003BD1E8 */
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
    union { Quad_003BD1E8 q; vu0_v4 v; } saved;
    union { Quad_003BD1E8 q; vu0_v4 v; } tmp;
    s32 v;
    f32 d;

    if (obj[0x20] == 0) {
        func_L07_003BD9D0(obj);
    }
    func_L07_003BDC08(obj);
    saved.q = *(Quad_003BD1E8 *)(obj + 0x10);
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
            s32 *p = D_L07_0021D2C0[*(s32 *)(s + 0x398)];
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
    case 10:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003BE708(obj);
        }
        break;
    case 6:
        if (func_L01_004561B8(obj) != 0) {
            s32 *p = D_L07_0021D2C0[*(s32 *)(s + 0x39C)];
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
    case 11:
        if (func_L01_004561B8(obj) != 0) {
            s32 *p = D_L07_0021D2C0[*(s32 *)(s + 0x39C)];
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
            u8 *q = s + 0x150;
            *(u32 *)(q + 0x38) |= 0x10;
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
            *(u16 *)(s + 0x4F6) += 1;
            if ((*(u16 *)(s + 0x4F6) & 1) == 0) {
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
            s32 *p;

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
        if (func_L07_003BE570(obj) != 0) {
            *(u16 *)(s + 0x4F6) += 1;
            if ((*(u16 *)(s + 0x4F6) & 1) == 0) {
                func_L07_003BE9B8(obj);
            }
            func_L01_00404808(func_L07_003BEAC0, obj);
            func_L07_003BE870(obj);
            if (func_L01_0045BDE8(obj, *(s32 *)(s + 0x3A0)) != 0) {
                func_L07_003BE3A8(obj, 0x10);
            }
        } else {
            func_L07_003BE3A8(obj, 7);
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
        if (func_L07_003BE570(obj) != 0) {
            *(u16 *)(s + 0x4F6) += 1;
            if ((*(u16 *)(s + 0x4F6) & 1) == 0) {
                func_L07_003BE9B8(obj);
            }
            func_L01_00404808(func_L07_003BEAC0, obj);
            func_L07_003BE870(obj);
            if ((func_L01_0045A748(obj, s + 0x360) & 0x80) != 0) {
                func_L07_003BE3A8(obj, 0x11);
            }
        } else {
            func_L07_003BE3A8(obj, 7);
        }
        break;
    case 1:
    default:
        break;
    }
    func_L07_003BDFB8(obj, (f32 *)&saved);
}
/* localdecomp:end func_L07_003BD1E8 */
