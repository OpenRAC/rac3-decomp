#include "common.h"

/* localdecomp:start func_L08_0039A9D8 */
void func_L01_004450F0(s32, s32, s32);
void func_003C2880(s32);
void func_L01_003361D8(void *);
void func_L01_0044EA78(void *, s32);

void func_L08_0039A9D8(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004450F0((s32) arg0, 1, -1);
    func_L01_0044EA78(arg0, temp_s0 + 0x4D0);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x5D0);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
    }
    func_L01_003361D8(arg0);
}
/* localdecomp:end func_L08_0039A9D8 */

INCLUDE_ASM("asm/levels", func_L08_0039AA38);

/* localdecomp:start func_L08_0039AC38 */
extern u8 D_001D5471;
__asm__(".extern D_001D5471, 16");
void func_L08_00431BE8(void *, void *, s32, s32);
void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L08_0039AC38(u8 *a0) {
    u8 *p;

    if (a0[0x20] != 0) {
        p = *(u8 **)(a0 + 0x68);
        *(u8 *)(a0 + 0xA8) = 0xFF;
        if (D_001D5471 != 0) {
            *(f32 *)(p + 0x5C0) = 2.75f;
        }
        func_L08_00431BE8(a0, p + 0x280, 2, 3);
        func_L01_0044E850(a0, p + 0x4D0, 4, 0.0432f, 0.43200004f);
    }
}
/* localdecomp:end func_L08_0039AC38 */

/* localdecomp:start func_L08_0039ACD0 */
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039ACD0(u8 *arg0, u8 arg1, s32 arg2) {
    u8 temp_s1 = arg0[0x20];
    u8 *temp_v0 = *(u8 **)(arg0 + 0x68);

    temp_v0[0x490] = arg1;
    *(s32 *)(temp_v0 + 0x47C) = arg2;
    func_L01_00445130((void *)arg0, 3, -1);
    return (arg0[0x20] ^ temp_s1) != 0;
}
/* localdecomp:end func_L08_0039ACD0 */

/* localdecomp:start func_L08_0039AD20 */
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039AD20(void *arg0, s32 arg1, s32 arg2) {
    void *temp;
    u8 before;

    before = *(u8 *)((u8 *)arg0 + 0x20);
    temp = *(void **)((u8 *)arg0 + 0x68);
    *(u8 *)((u8 *)temp + 0x490) = arg1;
    *(s32 *)((u8 *)temp + 0x47C) = arg2;
    func_L01_00445130(arg0, 4, -1);
    return (before ^ *(u8 *)((u8 *)arg0 + 0x20)) != 0;
}
/* localdecomp:end func_L08_0039AD20 */

/* localdecomp:start func_L08_0039AD70 */
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039AD70(void *arg0, s32 arg1, s32 arg2) {
    u8 old;
    void *temp_s0;
    u8 new;

    old = *(u8 *)((u8 *)arg0 + 0x20);
    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    *(u8 *)((u8 *)temp_s0 + 0x490) = arg1;
    *(s32 *)((u8 *)temp_s0 + 0x47C) = arg2;
    func_L01_00445130(arg0, 5, -1);
    new = *(u8 *)((u8 *)arg0 + 0x20);
    return (new ^ old) != 0;
}
/* localdecomp:end func_L08_0039AD70 */

/* localdecomp:start func_L08_0039ADC0 */
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039ADC0(void *arg0, s32 arg1, s32 arg2) {
    u8 old = *(u8 *)((u8 *)arg0 + 0x20);
    void *temp = *(void **)((u8 *)arg0 + 0x68);

    *(u8 *)((u8 *)temp + 0x490) = arg1;
    *(s32 *)((u8 *)temp + 0x47C) = arg2;
    func_L01_00445130(arg0, 6, -1);
    return (*(u8 *)((u8 *)arg0 + 0x20) ^ old) != 0;
}
/* localdecomp:end func_L08_0039ADC0 */

INCLUDE_ASM("asm/levels", func_L08_0039AE10);

INCLUDE_ASM("asm/levels", func_L08_0039AE60);

/* localdecomp:start func_L08_0039AEB0 */
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039AEB0(u8 *a0, u8 a1, s32 a2) {
    u8 old = *(a0 + 0x20);
    u8 *p = *(u8 **)(a0 + 0x68);
    *(u8 *)(p + 0x490) = a1;
    *(s32 *)(p + 0x47C) = a2;
    func_L01_00445130(a0, 9, -1);
    return (*(a0 + 0x20) ^ old) != 0;
}
/* localdecomp:end func_L08_0039AEB0 */

/* localdecomp:start func_L08_0039AF00 */
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039AF00(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *sub;
    s32 before;
    s32 after;

    before = arg0[0x20];
    sub = *(u8 **)(arg0 + 0x68);
    *(u8 *)(sub + 0x490) = arg1;
    *(s32 *)(sub + 0x47C) = arg2;
    func_L01_00445130(arg0, 10, -1);
    after = arg0[0x20];
    return (after ^ before) != 0;
}
/* localdecomp:end func_L08_0039AF00 */

/* localdecomp:start func_L08_0039AF50 */
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039AF50(u8 *arg0, u8 arg1, s32 arg2) {
    u8 temp_s1 = arg0[0x20];
    u8 *temp_v0 = *(u8 **)(arg0 + 0x68);

    temp_v0[0x490] = arg1;
    *(s32 *)(temp_v0 + 0x47C) = arg2;
    func_L01_00445130((void *)arg0, 11, -1);
    return (arg0[0x20] ^ temp_s1) != 0;
}
/* localdecomp:end func_L08_0039AF50 */

/* localdecomp:start func_L08_0039AFA0 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *D_L08_001DF21C;
__asm__(".extern D_L08_001DF21C, 4");
void func_L01_004450F0(s32, s32, s32);
void func_L01_00445130(void *, s32, s32);

s32 func_L08_0039AFA0(void *arg0, s32 arg1, s32 arg2) {
    u8 *t8 = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *y = *(u8 **)(*(u8 **)((u8 *)arg0 + 0xB8) + 0xB8);
    u8 *z = *(u8 **)(y + 0x68);
    u8 old = *(u8 *)((u8 *)arg0 + 0x20);
    s32 idx;

    *(u8 *)(t8 + 0x490) = arg1;
    *(s32 *)(t8 + 0x47C) = arg2;
    idx = *(s32 *)(z + 0x60);
    if (idx != -1 && *(u8 *)((u8 *)arg0 + 0x20) < 0xF) {
        *(u128_t *)(t8 + 0x4A0) = *(u128_t *)(D_L08_001DF21C + (idx << 8) + 0x10);
        func_L01_004450F0((s32) arg0, 0xF, -1);
    } else {
        func_L01_00445130(arg0, 0x10, -1);
    }
    return (*(u8 *)((u8 *)arg0 + 0x20) ^ old) != 0;
}
/* localdecomp:end func_L08_0039AFA0 */
