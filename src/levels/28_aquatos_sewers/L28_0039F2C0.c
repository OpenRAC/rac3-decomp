#include "common.h"
#include "vu0.h"

typedef int q_0039F2C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039F2C0;

/* localdecomp:start func_L28_0039F2C0 */
extern f32 D_L28_001DE040;
__asm__(".extern D_L28_001DE040, 4");
extern f32 D_L28_001DE044;
__asm__(".extern D_L28_001DE044, 4");
extern f32 D_L28_001DE048;
__asm__(".extern D_L28_001DE048, 4");
extern f32 D_L28_001DE04C;
__asm__(".extern D_L28_001DE04C, 4");
extern f32 D_L28_001DE050;
__asm__(".extern D_L28_001DE050, 4");
extern f32 D_L28_001DE054;
__asm__(".extern D_L28_001DE054, 4");
extern s32 D_L28_001DE058;
__asm__(".extern D_L28_001DE058, 4");
extern s32 D_L28_001DE074;
__asm__(".extern D_L28_001DE074, 4");
extern s32 D_L28_001DE078;
__asm__(".extern D_L28_001DE078, 4");
extern s32 D_L28_001DE07C;
__asm__(".extern D_L28_001DE07C, 4");
extern s32 D_L28_001DE080;
__asm__(".extern D_L28_001DE080, 4");
extern f32 D_L28_001DE084;
__asm__(".extern D_L28_001DE084, 4");
extern f32 D_L28_001DE088;
__asm__(".extern D_L28_001DE088, 4");
extern f32 D_L28_001DE08C;
__asm__(".extern D_L28_001DE08C, 4");
extern f32 D_L28_001DE090;
__asm__(".extern D_L28_001DE090, 4");
extern f32 D_L28_001DE094;
__asm__(".extern D_L28_001DE094, 4");
extern f32 D_L28_001DE098;
__asm__(".extern D_L28_001DE098, 4");
extern f32 D_L28_001DE09C;
__asm__(".extern D_L28_001DE09C, 4");
extern f32 D_L28_001DE0A0;
__asm__(".extern D_L28_001DE0A0, 4");
extern f32 D_L28_001DE0A4;
__asm__(".extern D_L28_001DE0A4, 4");
extern f32 D_L28_001DE0A8;
__asm__(".extern D_L28_001DE0A8, 4");
extern s32 D_L28_001DE0AC;
__asm__(".extern D_L28_001DE0AC, 4");
extern s32 D_L28_001DE0B0;
__asm__(".extern D_L28_001DE0B0, 4");
extern s32 D_L28_001DE0B4;
__asm__(".extern D_L28_001DE0B4, 4");
extern s32 D_L28_001DE0B8;
__asm__(".extern D_L28_001DE0B8, 4");
extern s32 D_L28_001DE0BC;
__asm__(".extern D_L28_001DE0BC, 4");
extern s32 D_L28_001DE0C0;
__asm__(".extern D_L28_001DE0C0, 4");
extern s32 D_L28_001DE0C4;
__asm__(".extern D_L28_001DE0C4, 4");
extern s32 D_L28_001DE0C8;
__asm__(".extern D_L28_001DE0C8, 4");
extern s32 D_L28_001DE0CC;
__asm__(".extern D_L28_001DE0CC, 4");
extern s32 D_L28_001DE0D0;
__asm__(".extern D_L28_001DE0D0, 4");
extern f32 D_L28_001DE0D4;
__asm__(".extern D_L28_001DE0D4, 4");
extern f32 D_L28_001DE0D8;
__asm__(".extern D_L28_001DE0D8, 4");
extern f32 D_L28_001DE0DC;
__asm__(".extern D_L28_001DE0DC, 4");
extern f32 D_L28_001DE0E0;
__asm__(".extern D_L28_001DE0E0, 4");
extern f32 D_L28_001DE0E4;
__asm__(".extern D_L28_001DE0E4, 4");
extern f32 D_L28_001DE0E8;
__asm__(".extern D_L28_001DE0E8, 4");
extern f32 D_L28_001DE0EC;
__asm__(".extern D_L28_001DE0EC, 4");
extern f32 D_L28_001DE0F0;
__asm__(".extern D_L28_001DE0F0, 4");
extern f32 D_L28_001DE0F4;
__asm__(".extern D_L28_001DE0F4, 4");
extern f32 D_L28_001DE0F8;
__asm__(".extern D_L28_001DE0F8, 4");
extern s32 D_L28_001DE0FC;
__asm__(".extern D_L28_001DE0FC, 4");
extern s32 D_L28_001DE100;
__asm__(".extern D_L28_001DE100, 4");
extern s32 D_L28_001DE104;
__asm__(".extern D_L28_001DE104, 4");
extern s32 D_L28_001DE108;
__asm__(".extern D_L28_001DE108, 4");
extern s32 D_L28_001DE10C;
__asm__(".extern D_L28_001DE10C, 4");
extern s32 D_L28_001DE110;
__asm__(".extern D_L28_001DE110, 4");
extern s32 D_L28_001DE114;
__asm__(".extern D_L28_001DE114, 4");
extern s32 D_L28_001DE118;
__asm__(".extern D_L28_001DE118, 4");
extern f32 D_L28_001DE11C;
__asm__(".extern D_L28_001DE11C, 4");
extern s32 D_L28_001DE120;
__asm__(".extern D_L28_001DE120, 4");
extern s32 D_L28_001DE124;
__asm__(".extern D_L28_001DE124, 4");
extern f32 D_L28_001DE128;
__asm__(".extern D_L28_001DE128, 4");
extern f32 D_L28_001DE12C;
__asm__(".extern D_L28_001DE12C, 4");
extern f32 D_L28_001DE130;
__asm__(".extern D_L28_001DE130, 4");
extern f32 D_L28_001DE134;
__asm__(".extern D_L28_001DE134, 4");
extern f32 D_L28_001DE138;
__asm__(".extern D_L28_001DE138, 4");
extern f32 D_L28_001DE13C;
__asm__(".extern D_L28_001DE13C, 4");


extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_L28_001DE840;
extern s32 D_L28_001E8298[];
extern u8 *D_001A73E8[];
extern u8 D_001A4BE0[];

extern s32 func_L28_003A0708(u8 *);
extern void func_L28_003A0B60(u8 *);
extern void func_L28_003A0DC0(u8 *);
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
extern void func_L01_004468C8(u8 *, s32, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_L01_00454370(void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_0038DBD8(f32, u32, u32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static inline f32 fmin_0039F2C0(f32 a, f32 b) {
    if (a < b) return a;
    return b;
}
static inline f32 fmin2_0039F2C0(f32 a, f32 b) {
    return a < b ? a : b;
}
#define FRAMES(x) (((x) * 5 + 2) / 6)
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

#define BURST_0039F2C0(Pv, Pa, Pb, Pc, Pn)                                                              \
    (Pv) = *(V4_0039F2C0 *)(self + 0xE0);                                                               \
    for (n8 = 0; n8 < D_L28_001DE080; n8++) {                                                           \
        f32 ang, r, z, s, g;                                                                            \
        s32 c1, c2;                                                                                     \
        ang = func_00382538();                                                                          \
        r = func_003824E0(D_L28_001DE090, D_L28_001DE094);                                              \
        z = func_003824E0(D_L28_001DE098, D_L28_001DE09C);                                              \
        qzero(&(Pb));                                                                                   \
        (Pb).x += func_0038D098(ang) * (r * 0.020000001f);                                              \
        (Pb).y += func_0038D0B0(ang) * (r * 0.020000001f);                                              \
        func_0038CF68(&(Pn), &(Pv), z * 0.020000001f);                                                  \
        vec_add_ba(&(Pb), &(Pb), &(Pn));                                                                \
        (Pc) = (Pb);                                                                                    \
        func_0038CF68(&(Pn), &(Pv), -(D_L28_001DE0A0 * 0.00040000002f) * (f32)FRAMES(D_L28_001DE0C0));  \
        vec_add_ab(&(Pc), &(Pc), &(Pn));                                                                \
        s = func_003824E0(0.5f, 1.5f);                                                                  \
        (Pb).w = s * D_L28_001DE0A4;                                                                    \
        (Pc).w = s * D_L28_001DE0A8;                                                                    \
        func_0038CF68(&(Pa), &(Pv), D_L28_001DE084);                                                    \
        vec_add_ba(&(Pa), &(Pa), self + 0x10);                                                          \
        func_003C4C18(&(Pa), D_L28_001DE088);                                                           \
        func_003C4C18(&(Pc), D_L28_001DE08C * 0.020000001f);                                            \
        c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DE0AC, D_L28_001DE0B4);                  \
        c2 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DE0B0, D_L28_001DE0B8);                  \
        g = func_003824E0((f32)D_L28_001DE0C4, (f32)D_L28_001DE0C8);                                    \
        func_L01_00463378(&(Pa), &(Pb), &(Pc), c1, c2, FRAMES(D_L28_001DE0BC), FRAMES(D_L28_001DE0C0),  \
                          (s32)((g * 5.0f + 2.0f) / 6.0f), -1);                                         \
    }

void func_L28_0039F2C0(u8 *self) {
    V4_0039F2C0 v;
    V4_0039F2C0 a;
    V4_0039F2C0 b;
    V4_0039F2C0 c;
    V4_0039F2C0 n;
    V4_0039F2C0 w;
    u8 *st = *(u8 **)(self + 0x68);
    u8 *m;
    s32 idx;
    s32 i, j, k, n6, r8;
    f32 f, g, f6, f9, save;

    if (func_L28_003A0708(self) != 0) {
        func_L28_003A0B60(self);
        func_003C2880(self);
        return;
    }

    switch (self[0x20]) {
    case 1:
        if (S32(st, 0x2FC) == 2) {
            func_L01_004450F0(self, 2, -1);
            break;
        }
        idx = S32(st, 0x2F0);
        if (idx != -1) {
            m = D_L28_001DEC9C + (idx << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_00382468(0x32) == 0) {
                    func_L01_004450F0(self, 2, -1);
                    break;
                }
            }
        } else if (S32(st, 0x2F8) != idx) {
            m = D_L28_001DEC9C + (S32(st, 0x2F8) << 8);
            if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
                if (func_00382468(0x32) == 0) {
                    func_L01_004450F0(self, 2, -1);
                    break;
                }
            }
        } else if (S16(st, 0x234) == 1) {
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
            S32(self, 0xE0) = 0;
            S32(self, 0xE4) = 0;
            F32(self, 0xE8) = 1.0f;
            F32(self, 0xC0) = 1.0f;
            S32(self, 0xC4) = 0;
            S32(self, 0xC8) = 0;
            vec_sub_ba(&v, st + 0x220, self + 0x10);
            func_0038CF68(&v, &v, 1.0f);
            if (abs_asm(func_0038CE68(&v, self + 0xE0) < 0.9f)) {
                *(q_0039F2C0 *)(self + 0xC0) = *(q_0039F2C0 *)&v;
            }
            func_0038CE90(self + 0xD0, self + 0xE0, self + 0xC0);
            func_0038CF68(self + 0xD0, self + 0xD0, 1.0f);
            func_0038CE90(self + 0xC0, self + 0xD0, self + 0xE0);
            func_0038CF68(self + 0xC0, self + 0xC0, 1.0f);
            F32(st, 0x308) = F32(self, 0x2C);
            func_003A52A0(6, 0, self);
        }
        func_L01_0045D218(self, self + 0x10);
        F32(self, 0x2C) = fmin2_0039F2C0(F32(st, 0x308) * (f32)U16(self, 0x96) / 25.0f, F32(st, 0x308));
        if (self[0x60] & 2) {
            func_L01_004450F0(self, 3, -1);
            if (self[0x43] != 1) {
                func_003C3A10(self, 1, 0, 8);
            }
            F32(self, 0x2C) = F32(st, 0x308);
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x42] != 1 && self[0x43] != 1) {
                func_003C3A10(self, 1, 0, 8);
            }
        }
        func_L01_0045D218(self, self + 0x10);
        if (S16(st, 0x234) == 1 && (func_00382468(0x32) == 0 || U16(self, 0x96) > 0x32)) {
            func_L01_004450F0(self, 6, -1);
            break;
        }
        if (S32(st, 0x300) != 0 && (func_00382468(0x19) == 0 || U16(self, 0x96) > 0x19)) {
            func_L01_004450F0(self, 5, -1);
            S32(st, 0x300) = 0;
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
            qzero(st + 0x2E0);
            F32(st, 0x2E0) = func_0038D098(ang4) * r4;
            F32(st, 0x2E4) = func_0038D0B0(ang4) * r4;
            vec_add_ab(st + 0x2E0, st + 0x2E0, st + 0x2D0);
            func_L01_0045BD78(self, D_L28_001DE044 * 0.5f * 0.00040000002f, D_L28_001DE040 * 0.5f * 0.020000001f,
                              0.010053097f, 0.25132743f);
        }
        func_0038CF68(&a, self + 0xC0, 3.0f);
        vec_add_ba(&v, self + 0x10, &a);
        func_L01_0045D218(self, &v);
        f = func_0038D160(F32(st, 0x2E0) - F32(self, 0x10), F32(st, 0x2E4) - F32(self, 0x14));
        if (func_0038DBA0(F32(self, 0xF8), f) > 0.17453292f) {
            func_0038D890(self + 0xC0, self + 0xC0, self + 0xE0, 0.09075713f);
            func_0038D890(self + 0xD0, self + 0xD0, self + 0xE0, 0.09075713f);
            F32(self, 0xF8) = func_0038D160(F32(self, 0xC0), F32(self, 0xC4));
        }
        if (func_0038CF38(self + 0x10, st + 0x2E0) < 0.75f) {
            func_L01_004450F0(self, 4, -1);
        }
        if (S16(st, 0x234) == 1 || FRAMES(D_L28_001DE074) < U16(self, 0x96)) {
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
        if (S16(st, 0x234) == 1) {
            func_L01_004450F0(self, 6, -1);
            break;
        }
        if (FRAMES(D_L28_001DE078) < U16(self, 0x96) && func_00382468(0x53) == 0) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(self) != 0) {
            if (self[0x43] != 0) {
                func_003C3A10(self, 0, 0, 8);
            }
            self[0xBC] = 0;
            func_L01_0045BD78(self, D_L28_001DE044 * 0.00040000002f, D_L28_001DE040 * 0.020000001f, 0.010053097f,
                              0.25132743f);
        }
        if (self[0xBC] == 0) {
            func_L01_0045D218(self, st + 0x220);
            F32(self, 0xF8) = func_0038D160(F32(self, 0xC0), F32(self, 0xC4));
            if (func_00382468(FRAMES(D_L28_001DE07C)) == 0) {
                func_L01_004450F0(self, 7, -1);
            }
            vec_sub_ba(&v, st + 0x220, self + 0x10);
            func_0038CF68(&v, &v, 1.0f);
            f6 = func_0038CE68(&v, self + 0xC0);
            if (func_0038CF38(self + 0x10, st + 0x220) < D_L28_001DE048 && D_L28_001DE04C < f6) {
                self[0xBC] = 1;
                if (self[0x43] != 4) {
                    func_003C3A10(self, 4, 0, 8);
                }
                func_L01_0045BD78(self, D_L28_001DE054 * 0.00040000002f, D_L28_001DE050 * 0.020000001f,
                                  0.010053097f, 0.25132743f);
            }
        } else if (self[0xBC] == 1) {
            if (func_L01_004395E0(self) > 11.0f && func_L01_004395E0(self) < 18.0f && self[0x42] == 4 &&
                func_0038CF38(self + 0x10, st + 0x220) > 1.75f) {
                save = F32(st, 0xA4);
                S32(st, 0xA4) = 0;
                for (n6 = 0; n6 < D_L28_001DE058; n6++) {
                    vec_sub_ba(&v, st + 0x220, self + 0x10);
                    func_0038CE20(&v, &v, 1.0f / (f32)D_L28_001DE058);
                    vec_add_ba(&a, self + 0x10, &v);
                    func_L01_0045D218(self, &a);
                    S32(st, 0x12C) = D_L28_001DE840 - 1;
                }
                F32(st, 0xA4) = save;
                {
                    u8 *h = D_001A4BE0;
                    func_L01_004468C8(self, 0, 1.1f, S32(st, 0x230) == S32(h, 0x25C0) ? 1 : 0x10001, 9.0f, 1.5f, 0, 1, 0);
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
        if (S16(st, 0x234) != 1) {
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
            if (self[0x43] != 5) {
                func_003C3A10(self, 5, 0, 2);
            }
            {
                s32 n8;
                BURST_0039F2C0(v, a, b, c, n);
            }
        }
        r8 = func_L01_00454370(self, st + 0x160);
        if ((r8 & 1) || F32(st, 0x30) <= 0.0f) {
            func_L01_004450F0(self, 9, -1);
            break;
        }
        if (r8 & 2) {
            *(q_0039F2C0 *)&v = 0;
            v.z = 1.0f;
            if (func_0038CE68(self + 0xE0, &v) < 0.7f) {
                {
                    s32 n8;
                    BURST_0039F2C0(a, b, c, n, w);
                }
                S32(self, 0x98) = 0;
                U16(self, 0x34) = (U16(self, 0x34) | 0x41) & ~0x1000;
                func_L01_004AA7E8(self, 1);
                func_L01_004450F0(self, 2, 0);
            } else {
                func_L01_004450F0(self, 6, 0);
            }
        }
        break;
    case 9:
        func_L28_003A0B60(self);
        v = *(V4_0039F2C0 *)(self + 0xE0);
        for (i = 0; i < D_L28_001DE118; i++) {
            func_0038CF68(&a, &v, func_003824E0(D_L28_001DE128, D_L28_001DE12C) * 0.020000001f);
            func_003C4C18(&a, D_L28_001DE13C * 0.020000001f);
            func_0038CF68(&b, &v, D_L28_001DE11C);
            vec_add_ab(&b, &b, self + 0x10);
            func_003C4C18(&b, D_L28_001DE138);
            f9 = func_003824E0(D_L28_001DE130, D_L28_001DE134) * 210000.0f;
            func_L01_004739D8(&b, &a, D_L28_001DE120, D_L28_001DE124, FRAMES(func_00382498(0x78, 0xF0)), 0, f9);
        }
        for (j = 0; j < D_L28_001DE0CC; j++) {
            f32 ang, r, z;
            a = *(V4_0039F2C0 *)(self + 0x10);
            func_003C4C18(&a, D_L28_001DE0D4);
            ang = func_00382538();
            r = func_003824E0(D_L28_001DE0E0, D_L28_001DE0E4);
            z = func_003824E0(D_L28_001DE0E8, D_L28_001DE0EC);
            qzero(&b);
            b.x += func_0038D098(ang) * (r * 0.020000001f);
            b.y += func_0038D0B0(ang) * (r * 0.020000001f);
            b.z += z * 0.020000001f;
            c = b;
            c.z -= D_L28_001DE0F0 * 0.00040000002f * (f32)FRAMES(D_L28_001DE110);
            for (k = 0; k < D_L28_001DE0D0; k++) {
                f32 s, g;
                s32 c1, c2;
                s = func_003824E0(0.5f, 1.5f);
                b.w = s * D_L28_001DE0F4;
                c.w = s * D_L28_001DE0F8;
                func_003C4C18(&a, D_L28_001DE0D8);
                func_003C4C18(&c, D_L28_001DE0DC * 0.020000001f);
                c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DE0FC, D_L28_001DE104);
                c2 = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L28_001DE100, D_L28_001DE108);
                g = (f32)D_L28_001DE114;
                g = func_003824E0(g * 0.5f, g * 2.5f);
                func_L01_00463378(&a, &b, &c, c1, c2, FRAMES(D_L28_001DE10C), FRAMES(D_L28_001DE110),
                                  (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
            }
        }
        func_003C2880(self);
        return;
    }
    func_L28_003A0DC0(self);
}
/* localdecomp:end func_L28_0039F2C0 */

/* localdecomp:start func_L28_003A0708 */
extern s32 func_L28_003A0930(void *);
extern void func_003C2880(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L28_003A0EC0(u8 *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L28_003A0B60(u8 *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_003A0708(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 t;
    if (a0[0x20] == 0) {
        if (func_L28_003A0930(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x2D8) - 200.0f) {
        func_003C2880(a0);
        return 1;
    }
    if (func_L01_00452FB0(a0, st + 0x160, 0, 0, 0) != 0) func_L28_003A0EC0(a0);
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_003A0B60(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_003A0708 */

/* localdecomp:start func_L28_003A0930 */
typedef int u128_003A0930 __attribute__((mode(TI)));
extern f32 D_L28_001DE040;
extern f32 D_L28_001DE044;
extern u8 D_L28_001DE070;
__asm__(".extern D_L28_001DE040, 4");
__asm__(".extern D_L28_001DE044, 4");
__asm__(".extern D_L28_001DE070, 1");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);
s32 func_L28_003A0930(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_003A0930 *)(st + 0x2D0) = *(u128_003A0930 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x2F0) = -1;
        *(s32 *)(st + 0x2F8) = -1;
    }
    a0[0x23] = 0x70;
    *(u16 *)(a0 + 0x34) |= 0x2100;
    *(s32 *)(a0 + 0xB8) = 0;
    st[0x170] = 8;
    st[0x1DB] = 0xFF;
    st[0x1A8] = 1;
    st[0x1D7] = 1;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    fa = D_L28_001DE044 * 0.00040000002f;
    fb = D_L28_001DE040 * 0.020000001f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x19C) = 0.15000001f;
    *(f32 *)(st + 0x78) = 2.0f;
    *(f32 *)(st + 0x194) = 0.5f;
    *(f32 *)(st + 0x70) = 1.0f;
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
    st[0x39] = D_L28_001DE070;
    st[0x3E] = 1;
    st[0x3F] = 0;
    func_L01_004450F0(a0, 3, -1);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x2F0) != -1 || *(unsigned long *)(st + 0x2F8) != 0xFFFFFFFFUL) {
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    func_003C7DD8(a0);
    return 0;
}
/* localdecomp:end func_L28_003A0930 */

/* localdecomp:start func_L28_003A0B60 */
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L28_0039EBC8(void *);
extern void func_L01_004443E8(u8 *, s32, s32);
typedef int q_003A0B60 __attribute__((mode(TI)));
static __inline__ void spawn_003A0B60(u8 *self, u8 *st, f32 side, f32 up) {
    vu0_v4 a, b;
    u8 *m;
    u8 *d;
    m = func_003C24B0(0x1B5E, 0x200);
    if (m != 0) {
        func_L01_00456160(m, self);
        *(u16 *)(m + 0x34) |= 0x20;
        func_L01_0044A7D0(m);
        d = *(u8 **)(m + 0x68);
        *(s32 *)(d + 0x190) = *(s32 *)(st + 0x2C0);
        *(s32 *)(d + 0x198) = *(s32 *)(st + 0x2C8);
        *(f32 *)(d + 0x19C) = *(f32 *)(st + 0x2CC);
        *(f32 *)(d + 0x194) = *(f32 *)(st + 0x2C4);
        *(u8 **)(d + 0x1C) = d + 0x70;
        *(u8 **)(d + 0xC) = d + 0x160;
        *(u8 **)(d + 0x0) = d + 0x30;
        *(s16 *)(d + 0x36) = 0x1E;
        *(s32 *)(d + 0x1CC) = 2;
        func_0038CF68(&a, self + 0xD0, side);
        vec_add_ab(m + 0x10, &a, self + 0x10);
        func_0038CF68(&b, self + 0xE0, up);
        vec_add_ab(m + 0x10, &b, m + 0x10);
        *(q_003A0B60 *)(m + 0xC0) = *(q_003A0B60 *)(self + 0xC0);
        *(q_003A0B60 *)(m + 0xD0) = *(q_003A0B60 *)(self + 0xD0);
        *(q_003A0B60 *)(m + 0xE0) = *(q_003A0B60 *)(self + 0xE0);
        *(s16 *)(m + 0xB6) = 0xA;
        func_L28_0039EBC8(m);
    }
}
void func_L28_003A0B60(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    func_003A52A0(0, 0, self);
    func_003A52A0(1, 0, self);
    spawn_003A0B60(self, st, 0.7f, 0.4f);
    spawn_003A0B60(self, st, -0.7f, 0.3f);
    func_L01_004443E8(self, 0, 3);
    *(u16 *)(self + 0x34) &= 0xFFDF;
}
/* localdecomp:end func_L28_003A0B60 */

/* localdecomp:start func_L28_003A0DC0 */
extern u8 D_L28_001E1540[];
extern void func_L01_00404808(void *, void *);
extern void func_L08_003A16C8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, u32);
void func_L28_003A0DC0(u8 *a0) {
    u8 *d = *(u8 **)(a0 + 0x68);
    f32 t;
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE) *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x20] != 1 && a0[0x31] != 0) func_L01_00404808(func_L08_003A16C8, a0);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L28_001E1540, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    t = func_0038DAB8(*(f32 *)(d + 0x30C), 0.15358898f);
    *(f32 *)(d + 0x30C) = t;
    *(s32 *)(a0 + 0x78) = func_0038DBD8((func_0038D0B0(t) + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L28_003A0DC0 */

/* localdecomp:start func_L28_003A0EC0 */
extern u16 *D_L28_0021B6A0[];
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_L28_001DECD8;

void func_L28_003A0EC0(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L28_0021B6A0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L28_001DECD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L28_0021B6A0[a0[0x21]])) {
        e = D_L28_001DEC9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x300) = 1;
        }
    }
}
/* localdecomp:end func_L28_003A0EC0 */
