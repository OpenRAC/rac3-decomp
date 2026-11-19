/* functional: high */
extern f32 D_001DE418_sda;
__asm__(".extern D_001DE418_sda, 4");
extern f32 D_001DE41C_sda;
__asm__(".extern D_001DE41C_sda, 4");
extern f32 D_001DE420_sda;
__asm__(".extern D_001DE420_sda, 4");
extern f32 func_0038CEA8(Vec4 *);
extern f32 func_0038CE68(Vec4 *, u8 *);

void func_L01_003ABF48(u8 *obj, s32 unused, Vec4 *a2, f32 *out1, f32 *out2) {
    Vec4 q = *a2;
    Vec4 v;
    f32 t;

    v.f[0] = *(f32 *)(obj + 0x10) - q.f[0];
    v.f[1] = *(f32 *)(obj + 0x14) - q.f[1];
    v.f[2] = *(f32 *)(obj + 0x18) - q.f[2];
    v.f[3] = *(f32 *)(obj + 0x1C);
    t = func_0038CEA8(&v);
    if (D_001DE418_sda < t) {
        func_0038CF68((u8 *)&v, &v, D_001DE418_sda);
    }
    *out1 = func_0038CE68(&v, obj + 0xD0) * D_001DE41C_sda;
    *out2 = func_0038CE68(&v, obj + 0xC0) * D_001DE420_sda;
}
