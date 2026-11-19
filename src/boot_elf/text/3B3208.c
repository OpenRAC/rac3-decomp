#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B2DB8.c's earlier functions */
extern s32 *func_003B3180(s32 idx);

/* localdecomp:start func_003B3208 */
extern void func_003AA060_003B3208(s32);
extern s32 func_003E9828(void);
extern void func_003E7670(s32);
extern void *func_003E6FC0();
extern u8 D_001DA938[];
extern s32 func_003E5E58();
extern s32 func_003E7090();
extern s32 *func_003B4678();
extern void *func_003B46B0(s32);
extern s32 *func_003B4738();
extern s32 *func_003B4768();
extern s32 func_003E6D68();
extern s32 func_003E70C8();
extern s32 func_003E71C8();
extern u8 D_0022E820[];
extern u8 D_0022E420[];

s32 func_003B3208(void) {
    s32 ok = 1;
    void *p;
    s32 i;
    s32 r;
    s32 t;
    u8 *x;

    func_003AA060_003B3208(1);
    func_003E9828();
    func_003E7670(1);
    func_003E6FC0();
    x = D_001DA938;
    if (*(s32 *)(x + 4) != 0) {
        p = x;
    } else {
        p = func_003E6FC0();
    }
    r = ok != 0;
    for (i = 0; i < 1; i++) {
        func_003E5E58(func_003B3180(i), i);
        func_003E7090(p, i, func_003B3180(i));
    }
    func_003E6D68(p, 0, func_003B4678());
    func_003E6D68(p, 1, func_003B46B0(0));
    func_003E6D68(p, 2, func_003B46B0(1));
    func_003E6D68(p, 3, func_003B46B0(2));
    func_003E6D68(p, 4, func_003B46B0(3));
    func_003E6D68(p, 5, func_003B4738());
    func_003E6D68(p, 6, func_003B4768(0));
    func_003E6D68(p, 7, func_003B4768(1));
    func_003E6D68(p, 8, func_003B4768(2));
    func_003E6D68(p, 9, func_003B4768(3));
    t = func_003E70C8(p, 0, 0x400, D_0022E820, 0x10) != 0;
    ok = r & t;
    t = func_003E70C8(p, 1, 0x12000, D_0022E420, 0xC0) != 0;
    ok = ok & t;
    func_003E71C8(p, 0);
    return ok;
}
/* localdecomp:end func_003B3208 */
