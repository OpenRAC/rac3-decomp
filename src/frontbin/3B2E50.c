#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003B2E50(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B2A00.c's earlier functions */
extern s32 *func_003B2DC8(s32 idx);

/* localdecomp:start func_003B2E50 */
extern void func_003A9CA8();
extern s32 func_003E9470();
extern void func_003E72B8(s32);
extern void *func_003E6C08();
extern s32 func_003E5AA0();
extern s32 func_003E6CD8();
extern s32 *func_003B42C0();
extern void *func_003B42F8(s32);
extern s32 *func_003B4380();
extern s32 *func_003B43B0(s32);
extern s32 func_003E69B0();
extern s32 func_003E6D10();
extern s32 func_003E6E10();
extern u8 D_001DA938[];
extern u8 D_0022E820[];
extern u8 D_0022E420[];
s32 func_003B2E50(void) {
    s32 ok = 1;
    s32 i;
    s32 r;
    void *x;
    u8 *p;
    func_003A9CA8(1);
    func_003E9470();
    func_003E72B8(1);
    func_003E6C08();
    p = D_001DA938;
    if (*(s32 *)(p + 0x4) != 0) {
        x = p;
    } else {
        x = func_003E6C08();
    }
    for (i = 0; i < 1; i++) {
        func_003E5AA0(func_003B2DC8(i), i);
        func_003E6CD8(x, i, func_003B2DC8(i));
    }
    func_003E69B0(x, 0, func_003B42C0());
    func_003E69B0(x, 1, func_003B42F8(0));
    func_003E69B0(x, 2, func_003B42F8(1));
    func_003E69B0(x, 3, func_003B42F8(2));
    func_003E69B0(x, 4, func_003B42F8(3));
    func_003E69B0(x, 5, func_003B4380());
    func_003E69B0(x, 6, func_003B43B0(0));
    func_003E69B0(x, 7, func_003B43B0(1));
    func_003E69B0(x, 8, func_003B43B0(2));
    func_003E69B0(x, 9, func_003B43B0(3));
    r = func_003E6D10(x, 0, 0x400, D_0022E820, 0x10);
    ok = (ok != 0) & (r != 0);
    r = func_003E6D10(x, 1, 0x12000, D_0022E420, 0xC0);
    ok = (ok != 0) & (r != 0);
    func_003E6E10(x, 0);
    return ok;
}
/* localdecomp:end func_003B2E50 */
