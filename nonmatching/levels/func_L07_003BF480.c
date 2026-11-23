/* func_L07_003BF480 (level 7): near miss, 36 diff under the file's own line (-O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as); the existing draft (Codex wave 11) is 38. Changed against it:
   the 0x44 written to particle[3] in the loop comes from a local set before the loop
   ('alpha = 0x44'), which brings the loop's tail (the sb of particle[3]/[2] and the loop count)
   back to retail's order. Still differs: (1) the VU0 add is one asm block (the file's line has no
   -mvu0-use-vf0-vf2, so the vu0.h vec_add helpers that let retail interleave lqc2/vadd/sqc2 with
   the address setup cannot be used): 8 words; (2) retail keeps 0x44 in fp and rematerialises the
   cmov constant 2 (addiu v1, 2 before movn); here the register allocator gives fp to the hoisted
   cmov constant (pseudo 202: 3 refs over 144 insns) ahead of alpha (3 refs over 152 insns, which
   sched1 sets in the first jal delay slot), so 2 sits in fp and 0x44 is rematerialised. loop.c
   (rerun pass) moves only two life-1 constants: the 0.06f and the cmov 2, never the QImode 0x44
   store constant; alpha at the loop top, in the for-init or after the call gives the same 36 or
   worse (203 when CSE carries alpha into the second block). */
#include "common.h"

/* localdecomp:start func_L07_003BF480 */
extern f32 D_001DE520_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DE520_sda, 4");
extern s32 D_001DE510_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DE510_sda, 4");
extern u8 D_L07_0021EC98[];
void func_L07_003BF480(u8 *m) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L07_003B9C28(void *, s32, s32, s32, s32, f32, f32, f32, f32);
    extern void func_0038D750(void *, s32, f32);
    extern void func_0038D810(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    f32 q[4];
    f32 matrix[3][4];
    V_003BF3A8 pos, at, velocity, scratch;
    s32 index;
    s32 tint;
    s32 i;
    f32 scale;
    u8 *base;
    s32 alpha;

    index = (u8)func_00382468(3);
    scale = D_001DE520_sda[index];
    tint = D_001DE510_sda[index];
    func_L07_003B9C28(m + 0x10, 8, 2, tint, tint, scale * 3.0f, scale * 15.0f, scale * 3.0f, scale * 8.0f);
    func_0038D750(q, 2, *(f32 *)(m + 0xF8));
    func_0038D810(q, matrix);
    func_0038CE20(&pos, matrix, 1.25f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(pos)
            : "m"(*(V_003BF3A8 *)(m + 0x10)), "m"(pos)
            : "vf1", "vf2");
    base = D_L07_0021EC98;
    alpha = 0x44;
    for (i = 1; i >= 0; i--) {
        s32 life;
        s32 rotation;
        f32 size;
        u8 *particle;

        *(u128_t *)&at = *(u128_t *)&pos;
        func_003C4C18(&at, 1.5f);
        *(u128_t *)&scratch = 0;
        scratch.y = func_00382468(2) ? -0.060000002f : 0.060000002f;
        scratch.z = 0.060000002f;
        *(u128_t *)&velocity = *(u128_t *)&scratch;
        func_0038D000(&velocity, &velocity, matrix);
        func_003C4C18(&velocity, 0.0200000014f);
        life = func_00382498(17, 33);
        rotation = 254;
        if (func_00382468(2) != 0) {
            rotation = 2;
        }
        size = func_003824E0(126000.0078125f, 189000.0f);
        particle = func_L01_00475C60(&at, &velocity, life, rotation, 0x7F5786AE, 0x2E475C, 0, size, size * 1.5f, 0.0200000014f);
        if (particle != 0) {
            particle[3] = alpha;
            particle[2] = **(u8 **)(base + 0x10);
        }
    }
    if (func_00382468(6) == 0) {
        s32 life;
        s32 color;
        s32 rotation;
        f32 size;
        u8 *particle;

        *(u128_t *)&at = *(u128_t *)&pos;
        func_003C4C18(&at, 0.15f);
        *(u128_t *)&scratch = 0;
        scratch.y = func_00382468(2) ? -0.3f : 0.3f;
        scratch.z = 0.2000000179f;
        *(u128_t *)&velocity = *(u128_t *)&scratch;
        func_0038D000(&velocity, &velocity, matrix);
        func_003C4C18(&velocity, 0.100000009f);
        life = func_00382498(50, 67);
        color = 0x2E475C;
        if (func_00382468(2) != 0) {
            color = 0x5786AE;
        }
        rotation = 254;
        if (func_00382468(2) != 0) {
            rotation = 2;
        }
        size = func_003824E0(42000.0f, 63000.00390625f);
        particle = func_L01_004713C8(&at, &velocity, life, color, rotation, 127, 127, func_00382468(3) + 10, size, size, 0.0100000007f);
        if (particle != 0) {
            particle[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L07_003BF480 */
