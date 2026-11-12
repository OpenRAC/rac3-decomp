/* func_L36_003A87C0: near miss, level 36 (Vidcomic 1 Special Edition). 13 differences (file builds with -mvu0-use-vf0-vf2 @ps2as): every instruction is there; retail loads $f13 (D_L36_001DEAB8) before the loop's first sub.s and again in the delay slot of the bottom bc1t, so neg.s comes before the swc1; ours schedules the load after the swc1 and fills the slot with bc1tl + a copy of sub.s. Statement orders, const on the global, and while/do-while tried */
__asm__(".extern D_L36_001DEAC8, 4");
__asm__(".extern D_L36_001DEAD4, 4");
__asm__(".extern D_L36_001DEAB8, 4");
__asm__(".extern D_L36_001DEAC0, 4");
__asm__(".extern D_L36_001DEAD0, 4");
__asm__(".extern D_L36_001DEAC4, 4");
__asm__(".extern D_L36_001DEAB4, 4");
__asm__(".extern D_L36_001DEABC, 4");
__asm__(".extern D_L36_001DEACC, 4");
extern f32 D_L36_001DEAC8;
extern s32 D_L36_001DEAD4;
extern f32 D_L36_001DEAB8;
extern f32 D_L36_001DEAC0;
extern f32 D_L36_001DEAD0;
extern f32 D_L36_001DEAC4;
extern f32 D_L36_001DEAB4;
extern s32 D_L36_001DEABC;
extern s32 D_L36_001DEACC;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004713C8(void *, void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
void func_L36_003A87C0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 v0, v1;
    s32 col;
    f32 r;
    *(f32 *)(s + 0xC) = *(f32 *)(s + 0xC) + D_L36_001DEAC8 * (f32)*(s32 *)(s + 0x10) / (f32)D_L36_001DEAD4;
    if (1.0f < *(f32 *)(s + 0xC)) {
        do {
            *(f32 *)(s + 0xC) = *(f32 *)(s + 0xC) - 1.0f;
            *(u128_t *)&v1 = *(u128_t *)(a0 + 0x10);
            v1.x = v1.x + func_003824E0(-D_L36_001DEAB8, D_L36_001DEAB8);
            v1.z = v1.z + func_003824E0(-D_L36_001DEAB8, D_L36_001DEAB8);
            qzero(&v0);
            v0.z = D_L36_001DEAD0;
            col = (*(s32 *)(s + 8) << 16) | (*(s32 *)(s + 4) << 8) | *(s32 *)s;
            r = func_003824E0(D_L36_001DEAC0, D_L36_001DEAC4);
            func_L01_004713C8(&v1, &v0, r, 0.0f, D_L36_001DEAB4, D_L36_001DEABC, col, func_00382498(-4, 4), 0x80, 0, D_L36_001DEACC);
        } while (1.0f < *(f32 *)(s + 0xC));
    }
}
