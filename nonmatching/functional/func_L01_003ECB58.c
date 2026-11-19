/* functional: high. Draws a screen-corner vignette: four half-screen quads from the corners with the 0x6E7F7F7F tint (call args mirror retail, including the a0/a1 values it leaves in registers for calls 2-4: a0=w, a1=0 / a0=0, a1=h / a0=w, a1=h), then one centred 10x8 tile panel; first resets the default panel size to 0xEC x 0xF0 when D_001D5520 is set */
extern s32 D_001D5520;
extern s32 D_001DF724_sda;
__asm__(".extern D_001DF724_sda, 4");
extern s32 D_001DF71C_sda;
__asm__(".extern D_001DF71C_sda, 4");
extern s32 D_001DF720_sda;
__asm__(".extern D_001DF720_sda, 4");
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
void func_L01_003ECB58(void) {
    extern u8 D_001CFEC0[];
    s16 *sz = (s16 *)(D_001CFEC0 + 0x150);
    long v;
    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_001DF724_sda = -1;
        D_001DF71C_sda = 0xEC;
        D_001DF720_sda = 0xF0;
    }
    func_003A9440(0x47, 0x513F1);
    func_003A9440(0x42, 0x800000006AUL);
    v = func_00389598(0x42);
    func_0038B4D0(0, 0, (s32)((f32)sz[0] * 0.5f), (s32)((f32)sz[1] * 0.5f), 0, 0, 0xFF, 0xFF, 0x6E7F7F7FL, v);
    func_0038B4D0(sz[0], 0, -(s32)((f32)sz[0] * 0.5f), (s32)((f32)sz[1] * 0.5f), 0, 0, 0xFF, 0xFF, 0x6E7F7F7FL, v);
    func_0038B4D0(0, sz[1], (s32)((f32)sz[0] * 0.5f), -(s32)((f32)sz[1] * 0.5f), 0, 0, 0xFF, 0xFF, 0x6E7F7F7FL, v);
    func_0038B4D0(sz[0], sz[1], -(s32)((f32)sz[0] * 0.5f), -(s32)((f32)sz[1] * 0.5f), 0, 0, 0xFF, 0xFF, 0x6E7F7F7FL, v);
    func_003A9440(0x42, 0x800000006AUL);
    func_003A9440(0x42, 0x8000000054UL);
    v = func_00389598(D_001DF724_sda);
    func_0038B4D0(0, 0, sz[0], sz[1], 10, 8, D_001DF71C_sda, D_001DF720_sda, 0x7F6F6F6FL, v);
}
