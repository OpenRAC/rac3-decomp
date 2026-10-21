#include "common.h"

typedef struct { u8 p0[0x34]; u16 h34; } M_3ABF90;
typedef struct { u8 p0[0x2C]; s32 w2C; u8 p30[0x20]; s32 w50; s32 w54; } S_3AC2C8;
typedef struct { u8 p0[0x68]; S_3AC2C8 *w68; } M_3AC2C8;

/* localdecomp:start func_L03_003AD8C8 */
extern void func_003C6F90(M_3ABF90 *, s32, s32, s32, s32);
extern s32 D_L03_001DE720[2];

void func_L03_003AD8C8(M_3ABF90 *m, s32 i) {
    m->h34 &= ~0x80;
    func_003C6F90(m, D_L03_001DE720[i], 14, 14, 14);
}
/* localdecomp:end func_L03_003AD8C8 */

INCLUDE_ASM("asm/levels", func_L03_003AD910);

INCLUDE_ASM("asm/levels", func_L03_003ADA98);

/* localdecomp:start func_L03_003ADB38 */
extern void func_L03_003AE810(u8 *);
void func_L03_003ADB38(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 n = *(s32 *)(p + 80) + 1;
    s32 m;
    *(s32 *)(p + 80) = n;
    m = p[*(s32 *)(p + 44) * 32 + 522];
    if (m < n) {
        *(s32 *)(p + 80) = m;
    }
    func_L03_003AE810(a0);
}
/* localdecomp:end func_L03_003ADB38 */

INCLUDE_ASM("asm/levels", func_L03_003ADB80);

/* localdecomp:start func_L03_003ADBC8 */
extern void func_L03_003AE810(u8 *);
extern void func_L03_003ADB80(u8 *);
void func_L03_003ADBC8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    *(s32 *)(p + 84) = 0;
    *(s32 *)(p + 80) = 0;
    ((void (*)(void))func_L03_003AE810)();
    func_L03_003ADB80(a0);
}
/* localdecomp:end func_L03_003ADBC8 */

/* localdecomp:start func_L03_003ADC00 */
extern void func_L03_003ADB80(u8 *);
extern void func_L03_003AE810(u8 *);
extern void func_L03_003AE880(M_3AC2C8 *);

void func_L03_003ADC00(M_3AC2C8 *m) {
    S_3AC2C8 *s = m->w68;
    s->w54 = 0;
    s->w50 = 0;
    s->w2C = 0;
    func_L03_003AE880(m);
    ((void (*)(M_3AC2C8 *))func_L03_003AE810)(m);
    ((void (*)(M_3AC2C8 *))func_L03_003ADB80)(m);
}
/* localdecomp:end func_L03_003ADC00 */

INCLUDE_ASM("asm/levels", func_L03_003ADC48);

INCLUDE_ASM("asm/levels", func_L03_003ADCD8);

INCLUDE_ASM("asm/levels", func_L03_003ADDA0);

INCLUDE_ASM("asm/levels", func_L03_003ADE98);

/* localdecomp:start func_L03_003ADF38 */
extern s32 D_L03_001DE5C0;

void func_L03_003ADF38(void) {
    D_L03_001DE5C0++;
}
/* localdecomp:end func_L03_003ADF38 */

/* localdecomp:start func_L03_003ADF48 */
extern s32 D_L03_001DE5C4;

void func_L03_003ADF48(void) {
    D_L03_001DE5C4++;
}
/* localdecomp:end func_L03_003ADF48 */

INCLUDE_ASM("asm/levels", func_L03_003ADF58);

/* localdecomp:start func_L03_003AE480 */
extern void func_L01_00516AA0(s32, s32, s32);

void func_L03_003AE480(s32 on) {
    if (on) {
        func_L01_00516AA0(0x4A0000, 1, 1);
    } else {
        func_L01_00516AA0(0x4A0000, 1, 0);
    }
}
/* localdecomp:end func_L03_003AE480 */

/* localdecomp:start func_L03_003AE4C0 */
extern void func_L01_00516AA0(s32, s32, s32);

void func_L03_003AE4C0(s32 arg0) {
    if (arg0) {
        func_L01_00516AA0(0x4A000A, 1, 1);
        func_L01_00516AA0(0x4A000B, 1, 1);
        func_L01_00516AA0(0x4A000C, 1, 1);
    } else {
        func_L01_00516AA0(0x4A000A, 1, 0);
        func_L01_00516AA0(0x4A000B, 1, 0);
        func_L01_00516AA0(0x4A000C, 1, 0);
    }
}
/* localdecomp:end func_L03_003AE4C0 */

/* localdecomp:start func_L03_003AE558 */
extern void func_L01_00516AA0(s32, s32, s32);

void func_L03_003AE558(s32 arg0) {
    if (arg0) {
        func_L01_00516AA0(0x4A000F, 1, 1);
        func_L01_00516AA0(0x4A0010, 1, 1);
        func_L01_00516AA0(0x4A000E, 1, 1);
    } else {
        func_L01_00516AA0(0x4A000F, 1, 0);
        func_L01_00516AA0(0x4A0010, 1, 0);
        func_L01_00516AA0(0x4A000E, 1, 0);
    }
}
/* localdecomp:end func_L03_003AE558 */

INCLUDE_ASM("asm/levels", func_L03_003AE5F0);
