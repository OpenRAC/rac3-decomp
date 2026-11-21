/* functional: high. Written from the PAL asm (the NTSC draft's twin differs); with --as ps2as only the jump-table address (unresolved reloc) differs, 3 diff; default assembler differs in float loading only. */
extern void func_L07_003AA228(u8 *);
extern void func_L07_003AA458(u8 *);
extern void func_L07_003AAA50(void *, s32);
extern void func_L07_003AADB0(u8 *, f32);
extern void func_L07_003AAF98(u8 *);
extern void func_L07_003AB200(u8 *);
extern void func_L07_003AB2B0(u8 *);
extern void func_L07_003AB4B8(u8 *);
extern void func_L07_003AB678(u8 *);
extern void func_L07_003AB918(void *);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L07_00331008(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L07_00334408(void *);
extern s32 func_L07_003346D8(void *);
extern void func_L07_00334588(void *);
extern void func_L01_00404808(void (*)(void *), void *);

void func_L07_003A9DB0(u8 *obj) {
    u8 *s;
    f32 d;

    if (obj[0x20] == 0) {
        func_L07_003AA228(obj);
    }
    func_L07_003AA458(obj);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0(obj);
        if (func_0038CB00(s + 0x24E) != 0) {
            func_L07_003AAA50(obj, 3);
        }
        break;
    case 3:
        func_L01_0045A9F0(obj);
        func_L07_003AAA50(obj, 4);
        break;
    case 4:
        func_L01_0045A748(obj, *(u8 **)(s + 0x240) + 0x10);
        if (func_L01_0040E570(*(u8 **)(s + 0x240) + 0x10, obj + 0x10) < 484.0f) {
            s[0x25E] = 1;
            func_L07_003AAA50(obj, 6);
        }
        break;
    case 5:
        func_L01_0045A9F0(obj);
        if (func_L01_00454370(obj, s + 0x70) & 2) {
            if (s[0x25E] != 0) {
                func_L07_003AAA50(obj, 6);
            } else {
                func_L07_003AAA50(obj, 4);
            }
        }
        break;
    case 6:
        func_L01_0045A9F0(obj);
        if (func_L07_00331008(*(u8 **)(s + 0x240), obj) != 0) {
            if (func_L01_0040E570(obj + 0x10, s + 0x130) < 196.0f) {
                func_L07_003AAA50(obj, 8);
            } else {
                func_L07_003AAA50(obj, 7);
            }
        } else {
            func_L07_003AAA50(obj, 0xE);
        }
        break;
    case 7:
        func_L07_003AADB0(obj, 5.0f);
        if (func_L07_00331008(*(u8 **)(s + 0x240), obj) != 0) {
            if (func_L01_0040E570(obj + 0x10, s + 0x130) < 100.0f) {
                func_L07_003AAA50(obj, 8);
            }
        } else {
            func_L07_003AAA50(obj, 6);
        }
        break;
    case 8:
        func_L07_003AADB0(obj, 8.0f);
        if (func_L07_00331008(*(u8 **)(s + 0x240), obj) != 0) {
            d = func_0038CF38(obj + 0x10, s + 0x130);
            if (14.0f < d) {
                func_L07_003AAA50(obj, 7);
            } else if (func_0038CB00(s + 0x530) != 0) {
                if (d < 10.0f) {
                    *(s16 *)(s + 0x24C) = func_L07_00334408(obj);
                    if (func_L07_003346D8(obj) != 0) {
                        func_L07_003AAA50(obj, 9);
                    }
                }
            }
        } else {
            func_L07_00334588(obj);
            func_L07_003AAA50(obj, 6);
        }
        break;
    case 9:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003AAA50(obj, 0xA);
        }
        break;
    case 10:
        func_L01_0045A9F0(obj);
        func_L07_003AAF98(obj);
        func_L07_003AB200(obj);
        func_L07_003AB4B8(obj);
        if (func_0038CB00(s + 0x530) != 0) {
            func_L07_003AAA50(obj, 0xB);
        }
        break;
    case 11:
        func_L01_0045A9F0(obj);
        func_L07_003AB200(obj);
        *(f32 *)(s + 0x538) += 0.12000000476837158f;
        if (*(f32 *)(s + 0x538) > 1.0f) {
            *(f32 *)(s + 0x538) = 1.0f;
        }
        *(f32 *)(s + 0x534) += 0.192f;
        if (*(f32 *)(s + 0x534) > 1.0f) {
            *(f32 *)(s + 0x534) -= 1.0f;
        }
        func_L07_003AB2B0(obj);
        func_L07_003AB678(obj);
        func_L01_00404808(func_L07_003AB918, obj);
        if (func_0038CB00(s + 0x530) != 0) {
            func_L07_003AAA50(obj, 0xC);
        }
        break;
    case 12:
        func_L07_003AADB0(obj, 8.0f);
        if (obj[0x60] & 2) {
            func_L07_00334588(obj);
            if (s[0x532] != 0) {
                func_L07_003AAA50(obj, 0xD);
            } else {
                *(s16 *)(s + 0x530) = 0x32;
                func_L07_003AAA50(obj, 6);
            }
        }
        break;
    case 13:
        func_L07_003AADB0(obj, 8.0f);
        if (obj[0x60] & 2) {
            func_L07_003AAA50(obj, 6);
        }
        break;
    case 14:
        func_L07_003AADB0(obj, 12.0f);
        if (func_L07_00331008(*(u8 **)(s + 0x240), obj) != 0) {
            func_L07_003AAA50(obj, 6);
        }
        break;
    }
}
