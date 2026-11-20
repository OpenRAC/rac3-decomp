#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef int s128_3AC638 __attribute__((mode(TI)));
typedef struct { u8 pad[3184]; int a[4]; int b[4]; int c[4]; int d[4]; int e[4]; int f[4]; int g[4]; } S_3AC638;
typedef struct {
    int f0;
    f32 f4;
    f32 f8;
    int fC;
} V_3AD948;

/* localdecomp:start func_L01_003AC8C0 */
typedef struct { s32 key; f32 f4; s32 w8; u8 pC[4]; vu0_v4 pos; } Ent_3AC8C0;
typedef struct { u8 p0[0x48]; s32 n; Ent_3AC8C0 *ents; s32 w50; f32 f54; f32 f58; f32 f5C; f32 f60; } St_3AC8C0;
extern f32 D_L01_001DE3C8;
__asm__(".extern D_L01_001DE3C8, 4");
extern u8 D_L01_001E2A40[];
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_L01_0046E078(s32, void *, void *, s32, s32);

void func_L01_003AC8C0(u8 *obj, u8 *other, void *pos) {
    St_3AC8C0 *st;
    Ent_3AC8C0 *p;
    f32 tmp[4] __attribute__((aligned(16)));
    f32 l10[4] __attribute__((aligned(16)));
    f32 l20[4] __attribute__((aligned(16)));
    f32 l30[4] __attribute__((aligned(16)));
    u8 pad[0x30];
    f32 f;
    s32 i;
    s32 key;
    s32 r;

    st = *(St_3AC8C0 **)(other + 0x68);
    if (st->w50 >= 0) {
        vec_sub_ba(tmp, obj + 0x10, pos);
        func_0038CE20(tmp, tmp, 60.0f);
        f = func_0038CE68(tmp, obj + 0xC0) * (1.0f / D_L01_001DE3C8) * st->f54;
        if (st->f5C < f) {
            f = st->f5C;
        } else if (f < st->f58) {
            f = st->f58;
        }
        f = func_0038DAB8(f, st->f60);
        f = func_0038DB00(f, *(f32 *)(obj + 0xF4) * 1.25f);
        qzero(other + 0xC00);
        *(f32 *)(other + 0xC04) = f;
        func_L01_0044E850(*(void **)(other + 0x64), other + 0xBA0, st->w50, 0.0432f, 0.43200004f);
    }
    f = func_L01_0040E548(D_L01_001E2A40, *(u8 **)(other + 0x64) + 0x10);
    r = *(s16 *)(*(u8 **)(other + 0x64) + 0x32);
    if ((f32)(r * r) < f) {
        return;
    }
    if (st->ents != 0 && st->n != 0) {
        p = st->ents;
        key = -1;
        for (i = 0; i < st->n; i++) {
            if (p->key != key) {
                func_003C2EC0(*(void **)(other + 0x64), p->key, l30);
                key = p->key;
            }
            func_0038D028(l10, &p->pos, l30);
            func_0038CE20(l20, l30, p->f4);
            func_L01_0046E078(0, l10, l20, p->w8, 1);
            p++;
        }
    }
}
/* localdecomp:end func_L01_003AC8C0 */

INCLUDE_ASM("asm/levels", func_L01_003ACAD0);

/* localdecomp:start func_L01_003ACCD8 */
extern void func_L01_003ACAD0(void *a, s32 b);
extern void func_L01_004443E8(void *, s32, s32);

void func_L01_003ACCD8(void *a, u8 *m) {
    *(s32 *)(m + 0xD20) = 1;
    func_L01_004443E8(a, 0, 3);
    (*(void (**)(void *))(*(u8 **)(m + 0xC48) + 4))(*(void **)(m + 0x64));
    func_L01_003ACAD0(a, 1);
}
/* localdecomp:end func_L01_003ACCD8 */

INCLUDE_ASM("asm/levels", func_L01_003ACD38);

/* localdecomp:start func_L01_003ACFA8 */
void func_L01_003ACFA8(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f0_2;

    (*(s32 *)arg3) = 0;
    temp_f1 = *(f32 *)((u8 *)arg3 + 4);
    var_f0 = *(f32 *)((u8 *)arg2 + 0xC);
    if ((var_f0 < temp_f1) || (var_f0 = (*(f32 *)((u8 *)arg2 + 8)), (temp_f1 < var_f0))) {
        *(f32 *)((u8 *)arg3 + 4) = var_f0;
    }
    temp_f1_2 = *(f32 *)((u8 *)arg3 + 8);
    var_f0_2 = *(f32 *)((u8 *)arg2 + 0x14);
    if ((var_f0_2 < temp_f1_2) || (var_f0_2 = (*(f32 *)((u8 *)arg2 + 0x10)), (temp_f1_2 < var_f0_2))) {
        *(f32 *)((u8 *)arg3 + 8) = var_f0_2;
    }
}
/* localdecomp:end func_L01_003ACFA8 */

/* localdecomp:start func_L01_003AD010 */
typedef struct {
    s32 w0;
    s32 w4;
    u8 p8[0x10];
} E_3AD010_003AD010;
typedef struct {
    u8 p0[8];
    s32 n;
    E_3AD010_003AD010 *e;
    u8 p10[0xC];
    f32 f1C;
    f32 f20;
    s32 w24;
    f32 f28;
    f32 f2C;
} C_3AD010_003AD010;
typedef struct {
    u8 p0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 p21[0x95 - 0x21];
    u8 b95;
    u8 p96[0xC0 - 0x96];
    vu0_v4 mC0[3];
    u8 pF0[8];
    f32 fF8;
} O_3AD010_003AD010;
typedef struct {
    u8 p0[0x44];
    s16 h44;
    u8 p46[0x64 - 0x46];
    void *w64;
    C_3AD010_003AD010 *cfg;
    u8 p6C[4];
    vu0_v4 v70;
    u8 p80[0x20];
    u8 ent[0xC60 - 0xA0];
    s32 wC60;
    u8 pC64[0xCE0 - 0xC64];
    s32 wCE0;
    u8 pCE4[8];
    s32 wCEC;
    u8 pCF0[0xD90 - 0xCF0];
    vu0_v4 mD90[3];
} M_3AD010_003AD010;

extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0044E850_003AD010(void *, void *, s32, f32, f32);
extern void func_L01_00445170_003AD010(void *, s32);
extern f32 func_0038CED8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040EE50_003AD010(void *, void *);
extern void func_003C2F58(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D308(u8 *a0, u8 *a1);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_L01_003ACFA8_003AD010(s32 arg0, s32 arg1, void *arg2, void *arg3);

void func_L01_003AD010(O_3AD010_003AD010 *o, M_3AD010_003AD010 *m) {
    vu0_v4 dir;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 rot;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 m70[3];
    vu0_v4 mA0[3];
    vu0_v4 mD0[3];
    vu0_v4 v100;
    C_3AD010_003AD010 *cfg;
    E_3AD010_003AD010 *e;
    u8 *ent;
    s32 i;
    f32 a;
    f32 s;
    f32 len;
    f32 t;

    cfg = m->cfg;
    if (cfg->n == 0) {
        return;
    }
    a = func_0038DAB8(o->fF8, cfg->f1C);
    dir.x = func_0038D098(a);
    dir.y = func_0038D0B0(a);
    *(s32 *)&dir.z = 0;
    func_0038D000(&v10, m->mD90, o->mC0);
    vec_add_ba(&v10, &v10, &o->v10);
    vec_sub_ab(&v40, &m->v70, &v10);
    v50 = v40;
    *(s32 *)&v50.z = 0;
    func_0038CF68(&v50, &v50, 1.0f);
    if (o->b20 < 2 || m->wCE0 == 0
        || (m->wCEC <= 0 && (o->b95 == 3 || m->h44 != 1 || v50.x * dir.x + v50.y * dir.y < cfg->f20))) {
        func_0038CAD0(&m->wC60);
        if (m->wC60 < cfg->w24) {
            m->wC60 = cfg->w24;
        }
        e = cfg->e;
        for (i = 0; i < cfg->n; i++) {
            ent = &m->ent[e->w4 * 128];
            qzero(ent + 0x60);
            func_L01_0044E850_003AD010(m->w64, ent, e->w0, 0.0432f, 0.43200004f);
            e++;
        }
        return;
    }
    if (o->b95 == 3) {
        func_0038CAD0(&m->wC60);
        if (m->wC60 < cfg->w24) {
            m->wC60 = cfg->w24;
        }
    } else if (func_0038CAD0(&m->wC60) != 0 && o->b95 != 2) {
        func_L01_00445170_003AD010(o, 2);
    }
    len = func_0038CED8(&v40);
    if (len < cfg->f28 * 0.5f + cfg->f2C) {
        s = cfg->f2C - len;
    } else {
        s = cfg->f28 * -0.5f;
    }
    if (m->wCEC > 0) {
        t = (f32)m->wCEC / (f32)m->wCE0;
        t = s + cfg->f28 * (1.0f - t);
    } else {
        t = s;
    }
    func_0038CE20(&v100, &v50, t);
    vec_add_ab(&v60, &v100, &m->v70);
    func_L01_0040EE50_003AD010(mD0, o->mC0);
    qzero(&rot);
    e = cfg->e;
    for (i = 0; i < cfg->n; i++) {
        ent = &m->ent[e->w4 * 128];
        func_003C2F58(m->w64, e->w0, &v10);
        vec_sub_ab(&v20, &v60, &v10);
        rot.y = -func_0038D160(func_0038CED8(&v20), v20.z);
        rot.z = func_0038D160(v20.x, v20.y);
        func_0038D308(m70, &rot);
        func_0038D5F0(mA0, mD0, m70);
        func_003C48A8(mA0, ent + 0x60);
        func_L01_003ACFA8_003AD010((s32)o, (s32)m, e, ent + 0x60);
        func_L01_0044E850_003AD010(m->w64, ent, e->w0, 0.0432f, 0.43200004f);
        e++;
    }
}
/* localdecomp:end func_L01_003AD010 */

INCLUDE_ASM("asm/levels", func_L01_003AD418);

/* localdecomp:start func_L01_003AD800 */
extern void func_003A52A0(s32, s32, s32);

void func_L01_003AD800(s32 a0, u8 *s) {
    s32 st = *(s32 *)(s + 3136);
    s32 idx;
    if (st == 0 || st == 3) {
        *(s32 *)(s + 3136) = 1;
        idx = *(s32 *)(*(u8 **)(s + 104) + 68);
        if (idx >= 0) {
            func_003A52A0(idx, 0, *(s32 *)(s + 100));
        }
    }
}
/* localdecomp:end func_L01_003AD800 */

/* localdecomp:start func_L01_003AD850 */
extern void func_003A52A0(s32, s32, s32);
void func_L01_003AD850(s32 a0, u8 *a1) {
    s32 t;
    if ((u32)(*(s32 *)(a1 + 3136) - 1) < 2) {
        *(s32 *)(a1 + 3136) = 3;
        t = *(s32 *)(*(u8 **)(a1 + 104) + 68);
        if (t >= 0) {
            func_003A52A0(t, 0, *(s32 *)(a1 + 100));
        }
    }
}
/* localdecomp:end func_L01_003AD850 */

/* localdecomp:start func_L01_003AD898 */
extern f32 func_L01_0040E910(f32);
extern void func_L01_0040E3C0(void *, void *, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L01_003AD898(void *a0, u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i;
    s32 j;
    u8 *g;
    u8 *e;
    u8 *o;
    f32 s;
    switch (*(s32 *)(m + 0xC40)) {
    case 0:
        break;
    case 3:
        *(f32 *)(m + 0xCFC) -= *(f32 *)(v + 0x40);
        if (*(f32 *)(m + 0xCFC) <= 0.0f) {
            *(s32 *)(m + 0xC40) = 0;
        }
        if (*(f32 *)(m + 0xCFC) < 0.0f) {
            *(f32 *)(m + 0xCFC) = 0.0f;
        }
        break;
    case 1:
        *(f32 *)(m + 0xCFC) += *(f32 *)(v + 0x3C);
        if (1.0f <= *(f32 *)(m + 0xCFC)) {
            *(s32 *)(m + 0xC40) = 2;
        }
        if (1.0f < *(f32 *)(m + 0xCFC)) {
            *(f32 *)(m + 0xCFC) = 1.0f;
        }
        break;
    case 2:
        break;
    }
    g = *(u8 **)(v + 0x38);
    for (i = 0; i < *(s32 *)(v + 0x34); i++) {
        if (*(s32 *)(g + 0x24) != 0) {
            e = *(u8 **)(g + 0x28);
            for (j = 0; j < *(s32 *)(g + 0x24); j++) {
                o = m + 0xA0 + (*(s32 *)(e + 4) << 7);
                s = func_L01_0040E910(*(f32 *)(m + 0xD00) + *(f32 *)(e + 0x20));
                func_L01_0040E3C0(o + 0x60, e + 0x10, *(f32 *)(m + 0xCFC) * (s * *(f32 *)(e + 0x24) + 1.0f));
                func_L01_0044E850(*(void **)(m + 0x64), o, *(s32 *)e, 0.0432f, 0.43200004f);
                e += 0x30;
            }
        }
        g += 0x30;
    }
}
/* localdecomp:end func_L01_003AD898 */

/* localdecomp:start func_L01_003ADA68 */
extern u16 *D_L01_0021DE20_003ADA68[];
extern s32 D_L01_001E0058_003ADA68;
extern u8 *D_L01_001E001C_003ADA68;
extern char *func_L01_0043B568_003ADA68(int, int, int);
typedef struct {
    u8 pad0[0xC90];
    s32 ids[31];
    s32 cur;
} M_003ADA68;

s32 func_L01_003ADA68(s32 unused, M_003ADA68 *m) {
    u16 *p = D_L01_0021DE20_003ADA68[m->ids[m->cur]];
    s32 last = -1;
    u8 *e;
    s32 r;

    for (; (m->ids[m->cur] & 0xFF) != 0xFF && m->ids[m->cur] <= D_L01_001E0058_003ADA68 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L01_0021DE20_003ADA68[m->ids[m->cur]]);
         p++) {
        e = D_L01_001E001C_003ADA68 + ((p[0] & 0x7FFF) << 8);
        if (e == 0) {
            return 0;
        }
        if (*(s16 *)(e + 0xAA) != last) {
            r = (*(s32 (**)(s32))func_L01_0043B568_003ADA68(*(s16 *)(e + 0xAA), 2, 12))(m->ids[m->cur]);
            if (r != 0) {
                return r;
            }
            last = *(s16 *)(e + 0xAA);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003ADA68 */

/* localdecomp:start func_L01_003ADBE0 */
extern void func_0038D000(void *, void *, void *);
extern void func_003C2F58(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern char *func_L01_0043B568(int, int, int);
void func_L01_003ADBE0(u8 *a0, u8 *m, u8 *a2) {
    vu0_v4 a;
    vu0_v4 b;
    u8 *pv;
    u8 *e;
    f32 f;
    char *r;
    pv = *(u8 **)(m + 104);
    e = *(u8 **)(pv + 56) + *(s32 *)(m + 3320) * 48;
    func_0038D000(&b, e + 16, a0 + 192);
    b.x *= 0.5f;
    b.y *= 0.5f;
    func_003C2F58(*(void **)(m + 100), *(void **)e, &a);
    vec_add_ab(&a, &a, &b);
    f = func_0038DAB8(*(f32 *)(e + 32), *(f32 *)(a0 + 248));
    r = func_L01_0043B568(*(s16 *)(a2 + 170), 2, 12);
    ((void (*)(u8 *, void *, void *, f32))*(void **)(r + 4))(a2, &a, *(void **)(m + 100), f);
    *(s32 *)(m + 3320) = (*(s32 *)(m + 3320) + 1) % *(s32 *)(pv + 52);
}
/* localdecomp:end func_L01_003ADBE0 */

/* localdecomp:start func_L01_003ADCE8 */
extern char *func_L01_0043B568(int, int, int);
void func_L01_003ADCE8(int a, int b, char *m)
{
    char *v = func_L01_0043B568(*(short *)(m + 170), 2, 12);
    (*(void (**)(char *))(v + 8))(m);
}
/* localdecomp:end func_L01_003ADCE8 */

/* localdecomp:start func_L01_003ADD28 */
extern u8 *func_L01_00449050(u8 *a0);
extern void func_0038D308(u8 *a0, u8 *a1);
void func_L01_003ADD28(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *v = func_L01_00449050(a0);
    s32 *src = (s32 *)(*(u8 **)(*(u8 **)(v + 8) + 104) + 160);
    s32 *dst = (s32 *)(s1 + 3216);
    s32 i;
    for (i = 0; i < 4; i++) {
        *dst++ = *src++;
    }
    *(u128_t *)(a0 + 16) = *(u128_t *)(s1 + 3376);
    *(u128_t *)(a0 + 240) = *(u128_t *)(s1 + 3392);
    func_0038D308(a0 + 192, a0 + 240);
}
/* localdecomp:end func_L01_003ADD28 */

/* localdecomp:start func_L01_003ADDA0 */
extern void func_L01_003ADDA0(void *p);
extern void func_L01_003ADDA0(void *);

extern void func_L01_003ACAD0_003ADDA0(void *, s32);
 
void func_L01_003ADDA0(void *p) {
    func_L01_003ACAD0_003ADDA0(p, 0);
}
/* localdecomp:end func_L01_003ADDA0 */

/* localdecomp:start func_L01_003ADDC0 */

#define W(p, o) (*(int *)((p) + (o)))
#define F(p, o) (*(f32 *)((p) + (o)))
#define Q(p, o) (*(s128_3AC638 *)((p) + (o)))


void func_L01_003ADDC0(u8 *a, u8 *b) {
    u8 *src = *(u8 **)(b + 0x68);
    u8 *dst = *(u8 **)(a + 0x68);
    int i;

    Q(dst, 3376) = Q(src, 3376);
    Q(dst, 3392) = Q(src, 3392);
    W(dst, 96) = W(src, 96);
    W(dst, 108) = W(src, 108);
    W(dst, 3104) = W(src, 3104);
    W(dst, 3108) = W(src, 3108);
    W(dst, 3112) = W(src, 3112);
    W(dst, 3116) = W(src, 3116);
    W(dst, 3120) = W(src, 3120);
    F(dst, 3124) = F(src, 3124);
    W(dst, 3152) = W(src, 3152);
    W(dst, 3156) = W(src, 3156);
    W(dst, 3160) = W(src, 3160);
    W(dst, 3164) = W(src, 3164);
    F(dst, 3172) = F(src, 3172);
    F(dst, 3176) = F(src, 3176);
    for (i = 0; i < 4; i++) {
        ((S_3AC638 *)dst)->a[i] = ((S_3AC638 *)src)->a[i];
        ((S_3AC638 *)dst)->b[i] = ((S_3AC638 *)src)->b[i];
        ((S_3AC638 *)dst)->c[i] = -1;
        ((S_3AC638 *)dst)->d[i] = ((S_3AC638 *)src)->d[i];
        ((S_3AC638 *)dst)->e[i] = ((S_3AC638 *)src)->e[i];
        ((S_3AC638 *)dst)->f[i] = ((S_3AC638 *)src)->f[i];
        ((S_3AC638 *)dst)->g[i] = ((S_3AC638 *)src)->g[i];
    }
    W(dst, 3296) = W(src, 3296);
    W(dst, 3300) = W(src, 3300);
    W(dst, 3304) = W(src, 3304);
    F(dst, 3312) = F(src, 3312);
    W(dst, 3148) = W(src, 3148);
}
/* localdecomp:end func_L01_003ADDC0 */

/* localdecomp:start func_L01_003ADEC8 */
extern void func_L01_003ADFC0(u8 *);
extern void func_L01_003AE0E8(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern s32 func_L01_003AE5B8(u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L01_003ADEC8(u8 *o) {
    u8 *s = *(u8 **)(o + 104);
    u8 *p;
    u8 *q;
    s32 st = o[32];

    if (st != 2) {
        if (st < 3) {
            if (st == 1) {
                func_L01_003ADFC0(o);
                func_L01_003AE0E8(o);
            }
        }
    } else {
        if (func_L01_004561B8(o) != 0) {
            func_L01_004AAC98(1, 0, o, 6496);
        }
        if (func_L01_003AE5B8(o) != 0) {
            p = *(u8 **)(o + 184);
            if (p != 0 && s[36] == 0) {
                p[188] = 1;
                s[36] = 1;
            }
        }
        if (func_0038CAD0(s + 20) != 0) {
            func_L01_004450F0(o, 3, -1);
            func_003C2880(o);
            q = *(u8 **)(o + 184);
            if (q != 0 && s[36] == 0) {
                q[188] = 2;
            }
        }
    }
}
/* localdecomp:end func_L01_003ADEC8 */

/* localdecomp:start func_L01_003ADFC0 */
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_003AE1A0(u8 *);
__asm__(".extern D_L01_001DE4A8, 4");
__asm__(".extern D_L01_001DE4AC, 4");
__asm__(".extern D_L01_001DE4A4, 4");
extern f32 D_L01_001DE4A8;
extern f32 D_L01_001DE4AC;
extern s32 D_L01_001DE4A4;

void func_L01_003ADFC0(u8 *m) {
    vu0_q v;
    u8 *pv;
    f32 t;
    f32 u;
    f32 r;
    pv = *(u8 **)(m + 104);
    v = *(vu0_q *)(m + 16);
    vec_add_ba(m + 16, pv, m + 16);
    t = D_L01_001DE4A8 * 0.0174532924f * 0.0200000014f;
    *(f32 *)(pv + 8) -= 0.00392000005f;
    r = func_0038DAB8(*(f32 *)(m + 244), t);
    u = D_L01_001DE4AC * 0.0174532924f * 0.0200000014f;
    *(f32 *)(m + 244) = r;
    *(f32 *)(m + 248) = func_0038DAB8(*(f32 *)(m + 248), u);
    if (func_0038CAD0(pv + 20) || func_003D3CB0(&v, m + 16, 0, 0, 0)) {
        func_L01_003AE1A0(m);
        *(s32 *)(pv + 20) = (D_L01_001DE4A4 * 5 + 2) / 6;
        func_L01_004450F0(m, 2, -1);
    }
}
/* localdecomp:end func_L01_003ADFC0 */

INCLUDE_ASM("asm/levels", func_L01_003AE0E8);

INCLUDE_ASM("asm/levels", func_L01_003AE1A0);

INCLUDE_ASM("asm/levels", func_L01_003AE5B8);

LINKER_REMNANT("asm/levels", func_L01_003AE6E0);

INCLUDE_ASM("asm/levels", func_L01_003AE6E8);

INCLUDE_ASM("asm/levels", func_L01_003AEA58);

INCLUDE_ASM("asm/levels", func_L01_003AEB68);

/* localdecomp:start func_L01_003AF118 */
extern void func_L01_004450F0(u8 *, s32, s32);

extern u8 D_001A4C60[];
extern void func_L01_003E8BD0(int, int, f32, f32);
extern void func_L01_003E8D48_003AF118(int, f32);
extern void func_L01_003E8F90(int, int);
extern int func_L01_00456500(void *, int);

void func_L01_003AF118(u8 *m) {
    u8 st = m[0x20];
    V_3AD948 *pv = *(V_3AD948 **)(m + 0x68);

    switch (st) {
    case 0:
        m[0x30] = 0xFF;
        ((void (*)(void *, int, int))func_L01_004450F0)(m, 1, -1);
    case 1:
        if (pv->f0 != -1 && func_L01_00456500(D_001A4C60, pv->f0) != 0) {
            ((void (*)(void *, int, int))func_L01_004450F0)(m, 2, -1);
        }
        break;
    case 2:
        func_L01_003E8BD0(0, 0, pv->f4, 0.003f);
        func_L01_003E8D48_003AF118(0, pv->f8 * 0.017453292f);
        if (pv->fC != -1) {
            if (pv->fC == 1) {
                func_L01_003E8F90(0, -1);
            } else if (pv->fC == 2) {
                func_L01_003E8F90(0, 1);
            } else if (pv->fC == 3) {
                func_L01_003E8F90(0, 2);
            }
        }
        if (func_L01_00456500(D_001A4C60, pv->f0) == 0) {
            ((void (*)(void *, int, int))func_L01_004450F0)(m, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L01_003AF118 */
