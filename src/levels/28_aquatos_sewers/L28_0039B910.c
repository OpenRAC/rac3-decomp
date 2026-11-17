#include "common.h"
#include "vu0.h"

typedef int q_0039BA28 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039BA28;

/* localdecomp:start func_L28_0039B910 */
extern u8 D_001426E0[];
extern s16 D_001A4DC0[];
extern s32 D_L28_001DE840;
extern s32 D_001A82AC[];
extern s32 D_001D545C_0039B910;
__asm__(".extern D_001D545C_0039B910, 16");
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
void func_L28_0039B910(u8 *a0) {
    u8 *q = D_001426E0;
    f32 v[4];
    f32 w[4];
    s32 m, t;
    if (q[0x73] == 0) {
        if (a0[0x20] == 0) {
            a0[0x30] = 0xFF;
            v[0] = 474.54998779f;
            v[1] = 445.32998657f;
            v[2] = 972.21997070f;
            w[2] = -3.11999988f;
            func_L01_004F50C8(v, w, 0, 1);
            q[0x73] = 1;
            D_001A4DC0[0] = 200;
            func_L01_004450F0(a0, 1, -1);
        }
    }
    if (a0[0x20] == 1) {
        if (D_L28_001DE840 > 0x3A98) {
            t = D_001A82AC[0];
            m = 1 << D_001D545C_0039B910;
            if ((t & m) == 0) {
                func_L01_0041A5B0(0xC9E, 0x61);
            }
        }
    }
}
/* localdecomp:end func_L28_0039B910 */

/* localdecomp:start func_L28_0039BA28 */
extern f32 D_L28_001DDDC0;
__asm__(".extern D_L28_001DDDC0, 4");
extern f32 D_L28_001DDDC4;
__asm__(".extern D_L28_001DDDC4, 4");
extern f32 D_L28_001DDDC8;
__asm__(".extern D_L28_001DDDC8, 4");
extern f32 D_L28_001DDDCC;
__asm__(".extern D_L28_001DDDCC, 4");
extern f32 D_L28_001DDDD0;
__asm__(".extern D_L28_001DDDD0, 4");
extern f32 D_L28_001DDDD4;
__asm__(".extern D_L28_001DDDD4, 4");
extern s32 D_L28_001DDDD8;
__asm__(".extern D_L28_001DDDD8, 4");
extern f32 D_L28_001DDDDC;
__asm__(".extern D_L28_001DDDDC, 4");
extern f32 D_L28_001DDDE0;
__asm__(".extern D_L28_001DDDE0, 4");
extern f32 D_L28_001DDDE4;
__asm__(".extern D_L28_001DDDE4, 4");
extern f32 D_L28_001DDDE8;
__asm__(".extern D_L28_001DDDE8, 4");
extern f32 D_L28_001DDDEC;
__asm__(".extern D_L28_001DDDEC, 4");
extern s32 D_L28_001DDDF4;
__asm__(".extern D_L28_001DDDF4, 4");
extern s32 D_L28_001DDDF8;
__asm__(".extern D_L28_001DDDF8, 4");
extern s32 D_L28_001DDDFC;
__asm__(".extern D_L28_001DDDFC, 4");
extern s32 D_L28_001DDE00;
__asm__(".extern D_L28_001DDE00, 4");
extern f32 D_L28_001DDE04;
__asm__(".extern D_L28_001DDE04, 4");
extern f32 D_L28_001DDE08;
__asm__(".extern D_L28_001DDE08, 4");
extern f32 D_L28_001DDE0C;
__asm__(".extern D_L28_001DDE0C, 4");
extern f32 D_L28_001DDE10;
__asm__(".extern D_L28_001DDE10, 4");
extern f32 D_L28_001DDE14;
__asm__(".extern D_L28_001DDE14, 4");
extern f32 D_L28_001DDE18;
__asm__(".extern D_L28_001DDE18, 4");
extern f32 D_L28_001DDE1C;
__asm__(".extern D_L28_001DDE1C, 4");
extern f32 D_L28_001DDE20;
__asm__(".extern D_L28_001DDE20, 4");
extern f32 D_L28_001DDE24;
__asm__(".extern D_L28_001DDE24, 4");
extern f32 D_L28_001DDE28;
__asm__(".extern D_L28_001DDE28, 4");
extern s32 D_L28_001DDE2C;
__asm__(".extern D_L28_001DDE2C, 4");
extern s32 D_L28_001DDE30;
__asm__(".extern D_L28_001DDE30, 4");
extern s32 D_L28_001DDE34;
__asm__(".extern D_L28_001DDE34, 4");
extern s32 D_L28_001DDE38;
__asm__(".extern D_L28_001DDE38, 4");
extern s32 D_L28_001DDE3C;
__asm__(".extern D_L28_001DDE3C, 4");
extern s32 D_L28_001DDE40;
__asm__(".extern D_L28_001DDE40, 4");
extern s32 D_L28_001DDE44;
__asm__(".extern D_L28_001DDE44, 4");
extern s32 D_L28_001DDE48;
__asm__(".extern D_L28_001DDE48, 4");
extern s32 D_L28_001DDE4C;
__asm__(".extern D_L28_001DDE4C, 4");
extern s32 D_L28_001DDE50;
__asm__(".extern D_L28_001DDE50, 4");
extern f32 D_L28_001DDE54;
__asm__(".extern D_L28_001DDE54, 4");
extern f32 D_L28_001DDE58;
__asm__(".extern D_L28_001DDE58, 4");
extern f32 D_L28_001DDE5C;
__asm__(".extern D_L28_001DDE5C, 4");
extern f32 D_L28_001DDE60;
__asm__(".extern D_L28_001DDE60, 4");
extern f32 D_L28_001DDE64;
__asm__(".extern D_L28_001DDE64, 4");
extern f32 D_L28_001DDE68;
__asm__(".extern D_L28_001DDE68, 4");
extern f32 D_L28_001DDE6C;
__asm__(".extern D_L28_001DDE6C, 4");
extern f32 D_L28_001DDE70;
__asm__(".extern D_L28_001DDE70, 4");
extern f32 D_L28_001DDE74;
__asm__(".extern D_L28_001DDE74, 4");
extern f32 D_L28_001DDE78;
__asm__(".extern D_L28_001DDE78, 4");
extern s32 D_L28_001DDE7C;
__asm__(".extern D_L28_001DDE7C, 4");
extern s32 D_L28_001DDE80;
__asm__(".extern D_L28_001DDE80, 4");
extern s32 D_L28_001DDE84;
__asm__(".extern D_L28_001DDE84, 4");
extern s32 D_L28_001DDE88;
__asm__(".extern D_L28_001DDE88, 4");
extern s32 D_L28_001DDE8C;
__asm__(".extern D_L28_001DDE8C, 4");
extern s32 D_L28_001DDE90;
__asm__(".extern D_L28_001DDE90, 4");
extern s32 D_L28_001DDE94;
__asm__(".extern D_L28_001DDE94, 4");
extern s32 D_L28_001DDE98;
__asm__(".extern D_L28_001DDE98, 4");
extern f32 D_L28_001DDE9C;
__asm__(".extern D_L28_001DDE9C, 4");
extern s32 D_L28_001DDEA0;
__asm__(".extern D_L28_001DDEA0, 4");
extern s32 D_L28_001DDEA4;
__asm__(".extern D_L28_001DDEA4, 4");
extern f32 D_L28_001DDEA8;
__asm__(".extern D_L28_001DDEA8, 4");
extern f32 D_L28_001DDEAC;
__asm__(".extern D_L28_001DDEAC, 4");
extern f32 D_L28_001DDEB0;
__asm__(".extern D_L28_001DDEB0, 4");
extern f32 D_L28_001DDEB4;
__asm__(".extern D_L28_001DDEB4, 4");
extern f32 D_L28_001DDEB8;
__asm__(".extern D_L28_001DDEB8, 4");
extern f32 D_L28_001DDEBC;
__asm__(".extern D_L28_001DDEBC, 4");


extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_L28_001DE840;
extern s32 D_L28_001E8298[];
extern u8 *D_001A73E8[];
extern u8 D_001A4BE0[];

extern s32 func_L28_0039CCD8(u8 *);
extern void func_L08_003A0D40(void *);
extern void func_L28_0039D280(u8 *);
extern void func_003C2880(void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_0045D218(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004468C8(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_0038DBD8(f32, u32, u32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static inline f32 fmin_0039BA28(f32 a, f32 b) {
    if (a < b) return a;
    return b;
}
static inline f32 fmin2_0039BA28(f32 a, f32 b) {
    return a < b ? a : b;
}
#define FRAMES(x) (((x) * 5 + 2) / 6)
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

void func_L28_0039BA28(u8 *self) {
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

    if (func_L28_0039CCD8(self) != 0) {
        func_L08_003A0D40(self);
        func_003C2880(self);
        return;
    }

    switch (self[0x20]) {
    case 1:
        if (S32(st, 0x1BC) == 2) {
            func_L01_004450F0(self, 2, -1);
            break;
        }
        idx = S32(st, 0x1B0);
        if (idx != -1) {
            m = D_L28_001DEC9C + (idx << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_00382468(0x32) == 0) {
                    func_L01_004450F0(self, 2, -1);
                    break;
                }
            }
        } else if (S32(st, 0x1B8) != idx) {
            m = D_L28_001DEC9C + (S32(st, 0x1B8) << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_00382468(0x32) == 0) {
                    func_L01_004450F0(self, 2, -1);
                    break;
                }
            }
        } else if (S16(st, 0x174) == 1) {
            if (func_00382468(0x32) == 0) {
                func_L01_004450F0(self, 2, -1);
                break;
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            u8 *o = *(u8 **)(self + 0x24);
            U16(self, 0x34) &= ~0x41;
            U16(self, 0x34) |= U16(o, 0x44) & 0x1000;
            S32(self, 0x98) = S32(o, 0x10);
            if (self[0x43] != 2) {
                func_003C3A10(self, 2, 0, 8);
            }
            S16(st, 0x36) = 0x21;
            F32(self, 0xC0) = 1.0f;
            S32(self, 0xC4) = 0;
            S32(self, 0xC8) = 0;
            vec_sub_ba(&v, st + 0x160, self + 0x10);
            func_0038CF68(&v, &v, 1.0f);
            if (abs_asm(func_0038CE68(&v, self + 0xE0) < 0.9f)) {
                *(q_0039BA28 *)(self + 0xC0) = *(q_0039BA28 *)&v;
            }
            func_0038CE90(self + 0xD0, self + 0xE0, self + 0xC0);
            func_0038CF68(self + 0xD0, self + 0xD0, 1.0f);
            func_0038CE90(self + 0xC0, self + 0xD0, self + 0xE0);
            func_0038CF68(self + 0xC0, self + 0xC0, 1.0f);
            F32(st, 0x1C8) = F32(self, 0x2C);
            func_003A52A0(6, 0, self);
        }
        func_L01_0045D218(self, self + 0x10);
        F32(self, 0x2C) = fmin2_0039BA28(F32(st, 0x1C8) * (f32)U16(self, 0x96) / 25.0f, F32(st, 0x1C8));
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 3, -1);
            if (self[0x43] != 1) {
                func_003C3A10(self, 1, 0, 8);
            }
            F32(self, 0x2C) = F32(st, 0x1C8);
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x42] != 1 && self[0x43] != 1) {
                func_003C3A10(self, 1, 0, 8);
            }
        }
        func_L01_0045D218(self, self + 0x10);
        if (S16(st, 0x174) == 1 && (func_00382468(0x32) == 0 || U16(self, 0x96) > 0x32)) {
            func_L01_004450F0(self, 6, -1);
            break;
        }
        if (S32(st, 0x1C0) != 0 && (func_00382468(0x19) == 0 || U16(self, 0x96) > 0x19)) {
            func_L01_004450F0(self, 5, -1);
            S32(st, 0x1C0) = 0;
        }
        break;
    case 4:
        if (func_L01_004561B8(self) != 0) {
            f32 ang4, r4;
            if (self[0x42] != 0 && self[0x43] != 0) {
                func_003C3A10(self, 0, 0, 8);
            }
            ang4 = func_00382538();
            r4 = func_003824E0(4.0f, 8.0f);
            qzero(st + 0x1A0);
            F32(st, 0x1A0) = func_0038D098(ang4) * r4;
            F32(st, 0x1A4) = func_0038D0B0(ang4) * r4;
            vec_add_ab(st + 0x1A0, st + 0x1A0, st + 0x190);
            func_L01_0045BD78(self, D_L28_001DDDC4 * 0.5f * 0.00040000002f, D_L28_001DDDC0 * 0.5f * 0.020000001f,
                              0.010053097f, 0.25132743f);
        }
        func_0038CF68(&a, self + 0xC0, 3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_0045D218(self, &v);
        f = func_0038D160(F32(st, 0x1A0) - F32(self, 0x10), F32(st, 0x1A4) - F32(self, 0x14));
        if (func_0038DBA0(F32(self, 0xF8), f) > 0.17453292f) {
            func_0038D890(self + 0xC0, self + 0xC0, self + 0xE0, 0.09075713f);
            func_0038D890(self + 0xD0, self + 0xD0, self + 0xE0, 0.09075713f);
            F32(self, 0xF8) = func_0038D160(F32(self, 0xC0), F32(self, 0xC4));
        }
        if (func_0038CF38(self + 0x10, st + 0x1A0) < 0.75f) {
            func_L01_004450F0(self, 4, -1);
        }
        if (S16(st, 0x174) == 1 || FRAMES(D_L28_001DDDF4) < U16(self, 0x96)) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x42] != 1 && self[0x43] != 1) {
                func_003C3A10(self, 1, 0, 8);
            }
        }
        func_L01_0045D218(self, self + 0x10);
        if (S16(st, 0x174) == 1) {
            func_L01_004450F0(self, 6, -1);
            break;
        }
        if (FRAMES(D_L28_001DDDF8) < U16(self, 0x96) && func_00382468(0x53) == 0) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x43] != 0) {
                func_003C3A10(self, 0, 0, 8);
            }
            self[0xBC] = 0;
            func_L01_0045BD78(self, D_L28_001DDDC4 * 0.00040000002f, D_L28_001DDDC0 * 0.020000001f, 0.010053097f,
                              0.25132743f);
        }
        if (self[0xBC] == 0) {
            func_L01_0045D218(self, st + 0x160);
            F32(self, 0xF8) = func_0038D160(F32(self, 0xC0), F32(self, 0xC4));
            if (func_00382468(FRAMES(D_L28_001DDDFC)) == 0) {
                func_L01_004450F0(self, 7, -1);
            }
            vec_sub_ba(&v, st + 0x160, self + 0x10);
            func_0038CF68(&v, &v, 1.0f);
            f6 = func_0038CE68(&v, self + 0xC0);
            if (func_0038CF38(self + 0x10, st + 0x160) < D_L28_001DDDC8 && D_L28_001DDDCC < f6) {
                self[0xBC] = 1;
                if (self[0x43] != 4) {
                    func_003C3A10(self, 4, 0, 8);
                }
                func_L01_0045BD78(self, D_L28_001DDDD4 * 0.00040000002f, D_L28_001DDDD0 * 0.020000001f,
                                  0.010053097f, 0.25132743f);
            }
        } else if (self[0xBC] == 1) {
            if (func_L01_004395E0(self) > 11.0f && func_L01_004395E0(self) < 18.0f && self[0x42] == 4 &&
                func_0038CF38(self + 0x10, st + 0x160) > 1.75f) {
                save = F32(st, 0xA4);
                S32(st, 0xA4) = 0;
                for (n6 = 0; n6 < D_L28_001DDDD8; n6++) {
                    vec_sub_ba(&v, st + 0x160, self + 0x10);
                    func_0038CE20(&v, &v, 1.0f / (f32)D_L28_001DDDD8);
                    vec_add_ba(&a, self + 0x10, &v);
                    func_L01_0045D218(self, &a);
                    S32(st, 0x12C) = D_L28_001DE840 - 1;
                }
                F32(st, 0xA4) = save;
                {
                    u8 *h = D_001A4BE0;
                    func_L01_004468C8(self, 0, S32(st, 0x170) == S32(h, 0x25C0) ? 1 : 0x10001, 0, 1, 0, 1.1f,
                                      3.0f, 1.5f);
                }
            }
            if (self[0x60] & 2) {
                if (D_001A73E8[0] == self) {
                    func_L01_004450F0(self, 7, -1);
                } else {
                    func_L01_004450F0(self, 6, -1);
                }
            }
        }
        if (S16(st, 0x174) != 1) {
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(self) != 0 && self[0x43] != 3) {
            func_003C3A10(self, 3, 7, 5);
        }
        func_L01_0045D218(self, self + 0x10);
        if (self[0x60] & 2) {
            func_L01_004450F0(self, self[0x94], -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x43] != 3) {
                func_003C3A10(self, 3, 6, 2);
            }
            func_L01_0045BD78(self, D_L28_001DDDE4 * 0.00040000002f, D_L28_001DDDE0 * 0.020000001f, 0.010053097f,
                              0.25132743f);
            S32(st, 0xA8) |= 0x10;
            F32(self, 0x48) = D_L28_001DDDDC;
            v = *(V4_0039BA28 *)(self + 0xE0);
            for (n8 = 0; n8 < D_L28_001DDE00; n8++) {
                f32 ang, r, z, s, g;
                s32 c1, c2;
                ang = func_00382538();
                r = func_003824E0(D_L28_001DDE10, D_L28_001DDE14);
                z = func_003824E0(D_L28_001DDE18, D_L28_001DDE1C);
                qzero(&b);
                b.x += func_0038D098(ang) * (r * 0.020000001f);
                b.y += func_0038D0B0(ang) * (r * 0.020000001f);
                func_0038CF68(&n, &v, z * 0.020000001f);
                vec_add_ba(&b, &b, &n);
                c = b;
                func_0038CF68(&n, &v, -(D_L28_001DDE20 * 0.00040000002f) * (f32)FRAMES(D_L28_001DDE40));
                vec_add_ab(&c, &c, &n);
                s = func_003824E0(0.5f, 1.5f);
                b.w = s * D_L28_001DDE24;
                c.w = s * D_L28_001DDE28;
                func_0038CF68(&a, &v, D_L28_001DDE04);
                vec_add_ba(&a, &a, self + 0x10);
                func_003C4C18(&a, D_L28_001DDE08);
                func_003C4C18(&c, D_L28_001DDE0C * 0.020000001f);
                c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDE2C, D_L28_001DDE34);
                c2 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDE30, D_L28_001DDE38);
                g = func_003824E0((f32)D_L28_001DDE44, (f32)D_L28_001DDE48);
                func_L01_00463378(&a, &b, &c, c1, c2, FRAMES(D_L28_001DDE3C), FRAMES(D_L28_001DDE40),
                                  (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
            }
        }
        func_0038CF68(&a, self + 0xC0, -3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_0045D218(self, &v);
        func_0038CF68(&b, self + 0xE0, D_L28_001DDDEC);
        vec_add_ab(&b, &b, self + 0x10);
        if (func_L01_003FB640(&b, 0, self, D_L28_001DDDE8) != 0) {
            S32(st, 0xA8) &= ~0x10;
            func_L01_00446780(self, &b, 0x10000, 0, 1, 0, D_L28_001DDDE8, 5.0f, 1.0f);
            func_L01_004450F0(self, 9, -1);
        }
        if ((self[0x60] & 2) || func_00382468((s32)((60.0f / D_L28_001DDDDC * 5.0f + 2.0f) / 6.0f)) == 0) {
            S32(st, 0xA8) &= ~0x10;
            func_L01_004450F0(self, 9, -1);
        }
        break;
    case 9:
        func_L08_003A0D40(self);
        v = *(V4_0039BA28 *)(self + 0xE0);
        for (i = 0; i < D_L28_001DDE98; i++) {
            func_0038CF68(&a, &v, func_003824E0(D_L28_001DDEA8, D_L28_001DDEAC) * 0.020000001f);
            func_003C4C18(&a, D_L28_001DDEBC * 0.020000001f);
            func_0038CF68(&b, &v, D_L28_001DDE9C);
            vec_add_ab(&b, &b, self + 0x10);
            func_003C4C18(&b, D_L28_001DDEB8);
            f9 = func_003824E0(D_L28_001DDEB0, D_L28_001DDEB4) * 210000.0f;
            func_L01_004739D8(&b, &a, D_L28_001DDEA0, D_L28_001DDEA4, FRAMES(func_00382498(0x78, 0xF0)), 0, f9);
        }
        for (j = 0; j < D_L28_001DDE4C; j++) {
            f32 ang, r, z;
            a = *(V4_0039BA28 *)(self + 0x10);
            func_003C4C18(&a, D_L28_001DDE54);
            ang = func_00382538();
            r = func_003824E0(D_L28_001DDE60, D_L28_001DDE64);
            z = func_003824E0(D_L28_001DDE68, D_L28_001DDE6C);
            qzero(&b);
            b.x += func_0038D098(ang) * (r * 0.020000001f);
            b.y += func_0038D0B0(ang) * (r * 0.020000001f);
            b.z += z * 0.020000001f;
            c = b;
            c.z -= D_L28_001DDE70 * 0.00040000002f * (f32)FRAMES(D_L28_001DDE90);
            for (k = 0; k < D_L28_001DDE50; k++) {
                f32 s, g;
                s32 c1, c2;
                s = func_003824E0(0.5f, 1.5f);
                b.w = s * D_L28_001DDE74;
                c.w = s * D_L28_001DDE78;
                func_003C4C18(&a, D_L28_001DDE58);
                func_003C4C18(&c, D_L28_001DDE5C * 0.020000001f);
                c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDE7C, D_L28_001DDE84);
                c2 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDE80, D_L28_001DDE88);
                g = (f32)D_L28_001DDE94;
                g = func_003824E0(g * 0.5f, g * 2.5f);
                func_L01_00463378(&a, &b, &c, c1, c2, FRAMES(D_L28_001DDE8C), FRAMES(D_L28_001DDE90),
                                  (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
            }
        }
        func_003C2880(self);
        return;
    }
    func_L28_0039D280(self);
}
/* localdecomp:end func_L28_0039BA28 */

/* localdecomp:start func_L28_0039CCD8 */
typedef int q_0039CCD8 __attribute__((mode(TI)));
extern s32 func_L28_0039D038(void *);
extern void func_003C2880(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 func_L01_0044CE88(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_L02_00351780(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L08_003A0D40(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_0039CCD8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;
    s32 t;
    vu0_v4 v;
    if (a0[0x20] == 0) {
        if (func_L28_0039D038(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x198) - 200.0f) {
        func_003C2880(a0);
        return 1;
    }
    p = func_L01_00447490(a0, 0x10000, 0);
    if (func_0038CB00(st + 0x36) == 0) p = 0;
    if (p != 0 || *(f32 *)(st + 0x30) <= 0.0f) {
        if (*(u8 **)(p + 0x20) == a0) {
            func_L01_004450F0(a0, 9, -1);
        } else {
            st[0x47] = func_L01_0044CE88(*(u8 **)(p + 0x20));
            func_0038CF68(&v, p + 0x10, -1.0f);
            if (abs_asm(func_0038CE68(&v, a0 + 0xE0) < 0.9f)) *(q_0039CCD8 *)(a0 + 0xC0) = *(q_0039CCD8 *)&v;
            func_0038CE90(a0 + 0xD0, a0 + 0xE0, a0 + 0xC0);
            func_0038CF68(a0 + 0xD0, a0 + 0xD0, 1.0f);
            func_0038CE90(a0 + 0xC0, a0 + 0xD0, a0 + 0xE0);
            func_0038CF68(a0 + 0xC0, a0 + 0xC0, 1.0f);
            *(s16 *)(st + 0x36) = 0x21;
            func_L01_004450F0(a0, 8, -1);
        }
        func_L02_00351780(a0);
    }
    a0[0xA8] = 0xFF;
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L08_003A0D40(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x180), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x184), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x188), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x18C), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x180), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x184), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x188), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x18C), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_0039CCD8 */

/* localdecomp:start func_L28_0039D038 */
/* stores to 0x34 and 0xB8 go through a struct so sched1 sees them as not aliasing the $gp scalars */

typedef int u128_0039D038 __attribute__((mode(TI)));
extern f32 D_L28_001DDDC0;
extern f32 D_L28_001DDDC4;
extern u8 D_L28_001DDDF0;
__asm__(".extern D_L28_001DDDC0, 4");
__asm__(".extern D_L28_001DDDC4, 4");
__asm__(".extern D_L28_001DDDF0, 1");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);
typedef struct { u8 pad[0x23]; u8 f23; u8 pad2[0x10]; u16 f34; u8 pad3[0x82]; s32 fB8; } S_0039D038;
s32 func_L28_0039D038(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_0039D038 *)(st + 0x190) = *(u128_0039D038 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x1B0) = -1;
        *(s32 *)(st + 0x1B8) = -1;
    }
    a0[0x23] = 0x70;
    ((S_0039D038 *)a0)->f34 |= 0x2100;
    ((S_0039D038 *)a0)->fB8 = 0;
    fa = D_L28_001DDDC4 * 0.00040000002f;
    fb = D_L28_001DDDC0 * 0.020000001f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x78) = 0.7f;
    *(f32 *)(st + 0x70) = 0.4f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 0.7f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, fa, fb, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 1;
        *(f32 *)(st + 0x30) = 1.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DDDF0;
    st[0x3F] = 1;
    st[0x64] = 1;
    st[0x3E] = 1;
    func_L01_004450F0(a0, 3, -1);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x1B0) != -1 || *(unsigned long *)(st + 0x1B8) != 0xFFFFFFFFUL) {
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    func_003C7DD8(a0);
    return 0;
}
/* localdecomp:end func_L28_0039D038 */
