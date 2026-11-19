/* functional: medium. Same calls, order and stores as retail (14-arg func_L30_0034D1E8 args and every gp slot checked against the asm); the COP2 vsub/vadd.xyz are scalar xyz ops (w from the first operand, t0.w uninitialised as retail) and the final quad copy is a struct copy; register allocation and scheduling differ (279 diff words). */
#include "vu0.h"
__asm__(".extern D_L30_001DE93C, 4");
extern s32 D_L30_001DE93C;
__asm__(".extern D_L30_001DE8EC, 4");
extern s32 D_L30_001DE8EC;
__asm__(".extern D_L30_001DE8F0, 4");
extern f32 D_L30_001DE8F0;
__asm__(".extern D_L30_001DE930, 4");
extern f32 D_L30_001DE930;
__asm__(".extern D_L30_001DE8BC, 4");
extern f32 D_L30_001DE8BC;
__asm__(".extern D_L30_001DE8B0, 4");
extern f32 D_L30_001DE8B0;
__asm__(".extern D_L30_001DE988, 4");
extern f32 D_L30_001DE988;
__asm__(".extern D_L30_001DE958, 4");
extern f32 D_L30_001DE958;
__asm__(".extern D_L30_001DE95C, 4");
extern f32 D_L30_001DE95C;
__asm__(".extern D_L30_001DE964, 4");
extern f32 D_L30_001DE964;
__asm__(".extern D_L30_001DE8A8, 4");
extern f32 D_L30_001DE8A8;
__asm__(".extern D_L30_001DE8A4, 4");
extern f32 D_L30_001DE8A4;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_3A1D08;
typedef struct {
    Q_3A1D08 x0; f32 x10; f32 x14; f32 x18; u8 p1C[4];
    Q_3A1D08 x20; Q_3A1D08 x30;
    u8 p40[0x4C - 0x40]; s32 x4C; s32 x50;
    u8 p54[0x5C - 0x54]; f32 x5C; s32 x60; s32 x64;
    u8 p68[0x6C - 0x68]; f32 x6C;
    u8 p70[0x74 - 0x70]; f32 x74;
    u8 p78[0x80 - 0x78]; f32 x80[32]; f32 x100[32];
} V_3A1D08;
extern s32 D_L30_001DF2C0;
extern u8 D_L30_001E1221;
extern Q_3A1D08 D_L30_001E1200;
extern Q_3A1D08 D_L30_001E9020;
extern f32 D_001A4C64;
extern s32 func_L01_004561B8(void *);
extern void func_L30_003A20D0(void *, s32 *, f32 *, s32, s32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L30_003A2C68(void *, s32);
extern f32 func_L30_0034C9F8(f32 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L30_003A1D08(u8 *self) {
    V_3A1D08 *v = *(V_3A1D08 **)(self + 0x68);
    s32 flag = 0;
    s32 idx;
    f32 dist;
    s32 hit;
    Q_3A1D08 t0, t10, t20, t30, t40, t50, t60;

    dist = 10000.0f;
    if (func_L01_004561B8(self) != 0) {
        v->x50 = v->x64;
        v->x0.x = 0.0f; v->x0.y = 0.0f; v->x0.z = 0.0f; v->x0.w = 0.0f;
        flag = 1;
    }
    if ((D_L30_001DF2C0 & D_L30_001DE93C) == (((s32)self >> 8) & D_L30_001DE93C) || flag != 0) {
        s32 k;
        func_L30_003A20D0(self, &idx, &dist, 1, 1);
        if (idx != -1) {
            if (idx >= v->x4C) {
                v->x4C = idx;
            }
        }
        k = v->x4C + D_L30_001DE8EC;
        if (k > 31) {
            k = 31;
        }
        v->x10 = v->x80[k];
        v->x14 = D_001A4C64;
        v->x18 = v->x100[k];
    }
    t0.x = v->x10 - v->x30.x;
    t0.y = v->x14 - v->x30.y;
    t0.z = v->x18 - v->x30.z;
    func_L02_003BA9F8(&t0, &v->x20, &t10, &t20);
    func_0038CF68(&t30, &t20, v->x5C);
    v->x0.x += t30.x;
    v->x0.y += t30.y;
    v->x0.z += t30.z;
    func_0038CF68(&t50, &v->x20, D_L30_001DE8F0);
    hit = func_L30_0034D1E8(self, &v->x30, v, &t50, 1, 1, 1, 0, v->x6C, 0.0f, 0.0f, v->x74, D_L30_001DE930, 0.0f);
    if (D_L30_001E1221 != 0) {
        v->x20.x = D_L30_001E1200.x - v->x30.x;
        v->x20.y = D_L30_001E1200.y - v->x30.y;
        v->x20.z = D_L30_001E1200.z - v->x30.z;
        v->x20.w = D_L30_001E1200.w;
        func_0038CF68(&t40, &v->x20, -v->x6C);
        v->x30.x = D_L30_001E1200.x + t40.x;
        v->x30.y = D_L30_001E1200.y + t40.y;
        v->x30.z = D_L30_001E1200.z + t40.z;
        v->x30.w = D_L30_001E1200.w;
        func_0038CF68(&v->x20, &v->x20, 1.0f);
        v->x0.x = 0.0f; v->x0.y = 0.0f; v->x0.z = 0.0f; v->x0.w = 0.0f;
    } else if (hit == 0) {
        if (func_L01_003FB640(&v->x30, 2, 0, v->x6C + func_0038CEA8(v) + D_L30_001DE8BC) != 0) {
            v->x20.x = D_L30_001E9020.x - v->x30.x;
            v->x20.y = D_L30_001E9020.y - v->x30.y;
            v->x20.z = D_L30_001E9020.z - v->x30.z;
            v->x20.w = D_L30_001E9020.w;
            func_0038CF68(&t40, &v->x20, -v->x6C);
            v->x30.x = D_L30_001E9020.x + t40.x;
            v->x30.y = D_L30_001E9020.y + t40.y;
            v->x30.z = D_L30_001E9020.z + t40.z;
            v->x30.w = D_L30_001E9020.w;
            func_0038CF68(&v->x20, &v->x20, 1.0f);
            func_L02_003BA9F8(v, &v->x20, &t10, &t20);
            v->x0 = t20;
        } else {
            func_L30_003A2C68(self, 2);
        }
    }
    *(f32 *)(self + 0x48) = D_L30_001DE8B0 * func_0038CEA8(v) / D_L30_001DE988;
    if (func_0038CAD0(&v->x50) != 0) {
        func_L30_003A2C68(self, 7);
    }
    if (func_0038CEA8(&v->x20) > 0.0f) {
        func_L01_00448890(self + 0xF4, (u8 *)v + 0x40, 0, func_0038DAB8(func_L30_0034C9F8(&v->x20.x), 1.5707964f),
                          D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964);
        func_0038CE90(&t60, v, &v->x20);
        func_L01_00448890(self + 0xF8, (u8 *)v + 0x44, 0, t60.y < 0.0f ? D_L30_001DE8A8 : D_L30_001DE8A4,
                          D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964);
    }
}
