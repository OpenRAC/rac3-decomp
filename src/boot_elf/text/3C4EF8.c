#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C4FD0(f32 *v, f32 r);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C4EF8 */
s32 func_003C4EF8(s32 arg0) {
    return (u32)(arg0 - 500) < 41;
}
/* localdecomp:end func_003C4EF8 */

/* localdecomp:start func_003C4F08 */
extern s32 func_003C4EF8_003C4F08(s16);
extern u32 D_001DA49C[];
extern u32 D_001DA4A4[];
s32 func_003C4F08(u32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 < D_001DA49C[0]) return 0;
    if (D_001DA4A4[0] >= arg0) {
        return func_003C4EF8_003C4F08(*(s16 *)((u8 *)arg0 + 0xAA)) != 0;
    }
    return 0;
}
/* localdecomp:end func_003C4F08 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4F58);

/* localdecomp:start func_003C4F68 */
extern f32 func_0038D288(s32 a);
extern void func_0038D348(s32 a, s32 b, f32 x);
void func_003C4F68(s32 a, f32 x) {
    if (x < func_0038D288(a)) func_0038D348(a, a, x);
}
/* localdecomp:end func_003C4F68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4FB8);

/* localdecomp:start func_003C4FD0 */
extern f32 func_003828C0(f32, f32);
void func_003C4FD0(f32 *v, f32 r) {
    v[0] += func_003828C0(-r, r);
    v[1] += func_003828C0(-r, r);
    v[2] += func_003828C0(-r, r);
}
/* localdecomp:end func_003C4FD0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5050);

/* localdecomp:start func_003C50A0 */
extern void func_0038D348(s32 a, s32 b, f32 x);
void func_003C50A0(void *a, f32 f) {
    f32 r;
    ((void (*)(void *, f32))func_0038D348)(a, f);
    r = 1.0f - f * f;
    __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(r) : "f"(r));
    *(f32*)((u8*)a + 0xC) = r;
}
/* localdecomp:end func_003C50A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C50F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C5110);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5148);

/* localdecomp:start func_003C5160 */
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0038D708();
extern void func_0038D990();
extern void func_0038DA20();
extern void func_003C4C60();
void func_003C5160(u8 *p, u128_3BF838 *a1, u128_3BF838 *a2, void *a3) {
    M_3BF838 m0, m1, m2, m3;
    func_0038D708(&m0, a2);
    func_0038D990(&m1, &m0);
    func_0038D708(&m2, a3);
    func_0038DA20(&m3, &m1, &m2);
    func_003C4C60(&m3, p);
    if (*(s32 *)(p + 0x3C) & 2) {
        *(u128_3BF838 *)(p + 0x20) = *a2;
    }
    *(u128_3BF838 *)(p + 0x10) = *a1;
}
/* localdecomp:end func_003C5160 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5220);

extern s32 func_0038D438(f32 *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C5238);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C5340);

/* localdecomp:start func_003C5418 */
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0038D990(M_3BFAF8 *, void *);
void func_0038D3E0(void *, void *, M_3BFAF8 *);
void func_003C5418(u8 *a, void *b, void *c, M_3BFAF8 *d) {
M_3BFAF8 m; if (d == 0) { func_0038D990(&m, a + 0xC0); func_0038D3E0(b, c, &m); } else { func_0038D3E0(b, c, d); }
}
/* localdecomp:end func_003C5418 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5480);

/* localdecomp:start func_003C54A0 */
f32 func_003C54A0(s32 a, s32 b, s32 c) {
    f32 v[4];
    func_003C5418(a, v, b, c);
    return v[2];
}
/* localdecomp:end func_003C54A0 */
