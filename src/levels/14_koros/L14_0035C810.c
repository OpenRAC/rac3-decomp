#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_0035C810 */
extern void func_L14_0035C9C0(u8 *, u8 *);
extern int func_L14_0035CA20(int, int *);
extern s32 func_L14_0035CA60(u8 *, u8 *);
extern s32 func_L14_0035CBA0(s32, u8 *);
extern void func_L14_0035CC40(void *, u8 *);
extern void func_L14_0035CD38(void *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_0038CAD0(void *);
__asm__(".extern D_L14_001DD6D0, 4");
__asm__(".extern D_L14_001DD6C0, 4");
extern s32 D_L14_001DD6D0;
extern f32 D_L14_001DD6C0;
void func_L14_0035C810(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        func_L14_0035C9C0(a0, s);
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L14_0035CA20((int)a0, (int *)s)) {
            *(s32 *)s = -1;
            func_L01_004450F0(a0, 2, -1);
            *(s32 *)(s + 0x18) = D_L14_001DD6D0;
        }
        break;
    case 2:
        if (func_0038CAD0(s + 0x18)) {
            func_L01_004450F0(a0, 3, -1);
            *(f32 *)(s + 0x10) = D_L14_001DD6C0;
            func_L14_0035CC40(a0, s);
        }
        break;
    case 3:
        if (func_L14_0035CA60(a0, s)) {
            func_L01_004450F0(a0, 4, -1);
            if (*(s32 *)(s + 0x1C) == -1 || *(s32 *)(s + 0x20) == 0) {
                func_L14_0035CD38(a0, s);
            }
            *(s32 *)(s + 0x18) = *(s32 *)(s + 8);
        }
        break;
    case 4:
        if (*(s32 *)(s + 0x1C) != -1) {
            if (func_L14_0035CBA0((s32)a0, s)) {
                if (*(s32 *)(s + 0x20) != 0) {
                    func_L14_0035CD38(a0, s);
                }
                *(s32 *)(s + 0x1C) = -1;
            }
        }
        if (func_0038CAD0(s + 0x18)) {
            func_L01_004450F0(a0, 5, -1);
            *(s32 *)(s + 0x10) = 0;
        }
        break;
    case 5:
        if (func_L14_0035CA60(a0, s)) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L14_0035C810 */

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
