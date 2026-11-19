/* functional: high. Multiplayer-menu input handler: per menu state (D_L39_002403F8, 1..32) reads the pad button word and updates the menu flags (D_L39_002403FC), the step counter (D_L39_002433EC) or the state (state 19/20/24), or calls func_L39_005A61D0/func_L39_005FBDA0/func_L39_005BF840/func_L39_005A5D48. Pad bits are named by value only (0x10, 0x20, 0x40). */
typedef struct { u8 pad[0x1A4]; s32 buttons; } PadBtn_005E3618;
typedef struct { u8 p0[8]; s32 w8; u8 pC[4]; s32 w10; } State_005E3618;
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern s32 D_L39_002433EC;
extern PadBtn_005E3618 *D_L39_00241164;
extern u8 D_L39_0024BE70;
extern u8 D_L39_002429AC;
extern u8 D_L39_002429AD;
extern State_005E3618 D_001A43E0;
extern void func_L39_005A61D0(void);
extern void func_L39_005FBDA0(void);
extern void func_L39_005BF840(s32, s32);
extern s32 func_L39_005A5D48(s32, s32);

void func_L39_005E3618(void) {
    s32 t;
    s32 x;
    s32 st = D_L39_002403F8 - 1;

    if ((u32)st >= 0x20) {
        return;
    }
    switch (st + 1) {
    case 1:
    case 11:
    case 18:
        if ((D_L39_002403FC & 6) == 0) {
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    case 3:
        if (D_L39_00241164->buttons & 0x40) {
            D_L39_002403FC = D_L39_002403FC & ~1;
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    case 8:
        t = D_L39_00241164->buttons;
        if (t & 0x20) {
            D_L39_002403FC = D_L39_002403FC | 8;
            return;
        }
        if (t & 0x10) {
            if (D_L39_002429AD != 0) {
                func_L39_005FBDA0();
                return;
            }
            D_L39_002403FC = (D_L39_002403FC | 0x20) & ~6;
            if (D_L39_002429AC != 0) {
                return;
            }
            func_L39_005BF840(6, 0);
        }
        return;
    case 15:
        t = D_L39_00241164->buttons;
        if (t & 0x20) {
            func_L39_005A5D48(0, 0);
            return;
        }
        if (t & 0x10) {
            if (D_L39_002429AD != 0) {
                func_L39_005FBDA0();
                return;
            }
            D_L39_002403FC = (D_L39_002403FC | 0x20) & ~6;
            if (D_L39_002429AC != 0) {
                return;
            }
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    case 22:
        if (D_L39_00241164->buttons & 0x40) {
            D_L39_002403FC = D_L39_002403FC & ~0x40 & ~0x400 & ~2 & ~4;
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    case 19:
    case 20:
    case 24:
        if (D_001A43E0.w8 != 2) {
            func_L39_005FBDA0();
            return;
        }
        t = D_001A43E0.w10;
        if (t == 0) {
            x = 0xB;
        } else if (t == -1) {
            x = 0xB;
            D_001A43E0.w10 = 0;
        } else if (t == -2) {
            x = 7;
        } else {
            x = 0xE;
        }
        D_L39_002403F8 = x;
        D_L39_002433EC = D_L39_002433EC + 1;
        return;
    case 14:
        if (D_L39_0024BE70 == 0) {
            return;
        }
        /* fall through */
    case 4:
    case 5:
    case 7:
        if (D_L39_00241164->buttons & 0x40) {
            D_L39_002403FC = D_L39_002403FC & ~6;
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    case 21:
        if (D_L39_002429AC != 0 && D_L39_0024BE70 == 0) {
            if (D_L39_00241164->buttons & 0x40) {
                func_L39_005A61D0();
                D_L39_002403FC = (D_L39_002403FC & ~6) | 0x20;
                func_L39_005FBDA0();
            }
            return;
        }
        if (D_L39_002429AD != 0) {
            if (D_L39_00241164->buttons & 0x40) {
                func_L39_005FBDA0();
            }
            return;
        }
        if (D_L39_00241164->buttons & 0x40) {
            D_L39_002403FC = D_L39_002403FC & ~6;
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    case 26:
    case 27:
        t = D_L39_00241164->buttons;
        if (t & 0x40) {
            func_L39_005A61D0();
            D_L39_002403FC = (D_L39_002403FC & ~6) | 0x20;
            func_L39_005FBDA0();
            return;
        }
        if (t & 0x10) {
            D_L39_002403FC = D_L39_002403FC | 0x20;
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    case 6:
        if (D_L39_002429AC != 0) {
            if (D_L39_0024BE70 == 0) {
                if (D_L39_00241164->buttons & 0x40) {
                    func_L39_005A61D0();
                    D_L39_002403FC = D_L39_002403FC & ~6;
                    func_L39_005FBDA0();
                }
                t = D_L39_00241164->buttons & 0x10;
            } else {
                t = D_L39_00241164->buttons & 0x40;
            }
        } else if (D_L39_002429AD != 0) {
            if (D_L39_00241164->buttons & 0x20) {
                func_L39_005FBDA0();
            }
            return;
        } else {
            t = D_L39_00241164->buttons & 0x40;
        }
        if (t != 0) {
            D_L39_002403FC = (D_L39_002403FC | 0x20) & ~6;
            D_L39_002433EC = D_L39_002433EC + 1;
        }
        return;
    default:
        return;
    }
}
