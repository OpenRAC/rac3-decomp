/* functional: high. Checked at L04: same instructions, only constant-load scheduling order differs (27 diff lines, no operand differences). Callback-table return type declared locally because the file's typedef comes later. */
/* localdecomp:start func_L04_003D3520 */
extern u8 D_001A30B0[];
extern void (**func_L01_0043B548(s32, s32))(u8 *);
extern void func_003A4F28(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L04_003D3520(u8 *self, u8 *m) {
    s32 idx = *(s32 *)(m + 0xBC);
    if (idx != -1) {
        u8 *e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(m + 0xBC) = -1;
    if (self[0x20] == 2) {
        vu0_v4 pos __attribute__((aligned(16)));
        *(s32 *)(m + 0x90) = 1;
        if (*(s32 *)(m + 0x70) != 0) {
            if (((s32 (**)(u8 *))func_L01_0043B548(0x19E1, 0x6C))[0x48 / 4](self)) {
                *(s32 *)(m + 0x98) = 0;
            } else {
                *(s32 *)(m + 0x98) = 0xB4;
            }
        } else {
            *(s32 *)(m + 0x98) = 0xB4;
        }
        func_0038CE20(&pos, self + 0xC0, 5.0f);
        vec_add_ab(&pos, &pos, self + 0x10);
        func_L01_003303B8(&pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C3A10(self, 3, 0, 1);
        func_L01_004450F0(self, 5, -1);
    } else {
        *(s32 *)(m + 0x98) = 0;
        func_L01_003303B8(self + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C3A10(self, 0, 0, 1);
        func_L01_004450F0(self, 5, -1);
    }
    if (*(s32 *)(m + 0x70) != 0) {
        func_L01_0043B548(0x19E1, 0x6C)[1](self);
    }
}
/* localdecomp:end func_L04_003D3520 */
