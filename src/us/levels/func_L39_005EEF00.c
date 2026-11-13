#include "common.h"

/* NTSC-U counterpart of func_L39_005F1470 (src/levels/shared/L39_005F1470.c) */
/* localdecomp:start func_L39_005EEF00 */
typedef struct { s32 cur[8]; s32 prev[8]; u8 pad40[0x1B20 - 0x40]; s32 f1B20; } S_005F1470;
extern u8 D_L39_001FE1A0[];
extern s32 D_001A5990[];
extern void func_003885F0(void *, void *, s32);

void func_L39_005EEF00(void) {
    s32 i;
    func_003885F0(((S_005F1470 *)D_L39_001FE1A0)->prev, ((S_005F1470 *)D_L39_001FE1A0)->cur, 0x20);
    ((S_005F1470 *)D_L39_001FE1A0)->cur[0] = D_001A5990[4] * 7 / 10;
    ((S_005F1470 *)D_L39_001FE1A0)->cur[1] = D_001A5990[3];
    ((S_005F1470 *)D_L39_001FE1A0)->cur[2] = D_001A5990[4];
    ((S_005F1470 *)D_L39_001FE1A0)->cur[3] = D_001A5990[4] * 6 / 10;
    ((S_005F1470 *)D_L39_001FE1A0)->cur[4] = D_001A5990[4] * 6 / 10;
    ((S_005F1470 *)D_L39_001FE1A0)->cur[5] = D_001A5990[4] * 25 / 32;
    {
        s32 *p = ((S_005F1470 *)D_L39_001FE1A0)->prev;
        s32 *q = ((S_005F1470 *)D_L39_001FE1A0)->cur;
        for (i = 0; i < 6; i++) {
            s32 bit = 1;
            if (*p++ == *q++) {
                bit = 0;
            }
            ((S_005F1470 *)D_L39_001FE1A0)->f1B20 |= bit << i;
        }
    }
}
/* localdecomp:end func_L39_005EEF00 */
