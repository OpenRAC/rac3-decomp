/* func_L24_003B69F8: level 24 near miss. 20 differences (VU0 helpers vec_sub_ab/vec_add_ab/vec_sub_ba/vec_add_ba from include/vu0.h, needs -mvu0-use-vf0-vf2 and @ps2as on L24_003B6050.c, plus __asm__(".extern D_L24_001DE804, 4") for the $gp divisor): the $gp divisor load is scheduled differently (retail hoists lw $v1,0x1F54($gp) into the bc1f slot and re-reads it in the p->900>=2 block; this C reads it into $a0 and reorders the 8FC load/mfhi/slt). A function-scope local for the divisor gave 28; a block-scope local gave 20. Declares the function with void *arg0 because func_L24_003B6320 declares it that way */
__asm__(".extern D_L24_001DE804, 4");
extern s32 D_L24_001DE804;
extern void func_L24_004214F8(s32, s32, void *);
extern void func_L24_00421460(s32, s32, void *);
extern void func_L24_003F6888(void *, void *, f32);
extern void func_L24_00432DE0(void *, void *, void *, s32, f32);
extern void func_L24_0042DC40(void *, void *);

void func_L24_003B69F8(void *arg0) {
    u8 *a0 = arg0;
    f32 a[4] __attribute__((aligned(16)));
    f32 d[16] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 f[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    f32 h[4] __attribute__((aligned(16)));
    f32 i[4] __attribute__((aligned(16)));
    f32 j[4] __attribute__((aligned(16)));
    u8 *p = *(u8 **)(a0 + 0x68);
    *(s32 *)(p + 0x8F8) = 0;
    func_L24_004214F8(*(s32 *)(p + 0x8DC), 3, a);
    func_L24_00421460(*(s32 *)(p + 0x8DC), 3, d);
    func_L24_004214F8(*(s32 *)(p + 0x8DC), 2, e);
    vec_sub_ab(f, e, a);
    func_L24_003F6888(f, f, *(f32 *)(p + 0x8E4));
    vec_add_ab(a, f, e);
    if (*(f32 *)(p + 0x8F8) == 0.0f) {
        s32 n = D_L24_001DE804;
        *(s32 *)(p + 0x8EC) = (*(s32 *)(p + 0x8EC) + 1) % n;
        if (*(s32 *)(p + 0x8FC) < n) {
            *(s32 *)(p + 0x8FC) = *(s32 *)(p + 0x8FC) + 1;
        }
    }
    g[0] = 0;
    g[1] = 0;
    g[2] = 0;
    g[3] = 0;
    if (*(s32 *)(p + 0x900) >= 2) {
        vec_sub_ab(h, a, a0 + 0x10);
        vec_sub_ba(i, p + 0x2C0 + ((*(s32 *)(p + 0x8EC) + D_L24_001DE804 - 1) % D_L24_001DE804) * 16, a0 + 0x10);
        func_L24_00432DE0(j, i, h, 0, 0.5f);
        func_L24_0042DC40(p + 0x4C0 + *(s32 *)(p + 0x8EC) * 16, g);
        vec_add_ba(p + 0x2C0 + *(s32 *)(p + 0x8EC) * 16, j, a0 + 0x10);
        *(s32 *)(p + 0x8EC) = (*(s32 *)(p + 0x8EC) + 1) % D_L24_001DE804;
    }
    func_L24_0042DC40(p + 0x4C0 + *(s32 *)(p + 0x8EC) * 16, g);
    *(vu0_q *)(p + 0x2C0 + *(s32 *)(p + 0x8EC) * 16) = *(vu0_q *)a;
}
