#include "common.h"

/* localdecomp:start func_L07_00351148 */
/* follows func_L04_00362DF0 (src/levels/shared/L04_00362CE0.c) */
typedef int Q_00351148 __attribute__((mode(TI)));
extern u8 *func_00382348(void *);
extern u8 *func_L01_00448FF0(u8 *);
extern s32 func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_00351148(u8 *a0) {
    u8 *s;
    u8 *p;
    u8 *q;

    s = *(u8 **)(a0 + 0x68);
    a0[0x7F] = 0;
    p = func_00382348(a0);
    *(f32 *)p = *(s16 *)(p + 4);
    q = func_L01_00448FF0(a0);
    *(s16 *)(q + 0x38) = 0;
    q[7] = 0;
    q[9] = 0;
    q[8] = 0;
    func_L01_00456C98(a0, -1, 0, 0, 0, 0, 3, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    *(s32 *)(a0 + 0x98) = 0;
    a0[0xA8] = 0xFF;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x43) & ~0x1000;
    func_L01_004AA7E8(a0, 1);
    *(Q_00351148 *)(a0 + 0x10) = *(Q_00351148 *)(s + 0x260);
    *(Q_00351148 *)(a0 + 0xF0) = *(Q_00351148 *)(s + 0x270);
    func_L01_004450F0(a0, 7, 4);
}
/* localdecomp:end func_L07_00351148 */
