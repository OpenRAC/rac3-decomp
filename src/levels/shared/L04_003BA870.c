#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L04_003BA870);

/* localdecomp:start func_L04_003BAA98 */
typedef int u128_3BAA98 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00366E48(u8 *, u8 *, void *, void *, s32);
extern void func_0038D308(u8 *, u8 *);
extern void func_L04_003BAB98(u8 *, u8 *);

u8 *func_L04_003BAA98(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *m = func_003C24B0(0x192F, 0xC0);
    u8 *mv;
    u8 *rot;
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        mv = *(u8 **)(m + 0x68);
        m[0x30] = a0[0x30];
        *(u16 *)(m + 0x32) = *(u16 *)(a0 + 0x32);
        m[0x31] = a0[0x31];
        m[0x20] = 1;
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(u128_3BAA98 *)(m + 0x10) = *(u128_3BAA98 *)(a0 + 0x10);
        func_L01_00366E48(m, mv, mv + 4, mv + 0x10, 0);
        func_L04_003BAB98(m, mv);
        rot = m + 0xF0;
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = *(f32 *)(a0 + 0xF8);
        if (*(s32 *)(pv + 4) < 0) {
            *(f32 *)(m + 0xF0) = 3.1415927f;
            *(f32 *)(mv + 8) = -*(f32 *)(mv + 8);
        }
        func_0038D308(m + 0xC0, rot);
        *(u16 *)(m + 0x34) |= 0x104;
        *(s32 *)(mv + 0xA0) = 0;
    }
    return m;
}
/* localdecomp:end func_L04_003BAA98 */

/* localdecomp:start func_L04_003BAB98 */
extern void func_L01_0043A800(u8 *, s32, void *);
extern void func_L01_0043A430(u8 *, s32, void *);
extern void func_0038CB78(void *, s32, s32);

void func_L04_003BAB98(u8 *a0, u8 *a1) {
    f32 v[4];
    func_L01_0043A800(a0, 1, v);
    *(s32 *)(a1 + 0xC) = 0;
    *(f32 *)(a1 + 8) = v[2];
    qzero(a1 + 0x90);
    func_0038CB78(a1 + 0x50, 0, 0x40);
    func_L01_0043A430(a0, 1, a1 + 0x50);
}
/* localdecomp:end func_L04_003BAB98 */

INCLUDE_ASM("asm/levels", func_L04_003BAC10);

INCLUDE_ASM("asm/levels", func_L04_003BAD68);

INCLUDE_ASM("asm/levels", func_L04_003BAF58);

/* localdecomp:start func_L04_003BB058 */
extern void func_L01_0043A800(u8 *, s32, void *);
extern void func_L01_0043A430(u8 *, s32, void *);
extern void func_0038CB78(void *, s32, s32);

void func_L04_003BB058(u8 *a0, u8 *a1) {
    f32 v[4];
    func_L01_0043A800(a0, 1, v);
    *(s32 *)(a1 + 0xC) = 0;
    *(f32 *)(a1 + 8) = v[2];
    qzero(a1 + 0x90);
    func_0038CB78(a1 + 0x50, 0, 0x40);
    func_L01_0043A430(a0, 1, a1 + 0x50);
}
/* localdecomp:end func_L04_003BB058 */

INCLUDE_ASM("asm/levels", func_L04_003BB0D0);
