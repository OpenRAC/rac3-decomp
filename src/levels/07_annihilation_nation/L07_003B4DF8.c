#include "common.h"
#include "structs/moby.h"
#include "vu0.h"

/* declared by earlier blocks of L07_003AF600.c, which this file was cut from */
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
typedef struct {
    u8 pad[0x144];
    void *w144;
    s32 w148;
} Pool_003AF678;
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                              float f14, float f15);
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L07_003A2380(u8, s32, u8, s16);
extern s32 func_0038CB00(void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L07_003B4B68(void *, s16, f32);
extern f32 func_L01_004474E8(void *, s32);
extern void func_L01_00459BE8(void *, s32, f32);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_0044E820(void *, s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003A2450(void);
extern void func_L07_003315B0(void *);
extern s32 func_L07_00333D20(s32);
extern void func_L07_003B4DF8(u8 *);

/* localdecomp:start func_L07_003B4DF8 */
typedef struct { u8 pad[0x1F0]; u8 *p; } G_003B4DF8;
extern G_003B4DF8 D_L07_0021EC98;
void func_L07_003B4DF8(u8 *self) {
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    f32 position[4];
    f32 velocity[4];
    s32 i, j, next;
    s32 three = 3;
    G_003B4DF8 *g = &D_L07_0021EC98;
    f32 a, b, c;
    u8 *particle;
    i = 0;
    do {
        func_003C2F58(self, i + 14, position);
        next = i + 1;
        for (j = 1; j >= 0; j--) {
            func_0038CE20(velocity, self + 0xC0, -func_003824E0(0.20000001788139343f, 0.30000001192092896f));
            func_003C4C18(velocity, 0.08000000566244125f);
            i = func_00382498(40, 60);
            a = func_003824E0(63000.00390625f, 147000.0f);
            b = func_003824E0(315000.0f, 525000.0f);
            c = func_003824E0(-0.004000000189989805f, -0.00800000037997961f);
            particle = func_L01_0046FB40(position, velocity, i, 0x202020, func_00382468(2) ? three : -3, 96, 0, 0, a, b, c);
            if (particle) {
                u8 color = g->p[1];
                particle[3] = 0x44;
                particle[2] = color;
            }
        }
        i = next;
    } while (i < 2);
}
/* localdecomp:end func_L07_003B4DF8 */

/* localdecomp:start func_L07_003B4FD0 */
extern s32 func_L01_0045A9F0_003B4FD0(void *);
extern s32 func_L01_0045A748_003B4FD0(void *, void *);
extern void func_L07_003B5CC8(u8 *);
extern void func_L07_003B5E08(u8 *);
extern void func_L07_003B64D0(u8 *, s32);
extern s32 func_L01_0040E020(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_004395E0(void *);
extern f32 func_L01_0040F518(f32, f32);
extern s32 func_00382468(s32);
extern void func_L03_0043FC00(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L07_003B6BD8(u8 *, s32);
extern void func_L07_003B6800(u8 *);
extern f32 func_L07_003B6DC8(u8 *, u8 *);
extern void func_L07_003B6E98(u8 *, u8);
extern s32 func_L07_003B6CD8(u8 *, u8);
extern void func_L07_003B70F0(u8 *, u8);
extern void func_L07_003B7230(u8 *);
extern void func_L07_003B6998(u8 *);
extern void func_L07_003B6AE8(u8 *);
extern void func_L07_003B7378(void *);
extern void func_L07_003B68F0(u8 *);
extern void func_L07_003B8D80(u8 *);
extern void func_L07_003B6B38(u8 *);
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001DE478[8];
__asm__(".extern D_L07_001DE478, 8");
extern u8 D_L07_001E1EC0[];

typedef struct { f32 rate; s32 pad4; s32 count; s32 phase; u8 pad10[0x10]; } Fx_003B4FD0;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B4FD0;

void func_L07_003B4FD0(u8 *obj) {
    u8 *p;
    u8 *target;
    u8 *flags;
    f32 lim;
    f32 a;
    f32 step;
    f32 f;
    s32 k;
    u8 n;
    s32 x;
    V4_003B4FD0 v;

    if (obj[0x20] == 0) {
        func_L07_003B5CC8(obj);
    }
    func_L07_003B5E08(obj);
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0_003B4FD0(obj);
        if (func_0038CB00(p + 0x19E)) {
            func_L07_003B64D0(obj, 3);
        }
        break;
    case 3:
        func_L07_003B64D0(obj, 4);
        break;
    case 4:
        if (func_L01_004561B8(obj)) {
            *(u16 *)(obj + 0x34) |= 0x5000;
        }
        func_L01_0045A748_003B4FD0(obj, *(u8 **)(p + 0x190) + 0x10);
        if (func_L01_0040E570(*(u8 **)(p + 0x190) + 0x10, obj + 0x10) < 484.0f) {
            p[0x1AE] = 1;
            func_L07_003B64D0(obj, 5);
        }
        break;
    case 5:
        func_L01_0045A9F0_003B4FD0(obj);
        func_L07_003B6BD8(obj, 0);
        break;
    case 6:
        if (func_L01_004561B8(obj) && *(s16 *)(p + 0x328) == 0) {
            func_L07_003A2380(2, (s32)obj, 0, 100);
            *(s16 *)(p + 0x328) = 500;
        }
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 7);
        }
        break;
    case 7:
        if (func_L01_004561B8(obj)) {
            if (*(s16 *)(p + 0x32A) == 0) {
                func_L07_003A2380(14, (s32)(D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8)), 0, 100);
                *(s16 *)(p + 0x32A) = 1000;
            }
            func_L01_00456230(obj, 0);
        }
        func_L01_0045A9F0_003B4FD0(obj);
        func_L07_003B6800(obj);
        if (func_L01_0040E570(obj + 0x10, p + 0x80) < 64.0f) {
            func_L07_003B64D0(obj, 0x11);
        } else if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 8);
        }
        break;
    case 8:
        if (func_L01_004561B8(obj)) {
            *(s16 *)(p + 0x31A) = 75;
            if (p[0x321] == 5) {
                *(s16 *)(p + 0x318) = 333;
            } else {
                *(s16 *)(p + 0x318) = 500;
            }
            p[0x31C] = 5;
            p[0x31D] = func_00382468(4);
        }
        target = p + 0x80;
        func_L01_0045A9F0_003B4FD0(obj);
        lim = 0.5235988f;
        func_L07_003B6800(obj);
        a = func_L07_003B6DC8(obj, target);
        step = (func_0038DBA0(*(f32 *)(obj + 0xF8), a) / lim * 0.7f + 0.3f) * 0.020943953f;
        if (obj[0x42] == 8) {
            *(f32 *)(obj + 0xF8) = func_0038DB00(*(f32 *)(obj + 0xF8), step);
            if (func_0038DB00(*(f32 *)(obj + 0xF8), a) < -0.5235988f && obj[0x43] != 7) {
                func_003C3A10(obj, 7, 0, 2);
            }
        } else if (obj[0x42] == 7) {
            *(f32 *)(obj + 0xF8) = func_0038DAB8(*(f32 *)(obj + 0xF8), step);
            if (lim < func_0038DB00(*(f32 *)(obj + 0xF8), a) && obj[0x43] != 8) {
                func_003C3A10(obj, 8, 0, 2);
            }
        }
        func_0038CB00(p + 0x31A);
        if (func_L01_0040E020(p + 0x31C)) {
            func_L07_003B6E98(obj, p[0x31D]);
            p[0x31C] = 5;
            p[0x31D] = (p[0x31D] + 1) % 4;
        }
        if (func_L01_0040E570(obj + 0x10, p + 0x80) < 64.0f) {
            func_L07_003B64D0(obj, 0x11);
        } else if (func_0038CB00(p + 0x318) || func_L07_003B6CD8(obj, 1)) {
            *(s32 *)(p + 0xD8) &= ~0x10;
            func_L07_003B64D0(obj, 9);
        }
        break;
    case 9:
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 10);
        }
        break;
    case 10:
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            p[0x320]++;
            if (p[0x321] == 0 || p[0x321] == 5) {
                func_L07_003B6998(obj);
            } else if (p[0x320] >= 2) {
                p[0x320] = 0;
                func_L07_003B6998(obj);
            } else {
                if (*(s16 *)(p + 0x328) == 0) {
                    func_L07_003A2380(4, (s32)obj, 0, 100);
                    *(s16 *)(p + 0x328) = 500;
                }
                func_L07_003B64D0(obj, 12);
            }
        }
        break;
    case 11:
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 12);
        }
        break;
    case 12:
        if (func_L01_004561B8(obj)) {
            func_L01_00456230(obj, 0);
        }
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 13);
        }
        break;
    case 13:
        func_L01_0045A9F0_003B4FD0(obj);
        if (func_L01_004561B8(obj)) {
            p[0x31E] = 0xFF;
            *(s16 *)(p + 0x318) = 200;
            if (p[0x321] == 2) {
                *(s16 *)(p + 0x318) = 100;
            }
        }
        n = (s32)(func_L01_0040F518(func_L01_004395E0(obj) + 1.0f, 10.0f) * 0.5f);
        if (p[0x31E] != 0xFF && p[0x31E] != n) {
            func_L07_003B70F0(obj, D_L07_001DE478[n]);
        }
        p[0x31E] = n;
        if (p[0x321] == 3) {
            if ((D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8))[0x20] == 1) {
                p[0x321] = 4;
                func_L07_003B64D0(obj, 14);
            } else if (func_0038CB00(p + 0x318)) {
                func_L07_003B64D0(obj, 14);
            }
        } else if (func_0038CB00(p + 0x318) || func_L07_003B6CD8(obj, 1)) {
            func_L07_003B64D0(obj, 14);
        }
        break;
    case 14:
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            if (p[0x321] == 5) {
                func_L07_003B64D0(obj, 7);
            } else if (p[0x321] == 3) {
                func_L07_003B64D0(obj, 0x16);
            } else if (p[0x321] == 4) {
                p[0x321] = 5;
                func_L07_003B6B38(obj);
            } else {
                func_L07_003B64D0(obj, 15);
            }
        }
        break;
    case 15:
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            p[0x320]++;
            if (p[0x321] == 0) {
                func_L07_003B6998(obj);
            } else if (p[0x320] >= 2) {
                p[0x320] = 0;
                func_L07_003B6998(obj);
            } else {
                func_L07_003B64D0(obj, 7);
            }
        }
        break;
    case 17:
        f = func_L01_004395E0(obj);
        if (obj[0x42] == 14 && 10.0f <= f && f <= 20.0f) {
            func_L07_003B7230(obj);
        }
        if (obj[0x60] & 2) {
            func_L07_003B6998(obj);
        }
        break;
    case 18:
        if (func_L01_004561B8(obj)) {
            *(s32 *)(p + 0xD8) &= ~0x415;
            *(u16 *)(obj + 0x34) &= 0xAFFF;
            if (0.0f < *(f32 *)(p + 0x148)) {
                *(f32 *)(p + 0x148) = 0.0f;
            }
        }
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B6AE8(obj);
        }
        break;
    case 19:
        if (func_L01_004561B8(obj)) {
            flags = p + 0xA0;
            *(s32 *)(flags + 0x38) |= 0x415;
        }
        if (obj[0x42] == 2 && 5.0f < func_L01_004395E0(obj)) {
            func_L07_003B7378(obj);
            func_L07_003B68F0(obj);
            v = *(V4_003B4FD0 *)(obj + 0x10);
            v.z += 50.0f;
            func_L01_0045A748_003B4FD0(obj, &v);
        } else {
            func_L01_0045A9F0_003B4FD0(obj);
        }
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 0x14);
        }
        break;
    case 20:
        if (func_L01_004561B8(obj)) {
            *(f32 *)(p + 0x314) = func_0038CF38(obj + 0x10, p + 0x2F0);
        }
        func_L07_003B7378(obj);
        func_L07_003B68F0(obj);
        v = *(V4_003B4FD0 *)(p + 0x2F0);
        v.z += func_0038CF38(obj + 0x10, &v) * 20.0f / *(f32 *)(p + 0x314) + 5.0f;
        if (func_L01_0045A748_003B4FD0(obj, &v) & 0x80) {
            func_L07_003B64D0(obj, 0x15);
        }
        break;
    case 21:
        if (obj[0x42] != 4 || func_L01_004395E0(obj) <= 15.0f) {
            func_L07_003B7378(obj);
            func_L07_003B68F0(obj);
            func_L01_0045A748_003B4FD0(obj, p + 0x2F0);
        } else {
            if (func_L01_004561B8(obj)) {
                if (p[0x322] != 0x16) {
                    Fx_003B4FD0 *fx = (Fx_003B4FD0 *)D_L07_001E1EC0;
                    fx[1].rate = 0.05f;
                    fx[1].count = 12;
                    fx[2].rate = 0.05f;
                    fx[2].count = 12;
                    fx[1].phase = 0;
                }
                func_L07_003B8D80(obj);
            }
            func_L01_0045A9F0_003B4FD0(obj);
        }
        if (obj[0x60] & 2) {
            *(s32 *)(p + 0xD8) &= ~0x415;
            if (p[0x322] == 0xFF) {
                x = p[0x31F];
                if (p[0x321] == 5) {
                    x = 1;
                } else if (p[0x321] == 1 || func_L07_003B6CD8(obj, 0)) {
                    if (x) {
                        x = 0;
                    } else {
                        x = 1;
                    }
                }
                func_L07_003B6BD8(obj, x);
            } else {
                func_L07_003B64D0(obj, p[0x322]);
            }
            if (p[0x321] == 5) {
                func_L07_003A2380(5, (s32)obj, 0, 100);
            }
        }
        break;
    case 22:
        func_L01_0045A9F0_003B4FD0(obj);
        if (func_L01_004561B8(obj)) {
            *(s16 *)(p + 0x318) = func_00382468(100) + 200;
        }
        func_0038CB00(p + 0x318);
        if (p[0x321] == 3) {
            if ((D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8))[0x20] == 1) {
                p[0x321] = 5;
                func_L07_003A2380(7, (s32)obj, 0, 100);
                func_L07_003B6B38(obj);
            } else if (*(s16 *)(p + 0x318) == 0) {
                func_L07_003B64D0(obj, 12);
            }
        } else {
            k = obj[0xBC];
            if (k == 4) {
                p[0x321] = 3;
                func_L07_003B64D0(obj, 12);
                obj[0xBC] = 0;
            } else if (k == 3) {
                func_L07_003B6B38(obj);
                obj[0xBC] = 0;
            } else if (*(s16 *)(p + 0x318) == 0) {
                if (k == 2) {
                    func_L07_003B64D0(obj, 0x17);
                    obj[0xBC] = 0;
                } else if (k == 1) {
                    func_L07_003B64D0(obj, 0x18);
                    obj[0xBC] = 0;
                }
            }
        }
        break;
    case 23:
    case 24:
        func_L01_0045A9F0_003B4FD0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 0x16);
        }
        break;
    case 25:
        if (obj[0x60] & 2) {
            func_L07_003A2450();
            if (func_00382468(2)) {
                func_L07_003A2380(0x4F, (s32)obj, 0, 100);
            } else {
                func_L07_003A2380(0x50, (s32)obj, 0, 100);
            }
            func_L03_0043FC00(obj, 0x1FFF, D_L07_001D66B0, 2, 3, 0xFF, 0xB4, 0,
                3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f);
            func_L07_003315B0(obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003B4FD0 */

/* localdecomp:start func_L07_003B5CC8 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0044E7D8(void *);
extern void func_L07_003B6320(u8 *);
extern void func_L07_003B62C8(u8 *);

void func_L07_003B5CC8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 t;

    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    *(f32 *)(p + 0x40) = 1.0f;
    p[0x3E] = 3;
    *(u16 *)(p + 0x32C) = *(u16 *)(p + 0x34);
    p[0x3F] = 0;
    p[0x64] = 0;
    t = *(u16 *)(a0 + 0xB6);
    p[0x39] = 0;
    *(f32 *)(p + 0xA0) = 3.0f;
    *(f32 *)(p + 0xA4) = 1.2f;
    *(f32 *)(p + 0xA8) = 1.2f;
    *(f32 *)(p + 0xAC) = 1.2f;
    *(f32 *)(p + 0xB0) = 3.1415927f;
    *(f32 *)(p + 0xD0) = 0.7853982f;
    *(f32 *)(p + 0xCC) = 0.00392f;
    *(f32 *)(p + 0xD4) = 0.2f;
    *(u16 *)(p + 0x32E) = t;
    func_L01_0045BD78(a0, 0.072000005f, 0.40000004f, 0.0012566372f, 0.06283186f);
    *(void **)(p + 0x194) = func_L07_003B6320;
    *(void **)(p + 0x198) = func_L07_003B62C8;
    *(u8 *)(p + 0x1AD) = 0xFF;
    *(s16 *)(p + 0x19C) = -1;
    *(s32 *)(p + 0x33C) = func_L01_0044E7D8(a0);
    func_L07_003B62C8(a0);
}
/* localdecomp:end func_L07_003B5CC8 */

/* localdecomp:start func_L07_003B5E08 */
typedef struct { u8 bytes[16]; } Saved_003B5E08;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0x89]; s16 oclass; } M_003B5E08;
typedef struct {
    u8 pad0[0x30]; f32 health; s16 max_health; u8 pad36[0x11]; u8 color;
    u8 pad48[0x16]; u8 flag5E, pad5F, flag60; u8 pad61[0xF]; Saved_003B5E08 damage;
    u8 pad80[0x110]; s32 anim; u8 pad194[0x11C]; u8 bone[0x50]; s32 child_index;
    u8 pad304[4]; M_003B5E08 *child; u8 pad30C[0x15]; u8 phase; u8 pad322[2]; u8 tracking;
    u8 pad325; u8 effect; u8 pad327; s16 timer; u8 pad32A[6]; s16 cooldown;
    u8 pad332[10]; s32 saved;
} State_003B5E08;
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001E1EC0[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
void func_L07_003B5E08(u8 *obj)
{
    extern s32 func_L01_00447490(void *, s32, s32);
    extern f32 func_L01_004474E8(void *, s32);
    extern s32 func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_00459BE8(void *, s32, f32);
    extern void func_003C4A40(void *, void *);
    extern void func_L01_0044ABD0(void *, void *);
    extern void func_L01_0044E820(void *, s32);
    extern s32 func_0038CB00(void *);
    extern s32 func_L07_003A2380(u8, s32, u8, s16);
    extern void func_L07_003B64D0(u8 *, s32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                                s32, s32, s32, s32, s32, s32, s32);
    extern void func_L07_003315B0(void *);
    extern void func_L01_0047C990(s32, s32, s32, f32);
    extern void func_L01_00456BD0(void *, s32);
    extern s32 func_L07_00333D20(s32);
    extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                                s32, s32, s32, s32);
    extern void func_L07_003B6870(u8 *);
    extern void func_L07_004522E8(void *, s32, void *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_004472C0(void *);
    Saved_003B5E08 saved;
    State_003B5E08 *p = *(State_003B5E08 **)(obj + 0x68);
    Saved_003B5E08 *damage;
    u8 *child;
    f32 amount;
    s32 hit;
    Pool_003AF678 *pool;
    if (obj[0x20] == 1) return;
    hit = func_L01_00447490(obj, -1, 0);
    damage = &p->damage;
    amount = func_L01_004474E8(obj, hit);
    obj[0xA8] = 255;
    if ((*(u16 *)(obj + 0x34) & 0x4000) && amount > 0.0f) {
        if (p->cooldown == 0) {
            func_L01_004AAC98(0, 0, obj, 0x1A1C);
            p->cooldown = 50;
        }
        p->health -= amount;
        func_L01_00459BE8(obj, p->color, amount);
        p->damage.bytes[7] = 255;
        func_003C4A40(obj, damage);
        if ((f32)p->max_health * 0.1f <= amount) {
            child = D_L07_001DF41C + (p->child_index << 8);
            if (child[0xBC] == 0) child[0xBC] = 2;
        }
    }
    func_L01_0044ABD0(obj, damage);
    if (*(s16 *)&p->damage == 0) func_L01_0044E820(obj, p->saved);
    func_0038CB00(&p->cooldown);
    if (p->phase == 0) {
        if (p->health < (f32)p->max_health * 0.66f) {
            func_L07_003A2380(6, (s32)obj, 0, 100);
            func_L07_003B64D0(obj, 18);
            p->phase = 1;
            p->effect = 3;
            p->health = (f32)p->max_health * 0.66f;
        }
    } else if (p->phase == 1) {
        if (p->health < (f32)p->max_health * 0.33f) {
            func_L07_003B64D0(obj, 18);
            p->phase = 2;
            p->effect = 3;
            p->health = (f32)p->max_health * 0.33f;
        }
    }
    if (p->effect) {
        M_003B5E08 *linked = p->child;
        if (linked) {
            if (linked->oclass != 0x1C81 || linked->state == 0xFE || linked->state == 0xFD) p->child = 0;
        } else {
            ((u8 *)((p->child_index << 8) + (s32)D_L07_001DF41C))[0xBC] = p->effect;
            p->effect = 0;
        }
    }
    if (p->health <= 0.0f) {
        saved = p->damage;
        func_L01_0043B9E8(obj, saved.bytes[4], saved.bytes[5], saved.bytes[6]);
        func_L01_00451FE0(obj, 0x3FFF, D_L07_001D66B0,
                          8.0f, 12.0f, 8.0f, 12.0f, -1.0f, -1.0f, 1.0f, 1.0f, 255, 180, 0, 0, 35, 0, 3);
        func_L07_003315B0(obj);
        return;
    }
    if (p->flag5E) {
        func_L07_003315B0(obj);
        p->flag5E = 0;
        return;
    }
    if (p->flag60) {
        func_L07_003315B0(obj);
        p->flag60 = 0;
        return;
    }
    if (p->tracking) {
        Pool_003AF678 *g = (Pool_003AF678 *)D_L07_001E1EC0;
        if (g->w144 != obj && g->w144 == 0) {
            g->w144 = obj;
            g->w148 = 0;
        }
    } else {
        Pool_003AF678 *g = (Pool_003AF678 *)D_L07_001E1EC0;
        if (g->w144 == obj) g->w144 = 0;
    }
    pool = (Pool_003AF678 *)D_L07_001E1EC0;
    func_L01_0047C990(2, 0, pool->w144 != obj, p->health / (f32)p->max_health);
    func_L01_00456BD0(obj, 3);
    hit = func_L07_00333D20(p->anim);
    func_L01_00456C98(obj, 0.0f, 0.0f, 1.0f, hit, 0, 0, 0, 0, 1, 0, 0, 0);
    func_L07_003B6870(obj);
    func_0038CB00(&p->timer);
    func_L07_004522E8(obj, 17, p->bone, 2.5f);
    if (func_L01_0040E548(pool, obj + 0x10) < 5625.0f) {
        func_L01_004472C0(obj);
        obj[0x6F] = 70;
    }
}
/* localdecomp:end func_L07_003B5E08 */

/* localdecomp:start func_L07_003B62C8 */
extern u8 D_L07_001E1EC0[];
extern void func_L07_00334740(void *);
extern void func_L07_003B64D0(u8 *, s32);
void func_L07_003B62C8(u8 *arg0) {
    u8 *g = D_L07_001E1EC0;
    u8 *p = *(u8 **)(arg0 + 0x68);
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    if (*(u8 **)(g + 0x144) == arg0) *(u8 **)(g + 0x144) = 0;
    func_L07_00334740(arg0);
    func_L07_003B64D0(arg0, 1);
}
/* localdecomp:end func_L07_003B62C8 */

/* localdecomp:start func_L07_003B6320 */
extern u8 D_001426E0[];
extern u8 D_00142660[];
void func_L07_003B6320(u8 *self) {
    extern s32 func_L01_0041A4F0(void);
    extern f32 func_L07_00334A98(s32);
    extern f32 func_L01_004DFE88(s32);
    extern void func_L07_00334800(u8 *);
    u8 *g = D_001426E0;
    u8 *p = *(u8 **)(self + 0x68);
    f32 ratio, health;
    u8 tint;
    if (!g[0x83]) {
        g[0x83] = D_00142660[8];
        g[0xD7] = D_00142660[0x40];
    }
    if (func_L01_0041A4F0()) {
        *(s16 *)(p + 0x34) = 1000;
        *(f32 *)(p + 0x30) = 1000.0f;
        ratio = 1000.0f / (f32)*(s16 *)(p + 0x32C);
    } else {
        ratio = func_L07_00334A98(g[0x83]);
        *(s16 *)(p + 0x34) = (f32)*(s16 *)(p + 0x32C) * ratio;
        *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34);
    }
    health = ratio * (f32)*(s16 *)(p + 0x32E);
    if (health > 65535.0f) health = 65535.0f;
    *(s16 *)(self + 0xB6) = health;
    tint = (u8)(((f32)D_001426E0[0x83] / func_L01_004DFE88(D_001426E0[0xD7])) * 0.125f);
    {
    s32 one = 1;
    p[0x327] = 0;
    p[0x321] = 0;
    *(s16 *)(p + 0x328) = 0;
    p[0x324] = one;
    *(f32 *)(p + 0x310) = (f32)*(s16 *)(p + 0x34);
    p[0x44] = tint;
    p[0x45] = tint;
    p[0x46] = tint;
    func_L07_00334800(self);
    }
    func_L07_003B64D0(self, 2);
}
/* localdecomp:end func_L07_003B6320 */
