#include "common.h"

/* NTSC-U counterpart of func_L11_00316318 (src/levels/11_obani_moons/L11_003161B8.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3161B8;
typedef struct { u8 pad0[0x30]; V4_3161B8 pos; u8 pad40[0x30]; V4_3161B8 rot; } N_3161B8;
extern s32 D_L11_001DE75C_00315F10;
extern N_3161B8 *D_L11_001DEF00_00315F10;
extern void func_L01_003E94A0(s32, void *);
extern void func_L01_003E9510(s32, void *);

/* localdecomp:start func_L11_00315F10 */
#include "vu0.h"
typedef struct { u8 pad0[0x80]; V4_3161B8 pos; V4_3161B8 f90; u8 padA0[0x10]; V4_3161B8 fB0; u8 padC0[0x19E0 - 0xC0]; u8 *hero; u8 pad19E4[0x25C4 - 0x19E4]; s32 mode; } G_316318;
extern G_316318 D_001A4BE0;
extern f32 D_L11_001E0540_00315F10;
extern f32 D_L11_001E0544_00315F10;
extern f32 D_L11_001DEA50_00315F10[2];
extern u8 *D_L11_001DEE1C_00315F10;
extern u8 *D_L11_001DEE20_00315F10;
extern s32 D_L11_001DE940_00315F10;
extern s32 D_L11_001DE990_00315F10;
extern V4_3161B8 D_L11_001E84E0_00315F10;
extern u16 D_001A4DC0[];
extern u8 D_0014275F[];
extern u16 D_001A8C40[];
extern u8 D_001426E0[];
extern void func_L11_00315DB0(u8 *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_003F3918(s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L01_00417F60(s32, s32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern s32 func_003BF5E0(void *);
extern void func_003BFC18(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_0045BE58(s32, s32);
extern void func_00399F90(void);
extern void func_L01_00413778(s32);

void func_L11_00315F10(u8 *a0)
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
        *(V4_3161B8 *)&D_L11_001E0540_00315F10 = *(V4_3161B8 *)D_L11_001DEA50_00315F10;
    }
    if (v[0x34 / 4] != 0) {
        D_001A4DC0[0] = 2;
        func_L11_00315DB0(a0);
    }
    if (a0[0x20] != 1) {
        return;
    }
    if (func_L01_00452F60(D_L11_001DEE1C_00315F10 + (v[0x30 / 4] << 8)) != 0 && v[0x38 / 4] == 0) {
        N_3161B8 *nd = &D_L11_001DEF00_00315F10[v[0x28 / 4]];

        m = nd->pos;
        a = nd->rot;
        func_L01_003E9588(0, &m, &a, 1, 0, 0);
        func_L01_003E94A0(0, &m);
        func_L01_003E9510(0, &a);
        v[0x34 / 4] = 1;
        D_L11_001DE75C_00315F10 = 1;
        v[0x38 / 4] = 1;
        D_0014275F[0] = 1;
    }
    if (func_0037E0F0(pp = &D_001A4BE0.pos, v[8 / 4], 0) != 0 && D_001A4BE0.mode == 0x31) {
        vu0_q t;
        u8 *h;

        *(f32 *)(D_001A4BE0.hero + 0x10) = 151.56f;
        *(f32 *)(D_001A4BE0.hero + 0x14) = 395.59f;
        *(f32 *)(D_001A4BE0.hero + 0x18) = 226.23f;
        h = D_001A4BE0.hero;
        t = *(vu0_q *)(h + 0x10);
        D_L11_001DEA50_00315F10[1] = 400.0f;
        D_L11_001DEA50_00315F10[0] = 200.0f;
        D_L11_001DEA50_00315F10[2] = 200.0f;
        *(vu0_q *)pp = t;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50_00315F10;
        *(V4_3161B8 *)(*(u8 **)(h + 0x68) + 0x420) = *(V4_3161B8 *)(h + 0x10);
        func_L01_003F3918(0, 1);
    }
    if (func_0037E0F0(&D_001A4BE0.pos, v[0x18 / 4], 0) != 0) {
        v[0x1C / 4] = 3600;
    } else if (func_00388398(&v[0x1C / 4]) != 0 && D_001A8C40[0] < 4 && func_L01_00417F60(0x15F7, 0x12E) != 0) {
        v[0x1C / 4] = 3600;
    }
    if (func_0037E0F0(pp = &D_001A4BE0.pos, v[0], 0) != 0 && D_001A4BE0.mode == 0x31) {
        vu0_q t;
        u8 *h;

        *(f32 *)(D_001A4BE0.hero + 0x10) = 151.56f;
        *(f32 *)(D_001A4BE0.hero + 0x14) = 395.59f;
        *(f32 *)(D_001A4BE0.hero + 0x18) = 226.23f;
        h = D_001A4BE0.hero;
        t = *(vu0_q *)(h + 0x10);
        D_L11_001DEA50_00315F10[1] = 400.0f;
        D_L11_001DEA50_00315F10[0] = 200.0f;
        D_L11_001DEA50_00315F10[2] = 200.0f;
        *(vu0_q *)pp = t;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50_00315F10;
        *(V4_3161B8 *)(*(u8 **)(h + 0x68) + 0x420) = *(V4_3161B8 *)(h + 0x10);
        func_L01_003F3918(0, 1);
    }
    if (func_0037E0F0(&D_001A4BE0.pos, v[0], 0) != 0) {
        if (D_L11_001DEA50_00315F10[0] != 526.922f) {
            func_L01_003F3918(0, 1);
        }
        D_L11_001DEA50_00315F10[0] = 526.922f;
        D_L11_001DEA50_00315F10[1] = 200.0f;
        D_L11_001DEA50_00315F10[2] = 819.262f;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50_00315F10;
    } else if (func_0037E0F0(&D_001A4BE0.pos, v[1], 0) != 0) {
        r = 0;
        if (D_L11_001DEA50_00315F10[0] != 200.0f) {
            r = D_L11_001DE940_00315F10 < 5;
            func_L01_003F3918(0, 1);
        }
        D_L11_001DEA50_00315F10[1] = 400.0f;
        D_L11_001DEA50_00315F10[0] = 200.0f;
        D_L11_001DEA50_00315F10[2] = 200.0f;
        *(vu0_q *)&D_001A4BE0.fB0 = *(vu0_q *)D_L11_001DEA50_00315F10;
        if (r != 0) {
            func_L01_004F12C0(&D_001A4BE0.pos, &D_001A4BE0.f90, 0, 1);
            func_L01_003F3918(0, 1);
        }
    }
    if (D_L11_001E0544_00315F10 != D_L11_001DEA50_00315F10[1]) {
        p = D_L11_001DEE1C_00315F10;
        *(V4_3161B8 *)&D_L11_001E0540_00315F10 = *(V4_3161B8 *)D_L11_001DEA50_00315F10;
        for (; p < D_L11_001DEE20_00315F10; p += 0x100) {
            id = *(s16 *)(p + 0xAA);
            if (id == 0x9B9 || id == 0xF05 || id == 0x1B6C || id == 0x1BF6 || func_003BF5E0(p) != 0 || *(s16 *)(p + 0xAA) == 0x1C08) {
                *(u16 *)(p + 0x34) |= 0x100;
                func_003BFC18(p + 0x10, &m, 0);
                func_L01_0044E358(p + 0xC0, &m, o);
                func_00388830(&a, p + 0xE0, 0.5f);
                func_00388830(&b, p + 0xE0, -4.0f);
                vec_add_ab(&a, &a, p + 0x10);
                vec_add_ab(&b, &b, p + 0x10);
                if (func_003CE740(&a, &b, 2, p, 0) != 0) {
                    *(V4_3161B8 *)(p + 0x10) = D_L11_001E84E0_00315F10;
                    func_00388830(&b, p + 0xE0, -0.1f);
                    vec_add_ab(p + 0x10, &b, p + 0x10);
                    func_003BFC18(p + 0x10, &m2, 0);
                    func_L01_0044E358(p + 0xC0, &m2, &o2);
                }
            }
        }
    }
    if (func_0037E0F0(&D_001A4BE0.pos, v[0], 0) != 0) {
        func_L01_0045BE58(v[0x20 / 4], -1);
        n = 4;
        if (D_L11_001DE990_00315F10 != n) {
            func_L01_00413778(n);
            D_L11_001DE990_00315F10 = n;
        }
    } else {
        if (D_001426E0[0x7F] == 0) {
            D_001426E0[0x21] = 1;
            func_00399F90();
            D_001426E0[0x7F] = 1;
            func_00399F90();
        }
        func_L01_0045BE58(v[0x24 / 4], -1);
        n = 3;
        if (D_L11_001DE990_00315F10 != n) {
            func_L01_00413778(n);
            D_L11_001DE990_00315F10 = n;
        }
    }
}
/* localdecomp:end func_L11_00315F10 */
