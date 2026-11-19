/* functional: high. Plain-C rewrite of vadd.xyz: x,y,z summed, w kept from the first operand. Callee 0x382578 is an unmatched level function; four float args in f12..f15 as retail. */
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00382578(s32 a0, s32 a1, s32 alpha);
extern u8 D_001DDCE0_sda[8];
__asm__(".extern D_001DDCE0_sda, 8");
extern s32 D_L01_001E1E94;

void func_L01_00382500(u8 *a0) {
    f32 v[4] __attribute__((aligned(16)));
    f32 *p;

    func_0038D000(v, D_001DDCE0_sda, a0 + 0xC0);
    p = (f32 *)(a0 + 0x10);
    /* vadd.xyz: x,y,z summed, w comes from the first operand (a0+0x10) */
    v[0] = p[0] + v[0];
    v[1] = p[1] + v[1];
    v[2] = p[2] + v[2];
    v[3] = p[3];
    ((void (*)(void *, s32, s32, f32, f32, f32, f32))func_L01_00382578)(v, 0x78, D_L01_001E1E94 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
