/* NTSC-U draft (2026-11-14, Claude worker): C of func_L19_003D4E40, the NTSC-U twin of func_L19_003D7210, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/19_thran_asteroid_belt/L19_003D7210.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003D4E40 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) beyond the PAL file's flags. */
typedef int U128_003D4E40 __attribute__((mode(TI)));
typedef union { U128_003D4E40 q; f32 f[4]; } Vec4_003D4E40;
typedef struct { u8 *a; u8 *b; u8 *c; u8 pad[0x44]; } Row_003D4E40;
typedef struct {
    u8 pad0[0x35C];
    u8 *w35C;
    u8 pad360[0x1200 - 0x360];
    Row_003D4E40 row[7];
    u8 pad1430[0x25C0 - 0x1430];
    u8 *moby;
} Hero_003D4E40;
typedef struct { u8 pad0[0x5A4]; u32 w5A4; } Stat_003D4E40;
typedef struct { u8 pad0[0x1F]; u8 b1F; } Cfg_003D4E40;
typedef struct { u8 pad0[0x1A4]; s32 w1A4; } Pad_003D4E40;

extern Hero_003D4E40 D_001A4BE0;
extern Stat_003D4E40 D_001A7E18;
extern Cfg_003D4E40 D_00142CA0;
extern s32 D_001D4C38;
extern Pad_003D4E40 *D_001D52FC;
extern u16 D_001A8CC4[];
typedef struct { u8 pad0[0x18]; u8 *w18; } G_003D4E40;
extern G_003D4E40 D_L19_001E8E40;
extern u8 *D_L19_001DD91C;
extern s32 D_L19_001DD928;
extern s32 D_L19_001DD92C;
extern s32 D_L19_001E1B08;
extern s32 D_L19_001E1250;
extern s32 D_L19_001DD920;
extern u8 D_L19_0021EED8[];
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];

extern s32 func_00388398(void *);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00457240(s32);
extern void func_L19_0035C1B8(s32);
extern void func_L19_0035C238(void *, void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L19_003DCF48(s32);
extern void func_L01_00449AE8(s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_003894E8(void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_004026A0(void (*)(void *), void *);
extern void func_L19_003D56E0(void *);
extern void func_L01_004D7BB8(void *);
extern s32 func_L01_004A6D20(void *, s32);
extern void func_0039FB08(s32);

void func_L19_003D4E40(u8 *self) {
    u8 *p;
    u8 *q;
    u8 *obj;
    s32 i;
    s32 n;
    s32 m;
    s32 rnd;
    s32 last;
    s32 t;
    s32 now;
    u8 *hp;
    u8 *eed;
    u8 *old;
    s32 hi;
    s32 he;
    Vec4_003D4E40 tmp;
    Vec4_003D4E40 v;
    Vec4_003D4E40 pos;
    Vec4_003D4E40 dir;
    Vec4_003D4E40 pos2;

    p = *(u8 **)(self + 0x68);
    if (self[0x20] == 0) {
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x24) = 0x1E;
        self[0x20] = 1;
        D_L19_001E1B08 = 0;
    }
    if (self[0x20] == 1) {
        if (func_00388398(p + 0x24)) {
            self[0x20] = 2;
        }
        *(s32 *)(D_001A4BE0.moby + 0x98) = 0;
        if (func_L01_003F9498(self + 0x10, 0, self, 0.5f)) {
            obj = D_001A4BE0.moby;
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
            if (D_L19_001E8E40.w18 != 0) {
                self[0x20] = 2;
                *(u8 **)(p + 0x18) = D_L19_001E8E40.w18;
                *(U128_003D4E40 *)p = *(U128_003D4E40 *)(*(u8 **)(p + 0x18) + 0x10);
            }
        }
        obj = D_001A4BE0.moby;
        *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    }
    if (self[0x20] == 2) {
        if (*(u8 **)(p + 0x18) != 0) {
            vec_sub_ab(&tmp, *(u8 **)(p + 0x18) + 0x10, p);
            *(U128_003D4E40 *)p = *(U128_003D4E40 *)(*(u8 **)(p + 0x18) + 0x10);
            vec_add_ab(self + 0x10, self + 0x10, &tmp);
        }
        if (D_001A4BE0.w35C != 0 && D_001A4BE0.w35C == self) {
            *(s32 *)(p + 0x38) = *(s32 *)(p + 0x38) + 1;
        } else {
            *(s32 *)(p + 0x38) = 0;
        }
        if (*(s32 *)(p + 0x38) != 0) {
            if (D_00142CA0.b1F == 0) {
                if ((u32)(D_001D4C38 - D_001A7E18.w5A4) >= 0x439 || D_001A7E18.w5A4 == 0) {
                    func_L01_00417F60(0xCCE, 0x78);
                } else if (D_001A7E18.w5A4 < (u32)D_001D4C38) {
                    D_001A7E18.w5A4 = D_001D4C38;
                }
            }
            if (D_00142CA0.b1F != 0 && *(s32 *)(p + 0x1C) == 0) {
                if (D_001A8CC4[0] == 0) {
                    func_L01_00417F60(0x162C, 0x139);
                }
                func_L01_0044F2E8(0, 0xD, 0x15F4, 1, 0, 0, 0);
                if (D_001D52FC->w1A4 & 0x10) {
                    func_0039FE80(2, 0, self);
                    old = D_L19_001DD91C;
                    *(s32 *)(p + 0x1C) = 1;
                    D_L19_001E1B08 = 0;
                    if (old != 0) {
                        *(s32 *)(*(u8 **)(old + 0x68) + 0x1C) = 0;
                    }
                    D_L19_001DD91C = self;
                    *(U128_003D4E40 *)&D_L19_001E1250 = *(U128_003D4E40 *)(self + 0xF0);
                }
            }
        }
        if (func_00388398(&D_L19_001DD92C) == 0) {
            if (D_L19_001DD928 == 1) {
                func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
                func_L01_00457240(0xA);
                func_L19_0035C1B8(-3);
                func_L19_0035C238(self, &D_L19_001DD920);
                goto after;
            }
        } else {
            if (D_L19_001DD928 == 1) {
                func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
                func_L01_00457240(0xA);
                D_001A4BE0.moby[0x23] = 0;
                hi = (s32)&D_001A4BE0;
                he = hi + 0x230;
                do {
                    if (*(u8 **)(hi + 0x1200)) (*(u8 **)(hi + 0x1200))[0x23] = 0;
                    if (*(u8 **)(hi + 0x1204)) (*(u8 **)(hi + 0x1204))[0x23] = 0;
                    if (*(u8 **)(hi + 0x1208)) (*(u8 **)(hi + 0x1208))[0x23] = 0;
                    hi += 0x50;
                } while (hi < he);
                if (D_L19_001DD91C) {
                    func_L01_004F12C0(D_L19_001DD91C + 0x10, &D_L19_001E1250, 0, 1);
                }
                func_L19_003DCF48(0);
                D_L19_001DD928 = 2;
                D_L19_001DD92C = 0x2D;
                func_0039FE80(2, 0, self);
                goto after;
            }
        }
        if (func_00388398(&D_L19_001DD92C) == 0) {
            if (D_L19_001DD928 == 2) {
                func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
                func_L01_00457240(0xA);
                func_L19_0035C1B8(2);
                func_L19_0035C238(self, &D_L19_001DD920);
                goto after;
            }
        } else {
            if (D_L19_001DD928 == 2) {
                func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
                func_L01_00457240(0xA);
                D_001A4BE0.moby[0x23] = 0x80;
                hp = (u8 *)&D_001A4BE0;
                do {
                    if (*(u8 **)(hp + 0x1200)) (*(u8 **)(hp + 0x1200))[0x23] = 0x80;
                    if (*(u8 **)(hp + 0x1204)) (*(u8 **)(hp + 0x1204))[0x23] = 0x80;
                    if (*(u8 **)(hp + 0x1208)) (*(u8 **)(hp + 0x1208))[0x23] = 0x80;
                    hp += 0x50;
                } while ((s32)hp < (s32)((u8 *)&D_001A4BE0 + 0x230));
                D_L19_001DD928 = 0;
            }
        }
after:
        m = *(s32 *)(p + 0x38);
        if (m != 0 && m < 5) {
            if (D_00142CA0.b1F != 0) {
                func_L01_00449AE8(0x1F);
            }
        }
        {
            s32 a1 = *(s32 *)(p + 0x30);
            if (a1 >= 0) {
                if (D_L19_001DD91C == self) {
                    if (func_0037E0F0(D_001A4C60, a1, 0) == 0) {
                        *(s32 *)(p + 0x1C) = 0;
                        D_L19_001DD91C = 0;
                    }
                }
            }
        }
        t = *(s32 *)(p + 0x1C) ? 0xA0 : 0x64;
        *(f32 *)(p + 0x20) = func_00389380(*(f32 *)(p + 0x20), (f32)t * 0.0174532924f * 0.0166666675f);
        *(s32 *)(self + 0x78) = func_003894A0(0x5F4F4F4F, -1, func_00388978(*(f32 *)(p + 0x20)) * 0.5f + 0.5f);
        v.q = *(U128_003D4E40 *)(self + 0x10);
        v.f[3] = 1.0f;
        if (func_003894E8(&v, 96.0f) > 0) {
            eed = D_L19_0021EED8;
            for (n = 0; n < 2; n++) {
                pos.q = *(U128_003D4E40 *)(self + 0x10);
                rnd = (s32)func_L01_00440918(2.0f, 5.0f);
                pos.f[0] += func_0037E250(-0.6f, 0.6f);
                pos.f[1] += func_0037E250(-0.6f, 0.6f);
                pos2.q = pos.q;
                pos2.f[2] += 1.0f;
                vec_sub_ab(&dir, &pos2, &pos);
                func_00388830(&dir, &dir, func_0037E250(2.0f, 3.0f) * 0.0166666675f);
                func_L01_0046DCB8(&pos, &dir, func_0037E208(10, 20), 0x204060, rnd, 0x7F, 0x7F, 54599.996f, 6300.0f, -0.00083333335f, 1);
                rnd = -(rnd << 1);
                q = func_L01_0046DCB8(&pos, &dir, func_0037E208(10, 20), 0x505070, rnd, 0x30, 0x30, 218399.984375f, 6300.0f, -0.00083333335f, 0);
                if (q) {
                    q[2] = **(u8 **)(eed + 0xD4);
                }
            }
            func_L01_004026A0(func_L19_003D56E0, self);
            if (*(s32 *)(p + 0x1C)) {
                D_L19_001E1B08 = D_L19_001E1B08 + 1;
                if (D_L19_001E1B08 >= 0x15) D_L19_001E1B08 = 0x14;
                func_L01_004D7BB8(self);
            }
        }
        if (*(s32 *)(p + 0x1C)) {
            if (func_L01_004A6D20(self, *(s32 *)(p + 0x34)) == 0) {
                *(s32 *)(p + 0x34) = func_0039FE80(3, 4, self);
            }
            return;
        }
    }
    now = *(s32 *)(p + 0x34);
    if (now != -1) {
        u8 *rec = D_001A30B0 + (now << 7);
        if (*(u8 **)(rec + 0xDC) == self && rec[0xD0] != 0) {
            func_0039FB08(now);
        }
    }
    *(s32 *)(p + 0x34) = -1;
}
/* localdecomp:end func_L19_003D4E40 */
