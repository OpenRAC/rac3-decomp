#include "common.h"

/* localdecomp:start func_L05_003619F0 */
#include "vu0.h"
__asm__(".extern D_L05_001DD9C4, 4");
__asm__(".extern D_L05_001DD9C8, 4");
__asm__(".extern D_L05_001DD9D0, 4");
__asm__(".extern D_L05_001DD9E0, 4");
__asm__(".extern D_L05_001DD9E4, 4");
__asm__(".extern D_L05_001DD9E8, 4");
__asm__(".extern D_L05_001DD9EC, 4");
__asm__(".extern D_L05_001DD9F0, 1");
__asm__(".extern D_L05_001DD9F4, 4");
__asm__(".extern D_L05_001DD9F8, 4");
__asm__(".extern D_L05_001DD9FC, 4");
__asm__(".extern D_L05_001DDA00, 4");
__asm__(".extern D_L05_001DDA04, 4");
__asm__(".extern D_L05_001DDA08, 4");
__asm__(".extern D_L05_001DDA0C, 4");
__asm__(".extern D_L05_001DDA10, 4");
__asm__(".extern D_L05_001DDA14, 4");
__asm__(".extern D_L05_001DDA18, 4");
__asm__(".extern D_L05_001DDA1C, 4");
__asm__(".extern D_L05_001DDA20, 4");
__asm__(".extern D_L05_001DDA24, 4");
extern f32 D_L05_001DD9C4;
extern f32 D_L05_001DD9C8;
extern f32 D_L05_001DD9D0;
extern f32 D_L05_001DD9E0;
extern s32 D_L05_001DD9E4;
extern s32 D_L05_001DD9E8;
extern s32 D_L05_001DD9EC;
extern u8 D_L05_001DD9F0;
extern s32 D_L05_001DD9F4;
extern f32 D_L05_001DD9F8;
extern f32 D_L05_001DD9FC;
extern f32 D_L05_001DDA00;
extern f32 D_L05_001DDA04;
extern f32 D_L05_001DDA08;
extern f32 D_L05_001DDA0C;
extern f32 D_L05_001DDA10;
extern s32 D_L05_001DDA14;
extern f32 D_L05_001DDA18;
extern f32 D_L05_001DDA1C;
extern f32 D_L05_001DDA20;
extern f32 D_L05_001DDA24;
extern u8 *D_L05_001EA6D8 __attribute__((section(".data")));
extern u8 D_L05_001D66B0[8];

extern void func_L01_004450F0(s32, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_003C2880(void *);
extern void func_003C4C18(void *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L05_003622D0(u8 *);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);

typedef struct {
    s32 id;
    u8 *target;
    s16 timer;
    s16 pad_a;
    f32 scale;
    vu0_v4 p10;
    vu0_v4 p20;
    vu0_v4 p30;
    vu0_v4 p40;
    f32 spin;
    s32 x54;
    f32 x58;
} V_3619F0;

void func_L05_003619F0(u8 *o) {
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 vel; /* never written: retail reads its stack slot (sp+0x30) uninitialised too */
    vu0_v4 b;
    vu0_v4 r;
    V_3619F0 *v;
    u8 *t;
    s32 id;
    s32 hit;
    s32 i;
    s32 j;

    v = *(V_3619F0 **)(o + 0x68);
    switch (o[0x20]) {
    case 0:
        func_L01_004450F0((s32)o, 1, -1);
        func_L01_004AAC98(0, 4, o, 0x169C);
        break;
    case 1:
        if (*(f32 *)(o + 0x18) < 0.0f) {
            func_003C2880(o);
        }
        if (--v->timer <= 0 && (v->target != 0 || v->x54 == 1)) {
            *(vu0_q *)&p = *(vu0_q *)&v->p10;
            func_003C4C18(&p, 0.045f);
            if (v->target != 0) {
                func_L01_00456230(v->target, 1);
            }
            func_L01_004450F0((s32)o, 2, -1);
            break;
        }
        *(vu0_q *)&p = *(vu0_q *)(o + 0x10);
        func_L01_00445208(o + 0x10, &v->p10, &v->p20, &v->p30, &v->p40,
                          (f32)v->timer * v->scale);
        vec_sub_ba(&d, o + 0x10, &p);
        v->spin = func_0038DAB8(v->spin, D_L05_001DD9C8 * 0.017453292f * 0.020000001f);
        *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), D_L05_001DD9C4 * 0.017453292f * 0.020000001f);
        *(f32 *)(o + 0xF8) = func_0038D160(d.x, d.y);
        *(f32 *)(o + 0xF4) = -func_0038D160(func_0038CF38(&p, o + 0x10), d.z);
        *(vu0_q *)&r = 0;
        r.x = func_003824E0(-1.0f, 1.0f);
        r.y = func_003824E0(-1.0f, 1.0f);
        r.z = func_003824E0(-1.0f, 1.0f);
        *(vu0_q *)&b = *(vu0_q *)&r;
        func_0038CF68(&b, &b, func_003824E0(0.1f, 0.2f) * 0.020000001f);
        func_0038CF68(&a, &vel, -func_003824E0(0.002f, 0.020000001f));
        vec_add_ba(&b, &b, &a);
        func_0038CF68(&a, &vel, func_003824E0(0.0f, 1.0f) * func_0038CEA8(&d));
        vec_add_ab(&a, &a, o + 0x10);
        func_L01_004637C8(&a, &b, 0x6F00AFFF, 0x100000FF, (func_00382498(0x1C, 0x28) * 5 + 2) / 6, 0x28, func_00382498(0x28, 0x46), 1);
        id = v->id;
        func_L01_004CB320();
        hit = func_003D3CB0(&p, o + 0x10, 0, id, 0);
        if (hit != 0) {
            t = D_L05_001EA6D8;
            if (t != 0 && *(s16 *)(t + 0xAA) == 0x186D && t[0x20] != 2 && t[0x20] != 5) {
                t[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            if (v->target != 0 && D_L05_001EA6D8 == v->target) {
                func_L01_00456230(D_L05_001EA6D8, 1);
            }
            func_L01_004450F0((s32)o, 2, -1);
        } else if (v->target != 0 || v->x54 == 1) {
            func_L01_00404A10(func_L05_003622D0, o);
        }
        break;
    case 2:
        func_L01_004AAC98(1, 0, o, 0x169C);
        *(vu0_q *)&p = *(vu0_q *)(o + 0x10);
        p.z += D_L05_001DD9E0;
        func_L01_0046A610(&p, D_L05_001D66B0, (D_L05_001DD9E4 * 5 + 2) / 6, D_L05_001DD9F0, D_L05_001DD9F4, 0,
                          D_L05_001DD9F8 * 210000.0f, D_L05_001DD9F8 * D_L05_001DD9FC, 0.0f,
                          D_L05_001DDA04 * 0.00040000002f, 0.0f);
        for (i = 0; i < D_L05_001DD9E8; i++) {
            *(vu0_q *)&d = *(vu0_q *)&p;
            func_003C4C18(&d, D_L05_001DDA20);
            func_00382760(&a, D_L05_001DDA0C * 0.020000001f, func_00382538(), func_003824E0(D_L05_001DDA24 * 3.1415927f, 3.1415927f));
            func_L01_0046A610(&d, &a, (D_L05_001DDA14 * 5 + 2) / 6, D_L05_001DD9F0, D_L05_001DD9F4, func_00382468(2) ? -1 : 1,
                              D_L05_001DDA18 * 210000.0f, 0.0f, D_L05_001DDA00, D_L05_001DDA04 * 0.00040000002f, 0.0f);
        }
        for (j = 0; j < D_L05_001DD9EC; j++) {
            *(vu0_q *)&d = *(vu0_q *)&p;
            func_003C4C18(&d, D_L05_001DDA20);
            func_00382760(&a, D_L05_001DDA10 * 0.020000001f, func_00382538(), func_003824E0(D_L05_001DDA24 * 3.1415927f, 3.1415927f));
            func_L01_004713C8(&d, &a, (D_L05_001DDA14 * 5 + 2) / 6, D_L05_001DD9F4, func_00382468(2) ? -1 : 1, D_L05_001DD9F0, 0, 0,
                              D_L05_001DDA1C * 210000.0f, D_L05_001DDA1C * 0.5f * 210000.0f, D_L05_001DDA08 * 0.00040000002f);
        }
        func_L01_00446780(o, o + 0x10, 0x08000001, D_L05_001DD9D0, v->x58, 1.0f, 0, 1, 0);
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L05_003619F0 */

/* localdecomp:start func_L05_00362148 */
#include "vu0.h"
__asm__(".extern D_L05_001DD9C0, 4");
__asm__(".extern D_L05_001DD9D4, 4");
typedef struct { u8 pad[0x32]; s16 f32; } M_362148;
extern f32 D_L05_001DD9C0;
extern f32 D_L05_001DD9D4;
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

u8 *func_L05_00362148(u8 *a0, vu0_v4 *a1, vu0_v4 *a2, s32 a3, s32 t0, u8 t1, f32 f) {
    u8 *m;
    u8 *s;
    vu0_v4 tmp;
    m = func_003C24B0(0x169C, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        m[0x30] = 0xFF;
        m[0x20] = 0;
        ((M_362148 *)m)->f32 = 0xFF;
        m[0x31] = 1;
        *(s32 *)(s + 4) = a3;
        *(s32 *)(s + 0) = (s32)a0;
        *(vu0_q *)(m + 0x10) = *(vu0_q *)a1;
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(a0 + 0xF0);
        *(f32 *)(m + 0x2C) = D_L05_001DD9C0;
        *(f32 *)(s + 0xC) = 1.0f / (f32)t0;
        *(s32 *)(s + 0x54) = t1;
        *(f32 *)(s + 0x58) = f;
        *(s16 *)(s + 8) = t0;
        *(s32 *)(s + 0x50) = 0;
        *(vu0_q *)(s + 0x20) = *(vu0_q *)a1;
        *(vu0_q *)(s + 0x10) = *(vu0_q *)a2;
        vec_sub_ba(&tmp, s + 0x10, s + 0x20);
        tmp.z = 0;
        func_0038CE20(&tmp, &tmp, D_L05_001DD9D4);
        vec_add_ba(s + 0x40, s + 0x20, &tmp);
        func_0038CF68(&tmp, &tmp, -1.0f);
        tmp.z = *(f32 *)(s + 0x18) - *(f32 *)(s + 0x28);
        vec_add_ab(s + 0x30, s + 0x10, &tmp);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L05_00362148 */

/* localdecomp:start func_L05_003622D0 */
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C;
    long x70, x78, x80, x88;
} S_3622D0;
__asm__(".extern D_L05_001DD9CC, 4");
__asm__(".extern D_L05_001DD9D8, 4");
__asm__(".extern D_L05_001DD9DC, 4");
extern f32 D_L05_001DD9CC;
extern s32 D_L05_001DD9D8;
extern s32 D_L05_001DD9DC;
extern void func_0038D2A0(void *);
extern long func_00389598(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L05_003622D0(u8 *p) {
    S_3622D0 s;
    vu0_v4 mat[4];
    u8 *v;
    s32 i;
    f32 t;
    f32 sn;
    f32 cs;
    f32 a;
    f32 x;
    f32 y;

    v = *(u8 **)(p + 0x68);
    t = 1.0f - (f32)*(s16 *)(v + 8) * *(f32 *)(v + 0xC);
    func_0038D2A0(mat);
    s.x78 = func_00389598(0x27);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    sn = func_0038D098(*(f32 *)(v + 0x50));
    cs = func_0038D0B0(*(f32 *)(v + 0x50));
    for (i = 0; i < 4; i++) {
        a = t * 1.5f;
        s.x50 = 0.0f;
        s.x54 = 0.0f;
        s.x58 = 0.0f;
        s.x5C = 1.0f;
        s.x60 = 1.0f;
        s.x64 = 0.0f;
        s.x68 = 1.0f;
        s.x6C = 1.0f;
        if (a > 1.0f) {
            a = 1.0f;
        }
        s.c[i] = func_0038DBD8(D_L05_001DD9D8, D_L05_001DD9DC, a);
        x = -1.0f;
        *(vu0_q *)&s.m[i] = *(vu0_q *)(v + 0x10);
        if ((i & 1) == 0) {
            x = 1.0f;
        }
        y = (i >= 2) ? -1.0f : 1.0f;
        s.m[i].x += (x * sn - y * cs) * D_L05_001DD9CC;
        s.m[i].y += (y * sn + x * cs) * D_L05_001DD9CC;
    }
    func_003D2DA0(&s, mat, 0);
}
/* localdecomp:end func_L05_003622D0 */

/* localdecomp:start func_L05_003624B0 */
__asm__(".extern D_L05_001DDA28, 4");
__asm__(".extern D_L05_001DDA2C, 4");
__asm__(".extern D_L05_001DDA30, 4");
__asm__(".extern D_L05_001DDA34, 4");
extern f32 D_L05_001DDA28;
extern f32 D_L05_001DDA2C;
extern f32 D_L05_001DDA30;
extern f32 D_L05_001DDA34;
void func_L05_003627A0(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);

void func_L05_003624B0(u8 *o) {
    vu0_v4 t;
    vu0_v4 u;
    vu0_v4 w;
    u8 *v;
    u8 *a;
    f32 d;
    f32 ang;

    func_L05_003627A0(o);
    v = *(u8 **)(o + 0x68);
    if (o[0x20] != 1) {
        return;
    }
    if (v[0x10] == 0) {
        a = *(u8 **)(v + 8);
        if ((*(u8 **)(a + 0x68))[0x10] == 1) {
            func_0038CF68(&t, a + 0xC0, D_L05_001DDA28);
            vec_add_ba(o + 0x10, *(u8 **)(v + 8) + 0x10, &t);
            d = func_0038CF38(o + 0x10, *(u8 **)(v + 0xC) + 0x10);
            ang = func_0038D160(d, *(f32 *)(*(u8 **)(v + 0xC) + 0x18) - *(f32 *)(o + 0x18));
            *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), func_0038DB00(-ang, *(f32 *)(o + 0xF4)) * 0.1f);
            ang = func_0038D160(*(f32 *)(*(u8 **)(v + 0xC) + 0x10) - *(f32 *)(o + 0x10),
                                *(f32 *)(*(u8 **)(v + 0xC) + 0x14) - *(f32 *)(o + 0x14));
            *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), func_0038DB00(ang, *(f32 *)(o + 0xF8)) * 0.1f);
        } else {
            vec_sub_ba(&t, *(u8 **)(v + 0xC) + 0x10, o + 0x10);
            func_0038CF68(&t, &t, (func_0038CEA8(&t) - D_L05_001DDA28) * D_L05_001DDA34);
            vec_sub_ba(&u, *(u8 **)(v + 8) + 0x10, o + 0x10);
            func_0038CF68(&u, &u, (func_0038CEA8(&u) - D_L05_001DDA28) * D_L05_001DDA30);
            vec_add_ba(&w, &t, &u);
            w.z -= D_L05_001DDA2C * 0.00040000002f;
            vec_add_ab(o + 0x10, o + 0x10, &w);
            d = func_0038CF38(o + 0x10, *(u8 **)(v + 0xC) + 0x10);
            ang = func_0038D160(d, *(f32 *)(*(u8 **)(v + 0xC) + 0x18) - *(f32 *)(o + 0x18));
            *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), func_0038DB00(-ang, *(f32 *)(o + 0xF4)) * 0.1f);
            ang = func_0038D160(*(f32 *)(*(u8 **)(v + 0xC) + 0x10) - *(f32 *)(o + 0x10),
                                *(f32 *)(*(u8 **)(v + 0xC) + 0x14) - *(f32 *)(o + 0x14));
            *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), func_0038DB00(ang, *(f32 *)(o + 0xF8)) * 0.1f);
        }
    } else {
        a = *(u8 **)(v + 0xC);
        if (*(s16 *)(a + 0xAA) == 0x16C7) {
            func_0038CF68(&t, a + 0xD0, D_L05_001DDA28);
            vec_add_ba(o + 0x10, *(u8 **)(v + 0xC) + 0x10, &t);
            *(vu0_q *)(o + 0xF0) = *(vu0_q *)(*(u8 **)(v + 0xC) + 0xF0);
            *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), 1.5707964f);
        }
        if (*(s16 *)(*(u8 **)(v + 8) + 0xAA) == 0x16C7) {
            *(vu0_q *)(o + 0x10) = *(vu0_q *)(*(u8 **)(v + 8) + 0x10);
            *(vu0_q *)(o + 0xF0) = *(vu0_q *)(*(u8 **)(v + 8) + 0xF0);
            *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), 1.5707964f);
        }
    }
}
/* localdecomp:end func_L05_003624B0 */

/* localdecomp:start func_L05_003627A0 */
extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L05_001DFB9C;
extern u8 *D_001DFB9C_sda;
__asm__(".extern D_L05_001DFB9C, 16");
__asm__(".extern D_001DFB9C_sda, 4");

void func_L05_003627A0(void *arg0) {
    u8 *p;
    s32 a;

    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        p = *(u8 **)((u8 *)arg0 + 0x68);
        a = *(s32 *)p;
        *(s32 *)(p + 0x8) = 0;
        *(s32 *)(p + 0xC) = 0;
        if (a != -1) {
            *(u8 **)(p + 0x8) = D_L05_001DFB9C + (a << 8);
        }
        a = *(s32 *)(p + 0x4);
        if (a != -1) {
            *(u8 **)(p + 0xC) = D_001DFB9C_sda + (a << 8);
        }
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L05_003627A0 */

/* localdecomp:start func_L05_00362810 */
typedef struct P_362810 {
    f32 f0;
    s32 w4;
    f32 f8;
    s32 wC;
} P_362810;

typedef struct S_362810 {
    char pad0[0x18];
    f32 f18;
    char pad1[0x20 - 0x1C];
    u8 b20;
    char pad2[0x68 - 0x21];
    P_362810 *p68;
} S_362810;

struct S_362968;
void func_L05_00362968(struct S_362968 *a0);
s32 func_003A52A0(void *, s32, void *);
void func_003A4F28(s32);
void func_003C41A0(f32 *, void *, f32, f32, f32, f32);

extern u8 D_001A30B0[];
__asm__(".extern D_001A30B0, 16");
extern f32 D_001DDA38_sda;
extern f32 D_001DDA3C_sda;
__asm__(".extern D_001DDA38_sda, 4");
__asm__(".extern D_001DDA3C_sda, 4");

void func_L05_00362810(S_362810 *a0) {
    P_362810 *p;
    u8 *e;
    s32 w;
    s32 k;
    f32 t;
    f32 u;

    func_L05_00362968(a0);
    p = a0->p68;
    k = a0->b20;
    if (k != 2) {
        if (k < 3) {
            if (k == 1) {
                func_L01_004450F0((s32) a0, 2, -1);
            }
        }
    } else {
        if (a0->f18 < p->f0) {
            if (p->wC == -1) {
                p->wC = func_003A52A0(0, 4, a0);
            } else {
                e = D_001A30B0 + (p->wC << 7);
                if (*(void **) (e + 0xDC) != a0 || e[0xD0] == 0) {
                    p->wC = func_003A52A0(0, 4, a0);
                }
            }
            t = D_001DDA38_sda * 1.44f;
            u = D_001DDA3C_sda * 1.2f;
            func_003C41A0(&a0->f18, &p->w4, p->f0, t, t, u);
        } else {
            w = p->wC;
            if (w != -1) {
                e = D_001A30B0 + (w << 7);
                if (*(void **) (e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_003A4F28(w);
                }
            }
            p->wC = -1;
            func_L01_004450F0((s32) a0, 3, -1);
        }
    }
}
/* localdecomp:end func_L05_00362810 */

/* localdecomp:start func_L05_00362968 */
typedef struct P_362968 {
    f32 f0;
    s32 w4;
    f32 f8;
    s32 wC;
} P_362968;

typedef struct S_362968 {
    char pad0[0x18];
    f32 f18;
    char pad1[0x20 - 0x1C];
    u8 b20;
    char pad2[0x68 - 0x21];
    P_362968 *p68;
} S_362968;

s32 func_L01_004450F0_00362968(void *, s32, s32);

void func_L05_00362968(S_362968 *a0) {
    P_362968 *p;
    f32 t;
    f32 g;

    p = a0->p68;
    if (a0->b20 == 0) {
        g = p->f8;
        p->wC = -1;
        t = a0->f18 + g;
        p->w4 = 0;
        p->f0 = t;
        func_L01_004450F0_00362968(a0, 1, -1);
    }
}
/* localdecomp:end func_L05_00362968 */
