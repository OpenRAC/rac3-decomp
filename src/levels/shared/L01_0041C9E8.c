#include "common.h"

/* localdecomp:start func_L01_0041C9E8 */
typedef struct {
    u8 pad0[108];
    s32 x6C;
    u8 pad70[12];
    s32 x7C;
    u8 pad80[16];
} Entry_0041A2E0;

extern Entry_0041A2E0 D_L01_002E60D0[];
extern void func_00393348(s32, s32, s32, s32, s32, s32, s32);
extern void func_00393450(Entry_0041A2E0 *);

void func_L01_0041C9E8(void)
{
    s32 i;

    for (i = 0; i < 13; i++) {
        func_00393348(i, 0xFFFF, 0, 0, 0, 0, 1);
        D_L01_002E60D0[i].x7C = 0;
        D_L01_002E60D0[i].x6C = -6;
        func_00393450(&D_L01_002E60D0[i]);
    }
}
/* localdecomp:end func_L01_0041C9E8 */
