#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003B7408);

INCLUDE_ASM("asm/levels", func_L07_003B7548);

INCLUDE_ASM("asm/levels", func_L07_003B7E40);

INCLUDE_ASM("asm/levels", func_L07_003B7F80);

/* localdecomp:start func_L07_003B8448 */
extern void func_003C2880(s32 p);
extern void func_L07_00334740(void *);
extern void func_L07_003B8690(void *, s32);
extern u8 D_L07_001E1EC0[];

void func_L07_003B8448(void *arg0) {
    u8 *temp_s0;
    s32 temp_a0;
    u8 *g;

    temp_s0 = *(u8 **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x288);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x288) = 0;
    }
    *(u8 *)(temp_s0 + 0x187) = 0;
    *(u8 *)(temp_s0 + 0x188) = 0;
    *(u8 *)(temp_s0 + 0x189) = 0;
    g = D_L07_001E1EC0;
    if (*(void **)(g + 0x144) == arg0) {
        *(void **)(g + 0x144) = 0;
    }
    func_L07_00334740(arg0);
    func_L07_003B8690(arg0, 1);
}
/* localdecomp:end func_L07_003B8448 */

INCLUDE_ASM("asm/levels", func_L07_003B84C0);

INCLUDE_ASM("asm/levels", func_L07_003B8690);

/* localdecomp:start func_L07_003B8870 */
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L07_003B8870(u8 *arg0) {
    u8 *o = *(u8 **)(arg0 + 0x68);

    if (*(f32 *)(o + 0x218) > 1.3962634f) {
        *(f32 *)(o + 0x218) = 1.3962634f;
    } else if (*(f32 *)(o + 0x218) < -1.3962634f) {
        *(f32 *)(o + 0x218) = -1.3962634f;
    }
    func_L01_0044E850(arg0, o + 0x1B0, 1, 0.0432f, 0.43200005f);
}
/* localdecomp:end func_L07_003B8870 */

INCLUDE_ASM("asm/levels", func_L07_003B88F0);

/* localdecomp:start func_L07_003B89C0 */
void func_L07_003B89C0(int a, void (*fn)(void)) {
    if (fn)
        fn();
}
/* localdecomp:end func_L07_003B89C0 */

INCLUDE_ASM("asm/levels", func_L07_003B89E0);

INCLUDE_ASM("asm/levels", func_L07_003B8AE0);

/* localdecomp:start func_L07_003B8BA0 */
extern f32 func_0038D160(f32, f32);
extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
extern void func_L07_003B8690(void *, s32);

void func_L07_003B8BA0(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *t = *(u8 **)(s + 0x190);
    f32 a;

    a = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(s + 0x70),
                      *(f32 *)(t + 0x14) - *(f32 *)(s + 0x74));
    func_L03_0032FAF0((f32 *)(s + 0x270), (f32 *)(*(u8 **)(s + 0x190) + 0x10),
                      (f32)(s32)(a / 0.785398f) * 0.785398f, 20.0f);
    *(s32 *)(s + 0x290) = 0;
    *(u8 *)(s + 0x298) = 0;
    *(u8 *)(s + 0x297) = 6;
    func_L07_003B8690(arg0, 10);
}
/* localdecomp:end func_L07_003B8BA0 */

/* localdecomp:start func_L07_003B8C50 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L07_001DF500_003B8C50;
extern void func_L07_003A2380(s32, void *, s32, s32);
extern void func_L07_003B8690(void *, s32);

void func_L07_003B8C50(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (s[0x296] == 1) {
        func_L07_003A2380(0xF, a0, 0, 0x64);
    }
    s[0x299] = 0;
    *(u128_t *)(s + 0x270) = *(u128_t *)(&D_L07_001DF500_003B8C50[(*(s32 *)(s + 0x284) << 7) + 0x30]);
    s[0x298] = 2;
    s[0x297] = 0xE;
    *(s32 *)(s + 0x290) = 0;
    func_L07_003B8690(a0, 10);
}
/* localdecomp:end func_L07_003B8C50 */

INCLUDE_ASM("asm/levels", func_L07_003B8CE0);

INCLUDE_ASM("asm/levels", func_L07_003B8D80);

/* localdecomp:start func_L07_003B8F88 */
void func_L07_003B8FC0(void *, s32);

void func_L07_003B8F88(void *arg0) {
    func_L07_003B8FC0(arg0, 2);
    func_L07_003B8FC0(arg0, 3);
}
/* localdecomp:end func_L07_003B8F88 */

INCLUDE_ASM("asm/levels", func_L07_003B8FC0);
