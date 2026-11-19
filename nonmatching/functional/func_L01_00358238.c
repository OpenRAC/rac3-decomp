/* functional: high. bytes differ only in register allocation and loop counter form */
extern u8 D_L01_002843C0[];
extern u8 D_L01_00284320[];
extern s32 D_L01_001E1A20[];
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L01_00358238(u8 *a0) {
    u8 tmp[0x50];
    u8 *obj = *(u8 **)(a0 + 0x68);
    u8 *pos = D_L01_002843C0 + 0x10;
    u8 *ground = D_L01_00284320 + 0x10;
    s32 *list = D_L01_001E1A20;
    s32 i;
    for (i = 8; i >= 0; i--) {
        f32 g;
        func_003C2EC0((void *)*list, 0, tmp + 0x10);
        func_0038CF68(tmp, tmp + 0x10, *(f32 *)(obj + 0x14));
        vec_add_ab(pos, tmp, tmp + 0x40);
        g = func_003C3D30(ground, 2, 0, 0.5f) + 0.15f;
        if (*(f32 *)(pos + 8) < g) *(f32 *)(pos + 8) = g;
        ground += 0x10; pos += 0x10; list++;
    }
}
