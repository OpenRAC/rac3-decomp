/* functional: medium. 33 words differ from retail (VU asm interleaving with EE scheduling); behaviour same: same operand order and memory ops. */
typedef int Q_00323A18 __attribute__((mode(TI)));
typedef union { Q_00323A18 q; f32 f[4]; } V_00323A18;
typedef struct { u8 pad[0xD4]; u8 *texture; } Textures_00323A18;
extern Textures_00323A18 D_L01_00221098[];
extern s32 D_L01_001DCA00;
__asm__(".extern D_L01_001DCA00, 4");
extern s32 D_L01_001DC9E0;
__asm__(".extern D_L01_001DC9E0, 4");
extern u8 D_L01_001D66B0[8];
static __inline__ void add_ba_00323A18(V_00323A18 *d, V_00323A18 *a, V_00323A18 *b) {
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_ab_00323A18(V_00323A18 *d, V_00323A18 *a, V_00323A18 *b) {
    __asm__("lqc2 $vf1, %1
	lqc2 $vf2, %2
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_00323A18(u8 *obj) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, u8 *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
    V_00323A18 pos, delta, step, jitter;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 size, spread;
    s32 i, spin;
    u8 *p;
    if (D_L01_001DCA00) pos.q = *(Q_00323A18 *)(vars + 0x10);
    else pos.q = *(Q_00323A18 *)(vars + 0x20);
    func_0038CE20(&delta, obj + 0xD0, -0.1f);
    add_ba_00323A18(&pos, &pos, &delta);
    func_0038CE20(&step, obj + 0xE0, 0.15f);
    add_ab_00323A18(&pos, &pos, &step);
    func_0038CE20(&step, obj + 0xE0, -0.033333335f);
    spread = 0.15f;
    if (D_L01_001DC9E0) size = 0.2f;
    else { size = 0.175f; spread = 0.1f; }
    for (i = 8; i >= 0; i--) {
        jitter.f[0] = pos.f[0] + func_L01_00443A18(0.0f, spread);
        jitter.f[1] = pos.f[1] + func_L01_00443A18(0.0f, spread);
        jitter.f[2] = pos.f[2] + func_L01_00443A18(0.0f, spread);
        spin = func_00382468(255);
        func_L01_0046FB40(&jitter, D_L01_001D66B0, 3, 0x808080, spin, 127, 127,
                          size * 210000.0f, size * 210000.0f, 0.0f, 1);
        p = func_L01_0046FB40(&pos, D_L01_001D66B0, 3, 0x203080, spin, 16, 16,
                             262500.0f, 262500.0f, 0.0f, 1);
        if (p) p[2] = *D_L01_00221098[0].texture;
        add_ab_00323A18(&pos, &pos, &step);
    }
}
