/* functional: high. Written from the PAL asm (NTSC draft is a different version); under ps2as the instruction multiset equals retail apart from the unresolved jump-table address; 18 diff (block order/scheduling). */
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L07_003AAF98(void *);

void func_L07_003AAA50(void *arg0, s32 state) {
    u8 *obj = arg0;
    u8 *s = *(u8 **)(obj + 0x68);

    switch (state) {
    case 1:
        break;
    case 2:
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 0);
        }
        break;
    case 4:
        if (obj[0x43] != 4) {
            func_003C3A10(obj, 4, 0, 4);
        }
        *(f32 *)(s + 0x174) = 0.0026000002399086952f;
        *(f32 *)(s + 0x178) = 0.1300000101327896f;
        *(f32 *)(s + 0x170) = 0.0026000002399086952f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        break;
    case 6:
        *(s32 *)(s + 0x188) &= ~0x10;
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 4);
        }
        break;
    case 7:
        *(s32 *)(s + 0x188) &= ~0x10;
        *(f32 *)(s + 0x178) = 0.1300000101327896f;
        *(f32 *)(s + 0x174) = 0.0026000002399086952f;
        *(f32 *)(s + 0x170) = 0.0026000002399086952f;
        if (obj[0x43] != 4) {
            func_003C3A10(obj, 4, 0, 4);
        }
        break;
    case 8:
        *(s32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x178) = 0.07000000774860382f;
        *(f32 *)(s + 0x174) = 0.0014000000664964318f;
        *(f32 *)(s + 0x170) = 0.0014000000664964318f;
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 4);
        }
        break;
    case 9:
        s[0x532] = 0;
        *(s32 *)(s + 0x538) = 0;
        *(s32 *)(s + 0x534) = 0;
        if (func_00382468(2) != 0) {
            s[0x533] = 0;
            if (obj[0x43] != 5) {
                func_003C3A10(obj, 5, 0, 2);
            }
        } else {
            s[0x533] = 1;
            if (obj[0x43] != 9) {
                func_003C3A10(obj, 9, 0, 2);
            }
        }
        break;
    case 10:
        func_L01_004AAC98(2, 0, obj, 0x19BD);
        *(s16 *)(s + 0x530) = 0x25;
        if (s[0x533] == 0) {
            if (obj[0x43] != 6) {
                func_003C3A10(obj, 6, 0, 2);
            }
        } else {
            if (obj[0x43] != 0xA) {
                func_003C3A10(obj, 0xA, 0, 2);
            }
        }
        break;
    case 11:
        func_L07_003AAF98(obj);
        *(s16 *)(s + 0x530) = 0x25;
        if (s[0x533] == 0) {
            if (obj[0x43] != 7) {
                func_003C3A10(obj, 7, 0, 2);
            }
        } else {
            if (obj[0x43] != 0xB) {
                func_003C3A10(obj, 0xB, 0, 2);
            }
        }
        break;
    case 12:
        *(s32 *)(s + 0x188) |= 0x10;
        if (s[0x533] == 0) {
            if (obj[0x43] != 8) {
                func_003C3A10(obj, 8, 0, 2);
            }
        } else {
            if (obj[0x43] != 0xC) {
                func_003C3A10(obj, 0xC, 0, 2);
            }
        }
        break;
    case 13:
        if (obj[0x43] != 0xE) {
            func_003C3A10(obj, 0xE, 0, 2);
        }
        break;
    case 14:
        *(s32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x178) = 0.07000000774860382f;
        *(f32 *)(s + 0x174) = 0.0014000000664964318f;
        *(f32 *)(s + 0x170) = 0.0014000000664964318f;
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 4);
        }
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
