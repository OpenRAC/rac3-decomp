#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L34_0034EBE0 */
typedef int u128_t_0034EBE0 __attribute__((mode(TI)));
__asm__(".extern D_L34_001DD700, 4");
extern s32 D_L34_001DD700;
__asm__(".extern D_L34_001DD704, 4");
extern f32 D_L34_001DD704;
__asm__(".extern D_L34_001DD70C, 4");
extern s32 D_L34_001DD70C;
__asm__(".extern D_L34_001DD710, 4");
extern s32 D_L34_001DD710;
__asm__(".extern D_L34_001DD714, 4");
extern f32 D_L34_001DD714;
extern u8 D_001A4C60[];
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L30_0034C300(u8 *, void *, void *, s32, s32, f32);
extern s32 func_00382380(void *, s32, s32);
extern void func_L34_0034F2E0(u8 *);
extern void func_L34_0034F4B8(u8 *);
extern void func_L34_0034F500(u8 *);
extern void func_L34_0034F5A0(u8 *);
extern void func_L34_0034F630(u8 *);

void func_L34_0034EBE0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 flags;
    f32 t;
    vu0_v4 tmp;

    switch (o[0x20]) {
    case 0x42:
        if (func_L01_004561B8(o)) {
            func_L01_003303B8(o + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            *(u128_t_0034EBE0 *)(o + 0x10) = *(u128_t_0034EBE0 *)(v + 0x50);
            flags = *(s32 *)(v + 0x60);
            *(s32 *)(v + 0x60) = flags & ~4;
            if ((flags & 2) || ((v[0x60] ^ 1) & 1)) {
                func_003C2880(o);
                return;
            }
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(o, 1);
        }
        if (func_L30_0034D8D8(o + 0x10, 1.5f) != 0) {
            if (*(s32 *)(v + 0x60) & 1) {
                if (*(s32 *)(v + 0x60) & 4) {
                    u8 *c;
                    *(u16 *)(o + 0x34) &= 0xFFBE;
                    c = *(u8 **)(o + 0x24);
                    *(u16 *)(o + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
                    *(s32 *)(o + 0x98) = *(s32 *)(c + 0x10);
                    func_L01_004450F0(o, 0, -1);
                }
            }
        } else {
            *(s32 *)(v + 0x60) |= 4;
        }
        break;
    case 0:
        func_L34_0034F4B8(o);
        func_L01_004450F0(o, 5, -1);
        break;
    case 1:
        if (func_L01_004561B8(o)) {
            if (o[0x43] != 1) {
                func_003C3A10(o, 1, 0, (D_L34_001DD700 * 5 + 2) / 6);
            }
            *(s32 *)(v + 0x84) = *(s32 *)(v + 0x80);
            if (o[0x94] != 4) {
                *(s32 *)(v + 0x6C) = 0;
            }
        }
        *(s32 *)(v + 0x6C) += 1;
        *(f32 *)(v + 0x7C) = (f32)*(s32 *)(v + 0x6C) * *(f32 *)(v + 0x70) /
            ((fabs_asm(*(f32 *)(v + 0x78)) + fabs_asm(*(f32 *)(v + 0x68))) * 3.1415927f);
        func_L34_0034F630(o);
        if (*(s32 *)(v + 0x84) == 0) {
            if (o[0x43] != 2) {
                func_003C3A10(o, 2, 0, (D_L34_001DD700 * 5 + 2) / 6);
            } else {
                if (*(s32 *)(v + 0x80) != -1 && func_L01_0044E1B8(o, D_L34_001DD704)) {
                    vu0_v4 *d = &tmp;
                    qzero(&tmp);
                    tmp.z = -1.0f;
                    func_0038CF68(d, d, D_L34_001DD714);
                    func_L30_0034C300(o, d, o + 0x10, D_L34_001DD710, D_L34_001DD710, (f32)v[0x14]);
                }
                if (o[0x60] & 2) {
                    *(s32 *)(v + 0x84) = *(s32 *)(v + 0x80);
                    if (o[0x43] != 1) {
                        func_003C3A10(o, 1, 0, (D_L34_001DD700 * 5 + 2) / 6);
                    }
                }
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            if (o[0x43] != 1) {
                func_003C3A10(o, 1, 0, (D_L34_001DD700 * 5 + 2) / 6);
            }
            *(s32 *)(v + 0x84) = *(s32 *)(v + 0x80);
        }
        if (*(s32 *)(v + 0x84) == 0) {
            if (o[0x43] != 2) {
                func_003C3A10(o, 2, 0, (D_L34_001DD700 * 5 + 2) / 6);
            } else {
                if (*(s32 *)(v + 0x80) != -1 && func_L01_0044E1B8(o, D_L34_001DD704)) {
                    vu0_v4 *d = &tmp;
                    qzero(&tmp);
                    tmp.z = -1.0f;
                    func_0038CF68(d, d, D_L34_001DD714);
                    func_L30_0034C300(o, d, o + 0x10, D_L34_001DD710, D_L34_001DD710, (f32)v[0x14]);
                }
                if (o[0x60] & 2) {
                    *(s32 *)(v + 0x84) = *(s32 *)(v + 0x80);
                    if (o[0x43] != 1) {
                        func_003C3A10(o, 1, 0, (D_L34_001DD700 * 5 + 2) / 6);
                    }
                }
            }
        }
        func_L34_0034F5A0(o);
        break;
    case 3:
        if (func_L01_004561B8(o)) {
            if (o[0x43] != 1) {
                func_003C3A10(o, 1, 0, (D_L34_001DD700 * 5 + 2) / 6);
            }
            if (o[0x94] != 4) {
                *(s32 *)(v + 0x6C) = 0;
            }
        }
        *(s32 *)(v + 0x6C) += 1;
        t = *(f32 *)(v + 0x70) * (f32)*(s32 *)(v + 0x6C) /
            ((fabs_asm(*(f32 *)(v + 0x68)) + fabs_asm(*(f32 *)(v + 0x78))) * 0.7853982f);
        *(f32 *)(v + 0x7C) = t;
        if (1.0f < t) {
            func_L01_004450F0(o, 2, -1);
        } else {
            func_L34_0034F500(o);
        }
        break;
    case 4:
        if (func_L01_004561B8(o)) {
            if (o[0x43] != 3) {
                func_003C3A10(o, 3, 0, (D_L34_001DD700 * 5 + 2) / 6);
            }
            *(s32 *)(v + 0x88) = D_L34_001DD70C;
        }
        if (o[0x60] & 2) {
            func_L01_004450F0(o, o[0x94], -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(o)) {
            if (o[0x43] != 0) {
                func_003C3A10(o, 0, 0, (D_L34_001DD700 * 5 + 2) / 6);
            }
        }
        if (*(s32 *)(v + 0x64) != 0 ? func_00382380(D_001A4C60, *(s32 *)(v + 0x64), 0)
                                     : func_L30_0034D8D8(o + 0x10, 1.5f)) {
            if (*(s32 *)(v + 0x74) != 0) {
                func_L01_004450F0(o, 1, -1);
            } else {
                func_L01_004450F0(o, 3, -1);
            }
        }
        break;
    }
    func_L34_0034F2E0(o);
}
/* localdecomp:end func_L34_0034EBE0 */

/* localdecomp:start func_L34_0034F2E0 */
__asm__(".extern D_L34_001DD708, 4");
extern f32 D_L34_001DD708;
extern u8 D_001A4C60[];
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L30_0034D8D8(void *, f32);

void func_L34_0034F2E0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    u8 *r;
    f32 dmg;
    vu0_v4 tmp;

    if (o[0x20] != 4 && o[0x20] != 0x42) {
        func_0038CAD0(v + 0x84);
        func_0038CAD0(v + 0x88);
    }
    func_L01_0044ABD0(o, v + 0x40);
    r = func_L01_00447490(o, 0x10000, 0);
    if (r != 0) {
        o[0xA8] = 0xFF;
        dmg = *(f32 *)(r + 0x2C);
        if (dmg > 0.0f && o[0x20] != 0x42 && *(s32 *)(v + 0x88) <= 0) {
            v[0x47] = 0xFF;
            *(f32 *)v -= dmg;
            func_003C4A40(o, v + 0x40);
            if (*(f32 *)v <= 0.0f) {
                func_L01_004450F0(o, 0x42, -1);
            } else {
                func_L01_004450F0(o, 4, -1);
            }
        }
    }
    if (o[0x20] != 0x42) {
        vec_sub_ba(&tmp, D_001A4C60, o + 0x10);
        func_0038CF68(&tmp, &tmp, 1.0f);
        func_L30_0034CB68(o, &tmp, 1, -1, 0, 0, (f32)v[0x14],
                          D_L34_001DD708 * *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24));
        if (o[0x20] != 0x42 && (*(s32 *)(v + 0x60) & 1) && !func_L30_0034D8D8(o + 0x10, 1.5f)) {
            func_L01_004450F0(o, 0x42, -1);
        }
    }
}
/* localdecomp:end func_L34_0034F2E0 */

/* localdecomp:start func_L34_0034F4B8 */
typedef int u128_t __attribute__((mode(TI)));

void func_L34_0034F4B8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 n = *(s32 *)(p + 0x80);
    *(u128_t *)(p + 0x50) = *(u128_t *)(a0 + 0x10);
    *(s32 *)(p + 0x88) = 0;
    *(s32 *)(p + 0x84) = 0;
    *(s32 *)(p + 0x80) = (n * 5 + 2) / 6;
    *(f32 *)(a0 + 0xF8) = -1.57079637050628662109375f;
}
/* localdecomp:end func_L34_0034F4B8 */

/* localdecomp:start func_L34_0034F500 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L34_0034F500(u8 *a0) {
    vu0_v4 tmp;
    u8 *o;
    f32 ang;
    f32 s;
    f32 c;
    qzero(&tmp);
    o = *(u8 **)(a0 + 0x68);
    ang = *(f32 *)(o + 0x7C) * 0.5f * 3.14159274f;
    s = func_0038D098(ang);
    c = (1.0f - s) * *(f32 *)(o + 0x68);
    tmp.x = c;
    tmp.z = func_0038D0B0(ang) * *(f32 *)(o + 0x78);
    vec_add_ab(a0 + 0x10, o + 0x50, &tmp);
}
/* localdecomp:end func_L34_0034F500 */

/* localdecomp:start func_L34_0034F5A0 */
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L34_0034F5A0(u8 *a0) {
    vu0_v4 tmp;
    u8 *p = *(u8 **)(a0 + 0x68);

    qzero(&tmp);
    *(f32 *)&tmp = *(f32 *)(p + 0x68);
    func_0038CF68(&tmp, &tmp, *(f32 *)(p + 0x70));
    vec_add_ba(&tmp, a0 + 0x10, &tmp);
    if (func_003D3CB0(a0 + 0x10, &tmp, 2, a0, 0) != 0) {
        func_L01_004450F0(a0, 0x42, -1);
    } else {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)&tmp;
    }
}
/* localdecomp:end func_L34_0034F5A0 */

/* localdecomp:start func_L34_0034F630 */
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L34_0034F630(u8 *a0) {
    f32 v[4];
    u8 *q = a0 + 0x10;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 x, t;
    *(u128_t *)v = *(u128_t *)q;
    v[2] = *(f32 *)(s + 0x58) + *(f32 *)(s + 0x78) * *(f32 *)(s + 0x7C);
    x = *(f32 *)(s + 0x7C);
    t = func_0038D098(func_0038DB48((x + x) * 3.1415927410125732f + 1.5707963705062866f));
    v[0] = *(f32 *)(s + 0x50) + *(f32 *)(s + 0x68) * t;
    if (func_003D3CB0(q, v, 2, a0, 0) != 0) {
        func_L01_004450F0(a0, 0x42, -1);
    } else {
        *(u128_t *)q = *(u128_t *)v;
    }
}
/* localdecomp:end func_L34_0034F630 */
