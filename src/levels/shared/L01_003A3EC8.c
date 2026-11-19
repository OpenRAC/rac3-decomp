#include "common.h"

typedef void (*fn_3A2780)(u8 *);

/* localdecomp:start func_L01_003A3EC8 */

extern fn_3A2780 *func_L01_0043B548(s32, s32);
extern void func_L01_003A4810(u8 *);
extern void func_003C2880(u8 *);

void func_L01_003A3EC8(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3A2780 *tbl;
    if (*(s32 *)(pv + 576) != 0) {
        tbl = func_L01_0043B548(6625, 108);
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else if (*(s32 *)(pv + 1052) != 0) {
        func_L01_003A4810(a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003A3EC8 */

/* localdecomp:start func_L01_003A3F68 */
extern s32 D_001D545C;
extern s32 D_L01_001D67AC_003A3F68;
extern s32 D_L01_001D67B4_003A3F68;
extern s32 D_L01_001D67C0_003A3F68;
extern u8 D_L01_001D66B0_003A3F68[] __attribute__((section(".sdata")));
extern u8 D_00142758[];
extern void func_L01_00459C50(s32);
extern void func_L01_00452310(void *, f32, f32, s32, f32, void *, s32, s32, f32, f32, s32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern s32 func_0039EF28(void);
extern void func_003A52A0(s32, s32, u8 *);

void func_L01_003A3F68(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    s16 h;
    if (D_001D545C == 4 && *(u8 **)(v + 0x48) != 0 &&
        (*(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x185E || *(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x11C1)) {
        D_00142758[0] = 1;
        func_0039EF28();
        if (++D_L01_001D67AC_003A3F68 >= 25) func_L01_00459C50(6);
    } else if (D_001D545C == 12 && *(u8 **)(v + 0x48) != 0 && v[0x47] == 9) {
        if (++D_L01_001D67B4_003A3F68 >= 20) func_L01_00459C50(15);
    } else if (D_001D545C == 18 && *(u8 **)(v + 0x48) != 0 &&
               (*(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x185E || *(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x11C1)) {
        if (++D_L01_001D67C0_003A3F68 >= 20) func_L01_00459C50(21);
    }
    if (v[0x5E] == 0) {
        func_003A52A0(11, 0, obj);
        h = *(s16 *)(obj + 0xAA);
        if (D_001D545C == 1 && *(s32 *)(v + 0x42C) != 0 && *(s32 *)(v + 0x3C0) != 0) {
            *(s16 *)(obj + 0xAA) = 0x1F02;
        }
        func_L01_00452310(obj, 0.75f, 3.0f, 0x7FFF, 6.0f, D_L01_001D66B0_003A3F68, 1, 20, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
        if (D_001D545C == 1 && *(s32 *)(v + 0x42C) != 0 && *(s32 *)(v + 0x3C0) != 0) {
            *(s16 *)(obj + 0xAA) = h;
        }
    }
    func_L01_004443E8(obj, 0, 3);
}
/* localdecomp:end func_L01_003A3F68 */

INCLUDE_ASM("asm/levels", func_L01_003A4180);

/* localdecomp:start func_L01_003A4320 */
extern u16 *D_L01_0021DE20_003A4320[];
extern u8 *D_L01_001E001C_003A4320;
__asm__(".extern D_L01_001E001C_003A4320, 16");
extern s32 D_L01_001E0058_003A4320;
extern void func_L01_00445BE0_003A4320(s32 a0, s32 a1);

void func_L01_003A4320(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    func_L01_00445BE0_003A4320(a0[0x21], 0);
    p = D_L01_0021DE20_003A4320[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L01_001E0058_003A4320 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L01_0021DE20_003A4320[a0[0x21]])) {
        e = D_L01_001E001C_003A4320 + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2E8) = 1;
        }
    }
}
/* localdecomp:end func_L01_003A4320 */


INCLUDE_ASM("asm/levels", func_L01_003A43F8);
