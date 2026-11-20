#include "common.h"

/* localdecomp:start func_L07_003AA9C0 */
void func_L07_00334740(void *);
void func_L07_003AAA50(void *, s32);

void func_L07_003AA9C0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    *(s32 *)(p + 0x188) &= -0x11;
    *(s32 *)(p + 0x53C) = 0;
    func_L07_00334740(arg0);
    func_L07_003AAA50(arg0, 1);
}
/* localdecomp:end func_L07_003AA9C0 */

/* localdecomp:start func_L07_003AAA08 */
void func_L07_00334800();
void func_L07_003AAA50(void *, s32);

void func_L07_003AAA08(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)) * 0.75f);
    func_L07_00334800();
    func_L07_003AAA50(arg0, 2);
}
/* localdecomp:end func_L07_003AAA08 */

INCLUDE_ASM("asm/levels", func_L07_003AAA50);

INCLUDE_ASM("asm/levels", func_L07_003AADB0);

INCLUDE_ASM("asm/levels", func_L07_003AAF98);

/* localdecomp:start func_L07_003AB200 */
extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DB48(f32 a);

void func_L07_003AB200(u8 *arg0) {
    u8 *p;
    u8 *q;
    f32 v[3];
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    func_003C2F58(arg0, p[0x533] + 3, v);
    d = func_0038D160(*(f32 *)(p + 0x520) - v[0], *(f32 *)(p + 0x524) - v[1]);
    d = func_0038DB48((d - *(f32 *)(p + 0x2A8)) - *(f32 *)(arg0 + 0xF8));
    q = p + p[0x533] * 128;
    *(f32 *)(q + 0x3C8) = d;
    d = func_0038CF38(v, p + 0x520);
    d = func_0038D160(d, *(f32 *)(p + 0x528) - v[2]);
    p = p + p[0x533] * 128;
    *(f32 *)(p + 0x3C4) = -d;
}
/* localdecomp:end func_L07_003AB200 */

INCLUDE_ASM("asm/levels", func_L07_003AB2B0);

INCLUDE_ASM("asm/levels", func_L07_003AB4B8);

INCLUDE_ASM("asm/levels", func_L07_003AB678);

INCLUDE_ASM("asm/levels", func_L07_003AB918);

INCLUDE_ASM("asm/levels", func_L07_003ABD18);
