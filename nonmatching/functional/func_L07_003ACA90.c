/* functional: high. MATCH byte-exact with --as ps2as; default flags differ only in float constant loading. */
void func_L07_003ACA90(void *obj, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L07_003AD058(void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *p = obj;
    u8 *s = *(u8 **)(p + 0x68);
    f32 r;
    switch (state) {
    case 1: break;
    case 2:
        if (p[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
        break;
    case 4:
        if (p[0x43] != 4) func_003C3A10(obj, 4, 0, 4);
        *(f32 *)(s + 0x170) = 0.0026000002399086952f;
        *(f32 *)(s + 0x174) = 0.0026000002399086952f;
        *(f32 *)(s + 0x178) = 0.1300000101327896f;
        *(u16 *)(p + 0x34) |= 0x5000;
        break;
    case 6:
        if (p[0x43] != 3) func_003C3A10(obj, 3, 0, 4);
        break;
    case 7:
        *(f32 *)(s + 0x170) = 0.0026000002399086952f;
        *(f32 *)(s + 0x174) = 0.0026000002399086952f;
        *(f32 *)(s + 0x178) = 0.1300000101327896f;
        if (p[0x43] != 4) func_003C3A10(obj, 4, 0, 4);
        break;
    case 8:
        *(u32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 0.0014000000664964318f;
        *(f32 *)(s + 0x174) = 0.0014000000664964318f;
        *(f32 *)(s + 0x178) = 0.07000000774860382f;
        if (p[0x43] != 3) func_003C3A10(obj, 3, 0, 4);
        break;
    case 10:
        *(s16 *)(s + 0x564) = 0;
        func_L07_003AD058(obj);
        s[0x566] = 0;
        r = func_003824E0(0.0f, 1.0f);
        if (r < 0.5f) {
            s[0x567] = 1;
            if (p[0x43] != 5) func_003C3A10(obj, 5, 0, 2);
        } else if (r < 1.0f) {
            s[0x567] = 2;
            if (p[0x43] != 6) func_003C3A10(obj, 6, 0, 2);
        } else {
            s[0x567] = 3;
            if (p[0x43] != 7) func_003C3A10(obj, 7, 0, 2);
            state = 11;
        }
        break;
    case 12:
        if (p[0x43] != 8) func_003C3A10(obj, 8, 0, 2);
        break;
    case 13:
        *(u32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 0.0014000000664964318f;
        *(f32 *)(s + 0x174) = 0.0014000000664964318f;
        *(f32 *)(s + 0x178) = 0.07000000774860382f;
        if (p[0x43] != 3) func_003C3A10(obj, 3, 0, 4);
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
