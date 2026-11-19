#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_0038F7E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_38F7E8;
__asm__(".extern D_L04_001DDD20, 4");
__asm__(".extern D_L04_001DDD24, 4");
__asm__(".extern D_L04_001D6740, 4");
extern f32 D_L04_001DDD20;
extern f32 D_L04_001DDD24;
extern s32 D_L04_001D6740;
extern s32 D_L04_001D673C;
extern V4_38F7E8 D_L04_001E95A0;
extern u8 *D_L04_001E9598[];
extern u8 *D_L04_0021D3E0[];
typedef struct {
    u8 pad0[0x80];
    f32 x80;
    f32 x84;
    u8 pad88[0x344 - 0x88];
    f32 x344;
    u8 pad348[0x368 - 0x348];
    s16 x368;
    u8 pad36A[0x25C0 - 0x36A];
    u8 *x25C0;
} H_38F7E8;
extern H_38F7E8 D_001A4BE0;
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);

u8 *func_L04_0038F7E8(u8 *m, V4_38F7E8 *in, f32 *yaw, f32 *pitch) {
    V4_38F7E8 pos;
    V4_38F7E8 *pp = &pos;
    V4_38F7E8 dir;
    V4_38F7E8 eye;
    u8 *list[128];
    V4_38F7E8 q;
    V4_38F7E8 o;
    V4_38F7E8 u;
    V4_38F7E8 w;
    u8 *v;
    u8 *res;
    u8 *e;
    u8 *t;
    s32 i;
    s32 n;
    s32 cnt;
    s32 st;
    s32 ok;
    f32 range;
    f32 ay;
    f32 ap;
    f32 dy;
    f32 dist;
    f32 f;
    f32 a;
    f32 g;

    range = D_L04_001DDD24;
    *pp = *in;
    v = *(u8 **)(m + 0x68);
    res = 0;
    func_0038CE20(&dir, D_001A4BE0.x25C0 + 0xE0, 0.5f);
    vec_add_ba(&eye, D_001A4BE0.x25C0 + 0x10, &dir);
    if (func_003D3CB0(&eye, pp, 6, D_001A4BE0.x25C0, 0) != 0) {
        *pp = D_L04_001E95A0;
        return 0;
    }
    cnt = 0;
    for (i = 0; (e = D_L04_0021D3E0[i]) != 0; i++) {
        V4_38F7E8 *z = &D_L04_001E95A0;

        st = e[0x20];
        if (st == 0xFE) {
            continue;
        }
        if (st == 0xFD) {
            continue;
        }
        if (*(s16 *)(e + 0xAA) == 0x1BC3 || *(s16 *)(e + 0xAA) == 0x189B || *(s16 *)(e + 0xAA) == 0x1D3E ||
            *(s16 *)(e + 0xAA) == 0x1A90) {
            continue;
        }
        q = *(V4_38F7E8 *)(e + 0x10);
        t = func_00382348(e);
        if (t == 0 || t[0xE] == 3) {
            continue;
        }
        func_0038CE20(&o, e + 0xE0, *(f32 *)(t + 0x10));
        vec_add_ab(&q, &q, &o);
        if (e == 0 || *(u8 **)(e + 0x24) == 0 || (*(u8 **)(e + 0x24))[0x46] != 5) {
            continue;
        }
        ok = 0;
        ay = func_0038D160(q.x - pp->x, q.y - pp->y);
        ap = func_0038D160(func_0038CF38(pp, &q), q.z - pp->z);
        dy = func_0038DBA0(*yaw, ay);
        dist = func_0038CF00(pp, &q);
        if (D_L04_001D673C != 0 || D_001A4BE0.x368 != 0 || D_L04_001D6740 != 0) {
            if (dist < 2.5f) {
                f32 d0;
                vec_sub_ab(&u, e + 0x10, D_001A4BE0.x25C0 + 0x10);
                d0 = func_0038CE68(&u, D_001A4BE0.x25C0 + 0xE0);
                if (__builtin_fabsf(d0) < 2.0f) {
                    func_0038CE20(&w, D_001A4BE0.x25C0 + 0xE0, d0);
                    vec_sub_ab(&u, &u, &w);
                    f = func_0038CE68(&u, D_001A4BE0.x25C0 + 0xC0);
                    {
                        f32 d1 = func_0038CEA8(&u);
                        if (d1 != 0.0f && 1.5707964f - func_0038D0C8(f / d1) < 1.0471976f) {
                            ok = 1;
                        }
                    }
                }
            }
        } else if (dist < 2.5f) {
            u8 *c = D_001A4BE0.x25C0;
            a = func_0038D160(*(f32 *)(e + 0x10) - D_001A4BE0.x80, *(f32 *)(e + 0x14) - D_001A4BE0.x84);
            if (func_0038DBA0(*(f32 *)(c + 0xF8), a) < 1.0471976f && __builtin_fabsf(pp->z - q.z) < 2.0f) {
                ok = 1;
            }
        }
        if (ok != 0 && func_003D3CB0(pp, &q, 6, D_001A4BE0.x25C0, 0) == 0) {
            res = e;
            *pitch = -ap;
            *yaw = ay;
            break;
        }
        if (range < dist && e != *(u8 **)(v + 0x10)) {
            continue;
        }
        if (D_L04_001DDD24 < dist) {
            continue;
        }
        func_00382760(&o, dist, *yaw, *pitch + D_001A4BE0.x344 * 0.5f);
        vec_add_ab(&o, &o, pp);
        a = func_0038D0C8(func_0038CF00(&o, &q) / (dist + dist));
        a = a + a;
        if (D_L04_001DDD20 * 0.017453292f < a) {
            t = func_00382348(e);
            if (t != 0) {
                f = (f32)t[0xA];
                f = f * 0.125f;
                g = func_0038D0C8(f / dist);
                if (f < dist) {
                    a = a - g;
                    if (a < 0.0f) {
                        a = 0.0f;
                    }
                }
            }
        }
        if (a < D_L04_001DDD20 * 0.017453292f) {
            ok = 1;
            u = *pp;
            for (n = 0; func_003D3CB0(&u, &q, 6, m, 0) != 0; ) {
                if (++n >= 7) {
                    break;
                }
                t = D_L04_001E9598[0];
                if (t != 0) {
                    if (*(s16 *)(t + 0xAA) == 0x1BC3 || *(s16 *)(t + 0xAA) == 0x189B || *(s16 *)(t + 0xAA) == 0x1D3E) {
                        list[cnt++] = t;
                        *(s32 *)(t + 0x98) = 0;
                        if (cnt >= 0x80) {
                            break;
                        }
                        u = *z;
                        continue;
                    }
                    if (t == e) {
                        break;
                    }
                }
                ok = 0;
                break;
            }
            if (ok != 0) {
                *pitch = -ap;
                range = dist;
                if (dy < 0.17453292f) {
                    *yaw = ay;
                }
                res = e;
                if (e == *(u8 **)(v + 0x10)) {
                    return res;
                }
            }
        }
    }
    {
        s32 k;
        for (k = 0; k < cnt; k++) {
            *(s32 *)(list[k] + 0x98) = *(s32 *)(*(u8 **)(list[k] + 0x24) + 0x10);
        }
    }
    return res;
}
/* localdecomp:end func_L04_0038F7E8 */
