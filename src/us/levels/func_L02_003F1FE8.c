#include "common.h"

/* NTSC-U counterpart of func_L02_003F4BE8 (src/levels/shared/L02_003F4BE8.c) */
typedef struct State_003F4BE8 {
    u8 pad[0x1BC];
    u16 count;
    u16 pad1;
    u32 time;
    u32 flags;
} State_003F4BE8;

/* localdecomp:start func_L02_003F1FE8 */
extern State_003F4BE8 D_001A7C10;
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern s32 func_L01_0050FF18(void);
extern void func_L01_00417F60(s32, s32);

void func_L02_003F1FE8(s32 id, u32 delay)
{
    if (func_L01_0050FF18()) return;
    if (D_001A7C10.count && delay >= (u32)D_001D4C38 - D_001A7C10.time) return;
    if (id == 0xB76) func_L01_00417F60(0xB76, 0x19);
    else if (id == 0xCD6) func_L01_00417F60(0xCD6, 0x7F);
    else if (id == 0xCD7) func_L01_00417F60(0xCD7, 0x80);
    else if (id == 0xCD8) func_L01_00417F60(0xCD8, 0x81);
    if (D_001A7C10.count < 0xFFFF) D_001A7C10.count++;
    if ((u32)D_001D4C38 > D_001A7C10.time)
        D_001A7C10.time = D_001D4C38;
    {
        u32 bit = 1 << D_001D545C;
        u32 flags = D_001A7C10.flags;
        flags |= bit;
        flags |= 0x80000000;
        D_001A7C10.flags = flags;
    }
}
/* localdecomp:end func_L02_003F1FE8 */
