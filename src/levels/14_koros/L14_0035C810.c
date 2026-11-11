#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_0035C810);

/* localdecomp:start func_L14_0035C9C0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L14_0035C9C0(u8 *a0, u8 *a1) {
    s32 i;
    *(u128_t *)(a1 + 0x30) = *(u128_t *)(a0 + 0x10);
    *(s32 *)(a1 + 0x14) = 0;
    *(s32 *)(a1 + 0xC) = 0;
    i = *(s32 *)(a1 + 0x1C);
    if (i != -1) {
        *(f32 *)(a1 + 0x24) = *(f32 *)(D_L14_001DF71C + (i << 8) + 0x18);
        *(s32 *)(a1 + 0x28) = 0;
        *(s32 *)(a1 + 0x2C) = 0;
    }
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L14_0035C9C0 */

/* localdecomp:start func_L14_0035CA20 */
extern char D_001A4C60[];
extern int func_00382380(char *, int, int);

int func_L14_0035CA20(int arg0, int *arg1)
{
    int v = *arg1;
    if (v == -1)
        return 0;
    return func_00382380(D_001A4C60, v, 0) != 0;
}
/* localdecomp:end func_L14_0035CA20 */

INCLUDE_ASM("asm/levels", func_L14_0035CA60);

INCLUDE_ASM("asm/levels", func_L14_0035CBA0);

/* localdecomp:start func_L14_0035CC40 */
extern u16 *D_L14_0021CCE0[];
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern s32 D_L14_001DF758;
extern void func_L14_00355FE0(u8 *e);
extern void func_L14_0035F9B0(u8 *e);

void func_L14_0035CC40(void *unused, u8 *object) {
    u16 *p;
    u8 *e;
    if (*(s32 *)(object + 4) == -1)
        return;
    p = D_L14_0021CCE0[*(s32 *)(object + 4)];
    while ((*(s32 *)(object + 4) & 0xFF) != 0xFF && *(s32 *)(object + 4) <= D_L14_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L14_0021CCE0[*(s32 *)(object + 4)])) {
        e = D_L14_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return;
        switch (*(s16 *)(e + 0xAA)) {
        case 0x1699:
            func_L14_00355FE0(e);
            break;
        case 0x16CA:
            func_L14_0035F9B0(e);
            break;
        }
        p++;
    }
}
/* localdecomp:end func_L14_0035CC40 */

INCLUDE_ASM("asm/levels", func_L14_0035CD38);

/* localdecomp:start func_L14_0035CE38 */
void func_L14_0035CF00(u8 *a0);
s32 func_L01_00447490(u8 *a0, s32 a1, s32 a2);
void func_L01_00439880(u8 *a0, u16 *a1, s32 *a2);
void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);

void func_L14_0035CE38(u8 *arg0) {
    u16 tmp;
    s32 tmp2;
    s32 v;

    v = arg0[0x20];
    switch (v) {
    case 0:
        func_L01_00439880(arg0, &tmp, &tmp2);
        *(u16 *)(arg0 + 0x7C) = tmp;
        func_L01_004450F0(arg0, 1, -1);
        break;
    case 1:
        if (func_L01_00447490(arg0, -1, 0) != 0) {
            func_L01_004450F0(arg0, 2, -1);
        }
        break;
    case 2:
        func_L14_0035CF00(arg0);
        break;
    }
    arg0[0xA8] = 0xFF;
}
/* localdecomp:end func_L14_0035CE38 */

INCLUDE_ASM("asm/levels", func_L14_0035CF00);

INCLUDE_ASM("asm/levels", func_L14_0035D088);
