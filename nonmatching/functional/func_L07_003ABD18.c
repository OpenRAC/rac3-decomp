/* functional: high. Draft verified case by case against PAL asm (all 12 cases, constants, delay-slot flag clears); retail masks the u16 counter with an extra andi 0xFFFF, which the C does not emit (8 bytes, no behaviour change); 150 diff are the shifted branches. */
void func_L07_003ABD18(u8 *m) {
    extern void func_L07_003AC2D0(u8 *);
    extern void func_L07_003AC500(u8 *);
    extern void func_L01_0045A9F0(u8 *);
    extern s32 func_0038CB00(void *);
    extern void func_L07_003ACA90(void *, s32);
    extern void func_L01_0045A748(u8 *, void *);
    extern f32 func_L01_0040E570(void *, void *);
    extern s32 func_L01_00454370(u8 *, void *);
    extern s32 func_L07_00331008(void *, void *);
    extern void func_L07_003ACD58(u8 *, f32);
    extern s32 func_L07_00334408(u8 *);
    extern s32 func_L07_003346D8(u8 *);
    extern void func_L07_00334588(u8 *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_L01_004395E0(u8 *);
    extern void func_L07_003AD088(void *);
    extern void func_L07_003AD180(void *);
    extern void func_L01_00404808(void (*)(void *), void *);
    extern void func_L07_003ACF40(u8 *);
    extern void func_003C3A10(u8 *, s32, s32, s32);
    extern void func_L01_004450F0(u8 *, s32, s32);
    u8 *p;
    f32 frame, distance;
    if (m[0x20] == 0) func_L07_003AC2D0(m);
    func_L07_003AC500(m);
    p = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0(m);
        if (func_0038CB00(p + 0x24E)) func_L07_003ACA90(m, 3);
        break;
    case 3:
        func_L01_0045A9F0(m);
        { func_L07_003ACA90(m, 4); break; }
    case 4:
        func_L01_0045A748(m, *(u8 **)(p + 0x240) + 0x10);
        if (func_L01_0040E570(*(u8 **)(p + 0x240) + 0x10, m + 0x10) < 484.0f) {
            p[0x25E] = 1;
            { func_L07_003ACA90(m, 6); break; }
        }
        break;
    case 5:
        func_L01_0045A9F0(m);
        if (func_L01_00454370(m, p + 0x70) & 2) {
            if (p[0x25E]) { func_L07_003ACA90(m, 6); break; }
            func_L07_003ACA90(m, 4);
        }
        break;
    case 6:
        func_L01_0045A9F0(m);
        if (func_L07_00331008(*(void **)(p + 0x240), m)) {
            if (func_L01_0040E570(m + 0x10, p + 0x130) < 121.0f) { func_L07_003ACA90(m, 8); break; }
            { func_L07_003ACA90(m, 7); break; }
        } else {
            func_L07_003ACA90(m, 13);
        }
        break;
    case 7:
        func_L07_003ACD58(m, 5.0f);
        if (func_L07_00331008(*(void **)(p + 0x240), m)) {
            if (func_L01_0040E570(m + 0x10, p + 0x130) < 64.0f) {
                func_L07_003ACA90(m, 8);
            }
        } else {
            { func_L07_003ACA90(m, 6); break; }
        }
        break;
    case 8:
        func_L07_003ACD58(m, 1.5f);
        if (func_L07_00331008(*(void **)(p + 0x240), m)) {
            if (func_L01_0040E570(m + 0x10, p + 0x130) > 121.0f) {
                *(s32 *)(p + 0x188) &= ~0x10;
                { func_L07_003ACA90(m, 7); break; }
            } else if (func_0038CB00(p + 0x564)) {
                if (func_L01_0040E570(m + 0x10, p + 0x130) < 6.25f) {
                    *(s16 *)(p + 0x24C) = func_L07_00334408(m);
                    if (func_L07_003346D8(m)) { func_L07_003ACA90(m, 10); break; }
                }
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(m);
            { func_L07_003ACA90(m, 6); break; }
        }
        break;
    case 9:
        func_L07_003ACD58(m, 1.5f);
        if (func_L07_00331008(*(void **)(p + 0x240), m)) {
            distance = func_0038CF38(m + 0x10, p + 0x130);
            if (distance > 11.0f) {
                *(s32 *)(p + 0x188) &= ~0x10;
                func_L07_00334588(m);
                func_L07_003ACA90(m, 7);
            } else if (distance < 2.5f) {
                func_L07_003ACA90(m, 10);
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(m);
            { func_L07_003ACA90(m, 6); break; }
        }
        break;
    case 10:
        frame = func_L01_004395E0(m);
        func_L01_0045A9F0(m);
        if (frame > 10.0f) {
            if (++*(u16 *)(p + 0x564) % 2 == 0) func_L07_003AD088(m);
            func_L01_00404808(func_L07_003AD180, m);
        }
        if (frame > 13.0f && frame < 16.0f) func_L07_003ACF40(m);
        if (m[0x60] & 2) {
            func_L07_00334588(m);
            if (p[0x566]) { func_L07_003ACA90(m, 12); break; }
            *(s16 *)(p + 0x564) = 50;
            func_L07_003ACA90(m, 6);
        }
        break;
    case 11:
        if (++*(u16 *)(p + 0x564) % 2 == 0) func_L07_003AD088(m);
        func_L01_00404808(func_L07_003AD180, m);
        func_L01_0045A9F0(m);
        func_L07_003ACF40(m);
        if (m[0x60] & 2) {
            func_L07_00334588(m);
            if (p[0x566]) {
                if (m[0x43] != 8) func_003C3A10(m, 8, 0, 10);
                func_L07_003ACA90(m, 12);
            } else {
                *(s16 *)(p + 0x564) = 50;
                if (m[0x43] != 3) func_003C3A10(m, 3, 0, 10);
                func_L01_004450F0(m, 6, -1);
            }
        }
        break;
    case 12:
        func_L07_003ACD58(m, 4.0f);
        if (m[0x60] & 2) {
            *(s32 *)(p + 0x188) &= ~0x10;
            { func_L07_003ACA90(m, 6); break; }
        }
        break;
    case 13:
        func_L07_003ACD58(m, 8.0f);
        if (func_L07_00331008(*(void **)(p + 0x240), m)) func_L07_003ACA90(m, 6);
        break;
    }
}
