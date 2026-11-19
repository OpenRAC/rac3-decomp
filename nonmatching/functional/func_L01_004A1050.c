/* functional: high. 48 diff at default flags: address folding of the +0x74 offset and constant materialisation order; arithmetic order preserved (a+c+k1 + ((b-(a+c))-k2)*pct). */
extern f32 D_L01_001D9580;
extern f32 D_L01_001D9584;
extern f32 D_L01_001D9588;
__asm__(".extern D_L01_001D9580, 4");
__asm__(".extern D_L01_001D9584, 4");
__asm__(".extern D_L01_001D9588, 4");
extern u8 D_00143950[];
extern s32 D_L01_001E0CD0[];
extern void func_L01_00516558(s32, void *, void *);
extern void func_L01_00516470(s32, f32, f32);
void func_L01_004A1050(void) {
    f32 pos[2];
    f32 pct;
    pct = (f32)*(s32 *)(D_00143950 + 0x74 + D_L01_001E0CD0[0] * 16) / 100.0f;
    pos[0] = 0.0f;
    pos[1] = 0.0f;
    func_L01_00516558(0x54003D, &pos[0], &pos[1]);
    pos[0] = (D_L01_001D9580 + D_L01_001D9588 + 0.00700000022f)
             + ((D_L01_001D9584 - (D_L01_001D9580 + D_L01_001D9588)) - 0.0120000001f) * pct;
    func_L01_00516470(0x54003D, pos[0], pos[1]);
}
