/* func_L01_005055A0 (Claude wave 14 r66, 2026-11-28). Replaces the earlier draft of this function (k6 port of func_L08_004E1388 + case 0xB). */
/* PAL near miss (wave 14 r66, 2026-11-28): 273 instruction diffs at level 01 under the file's own line (one instruction
 * short, so most rows are the branch offsets and the shift after case 0xB; the k6 header's "22 aligned differences" is
 * the same code). Against the k6 draft: it compiles in the file's context now (func_L01_005003D0 returns s32 as the
 * file's earlier definition does; the draft's void prototype conflicts with it), and it has no #define: the FLD/H/PAD
 * macros are expanded into the struct types Hero_005055A0 (37 fields of D_001A4BE0), Pad_005055A0 (D_001D52FC +0x1A0 /
 * +0x1A4), Entry_005055A0 (+0xC / +0x10 of the D_L01_002F62D0 rows) and Moby_005055A0 (+0xAA), which compile to the
 * same code as the macro form (273 both).
 * Left (k6's analysis, unchanged): retail keeps case 0xB's 0xE argument of func_L01_004606E8 in $s0 (st's register,
 * set in the delay slot of the 0x27 test) and passes it with daddu at both calls; here the constant is propagated into
 * the calls (one instruction fewer), and the allocation fallout swaps case 9's k = 0xC / 0xF movn/movz registers. */
#include "common.h"

/* localdecomp:start func_L01_005055A0 */
typedef struct {
    u8 pad0[0x1B8];
    s32 f1B8;
    u8 pad1BC[0x24];
    s16 f1E0;
    u8 pad1E2[0x24];
    s16 f206;
    u8 pad208[0x8];
    unsigned long f210;
    u8 pad218[0x1C];
    s32 f234;
    u8 pad238[0x104];
    f32 f33C;
    u8 pad340[0x20];
    s32 f360;
    u8 pad364[0x4];
    s16 f368;
    u8 pad36A[0x102];
    u8 f46C;
    u8 pad46D[0x1];
    u8 f46E;
    u8 pad46F[0x35];
    s32 f4A4;
    u8 pad4A8[0x1F4];
    s32 f69C;
    u8 pad6A0[0x388];
    s32 fA28;
    u8 padA2C[0x18];
    f32 fA44;
    u8 padA48[0x10];
    f32 fA58;
    u8 padA5C[0x2];
    s16 fA5E;
    u8 padA60[0x34];
    s32 fA94;
    u8 padA98[0x2C];
    s32 fAC4;
    u8 padAC8[0x4];
    s32 fACC;
    u8 padAD0[0x10C];
    s16 fBDC;
    u8 padBDE[0x2E];
    s32 fC0C;
    u8 padC10[0x8];
    f32 fC18;
    u8 padC1C[0x5E4];
    u8 * f1200;
    u8 pad1204[0xC];
    s32 f1210;
    u8 pad1214[0x6];
    u8 f121A;
    u8 pad121B[0x5];
    s32 f1220;
    s32 f1224;
    s32 f1228;
    u8 pad122C[0x250];
    u8 f147C;
    u8 pad147D[0x233];
    s32 f16B0;
    u8 pad16B4[0xF10];
    s32 f25C4;
    u8 pad25C8[0x4];
    s32 f25CC;
    u8 pad25D0[0x14];
    u8 f25E4;
    u8 pad25E5[0x8];
    u8 f25ED;
    u8 pad25EE[0x29A];
    s16 f2888;
    s16 f288A;
    s16 f288C;
} Hero_005055A0;
typedef struct {
    u8 pad0[0x1A0];
    s32 f1A0;
    s32 f1A4;
} Pad_005055A0;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    s32 f10;
} Entry_005055A0;
typedef struct {
    u8 pad0[0xAA];
    s16 fAA;
} Moby_005055A0;
/* Hero button checks for the aquatos levels (08, 27). D_001D4C40 is a two-word pair: [1] is read through the
 * symbol+4 macro load (lui form). The D_001A4BE0_005055A0.234 test's empty-looking else (k = 0, dead) is what keeps cse's path from
 * running past it into the switch, so the hero base is rebuilt before `old` as in retail. */
extern char D_001A4BE0_005055A0[];
extern u8 *D_001D52FC;
extern s32 D_001D4C40[2];
extern s32 D_L01_001DBCFC;
__asm__(".extern D_L01_001DBCFC, 4");
extern u8 D_00142CBD[];
extern u8 D_001439F4[];
extern u8 D_L01_002F62D0_005055A0[];

s32 func_003A3BB8(s32 a0, s32 a1);
s32 func_L01_005003D0(s32, s32);
s32 func_L01_004EDFA8(u8 *object);
void func_L01_004F5810(void);
void func_L01_004F5AE8(void);
s32 func_L01_004EC598(void);


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

    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25ED != 0) {
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1228 != 9) {
            return 0;
        }
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f368 != 1) {
            return 0;
        }
    }
    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25E4 != 0) {
        return 0;
    }
    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1200 == 0) {
        return 0;
    }
    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f121A != 0) {
        return 0;
    }
    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1224 != 2) {
        return 0;
    }
    st = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1228;
    mask = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1210;
    if (D_001439F4[0] != 0 && (mask & 0x20)) {
        mask |= 8;
    }
    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f234 != 0) {
        if (mask & 0x80) {
            mask |= 0x20;
        }
    } else {
        k = 0;
    }
    old = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8;
    switch (st) {
    case 9:
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f147C != 0) {
            break;
        }
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1E0 != 0) {
            break;
        }
        if ((u32)((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC < 2 || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC == 4 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f46C != 0)) {
            if (func_L01_004606E8(mask, 8, (s32)&sp0, 0) == 0) {
                break;
            }
            o = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1200;
            if (o == 0) {
                break;
            }
            if (func_L01_004EDFA8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if ((b = ((Pad_005055A0 *)(D_001D52FC))->f1A0, ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f16B0 == 0 ? b & func_003A3BB8(8, 0) : b & 0xA) == 0) {
                if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 1 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 0x1D) || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 < 0x12) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
            }
            if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 1 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 0x1D) || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 < 0x12) {
                func_L01_005003D0(0x15, 1);
                break;
            }
            func_L01_004F5810();
            break;
        }
        if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 7 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 9 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xF || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xA
             || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xD || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 8 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 6
             || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xE && 32.0f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)
             || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xB && ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f4A4 != 3 && 18.0f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)
                                             || (*(s32 *)(D_001A4BE0_005055A0 + 0x4A4) == 3 && 20.0f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)))
             || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x2C || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x11)
            && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 >= 9) {
            k = 0xC;
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xB || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xE) {
                k = 0xF;
            }
            if (func_L01_004606E8(mask, k, 0, 0) == 0) {
                break;
            }
            if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f46E == 0 ? 0.1f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f33C : 0.57f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f33C)
                || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 8 && 0.57f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f33C)) {
                if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f69C == 0) {
                    func_L01_005003D0(0x14, 1);
                }
            } else {
                func_L01_005003D0(0x13, 1);
            }
            break;
        }
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC != 6) {
            break;
        }
        e = D_L01_002F62D0_005055A0 + ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fBDC * 0x2C;
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x15 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 >= 0x1A && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f121A == 0) {
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC0C != 0) {
                break;
            }
            if ((f32)((Entry_005055A0 *)(e))->f10 <= ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18
                && (b = ((Pad_005055A0 *)(D_001D52FC))->f1A0, ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f16B0 == 0 ? b & func_003A3BB8(8, 0) : b & 0xA)
                && func_L01_004606E8(mask, 0xC, 0, 0) != 0) {
                func_L01_005003D0(0x15, 1);
                break;
            }
        }
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC0C != 0) {
            break;
        }
        if ((z = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f121A) != 0) {
            break;
        }
        if (!((f32)((Entry_005055A0 *)(e))->f10 <= ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)) {
            break;
        }
        n = ((s32)((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18 - ((Entry_005055A0 *)(e))->fC) * 2;
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
        func_L01_005003D0((b = ((Pad_005055A0 *)(D_001D52FC))->f1A0, ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f16B0 == 0 ? b & func_003A3BB8(8, 0) : b & 0xA) ? 0x15 : 0x13, 1);
        break;
    case 0x7F:
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f147C != 0) {
            break;
        }
        if ((u32)((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC < 2 || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC == 4 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f46C != 0)) {
            if (func_L01_004606E8(mask, 8, &sp4, 0) == 0) {
                break;
            }
            o = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1200;
            if (o == 0) {
                break;
            }
            if (func_L01_004EDFA8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if ((((Pad_005055A0 *)(D_001D52FC))->f1A0 & func_003A3BB8(8, 0)) == 0) {
                if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 1 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 0x1D) || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 < 0x12) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
            }
            if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 1 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 0x1D) || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 < 0x12) {
                func_L01_005003D0(0x15, 1);
                break;
            }
            func_L01_004F5AE8();
            break;
        }
        if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 7 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 9 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 8 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 6
             || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xE && 32.0f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)
             || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xB && ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f4A4 != 3 && 18.0f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)
                                             || (*(s32 *)(D_001A4BE0_005055A0 + 0x4A4) == 3 && 20.0f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)))
             || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x2C || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x11)
            && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 >= 9) {
            k = 0xC;
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xB || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0xE) {
                k = 0xF;
            }
            if (func_L01_004606E8(mask, k, 0, 0) == 0) {
                break;
            }
            if ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f46E == 0 ? 0.1f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f33C : 0.57f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f33C)
                || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 8 && 0.57f < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f33C)) {
                if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f69C == 0) {
                    func_L01_005003D0(0x14, 1);
                }
            } else {
                func_L01_005003D0(0x13, 1);
            }
            break;
        }
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC != 6) {
            break;
        }
        e2 = D_L01_002F62D0_005055A0 + ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fBDC * 0x2C;
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x15 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 >= 0x1A && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f121A == 0) {
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC0C != 0) {
                break;
            }
            if ((f32)((Entry_005055A0 *)(e2))->f10 <= ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18
                && (((Pad_005055A0 *)(D_001D52FC))->f1A0 & func_003A3BB8(8, 0))
                && func_L01_004606E8(mask, 0xC, 0, 0) != 0) {
                func_L01_005003D0(0x15, 1);
                break;
            }
        }
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC0C != 0) {
            break;
        }
        if ((z2 = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f121A) != 0) {
            break;
        }
        if (!((f32)((Entry_005055A0 *)(e2))->f10 <= ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18)) {
            break;
        }
        n2 = ((s32)((Hero_005055A0 *)(D_001A4BE0_005055A0))->fC18 - ((Entry_005055A0 *)(e2))->fC) * 2;
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
        if (((Pad_005055A0 *)(D_001D52FC))->f1A0 & func_003A3BB8(8, 0)) {
            func_L01_005003D0(0x15, 1);
        } else {
            func_L01_005003D0(0x13, 1);
        }
        break;
    case 0xB:
        k = 0xE;
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x27 && (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA5E != 0 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA28 != 0)) {
            if (func_L01_004606E8(mask, k, 0, 0) != 0 || ((((Pad_005055A0 *)(D_001D52FC))->f1A0 & mask) && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1220 >= 0xD)) {
                func_L01_005003D0(0x28, 1);
                break;
            }
        }
        c = ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC;
        if ((u32)c < 2 || c == 0xC || c == 4 || c == 2 || c == 0x1E || c == 5
            || (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x28 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 >= 5) || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 == 0x1D) {
            if (func_L01_004606E8(mask, k, 0, 0) == 0 && ((((Pad_005055A0 *)(D_001D52FC))->f1A4 & mask) == 0 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1220 < 0xD)) {
                break;
            }
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA5E != 0) {
                if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA28 != 0) {
                    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA58 < ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA44) {
                        ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA28 = 0;
                    } else {
                        ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA5E = 0;
                    }
                }
                if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA5E != 0 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f206 == 0 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 0x2B) {
                    func_L01_005003D0(0x2B, 1);
                    break;
                }
            }
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA28 != 0 && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f206 == 0) {
                func_L01_005003D0(0x23, 1);
                break;
            }
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fA94 != 0) {
                func_L01_005003D0(0x8F, 1);
                break;
            }
            if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->fAC4 != 0) {
                ((Hero_005055A0 *)(D_001A4BE0_005055A0))->fACC = 1;
                func_L01_004EA7D8(0x12);
            }
        }
        break;
    case 0x1E:
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25E4 != 0) {
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
        if (((Moby_005055A0 *)(((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1200))->fAA != 0x1D7E) {
            break;
        }
        if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f288C != 0) {
            break;
        }
        ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f2888 = 1;
        ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f288C = 0x12;
        ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f288A = 1;
        break;
    }
    if (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 == old && D_00142CBD[0] != 0 && D_001D4C40[1] == 0x1D
        && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 0x1D && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25C4 != 1
        && (((Hero_005055A0 *)(D_001A4BE0_005055A0))->f210 & 0xFFFFFFFF00000000UL) == 0) {
        func_0038CAD0(&D_L01_001DBCFC);
        if (D_L01_001DBCFC != 0) {
            if ((u32)((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC < 2 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC == 0xC
                || ((((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC == 2 || ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f25CC == 4) && ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f360 != 0)) {
                if ((((Pad_005055A0 *)(D_001D52FC))->f1A0 & func_003A3BB8(8, 0)) && (((Pad_005055A0 *)(D_001D52FC))->f1A4 & func_003A3BB8(8, 0))) {
                    func_L01_005003D0(0x80, 1);
                }
            }
        }
        if (((Pad_005055A0 *)(D_001D52FC))->f1A4 & func_003A3BB8(8, 0)) {
            D_L01_001DBCFC = 0xC;
        }
    }
    return ((Hero_005055A0 *)(D_001A4BE0_005055A0))->f1B8 < old;
}
/* localdecomp:end func_L01_005055A0 */
