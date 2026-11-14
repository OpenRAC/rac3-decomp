#include "common.h"

/* NTSC-U counterpart of func_L19_003CE990 (src/levels/19_thran_asteroid_belt/L19_003CDD90.c) */
#include "vu0.h"

/* localdecomp:start func_L19_003CC878 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CE990;
extern u8 *D_L19_001DF71C_003CC878;
extern s32 D_L19_001DF240_003CC878;
extern s32 func_L01_00448E90(void *);
extern void func_L19_003CCD90(u8 *);
extern void func_L19_003CCF08(u8 *);
extern void func_L19_003CD0F8(u8 *);
extern s32 func_L01_00452EC8(u8 *);
extern void func_003BE418(void *, s32, s32);
extern s32 func_00388398(void *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(u8 *);
extern u8 *func_L01_00444358(u8 *, s32, s32);
extern void func_003BF4F8(void *, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_004479A8(void *, void *);
extern void func_L01_004538E0(void *, s32);

void func_L19_003CC878(u8 *obj) {
    u8 *p;
    u8 *h;
    u8 *q;
    u8 *t;
    V4_3CE990 a;
    V4_3CE990 b;
    V4_3CE990 c;
    f32 ang;
    f32 r;
    s32 n;
    s32 k1, k2, k3;
    s32 n24, col;
    V4_3CE990 *pa;

    if (func_L01_00448E90(obj + 0x10) == 0)
        return;
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        func_L19_003CCD90(obj);
        func_L01_00441FB8(obj, 4, -1);
        break;
    case 2:
        if (func_L01_00452EC8(obj))
            func_003BE418(obj, 0, 0);
        func_00388398(p + 0x10C);
        if (*(s32 *)(p + 0x10C) == 0) {
            *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34);
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(obj) && obj[0x43] != 1)
            func_003BE4F0(obj, 1, 0, 6);
        func_L19_003CCF08(obj);
        if (obj[0x60] & 2) {
            func_003BE418(obj, 2, 0);
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(obj))
            func_003BE418(obj, 2, 0);
        func_L19_003CCF08(obj);
        break;
    case 1:
        t = *(u8 **)((*(s32 *)(p + 0x114) << 8) + (s32)D_L19_001DF71C_003CC878 + 0x68);
        if (obj[0x42] == obj[0x43]) {
            if (obj[0x42] != 4 && *(s32 *)(t + 0x18) == 0)
                func_003BE4F0(obj, 4, 0, 6);
            if (obj[0x42] == obj[0x43] && obj[0x42] == 4 && (obj[0x60] & 2)) {
                func_003BE418(obj, 0, 0);
                func_L01_00441FB8(obj, 2, -1);
            }
        }
        break;
    case 5:
        func_L01_0032FE90(obj + 0x10, 0, 0, 0x14, 0, 8, 0x28, 4, 1.0f, 2.0f, 0.0f, 0.0f,
            1, 1, 1, 1, 1, 0, 0, 0, 0xFF4020FF, 0xFF6020C0, 0, 0, 0xFF802040, 0, 0xFFF02060, 0xFF4020FF, 0xFF802040, 0);
        func_003BD360(obj);
        return;
    }
    h = func_L01_00444358(obj, -1, 0);
    q = p + 0x70;
    if (h != 0) {
        if (*(u8 **)(h + 0x20) != D_L19_001DF71C_003CC878 + (*(s32 *)(p + 0x114) << 8)) {
            if ((u32)(obj[0x20] - 3) < 2 && D_L19_001DF240_003CC878 >= *(s32 *)(p + 0x118)) {
                p[0x77] = 0xFF;
                func_003BF4F8(obj, q);
                *(f32 *)(p + 0x30) = *(f32 *)(p + 0x30) - *(f32 *)(h + 0x2C);
                if (*(f32 *)(p + 0x30) <= 0.0f) {
                    *(s32 *)(p + 0x10C) = *(s32 *)(p + 0x108);
                    func_L01_00441FB8(obj, 1, -1);
                }
                if (*(u16 *)(h + 0x2A) == 0x185E)
                    func_L01_00441FB8(obj, 5, -1);
            }
        }
        obj[0xA8] = 0xFF;
    }
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        pa = &a;
        qzero(&a);
        a.z = func_0037E250(0.0166666675f, 0.025000002f);
        qzero(&b);
        b.w = 0.25f;
        a.w = 0.15f;
        ang = func_0037E2A8();
        r = func_0037E250(-0.25f, 0.25f);
        c.x = func_00388960(ang) * r;
        c.y = func_00388978(ang) * r;
        c.z = 0.0f;
        vec_add_ba(&c, &c, obj + 0x10);
        n = *(s32 *)(p + 0x10C);
        col = ((n >> 1) << 24) | 0x404040;
        n24 = n << 24;
        k1 = func_0037E208(5, 10);
        k2 = func_0037E208(0x3C, 0x78);
        k3 = func_0037E208(0x1E, 0x3C);
        func_L01_0045FEC8(&c, pa, &b, n24, col, k1, k2, k3, -1);
    }
    func_L19_003CD0F8(obj);
    func_L01_004479A8(obj, q);
    if (0.0f < *(f32 *)(p + 0x30))
        func_L01_004538E0(obj, 3);
}
/* localdecomp:end func_L19_003CC878 */
