#include "common.h"
#include "vu0.h"

typedef int q_0039D530 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039D530;

/* localdecomp:start func_L28_0039D530 */
extern f32 D_L28_001DDF00;
__asm__(".extern D_L28_001DDF00, 4");
extern f32 D_L28_001DDF04;
__asm__(".extern D_L28_001DDF04, 4");
extern f32 D_L28_001DDF08;
__asm__(".extern D_L28_001DDF08, 4");
extern f32 D_L28_001DDF0C;
__asm__(".extern D_L28_001DDF0C, 4");
extern f32 D_L28_001DDF10;
__asm__(".extern D_L28_001DDF10, 4");
extern f32 D_L28_001DDF14;
__asm__(".extern D_L28_001DDF14, 4");
extern s32 D_L28_001DDF18;
__asm__(".extern D_L28_001DDF18, 4");
extern f32 D_L28_001DDF1C;
__asm__(".extern D_L28_001DDF1C, 4");
extern f32 D_L28_001DDF20;
__asm__(".extern D_L28_001DDF20, 4");
extern f32 D_L28_001DDF24;
__asm__(".extern D_L28_001DDF24, 4");
extern f32 D_L28_001DDF28;
__asm__(".extern D_L28_001DDF28, 4");
extern f32 D_L28_001DDF2C;
__asm__(".extern D_L28_001DDF2C, 4");
extern s32 D_L28_001DDF34;
__asm__(".extern D_L28_001DDF34, 4");
extern s32 D_L28_001DDF38;
__asm__(".extern D_L28_001DDF38, 4");
extern s32 D_L28_001DDF3C;
__asm__(".extern D_L28_001DDF3C, 4");
extern s32 D_L28_001DDF40;
__asm__(".extern D_L28_001DDF40, 4");
extern f32 D_L28_001DDF44;
__asm__(".extern D_L28_001DDF44, 4");
extern f32 D_L28_001DDF48;
__asm__(".extern D_L28_001DDF48, 4");
extern f32 D_L28_001DDF4C;
__asm__(".extern D_L28_001DDF4C, 4");
extern f32 D_L28_001DDF50;
__asm__(".extern D_L28_001DDF50, 4");
extern f32 D_L28_001DDF54;
__asm__(".extern D_L28_001DDF54, 4");
extern f32 D_L28_001DDF58;
__asm__(".extern D_L28_001DDF58, 4");
extern f32 D_L28_001DDF5C;
__asm__(".extern D_L28_001DDF5C, 4");
extern f32 D_L28_001DDF60;
__asm__(".extern D_L28_001DDF60, 4");
extern f32 D_L28_001DDF64;
__asm__(".extern D_L28_001DDF64, 4");
extern f32 D_L28_001DDF68;
__asm__(".extern D_L28_001DDF68, 4");
extern s32 D_L28_001DDF6C;
__asm__(".extern D_L28_001DDF6C, 4");
extern s32 D_L28_001DDF70;
__asm__(".extern D_L28_001DDF70, 4");
extern s32 D_L28_001DDF74;
__asm__(".extern D_L28_001DDF74, 4");
extern s32 D_L28_001DDF78;
__asm__(".extern D_L28_001DDF78, 4");
extern s32 D_L28_001DDF7C;
__asm__(".extern D_L28_001DDF7C, 4");
extern s32 D_L28_001DDF80;
__asm__(".extern D_L28_001DDF80, 4");
extern s32 D_L28_001DDF84;
__asm__(".extern D_L28_001DDF84, 4");
extern s32 D_L28_001DDF88;
__asm__(".extern D_L28_001DDF88, 4");
extern s32 D_L28_001DDF8C;
__asm__(".extern D_L28_001DDF8C, 4");
extern s32 D_L28_001DDF90;
__asm__(".extern D_L28_001DDF90, 4");
extern f32 D_L28_001DDF94;
__asm__(".extern D_L28_001DDF94, 4");
extern f32 D_L28_001DDF98;
__asm__(".extern D_L28_001DDF98, 4");
extern f32 D_L28_001DDF9C;
__asm__(".extern D_L28_001DDF9C, 4");
extern f32 D_L28_001DDFA0;
__asm__(".extern D_L28_001DDFA0, 4");
extern f32 D_L28_001DDFA4;
__asm__(".extern D_L28_001DDFA4, 4");
extern f32 D_L28_001DDFA8;
__asm__(".extern D_L28_001DDFA8, 4");
extern f32 D_L28_001DDFAC;
__asm__(".extern D_L28_001DDFAC, 4");
extern f32 D_L28_001DDFB0;
__asm__(".extern D_L28_001DDFB0, 4");
extern f32 D_L28_001DDFB4;
__asm__(".extern D_L28_001DDFB4, 4");
extern f32 D_L28_001DDFB8;
__asm__(".extern D_L28_001DDFB8, 4");
extern s32 D_L28_001DDFBC;
__asm__(".extern D_L28_001DDFBC, 4");
extern s32 D_L28_001DDFC0;
__asm__(".extern D_L28_001DDFC0, 4");
extern s32 D_L28_001DDFC4;
__asm__(".extern D_L28_001DDFC4, 4");
extern s32 D_L28_001DDFC8;
__asm__(".extern D_L28_001DDFC8, 4");
extern s32 D_L28_001DDFCC;
__asm__(".extern D_L28_001DDFCC, 4");
extern s32 D_L28_001DDFD0;
__asm__(".extern D_L28_001DDFD0, 4");
extern s32 D_L28_001DDFD4;
__asm__(".extern D_L28_001DDFD4, 4");
extern s32 D_L28_001DDFD8;
__asm__(".extern D_L28_001DDFD8, 4");
extern f32 D_L28_001DDFDC;
__asm__(".extern D_L28_001DDFDC, 4");
extern s32 D_L28_001DDFE0;
__asm__(".extern D_L28_001DDFE0, 4");
extern s32 D_L28_001DDFE4;
__asm__(".extern D_L28_001DDFE4, 4");
extern f32 D_L28_001DDFE8;
__asm__(".extern D_L28_001DDFE8, 4");
extern f32 D_L28_001DDFEC;
__asm__(".extern D_L28_001DDFEC, 4");
extern f32 D_L28_001DDFF0;
__asm__(".extern D_L28_001DDFF0, 4");
extern f32 D_L28_001DDFF4;
__asm__(".extern D_L28_001DDFF4, 4");
extern f32 D_L28_001DDFF8;
__asm__(".extern D_L28_001DDFF8, 4");
extern f32 D_L28_001DDFFC;
__asm__(".extern D_L28_001DDFFC, 4");


extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_L28_001DE840;
extern s32 D_L28_001E8298[];
extern u8 *D_001A73E8[];
extern u8 D_001A4BE0[];

extern s32 func_L28_0039E820(u8 *);
extern void func_L28_0039EDB8(u8 *);
extern void func_L28_0039F010(u8 *);
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

static inline f32 fmin_0039D530(f32 a, f32 b) {
    if (a < b) return a;
    return b;
}
static inline f32 fmin2_0039D530(f32 a, f32 b) {
    return a < b ? a : b;
}
#define FRAMES(x) (((x) * 5 + 2) / 6)
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

void func_L28_0039D530(u8 *self) {
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

    if (func_L28_0039E820(self) != 0) {
        func_L28_0039EDB8(self);
        func_003C2880(self);
        return;
    }

    switch (self[0x20]) {
    case 1:
        if (S32(st, 0x1CC) == 2) {
            func_L01_004450F0(self, 2, -1);
            break;
        }
        idx = S32(st, 0x1C0);
        if (idx != -1) {
            m = D_L28_001DEC9C + (idx << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_00382468(0x32) == 0) {
                    func_L01_004450F0(self, 2, -1);
                    break;
                }
            }
        } else if (S32(st, 0x1C8) != idx) {
            m = D_L28_001DEC9C + (S32(st, 0x1C8) << 8);
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
                *(q_0039D530 *)(self + 0xC0) = *(q_0039D530 *)&v;
            }
            func_0038CE90(self + 0xD0, self + 0xE0, self + 0xC0);
            func_0038CF68(self + 0xD0, self + 0xD0, 1.0f);
            func_0038CE90(self + 0xC0, self + 0xD0, self + 0xE0);
            func_0038CF68(self + 0xC0, self + 0xC0, 1.0f);
            F32(st, 0x1D8) = F32(self, 0x2C);
            func_003A52A0(6, 0, self);
        }
        func_L01_0045D218(self, self + 0x10);
        F32(self, 0x2C) = fmin2_0039D530(F32(st, 0x1D8) * (f32)U16(self, 0x96) / 25.0f, F32(st, 0x1D8));
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 3, -1);
            if (self[0x43] != 1) {
                func_003C3A10(self, 1, 0, 8);
            }
            F32(self, 0x2C) = F32(st, 0x1D8);
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
        if (S32(st, 0x1D0) != 0 && (func_00382468(0x19) == 0 || U16(self, 0x96) > 0x19)) {
            func_L01_004450F0(self, 5, -1);
            S32(st, 0x1D0) = 0;
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
            qzero(st + 0x1B0);
            F32(st, 0x1B0) = func_0038D098(ang4) * r4;
            F32(st, 0x1B4) = func_0038D0B0(ang4) * r4;
            vec_add_ab(st + 0x1B0, st + 0x1B0, st + 0x1A0);
            func_L01_0045BD78(self, D_L28_001DDF04 * 0.5f * 0.00040000002f, D_L28_001DDF00 * 0.5f * 0.020000001f,
                              0.010053097f, 0.25132743f);
        }
        func_0038CF68(&a, self + 0xC0, 3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_0045D218(self, &v);
        f = func_0038D160(F32(st, 0x1B0) - F32(self, 0x10), F32(st, 0x1B4) - F32(self, 0x14));
        if (func_0038DBA0(F32(self, 0xF8), f) > 0.17453292f) {
            func_0038D890(self + 0xC0, self + 0xC0, self + 0xE0, 0.09075713f);
            func_0038D890(self + 0xD0, self + 0xD0, self + 0xE0, 0.09075713f);
            F32(self, 0xF8) = func_0038D160(F32(self, 0xC0), F32(self, 0xC4));
        }
        if (func_0038CF38(self + 0x10, st + 0x1B0) < 0.75f) {
            func_L01_004450F0(self, 4, -1);
        }
        if (S16(st, 0x174) == 1 || FRAMES(D_L28_001DDF34) < U16(self, 0x96)) {
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
        if (FRAMES(D_L28_001DDF38) < U16(self, 0x96) && func_00382468(0x53) == 0) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x43] != 0) {
                func_003C3A10(self, 0, 0, 8);
            }
            self[0xBC] = 0;
            func_L01_0045BD78(self, D_L28_001DDF04 * 0.00040000002f, D_L28_001DDF00 * 0.020000001f, 0.010053097f,
                              0.25132743f);
        }
        if (self[0xBC] == 0) {
            func_L01_0045D218(self, st + 0x160);
            F32(self, 0xF8) = func_0038D160(F32(self, 0xC0), F32(self, 0xC4));
            if (func_00382468(FRAMES(D_L28_001DDF3C)) == 0) {
                func_L01_004450F0(self, 7, -1);
            }
            vec_sub_ba(&v, st + 0x160, self + 0x10);
            func_0038CF68(&v, &v, 1.0f);
            f6 = func_0038CE68(&v, self + 0xC0);
            if (func_0038CF38(self + 0x10, st + 0x160) < D_L28_001DDF08 && D_L28_001DDF0C < f6) {
                self[0xBC] = 1;
                if (self[0x43] != 4) {
                    func_003C3A10(self, 4, 0, 8);
                }
                func_L01_0045BD78(self, D_L28_001DDF14 * 0.00040000002f, D_L28_001DDF10 * 0.020000001f,
                                  0.010053097f, 0.25132743f);
            }
        } else if (self[0xBC] == 1) {
            if (func_L01_004395E0(self) > 11.0f && func_L01_004395E0(self) < 18.0f && self[0x42] == 4 &&
                func_0038CF38(self + 0x10, st + 0x160) > 1.75f) {
                save = F32(st, 0xA4);
                S32(st, 0xA4) = 0;
                for (n6 = 0; n6 < D_L28_001DDF18; n6++) {
                    vec_sub_ba(&v, st + 0x160, self + 0x10);
                    func_0038CE20(&v, &v, 1.0f / (f32)D_L28_001DDF18);
                    vec_add_ba(&a, self + 0x10, &v);
                    func_L01_0045D218(self, &a);
                    S32(st, 0x12C) = D_L28_001DE840 - 1;
                }
                F32(st, 0xA4) = save;
                {
                    u8 *h = D_001A4BE0;
                    func_L01_004468C8(self, 0, S32(st, 0x170) == S32(h, 0x25C0) ? 1 : 0x10001, 0, 1, 0, 1.1f,
                                      7.0f, 1.5f);
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
            func_003C3A10(self, 3, 0, 5);
        }
        func_L01_0045D218(self, self + 0x10);
        if (self[0x60] & 2) {
            func_L01_004450F0(self, self[0x94], -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x43] != 3) {
                func_003C3A10(self, 3, 0, 2);
            }
            func_L01_0045BD78(self, D_L28_001DDF24 * 0.00040000002f, D_L28_001DDF20 * 0.020000001f, 0.010053097f,
                              0.25132743f);
            S32(st, 0xA8) |= 0x10;
            F32(self, 0x48) = D_L28_001DDF1C;
            v = *(V4_0039D530 *)(self + 0xE0);
            for (n8 = 0; n8 < D_L28_001DDF40; n8++) {
                f32 ang, r, z, s, g;
                s32 c1, c2;
                ang = func_00382538();
                r = func_003824E0(D_L28_001DDF50, D_L28_001DDF54);
                z = func_003824E0(D_L28_001DDF58, D_L28_001DDF5C);
                qzero(&b);
                b.x += func_0038D098(ang) * (r * 0.020000001f);
                b.y += func_0038D0B0(ang) * (r * 0.020000001f);
                func_0038CF68(&n, &v, z * 0.020000001f);
                vec_add_ba(&b, &b, &n);
                c = b;
                func_0038CF68(&n, &v, -(D_L28_001DDF60 * 0.00040000002f) * (f32)FRAMES(D_L28_001DDF80));
                vec_add_ab(&c, &c, &n);
                s = func_003824E0(0.5f, 1.5f);
                b.w = s * D_L28_001DDF64;
                c.w = s * D_L28_001DDF68;
                func_0038CF68(&a, &v, D_L28_001DDF44);
                vec_add_ba(&a, &a, self + 0x10);
                func_003C4C18(&a, D_L28_001DDF48);
                func_003C4C18(&c, D_L28_001DDF4C * 0.020000001f);
                c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDF6C, D_L28_001DDF74);
                c2 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDF70, D_L28_001DDF78);
                g = func_003824E0((f32)D_L28_001DDF84, (f32)D_L28_001DDF88);
                func_L01_00463378(&a, &b, &c, c1, c2, FRAMES(D_L28_001DDF7C), FRAMES(D_L28_001DDF80),
                                  (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
            }
        }
        func_0038CF68(&a, self + 0xC0, -3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_0045D218(self, &v);
        func_0038CF68(&b, self + 0xE0, D_L28_001DDF2C);
        vec_add_ab(&b, &b, self + 0x10);
        if (func_L01_003FB640(&b, 0, self, D_L28_001DDF28) != 0) {
            S32(st, 0xA8) &= ~0x10;
            func_L01_00446780(self, &b, 0x10000, 0, 1, 0, D_L28_001DDF28, 5.0f, 1.0f);
            if (F32(st, 0x30) < 0.0f) {
                func_L01_004450F0(self, 9, -1);
            } else if (D_L28_001E8298[0] == 0) {
                func_L01_004450F0(self, 6, -1);
            }
        }
        if ((self[0x60] & 2) ||
            (U16(self, 0x96) > 2 && func_00382468((s32)((60.0f / D_L28_001DDF1C * 5.0f + 2.0f) / 6.0f)) == 0)) {
            S32(st, 0xA8) &= ~0x10;
            if (F32(st, 0x30) < 0.0f) {
                func_L01_004450F0(self, 9, -1);
            } else {
                func_L01_004450F0(self, 6, -1);
            }
        }
        break;
    case 9:
        func_L28_0039EDB8(self);
        v = *(V4_0039D530 *)(self + 0xE0);
        for (i = 0; i < D_L28_001DDFD8; i++) {
            func_0038CF68(&a, &v, func_003824E0(D_L28_001DDFE8, D_L28_001DDFEC) * 0.020000001f);
            func_003C4C18(&a, D_L28_001DDFFC * 0.020000001f);
            func_0038CF68(&b, &v, D_L28_001DDFDC);
            vec_add_ab(&b, &b, self + 0x10);
            func_003C4C18(&b, D_L28_001DDFF8);
            f9 = func_003824E0(D_L28_001DDFF0, D_L28_001DDFF4) * 210000.0f;
            func_L01_004739D8(&b, &a, D_L28_001DDFE0, D_L28_001DDFE4, FRAMES(func_00382498(0x78, 0xF0)), 0, f9);
        }
        for (j = 0; j < D_L28_001DDF8C; j++) {
            f32 ang, r, z;
            a = *(V4_0039D530 *)(self + 0x10);
            func_003C4C18(&a, D_L28_001DDF94);
            ang = func_00382538();
            r = func_003824E0(D_L28_001DDFA0, D_L28_001DDFA4);
            z = func_003824E0(D_L28_001DDFA8, D_L28_001DDFAC);
            qzero(&b);
            b.x += func_0038D098(ang) * (r * 0.020000001f);
            b.y += func_0038D0B0(ang) * (r * 0.020000001f);
            b.z += z * 0.020000001f;
            c = b;
            c.z -= D_L28_001DDFB0 * 0.00040000002f * (f32)FRAMES(D_L28_001DDFD0);
            for (k = 0; k < D_L28_001DDF90; k++) {
                f32 s, g;
                s32 c1, c2;
                s = func_003824E0(0.5f, 1.5f);
                b.w = s * D_L28_001DDFB4;
                c.w = s * D_L28_001DDFB8;
                func_003C4C18(&a, D_L28_001DDF98);
                func_003C4C18(&c, D_L28_001DDF9C * 0.020000001f);
                c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDFBC, D_L28_001DDFC4);
                c2 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DDFC0, D_L28_001DDFC8);
                g = (f32)D_L28_001DDFD4;
                g = func_003824E0(g * 0.5f, g * 2.5f);
                func_L01_00463378(&a, &b, &c, c1, c2, FRAMES(D_L28_001DDFCC), FRAMES(D_L28_001DDFD0),
                                  (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
            }
        }
        func_003C2880(self);
        return;
    }
    func_L28_0039F010(self);
}
/* localdecomp:end func_L28_0039D530 */

/* localdecomp:start func_L28_0039E820 */
typedef int q_0039E820 __attribute__((mode(TI)));
extern s32 func_L28_0039EBC8(void *);
extern void func_003C2880(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 func_L01_0044CE88(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_L02_003A5138(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L28_0039EDB8(u8 *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_0039E820(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;
    s32 t;
    vu0_v4 v;
    if (a0[0x20] == 0) {
        if (func_L28_0039EBC8(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x1A8) - 200.0f) {
        func_003C2880(a0);
        return 1;
    }
    func_L01_0044ABD0(a0, st + 0x180);
    p = func_L01_00447490(a0, 0x10000, 0);
    if (func_0038CB00(st + 0x36) == 0) p = 0;
    if (p != 0) {
        *(f32 *)(st + 0x30) -= *(f32 *)(p + 0x2C);
        if (*(u8 **)(p + 0x20) != a0) goto chase;
    } else {
        if (!(*(f32 *)(st + 0x30) <= 0.0f)) goto done;
        if (a0[0x20] == 8) goto done;
        if (a0[0x20] == 9) goto done;
    }
    func_L01_004450F0(a0, 9, -1);
    goto hit;
chase:
            st[0x47] = func_L01_0044CE88(*(u8 **)(p + 0x20));
            func_0038CF68(&v, p + 0x10, -1.0f);
            if (abs_asm(func_0038CE68(&v, a0 + 0xE0) < 0.9f)) *(q_0039E820 *)(a0 + 0xC0) = *(q_0039E820 *)&v;
            func_0038CE90(a0 + 0xD0, a0 + 0xE0, a0 + 0xC0);
            func_0038CF68(a0 + 0xD0, a0 + 0xD0, 1.0f);
            func_0038CE90(a0 + 0xC0, a0 + 0xD0, a0 + 0xE0);
            func_0038CF68(a0 + 0xC0, a0 + 0xC0, 1.0f);
            *(s16 *)(st + 0x36) = 0x11;
            func_003C4A40(a0, st + 0x180);
            func_L01_004450F0(a0, 8, -1);
hit:
    func_L02_003A5138(a0);
done:
    a0[0xA8] = 0xFF;
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_0039EDB8(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x190), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x194), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x198), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x19C), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x190), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x194), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x198), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x19C), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_0039E820 */

/* localdecomp:start func_L28_0039EBC8 */
/* stores to 0x34 and 0xB8 go through a struct so sched1 sees them as not aliasing the $gp scalars */

typedef int u128_0039EBC8 __attribute__((mode(TI)));
extern f32 D_L28_001DDF00;
extern f32 D_L28_001DDF04;
extern u8 D_L28_001DDF30;
__asm__(".extern D_L28_001DDF00, 4");
__asm__(".extern D_L28_001DDF04, 4");
__asm__(".extern D_L28_001DDF30, 1");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);
typedef struct { u8 pad[0x23]; u8 f23; u8 pad2[0x10]; u16 f34; u8 pad3[0x82]; s32 fB8; } S34_0039EBC8;
s32 func_L28_0039EBC8(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_0039EBC8 *)(st + 0x1A0) = *(u128_0039EBC8 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x1C0) = -1;
        *(s32 *)(st + 0x1C8) = -1;
    }
    a0[0x23] = 0x70;
    ((S34_0039EBC8 *)a0)->f34 |= 0x2100;
    ((S34_0039EBC8 *)a0)->fB8 = 0;
    fa = D_L28_001DDF04 * 0.00040000002f;
    fb = D_L28_001DDF00 * 0.020000001f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x78) = 2.0f;
    *(f32 *)(st + 0x70) = 0.75f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 2.0f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, fa, fb, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 10;
        *(f32 *)(st + 0x30) = 10.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DDF30;
    st[0x64] = 1;
    st[0x3E] = 1;
    st[0x3F] = 0;
    func_L01_004450F0(a0, 3, -1);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x1C0) != -1 || *(unsigned long *)(st + 0x1C8) != 0xFFFFFFFFUL) {
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    func_003C7DD8(a0);
    return 0;
}
/* localdecomp:end func_L28_0039EBC8 */

/* localdecomp:start func_L28_0039EDB8 */
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L28_0039D038(void *);
extern void func_L01_004443E8(u8 *, s32, s32);
typedef int q_0039EDB8 __attribute__((mode(TI)));
static __inline__ void spawn_0039EDB8(u8 *self, u8 *st, f32 side) {
    vu0_v4 a, b;
    u8 *m;
    u8 *d;
    m = func_003C24B0(0x1B5D, 0x200);
    if (m != 0) {
        func_L01_00456160(m, self);
        *(u16 *)(m + 0x34) |= 0x20;
        func_L01_0044A7D0(m);
        d = *(u8 **)(m + 0x68);
        *(s32 *)(d + 0x180) = *(s32 *)(st + 0x190);
        *(s32 *)(d + 0x188) = *(s32 *)(st + 0x198);
        *(f32 *)(d + 0x18C) = *(f32 *)(st + 0x19C);
        *(f32 *)(d + 0x184) = *(f32 *)(st + 0x194);
        *(u8 **)(d + 0x1C) = d + 0x70;
        *(u8 **)(d + 0xC) = d + 0x160;
        *(u8 **)(d + 0x0) = d + 0x30;
        *(s16 *)(d + 0x36) = 0x1E;
        *(s32 *)(d + 0x1BC) = 2;
        func_0038CF68(&a, self + 0xD0, side);
        vec_add_ab(m + 0x10, &a, self + 0x10);
        func_0038CF68(&b, self + 0xE0, 0.6f);
        vec_add_ab(m + 0x10, &b, m + 0x10);
        *(q_0039EDB8 *)(m + 0xC0) = *(q_0039EDB8 *)(self + 0xC0);
        *(q_0039EDB8 *)(m + 0xD0) = *(q_0039EDB8 *)(self + 0xD0);
        *(q_0039EDB8 *)(m + 0xE0) = *(q_0039EDB8 *)(self + 0xE0);
        *(s16 *)(m + 0xB6) = 0x14;
        func_L28_0039D038(m);
    }
}
void func_L28_0039EDB8(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    func_003A52A0(0, 0, self);
    func_003A52A0(1, 0, self);
    spawn_0039EDB8(self, st, 0.5f);
    spawn_0039EDB8(self, st, -0.5f);
    func_L01_004443E8(self, 0, 3);
    *(u16 *)(self + 0x34) &= 0xFFDF;
}
/* localdecomp:end func_L28_0039EDB8 */

/* localdecomp:start func_L28_0039F010 */
extern u8 D_L28_001E1540[];
extern void func_L01_00404808(void *, void *);
extern void func_L08_0039F4E8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, u32);
void func_L28_0039F010(u8 *a0) {
    u8 *d = *(u8 **)(a0 + 0x68);
    f32 t;
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE) *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L28_001E1540, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    if (a0[0x20] != 1 && a0[0x31] != 0) func_L01_00404808(func_L08_0039F4E8, a0);
    t = func_0038DAB8(*(f32 *)(d + 0x1DC), 0.15358898f);
    *(f32 *)(d + 0x1DC) = t;
    *(s32 *)(a0 + 0x78) = func_0038DBD8((func_0038D0B0(t) + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L28_0039F010 */
