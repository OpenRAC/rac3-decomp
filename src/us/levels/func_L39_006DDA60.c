#include "common.h"

/* NTSC-U counterpart of func_L39_006E05C0 (src/levels/39_multiplayer_menu/L39_006E0298.c) */
#include "vu0.h"

/* localdecomp:start func_L39_006DDA60 */
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    char pad60[0x8C - 0x60];
    s32 count;
    char pad90[0xA4 - 0x90];
} S_006E05C0_Ent;
typedef struct {
    s32 sel[0x1C8 / 4];
    S_006E05C0_Ent ent[8];
} S_006E05C0;
extern S_006E05C0 D_L39_001FDA88;
extern f32 D_001A6AD0[];

f32 func_L39_006DDA60(s32 arg0) {
    s32 skip = D_L39_001FDA88.sel[arg0];
    f32 num = 0.0f;
    f32 den = num;
    s32 i;

    for (i = 0; i < 8; i++) {
        s32 j;
        if (skip != i) {
            for (j = 0; j < *(&D_L39_001FDA88.ent[i].count); j++) {
                f32 w = D_001A6AD0[0xDC / 4] - (D_L39_001FDA88.ent + i)->b[j] + D_001A6AD0[0xE4 / 4];
                num += D_L39_001FDA88.ent[i].a[j] * w;
                den += w;
            }
        }
    }
    return num / den;
}
/* localdecomp:end func_L39_006DDA60 */
