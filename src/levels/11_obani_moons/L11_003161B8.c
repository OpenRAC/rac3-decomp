#include "common.h"

/* localdecomp:start func_L11_003161B8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3161B8;
typedef struct { u8 pad0[0x30]; V4_3161B8 pos; u8 pad40[0x30]; V4_3161B8 rot; } N_3161B8;
typedef struct { u8 pad0[0x28]; s32 from; s32 to; s32 f30; s32 f34; } Vars_3161B8;
__asm__(".extern D_L11_001DE75C, 16");
extern s32 D_L11_001DE75C;
__asm__(".extern D_L11_001DEF00, 16");
extern N_3161B8 *D_L11_001DEF00;
extern void func_L01_003EB5E0(s32, s32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);

void func_L11_003161B8(u8 *a0)
{
    Vars_3161B8 *v = *(Vars_3161B8 **)(a0 + 0x68);
    V4_3161B8 pos;
    V4_3161B8 rot;
    V4_3161B8 a;
    V4_3161B8 b;
    f32 f;

    if (*(u16 *)(a0 + 0x96) < 0xAA) {
        *(u16 *)(a0 + 0x96) += 1;
    } else {
        func_L01_003EB5E0(0, 0);
        D_L11_001DE75C = 0;
        v->f34 = 0;
        *(u16 *)(a0 + 0x96) = 0xAA;
    }
    f = (f32)*(u16 *)(a0 + 0x96) / 170.0f;
    func_0038CDF8(&pos, &D_L11_001DEF00[v->from].pos, &D_L11_001DEF00[v->to].pos, f);
    a = D_L11_001DEF00[v->from].rot;
    b = D_L11_001DEF00[v->to].rot;
    rot.z = func_0038DAB8(func_0038DB00(b.z, a.z) * f, a.z);
    rot.y = func_0038DAB8(func_0038DB00(b.y, a.y) * f, a.y);
    rot.x = func_0038DAB8(func_0038DB00(b.x, a.x) * f, a.x);
    func_L01_003EB350(0, &pos);
    func_L01_003EB3C0(0, &rot);
}
/* localdecomp:end func_L11_003161B8 */

/* localdecomp:start func_L11_00316318 */
#include "vu0.h"
typedef struct { u8 pad0[0x80]; V4_3161B8 pos; V4_3161B8 f90; u8 padA0[0x10]; V4_3161B8 fB0; u8 padC0[0x19E0 - 0xC0]; u8 *hero; u8 pad19E4[0x25C4 - 0x19E4]; s32 mode; } G_316318;
extern G_316318 D_001A4BE0;
extern f32 D_L11_001E0540;
extern f32 D_L11_001E0544;
extern f32 D_L11_001DEA50[2];
extern u8 *D_L11_001DEE1C;
extern u8 *D_L11_001DEE20;
extern s32 D_L11_001DE940;
extern s32 D_L11_001DE990;
extern V4_3161B8 D_L11_001E84E0;
extern u16 D_001A4DC0[];
extern u8 D_0014275F[];
extern u16 D_001A8C40[];
extern u8 D_001426E0[];
extern void func_L11_003161B8(u8 *);
extern s32 func_L01_00456250(void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_003F5AC0(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0041A5B0(s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern s32 func_003C4B50(void *);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_0039EF28(void);
extern void func_L01_00415DC8(s32);

void func_L11_00316318(u8 *a0)
{
    s32 *v = *(s32 **)(a0 + 0x68);
    u8 *p;
    s32 r;
    s32 n;
    s16 id;
    V4_3161B8 *pp;
    V4_3161B8 m;
    V4_3161B8 a;
    V4_3161B8 o[3];
    V4_3161B8 b;
    V4_3161B8 m2;
    V4_3161B8 o2;
    char buf[0x20];

    if (a0[0x20] == 0) {
        a0[0x20] = 1;
        a0[0x30] = 0xFF;
        *(V4_3161B8 *)&D_L11_001E0540 = *(V4_3161B8 *)D_L11_001DEA50;
    }
    if (v[0x34 / 4] != 0) {
        D_001A4DC0[0] = 2;
        func_L11_003161B8(a0);
    }
    if (a0[0x20] != 1) {
        return;
    }
    if (func_L01_00456250(D_L11_001DEE1C + (v[0x30 / 4] << 8)) != 0 && v[0x38 / 4] == 0) {
        N_3161B8 *nd = &D_L11_001DEF00[v[0x28 / 4]];

        m = nd->pos;
        a = nd->rot;
        func_L01_003EB438(0, &m, &a, 1, 0, 0);
        func_L01_003EB350(0, &m);
        func_L01_003EB3C0(0, &a);
        v[0x34 / 4] = 1;
        D_L11_001DE75C = 1;
        v[0x38 / 4] = 1;
        D_0014275F[0] = 1;
    }
    if (func_00382380(pp = &D_001A4BE0.pos, v[8 / 4], 0) != 0 && D_001A4BE0.mode == 0x31) {
        vu0_q t;
        u8 *h;

        *(f32 *)(D_001A4BE0.hero + 0x10) = 151.56f;
        *(f32 *)(D_001A4BE0.hero + 0x14) = 395.59f;
        *(f32 *)(D_001A4BE0.hero + 0x18) = 226.23f;
        h = D_001A4BE0.hero;
        t = *(vu0_q *)(h + 0x10);
        D_L11_001DEA50[1] = 400.0f;
        D_L11_001DEA50[0] = 200.0f;
        D_L11_001DEA50[2] = 200.0f;
        *(vu0_q *)pp = t;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50;
        *(V4_3161B8 *)(*(u8 **)(h + 0x68) + 0x420) = *(V4_3161B8 *)(h + 0x10);
        func_L01_003F5AC0(0, 1);
    }
    if (func_00382380(&D_001A4BE0.pos, v[0x18 / 4], 0) != 0) {
        v[0x1C / 4] = 3000;
    } else if (func_0038CAD0(&v[0x1C / 4]) != 0 && D_001A8C40[0] < 4 && func_L01_0041A5B0(0x15F7, 0x12E) != 0) {
        v[0x1C / 4] = 3000;
    }
    if (func_00382380(pp = &D_001A4BE0.pos, v[0], 0) != 0 && D_001A4BE0.mode == 0x31) {
        vu0_q t;
        u8 *h;

        *(f32 *)(D_001A4BE0.hero + 0x10) = 151.56f;
        *(f32 *)(D_001A4BE0.hero + 0x14) = 395.59f;
        *(f32 *)(D_001A4BE0.hero + 0x18) = 226.23f;
        h = D_001A4BE0.hero;
        t = *(vu0_q *)(h + 0x10);
        D_L11_001DEA50[1] = 400.0f;
        D_L11_001DEA50[0] = 200.0f;
        D_L11_001DEA50[2] = 200.0f;
        *(vu0_q *)pp = t;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50;
        *(V4_3161B8 *)(*(u8 **)(h + 0x68) + 0x420) = *(V4_3161B8 *)(h + 0x10);
        func_L01_003F5AC0(0, 1);
    }
    if (func_00382380(&D_001A4BE0.pos, v[0], 0) != 0) {
        if (D_L11_001DEA50[0] != 526.922f) {
            func_L01_003F5AC0(0, 1);
        }
        D_L11_001DEA50[0] = 526.922f;
        D_L11_001DEA50[1] = 200.0f;
        D_L11_001DEA50[2] = 819.262f;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50;
    } else if (func_00382380(&D_001A4BE0.pos, v[1], 0) != 0) {
        r = 0;
        if (D_L11_001DEA50[0] != 200.0f) {
            r = D_L11_001DE940 < 5;
            func_L01_003F5AC0(0, 1);
        }
        D_L11_001DEA50[1] = 400.0f;
        D_L11_001DEA50[0] = 200.0f;
        D_L11_001DEA50[2] = 200.0f;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50;
        if (r != 0) {
            func_L01_004F50C8(&D_001A4BE0.pos, &D_001A4BE0.f90, 0, 1);
            func_L01_003F5AC0(0, 1);
        }
    }
    if (D_L11_001E0544 != D_L11_001DEA50[1]) {
        p = D_L11_001DEE1C;
        *(V4_3161B8 *)&D_L11_001E0540 = *(V4_3161B8 *)D_L11_001DEA50;
        for (; p < D_L11_001DEE20; p += 0x100) {
            id = *(s16 *)(p + 0xAA);
            if (id == 0x9B9 || id == 0xF05 || id == 0x1B6C || id == 0x1BF6 || func_003C4B50(p) != 0 || *(s16 *)(p + 0xAA) == 0x1C08) {
                *(u16 *)(p + 0x34) |= 0x100;
                func_003C5180(p + 0x10, &m, 0);
                func_L01_004515D8(p + 0xC0, &m, o);
                func_0038CF68(&a, p + 0xE0, 0.5f);
                func_0038CF68(&b, p + 0xE0, -4.0f);
                vec_add_ab(&a, &a, p + 0x10);
                vec_add_ab(&b, &b, p + 0x10);
                if (func_003D3CB0(&a, &b, 2, p, 0) != 0) {
                    *(V4_3161B8 *)(p + 0x10) = D_L11_001E84E0;
                    func_0038CF68(&b, p + 0xE0, -0.1f);
                    vec_add_ab(p + 0x10, &b, p + 0x10);
                    func_003C5180(p + 0x10, &m2, 0);
                    func_L01_004515D8(p + 0xC0, &m2, &o2);
                }
            }
        }
    }
    if (func_00382380(&D_001A4BE0.pos, v[0], 0) != 0) {
        func_L01_0045F1E8(v[0x20 / 4], -1);
        n = 4;
        if (D_L11_001DE990 != n) {
            func_L01_00415DC8(n);
            D_L11_001DE990 = n;
        }
    } else {
        if (D_001426E0[0x7F] == 0) {
            D_001426E0[0x21] = 1;
            func_0039EF28();
            D_001426E0[0x7F] = 1;
            func_0039EF28();
        }
        func_L01_0045F1E8(v[0x24 / 4], -1);
        n = 3;
        if (D_L11_001DE990 != n) {
            func_L01_00415DC8(n);
            D_L11_001DE990 = n;
        }
    }
}
/* localdecomp:end func_L11_00316318 */
