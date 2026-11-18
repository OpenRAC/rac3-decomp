#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003D7210 */
typedef int U128_003D7210 __attribute__((mode(TI)));
typedef union { U128_003D7210 q; f32 f[4]; } Vec4_003D7210;
typedef struct { u8 *a; u8 *b; u8 *c; u8 pad[0x44]; } Row_003D7210;
typedef struct {
    u8 pad0[0x35C];
    u8 *w35C;
    u8 pad360[0x1200 - 0x360];
    Row_003D7210 row[7];
    u8 pad1430[0x25C0 - 0x1430];
    u8 *moby;
} Hero_003D7210;
typedef struct { u8 pad0[0x5A4]; u32 w5A4; } Stat_003D7210;
typedef struct { u8 pad0[0x1F]; u8 b1F; } Cfg_003D7210;
typedef struct { u8 pad0[0x1A4]; s32 w1A4; } Pad_003D7210;

extern Hero_003D7210 D_001A4BE0;
extern Stat_003D7210 D_001A7E18;
extern Cfg_003D7210 D_00142CA0;
extern s32 D_001D4C38;
extern Pad_003D7210 *D_001D52FC;
extern u16 D_001A8CC4[];
typedef struct { u8 pad0[0x18]; u8 *w18; } G_003D7210;
extern G_003D7210 D_L19_001E8E40;
extern u8 *D_L19_001DD8DC;
extern s32 D_L19_001DD8E8;
extern s32 D_L19_001DD8EC;
extern s32 D_L19_001E1B08;
extern s32 D_L19_001E1250;
extern s32 D_L19_001DD8E0;
extern u8 D_L19_0021EED8[];
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];

extern s32 func_0038CAD0(void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_0045A530(s32);
extern void func_L19_0035D238(s32);
extern void func_L19_0035D2B8(void *, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L19_003DF530(s32);
extern void func_L01_0044CD60(s32);
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_0038DC20(void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L19_003D7AE8(void *);
extern void func_L01_004DB8A8(void *);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);

void func_L19_003D7210(u8 *self) {
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
    Vec4_003D7210 tmp;
    Vec4_003D7210 v;
    Vec4_003D7210 pos;
    Vec4_003D7210 dir;
    Vec4_003D7210 pos2;

    p = *(u8 **)(self + 0x68);
    if (self[0x20] == 0) {
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x24) = 0x19;
        self[0x20] = 1;
        D_L19_001E1B08 = 0;
    }
    if (self[0x20] == 1) {
        if (func_0038CAD0(p + 0x24)) {
            self[0x20] = 2;
        }
        *(s32 *)(D_001A4BE0.moby + 0x98) = 0;
        if (func_L01_003FB640(self + 0x10, 0, self, 0.5f)) {
            obj = D_001A4BE0.moby;
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
            if (D_L19_001E8E40.w18 != 0) {
                self[0x20] = 2;
                *(u8 **)(p + 0x18) = D_L19_001E8E40.w18;
                *(U128_003D7210 *)p = *(U128_003D7210 *)(*(u8 **)(p + 0x18) + 0x10);
            }
        }
        obj = D_001A4BE0.moby;
        *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    }
    if (self[0x20] == 2) {
        if (*(u8 **)(p + 0x18) != 0) {
            vec_sub_ab(&tmp, *(u8 **)(p + 0x18) + 0x10, p);
            *(U128_003D7210 *)p = *(U128_003D7210 *)(*(u8 **)(p + 0x18) + 0x10);
            vec_add_ab(self + 0x10, self + 0x10, &tmp);
        }
        if (D_001A4BE0.w35C != 0 && D_001A4BE0.w35C == self) {
            *(s32 *)(p + 0x38) = *(s32 *)(p + 0x38) + 1;
        } else {
            *(s32 *)(p + 0x38) = 0;
        }
        if (*(s32 *)(p + 0x38) != 0) {
            if (D_00142CA0.b1F == 0) {
                s32 cur = (D_001D4C38 * 5 + 2) / 6;
                if ((u32)(cur - D_001A7E18.w5A4) >= 0x385 || D_001A7E18.w5A4 == 0) {
                    func_L01_0041A5B0(0xCCE, 0x78);
                } else if (D_001A7E18.w5A4 < (u32)cur) {
                    D_001A7E18.w5A4 = cur;
                }
            }
            if (D_00142CA0.b1F != 0 && *(s32 *)(p + 0x1C) == 0) {
                if (D_001A8CC4[0] == 0) {
                    func_L01_0041A5B0(0x162C, 0x139);
                }
                func_L01_00452560(0, 0xD, 0x15F4, 1, 0, 0, 0);
                if (D_001D52FC->w1A4 & 0x10) {
                    func_003A52A0(2, 0, self);
                    old = D_L19_001DD8DC;
                    *(s32 *)(p + 0x1C) = 1;
                    D_L19_001E1B08 = 0;
                    if (old != 0) {
                        *(s32 *)(*(u8 **)(old + 0x68) + 0x1C) = 0;
                    }
                    D_L19_001DD8DC = self;
                    *(U128_003D7210 *)&D_L19_001E1250 = *(U128_003D7210 *)(self + 0xF0);
                }
            }
        }
        if (func_0038CAD0(&D_L19_001DD8EC) == 0) {
            if (D_L19_001DD8E8 == 1) {
                func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
                func_L01_0045A530(0xA);
                func_L19_0035D238(-3);
                func_L19_0035D2B8(self, &D_L19_001DD8E0);
                goto after;
            }
        } else {
            if (D_L19_001DD8E8 == 1) {
                func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
                func_L01_0045A530(0xA);
                D_001A4BE0.moby[0x23] = 0;
                hi = (s32)&D_001A4BE0;
                he = hi + 0x230;
                do {
                    if (*(u8 **)(hi + 0x1200)) (*(u8 **)(hi + 0x1200))[0x23] = 0;
                    if (*(u8 **)(hi + 0x1204)) (*(u8 **)(hi + 0x1204))[0x23] = 0;
                    if (*(u8 **)(hi + 0x1208)) (*(u8 **)(hi + 0x1208))[0x23] = 0;
                    hi += 0x50;
                } while (hi < he);
                if (D_L19_001DD8DC) {
                    func_L01_004F50C8(D_L19_001DD8DC + 0x10, &D_L19_001E1250, 0, 1);
                }
                func_L19_003DF530(0);
                D_L19_001DD8E8 = 2;
                D_L19_001DD8EC = 0x25;
                func_003A52A0(2, 0, self);
                goto after;
            }
        }
        if (func_0038CAD0(&D_L19_001DD8EC) == 0) {
            if (D_L19_001DD8E8 == 2) {
                func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
                func_L01_0045A530(0xA);
                func_L19_0035D238(2);
                func_L19_0035D2B8(self, &D_L19_001DD8E0);
                goto after;
            }
        } else {
            if (D_L19_001DD8E8 == 2) {
                func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
                func_L01_0045A530(0xA);
                D_001A4BE0.moby[0x23] = 0x80;
                hp = (u8 *)&D_001A4BE0;
                do {
                    if (*(u8 **)(hp + 0x1200)) (*(u8 **)(hp + 0x1200))[0x23] = 0x80;
                    if (*(u8 **)(hp + 0x1204)) (*(u8 **)(hp + 0x1204))[0x23] = 0x80;
                    if (*(u8 **)(hp + 0x1208)) (*(u8 **)(hp + 0x1208))[0x23] = 0x80;
                    hp += 0x50;
                } while ((s32)hp < (s32)((u8 *)&D_001A4BE0 + 0x230));
                D_L19_001DD8E8 = 0;
            }
        }
after:
        m = *(s32 *)(p + 0x38);
        if (m != 0 && m < 4) {
            if (D_00142CA0.b1F != 0) {
                func_L01_0044CD60(0x1F);
            }
        }
        {
            s32 a1 = *(s32 *)(p + 0x30);
            if (a1 >= 0) {
                if (D_L19_001DD8DC == self) {
                    if (func_00382380(D_001A4C60, a1, 0) == 0) {
                        *(s32 *)(p + 0x1C) = 0;
                        D_L19_001DD8DC = 0;
                    }
                }
            }
        }
        t = *(s32 *)(p + 0x1C) ? 0xA0 : 0x64;
        *(f32 *)(p + 0x20) = func_0038DAB8(*(f32 *)(p + 0x20), (f32)t * 0.0174532924f * 0.0200000014f);
        *(s32 *)(self + 0x78) = func_0038DBD8(0x5F4F4F4F, -1, func_0038D0B0(*(f32 *)(p + 0x20)) * 0.5f + 0.5f);
        v.q = *(U128_003D7210 *)(self + 0x10);
        v.f[3] = 1.0f;
        if (func_0038DC20(&v, 96.0f) > 0) {
            eed = D_L19_0021EED8;
            for (n = 0; n < 2; n++) {
                pos.q = *(U128_003D7210 *)(self + 0x10);
                rnd = (s32)func_L01_00443A18(2.0f, 5.0f);
                pos.f[0] += func_003824E0(-0.6f, 0.6f);
                pos.f[1] += func_003824E0(-0.6f, 0.6f);
                pos2.q = pos.q;
                pos2.f[2] += 1.0f;
                vec_sub_ab(&dir, &pos2, &pos);
                func_0038CF68(&dir, &dir, func_003824E0(2.0f, 3.0f) * 0.0200000014f);
                func_L01_004713C8(&pos, &dir, (func_00382498(10, 20) * 5 + 2) / 6, 0x204060, rnd, 0x7F, 0x7F, 54599.996f, 6300.0f, -0.0012f, 1);
                rnd = -(rnd << 1);
                q = func_L01_004713C8(&pos, &dir, (func_00382498(10, 20) * 5 + 2) / 6, 0x505070, rnd, 0x30, 0x30, 218399.984375f, 6300.0f, -0.0012f, 0);
                if (q) {
                    q[2] = **(u8 **)(eed + 0xD4);
                }
            }
            func_L01_00404A10(func_L19_003D7AE8, self);
            if (*(s32 *)(p + 0x1C)) {
                D_L19_001E1B08 = D_L19_001E1B08 + 1;
                if (D_L19_001E1B08 >= 0x15) D_L19_001E1B08 = 0x14;
                func_L01_004DB8A8(self);
            }
        }
        if (*(s32 *)(p + 0x1C)) {
            if (func_L01_004AA710(self, *(s32 *)(p + 0x34)) == 0) {
                *(s32 *)(p + 0x34) = func_003A52A0(3, 4, self);
            }
            return;
        }
    }
    now = *(s32 *)(p + 0x34);
    if (now != -1) {
        u8 *rec = D_001A30B0 + (now << 7);
        if (*(u8 **)(rec + 0xDC) == self && rec[0xD0] != 0) {
            func_003A4F28(now);
        }
    }
    *(s32 *)(p + 0x34) = -1;
}
/* localdecomp:end func_L19_003D7210 */
