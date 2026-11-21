#include "common.h"

/* localdecomp:start func_L01_0033D2B8 */
extern f32 D_L01_001DCFD8;
extern f32 func_00382538(void);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D750(u8 *, s32, f32);
extern void func_L01_0043A430(u8 *, s32, u8 *);

void func_L01_0033D2B8(u8 *a) {
    u8 *s = *(u8 **)(a + 0x68);
    f32 f;

    switch (a[0x20]) {
    case 0:
        a[0x20] = 1;
        a[0x63] = 0x20;
        *(f32 *)(s + 0x40) = func_00382538();
        func_L01_0043A430(a, 1, s);
        break;
    case 1:
        f = D_L01_001DCFD8 * 0.01745329238474369f * 0.020000001415610313f;
        *(f32 *)(a + 0xF8) = func_0038DAB8(*(f32 *)(a + 0xF8), f);
        *(f32 *)(s + 0x40) = func_0038DAB8(*(f32 *)(s + 0x40), f * -2.0f);
        func_0038D750(s + 0x10, 2, *(f32 *)(s + 0x40));
        break;
    }
}
/* localdecomp:end func_L01_0033D2B8 */

/* localdecomp:start func_L01_0033D390 */
void func_L01_0033D390(void) {

}
/* localdecomp:end func_L01_0033D390 */

/* localdecomp:start func_L01_0033D398 */
#include "vu0.h"

typedef int u128_0033D398 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xAA - 0x21];
    u16 xAA;
} O_0033D398;

typedef struct {
    u8 pad0[0x360];
    s32 w360;
    u8 pad364[0xAC0 - 0x364];
    u8 *pAC0;
    u8 padAC4[0xC00 - 0xAC4];
    f32 fC00;
    u8 padC04[0x1210 - 0xC04];
    s32 w1210;
    u8 pad1214[0x25C4 - 0x1214];
    s32 w25C4;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 b25ED;
} Hero_0033D398;

typedef struct {
    u128_0033D398 x0;
    void *x10;
    s32 x14;
    u8 x18;
    u8 x19;
    u16 x1A;
    f32 x1C;
    s32 x20;
    u8 pad24[0xC];
} S_0033D398;

typedef struct {
    u8 pad0[0x8C];
    s32 w8C;
    u8 pad90[0x10];
} E_0033D398;

typedef struct {
    u8 pad0[0x6C];
    f32 f6C;
    u8 pad70[0xF0 - 0x70];
} Row_0033D398;

extern E_0033D398 D_L01_00278BC0_0033D398[];
extern vu0_v4 D_L01_001E18A0 __attribute__((section(".sdata")));
extern u8 D_L01_001E18B0;
extern vu0_v4 D_L01_001E29C0;
extern Hero_0033D398 D_001A4BE0;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L01_001DCFDC;
__asm__(".extern D_L01_001DCFDC, 4");
extern u8 D_001425D2[];
extern Row_0033D398 D_L01_002C5600[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_005003D0(s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004EA7D8(s32);
extern s32 func_0038CAD0(void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_0033D940(void *, void *, s32);
extern void func_L01_0033DBE8(void *);
extern void func_L01_00404A10_0033D398(void *, void *);
extern void func_L01_0033D780(void *);

void func_L01_0033D398(O_0033D398 *o) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    S_0033D398 s;
    s32 i;
    f32 d;

    *(u128_0033D398 *)&v0 = 0;
    if (o->b20 == 0) {
        for (i = 2; i >= 0; i--) {
            D_L01_00278BC0_0033D398[i].w8C = 0;
        }
        o->b20 = 1;
    }
    func_003C2F58(o, 1, &D_L01_001E18A0);
    func_003C2F58(o, 0, &D_L01_001E18B0);
    if (D_001A4BE0.w25C4 == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    func_003C2F58(o, 0, &v10);
    switch (o->b20) {
    case 0:
        o->b20 = 1;
        /* fall through */
    case 1:
        if (D_001A4BE0.b25ED == 0) {
            if (D_001A4BE0.pAC0 != 0) {
                d = func_0038CF00(&D_L01_001E29C0, D_001A4BE0.pAC0 + 0x10) / 50.0f;
                *(u128_0033D398 *)&v20 = *(u128_0033D398 *)(D_001A4BE0.pAC0 + 0x10);
                func_L01_003F6F20(0, o, 0xFF0FFF0F, &v20, 0x26, -1, 4, fabs_asm(0.9f - d * 0.65f), 0.0f, 90.0f, 0.5f,
                                  0.5f, 40.0f, 40.0f);
                __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                        : "=m"(v0) : "m"(*(vu0_v4 *)(D_001A4BE0.pAC0 + 0x10)), "m"(v10) : "vf1", "vf2");
            }
            if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.w1210) != 0 && D_001A4BE0.pAC0 != 0) {
                if (D_001A4BE0.w360 != 0) {
                    D_L01_001DCFDC = 10;
                } else {
                    D_L01_001DCFDC = 3;
                }
                o->b20 = 2;
                func_L01_004EA7D8(-1);
            }
        }
        break;
    case 2:
        if (func_0038CAD0(&D_L01_001DCFDC) != 0) {
            s.x14 = 0x10000;
            s.x20 = 1;
            *(u128_0033D398 *)&s = *(u128_0033D398 *)&v0;
            s.x1C = (D_L01_002C5600 + D_001425D2[0])->f6C;
            s.x10 = o;
            D_001A4BE0.fC00 = 0.0f;
            func_0038CFB8(&s, &s, 1.0f);
            ((f32 *)&s)[2] = 1.0f;
            ((f32 *)&s)[3] = 5627.9248f;
            s.x19 = 2;
            s.x1A = o->xAA;
            s.x18 = 3;
            func_L01_00446978(D_001A4BE0.pAC0, &s);
            o->b20 = 3;
            if (D_001A4BE0.w360 != 0) {
                D_L01_001DCFDC = 12;
                func_L01_0033D940(o, D_001A4BE0.pAC0, 6);
                func_L01_0033D940(o, D_001A4BE0.pAC0, 6);
                func_L01_0033D940(o, D_001A4BE0.pAC0, 6);
            } else {
                D_L01_001DCFDC = 2;
                func_L01_0033D940(o, D_001A4BE0.pAC0, 2);
                func_L01_0033D940(o, D_001A4BE0.pAC0, 2);
                func_L01_0033D940(o, D_001A4BE0.pAC0, 2);
            }
            D_001A4BE0.pAC0 = 0;
        }
        break;
    case 3:
        if (func_0038CAD0(&D_L01_001DCFDC) != 0) {
            D_001A4BE0.fC00 = 1.0f;
            D_L01_001DCFDC = 6;
            o->b20 = 4;
        }
        break;
    case 4:
        if (func_0038CAD0(&D_L01_001DCFDC) != 0) {
            o->b20 = 1;
        }
        break;
    }
    func_L01_0033DBE8(o);
    func_L01_00404A10_0033D398(func_L01_0033D780, o);
}
/* localdecomp:end func_L01_0033D398 */

/* localdecomp:start func_L01_0033D780 */
extern f32 D_L01_001DD010;
__asm__(".extern D_L01_001DD010, 4");
extern u8 D_L01_001E18B0;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L01_0033DED0(void *);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0033D780(void *a0) {
    f32 t;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    s32 c0;
    s32 c1;
    s32 c2;

    D_L01_001DD010 = func_0038DAB8(D_L01_001DD010, 0.15f);
    t = func_0038D098(D_L01_001DD010);
    f20 = (t + 1.0f) * 0.5f;
    f23 = f20 * 0.0625f + 0.0625f;
    f22 = f20 * 0.19999999f + 0.15f;
    f21 = f20 * 0.125f + 0.125f;
    c0 = func_0038DBD8(f20, 0x2F007F00, 0x3F007F00);
    c1 = func_0038DBD8(f20, 0x2F7F7F7F, 0x5F7F7F7F);
    c2 = func_0038DBD8(f20, 0x10003F00, 0x10003F00);
    func_L01_0033DED0(a0);
    func_003D9508(&D_L01_001E18B0, 0x31, c0, 1, f21, 0.125f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0x31, c1, 1, f23, 0.124f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0xB, c2, 1, f22, 0.123f, 0.0f);
}
/* localdecomp:end func_L01_0033D780 */

/* localdecomp:start func_L01_0033D940 */
#include "vu0.h"

typedef struct {
    f32 a[4];
    f32 b[4];
    vu0_v4 start;
    vu0_v4 pos;
    f32 ang0[3];
    f32 tgt0[3];
    f32 scale0[3];
    f32 ang1[3];
    f32 tgt1[3];
    f32 scale1[3];
    s32 life;
    void *key;
    void *parent;
    s32 timer;
    s32 duration;
    s32 started;
} Ent_0033D940;

extern Ent_0033D940 D_L01_00278BC0_0033D940[];
extern u8 D_L01_001E18B0;
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 *func_00382348(void *);
extern void func_L01_00451290(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);

void func_L01_0033D940(void *key, void *parent, s32 time) {
    s32 i;
    vu0_v4 v;
    Ent_0033D940 *list = D_L01_00278BC0_0033D940;

    for (i = 0; i < 3; i++) {
        Ent_0033D940 *e = &list[i];
        f32 *m;
        vu0_v4 *zero = (vu0_v4 *)&D_L01_001E18B0;

        if (e->key != 0) {
            continue;
        }
        e->key = key;
        e->start = *zero;
        e->ang0[0] = func_003824E0(-3.1415927f, 3.1415927f);
        e->ang0[1] = func_003824E0(-3.1415927f, 3.1415927f);
        e->ang0[2] = func_003824E0(-3.1415927f, 3.1415927f);
        e->ang1[0] = func_003824E0(-3.1415927f, 3.1415927f);
        e->ang1[1] = func_003824E0(-3.1415927f, 3.1415927f);
        e->ang1[2] = func_003824E0(-3.1415927f, 3.1415927f);
        e->tgt0[0] = func_L01_00443A18(0.001f, 0.005f);
        e->tgt0[1] = func_L01_00443A18(0.001f, 0.005f);
        e->tgt0[2] = func_L01_00443A18(0.001f, 0.005f);
        e->tgt1[0] = func_L01_00443A18(0.001f, 0.005f);
        e->tgt1[1] = func_L01_00443A18(0.001f, 0.005f);
        e->tgt1[2] = func_L01_00443A18(0.001f, 0.005f);
        e->scale0[0] = func_003824E0(3.25f, 4.75f) * 0.5f;
        e->scale0[1] = func_003824E0(3.25f, 4.75f) * 0.5f;
        e->scale0[2] = func_003824E0(3.25f, 4.75f) * 0.5f;
        e->scale1[0] = func_003824E0(3.25f, 4.75f) * 0.5f;
        e->scale1[1] = func_003824E0(3.25f, 4.75f) * 0.5f;
        e->scale1[2] = func_003824E0(3.25f, 4.75f) * 0.5f;
        e->timer = time;
        qzero(e->a);
        e->duration = time;
        qzero(e->b);
        e->life = 0xC;
        e->parent = parent;
        e->started = 0;
        m = func_00382348(parent);
        if (m != 0) {
            func_L01_00451290(parent, &v, 1);
            func_0038CE20(&v, &v, m[4]);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(e->pos) : "m"(v), "m"(*(vu0_v4 *)((u8 *)parent + 0x10)) : "vf1", "vf2");
        } else {
            e->pos = *(vu0_v4 *)((u8 *)parent + 0x10);
        }
        return;
    }
}
/* localdecomp:end func_L01_0033D940 */

/* localdecomp:start func_L01_0033DBE8 */
#include "vu0.h"

typedef struct {
    f32 a[4];
    f32 b[4];
    vu0_v4 start;
    vu0_v4 pos;
    f32 ang0[3];
    f32 tgt0[3];
    f32 scale0[3];
    f32 ang1[3];
    f32 tgt1[3];
    f32 scale1[3];
    s32 life;
    void *key;
    void *parent;
    s32 timer;
    s32 duration;
    s32 started;
} Ent_0033DBE8;

extern Ent_0033DBE8 D_L01_00278BC0_0033DBE8[];
extern u8 D_L01_001E18B0_0033DBE8;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 *func_00382348(void *);
extern void func_L01_00451290_0033DBE8(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_0038CAD0(void *);

void func_L01_0033DBE8(void *key) {
    s32 i;
    vu0_v4 v;
    vu0_v4 *zero = (vu0_v4 *)&D_L01_001E18B0_0033DBE8;
    Ent_0033DBE8 *list = D_L01_00278BC0_0033DBE8;

    for (i = 0; i < 3; i++) {
        Ent_0033DBE8 *e = &list[i];

        if (e->key != key) {
            continue;
        }
        e->start = *zero;
        if (e->timer != 0) {
            e->ang0[0] = func_0038DAB8(e->ang0[0], e->tgt0[0] * 100.0f);
            e->ang0[1] = func_0038DAB8(e->ang0[1], e->tgt0[1] * 100.0f);
            e->ang0[2] = func_0038DAB8(e->ang0[2], e->tgt0[2] * 100.0f);
            e->ang1[0] = func_0038DAB8(e->ang1[0], e->tgt1[0] * 100.0f);
            e->ang1[1] = func_0038DAB8(e->ang1[1], e->tgt1[1] * 100.0f);
            e->ang1[2] = func_0038DAB8(e->ang1[2], e->tgt1[2] * 100.0f);
        } else {
            e->ang0[0] = func_0038DAB8(e->ang0[0], e->tgt0[0] * 50.0f);
            e->ang0[1] = func_0038DAB8(e->ang0[1], e->tgt0[1] * 50.0f);
            e->ang0[2] = func_0038DAB8(e->ang0[2], e->tgt0[2] * 50.0f);
            e->ang1[0] = func_0038DAB8(e->ang1[0], e->tgt1[0] * 50.0f);
            e->ang1[1] = func_0038DAB8(e->ang1[1], e->tgt1[1] * 50.0f);
            e->ang1[2] = func_0038DAB8(e->ang1[2], e->tgt1[2] * 50.0f);
        }
        e->a[0] = func_0038D098(e->ang0[0]) * e->scale0[0];
        e->a[1] = func_0038D0B0(e->ang0[1]) * e->scale0[1];
        e->a[2] = -func_0038D0B0(e->ang0[2]) * e->scale0[2];
        e->b[0] = func_0038D098(e->ang1[0]) * e->scale1[0];
        e->b[1] = func_0038D0B0(e->ang1[1]) * e->scale1[1];
        e->b[2] = -func_0038D0B0(e->ang1[2]) * e->scale1[2];
        if (e->parent != 0) {
            f32 *m = func_00382348(e->parent);

            if (m != 0) {
                func_L01_00451290_0033DBE8(e->parent, &v, 1);
                func_0038CE20(&v, &v, m[4]);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                        : "=m"(e->pos) : "m"(v), "m"(*(vu0_v4 *)((u8 *)e->parent + 0x10)) : "vf1", "vf2");
            } else {
                e->pos = *(vu0_v4 *)((u8 *)e->parent + 0x10);
            }
            func_0038CDF8(&e->pos, &e->start, &e->pos, 1.0f - (f32)e->timer / (f32)e->duration);
        }
        if (func_0038CAD0(&e->timer)) {
            if (e->started == 0) {
                e->started = 1;
            }
            if (func_0038CAD0(&e->life)) {
                e->key = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_0033DBE8 */

/* localdecomp:start func_L01_0033DED0 */
typedef struct {
    u8 pad0[0x30];
    u8 obj[0x5C];
    void *key;
    u8 pad8[4];
    s32 flag;
    u8 pad9[8];
} Ent_0033DED0;

extern Ent_0033DED0 D_L01_00278BC0[];
extern void func_L01_0033E0C8(void *a, Ent_0033DED0 *b);
extern void func_003D9508(void *o, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14);
extern f32 func_003824E0(f32 a, f32 b);

void func_L01_0033DED0(void *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Ent_0033DED0 *e = &D_L01_00278BC0[i];

        if (e->key == arg0) {
            func_L01_0033E0C8(arg0, e);
            if (e->flag == 0) {
                func_003D9508(e->obj, 0x31, 0x3F007F00, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508(e->obj, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508(e->obj, 0xB, 0x10003F00, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
    }
}
/* localdecomp:end func_L01_0033DED0 */
