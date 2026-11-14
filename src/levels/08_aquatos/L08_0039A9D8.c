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

/* localdecomp:start func_L08_0039AA38 */
typedef int q_0039AA38 __attribute__((mode(TI)));
extern void func_0038CB78(void *, s32, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_003C7C38(void *);

s32 func_L08_0039AA38(u8 *a) {
    u8 *p;
    u8 *c;

    if (a[0x20] >= 2) {
        return 0;
    }
    if (a == 0) {
        return 0;
    }
    c = *(u8 **)(a + 0x24);
    p = *(u8 **)(a + 0x68);
    *(u16 *)(a + 0x34) &= 0xFFBC;
    *(u16 *)(a + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
    *(s32 *)(a + 0x98) = *(s32 *)(c + 0x10);
    *(s16 *)(p + 0x108) = 0;
    p[0xE0] = 0xFF;
    p[0x118] = 0xFF;
    p[0xE1] = 0xFF;
    p[0xE2] = 0xFF;
    *(f32 *)(p + 0x100) = 0.5f;
    p[0x147] = 1;
    p[0x38] = 1;
    p[0xE6] = 0xFF;
    *(f32 *)(p + 0x104) = 0.5f;
    *(f32 *)(p + 0x10C) = 0.15f;
    *(f32 *)(p + 0x190) = 0.4f;
    *(f32 *)(p + 0x194) = 0.3f;
    *(f32 *)(p + 0x198) = 2.2f;
    *(f32 *)(p + 0x19C) = 2.0f;
    *(f32 *)(p + 0x1A0) = 1.3089969f;
    *(f32 *)(p + 0x1C0) = 3.1415927f;
    *(f32 *)(p + 0x1BC) = 0.00392f;
    *(f32 *)(p + 0x1C4) = 1.0f;
    *(s32 *)(p + 0x1C8) |= 2;
    *(f32 *)(p + 0x40) = 1.5f;
    p[0x39] = 1;
    p[0x3F] = 0;
    if (*(s16 *)(p + 0x34) == 0 || *(f32 *)(p + 0x30) <= 0.0f) {
        *(s16 *)(p + 0x34) = 100;
        *(f32 *)(p + 0x30) = 100.0f;
    }
    p[0x58] = 20;
    p[0x5A] = 14;
    *(s32 *)(p + 0x3AC) = 0;
    *(q_0039AA38 *)(p + 0x4B0) = *(q_0039AA38 *)(a + 0x10);
    *(q_0039AA38 *)(p + 0x4C0) = *(q_0039AA38 *)(a + 0xF0);
    func_0038CB78(p + 0x4D0, 0, 0x80);
    if (*(u8 **)(p + 0x5D0) == 0) {
        *(u8 **)(p + 0x5D0) = func_003C24B0(0x1ADF, 0x80);
        func_L01_00456160(*(u8 **)(p + 0x5D0), a);
    }
    func_L01_004450F0((s32)a, 2, -1);
    func_003C7C38(a);
    return 1;
}
/* localdecomp:end func_L08_0039AA38 */

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

/* localdecomp:start func_L08_0039AE10 */

s32 func_L08_0039AE10(void *arg0, s32 arg1, s32 arg2) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    u8 before = *(u8 *)((u8 *)arg0 + 0x20);
    *(u8 *)(v + 0x490) = arg1;
    *(u32 *)(v + 0x47C) = arg2;
    func_L01_00445130((void *)arg0, 7, -1);
    return *(u8 *)((u8 *)arg0 + 0x20) != before;
}
/* localdecomp:end func_L08_0039AE10 */

/* localdecomp:start func_L08_0039AE60 */

s32 func_L08_0039AE60(void *arg0, s32 arg1, s32 arg2) {
    u8 before;
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    before = *(u8 *)((u8 *)arg0 + 0x20);
    *(u8 *)((u8 *)temp_v0 + 0x490) = arg1;
    *(s32 *)((u8 *)temp_v0 + 0x47C) = arg2;
    func_L01_00445130(arg0, 8, -1);
    return (*(u8 *)((u8 *)arg0 + 0x20) ^ before) != 0;
}
/* localdecomp:end func_L08_0039AE60 */

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
