#include "common.h"

/* NTSC-U counterpart of func_L35_0037CAB8 (src/levels/35_vidcomic_5/L35_0037CAB8.c) */
/* localdecomp:start func_L35_0037B7C8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0xA];
    u8 xA;
    u8 padB[0xE - 0xB];
    u8 xE;
    u8 padF;
    f32 x10;
} S_37CAB8r;

typedef struct {
    u8 pad0[0x10];
    void *x10;
    u8 pad14[0x46 - 0x14];
    u8 x46;
} S_37CAB8c;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 x20;
    u8 pad21[0x24 - 0x21];
    S_37CAB8c *x24;
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
} S_37CAB8m;

__asm__(".extern D_L35_001DE0C4, 4");
__asm__(".extern D_L35_001DE0C0, 4");
extern u8 D_001A4BE0[];
extern f32 D_L35_001DE0C4;
extern f32 D_L35_001DE0C0;
extern s32 D_L35_001D673C_0037B7C8;
extern s32 D_L35_001D6740_0037B7C8;
extern S_37CAB8m *D_L35_0021CAA0[];
extern S_37CAB8m *D_L35_001E9358[];
extern vu0_v4 D_L35_001E9360[];
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern S_37CAB8r *func_0037E0B8(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00389468(f32, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_00388990(f32);
extern void func_0037E4B8(void *, f32, f32, f32);

/* from its matched twin func_L36_00384358 (itself from the draft of func_L28_0036CF48) */
S_37CAB8m *func_L35_0037B7C8(S_37CAB8m *self, vu0_v4 *from, f32 *yaw, f32 *pitch) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 to;
    S_37CAB8m *list[0x80];
    vu0_v4 mpos;
    vu0_v4 v240;
    vu0_v4 v250;
    vu0_v4 v260;
    f32 best;
    void *x68;
    S_37CAB8m *found;
    S_37CAB8m *m;
    S_37CAB8m *o;
    S_37CAB8r *r;
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
    best = D_L35_001DE0C4;
    x68 = self->x68;
    found = 0;
    func_003886E8(&off, &(*(S_37CAB8m **)(h1 + 0x25C0))->xE0, 0.5f);
    vec_add_ba(&to, &(*(S_37CAB8m **)(h1 + 0x25C0))->pos, &off);
    if (func_003CE740(&to, pp, 6, *(S_37CAB8m **)(h1 + 0x25C0), 0) != 0) {
        *pp = D_L35_001E9360[0];
        return 0;
    }
    n = 0;
    for (i = 0; (m = D_L35_0021CAA0[i]) != 0; i++) {
        vu0_v4 *hit = D_L35_001E9360;

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
        r = func_0037E0B8(m);
        if (r == 0 || r->xE == 3) {
            continue;
        }
        func_003886E8(&v240, &m->xE0, r->x10);
        vec_add_ab(&mpos, &mpos, &v240);
        if (m == 0 || m->x24 == 0 || m->x24->x46 != 5) {
            continue;
        }
        flag = 0;
        ay = func_00388A28(mpos.x - pp->x, mpos.y - pp->y);
        ap = func_00388A28(func_00388800(pp, &mpos), mpos.z - pp->z);
        dy = func_00389468(*yaw, ay);
        dist = func_003887C8(pp, &mpos);
        if (D_L35_001D673C_0037B7C8 != 0 || (h2 = D_001A4BE0, *(s16 *)(h2 + 0x368) != 0) || D_L35_001D6740_0037B7C8 != 0) {
            if (dist < 2.5f) {
                h3 = D_001A4BE0;
                vec_sub_ab(&v250, &m->pos, &(*(S_37CAB8m **)(h3 + 0x25C0))->pos);
                d = func_00388730(&v250, &(*(S_37CAB8m **)(h3 + 0x25C0))->xE0);
                if (__builtin_fabsf(d) < 2.0f) {
                    func_003886E8(&v260, &(*(S_37CAB8m **)(h3 + 0x25C0))->xE0, d);
                    vec_sub_ab(&v250, &v250, &v260);
                    w = func_00388730(&v250, &(*(S_37CAB8m **)(h3 + 0x25C0))->xC0);
                    len = func_00388770(&v250);
                    if (len != 0.0f) {
                        if (1.5707964f - func_00388990(w / len) < 1.0471976f) {
                            flag = 1;
                        }
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                if (func_00389468((*(S_37CAB8m **)(h2 + 0x25C0))->xF8,
                                  func_00388A28(m->pos.x - *(f32 *)(h2 + 0x80),
                                                m->pos.y - *(f32 *)(h2 + 0x84))) < 1.0471976f) {
                    if (__builtin_fabsf(pp->z - mpos.z) < 2.0f) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag != 0 && (h4 = D_001A4BE0, func_003CE740(pp, &mpos, 6, *(S_37CAB8m **)(h4 + 0x25C0), 0) == 0)) {
            *pitch = -ap;
            found = m;
            *yaw = ay;
            break;
        }
        if (best < dist && m != ((S_37CAB8m **)x68)[4]) {
            continue;
        }
        if (D_L35_001DE0C4 < dist) {
            continue;
        }
        h5 = D_001A4BE0;
        func_0037E4B8(&v240, dist, *yaw, *pitch + *(f32 *)(h5 + 0x344) * 0.5f);
        vec_add_ab(&v240, &v240, pp);
        a = func_00388990(func_003887C8(&v240, &mpos) / (dist + dist));
        a = a + a;
        if (D_L35_001DE0C0 * 0.017453292f < a) {
            r = func_0037E0B8(m);
            if (r != 0) {
                w = r->xA;
                w *= 0.125f;
                c = func_00388990(w / dist);
                if (w < dist) {
                    a -= c;
                    if (a < 0.0f) {
                        a = 0.0f;
                    }
                }
            }
        }
        if (!(a < D_L35_001DE0C0 * 0.017453292f)) {
            continue;
        }
        flag = 1;
        v250 = *pp;
        j = 0;
        while (func_003CE740(&v250, &mpos, 6, self, 0) != 0 && ++j < 7) {
            o = D_L35_001E9358[0];
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
            if (m == ((S_37CAB8m **)x68)[4]) {
                return found;
            }
        }
    }
    for (k = 0; k < n; k++) {
        list[k]->x98 = list[k]->x24->x10;
    }
    return found;
}
/* localdecomp:end func_L35_0037B7C8 */
