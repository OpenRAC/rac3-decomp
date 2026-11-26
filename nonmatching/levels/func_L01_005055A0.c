/* func_L01_005055A0: near miss (k6, 2026-11-26), 22 aligned differences in src/levels/shared/L01_004FE668.c with the
   file's flags. Ported from its level-08 twin func_L08_004E1388 (83 % equal masked words; names moved to level 01 by
   relocation), plus level 01's own `case 0xB` (decompiled from retail, 0x505F04-0x5060DC). Left: retail keeps the
   0xE argument of case 0xB's two func_L01_004606E8 calls in $s0 (set in a delay slot); every wording tried (k, other
   locals, a literal) has the constant folded into the calls, and the allocation fallout swaps registers in case 9's
   k = 0xC / 0xF (movn/movz) and the 0x25CC compare chain. */
/* localdecomp:start func_L01_005055A0 */
/* Hero button checks for the aquatos levels (08, 27). D_001D4C40 is a two-word pair: [1] is read through the
 * symbol+4 macro load (lui form). The H.234 test's empty-looking else (k = 0, dead) is what keeps cse's path from
 * running past it into the switch, so the hero base is rebuilt before `old` as in retail. */
#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
extern char D_001A4BE0_005055A0[];
extern u8 *D_001D52FC;
extern s32 D_001D4C40[2];
extern s32 D_L01_001DBCFC;
__asm__(".extern D_L01_001DBCFC, 4");
extern u8 D_00142CBD[];
extern u8 D_001439F4[];
extern u8 D_L01_002F62D0_005055A0[];

s32 func_003A3BB8(s32 a0, s32 a1);
void func_L01_005003D0(s32, s32);
s32 func_L01_004EDFA8(u8 *object);
void func_L01_004F5810(void);
void func_L01_004F5AE8(void);
s32 func_L01_004EC598(void);

#define H D_001A4BE0_005055A0
#define PAD(o) FLD(D_001D52FC, s32, o)

extern void func_L01_004EA7D8(s32);

s32 func_L01_005055A0(void) {
    s32 sp0;
    s32 sp4;
    s32 st;
    s32 mask;
    s32 old;
    u8 *o;
    u8 *e;
    u8 *e2;
    s32 n2;
    s32 c2;
    s32 n;
    s32 b;
    s32 c;
    s32 z;
    s32 z2;
    s32 k;
    f32 lim;

    if (FLD(H, u8, 0x25ED) != 0) {
        if (FLD(H, s32, 0x1228) != 9) {
            return 0;
        }
        if (FLD(H, s16, 0x368) != 1) {
            return 0;
        }
    }
    if (FLD(H, u8, 0x25E4) != 0) {
        return 0;
    }
    if (FLD(H, u8 *, 0x1200) == 0) {
        return 0;
    }
    if (FLD(H, u8, 0x121A) != 0) {
        return 0;
    }
    if (FLD(H, s32, 0x1224) != 2) {
        return 0;
    }
    st = FLD(H, s32, 0x1228);
    mask = FLD(H, s32, 0x1210);
    if (D_001439F4[0] != 0 && (mask & 0x20)) {
        mask |= 8;
    }
    if (FLD(H, s32, 0x234) != 0) {
        if (mask & 0x80) {
            mask |= 0x20;
        }
    } else {
        k = 0;
    }
    old = FLD(H, s32, 0x1B8);
    switch (st) {
    case 9:
        if (FLD(H, u8, 0x147C) != 0) {
            break;
        }
        if (FLD(H, s16, 0x1E0) != 0) {
            break;
        }
        if ((u32)FLD(H, s32, 0x25CC) < 2 || (FLD(H, s32, 0x25CC) == 4 && FLD(H, u8, 0x46C) != 0)) {
            if (func_L01_004606E8(mask, 8, (s32)&sp0, 0) == 0) {
                break;
            }
            o = FLD(H, u8 *, 0x1200);
            if (o == 0) {
                break;
            }
            if (func_L01_004EDFA8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if ((b = PAD(0x1A0), FLD(H, s32, 0x16B0) == 0 ? b & func_003A3BB8(8, 0) : b & 0xA) == 0) {
                if ((FLD(H, s32, 0x25C4) != 1 && FLD(H, s32, 0x25C4) != 0x1D) || FLD(H, s32, 0x1B8) < 0x12) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
            }
            if ((FLD(H, s32, 0x25C4) != 1 && FLD(H, s32, 0x25C4) != 0x1D) || FLD(H, s32, 0x1B8) < 0x12) {
                func_L01_005003D0(0x15, 1);
                break;
            }
            func_L01_004F5810();
            break;
        }
        if ((FLD(H, s32, 0x25C4) == 7 || FLD(H, s32, 0x25C4) == 9 || FLD(H, s32, 0x25C4) == 0xF || FLD(H, s32, 0x25C4) == 0xA
             || FLD(H, s32, 0x25C4) == 0xD || FLD(H, s32, 0x25C4) == 8 || FLD(H, s32, 0x25C4) == 6
             || (FLD(H, s32, 0x25C4) == 0xE && 32.0f < FLD(H, f32, 0xC18))
             || (FLD(H, s32, 0x25C4) == 0xB && ((FLD(H, s32, 0x4A4) != 3 && 18.0f < FLD(H, f32, 0xC18))
                                             || (*(s32 *)(H + 0x4A4) == 3 && 20.0f < FLD(H, f32, 0xC18))))
             || FLD(H, s32, 0x25C4) == 0x2C || FLD(H, s32, 0x25C4) == 0x11)
            && FLD(H, s32, 0x1B8) >= 9) {
            k = 0xC;
            if (FLD(H, s32, 0x25C4) == 0xB || FLD(H, s32, 0x25C4) == 0xE) {
                k = 0xF;
            }
            if (func_L01_004606E8(mask, k, 0, 0) == 0) {
                break;
            }
            if ((FLD(H, u8, 0x46E) == 0 ? 0.1f < FLD(H, f32, 0x33C) : 0.57f < FLD(H, f32, 0x33C))
                || (FLD(H, s32, 0x25C4) == 8 && 0.57f < FLD(H, f32, 0x33C))) {
                if (FLD(H, s32, 0x69C) == 0) {
                    func_L01_005003D0(0x14, 1);
                }
            } else {
                func_L01_005003D0(0x13, 1);
            }
            break;
        }
        if (FLD(H, s32, 0x25CC) != 6) {
            break;
        }
        e = D_L01_002F62D0_005055A0 + FLD(H, s16, 0xBDC) * 0x2C;
        if (FLD(H, s32, 0x25C4) == 0x15 && FLD(H, s32, 0x1B8) >= 0x1A && FLD(H, u8, 0x121A) == 0) {
            if (FLD(H, s32, 0xC0C) != 0) {
                break;
            }
            if ((f32)FLD(e, s32, 0x10) <= FLD(H, f32, 0xC18)
                && (b = PAD(0x1A0), FLD(H, s32, 0x16B0) == 0 ? b & func_003A3BB8(8, 0) : b & 0xA)
                && func_L01_004606E8(mask, 0xC, 0, 0) != 0) {
                func_L01_005003D0(0x15, 1);
                break;
            }
        }
        if (FLD(H, s32, 0xC0C) != 0) {
            break;
        }
        if ((z = FLD(H, u8, 0x121A)) != 0) {
            break;
        }
        if (!((f32)FLD(e, s32, 0x10) <= FLD(H, f32, 0xC18))) {
            break;
        }
        n = ((s32)FLD(H, f32, 0xC18) - FLD(e, s32, 0xC)) * 2;
        c = 1;
        if (n > z) {
            c = n;
        }
        if (c > 12) {
            c = 12;
        }
        if (func_L01_004606E8(mask, c, 0, 0) == 0) {
            break;
        }
        func_L01_005003D0((b = PAD(0x1A0), FLD(H, s32, 0x16B0) == 0 ? b & func_003A3BB8(8, 0) : b & 0xA) ? 0x15 : 0x13, 1);
        break;
    case 0x7F:
        if (FLD(H, u8, 0x147C) != 0) {
            break;
        }
        if ((u32)FLD(H, s32, 0x25CC) < 2 || (FLD(H, s32, 0x25CC) == 4 && FLD(H, u8, 0x46C) != 0)) {
            if (func_L01_004606E8(mask, 8, &sp4, 0) == 0) {
                break;
            }
            o = FLD(H, u8 *, 0x1200);
            if (o == 0) {
                break;
            }
            if (func_L01_004EDFA8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if ((PAD(0x1A0) & func_003A3BB8(8, 0)) == 0) {
                if ((FLD(H, s32, 0x25C4) != 1 && FLD(H, s32, 0x25C4) != 0x1D) || FLD(H, s32, 0x1B8) < 0x12) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
            }
            if ((FLD(H, s32, 0x25C4) != 1 && FLD(H, s32, 0x25C4) != 0x1D) || FLD(H, s32, 0x1B8) < 0x12) {
                func_L01_005003D0(0x15, 1);
                break;
            }
            func_L01_004F5AE8();
            break;
        }
        if ((FLD(H, s32, 0x25C4) == 7 || FLD(H, s32, 0x25C4) == 9 || FLD(H, s32, 0x25C4) == 8 || FLD(H, s32, 0x25C4) == 6
             || (FLD(H, s32, 0x25C4) == 0xE && 32.0f < FLD(H, f32, 0xC18))
             || (FLD(H, s32, 0x25C4) == 0xB && ((FLD(H, s32, 0x4A4) != 3 && 18.0f < FLD(H, f32, 0xC18))
                                             || (*(s32 *)(H + 0x4A4) == 3 && 20.0f < FLD(H, f32, 0xC18))))
             || FLD(H, s32, 0x25C4) == 0x2C || FLD(H, s32, 0x25C4) == 0x11)
            && FLD(H, s32, 0x1B8) >= 9) {
            k = 0xC;
            if (FLD(H, s32, 0x25C4) == 0xB || FLD(H, s32, 0x25C4) == 0xE) {
                k = 0xF;
            }
            if (func_L01_004606E8(mask, k, 0, 0) == 0) {
                break;
            }
            if ((FLD(H, u8, 0x46E) == 0 ? 0.1f < FLD(H, f32, 0x33C) : 0.57f < FLD(H, f32, 0x33C))
                || (FLD(H, s32, 0x25C4) == 8 && 0.57f < FLD(H, f32, 0x33C))) {
                if (FLD(H, s32, 0x69C) == 0) {
                    func_L01_005003D0(0x14, 1);
                }
            } else {
                func_L01_005003D0(0x13, 1);
            }
            break;
        }
        if (FLD(H, s32, 0x25CC) != 6) {
            break;
        }
        e2 = D_L01_002F62D0_005055A0 + FLD(H, s16, 0xBDC) * 0x2C;
        if (FLD(H, s32, 0x25C4) == 0x15 && FLD(H, s32, 0x1B8) >= 0x1A && FLD(H, u8, 0x121A) == 0) {
            if (FLD(H, s32, 0xC0C) != 0) {
                break;
            }
            if ((f32)FLD(e2, s32, 0x10) <= FLD(H, f32, 0xC18)
                && (PAD(0x1A0) & func_003A3BB8(8, 0))
                && func_L01_004606E8(mask, 0xC, 0, 0) != 0) {
                func_L01_005003D0(0x15, 1);
                break;
            }
        }
        if (FLD(H, s32, 0xC0C) != 0) {
            break;
        }
        if ((z2 = FLD(H, u8, 0x121A)) != 0) {
            break;
        }
        if (!((f32)FLD(e2, s32, 0x10) <= FLD(H, f32, 0xC18))) {
            break;
        }
        n2 = ((s32)FLD(H, f32, 0xC18) - FLD(e2, s32, 0xC)) * 2;
        c2 = 1;
        if (n2 > z2) {
            c2 = n2;
        }
        if (c2 > 12) {
            c2 = 12;
        }
        if (func_L01_004606E8(mask, c2, 0, 0) == 0) {
            break;
        }
        if (PAD(0x1A0) & func_003A3BB8(8, 0)) {
            func_L01_005003D0(0x15, 1);
        } else {
            func_L01_005003D0(0x13, 1);
        }
        break;
    case 0xB:
        k = 0xE;
        if (FLD(H, s32, 0x25C4) == 0x27 && (FLD(H, s16, 0xA5E) != 0 || FLD(H, s32, 0xA28) != 0)) {
            if (func_L01_004606E8(mask, k, 0, 0) != 0 || ((PAD(0x1A0) & mask) && FLD(H, s32, 0x1220) >= 0xD)) {
                func_L01_005003D0(0x28, 1);
                break;
            }
        }
        c = FLD(H, s32, 0x25CC);
        if ((u32)c < 2 || c == 0xC || c == 4 || c == 2 || c == 0x1E || c == 5
            || (FLD(H, s32, 0x25C4) == 0x28 && FLD(H, s32, 0x1B8) >= 5) || FLD(H, s32, 0x25C4) == 0x1D) {
            if (func_L01_004606E8(mask, k, 0, 0) == 0 && ((PAD(0x1A4) & mask) == 0 || FLD(H, s32, 0x1220) < 0xD)) {
                break;
            }
            if (FLD(H, s16, 0xA5E) != 0) {
                if (FLD(H, s32, 0xA28) != 0) {
                    if (FLD(H, f32, 0xA58) < FLD(H, f32, 0xA44)) {
                        FLD(H, s32, 0xA28) = 0;
                    } else {
                        FLD(H, s16, 0xA5E) = 0;
                    }
                }
                if (FLD(H, s16, 0xA5E) != 0 && FLD(H, s16, 0x206) == 0 && FLD(H, s32, 0x25C4) != 0x2B) {
                    func_L01_005003D0(0x2B, 1);
                    break;
                }
            }
            if (FLD(H, s32, 0xA28) != 0 && FLD(H, s16, 0x206) == 0) {
                func_L01_005003D0(0x23, 1);
                break;
            }
            if (FLD(H, s32, 0xA94) != 0) {
                func_L01_005003D0(0x8F, 1);
                break;
            }
            if (FLD(H, s32, 0xAC4) != 0) {
                FLD(H, s32, 0xACC) = 1;
                func_L01_004EA7D8(0x12);
            }
        }
        break;
    case 0x1E:
        if (FLD(H, u8, 0x25E4) != 0) {
            break;
        }
        if (func_L01_004EC598() == 0) {
            break;
        }
        if (func_L01_004606E8(mask, 6, 0, 0) == 0) {
            break;
        }
        if (D_001D4C40[0] != 0x1E) {
            break;
        }
        if (FLD(FLD(H, u8 *, 0x1200), s16, 0xAA) != 0x1D7E) {
            break;
        }
        if (FLD(H, s16, 0x288C) != 0) {
            break;
        }
        FLD(H, s16, 0x2888) = 1;
        FLD(H, s16, 0x288C) = 0x12;
        FLD(H, s16, 0x288A) = 1;
        break;
    }
    if (FLD(H, s32, 0x1B8) == old && D_00142CBD[0] != 0 && D_001D4C40[1] == 0x1D
        && FLD(H, s32, 0x25C4) != 0x1D && FLD(H, s32, 0x25C4) != 1
        && (FLD(H, unsigned long, 0x210) & 0xFFFFFFFF00000000UL) == 0) {
        func_0038CAD0(&D_L01_001DBCFC);
        if (D_L01_001DBCFC != 0) {
            if ((u32)FLD(H, s32, 0x25CC) < 2 || FLD(H, s32, 0x25CC) == 0xC
                || ((FLD(H, s32, 0x25CC) == 2 || FLD(H, s32, 0x25CC) == 4) && FLD(H, s32, 0x360) != 0)) {
                if ((PAD(0x1A0) & func_003A3BB8(8, 0)) && (PAD(0x1A4) & func_003A3BB8(8, 0))) {
                    func_L01_005003D0(0x80, 1);
                }
            }
        }
        if (PAD(0x1A4) & func_003A3BB8(8, 0)) {
            D_L01_001DBCFC = 0xC;
        }
    }
    return FLD(H, s32, 0x1B8) < old;
}
/* localdecomp:end func_L01_005055A0 */
