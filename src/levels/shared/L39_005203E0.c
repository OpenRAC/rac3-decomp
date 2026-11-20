#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* declared by functions of L39_0051F740.c, which this file was cut from */
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_005203E0(char *);
extern void func_L39_00520630(char *);

/* localdecomp:start func_L39_005203E0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V_005203E0 __attribute__((aligned(16)));
typedef struct {
    V_005203E0 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_005203E0;
extern s32 D_L39_0024A978;
extern s32 D_L39_0024A97C;
extern s32 D_L39_0024A980;
extern s32 D_L39_0024A984;
extern s32 D_L39_0024A988;
extern s32 D_L39_0024A98C;
extern s32 D_L39_0024A990;
extern f32 D_L39_0024A994;
__asm__(".extern D_L39_0024A978, 4");
__asm__(".extern D_L39_0024A97C, 4");
__asm__(".extern D_L39_0024A980, 4");
__asm__(".extern D_L39_0024A984, 4");
__asm__(".extern D_L39_0024A988, 4");
__asm__(".extern D_L39_0024A98C, 4");
__asm__(".extern D_L39_0024A990, 4");
__asm__(".extern D_L39_0024A994, 4");
extern s16 D_L39_0046FB30[][4][2];
extern V_005203E0 D_L39_0046F630_005203E0[];
extern f32 D_L39_0046FF30[][2];
extern unsigned long func_L39_00589890(int);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern void func_L39_005BC330(void *, void *, s32);

void func_L39_005203E0(char *obj)
{
    S_005203E0 s;
    V_005203E0 mtx[3];
    V_005203E0 pos;
    char *data = *(char **)(obj + 0x68);
    s32 i;
    s32 j;
    s32 c;
    s32 k;

    s.x78 = func_L39_00589890(D_L39_0024A98C);
    s.x88 = D_L39_0024A978 | ((long)D_L39_0024A97C << 2) | ((long)D_L39_0024A980 << 4)
          | ((long)D_L39_0024A984 << 6) | ((long)D_L39_0024A988 << 32);
    s.x80 = 0xFF9000000260L;
    s.x70 = 0;
    qzero(&mtx[0]);
    qzero(&mtx[1]);
    qzero(&mtx[2]);
    mtx[0].x = *(f32 *)(data + 0x10) * 2.0f;
    mtx[1].y = *(f32 *)(data + 0x10) * 2.0f;
    mtx[2].z = *(f32 *)(data + 0x10) * 0.25f;
    c = D_L39_0024A990 + (*(s32 *)(data + 0x24) << 24);
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    func_L39_005BC330(obj + 0x10, &pos, 1);
    func_0038CE20(&pos, &pos, 0.25f);
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 4; j++) {
            k = D_L39_0046FB30[i][j][1];
            func_0038CE20(&s.m[j], &D_L39_0046F630_005203E0[D_L39_0046FB30[i][j][0]], D_L39_0024A994);
            s.uv[j][0] = D_L39_0046FF30[k][0];
            s.uv[j][1] = D_L39_0046FF30[k][1];
            func_0038D000(&s.m[j], &s.m[j], mtx);
            func_0038D000(&s.m[j], &s.m[j], obj + 0xC0);
            vec_add_ab(&s.m[j], &s.m[j], obj + 0x10);
            vec_add_ab(&s.m[j], &s.m[j], &pos);
        }
        func_003D2DA0(&s, 0, 0);
    }
}
/* localdecomp:end func_L39_005203E0 */

/* localdecomp:start func_L39_00520630 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V_00520630 __attribute__((aligned(16)));
typedef struct {
    V_00520630 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_00520630;
extern s32 D_L39_0024A978;
extern s32 D_L39_0024A97C;
extern s32 D_L39_0024A980;
extern s32 D_L39_0024A984;
extern s32 D_L39_0024A988;
extern s32 D_L39_0024A98C;
extern s32 D_L39_0024A990;
extern f32 D_L39_0024A994;
__asm__(".extern D_L39_0024A978, 4");
__asm__(".extern D_L39_0024A97C, 4");
__asm__(".extern D_L39_0024A980, 4");
__asm__(".extern D_L39_0024A984, 4");
__asm__(".extern D_L39_0024A988, 4");
__asm__(".extern D_L39_0024A98C, 4");
__asm__(".extern D_L39_0024A990, 4");
__asm__(".extern D_L39_0024A994, 4");
extern s16 D_L39_0046FB30[][4][2];
extern V_00520630 D_L39_0046F630[];
extern f32 D_L39_0046FF30[][2];
extern unsigned long func_L39_00589890(int);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern void func_L39_005BC330(void *, void *, s32);

void func_L39_00520630(char *obj)
{
    S_00520630 s;
    V_00520630 mtx[3];
    V_00520630 pos;
    char *data = *(char **)(obj + 0x68);
    s32 i;
    s32 j;
    s32 c;
    s32 k;

    s.x78 = func_L39_00589890(D_L39_0024A98C);
    s.x88 = D_L39_0024A978 | ((long)D_L39_0024A97C << 2) | ((long)D_L39_0024A980 << 4)
          | ((long)D_L39_0024A984 << 6) | ((long)D_L39_0024A988 << 32);
    s.x80 = 0xFF9000000260L;
    s.x70 = 0;
    qzero(&mtx[0]);
    qzero(&mtx[1]);
    qzero(&mtx[2]);
    mtx[0].x = *(f32 *)(data + 0x10);
    mtx[1].y = *(f32 *)(data + 0x10);
    mtx[2].z = *(f32 *)(data + 0x10) * 0.125f;
    c = D_L39_0024A990 + (*(s32 *)(data + 0x24) << 24);
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    func_L39_005BC330(obj + 0x10, &pos, 1);
    func_0038CE20(&pos, &pos, 0.25f);
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 4; j++) {
            k = D_L39_0046FB30[i][j][1];
            func_0038CE20(&s.m[j], &D_L39_0046F630[D_L39_0046FB30[i][j][0]], D_L39_0024A994);
            s.uv[j][0] = D_L39_0046FF30[k][0];
            s.uv[j][1] = D_L39_0046FF30[k][1];
            func_0038D000(&s.m[j], &s.m[j], mtx);
            func_0038D000(&s.m[j], &s.m[j], obj + 0xC0);
            vec_add_ab(&s.m[j], &s.m[j], obj + 0x10);
            vec_add_ab(&s.m[j], &s.m[j], &pos);
        }
        func_003D2DA0(&s, 0, 0);
    }
}
/* localdecomp:end func_L39_00520630 */

/* localdecomp:start func_L39_00520870 */
#include "vu0.h"

typedef struct {
    u8 p0[0x18];
    u8 *hit;
    s32 n1C;
    vu0_v4 pos;
    u8 p30[0x10];
    vu0_v4 nrm;
} C_00520870;

typedef struct {
    vu0_v4 dir;
    void *owner;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 oclass;
    f32 f1C;
    s32 w20;
    u8 p24[4];
    s32 w28;
} Q_00520870;

extern C_00520870 D_L39_0025F740;

extern f32 func_0038D160(f32, f32);
extern f32 func_L18_00457C10(f32, f32, f32 *, f32, f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void *func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_L39_005B8978(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern s32 func_0019D510(void);

/* port of func_L18_00320C30 (src/levels/shared/L18_00320C30.c), the same code in level 18 */
void func_L39_00520870(u8 *m) {
    u8 *v;
    vu0_v4 save;
    vu0_v4 n;
    vu0_v4 w;
    vu0_v4 e;
    vu0_v4 d;
    s32 hit;
    f32 dist;

    if (m == 0) {
        return;
    }
    v = *(u8 **)(m + 0x68);
    if (v == 0) {
        return;
    }
    n = (vu0_v4){0};
    n.z = 0.16000001f;
    *(f32 *)(m + 0x2C) += (*(f32 *)(*(u8 **)(m + 0x24) + 0x24) - *(f32 *)(m + 0x2C)) * 0.060000002f;
    *(f32 *)(v + 0x38) += (1.2f - *(f32 *)(v + 0x38)) * 0.120000005f * 1.44f;
    vec_sub_ab(&d, v + 0x10, m + 0x10);
    if (*(s32 *)(v + 0x34) < 0xCC) {
        f32 len;

        *(f32 *)(m + 0xF8) = func_L18_00457C10(*(f32 *)(m + 0xF8), func_0038D160(d.x, d.y), (f32 *)(v + 0x3C),
                                               0.037699115f, 0.0f, 0.0f);
        len = func_0038CED8(&d);
        *(f32 *)(m + 0xF4) = func_L18_00457C10(*(f32 *)(m + 0xF4), -func_0038D160(len, d.z), (f32 *)(v + 0x40),
                                               0.037699115f, 0.0f, 0.0f);
        vec_sub_ab(&d, v + 0x10, v + 0x20);
        len = func_0038CEA8(&d);
        if (len < 6.0f) {
            *(f32 *)(v + 0x44) *= len / 6.0f;
        } else {
            *(f32 *)(v + 0x44) += 0.120000005f;
        }
    }
    {
        {
            vu0_v4 q;
            vu0_v4 r;
            f32 h[16];

            func_00382760(&e, *(f32 *)(v + 0x38), *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            r = (vu0_v4){0};
            r.x = func_L39_005B4410(-1.0f, 1.0f);
            r.y = func_L39_005B4410(-1.0f, 1.0f);
            r.z = func_L39_005B4410(-1.0f, 1.0f);
            q = r;
            func_0038CF68(&q, &q, func_L39_005B4410(0.1f, 0.2f) * 0.020000001f);
            func_0038CF68(&w, &e, -func_L39_005B4410(0.002f, 0.020000001f));
            vec_add_ba(&q, &q, &w);
            func_0038CF68(&w, &e, func_L39_005B4410(0.0f, 1.0f) * *(f32 *)(v + 0x38));
            vec_add_ab(&w, &w, m + 0x10);
            {
                s32 life = (func_L39_005B43C8(0x1C, 0x28) * 5 + 2) / 6;

                func_L39_005C5FC8(&w, &q, 0x6F00AFFF, 0x100000FF, life, 0x28, func_L39_005B43C8(0x28, 0x46), 1);
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
            for (;;) {
                q.y = *(f32 *)(v + 0x44) * func_0038D0B0(*(f32 *)(v + 0x48)) * func_0038D098(*(f32 *)(v + 0x4C));
                q.z = *(f32 *)(v + 0x44) * func_0038D098(*(f32 *)(v + 0x48)) * func_0038D098(*(f32 *)(v + 0x4C));
                q.x = q.w = 0.0f;
                func_0038D328(h, m + 0xF0);
                func_0038D028(&q, &q, h);
                vec_add_ba(m + 0x10, v + 0x20, &q);
                if (func_003D3CB0(&save, m + 0x10, 6, *(void **)(v + 0x30), 0) != 0) {
                    dist = *(f32 *)(v + 0x44) * 0.7f;
                    *(f32 *)(v + 0x44) = dist;
                    hit = 1;
                } else {
                    break;
                }
                if (!(0.1f < dist)) {
                    break;
                }
            }
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
        Q_00520870 rec;

        rec.owner = *(void **)(v + 0x30);
        rec.flags = 0x1030001;
        rec.f1C = *(f32 *)(v + 0x5C);
        rec.dir = e;
        rec.w20 = 1;
        func_0038CFB8(&rec, &rec, 1.0f);
        rec.dir.z = 1.0f;
        rec.dir.w = 5627.9248f;
        rec.b18 = 3;
        rec.b19 = 3;
        rec.oclass = *(u16 *)(m + 0xAA);
        rec.w28 = *(s32 *)(v + 0x60);
        if (func_003D3CB0(&save, m + 0x10, 0, *(void **)(v + 0x30), &rec) != 0) {
            C_00520870 *cr = &D_L39_0025F740;

            if (cr->hit != 0) {
                if (cr->hit != *(u8 **)(v + 0x30) && *(s16 *)(cr->hit + 0xAA) != 0x1092) {
                    m[0xBC] = 2;
                    *(vu0_v4 *)(m + 0x10) = cr->pos;
                    func_L01_0040E790(&n, &e, &cr->nrm);
                    func_0038CF68(&n, &n, 0.040000003f);
                    func_L39_005B8978(m, &n, 0, 0.0f, 0.0f, 10, 3, 9, 4.0f, 2.0f, 9.0f, 1.0f, 0, 15.0f, 1, 1, -1, 0,
                                      0x1010001);
                    func_003C2880(m);
                    return;
                }
            } else if (cr->n1C > 0) {
                m[0xBC] = 1;
                *(vu0_v4 *)(m + 0x10) = cr->pos;
                func_L01_0040E790(&n, &e, &cr->nrm);
                func_0038CF68(&n, &n, 0.040000003f);
                func_L39_005B8978(m, &n, 0, 0.0f, *(f32 *)(v + 0x5C), 10, 3, 9, 4.0f, 2.0f, 9.0f, 1.0f, 0, 15.0f, 1, 1,
                                  -1, 0, 0x1010001);
                func_003C2880(m);
                return;
            }
        } else if (func_0038CAD0(v + 0x34) != 0) {
            func_003C2880(m);
            return;
        }
    }
    if (*(s32 *)(v + 0x34) % 0x1B == 0) {
        if (func_0019D510() & 1) {
            *(f32 *)(v + 0x50) *= func_L39_005B4410(-0.7f, -1.5f);
        }
        if (func_0019D510() & 1) {
            *(f32 *)(v + 0x54) *= func_L39_005B4410(-0.6f, -1.6f);
        }
    }
}
/* localdecomp:end func_L39_00520870 */

INCLUDE_ASM("asm/levels", func_L39_005210A0);

/* localdecomp:start func_L39_00521BC0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00521BC0;
typedef struct {
    V4_00521BC0 v0;
    V4_00521BC0 v10;
    u8 pad20[0x44];
    s16 s64;
} D_00521BC0;
typedef struct {
    u8 pad0[0x68];
    D_00521BC0 *p68;
    u8 pad6C[0x64];
    V4_00521BC0 vD0;
    V4_00521BC0 vE0;
} O_00521BC0;
typedef struct {
    u8 pad0[0xD4];
    u8 *pD4;
} G_00521BC0;
extern f32 func_L39_005B4468(f32, f32);
extern s32 func_L39_005B4398(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern G_00521BC0 D_L39_00296818;
extern u8 D_L39_00242930[] __attribute__((section(".sdata")));

static __inline__ void jitter_00521BC0(V4_00521BC0 *d, V4_00521BC0 *s, f32 lo) {
    d->x = s->x + func_L39_005B4468(lo, 0.15f);
    d->y = s->y + func_L39_005B4468(lo, 0.15f);
    d->z = s->z + func_L39_005B4468(lo, 0.15f);
}

void func_L39_00521BC0(O_00521BC0 *obj) {
    D_00521BC0 *data = obj->p68;
    V4_00521BC0 cur;
    V4_00521BC0 off;
    V4_00521BC0 step;
    V4_00521BC0 pt;
    f32 size;
    f32 big;
    f32 glow;
    f32 zero;
    s32 i;
    s32 c;
    u8 *r;

    if (data->s64 != 0) {
        cur = data->v0;
    } else {
        cur = data->v10;
    }
    size = 0.2f;
    func_0038CE20(&off, &obj->vD0, -0.1f);
    vec_add_ab(&cur, &cur, &off);
    func_0038CE20(&step, &obj->vE0, 0.15f);
    vec_add_ab(&cur, &cur, &step);
    func_0038CE20(&step, &obj->vE0, -0.033333335f);
    for (i = 8; i >= 0; i--) {
        zero = 0.0f;
        glow = 262500.0f;
        big = 210000.0f;
        jitter_00521BC0(&pt, &cur, zero);
        c = func_L39_005B4398(0xFF);
        func_L01_0046FB40(&pt, D_L39_00242930, 3, 0x808080, c, 0x7F, 0x7F, size * big, size * big, zero, 1);
        r = func_L01_0046FB40(&cur, D_L39_00242930, 3, 0x203080, c, 0x10, 0x10, glow, glow, zero, 1);
        if (r != 0) {
            r[2] = *D_L39_00296818.pD4;
        }
        vec_add_ab(&cur, &cur, &step);
    }
}
/* localdecomp:end func_L39_00521BC0 */

/* localdecomp:start func_L39_00521DE8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00521DE8;
typedef struct {
    u8 pad0[0x23A0];
    V4_00521DE8 v23A0;
} T_00521DE8;
typedef struct {
    V4_00521DE8 v0;
    V4_00521DE8 v10;
    u8 pad20[0x38];
    T_00521DE8 *p58;
    u8 pad5C[8];
    s16 s64;
} D_00521DE8;
typedef struct {
    u8 pad0[0x10];
    V4_00521DE8 v10;
    u8 pad20[0x48];
    D_00521DE8 *p68;
    u8 pad6C[0x54];
    V4_00521DE8 mC0;
    V4_00521DE8 vD0;
} O_00521DE8;
typedef struct {
    V4_00521DE8 v[4];
    s32 c[4];
    s32 f50;
    s32 f54;
    s32 f58;
    f32 f5C;
    f32 f60;
    s32 f64;
    f32 f68;
    f32 f6C;
    u8 pad70[0x20];
    V4_00521DE8 v90;
} P_00521DE8;
extern f32 func_L39_005B4410(f32, f32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_00521DE8(void *arg) {
    O_00521DE8 *obj = arg;
    D_00521DE8 *data = obj->p68;
    T_00521DE8 *t = data->p58;
    V4_00521DE8 m[4];
    P_00521DE8 p;
    f32 s1, s2;
    s32 i;
    vu0_q qa, qb;

    s1 = func_L39_005B4410(0.75f, 0.95f);
    s2 = func_L39_005B4410(2.0f, 2.5f);
    m[0] = obj->vD0;
    vec_sub_ba(&m[1], &t->v23A0, &obj->v10);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], s1);
    func_0038CF68(&m[0], &m[0], s2);
    m[0].w = 0.0f;
    m[1].w = 0.0f;
    m[2].w = 0.0f;
    func_003D93B0(&p, 0x3F, 1, 0x80);
    p.f50 = 0;
    p.f54 = 0;
    p.f58 = 0;
    p.f5C = 1.0f;
    p.f60 = 1.0f;
    p.f64 = 0;
    p.f68 = 1.0f;
    p.f6C = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&p.v[i]);
        if (i < 2) {
            p.v[i].x = 0.0f;
        } else {
            p.v[i].x = 1.0f;
        }
        p.v[i].y = 0.0f;
        if (i & 1) {
            p.v[i].z = 1.0f;
        } else {
            p.v[i].z = -1.0f;
        }
        p.v[i].w = 1.0f;
        p.c[i] = 0x7FFFFFFF;
    }
    *(u128_t *)&p.v90 = 0;
    p.v90.y = -2.0f;
    func_0038D000(&m[3], &p.v90, &obj->mC0);
    if (data->s64 != 0) {
        __asm__ __volatile__("lqc2 $vf2, %0" : : "m"(data->v0));
    } else {
        __asm__ __volatile__("lqc2 $vf2, %0" : : "m"(data->v10));
    }
    __asm__ __volatile__(
        "lqc2 $vf1, %0\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : : "m"(m[3]) : "memory");
    m[3].w = 1.0f;
    func_003D2DA0(&p, m, 0);
}
/* localdecomp:end func_L39_00521DE8 */
