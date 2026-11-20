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

/* declared by functions of L02_003C5150.c, which this file was cut from */
extern Sp_003C5150 *D_L02_001DE184;
extern s32 D_001A71AC[];

/* localdecomp:start func_L02_003C5C48 */
typedef struct {
    char pad0[0x36C];
    s16 f36C;
    char pad1[0x280C - 0x36E];
    s32 f280C;
} S_003C5C48;
extern u8 D_001A71C4[];
extern S_003C5C48 D_001A4BE0;
extern s32 D_001D545C;
extern void func_L02_003C5310(u8 *);

s32 func_L02_003C5C48(u8 *moby) {
    u8 *st = D_L02_001DE184[*(s16 *)(moby + 0x84)].st;

    if (*(s16 *)(st + 0x48) == 1 && *(s16 *)(st + 0x4A) != 0) {
        return 0;
    }
    if (*(s16 *)(st + 0x2C) == 11 && D_001A71C4[0] != 2) {
        return 0;
    }
    if (*(s16 *)(st + 0x2C) == 1 || *(s16 *)(st + 0x2C) == 10) {
        if (*(s16 *)(st + 0x2E) == 0) {
            if (D_001A4BE0.f36C != 0) {
                if (D_001D545C != 14) {
                    return 0;
                }
                if (D_001A4BE0.f280C != 13) {
                    return 0;
                }
            }
        }
    }
    if (*(s16 *)(st + 0x2C) == 2 && D_001A71AC[0] != 26) {
        *(s16 *)(st + 0x2E) = 0;
    } else {
        func_L02_003C5310(moby);
    }
    return 0;
}
/* localdecomp:end func_L02_003C5C48 */
