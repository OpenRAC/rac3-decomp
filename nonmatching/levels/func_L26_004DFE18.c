/* near miss (level 26: 55 diff with @ps2as, needs @ps2as) */
#include "common.h"

/* localdecomp:start func_L26_004DFE18 */
extern u8 D_00142430[];
extern s32 D_L26_001DF600;
extern s32 D_001D4BC4;
extern s32 D_L26_001DF7C8;
extern f32 D_L26_001DB7A0;
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389370(void);
extern void func_0038AE20(s32, s32, s32, s32);

void func_L26_004DFE18(void) {
    f32 a;
    f32 b;
    f32 c;
    long r;

    if ((u32)(*(s32 *)(D_00142430 + 0x15C) - 0xF) < 2 || *(s32 *)(D_00142430 + 0x164) == 0xF || D_L26_001DF600 != 0) {
        c = 272.0f;
        func_00389240(1);
        func_003A9440(0x42, 0x8000000044UL);
        func_003A9440(0x47, 0x3004B);
        r = func_00389598(3);
        func_0038B4D0(0x2C, D_001D4BC4 - 0x60, 0x40, 0x40, 0, 0, 0x40, 0x40, 0x80808080, r);
        b = (f32)((D_001D4BC4 - 0x40) << 4);
        a = (f32)(D_L26_001DF7C8 % 0x37) * -6.2831855f / 55.0f;
        func_00397638(1216.0f, b, c, c, a, 0x40, 0x40, func_00389598(4));
        func_00389370();
        if ((u32)(*(s32 *)(D_00142430 + 0x15C) - 0xF) < 2) {
            D_L26_001DF600 = 0x19;
        } else if (*(s32 *)(D_00142430 + 0x164) == 0xF) {
            D_L26_001DF600 = 0x19;
        } else {
            D_L26_001DF600 = D_L26_001DF600 - 1;
        }
    }
    func_003A9440(0x42, 0x8000000044UL);
    func_0038AE20(0, 0, 0, (s32)(D_L26_001DB7A0 * 128.0f));
}
/* localdecomp:end func_L26_004DFE18 */
