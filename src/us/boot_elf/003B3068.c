#include "common.h"

/* NTSC-U counterpart of func_003B3208 (src/boot_elf/text/3B3208.c): func_003E7670 is called with 0, not 1 */
/* localdecomp:start func_U_003B3068 */
extern void func_U_003A9F18(s32);
extern s32 func_U_003E96C8(void);
extern void func_U_003E7528(s32);
extern void *func_U_003E6E78();
extern u8 D_U_001DA9B8[];
extern s32 func_U_003E5D10();
extern s32 func_U_003E6F48();
extern s32 *func_U_003B44C8();
extern void *func_U_003B4500(s32);
extern s32 *func_U_003B4588();
extern s32 *func_U_003B45B8();
extern s32 func_U_003E6C20();
extern s32 func_U_003E6F80();
extern s32 func_U_003E7080();
extern u8 D_U_0022E8A0[];
extern u8 D_U_0022E4A0[];
extern s32 *func_U_003B2FE0(s32 idx);

s32 func_U_003B3068(void) {
    s32 ok = 1;
    void *p;
    s32 i;
    s32 r;
    s32 t;
    u8 *x;

    func_U_003A9F18(1);
    func_U_003E96C8();
    func_U_003E7528(0);
    func_U_003E6E78();
    x = D_U_001DA9B8;
    if (*(s32 *)(x + 4) != 0) {
        p = x;
    } else {
        p = func_U_003E6E78();
    }
    r = ok != 0;
    for (i = 0; i < 1; i++) {
        func_U_003E5D10(func_U_003B2FE0(i), i);
        func_U_003E6F48(p, i, func_U_003B2FE0(i));
    }
    func_U_003E6C20(p, 0, func_U_003B44C8());
    func_U_003E6C20(p, 1, func_U_003B4500(0));
    func_U_003E6C20(p, 2, func_U_003B4500(1));
    func_U_003E6C20(p, 3, func_U_003B4500(2));
    func_U_003E6C20(p, 4, func_U_003B4500(3));
    func_U_003E6C20(p, 5, func_U_003B4588());
    func_U_003E6C20(p, 6, func_U_003B45B8(0));
    func_U_003E6C20(p, 7, func_U_003B45B8(1));
    func_U_003E6C20(p, 8, func_U_003B45B8(2));
    func_U_003E6C20(p, 9, func_U_003B45B8(3));
    t = func_U_003E6F80(p, 0, 0x400, D_U_0022E8A0, 0x10) != 0;
    ok = r & t;
    t = func_U_003E6F80(p, 1, 0x12000, D_U_0022E4A0, 0xC0) != 0;
    ok = ok & t;
    func_U_003E7080(p, 0);
    return ok;
}
/* localdecomp:end func_U_003B3068 */
