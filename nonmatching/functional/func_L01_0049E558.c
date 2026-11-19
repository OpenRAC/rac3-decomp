/* functional: high. Matches retail except the first float constant is loaded from sdata instead of lui/ori; 3EF4EC20 = 0.478363991 */
extern s32 D_001D94CC_sda;
__asm__(".extern D_001D94CC_sda, 4");
extern s32 D_001D94D0_sda;
__asm__(".extern D_001D94D0_sda, 4");
extern s32 D_001D94D4_sda;
__asm__(".extern D_001D94D4_sda, 4");
extern void func_L01_00516470(s32, f32, f32);

void func_L01_0049E558(void) {
    func_L01_00516470(D_001D94CC_sda, 0.5f, 0.478363991f);
    func_L01_00516470(D_001D94D0_sda, -0.5f, 0.478363991f);
    func_L01_00516470(D_001D94D4_sda, 1.5f, 0.478363991f);
}
