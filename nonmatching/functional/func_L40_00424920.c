/* functional: high. NTSC draft rebuilt for PAL: phase uses 212 (0xD4) and /6 instead of 255, callees func_0038DBD8 and func_L39_005CDCF0, table D_L40_003A33F0; vsub/vadd and fabs in plain C; 134 diff (layout) */
/* localdecomp:start func_L40_00424920 */
extern s32 func_L40_004224E0(u8 *);
extern s32 func_L40_00422540(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L39_005CDCF0(void *, s32, s32, s32, s32, s32, s32, s32, f32);
typedef struct { s32 a, b; } E_424920;
extern E_424920 D_L40_003A33F0[];
extern s32 D_L40_0024112C;
extern f32 D_001DC030_sda;
extern f32 D_001DC034_sda;
extern s32 D_001DC038_sda;
extern s32 D_001DC03C_sda;
__asm__(".extern D_001DC030_sda, 4");
__asm__(".extern D_001DC034_sda, 4");
__asm__(".extern D_001DC038_sda, 4");
__asm__(".extern D_001DC03C_sda, 4");

void func_L40_00424920(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    s32 i;
    s32 j;
    s32 idx;
    s32 x;
    s32 a;
    f32 d;
    E_424920 *tbl;

    if (func_L40_004224E0(a0)) {
        idx = *(s32 *)(p + 0x7C);
    } else {
        if (!func_L40_00422540(a0)) {
            return;
        }
        idx = *(s32 *)(p + 0x80);
    }
    tbl = &D_L40_003A33F0[idx];
    if (*(void **)(p + 0x78) != 0) {
        func_0038CE20(v, *(void **)(p + 0x78), 0.0009765625f);
    } else {
        w[0] = *(f32 *)(a0 + 0xE0);
        w[1] = *(f32 *)(a0 + 0xE4);
        w[2] = *(f32 *)(a0 + 0xE8);
        w[3] = *(f32 *)(a0 + 0xEC);
        func_0038CF68(w, w, 0.75f);
        v[0] = *(f32 *)(a0 + 0x10) + w[0];
        v[1] = *(f32 *)(a0 + 0x14) + w[1];
        v[2] = *(f32 *)(a0 + 0x18) + w[2];
        v[3] = *(f32 *)(a0 + 0x1C);
    }
    j = 0;
    for (i = 0; i < 4; i++) {
        s32 col;
        x = (D_L40_0024112C + j) & 0xFF;
        d = 0.5f - (f32)(0xD4 - (x * 5 + 2) / 6) / 212.0f;
        if (d < 0.0f) {
            d = -d;
        }
        col = func_0038DBD8(tbl->a, tbl->b, d);
        j += 0x14;
        a = (u8)D_L40_0024112C;
        if (i & 2) {
            a = a << 1;
        }
        if (i & 1) {
            a = 0xFF - a;
        }
        func_L39_005CDCF0(v, col, a & 0xFF, D_001DC03C_sda, D_001DC038_sda, 2, 0, 0,
                          (D_001DC030_sda + (f32)i * D_001DC034_sda) * (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24)));
    }
}
/* localdecomp:end func_L40_00424920 */
