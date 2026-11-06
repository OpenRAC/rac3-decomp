#include "common.h"

/* localdecomp:start func_L30_004E2F50 */
extern u8 D_001A4BE0[];
extern void func_L30_004DC648(s32, s32, f32);
extern void func_L30_004CB6E0(s32, s32);

void func_L30_004E2F50(void) {
    u8 *global = D_001A4BE0;
    u8 *part = *(u8 **)(global + 0x25C0);
    s32 count = 0xE;
    s32 amount = 2;
    s32 pending;
    if (part[0x43] == 0x3A) {
        count = 0xB;
        amount = 5;
    }
    func_L30_004DC648(0x3A, count, (f32)amount);
    pending = *(s32 *)(global + 0x25CC);
    *(s16 *)(global + 0x1B3C) = 1;
    *(s16 *)(global + 0xBDC) = 0;
    if (pending != 2) {
        func_L30_004CB6E0(0x9C, 0);
    }
    *(s16 *)(global + 0x1E0) = 0x14;
}
/* localdecomp:end func_L30_004E2F50 */
