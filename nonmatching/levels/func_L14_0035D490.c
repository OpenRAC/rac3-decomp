/* func_L14_0035D490: near miss, 8 diff: needs @ps2as on L14_0035D490.c; left: (1) sw $v0,8($sp) comes before mov.s $f17,$f16 in ours, after it in retail; (2) the D_L14_001D67B8 counter: retail loads it into $v1 and compares into $v0, ours the reverse (n local, ++, +=, > 99 wordings tried; the same pattern matches in func_L14_00354C28's counter shape only by luck of allocation)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
void func_L14_0035D490(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L01_00451FE0(a0, 0x7FFF, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_003A52A0(0, 0, a0);
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
