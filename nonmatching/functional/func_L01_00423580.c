/* functional: high. near miss, stack frame 0xB0 vs 0xA0 and some store order; every offset and the flag branches read against asm */
extern s32 D_L01_001DFE10;
extern s128 D_L01_001DFDD0[];
extern u8 D_L01_001D6AF4;
extern u8 D_L01_002E68E0[];
extern void func_003D93B0(void *, s32, s32, long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00388258(void *, void *, long);
__asm__(".extern D_L01_001D6AF4, 1");
void func_L01_00423580(void) {
    s128 m[10] __attribute__((aligned(16)));
    f32 *w = (f32 *)m;
    s32 *o;
    s32 c;
    s32 i;

    o = (s32 *)D_L01_001DFE10;
    func_003D93B0(m, o[2], o[4], 0x80);
    c = ((s32 *)D_L01_001DFE10)[3];
    ((s32 *)m)[0x10] = c;
    ((s32 *)m)[0x13] = c;
    ((s32 *)m)[0x12] = c;
    ((s32 *)m)[0x11] = c;
    if (D_L01_001D6AF4 == 0) {
        ((s32 *)m)[0x14] = 0;
        w[0x1A] = 1.0f;
        w[0x15] = 1.0f;
        ((s32 *)m)[0x16] = 0;
        ((s32 *)m)[0x17] = 0;
        w[0x18] = 1.0f;
        w[0x19] = 1.0f;
        ((s32 *)m)[0x1B] = 0;
    } else {
        ((s32 *)m)[0x14] = 0;
        w[0x1B] = 1.0f;
        ((s32 *)m)[0x15] = 0;
        ((s32 *)m)[0x16] = 0;
        w[0x17] = 1.0f;
        w[0x18] = 1.0f;
        ((s32 *)m)[0x19] = 0;
        w[0x1A] = 1.0f;
    }
    D_L01_001D6AF4 = 0;
    for (i = 0; i < 4; i++) {
        m[i] = D_L01_001DFDD0[i];
        w[i * 4 + 3] = 1.0f;
    }
    func_003D2DA0(m, 0, 0);
    func_00388258(D_L01_002E68E0, m, ((s32 *)D_L01_001DFE10)[2]);
}
