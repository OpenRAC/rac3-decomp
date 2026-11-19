/* functional: high. Same reads, writes and call order; only register allocation and loop layout differ. */
extern u8 *D_L01_001E001C;
extern void func_L01_004450F0(s32, s32, s32);

void func_L01_003B2688(u8 *a0, u8 *a1) {
    u8 *base;
    s32 idx;
    u8 *node;
    a0[48] = 255;
    idx = *(s32 *)(a1 + 24);
    base = D_L01_001E001C;
    if (idx != -1) {
        node = base + (idx << 8);
        while (1) {
            if (*(s16 *)(node + 170) != 6627) {
                **(s32 **)(node + 104) = (s32)a0;
                break;
            }
            {
                u8 *st = *(u8 **)(node + 104);
                s32 next = *(s32 *)st;
                *(s32 *)(st + 8) = (s32)a0;
                node = base + (next << 8);
            }
        }
    }
    if (*(s32 *)(a1 + 48) == 0) {
        if (*(f32 *)(a1 + 44) == -8.0f) {
            *(s32 *)(a1 + 44) = 0;
        }
    }
    func_L01_004450F0((s32)a0, 1, -1);
}
