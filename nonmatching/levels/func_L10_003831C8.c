/* NTSC-U draft (2026-11-14, Claude worker): C of func_L10_00381840, the NTSC-U twin of func_L10_003831C8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/10_zeldrin_starport/L10_003831C8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L10_003831C8 (src/levels/10_zeldrin_starport/L10_003831C8.c) */

/* localdecomp:start func_L10_00381840 */
typedef union { u8 b[0x3000]; s16 h[0x1800]; s32 i[0xC00]; f32 f[0xC00]; u8 *ptr[0xC00]; } G_L10;
extern G_L10 D_001A4BE0;
extern u8 *D_L10_0021C3E0[];
extern s32 D_L10_001D673C;
extern s32 D_001D6740_sda;
extern f32 D_001DDDD4_sda;
extern f32 D_001DDDD0_sda;
__asm__(".extern D_001D6740_sda, 4");
__asm__(".extern D_001DDDD4_sda, 4");
__asm__(".extern D_001DDDD0_sda, 4");
extern u8 *D_L10_001E8998[];
extern vu0_v4 D_L10_001E89A0;
extern void func_003886E8(void *, void *, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00389468(f32, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_00388990(f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_0037E0B8(void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);

s32 func_L10_00381840(u8 *a0, vu0_v4 v, f32 *a2, f32 *a3)
{
    vu0_v4 t0;
    vu0_v4 p20;
    u8 *list[128];
    vu0_v4 q;
    vu0_v4 t1;
    vu0_v4 t2;
    vu0_v4 t3;
    u8 *cam;
    u8 *o;
    u8 *p;
    u8 *hit;
    s32 ret;
    s32 i;
    s32 n;
    s32 k;
    s32 s0;
    s32 flag;
    s32 h;
    f32 best;
    f32 yaw;
    f32 pitch;
    f32 dyaw;
    f32 dist;
    f32 dxy;
    f32 f20;
    f32 f21;
    f32 f;
    f32 g;
    f32 e;
    vu0_v4 *hp;

    cam = *(u8 **)(a0 + 0x68);
    ret = 0;
    best = D_001DDDD4_sda;
    func_003886E8(&t0, D_001A4BE0.ptr[0x25C0 / 4] + 0xE0, 0.5f);
    vec_add_ba(&p20, D_001A4BE0.ptr[0x25C0 / 4] + 0x10, &t0);
    if (func_003CE740(&p20, &v, 6, D_001A4BE0.ptr[0x25C0 / 4], 0) != 0) {
        v = D_L10_001E89A0;
        return 0;
    }
    n = 0;
    i = 0;
    for (o = D_L10_0021C3E0[0]; o != 0; o = D_L10_0021C3E0[++i]) {
        hp = &D_L10_001E89A0;
        if (o[0x20] == 0xFE) {
            continue;
        }
        if (o[0x20] == 0xFD) {
            continue;
        }
        h = *(s16 *)(o + 0xAA);
        if (h == 0x1BC3 || h == 0x189B || h == 0x1D3E || h == 0x1A90) {
            continue;
        }
        q = *(vu0_v4 *)(o + 0x10);
        p = func_0037E0B8(o);
        if (p == 0 || p[0xE] == 3) {
            continue;
        }
        func_003886E8(&t1, o + 0xE0, *(f32 *)(p + 0x10));
        vec_add_ab(&q, &q, &t1);
        if (o == 0 || *(u8 **)(o + 0x24) == 0 || (*(u8 **)(o + 0x24))[0x46] != 5) {
            continue;
        }
        flag = 0;
        yaw = func_00388A28(q.x - v.x, q.y - v.y);
        dxy = func_00388800(&v, &q);
        pitch = func_00388A28(dxy, q.z - v.z);
        dyaw = func_00389468(*a2, yaw);
        dist = func_003887C8(&v, &q);
        if (D_L10_001D673C != 0 || D_001A4BE0.h[0x368 / 2] != 0 || D_001D6740_sda != 0) {
            if (dist < 2.5f) {
                vec_sub_ab(&t2, o + 0x10, D_001A4BE0.ptr[0x25C0 / 4] + 0x10);
                f = func_00388730(&t2, D_001A4BE0.ptr[0x25C0 / 4] + 0xE0);
                if (fabs_asm(f) < 2.0f) {
                    func_003886E8(&t3, D_001A4BE0.ptr[0x25C0 / 4] + 0xE0, f);
                    vec_sub_ab(&t2, &t2, &t3);
                    f20 = func_00388730(&t2, D_001A4BE0.ptr[0x25C0 / 4] + 0xC0);
                    g = func_00388770(&t2);
                    if (g != 0.0f) {
                        if (1.5707964f - func_00388990(f20 / g) < 1.0471976f) {
                            flag = 1;
                        }
                    }
                }
            }
        } else if (dist < 2.5f) {
            if (func_00389468(*(f32 *)(D_001A4BE0.ptr[0x25C0 / 4] + 0xF8),
                              func_00388A28(*(f32 *)(o + 0x10) - D_001A4BE0.f[0x80 / 4],
                                            *(f32 *)(o + 0x14) - D_001A4BE0.f[0x84 / 4])) < 1.0471976f) {
                if (fabs_asm(v.z - q.z) < 2.0f) {
                    flag = 1;
                }
            }
        }
        if (flag != 0) {
            if (func_003CE740(&v, &q, 6, D_001A4BE0.ptr[0x25C0 / 4], 0) == 0) {
                *a3 = -pitch;
                ret = (s32)o;
                *a2 = yaw;
                break;
            }
        }
        if (best < dist && o != *(u8 **)(cam + 0x10)) {
            continue;
        }
        if (D_001DDDD4_sda < dist) {
            continue;
        }
        func_0037E4B8(&t1, dist, *a2, *a3 + D_001A4BE0.f[0x344 / 4] * 0.5f);
        vec_add_ab(&t1, &t1, &v);
        f21 = func_00388990(func_003887C8(&t1, &q) / (dist + dist)) * 2.0f;
        if (D_001DDDD0_sda * 0.017453292f < f21) {
            p = func_0037E0B8(o);
            if (p != 0) {
                f20 = (f32)p[0xA];
                f20 = f20 * 0.125f;
                e = func_00388990(f20 / dist);
                if (f20 < dist) {
                    f21 = f21 - e;
                    if (f21 < 0.0f) {
                        f21 = 0.0f;
                    }
                }
            }
        }
        if (f21 < D_001DDDD0_sda * 0.017453292f) {
            flag = 1;
            t2 = v;
            for (s0 = 0; func_003CE740(&t2, &q, 6, a0, 0) != 0 && ++s0 < 7; ) {
                hit = D_L10_001E8998[0];
                if (hit != 0) {
                    h = *(s16 *)(hit + 0xAA);
                    if (h == 0x1BC3 || h == 0x189B || h == 0x1D3E) {
                        list[n++] = hit;
                        *(s32 *)(hit + 0x98) = 0;
                        if (n >= 0x80) {
                            break;
                        }
                        t2 = *hp;
                        continue;
                    }
                    if (hit == o) {
                        break;
                    }
                }
                flag = 0;
                break;
            }
            if (flag != 0) {
                best = dist;
                *a3 = -pitch;
                if (dyaw < 0.17453292f) {
                    *a2 = yaw;
                }
                ret = (s32)o;
                if (o == *(u8 **)(cam + 0x10)) {
                    return ret;
                }
            }
        }
    }
    for (k = 0; k < n; k++) {
        *(s32 *)(list[k] + 0x98) = *(s32 *)(*(u8 **)(list[k] + 0x24) + 0x10);
    }
    return ret;
}
/* localdecomp:end func_L10_00381840 */
