#include "common.h"

/* NTSC-U counterpart of func_L05_003B00A8 (src/levels/05_daxx/L05_003AFF38.c) */
#include "vu0.h"
typedef struct { u8 pad[0x2A0]; s32 ids[3]; } V_3B00A8;

/* localdecomp:start func_L05_003AE190 */
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))

extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern s16 D_001CD018[];
extern u8 *D_L05_001DFC1C;
extern u8 *D_L05_001DFD00;
extern u8 D_001A4BE0[];
extern u8 D_00142660[];
extern s32 D_001A7430[];
extern s32 D_00142668[];
extern u8 D_L05_001D9B20[8];
extern u8 D_L05_001DAF70;
extern u8 D_L05_001D66B0_003AE190;
extern u8 D_L05_001E2780[];
extern u8 *D_L05_0022092C[];
extern vu0_v4 D_L05_001DE7F0 __attribute__((section(".sdata")));
__asm__(".extern D_L05_001DE7F0, 4");

extern void func_L05_003AF3C8(u8 *);
extern void func_L05_003AF1E0(u8 *);
extern void func_L05_003AF858(u8 *);
extern void func_L05_003AFAC8(u8 *);
extern void func_L05_003AFB20(u8 *);
extern u8 *func_L05_003AFCB0(u8 *, void *);
extern void func_L05_003AFDD8(u8 *);
extern s32 func_L05_003AFF60(s32, s32);
extern void func_L05_003B0F20(u8 *);
extern u8 *func_L05_00360E30(u8 *, vu0_v4 *, vu0_v4 *, s32, s32, u8, f32);
extern void func_L05_003AE020(u8 *, f32, f32, f32, f32, s32, s32, s32);
extern void func_L05_003AFF70(u8 *);
extern void func_L05_003B0288(u8 *);
extern void func_L05_003B0748(u8 *);
extern void func_L05_003B0AB0(u8 *);
extern s32 func_L01_0032FE90_003AE190(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_004026A0(void *, void *);
extern s32 func_003883C8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_L01_0040C040(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_003BD360(void *);
extern void func_L01_00438430(s32);
extern void func_003C4F30();
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_0039C8A8(s32, s32, s32);
extern void func_L01_0045BE58(s32, s32);
extern void func_0039CBA0(void);
extern u8 *func_L01_0046CA58(void *, void *, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern void func_L01_0049FDB0(u8 *, u8 *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);


void func_L05_003AE190(u8 *m)
{
    vu0_v4 v90;
    vu0_v4 mtx[4];
    vu0_v4 vE0;
    vu0_v4 vF0;
    s32 t;
    u8 *v;
    u8 *o;
    s32 *p;
    s32 *q0;
    s32 *ids;
    s32 i;
    s32 j;
    f32 f;

    v = PTR(m, 0x68);
    func_L05_003AF3C8(m);
    func_L05_003AF1E0(m);
    if (D_001BBC40[U8(m, 0xB0) + (D_001D545C << 4)] & 0x80) {
        s32 *pp = (s32 *)(v + 0x2A0);
        u8 *o2;
        if (D_001CD018[0] == S32(v, 0x2C8)) {
            func_0039CBA0();
            func_0039C8A8(0, 1, 0x400);
        }
        for (i = 0; i < 2; i++) {
            u8 *q = D_L05_001DFC1C + (*pp++ << 8);
            S32(q, 0x98) = 0;
            U16(q, 0x34) = (U16(q, 0x34) | 0x41) & ~0x1000;
            func_L01_004A6DF8(q, 1);
        }
        o2 = D_L05_001DFC1C + (S32(v, 0x2A8) << 8);
        U16(o2, 0x34) &= ~0x41;
        U16(o2, 0x34) |= U16(PTR(o2, 0x24), 0x44) & 0x1000;
        S32(o2, 0x98) = S32(PTR(o2, 0x24), 0x10);
        func_003BD360(m);
        return;
    }
    switch (U8(m, 0x20)) {
    case 1:
        func_L01_00441FB8(m, 2, -1);
        break;
    case 2:
        ids = ((V_3B00A8 *)v)->ids;
        p = ids;
        ids += U8(v, 0x2C0);
        o = D_L05_001DFC1C + (*ids << 8);
        if (func_0037E0F0(D_001A4BE0 + 0x80, S32(v, 0x2C4), 0) == 0) {
            break;
        }
        {
            u8 *g1 = D_001A4BE0;
            if (S32(g1, 0x25CC) == 0xE && o == PTR(g1, 0xA54)) {
                return;
            }
        }
        F32(m, 0xF8) = func_00388A28(F32(v, 0x260) - F32(m, 0x10), F32(v, 0x264) - F32(m, 0x14));
        D_L05_001DAF70 = 1;
        func_L05_003AFB20(m);
        func_L05_003AFAC8(m);
        func_L05_003AF858(m);
        U8(v, 0x2B9) = 2;
        q0 = p;
        for (j = 0; j < 2; j++) {
            o = D_L05_001DFC1C;
            o += *q0++ << 8;
            func_L01_00447D00(o, D_L05_001D9B20, 0, 0.5f, 1.0f, 5.0f, 2.5f, 9.0f, 1.5f, 15.0f, 10, 3, 16, -1, 1, 1, -1, 0, 0x1010001);
            S32(o, 0x98) = 0;
            U16(o, 0x34) = (U16(o, 0x34) | 0x41) & ~0x1000;
            func_L01_004A6DF8(o, 1);
        }
        func_0039CBA0();
        func_0039C8A8(S32(v, 0x2C8), 1, 0x400);
        {
            u8 *h = D_00142660;
            u8 *g2 = D_001A4BE0;
            S32(g2, 0x2850) = S32(h, 8);
        }
        func_L01_00441FB8(m, 3, -1);
        break;
    case 3:
        if (func_L01_00452EC8(m)) {
            func_L01_004A72A8(3, 4, m, 0x1A13);
            S16(v, 0x2B4) = 120;
        }
        if (func_003883C8(v + 0x2B4)) {
            D_001A7430[0] = D_00142668[0];
            func_L01_00441FB8(m, 6, -1);
            U16(m, 0x34) |= 0x4000;
            break;
        }
        func_L01_004026A0(func_L05_003AFF70, m);
        break;
    case 6:
        if (func_L01_00452EC8(m)) {
            if (U8(v, 0x2B8) >= 2) {
                func_L01_004A72A8(3, 0, m, 0x1A13);
            }
            U8(v, 0x2B9) = 1;
            S16(v, 0x2B4) = 120;
        }
        func_L05_003AF858(m);
        if (U8(v, 0x2B8) < 2) {
            func_L05_003B0F20(m);
            break;
        }
        if (func_003883C8(v + 0x2B4)) {
            func_L01_00441FB8(m, 7, -1);
            break;
        }
        func_L01_004026A0(func_L05_003AFF70, m);
        break;
    case 7:
        if (func_L01_00452EC8(m)) {
            S16(v, 0x2B4) = 0x14;
        }
        if (func_003883C8(v + 0x2B4)) {
            func_L05_003AFB20(m);
            func_L05_003AFAC8(m);
            func_L05_003AF858(m);
            U8(v, 0x2B9) = 2;
            func_L01_00441FB8(m, 8, -1);
        }
        break;
    case 8:
        if (func_L01_00452EC8(m)) {
            func_L01_004A72A8(3, 0, m, 0x1A13);
            S16(v, 0x2B4) = 120;
        }
        func_L05_003AF858(m);
        if (func_003883C8(v + 0x2B4)) {
            func_L05_003B0F20(m);
            break;
        }
        func_L01_004026A0(func_L05_003AFF70, m);
        break;
    case 9:
        if (func_L01_00452EC8(m)) {
            F32(v, 0x284) = 4.6f;
            F32(v, 0x290) = 22.0f;
            U8(v, 0x2BB) = 3;
            U8(v, 0x2BE) = 1;
            S16(v, 0x2B4) = 0x96;
            S32(v, 0x270) = 0;
        }
        func_L05_003AF858(m);
        F32(v, 0x248) = -0.17453292f;
        F32(v, 0x1C8) = 0.17453292f;
        if (func_003883C8(v + 0x2B4)) {
            func_L01_00441FB8(m, 10, -1);
        }
        break;
    case 10:
        if (func_L01_00452EC8(m)) {
            S16(v, 0x2B4) = 0x8C;
            func_L01_004A72A8(2, 4, m, 0x1A13);
        }
        func_L05_003AF858(m);
        F32(v, 0x248) = 0.69813168f;
        F32(v, 0x1C8) = -0.69813168f;
        func_L05_003AFDD8(m);
        func_L01_00402498(func_L05_003B0288, m);
        if (func_003883C8(v + 0x2B4)) {
            if (U8(v, 0x2B8) >= 4) {
                func_L01_00441FB8(m, 11, -1);
            } else {
                U8(v, 0x2BE) = 0;
                func_L05_003AFB20(m);
                func_L01_004A6D70(2, m);
                func_L01_00441FB8(m, 6, -1);
            }
        }
        break;
    case 11:
        if (func_L01_00452EC8(m)) {
            S16(v, 0x2B4) = 0x8C;
        }
        func_L05_003AF858(m);
        F32(v, 0x248) = -0.17453292f;
        F32(v, 0x1C8) = 0.17453292f;
        func_L05_003AFDD8(m);
        func_L01_00402498(func_L05_003B0288, m);
        if (func_003883C8(v + 0x2B4)) {
            U8(v, 0x2BE) = 0;
            func_L05_003AFB20(m);
            func_L01_004A6D70(2, m);
            func_L01_00441FB8(m, 6, -1);
        }
        break;
    case 12:
        if (func_L01_00452EC8(m)) {
            U8(v, 0x2BA) = func_0037E208(0, 1);
            switch (U8(v, 0x2BA)) {
            case 0:
                F32(v, 0x27C) = func_003893C8(F32(v, 0x278), 0.87266463f);
                U8(v, 0x2BB) = 2;
                break;
            case 1:
                F32(v, 0x27C) = func_00389380(F32(v, 0x278), 0.87266463f);
                U8(v, 0x2BB) = 1;
                break;
            }
            F32(v, 0x284) = 4.6f;
            F32(v, 0x290) = 22.0f;
            U8(v, 0x2BE) = 1;
            U8(v, 0x2BF) = 1;
            S16(v, 0x2B4) = 0xB4;
        }
        func_L05_003AF858(m);
        if (func_003883C8(v + 0x2B4)) {
            switch (U8(v, 0x2BA)) {
            case 0:
                F32(v, 0x27C) = func_00389380(F32(v, 0x278), 1.0821041f);
                break;
            case 1:
                F32(v, 0x27C) = func_003893C8(F32(v, 0x278), 1.0821041f);
                break;
            }
            func_L01_00441FB8(m, 0xD, -1);
        }
        break;
    case 13:
        if (func_L01_00452EC8(m)) {
            S16(v, 0x2B4) = 0xF0;
            func_L01_004A72A8(2, 4, m, 0x1A13);
        }
        func_L05_003AF858(m);
        func_L05_003AFDD8(m);
        func_L01_00402498(func_L05_003B0288, m);
        if (func_003883C8(v + 0x2B4)) {
            U8(v, 0x2BE) = 0;
            U8(v, 0x2BF) = 0;
            func_L05_003AFB20(m);
            func_L01_004A6D70(2, m);
            func_L01_00441FB8(m, 0xE, -1);
        }
        break;
    case 14:
        if (func_L01_00452EC8(m)) {
            S16(v, 0x2B4) = 0x4B;
        }
        func_L05_003AF858(m);
        if (func_003883C8(v + 0x2B4)) {
            func_L01_00441FB8(m, 6, -1);
        }
        break;
    case 15:
        if (func_L01_00452EC8(m)) {
            U8(v, 0x2BD) = func_0037E208(4, 6);
            S16(v, 0x2B4) = 120;
            U8(v, 0x2BC) = 0;
        }
        t = func_L05_003AFF60(U8(v, 0x2BA), 0);
        f = F32(m, 0x2C);
        f = f * 0.0009765625f;
        func_003C4F30(m, 1, &t, mtx);
        func_003886E8(&v90, &mtx[3], f);
        if (S16(v, 0x2B4) < 6) {
            u8 *r;
            *(vu0_q *)&vE0 = *(vu0_q *)&v90;
            f = 3 - S16(v, 0x2B4) / 2;
            f = f * 0.8f;
            f = f + 1.5f;
            f *= func_0037E250(0.9f, 1.1f);
            func_003BF6A8(&vE0, 0.3f);
            r = func_L01_0046CA58(&vE0, m, 0x30204080, -1, 0, 10, f * 210000.0f, 0.0f, 0, -1, 0.92f, func_0037E1D8(2) ? 0xD0 : 0x30, 0);
            if (r != 0) {
                r[2] = *D_L05_0022092C[0];
            }
        }
        func_L05_003AF858(m);
        if (func_003883C8(v + 0x2B4)) {
            u8 *r;
            func_003888C8(&v90, &v90, m + 0xC0);
            vec_add_ab(&v90, &v90, m + 0x10);
            *(vu0_q *)&vE0 = *(vu0_q *)(v + 0x140);
            if (func_L01_0040C040(&vE0, &D_L05_001DE7F0) > 118.80999f) {
                vec_sub_ab(&vF0, &vE0, &D_L05_001DE7F0);
                vF0.z = 0.0f;
                func_00388830(&vF0, &vF0, 10.9f);
                vec_add_ab(&vE0, &D_L05_001DE7F0, &vF0);
            }
            r = func_L05_003AFCB0(m, &vE0);
            if (r != 0) {
                vE0.z = F32(r, 0x18) + 0.2f;
            } else {
                vE0.z = 32.35f;
            }
            func_L05_00360E30(m, &v90, &vE0, (s32)r, 0x3C, 1, U8(v, 0x44));
            func_L01_004A72A8(1, 0, m, 0x1A13);
            if (U8(v, 0x2BC) >= U8(v, 0x2BD)) {
                func_L01_00441FB8(m, 0x10, -1);
            } else {
                U8(v, 0x2BC)++;
                S16(v, 0x2B4) = 0x1E;
                U8(v, 0x2BA) ^= 1;
            }
        }
        break;
    case 16:
        if (func_L01_00452EC8(m)) {
            S16(v, 0x2B4) = 0x3C;
        }
        func_L05_003AF858(m);
        if (func_003883C8(v + 0x2B4)) {
            func_L01_00441FB8(m, 6, -1);
        }
        break;
    case 17:
        if (func_L01_00452EC8(m)) {
            F32(v, 0x27C) = 0.0f;
            S16(v, 0x2B4) = 0x87;
            func_L01_004A72A8(5, 0, m, 0x1A13);
        }
        if (S16(v, 0x2B4) % 6 == 0) {
            func_L05_003AE020(m, 2.0f, 3.0f, 1.5f, F32(m, 0x2C) / F32(PTR(m, 0x24), 0x24), 5, 0xFF, 2);
            if (S16(v, 0x2B4) % 42 == 0) {
                u8 *e = D_L05_001E2780;
                F32(e, 0x11A0) = 1.0f;
                S32(e, 0x11A8) = 0x1E;
                S32(e, 0x11AC) = 0;
                func_L01_004A72A8(5, 0, m, 0x1A13);
            }
        }
        func_L05_003AF858(m);
        F32(m, 0x18) -= 0.5f;
        if (func_003883C8(v + 0x2B4)) {
            func_L01_00441FB8(m, 0x12, -1);
        }
        break;
    case 18:
        if (func_L01_00452EC8(m)) {
            S32(v, 0x29C) = 0;
            S16(v, 0x2B4) = 0x1E;
            func_L01_004A72A8(5, 0, m, 0x1A13);
        }
        if (S16(v, 0x2B4) % 6 == 0) {
            func_L05_003AE020(m, 0.0f, 3.0f, 1.7f, F32(m, 0x2C) / F32(PTR(m, 0x24), 0x24), 5, 0xFF, 2);
        }
        func_L05_003AF858(m);
        F32(m, 0x18) -= 0.25f;
        if (func_003883C8(v + 0x2B4)) {
            func_L01_00441FB8(m, 0x13, -1);
            break;
        }
        func_L01_00402498(func_L05_003B0748, m);
        break;
    case 19:
        if (func_L01_00452EC8(m)) {
            S32(v, 0x29C) = 0;
            S16(v, 0x2B4) = 0x50;
            F32(v, 0x298) = func_0037E2A8();
            U8(v, 0x2C1) = 1;
            func_L01_004A72A8(5, 0, m, 0x1A13);
        }
        if (S16(v, 0x2B4) % 6 == 0) {
            func_L05_003AE020(m, 0.0f, 5.0f, 2.0f, F32(m, 0x2C) / F32(PTR(m, 0x24), 0x24), 5, 0xFF, 2);
        }
        if (func_003883C8(v + 0x2B4)) {
            func_L01_00441FB8(m, 0x15, -1);
            break;
        }
        S32(m, 0x98) = 0;
        U16(m, 0x34) = (U16(m, 0x34) | 0x41) & ~0x1000;
        func_L01_004A6DF8(m, 1);
        func_L01_00402498(func_L05_003B0AB0, m);
        if (U8(v, 0x2C1) != 0) {
            func_L01_0044ED60(m, 0x3FFF, &D_L05_001D66B0_003AE190, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            {
                u8 *e = D_L05_001E2780;
                F32(e, 0x40) = 0.15f;
                S32(e, 0x48) = 0x1E;
                S32(e, 0x2C) = 0;
            }
            func_00388830(&mtx[0], m + 0xE0, 1.0f);
            vec_add_ab(&v90, m + 0x10, &mtx[0]);
            func_L01_0032FE90_003AE190(&v90, 0, 0x19, 0, 0x28, 0x19, 0x23, 1, 1.5f, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            U8(v, 0x2C1) = 0;
        }
        break;
    case 21:
        func_L01_0045BE58(0, S32(v, 0x2CC));
        func_L01_004412D0(m, 0, 3);
        func_L01_00438430(U8(m, 0xB0));
        {
            u8 *a = D_L05_001DFD00 + (S32(v, 0x2C4) << 7);
            func_L01_0049FDB0(a + 0x30, a + 0x70);
        }
        D_L05_001DAF70 = 0;
        {
            u8 *b;
            ids = ((V_3B00A8 *)v)->ids;
            b = D_L05_001DFC1C + (ids[2] << 8);
            U16(b, 0x34) &= ~0x41;
            U16(b, 0x34) |= U16(PTR(b, 0x24), 0x44) & 0x1000;
            S32(b, 0x98) = S32(PTR(b, 0x24), 0x10);
        }
        func_L01_004A72A8(5, 0, m, 0x1A13);
        func_003BD360(m);
        break;
    }
}
/* localdecomp:end func_L05_003AE190 */
