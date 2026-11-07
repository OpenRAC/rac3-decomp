#include "common.h"

/* localdecomp:start func_L03_00399278 */
extern f32 D_001DE350_sda; __asm__(".extern D_001DE350_sda, 4");
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
void func_L03_00399278(u8 *self)
{
    s32 s = self[0x20];
    f32 *p = *(f32 **)(self + 0x68);
    f32 v;
    switch (s) {
    case 0:
        *(u16 *)(self + 0x34) |= 0x2000;
        *p = 1.0f;
        func_L01_004450F0(self, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(self)) {
            func_L01_004450F0(self, 2, -1);
        }
        break;
    case 2:
        self[0x23] = (s32)(*p * 128.0f);
        v = *p - D_001DE350_sda * 1.2f;
        *p = v;
        if (v <= 0.0f) {
            *p = 0.0f;
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(self, 1);
            func_L01_004450F0(self, 3, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_00399278 */

INCLUDE_ASM("asm/levels", func_L03_003993A0);

/* localdecomp:start func_L03_00399868 */
extern f32 func_00382538(void);
extern void func_L01_003F5E88(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L03_00399868(u8 *self)
{
    u8 *s;

    if (self[0x95] == 0) {
        s = *(u8 **)(self + 0x68);
        *(f32 *)(s + 0x40) = *(f32 *)(self + 0x18);
        *(f32 *)(s + 0x44) = *(f32 *)(self + 0x18) - 6.8f;
        *(f32 *)(s + 0x74) = func_00382538();
        s[0x7F] = 15;
        func_L01_003F5E88(self);
        func_L01_004450F0(self, 0, 1);
    }
}
/* localdecomp:end func_L03_00399868 */

INCLUDE_ASM("asm/levels", func_L03_003998E8);

/* localdecomp:start func_L03_00399BD8 */
extern s32 func_00382498(s32, s32);

s32 func_L03_00399BD8(u8 *p, s32 n) {
    s32 i;
    s32 base;
    s32 r;

    base = func_00382498(0, n - 1);
    for (i = 0; i < n; i++) {
        r = (base + i) % n;
        if ((((*p >> r) ^ 1) & 1)) {
            *p |= 1 << r;
            return r;
        }
    }
    return -1;
}
/* localdecomp:end func_L03_00399BD8 */

/* localdecomp:start func_L03_00399C68 */
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L03_00399C68(u8 *obj, s32 a1, s32 a2, s32 a3)
{
    if (obj[0x95] == 1) {
        u8 *m = *(u8 **)(obj + 0x68);
        m[0x7C] = a1;
        m[0x7D] = a2;
        m[0x7E] = a3;
        *(s32 *)(m + 0x5C) = func_L01_004AAC98(0, 4, obj, 0x18EC);
        func_L01_004450F0(obj, 0, 2);
    }
}
/* localdecomp:end func_L03_00399C68 */

/* localdecomp:start func_L03_00399CE0 */
void func_L03_00399CE0(u8 *self) {
    if (self[0x95] != 0) {
        u8 *p = *(u8 **)(self + 0x68);
        *(f32 *)(self + 0x18) = *(f32 *)(p + 0x40);
        p[0x7F] = 15;
        func_L01_004450F0(self, 0, 1);
    }
}
/* localdecomp:end func_L03_00399CE0 */
