#include "common.h"

/* NTSC-U counterpart of func_L39_005DB1A8 (src/levels/shared/L39_005DA870.c): 100 -> 120 */
extern void func_003E82F8_005D8C00(s32);
extern void func_L01_005131A0(s32, s32);
extern void func_L01_005130C8(s32, s32);

/* localdecomp:start func_L39_005D8C00 */
typedef struct {
    u8 pad0[0x12];
    u16 h12;
    u8 pad14[0x6C];
} S_005DB1A8;
extern S_005DB1A8 D_L39_0049C950[];
extern s32 D_001D7F90_sda[2];
extern void func_003E82F8_005D8C00(s32);
extern s32 func_L01_00512D70(s32, s32);
extern void func_L01_005131A0(s32, s32);
extern void func_L01_005130C8(s32, s32);

void func_L39_005D8C00(s32 *a0, s32 a1)
{
    s32 vals[9];
    u8 flags[9];
    s32 n = 0;
    s32 i;
    s32 m;
    s32 k;
    s32 j;
    s32 start;
    s32 end;
    S_005DB1A8 *e = D_L39_0049C950;

    for (m = 0; m < 16 && n < 9; m++) {
        if (a0[m] != 0) {
            vals[n] = e[m].h12;
            flags[n] = a0[m] == 2;
            n++;
        }
    }
    if (n != 0) {
        func_003E82F8_005D8C00(a1);
        for (i = 0; i <= 16; i++)
            func_L01_00512D70(0x2001B + i, 0);
        func_L01_00512D70(0x20019, n & 1);
        func_L01_00512D70(0x2001A, (n ^ 1) & 1);
        start = 9 - n;
        end = n + 7;
        k = start;
        for (; k <= end; k += 2) {
            func_L01_00512D70(0x2001B + k, 1);
            j = (k - start) >> 1;
            func_L01_005131A0(0x2001B + k, vals[j]);
            if (flags[j])
                func_L01_005130C8(0x2001B + k, 0x70D04040);
            else
                func_L01_005130C8(0x2001B + k, 0x706EC8FF);
        }
        D_001D7F90_sda[a1] = 120;
    }
}
/* localdecomp:end func_L39_005D8C00 */
