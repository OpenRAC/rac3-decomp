/* func_L36_003540D8: near miss, level 36 (Vidcomic 1 Special Edition). 21 differences, one cause: retail keeps the object pointer a0 in $s2 and its state pointer s in $s1 (the D_001A4BE0 base in $s0), ours swaps $s1/$s2 (the u128_t typedef is in the file prelude); declaration order, caching the 0x5C field and a late assignment of s tried */
__asm__(".extern D_L36_001DD910, 4");
__asm__(".extern D_L36_001DD90C, 4");
__asm__(".extern D_L36_001DD914, 4");
extern f32 D_L36_001DD910;
extern f32 D_L36_001DD90C;
extern f32 D_L36_001DD914;
extern u8 D_001A4BE0[];
extern f32 func_0038CF00(u8 *, f32 *);
extern void func_0038CF68(f32 *, u8 *, f32);
extern void func_L36_00354648(u8 *);
extern void func_L36_00354288(u8 *);
extern void func_L30_0034CB68(u8 *, f32 *, s32, s32, u8 *, s32, f32, f32);
void func_L36_003540D8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    u8 *g;
    f32 one_minus;
    f32 d;
    f32 t;
    if (*(s32 *)(s + 0x5C) == 0) {
        g = D_001A4BE0;
        *(u128_t *)v = *(u128_t *)s;
        v[1] = *(f32 *)(g + 0x84);
        one_minus = 1.0f - D_L36_001DD910;
        d = func_0038CF00(g + 0x80, v) / D_L36_001DD90C;
        if (1.0f < d) {
            *(u8 *)(a0 + 0x23) = (s32)((D_L36_001DD910 + one_minus) * 128.0f);
        } else {
            d = func_0038CF00(g + 0x80, v) / D_L36_001DD90C;
            *(u8 *)(a0 + 0x23) = (s32)((D_L36_001DD910 + one_minus * d) * 128.0f);
        }
    } else {
        t = (f32)*(u8 *)(a0 + 0x23) + 1.0f;
        if (128.0f < t) {
            *(u8 *)(a0 + 0x23) = 0x80;
        } else {
            *(u8 *)(a0 + 0x23) = (s32)t;
        }
    }
    if (*(s32 *)(s + 0x5C) != 1) {
        if (*(s16 *)(s + 0x46) != 0) {
            func_L36_00354648(a0);
        } else {
            func_L36_00354288(a0);
        }
    }
    if (*(s32 *)(s + 0x5C) == 2) {
        func_0038CF68(w, s + 0x20, 1.0f);
        func_L30_0034CB68(a0, w, 1, -1, s, 0, D_L36_001DD914, *(f32 *)(s + 0x50));
    }
}
