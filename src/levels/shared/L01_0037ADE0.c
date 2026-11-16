#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L01_0037ADE0);

INCLUDE_ASM("asm/levels", func_L01_0037B6C0);

INCLUDE_ASM("asm/levels", func_L01_0037BCF8);

INCLUDE_ASM("asm/levels", func_L01_0037BE80);

/* localdecomp:start func_L01_0037C208 */
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(u8 *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);

void func_L01_0037C208(u8 *arg0) {
    u8 *sub;

    sub = *(u8 **)(arg0 + 104);
    *(f32 *)(sub + 16) = func_0038DAB8(*(f32 *)(sub + 16), 0.017453292f);
    func_003D9508(arg0 + 16, 57, 0x40505050, 1, 0.5f, 0.08f, func_0038DAB8(*(f32 *)(sub + 16) * 2.5f, 0.0f));
    func_003D9508(arg0 + 16, 42, 0x207F2040, 1, 0.5f, 0.08f, func_0038DAB8(-*(f32 *)(sub + 16) * 1.5f, 0.0f));
    func_003D9508(arg0 + 16, 44, 0x207F2040, 1, 0.5f, 0.08f, func_0038DAB8(*(f32 *)(sub + 16), 0.0f));
    func_003D9508(arg0 + 16, 49, 0x20FF7F00, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * 0.5f);
    func_003D9508(arg0 + 16, 49, 0x0020FF7F, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * -0.5f);
    func_003D9508(arg0 + 16, 47, 0x507F7F7F, 1, 0.11f, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_0037C208 */

INCLUDE_ASM("asm/levels", func_L01_0037C3C8);

/* localdecomp:start func_L01_0037C6E8 */
extern s32 D_L01_001E10D0[];

void func_L01_0037C6E8(s32 a0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == 0) {
            D_L01_001E10D0[i] = a0;
            return;
        }
    }
}
/* localdecomp:end func_L01_0037C6E8 */

/* localdecomp:start func_L01_0037C720 */
extern s32 D_L01_001E10D0[];
s32 func_L01_0037C720(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_0037C720 */

/* localdecomp:start func_L01_0037C758 */
extern int D_L01_001E10D0[];
int func_L01_0037C758(int a)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == a) {
            D_L01_001E10D0[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0037C758 */

/* localdecomp:start func_L01_0037C798 */
void func_L01_0037C798(vu0_v4 *p, s32 i) {
    vu0_v4 d;

    vec_sub_ab(&d, &p[i - 2], &p[i - 3]);
    vec_add_ab(&p[i - 1], &p[i - 2], &d);
}
/* localdecomp:end func_L01_0037C798 */

/* localdecomp:start func_L01_0037C7D8 */
void func_L01_0037C7D8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0037C7D8 */

INCLUDE_ASM("asm/levels", func_L01_0037C860);

INCLUDE_ASM("asm/levels", func_L01_0037C978);

LINKER_REMNANT("asm/levels", func_L01_0037CC28);

INCLUDE_ASM("asm/levels", func_L01_0037CC30);

LINKER_REMNANT("asm/levels", func_L01_0037CEC0);

INCLUDE_ASM("asm/levels", func_L01_0037CEC8);

INCLUDE_ASM("asm/levels", func_L01_0037D210);

INCLUDE_ASM("asm/levels", func_L01_0037D358);

INCLUDE_ASM("asm/levels", func_L01_0037D920);

INCLUDE_ASM("asm/levels", func_L01_0037DC70);

/* localdecomp:start func_L01_0037E2E8 */
#include "vu0.h"
__asm__(".extern D_L01_001DDB74, 4");
__asm__(".extern D_L01_001DDB68, 4");
__asm__(".extern D_L01_001DDB6C, 4");
__asm__(".extern D_L01_001DDB70, 4");

extern f32 D_L01_001DDB74 __attribute__((section(".sdata")));
extern f32 D_L01_001E1DBC __attribute__((section(".data")));
extern f32 D_L01_001E1DB8 __attribute__((section(".data")));
extern f32 D_L01_001E1DA4;
extern f32 D_L01_001E1DA8;
extern f32 D_L01_001E1DAC;
extern s32 D_L01_001E1DA0 __attribute__((section(".data")));
extern s32 D_L01_001DDB68 __attribute__((section(".sdata")));
extern s32 D_L01_001DDB6C __attribute__((section(".sdata")));
extern s32 D_L01_001DDB70 __attribute__((section(".sdata")));
void func_L01_0037E2E8(u8 *p) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_003D9740(void *, s32, u32, s32, s32, f32);
    vu0_v4 matrix[4];
    vu0_v4 pos;
    vu0_v4 delta;
    vu0_v4 rotation;
    vu0_v4 axis;
    u8 *sub = *(u8 **)(p + 0x68);
    u32 c0, c1, c2;
    *(vu0_q *)&pos = *(vu0_q *)(sub + 0x20);
    vec_sub_ab(&delta, p + 0x10, sub + 0x20);
    func_0038CF68(&delta, &delta, 1.0f);
    rotation.x = 0.0f;
    rotation.y = -func_0038D160(func_0038CED8(&delta), delta.z) + -1.5707963705f;
    rotation.z = func_0038D160(delta.x, delta.y);
    rotation.w = 1.0f;
    func_0038D328(matrix, &rotation);
    *(vu0_q *)&axis = *(vu0_q *)&delta;
    func_0038CE20(&axis, &axis, D_L01_001DDB74);
    vec_add_ab(&pos, &pos, &axis);
    *(vu0_q *)&matrix[3] = *(vu0_q *)&pos;
    func_0038CE20(&matrix[0], &matrix[0], D_L01_001E1DBC);
    func_0038CE20(&matrix[1], &matrix[1], D_L01_001E1DB8);
    func_0038CE20(&matrix[2], &matrix[2], D_L01_001DDB74);
    D_L01_001E1DA4 += 0.15f;
    if (D_L01_001E1DA4 >= 7.0f) D_L01_001E1DA4 -= 7.0f;
    D_L01_001E1DA8 += 0.1f;
    if (D_L01_001E1DA8 >= 7.0f) D_L01_001E1DA8 -= 7.0f;
    D_L01_001E1DAC += 0.05f;
    if (D_L01_001E1DAC >= 7.0f) D_L01_001E1DAC -= 7.0f;
    c0 = (D_L01_001E1DA0 << 24) | 0x204080;
    c2 = (D_L01_001E1DA0 << 24) | 0x104080;
    c1 = (D_L01_001E1DA0 << 24) | 0x80C4FF;
    func_0038D890(&matrix[0], &matrix[0], &matrix[2], 0.7853981853f);
    func_0038D890(&matrix[1], &matrix[1], &matrix[2], 0.7853981853f);
    func_003D9740(matrix, D_L01_001DDB68, c0, 8, 1, D_L01_001E1DA4);
    func_0038D890(&matrix[0], &matrix[0], &matrix[2], -1.5707963705f);
    func_0038D890(&matrix[1], &matrix[1], &matrix[2], -1.5707963705f);
    func_003D9740(matrix, D_L01_001DDB6C, c2, 8, 1, D_L01_001E1DA8);
    func_003D9740(matrix, D_L01_001DDB70, c0, 8, 1, D_L01_001E1DAC);
    func_0038CE20(&matrix[0], &matrix[0], 1.1f);
    func_0038CE20(&matrix[1], &matrix[1], 1.1f);
    func_003D9740(matrix, 10, c1, 6, 1, D_L01_001E1DA4);
}
/* localdecomp:end func_L01_0037E2E8 */

INCLUDE_ASM("asm/levels", func_L01_0037E620);

INCLUDE_ASM("asm/levels", func_L01_0037E670);
