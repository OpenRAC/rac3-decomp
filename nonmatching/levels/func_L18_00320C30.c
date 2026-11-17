/* near miss (levels 18 20 26 29): func_L18_00320C30, 0x82C, written from retail by e12 (2026-11-17): 68 aligned
 * rows, all scheduling/allocation (the structure matches). Needs the file line
 * "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (the file holds only this function;
 * li.s as lui/ori needs @ps2as, the vector helpers need the vu0 flag). Found so far: the retry loop is a goto loop
 * (entry jumps into the body, the 0.1f test above it, `goto top` after a hit: 88 -> 73); q/r/h and the collision
 * record in separate blocks one level deeper than their statements (frame 0x170 -> 0x140, record at 0x70);
 * literals 0.16000001f, 0.060000002f, 0.120000005f, 0.037699115f, 0.020000001f; func_L01_004637C8 returns a
 * value (v1 for the following lq). Left: the vadd in the loop allocates vf1/vf2 the other way, `v44 *= 0.7f`
 * gets f0/f1 swapped, the h/m+0xF0/m+0x10 pointers take s0/s1/s2 in another order, the record's field stores and
 * func_L01_0044AF78's argument set-up are scheduled differently. */
#include "common.h"

#include "vu0.h"

typedef struct {
    u8 p0[0x18];
    u8 *hit;
    s32 n1C;
    vu0_v4 pos;
    u8 p30[0x10];
    vu0_v4 nrm;
} C_00320C30;

typedef struct {
    vu0_v4 dir;
    s32 w10;
    s32 w14;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 w20;
    u8 p24[4];
    s32 w28;
} Q_00320C30;

extern C_00320C30 D_L18_001EAA80;

extern f32 func_0038D160(f32, f32);
extern f32 func_L18_00457C10(f32, f32, f32, f32, f32, f32 *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32,
                              s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern s32 func_0013D3E0(void);

void func_L18_00320C30(u8 *m) {
    u8 *v;
    vu0_v4 save;
    vu0_v4 n;
    vu0_v4 w;
    vu0_v4 e;
    vu0_v4 d;
    s32 hit;
    f32 t, c;

    if (m == 0) {
        return;
    }
    v = *(u8 **)(m + 0x68);
    if (v == 0) {
        return;
    }
    *(vu0_q *)&n = 0;
    n.z = 0.16000001f;
    *(f32 *)(m + 0x2C) += (*(f32 *)(*(u8 **)(m + 0x24) + 0x24) - *(f32 *)(m + 0x2C)) * 0.060000002f;
    *(f32 *)(v + 0x38) += (1.2f - *(f32 *)(v + 0x38)) * 0.120000005f * 1.44f;
    vec_sub_ab(&d, v + 0x10, m + 0x10);
    if (*(s32 *)(v + 0x34) < 0xCC) {
        f32 len;
        *(f32 *)(m + 0xF8) = func_L18_00457C10(*(f32 *)(m + 0xF8), func_0038D160(d.x, d.y), 0.037699115f, 0.0f, 0.0f,
                                               (f32 *)(v + 0x3C));
        len = func_0038CED8(&d);
        *(f32 *)(m + 0xF4) = func_L18_00457C10(*(f32 *)(m + 0xF4), -func_0038D160(len, d.z), 0.037699115f, 0.0f, 0.0f,
                                               (f32 *)(v + 0x40));
        vec_sub_ab(&d, v + 0x10, v + 0x20);
        len = func_0038CEA8(&d);
        if (len < 6.0f) {
            *(f32 *)(v + 0x44) *= len / 6.0f;
        } else {
            *(f32 *)(v + 0x44) += 0.120000005f;
        }
    }
    {
        vu0_v4 q;
        vu0_v4 r;
        f32 h[16];
        {
            func_00382760(&e, *(f32 *)(v + 0x38), *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            *(vu0_q *)&r = 0;
            r.x = func_003824E0(-1.0f, 1.0f);
            r.y = func_003824E0(-1.0f, 1.0f);
            r.z = func_003824E0(-1.0f, 1.0f);
            q = r;
            func_0038CF68(&q, &q, func_003824E0(0.1f, 0.2f) * 0.020000001f);
            func_0038CF68(&w, &e, -func_003824E0(0.002f, 0.020000001f));
            vec_add_ba(&q, &q, &w);
            func_0038CF68(&w, &e, func_003824E0(0.0f, 1.0f) * *(f32 *)(v + 0x38));
            vec_add_ab(&w, &w, m + 0x10);
            {
                s32 life = (func_00382498(0x1C, 0x28) * 5 + 2) / 6;
                func_L01_004637C8(&w, &q, 0x6F00AFFF, 0x100000FF, life, 0x28, func_00382498(0x28, 0x46), 1);
            }
            save = *(vu0_v4 *)(m + 0x10);
            vec_add_ba(v + 0x20, v + 0x20, &e);
            *(f32 *)(v + 0x48) = func_0038DAB8(*(f32 *)(v + 0x48), *(f32 *)(v + 0x50));
            *(f32 *)(v + 0x4C) = func_0038DAB8(*(f32 *)(v + 0x4C), *(f32 *)(v + 0x54));
            *(f32 *)(v + 0x48) = func_0038DAB8(*(f32 *)(v + 0x48), func_0038D0B0(*(f32 *)(v + 0x4C)) * 0.075f);
            if (0.7f < *(f32 *)(v + 0x44)) {
                *(f32 *)(v + 0x44) = 0.7f;
            }
            hit = 0;
            goto body;
        top:
            if (!(0.1f < *(f32 *)(v + 0x44))) {
                goto done;
            }
        body:
            t = func_0038D0B0(*(f32 *)(v + 0x48));
            c = func_0038D098(*(f32 *)(v + 0x4C));
            q.y = *(f32 *)(v + 0x44) * t * c;
            t = func_0038D098(*(f32 *)(v + 0x48));
            c = func_0038D098(*(f32 *)(v + 0x4C));
            {
                f32 z = 0.0f;
                q.x = z;
                q.w = z;
            }
            q.z = *(f32 *)(v + 0x44) * t * c;
            func_0038D328(h, m + 0xF0);
            func_0038D028(&q, &q, h);
            vec_add_ba(m + 0x10, v + 0x20, &q);
            if (func_003D3CB0(&save, m + 0x10, 6, *(void **)(v + 0x30), 0) != 0) {
                *(f32 *)(v + 0x44) *= 0.7f;
                hit = 1;
                goto top;
            }
        done:
            if (hit) {
                *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)(m + 0x10) - save.x, *(f32 *)(m + 0x14) - save.y);
                *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CF38(&save, m + 0x10), *(f32 *)(m + 0x18) - save.z);
                *(s32 *)(v + 0x3C) = 0;
                *(s32 *)(v + 0x40) = 0;
            }
        }
    }
    if (*(f32 *)(m + 0x10) < 0.0f || *(f32 *)(m + 0x14) < 0.0f || *(f32 *)(m + 0x18) < 0.0f) {
        func_003C2880(m);
        return;
    }
    {
        Q_00320C30 rec;
        {
        rec.w10 = *(s32 *)(v + 0x30);
        rec.w14 = 0x1030001;
        rec.dir = e;
        rec.f1C = *(f32 *)(v + 0x5C);
        rec.w20 = 1;
        func_0038CFB8(&rec, &rec, 1.0f);
        rec.b19 = 3;
        rec.dir.w = 5627.9248f;
        rec.h1A = *(u16 *)(m + 0xAA);
        rec.dir.z = 1.0f;
        rec.b18 = 3;
        rec.w28 = *(s32 *)(v + 0x60);
        if (func_003D3CB0(&save, m + 0x10, 0, *(void **)(v + 0x30), &rec) != 0) {
            C_00320C30 *cr = &D_L18_001EAA80;
            if (cr->hit != 0) {
                if (cr->hit == *(u8 **)(v + 0x30) || *(s16 *)(cr->hit + 0xAA) == 0x1092) {
                    goto rnd;
                }
                m[0xBC] = 2;
                *(vu0_v4 *)(m + 0x10) = cr->pos;
                func_L01_0040E790(&n, &e, &cr->nrm);
                func_0038CF68(&n, &n, 0.040000003f);
                func_L01_0044AF78(m, &n, 0, 0.0f, 0.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 10, 3, 9, 0, 1, 1, -1, 0,
                                  0x1010001);
            } else {
                if (cr->n1C <= 0) {
                    goto rnd;
                }
                m[0xBC] = 1;
                *(vu0_v4 *)(m + 0x10) = cr->pos;
                func_L01_0040E790(&n, &e, &cr->nrm);
                func_0038CF68(&n, &n, 0.040000003f);
                func_L01_0044AF78(m, &n, 0, 0.0f, *(f32 *)(v + 0x5C), 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 10, 3, 9, 0, 1, 1,
                                  -1, 0, 0x1010001);
            }
            func_003C2880(m);
            return;
        }
        }
    }
    if (func_0038CAD0(v + 0x34) != 0) {
        func_003C2880(m);
        return;
    }
rnd:
    if (*(s32 *)(v + 0x34) % 0x1B == 0) {
        if (func_0013D3E0() & 1) {
            *(f32 *)(v + 0x50) *= func_003824E0(-0.7f, -1.5f);
        }
        if (func_0013D3E0() & 1) {
            *(f32 *)(v + 0x54) *= func_003824E0(-0.6f, -1.6f);
        }
    }
}
