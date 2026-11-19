#include "common.h"

typedef unsigned int DebrisQuad __attribute__((mode(TI)));
typedef union { DebrisQuad q; float f[4]; } DebrisVector;

/* localdecomp:start func_L09_003CBEC0 */
#include "vu0.h"
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L09_00220018[];
__asm__(".extern D_L09_00220018, 16");

void func_L09_003CBEC0(f32 x, u8 *p, s32 n, u8 *a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 f22, f21, f20, f23, t;
    s32 v;

    func_00382580(loc, 0.020000001f, 0.040000003f);
    func_L01_003D8E60(p, loc, 60, 7, 5, n, a, 0, -1e+05f, x * 3.5f, -5.0f);
    if (cnt > 0) {
        if (func_00382468(cnt) == 0) {
            func_L01_003303B8(p, x, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L09_00220018;
        cnt = n;
        v = 0xF2;
        do {
            func_00382580(loc, 0.040000003f, 0.080000006f);
            k = func_00382498(-2, 2);
            f22 = x * 3.0f;
            t = func_003824E0(-6.0f, -10.0f);
            f23 = f22 * 2.1e+05f;
            r = func_L01_00475C60(p, loc, 50, k, 0x7F407FFF, 0x407FFF, f23, f23, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            func_0038CE20(loc, loc, 2.0f);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            k = func_00382498(-2, 2);
            f21 = (f22 * 0.4f) * 2.1e+05f;
            f20 = (f22 * 0.04f) * 2.1e+05f;
            t = func_003824E0(24.0f, 4e+01f);
            r = func_L01_00475C60(p, loc, 50, k, 0x7F0048FF, 0x48FF, f21, f20, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L09_003CBEC0 */

/* localdecomp:start func_L09_003CC1F0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_0038DC20(void *, f32);
extern void func_00382580(void *, f32, f32);
extern void func_L09_003CBEC0(f32, u8 *, s32, u8 *, s32);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);

void func_L09_003CC1F0(u8 *self, s32 a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2, s32 a3) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    s32 i;
    s32 j;
    f32 lim;
    *(u128_t *)&v0 = *(u128_t *)(self + 0x10);
    v0.w = f15 + f15;
    i = a2 == 0x1FF ? 0xFF : (s32)(f32)a2;
    lim = i < 0x81 ? 128.0f : (f32)i;
    if (func_0038DC20(&v0, lim) >= 0) {
        func_00382580(&v1, f13 * 0.8f, f13 * 1.2f);
        v1.z += f12;
        vec_add_ba(&v1, &v1, self + 0x10);
        j = 1;
        do {
            func_00382580(&v2, f14 * 0.75f, f14 * 1.25f);
            j--;
            vec_add_ab(&v2, &v1, &v2);
            func_L09_003CBEC0(f15 * 0.75f, (u8 *)&v2, a1, (u8 *)i, a3);
        } while (j >= 0);
        if (self[0x20] != 4) {
            func_L01_004AAC98(1, 0x10, self, 0x1AEE);
        }
    }
}
/* localdecomp:end func_L09_003CC1F0 */

/* localdecomp:start func_L09_003CC3A0 */
/* from the NTSC-U draft of its twin func_L09_003CA908 */
typedef int V4_003CC3A0 __attribute__((mode(TI)));
extern s32 func_L01_0044C108(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L09_003C6C38(void *);
extern void func_L09_005164C0(s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_003EC9E0(void *);
extern void func_L09_003CC1F0(u8 *, s32, f32, f32, f32, f32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L09_00405450(void *);
extern void func_L09_003175A0(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern float func_0038D098(float);
extern float func_0038D0B0(float);
extern void func_L09_00350968(void *, void *, void *, f32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern void func_L01_004AA760(s32, void *);
extern s32 D_001D545C, D_001D545C_sda;
extern u8 D_001BBC40[], D_L09_001D66B0[8];
typedef struct { u8 a[0x1DC]; s16 timer; u8 b[0x1802]; void *obj; } Hero_003CC3A0;
extern Hero_003CC3A0 D_001A4BE0;
typedef struct { u8 a[0x20]; f32 x; s32 b, c, d; } Effect_003CC3A0;
extern Effect_003CC3A0 D_L09_001E2B80;
extern s16 D_001A4DBC[];
extern u8 D_0014275B[];
extern f32 D_L09_001DA9F0, D_L09_002F1D50[];
extern u8 *D_L09_001E009C;
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_L09_001DA9F0, 4");
__asm__(".extern D_001A4BE0, 16");
__asm__(".extern D_L09_001E2B80, 16");

void func_L09_003CC3A0(u8 *m) {
    u8 pos[16] __attribute__((aligned(16)));
    u8 vel[16] __attribute__((aligned(16)));
    u8 *p;
    s32 active;
    f32 t;
    if (!func_L01_0044C108(m + 0x10)) return;
    active = 1;
    p = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        m[0x30] = 255;
        if (!func_L01_004561B8(m)) {
            if (D_001BBC40[m[0xB0] + (D_001D545C << 4)] & 0x80) {
                *(u16 *)(m + 0x34) |= 0x41;
                func_L01_004450F0(m, 6, -1);
            } else func_L01_004450F0(m, 1, -1);
        } else *(f32 *)(p + 0x10) = *(f32 *)(m + 0xF8);
        return;
    case 2:
        if (func_L01_004561B8(m)) {
            *(s16 *)(p + 8) = 50;
            if (D_001A4BE0.obj) func_L09_003C6C38(D_001A4BE0.obj);
            D_001A4BE0.timer = 50;
            func_L09_005164C0(116, 1);
        }
        if (func_0038CB00(p + 8)) {
            func_L01_003EC9E0(*(void **)p);
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3: {
        f32 y;
        s32 n;
        if (func_L01_004561B8(m)) {
            *(s16 *)(p + 8) = 120;
            D_001A4DBC[0] = 120;
        }
        if (*(s16 *)(p + 8) % 20 == 0) func_L09_003CC1F0(m, 10, 7.0f, 2.0f, 4.0f, 1.0f, 128, 2);
        if (func_0038CB00(p + 8)) {
            D_L09_001E2B80.c = 37;
            D_L09_001E2B80.x = 0.8f;
            D_L09_001E2B80.d = 0;
            *(u16 *)(m + 0x34) |= 0x41;
            *(s32 *)(m + 0x98) = 0;
            y = func_003824E0(10, 20);
            n = func_00382498(90, 150);
            func_L01_00451FE0(m, 0x1FFF, D_L09_001D66B0, 2.0f, 3.0f, 5.0f, 7.0f, 255, 6.0f, y, n, 0, 0, 35, 1.0f, 1.0f, 0, 3);
            func_L01_00452460(m, 0x1EF4, 0);
            func_003A52A0(0, 16, m);
            func_003A52A0(3, 16, m);
            *(s16 *)(p + 8) = 130;
            D_001A4DBC[0] = 180;
            m[0xBC] = 0;
            *(V4_003CC3A0 *)pos = *(V4_003CC3A0 *)(m + 0x10);
            *(f32 *)(pos + 8) += 7;
            if (func_L01_0041A4F0()) {
                s32 index = D_001D545C_sda;
                if (index != 7 || !D_0014275B[0]) t = D_L09_002F1D50[index] * 30;
                else t = D_L09_001DA9F0 * 30;
            } else t = 30;
            func_L01_003303B8(pos, 8, 0, 30, 20, 20, 20, 15, 4, 0, t, 15, 0, 1, 1, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            active = 0;
            func_L01_004450F0(m, 4, -1);
        }
        break;
    }
    case 4:
        if (m[0xBC] == 0) {
            if (*(s16 *)(p + 8) % 3 == 0) func_L09_003CC1F0(m, 10, 10.0f, 4.0f, 4.0f, 1.0f, 128, 2);
            if (func_0038CB00(p + 8)) {
                *(s16 *)(p + 8) = 50;
                m[0xBC] = 1;
            }
        } else if (m[0xBC] == 1) {
            if (func_0038CB00(p + 8)) func_L01_004450F0(m, 5, -1);
        }
        active = 0;
        break;
    case 5:
        D_001A4DBC[0] = 30;
        func_L09_005164C0(0, 1);
        if (*(s32 *)(p + 4) != -1) {
            func_L09_00405450(*(void **)p);
            func_L09_003175A0(D_L09_001E009C + (*(s32 *)(p + 4) << 8), *(s32 *)(p + 12), m[0xB0], *(s32 *)(p + 0x20));
        }
        active = 0;
        func_L01_004450F0(m, 6, -1);
        break;
    case 6:
        *(u16 *)(m + 0x34) |= 2;
        active = 0;
        break;
    }
    if (active) {
        if (func_0038CB00(p + 10)) {
            f32 x, z;
            *(s16 *)(p + 10) = (func_00382498(45, 80) * 5 + 2) / 6;
            func_003C2F58(m, 0, pos);
            x = func_0038D098(func_0038D160(*(f32 *)pos - *(f32 *)(m + 16), *(f32 *)(pos + 4) - *(f32 *)(m + 20)));
            x *= func_003824E0(62, 66) * 0.020000001f;
            *(f32 *)vel = x;
            z = func_0038D0B0(func_0038D160(*(f32 *)pos - *(f32 *)(m + 16), *(f32 *)(pos + 4) - *(f32 *)(m + 20)));
            z *= func_003824E0(62, 66) * 0.020000001f;
            *(f32 *)(vel + 4) = z;
            *(s32 *)(vel + 8) = 0;
            func_003A52A0(1, 0, m);
            func_L09_00350968(m, vel, pos, 0, 0);
        }
        if (func_0038CAD0(p + 0x1C)) {
            *(s32 *)(p + 0x1C) = (s32)(func_00382498(5, 10) * 50.0f);
            *(f32 *)(p + 0x14) = func_0038DAB8(*(f32 *)(p + 0x10), func_L01_00443A18(10, 40) * 0.0174532924f);
        }
        func_L01_00448890(m + 0xF8, p + 0x18, *(f32 *)(p + 0x14), 0.000400000019f, 0.000400000019f, 0.100000009f, 0);
        if (func_0038DBA0(*(f32 *)(m + 0xF8), *(f32 *)(p + 0x14)) > 0.0349065848f) {
            if (func_L01_004561E0(m)) func_003A52A0(2, 4, m);
        } else {
            m[0xBE] &= 0xFD;
            func_L01_004AA760(2, m);
        }
    } else func_L01_004AA760(2, m);
}
/* localdecomp:end func_L09_003CC3A0 */

/* localdecomp:start func_L09_003CCB28 */
void func_L01_00445130(s32, s32, s32);
void func_L09_003CCB28(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x20) = arg1;
    func_L01_00445130((s32) arg0, 2, -1);
}
/* localdecomp:end func_L09_003CCB28 */

/* localdecomp:start func_L09_003CCB50 */
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L09_003CCC00(void *, s32, f32, f32, f32, f32);
extern void func_003C2880(void *);
void func_L09_003CCB50(u8 *a0) {
    switch (a0[0x20]) {
    case 0:
        break;
    case 1:
        if (func_L01_00447490(a0, 0x8010000, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        a0[0xA8] = 0xFF;
        break;
    case 2:
        func_L09_003CCC00(a0, 0x3C, 0.4f, 10.0f, 10.0f, 0.100000009f);
        func_003C2880(a0);
        break;
    }
}
/* localdecomp:end func_L09_003CCB50 */

/* localdecomp:start func_L09_003CCC00 */
extern float func_0038D098(float);
extern float func_0038D0B0(float);
extern void func_0038CF68(void *, void *, float);
extern void func_L02_00429840(void *, void *, float, int, int, void *, float, float, unsigned int, float, int, int);

void func_L09_003CCC00(void *mv, s32 count, f32 low, f32 high, f32 radius, f32 speed)
{
    DebrisVector position;
    DebrisVector velocity;
    float angle;
    position.q = 0;
    velocity.q = 0;
    if (count > 0) {
        int remaining = count;
        do {
            angle = func_003824E0(-3.1415927f, 3.1415927f);
            position.f[0] = radius * func_0038D098(angle);
            position.f[1] = radius * func_0038D0B0(angle);
            position.f[2] = func_003824E0(0.0f, 1.0f);
            func_0038CF68(&velocity, &position, func_003824E0(speed * 0.75f, speed * 1.25f));
            position.f[2] = func_003824E0(low, high);
            vec_add_ab(&position, (u8 *)mv + 0x10, &position);
            func_L02_00429840(mv, &position, 0.0f, 1, 1, &velocity, 0.0f, 1.0f, 0x80402000, 3.5f, 0, 0xB4);
        } while (--remaining);
    }
}
/* localdecomp:end func_L09_003CCC00 */
