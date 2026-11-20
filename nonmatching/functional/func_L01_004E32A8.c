/* functional: high. Verified block by block against PAL asm (offsets, constants, call args; two float literals set to the retail bit patterns). Does not compile in-file until the owner's `extern char func_L01_004E32A8[]` in func_L01_004E3268 becomes a function type; compiles clean otherwise. */
extern s32 D_L01_001D6694;
extern u8 D_001A6EA0[];
extern u8 D_001D5470;
/* the owning unit declares func_L01_004E32A8 as a char array, so define it under the same linker symbol */
void func_L01_004E32A8_fn(void) __asm__("func_L01_004E32A8");
void func_L01_004E32A8_fn(void) {
    extern void func_003C5458(void *, s32, f32, f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038AE20(s32, s32, s32, s32);
    extern void func_003A9440(s32, unsigned long);
    extern s32 func_L01_004E9238(s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);
    extern f32 func_003C4138(f32 *, f32, f32);
    u8 *h = (u8 *)&D_001A4BE0;
    S_4DF808 *effects = (S_4DF808 *)&D_001A4BE0;
    s32 i;
    f32 scale;
    if (D_L01_001D6694 == 2 || D_L01_001D6694 == 6) {
        for (i = 0; i < effects->count; i++)
            func_003C5458(&effects->q[i], effects->i[i], effects->a[i], effects->b[i]);
    } else {
        if (*(s16 *)(h + 0x21C)) {
            func_0038AE20(170, 0, 0, (s32)((func_0038D0B0(*(s16 *)(h + 0x21C) * 3.1415927f / 15.0f) * 0.5f + 0.5f) * 80.0f));
            func_003A9440(71, 0x5360B);
        }
        if (h[0x25E4] == 0) {
            if ((func_L01_004E9238(3) == 3 || func_L01_004E9238(3) == 2) && !*(s16 *)(h + 0x2884)) {
                if (*(s16 *)(h + 0x2888)) {
                    scale = 1.0f;
                    if (scale < *(f32 *)(h + 0x22D0)) scale = *(f32 *)(h + 0x22D0);
                    if (scale < *(f32 *)(h + 0x22D4)) scale = *(f32 *)(h + 0x22D4);
                    if (scale < *(f32 *)(h + 0x22D8)) scale = *(f32 *)(h + 0x22D8);
                    func_0038DBD8(0xC0000028, 40, scale);
                }
                func_003C5458(D_001A6EA0, 0xC0000028, 0.057f, 0.08f);
            }
            for (i = 0; i < effects->count; i++)
                func_003C5458(&effects->q[i], effects->i[i], effects->a[i], effects->b[i]);
        } else if (h[0x25E4] == 2) {
            func_003C5458(h + 0x22C0, 0x300000C0, 0.25f, 0.08f);
        } else if (h[0x25E4] == 1) {
            if (*(s32 *)(h + 0x1A54))
                func_L01_004C70A8(h + 0x1A30, h + 0x1A40, 0, 1, 0.5f);
            scale = 0.07f;
            if (*(s16 *)(h + 0x28A8)) scale = 0.101500005f;
            if (D_001D5470) scale *= 1.7f;
            func_003C4138((f32 *)(h + 0x1A2C), scale, 0.00360000017f);
            func_003C5458(h + 0x22C0, *(s32 *)(h + 0x28AC), *(f32 *)(h + 0x1A2C), 0.08f);
        }
    }
}
