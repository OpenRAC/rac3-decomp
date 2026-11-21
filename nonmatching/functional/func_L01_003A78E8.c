/* functional: high. Bytes differ only in VU0 register allocation/scheduling */
typedef int Q_003A78E8 __attribute__((mode(TI)));
typedef union { Q_003A78E8 q; f32 f[4]; } V_003A78E8;
__asm__(".extern D_L01_001DE360, 4");
extern s32 D_L01_001DE360;
__asm__(".extern D_L01_001DE340, 4");
extern s32 D_L01_001DE340;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L01_00221098[];
void func_L01_003A78E8(u8 *obj) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    V_003A78E8 pos, offset, step, point;
    f32 spread, scale;
    s32 i, r;
    u8 *p;
    u8 *v = *(u8 **)(obj + 0x68);
    if (D_L01_001DE360) pos.q = *(Q_003A78E8 *)(v + 0x10);
    else pos.q = *(Q_003A78E8 *)(v + 0x20);
    func_0038CE20(&offset, obj + 0xD0, -0.1f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(pos), "m"(offset) : "vf1", "vf2");
    func_0038CE20(&step, obj + 0xE0, 0.15f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(pos), "m"(step) : "vf1", "vf2");
    func_0038CE20(&step, obj + 0xE0, -0.033333335f);
    if (D_L01_001DE340) { spread = 0.15f; scale = 0.2f; }
    else { scale = 0.175f; spread = 0.1f; }
    for (i = 8; i >= 0; i--) {
        point.f[0] = pos.f[0] + func_L01_00443A18(0.0f, spread);
        point.f[1] = pos.f[1] + func_L01_00443A18(0.0f, spread);
        point.f[2] = pos.f[2] + func_L01_00443A18(0.0f, spread);
        r = func_00382468(255);
        func_L01_0046FB40(&point, D_L01_001D66B0, 3, 0x808080, r, 127, 127, scale * 210000.0f, scale * 210000.0f, 0.0f, 1);
        p = func_L01_0046FB40(&pos, D_L01_001D66B0, 3, 0x203080, r, 16, 16, 262500.0f, 262500.0f, 0.0f, 1);
        if (p) p[2] = **(u8 **)(D_L01_00221098 + 0xD4);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(pos), "m"(step) : "vf1", "vf2");
    }
}
