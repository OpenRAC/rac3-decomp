#include "common.h"

/* NTSC-U counterpart of func_L28_0039D530 (src/levels/28_aquatos_sewers/L28_0039D530.c) */
#include "vu0.h"
typedef int q_0039D530 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039D530;

/* localdecomp:start func_L28_0039B7D0 */
extern f32 D_L28_001DDF40_0039B7D0;
__asm__(".extern D_L28_001DDF40_0039B7D0, 4");
extern f32 D_L28_001DDF44_0039B7D0;
__asm__(".extern D_L28_001DDF44_0039B7D0, 4");
extern f32 D_L28_001DDF48_0039B7D0;
__asm__(".extern D_L28_001DDF48_0039B7D0, 4");
extern f32 D_L28_001DDF4C_0039B7D0;
__asm__(".extern D_L28_001DDF4C_0039B7D0, 4");
extern f32 D_L28_001DDF50_0039B7D0;
__asm__(".extern D_L28_001DDF50_0039B7D0, 4");
extern f32 D_L28_001DDF54_0039B7D0;
__asm__(".extern D_L28_001DDF54_0039B7D0, 4");
extern s32 D_L28_001DDF58_0039B7D0;
__asm__(".extern D_L28_001DDF58_0039B7D0, 4");
extern f32 D_L28_001DDF5C_0039B7D0;
__asm__(".extern D_L28_001DDF5C_0039B7D0, 4");
extern f32 D_L28_001DDF60_0039B7D0;
__asm__(".extern D_L28_001DDF60_0039B7D0, 4");
extern f32 D_L28_001DDF64_0039B7D0;
__asm__(".extern D_L28_001DDF64_0039B7D0, 4");
extern f32 D_L28_001DDF68_0039B7D0;
__asm__(".extern D_L28_001DDF68_0039B7D0, 4");
extern f32 D_L28_001DDF6C_0039B7D0;
__asm__(".extern D_L28_001DDF6C_0039B7D0, 4");
extern s32 D_L28_001DDF74_0039B7D0;
__asm__(".extern D_L28_001DDF74_0039B7D0, 4");
extern s32 D_L28_001DDF78_0039B7D0;
__asm__(".extern D_L28_001DDF78_0039B7D0, 4");
extern s32 D_L28_001DDF7C_0039B7D0;
__asm__(".extern D_L28_001DDF7C_0039B7D0, 4");
extern s32 D_L28_001DDF80_0039B7D0;
__asm__(".extern D_L28_001DDF80_0039B7D0, 4");
extern f32 D_L28_001DDF84_0039B7D0;
__asm__(".extern D_L28_001DDF84_0039B7D0, 4");
extern f32 D_L28_001DDF88_0039B7D0;
__asm__(".extern D_L28_001DDF88_0039B7D0, 4");
extern f32 D_L28_001DDF8C_0039B7D0;
__asm__(".extern D_L28_001DDF8C_0039B7D0, 4");
extern f32 D_L28_001DDF90_0039B7D0;
__asm__(".extern D_L28_001DDF90_0039B7D0, 4");
extern f32 D_L28_001DDF94_0039B7D0;
__asm__(".extern D_L28_001DDF94_0039B7D0, 4");
extern f32 D_L28_001DDF98_0039B7D0;
__asm__(".extern D_L28_001DDF98_0039B7D0, 4");
extern f32 D_L28_001DDF9C_0039B7D0;
__asm__(".extern D_L28_001DDF9C_0039B7D0, 4");
extern f32 D_L28_001DDFA0_0039B7D0;
__asm__(".extern D_L28_001DDFA0_0039B7D0, 4");
extern f32 D_L28_001DDFA4_0039B7D0;
__asm__(".extern D_L28_001DDFA4_0039B7D0, 4");
extern f32 D_L28_001DDFA8_0039B7D0;
__asm__(".extern D_L28_001DDFA8_0039B7D0, 4");
extern s32 D_L28_001DDFAC_0039B7D0;
__asm__(".extern D_L28_001DDFAC_0039B7D0, 4");
extern s32 D_L28_001DDFB0_0039B7D0;
__asm__(".extern D_L28_001DDFB0_0039B7D0, 4");
extern s32 D_L28_001DDFB4_0039B7D0;
__asm__(".extern D_L28_001DDFB4_0039B7D0, 4");
extern s32 D_L28_001DDFB8_0039B7D0;
__asm__(".extern D_L28_001DDFB8_0039B7D0, 4");
extern s32 D_L28_001DDFBC_0039B7D0;
__asm__(".extern D_L28_001DDFBC_0039B7D0, 4");
extern s32 D_L28_001DDFC0_0039B7D0;
__asm__(".extern D_L28_001DDFC0_0039B7D0, 4");
extern s32 D_L28_001DDFC4_0039B7D0;
__asm__(".extern D_L28_001DDFC4_0039B7D0, 4");
extern s32 D_L28_001DDFC8_0039B7D0;
__asm__(".extern D_L28_001DDFC8_0039B7D0, 4");
extern s32 D_L28_001DDFCC_0039B7D0;
__asm__(".extern D_L28_001DDFCC_0039B7D0, 4");
extern s32 D_L28_001DDFD0_0039B7D0;
__asm__(".extern D_L28_001DDFD0_0039B7D0, 4");
extern f32 D_L28_001DDFD4_0039B7D0;
__asm__(".extern D_L28_001DDFD4_0039B7D0, 4");
extern f32 D_L28_001DDFD8_0039B7D0;
__asm__(".extern D_L28_001DDFD8_0039B7D0, 4");
extern f32 D_L28_001DDFDC_0039B7D0;
__asm__(".extern D_L28_001DDFDC_0039B7D0, 4");
extern f32 D_L28_001DDFE0_0039B7D0;
__asm__(".extern D_L28_001DDFE0_0039B7D0, 4");
extern f32 D_L28_001DDFE4_0039B7D0;
__asm__(".extern D_L28_001DDFE4_0039B7D0, 4");
extern f32 D_L28_001DDFE8_0039B7D0;
__asm__(".extern D_L28_001DDFE8_0039B7D0, 4");
extern f32 D_L28_001DDFEC_0039B7D0;
__asm__(".extern D_L28_001DDFEC_0039B7D0, 4");
extern f32 D_L28_001DDFF0_0039B7D0;
__asm__(".extern D_L28_001DDFF0_0039B7D0, 4");
extern f32 D_L28_001DDFF4_0039B7D0;
__asm__(".extern D_L28_001DDFF4_0039B7D0, 4");
extern f32 D_L28_001DDFF8_0039B7D0;
__asm__(".extern D_L28_001DDFF8_0039B7D0, 4");
extern s32 D_L28_001DDFFC_0039B7D0;
__asm__(".extern D_L28_001DDFFC_0039B7D0, 4");
extern s32 D_L28_001DE000;
__asm__(".extern D_L28_001DE000, 4");
extern s32 D_L28_001DE004;
__asm__(".extern D_L28_001DE004, 4");
extern s32 D_L28_001DE008;
__asm__(".extern D_L28_001DE008, 4");
extern s32 D_L28_001DE00C;
__asm__(".extern D_L28_001DE00C, 4");
extern s32 D_L28_001DE010;
__asm__(".extern D_L28_001DE010, 4");
extern s32 D_L28_001DE014;
__asm__(".extern D_L28_001DE014, 4");
extern s32 D_L28_001DE018;
__asm__(".extern D_L28_001DE018, 4");
extern f32 D_L28_001DE01C;
__asm__(".extern D_L28_001DE01C, 4");
extern s32 D_L28_001DE020;
__asm__(".extern D_L28_001DE020, 4");
extern s32 D_L28_001DE024;
__asm__(".extern D_L28_001DE024, 4");
extern f32 D_L28_001DE028;
__asm__(".extern D_L28_001DE028, 4");
extern f32 D_L28_001DE02C;
__asm__(".extern D_L28_001DE02C, 4");
extern f32 D_L28_001DE030;
__asm__(".extern D_L28_001DE030, 4");
extern f32 D_L28_001DE034;
__asm__(".extern D_L28_001DE034, 4");
extern f32 D_L28_001DE038;
__asm__(".extern D_L28_001DE038, 4");
extern f32 D_L28_001DE03C;
__asm__(".extern D_L28_001DE03C, 4");


extern u8 *D_L28_001DEC9C_0039B7D0;
__asm__(".extern D_L28_001DEC9C_0039B7D0, 16");
extern s32 D_L28_001DE840_0039B7D0;
extern s32 D_L28_001E8298_0039B7D0[];
extern u8 *D_001A73E8[];
extern u8 D_001A4BE0[];

extern s32 func_L28_0039C960(u8 *);
extern void func_L28_0039CEF8(u8 *);
extern void func_L28_0039D150(u8 *);
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

static inline f32 fmin_0039D530(f32 a, f32 b) {
    if (a < b) return a;
    return b;
}
static inline f32 fmin2_0039D530(f32 a, f32 b) {
    return a < b ? a : b;
}
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

void func_L28_0039B7D0(u8 *self) {
    V4_0039D530 v;
    V4_0039D530 a;
    V4_0039D530 b;
    V4_0039D530 c;
    V4_0039D530 n;
    u8 *st = *(u8 **)(self + 0x68);
    u8 *m;
    s32 idx;
    s32 i, j, k, n6, n8;
    f32 f, g, f6, f9, save;

    if (func_L28_0039C960(self) != 0) {
        func_L28_0039CEF8(self);
        func_003BD360(self);
        return;
    }

    switch (self[0x20]) {
    case 1:
        if (S32(st, 0x1CC) == 2) {
            func_L01_00441FB8(self, 2, -1);
            break;
        }
        idx = S32(st, 0x1C0);
        if (idx != -1) {
            m = D_L28_001DEC9C_0039B7D0 + (idx << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_0037E1D8(0x3C) == 0) {
                    func_L01_00441FB8(self, 2, -1);
                    break;
                }
            }
        } else if (S32(st, 0x1C8) != idx) {
            m = D_L28_001DEC9C_0039B7D0 + (S32(st, 0x1C8) << 8);
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
                *(q_0039D530 *)(self + 0xC0) = *(q_0039D530 *)&v;
            }
            func_00388758(self + 0xD0, self + 0xE0, self + 0xC0);
            func_00388830(self + 0xD0, self + 0xD0, 1.0f);
            func_00388758(self + 0xC0, self + 0xD0, self + 0xE0);
            func_00388830(self + 0xC0, self + 0xC0, 1.0f);
            F32(st, 0x1D8) = F32(self, 0x2C);
            func_0039FE80(6, 0, self);
        }
        func_L01_00459F10(self, self + 0x10);
        F32(self, 0x2C) = fmin2_0039D530(F32(st, 0x1D8) * (f32)U16(self, 0x96) / 30.0f, F32(st, 0x1D8));
        if (self[0x60] & 2) {
            func_L01_00441FB8(self, 3, -1);
            if (self[0x43] != 1) {
                func_003BE4F0(self, 1, 0, 10);
            }
            F32(self, 0x2C) = F32(st, 0x1D8);
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
        if (S32(st, 0x1D0) != 0 && (func_0037E1D8(0x1E) == 0 || U16(self, 0x96) > 0x1E)) {
            func_L01_00441FB8(self, 5, -1);
            S32(st, 0x1D0) = 0;
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
            qzero(st + 0x1B0);
            F32(st, 0x1B0) = func_00388960(ang4) * r4;
            F32(st, 0x1B4) = func_00388978(ang4) * r4;
            vec_add_ab(st + 0x1B0, st + 0x1B0, st + 0x1A0);
            func_L01_00458A70(self, D_L28_001DDF44_0039B7D0 * 0.5f * 0.00027777778f, D_L28_001DDF40_0039B7D0 * 0.5f * 0.016666668f,
                              0.0069813174f, 0.20943953f);
        }
        func_00388830(&a, self + 0xC0, 3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_00459F10(self, &v);
        f = func_00388A28(F32(st, 0x1B0) - F32(self, 0x10), F32(st, 0x1B4) - F32(self, 0x14));
        if (func_00389468(F32(self, 0xF8), f) > 0.17453292f) {
            func_00389158(self + 0xC0, self + 0xC0, self + 0xE0, 0.07563094f);
            func_00389158(self + 0xD0, self + 0xD0, self + 0xE0, 0.07563094f);
            F32(self, 0xF8) = func_00388A28(F32(self, 0xC0), F32(self, 0xC4));
        }
        if (func_00388800(self + 0x10, st + 0x1B0) < 0.75f) {
            func_L01_00441FB8(self, 4, -1);
        }
        if (S16(st, 0x174) == 1 || D_L28_001DDF74_0039B7D0 < U16(self, 0x96)) {
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
        if (D_L28_001DDF78_0039B7D0 < U16(self, 0x96) && func_0037E1D8(0x64) == 0) {
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(self) != 0) {
            if (self[0x43] != 0) {
                func_003BE4F0(self, 0, 0, 10);
            }
            self[0xBC] = 0;
            func_L01_00458A70(self, D_L28_001DDF44_0039B7D0 * 0.00027777778f, D_L28_001DDF40_0039B7D0 * 0.016666668f, 0.0069813174f,
                              0.20943953f);
        }
        if (self[0xBC] == 0) {
            func_L01_00459F10(self, st + 0x160);
            F32(self, 0xF8) = func_00388A28(F32(self, 0xC0), F32(self, 0xC4));
            if (func_0037E1D8(D_L28_001DDF7C_0039B7D0) == 0) {
                func_L01_00441FB8(self, 7, -1);
            }
            vec_sub_ba(&v, st + 0x160, self + 0x10);
            func_00388830(&v, &v, 1.0f);
            f6 = func_00388730(&v, self + 0xC0);
            if (func_00388800(self + 0x10, st + 0x160) < D_L28_001DDF48_0039B7D0 && D_L28_001DDF4C_0039B7D0 < f6) {
                self[0xBC] = 1;
                if (self[0x43] != 4) {
                    func_003BE4F0(self, 4, 0, 10);
                }
                func_L01_00458A70(self, D_L28_001DDF54_0039B7D0 * 0.00027777778f, D_L28_001DDF50_0039B7D0 * 0.016666668f,
                                  0.0069813174f, 0.20943953f);
            }
        } else if (self[0xBC] == 1) {
            if (func_L01_00436500(self) > 11.0f && func_L01_00436500(self) < 18.0f && self[0x42] == 4 &&
                func_00388800(self + 0x10, st + 0x160) > 1.75f) {
                save = F32(st, 0xA4);
                S32(st, 0xA4) = 0;
                for (n6 = 0; n6 < D_L28_001DDF58_0039B7D0; n6++) {
                    vec_sub_ba(&v, st + 0x160, self + 0x10);
                    func_003886E8(&v, &v, 1.0f / (f32)D_L28_001DDF58_0039B7D0);
                    vec_add_ab(&a, self + 0x10, &v);
                    func_L01_00459F10(self, &a);
                    S32(st, 0x12C) = D_L28_001DE840_0039B7D0 - 1;
                }
                F32(st, 0xA4) = save;
                {
                    u8 *h = D_001A4BE0;
                    func_L01_00443790(self, 0, S32(st, 0x170) == S32(h, 0x25C0) ? 1 : 0x10001, 0, 1, 0, 1.1f,
                                      7.0f, 1.5f);
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
            func_003BE4F0(self, 3, 0, 6);
        }
        func_L01_00459F10(self, self + 0x10);
        if (self[0x60] & 2) {
            func_L01_00441FB8(self, self[0x94], -1);
        }
        break;
    case 8:
        if (func_L01_00452EC8(self) != 0) {
            if (self[0x43] != 3) {
                func_003BE4F0(self, 3, 0, 3);
            }
            func_L01_00458A70(self, D_L28_001DDF64_0039B7D0 * 0.00027777778f, D_L28_001DDF60_0039B7D0 * 0.016666668f, 0.0069813174f,
                              0.20943953f);
            S32(st, 0xA8) |= 0x10;
            F32(self, 0x48) = D_L28_001DDF5C_0039B7D0;
            v = *(V4_0039D530 *)(self + 0xE0);
            for (n8 = 0; n8 < D_L28_001DDF80_0039B7D0; n8++) {
                f32 ang, r, z, s, g;
                s32 c1, c2;
                ang = func_0037E2A8();
                r = func_0037E250(D_L28_001DDF90_0039B7D0, D_L28_001DDF94_0039B7D0);
                z = func_0037E250(D_L28_001DDF98_0039B7D0, D_L28_001DDF9C_0039B7D0);
                qzero(&b);
                b.x += func_00388960(ang) * (r * 0.016666668f);
                b.y += func_00388978(ang) * (r * 0.016666668f);
                func_00388830(&n, &v, z * 0.016666668f);
                vec_add_ba(&b, &b, &n);
                c = b;
                func_00388830(&n, &v, -(D_L28_001DDFA0_0039B7D0 * 0.00027777778f) * (f32)D_L28_001DDFC0_0039B7D0);
                vec_add_ab(&c, &c, &n);
                s = func_0037E250(0.5f, 1.5f);
                b.w = s * D_L28_001DDFA4_0039B7D0;
                c.w = s * D_L28_001DDFA8_0039B7D0;
                func_00388830(&a, &v, D_L28_001DDF84_0039B7D0);
                vec_add_ba(&a, &a, self + 0x10);
                func_003BF6A8(&a, D_L28_001DDF88_0039B7D0);
                func_003BF6A8(&c, D_L28_001DDF8C_0039B7D0 * 0.016666668f);
                c1 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DDFAC_0039B7D0, D_L28_001DDFB4_0039B7D0);
                c2 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DDFB0_0039B7D0, D_L28_001DDFB8_0039B7D0);
                g = func_0037E250((f32)D_L28_001DDFC4_0039B7D0, (f32)D_L28_001DDFC8_0039B7D0);
                func_L01_0045FEC8(&a, &b, &c, c1, c2, D_L28_001DDFBC_0039B7D0, D_L28_001DDFC0_0039B7D0,
                                  (s32)g, -1);
            }
        }
        func_00388830(&a, self + 0xC0, -3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_00459F10(self, &v);
        func_00388830(&b, self + 0xE0, D_L28_001DDF6C_0039B7D0);
        vec_add_ab(&b, &b, self + 0x10);
        if (func_L01_003F9498(&b, 0, self, D_L28_001DDF68_0039B7D0) != 0) {
            S32(st, 0xA8) &= ~0x10;
            func_L01_00443648(self, &b, 0x10000, 0, 1, 0, D_L28_001DDF68_0039B7D0, 5.0f, 1.0f);
            if (F32(st, 0x30) < 0.0f) {
                func_L01_00441FB8(self, 9, -1);
            } else if (D_L28_001E8298_0039B7D0[0] == 0) {
                func_L01_00441FB8(self, 6, -1);
            }
        }
        if ((self[0x60] & 2) ||
            (U16(self, 0x96) > 3 && func_0037E1D8((s32)(60.0f / D_L28_001DDF5C_0039B7D0)) == 0)) {
            S32(st, 0xA8) &= ~0x10;
            if (F32(st, 0x30) < 0.0f) {
                func_L01_00441FB8(self, 9, -1);
            } else {
                func_L01_00441FB8(self, 6, -1);
            }
        }
        break;
    case 9:
        func_L28_0039CEF8(self);
        v = *(V4_0039D530 *)(self + 0xE0);
        for (i = 0; i < D_L28_001DE018; i++) {
            func_00388830(&a, &v, func_0037E250(D_L28_001DE028, D_L28_001DE02C) * 0.016666668f);
            func_003BF6A8(&a, D_L28_001DE03C * 0.016666668f);
            func_00388830(&b, &v, D_L28_001DE01C);
            vec_add_ab(&b, &b, self + 0x10);
            func_003BF6A8(&b, D_L28_001DE038);
            f9 = func_0037E250(D_L28_001DE030, D_L28_001DE034) * 210000.0f;
            func_L01_00470258(&b, &a, D_L28_001DE020, D_L28_001DE024, func_0037E208(0x78, 0xF0), 0, f9);
        }
        for (j = 0; j < D_L28_001DDFCC_0039B7D0; j++) {
            f32 ang, r, z;
            a = *(V4_0039D530 *)(self + 0x10);
            func_003BF6A8(&a, D_L28_001DDFD4_0039B7D0);
            ang = func_0037E2A8();
            r = func_0037E250(D_L28_001DDFE0_0039B7D0, D_L28_001DDFE4_0039B7D0);
            z = func_0037E250(D_L28_001DDFE8_0039B7D0, D_L28_001DDFEC_0039B7D0);
            qzero(&b);
            b.x += func_00388960(ang) * (r * 0.016666668f);
            b.y += func_00388978(ang) * (r * 0.016666668f);
            b.z += z * 0.016666668f;
            c = b;
            c.z -= D_L28_001DDFF0_0039B7D0 * 0.00027777778f * (f32)D_L28_001DE010;
            for (k = 0; k < D_L28_001DDFD0_0039B7D0; k++) {
                f32 s, g;
                s32 c1, c2;
                s = func_0037E250(0.5f, 1.5f);
                b.w = s * D_L28_001DDFF4_0039B7D0;
                c.w = s * D_L28_001DDFF8_0039B7D0;
                func_003BF6A8(&a, D_L28_001DDFD8_0039B7D0);
                func_003BF6A8(&c, D_L28_001DDFDC_0039B7D0 * 0.016666668f);
                c1 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DDFFC_0039B7D0, D_L28_001DE004);
                c2 = func_003894A0(func_0037E250(0.0f, 1.0f), D_L28_001DE000, D_L28_001DE008);
                g = (f32)D_L28_001DE014;
                g = func_0037E250(g * 0.5f, g * 2.5f);
                func_L01_0045FEC8(&a, &b, &c, c1, c2, D_L28_001DE00C, D_L28_001DE010,
                                  (s32)g, -1);
            }
        }
        func_003BD360(self);
        return;
    }
    func_L28_0039D150(self);
}
/* localdecomp:end func_L28_0039B7D0 */
