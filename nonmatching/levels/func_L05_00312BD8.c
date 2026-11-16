/* NTSC-U draft (Claude wave C4): C of func_L05_003128A0, the NTSC-U twin of func_L05_00312BD8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L05_003128A0", whose code is not the PAL one).
 * Worker's note: flags: needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (vec_sub_ba; three lui/ori/mtc1 0.017453292f constants); the PAL file L05_00312BD8.c has plain STD, so it cannot land as is. With them 351/351 words and 95 words differ ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003128A0 */
/* func_L05_003128A0: update of a trigger/emitter object (state at +0x68): activation test, spawn of an
   effect object (func_L01_003F08D8, fields copied from the state), follow of the path nodes
   D_L05_0021EE00[] with the camera/listener calls, position updates of the effect. Written from the
   retail assembly (C4 w02 fork F4).
   Build needs "-mvu0-use-vf0-vf2 ... @ps2as" (vec_sub_ba; the 0.017453292f constants are lui/ori/mtc1).
   Not matched: the global allocator gives st the $s1 and near the $s2 of retail ($s2 / $s1); with those two
   forced ('register ... asm') 32 aligned words differ (init-block store order is found, f14 select, gp/lui
   forms of D_001DFD00 are in; left: the -1 constant in $a0 instead of $a2, the base load before the
   index shift in the L458 arm, node/np registers). */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

extern u8 D_001A4C60[];
extern u8 *D_001DFD00_sda;
__asm__(".extern D_001DFD00_sda, 4");
extern u8 *D_L05_001DFD00;
extern u8 *D_L05_0021EE00[];
extern u8 D_L05_001E2700_003128A0[];
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern void func_L01_003F0980(s32, void *);
extern u8 *func_L01_003F08D8(s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003E94A0(s32, void *);
extern void func_L01_003E9510(s32, void *);
extern s32 func_L05_003E3C38(s32);
extern void func_L05_003E3DD8(s32, s32, s32);
extern void func_L01_003E9730(s32, s32);
extern s32 func_003894E8(void *, f32);

void func_L05_003128A0(u8 *o) {
    V4 loc0;
    V4 loc10;
    u8 *st;
    u8 *p0;
    u8 *q;
    u8 *pt;
    u8 *node;
    u8 *np;
    s32 near;
    s32 ok;
    f32 f;

    st = *(u8 **)(o + 0x68);
    ok = 1;
    near = func_0037E0F0(D_001A4C60, *(s32 *)(st + 0x10), 0);
    if (*(s32 *)st == -1 && *(s32 *)(st + 4) == -1 && *(s32 *)(st + 8) == -1) {
        if (*(s32 *)(st + 0xC) == -1) {
            ok = 0;
        }
    }
    if (*(s32 *)st != -1 && func_L01_00442998(*(s32 *)st, -1, 0) != 0) {
        ok = 0;
    }
    if (*(s32 *)(st + 4) != -1 && func_L01_00442998(*(s32 *)(st + 4), -1, 0) != 0) {
        ok = 0;
    }
    if (*(s32 *)(st + 8) != -1 && func_L01_00442998(*(s32 *)(st + 8), -1, 0) != 0) {
        ok = 0;
    }
    if (*(s32 *)(st + 0xC) != -1 && func_L01_00442998(*(s32 *)(st + 0xC), -1, 0) != 0) {
        ok = 0;
    }
    if (o[0x20] != 0) {
        p0 = *(u8 **)(st + 0x14);
        if (p0 != 0) {
            if (near == 0 || ok != 0) {
                func_L01_003F0980(0, p0);
                *(s32 *)(st + 0x14) = 0;
                goto tail;
            }
        } else if (near == 0) {
            goto l404;
        } else if (ok == 0 && *(s32 *)(st + 0x38) == -1) {
            q = func_L01_003F08D8(0, st[0x33]);
            *(u8 **)(st + 0x14) = q;
            if (q == 0) {
                return;
            }
            *(f32 *)q = *(f32 *)(st + 0x18);
            f = *(f32 *)(st + 0x1C);
            if (f != -1.0f) {
                f = f * 0.017453292f;
            }
            *(f32 *)(q + 0xC) = f;
            *(f32 *)(q + 4) = *(f32 *)(st + 0x20);
            *(f32 *)(q + 8) = *(f32 *)(st + 0x24);
            if (st[0x45] == 0) {
                *(f32 *)(q + 0x14) = *(f32 *)(st + 0x28);
            } else {
                *(f32 *)(q + 0x14) = -1.0f;
            }
            f = *(f32 *)(st + 0x2C);
            if (f != -1.0f) {
                f = f * 0.017453292f;
            }
            *(f32 *)(q + 0x10) = f;
            *(u16 *)(q + 0x1A) = st[0x30];
            q[0x1E] = st[0x31];
            q[0x1F] = st[0x32];
            q[0x18] = st[0x46];
            if (*(s32 *)(st + 0x40) != -1) {
                *(s32 *)(q + 0x34) = *(s32 *)(st + 0x40);
            }
            if (*(s32 *)(st + 0x34) == -1) {
                goto tail;
            }
            if (st[0x49] != 0) {
                *(u128_t *)(q + 0x20) = *(u128_t *)(D_001DFD00_sda + (*(s32 *)(st + 0x34) << 7));
                goto tail;
            }
            vec_sub_ba(&loc10, D_001DFD00_sda + (*(s32 *)(st + 0x34) << 7) + 0x30, D_001A4C60);
            *(u128_t *)&loc0 = *(u128_t *)&loc10;
            *(u128_t *)(q + 0x20) = *(u128_t *)&loc0;
            goto tail;
        }
        if (near != 0 && *(s32 *)(st + 0x3C) == 0 && *(s32 *)(st + 0x38) != -1) {
            node = D_L05_0021EE00[*(s32 *)(st + 0x38)];
            *(u128_t *)&loc0 = *(u128_t *)D_001A4C60;
            loc0.z = loc0.z + 1.25f;
            np = node + 0x10;
            loc10.z = func_00388A28(loc0.x - *(f32 *)(node + 0x10), loc0.y - *(f32 *)(node + 0x14));
            loc10.y = -func_00388A28(func_00388800(np, &loc0), loc0.z - *(f32 *)(node + 0x18));
            loc10.x = 0.0f;
            func_L01_003E9588(0, D_L05_001E2700_003128A0, D_L05_001E2700_003128A0 + 0x10, 3, 0x78, 0);
            func_L01_003E94A0(0, np);
            func_L01_003E9510(0, &loc10);
            *(s32 *)(st + 0x3C) = 1;
            goto tail;
        }
        if (near != 0) {
            if (*(s32 *)(st + 0x3C) == 0) {
                goto l41c;
            }
            if (*(s32 *)(st + 0x3C) == 1) {
                if (func_L05_003E3C38(0) & 1) {
                    *(s32 *)(st + 0x3C) = 2;
                    func_L05_003E3DD8(0, 1, 0);
                }
            }
            node = D_L05_0021EE00[*(s32 *)(st + 0x38)];
            *(u128_t *)&loc0 = *(u128_t *)D_001A4C60;
            loc0.z = loc0.z + 1.25f;
            np = node + 0x10;
            loc10.z = func_00388A28(loc0.x - *(f32 *)(node + 0x10), loc0.y - *(f32 *)(node + 0x14));
            loc10.y = -func_00388A28(func_00388800(np, &loc0), loc0.z - *(f32 *)(node + 0x18));
            loc10.x = 0.0f;
            func_L01_003E94A0(0, np);
            func_L01_003E9510(0, &loc10);
            goto tail;
        }
    l404:
        if (*(s32 *)(st + 0x3C) != 0) {
            func_L01_003E9730(0, 1);
            *(s32 *)(st + 0x3C) = 0;
            goto tail;
        }
    l41c:
        if (p0 == 0) {
            return;
        }
        if (*(s32 *)(st + 0x34) != -1) {
            if (st[0x49] != 0) {
                *(u128_t *)(p0 + 0x20) = *(u128_t *)(D_001DFD00_sda + (*(s32 *)(st + 0x34) << 7));
            } else {
                vec_sub_ba(&loc10, D_L05_001DFD00 + (*(s32 *)(st + 0x34) << 7) + 0x30, D_001A4C60);
                *(u128_t *)&loc0 = *(u128_t *)&loc10;
                *(u128_t *)(p0 + 0x20) = *(u128_t *)&loc0;
            }
        }
    tail:
        pt = *(u8 **)(st + 0x14);
        if (pt != 0) {
            if (st[0x47] == 0) {
                if (*(s32 *)(st + 0x34) != -1) {
                    *(u128_t *)&loc0 = *(u128_t *)(D_001DFD00_sda + (*(s32 *)(st + 0x34) << 7) + 0x30);
                    loc0.w = 1.0f;
                    if (func_003894E8(&loc0, 255.0f) != -1) {
                        st[0x47] = 1;
                        if (st[0x45] != 0) {
                            *(f32 *)(*(u8 **)(st + 0x14) + 0x14) = *(f32 *)(st + 0x28);
                        }
                        if (st[0x44] != 0) {
                            (*(u8 **)(st + 0x14))[0x1F] = 0;
                            (*(u8 **)(st + 0x14))[0x1E] = 0;
                        }
                        if (st[0x48] != 0) {
                            (*(u8 **)(st + 0x14))[0x18] = 1;
                        }
                    }
                }
            }
            *(f32 *)(pt + 0x10) = *(f32 *)(st + 0x2C) * 0.017453292f;
        }
    } else {
        *(s32 *)(st + 0x14) = 0;
        *(s32 *)(st + 0x3C) = 0;
        st[0x47] = 0;
        o[0x20] = 1;
        o[0x30] = 0xFF;
    }
}
/* localdecomp:end func_L05_003128A0 */
