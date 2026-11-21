/* functional: high. Plain f32 subtraction replaces lqc2/vsub.xyz/sqc2 (xyz = b - a->pos, w copied from b); no VU0 flag on this file so not byte exact. */
extern s32 func_L01_0045D248(u8 *, u8 *, f32 *);
s32 func_L01_0045D218(u8 *a, u8 *b) {
    f32 d[4] __attribute__((aligned(16)));
    d[0] = *(f32 *)b - *(f32 *)(a + 16);
    d[1] = *(f32 *)(b + 4) - *(f32 *)(a + 20);
    d[2] = *(f32 *)(b + 8) - *(f32 *)(a + 24);
    d[3] = *(f32 *)(b + 12);
    return func_L01_0045D248(a, b, d);
}
