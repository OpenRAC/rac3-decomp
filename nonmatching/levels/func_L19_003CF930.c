/* func_L19_003CF930: 12 diff (register numbering); file already @ps2as */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } V4_3CF930;

extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DC20(f32 *, f32);
extern void func_L01_0040C948(void *, void *);
extern s32 func_00382468(s32);
extern void func_L19_003CF7B8(void *, f32, f32, s32, s32, s32, s32);
extern u8 D_001A4C60[];

void func_L19_003CF930(u8 *a) {
    V4_3CF930 t;
    u8 *s;
    s32 i;
    s32 k;
    s32 m;
    f32 d;
    t.q = *(u128_t *)(a + 0x10);
    s = *(u8 **)(a + 0x68);
    t.f[3] = 0.05f;
    d = func_0038CF00(a + 0x10, D_001A4C60);
    for (i = 0; i < *(s32 *)(s + 8); i++) {
        V4_3CF930 v;
        V4_3CF930 w;
        v.q = *(u128_t *)(s + 0x50 + i * 0xB0);
        v.f[3] = 1.0f;
        if (func_0038DC20(v.f, 64.0f) >= 0 || func_0038DC20(t.f, 64.0f) >= 0) {
            func_L01_0040C948(s + 0x40 + i * 0xB0, s + 0x300);
        }
        k = 15;
        m = 1;
        if (10.0f <= d) {
            k = 10;
            m = 2;
        } else if (20.0f <= d) {
            k = 5;
            m = 3;
        } else if (30.0f <= d) {
            k = 1;
            m = 4;
        } else if (35.0f < d) {
            m = 0;
        }
        if (m == 1 || (m > 0 && func_00382468(0) == 0)) {
            w.q = *(u128_t *)(s + 0x50 + i * 0xB0);
            func_L19_003CF7B8(&w, 0.5f, 1.0f, (k * 5 + 2) / 6, *(s32 *)(s + 4), (k * 5 + 2) / 6, -1);
        }
    }
}
