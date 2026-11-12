#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0034DAB8);

/* localdecomp:start func_L24_0034E250 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_L01_00445F40(u8 *, s32);
extern u8 *D_001A71A0[];

u8 *func_L24_0034E250(s32 a0, void *a1, void *a2, void *a3, s32 a4, f32 f12, f32 f13) {
    u8 *o = func_003C24B0(0x15AF, 0x80);
    u8 *s;

    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        s = *(u8 **)(o + 0x68);
        *(long *)(o + 0x38) = *(long *)(D_001A71A0[0] + 0x38);
        *(u128_t *)(o + 0x10) = *(u128_t *)a2;
        *(u128_t *)(o + 0xF0) = *(u128_t *)a3;
        *(u128_t *)s = *(u128_t *)a1;
        *(s32 *)(s + 0x10) = a0;
        *(f32 *)(s + 0xC) = f12;
        *(f32 *)(s + 0x14) = f13;
        *(f32 *)(s + 0x20) = 0.15f;
        *(s32 *)(s + 0x2C) = 0x10001;
        *(s32 *)(s + 0x24) = 0;
        func_003C7C38(o);
    }
    func_L01_00445F40(o, a4);
    func_003C7C38(o);
    *(s32 *)(o + 0x98) = 0;
    return o;
}
/* localdecomp:end func_L24_0034E250 */

INCLUDE_ASM("asm/levels", func_L24_0034E370);

/* localdecomp:start func_L24_0034E6B0 */
extern void func_L01_004C70A8(char *, char *, unsigned int *, float, int);
void func_L24_0034E6B0(char *a0)
{
    char *s = *(char **)(a0 + 0x68);
    unsigned int c;
    if (((unsigned char *)s)[0x1A4] != 0) {
        c = 0x80008000;
        func_L01_004C70A8(s + 0x170, s + 0x180, &c, 1.0f, 1);
    }
}
/* localdecomp:end func_L24_0034E6B0 */

INCLUDE_ASM("asm/levels", func_L24_0034E6F8);

/* localdecomp:start func_L24_0034EBF8 */
void func_L01_003EB5E0(s32, s32);
void func_L01_003F2AF8(s32, s32);

void func_L24_0034EBF8(void *arg0) {
    s32 temp_a1;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = *(s32 *)((u8 *)temp_s0 + 0x158);
    if (temp_a1 != 0) {
        func_L01_003F2AF8(0, temp_a1);
        *(s32 *)((u8 *)temp_s0 + 0x158) = 0;
        return;
    }
    func_L01_003EB5E0(0, 3);
}
/* localdecomp:end func_L24_0034EBF8 */

INCLUDE_ASM("asm/levels", func_L24_0034EC40);

INCLUDE_ASM("asm/levels", func_L24_0034ED28);
