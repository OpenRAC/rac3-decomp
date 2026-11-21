#include "common.h"

/* NTSC-U counterpart of func_003B2E50 (src/frontbin/3B2E50.c): func_U_003E1D68 gets 0 where PAL passes 1 */
/* localdecomp:start func_U_003AD8A8 */
extern void func_U_003A4758();
extern s32 func_U_003E3F08();
extern void func_U_003E1D68(s32);
extern void *func_U_003E16B8();
extern s32 func_U_003E0550();
extern s32 func_U_003E1788();
extern s32 *func_U_003AED08();
extern void *func_U_003AED40(s32);
extern s32 *func_U_003AEDC8();
extern s32 *func_U_003AEDF8(s32);
extern s32 func_U_003E1460();
extern s32 func_U_003E17C0();
extern s32 func_U_003E18C0();
extern u8 D_U_001DA9B8[];
extern u8 D_U_0022A8A0[];
extern u8 D_U_0022A4A0[];
extern s32 *func_U_003AD820(s32 idx);
s32 func_U_003AD8A8(void) {
    s32 ok = 1;
    s32 i;
    s32 r;
    void *x;
    u8 *p;
    func_U_003A4758(1);
    func_U_003E3F08();
    func_U_003E1D68(0);
    func_U_003E16B8();
    p = D_U_001DA9B8;
    if (*(s32 *)(p + 0x4) != 0) {
        x = p;
    } else {
        x = func_U_003E16B8();
    }
    for (i = 0; i < 1; i++) {
        func_U_003E0550(func_U_003AD820(i), i);
        func_U_003E1788(x, i, func_U_003AD820(i));
    }
    func_U_003E1460(x, 0, func_U_003AED08());
    func_U_003E1460(x, 1, func_U_003AED40(0));
    func_U_003E1460(x, 2, func_U_003AED40(1));
    func_U_003E1460(x, 3, func_U_003AED40(2));
    func_U_003E1460(x, 4, func_U_003AED40(3));
    func_U_003E1460(x, 5, func_U_003AEDC8());
    func_U_003E1460(x, 6, func_U_003AEDF8(0));
    func_U_003E1460(x, 7, func_U_003AEDF8(1));
    func_U_003E1460(x, 8, func_U_003AEDF8(2));
    func_U_003E1460(x, 9, func_U_003AEDF8(3));
    r = func_U_003E17C0(x, 0, 0x400, D_U_0022A8A0, 0x10);
    ok = (ok != 0) & (r != 0);
    r = func_U_003E17C0(x, 1, 0x12000, D_U_0022A4A0, 0xC0);
    ok = (ok != 0) & (r != 0);
    func_U_003E18C0(x, 0);
    return ok;
}
/* localdecomp:end func_U_003AD8A8 */
