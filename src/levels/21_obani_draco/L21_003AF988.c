#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L21_003AF988 */
extern u8 D_L21_001E1700[];
extern s32 D_L21_001DE8C0;
extern u8 D_L21_001DCF40;
extern f32 D_L21_001DCF50;
__asm__(".extern D_L21_001DE8C0, 4");
__asm__(".extern D_L21_001DCF50, 4");
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L21_003AFBA8(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L21_003AF988(u8 *m)
{
    u8 *p = *(u8 **)(m + 0x68);

    if (m[0x31] != 0) {
        if (func_L01_0040E548(D_L21_001E1700, m + 0x10) < 1024.0f) {
            func_L01_004472C0(m);
            m[0x6F] = 0x1E;
        }
    }
    func_L01_00452860(m, p + 0x30, 0);
    func_L01_00452FB0(m, p + 0xD0, 0, 0, 0);
    if (p[0x3E] == 2) {
        func_L21_003AFBA8(m);
    }
    if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
        if (0.0f < *(f32 *)(p + 0x30)) {
            if (p[0x5F] != 0) {
                func_L01_00456BD0(m, 5);
            } else {
                func_L01_00456BD0(m, 3);
            }
        }
    }
    if (m[0x20] == 4 && (*(s16 *)(m + 0xB2) + 8) % 8 == D_L21_001DE8C0 % 8) {
        if (p[0x5F] != 0) {
            func_L01_00456C98(m, -1, (s32)&D_L21_001DCF40, 0, 0, 0, 3, 0, 0, 0, D_L21_001DCF50, 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, -1, (s32)&D_L21_001DCF40, 0, 0, 0, 2, 0, 0, 0, D_L21_001DCF50, 10.0f, 1.0f);
        }
    }
    func_L01_00451DF8(m, p + 0x280, 2, 1, 2.5f);
}
/* localdecomp:end func_L21_003AF988 */

/* localdecomp:start func_L21_003AFBA8 */
extern u8 *func_00382348(void *);
extern u8 *func_L01_00448FF0(u8 *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L21_003B00A0(void *, s8);
extern void func_L21_003B00C0(void *, s8);
void func_L21_003AFBA8(void *arg) {
    u8 *a0 = arg;
    u8 *p;
    u8 *r;
    s32 i;
    a0[0x7F] = 0;
    p = func_00382348(a0);
    *(f32 *)(p + 0) = (f32)*(s16 *)(p + 4);
    r = func_L01_00448FF0(a0);
    *(s16 *)(r + 0x38) = 0;
    r[0x7] = 0;
    r[0x9] = 0;
    r[0x8] = 0;
    p[0xE] = 1;
    p[0x2F] = 0;
    ((s32 (*)(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32))func_L01_00456C98)(a0, -1, 0, 0, 0, 0, 3, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    *(s32 *)(a0 + 0x98) = 0;
    a0[0xA8] = 0xFF;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(a0, 1);
    for (i = 0; i < 0x34; i++) {
        if (func_L01_004AA710(a0, i) != 0) {
            func_003A4F28(i);
        }
    }
    func_L21_003B00A0(a0, 0);
    func_L21_003B00C0(a0, -1);
    if (a0[0x20] != 0) {
        func_L01_004443E8(a0, 0, 3);
        a0[0x7F] = 0;
    }
    func_L01_004450F0(a0, 1, 4);
}
/* localdecomp:end func_L21_003AFBA8 */
