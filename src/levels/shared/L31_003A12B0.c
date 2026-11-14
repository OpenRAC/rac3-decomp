#include "common.h"

/* localdecomp:start func_L31_003A12B0 */
extern s32 D_L31_001DE750;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
typedef struct { u8 pad[0x30]; u8 f30; u8 f31; s16 f32; } M_003A12B0;
typedef int Q_003A12B0 __attribute__((mode(TI)));

u8 *func_L31_003A12B0(u8 *a0, void *a1, void *a2, f32 *a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 k,
                      f32 f12, f32 f13, f32 f14) {
    u8 *m = func_003C24B0(0x18C5, 0x80);
    if (m != 0) {
        u8 *v;
        s32 n;
        m[0x30] = 0xFF;
        ((M_003A12B0 *)m)->f32 = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        v = *(u8 **)(m + 0x68);
        *(unsigned long *)(m + 0x38) = *(unsigned long *)(a0 + 0x38);
        *(Q_003A12B0 *)(m + 0x10) = *(Q_003A12B0 *)a2;
        *(Q_003A12B0 *)(v + 0x10) = *(Q_003A12B0 *)a1;
        n = (D_L31_001DE750 * 5 + 2) / 6;
        *(f32 *)(v + 0x20) = a3[0];
        *(f32 *)(v + 0x24) = a3[2];
        *(f32 *)(v + 0x60) = f14;
        *(f32 *)(v + 0x2C) = f12;
        *(u8 **)(v + 0x30) = a0;
        *(f32 *)(v + 0x38) = f13;
        *(s32 *)(v + 0x3C) = k;
        *(s32 *)(v + 0x44) = t0;
        *(s32 *)(v + 0x48) = t1;
        *(s32 *)(v + 0x4C) = t2;
        *(s32 *)(v + 0x50) = t3;
        *(s32 *)(v + 0x34) = -1;
        *(s32 *)(v + 0x54) = -1;
        *(s32 *)(v + 0x40) = 0;
        *(s32 *)(v + 0x58) = 0;
        *(s32 *)(v + 0x5C) = 0;
        *(s32 *)(v + 0x28) = n;
        func_L01_004450F0(m, 0, -1);
    }
    return m;
}
/* localdecomp:end func_L31_003A12B0 */
