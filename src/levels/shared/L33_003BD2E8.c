#include "common.h"

/* localdecomp:start func_L33_003BD2E8 */
extern void func_L33_003BD798();
extern void func_L33_003BD828(u8 *);
extern void func_L33_003BD7C8(u8 *);
extern void func_L33_003BD5F8(u8 *);
extern void func_L33_003BD978(u8 *);
extern void func_L33_003BDA58(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L33_003BD2E8(u8 *a0) {
    switch (a0[0x20]) {
    case 1:
        func_L33_003BD798(a0);
        break;
    case 2:
        func_L33_003BD828(a0);
        break;
    case 3:
        func_L33_003BD7C8(a0);
        break;
    case 0:
        func_L33_003BD5F8(a0);
        func_L01_004450F0(a0, 5, -1);
        break;
    case 4:
        func_L33_003BD978(a0);
        break;
    case 5:
        func_L33_003BDA58(a0);
        break;
    }
}
/* localdecomp:end func_L33_003BD2E8 */
