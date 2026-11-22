/* func_L05_003C4F88 (levels 05, 11, 17; a switch, 9-entry jump table): near miss, 18 differences (tools/check.py) at levels 05, 11 and 17 with the
 * file's line (`-mvu0-use-vf0-vf2 ... @ps2as`, which vec_add_ba / vec_sub_ab need; re-measured 2026-11-22). Start: round 13's draft
 * (125 aligned diffs); round 18 (sonnet-b29-n1b) took it to 18 raw / 11 aligned. What fixed what:
 *  - the three vectors v90/va0/vb0 in ONE struct with two unused 16-byte slots after them (frame 0x120 -> 0x140);
 *  - the 0x30-entry table test `idx != -1 && T[idx].cnt != 0` (8 copies): a nested `if` with a BLOCK-scoped pointer `u8 *e = T + idx * 0x30;` (a function-level
 *    pointer made a global pseudo that took $v1 before the block's temps: 84 -> 33 aligned);
 *  - `g` (the D_L05_001D673C flag) declared inside each of the two case-4 blocks (a function-level g is a global pseudo and swapped g/flags registers);
 *  - the `if (D != 0) vsub...; else ... break;` of the FIRST case-6 block with its arms swapped (`if (D == 0) { else arm } else { vsub arm }`): retail
 *    falls through into the vsub arm (`beql v0,zero`), 25 -> 11 aligned (raw 467 -> 18); the second block stays as written.
 * Still differs (18 words): (1) retail's `ori $v0,0x8ef7` of the 28-argument call comes after `sw $a1,0x30($sp)` (ours before; 4 placements of the constant,
 * a named local and a long suffix change nothing); (2) the loop-entry test of the case-6 table loop: `addu $v0,$a3,$a1` / `lh $v1` in retail, ours the
 * operand order (table first needs a pointer variable, which then takes $v1: `for (...; i < *(s16 *)((e = T + idx * 0x30) + 0x32); ...)` fixes the loop-end
 * sum but swaps the registers of the entry test); (3) in both case-6 vsub arms retail loads `a0+0x10` into vf2 BEFORE `s+0x220` into vf1 and orders
 * `addiu $a2,$sp,0x90` / `move $a1` / sqc2 / `move $a0` (in the delay slot): ours loads s+0x220 first and puts `addiu $a2` in the slot; vec_sub_ab and
 * vec_sub_ba give the same code, and so do a pointer local for &v90 / a0+0x10 and (2026-11-22) inline j-form arms with a0+0x10 loaded
 * first, with the result in the first operand's variable or a fresh one, and the vsub as a comma operand of the call's argument.
 * All 18 are real differences: check.py does not count the jump table's lui/addiu words (compare the table with retail's in the full build). */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L05_003C4F88 */
typedef struct { u8 b[0x80]; } Snd80_003C4F88;
extern Snd80_003C4F88 D_001A30B0[];
extern s32 D_L05_001D673C;
extern u8 *D_L05_001DF7CC;
extern u8 *D_L05_001DFC80;
extern u8 D_L05_001D66B0[8];
extern s32 func_L05_003C6080(u8 *);
extern void func_L05_003C66F0(u8 *);
extern void func_L05_003C67C0(u8 *);
extern void func_L05_003C69D8(u8 *);
extern void func_L05_00323AC0(u8 *, void *, void *, f32, f32);
extern void func_003C2880(u8 *);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern s32 func_L01_00454370(u8 *, u8 *);
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_003A4F28(s32);
extern void func_L01_0045BD78(u8 *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(u8 *, s32);
extern void func_L01_0045BD10(u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045CED0(u8 *, void *);
extern void func_L01_0045A748(u8 *, void *);
extern void func_L01_0045CF00(u8 *, void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0043A800(u8 *, s32, void *);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern void func_003C2F58(u8 *, s32, void *);
extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, f32, f32, f32, s32);
void func_L05_003C4F88(u8 *a0) {
    u8 *s;
    struct { vu0_v4 v90, va0, vb0, vc0, vd0; } L;
    s32 f;
    s32 i;
    s32 id;
    Snd80_003C4F88 *snd;
    f32 d;
    f32 d1;
    f32 f20;
    f32 f21;
    s = *(u8 **)(a0 + 0x68);
    if (func_L05_003C6080(a0)) {
        func_003C2880(a0);
        return;
    }
    switch (a0[0x95]) {
    case 0:
        if (func_L01_004561E0(a0)) {
            *(s16 *)(s + 0x2F6) = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        if (*(s16 *)(s + 0x234) == 1 && func_0038CB00(s + 0x2F6)) {
            func_L01_004450F0(a0, 5, 2);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
            if (*(s32 *)(s + 0x2FC) != -1) {
                func_L01_004450F0(a0, 4, -1);
            }
        } else if (*(s32 *)(s + 0x2F8) != 0 && func_0038CB00(s + 0x2F6)) {
            func_L01_004450F0(a0, 5, 2);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
            if (*(s32 *)(s + 0x2FC) != -1) {
                func_L01_004450F0(a0, 4, -1);
            }
            *(s32 *)(s + 0x2F8) = 0;
            if (*(s32 *)(s + 0x2F0) < 0xFA) {
                *(s32 *)(s + 0x2F0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (*(s16 *)(s + 0x234) == 1) {
            func_L01_004450F0(a0, 5, 2);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
            if (*(s32 *)(s + 0x2FC) != -1) {
                func_L01_004450F0(a0, 4, -1);
            }
        } else if (*(s32 *)(s + 0x2F0) == 0) {
            func_L01_004450F0(a0, 1, 0);
        }
        break;
    case 2:
        if (func_L01_004561E0(a0)) {
            if (*(s32 *)(s + 0x424) != 0) {
                func_L01_00409598(a0, a0 + 0x10, a0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                *(s32 *)(s + 0x424) = 0;
            }
        }
        if (*(s16 *)(s + 0x234) != 1 && func_L01_004561E0(a0) == 0) {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 8);
            }
            func_L01_004450F0(a0, 3, 1);
            *(s32 *)(s + 0x2F0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        if (func_L01_004561E0(a0)) {
            *(s32 *)(s + 0x2FC) = -1;
        }
        f = func_L01_00454370(a0, s + 0x160);
        if ((f & 1) || *(f32 *)(s + 0x30) <= 0.0f) {
            func_L05_003C66F0(a0);
            func_0038CF68(&L.va0, a0 + 0xE0, 3.0f);
            vec_add_ba(&L.v90, a0 + 0x10, &L.va0);
            func_L01_003303B8(&L.v90, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 1, 0, 1,
                              0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                              0x280000FF, 0x3064FF, 0);
            func_003A52A0(5, 0, a0);
            id = *(s32 *)(s + 0x420);
            if (id != -1) {
                snd = &D_001A30B0[id];
                if (*(u8 **)&snd->b[0xDC] == a0 && snd->b[0xD0] != 0) {
                    func_003A4F28(id);
                }
            }
            *(s32 *)(s + 0x420) = -1;
            func_003C2880(a0);
            return;
        }
        if (f & 2) {
            if (*(s16 *)(s + 0x234) == 1) {
                func_L01_004450F0(a0, 5, 2);
                if (*(s32 *)(s + 0x408) != -1) {
                    u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                    if (*(s16 *)(e + 0x32) != 0) {
                        if (a0[0x43] != 1) {
                            func_003C3A10(a0, 1, 0, 8);
                        }
                        func_L01_004450F0(a0, 6, -1);
                    }
                }
            } else {
                func_L01_004450F0(a0, 3, 1);
                *(s32 *)(s + 0x2F0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    switch (a0[0x20]) {
    case 4:
        if (func_L01_004561B8(a0)) {
            s32 g = D_L05_001D673C;
            *(s32 *)(s + 0xA8) |= 0x400;
            if (g != 0) {
                *(s32 *)(s + 0xA8) |= 0x10;
            }
            func_L01_0045BD78(a0, *(f32 *)(s + 0x404) * 2.5f * 0.00040000002f, *(f32 *)(s + 0x404) * 0.020000001f,
                              0.010053097f, 0.25132743f);
        }
        if (func_L01_0045BDE8(a0, *(s32 *)(s + 0x2FC))) {
            s32 g = D_L05_001D673C;
            *(s32 *)(s + 0x2FC) = -1;
            *(s32 *)(s + 0xA8) &= ~0x400;
            if (g != 0) {
                *(s32 *)(s + 0xA8) &= ~0x10;
            }
            qzero(s + 0x110);
            func_L01_004450F0(a0, 5, -1);
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
        } else {
            func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
        }
        break;
    case 5:
        if (*(s16 *)(s + 0x428) == 0) {
            if (D_L05_001D673C != 0) {
                func_L01_0045CED0(a0, s + 0x220);
            } else {
                func_L01_0045A748(a0, s + 0x220);
            }
        }
        if (func_0038CF38(a0 + 0x10, s + 0x220) < 25.0f || *(s16 *)(s + 0x428) != 0) {
            func_L01_004450F0(a0, 7, -1);
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
        }
        break;
    case 7:
        if (*(s16 *)(s + 0x428) != 0) {
            func_L05_003C69D8(a0);
        } else if (D_L05_001D673C != 0) {
            vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
            func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
        } else {
            func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
        }
        if (a0[0x60] & 2) {
            if (a0[0x43] != 4) {
                func_003C3A10(a0, 4, 0, 8);
            }
            func_L01_004450F0(a0, 8, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    *(u128_t *)(s + 0x410) =
                        *(u128_t *)(D_L05_001DFC80 + (**(s32 **)(D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30 + 0x40) << 7) + 0x30);
                    for (i = 0; i < *(s16 *)(*(s32 *)(s + 0x408) * 0x30 + D_L05_001DF7CC + 0x32); i++) {
                        u8 *w = D_L05_001DFC80 +
                                (*(s32 *)(*(u8 **)(D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30 + 0x40) + i * 4) << 7);
                        f20 = func_0038CF38(w + 0x30, s + 0x220);
                        if ((func_0038CF38(s + 0x410, s + 0x220) < f20 || func_0038CF38(a0 + 0x10, s + 0x410) < 2.0f) &&
                            2.0f < func_0038CF38(a0 + 0x10, w + 0x30)) {
                            *(u128_t *)(s + 0x410) = *(u128_t *)(w + 0x30);
                        }
                    }
                }
            }
        }
        if (D_L05_001D673C != 0) {
            if (func_0038CF00(a0 + 0x10, s + 0x410) < 3.0f) {
                if (D_L05_001D673C == 0) {
                    func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                        *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
                    if (!(func_0038DBA0(*(f32 *)(a0 + 0xF8), func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                                           *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14))) < 0.27925268f)) {
                        break;
                    }
                } else {
                    vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
                    func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
                }
                func_L01_004450F0(a0, 7, -1);
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 8);
                }
            } else if (D_L05_001D673C != 0) {
                func_L01_0045CED0(a0, s + 0x410);
            } else {
                func_L01_0045A748(a0, s + 0x410);
                func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                    *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
            }
        } else {
            if (func_0038CF38(a0 + 0x10, s + 0x410) < 1.0f) {
                if (D_L05_001D673C != 0) {
                    vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
                    func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
                } else {
                    func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                        *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
                    if (!(func_0038DBA0(*(f32 *)(a0 + 0xF8), func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                                           *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14))) < 0.27925268f)) {
                        break;
                    }
                }
                func_L01_004450F0(a0, 7, -1);
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 8);
                }
            } else if (D_L05_001D673C != 0) {
                func_L01_0045CED0(a0, s + 0x410);
            } else {
                func_L01_0045A748(a0, s + 0x410);
                func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                    *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
            }
        }
        break;
    case 8:
        if (D_L05_001D673C == 0) {
            func_L01_0040EE50(&L.vb0, a0 + 0xC0);
            vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
            func_0038D000(&L.v90, &L.v90, &L.vb0);
            func_L01_0043A800(a0, 0, &L.va0);
            *(f32 *)(s + 0x364) = -func_0038D160(func_0038CF38(&L.va0, &L.v90), L.v90.z - L.va0.z);
            func_L01_0043A800(a0, 1, &L.va0);
            *(f32 *)(s + 0x3E4) = -func_0038D160(func_0038CF38(&L.va0, &L.v90), L.v90.z - L.va0.z);
        }
        if (*(s16 *)(s + 0x428) != 0) {
            func_L05_003C69D8(a0);
        } else {
            func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
        }
        if (D_L05_001D673C != 0) {
            vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
            func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
        }
        if (*(u16 *)(a0 + 0x96) >= 0xC9) {
            func_L01_004450F0(a0, 9, -1);
            if (a0[0x43] != 5) {
                func_003C3A10(a0, 5, 0, 8);
            }
        }
        if ((func_L01_0044E1B8(a0, 2.0f) || func_L01_0044E1B8(a0, 6.0f) || func_L01_0044E1B8(a0, 10.0f) ||
             func_L01_0044E1B8(a0, 14.0f) || func_L01_0044E1B8(a0, 18.0f) || func_L01_0044E1B8(a0, 22.0f) ||
             func_L01_0044E1B8(a0, 26.0f)) &&
            a0[0x42] == 4) {
            func_003C2F58(a0, 2, &L.v90);
            f21 = 1.0f;
            f20 = 0.0f;
            vec_sub_ab(&L.va0, s + 0x220, &L.v90);
            func_L05_00323AC0(a0, &L.v90, &L.va0, (f32)s[0x44], *(f32 *)(s + 0x40C));
            func_0038CF68(&L.vb0, &L.va0, f21);
            vec_add_ab(&L.vb0, &L.vb0, &L.v90);
            func_L01_0046B458(&L.vb0, 2, 0x7F1040FF, 0, 2, D_L05_001D66B0, 3.0f, 10.0f, f20, 0);
            func_L01_0046B458(&L.vb0, 2, 0x5F5F5F5F, 0, 2, D_L05_001D66B0, f21, 7.0f, f20, 0);
        }
        if ((func_L01_0044E1B8(a0, 4.0f) || func_L01_0044E1B8(a0, 8.0f) || func_L01_0044E1B8(a0, 12.0f) ||
             func_L01_0044E1B8(a0, 16.0f) || func_L01_0044E1B8(a0, 20.0f) || func_L01_0044E1B8(a0, 24.0f) ||
             func_L01_0044E1B8(a0, 28.0f)) &&
            a0[0x42] == 4) {
            func_003C2F58(a0, 3, &L.v90);
            f21 = 1.0f;
            f20 = 0.0f;
            vec_sub_ab(&L.va0, s + 0x220, &L.v90);
            func_L05_00323AC0(a0, &L.v90, &L.va0, (f32)s[0x44], *(f32 *)(s + 0x40C));
            func_0038CF68(&L.vb0, &L.va0, f21);
            vec_add_ab(&L.vb0, &L.vb0, &L.v90);
            func_L01_0046B458(&L.vb0, 2, 0x7F1040FF, 0, 2, D_L05_001D66B0, 3.0f, 10.0f, f20, 0);
            func_L01_0046B458(&L.vb0, 2, 0x5F5F5F5F, 0, 2, D_L05_001D66B0, f21, 7.0f, f20, 0);
        }
        break;
    case 9:
        if (a0[0x60] & 2) {
            *(s16 *)(s + 0x42A) = 0;
            func_L01_004450F0(a0, 5, -1);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    func_L05_003C67C0(a0);
}
/* localdecomp:end func_L05_003C4F88 */
