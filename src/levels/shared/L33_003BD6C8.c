#include "common.h"

/* declared by functions of L33_003BD2E8.c, which this file was cut from */
extern void func_L33_003BD798();
extern void func_L33_003BD7C8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

/* localdecomp:start func_L33_003BD6C8 */
__asm__(".extern D_L33_001DF184, 4");
typedef int u128_003BD6C8 __attribute__((mode(TI)));
extern s32 D_L33_001DF184;
extern u8 *func_003C24B0(s32, s32);
extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

u8 *func_L33_003BD6C8(u8 *a0) {
    u8 *m;
    s32 *v;
    s32 r, g, b;
    s32 t;

    m = func_003C24B0(0x1E79, 0x20);
    if (m == 0) {
        return 0;
    }
    m[0x30] = 0xFF;
    *(s16 *)(m + 0x32) = 0xFF;
    v = *(s32 **)(m + 0x68);
    *(u128_003BD6C8 *)(m + 0x10) = *(u128_003BD6C8 *)(a0 + 0x10);
    *(u128_003BD6C8 *)(m + 0xF0) = *(u128_003BD6C8 *)(a0 + 0xF0);
    func_003C6FB0(a0, &r, &g, &b);
    func_L01_0043B9E8(m, r, g, b);
    t = D_L33_001DF184;
    v[0] = -1;
    v[1] = 0;
    v[2] = -1;
    v[3] = 1;
    v[4] = t;
    v[5] = t - 1;
    func_L01_004450F0(m, 4, -1);
    return m;
}
/* localdecomp:end func_L33_003BD6C8 */

/* localdecomp:start func_L33_003BD798 */
extern u8 D_00142732[];
extern s32 func_L01_004561B8(void);

void func_L33_003BD798(void) {
    if (func_L01_004561B8()) {
        D_00142732[0] = 1;
    }
}
/* localdecomp:end func_L33_003BD798 */

/* localdecomp:start func_L33_003BD7C8 */
extern s32 func_L01_004561B8(void);
extern s32 D_L33_001DF17C;
extern void func_L30_0034DAC0(u8 *);
extern s32 func_0038CAD0(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L33_003BD7C8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (((s32 (*)(u8 *))func_L01_004561B8)(a0)) {
        *(s32 *)(v + 20) = D_L33_001DF17C;
        func_L30_0034DAC0(v + 8);
    }
    if (func_0038CAD0(v + 20)) {
        func_L01_004450F0(a0, 1, -1);
    }
}
/* localdecomp:end func_L33_003BD7C8 */

INCLUDE_ASM("asm/levels", func_L33_003BD828);
