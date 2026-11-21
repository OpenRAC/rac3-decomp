/* functional: high. Not byte-matched. 128-bit quad copies written as four floats. Calls match sibling call sites (func_L01_003303B8 effect burst, func_L01_00452310 light flash). */
extern u8 D_L01_001D66B0[];
extern u8 *func_L01_0045B958(u8 *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);

void func_L01_003BC668(u8 *m) {
    f32 v[4] __attribute__((aligned(16)));
    u8 *r;

    v[0] = *(f32 *)(D_L01_001D66B0 + 0);
    v[1] = *(f32 *)(D_L01_001D66B0 + 4);
    v[2] = *(f32 *)(D_L01_001D66B0 + 8);
    v[3] = *(f32 *)(D_L01_001D66B0 + 12);
    r = func_L01_0045B958(m);
    if (r != 0) {
        v[0] = *(f32 *)(r + 0xA0);
        v[1] = *(f32 *)(r + 0xA4);
        v[2] = *(f32 *)(r + 0xA8);
        v[3] = *(f32 *)(r + 0xAC);
    }
    func_L01_003303B8(m + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.5f, 0.0f, 0.0f, 2.0f,
                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                      0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_L01_00452310(m, 0x1FFF, v, 1, 0x14, -1.0f, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_003A52A0(3, 0, m);
}
