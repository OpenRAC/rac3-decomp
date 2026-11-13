#include "common.h"

/* NTSC-U counterpart of func_L01_00337E10 (src/levels/shared/L01_003326A8.c): 6 -> 7; 14 -> 17 */
extern u8 D_001A4BE0[];

/* localdecomp:start func_L01_003377B8 */
/* The wrench object's animation: sequence 11 while the hero is in state 0x37, else from
   sequences 11, 19 and 18 back to 1. Both blends go through one helper that skips the call
   when the moby already plays the sequence; the current sequence comes from an int accessor
   narrowed to a byte, which is what leaves retail's `andi` and its copy of the raw value. */
extern u8 D_001A4BE0[];
extern void func_003C3A10(u8 *, s32, s32, s32);

static inline s32 seq_00337E10(u8 *moby)
{
    return moby[0x43];
}

static inline void blend_00337E10(u8 *moby, s32 seq, s32 start, s32 frames)
{
    if (moby[0x43] != seq) {
        func_003C3A10(moby, seq, start, frames);
    }
}

void func_L01_003377B8(u8 *moby)
{
    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x37) {
        blend_00337E10(moby, 11, 0, 7);
    } else {
        u8 seq = seq_00337E10(moby);

        if (seq == 11 || seq == 19 || seq == 18) {
            blend_00337E10(moby, 1, 0, 17);
        }
    }
}
/* localdecomp:end func_L01_003377B8 */
