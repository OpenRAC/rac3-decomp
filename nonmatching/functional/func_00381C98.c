/* functional: high. Rewritten from the PAL boot_elf assembly; register allocation and block order differ from retail. func_0038FDF8's sixth argument (t1) is left unset by retail and unused by the callee; it is passed as 0 here. */
typedef struct {
    u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s16 h18; u8 p1A[0x15C - 0x1A];
    s32 f15C; u8 p160[4]; s32 f164; s32 f168;
} S_142430_00381C98;
typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_00381C98;
typedef struct { u8 p0[0x1A4]; s32 f1A4; } S_1D52FC_00381C98;

extern S_142430_00381C98 D_00142430_00381C98[];
extern S_143950_00381C98 D_00143950_00381C98[];
extern S_1D52FC_00381C98 *D_001D52FC_00381C98[];
extern s32 D_001D5694_00381C98;
extern s32 D_001D5690_00381C98;
extern s32 D_001D568C_00381C98;
extern s32 D_001D5784_00381C98;
extern s32 D_001D4D40_00381C98;
extern s32 D_001D4BC0_00381C98[];
extern s32 D_00227400_00381C98[];

extern void func_0038E530(s32);
extern void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern s32 func_003823D0(s32);
extern void func_0038FDF8(s32 box, long color, s32 str, s32 len, unsigned long flags64, s32 a5, f32 scale, f32 scale2);
extern void func_0038EBC8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern s32 func_00392F00(s32 *, s32);
extern s32 func_00393058(s32 *);
extern void func_0013D3C0(s32);
extern void func_003824A8(void);

/* Front-end attract/demo-message overlay (boot_elf), one frame: fades a text box in and out
 * on timer D_001D5694 and steps state D_001D5690 (pad press, demo end, quit to title). */
void func_00381C98(void) {
    s16 box[0x20];
    s32 t;
    s32 a;
    s32 col;
    s32 id;
    f32 sc;
    S_142430_00381C98 *g = &D_00142430_00381C98[0];

    t = D_001D5694_00381C98;
    if (t < 75) {
        a = (t - 12) * 224 / 25;
    } else {
        a = (138 - t) * 224 / 25;
    }
    D_001D5694_00381C98 = t + 1;
    if (a < 0) {
        a = 0;
    }
    if (a > 224) {
        a = 224;
    }
    col = a | ((a << 16) | ((a << 8) | 0x80000000));
    func_0038E530(1);

    switch (D_001D5690_00381C98) {
    case 0:
        D_001D568C_00381C98 = 1;
        if (g->f15C != 2 || g->f164 >= 0) {
            D_001D5690_00381C98 = 1;
        }
        break;

    case 1:
    case 2:
    case 3:
        D_001D568C_00381C98 = 1;
        if (g->f15C == 2 && g->f164 < 0) {
            s32 quit = 0;
            if (g->f8 != 2) {
                D_001D5690_00381C98 = 2;
            } else if (g->f14 == 0 || g->h18 >= -1 || g->fC >= 600) {
                quit = 1;
            } else if (g->h18 != -4) {
                D_001D5690_00381C98 = 3;
            }
            g->f10 = 0;
            if (g->f164 < 0) {
                g->f168 = 0;
                g->f164 = 7;
            }
            if (quit) {
                D_001D5694_00381C98 = 0;
                D_001D5690_00381C98 = 4;
            }
        }
        if (D_001D5694_00381C98 >= 76) {
            if (D_001D52FC_00381C98[0]->f1A4 & 0xFFFF0FFF) {
                g->f10 = 0;
                if (g->f164 < 0) {
                    g->f168 = 0;
                    g->f164 = 7;
                }
                D_001D5694_00381C98 = 0;
                D_001D5690_00381C98 = 4;
            }
        }
        if (D_001D5690_00381C98 == 2) {
            func_003914A0(box, 0, 0x1E0, 0x2C, 0x1D4, 0x100, 0xC8, 0x10, 3);
            sc = 1.0f;
            id = 0x1FDB;
        } else if (D_001D5690_00381C98 == 3) {
            sc = 1.0f;
            func_003914A0(box, 0, 0x1E0, 0x2C, 0x1D4, 0x100, 0xC8, 0x10, 3);
            id = 0x1FD9;
        } else {
            break;
        }
        func_0038FDF8((s32)box, 0x80E0E0E0UL, func_003823D0(id), -1, 0x80000000UL, 0, sc, sc);
        if (D_001D5694_00381C98 >= 76) {
            f32 x = (f32)(D_001D4BC0_00381C98[0] >> 1);
            s32 r = func_003823D0(0x24F);
            func_0038EBC8(x, 315.0f, sc, 0x80E0E0E0UL, r, -1, sc, 1, 0, 0x80000000UL, 0.0f, 0.0f);
        }
        break;

    case 4:
        func_003914A0(box, 0, 0x1E0, 0x2C, 0x1D4, 0x100, 0x168, 0x10, 3);
        func_0038FDF8((s32)box, col, func_003823D0(0x242), -1, 0x80000000UL, 0, 1.0f, 1.0f);
        func_003914A0(box, 0, 0x1E0, 0xC, 0x1F4, 0x100, 0xC8, 0x12, 3);
        func_0038FDF8((s32)box, col, func_003823D0(0x245), -1, 0x80000000UL, 0, 1.25f, 1.25f);
        if (g->h18 == -1 && (D_001D52FC_00381C98[0]->f1A4 & 0xFFFF0FFF)) {
            D_001D5784_00381C98 = 1;
        }
        D_001D568C_00381C98 = 1;
        if (D_001D5694_00381C98 >= 151) {
            D_001D5694_00381C98 = 0;
            D_001D5690_00381C98 = D_001D5784_00381C98 != 0 ? 8 : 6;
        }
        break;

    case 6:
        D_001D568C_00381C98 = 1;
        func_003914A0(box, 0, 0x1E0, 0x20, 0x1E0, 0x100, 0xC8, 0x12, 3);
        func_0038FDF8((s32)box, col, func_003823D0(0x1B75), -1, 0x80000000UL, 0, 1.2f, 1.2f);
        if (g->h18 == -1 && (D_001D52FC_00381C98[0]->f1A4 & 0xFFFF0FFF)) {
            D_001D5694_00381C98 = 0;
            D_001D5690_00381C98 = 8;
            break;
        }
        if (D_001D5694_00381C98 >= 151) {
            if (g->h18 == -1) {
                D_001D4D40_00381C98 = 0;
            } else {
                D_001D4D40_00381C98 = 0x80;
            }
            D_00227400_00381C98[0] = 3;
            if (D_00143950_00381C98[0].bAD != 0) {
                func_00392F00(D_00227400_00381C98, 0x1D);
            } else {
                func_00392F00(D_00227400_00381C98, 0x1F);
            }
            func_00393058(D_00227400_00381C98);
            D_001D5694_00381C98 = 0;
            D_001D5690_00381C98 = 8;
        }
        break;

    case 7:
        D_001D4D40_00381C98 = 0;
        if (D_00143950_00381C98[0].bAD != 0) {
            func_00392F00(D_00227400_00381C98, 0x1D);
        } else {
            func_00392F00(D_00227400_00381C98, 0x1F);
        }
        D_00227400_00381C98[0] = 4;
        func_00393058(D_00227400_00381C98);
        D_001D5694_00381C98 = 0;
        D_001D5690_00381C98 = 8;
        break;

    case 8:
        D_001D568C_00381C98 = 0;
        func_0013D3C0(10);
        if (g->f15C == 2 && g->f164 < 0) {
            g->f168 = 0;
            g->f164 = 0x18;
        }
        break;

    case 9:
        D_001D568C_00381C98 = 1;
        func_003914A0(box, 0, 0x1E0, 0x20, 0x1E0, 0x100, 0xC8, 0x10, 3);
        func_0038FDF8((s32)box, col, func_003823D0(0x1700), -1, 0x80000000UL, 0, 1.0f, 1.0f);
        if (D_001D5694_00381C98 >= 151) {
            func_003824A8();
        }
        break;
    }
}
