/* functional: high. same calls in the same order with same arguments; only register allocation differs */
extern u8 D_L01_00284500[];
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_0035ABB8(char *);

void func_L01_0035AC28(s32 unused, f32 *pos, u128_t *src, u128_t *vel) {
    s32 idx, k;
    u8 *rec;
    for (idx = 0; idx < 25; idx++) {
        rec = D_L01_00284500 + idx * 0x530;
        if (*(s32 *)(rec + 0x514) != 0) continue;
        for (k = 0; k < 2; k++) {
            u8 *p = rec + k * 0x90;
            f32 r;
            func_L01_0035ABB8((char *)(p + 0x2A0));
            func_L01_0035ABB8((char *)(p + 0x60));
            r = func_003824E0(0.3f, 0.5f);
            *(f32 *)(p + 0x64) *= r;
            *(f32 *)(p + 0x74) *= r;
            *(f32 *)(p + 0x84) *= r;
            *(f32 *)(p + 0x94) *= r;
            r = func_003824E0(0.2f, 1.3f);
            *(f32 *)(p + 0x78) *= r;
            *(f32 *)(p + 0x98) *= r;
            *(f32 *)(p + 0x74) *= 0.4f;
            *(f32 *)(p + 0x94) *= 0.4f;
            *(f32 *)(rec + 0x20 + k * 0x10) = pos[0] + func_003824E0(-0.1f, 0.1f);
            *(f32 *)(rec + 0x24 + k * 0x10) = pos[1] + func_003824E0(-0.1f, 0.1f);
            *(f32 *)(rec + 0x28 + k * 0x10) = pos[2];
            *(f32 *)(rec + 0x2C + k * 0x10) = 1.0f;
            *(f32 *)(rec + 0x4F0 + k * 4) = func_003824E0(-0.03f, -0.01f);
            *(f32 *)(rec + 0x500 + k * 4) = func_003824E0(-7.99f, 0.0f);
            *(s32 *)(rec + 0x4E0 + k * 4) = func_0013D3E0() % 2;
        }
        *(s32 *)(rec + 0x510) = 0;
        *(s32 *)(rec + 0x514) = 1;
        *(s32 *)(rec + 0x518) = 0;
        *(s32 *)(rec + 0x51C) = 0;
        *(u128_t *)(rec + 0x10) = *vel;
        *(u128_t *)rec = *src;
        return;
    }
}
