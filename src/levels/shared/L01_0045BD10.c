#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045BD10 */
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                          float f14, float f15);

/* from rac2-decomp's func_L01_00322288, renamed */
int func_L01_0045BD10(int a0, float f12) {
    char *p = func_L01_0045B958(a0);
    if (p == 0)
        return 0;
    func_L01_00448890((char *)a0 + 0xF8, p + 0xB4, 0, f12, *(float *)(p + 0x14),
                  *(float *)(p + 0x18), *(float *)(p + 0x1C));
    return 1;
}
/* localdecomp:end func_L01_0045BD10 */

LINKER_REMNANT("asm/levels", func_L01_0045BD70);

/* localdecomp:start func_L01_0045BD78 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d)
{
    u8 *p = ((u8 * (*)(u8 *a0))func_L01_0045B958)(a0);

    if (p != 0) {
        *(f32 *)(p + 32) = a;
        *(f32 *)(p + 36) = a;
        *(f32 *)(p + 40) = b;
        *(f32 *)(p + 20) = c;
        *(f32 *)(p + 24) = c;
        *(f32 *)(p + 28) = d;
    }
}
/* localdecomp:end func_L01_0045BD78 */

LINKER_REMNANT("asm/levels", func_L01_0045BDE0);

/* localdecomp:start func_L01_0045BDE8 */
extern s32 D_L01_0021F6C0[];
extern s32 func_L01_0045BE38(void *a0, s32 a1);
s32 func_L01_0045BDE8(void *a0, s32 a1) {
    s32 v;
    if (a1 == -1) return 0;
    v = D_L01_0021F6C0[a1];
    if (v == 0) return 0;
    return func_L01_0045BE38(a0, v);
}
/* localdecomp:end func_L01_0045BDE8 */

INCLUDE_ASM("asm/levels", func_L01_0045BE38);

LINKER_REMNANT("asm/levels", func_L01_0045C148);

/* localdecomp:start func_L01_0045C150 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
s32 func_L01_0045C150(void *a0, u16 *a1, s32 a2, s32 a3) {
    u8 *p;

    p = ((u8 * (*)(void *))func_L01_0045B958)(a0);
    if (p == 0) {
        return 0;
    }
    *(u16 **)(p + 196) = a1;
    *(s32 *)(p + 156) &= ~4;
    if (a2 == -1) {
        *(s16 *)(p + 202) = *a1 - 1;
    } else {
        *(s16 *)(p + 202) = a2;
    }
    *(s16 *)(p + 200) = a3;
    return 1;
}
/* localdecomp:end func_L01_0045C150 */

/* localdecomp:start func_L01_0045C1D0 */
extern s32 D_L01_001DFB40_0045C1D0;
__asm__(".extern D_L01_001DFB40_0045C1D0, 16");
extern f32 D_L01_001D7DD4_0045C1D0;
extern s32 D_L01_001D7DD8_0045C1D0;
extern s32 D_L01_001D7DDC_0045C1D0;
extern f32 D_L01_001D7DE0_0045C1D0;
void func_L01_0045C1D0(void) {
    if (D_L01_001D7DD8_0045C1D0 != D_L01_001DFB40_0045C1D0) {
        if (D_L01_001D7DDC_0045C1D0 != 0) {
            D_L01_001D7DE0_0045C1D0 = D_L01_001D7DD4_0045C1D0 / D_L01_001D7DDC_0045C1D0;
        } else {
            D_L01_001D7DE0_0045C1D0 = 0;
        }
        D_L01_001D7DDC_0045C1D0 = 0;
        D_L01_001D7DD8_0045C1D0 = D_L01_001DFB40_0045C1D0;
        D_L01_001D7DD4_0045C1D0 = 0;
    }
    *(volatile u32 *)0x10000010 = 0x81;
    *(volatile u32 *)0x10000000 = 0;
}
/* localdecomp:end func_L01_0045C1D0 */

/* localdecomp:start func_L01_0045C240 */
extern s32 D_L01_001D7DDC;
extern f32 D_L01_001D7DD4;
void func_L01_0045C240(void) {
    D_L01_001D7DDC++;
    D_L01_001D7DD4 += (f32)*(volatile u32 *)0x10000000;
}
/* localdecomp:end func_L01_0045C240 */

LINKER_REMNANT("asm/levels", func_L01_0045C298);
