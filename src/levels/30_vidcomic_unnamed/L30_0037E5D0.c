#include "common.h"

/* localdecomp:start func_L30_0037E5D0 */
#include "vu0.h"
typedef struct {
    u8 pad0[0xA];
    u8 xA;
    u8 padB[0xE - 0xB];
    u8 xE;
    u8 padF;
    f32 x10;
} S_372D20r;

typedef struct {
    u8 pad0[0x10];
    void *x10;
    u8 pad14[0x46 - 0x14];
    u8 x46;
} S_372D20c;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 x20;
    u8 pad21[0x24 - 0x21];
    S_372D20c *x24;
    u8 pad28[0x68 - 0x28];
    void *x68;
    u8 pad6C[0x98 - 0x6C];
    void *x98;
    u8 pad9C[0xAA - 0x9C];
    s16 xAA;
    u8 padAC[0xC0 - 0xAC];
    vu0_v4 xC0;
    vu0_v4 xD0;
    vu0_v4 xE0;
    f32 xF0;
    f32 xF4;
    f32 xF8;
} S_372D20m;

__asm__(".extern D_L30_001DE144, 4");
__asm__(".extern D_L30_001DE140, 4");
extern u8 D_001A4BE0[];
extern f32 D_L30_001DE144;
extern f32 D_L30_001DE140;
extern s32 D_L30_001D673C;
extern s32 D_L30_001D6740;
extern S_372D20m *D_L30_0021C860[];
extern S_372D20m *D_L30_001E9018[];
extern vu0_v4 D_L30_001E9020[];
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern S_372D20r *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);

/* from this repo's func_L36_00384358 (its twin) */
S_372D20m *func_L30_0037E5D0(S_372D20m *self, vu0_v4 *from, f32 *yaw, f32 *pitch) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 to;
    S_372D20m *list[0x80];
    vu0_v4 mpos;
    vu0_v4 v240;
    vu0_v4 v250;
    vu0_v4 v260;
    f32 best;
    void *x68;
    S_372D20m *found;
    S_372D20m *m;
    S_372D20m *o;
    S_372D20r *r;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 flag;
    f32 ay;
    f32 ap;
    f32 dy;
    f32 dist;
    f32 d;
    f32 len;
    f32 a;
    f32 w;
    f32 c;
    vu0_v4 *pp;
    u8 *h1;
    u8 *h2;
    u8 *h3;
    u8 *h4;
    u8 *h5;

    pp = &pos;
    h1 = D_001A4BE0;
    *pp = *from;
    best = D_L30_001DE144;
    x68 = self->x68;
    found = 0;
    func_0038CE20(&off, &(*(S_372D20m **)(h1 + 0x25C0))->xE0, 0.5f);
    vec_add_ba(&to, &(*(S_372D20m **)(h1 + 0x25C0))->pos, &off);
    if (func_003D3CB0(&to, pp, 6, *(S_372D20m **)(h1 + 0x25C0), 0) != 0) {
        *pp = D_L30_001E9020[0];
        return 0;
    }
    n = 0;
    for (i = 0; (m = D_L30_0021C860[i]) != 0; i++) {
        vu0_v4 *hit = D_L30_001E9020;

        if (m->x20 == 0xFE) {
            continue;
        }
        if (m->x20 == 0xFD) {
            continue;
        }
        if (m->xAA == 0x1BC3 || m->xAA == 0x189B || m->xAA == 0x1D3E || m->xAA == 0x1A90) {
            continue;
        }
        mpos = m->pos;
        r = func_00382348(m);
        if (r == 0 || r->xE == 3) {
            continue;
        }
        func_0038CE20(&v240, &m->xE0, r->x10);
        vec_add_ab(&mpos, &mpos, &v240);
        if (m == 0 || m->x24 == 0 || m->x24->x46 != 5) {
            continue;
        }
        flag = 0;
        ay = func_0038D160(mpos.x - pp->x, mpos.y - pp->y);
        ap = func_0038D160(func_0038CF38(pp, &mpos), mpos.z - pp->z);
        dy = func_0038DBA0(*yaw, ay);
        dist = func_0038CF00(pp, &mpos);
        if (D_L30_001D673C != 0 || (h2 = D_001A4BE0, *(s16 *)(h2 + 0x368) != 0) || D_L30_001D6740 != 0) {
            if (dist < 2.5f) {
                h3 = D_001A4BE0;
                vec_sub_ab(&v250, &m->pos, &(*(S_372D20m **)(h3 + 0x25C0))->pos);
                d = func_0038CE68(&v250, &(*(S_372D20m **)(h3 + 0x25C0))->xE0);
                if (__builtin_fabsf(d) < 2.0f) {
                    func_0038CE20(&v260, &(*(S_372D20m **)(h3 + 0x25C0))->xE0, d);
                    vec_sub_ab(&v250, &v250, &v260);
                    w = func_0038CE68(&v250, &(*(S_372D20m **)(h3 + 0x25C0))->xC0);
                    len = func_0038CEA8(&v250);
                    if (len != 0.0f) {
                        if (1.5707964f - func_0038D0C8(w / len) < 1.0471976f) {
                            flag = 1;
                        }
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                if (func_0038DBA0((*(S_372D20m **)(h2 + 0x25C0))->xF8,
                                  func_0038D160(m->pos.x - *(f32 *)(h2 + 0x80),
                                                m->pos.y - *(f32 *)(h2 + 0x84))) < 1.0471976f) {
                    if (__builtin_fabsf(pp->z - mpos.z) < 2.0f) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag != 0 && (h4 = D_001A4BE0, func_003D3CB0(pp, &mpos, 6, *(S_372D20m **)(h4 + 0x25C0), 0) == 0)) {
            *pitch = -ap;
            found = m;
            *yaw = ay;
            break;
        }
        if (best < dist && m != ((S_372D20m **)x68)[4]) {
            continue;
        }
        if (D_L30_001DE144 < dist) {
            continue;
        }
        h5 = D_001A4BE0;
        func_00382760(&v240, dist, *yaw, *pitch + *(f32 *)(h5 + 0x344) * 0.5f);
        vec_add_ab(&v240, &v240, pp);
        a = func_0038D0C8(func_0038CF00(&v240, &mpos) / (dist + dist));
        a = a + a;
        if (D_L30_001DE140 * 0.017453292f < a) {
            r = func_00382348(m);
            if (r != 0) {
                w = r->xA;
                w *= 0.125f;
                c = func_0038D0C8(w / dist);
                if (w < dist) {
                    a -= c;
                    if (a < 0.0f) {
                        a = 0.0f;
                    }
                }
            }
        }
        if (!(a < D_L30_001DE140 * 0.017453292f)) {
            continue;
        }
        flag = 1;
        v250 = *pp;
        j = 0;
        while (func_003D3CB0(&v250, &mpos, 6, self, 0) != 0 && ++j < 7) {
            o = D_L30_001E9018[0];
            if (o != 0) {
                if (o->xAA == 0x1BC3 || o->xAA == 0x189B || o->xAA == 0x1D3E) {
                    list[n++] = o;
                    o->x98 = 0;
                    if (n >= 0x80) {
                        break;
                    }
                    v250 = *hit;
                    continue;
                }
                if (o == m) {
                    break;
                }
            }
            flag = 0;
            break;
        }
        if (flag != 0) {
            *pitch = -ap;
            best = dist;
            if (dy < 0.17453292f) {
                *yaw = ay;
            }
            found = m;
            if (m == ((S_372D20m **)x68)[4]) {
                return found;
            }
        }
    }
    for (k = 0; k < n; k++) {
        list[k]->x98 = list[k]->x24->x10;
    }
    return found;
}
/* localdecomp:end func_L30_0037E5D0 */
