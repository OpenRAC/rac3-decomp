/* functional: high. Math verified against PAL asm (100-p[0x3D/0x3E])*2.55 scale, z=f40/f44*1024, linear fit coefficients); symbol names carry per-function aliases only for the near-miss check. */
__asm__(".extern D_L02_001E00E0, 16");
__asm__(".extern D_L02_001E00E4, 16");
__asm__(".extern D_L02_001E00E8, 16");
__asm__(".extern D_L02_001E00EC, 16");
__asm__(".extern D_L02_001E5EE0, 16");
extern f32 D_L02_001E00E0;
extern f32 D_L02_001E00E4;
extern f32 D_L02_001E00E8;
extern f32 D_L02_001E00EC;
extern f32 D_L02_001E5EE0[];

void func_L02(void *arg0) {
    u8 *p = arg0;
    f32 a = (100.0f - (f32)p[0x3D]) * 2.55f;
    f32 b = (100.0f - (f32)p[0x3E]) * 2.55f;
    f32 z0 = *(f32 *)(p + 0x40) * 1024.0f;
    f32 z1 = *(f32 *)(p + 0x44) * 1024.0f;
    f32 inv;

    D_L02_001E00E4 = b;
    D_L02_001E00E0 = a;
    inv = 1.0f / (z1 - z0);
    D_L02_001E00EC = (a * z1 - b * z0) * inv;
    D_L02_001E00E8 = (b - a) * D_L02_001E5EE0[0] * inv;
}
