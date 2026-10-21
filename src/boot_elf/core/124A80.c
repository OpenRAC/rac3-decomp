#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 124988.c's earlier functions (tools/port_from_us.py) */
typedef struct { s32 pad0; s32 f4; s32 f8; s32 fc; s32 f10; void *f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; s32 f2c; s32 f30; void *f34; } S_124988;
extern s32 D_0013E310[];
extern s32 D_0013E314[];
extern u8 D_00150DC0[];
extern u8 D_00150DD0[];
extern s32 func_0011EE20(void *);

/* localdecomp:start func_00124A80 */
extern u32 D_0013E300[4];
extern u32 D_0013E2F8;
extern void func_00124B80(u32, u32);
extern u32 func_00124A68(u32, u32, void *);
extern void func_00124A28(void);
extern void func_001249F0(void);

void func_00124A80(void) {
    u32 a;
    u32 b;
    u32 pa;
    u32 pb;

    func_00124B80(D_0013E300[0], D_0013E300[1]);
    func_00124B80(D_0013E300[2], D_0013E300[3]);
    a = func_00124A68(0x80000000, 0x80080000, func_00124A28);
    b = func_00124A68(0x80000000, 0x80080000, func_001249F0);
    pa = a - 0x20C;
    pb = b - 0x168;
    while (pa != pb) {
        if (pa < pb) {
            a = func_00124A68(a + 4, 0x80080000, func_00124A28);
            pa = a - 0x20C;
        } else {
            b = func_00124A68(b + 4, 0x80080000, func_001249F0);
            pb = b - 0x168;
        }
    }
    D_0013E2F8 = pa;
}
/* localdecomp:end func_00124A80 */
