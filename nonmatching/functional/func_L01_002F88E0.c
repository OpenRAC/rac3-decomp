/* functional: high. Near-miss draft, 3 words differ. func_L01_002F94F8 is declared with void * because S_002F94F8 is typedef'd later in the file; retail passes the same pointer. D_00142660 declared s32[] (player stats base). */
/* localdecomp:start func_L01_002F88E0 */
extern s32 D_00142660[];
extern s32 D_L01_001D6714 __attribute__((section(".data")));
extern u8 *D_001E0020_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D545C_sda;
extern s32 D_001A9280[];
void func_L01_002F88E0(u8 *m) {
    extern s32 func_L01_002F94F8(void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_003E54E0(s32);
    extern void func_L01_00443B88(f32 *, f32, f32);
    extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, s32, f32, f32, f32);
    f32 direction[4] __attribute__((aligned(16)));
    f32 position[4] __attribute__((aligned(16)));
    Src_002F7888 *row = D_L01_002BE708;
    u8 *vars = *(u8 **)(m + 0x68);
    s32 n;
    s32 increment;
    f32 scale;
    row = (Src_002F7888 *)((s32)row + func_L01_002F94F8((void *)m) * 28);
    increment = *(s32 *)((u8 *)row + 24);
    D_00142660[0] += increment;
    if ((vars[0x6D] & 2) || (D_L01_001D6714 && m < D_001E0020_sda)) {
        D_001A9280[D_001D545C_sda] += increment;
    }
    func_003E54E0(150);
    func_L01_00443B88(direction, 0.014f, 0.020000001f);
    func_0038CE20(position, direction, 10.0f);
    vec_add_ba(position, position, m + 0x10);
    n = func_00382468(2);
    if (n == 0) n--;
    scale = func_003824E0(0.4f, 0.5f);
    func_L01_0046B458(position, 21, 0x7F207F7F, 0, n, direction, 0, scale * 0.2f, scale, 0.0f);
    func_L01_0046B458(position, 21, 0x7F7F7F7F, 1, -n, direction, 0, scale * 0.14f, scale * 0.7f, 0.0f);
}
/* localdecomp:end func_L01_002F88E0 */
