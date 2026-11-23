#include "common.h"

/* NTSC-U counterpart of func_L28_0039BA28 (src/levels/28_aquatos_sewers/L28_0039B910.c) */
#include "vu0.h"
typedef int q_0039BA28 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039BA28;
extern s32 D_L28_001DE840_00399E28;
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L28_00399E28 */
extern f32 D_L28_001DDE00_00399E28;
__asm__(".extern D_L28_001DDE00_00399E28, 4");
extern f32 D_L28_001DDE04_00399E28;
__asm__(".extern D_L28_001DDE04_00399E28, 4");
extern f32 D_L28_001DDE08_00399E28;
__asm__(".extern D_L28_001DDE08_00399E28, 4");
extern f32 D_L28_001DDE0C_00399E28;
__asm__(".extern D_L28_001DDE0C_00399E28, 4");
extern f32 D_L28_001DDE10_00399E28;
__asm__(".extern D_L28_001DDE10_00399E28, 4");
extern f32 D_L28_001DDE14_00399E28;
__asm__(".extern D_L28_001DDE14_00399E28, 4");
extern s32 D_L28_001DDE18_00399E28;
__asm__(".extern D_L28_001DDE18_00399E28, 4");
extern f32 D_L28_001DDE1C_00399E28;
__asm__(".extern D_L28_001DDE1C_00399E28, 4");
extern f32 D_L28_001DDE20_00399E28;
__asm__(".extern D_L28_001DDE20_00399E28, 4");
extern f32 D_L28_001DDE24_00399E28;
__asm__(".extern D_L28_001DDE24_00399E28, 4");
extern f32 D_L28_001DDE28_00399E28;
__asm__(".extern D_L28_001DDE28_00399E28, 4");
extern f32 D_L28_001DDE2C_00399E28;
__asm__(".extern D_L28_001DDE2C_00399E28, 4");
extern s32 D_L28_001DDE34_00399E28;
__asm__(".extern D_L28_001DDE34_00399E28, 4");
extern s32 D_L28_001DDE38_00399E28;
__asm__(".extern D_L28_001DDE38_00399E28, 4");
extern s32 D_L28_001DDE3C_00399E28;
__asm__(".extern D_L28_001DDE3C_00399E28, 4");
extern s32 D_L28_001DDE40_00399E28;
__asm__(".extern D_L28_001DDE40_00399E28, 4");
extern f32 D_L28_001DDE44_00399E28;
__asm__(".extern D_L28_001DDE44_00399E28, 4");
extern f32 D_L28_001DDE48_00399E28;
__asm__(".extern D_L28_001DDE48_00399E28, 4");
extern f32 D_L28_001DDE4C_00399E28;
__asm__(".extern D_L28_001DDE4C_00399E28, 4");
extern f32 D_L28_001DDE50_00399E28;
__asm__(".extern D_L28_001DDE50_00399E28, 4");
extern f32 D_L28_001DDE54_00399E28;
__asm__(".extern D_L28_001DDE54_00399E28, 4");
extern f32 D_L28_001DDE58_00399E28;
__asm__(".extern D_L28_001DDE58_00399E28, 4");
extern f32 D_L28_001DDE5C_00399E28;
__asm__(".extern D_L28_001DDE5C_00399E28, 4");
extern f32 D_L28_001DDE60_00399E28;
__asm__(".extern D_L28_001DDE60_00399E28, 4");
extern f32 D_L28_001DDE64_00399E28;
__asm__(".extern D_L28_001DDE64_00399E28, 4");
extern f32 D_L28_001DDE68_00399E28;
__asm__(".extern D_L28_001DDE68_00399E28, 4");
extern s32 D_L28_001DDE6C_00399E28;
__asm__(".extern D_L28_001DDE6C_00399E28, 4");
extern s32 D_L28_001DDE70_00399E28;
__asm__(".extern D_L28_001DDE70_00399E28, 4");
extern s32 D_L28_001DDE74_00399E28;
__asm__(".extern D_L28_001DDE74_00399E28, 4");
extern s32 D_L28_001DDE78_00399E28;
__asm__(".extern D_L28_001DDE78_00399E28, 4");
extern s32 D_L28_001DDE7C_00399E28;
__asm__(".extern D_L28_001DDE7C_00399E28, 4");
extern s32 D_L28_001DDE80_00399E28;
__asm__(".extern D_L28_001DDE80_00399E28, 4");
extern s32 D_L28_001DDE84_00399E28;
__asm__(".extern D_L28_001DDE84_00399E28, 4");
extern s32 D_L28_001DDE88_00399E28;
__asm__(".extern D_L28_001DDE88_00399E28, 4");
extern s32 D_L28_001DDE8C_00399E28;
__asm__(".extern D_L28_001DDE8C_00399E28, 4");
extern s32 D_L28_001DDE90_00399E28;
__asm__(".extern D_L28_001DDE90_00399E28, 4");
extern f32 D_L28_001DDE94_00399E28;
__asm__(".extern D_L28_001DDE94_00399E28, 4");
extern f32 D_L28_001DDE98_00399E28;
__asm__(".extern D_L28_001DDE98_00399E28, 4");
extern f32 D_L28_001DDE9C_00399E28;
__asm__(".extern D_L28_001DDE9C_00399E28, 4");
extern f32 D_L28_001DDEA0_00399E28;
__asm__(".extern D_L28_001DDEA0_00399E28, 4");
extern f32 D_L28_001DDEA4_00399E28;
__asm__(".extern D_L28_001DDEA4_00399E28, 4");
extern f32 D_L28_001DDEA8_00399E28;
__asm__(".extern D_L28_001DDEA8_00399E28, 4");
extern f32 D_L28_001DDEAC_00399E28;
__asm__(".extern D_L28_001DDEAC_00399E28, 4");
extern f32 D_L28_001DDEB0_00399E28;
__asm__(".extern D_L28_001DDEB0_00399E28, 4");
extern f32 D_L28_001DDEB4_00399E28;
__asm__(".extern D_L28_001DDEB4_00399E28, 4");
extern f32 D_L28_001DDEB8_00399E28;
__asm__(".extern D_L28_001DDEB8_00399E28, 4");
extern s32 D_L28_001DDEBC_00399E28;
__asm__(".extern D_L28_001DDEBC_00399E28, 4");
extern s32 D_L28_001DDEC0;
__asm__(".extern D_L28_001DDEC0, 4");
extern s32 D_L28_001DDEC4;
__asm__(".extern D_L28_001DDEC4, 4");
extern s32 D_L28_001DDEC8;
__asm__(".extern D_L28_001DDEC8, 4");
extern s32 D_L28_001DDECC;
__asm__(".extern D_L28_001DDECC, 4");
extern s32 D_L28_001DDED0;
__asm__(".extern D_L28_001DDED0, 4");
extern s32 D_L28_001DDED4;
__asm__(".extern D_L28_001DDED4, 4");
extern s32 D_L28_001DDED8;
__asm__(".extern D_L28_001DDED8, 4");
extern f32 D_L28_001DDEDC;
__asm__(".extern D_L28_001DDEDC, 4");
extern s32 D_L28_001DDEE0;
__asm__(".extern D_L28_001DDEE0, 4");
extern s32 D_L28_001DDEE4;
__asm__(".extern D_L28_001DDEE4, 4");
extern f32 D_L28_001DDEE8;
__asm__(".extern D_L28_001DDEE8, 4");
extern f32 D_L28_001DDEEC;
__asm__(".extern D_L28_001DDEEC, 4");
extern f32 D_L28_001DDEF0;
__asm__(".extern D_L28_001DDEF0, 4");
extern f32 D_L28_001DDEF4;
__asm__(".extern D_L28_001DDEF4, 4");
extern f32 D_L28_001DDEF8;
__asm__(".extern D_L28_001DDEF8, 4");
extern f32 D_L28_001DDEFC;
__asm__(".extern D_L28_001DDEFC, 4");


extern u8 *D_L28_001DEC9C_00399E28;
__asm__(".extern D_L28_001DEC9C_00399E28, 16");
extern s32 D_L28_001DE840_00399E28;
extern u8 *D_001A73E8[];
extern u8 D_001A4BE0[];

extern s32 func_L28_0039AF78(u8 *);
extern void func_L08_0039F170(void *);
extern void func_L28_0039B520(u8 *);
extern void func_003BD360(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00459F10(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern f32 func_L01_00436500(void *);
extern void func_L01_00443790(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_L01_00443648(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_003894A0(f32, u32, u32);
extern void func_L01_00470258(void *, void *, s32, s32, s16, u8, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static inline f32 fmin_0039BA28(f32 a, f32 b) {
    if (a < b) return a;
    return b;
}
static inline f32 fmin2_0039BA28(f32 a, f32 b) {
    return a < b ? a : b;
}
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

void func_L28_00399E28(u8 *self) {
    V4_0039BA28 v;
    V4_0039BA28 a;
    V4_0039BA28 b;
    V4_0039BA28 c;
    V4_0039BA28 n;
    u8 *st = *(u8 **)(self + 0x68);
    u8 *m;
    s32 idx;
    s32 i, j, k, n6, n8;
    f32 f, g, f6, f9, save;

    if (func_L28_0039AF78(self) != 0) {
        func_L08_0039F170(self);
        func_003BD360(self);
        return;
    }

    switch (self[0x20]) {
    case 1:
        if (S32(st, 0x1BC) == 2) {
            func_L01_00441FB8(self, 2, -1);
            break;
        }
        idx = S32(st, 0x1B0);
        if (idx != -1) {
            m = D_L28_001DEC9C_00399E28 + (idx << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_0037E1D8(0x3C) == 0) {
                    func_L01_00441FB8(self, 2, -1);
                    break;
                }
            }
        } else if (S32(st, 0x1B8) != idx) {
            m = D_L28_001DEC9C_00399E28 + (S32(st, 0x1B8) << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_0037E1D8(0x3C) == 0) {
                    func_L01_00441FB8(self, 2, -1);
                    break;
                }
            }
        } else if (S16(st, 0x174) == 1) {
            if (func_0037E1D8(0x3C) == 0) {
                func_L01_00441FB8(self, 2, -1);
                break;
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8(self) != 0) {
            u8 *o = *(u8 **)(self + 0x24);
            U16(self, 0x34) &= ~0x41;
            U16(self, 0x34) |= U16(o, 0x44) & 0x1000;
            S32(self, 0x98) = S32(o, 0x10);
            if (self[0x43] != 2) {
                func_003BE4F0(self, 2, 0, 10);
            }
            S16(st, 0x36) = 0x28;
            F32(self, 0xC0) = 1.0f;
            S32(self, 0xC4) = 0;
            S32(self, 0xC8) = 0;
            vec_sub_ba(&v, st + 0x160, self + 0x10);
            func_00388830(&v, &v, 1.0f);
            if (abs_asm(func_00388730(&v, self + 0xE0) < 0.9f)) {
                *(q_0039BA28 *)(self + 0xC0) = *(q_0039BA28 *)&v;
            }
            func_00388758(self + 0xD0, self + 0xE0, self + 0xC0);
            func_00388830(self + 0xD0, self + 0xD0, 1.0f);
            func_00388758(self + 0xC0, self + 0xD0, self + 0xE0);
            func_00388830(self + 0xC0, self + 0xC0, 1.0f);
            F32(st, 0x1C8) = F32(self, 0x2C);
            func_0039FE80(6, 0, self);
        }
        func_L01_00459F10(self, self + 0x10);
        F32(self, 0x2C) = fmin2_0039BA28(F32(st, 0x1C8) * (f32)U16(self, 0x96) / 30.0f, F32(st, 0x1C8));
        if (self[0x60] & 2) {
            func_L01_00441FB8(self, 3, -1);
            if (self[0x43] != 1) {
                func_003BE4F0(self, 1, 0, 10);
            }
            F32(self, 0x2C) = F32(st, 0x1C8);
        }
        break;
    case 3:
        if (func_L01_00452EC8(self) != 0) {
            if (self[0x42] != 1 && self[0x43] != 1) {
                func_003BE4F0(self, 1, 0, 10);
            }
        }
        func_L01_00459F10(self, self + 0x10);
        if (S16(st, 0x174) == 1 && (func_0037E1D8(0x3C) == 0 || U16(self, 0x96) > 0x3C)) {
            func_L01_00441FB8(self, 6, -1);
            break;
        }
        if (S32(st, 0x1C0) != 0 && (func_0037E1D8(0x1E) == 0 || U16(self, 0x96) > 0x1E)) {
            func_L01_00441FB8(self, 5, -1);
            S32(st, 0x1C0) = 0;
        }
        break;
    case 4:
        if (func_L01_00452EC8(self) != 0) {
            f32 ang4, r4;
            if (self[0x42] != 0 && self[0x43] != 0) {
                func_003BE4F0(self, 0, 0, 10);
            }
            ang4 = func_0037E2A8();
            r4 = func_0037E250(4.0f, 8.0f);
            qzero(st + 0x1A0);
            F32(st, 0x1A0) = func_00388960(ang4) * r4;
            F32(st, 0x1A4) = func_00388978(ang4) * r4;
            vec_add_ab(st + 0x1A0, st + 0x1A0, st + 0x190);
            func_L01_00458A70(self, D_L28_001DDE04_00399E28 * 0.5f * 0.00027777778f, D_L28_001DDE00_00399E28 * 0.5f * 0.016666668f,
                              0.0069813174f, 0.20943953f);
        }
        func_00388830(&a, self + 0xC0, 3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_00459F10(self, &v);
        f = func_00388A28(F32(st, 0x1A0) - F32(self, 0x10), F32(st, 0x1A4) - F32(self, 0x14));
        if (func_00389468(F32(self, 0xF8), f) > 0.17453292f) {
            func_00389158(self + 0xC0, self + 0xC0, self + 0xE0, 0.07563094f);
            func_00389158(self + 0xD0, self + 0xD0, self + 0xE0, 0.07563094f);
            F32(self, 0xF8) = func_00388A28(F32(self, 0xC0), F32(self, 0xC4));
        }
        if (func_00388800(self + 0x10, st + 0x1A0) < 0.75f) {
            func_L01_00441FB8(self, 4, -1);
        }
        if (S16(st, 0x174) == 1 || D_L28_001DDE34_00399E28 < U16(self, 0x96)) {
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(self) != 0) {
            if (self[0x42] != 1 && self[0x43] != 1) {
                func_003BE4F0(self, 1, 0, 10);
            }
        }
        func_L01_00459F10(self, self + 0x10);
        if (S16(st, 0x174) == 1) {
            func_L01_00441FB8(self, 6, -1);
            break;
        }
        if (D_L28_001DDE38_00399E28 < U16(self, 0x96) && func_0037E1D8(0x64) == 0) {
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(self) != 0) {
            if (self[0x43] != 0) {
                func_003BE4F0(self, 0, 0, 10);
            }
            self[0xBC] = 0;
            func_L01_00458A70(self, D_L28_001DDE04_00399E28 * 0.00027777778f, D_L28_001DDE00_00399E28 * 0.016666668f, 0.0069813174f,
                              0.20943953f);
        }
        if (self[0xBC] == 0) {
            func_L01_00459F10(self, st + 0x160);
            F32(self, 0xF8) = func_00388A28(F32(self, 0xC0), F32(self, 0xC4));
            if (func_0037E1D8(D_L28_001DDE3C_00399E28) == 0) {
                func_L01_00441FB8(self, 7, -1);
            }
            vec_sub_ba(&v, st + 0x160, self + 0x10);
            func_00388830(&v, &v, 1.0f);
            f6 = func_00388730(&v, self + 0xC0);
            if (func_00388800(self + 0x10, st + 0x160) < D_L28_001DDE08_00399E28 && D_L28_001DDE0C_00399E28 < f6) {
                self[0xBC] = 1;
                if (self[0x43] != 4) {
                    func_003BE4F0(self, 4, 0, 10);
                }
                func_L01_00458A70(self, D_L28_001DDE14_00399E28 * 0.00027777778f, D_L28_001DDE10_00399E28 * 0.016666668f,
                                  0.0069813174f, 0.20943953f);
            }
        } else if (self[0xBC] == 1) {
            if (func_L01_00436500(self) > 11.0f && func_L01_00436500(self) < 18.0f && self[0x42] == 4 &&
                func_00388800(self + 0x10, st + 0x160) > 1.75f) {
                save = F32(st, 0xA4);
                S32(st, 0xA4) = 0;
                for (n6 = 0; n6 < D_L28_001DDE18_00399E28; n6++) {
                    vec_sub_ba(&v, st + 0x160, self + 0x10);
                    func_003886E8(&v, &v, 1.0f / (f32)D_L28_001DDE18_00399E28);
                    vec_add_ba(&a, self + 0x10, &v);
                    func_L01_00459F10(self, &a);
                    S32(st, 0x12C) = D_L28_001DE840_00399E28 - 1;
                }
                F32(st, 0xA4) = save;
                {
                    u8 *h = D_001A4BE0;
                    func_L01_00443790(self, 0, S32(st, 0x170) == S32(h, 0x25C0) ? 1 : 0x10001, 0, 1, 0, 1.1f,
                                      3.0f, 1.5f);
                }
            }
            if (self[0x60] & 2) {
                if (D_001A73E8[0] == self) {
                    func_L01_00441FB8(self, 7, -1);
                } else {
                    func_L01_00441FB8(self, 6, -1);
                }
            }
        }
        if (S16(st, 0x174) != 1) {
            func_L01_00441FB8(self, 4, -1);
        }
        break;
    case 7:
        if (func_L01_00452EC8(self) != 0 && self[0x43] != 3) {
            func_003BE4F0(self, 3, 7, 6);
        }
        func_L01_00459F10(self, self + 0x10);
        if (self[0x60] & 2) {
            func_L01_00441FB8(self, self[0x94], -1);
        }
        break;
    case 8:
        if (func_L01_00452EC8(self) != 0) {
            if (self[0x43] != 3) {
                func_003BE4F0(self, 3, 6, 3);
            }
            func_L01_00458A70(self, D_L28_001DDE24_00399E28 * 0.00027777778f, D_L28_001DDE20_00399E28 * 0.016666668f, 0.0069813174f,
                              0.20943953f);
            S32(st, 0xA8) |= 0x10;
            F32(self, 0x48) = D_L28_001DDE1C_00399E28;
            v = *(V4_0039BA28 *)(self + 0xE0);
            for (n8 = 0; n8 < D_L28_001DDE40_00399E28; n8++) {
                f32 ang, r, z, s, g;
                s32 c1, c2;
                ang = func_0037E2A8();
                r = func_0037E250(D_L28_001DDE50_00399E28, D_L28_001DDE54_00399E28);
                z = func_0037E250(D_L28_001DDE58_00399E28, D_L28_001DDE5C_00399E28);
                qzero(&b);
                b.x += func_00388960(ang) * (r * 0.016666668f);
                b.y += func_00388978(ang) * (r * 0.016666668f);
                func_00388830(&n, &v, z * 0.016666668f);
                vec_add_ba(&b, &b, &n);
                c = b;
                func_00388830(&n, &v, -(D_L28_001DDE60_00399E28 * 0.00027777778f) * (f32)D_L28_001DDE80_00399E28);
                vec_add_ab(&c, &c, &n);
                s = func_0037E250(0.5f, 1.5f);
                b.w = s * D_L28_001DDE64_00399E28;
                c.w = s * D_L28_001DDE68_00399E28;
                func_00388830(&a, &v, D_L28_001DDE44_00399E28);
                vec_add_ba(&a, &a, self + 0x10);
                func_003BF6A8(&a, D_L28_001DDE48_00399E28);
                func_003BF6A8(&c, D_L28_001DDE4C_00399E28 * 0.016666668f);
                c1 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DDE6C_00399E28, D_L28_001DDE74_00399E28);
                c2 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DDE70_00399E28, D_L28_001DDE78_00399E28);
                g = func_0037E250((f32)D_L28_001DDE84_00399E28, (f32)D_L28_001DDE88_00399E28);
                func_L01_0045FEC8(&a, &b, &c, c1, c2, D_L28_001DDE7C_00399E28, D_L28_001DDE80_00399E28,
                                  (s32)g, -1);
            }
        }
        func_00388830(&a, self + 0xC0, -3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_00459F10(self, &v);
        func_00388830(&b, self + 0xE0, D_L28_001DDE2C_00399E28);
        vec_add_ab(&b, &b, self + 0x10);
        if (func_L01_003F9498(&b, 0, self, D_L28_001DDE28_00399E28) != 0) {
            S32(st, 0xA8) &= ~0x10;
            func_L01_00443648(self, &b, 0x10000, 0, 1, 0, D_L28_001DDE28_00399E28, 5.0f, 1.0f);
            func_L01_00441FB8(self, 9, -1);
        }
        if ((self[0x60] & 2) || func_0037E1D8((s32)(60.0f / D_L28_001DDE1C_00399E28)) == 0) {
            S32(st, 0xA8) &= ~0x10;
            func_L01_00441FB8(self, 9, -1);
        }
        break;
    case 9:
        func_L08_0039F170(self);
        v = *(V4_0039BA28 *)(self + 0xE0);
        for (i = 0; i < D_L28_001DDED8; i++) {
            func_00388830(&a, &v, func_0037E250(D_L28_001DDEE8, D_L28_001DDEEC) * 0.016666668f);
            func_003BF6A8(&a, D_L28_001DDEFC * 0.016666668f);
            func_00388830(&b, &v, D_L28_001DDEDC);
            vec_add_ab(&b, &b, self + 0x10);
            func_003BF6A8(&b, D_L28_001DDEF8);
            f9 = func_0037E250(D_L28_001DDEF0, D_L28_001DDEF4) * 210000.0f;
            func_L01_00470258(&b, &a, D_L28_001DDEE0, D_L28_001DDEE4, func_0037E208(0x78, 0xF0), 0, f9);
        }
        for (j = 0; j < D_L28_001DDE8C_00399E28; j++) {
            f32 ang, r, z;
            a = *(V4_0039BA28 *)(self + 0x10);
            func_003BF6A8(&a, D_L28_001DDE94_00399E28);
            ang = func_0037E2A8();
            r = func_0037E250(D_L28_001DDEA0_00399E28, D_L28_001DDEA4_00399E28);
            z = func_0037E250(D_L28_001DDEA8_00399E28, D_L28_001DDEAC_00399E28);
            qzero(&b);
            b.x += func_00388960(ang) * (r * 0.016666668f);
            b.y += func_00388978(ang) * (r * 0.016666668f);
            b.z += z * 0.016666668f;
            c = b;
            c.z -= D_L28_001DDEB0_00399E28 * 0.00027777778f * (f32)D_L28_001DDED0;
            for (k = 0; k < D_L28_001DDE90_00399E28; k++) {
                f32 s, g;
                s32 c1, c2;
                s = func_0037E250(0.5f, 1.5f);
                b.w = s * D_L28_001DDEB4_00399E28;
                c.w = s * D_L28_001DDEB8_00399E28;
                func_003BF6A8(&a, D_L28_001DDE98_00399E28);
                func_003BF6A8(&c, D_L28_001DDE9C_00399E28 * 0.016666668f);
                c1 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DDEBC_00399E28, D_L28_001DDEC4);
                c2 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DDEC0, D_L28_001DDEC8);
                g = (f32)D_L28_001DDED4;
                g = func_0037E250(g * 0.5f, g * 2.5f);
                func_L01_0045FEC8(&a, &b, &c, c1, c2, D_L28_001DDECC, D_L28_001DDED0,
                                  (s32)g, -1);
            }
        }
        func_003BD360(self);
        return;
    }
    func_L28_0039B520(self);
}
/* localdecomp:end func_L28_00399E28 */
