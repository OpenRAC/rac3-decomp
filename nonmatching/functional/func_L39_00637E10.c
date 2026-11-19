/* functional: high. Unnamed struct fields accessed by raw offsets as the neighbours do. */
extern void func_L39_00633308(void *, s32, f32, f32, f32);

typedef int u128_t __attribute__((mode(TI)));

void func_L39_00637E10(void *p) {
    u8 *o = p;
    f32 a;
    f32 b;
    f32 c;
    u128_t q;

    if (o[0x1A14] != 0 && *(s16 *)(*(u8 **)(*(u8 **)(o + 0x2530) + 0x50) + 0x86) == 0x21) {
        return;
    }
    b = *(f32 *)(o + 0x3EC);
    a = *(f32 *)(o + 0x23B8);
    q = *(u128_t *)(o + 0x23C0);
    *(f32 *)(o + 0xFD4) = b;
    *(f32 *)(o + 0xFD0) = a;
    *(u128_t *)(o + 0xFC0) = q;
    func_L39_00633308(o, 0, 0.1296f, 0.36f, 0.45378562808f);
    c = *(f32 *)(o + 0xFD8);
    b = *(f32 *)(o + 0xFD4);
    *(f32 *)(o + 0x41C) = c;
    *(f32 *)(o + 0x3EC) = b;
    if (c == 0.0f) {
        *(s32 *)(o + 0x3FC) = *(s32 *)(o + 0x3FC) + 1;
    } else {
        *(s32 *)(o + 0x3FC) = 0;
    }
}
