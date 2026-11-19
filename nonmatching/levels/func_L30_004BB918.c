/* PAL near miss (Sonnet worker b22-nm13-a, round 13): 14 raw diff (check.py --no-context, levels 30-36 alike), down from the
 * b22-nm5-b draft's 54 raw. Not linked: the file keeps its INCLUDE_ASM marker. Needs the file's line in
 * config/levels/text_parts.txt to be `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` and
 * `func_L30_004BB918 1` in config/levels/divs_nops.txt (neither is committed). The 4 cases of the switch compile to a compare
 * chain (retail has no jump table), so there is nothing extra to check in the full level build.
 *
 * What changed against the earlier draft: only the VU0 tail. It no longer calls vec_copy / vec_add_ba / vec_add_ab. Those load v
 * twice (two asm statements on two lines of vu0.h never merge in cse) and give v the wrong vector register. The tail is now
 * one shared asm load of v (lqc2), the copy's sqc2, plain 128-bit C loads/stores of the two hero slots and of t, and one asm vadd
 * per add. Result: retail's 4 lqc2 (v once, vf1), `vadd vf2,vf2,vf1` (0x4bc110a8) and `vadd vf1,vf1,vf2` (0x4bc20868) are
 * exactly retail's words, `lqc2 v` is the first insn of the tail (so the switch arms' delay slots stay `nop` as in retail),
 * frame 0x60, no spill.
 *
 * What still differs (14 raw, 12 aligned): (1) retail folds the first hero slot into the address, `lui $v0,%hi; lqc2 vf2,%lo($v0)`
 * and `sqc2 vf2,%lo($v0)`, with `addiu $v1,$v0,0x4cd0` only as the base of the second slot; a plain 128-bit load/store cannot
 * fold a %lo() address (it builds `lui; addiu` and uses 0($v1)), an asm "m" operand can, but with asm loads for that slot the
 * registers go back to v in vf2 (see the findings). (2) `li $v0,1` stays in the middle of the tail (retail: last, in the delay
 * slot of `b`, merged by the late cross-jump) and the last sqc2 fills the delay slot of `b` here. (3) the last return path orders
 * `addiu $v0,0x40` before `addiu $v1,$s2,0x4be0` (retail: reversed; no wording of the store changed it: 3 tried).
 * Note: a function-local plain `vu0_q` load of t right after the asm sqc2 into t is not folded by cse (the asm output is opaque).
 */
#include "common.h"

/* localdecomp:start func_L30_004BB918 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

extern u8 D_001A4BE0[];
extern u8 D_00142660[];
extern s32 D_L30_001D6694_004BB918;
extern u8 D_L30_001ED280[];

extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004DFEA0(s32);
extern void func_L01_004E1560(void);
extern void func_L30_004CF4B0(s32, s32);
extern u8 *func_L01_00447490(s32, s32, s32);
extern void func_L01_003F1F20(s32, s32);
extern void func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);

static __inline__ u8 *hero(void) {
    return D_001A4BE0;
}

s32 func_L30_004BB918(s32 a0) {
    u8 *m;
    u8 *r;
    u8 *p;
    s32 flag;
    s32 n;
    f32 f;
    V4 v;
    V4 t;

    if (*(s32 *)(hero() + 0x25CC) == 0x14 || *(s32 *)(hero() + 0x25CC) == 7) {
        return 0;
    }
    if (*(s32 *)(hero() + 0x25C4) == 0x74) {
        return 0;
    }
    if (*(s32 *)(hero() + 0x25C4) == 0x31) {
        return 0;
    }
    if (*(s16 *)(hero() + 0x1DC) != 0) {
        return 0;
    }
    if (D_L30_001D6694_004BB918 != 0) {
        return 0;
    }
    *(s32 *)(hero() + 0x2808) = 0;
    if (*(u8 *)(*(u8 **)(hero() + 0x25C0) + 0xA8) == 0xFF) {
        return 0;
    }
    m = D_L30_001ED280 + *(u8 *)(*(u8 **)(hero() + 0x25C0) + 0xA8) * 64;
    if (*(u8 **)(m + 0x38) != *(u8 **)(hero() + 0x25C0)) {
        return 0;
    }
    if ((*(s32 *)(m + 0x24) & 9) == 0) {
        return 0;
    }
    if (*(s32 *)(hero() + 0x234) != 0) {
        return 0;
    }
    if (*(f32 *)(m + 0x2C) != 0.0f) {
        if (func_L01_0041A4F0() != 0 && *(u8 *)(hero() + 0x25E4) != 5) {
            D_00142660[0x5A] = 0;
            D_00142660[0x5B] = 0;
        }
    }
    f = func_L01_004C93D8();
    if (f != 0.0f && *(u8 *)(hero() + 0x25E4) == 0 && (*(s32 *)(m + 0x24) & 0x20000000) == 0) {
        *(f32 *)(m + 0x2C) = func_L01_004C9360(*(f32 *)(m + 0x2C));
        if (*(f32 *)(m + 0x2C) == 0.0f) {
            return 0;
        }
    }
    if ((*(s32 *)(m + 0x24) & 0x20000000) != 0 && *(u8 *)(hero() + 0x25E4) == 0) {
        s32 x = *(s16 *)(D_00142660 + 0x40);
        if (x > 4) {
            x = 4;
        }
        if (x < 0) {
            x = 0;
        }
        *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) / func_L01_004DFE88(x);
    }
    *(s32 *)(hero() + 0x2808) = *(s32 *)(m + 0x20);
    if (*(s32 *)(hero() + 0x25CC) == 0xF) {
        *(u8 **)(hero() + 0x664) = m;
        *(s16 *)(hero() + 0x62E) = 1;
        return 0;
    }
    if (*(u8 *)(hero() + 0x25E4) == 5 && *(s32 *)(hero() + 0x25CC) == 6 && (*(s32 *)(m + 0x24) & 0x30000) == 0 &&
        *(s32 *)(hero() + 0x1B8) < 0x11) {
        return 0;
    }
    if (a0 != 0) {
        func_L01_004E1560();
        flag = 0;
        if ((*(s32 *)(m + 0x30) & 1) != 0) {
            *(V4 *)&v = *(V4 *)(m + 0x10);
            if (*(f32 *)(m + 0x1C) == 5627.9248f) {
                flag = 1;
            }
        } else if (*(s32 *)(m + 0x20) != 0) {
            vec_sub_ba(&v, D_001A4BE0 + 0x80, *(u8 **)(m + 0x20) + 0x10);
        } else {
            func_L01_005110E8(&v, 0, -1.0f, 0.0f, 0.0f);
        }
        switch (*(u8 *)(hero() + 0x25E4)) {
        case 0:
            p = *(u8 **)(hero() + 0x2808);
            if (p != 0) {
                n = *(s16 *)(p + 0xAA);
                if (n == 0x4EB || n == 0x558 || n == 0x1C5F) {
                    func_L30_004CF4B0(0x82, 1);
                    return 1;
                }
            }
            if (*(s32 *)(hero() + 0x25C4) == 1 || *(s32 *)(hero() + 0x25C4) == 0x1D || *(s32 *)(hero() + 0x16B0) == 2) {
                if ((*(s32 *)(m + 0x24) & 8) == 0) {
                    r = func_L01_00447490(*(s32 *)(hero() + 0x25C0), 1, 0);
                    if (r != 0) {
                        func_L01_004DFEA0((s32) * (f32 *)(r + 0x2C));
                    }
                    if (*(s32 *)(hero() + 0x2850) == 0) {
                        func_L30_004CF4B0(0x16, 1);
                    } else {
                        func_L01_003F1F20(0x12, 0);
                    }
                    *(s16 *)(hero() + 0x1DC) = 0x40;
                    if (*(s16 *)(hero() + 0x21C) == 0) {
                        *(s16 *)(hero() + 0x21C) = 0xF;
                    }
                    func_L01_004F4E70(0x14, 0);
                    return 0;
                }
            }
            if (*(s32 *)(hero() + 0x25CC) == 0x12) {
                func_L30_004CF4B0(0x77, 1);
            } else if (*(s32 *)(hero() + 0x25CC) == 0x11) {
                func_L30_004CF4B0(0x78, 1);
            } else if ((*(s32 *)(m + 0x24) & 8) != 0) {
                func_L30_004CF4B0(0x91, 1);
            } else {
                func_L30_004CF4B0(0x16, 1);
            }
            if (*(s32 *)(hero() + 0x25C4) == 0x91) {
                qzero(&v);
            } else {
                f32 g = 0.06600001f;
                if (*(u8 *)(hero() + 0x1479) != 0) {
                    g = 0.0f;
                }
                func_L01_004ED838(&v, flag, g, 0.034f);
                if (flag != 0 && *(u8 *)(m + 0x28) == 4) {
                    func_L01_00511618(&v, &v, 2.0f);
                }
            }
            break;
        case 1:
            func_L30_004CF4B0(0x42, 1);
            func_L01_004ED838(&v, flag, 0.060000002f, 0.060000002f);
            break;
        case 5:
            if ((*(s32 *)(m + 0x24) & 0x100000) != 0) {
                r = func_L01_00447490(*(s32 *)(hero() + 0x25C0), 0x100001, 0);
                if (r != 0) {
                    func_L01_004DFEA0((s32) * (f32 *)(r + 0x2C));
                } else {
                    func_L01_004DFEA0(1);
                }
                *(s16 *)(hero() + 0x1DC) = 0x64;
                if (*(s32 *)(hero() + 0x2850) > 0) {
                    func_L30_004CF4B0(0xAC, 1);
                } else {
                    func_L30_004CF4B0(0x9F, 0);
                    func_L01_0050FB40(0x28, 0x46, 6.0f);
                }
                func_L01_003F1F20(0x12, 0);
            } else {
                *(s16 *)(hero() + 0x1DC) = 0x64;
                func_L30_004CF4B0(0x9E, 1);
                func_L01_004ED838(&v, flag, 0.040000003f, 0.020000001f);
                func_L01_003F1F20(0x12, 0);
            }
            break;
        case 3:
            func_L30_004CF4B0(0x55, 1);
            func_L01_004ED838(&v, flag, 0.10000001f, 0.048000004f);
            break;
        }
        {
            vu0_q qv, qf, qr, q1, qt, qr2;
            /* retail's four lqc2: v once (shared by the copy and the first add), the hero slot, the second slot, t */
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(*(vu0_v4 *)&v));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&t) : "j"(qv));
            qf = *(vu0_q *)(D_001A4BE0 + 0xF0);
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qf), "j"(qv));
            *(vu0_q *)(D_001A4BE0 + 0xF0) = qr;
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)(D_001A4BE0 + 0x110)));
            qt = *(vu0_q *)&t;
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr2) : "j"(q1), "j"(qt));
            *(vu0_q *)(D_001A4BE0 + 0x110) = qr2;
        }

        return 1;
    }
    if (*(s16 *)(hero() + 0x1DC) != 0) {
        return 1;
    }
    r = func_L01_00447490(*(s32 *)(hero() + 0x25C0), 1, 0);
    if (r != 0) {
        func_L01_004DFEA0((s32) * (f32 *)(r + 0x2C));
    } else {
        func_L01_004DFEA0(1);
    }
    *(s16 *)(hero() + 0x1DC) = 0x40;
    return 1;
}
/* localdecomp:end func_L30_004BB918 */
