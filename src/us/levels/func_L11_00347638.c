#include "common.h"

/* NTSC-U counterpart of func_L11_00348538 (src/levels/11_obani_moons/L11_00348538.c) */
/* localdecomp:start func_L11_00347638 */
#include "vu0.h"
typedef struct { u8 pad0[0x80]; vu0_v4 f80; u8 pad90[0x60]; vu0_v4 fF0; vu0_v4 f100; u8 pad110[0x90]; f32 f1A0; u8 pad1A4[0x38]; u16 f1DC; u8 pad1DE[0x35C - 0x1DE]; u8 *f35C; u8 pad360[0x25C4 - 0x360]; s32 mode; } G_348538;
typedef struct { f32 f0; f32 f4; f32 f8; f32 fC; u8 pad10[0xA]; u16 f1A; u8 pad1C[2]; u8 f1E; u8 pad1F; vu0_v4 f20; } P_348538;
typedef struct { s32 f0; s32 f4; u8 pad8[4]; f32 fC; vu0_v4 f10; vu0_v4 f20; s32 f30; s32 f34; s32 f38; s32 f3C; P_348538 *f40; } V_348538;
typedef struct { u8 pad0[0x30]; f32 f30; f32 f34; u8 pad38[0x48]; } M_348538;
typedef struct { u8 pad0[0x10]; f32 f10; f32 f14; u8 pad18[0x1C]; u16 f34; u8 pad36[0xCA]; } N_348538;
typedef struct { u8 pad0[0xD0]; u8 fD0; u8 padD1[0xB]; u8 *fDC; } E_348538;
extern G_348538 D_001A4BE0;
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern s32 D_L11_001D6694_00347638;
extern s32 D_001D545C;
extern f32 D_L11_001DBBE8;
extern f32 D_L11_001DBBEC;
__asm__(".extern D_L11_001DD1D8, 4");
extern f32 D_L11_001DD1D8;
__asm__(".extern D_L11_001DD1DC, 4");
extern f32 D_L11_001DD1DC;
__asm__(".extern D_L11_001DD1E0, 4");
extern f32 D_L11_001DD1E0;
__asm__(".extern D_L11_001DD1E4, 4");
extern f32 D_L11_001DD1E4;
__asm__(".extern D_L11_001DD1F0, 4");
extern vu0_v4 D_L11_001DD1F0 __attribute__((section(".sdata")));
__asm__(".extern D_L11_001DE940_00347638, 4");
extern s32 D_L11_001DE940_00347638;
extern u8 *D_L11_001DEE1C_00347638;
__asm__(".extern D_L11_001DEF00_00347638, 4");
extern M_348538 *D_L11_001DEF00_00347638;
extern vu0_v4 D_L11_001E84E0_00347638;
extern void func_003BFC18(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003BD360(void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L11_00347F88(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_00388800(void *, void *);
extern void func_00388880(void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388730(void *, void *);
extern u8 *func_L01_003F08D8(s32, s32);
extern void func_L01_003F0980(s32, void *);
extern void func_L11_00347DA0(void *);
extern void func_L01_0040C040(void *, void *);
extern void func_0039FB08(s32);

void func_L11_00347638(u8 *a0)
{
    V_348538 *v = *(V_348538 **)(a0 + 0x68);
    vu0_v4 t[8];
    vu0_q x, y, r;
    f32 f20, f21, f22, d, zz;
    s32 n;
    char buf[0x20];

    if (D_L11_001D6694_00347638 == 2) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        *(u16 *)(a0 + 0x34) |= 0x100;
        func_003BFC18(a0 + 0x10, &t[0], 0);
        func_L01_0044E358(a0 + 0xC0, &t[0], &t[1]);
        func_00388830(&t[4], a0 + 0xE0, 0.5f);
        func_00388830(&t[5], a0 + 0xE0, -4.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t[4]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t[4]) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t[5]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t[5]) : "j"(x));
        if (func_003CE740(&t[4], &t[5], 2, a0, 0) != 0) {
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&D_L11_001E84E0_00347638;
            func_00388830(&t[5], a0 + 0xE0, -0.1f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)(a0 + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t[5]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(a0 + 0x10)) : "j"(r));
            func_003BFC18(a0 + 0x10, &t[6], 0);
            func_L01_0044E358(a0 + 0xC0, &t[6], &t[7]);
        }
        if (D_001D545C == 0x10) {
            D_L11_001DBBEC = D_L11_001DD1D8;
        }
        n = v->f0;
        if (n != -1) {
            *(f32 *)(a0 + 0xF8) = func_00388A28(*(f32 *)(a0 + 0x10) - D_L11_001DEF00_00347638[n].f30,
                                                *(f32 *)(a0 + 0x14) - D_L11_001DEF00_00347638[n].f34);
        } else {
            if (v->f4 == n) {
                func_003BD360(a0);
                return;
            }
            *(f32 *)(a0 + 0xF8) = func_00388A28(*(f32 *)(a0 + 0x10) - ((N_348538 *)D_L11_001DEE1C_00347638)[v->f4].f10,
                                                *(f32 *)(a0 + 0x14) - ((N_348538 *)D_L11_001DEE1C_00347638)[v->f4].f14);
        }
        v->f30 = -1;
        a0[0x30] = 0xFF;
        *(u16 *)(a0 + 0x34) |= 0x2000;
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (D_001A4BE0.f35C == a0) {
            func_L11_00347F88(a0, &v->f20);
            D_L11_001DBBE8 = (v->f20.z - D_001A4BE0.f80.z) * 2.5f;
            if (D_L11_001DBBE8 < 37.0f) {
                D_L11_001DBBE8 = 37.0f;
            }
        }
        if (D_001A4BE0.mode == 0x86) {
            if (D_001A4BE0.f35C != a0) {
                break;
            }
            zz = D_001A4BE0.fF0.z;
            f21 = 0.0f;
            if (f21 < zz) {
                func_0039FE80(1, 0, a0);
                f22 = 0.5f;
                if (D_001D545C == 0x10) {
                    f22 = 0.3f;
                }
                d = func_00388800(&D_001A4BE0.f80, &v->f20);
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4BE0.f80));
                f20 = D_L11_001DBBEC;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v->f20));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
                f20 = f20 * 0.00027777778450399637f;
                __asm__("sqc2 %1, %0" : "=m"(t[0]) : "j"(r));
                t[0].z = f21;
                f20 = f20 * d;
                f20 = f20 * f22;
                f20 = f20 / D_L11_001DBBE8;
                func_00388880(&v->f10, &t[0], sqrt_asm((f20 + f20) * d));
                func_00388880(&D_001A4BE0.fF0, &D_001A4BE0.fF0, f21);
                v->fC = f20;
                func_L01_00441FB8(a0, 2, -1);
            }
        } else if ((D_L11_001DE940_00347638 & 0xF) == (((s32)a0 >> 8) & 0xF)) {
            if (v->f4 != -1 && (((N_348538 *)D_L11_001DEE1C_00347638)[v->f4].f34 & 1) != 0) {
                func_L01_00441FB8(a0, 3, -1);
            }
        }
        break;
    case 2:
        if (D_001A4BE0.mode == 0x86) {
            f21 = func_003887A0(&v->f10);
            if (func_00388800(&D_001A4BE0.f80, &v->f20) < 0.5f) {
                f21 = 0.0f;
            } else {
                f20 = 0.0f;
                if (f21 != f20) {
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4BE0.f80));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v->f20));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(t[0]) : "j"(r));
                    t[0].z = f20;
                    if (func_00388730(&t[0], &v->f10) < f20) {
                        f21 = 0.0f;
                    }
                }
            }
            f21 = f21 - v->fC;
            func_00388880(&v->f10, &v->f10, f21);
            func_00388880(&D_001A4BE0.fF0, &D_001A4BE0.fF0, 0.0f);
            *(vu0_q *)&D_001A4BE0.f100 = *(vu0_q *)&v->f10;
            D_001A4BE0.f100.w = 0.0f;
            if (f21 != 0.0f) {
                D_001A4BE0.f1A0 = func_00388A28(v->f10.x, v->f10.y);
            }
            D_001A4BE0.f1DC = 10;
            if (D_001D545C == 0x11) {
                if (v->f38 == 0) {
                    P_348538 *p = (P_348538 *)func_L01_003F08D8(0, 5);
                    v->f40 = p;
                    if (p != 0) {
                        v->f38 = 1;
                        *(vu0_q *)&p->f20 = *(vu0_q *)&D_L11_001DD1F0;
                        v->f40->f0 = D_L11_001DD1DC;
                        v->f40->f4 = D_L11_001DD1E0;
                        v->f40->fC = D_L11_001DD1E4 * 0.01745329238474369f;
                        v->f40->f1E = 1;
                        v->f40->f1A = 1;
                    }
                }
            }
        } else {
            if (v->f38 != 0) {
                v->f40->f1A = 0;
                func_L01_003F0980(0, v->f40);
                v->f38 = 0;
            }
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    case 3: {
        u8 *e = D_L11_001DEE1C_00347638 + (v->f4 << 8);
        s32 t23;
        if ((*(u16 *)(e + 0x34) & 1) != 0 && (u8)(t23 = a0[0x23]) != 0) {
            *(s32 *)(a0 + 0x98) = 0;
            if ((u8)t23 >= 4) {
                a0[0x23] = t23 - 4;
            } else {
                a0[0x23] = 0;
            }
        } else if ((((e[0x34]) ^ 1) & 1) != 0) {
            t23 = a0[0x23];
            if ((u32)t23 < 0x7C) {
                a0[0x23] = t23 + 4;
            } else {
                a0[0x23] = 0x80;
                func_L01_00441FB8(a0, 1, -1);
                *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            }
        }
        break;
    }
    }
    if (a0[0x31] != 0) {
        if (a0[0x20] != 3) {
            func_L11_00347DA0(a0);
        }
    }
    if (D_001D545C == 0x10) {
        func_L01_0040C040(D_001A4C60, a0 + 0x10);
    }
    if ((((a0[0x34]) ^ 1) & 1) != 0 && *(s32 *)(a0 + 0x98) != 0) {
        s32 s = v->f30;
        if (s != -1) {
            E_348538 *e = (E_348538 *)(D_001A30B0 + (s << 7));
            if (e->fDC == a0 && e->fD0 != 0) {
                return;
            }
        }
        v->f30 = func_0039FE80(0, 4, a0);
        return;
    }
    {
        s32 s = v->f30;
        if (s != -1) {
            E_348538 *e = (E_348538 *)(D_001A30B0 + (s << 7));
            if (e->fDC == a0 && e->fD0 != 0) {
                func_0039FB08(s);
            }
        }
        v->f30 = -1;
    }
}
/* localdecomp:end func_L11_00347638 */
