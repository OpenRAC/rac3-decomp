#include "common.h"

typedef struct {
    u8 pad0[0x50];
    u8 *p50;
    u8 pad54[0x460 - 0x54];
} Ent_003C5150;
typedef struct {
    u8 pad0[0x1C];
    u8 *st;
} Sp_003C5150;

/* localdecomp:start func_L02_003C5150 */
extern Ent_003C5150 D_L02_001E1300[];

extern Sp_003C5150 *D_L02_001DE184;
extern u8 *D_L02_0021C700[];
extern u8 D_001A4C60[];
extern s32 D_001A71AC[];
extern s32 D_001A73EC[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_0044BFC8(void *, s32);
extern s32 func_L01_0044C078(void *, s32);
extern s32 func_L01_004463F8(void *, void *, s32);

s32 func_L02_003C5150(u8 *moby) {
    s32 force = 0;
    u8 *g = ((Ent_003C5150 *)((u8 *)D_L02_001E1300 + *(s32 *)(moby + 0x94) * 0x460))->p50;
    u8 *st = D_L02_001DE184[*(s16 *)(moby + 0x84)].st;
    if (*(s16 *)(g + 0x86)) return 0;
    if (*(s16 *)(st + 0x2C) == 2 && D_001A71AC[0] == 0x1A && *(s16 *)(st + 0x2E) > 0) force = 1;
    else if (*(s16 *)(st + 0x2C) == 4 && D_001A73EC[0] == 3) force = *(s16 *)(st + 0x2E) > 0;
    if (*(s32 *)(st + 0xC) >= 0 && (force || func_00382380(D_001A4C60, *(s32 *)(st + 0xC), 0))) return 1;
    if (*(s32 *)(st + 0x4C) >= 0 && (force || func_00382380(D_001A4C60, *(s32 *)(st + 0x4C), 0))) return 1;
    if (*(s32 *)(st + 0x10) >= 0 && (force || func_L01_0044BFC8(D_001A4C60, *(s32 *)(st + 0x10)))) return 1;
    if (*(s32 *)(st + 8) >= 0 && (force || func_L01_0044C078(D_001A4C60, *(s32 *)(st + 8)))) return 1;
    if (*(s32 *)(st + 0x14) >= 0) {
        if (force || func_L01_004463F8(D_001A4C60, D_L02_0021C700[*(s32 *)(st + 0x14)] + 16,
                                       *(s32 *)D_L02_0021C700[*(s32 *)(st + 0x14)])) return 1;
    }
    return 0;
}
/* localdecomp:end func_L02_003C5150 */

INCLUDE_ASM("asm/levels", func_L02_003C5310);

INCLUDE_ASM("asm/levels", func_L02_003C5C48);
