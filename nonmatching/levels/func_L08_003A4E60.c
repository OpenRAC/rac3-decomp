/* func_L08_003A4E60 (Aquatos boss state machine, 8420 bytes, level 08): near miss, 58 of 2105
   instructions differ when aligned (c3, 2026-11-14; was 249). Needs "-mvu0-use-vf0-vf2 ... @ps2as"
   on src/levels/08_aquatos/L08_003A4E60.c (already @ps2as). Two of the 58 are the jump table's
   %hi/%lo (masked by check.py).
   What closed rows: the record lookup as an inline function returning a pointer value (rec_of; base
   first in the addu), but array-index form for the case-6 loop condition and list access (that is what
   lets GCSE carry the base load into the loop top); case 6 as a for loop, its first record in its own
   variable (q0) and the loop's in another (q6); every st+0x2F0 / a+0x10 / st+0x220 written inline
   (no pos/tgt locals, lessons 14); float params moved inside the 3303B8/00446780/00464EC8/004468C8
   prototypes; AF78/00446780/0045BD10/00464EC8/004468C8 return s32; the gp float D_L08_001DE298 with
   .extern size 4; ok = 1 as the 0x21 == 0xFF arm; separate full tails for the state-11/14 arms.
   Left:
   - case 3: the constant set-up for func_L01_0044AF78 / func_L01_003303B8 (~33 rows): sched1/local-alloc
     order of the stack-arg constants; prototype float positions and return types exhausted;
   - case 7 top: retail sets the loop counter (s7 = 2) after the first func_0038CF68 and a+0x10 (fp)
     after the second, ours the other way round; st+0x220's spill slot store lands one call later;
   - case 7 second loop: retail counter $s2 / table base $s3, ours $s7 / $s2 (a separate counter
     variable spills the first loop's counter instead);
   - the case-6 loop test computes base + idx*0x30 with the base first in retail (2 rows). */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union { f32 f[4]; s32 i[4]; u128_t q; } __attribute__((aligned(16))) V4;

extern u8 *D_L08_001DF21C;
extern u8 *D_L08_001DF300;
extern u8 *D_L08_001DEECC;
extern f32 D_L08_001DE298;
__asm__(".extern D_L08_001DE298, 4");
extern u8 *D_L08_0021EB18[];
extern s32 D_001A71A0[];
extern char D_L08_001D66B0[] __attribute__((section(".sdata")));

extern s32 func_L08_003A7138(u8 *);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_00456250();
extern f32 *func_00382348(void *);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern s32 func_L01_00454370(u8 *, void *);
extern void func_L08_003A76C8(u8 *);
extern void func_003C2F58(u8 *, s32, void *);
extern void func_003C2EC0(u8 *, s32, void *);
extern s32 func_L01_0044AF78(u8 *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32  func_L01_003303B8(void *, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(u8 *);
extern void func_L08_003A6F48();
extern void func_L08_003A7750(u8 *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045BD78(f32, f32, f32, f32, u8 *);
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

    if (func_L08_003A7138(a) != 0) goto kill;

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
            func_L01_0044AF78(a, D_L08_001D66B0, &v90, 10, 0, 0x10, -1, 0, 9, -1, 0, 0x1010001,
                              0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 1.0f, 0.0f);
            func_L01_003303B8(&v90, 0, 0x19, 0x14, 1.25f, 0.0f, 0.0f, 2.0f, 0x14, 0x14, 0x19, 0, 0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003A52A0(0, 0, a);
        kill:
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
            func_L01_0045BD78(0.004f, 0.080000006f, 0.0018151426f, 0.12566371f, a);
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
            func_L01_0045BD78(0.0096f, 0.22500001f, 0.010053097f, 0.25132743f, a);
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
            func_L01_0045BD78(0.004f, 0.040000003f, 0.010053097f, 0.25132743f, a);
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
        for (n = 2; n >= 0; n--) {
            func_003C4C18(&vE0, 0.1f);
            func_003C4C18(&v130, 0.02f);
            r = func_003824E0(0.4f, 0.6f) * 210000.0f;
            r2 = func_003824E0(1.0f, 1.5f) * 210000.0f;
            func_L01_0046FB40(&vE0, &v130, 8, 0x808080, 0x1E, 0x7F, 0x20, 0, r, r2, func_L01_00443A18(0.0f, 0.002f));
        }
        for (n = 2; n >= 0; n--) {
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
            func_L01_0045BD78(0.0064000003f, 0.15f, 0.010053097f, 0.25132743f, a);
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
            func_L01_0045BD78(0.0064000003f, 0.15f, 0.010053097f, 0.25132743f, a);
            q0 = D_L08_001DF300 + (*REC(st)->list << 7);
            *(u128_t *)(st + 0x2F0) = *(u128_t *)(q0 + 0x30);
            *(u8 **)(st + 0x34C) = q0;
            for (n2 = 0; n2 < ((R30 *)D_L08_001DEECC)[S32(st, 0x334) + 1].n; n2++) {
                q6 = D_L08_001DF300 + (((R30 *)D_L08_001DEECC)[S32(st, 0x334) + 1].list[n2] << 7);
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
            func_L01_0045BD78(0.0064000003f, 0.15f, 0.010053097f, 0.25132743f, a);
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
            func_L01_0045BD78(0.0064000003f, 0.15f, 0.010053097f, 0.25132743f, a);
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
