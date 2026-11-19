/* functional: high. Checked at L04: same operations, different branch layout and register choice (bytes only). */
/* localdecomp:start func_L04_003D3A30 */
extern void func_003C3A10(void *, s32, s32, s32);
void func_L04_003D3A30(u8 *a, u8 *b) {
    u8 *bv = *(u8 **)(b + 0x68);
    u8 *av = *(u8 **)(a + 0x68);
    s32 kind;
    av[0x80] = bv[0x54];
    kind = *(s32 *)(bv + 0x1C);
    if (kind == 2) {
        av[0x82] = 1;
        *(s32 *)(av + 0xD0) = -1;
        *(s32 *)(av + 0xD4) = 0;
        av[0x81] = 1;
    } else if (kind == 3) {
        av[0x82] = 2;
        *(s32 *)(av + 0xD4) = 0;
        *(s32 *)(av + 0xD0) = *(s32 *)(bv + 0x70);
    } else {
        *(s32 *)(av + 0xD0) = -1;
        av[0x81] = bv[0x1C];
        *(s32 *)(av + 0xD4) = 0;
        av[0x82] = 0;
    }
    if (a[0x43]) {
        func_003C3A10(a, 0, 0, 0);
    }
}
/* localdecomp:end func_L04_003D3A30 */
