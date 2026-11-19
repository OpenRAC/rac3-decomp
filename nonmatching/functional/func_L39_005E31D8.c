/* functional: high. Multiplayer-menu footer: picks the centre/left/right button-hint strings by menu state (D_L39_002403F8, states 3..32) and draws each non-null one at the menu origin (left/right offset +-100, +70 down). States outside 3..32 or with no hint (11, 18, 28) draw nothing; default centre string is D_L39_00243A00. */
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern u8 D_L39_00243A00[];
extern u8 D_L39_00243A08[];
extern u8 D_L39_002B5C70[];
extern u8 D_L39_0024BE70;
extern u8 D_L39_002429AC;
extern u8 D_L39_002429AD;
extern s32 D_L39_00240308;
__asm__(".extern D_L39_00240308, 16");
extern s32 D_L39_0024030C;
__asm__(".extern D_L39_0024030C, 16");
extern u8 *func_L39_0059A970(s32 id);
extern s32 func_120048();
extern void func_L39_00592238(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);

void func_L39_005E31D8(void) {
    u8 *center = D_L39_00243A00;
    u8 *left = 0;
    u8 *right = 0;
    s32 draw = 1;
    s32 id;
    u8 *s18;

    switch (D_L39_002403F8) {
    case 3:
        id = 0x194;
        goto set_center;
    case 4:
    case 5:
    case 6:
        if (D_L39_002429AC ? 1 : 0) {
            if (D_L39_0024BE70 == 0) {
                left = func_L39_0059A970(0x8E2);
                right = func_L39_0059A970(0x8DF);
                id = 0x19C;
                goto set_center;
            }
            if (D_L39_002429AD != 0) {
                left = func_L39_0059A970(0x8E2);
                id = 0x19C;
                goto set_center;
            }
        } else {
            if (D_L39_002429AD != 0) {
                left = func_L39_0059A970(0x8E2);
                id = 0x19C;
                goto set_center;
            }
        }
        id = (D_L39_0024BE70 == 0) ? 0x19E : 0x196;
        goto center_then_left_11E8;
    case 7:
        id = 0x196;
        goto center_then_left_11E8;
    case 8:
        left = func_L39_0059A970(0x8E3);
        right = func_L39_0059A970(0x8DF);
        id = 0x1A3;
        goto set_center;
    case 9:
    case 10:
        id = 0x1AD;
        goto set_center;
    case 11:
    case 18:
    case 28:
        draw = 0;
        break;
    case 12:
    case 13:
    case 31:
    case 32:
        id = 0x1AF;
        goto set_center;
    case 14:
        if (D_L39_0024BE70 != 0) {
            id = 0x196;
            goto center_then_left_11E8;
        }
        /* fall through */
    case 15:
        left = func_L39_0059A970(0x8E3);
        right = func_L39_0059A970(0x8DF);
        id = 0x1A0;
        goto set_center;
    case 16:
    case 17:
        id = 0x1AE;
        goto set_center;
    case 19:
        center = func_L39_0059A970(0x1B0);
        left = func_L39_0059A970(0x8DE);
        break;
    case 20:
    case 24:
        center = func_L39_0059A970(0x1B2);
        left = func_L39_0059A970(0x8DE);
        break;
    case 21:
        if (D_L39_0024BE70 != 0) {
            id = 0x196;
            goto center_then_left_11E8;
        }
        if (D_L39_002429AC != 0) {
            center = D_L39_002B5C70;
            s18 = func_L39_0059A970(0x199);
            func_120048(D_L39_002B5C70, D_L39_00243A08, s18, 1, 1, func_L39_0059A970(0x19A));
            left = func_L39_0059A970(0x8E2);
            right = func_L39_0059A970(0x8DF);
            break;
        }
        id = 0x199;
        goto center_then_left_11E8;
    case 22:
        center = func_L39_0059A970(0x1B1);
        left = func_L39_0059A970(0x8DE);
        break;
    case 23:
    case 30:
        id = 0x1AC;
        goto set_center;
    case 25:
    case 29:
        id = 0x1AB;
        goto set_center;
    case 27:
        left = func_L39_0059A970(0x8E2);
        right = func_L39_0059A970(0x8DF);
        s18 = func_L39_0059A970(0x1A2);
        center = D_L39_002B5C70;
        func_120048(D_L39_002B5C70, D_L39_00243A08, s18, 1, 1, func_L39_0059A970(0x11E8));
        break;
    case 26:
        left = func_L39_0059A970(0x8E2);
        right = func_L39_0059A970(0x8DF);
        id = 0x1A5;
        goto set_center;
    default:
        draw = 0;
        break;
    }
    goto draw_it;
set_center:
    center = func_L39_0059A970(id);
    goto draw_it;
center_then_left_11E8:
    center = func_L39_0059A970(id);
    left = func_L39_0059A970(0x11E8);
draw_it:
    if (draw == 0) {
        return;
    }
    if (center != 0) {
        func_L39_00592238((f32)D_L39_00240308, (f32)D_L39_0024030C, 1.0f, 1.0f,
                          0x8066CCFF, (s32)center, -1, 1, 0, 0x80000000, 0.0f, 0.0f);
    }
    if (left != 0) {
        func_L39_00592238((f32)(D_L39_00240308 - 100), (f32)(D_L39_0024030C + 70), 1.0f, 1.0f,
                          0x8066CCFF, (s32)left, -1, 1, 0, 0x80000000, 0.0f, 0.0f);
    }
    if (right != 0) {
        func_L39_00592238((f32)(D_L39_00240308 + 100), (f32)(D_L39_0024030C + 70), 1.0f, 1.0f,
                          0x8066CCFF, (s32)right, -1, 1, 0, 0x80000000, 0.0f, 0.0f);
    }
}
