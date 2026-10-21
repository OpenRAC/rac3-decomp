/* US draft of func_0039F348 (rac3-uya-decomp func_0039A3B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-fno-force-mem` (a single-function override). */


/* localdecomp:start func_0039F348 */
typedef struct { s32 p[3]; s32 fC; } E_39A3B0;
extern u8 D_1D5530[8];
extern u8 D_142CA0[];
extern u8 D_142D40[];
extern E_39A3B0 D_143230_0039F348[];
extern u8 D_1426E0[];
extern u32 D_142BA0[];
extern u8 D_1BBB18[];
extern u8 D_1D5570[];
extern s32 func_00381D48_0039F348(s32, s32);
s32 func_0039F348(a0, kind, a2)
    s32 a0;
    s16 kind;
    s32 a2;
{
    switch (kind) {
    case 1:
        return D_1D5530[a2] != 0;
    case 2:
        return D_142CA0[a2] != 0;
    case 3:
        return D_142D40[a2] != 0;
    case 4:
        if (a2 < 0x72) return D_143230_0039F348[a2].fC != 0;
        return 0;
    case 5:
        if (a2 < 0x72) return D_143230_0039F348[a2].fC >= 2;
        return 0;
    case 6:
        return D_1426E0[a2] != 0;
    case 7:
        if (a2 != 0) return ((s32 (*)())a2)() != 0;
    case 9:
        return (D_142BA0[(u32)a2 >> 2] & (1 << (a2 & 0x1F))) != 0;
    case 8:
        return D_1BBB18[(a2 & 0xFFFF) + (a2 >> 16) * 8] != 0;
    case 10:
        return func_00381D48_0039F348(a0, a2);
    case 11:
        return D_1D5570[a2] != 0;
    case 12:
        break;
    }
    return 0;
}
/* localdecomp:end func_0039F348 */
