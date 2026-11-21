/* functional: high. Rewritten from the asm. Callee prototypes follow the matched callers (ints in a0..t3 then the stack, floats in f12..); the VU0 vadd.xyz (w kept) is three scalar adds, the quad copies are 128-bit copies; not byte-matched. func_L03_003D0190 (which copies the object into a new effect object of class clsB) runs only when clsB is nonzero, as in retail. */
typedef int u128_003D02A0 __attribute__((mode(TI)));
extern u8 D_L03_001D66B0[];
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L03_003D0190(u8 *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(u8 *);
void func_L03_003D02A0(u8 *self, s32 cls, s32 idx, s32 clsB, s32 dust, s32 spark, s32 burst, s32 flip, s32 color, f32 scale, f32 zOfs) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    func_003A52A0(0, 0, self);
    func_L01_00451FE0(self, cls, D_L03_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (clsB != 0) {
        func_L03_003D0190(self, clsB, flip);
    }
    *(u128_003D02A0 *)pos = *(u128_003D02A0 *)(self + 0x10);
    *(u128_003D02A0 *)vel = *(u128_003D02A0 *)(self + 0xC0 + (s16)idx * 16);
    func_0038CF68(vel, vel, *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * scale);
    pos[2] += *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * zOfs;
    pos[0] += vel[0];
    pos[1] += vel[1];
    pos[2] += vel[2];
    if (dust != 0) {
        func_L02_00429840(self, pos, 4.0f, 20, 0, D_L03_001D66B0, 0.20000002f, 0.7f, 1.3f, color, 0, 75);
    }
    if (spark != 0) {
        func_L02_003E2E38(self, pos, 1.0f, D_L03_001D66B0, 15, 0, 1, 0.050000004f, 2.5f, 5.0f, 1.0f);
    }
    if (burst != 0) {
        func_L01_003303B8(pos, 0, 0, 0, 0, 2, 5, 0, 1.0f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    }
    func_L01_00451E78(self, 1, 0.0f);
    func_003C2880(self);
}
