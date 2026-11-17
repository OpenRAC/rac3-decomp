#include "common.h"

/* declared by functions of L28_003420C0.c, which this file was cut from */
extern s32 D_L28_001DCF18;

/* localdecomp:start func_L28_003421E0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003421E0;
__asm__(".extern D_L28_001DCF18, 4");
__asm__(".extern D_L28_001D6694, 16");
__asm__(".extern D_L28_001DE840, 16");
__asm__(".extern D_L28_001DEA34, 16");
__asm__(".extern D_L28_001DED80, 16");
__asm__(".extern D_001D52FC, 16");
__asm__(".extern D_001D5470, 16");
extern s32 D_L28_001D6694;
extern s32 D_L28_001DE840;
typedef struct { s16 f34; s16 f36; s32 f38; } S_003421E0;
extern S_003421E0 D_L28_001DEA34;
extern u8 *D_L28_001DED80;
extern u8 *D_001D52FC;
typedef struct { u8 f0; u8 f1; } S2_003421E0;
extern S2_003421E0 D_001D5470;
extern u8 D_00142715[];
extern u8 D_00142716[];
extern s16 D_001426A2[];
extern u8 D_00142660[];
extern u8 D_001426E0[];
extern u32 D_00142BA0[];
extern u8 D_001A4C60[];
extern u8 D_001A4CC0[];
extern u8 D_L28_001E8040[];
extern u8 D_L28_001E1540[];
extern s32 func_0038CAD0(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern s32 func_L01_0041A4F0(void);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L10_0042A4D0(void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00459C50(s32);
extern void func_L28_00428400(s32, ...);
extern s32 func_L04_0046FFA0(u8 *, s32, f32);
extern void func_L01_0047F3B0(void *);
extern void func_003E54E0(s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
void func_L28_003421E0(u8 *self) {
    u8 *pv;
    u8 *g;
    s32 mult;
    s32 k;
    u8 *hero;
    s32 c;
    s32 aim;
    s16 n;
    f32 ka;
    f32 kb;
    f32 yaw;
    f32 pitch;
    f32 f;
    V_003421E0 tgt;
    V_003421E0 pos;
    V_003421E0 d;

    pv = *(u8 **)(self + 0x68);
    if (D_L28_001D6694 == 6) {
        self[0x31] = 0;
        *(u16 *)(self + 0x34) |= 1;
        *(f32 *)(self + 0xF4) = -3.1415927f;
    } else {
        self[0x31] = 1;
        *(u16 *)(self + 0x34) &= ~1;
        *(f32 *)(self + 0xF4) = 0.0f;
    }
    if (D_L28_001DE840 == 5) {
        func_L28_003420C0();
    }
    switch (self[0x20]) {
    case 0:
        func_L28_003420C0();
        func_L10_0042A4D0(self);
        if (D_00142715[0] != 0) {
            if (D_001426A2[0] <= 0) {
                func_L01_004450F0(self, 6, -1);
            } else {
                func_L01_004450F0(self, 7, -1);
            }
        } else {
            func_L01_004450F0(self, 1, -1);
        }
        break;
    case 1:
        if (func_00382380(D_001A4C60, *(s32 *)(pv + 0x128), 0) == 0) break;
        if (func_L04_0046FFA0(self, 10, 1000.0f) == 0) break;
        func_L01_0047F3B0(self);
        if (func_00392B20(D_L28_001E8040, 0xCA) == 0) break;
        D_00142715[0] = 1;
        func_00392C78(D_L28_001E8040);
        func_L01_004450F0(self, 2, -1);
        break;
    case 2:
        if (D_L28_001D6694 == 2) {
            self[0x31] = 0;
            *(u16 *)(self + 0x34) |= 1;
        }
        D_L28_001DEA34.f38 = 1;
        if (func_L01_004BA800() != 0) break;
        func_L01_004F50C8(D_L28_001DED80 + *(s32 *)(pv + 0x130) * 0x80 + 0x30,
                          D_L28_001DED80 + *(s32 *)(pv + 0x130) * 0x80 + 0x70, 0, 1);
        D_L28_001DEA34.f38 = 0;
        self[0x31] = 1;
        *(u16 *)(self + 0x34) &= ~1;
        if (D_001426A2[0] <= 0) {
            func_L01_004450F0(self, 6, -1);
        } else {
            func_L01_004450F0(self, 7, -1);
        }
        break;
    case 6:
        if (D_001426A2[0] > 0) {
            func_L01_004450F0(self, 7, -1);
            break;
        }
        if (func_00382380(D_001A4C60, *(s32 *)(pv + 0x12C), 0) == 0) break;
        if (func_L04_0046FFA0(self, 10, 1000.0f) == 0) break;
        if (D_L28_001DCF18 == 0) {
            func_L28_00428400(0xC56, 0, -1);
            D_00142716[0] = 1;
        } else {
            func_L28_00428400(0xC56, D_L28_001DCF18, -1);
        }
        func_L01_0047F3B0(self);
        break;
    case 7:
        g = D_00142660;
        if (*(s16 *)(g + 0x42) <= 0) {
            func_L01_004450F0(self, 6, -1);
            break;
        }
        mult = 1;
        if (g[0x32] != 0) {
            mult = 10;
        }
        if (func_00382380(D_001A4C60, *(s32 *)(pv + 0x12C), 0) == 0) break;
        if (func_L04_0046FFA0(self, 10, 1000.0f) == 0) break;
        if (func_L01_0041A4F0() != 0) {
            n = *(s16 *)(g + 0x42);
            if (n < 2) { k = 2000; k *= mult; func_L28_00428400(0x1949, n, n * k, -1); } else { k = 2000; k *= mult; func_L28_00428400(0xBF3, n, n * k, -1); }
        } else {
            n = *(s16 *)(g + 0x42);
            if (n >= 2) { k = 2000; k *= mult; func_L28_00428400(0xBF3, n, n * k, -1); } else { k = 2000; k *= mult; func_L28_00428400(0x1949, n, n * k, -1); }
        }
        func_L01_0047F3B0(self);
        if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) == 0) break;
        if (func_L28_003420C0() <= 0) {
            func_L01_00459C50(0x18);
        }
        k = 2000; k *= mult;
        *(s32 *)D_00142660 += *(s16 *)(D_00142660 + 0x42) * k;
        func_L01_004AAC98(0, 0, self, func_00382498(0xD, 0x11));
        c = *(u8 *)(D_00142660 + 0x42);
        *(s16 *)(D_00142660 + 0x42) = 0;
        D_001426E0[0x7E] += c;
        func_003E54E0(0x96);
        func_L01_004450F0(self, 8, -1);
        if ((D_00142BA0[0xCC / 4] & 0x1000) == 0 && func_00392B20(D_L28_001E8040, 0xCC) != 0) {
            func_00392C78(D_L28_001E8040);
            func_L01_004450F0(self, 2, -1);
        }
        if (D_L28_001DCF18 != 0) break;
        if (D_00142BA0[0xC8 / 4] & 0x800) break;
        if (func_00392B20(D_L28_001E8040, 0xCB) == 0) break;
        func_00392C78(D_L28_001E8040);
        func_L01_004450F0(self, 2, -1);
        break;
    case 8:
        if (func_L01_004561B8(self) != 0) {
            func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
        }
        if (++*(u16 *)(self + 0x96) > 0x7FF8) {
            *(u16 *)(self + 0x96) = 0x7FF8;
        }
        if (*(u16 *)(self + 0x96) >= 0x22 && *(u16 *)(self + 0x96) <= 0x4A && *(u16 *)(self + 0x96) % 3 == 0) {
            func_L01_004AAC98(0, 0, self, func_00382498(0xD, 0x11));
        }
        if (func_L04_0046FFA0(self, 10, 2.5f) != 0) {
            func_L28_00428400(0xC56, D_L28_001DCF18, -1);
        } else {
            func_L01_004450F0(self, 6, -1);
        }
        break;
    }

    if (self[0x20] != 0) {
        if (self[0x43] == 0 && func_0038CAD0(pv + 0x11C) != 0) {
            *(s32 *)(pv + 0x11C) = (func_003824E0(1200.0f, 2400.0f) * 5.0f + 2.0f) / 6.0f;
            if (self[0x43] != 1) {
                func_003C3A10(self, 1, 0, 8);
            }
        } else if ((self[0x60] & 2) && self[0x43] != 0) {
            func_003C3A10(self, 0, 0, 8);
        }
    }

    ka = 0.02f;
    kb = 0.3f;
    aim = 0;
    if (self[0x43] == 0) {
        aim = 1;
        if (func_0038CF38(self + 0x10, D_001A4C60) < 8.0f
            && (hero = D_001A4C60 - 0x80, func_0038DBA0(*(f32 *)(self + 0xF8),
                             func_0038D160(*(f32 *)(hero + 0xE0) - *(f32 *)(self + 0x10),
                                           *(f32 *)(hero + 0xE4) - *(f32 *)(self + 0x14)))) < 1.5707964f) {
            if (0.01f < func_0038CEA8(D_001A4C60 + 0x90)) {
                *(s32 *)(pv + 0x114) = 100;
            } else {
                func_0038CAD0(pv + 0x114);
            }
        } else if (*(s32 *)(pv + 0x114) != 0) {
            *(s32 *)(pv + 0x114) = 0;
            *(V_003421E0 *)(pv + 0x100) = *(V_003421E0 *)D_001A4CC0;
        }
        if (func_0038CAD0(pv + 0x118) != 0) {
            f32 r = 6.0f;
            f32 dr = 0.017453292f;
            f32 h;
            f32 e;
            *(s32 *)(pv + 0x118) = (func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / r;
            h = func_0038DAB8(*(f32 *)(self + 0xF8), func_003824E0(-90.0f, 90.0f) * dr);
            e = func_003824E0(0.0f, 30.0f) * dr;
            func_00382760(pv + 0x100, r, h, e);
            vec_add_ab(pv + 0x100, pv + 0x100, self + 0x10);
        }
        if (*(s32 *)(pv + 0x114) != 0) {
            ka = 0.04f;
            kb = 0.3f;
            tgt = *(V_003421E0 *)D_001A4CC0;
        } else {
            tgt = *(V_003421E0 *)(pv + 0x100);
        }
    }
    if (aim) {
        pos = *(V_003421E0 *)(self + 0x10);
        pos.z += 2.0f;
        vec_sub_ab(&d, &tgt, &pos);
        yaw = func_0038DB00(func_0038D160(d.x, d.y), *(f32 *)(self + 0xF8));
        pitch = -func_0038D160(func_0038CED8(&d), d.z);
        if (yaw > 1.5707964f) {
            yaw = 1.5707964f;
        } else if (yaw < -1.5707964f) {
            yaw = -1.5707964f;
        }
        if (pitch > 0.5235988f) {
            pitch = 0.5235988f;
        } else if (pitch < -0.5235988f) {
            pitch = -0.5235988f;
        }
        *(f32 *)(pv + 0x64) = pitch;
        *(f32 *)(pv + 0x68) = yaw * 0.6f;
        *(f32 *)(pv + 0xE8) = yaw * 0.4f;
    }
    if (D_001D5470.f1 != 0) {
        *(f32 *)(pv + 0x70) = 2.75f;
    }
    f = 1.44f;
    func_L01_0044E850(self, pv, 0, ka * f, kb * f);
    func_L01_0044E850(self, pv + 0x80, 1, ka * f, kb * f);
    if (self[0x31] != 0 && func_L01_0040E548(D_L28_001E1540, self + 0x10) < 1024.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 30;
    }
}
/* localdecomp:end func_L28_003421E0 */
