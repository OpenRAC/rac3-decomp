#include "common.h"

/* localdecomp:start func_L24_00356100 */
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
void func_L24_00356100(u8 *a0, u8 *a1) {
    if (*(s32 *)(a1 + 0x8E0) > 0) {
        *(f32 *)(a1 + 0x8EC) = 3.1415927f;
    } else {
        *(f32 *)(a1 + 0x8EC) = 0.0f;
    }
    func_L01_00448890(a0 + 0xF8, a1 + 0x8E8, 0, *(f32 *)(a1 + 0x8EC), 0.31415927f, 0.31415927f, 0.34906587f);
}
/* localdecomp:end func_L24_00356100 */

INCLUDE_ASM("asm/levels", func_L24_00356168);

INCLUDE_ASM("asm/levels", func_L24_003572D8);

/* localdecomp:start func_L24_00357588 */
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);

void func_L24_00357588(u8 *obj, s32 a1, s32 a2, s32 a3, f32 scale) {
    u8 buf[16];

    func_003C2F58(obj, a2, buf);
    func_L01_00446780(obj, buf, 0x10000, 0, 1, 0, scale, (f32)a3, 1.0f);
}
/* localdecomp:end func_L24_00357588 */

/* localdecomp:start func_L24_00357600 */
void func_L24_00357600(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    *(s32 *)(s + 0x8C0) = 0x7F96006B;
    *(s32 *)(s + 0x8C4) = 0x6FFFFFFF;
    *(s32 *)(s + 0x8C8) = 0x2096006B;
    *(s32 *)(s + 0x8CC) = 0x450030;
}
/* localdecomp:end func_L24_00357600 */

INCLUDE_ASM("asm/levels", func_L24_00357638);

/* localdecomp:start func_L24_003577D0 */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
__asm__(".extern D_L24_001DD598, 4");
__asm__(".extern D_L24_001DD59C, 4");
__asm__(".extern D_L24_001DD5A0, 4");
__asm__(".extern D_L24_001DD5A4, 4");
__asm__(".extern D_L24_001DD5A8, 4");
__asm__(".extern D_L24_001DD5AC, 4");
__asm__(".extern D_L24_001DD5B0, 4");
__asm__(".extern D_L24_001DD5B4, 4");
extern u32 D_L24_001DD598;
extern f32 D_L24_001DD59C;
extern f32 D_L24_001DD5A0;
extern u32 D_L24_001DD5A4;
extern f32 D_L24_001DD5A8;
extern f32 D_L24_001DD5AC;
extern u32 D_L24_001DD5B0;
extern f32 D_L24_001DD5B4;

void func_L24_003577D0(u8 *obj) {
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 m1[16];
    f32 m2[16];
    f32 s;

    func_003C2F58(obj, 5, a);
    func_003C2EC0(obj, 6, m1);
    func_003C2EC0(obj, 7, m2);
    func_0038CF68(b, m1, D_L24_001DD5A0);
    vec_add_ab(b, b, &m1[12]);
    func_0038CF68(c, m2, D_L24_001DD5AC);
    vec_add_ab(c, c, &m2[12]);
    s = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    func_003D9508(a, 0xB, D_L24_001DD5B0, 1, s * D_L24_001DD5B4, 0.08f, 0.0f);
    func_003D9508(b, 0xB, D_L24_001DD598, 1, s * D_L24_001DD59C, 0.08f, 0.0f);
    func_003D9508(c, 0xB, D_L24_001DD5A4, 1, s * D_L24_001DD5A8, 0.08f, 0.0f);
}
/* localdecomp:end func_L24_003577D0 */

INCLUDE_ASM("asm/levels", func_L24_00357930);

/* localdecomp:start func_L24_00357BB0 */
typedef int u128_t __attribute__((mode(TI)));
void func_L24_00357BB0(u8 *obj) {
    *(u128_t *)(obj + 0x10) = *(u128_t *)(*(u8 **)(obj + 0x68) + 0x8A0);
}
/* localdecomp:end func_L24_00357BB0 */

INCLUDE_ASM("asm/levels", func_L24_00357BC0);

INCLUDE_ASM("asm/levels", func_L24_00357D50);

INCLUDE_ASM("asm/levels", func_L24_00357F70);

INCLUDE_ASM("asm/levels", func_L24_00358860);

/* localdecomp:start func_L24_00358D10 */
/* from rac2-decomp's func_00312B58, renamed (constants adapted) */
s32 func_L24_00358D10(void *p)
{
    return *((u8 *)p + 0x20) == 8;
}
/* localdecomp:end func_L24_00358D10 */

/* localdecomp:start func_L24_00358D20 */
extern s32 func_L24_00358D10(void *);
extern void func_L24_00358860(void *, s32, s32);

s32 func_L24_00358D20(void *arg0) {
    if (func_L24_00358D10(arg0) != 0) {
        func_L24_00358860(arg0, *(s32 *)((u8 *)arg0 + 0x68) + 0x160, 1);
    } else {
        func_L24_00358860(arg0, *(s32 *)((u8 *)arg0 + 0x68) + 0x160, 0);
    }
    return 0;
}
/* localdecomp:end func_L24_00358D20 */

/* localdecomp:start func_L24_00358D78 */
extern s32 func_0038CAD0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L24_00357930(void);
extern void func_L24_00357BC0(void *);
extern void func_L24_003577D0(u8 *);
extern s32 D_L24_001E0FF0;
extern s32 D_L24_001E0FF4;
extern s32 D_L24_001E0FF8;
extern s32 D_L24_001E1000;
extern s32 D_L24_001E1004;
extern s32 D_L24_001E1008;
extern s32 D_L24_001E1010;
extern s32 D_L24_001E1014;
extern s32 D_L24_001E1018;

void func_L24_00358D78(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    if (*(u16 *)(obj + 0x96) <= 0xFFFE) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
    if (*(s32 *)(s + 0x8BC) < 10) {
        *(s32 *)(s + 0x8BC) = *(s32 *)(s + 0x8BC) + 1;
    }
    if (func_0038CAD0(&D_L24_001E0FF4) != 0) {
        D_L24_001E0FF0 = 0;
        D_L24_001E0FF4 = 0;
        D_L24_001E0FF8 = 0;
    }
    if (func_0038CAD0(&D_L24_001E1004) != 0) {
        D_L24_001E1000 = 0;
        D_L24_001E1004 = 0;
        D_L24_001E1008 = 0;
    }
    if (func_0038CAD0(&D_L24_001E1014) != 0) {
        D_L24_001E1010 = 0;
        D_L24_001E1014 = 0;
        D_L24_001E1018 = 0;
    }
    if (*(s32 *)(s + 0x8BC) != 0) {
        func_L01_00404808(func_L24_00357930, obj);
        func_L24_00357BC0(obj);
    }
    func_L01_00404808(func_L24_003577D0, obj);
}
/* localdecomp:end func_L24_00358D78 */
