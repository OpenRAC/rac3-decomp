#include "common.h"

/* NTSC-U counterpart of func_L11_003AE290 (src/levels/11_obani_moons/L11_003AE1B0.c) */
#include "vu0.h"
extern s32 D_L11_001D6694_003AC568;

/* localdecomp:start func_L11_003AC568 */
typedef int q_3AE290 __attribute__((mode(TI)));
extern s32 D_L11_001D6694_003AC568;
extern u8 D_001D5470;

extern u8 D_001D5545;
typedef struct {
    u8 pad0[0x80];
    u8 f80[0x60];
    vu0_v4 fE0;
    u8 pad0F0[0x20];
    u8 f110[0x250];
    s32 f360;
} P_3AE290;
extern P_3AE290 D_001A4BE0;
extern vu0_v4 D_L11_001E84E0_003AC568;
extern u8 *D_L11_001DEE1C_003AC568;
extern u8 D_L11_001E1780_003AC568[];
extern s32 func_L01_004B6C68(void);
extern void func_L11_003AC488(u8 *);
extern void func_003BFC18(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BD360(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00452F40(void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_00388398(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388770(void *);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_00444188(void *);

void func_L11_003AC568(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 tgt;
    vu0_v4 pos;
    vu0_v4 d;
    vu0_v4 u0;
    vu0_v4 p0;
    vu0_v4 p1;
    vu0_v4 p2;
    vu0_v4 p3;
    vu0_v4 u1[2];
    s32 flag;
    f32 s0, s1, e, t;

    if (D_L11_001D6694_003AC568 == 2) {
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) |= 1;
        return;
    }
    if (func_L01_004B6C68() == 0) {
        a0[0x31] = 1;
        *(u16 *)(a0 + 0x34) &= 0xFFFE;
    }
    func_L11_003AC488(a0);
    switch (a0[0x20]) {
    case 0: {
        q_3AE290 qa, qb, qp;
        func_003BFC18(a0 + 0x10, &tgt, 0);
        func_L01_0044E358(a0 + 0xC0, &tgt, &pos);
        func_00388830(&p0, a0 + 0xE0, 0.5f);
        func_00388830(&p1, a0 + 0xE0, -4.0f);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(p0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(qa));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(p1));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(qb));
        if (func_003CE740(&p0, &p1, 2, (s32)a0, 0) != 0) {
            *(vu0_v4 *)(a0 + 0x10) = D_L11_001E84E0_003AC568;
            func_003BFC18(a0 + 0x10, &p2, 0);
            func_L01_0044E358(a0 + 0xC0, &p2, &p3);
        }
        func_L01_00441FB8(a0, 1, -1);
        if (D_001D5545 != 0) {
            func_003BD360(a0);
            return;
        }
        break;
    }
    case 1:
        if (func_L01_0040C018(a0 + 0x10, D_001A4BE0.f80) < 100.0f) {
            if (D_001A4BE0.f360 != 0) {
                func_L01_00452F40(D_L11_001DEE1C_003AC568 + (*(s32 *)(v + 0x120) << 8), 1);
                func_L01_00441FB8(a0, 2, -1);
            }
        }
        break;
    }
    if (a0[0x20] != 0) {
        if (a0[0x43] == 0 && func_00388398(v + 0x11C) != 0) {
            *(s32 *)(v + 0x11C) = (s32)func_0037E250(1200.0f, 2400.0f);
            if (a0[0x43] != 2) {
                func_003BE4F0(a0, 2, 0, 10);
            }
        } else if (a0[0x60] & 2) {
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 10);
            }
        }
    }
    s0 = 0.02f;
    s1 = 0.3f;
    flag = 0;
    if (a0[0x43] == 0) {
        f32 ang;
        flag = 1;
        if (func_00388800(a0 + 0x10, D_001A4BE0.f80) < 8.0f) {
            ang = func_00388A28(D_001A4BE0.fE0.x - *(f32 *)(a0 + 0x10), D_001A4BE0.fE0.y - *(f32 *)(a0 + 0x14));
            ang = func_00389468(*(f32 *)(a0 + 0xF8), ang);
            if (ang < 1.5707964f) {
                if (0.01f < func_00388770(D_001A4BE0.f110)) {
                    *(s32 *)(v + 0x114) = 120;
                } else {
                    func_00388398(v + 0x114);
                }
            } else {
                goto z;
            }
        } else {
z:
            if (*(s32 *)(v + 0x114) != 0) {
                *(s32 *)(v + 0x114) = 0;
                *(q_3AE290 *)(v + 0x100) = *(q_3AE290 *)&D_001A4BE0.fE0;
            }
        }
        if (func_00388398(v + 0x118) != 0) {
            *(s32 *)(v + 0x118) = (s32)func_0037E250(180.0f, 300.0f);
            ang = func_00389380(*(f32 *)(a0 + 0xF8), func_0037E250(-90.0f, 90.0f) * 0.017453292f);
            t = func_0037E250(0.0f, 30.0f) * 0.017453292f;
            func_0037E4B8(v + 0x100, 6.0f, ang, t);
            {
                q_3AE290 qa, qb, qr;
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(v + 0x100)));
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(a0 + 0x10)));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(v + 0x100)) : "j"(qr));
            }
        }
        if (*(s32 *)(v + 0x114) != 0) {
            s0 = 0.04f;
            s1 = 0.3f;
            *(q_3AE290 *)&tgt = *(q_3AE290 *)&D_001A4BE0.fE0;
        } else {
            tgt = *(vu0_v4 *)(v + 0x100);
        }
    }
    if (flag != 0) {
        f32 ang, ang2;
        pos = *(vu0_v4 *)(a0 + 0x10);
        pos.z += 2.0f;
        vec_sub_ab(&d, &tgt, &pos);
        ang = func_003893C8(func_00388A28(d.x, d.y), *(f32 *)(a0 + 0xF8));
        ang2 = -func_00388A28(func_003887A0(&d), d.z);
        if (1.5707964f < ang) {
            ang = 1.5707964f;
        } else if (ang < -1.5707964f) {
            ang = -1.5707964f;
        }
        if (0.5235988f < ang2) {
            ang2 = 0.5235988f;
        } else if (ang2 < -0.5235988f) {
            ang2 = -0.5235988f;
        }
        *(f32 *)(v + 0x64) = ang2;
        *(f32 *)(v + 0x68) = ang * 0.6f;
        *(f32 *)(v + 0xE8) = ang * 0.4f;
    }
    if ((&D_001D5470)[1] != 0) {
        *(f32 *)(v + 0x70) = 2.75f;
    }
    func_L01_0044B5C8(a0, v, 0, s0, s1);
    func_L01_0044B5C8(a0, v + 0x80, 1, s0, s1);
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L11_001E1780_003AC568, a0 + 0x10) < 1024.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 30;
        }
    }
}
/* localdecomp:end func_L11_003AC568 */
