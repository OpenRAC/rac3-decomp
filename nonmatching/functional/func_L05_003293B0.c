/* functional: high. Same call sequence and arguments as retail (checked jal-by-jal); VU xyz adds written as scalar float adds (w untouched, as vadd.xyz). Struct/global names from gp offsets: D_L05_001DC8F0 (+0x40) and D_L05_001DC91C (+0x6C) are $gp-relative in retail but lui-addressed here. */
typedef int u128_3293B0 __attribute__((mode(TI)));
extern f32 D_L05_001DC8F0[];
extern f32 D_L05_001DC91C;
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_L01_004668A0(void *, void *, u32, s32, s32, f32);

void func_L05_003293B0(u8 *o, u8 *s, f32 *base) {
    u128_3293B0 v10;
    u128_3293B0 v20;
    u128_3293B0 v30;
    u128_3293B0 b;
    f32 *f10 = (f32 *)&v10;
    f32 *f20 = (f32 *)&v20;
    f32 *f30 = (f32 *)&v30;
    f32 *fb = (f32 *)&b;
    s32 i;
    s32 r;
    s32 k;
    u32 col;
    f32 sz;

    b = *(u128_3293B0 *)base;
    if (o[0x20] == 3 && 0.0f < *(f32 *)(s + 0x168)) {
        for (i = 0; i < 2; i++) {
            v20 = *(u128_3293B0 *)(o + 0x10);
            func_0038D000(&v30, D_L05_001DC8F0 + i * 4, o + 0xC0);
            f20[0] = f20[0] + f30[0];
            f20[1] = f20[1] + f30[1];
            f20[2] = f20[2] + f30[2];
            func_0038CE20(&v10, o + 0xC0, *(f32 *)(s + 0x168) * D_L05_001DC91C);
            r = func_00382498(0x10, 0x20);
            col = 0x7F000000 | ((r + 8) << 16) | (r << 8) | r;
            k = func_00382498(0, 2) - 1;
            sz = func_003824E0(0.5f, 0.75f) * 210000.0f;
            func_L01_004669B0(&v20, 0.25f, 0.8f, 1.01f, sz, k, &v10, col, 0);
            f30[0] = fb[0] - *(f32 *)(o + 0x10);
            f30[1] = fb[1] - *(f32 *)(o + 0x14);
            f30[2] = fb[2] - *(f32 *)(o + 0x18);
            func_0038CE20(&v30, &v30, 0.5f);
            f20[0] = f20[0] + f30[0];
            f20[1] = f20[1] + f30[1];
            f20[2] = f20[2] + f30[2];
            r = func_00382498(0x20, 0x40);
            col = 0x40000000 | (r << 16) | (r << 8) | r;
            sz = func_003824E0(1.0f, 1.5f) * 210000.0f;
            k = func_00382498(0xF, 0x14);
            func_L01_004668A0(&v20, &v10, col, 0x101010, (k * 5 + 2) / 6, sz);
        }
    }
}
