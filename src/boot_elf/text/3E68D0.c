#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038CF58(void *, s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CF58();
extern void func_0038CF58(void *, int, int);
/* --- end of declarations from other files --- */

/* declarations of 3E5C60.c's earlier functions */
extern void *func_003E6A28();
extern s32 func_003E68D0(s32);
extern void func_003E69F0();

/* localdecomp:start func_003E68D0 */
extern s32 D_001D9650_003E68D0;
extern s32 D_001DA880_003E68D0;
extern s32 D_001DA894_003E68D0;
extern s32 D_001DA898_003E68D0;
extern s32 D_001DA8AC_003E68D0;
extern s32 D_001DA8B0_003E68D0;
extern s32 D_001DA8C4_003E68D0;
extern s32 D_001DA8C8_003E68D0;
extern s32 D_001DA8DC_003E68D0;
extern s32 D_001DA8E0_003E68D0;
extern s32 D_001DA8F4_003E68D0;

extern s32 *func_003E7238();
extern s32 func_003E6798();
s32 func_003E68D0(s32 a) {
    if (D_001DA894_003E68D0 == 0) {
        func_003E7238(&D_001DA880_003E68D0, 0, 0x3FF, 0, func_003E6798);
        D_001DA894_003E68D0 = 1;
    }
    if (D_001DA8AC_003E68D0 == 0) {
        func_003E7238(&D_001DA898_003E68D0, 0, 0x3FF, 1, func_003E6798);
        D_001DA8AC_003E68D0 = 1;
    }
    if (D_001DA8C4_003E68D0 == 0) {
        func_003E7238(&D_001DA8B0_003E68D0, 0, 0x3FF, 2, func_003E6798);
        D_001DA8C4_003E68D0 = 1;
    }
    if (D_001DA8DC_003E68D0 == 0) {
        func_003E7238(&D_001DA8C8_003E68D0, 0, 0x3FF, 3, func_003E6798);
        D_001DA8DC_003E68D0 = 1;
    }
    if (D_001DA8F4_003E68D0 == 0) {
        func_003E7238(&D_001DA8E0_003E68D0, 0, 0x3FF, 3, func_003E6798);
        D_001DA8F4_003E68D0 = 1;
    }
    return ((s32 *)&D_001D9650_003E68D0)[a];
}
/* localdecomp:end func_003E68D0 */

/* localdecomp:start func_003E69F0 */
void func_003E69F0(u8 *p) {
    func_0038CF58((s32)(p + 8), 0, 0x2000);
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003E69F0 */

/* localdecomp:start func_003E6A28 */
extern s32 *func_003F2748(s32 *);
void *func_003E6A28(void *p) {
    func_003F2748((s32 *)p);
    func_003E69F0(p);
    return p;
}
/* localdecomp:end func_003E6A28 */
