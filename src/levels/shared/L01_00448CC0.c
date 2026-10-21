#include "common.h"

/* localdecomp:start func_L01_00448CC0 */
u32 func_L01_00448CC0(f32 r, f32 g, f32 b, f32 a) {
    u32 gv = ((s32)(g * 255.0f) & 0xff) << 8;
    return ((s32)(r * 255.0f) & 0xff) | gv | (((s32)(b * 255.0f) & 0xff) << 16) | (((s32)(a * 255.0f) & 0xff) << 24);
}
/* localdecomp:end func_L01_00448CC0 */

INCLUDE_ASM("asm/levels", func_L01_00448D28);

/* localdecomp:start func_L01_00448D88 */
extern void func_L01_00448D28(s32 *r, s32 *g, s32 *b, s32 a3);
u32 func_L01_00448D88(u32 c, s32 a1) {
    s32 r;
    s32 g;
    s32 b;
    u32 a;
    if (a1 == 0) {
        return c;
    }
    r = c & 0xff;
    g = (s32)(c & 0xff00) >> 8;
    b = (c >> 16) & 0xff;
    a = c >> 24;
    func_L01_00448D28(&r, &g, &b, a1);
    return (a << 24) | (b << 16) | (g << 8) | r;
}
/* localdecomp:end func_L01_00448D88 */

/* localdecomp:start func_L01_00448E10 */
extern void func_0038CF68(f32 *, f32 *, f32);
void func_L01_00448E10(f32 (*m)[4]) {
    f32 v[4] __attribute__((aligned(16)));
    s32 i;
    s32 j;
    for (i = 0; i < 3; i++) {
        v[3] = 0.0f;
        for (j = 0; j < 3; j++) {
            v[j] = m[j][i];
        }
        func_0038CF68(v, v, 1.0f);
        for (j = 0; j < 3; j++) {
            m[j][i] = v[j];
        }
    }
}
/* localdecomp:end func_L01_00448E10 */

INCLUDE_ASM("asm/levels", func_L01_00448EC0);

INCLUDE_ASM("asm/levels", func_L01_00448F30);

/* localdecomp:start func_L01_00448FB8 */
s32 func_L01_00448FB8(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return q[5];
}
/* localdecomp:end func_L01_00448FB8 */

INCLUDE_ASM("asm/levels", func_L01_00448FF0);

/* localdecomp:start func_L01_00449020 */
s32 func_L01_00449020(u8 *a0) {
    if (a0 == 0) {
        return 0;
    }
    if (*(u16 *)(a0 + 52) & 0x20) {
        return *(s32 *)(*(u8 **)(a0 + 104) + 12);
    }
    return 0;
}
/* localdecomp:end func_L01_00449020 */

/* localdecomp:start func_L01_00449050 */
s32 func_L01_00449050(u8 *a0) {
    if (a0 == 0) {
        return 0;
    }
    if (*(u16 *)(a0 + 52) & 0x20) {
        return *(s32 *)(*(u8 **)(a0 + 104) + 44);
    }
    return 0;
}
/* localdecomp:end func_L01_00449050 */

LINKER_REMNANT("asm/levels", func_L01_00449080);

INCLUDE_ASM("asm/levels", func_L01_00449088);

INCLUDE_ASM("asm/levels", func_L01_004495F0);

INCLUDE_ASM("asm/levels", func_L01_00449BA8);

INCLUDE_ASM("asm/levels", func_L01_0044A030);

LINKER_REMNANT("asm/levels", func_L01_0044A530);
