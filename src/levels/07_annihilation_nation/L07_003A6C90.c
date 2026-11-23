#include "common.h"
/* localdecomp:start func_L07_003A6C90 */
typedef int TI_003A6C90 __attribute__((mode(TI)));
s32 func_L07_003A6C90(u8 *obj, void *pos, s16 n, s16 start, s16 mid, s16 end, s32 a6, s32 a7) {
    extern void func_003CD250(void *);
    extern u8 *func_L01_00470150(void *, u8 *, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
    f32 base[4] __attribute__((aligned(16)));
    f32 point[4] __attribute__((aligned(16)));
    u8 *s = *(u8 **)(obj + 0x68);
    void **slots;
    u8 *dst;
    s32 i;
    s32 j;
    s32 three;
    s32 one;
    void *p;
    if (*(s32 *)(s + 0x70) != -1) return 0;
    obj[0x30] = 0x40;
    *(s16 *)(obj + 0x32) = 0x40;
    obj[0x31] = 1;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    *(TI_003A6C90 *)(s + 0x90) = *(TI_003A6C90 *)(obj + 0x10);
    *(TI_003A6C90 *)(obj + 0x10) = *(TI_003A6C90 *)pos;
    *(s32 *)(s + 0x80) = n;
    *(s16 *)(s + 0x7C) = end - (start + mid);
    *(s32 *)(s + 0x74) = a6;
    *(s32 *)(s + 0x6C) |= 1;
    *(s32 *)(s + 0x70) = a7;
    *(s16 *)(s + 0x78) = start;
    *(s16 *)(s + 0x7A) = mid;
    *(TI_003A6C90 *)base = *(TI_003A6C90 *)(obj + 0x10);
    base[2] += 0.5f;
    j = 0;
    slots = (void **)(s + 0x130);
    three = 3;
    one = 1;
    dst = s + 0xA0;
    for (; j < 9; j++) {
        *(TI_003A6C90 *)point = *(TI_003A6C90 *)base;
        point[0] += (one - j / three) * 1.1f;
        point[1] += (one - j % three) * 1.1f;
        *(TI_003A6C90 *)dst = *(TI_003A6C90 *)point;
        dst += 16;
    }
    for (i = 0; i < 9; i++) {
        if (slots[i]) func_003CD250(slots[i]);
        p = func_L01_00470150(s + 0xA0 + i * 16, 0, 0x18204080, -1, 1, -1, 0, -1, 0.0f, 0.5f, 1.0f, 0, 0);
        slots[i] = p;
        if (p) *(f32 *)((u8 *)p + 0x18) -= 0.75f;
    }
    return 1;
}
/* localdecomp:end func_L07_003A6C90 */
