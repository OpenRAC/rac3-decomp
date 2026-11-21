#include "common.h"

/* NTSC-U counterpart of func_L08_004E1388 (src/levels/shared/L08_004E1388.c) */
/* localdecomp:start func_L08_004DCFC8 */
/* Hero button checks for the aquatos levels (08, 27). D_001D4C40 is a two-word pair: [1] is read through the
 * symbol+4 macro load (lui form). The +0x234 test's empty-looking else (k = 0, dead) is what keeps cse's path from
 * running past it into the switch, so the hero base is rebuilt before `old` as in retail. */
#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
extern char D_001A4BE0[];
extern u8 *D_001D52FC;
extern s32 D_001D4C40[2];
extern s32 D_L08_001DBBBC;
__asm__(".extern D_L08_001DBBBC, 4");
extern u8 D_00142CBD[];
extern u8 D_001439F4[];
extern u8 D_L08_002F5A10[];

s32 func_L01_0045D358(s32 mask, s32 arg1, s32 *a2, s32 a3);
s32 func_0039E928(s32 a0, s32 a1);
void func_L08_004D8D78(s32, s32);
s32 func_L01_004EA1D8(u8 *object);
void func_L01_004F1A08(void);
void func_L01_004F1CE0(void);
s32 func_L01_004E87C8(void);
s32 func_00388398(void *);

#define PAD(o) FLD(D_001D52FC, s32, o)

s32 func_L08_004DCFC8(void) {
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

    if (FLD(D_001A4BE0, u8, 0x25ED) != 0) {
        if (FLD(D_001A4BE0, s32, 0x1228) != 9) {
            return 0;
        }
        if (FLD(D_001A4BE0, s16, 0x368) != 1) {
            return 0;
        }
    }
    if (FLD(D_001A4BE0, u8, 0x25E4) != 0) {
        return 0;
    }
    if (FLD(D_001A4BE0, u8 *, 0x1200) == 0) {
        return 0;
    }
    if (FLD(D_001A4BE0, u8, 0x121A) != 0) {
        return 0;
    }
    if (FLD(D_001A4BE0, s32, 0x1224) != 2) {
        return 0;
    }
    st = FLD(D_001A4BE0, s32, 0x1228);
    mask = FLD(D_001A4BE0, s32, 0x1210);
    if (D_001439F4[0] != 0 && (mask & 0x20)) {
        mask |= 8;
    }
    if (FLD(D_001A4BE0, s32, 0x234) != 0) {
        if (mask & 0x80) {
            mask |= 0x20;
        }
    } else {
        k = 0;
    }
    old = FLD(D_001A4BE0, s32, 0x1B8);
    switch (st) {
    case 9:
        if (FLD(D_001A4BE0, u8, 0x147C) != 0) {
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) != 0) {
            break;
        }
        if ((u32)FLD(D_001A4BE0, s32, 0x25CC) < 2 || (FLD(D_001A4BE0, s32, 0x25CC) == 4 && FLD(D_001A4BE0, u8, 0x46C) != 0)) {
            if (func_L01_0045D358(mask, 0xA, &sp0, 0) == 0) {
                break;
            }
            o = FLD(D_001A4BE0, u8 *, 0x1200);
            if (o == 0) {
                break;
            }
            if (func_L01_004EA1D8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if ((b = PAD(0x1A0), FLD(D_001A4BE0, s32, 0x16B0) == 0 ? b & func_0039E928(8, 0) : b & 0xA) == 0) {
                if ((FLD(D_001A4BE0, s32, 0x25C4) != 1 && FLD(D_001A4BE0, s32, 0x25C4) != 0x1D) || FLD(D_001A4BE0, s32, 0x1B8) < 0x15) {
                    func_L08_004D8D78(0x13, 1);
                    break;
                }
            }
            if ((FLD(D_001A4BE0, s32, 0x25C4) != 1 && FLD(D_001A4BE0, s32, 0x25C4) != 0x1D) || FLD(D_001A4BE0, s32, 0x1B8) < 0x15) {
                func_L08_004D8D78(0x15, 1);
                break;
            }
            func_L01_004F1A08();
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x25C4) == 7 || FLD(D_001A4BE0, s32, 0x25C4) == 9 || FLD(D_001A4BE0, s32, 0x25C4) == 0xF || FLD(D_001A4BE0, s32, 0x25C4) == 0xA
             || FLD(D_001A4BE0, s32, 0x25C4) == 0xD || FLD(D_001A4BE0, s32, 0x25C4) == 8 || FLD(D_001A4BE0, s32, 0x25C4) == 6
             || (FLD(D_001A4BE0, s32, 0x25C4) == 0xE && 32.0f < FLD(D_001A4BE0, f32, 0xC18))
             || (FLD(D_001A4BE0, s32, 0x25C4) == 0xB && ((FLD(D_001A4BE0, s32, 0x4A4) != 3 && 18.0f < FLD(D_001A4BE0, f32, 0xC18))
                                             || (*(s32 *)(D_001A4BE0 + 0x4A4) == 3 && 20.0f < FLD(D_001A4BE0, f32, 0xC18))))
             || FLD(D_001A4BE0, s32, 0x25C4) == 0x2C || FLD(D_001A4BE0, s32, 0x25C4) == 0x11)
            && FLD(D_001A4BE0, s32, 0x1B8) >= 0xB) {
            k = 0xE;
            if (FLD(D_001A4BE0, s32, 0x25C4) == 0xB || FLD(D_001A4BE0, s32, 0x25C4) == 0xE) {
                k = 0x12;
            }
            if (func_L01_0045D358(mask, k, 0, 0) == 0) {
                break;
            }
            if ((FLD(D_001A4BE0, u8, 0x46E) == 0 ? 0.1f < FLD(D_001A4BE0, f32, 0x33C) : 0.57f < FLD(D_001A4BE0, f32, 0x33C))
                || (FLD(D_001A4BE0, s32, 0x25C4) == 8 && 0.57f < FLD(D_001A4BE0, f32, 0x33C))) {
                if (FLD(D_001A4BE0, s32, 0x69C) == 0) {
                    func_L08_004D8D78(0x14, 1);
                }
            } else {
                func_L08_004D8D78(0x13, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x25CC) != 6) {
            break;
        }
        e = D_L08_002F5A10 + FLD(D_001A4BE0, s16, 0xBDC) * 0x2C;
        if (FLD(D_001A4BE0, s32, 0x25C4) == 0x15 && FLD(D_001A4BE0, s32, 0x1B8) >= 0x1F && FLD(D_001A4BE0, u8, 0x121A) == 0) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                break;
            }
            if ((f32)FLD(e, s32, 0x10) <= FLD(D_001A4BE0, f32, 0xC18)
                && (b = PAD(0x1A0), FLD(D_001A4BE0, s32, 0x16B0) == 0 ? b & func_0039E928(8, 0) : b & 0xA)
                && func_L01_0045D358(mask, 0xF, 0, 0) != 0) {
                func_L08_004D8D78(0x15, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            break;
        }
        if ((z = FLD(D_001A4BE0, u8, 0x121A)) != 0) {
            break;
        }
        if (!((f32)FLD(e, s32, 0x10) <= FLD(D_001A4BE0, f32, 0xC18))) {
            break;
        }
        n = ((s32)FLD(D_001A4BE0, f32, 0xC18) - FLD(e, s32, 0xC)) * 2;
        c = 1;
        if (n > z) {
            c = n;
        }
        if (c > 15) {
            c = 15;
        }
        if (func_L01_0045D358(mask, c, 0, 0) == 0) {
            break;
        }
        func_L08_004D8D78((b = PAD(0x1A0), FLD(D_001A4BE0, s32, 0x16B0) == 0 ? b & func_0039E928(8, 0) : b & 0xA) ? 0x15 : 0x13, 1);
        break;
    case 0x7F:
        if (FLD(D_001A4BE0, u8, 0x147C) != 0) {
            break;
        }
        if ((u32)FLD(D_001A4BE0, s32, 0x25CC) < 2 || (FLD(D_001A4BE0, s32, 0x25CC) == 4 && FLD(D_001A4BE0, u8, 0x46C) != 0)) {
            if (func_L01_0045D358(mask, 0xA, &sp4, 0) == 0) {
                break;
            }
            o = FLD(D_001A4BE0, u8 *, 0x1200);
            if (o == 0) {
                break;
            }
            if (func_L01_004EA1D8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if ((PAD(0x1A0) & func_0039E928(8, 0)) == 0) {
                if ((FLD(D_001A4BE0, s32, 0x25C4) != 1 && FLD(D_001A4BE0, s32, 0x25C4) != 0x1D) || FLD(D_001A4BE0, s32, 0x1B8) < 0x15) {
                    func_L08_004D8D78(0x13, 1);
                    break;
                }
            }
            if ((FLD(D_001A4BE0, s32, 0x25C4) != 1 && FLD(D_001A4BE0, s32, 0x25C4) != 0x1D) || FLD(D_001A4BE0, s32, 0x1B8) < 0x15) {
                func_L08_004D8D78(0x15, 1);
                break;
            }
            func_L01_004F1CE0();
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x25C4) == 7 || FLD(D_001A4BE0, s32, 0x25C4) == 9 || FLD(D_001A4BE0, s32, 0x25C4) == 8 || FLD(D_001A4BE0, s32, 0x25C4) == 6
             || (FLD(D_001A4BE0, s32, 0x25C4) == 0xE && 32.0f < FLD(D_001A4BE0, f32, 0xC18))
             || (FLD(D_001A4BE0, s32, 0x25C4) == 0xB && ((FLD(D_001A4BE0, s32, 0x4A4) != 3 && 18.0f < FLD(D_001A4BE0, f32, 0xC18))
                                             || (*(s32 *)(D_001A4BE0 + 0x4A4) == 3 && 20.0f < FLD(D_001A4BE0, f32, 0xC18))))
             || FLD(D_001A4BE0, s32, 0x25C4) == 0x2C || FLD(D_001A4BE0, s32, 0x25C4) == 0x11)
            && FLD(D_001A4BE0, s32, 0x1B8) >= 0xB) {
            k = 0xE;
            if (FLD(D_001A4BE0, s32, 0x25C4) == 0xB || FLD(D_001A4BE0, s32, 0x25C4) == 0xE) {
                k = 0x12;
            }
            if (func_L01_0045D358(mask, k, 0, 0) == 0) {
                break;
            }
            if ((FLD(D_001A4BE0, u8, 0x46E) == 0 ? 0.1f < FLD(D_001A4BE0, f32, 0x33C) : 0.57f < FLD(D_001A4BE0, f32, 0x33C))
                || (FLD(D_001A4BE0, s32, 0x25C4) == 8 && 0.57f < FLD(D_001A4BE0, f32, 0x33C))) {
                if (FLD(D_001A4BE0, s32, 0x69C) == 0) {
                    func_L08_004D8D78(0x14, 1);
                }
            } else {
                func_L08_004D8D78(0x13, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x25CC) != 6) {
            break;
        }
        e2 = D_L08_002F5A10 + FLD(D_001A4BE0, s16, 0xBDC) * 0x2C;
        if (FLD(D_001A4BE0, s32, 0x25C4) == 0x15 && FLD(D_001A4BE0, s32, 0x1B8) >= 0x1F && FLD(D_001A4BE0, u8, 0x121A) == 0) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                break;
            }
            if ((f32)FLD(e2, s32, 0x10) <= FLD(D_001A4BE0, f32, 0xC18)
                && (PAD(0x1A0) & func_0039E928(8, 0))
                && func_L01_0045D358(mask, 0xF, 0, 0) != 0) {
                func_L08_004D8D78(0x15, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            break;
        }
        if ((z2 = FLD(D_001A4BE0, u8, 0x121A)) != 0) {
            break;
        }
        if (!((f32)FLD(e2, s32, 0x10) <= FLD(D_001A4BE0, f32, 0xC18))) {
            break;
        }
        n2 = ((s32)FLD(D_001A4BE0, f32, 0xC18) - FLD(e2, s32, 0xC)) * 2;
        c2 = 1;
        if (n2 > z2) {
            c2 = n2;
        }
        if (c2 > 15) {
            c2 = 15;
        }
        if (func_L01_0045D358(mask, c2, 0, 0) == 0) {
            break;
        }
        if (PAD(0x1A0) & func_0039E928(8, 0)) {
            func_L08_004D8D78(0x15, 1);
        } else {
            func_L08_004D8D78(0x13, 1);
        }
        break;
    case 0x1E:
        if (FLD(D_001A4BE0, u8, 0x25E4) != 0) {
            break;
        }
        if (func_L01_004E87C8() == 0) {
            break;
        }
        if (func_L01_0045D358(mask, 7, 0, 0) == 0) {
            break;
        }
        if (D_001D4C40[0] != 0x1E) {
            break;
        }
        if (FLD(FLD(D_001A4BE0, u8 *, 0x1200), s16, 0xAA) != 0x1D7E) {
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x288C) != 0) {
            break;
        }
        FLD(D_001A4BE0, s16, 0x2888) = 1;
        FLD(D_001A4BE0, s16, 0x288C) = 0x12;
        FLD(D_001A4BE0, s16, 0x288A) = 1;
        break;
    }
    if (FLD(D_001A4BE0, s32, 0x1B8) == old && D_00142CBD[0] != 0 && D_001D4C40[1] == 0x1D
        && FLD(D_001A4BE0, s32, 0x25C4) != 0x1D && FLD(D_001A4BE0, s32, 0x25C4) != 1
        && (FLD(D_001A4BE0, unsigned long, 0x210) & 0xFFFFFFFF00000000UL) == 0) {
        func_00388398(&D_L08_001DBBBC);
        if (D_L08_001DBBBC != 0) {
            if ((u32)FLD(D_001A4BE0, s32, 0x25CC) < 2 || FLD(D_001A4BE0, s32, 0x25CC) == 0xC
                || ((FLD(D_001A4BE0, s32, 0x25CC) == 2 || FLD(D_001A4BE0, s32, 0x25CC) == 4) && FLD(D_001A4BE0, s32, 0x360) != 0)) {
                if ((PAD(0x1A0) & func_0039E928(8, 0)) && (PAD(0x1A4) & func_0039E928(8, 0))) {
                    func_L08_004D8D78(0x80, 1);
                }
            }
        }
        if (PAD(0x1A4) & func_0039E928(8, 0)) {
            D_L08_001DBBBC = 0xF;
        }
    }
    return FLD(D_001A4BE0, s32, 0x1B8) < old;
}
/* localdecomp:end func_L08_004DCFC8 */
