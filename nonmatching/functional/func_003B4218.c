/* functional: high. PAL near-miss draft re-verified case by case against the asm and jump table jtbl_0031C710; fixed one behaviour error in the draft (state 22 always increments: retail loads D_001D5BDC there but never tests it). Aliased _003B4218 names collapsed to the real symbols. Block structure differs from retail (232 words, mostly gp vs lui addressing). The declarations at the top are the ones the file has just before the INCLUDE_ASM. */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
typedef struct { u8 pad0[8]; s32 f8; u8 pad0c[4]; s32 f10; } S_142430_003AE8A8;
extern s32 D_001D4CE8;
extern F_003B2F50 D_001D4CEC;
extern s32 D_001D888C;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern u8 D_001D9FA0_003B3BF8;
extern P_003B2F50 *D_001D52FC;
extern s32 func_0039C050(s32, s32);
extern void func_0039C6E0(void);
extern void func_003A9308(void);
extern u8 D_00142430[];
void func_003B4218(void) {
    switch (D_001D4CE8) {
    case 3:
        if (D_001D52FC->f1A4 & 0x40) {
            D_001D4CEC.b0 = 0;
            goto increment;
        }
        break;
    case 8:
        if (D_001D52FC->f1A4 & 0x20) {
            D_001D4CEC.b3 = 1;
        } else if (D_001D52FC->f1A4 & 0x10) {
            if (D_001D5BDD) goto activate;
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (!D_001D5BDC) D_001D888C++;
        }
        break;
    case 15:
        if (D_001D52FC->f1A4 & 0x20) {
            func_0039C050(0, 0);
        } else if (D_001D52FC->f1A4 & 0x10) {
            if (D_001D5BDD) goto activate;
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (!D_001D5BDC) D_001D888C++;
        }
        break;
    case 22:
        if (D_001D52FC->f1A4 & 0x40) {
            D_001D4CEC.b6 = 0;
            D_001D4CEC.b10 = 0;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            goto increment; /* retail loads D_001D5BDC here but never tests it */
        }
        break;
    case 19: case 20: case 24: {
        S_142430_003AE8A8 *state = (S_142430_003AE8A8 *)D_00142430;
        if (state->f8 == 2) {
            s32 n = state->f10;
            if (n == 0) n = 11;
            else if (n == -1) { n = 11; state->f10 = 0; }
            else if (n == -2) n = 7;
            else n = 14;
            D_001D4CE8 = n;
            goto increment;
        } else goto activate;
    }
    case 14:
        if (!D_001D9FA0_003B3BF8) break;
    case 4: case 5: case 7:
        if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 21: {
        u8 flag;
        if (D_001D5BDC) {
            if (!D_001D9FA0_003B3BF8) {
                if (D_001D52FC->f1A4 & 0x40) goto cancel;
                if (D_001D52FC->f1A4 & 0x10) {
                    D_001D4CEC.b1 = 0;
                    D_001D4CEC.b2 = 0;
                    D_001D888C++;
                }
                break;
            }
        }
        flag = D_001D5BDD;
        if (flag) {
            if (D_001D52FC->f1A4 & 0x40) goto activate;
        } else if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    }
    case 26: case 27:
        if (D_001D52FC->f1A4 & 0x40) {
        cancel:
            func_0039C6E0();
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D4CEC.b5 = 1;
        activate:
            func_003A9308();
        } else if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b5 = 1;
            goto increment;
        }
        break;
    case 6:
        if (D_001D5BDC) {
            if (!D_001D9FA0_003B3BF8 && (D_001D52FC->f1A4 & 0x40)) {
                func_0039C6E0();
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                func_003A9308();
            }
            goto test_confirm;
        } else if (!D_001D5BDD) {
            goto test_confirm;
        } else if (D_001D52FC->f1A4 & 0x20) goto activate;
        break;
    test_confirm:
        if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 1: case 11: case 18:
        if (D_001D4CEC.b1 == 0 && D_001D4CEC.b2 == 0) {
        increment:
            D_001D888C++;
        }
        break;
    }
}
