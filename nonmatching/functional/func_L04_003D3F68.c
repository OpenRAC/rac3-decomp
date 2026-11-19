/* functional: high. Byte-identical at L04 (checked); gp-relative floats named D_L04_<addr>. */
/* localdecomp:start func_L04_003D3F68 */
__asm__(".extern D_001DEBA4_sda, 4");
extern f32 D_001DEBA4_sda;
__asm__(".extern D_001DEBA8_sda, 4");
extern f32 D_001DEBA8_sda;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L04_003D3F68(u8 *self, u8 *o, u8 *base) {
    vu0_v4 v __attribute__((aligned(16)));
    v.x = func_0038D098(*(f32 *)(self + 0xF8)) * D_001DEBA4_sda;
    v.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * D_001DEBA4_sda;
    v.z = 0.0f;
    v.z = D_001DEBA8_sda + v.z;
    vec_add_ab(*(u8 **)(o + 0xD4) + 0x10, base, &v);
    *(f32 *)(*(u8 **)(o + 0xD4) + 0xF8) = *(f32 *)(self + 0xF8);
}
/* localdecomp:end func_L04_003D3F68 */
