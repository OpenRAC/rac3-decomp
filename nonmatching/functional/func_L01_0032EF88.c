/* functional: high. EXACT at level 01. Uses the s128 typedef the file prelude already has. */
extern f32 D_001DCEB0_sda;
__asm__(".extern D_001DCEB0_sda, 4");
extern void func_L01_004C7D40(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L01_0032EF88(u8 *self) {
    f32 old[4] __attribute__((aligned(16)));
    u8 *s;

    *(s128 *)old = *(s128 *)(self + 0x10);
    s = *(u8 **)(self + 0x68);
    vec_add_ab(self + 0x10, self + 0x10, s);
    func_L01_004C7D40(self + 0x10, s, D_001DCEB0_sda * 0.00040000002f * 0.1f);
    if (func_003D3CB0(old, self + 0x10, 0x10, self, 0) != 0) {
        self[0x20] = 8;
    }
}
