#include "common.h"

/* localdecomp:start func_L01_003E21C8 */
typedef int s128_3E0480 __attribute__((mode(TI)));

typedef struct M_003E0480 {
    u8 p0[0x10];
    s128_3E0480 x10;
    u8 p20[0x10];
    u8 x30;
    u8 x31;
    u8 p32[2];
    u16 x34;
    u8 p36[0x68 - 0x36];
    void *x68;
    u8 p6C[0xB8 - 0x6C];
    struct M_003E0480 *xB8;
    u8 pBC[4];
    u8 xC0[0x30];
    s128_3E0480 xF0;
} M_003E0480;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 p10[0x10];
    M_003E0480 *x20[4];
    s32 x30[4];
    s32 x40[4];
} V_003E0480;

extern M_003E0480 *func_003C24B0(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_004450F0(M_003E0480 *, s32, s32);
extern s32 func_L01_0044E7D8(M_003E0480 *);
extern void func_0038D308(void *, void *);
extern M_003E0480 **func_L01_00448FB8(M_003E0480 *);
extern void func_L01_003E2418(M_003E0480 *, V_003E0480 *);

s32 func_L01_003E21C8(M_003E0480 *m, s128_3E0480 *pos, s128_3E0480 *rot, M_003E0480 **list, s32 n) {
    M_003E0480 *o;
    V_003E0480 *v;
    M_003E0480 *e;
    M_003E0480 **l;
    s32 i;
    s32 j;

    o = func_003C24B0(7721, 128);
    if (o != 0) {
        v = o->x68;
        func_0038CB78(v, 0, 80);
        v->x8 = 0;
        func_L01_004450F0(o, 1, -1);
        o->xB8 = m;
        o->x30 = 255;
        o->x10 = *pos;
        v->x0 = m->x34;
        v->x4 = func_L01_0044E7D8(m);
        m->x10 = *pos;
        m->xF0 = *rot;
        func_0038D308(m->xC0, &m->xF0);
        if (n >= 5) {
            n = 4;
        }
        m->x31 = 0;
        m->x34 |= 1;
        v->xC = n;
        for (i = 0; i < n; i++) {
            e = list[i];
            v->x20[i] = e;
            v->x30[i] = e->x34;
            v->x40[i] = func_L01_0044E7D8(e);
            e->x31 = 0;
            e->x34 |= 1;
        }
        if (v->xC < 4) {
            l = func_L01_00448FB8(m);
            if (l != 0) {
                for (j = 0; j < 4; j++) {
                    if (l[j] != 0) {
                        e = l[j];
                        v->x20[v->xC] = e;
                        v->x30[v->xC] = e->x34;
                        v->x40[v->xC] = func_L01_0044E7D8(e);
                        e->x31 = 0;
                        e->x34 |= 1;
                        if (++v->xC == 4) {
                            break;
                        }
                    }
                }
            }
        }
        func_L01_003E2418(o, v);
        return 1;
    }
    m->x10 = *pos;
    m->xF0 = *rot;
    func_0038D308(m->xC0, &m->xF0);
    m->x31 = 1;
    m->x34 &= ~1;
    return 0;
}
/* localdecomp:end func_L01_003E21C8 */

/* localdecomp:start func_L01_003E2418 */
#include "vu0.h"
typedef struct { f32 x, y, z, radius; f32 x2, y2, z2, kind; } Bound_003E2418;
void func_L01_003E2418(M_003E0480 *m, V_003E0480 *v) {
    extern s32 func_003C2B88(M_003E0480 *, s32);
    extern f32 func_L01_0040E570(void *, void *);
    vu0_v4 position;
    Bound_003E2418 *p;
    s32 n;
    f32 height, radius, d, r;
    s32 left;
    *(f32 *)((u8 *)v + 0x10) = 0.5f;
    *(f32 *)((u8 *)v + 0x14) = 0.5f;
    n = func_003C2B88(m->xB8, 0);
    if (n == 0) return;
    position = *(vu0_v4 *)&m->xB8->x10;
    p = (Bound_003E2418 *)0x70000000;
    radius = 0.010000000707805f;
    height = 0.1f;
    if (n > 0) {
    left = n;
    do {
        if (p->kind == 0.0f) {
            d = func_L01_0040E570((void *)p, &position);
            r = p->radius;
            d += r * r;
            if (radius < d) radius = d;
            d = fabs_asm(p->z - position.z) + r;
            if (height < d) height = d;
        } else {
            d = func_L01_0040E570((void *)p, &position);
            r = p->radius;
            d += r * r;
            if (radius < d) radius = d;
            d = fabs_asm(p->z - position.z) + r;
            if (height < d) height = d;
            d = func_L01_0040E570((u8 *)p + 0x10, &position);
            r = p->radius;
            d += r * r;
            if (radius < d) radius = d;
            d = fabs_asm(p->z2 - position.z) + r;
            if (height < d) height = d;
        }
        p++;
    } while (--left);
    }
    *(f32 *)((u8 *)v + 0x10) = height;
    *(f32 *)((u8 *)v + 0x14) = sqrt_asm(radius);
}
/* localdecomp:end func_L01_003E2418 */
