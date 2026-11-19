/* functional: high. Per-entry cost/price: base = D_L01_002C5600[D_001425C0[a0]].f6C * 20.0f, then a multiplier chosen by entry id a0 (0x10, 0x13, 0x15, 0x2F, 0x4F, 0x57) and the tier byte at +1 (switch tables 002BC920/002BC940 read from the retail ELF); returns (int) truncation. Float constants are retail's exact values. Not byte-checked. */
typedef struct {
    u8 pad0;
    u8 tier;
    u8 pad2[0x6A];
    f32 base;
    u8 pad70[0xF0 - 0x70];
} S_002C5600_00485B68;
extern S_002C5600_00485B68 D_L01_002C5600[];
extern u8 D_001425C0[];

s32 func_L01_00485B68(s32 a0) {
    S_002C5600_00485B68 *e = &D_L01_002C5600[D_001425C0[a0]];
    f32 f0 = e->base;
    u32 k = e->tier;
    f32 f2 = 20.0f;
    f32 f1 = f0 * f2;

    if (a0 == 0x15) {
        if (k < 4) {
            f1 = f1 * f2;
        } else if (k < 8) {
            f1 = f1 * 13.0f;
        }
    } else if (a0 < 0x16) {
        if (a0 == 0x10) {
            if (k < 8 && !(k < 4)) {
                f1 = f1 + f1;
            }
        } else if (a0 == 0x13) {
            f1 = f1 + f1;
        }
    } else if (a0 == 0x4F) {
        if (k < 8) {
            switch (k) {
            case 2:
                f1 = f1 + f1;
                break;
            case 3:
                f1 = f1 * 3.0f;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                f1 = f1 * 4.0f;
                break;
            default:
                break;
            }
        }
    } else if (a0 < 0x50) {
        if (a0 == 0x2F) {
            f1 = f1 * 5.0f;
        }
    } else if (a0 == 0x57) {
        if (k < 8) {
            switch (k) {
            case 1:
                f1 = f1 * 1.25f;
                break;
            case 2:
                f1 = f1 * 1.5f;
                break;
            case 3:
                f1 = f1 * 4.0f;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                f1 = f1 * 10.0f;
                break;
            default:
                break;
            }
        }
    }
    return (s32)f1;
}
