/* func_L24_003A75F0: level 24 near miss. 2 differences: retail stores 0x1BC before 0x190/0x1D7/0x1D8, this C (statement order found by hill climbing from 20 down to 2; every 4-statement permutation and single moves tried) swaps the 0x1BC and 0x1D8 stores; needs @ps2as on L24_003A6BA8.c (inline float constants), checked here with --as ps2as */
void func_L24_003A75F0(u8 *a0, u8 *a1) {
    *(u16 *)(a0 + 0x34) |= 0x8000;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.75f;
    *(f32 *)(a1 + 0x98C) = 0.75f;
    *(f32 *)(a1 + 0x190) = 0.5f;
    a1[0x1D7] = 1;
    *(f32 *)(a1 + 0x1BC) = 0.5f;
    *(f32 *)(a1 + 0x30) = 100.0f;
    *(u16 *)(a1 + 0x34) = 100;
    a1[0x170] = 4;
    a1[0x1A8] = 5;
    *(f32 *)(a1 + 0x1B8) = 0.01f;
    *(f32 *)(a1 + 0x194) = 0.5f;
    *(f32 *)(a1 + 0x19C) = 0.15f;
    a1[0x1D9] = 0;
    a1[0x1DB] = 0xFF;
    a1[0x1DA] = 0;
    a1[0x171] = 0xB;
    a1[0x176] = 1;
    *(s32 *)(a1 + 0x980) = 0;
    a1[0x172] = 0xB;
    a1[0x177] = 1;
    *(s32 *)(a1 + 0x984) = 0;
    a1[0x39] = 0;
    a1[0x1D8] = 0;
}
