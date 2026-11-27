#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x24];
    f32 f24;
} T_003A56E8;
typedef struct {
    u8 p0[0x30];
    f32 f30;
    s16 h34;
    u8 p36[0x3];
    u8 b39;
    u8 p3A[0x4];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 p44[0x14];
    u8 b58;
    u8 p59[0x1];
    u8 b5A;
    u8 p5B[0x15];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 p84[0x18];
    s32 w9C;
    f32 fA0;
    u8 pA4[0x4];
    s32 wA8;
    u8 pAC[0xC4];
    u8 b170;
    u8 b171;
    u8 p172[0x4];
    u8 b176;
    u8 p177[0x19];
    f32 f190;
    f32 f194;
    u8 p198[0x4];
    f32 f19C;
    u8 p1A0[0x8];
    u8 b1A8;
    u8 p1A9[0x2E];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 p1DC[0x100];
    s32 w2DC;
    vu0_v4 v2E0;
    u8 p2F0[0x20];
    f32 f310;
    u8 p314[0x10];
    s32 w324;
    u8 p328[0x4];
    s32 w32C;
    u8 p330[0x1C];
    s32 w34C;
} P_003A56E8;
typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[4];
    T_003A56E8 *p24;
    u8 p28[4];
    f32 f2C;
    u8 p30[4];
    u16 h34;
    u8 p36[0xD];
    u8 b43;
    u8 p44[0x24];
    P_003A56E8 *p68;
    u8 p6C[0x2C];
    s32 w98;
    u8 p9C[0x20];
    u8 bBC;
} M_003A56E8;

/* localdecomp:start func_L08_003A4E60 */
/* Aquatos boss state machine. Notes for the match:
   - the kill path (func_003C2880 + return) is written out both at the top and at the end of state 3:
     with a shared label the explosion_spawn call ends its block early and its stack-argument
     constants are scheduled and allocated differently; jump2's cross-jumping merges the two tails;
   - explosion_spawn (func_L01_003303B8) and blast_pieces_spawn (func_L01_0044AF78) with their real
     prototypes (explosion_spawn returns a pointer, the floats interleaved in blast_pieces_spawn);
   - the state-6 loop test reads the record table as an array member (RT2), which gcc expands as
     base + index, while rec_of() and the loop body's pointer arithmetic give index + base. */
typedef int u128_t __attribute__((mode(TI)));
typedef union { f32 f[4]; s32 i[4]; u128_t q; } __attribute__((aligned(16))) V4;

extern u8 *D_L08_001DF21C;
extern u8 *D_L08_001DF300;
extern u8 *D_L08_001DEECC;
extern f32 D_L08_001DE298;
__asm__(".extern D_L08_001DE298, 4");
extern u8 *D_L08_0021EB18[];
extern s32 D_001A71A0[];
extern u8 D_L08_001D66B0[8];

extern s32 func_L08_003A7138();
extern s32 func_L01_004561E0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_00456250();
extern f32 *func_00382348(void *);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern s32 func_L01_00454370(u8 *, void *);
extern void func_L08_003A76C8(void *m);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(u8 *, s32, void *);
extern void func_L01_0044AF78(u8 *owner, void *direction, f32 *position, f32 radius, f32 damage, s32 sparks,
                       s32 flashes, s32 smoke, f32 glow, f32 white, f32 cutoff, f32 scale, s32 sound,
                       f32 blast, s32 shake, s32 debris, s32 quality, u8 channels, s32 flags);
extern void *func_L01_003303B8(void *pos, s32 notify, s32 w20, s32 w24, s32 w28, s32 w2C, s16 h32, s16 h30,
                        f32 scale, f32 last, f32 f6C, f32 f68,
                        s16 h18, s16 h1C, s16 h1A, s16 h1E, s16 h16, s16 h3C, s32 w64, s32 owner,
                        s32 u0, s32 u1, s32 u2, s32 u3, s32 u4, s32 u5,
                        s32 w58, s32 w5C, s32 w60, s16 h36);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_L08_003A6F48();
extern void func_L08_003A7750(void *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045A748(u8 *, void *);
extern void func_L01_0045A898(f32, u8 *, void *);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_0045BDE8(u8 *, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_00446780(u8 *, void *, f32, s32, f32, f32, s32, s32, s32);
extern void func_003C4C18(void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_0045BD10(u8 *, f32);
extern void func_L02_00431568(u8 *, void *, s32, f32, f32, f32, f32);
extern f32 func_003C3D30(f32, void *, s32, s32);
extern void func_003C4138(void *, f32, f32);
extern s32 func_L01_0044E1B8(f32, u8 *);
extern void func_L08_00311438(u8 *, void *, void *, s32, s32, f32);
extern s32 func_L01_00464EC8(void *, void *, f32, s32);
extern s32 func_L01_004468C8(f32, f32, f32, u8 *, s32, s32, s32, s32, s32);

#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)
#define P8(p, o) (((struct { u8 _p[o]; u8 *v; } *)(p))->v)
#define Q(p, o) (((struct { u8 _p[o]; u128_t v; } *)(p))->v)
typedef struct { s16 a; s16 n; u8 p[0xC]; s32 *list; u8 q[0x1C]; } R30;
static inline R30 *rec_of(u8 *st) { return (R30 *)D_L08_001DEECC + S32(st, 0x334) + 1; }
#define REC(st) rec_of(st)
typedef struct { R30 r0; R30 r[1]; } RT2;

static inline void restore_flags(u8 *a) {
    u8 *m = *(u8 **)(a + 0x24);
    U16(a, 0x34) &= ~0x41;
    U16(a, 0x34) |= U16(m, 0x44) & 0x1000;
    S32(a, 0x98) = S32(m, 0x10);
}

void func_L08_003A4E60(u8 *a) {
    V4 v90;
    V4 m[4];
    V4 vE0;
    V4 vF0;
    V4 v100;
    V4 v110;
    V4 v120;
    V4 v130;
    V4 v140;
    u8 *st = *(u8 **)(a + 0x68);
    s32 ok;
    s32 ok0;
    s32 t;
    s32 n2, n;
    u8 *p;
    u8 *q, *q0, *q6;
    u8 *e;
    u8 *rot;
    f32 ang, r, r2, d;

    if (func_L08_003A7138(a) != 0) {
        func_003C2880(a);
        return;
    }

    switch (U8(a, 0x95)) {
    case 0:
        if (func_L01_004561E0(a) != 0) {
            S16(st, 0x2D6) = S16(st, 0x34A) != -1 ? (S16(st, 0x34A) * 5 + 2) / 6 : (func_00382498(0, 40) * 5 + 2) / 6;
        }
        if (S32(st, 0x318) == -1) {
            ok0 = 1;
        } else {
            ok0 = func_L01_00456250(D_L08_001DF21C + (S32(st, 0x318) << 8)) != 0;
        }
        if (S32(st, 0x320) != -1) {
            u8 *o = D_L08_001DF21C + (S32(st, 0x320) << 8);
            f32 *hp = func_00382348(o);
            if (o == 0 || U8(o, 0x20) == 0xFE || U8(o, 0x20) == 0xFD || (hp != 0 && *hp <= 0.0f)) {
                ok0 = 1;
            } else ok0 = 0;
        }
        if (S16(st, 0x234) == 1 && ok0 && func_0038CB00(st + 0x2D6) != 0) {
            func_L01_004450F0(a, 4, 2);
            if (U8(a, 0x43) != 5) {
                func_003C3A10(a, 5, 0, 8);
            }
            if (S32(st, 0x308) != -1) {
                func_L01_004450F0(a, 3, -1);
            } else if (S32(st, 0x338) == 1) {
                func_L01_004450F0(a, 7, -1);
                if (U8(a, 0x43) != 10) {
                    func_003C3A10(a, 10, 0, 8);
                }
            } else if (REC(st)->n != 0) {
                func_L01_004450F0(a, 6, -1);
            } else if (S32(st, 0x328) != -1) {
                func_L01_004450F0(a, 5, -1);
            }
        } else if (S32(st, 0x2D8) != 0 && func_0038CB00(st + 0x2D6) != 0) {
            func_L01_004450F0(a, 2, 1);
            S32(st, 0x2D8) = 0;
            if (S32(st, 0x2D0) < 250) {
                S32(st, 0x2D0) = (func_00382498(480, 600) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (S16(st, 0x234) == 1) {
            func_L01_004450F0(a, 4, 2);
        } else if (S32(st, 0x2D0) == 0) {
            func_L01_004450F0(a, 1, 0);
        }
        break;
    case 2:
        restore_flags(a);
        if (S16(st, 0x234) != 1 && func_L01_004561E0(a) == 0 && U8(a, 0x20) != 10 && U8(a, 0x20) != 12) {
            if (U8(a, 0x21) != 0xFF) {
                func_L01_00445BE0(U8(a, 0x21), 0);
            }
            if (U8(a, 0x43) != 5) {
                func_003C3A10(a, 5, 0, 8);
            }
            func_L01_004450F0(a, 13, 0);
            S32(st, 0x2D0) = (func_00382498(580, 600) * 5 + 2) / 6;
        }
        break;
    case 3:
        t = func_L01_00454370(a, st + 0x160);
        if (F32(st, 0x30) <= 0.0f) {
            func_L08_003A76C8(a);
            func_003C2F58(a, 2, &v90);
            func_L01_0044AF78(a, D_L08_001D66B0, (f32 *)&v90, 0.0f, 0.0f, 10, 0, 0x10, 0.0f, 0.0f, 9.0f, 1.0f, -1,
                              0.0f, 0, 9, -1, 0, 0x1010001);
            func_L01_003303B8(&v90, 0, 0x19, 0x14, 0x14, 0x14, 0x19, 0, 1.25f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003A52A0(0, 0, a);
            func_003C2880(a);
            return;
        }
        if (t & 2) {
            if (S16(st, 0x234) == 1) {
                func_L01_004450F0(a, 4, 2);
                if (U8(a, 0x43) != 5) {
                    func_003C3A10(a, 5, 0, 8);
                }
                if (S32(st, 0x338) == 1) {
                    func_L01_004450F0(a, 7, -1);
                    if (U8(a, 0x43) != 10) {
                        func_003C3A10(a, 10, 0, 8);
                    }
                } else if (REC(st)->n != 0) {
                    func_L01_004450F0(a, 6, -1);
                } else if (S32(st, 0x328) != -1) {
                    func_L01_004450F0(a, 5, -1);
                }
            } else {
                func_L01_004450F0(a, 2, 1);
                S32(st, 0x2D0) = (func_00382498(580, 600) * 5 + 2) / 6;
            }
        }
        break;
    }

    switch (U8(a, 0x20)) {
    case 1:
        if ((U8(a, 0x60) & 2) && S32(st, 0x2DC) == 0) {
            if (U8(a, 0x43) != 5) {
                func_003C3A10(a, 5, 0, 8);
            }
            func_L01_004450F0(a, 13, -1);
        }
        break;
    case 13:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            ang = func_00382538();
            r = func_003824E0(4.0f, 8.0f);
            qzero(st + 0x2F0);
            F32(st, 0x2F0) = func_0038D098(ang) * r;
            F32(st, 0x2F4) = func_0038D0B0(ang) * r;
            vec_add_ab(st + 0x2F0, st + 0x2F0, st + 0x2E0);
            if (S32(st, 0x30C) != -1 && func_L01_00456500((st + 0x2F0), S32(st, 0x30C)) == 0) {
                Q(st, 0x2F0) = Q(st, 0x2E0);
            }
            S32(st, 0x304) = func_00382498(300, 530);
            func_L01_0045BD78(a, 0.004f, 0.080000006f, 0.0018151426f, 0.12566371f);
        }
        if (S32(st, 0x3D0) != 0) {
            func_L01_0045A748(a, (st + 0x2F0));
        } else {
            func_L01_0045A898(F32(a, 0xF8), a, (st + 0x2F0));
            rot = a + 0xF8;
            func_L01_00448890(rot, func_0038D160(F32(st, 0x2F0) - F32(a, 0x10), F32(st, 0x2F4) - F32(a, 0x14)),
                              0.0018151426f, 0.0018151426f, 0.020943953f, st + 0x300, 0);
        }
        if (func_0038CF38(a + 0x10, (st + 0x2F0)) < 0.75f) {
            ang = func_00382538();
            r = func_003824E0(2.0f, 6.0f);
            qzero(st + 0x2F0);
            F32(st, 0x2F0) = func_0038D098(ang) * r;
            F32(st, 0x2F4) = func_0038D0B0(ang) * r;
            vec_add_ab(st + 0x2F0, st + 0x2F0, st + 0x2E0);
            if (S32(st, 0x30C) != -1 && func_L01_00456500((st + 0x2F0), S32(st, 0x30C)) == 0) {
                Q(st, 0x2F0) = Q(st, 0x2E0);
            }
        }
        if (func_0038CAD0(st + 0x304) != 0) {
            if (U8(a, 0x43) != 1) {
                func_003C3A10(a, 1, 0, 8);
            }
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            S32(st, 0xA8) |= 0x400;
            func_L01_0045BD78(a, 0.0096f, 0.22500001f, 0.010053097f, 0.25132743f);
        }
        if (func_L01_0045BDE8(a, S32(st, 0x308)) != 0
            || (func_0038CF38(a + 0x10, st + 0x220) < 6.0f && S32(st, 0x230) == D_001A71A0[0])) {
            S32(st, 0x308) = -1;
            func_L01_004450F0(a, 4, -1);
            if (REC(st)->n != 0) {
                func_L01_004450F0(a, 6, -1);
            } else if (S32(st, 0x328) != -1) {
                func_L01_004450F0(a, 5, -1);
            }
            if (S32(st, 0x338) == 1) {
                func_L01_004450F0(a, 7, -1);
                if (U8(a, 0x43) != 10) {
                    func_003C3A10(a, 10, 0, 8);
                }
            }
            S32(st, 0xA8) &= ~0x400;
            S32(st, 0xAC) = S32(st, 0x330);
        }
        break;
    case 7:
        if (func_L01_004561B8(a) != 0) {
            func_L01_0045BD78(a, 0.004f, 0.040000003f, 0.010053097f, 0.25132743f);
        }
        func_003C2EC0(a, 0, m);
        {
        V4 *pv = &v90;
        v90.q = m[1].q;
        vE0.q = m[3].q;
        func_0038CF68(&vF0, pv, -0.85f);
        func_0038CF68(&v100, pv, -2.0f);
        func_0038CF68(&v110, pv, -3.5f);
        func_0038CF68(&v120, pv, -7.5f);
        }
        vec_add_ba(&vF0, &vF0, &vE0);
        vec_add_ba(&v100, &v100, &vE0);
        vec_add_ba(&v110, &v110, &vE0);
        vec_add_ab(&v120, &v120, &vE0);
        vF0.f[2] -= 0.1f;
        v100.f[2] -= 0.1f;
        func_0038CF68(&v130, &m[1], -(func_003824E0(20.0f, 25.0f) * 0.020000001f));
        func_L01_00446780(a, &vF0, 0.5f, 0x10001, (f32)U8(st, 0x45), 1.0f, 0, 1, 0);
        func_L01_00446780(a, &v100, 0.75f, 0x10001, (f32)U8(st, 0x45), 1.0f, 0, 1, 0);
        func_L01_00446780(a, &v110, 0.75f, 0x10001, (f32)U8(st, 0x45), 1.0f, 0, 1, 0);
        for (n = 0; n < 3; n++) {
            func_003C4C18(&vE0, 0.1f);
            func_003C4C18(&v130, 0.02f);
            r = func_003824E0(0.4f, 0.6f) * 210000.0f;
            r2 = func_003824E0(1.0f, 1.5f) * 210000.0f;
            func_L01_0046FB40(&vE0, &v130, 8, 0x808080, 0x1E, 0x7F, 0x20, 0, r, r2, func_L01_00443A18(0.0f, 0.002f));
        }
        for (n2 = 2; n2 >= 0; n2--) {
            func_003C4C18(&vE0, 0.1f);
            func_003C4C18(&v130, 0.02f);
            r = func_003824E0(0.4f, 0.6f) * 210000.0f;
            r2 = func_003824E0(1.0f, 1.5f) * 210000.0f;
            e = func_L01_0046FB40(&vE0, &v130, 8, 0x800000, 0x1E, 0x7F, 0x60, 0, r, r2, func_L01_00443A18(0.0f, 0.002f));
            if (e != 0) {
                e[2] = D_L08_0021EB18[0x5C / 4][0];
            }
        }
        if (func_0038CF38((a + 0x10), (st + 0x220)) > 7.0f) {
            func_L01_0045A748(a, (st + 0x220));
        } else if (func_0038CF38((a + 0x10), (st + 0x220)) < 6.0f) {
            v140.f[0] = func_0038D098(func_0038DAB8(F32(a, 0xF8), 3.1415927f)) * 6.0f;
            v140.f[1] = func_0038D0B0(func_0038DAB8(F32(a, 0xF8), 3.1415927f)) * 6.0f;
            v140.i[2] = 0;
            vec_add_ab(&v140, &v140, a + 0x10);
            func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
            func_L02_00431568(a, &v140, 0x10, func_0038D160(v140.f[0] - F32(a, 0x10), v140.f[1] - F32(a, 0x14)), -1.0f, -1.0f, -1.0f);
        }
        break;
    case 4:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            func_L01_0045BD78(a, 0.0064000003f, 0.15f, 0.010053097f, 0.25132743f);
        }
        func_L01_0045A748(a, st + 0x220);
        if (func_0038CF38(a + 0x10, st + 0x220) < 10.0f) {
            func_L01_004450F0(a, 11, -1);
            if (U8(a, 0x43) != 20) {
                func_003C3A10(a, 20, 0, 8);
            }
            if (S16(P8(st, 0x230), 0xAA) == 0x1969 && func_0038CF38(a + 0x10, P8(st, 0x230) + 0x10) < 5.0f) {
                func_L01_004450F0(a, 9, -1);
                if (U8(a, 0x43) != 9) {
                    func_003C3A10(a, 9, 0, 5);
                }
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            func_L01_0045BD78(a, 0.0064000003f, 0.15f, 0.010053097f, 0.25132743f);
            q0 = D_L08_001DF300 + (*REC(st)->list << 7);
            *(u128_t *)(st + 0x2F0) = *(u128_t *)(q0 + 0x30);
            *(u8 **)(st + 0x34C) = q0;
            for (n2 = 0; n2 < ((RT2 *)D_L08_001DEECC)->r[S32(st, 0x334)].n; n2++) {
                q6 = D_L08_001DF300 + (((RT2 *)D_L08_001DEECC)->r[S32(st, 0x334)].list[n2] << 7);
                d = func_0038CF38(q6 + 0x30, st + 0x220);
                if ((func_0038CF38((st + 0x2F0), st + 0x220) < d || func_0038CF38((a + 0x10), (st + 0x2F0)) < 2.0f)
                    && func_0038CF38((a + 0x10), q6 + 0x30) > 2.0f) {
                    Q(st, 0x2F0) = Q(q6, 0x30);
                    P8(st, 0x34C) = q6;
                }
            }
            if (S32(st, 0x340) != 0) {
                func_L01_004450F0(a, 14, -1);
                if (U8(a, 0x43) != 20) {
                    func_003C3A10(a, 20, 0, 8);
                }
            }
        }
        if (fabs_asm(F32(a, 0x18) - F32(st, 0x2F8)) > 0.75f) {
            if (abs_asm(F32(a, 0x18) - func_003C3D30(0.5f, (a + 0x10), 0, 0) > 0.75f)) {
                func_003C4138(a + 0x18, F32(st, 0x2F8), 0.040000003f);
            }
        }
        func_L01_0045A748(a, (st + 0x2F0));
        if (func_0038CF38((a + 0x10), (st + 0x2F0)) < 1.0f) {
            func_L01_004450F0(a, 11, -1);
            if (U8(a, 0x43) != 20) {
                func_003C3A10(a, 20, 0, 8);
            }
        }
        break;
    case 14:
        if (func_L01_004561B8(a) != 0) {
            S16(st, 0x348) = (S32(st, 0x344) * 5 + 2) / 6;
            func_L08_003A6F48(a);
        }
        if (fabs_asm(F32(a, 0x18) - F32(st, 0x2F8)) > 0.75f) {
            if (abs_asm(F32(a, 0x18) - func_003C3D30(0.5f, a + 0x10, 0, 0) > 0.75f)) {
                func_003C4138(a + 0x18, F32(st, 0x2F8), 0.040000003f);
            }
        }
        func_L02_00431568(a, st + 0x2F0, 0x10, func_0038D160(F32(st, 0x2F0) - F32(a, 0x10), F32(st, 0x2F4) - F32(a, 0x14)), -1.0f, -1.0f, -1.0f);
        func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
        if (U8(a, 0x21) == 0xFF) {
            ok = 1;
        } else {
            ok = U8(a, 0xBC) == 0;
        }
        if (func_0038CB00(st + 0x348) != 0 && ok) {
            if (U8(a, 0x21) != 0xFF) {
                func_L01_00445BE0(U8(a, 0x21), 1);
            }
            F32(a, 0x48) = 1.0f;
            func_L01_004450F0(a, 15, -1);
            if (U8(a, 0x43) != 22) {
                func_003C3A10(a, 22, 0, 2);
            }
        }
        if (U8(a, 0x42) == 3 && (U8(a, 0x60) & 2) && U8(a, 0x43) != 20) {
            func_003C3A10(a, 20, 0, 5);
        }
        break;
    case 15:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
        }
        if (fabs_asm(F32(a, 0x18) - F32(st, 0x2F8)) > 0.75f) {
            if (abs_asm(F32(a, 0x18) - func_003C3D30(0.5f, a + 0x10, 0, 0) > 0.75f)) {
                func_003C4138(a + 0x18, F32(st, 0x2F8), 0.040000003f);
            }
        }
        func_L02_00431568(a, (st + 0x2F0), 0x10, func_0038D160(F32(st, 0x2F0) - F32(a, 0x10), F32(st, 0x2F4) - F32(a, 0x14)), -1.0f, -1.0f, -1.0f);
        func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
        if (func_L01_0044E1B8(1.0f, a) != 0 && U8(a, 0x42) == 22) {
            func_003C2F58(a, 0, m);
            vec_sub_ab(&v90, st + 0x220, m);
            func_0038CF68(&v90, &v90, D_L08_001DE298 * 0.020000001f);
            func_L08_00311438(a, &v90, m, 0, 0, (f32)U8(st, 0x44));
        }
        if (U8(a, 0x60) & 2) {
            if (U8(a, 0x21) != 0xFF) {
                func_L01_00445BE0(U8(a, 0x21), 0);
            }
            if (func_0038CF38(a + 0x10, (st + 0x2F0)) < 1.0f) {
                func_L01_004450F0(a, 11, -1);
                if (U8(a, 0x43) != 20) {
                    func_003C3A10(a, 20, 0, 8);
                }
            } else {
                func_L01_004450F0(a, 14, -1);
                if (U8(a, 0x43) != 20) {
                    func_003C3A10(a, 20, 0, 8);
                }
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            func_L01_0045BD78(a, 0.0064000003f, 0.15f, 0.010053097f, 0.25132743f);
        }
        p = D_L08_001DF300 + (S32(st, 0x328) << 7) + 0x30;
        func_L01_0045A748(a, p);
        if (func_0038CF38(a + 0x10, p) < 1.0f) {
            func_L01_004450F0(a, 11, -1);
            if (U8(a, 0x43) != 20) {
                func_003C3A10(a, 20, 0, 8);
            }
            if (S16(P8(st, 0x230), 0xAA) == 0x1969 && func_0038CF38(a + 0x10, P8(st, 0x230) + 0x10) < 5.0f) {
                func_L01_004450F0(a, 9, -1);
                if (U8(a, 0x43) != 9) {
                    func_003C3A10(a, 9, 0, 5);
                }
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            func_L01_0045BD78(a, 0.0064000003f, 0.15f, 0.010053097f, 0.25132743f);
        }
        v90.f[0] = func_0038D098(func_0038DAB8(F32(a, 0xF8), 3.1415927f)) * 6.0f;
        v90.f[1] = func_0038D0B0(func_0038DAB8(F32(a, 0xF8), 3.1415927f)) * 6.0f;
        v90.i[2] = 0;
        vec_add_ab(&v90, &v90, a + 0x10);
        func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
        func_L02_00431568(a, &v90, 0x10, func_0038D160(v90.f[0] - F32(a, 0x10), v90.f[1] - F32(a, 0x14)), -1.0f, -1.0f, -1.0f);
        if (func_0038CF38(a + 0x10, st + 0x220) > 6.0f || U16(a, 0x96) >= 0x97 || S32(st, 0xF0) >= 5) {
            func_L01_004450F0(a, 11, -1);
            if (U8(a, 0x43) != 20) {
                func_003C3A10(a, 20, 0, 8);
            }
            if (S16(P8(st, 0x230), 0xAA) == 0x1969 && func_0038CF38(a + 0x10, P8(st, 0x230) + 0x10) < 5.0f) {
                func_L01_004450F0(a, 9, -1);
                if (U8(a, 0x43) != 9) {
                    func_003C3A10(a, 9, 0, 5);
                }
            }
        }
        break;
    case 9:
        func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
        if (U8(a, 0x60) & 2) {
            func_L01_004450F0(a, 10, -1);
            if (U8(a, 0x43) != 10) {
                func_003C3A10(a, 10, 0, 2);
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
        }
        func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
        func_003C2EC0(a, 0, m);
        vE0.q = m[1].q;
        func_0038CF68(&vE0, &vE0, -0.16000001f);
        func_003C2F58(a, 0, &v90);
        func_L01_00464EC8(&v90, &vE0, 10.0f, 0);
        func_L01_00464EC8(&v90, &vE0, 10.0f, 0);
        func_L01_004468C8(1.5f, (f32)U8(st, 0x45), 1.5f, a, 0, 0x10001, 0, 1, 0);
        if (U8(a, 0x60) & 2) {
            func_L01_004450F0(a, 8, -1);
            if (U8(a, 0x43) != 8) {
                func_003C3A10(a, 8, 0, 12);
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            S16(st, 0x348) = (S32(st, 0x344) * 5 + 2) / 6;
        }
        if (P8(st, 0x34C) != 0 && fabs_asm(F32(a, 0x18) - F32(P8(st, 0x34C), 0x38)) > 0.75f) {
            if (abs_asm(F32(a, 0x18) - func_003C3D30(0.5f, a + 0x10, 0, 0) > 0.75f)) {
                func_003C4138(a + 0x18, F32(P8(st, 0x34C), 0x38), 0.040000003f);
            }
        }
        if (S32(st, 0x328) != -1) {
            q = D_L08_001DF300 + (S32(st, 0x328) << 7);
            if (fabs_asm(F32(a, 0x18) - F32(q, 0x38)) > 0.5f && fabs_asm(F32(a, 0x18) - F32(q, 0x38)) > 0.75f) {
                if (abs_asm(F32(a, 0x18) - func_003C3D30(0.5f, a + 0x10, 0, 0) > 0.75f)) {
                    func_003C4138(a + 0x18, F32(q, 0x38), 0.040000003f);
                }
            }
        }
        func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
        if (U8(a, 0x21) == 0xFF) {
            ok = 1;
        } else {
            ok = U8(a, 0xBC) == 0;
        }
        if (func_0038CB00(st + 0x348) != 0 && ok) {
            if (U8(a, 0x21) != 0xFF) {
                func_L01_00445BE0(U8(a, 0x21), 1);
            }
            func_L01_004450F0(a, 12, -1);
            if (U8(a, 0x43) != 22) {
                func_003C3A10(a, 22, 0, 2);
            }
        }
        break;
    case 12:
        if (func_L01_004561B8(a) != 0) {
            func_L08_003A6F48(a);
            if (U8(a, 0x43) != 22) {
                func_003C3A10(a, 22, 0, 2);
            }
        }
        if (func_L01_0044E1B8(1.0f, a) != 0 && U8(a, 0x42) == 22) {
            func_003C2F58(a, 0, m);
            vec_sub_ab(&v90, st + 0x220, m);
            func_0038CF68(&v90, &v90, D_L08_001DE298 * 0.020000001f);
            func_L08_00311438(a, &v90, m, 0, 0, 5.0f);
        }
        if (P8(st, 0x34C) != 0) {
            if (fabs_asm(F32(a, 0x18) - F32(P8(st, 0x34C), 0x38)) > 1.5f && fabs_asm(F32(a, 0x18) - F32(P8(st, 0x34C), 0x38)) > 0.75f) {
                if (abs_asm(F32(a, 0x18) - func_003C3D30(0.5f, a + 0x10, 0, 0) > 0.75f)) {
                    func_003C4138(a + 0x18, F32(P8(st, 0x34C), 0x38), 0.040000003f);
                }
            }
        }
        if (S32(st, 0x328) != -1) {
            q = D_L08_001DF300 + (S32(st, 0x328) << 7);
            if (fabs_asm(F32(a, 0x18) - F32(q, 0x38)) > 0.5f && fabs_asm(F32(a, 0x18) - F32(q, 0x38)) > 0.75f) {
                if (abs_asm(F32(a, 0x18) - func_003C3D30(0.5f, a + 0x10, 0, 0) > 0.75f)) {
                    func_003C4138(a + 0x18, F32(q, 0x38), 0.040000003f);
                }
            }
        }
        func_L01_0045BD10(a, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)));
        if (U8(a, 0x60) & 2) {
            if (U8(a, 0x21) != 0xFF) {
                func_L01_00445BE0(U8(a, 0x21), 0);
            }
            func_L01_004450F0(a, 4, -1);
            if (U8(a, 0x43) != 5) {
                func_003C3A10(a, 5, 0, 12);
            }
            if (func_0038CF38((a + 0x10), st + 0x220) < 7.0f) {
                func_L01_004450F0(a, 8, -1);
                if (U8(a, 0x43) != 8) {
                    func_003C3A10(a, 8, 0, 12);
                }
            }
            if (S32(st, 0x328) != -1) {
                if (func_0038CF38((a + 0x10), D_L08_001DF300 + (S32(st, 0x328) << 7) + 0x30) < 1.5f) {
                    func_L01_004450F0(a, 11, -1);
                    if (U8(a, 0x43) != 20) {
                        func_003C3A10(a, 20, 0, 8);
                    }
                } else {
                    if (U8(a, 0x43) != 5) {
                        func_003C3A10(a, 5, 0, 12);
                    }
                    func_L01_004450F0(a, 5, -1);
                }
            }
            if (REC(st)->n != 0) {
                func_L01_004450F0(a, 6, -1);
            }
        }
        break;
    }
    func_L08_003A7750(a);
}
/* localdecomp:end func_L08_003A4E60 */

/* localdecomp:start func_L08_003A6F48 */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x44 - 0x14];
    u16 f44;
} C_003A6F48;
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[3];
    C_003A6F48 *pclass;
    u8 pad28[0x34 - 0x28];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    void *pvar;
    u8 pad6c[0x98 - 0x6C];
    s32 f98;
    u8 pad9c[0xAA - 0x9C];
    s16 oclass;
} M_003A6F48;
typedef struct {
    u8 pad0[0x324];
    s32 f324;
} P_003A6F48;
extern u8 *D_L08_001DF21C;
__asm__(".extern D_L08_001DF21C, 16");
extern s32 D_L08_001DF258;
extern s16 *D_L08_0021BEA0[];
extern void func_003C2880(void *);

void func_L08_003A6F48(M_003A6F48 *a0) {
    P_003A6F48 *p = a0->pvar;
    M_003A6F48 *r;
    s16 *q;

    if (p->f324 != 0xFF) {
        a0->flags &= ~0x41;
        a0->flags |= a0->pclass->f44 & 0x1000;
        a0->f98 = a0->pclass->f10;
        q = D_L08_0021BEA0[p->f324];
        while ((p->f324 & 0xFF) != 0xFF && p->f324 <= D_L08_001DF258 && q != 0 && (q[-1] >= 0 || q == D_L08_0021BEA0[p->f324])) {
            r = (M_003A6F48 *)(D_L08_001DF21C + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            if (r->oclass == 0x1A79 && r->state != 0xFE && r->state != 0xFD) {
                func_L01_003303B8((u8 *)r + 0x10, 0, 25, 20, 20, 20, 25, 0, 1.25f, 0.0f, 0.0f, 2.0f,
                    0, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_003C2880(r);
            }
            q++;
        }
    }
}
/* localdecomp:end func_L08_003A6F48 */

/* localdecomp:start func_L08_003A7138 */
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0x47]; u8 *p68; u8 p6C[0x29]; u8 b95;
} O_003A7138;
typedef struct {
    u8 p0[0x30]; f32 f30; u8 p34[0xA]; u8 b3E; u8 p3F[0x1F]; u8 b5E; u8 b5F;
    u8 p60[0x234 - 0x60]; s16 h234; u8 p236[0x2C0 - 0x236];
    s32 f2C0; f32 f2C4; s32 f2C8; f32 f2CC; u8 p2D0[8]; s32 f2D8; u8 p2DC[0x31C - 0x2DC];
    s32 f31C; u8 p320[0xC]; s32 f32C; u8 p330[0x3D4 - 0x330]; s32 f3D4;
} P_003A7138;
extern f32 D_001A4C60[];
extern s32 func_L08_003A74A8(M_003A56E8 *m);
extern void func_L08_003A76C8(void *m);
extern void func_L08_003A7A50(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L08_003A7138(O_003A7138 *a0) {
    P_003A7138 *p = (P_003A7138 *)a0->p68;
    f32 old;
    if (a0->b20 == 0 && func_L08_003A74A8(a0) != 0) return 1;
    if (p->b3E == 2) {
        func_L08_003A76C8(a0);
        return 1;
    }
    old = p->f30;
    if (func_L01_00452FB0(a0, (u8 *)p + 0x160, 0, 0, 0) != 0) func_L08_003A7A50(a0);
    if (p->f30 < old) {
        p->f2D8 = 1;
        func_L08_003A7A50(a0);
    }
    func_L01_00452860(a0, &p->f30, 0);
    if (p->b5E != 0) {
        func_L08_003A76C8(a0);
        return 1;
    }
    if (func_0038CF38((u8 *)a0 + 0x10, D_001A4C60) < 32.0f) {
        if (p->f31C != -1 && p->h234 != 1 && p->f32C == 0) {
            if (func_L01_00456500(D_001A4C60, p->f31C) != 0) p->f32C = 1;
        }
    }
    if (p->b5F != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 3, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
        else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 3, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
    } else {
        if (p->f3D4 == 0) {
            p->f32C = 1;
            func_L01_00456BD0(a0, 3);
            if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 1, 3, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
            else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 1, 3, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
        } else {
            func_L01_00456BD0(a0, 3);
            if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 1, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
            else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 1, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
        }
        if (p->f2C0 != -1) {
            if (p->f32C == 0) return 0;
            if (func_L01_00456500(D_001A4C60, p->f2C0) != 0) {
                p->f32C = 0;
                return 0;
            }
        }
        if (p->f32C != 0) {
            if (func_0038CF38((u8 *)a0 + 0x10, D_001A4C60) < p->f2C4) p->f32C = 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L08_003A7138 */

/* localdecomp:start func_L08_003A74A8 */
/* PAL port of the NTSC-U match src/us/levels/func_L08_003A56E8.c */
#include "vu0.h"


extern f32 D_L08_001DE29C;
__asm__(".extern D_L08_001DE29C, 4");
extern f32 func_00382538(void);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

s32 func_L08_003A74A8(M_003A56E8 *m) {
    P_003A56E8 *p;

    p = m->p68;
    p->f310 = func_00382538();
    p->w32C = 0;
    p->w34C = 0;
    m->bBC = 0;
    p->b170 = 0x10;
    p->b1A8 = 3;
    p->b171 = 0xE;
    p->f190 = 0.5f;
    p->f194 = 0.5f;
    p->b176 = 0x12;
    p->f19C = 0.15f;
    p->b1D7 = 1;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    p->b1DB = 0xFF;
    p->v2E0 = m->pos;
    p->f74 = 0.5f;
    p->f70 = 1.25f;
    p->w9C = 0;
    p->f78 = 0.5f;
    p->f7C = 1.0f;
    p->f80 = 1.4835298f;
    p->fA0 = 0.34906584f;
    p->wA8 |= 5;
    func_L01_0045BD78(m, 0.0064000003f, 0.15f, 0.010053097f, 0.25132743f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 10;
        p->f30 = 10.0f;
    }
    p->b39 = 1;
    p->b3F = 0;
    p->f40 = 2.0f;
    m->f2C = m->p24->f24 * D_L08_001DE29C;
    p->b3E = 1;
    if (m->b43 != 5) {
        func_003C3A10(m, 5, 0, 8);
    }
    func_L01_004450F0(m, 0xD, -1);
    if (p->w324 != -1) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    if (p->w2DC != 0) {
        func_L01_004450F0(m, 1, 0);
        if (m->b43 != 0) {
            func_003C3A10(m, 0, 0, 8);
        }
    }
    return 0;
}
/* localdecomp:end func_L08_003A74A8 */

/* localdecomp:start func_L08_003A76C8 */
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                   f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *m, s32 a, s32 b);
extern u8 D_L08_001D66B0[8];

void func_L08_003A76C8(void *m) {
    func_L01_00452310(m, 0x1FFF, D_L08_001D66B0, 1, 0x1E, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_L01_004443E8(m, 0, 3);
}
/* localdecomp:end func_L08_003A76C8 */

/* localdecomp:start func_L08_003A7750 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[0x11]; u8 b31; u8 p32[0x10]; u8 b42; u8 p43[0x2C]; u8 b6F;
    u8 p70[0x25]; u8 b95; u16 h96;
} M_003A7750;
typedef struct {
    u8 p0[0x220]; vu0_v4 v220; u8 p230[0x10]; u8 v240[0x90]; s32 w2D0; s32 w2D4; u8 p2D8[0x38];
    f32 f310; f32 f314; u8 p318[0x38]; u8 v350[0x64]; f32 f3B4;
} P_003A7750;
extern s32 D_L08_001DEDC0;
__asm__(".extern D_L08_001DEDC0, 16");
extern u8 D_L08_001E1D40[];
extern f32 D_001DE2A0_sda;
__asm__(".extern D_001DE2A0_sda, 4");
extern f32 D_001DE2A4_sda;
__asm__(".extern D_001DE2A4_sda, 4");
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382498(s32, s32);
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);

void func_L08_003A7750(void *arg) {
    M_003A7750 *m = arg;
    P_003A7750 *p = *(P_003A7750 **)((u8 *)m + 0x68);
    vu0_v4 out;
    vu0_v4 vel;
    vu0_v4 v;
    s32 t;

    func_0038CAD0(&p->w2D0);
    func_0038CB00(&p->w2D4);
    if (m->h96 < 0xFFFF) m->h96++;
    *(vu0_q *)&v = 0;
    v.z = -(func_003824E0(2.5f, 3.5f) * 0.020000001f);
    vel = v;
    func_003C2F58(m, 1, &out);
    out.z -= 0.25f;
    if (D_L08_001DEDC0 & 1) {
        func_L01_004637C8(&out, &vel, 0xCF0000FF, 0xCF, (func_00382498(0x12, 0x16) * 5 + 2) / 6, 0xA0, -10, 1);
    } else {
        func_L01_004637C8(&out, &vel, 0x6000FFFF, 0x80, (func_00382498(0x14, 0x18) * 5 + 2) / 6, 0xD2, -10, 1);
    }
    t = func_00382498(0x14, 0x5A);
    func_L01_004637C8(&out, &vel, 0xEFFF7F4F, 0xFF0000, (func_00382498(0xA, 0xF) * 5 + 2) / 6, t, -t, 1);
    if ((m->b42 == 0x14 || m->b42 == 0x16) && m->b95 == 2) {
        func_003C2F58(m, 3, &v);
        p->f3B4 = -func_0038D160(func_0038CF38(&v, &p->v220), p->v220.z - v.z);
    }
    func_L01_0044E850(m, p->v350, 3, 0.0432f, 0.43200004f);
    func_L01_00451DF8((u8 *)m, p->v240, 4, 1, 2.5f);
    if (m->b31 != 0 && func_L01_0040E548(D_L08_001E1D40, &m->pos) < 576.0f) {
        func_L01_004472C0(m);
        m->b6F = 0x16;
    }
    func_L01_0044EAE0(m, &p->f310, &p->f314, D_001DE2A0_sda, D_001DE2A4_sda * 0.017453292f * 0.020000001f, -1.0f);
}
/* localdecomp:end func_L08_003A7750 */
