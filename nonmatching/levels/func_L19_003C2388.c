/* func_L19_003C2388: 32 diff in L19_003C0938.c (-mvu0-use-vf0-vf2 @ps2as): the moby-vars init. Store order and the float constant registers of the two long store runs (a greedy single-move search over the statement order went from 41 to 36); the two D_L19_001DE838/83C loads are locals (retail loads each once). */
__asm__(".extern D_L19_001DE838, 4");
__asm__(".extern D_L19_001DE83C, 4");
extern f32 D_L19_001DE838;
extern f32 D_L19_001DE83C;
extern s32 func_00382468(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L19_003C2388(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    f32 a;
    f32 b;

    v[0x58] = 10;
    v[0x5A] = 2;
    *(f32 *)(v + 0x40) = 0.3f;
    v[0x39] = 1;
    v[0x3E] = 1;
    v[0x3F] = 1;
    v[0x60] = 0;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 1;
        *(f32 *)(v + 0x30) = 1.0f;
    }
    a = D_L19_001DE83C;
    b = D_L19_001DE838;
    v[0x170] = 0x10;
    *(f32 *)(v + 0xA4) = a;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 1.55334306f;
    *(f32 *)(v + 0xA0) = 0.17453292f;
    *(f32 *)(v + 0x9C) = 0.00392000005f;
    v[0x1D7] = 1;
    *(f32 *)(v + 0x19C) = 0.150000006f;
    *(f32 *)(v + 0x70) = b;
    *(f32 *)(v + 0x74) = b;
    *(f32 *)(v + 0x190) = b;
    *(f32 *)(v + 0x194) = b;
    if (func_00382468(3) != 0) {
        v[0x176] = 0x11;
        v[0x1D3] = 14;
        v[0x1D2] = 7;
    } else {
        v[0x176] = 0x12;
        v[0x1D3] = 16;
        v[0x1D2] = 7;
    }
    v[0x171] = 16;
    v[0x1CD] = 0x11;
    *(f32 *)(v + 0x1B8) = 0.1f;
    v[0x1CC] = 8;
    v[0x1DB] = 0x16;
    *(f32 *)(v + 0x188) = 0.0100000007f;
    *(f32 *)(v + 0x1BC) = 1.0f;
    *(f32 *)(v + 0x17C) = 0.3f;
    *(f32 *)(v + 0x180) = 0.0250000022f;
    *(f32 *)(v + 0x184) = 0.006f;
    *(f32 *)(v + 0x18C) = 0.000800000038f;
    v[0x1A9] = 1;
    v[0x1DA] = 0;
    v[0x1D8] = 0;
    *(s16 *)(v + 0x414) = 0;
    *(f32 *)(v + 0x1A0) = *(f32 *)(obj + 0x18) - 10.0f;
    *(s16 *)(v + 0x416) = 0;
    *(s32 *)(v + 0x418) = 0;
    *(s32 *)(v + 0x41C) = 0;
    *(s32 *)(v + 0x448) = 0;
    *(s32 *)(v + 0x44C) = 0;
    *(s32 *)(v + 0x438) = 0;
    *(u128_t *)(v + 0x460) = *(u128_t *)(obj + 0x10);
    *(u128_t *)(v + 0x470) = *(u128_t *)(obj + 0x10);
    if (func_00382468(3) == 0)
        *(u16 *)(obj + 0x34) |= 0x8000;
    if (*(s32 *)(v + 0x440) != 0)
        func_L01_004450F0(obj, 2, 2);
    else if (*(s32 *)(v + 0x444) != 0)
        func_L01_004450F0(obj, 1, 1);
    else if (*(s32 *)(v + 0x434) != 0)
        func_L01_004450F0(obj, 7, 4);
    else
        func_L01_004450F0(obj, 6, 4);
}
