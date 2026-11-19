/* functional: high. EXACT at level 01; same code as the matched func_L01_0032BEF0. */
extern void func_L01_0044C638(void *, s32, void *, void *, void *, void *);
extern void func_003C3D30(void *, s32, s32, f32);
extern s32 D_001D545C;
extern s32 D_L01_001EAA18[];

void func_L01_0032F138(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    func_L01_0044C638(a0, *(s32 *)(s + 0x70), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    if (D_001D545C == 7) {
        func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
        if (D_L01_001EAA18[0] == 0) {
            *(s32 *)(s + 0x70) = 0;
        }
    }
}
