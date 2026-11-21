/* functional: high. Rewritten from the PAL asm (the NTSC-U draft's constants and field values differ: e.g. s+0x3C0=(x*5+2)/6, 0x1C82-style values, 12.566371f, PAL float table). Same 22 calls in the same multiset, same 95 stores (compared after register normalisation); the hidden/active blocks are laid out in the other order by gcc, same paths. */
typedef int u128_359C78 __attribute__((mode(TI)));
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern u8 *D_L05_001DF7CC;
extern void func_L05_0035AEC8(u8 *);

s32 func_L05_00359C78(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 *c;
    u8 *p;

    *(u8 *)(s + 0x172) = 0x11;
    *(f32 *)(s + 0x188) = 0.0260000005f;
    *(f32 *)(s + 0x18C) = 0.000800000038f;
    *(f32 *)(s + 0x1B8) = 0.200000003f;
    *(u8 *)(s + 0x1A8) = 3;
    *(u8 *)(s + 0x171) = 0x10;
    *(f32 *)(s + 0x194) = 0.9375f;
    *(f32 *)(s + 0x17C) = 0.300000012f;
    *(f32 *)(s + 0x180) = 0.0200000014f;
    *(f32 *)(s + 0x184) = 0.00600000005f;
    *(u8 *)(s + 0x1DB) = 0x1B;
    *(u8 *)(s + 0x1CE) = 6;
    *(u8 *)(s + 0x1CF) = 12;
    *(f32 *)(s + 0x1BC) = 0.5f;
    *(s32 *)(s + 0x1DC) = *(s32 *)(s + 0x404);
    *(f32 *)(s + 0x70) = 0.6875f;
    *(f32 *)(s + 0x74) = 0.3125f;
    *(u8 *)(s + 0x170) = 6;
    *(f32 *)(s + 0x190) = 0.6875f;
    *(f32 *)(s + 0x19C) = 0.150000006f;
    *(u8 *)(s + 0x1CC) = 6;
    *(u8 *)(s + 0x1CD) = 12;
    *(s32 *)(s + 0xAC) = *(s32 *)(s + 0x404);
    *(u8 *)(s + 0x1D7) = 1;
    *(u8 *)(s + 0x1D8) = 0;
    *(u8 *)(s + 0x1D9) = 0;
    *(s16 *)(s + 0x198) = 0;
    *(u8 *)(s + 0x1A9) = 1;
    *(f32 *)(s + 0x78) = 1.25f;
    *(s32 *)(s + 0x3C0) = (*(s32 *)(s + 0x3C0) * 5 + 2) / 6;
    *(f32 *)(s + 0x7C) = 2.1875f;
    *(f32 *)(s + 0x80) = 1.65806282f;
    *(f32 *)(s + 0xA0) = 0.87266463f;
    *(f32 *)(s + 0x9C) = 0.00392000005f;
    func_L01_0045BD78(o, 0.0120000001f, 0.150000006f, 0.0209439527f, 0.174532935f);
    *(u8 *)(s + 0x58) = 20;
    *(u8 *)(s + 0x5A) = 14;
    if (*(s16 *)(s + 0x34) == 0) {
        *(s16 *)(s + 0x34) = 10;
        *(f32 *)(s + 0x30) = 10.0f;
    }
    *(f32 *)(s + 0x40) = 1.60000002f;
    *(u8 *)(s + 0x3E) = 1;
    *(u8 *)(s + 0x39) = 0;
    *(u8 *)(s + 0x3F) = 0;
    c = func_003C24B0(0x1610, 0x80);
    *(u8 **)(s + 0x3EC) = c;
    if (c == 0) {
        func_003C2880(o);
        return 1;
    }
    if (*(s16 *)(s + 0x40E) != 0) {
        *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) & 0xFBFF;
    }
    *(u8 **)(*(u8 **)(s + 0x3EC) + 0xB8) = o;
    *(u128_359C78 *)(*(u8 **)(s + 0x3EC) + 0x10) = *(u128_359C78 *)(o + 0x10);
    *(u128_359C78 *)(*(u8 **)(s + 0x3EC) + 0xF0) = *(u128_359C78 *)(o + 0xF0);
    *(long *)(*(u8 **)(s + 0x3EC) + 0x38) = *(long *)(o + 0x38);
    func_003C7C38(*(u8 **)(s + 0x3EC));
    *(u16 *)(*(u8 **)(s + 0x3EC) + 0x32) = *(u16 *)(o + 0x32);
    *(u8 *)(*(u8 **)(s + 0x3EC) + 0x30) = *(u8 *)(o + 0x30);
    *(u16 *)(*(u8 **)(s + 0x3EC) + 0x34) = *(u16 *)(*(u8 **)(s + 0x3EC) + 0x34) | 0x100;
    *(u128_359C78 *)(*(u8 **)(s + 0x3EC) + 0x10) = *(u128_359C78 *)(o + 0x10);
    *(u128_359C78 *)(*(u8 **)(s + 0x3EC) + 0xF0) = *(u128_359C78 *)(o + 0xF0);
    func_0038D308(*(u8 **)(s + 0x3EC) + 0xC0, *(u8 **)(s + 0x3EC) + 0xF0);
    *(u8 **)(s + 0x240) = *(u8 **)(s + 0x3EC);
    *(s16 *)(*(u8 **)(s + 0x3EC) + 0x7C) = 7;
    *(s16 *)(s + 0x3F6) = 1;
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 1.25f;
    c = *(u8 **)(s + 0x3EC);
    *(f32 *)(c + 0x2C) = *(f32 *)(*(u8 **)(c + 0x24) + 0x24) * 1.25f;
    if (*(s32 *)(s + 0x38C) != -1) {
        p = D_L05_001DF7CC + *(s32 *)(s + 0x38C) * 0x30;
        if (*(s16 *)(p + 0x32) == 1) {
            s32 v = **(s32 **)(p + 0x40);
            *(s32 *)(s + 0x38C) = -1;
            *(s32 *)(s + 0x388) = v;
        }
    }
    func_L05_0035AEC8(o);
    if (*(s16 *)(s + 0x3B8) != 0) {
        *(u128_359C78 *)(s + 0x360) = *(u128_359C78 *)(o + 0x10);
        *(f32 *)(s + 0x3B4) = *(f32 *)(o + 0xF8);
        func_L01_004450F0(o, 7, 4);
        goto active;
    }
    if (*(s32 *)(s + 0x3A4) != -1) {
        func_L01_004450F0(o, 3, 4);
        goto active;
    }
    if (*(s32 *)(s + 0x3A8) != -1) {
        if (*(s32 *)(s + 0x3AC) != 0) {
            func_L01_004450F0(o, 4, 4);
            c = *(u8 **)(s + 0x3EC);
            *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 2;
            c = *(u8 **)(s + 0x3EC);
            *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 4;
        } else {
            func_L01_004450F0(o, 5, 4);
            *(s32 *)(s + 0x39C) = 0;
        }
        goto active;
    }
    if (*(s32 *)(s + 0x3A0) == 0) {
        func_L01_004450F0(o, 1, 0);
        func_L05_0035AA68(o, 0, 0, 0);
        goto after;
    }
    func_L01_004450F0(o, 7, 0);
    func_L05_0035AA68(o, 2, 0, 0);
    goto active;
active:
    *(s32 *)(o + 0x98) = 0;
    *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(o, 1);
    c = *(u8 **)(s + 0x3EC);
    *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 0x41;
    c = *(u8 **)(s + 0x3EC);
    *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) & 0xEFFF;
    *(s32 *)(*(u8 **)(s + 0x3EC) + 0x98) = 0;
    func_L01_004AA7E8(*(u8 **)(s + 0x3EC), 1);
    c = *(u8 **)(s + 0x3EC);
    *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 2;
    c = *(u8 **)(s + 0x3EC);
    *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 4;
after:
    if (*(s32 *)(s + 0x3C8) != 0) {
        *(s32 *)(o + 0x98) = 0;
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(o, 1);
        c = *(u8 **)(s + 0x3EC);
        *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 0x41;
        c = *(u8 **)(s + 0x3EC);
        *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) & 0xEFFF;
        *(s32 *)(*(u8 **)(s + 0x3EC) + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(s + 0x3EC), 1);
        *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) | 6;
        c = *(u8 **)(s + 0x3EC);
        *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 2;
        c = *(u8 **)(s + 0x3EC);
        *(u16 *)(c + 0x34) = *(u16 *)(c + 0x34) | 4;
    }
    if (*(s16 *)(s + 0x3DA) != 0) {
        *(s32 *)(s + 0xA8) = *(s32 *)(s + 0xA8) | 4;
        *(f32 *)(s + 0x7C) = 0.699999988f;
        *(f32 *)(s + 0x78) = 0.699999988f;
        *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) | 0x100;
        *(f32 *)(s + 0x80) = 12.566371f;
        *(s32 *)(s + 0xA8) = *(s32 *)(s + 0xA8) | 1;
    }
    if (*(s32 *)(s + 0x3FC) != 0) {
        *(s32 *)(s + 0x394) = 1;
        *(f32 *)(s + 0x1BC) = 1.0f;
        *(f32 *)(s + 0x1B8) = 0.200000003f;
        func_003C3A10(o, 0x13, 0, 0);
        func_003C3A10(*(u8 **)(s + 0x3EC), 2, 0, 0);
        func_003C3A10(o, 0x13, 0, 1);
        func_003C3A10(*(u8 **)(s + 0x3EC), 2, 0, 1);
        *(s32 *)(s + 0xA8) = *(s32 *)(s + 0xA8) | 0x414;
    }
    return 0;
}
