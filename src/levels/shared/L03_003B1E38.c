#include "common.h"

/* localdecomp:start func_L03_003B1E38 */
typedef int Q_003B1E38 __attribute__((mode(TI)));
extern s32 D_001D6694;
__asm__(".extern D_001D6694, 16");
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern u8 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern s32 func_L01_004BA800(void);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L03_003B2158(void *);
extern void func_L03_003B2518(void *);

void func_L03_003B1E38(u8 *obj) {
    u8 *v;
    u8 *p;

    v = *(u8 **)(obj + 0x68);
    if (D_001D6694 == 2) {
        obj[0x31] = 0;
        *(u16 *)(obj + 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        obj[0x31] = 1;
        *(u16 *)(obj + 0x34) &= ~1;
    }
    switch (obj[0x20]) {
    case 0:
        if (D_001426E0[0x3D] != 0 && D_001426E0[0x85] == 0) {
            p = D_L03_001DFA80 + (*(s32 *)(v + 0x120) << 7);
            *(Q_003B1E38 *)(obj + 0x10) = *(Q_003B1E38 *)(p + 0x30);
            *(Q_003B1E38 *)(obj + 0xF0) = *(Q_003B1E38 *)(p + 0x70);
            if (obj[0x43] != 0) {
                func_003C3A10(obj, 0, 0, 8);
            }
            func_L01_004450F0(obj, 1, -1);
        } else if (D_00142CA0[0x1E] != 0) {
            if (obj[0x43] != 1) {
                func_003C3A10(obj, 1, 0, 8);
            }
            func_L01_004450F0(obj, 2, -1);
        } else {
            func_003C2880(obj);
            return;
        }
        break;
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(obj)) {
            if (obj[0x43] != 1) {
                func_003C3A10(obj, 1, 0, 8);
            }
            *(s32 *)(v + 0x12C) = (func_00382498(600, 800) * 5 + 2) / 6;
        }
        if (*(s32 *)(v + 0x114) == 0 && func_0038CAD0(v + 0x12C)) {
            *(s32 *)(v + 0x12C) = (func_00382498(600, 800) * 5 + 2) / 6;
            if (obj[0x43] != 2) {
                func_003C3A10(obj, 2, 0, 0x11);
            }
        }
        if ((obj[0x60] & 2) && obj[0x43] != 1) {
            func_003C3A10(obj, 1, 0, 0x11);
        }
        break;
    case 3:
        if (func_L01_004561B8(obj) && obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 8);
        }
        break;
    case 4:
        if (func_L01_004561B8(obj) && obj[0x43] != 4) {
            func_003C3A10(obj, 4, 0, 8);
        }
        break;
    case 5:
        if (func_L01_004561B8(obj) && obj[0x43] != 5) {
            func_003C3A10(obj, 5, 0, 8);
        }
        break;
    }
    func_L03_003B2158(obj);
    if (D_00142CA0[0x1E] != 0 && obj[0x20] != 1) {
        func_L03_003B2518(obj);
    }
}
/* localdecomp:end func_L03_003B1E38 */

INCLUDE_ASM("asm/levels", func_L03_003B2158);
