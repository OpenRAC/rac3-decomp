#include "common.h"

/* NTSC-U counterpart of func_L39_00672248 (src/levels/shared/L39_00672248.c) */
/* localdecomp:start func_L39_0066F8F8 */
typedef struct { u8 p0[0x1A14]; u8 b1A14; u8 p1A15[0xB33]; s32 w2548; u8 p254C[0xC]; s32 *w2558; } O_00672248;
typedef struct { u8 p0[0x88]; f32 f88[8]; u8 pA8[0x14]; u8 bBC; u8 bBD; } G_00672248;
extern G_00672248 D_001A5E50;
extern O_00672248 *D_L39_0024CF20[] __attribute__((section(".sdata")));
extern f32 D_001A6BDC[];
extern f32 D_001A6BC8[];
extern u8 *D_L39_002417C0_0066F8F8[] __attribute__((section(".sdata")));
extern void *func_0011D534(void *, s32, s32);
extern s32 func_00197640(s32);
extern void func_001962F8(void);

void func_L39_0066F8F8(void) {
    u8 seen[8];
    s32 i;
    s32 j;
    s32 n = 0;
    s32 teams = 0;
    s32 k = 0;

    func_0011D534(seen, 0, 8);
    D_001A5E50.bBD = 1;
    for (i = 0; i < 8; i++) {
        if (D_L39_0024CF20[i] != 0) {
            s32 first;
            s32 second;
            if (seen[D_L39_0024CF20[i]->w2548] == 0) {
                seen[D_L39_0024CF20[i]->w2548] = 1;
                teams++;
            }
            n++;
            first = *D_L39_0024CF20[i]->w2558;
            second = D_L39_0024CF20[i]->w2548;
            if (D_L39_0024CF20[i]->b1A14 != 0) k++;
            j = i + 1;
            while (j < 8) {
                if (D_L39_0024CF20[j] != 0 && *D_L39_0024CF20[j]->w2558 == first) {
                    if (D_L39_0024CF20[j]->w2548 != second) {
                        D_001A5E50.bBD = 0;
                        break;
                    }
                }
                j++;
            }
        }
    }
    if (k >= 2 && D_001A6BDC[0] <= 0.0f) D_001A5E50.bBD = 0;
    if (D_001A5E50.bBD == 0 || n < 2 || teams < 2) D_001A5E50.bBD = 0;
    D_001A5E50.bBC = 1;
    if (D_001A5E50.bBD != 0) {
        s32 r = func_00197640(*(s32 *)(D_L39_002417C0_0066F8F8[0] + 0x180));
        D_001A5E50.f88[r] -= D_001A6BC8[0];
        func_001962F8();
    }
}
/* localdecomp:end func_L39_0066F8F8 */
