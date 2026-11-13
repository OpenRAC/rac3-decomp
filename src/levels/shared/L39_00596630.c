#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00596630);

/* localdecomp:start func_L39_00596A08 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00596A08;
typedef struct { u8 pad0[0x46]; u8 b46; } P_00596A08;
typedef struct M_00596A08 {
    u8 pad0[0x10];
    V_00596A08 pos;
    u8 pad20[4];
    P_00596A08 *p24;
    u8 pad28[9];
    u8 b31;
    u8 pad32[0x66];
    void *p98;
    u8 pad9C[0xE];
    s16 hAA;
    u8 padAC[0x14];
    u8 mC0[0x40];
} M_00596A08;
typedef struct {
    V_00596A08 dir;
    u8 pad10[0x20];
    V_00596A08 pos;
    u8 pad40[0x3C];
    f32 f7C;
    u8 pad80[0xC];
    M_00596A08 *target;
    V_00596A08 v90;
    V_00596A08 vA0;
    f32 fB0;
    u8 padB4[8];
    M_00596A08 *self;
    u8 padC0[0x24];
    void (*fE4)(void *);
    u8 padE8[0x28];
    V_00596A08 v110;
    f32 f120;
    u8 pad124[8];
    s32 i12C;
} O_00596A08;
typedef struct { u8 pad0[0x18]; M_00596A08 *f18; u8 pad1C[4]; V_00596A08 v20; } S_00596A08;
typedef struct { u8 pad0[0x424]; f32 f424; u8 pad428[0x38]; } C_00596A08;
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_005B8928(void *);
extern f32 func_0038D098(f32);
extern u8 *func_00382348(void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern S_00596A08 D_L39_0025F740;
extern C_00596A08 D_L39_0024DE80[];
extern M_00596A08 *D_L39_00292C20[];

void func_L39_00596A08(O_00596A08 *o) {
    V_00596A08 v0;
    M_00596A08 *mobys[16];
    V_00596A08 vecs[16];
    f32 fracs[16];
    V_00596A08 p;
    V_00596A08 d;
    M_00596A08 *prev;
    M_00596A08 *m;
    u8 *r;
    f32 cosmax;
    f32 best;
    f32 dist;
    f32 len;
    f32 dot;
    f32 frac;
    s32 n;
    s32 i;

    if (o->fE4 != 0) {
        o->fE4(o);
        return;
    }
    prev = o->target;
    o->target = 0;
    o->fB0 = 0.0f;
    func_0038CF68(&v0, &o->dir, o->f120);
    vec_add_ab(&v0, &v0, &o->pos);
    if (func_003D3CB0(&o->pos, &v0, 0, o->self, 0) != 0) {
        M_00596A08 *t = D_L39_0025F740.f18;
        if (t != 0 && t->p24 != 0 && t->p24->b46 == 5 && t->hAA != 0x19C0 && t->hAA != 0x1AE6) {
            o->target = t;
            o->fB0 = 1.0f;
        }
        *(vu0_q *)&o->v110 = *(vu0_q *)&D_L39_0025F740.v20;
    } else {
        o->v110 = v0;
    }
    if (o->target != 0 && func_L39_005B8928(o->target) != 0) {
        o->target = 0;
        o->v110 = v0;
    }
    if (o->target == 0) {
        n = 0;
        best = 37000000.0f;
        cosmax = func_0038D098(o->f7C * (((C_00596A08 *)(o->i12C * 0x460 + (s32)D_L39_0024DE80))->f424 / 1.1100293f));
        for (i = 0; (m = D_L39_00292C20[i]) != 0; i++) {
            if (m->b31 == 0) continue;
            if (m->p24 == 0) continue;
            if (m->p24->b46 != 5) continue;
            if (m->p98 == 0) continue;
            if (m == o->self) continue;
            if (m->hAA == 0x19C0) continue;
            if (m->hAA == 0x1AE6) continue;
            r = func_00382348(m);
            if (r == 0) continue;
            *(vu0_q *)&d = 0;
            d.z = *(f32 *)(r + 0x10);
            p = d;
            func_0038D000(&p, &p, m->mC0);
            vec_add_ab(&p, &p, &m->pos);
            vec_sub_ab(&d, &p, &o->pos);
            dist = func_0038CEA8(&d);
            if (o->f120 < dist) continue;
            func_0038CE20(&d, &d, 1.0f / dist);
            dot = func_0038CE68(&d, &o->dir);
            if (dot < cosmax) continue;
            frac = (dot - cosmax) / (1.0f - cosmax);
            len = dist + dist * frac;
            if (func_L39_005B8928(m) != 0) continue;
            if (func_L39_005B8928(m) != 0) {
                len += 10.0f;
            }
            if (len < best) {
                best = len;
                mobys[n] = m;
                *(vu0_q *)&vecs[n] = *(vu0_q *)&p;
                fracs[n] = frac;
                n++;
                if (n >= 16) break;
            }
        }
        for (i = n - 1; i >= 0; i--) {
            if (func_003D3CB0(&o->pos, &vecs[i], 0, o->self, 0) == 0 || D_L39_0025F740.f18 == mobys[i]) {
                o->target = mobys[i];
                o->fB0 = fracs[i];
                break;
            }
        }
    }
    if (o->target != 0) {
        if (o->target == prev) {
            vec_sub_ab(&o->vA0, &o->target->pos, &o->v90);
        }
        o->v90 = o->target->pos;
    } else {
        qzero(&o->vA0);
    }
}
/* localdecomp:end func_L39_00596A08 */
