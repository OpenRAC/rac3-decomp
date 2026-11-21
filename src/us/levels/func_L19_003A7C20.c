#include "common.h"

/* NTSC-U counterpart of func_L19_003A9788 (src/levels/19_thran_asteroid_belt/L19_003A96A8.c) */
extern s32 D_L19_001D66D4_003A7C20;

/* localdecomp:start func_L19_003A7C20 */
#include "vu0.h"
typedef int u128_t_3A9788 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A9788;
extern u8 D_001A4BE0[];
extern u8 D_001D5470;
extern u32 D_00142C54[];
typedef struct { s32 x0; s32 x4; } S_3A9788;
__asm__(".extern D_L19_001DF434_003A7C20, 16");
extern S_3A9788 D_L19_001DF434_003A7C20;
extern u8 *D_L19_001DF800_003A7C20;
extern u8 D_L19_001E8C00_003A7C20[];
extern void func_L19_003A7B40(u8 *);
extern void func_003BD360(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern s32 func_L04_0046C8D0(u8 *, s32, f32);
extern void func_L01_0047BB50(void *);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern s32 func_L01_004B6C68(void);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_0049FDB0(void *, void *);
extern s32 func_00388398(void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388770(void *);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

/* hb is the hero base, passed in so that it stays one short-lived temp (retail rebuilds it as the position pointer
   minus 0x80) instead of folding into the position pointer's offsets. */
static __inline__ f32 aim_3A9788(u8 *obj, u8 *hb) {
    return func_00389468(*(f32 *)(obj + 0xF8), func_00388A28(*(f32 *)(hb + 0xE0) - *(f32 *)(obj + 0x10),
                                                              *(f32 *)(hb + 0xE4) - *(f32 *)(obj + 0x14)));
}

void func_L19_003A7C20(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    s32 one = 1;
    s32 aim;
    f32 fa, fb;
    f32 yaw, pt;
    f32 ry;
    f32 rp;
    V4_3A9788 tgt;
    V4_3A9788 o;
    V4_3A9788 d;

    func_L19_003A7B40(obj);
    switch (obj[0x20]) {
    case 0:
        if (D_00142C54[0] & 0x400000) {
            func_003BD360(obj);
            return;
        }
        if (D_00142C54[0] & 0x200000) {
            func_L01_00441FB8(obj, 3, -1);
            if (obj[0x43] != 0)
                func_003BE4F0(obj, 0, 0, 0);
            *(u128_t_3A9788 *)(obj + 0x10) = *(u128_t_3A9788 *)(D_L19_001DF800_003A7C20 + *(s32 *)(p + 0x128) * 0x80 + 0x30);
            *(u128_t_3A9788 *)(obj + 0xF0) = *(u128_t_3A9788 *)(D_L19_001DF800_003A7C20 + *(s32 *)(p + 0x128) * 0x80 + 0x70);
        } else {
            func_L01_00441FB8(obj, 1, -1);
            if (obj[0x43] != 2)
                func_003BE4F0(obj, 2, 0, 0);
        }
        break;
    case 1:
        if (func_L04_0046C8D0(obj, 0xA, 2.5f) != 0) {
            func_L01_0047BB50(obj);
            if (!(D_00142C54[0] & 0x200000) && func_0038E2E8(D_L19_001E8C00_003A7C20, 0xB5) != 0) {
                func_0038E440(D_L19_001E8C00_003A7C20);
                func_L01_00441FB8(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (D_L19_001D66D4_003A7C20 == 2) {
            obj[0x31] = 0;
            *(u16 *)(obj + 0x34) |= 1;
        }
        D_L19_001DF434_003A7C20.x4 = one;
        if (func_L01_004B6C68() == 0) {
            if (*(s32 *)(p + 0x124) >= 0)
                func_L01_004F12C0(D_L19_001DF800_003A7C20 + *(s32 *)(p + 0x124) * 0x80 + 0x30,
                                  D_L19_001DF800_003A7C20 + *(s32 *)(p + 0x124) * 0x80 + 0x70, 0, 1);
            func_L01_0049FDB0(D_001A4BE0 + 0x80, D_001A4BE0 + 0x90);
            if (obj[0x43] != 0)
                func_003BE4F0(obj, 0, 0, 0);
            *(u128_t_3A9788 *)(obj + 0x10) = *(u128_t_3A9788 *)(D_L19_001DF800_003A7C20 + *(s32 *)(p + 0x128) * 0x80 + 0x30);
            *(u128_t_3A9788 *)(obj + 0xF0) = *(u128_t_3A9788 *)(D_L19_001DF800_003A7C20 + *(s32 *)(p + 0x128) * 0x80 + 0x70);
            D_L19_001DF434_003A7C20.x4 = 0;
            obj[0x31] = one;
            *(u16 *)(obj + 0x34) &= 0xFFFE;
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    }
    if (obj[0x20] == 3) {
        if (obj[0x43] == 0 && func_00388398(p + 0x11C) != 0) {
            *(s32 *)(p + 0x11C) = (s32)func_0037E250(1200.0f, 2400.0f);
            if (obj[0x43] != 1)
                func_003BE4F0(obj, 1, 0, 10);
        } else if ((obj[0x60] & 2) && obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 10);
        }
    }
    fa = 0.02f;
    fb = 0.3f;
    aim = 0;
    if (obj[0x43] == 0) {
        u8 *hp = D_001A4BE0 + 0x80;
        aim = 1;
        if (func_00388800(obj + 0x10, hp) < 8.0f &&
            aim_3A9788(obj, hp - 0x80) < 1.5707964f &&
            (D_00142C54[0] & 0x200000)) {
            if (0.01f < func_00388770(D_001A4BE0 + 0x110))
                *(s32 *)(p + 0x114) = 0x78;
            else
                func_00388398(p + 0x114);
        } else if (*(s32 *)(p + 0x114) != 0) {
            *(s32 *)(p + 0x114) = 0;
            *(u128_t_3A9788 *)(p + 0x100) = *(u128_t_3A9788 *)(D_001A4BE0 + 0xE0);
        }
        if (func_00388398(p + 0x118) != 0) {
            *(s32 *)(p + 0x118) = (s32)func_0037E250(180.0f, 300.0f);
            ry = func_00389380(*(f32 *)(obj + 0xF8), func_0037E250(-90.0f, 90.0f) * 0.017453292f);
            rp = func_0037E250(0.0f, 30.0f) * 0.017453292f;
            func_0037E4B8(p + 0x100, 6.0f, ry, rp);
            {
                vu0_q qa, qb, qr;
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(p + 0x100)));
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(obj + 0x10)));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(p + 0x100)) : "j"(qr));
            }
        }
        if (*(s32 *)(p + 0x114) != 0) {
            fa = 0.04f;
            fb = 0.3f;
            tgt = *(V4_3A9788 *)(D_001A4BE0 + 0xE0);
        } else {
            tgt = *(V4_3A9788 *)(p + 0x100);
        }
    }
    if (aim) {
        o = *(V4_3A9788 *)(obj + 0x10);
        o.z = o.z + 2.0f;
        vec_sub_ab(&d, &tgt, &o);
        yaw = func_003893C8(func_00388A28(d.x, d.y), *(f32 *)(obj + 0xF8));
        pt = -func_00388A28(func_003887A0(&d), d.z);
        if (1.5707964f < yaw)
            yaw = 1.5707964f;
        else if (yaw < -1.5707964f)
            yaw = -1.5707964f;
        if (0.5235988f < pt)
            pt = 0.5235988f;
        else if (pt < -0.5235988f)
            pt = -0.5235988f;
        *(f32 *)(p + 0xE4) = pt;
        *(f32 *)(p + 0xE8) = yaw * 0.6f;
        *(f32 *)(p + 0x68) = yaw * 0.4f;
    }
    if ((&D_001D5470)[1] != 0)
        *(f32 *)(p + 0x70) = 2.75f;
    if (obj[0x20] != 3)
        *(f32 *)(p + 0xE4) = 0.2f;
    func_L01_0044B5C8(obj, p, 1, fa, fb);
    func_L01_0044B5C8(obj, p + 0x80, 0, fa, fb);
}
/* localdecomp:end func_L19_003A7C20 */
