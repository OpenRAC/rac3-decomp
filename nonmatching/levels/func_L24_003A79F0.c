/* func_L24_003A79F0: level 24 near miss. 15 differences: retail keeps the table entry pointer in $v1 with per-argument register copies (move $t1/$t3/$v0,$v1; extra move $t2,$a3) and n in $t0; this C allocates n in $v1 and the pointer chain in $t2/$a3. Array-indexed D_L24_002B9460[n-1].fXX arguments (same struct as func_L24_003A7750's S_3A7750) are the closest; u8* pointer, S* pointer, index local and argument temporaries in all orders were worse */
extern void func_L24_004214F8(void *, s32, void *);
extern void func_L24_003A6538(void *, void *, void *, f32, f32, s32, s32, s32);

void func_L24_003A79F0(u8 *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    s32 n;
    f32 x14;
    f32 x24;
    s32 x18;
    s32 x1C;
    s32 x20;
    *(u128_t *)b = *(u128_t *)(a0 + 0xC0);
    b[2] += -0.2f;
    func_L24_004214F8(a0, 1, a);
    n = *(s32 *)(a1 + 0x980);
    if (n != 0) {
        x14 = D_L24_002B9460[n - 1].f14;
        x24 = D_L24_002B9460[n - 1].f24;
        x18 = D_L24_002B9460[n - 1].f18;
        x1C = D_L24_002B9460[n - 1].f1C;
        x20 = D_L24_002B9460[n - 1].f20;
        func_L24_003A6538(a0, a, b, x14, x24, x18, x1C, x20);
    }
}
