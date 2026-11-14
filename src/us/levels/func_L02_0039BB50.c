#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L02_0039D7D0 (src/levels/02_florana/L02_0039C730.c) */
/* localdecomp:start func_L02_0039BB50 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39BB50;
typedef struct { u8 p0[0x18]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } __attribute__((aligned(16))) M_39BB50;
typedef struct { u8 p0[0x9C]; s32 w9C; } B_39BB50;
typedef struct {
    u8 p0[0x90];
    f32 rot[4];
    u8 pA0[0x20E - 0xA0];
    s16 h20E;
    u8 p210[0x35C - 0x210];
    void *f35C;
    s32 f360;
    u8 p364[0x22D0 - 0x364];
    f32 f22D0;
    f32 f22D4;
    f32 f22D8;
    u8 p22DC[0x25C0 - 0x22DC];
    B_39BB50 *body;
    u8 p25C4[0x2888 - 0x25C4];
    s16 h2888;
} H_39BB50;
typedef struct {
    s32 w0;
    s32 f4;
    f32 f8;
    u8 bC;
    u8 pD;
    u8 bE;
    u8 bF;
    V4_39BB50 pos;
    s32 w20;
    s32 w24;
} S_39BB50;
typedef struct {
    u8 p0[0x10];
    V4_39BB50 pos;
    u8 b20;
    u8 p21[0x68 - 0x21];
    S_39BB50 *st;
    u8 p6C[0xAA - 0x6C];
    u16 hAA;
    u8 pAC[0xB8 - 0xAC];
    s32 wB8;
    u8 pBC[0xF8 - 0xBC];
    f32 fF8;
} O_39BB50;
typedef struct { u8 p0[0x10]; V4_39BB50 pos; u8 p20[0x8A]; s16 hAA; } Mob_39BB50;
typedef struct { u8 p0[0x5C]; u8 *p5C; } T_39BB50;
typedef struct { V4_39BB50 a, b, c; } VV_39BB50;
typedef union { M_39BB50 m; VV_39BB50 v; } U_39BB50;

extern H_39BB50 D_001A4BE0;
extern u8 D_001A30B0[];
extern f32 D_L02_002EF270[];
extern Mob_39BB50 *D_L02_001EC140[];
extern T_39BB50 D_L02_0021E158;
extern V4_39BB50 D_L02_001E1380;
extern s32 D_001D545C_sda_0039BB50;
__asm__(".extern D_001D545C_sda_0039BB50, 4");
extern f32 D_001DDC38_sda;
__asm__(".extern D_001DDC38_sda, 4");

extern void func_L02_0039C568(void *);
extern s32 func_L01_00417EA0(void);
extern void func_L01_00443610(void *, void *, s32, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern f32 func_003BEB48(f32, f32, f32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L02_004CF3B8(s32, s32);
extern f32 func_00388730(void *, void *);
extern f32 func_00389380(f32, f32);
extern s32 func_003CF790(void *, s32, f32, s32, s32);
extern s32 func_L01_00453210(void *, s32);
extern s32 func_L01_004F1068(s32, s32);
extern s32 func_L01_003EFFE0(s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_L01_00447C00(f32);
extern void func_003BF2F8(void *, void *, f32);
extern void func_00389118(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_0046CF70(void *, void *, s32, f32);
extern s32 func_L01_004A6D20(void *, s32);

void func_L02_0039BB50(O_39BB50 *o) {
    U_39BB50 u0;
    U_39BB50 u1;
    S_39BB50 *st;

    func_L02_0039C568(o);
    st = o->st;
    if (D_001A4BE0.f35C == o && D_001A4BE0.f360 >= 2) {
        func_L01_00443610(&u0.m, o, 0x10001, func_L01_00417EA0() != 0 ? D_L02_002EF270[D_001D545C_sda_0039BB50] : 1.0f);
        u0.m.b19 = 1;
        u0.m.h1A = o->hAA;
        u0.m.b18 = 0;
        func_L01_00443840(D_001A4BE0.body, &u0.m);
    }
    switch (o->b20) {
    case 2:
        if (func_00388398(&st->f4)) {
            o->b20 = 3;
            st->f4 = 30;
        }
        break;
    case 3:
        if (func_00388398(&st->f4)) {
            o->b20 = 4;
            st->bC = 0;
            st->f4 = 20;
            st->f8 = 0.05f;
            st->w20 = func_0039FE80(0, 4, o);
        }
        break;
    case 4:
        if (func_00388398(&st->f4)) {
            o->b20 = 5;
            st->f4 = 90;
            st->f8 = 0.011111111f;
        } else {
            *(u128_t *)&u0.v.b = 0;
            u0.v.b.x = func_003BEB48(4.6f, 0.0f, (f32)st->f4 * st->f8);
            u0.v.a = u0.v.b;
            func_003888C8(&u0.v.a, &u0.v.a, (u8 *)o + 0xC0);
            vec_add_ab(&o->pos, &st->pos, &u0.v.a);
            if (st->w24 != 0 && st->bC != 0) {
                func_L02_004CF3B8(0x31, 1);
                D_001A4BE0.body->w9C = -1;
                if (0.0f < func_00388730((u8 *)o + 0xF0, D_001A4BE0.rot)) {
                    D_001A4BE0.rot[2] = func_00389380(o->fF8, 1.5707964f);
                } else {
                    D_001A4BE0.rot[2] = func_00389380(o->fF8, -1.5707964f);
                }
                D_001A4BE0.f22D4 = 0.2f;
                D_001A4BE0.f22D8 = 1.3f;
                D_001A4BE0.f22D0 = 1.3f;
                D_001A4BE0.h2888 = 1;
            }
        }
        if (st->w24 != 0) {
            s32 found;
            s32 n;
            s32 i;
            void *mp;
            f32 w;
            *(u128_t *)&u0.v.a = 0;
            u0.v.a.x = 7.5f;
            u0.v.a.z = 1.5f;
            found = 0;
            func_003888C8(&u0.v.a, &u0.v.a, (u8 *)o + 0xC0);
            vec_add_ab(&u0.v.b, &st->pos, &u0.v.a);
            if (st->bC == 0 && st->f4 < 3 && st->w0 != -1) {
                n = func_003CF790(&u0.v.b, 0, D_001DDC38_sda, o->wB8, 0);
                if (n != 0) {
                    *(u128_t *)&u0.v.c = 0;
                    u0.v.c.x = -1.0f;
                    u0.v.c.y = 1.0f;
                    u0.v.c.w = 5627.925f;
                    for (i = 0; i < n; i++) {
                        if (D_L02_001EC140[i]->hAA == 0x18BD) {
                            continue;
                        }
                        if (func_L01_00453210(&D_L02_001EC140[i]->pos, st->w0) == 0) {
                            continue;
                        }
                        if (D_L02_001EC140[i]->hAA == 0) {
                            st->bC = 1;
                        }
                        mp = &u1.m;
                        w = func_L01_00417EA0() != 0 ? D_L02_002EF270[D_001D545C_sda_0039BB50] : 1.0f;
                        func_L01_00443628(mp, o, 0x10001, &u0.v.c, w);
                        u1.m.h1A = o->hAA;
                        u1.m.b18 = 0;
                        u1.m.b19 = 1;
                        found = 1;
                        func_L01_00443840(D_L02_001EC140[i], &u1.m);
                    }
                }
            }
            if (found) {
                func_0039FE80(3, 0, o);
                if (st->bC != 0) {
                    func_L01_004F1068(0x14, 0);
                    func_L01_003EFFE0(0x12, 0);
                    D_001A4BE0.h20E = 0x2D;
                }
            }
        }
        if (o->b20 == 5) {
            s32 cnt;
            s32 i;
            *(u128_t *)&u0.v.a = 0;
            u0.v.a.x = 3.2f;
            u0.v.a.z = 1.5f;
            cnt = 0x4B;
            func_003888C8(&u0.v.a, &u0.v.a, (u8 *)o + 0xC0);
            vec_add_ba(&u0.v.a, &o->pos, &u0.v.a);
            if (20.0f < func_00388800(&o->pos, &D_L02_001E1380)) {
                cnt = 0x19;
            }
            for (i = 0; i < cnt; i++) {
                f32 spd;
                f32 ang;
                u8 *r;
                s32 k;
                spd = func_0037E250(0.25f, 1.5f) * 210000.0f;
                ang = func_L01_00440918(0.0f, 0.06981317f);
                func_003BF2F8(&u1, (u8 *)o + 0xC0, func_L01_00447C00((f32)i * 0.41887903f + ang));
                func_00389118(&u0.v.c, (u8 *)o + 0xE0, &u1);
                vec_add_ab(&u0.v.b, &u0.v.a, &u0.v.c);
                func_003886E8(&u0.v.c, &u0.v.c, func_0037E250(3.0f, 5.0f) * 0.016666668f);
                k = func_0037E1D8(3) - 1;
                r = func_L01_0046C468(&u0.v.b, &u0.v.c, func_0037E208(40, 70), 0x7F7F7F, k, 0x40, 0, spd, spd, 0.0f, 0);
                if (r != 0) {
                    u8 pv = *D_L02_0021E158.p5C;
                    r[3] = 0x44;
                    r[2] = pv;
                }
                if (func_0037E1D8(3) == 0) {
                    func_003886E8(&u0.v.c, &u0.v.c, 4.0f);
                    func_003BF6A8(&u0.v.c, 0.033333335f);
                    func_L01_0046CF70(&u0.v.b, &u0.v.c, func_0037E208(10, 20), 0.0f);
                }
            }
            if (func_L01_004A6D20(o, st->w20) != 0) {
                s32 h = st->w20;
                if (h != -1) {
                    u8 *slot = D_001A30B0 + (h << 7);
                    if (*(void **)(slot + 0xDC) == o && *(u8 *)(slot + 0xD0) != 0) {
                        func_0039FB08(h);
                    }
                }
                st->w20 = -1;
            }
            func_0039FE80(1, 0, o);
        }
        break;
    case 5:
        if (func_00388398(&st->f4)) {
            if (st->bF != 0) {
                o->b20 = 3;
                st->f4 = 30;
            } else {
                o->b20 = 1;
            }
            if (func_L01_004A6D20(o, st->w20) != 0) {
                s32 h = st->w20;
                if (h != -1) {
                    u8 *slot = D_001A30B0 + (h << 7);
                    if (*(void **)(slot + 0xDC) == o && *(u8 *)(slot + 0xD0) != 0) {
                        func_0039FB08(h);
                    }
                }
                st->w20 = -1;
            }
        } else {
            if (func_L01_004A6D20(o, st->w20) == 0) {
                st->w20 = func_0039FE80(2, 4, o);
            }
            *(u128_t *)&u0.v.b = 0;
            u0.v.b.x = func_003BE6A8(0.0f, 4.6f, (f32)st->f4 * st->f8);
            u0.v.a = u0.v.b;
            func_003888C8(&u0.v.a, &u0.v.a, (u8 *)o + 0xC0);
            vec_add_ab(&o->pos, &st->pos, &u0.v.a);
        }
        if (st->w24 != 0 && st->bC != 0) {
            if (st->f4 < 60) {
                if (st->f4 >= 41) {
                    f32 t;
                    func_L02_004CF3B8(0x74, 1);
                    D_001A4BE0.body->w9C = -1;
                    t = 1.0f / (f32)(st->f4 - 40);
                    D_001A4BE0.f22D8 = 1.3f - t * 0.3f;
                    D_001A4BE0.f22D4 = t * 0.8f + 0.2f;
                    D_001A4BE0.f22D0 = 1.3f - t * 0.3f;
                    D_001A4BE0.h2888 = 1;
                } else {
                    func_L02_004CF3B8(0, 1);
                    D_001A4BE0.body->w9C = 0;
                    D_001A4BE0.h2888 = 0;
                    st->bC = 0;
                }
            } else {
                func_L02_004CF3B8(0x31, 1);
                D_001A4BE0.body->w9C = -1;
                if (0.0f < func_00388730((u8 *)o + 0xF0, D_001A4BE0.rot)) {
                    D_001A4BE0.rot[2] = func_00389380(o->fF8, 1.5707964f);
                } else {
                    D_001A4BE0.rot[2] = func_00389380(o->fF8, -1.5707964f);
                }
                D_001A4BE0.f22D4 = 0.2f;
                D_001A4BE0.f22D8 = 1.3f;
                D_001A4BE0.f22D0 = 1.3f;
                D_001A4BE0.h2888 = 1;
            }
        }
        break;
    case 1:
        if (st->bF != 0) {
            if (st->bE == 0) {
                st->f4 = 0;
            } else if (st->bE == 1) {
                st->f4 = 30;
            } else {
                st->f4 = 60;
            }
            o->b20 = 2;
            st->bF = 0;
        }
        break;
    }
}
/* localdecomp:end func_L02_0039BB50 */
