#include "common.h"

/* localdecomp:start func_L01_003B1788 */
extern void func_L01_003B1858(u8 *, u8 *);
extern s32 func_00388398(void *);
extern s32 func_L01_003B1EB0(u8 *, u8 *);
extern void func_L01_003B29E8(u8 *, u8 *);
extern s32 func_L01_003B2450(u8 *, u8 *);
extern void func_L01_003B2A48(u8 *, u8 *);
extern void func_L01_003B3580(u8 *, u8 *);

void func_L01_003B1788(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);

    if (a0[0x20] == 0) {
        func_L01_003B1858(a0, st);
    }
    switch (a0[0x20]) {
    case 1:
        *(u16 *)(a0 + 0x34) |= 2;
        break;
    case 2:
        if (func_00388398(st + 0x2C) != 0) {
            *(s32 *)(st + 0x2C) = 6;
            if (func_L01_003B1EB0(a0, st) != 0) {
                func_L01_003B29E8(a0, st);
                return;
            }
            if (func_L01_003B2450(a0, st) != 0) {
                func_L01_003B2A48(a0, st);
                return;
            }
        }
        func_L01_003B3580(a0, st);
        break;
    }
}
/* localdecomp:end func_L01_003B1788 */
