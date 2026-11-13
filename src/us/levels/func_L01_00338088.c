#include "common.h"

/* NTSC-U counterpart of func_L01_003386E0 (src/levels/shared/L01_003386E0.c) */
/* localdecomp:start func_L01_00338088 */
/* func_L01_00338088: the wrench object's update (wrench_update, config/names.tsv): the swing's sweep
   points and hits, the sparks of the jump attack, and the thrown wrench's flight and return.
   No rac2 or rac4 twin; written from the retail assembly (Opus singletons, 2026-11-08).
   Build needs: "-mvu0-use-vf0-vf2 ... @ps2as" on this file (the VU0 helpers of include/vu0.h, the
   inline float constants, and the scalar globals Ps2EeAs reaches with lui because their .extern
   size comes after the first use) and its config/levels/divs_nops.txt row (0 1). The functions that
   followed it moved unchanged to L01_0033AC58.c, which keeps the old flags.
   What made the last differences go away: a fresh local per loop counter and per spark result,
   function-scope vectors s0..s7 (retail's 0x80 bytes of locals, the hit ball at s0 or s1 spills
   into the next one), the hero state read into the switch variable st (so the switch and both
   range tests keep their andi), and &s4/&s5/pv+0x40 written in place in the thrown state (GCSE
   makes the three spilled pointers in retail's order). */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
typedef union { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; u8 *ptr[0x40]; u128_t q[0x10]; } Obj;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 b[0x80]; } Snd80;
typedef struct { s32 w[11]; } Rec2C;
typedef struct { u8 b[0xF0]; } RecF0;

extern Hero D_001A4BE0;
extern u128_t D_001A4D30[];
extern Snd80 D_001A30B0[];
extern u8 D_001425C0[];
extern u8 D_001D5479;
extern s32 D_L01_001D6694_00338088;
extern s32 D_L01_001DFBC0_00338088;
extern Obj *D_L01_001EAA80[];
extern Obj *D_L01_001EEB00[];
extern u8 *D_L01_00221118[];
extern RecF0 D_L01_002C5640[];
extern Rec2C D_L01_002F6310[];
extern void func_L01_00337228(void);

extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern Obj *func_0037E0B8(Obj *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388880(void *, void *, f32);
extern f32 func_00388770(void *);
extern s32 func_00388398(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern Obj *func_003BCFB0(s32, s32);
extern void func_003BD360(Obj *);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BE418(Obj *, s32, s32);
extern void func_003BE4F0(Obj *, s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern f32 func_003BEBF8(void *, f32, f32);
extern s32 func_003BF5E0(Obj *);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern s32 func_003D00C0(void);
extern void func_L01_003377B8(Obj *);
extern s32 func_L01_00337850(void);
extern s32 func_L01_003378A0(void);
extern void func_L01_003378E0(void *, s32);
extern void func_L01_00337BD8(Obj *);
extern void func_L01_00337E58(Obj *);
extern void func_L01_00337FD0(void *);
extern void func_L01_003F4D78(s32, Obj *, u32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004026A0_00338088(void *, Obj *);
extern void func_L01_00443628(void *, Obj *, s32, f32, void *);
extern void func_L01_00443938(Obj *, Obj *, s32, void *, void *, f32);
extern s32 func_L01_00443AB8(void *, void *, void *, void *, void *, void *, s32);
extern s32 func_L01_00447C40(Obj *);
extern void func_L01_0044B010(Obj *, f32, f32, f32);
extern void func_L01_0044B4B8(void *);
extern void func_L01_0044CB08(void *, Obj *, s32, s32);
extern void func_L01_0044DBC8(void *, void *, f32, f32, f32);
extern void func_L01_00452E70(Obj *, Obj *);
extern u8 *func_L01_004633E8(void *, s32, void *, u32, s32, f32, f32, f32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004C41E8(void *, void *);
extern s32 func_L01_004EAA20(f32);
extern s32 func_L01_004F1068(s32, s32);
extern void func_L01_0050BF40(s32);
extern void func_L01_0050D180(void *, void *, f32);

void func_L01_00338088(Obj *m) {
    V4 s0, s1, s2, s3, s4, s5, s6, s7;
    Obj *pv;
    s32 i1, i2, i3, i4, i5, i6;

    pv = (Obj *)m->ptr[0x68 / 4];
    D_001A4BE0.b[0x121C] = 0;
    if (D_001A4BE0.i[0x1224 / 4] == 3) {
        return;
    }
    if (D_001D5479 != 0 && D_001A4BE0.ptr[0x28D0 / 4] == 0 && D_001A4BE0.b[0x25ED] == 0) {
        if (D_L01_001D6694_00338088 != 2 && D_001A4BE0.i[0x1228 / 4] != 0x7F) {
            Obj *o = func_003BCFB0(0x1B82, 0x630);
            D_001A4BE0.ptr[0x28D0 / 4] = (u8 *)o;
            if (o != 0) {
                func_L01_00452E70(o, m);
            }
        }
    }
    if (D_001A4BE0.i[0x234 / 4] != 0) {
        if (D_001A4BE0.ptr[0x28CC / 4] == 0 && D_L01_001DFBC0_00338088 != 0) {
            Obj *o = func_003BCFB0(0x47, 0x80);
            D_001A4BE0.ptr[0x28CC / 4] = (u8 *)o;
            if (o != 0) {
                func_L01_00452E70(o, m);
                ((Obj *)D_001A4BE0.ptr[0x28CC / 4])->uh[0x34 / 2] |= 0x8000;
                func_003BE418((Obj *)D_001A4BE0.ptr[0x28CC / 4], 1, 0);
                ((Obj *)D_001A4BE0.ptr[0x28CC / 4])->uh[0x34 / 2] |= 2;
                func_L01_0044CB08(D_001A4BE0.ptr[0x25C0 / 4], (Obj *)D_001A4BE0.ptr[0x28CC / 4], 0xE, 0);
            }
        } else {
            func_L01_0044CB08(D_001A4BE0.ptr[0x25C0 / 4], (Obj *)D_001A4BE0.ptr[0x28CC / 4], 0xE, 0);
        }
    } else if (D_001A4BE0.ptr[0x28CC / 4] != 0) {
        func_003BD360((Obj *)D_001A4BE0.ptr[0x28CC / 4]);
        D_001A4BE0.ptr[0x28CC / 4] = 0;
    }

    switch (m->b[0x20]) {
    case 0: {
        s32 ok;
        s32 hit;
        f32 yaw;
        f32 d;
        Rec2C *row;
        s32 st;

        m->ptr[0xB8 / 4] = D_001A4BE0.ptr[0x25C0 / 4];
        st = D_001A4BE0.i[0x25C4 / 4];
        if (st == 1 || st == 0x1D) {
            if (((Obj *)D_001A4BE0.ptr[0x25C0 / 4])->uh[0x34 / 2] & 1) {
                func_L01_003F4D78(0, m, 0xFF917267, 0, 0x25, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
        }
        if (D_001A4BE0.i[0x234 / 4] != 0) {
            s32 st2 = D_001A4BE0.i[0x25C4 / 4];

            if (st2 == 0x13 || st2 == 0x20 || st2 == 0x2A || st2 == 0x72 || st2 == 0x14) {
                {
                    u8 *r;
                    s32 n;
                    f32 s;
                    for (i1 = 0; i1 < 6; i1++) {
                        u32 c;
                        u8 *r;
                        func_003BDA38(m, func_0037E208(2, 9), &s0);
                        s0.x += func_0037E250(-0.02f, 0.02f);
                        s0.y += func_0037E250(-0.02f, 0.02f);
                        s0.z += func_0037E250(-0.02f, 0.02f);
                        func_L01_004C41E8(&m->q[1], &s1);
                        func_003886E8(&s1, &s1, func_0037E250(0.5f, 1.0f) * 0.016666668f);
                        c = func_0037E208(0x40, 0x64) | 0x5F404000;
                        func_L01_0046DCB8(&s0, &s1, func_0037E208(2, 5), c, 1, 0x5F, 0, 0, 84000.0f, 42000.0f, 0.0f);
                    }
                    func_L01_004C41E8(&m->q[1], &s1);
                    func_003886E8(&s1, &s1, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                    s0.x += func_0037E250(-0.02f, 0.02f);
                    s0.y += func_0037E250(-0.02f, 0.02f);
                    s0.z += func_0037E250(-0.02f, 0.02f);
                    n = func_0037E1D8(5) + 1;
                    s = func_0037E250(0.25f, 0.4f) * 210000.0f;
                    r = func_L01_004633E8(&s0, n, &s1, func_0037E208(0x40, 0x50) | 0x404000, 0, 0.0f, 0.99f, 0.995f, s);
                    if (r != 0) {
                        r[3] = 0x48;
                        *(s16 *)(r + 0xA) = 3;
                    }
                }
                if (D_001A4BE0.ptr[0x28CC / 4] != 0) {
                    {
                        u8 *r;
                        s32 n;
                        f32 s;
                        for (i2 = 0; i2 < 6; i2++) {
                            u32 c;
                            u8 *r;
                            func_003BDA38(D_001A4BE0.ptr[0x28CC / 4], func_0037E208(2, 9), &s2);
                            s2.x += func_0037E250(-0.02f, 0.02f);
                            s2.y += func_0037E250(-0.02f, 0.02f);
                            s2.z += func_0037E250(-0.02f, 0.02f);
                            func_L01_004C41E8(&m->q[1], &s3);
                            func_003886E8(&s3, &s3, func_0037E250(0.5f, 1.0f) * 0.016666668f);
                            c = func_0037E208(0x40, 0x64) | 0x5F404000;
                            func_L01_0046DCB8(&s2, &s3, func_0037E208(2, 5), c, 1, 0x5F, 0, 0, 84000.0f, 42000.0f, 0.0f);
                        }
                        func_L01_004C41E8(&m->q[1], &s3);
                        func_003886E8(&s3, &s3, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                        s2.x += func_0037E250(-0.02f, 0.02f);
                        s2.y += func_0037E250(-0.02f, 0.02f);
                        s2.z += func_0037E250(-0.02f, 0.02f);
                        n = func_0037E1D8(5) + 1;
                        s = func_0037E250(0.25f, 0.4f) * 210000.0f;
                        r = func_L01_004633E8(&s2, n, &s3, func_0037E208(0x40, 0x50) | 0x404000, 0, 0.0f, 0.99f, 0.995f, s);
                        if (r != 0) {
                            r[3] = 0x48;
                        }
                    }
                }
            } else {
                {
                    u8 *r;
                    s32 n;
                    f32 s;
                    for (i3 = 0; i3 < 8; i3++) {
                        u32 c;
                        u8 *r;
                        func_003BDA38(m, func_0037E208(2, 9), &s0);
                        s0.x += func_0037E250(-0.02f, 0.02f);
                        s0.y += func_0037E250(-0.02f, 0.02f);
                        s0.z += func_0037E250(-0.02f, 0.02f);
                        func_L01_004C41E8(&m->q[1], &s1);
                        func_003886E8(&s1, &s1, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                        if (func_0037E1D8(4) != 0) {
                            c = func_0037E208(0x40, 0x64) | 0x5F404000;
                        } else {
                            c = (func_0037E208(0x96, 0x64) << 16) | 0x5F002C2C;
                        }
                        r = func_L01_0046DCB8(&s0, &s1, func_0037E208(0xA, 0xF), c, 1, 0x4F, 0, 0, 58800.0f, 27299.998f, 0.0f);
                        if (r != 0) {
                            r[2] = *D_L01_00221118[0x16C / 4];
                        }
                    }
                    func_L01_004C41E8(&m->q[1], &s1);
                    func_003886E8(&s1, &s1, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                    s0.x += func_0037E250(-0.02f, 0.02f);
                    s0.y += func_0037E250(-0.02f, 0.02f);
                    s0.z += func_0037E250(-0.02f, 0.02f);
                    n = func_0037E1D8(5) + 1;
                    s = func_0037E250(0.25f, 0.4f) * 210000.0f;
                    r = func_L01_004633E8(&s0, n, &s1, func_0037E208(0x40, 0x50) | 0x404000, 0, 0.0f, 0.99f, 0.995f, s);
                    if (r != 0) {
                        r[3] = func_0037E1D8(2) != 0 ? 0x44 : 0x48;
                        *(s16 *)(r + 0xA) = 3;
                    }
                }
                if (D_001A4BE0.ptr[0x28CC / 4] != 0) {
                    {
                        u8 *r;
                        s32 n;
                        f32 s;
                        for (i4 = 0; i4 < 8; i4++) {
                            u32 c;
                            u8 *r;
                            func_003BDA38(D_001A4BE0.ptr[0x28CC / 4], func_0037E208(2, 9), &s2);
                            s2.x += func_0037E250(-0.02f, 0.02f);
                            s2.y += func_0037E250(-0.02f, 0.02f);
                            s2.z += func_0037E250(-0.02f, 0.02f);
                            func_L01_004C41E8(&m->q[1], &s3);
                            func_003886E8(&s3, &s3, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                            if (func_0037E1D8(4) != 0) {
                                c = func_0037E208(0x40, 0x64) | 0x5F404000;
                            } else {
                                c = (func_0037E208(0x96, 0x64) << 16) | 0x5F002C2C;
                            }
                            r = func_L01_0046DCB8(&s2, &s3, func_0037E208(0xA, 0xF), c, 1, 0x4F, 0, 0, 58800.0f, 27299.998f, 0.0f);
                            if (r != 0) {
                                r[2] = *D_L01_00221118[0x16C / 4];
                            }
                        }
                        func_L01_004C41E8(&m->q[1], &s3);
                        func_003886E8(&s3, &s3, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                        s2.x += func_0037E250(-0.02f, 0.02f);
                        s2.y += func_0037E250(-0.02f, 0.02f);
                        s2.z += func_0037E250(-0.02f, 0.02f);
                        n = func_0037E1D8(5) + 1;
                        s = func_0037E250(0.25f, 0.4f) * 210000.0f;
                        r = func_L01_004633E8(&s2, n, &s3, func_0037E208(0x40, 0x50) | 0x404000, 0, 0.0f, 0.99f, 0.995f, s);
                        if (r != 0) {
                            r[3] = func_0037E1D8(2) != 0 ? 0x44 : 0x48;
                            *(s16 *)(r + 0xA) = 3;
                        }
                    }
                }
            }
        }
        if (pv != 0 && pv->f[0x70 / 4] != 0.0f) {
            func_L01_004026A0_00338088(func_L01_00337228, m);
        }
        m->u[0x78 / 4] = 0x80909090;
        m->uh[0x34 / 2] |= 0x10;
        st = m->b[0x43];
        switch ((u8)st) {
        case 0:
            break;
        case 0xE:
            if (m->b[0x60] & 2) {
                func_003BE4F0(m, 1, 0, 5);
            }
            return;
        default:
            if (D_001A4BE0.b[0x25EF] != 0) {
                if ((u8)(st - 0xF) >= 2) {
                    func_003BE4F0(m, 0xF, 0, 4);
                } else if ((m->b[0x60] & 2) && (u8)st == 0xF) {
                    func_003BE4F0(m, 0x10, 0, 5);
                }
                return;
            }
            if ((u8)(st - 0xF) < 2) {
                func_003BE4F0(m, 0xE, 0, 2);
                return;
            }
            break;
        }
        if (((m->b[0x60] & 2) || m->b[0x43] == 6) && D_001A4BE0.i[0x25C4 / 4] != 0x37
            && D_001A4BE0.i[0x25CC / 4] != 0x22 && m->b[0x43] != 1) {
            func_003BE4F0(m, 1, 0, 5);
        }
        func_L01_003377B8(m);
        {
            s32 hs = D_001A4BE0.i[0x25C4 / 4];
            if (hs != 0x13 && hs != 0x20 && hs != 0x2A && hs != 0x72 && hs != 0x14) {
                if (m->b[0x43] >= 3) {
                    if (m->b[0x43] < 6) {
                        func_003BE4F0(m, 1, 0, 4);
                    }
                }
            }
        }
        {
            Obj *o = (Obj *)D_001A4BE0.ptr[0x25C0 / 4];
            if (o->b[0x43] != o->b[0x42] || o->b[0x41] - o->b[0x40] >= 3) {
                pv->uh[0x74 / 2]++;
            }
        }
        m->f[0x48 / 4] = D_001A4BE0.f[0xC00 / 4];
        row = &D_L01_002F6310[D_001A4BE0.h[0xBDC / 2]];
        if (D_001A4BE0.i[0x25CC / 4] != 6 && D_001A4BE0.i[0x25C4 / 4] != 0x2A) {
            return;
        }
        ok = 1;
        if (D_001A4BE0.i[0xC0C / 4] != 0 || D_001A4BE0.f[0xC18 / 4] < (f32)row->w[0x1C / 4]
            || (f32)row->w[0x20 / 4] < D_001A4BE0.f[0xC18 / 4]) {
            ok = 0;
        }
        hit = 0;
        if (pv->h[0x7C / 2] != pv->h[0x74 / 2]) {
            u8 a = ((Obj *)D_001A4BE0.ptr[0x25C0 / 4])->b[0x42];
            if (a == ((Obj *)D_001A4BE0.ptr[0x25C0 / 4])->b[0x43]) {
                if (a == 0x17) {
                    s32 x = 0.0f <= D_001A4BE0.f[0xC18 / 4];
                    hit = x;
                } else if (a == 0x18) {
                    s32 x = 0.0f <= D_001A4BE0.f[0xC18 / 4];
                    hit = x;
                } else if (a == 0x19) {
                    s32 x = 12.0f <= D_001A4BE0.f[0xC18 / 4];
                    hit = x;
                } else if (a == 0x28) {
                    s32 x = 23.0f <= D_001A4BE0.f[0xC18 / 4];
                    hit = x;
                }
            }
        }
        if (hit) {
            pv->f[0x70 / 4] = 1.0f;
            pv->h[0x7C / 2] = pv->h[0x74 / 2];
        }
        d = 0.0f;
        D_001A4BE0.q[0xB70 / 16] = D_001A4BE0.q[0xB50 / 16];
        *(u128_t *)(D_001A4BE0.b + 0xB60) = *(u128_t *)(D_001A4BE0.b + 0xB40);
        yaw = D_001A4BE0.f[0x98 / 4];
        func_003BDA38(m, 1, D_001A4BE0.b + 0xB50);
        func_003BDA38(D_001A4BE0.ptr[0x25C0 / 4], 0, D_001A4BE0.b + 0xB40);
        if (D_001A4BE0.i[0x25C4 / 4] == 0x13 || D_001A4BE0.i[0x25C4 / 4] == 0x72 || D_001A4BE0.i[0x25C4 / 4] == 0x2A) {
            yaw = func_00388A28(D_001A4BE0.f[0xB50 / 4] - D_001A4BE0.f[0x80 / 4], D_001A4BE0.f[0xB54 / 4] - D_001A4BE0.f[0x84 / 4]);
            {
                if (D_L01_002F6310[D_001A4BE0.h[0xBDC / 2]].w[1] == 1) {
                    yaw = func_00389380(yaw, -1.5707964f);
                } else {
                    yaw = func_00389380(yaw, 1.5707964f);
                }
            }
        }
        {
            s32 hs;

            vec_sub_ab(&s0, D_001A4BE0.b + 0xB50, D_001A4BE0.b + 0xB40);
            func_00388830(&s0, &s0, func_00388770(&s0) + 0.17f);
            if (D_001A4BE0.i[0x25CC / 4] != 0xF && (hs = D_001A4BE0.i[0x25C4 / 4]) != 0x72 && hs != 0x14) {
                d = func_00389468(D_001A4BE0.f[0x98 / 4], func_00388A28(D_001A4BE0.f[0xB50 / 4] - D_001A4BE0.f[0x80 / 4], D_001A4BE0.f[0xB54 / 4] - D_001A4BE0.f[0x84 / 4]));
                if (d > 1.5707964f) {
                    ok = 0;
                }
                func_L01_00337FD0(&s0);
            }
            vec_add_ba(D_001A4BE0.b + 0xB50, D_001A4BE0.b + 0xB40, &s0);
        }
        if (D_001A4BE0.i[0x25C4 / 4] != 0x2A && D_001A4BE0.i[0x25C4 / 4] != 0x72 && d < 1.2217305f
            && D_001A4BE0.i[0x1B8 / 4] >= 11) {
            f32 ang;

            *(u128_t *)&s0 = D_001A4BE0.q[0x80 / 16];
            s0.z += 0.5f;
            ang = func_00388A28(D_001A4BE0.f[0xB50 / 4] - D_001A4BE0.f[0x80 / 4], D_001A4BE0.f[0xB54 / 4] - D_001A4BE0.f[0x84 / 4]);
            *(u128_t *)&s1 = D_001A4BE0.q[0x80 / 16];
            s1.z += 0.5f;
            s2.x = func_00388960(ang) * 1.4f;
            s2.y = func_00388978(ang) * 1.4f;
            s2.z = 0.0f;
            func_L01_00337FD0(&s2);
            vec_add_ab(&s1, &s1, &s2);
            if (D_001A4BE0.h[0xBDE / 2] == 0 && func_003CE740(&s0, &s1, 2, 0, 0) != 0 && func_003D00C0() != 0
                && (D_L01_001EAA80[0x18 / 4] == 0 || func_L01_00447C40(D_L01_001EAA80[0x18 / 4]) != 0)) {
                D_001A4BE0.h[0xBDE / 2] = 1;
                if (D_001A4BE0.i[0x1228 / 4] != 0x7F) {
                    func_0039FE80(2, 0, m);
                }
                func_L01_00337BD8(m);
                if (D_L01_001EAA80[0x18 / 4] != 0) {
                    if (D_001A4BE0.b[0x25F4] == 0) {
                        s3.x = func_00388960(yaw);
                        s3.y = func_00388978(yaw);
                        s3.z = 0.0f;
                    } else {
                        *(u128_t *)&s3 = D_001A4BE0.q[0];
                    }
                    func_L01_00443938(D_L01_001EAA80[0x18 / 4], m, 0x10000, &D_L01_001EAA80[0x20 / 4], &s3, 1.0f);
                }
            }
        }
        if (D_001A4BE0.i[0x25C4 / 4] == 0x14 && func_L01_004EAA20(27.0f) != 0) {

            if (D_001A4BE0.i[0x1228 / 4] != 0x7F) {
                func_0039FE80(2, 0, m);
            }
            *(u128_t *)&s0 = D_001A4BE0.q[0xB50 / 16];
            *(u128_t *)&s1 = D_001A4BE0.q[0xB50 / 16];
            func_L01_0050D180(&s0, &s0, 0.7f);
            func_L01_0050D180(&s1, &s1, -0.9f);
            if (func_003CE740(&s0, &s1, 2, 0, 0) != 0) {
                func_L01_00337BD8(m);
            }
        }
        if (!ok) {
            return;
        }
        {
            f32 rad;
            f32 k;
            RecF0 *tb = &D_L01_002C5640[D_001425C0[9]];
            f32 dmg;

            k = 1.0f;
            dmg = *(f32 *)&tb->b[0x6C];
            if (D_001A4BE0.i[0x25C4 / 4] == 0x14) {
                dmg = *(f32 *)&tb->b[0x70];
                k = 1.55f;
            }
            if (D_001A4BE0.i[0x234 / 4] != 0) {
                dmg *= 50.0f;
            }
            s3.x = func_00388960(yaw);
            s3.y = func_00388978(yaw);
            s3.z = 0.0f;
            if (D_001A4BE0.i[0x234 / 4] != 0) {
                func_L01_00443628(&s0, m, 0x110000, dmg, &s3);
            } else {
                func_L01_00443628(&s0, m, 0x10000, dmg, &s3);
            }
            func_00388880(&s0, &s0, k);
            s0.w = 5627.925f;
            ((u8 *)&s0)[0x19] = 1;
            ((u16 *)&s0)[0x1A / 2] = m->uh[0xAA / 2];
            s0.z = 1.0f;
            ((u8 *)&s0)[0x18] = 0;
            if (D_001A4BE0.b[0x25F4] != 0) {
                qzero(&s3);
                func_L01_0044DBC8(D_001A4BE0.ptr[0x25C0 / 4], &s3, 1.0f, 0.0f, 1.0f);
            }
            if (func_L01_00443AB8(D_001A4BE0.b + 0xB40, D_001A4BE0.b + 0xB50, D_001A4BE0.b + 0xB60, D_001A4BE0.b + 0xB70, D_001A4BE0.ptr[0x25C0 / 4], &s0, 5) != 0
                && D_L01_001EAA80[0x18 / 4] != 0 && func_L01_003378A0() == 0 && D_001A4BE0.h[0xBDE / 2] == 0) {
                if (D_L01_001EAA80[0x18 / 4] == 0 || (Obj *)D_L01_001EAA80[0x18 / 4]->ptr[0x24 / 4] == 0
                    || ((Obj *)D_L01_001EAA80[0x18 / 4]->ptr[0x24 / 4])->b[0x46] != 0x14) {
                    D_001A4BE0.h[0xBDE / 2] = 1;
                    if (D_001A4BE0.i[0x1228 / 4] != 0x7F) {
                        func_0039FE80(func_L01_00337850(), 0, m);
                    }
                    func_L01_00337BD8(m);
                }
            }
            vec_sub_ab(&s5, D_001A4BE0.b + 0xB50, D_001A4BE0.b + 0xB40);
            func_00388830(&s5, &s5, func_00388770(&s5) - 0.085f);
            vec_add_ab(&s4, &s5, D_001A4BE0.b + 0xB40);
            rad = 0.35f;
            if (D_001A4BE0.i[0x25CC / 4] == 0xF) {
                rad = 0.7f;
            }
            if (D_001A4BE0.i[0x25C4 / 4] == 0x14) {
                rad = 0.47f;
            }
            if (func_003CF790(&s4, 0, rad, D_001A4BE0.ptr[0x25C0 / 4], &s0) != 0) {
                if ((D_L01_001EEB00[0] == 0 || D_L01_001EEB00[0]->ptr[0x24 / 4] == 0
                     || ((Obj *)D_L01_001EEB00[0]->ptr[0x24 / 4])->b[0x46] != 0x12)
                    && func_L01_003378A0() == 0 && D_001A4BE0.h[0xBDE / 2] == 0) {
                    D_001A4BE0.h[0xBDE / 2] = 1;
                    func_0039FE80(func_L01_00337850(), 0, m);
                    func_L01_00337BD8(m);
                }
            }
        }
        break;
    }
    case 10:
    case 11: {
        s32 reached;
        s32 close;
        s32 hit;
        f32 dist;
        f32 k;
        RecF0 *tb;

        if (D_001A4BE0.i[0x234 / 4] != 0) {
            {
                u8 *r;
                s32 n;
                f32 s;
                for (i5 = 0; i5 < 8; i5++) {
                    u32 c;
                    u8 *r;
                    func_003BDA38(m, func_0037E208(2, 9), &s0);
                    s0.x += func_0037E250(-0.02f, 0.02f);
                    s0.y += func_0037E250(-0.02f, 0.02f);
                    s0.z += func_0037E250(-0.02f, 0.02f);
                    func_L01_004C41E8(&m->q[1], &s1);
                    func_003886E8(&s1, &s1, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                    if (func_0037E1D8(4) != 0) {
                        c = func_0037E208(0x40, 0x64) | 0x5F404000;
                    } else {
                        c = (func_0037E208(0x96, 0x64) << 16) | 0x5F002C2C;
                    }
                    r = func_L01_0046DCB8(&s0, &s1, func_0037E208(0xA, 0xF), c, 1, 0x4F, 0, 0, 58800.0f, 27299.998f, 0.0f);
                    if (r != 0) {
                        r[2] = *D_L01_00221118[0x16C / 4];
                    }
                }
                func_L01_004C41E8(&m->q[1], &s1);
                func_003886E8(&s1, &s1, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                s0.x += func_0037E250(-0.02f, 0.02f);
                s0.y += func_0037E250(-0.02f, 0.02f);
                s0.z += func_0037E250(-0.02f, 0.02f);
                n = func_0037E1D8(5) + 1;
                s = func_0037E250(0.25f, 0.4f) * 210000.0f;
                r = func_L01_004633E8(&s0, n, &s1, func_0037E208(0x40, 0x50) | 0x404000, 0, 0.0f, 0.99f, 0.995f, s);
                if (r != 0) {
                    r[3] = func_0037E1D8(2) != 0 ? 0x44 : 0x48;
                    *(s16 *)(r + 0xA) = 3;
                }
            }
            if (D_001A4BE0.ptr[0x28CC / 4] != 0) {
                {
                    u8 *r;
                    s32 n;
                    f32 s;
                    for (i6 = 0; i6 < 8; i6++) {
                        u32 c;
                        u8 *r;
                        func_003BDA38(D_001A4BE0.ptr[0x28CC / 4], func_0037E208(2, 9), &s2);
                        s2.x += func_0037E250(-0.02f, 0.02f);
                        s2.y += func_0037E250(-0.02f, 0.02f);
                        s2.z += func_0037E250(-0.02f, 0.02f);
                        func_L01_004C41E8(&m->q[1], &s3);
                        func_003886E8(&s3, &s3, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                        if (func_0037E1D8(4) != 0) {
                            c = func_0037E208(0x40, 0x64) | 0x5F404000;
                        } else {
                            c = (func_0037E208(0x96, 0x64) << 16) | 0x5F002C2C;
                        }
                        r = func_L01_0046DCB8(&s2, &s3, func_0037E208(0xA, 0xF), c, 1, 0x4F, 0, 0, 58800.0f, 27299.998f, 0.0f);
                        if (r != 0) {
                            r[2] = *D_L01_00221118[0x16C / 4];
                        }
                    }
                    func_L01_004C41E8(&m->q[1], &s3);
                    func_003886E8(&s3, &s3, func_0037E250(0.4f, 1.0f) * 0.016666668f);
                    s2.x += func_0037E250(-0.02f, 0.02f);
                    s2.y += func_0037E250(-0.02f, 0.02f);
                    s2.z += func_0037E250(-0.02f, 0.02f);
                    n = func_0037E1D8(5) + 1;
                    s = func_0037E250(0.25f, 0.4f) * 210000.0f;
                    r = func_L01_004633E8(&s2, n, &s3, func_0037E208(0x40, 0x50) | 0x404000, 0, 0.0f, 0.99f, 0.995f, s);
                    if (r != 0) {
                        r[3] = func_0037E1D8(2) != 0 ? 0x44 : 0x48;
                        *(s16 *)(r + 0xA) = 3;
                    }
                }
            }
        }
        m->ptr[0xB8 / 4] = D_001A4BE0.ptr[0x25C0 / 4];
        D_001A4BE0.b[0x121C] = 2;
        if (m->b[0x20] == 10) {
            s32 id = D_001A4BE0.i[0x2790 / 4];
            Snd80 *e;
            if (id == -1 || (e = &D_001A30B0[id], *(u8 **)&e->b[0xDC] != D_001A4BE0.ptr[0x25C0 / 4]) || e->b[0xD0] == 0) {
                D_001A4BE0.i[0x2790 / 4] = func_0039FE80(0xB, 4, D_001A4BE0.ptr[0x25C0 / 4]);
            }
        }
        func_L01_0044B010(m, 0.0f, 0.0f, 0.4072435f);
        if (D_001A4BE0.h[0xBDE / 2] != 0 && func_00388398(&pv->b[0x6C]) != 0) {
            D_001A4BE0.h[0xBDE / 2] = 0;
        }
        if (D_001A4BE0.b[0x25F4] == 0) {
            f32 g = func_003BE7F0(&m->q[1], 0, 0, 0.5f);
            f32 y = m->f[0x18 / 4];
            if (y - g < 0.8f) {
                g += 0.55f;
                if (y < g) {
                    func_003BEBF8(&m->f[0x18 / 4], g, 0.06666667f);
                } else {
                    func_003BEBF8(&m->f[0x18 / 4], g, 0.016666668f);
                }
            }
        }
        *(u128_t *)&s0 = m->q[1];
        if (m->b[0x20] == 10) {
            *(u128_t *)&s1 = D_001A4D30[0];
            func_003886E8(&s1, &s1, 0.98f);
            vec_add_ba(&m->q[1], &m->q[1], &s1);
            func_00388830(&s1, &pv->q[4], pv->f[0x60 / 4]);
            vec_add_ab(&m->q[1], &m->q[1], &s1);
            pv->f[0x64 / 4] += 0.000787037f;
            func_003BEBF8(&pv->f[0x60 / 4], 0.0f, pv->f[0x64 / 4]);
            if (pv->f[0x60 / 4] == 0.0f) {
                m->b[0x20] = 11;
            }
        } else {
            reached = 0;
            *(u128_t *)&s1 = D_001A4D30[0];
            func_003886E8(&s1, &s1, 0.98f);
            vec_add_ba(&m->q[1], &m->q[1], &s1);
            func_L01_00337E58(m);
            vec_sub_ab(&s1, (u8 *)D_001A4D30 + 0x1090, &m->q[1]);
            pv->f[0x64 / 4] += 0.00025f;
            pv->f[0x60 / 4] += pv->f[0x64 / 4];
            dist = func_00388770(&s1);
            if (dist / pv->f[0x60 / 4] < 5.0f && m->b[0x43] != 1) {
                func_003BE4F0(m, 1, 0, 5);
            }
            if (dist <= pv->f[0x60 / 4]) {
                pv->f[0x60 / 4] = dist;
                reached = 1;
            }
            func_00388830(&s1, &s1, pv->f[0x60 / 4]);
            vec_add_ab(&m->q[1], &m->q[1], &s1);
            if (dist / pv->f[0x60 / 4] < 4.0f && D_001A4BE0.i[0xC20 / 4] != -1) {
                s32 id;
                Snd80 *e;
                func_L01_0050BF40(2);
                D_001A4BE0.i[0xC24 / 4] = 0x1A;
                id = D_001A4BE0.i[0x2790 / 4];
                if (id != -1 && (e = &D_001A30B0[id], *(u8 **)&e->b[0xDC] == D_001A4BE0.ptr[0x25C0 / 4]) && e->b[0xD0] != 0) {
                    func_0039FB08(id);
                }
                D_001A4BE0.i[0x2790 / 4] = -1;
            }
            close = 0;
            if (D_001A4BE0.i[0x25C4 / 4] == 0x31 || D_001A4BE0.i[0x25C4 / 4] == 0x65 || dist > 32.0f) {
                close = 1;
            }
            if (reached || close) {
                s32 id;
                Snd80 *e;
                if (!close) {
                    func_L01_004F1068(5, 0);
                }
                id = D_001A4BE0.i[0x2790 / 4];
                if (id != -1 && (e = &D_001A30B0[id], *(u8 **)&e->b[0xDC] == D_001A4BE0.ptr[0x25C0 / 4]) && e->b[0xD0] != 0) {
                    func_0039FB08(id);
                }
                D_001A4BE0.i[0x2790 / 4] = -1;
                func_L01_0044B4B8(D_001A4BE0.b + 0x1CE0);
                D_001A4BE0.b[0x121A] = 0;
                m->b[0x20] = 0;
            }
        }
        hit = 0;
        if (func_003CE740(&s0, &m->q[1], 2, 0, 0) != 0 && func_003D00C0() != 0) {
            if (D_L01_001EAA80[0x18 / 4] == 0 || func_003BF5E0(D_L01_001EAA80[0x18 / 4]) == 0) {
                hit = ((s32 *)D_L01_001EAA80)[0x1C / 4] != 0;
            }
        }
        if (hit || pv->h[0x76 / 2] != 0) {
            pv->h[0x76 / 2] = 0;
            if (D_001A4BE0.h[0xBDE / 2] == 0) {
                pv->i[0x6C / 4] = 0x1E;
                D_001A4BE0.h[0xBDE / 2] = 1;
                func_0039FE80(2, 0, m);
            }
            if (m->b[0x20] == 10) {
                func_L01_00337BD8(m);
                pv->f[0x60 / 4] *= 0.5f;
                m->b[0x20] = 11;
            }
        }
        k = 1.2f;
        if (m->b[0x20] == 11) {
            k = -0.37f;
        }
        func_00388830(&s4, &pv->q[4], k);
        tb = &D_L01_002C5640[D_001425C0[9]];
        {
            f32 dmg = *(f32 *)&tb->b[0x6C];
            if (D_001A4BE0.i[0x234 / 4] != 0) {
                func_L01_00443628(&s1, m, 0x110000, dmg * 50.0f, &s4);
            } else {
                func_L01_00443628(&s1, m, 0x10000, dmg, &s4);
            }
        }
        s1.z = 1.0f;
        if (D_001A4BE0.b[0x25F4] != 0) {
            qzero(&s1);
            func_L01_0044DBC8(D_001A4BE0.ptr[0x25C0 / 4], &s1, k, 0.0f, 1.0f);
        }
        ((u8 *)&s1)[0x19] = 1;
        s1.w = 5627.925f;
        ((u16 *)&s1)[0x1A / 2] = D_001A4BE0.uh[0xBEC / 2] + 1;
        ((u8 *)&s1)[0x18] = 0;
        func_003BDA38(m, 1, &s5);
        if (func_003CF790(&s5, 0, 0.4f, D_001A4BE0.ptr[0x25C0 / 4], &s1) != 0
            || (func_003BDA38(m, 0, &s5), func_003CF790(&s5, 0, 0.4f, D_001A4BE0.ptr[0x25C0 / 4], &s1) != 0)) {
            if (D_001A4BE0.h[0xBDE / 2] == 0 && D_L01_001EAA80[0x18 / 4] != 0
                && (D_L01_001EAA80[0x18 / 4]->ptr[0x24 / 4] == 0 || ((Obj *)D_L01_001EAA80[0x18 / 4]->ptr[0x24 / 4])->b[0x46] != 0x14)) {
                Obj *q = func_0037E0B8(D_L01_001EAA80[0x18 / 4]);
                if (q == 0 || q->h[0x1C / 2] == 0 || (Obj *)q->ptr[0x18 / 4] != m) {
                    *(u128_t *)&s7 = D_L01_001EAA80[0x18 / 4]->q[1];
                    func_003BEB58(&s6, &s5, &s7, 0.5f);
                    func_L01_003378E0(&s6, 5);
                    pv->i[0x6C / 4] = 0x1E;
                    D_001A4BE0.h[0xBDE / 2] = 1;
                    func_0039FE80(func_L01_00337850(), 0, m);
                }
            }
        }
        break;
    }
    }
}
/* localdecomp:end func_L01_00338088 */
