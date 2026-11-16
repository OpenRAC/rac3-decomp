/* PAL near miss (Codex wave 8): near miss: 176 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003B4068; 241 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 176).
 * Worker's note: Best 176 diff / 254 retail words, attempt07.log; mixed gp/lui accesses and shared branch tails still differ with fixed flags; decoded switch evidence func_003B4218.switch.txt
 */
#include "common.h"
/* localdecomp:start func_003B4218 */
extern s32 D_001D4CE8;
extern s32 D_001D4CE8_003B4218;
__asm__(".extern D_001D4CE8_003B4218, 16");
extern F_003B2F50 D_001D4CEC_003B4218;
__asm__(".extern D_001D4CEC_003B4218, 16");
extern P_003B2F50 *D_001D52FC_003B4218;
__asm__(".extern D_001D52FC_003B4218, 16");
__asm__(".extern D_001D5BDC, 16");
extern u8 D_001D5BDD_003B4218;
__asm__(".extern D_001D5BDD_003B4218, 16");
__asm__(".extern D_001D9FA0_003B3BF8, 16");
extern u8 D_001D9FA0_gp_003B4218;
extern F_003B2F50 D_001D4CEC;
extern s32 D_001D888C;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern u8 D_001D9FA0_003B3BF8;
extern P_003B2F50 *D_001D52FC;
extern S_003ADCB0 D_00142430;
extern F_003B2F50 D_001D4CEC_c15_003B4218;
extern u8 D_001D5BDD_c15_003B4218;
extern u8 D_001D5BDC_c15_003B4218;
__asm__(".extern D_001D5BDC_c15_003B4218, 16");
void func_003B4218(void) {
    extern s32 func_0039C050(s32, s32);
    extern void func_0039C6E0(void);
    extern void func_003A9308(void);
    switch (D_001D4CE8_003B4218) {
    case 3:
        if (D_001D52FC_003B4218->f1A4 & 0x40) {
            D_001D4CEC.b0 = 0;
            goto increment;
        }
        break;
    case 8:
        if (D_001D52FC_003B4218->f1A4 & 0x20) {
            F_003B2F50 f = D_001D4CEC_003B4218;
            f.b3 = 1;
            D_001D4CEC = f;
        } else if (D_001D52FC_003B4218->f1A4 & 0x10) {
            if (D_001D5BDD) goto activate;
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (!D_001D5BDC) D_001D888C++;
        }
        break;
    case 15:
        if (D_001D52FC_003B4218->f1A4 & 0x20) {
            func_0039C050(0, 0);
        } else if (D_001D52FC_003B4218->f1A4 & 0x10) {
            if (D_001D5BDD_c15_003B4218) goto activate;
            D_001D4CEC_c15_003B4218.b5 = 1;
            D_001D4CEC_c15_003B4218.b1 = 0;
            D_001D4CEC_c15_003B4218.b2 = 0;
            if (!D_001D5BDC_c15_003B4218) D_001D888C++;
        }
        break;
    case 22:
        if (D_001D52FC_003B4218->f1A4 & 0x40) {
            D_001D4CEC.b6 = 0;
            D_001D4CEC.b10 = 0;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (!D_001D5BDC) goto increment;
        }
        break;
    case 19: case 20: case 24: {
        S_142430_003AE8A8 *state = (S_142430_003AE8A8 *)&D_00142430;
        if (state->f8 == 2) {
            s32 n = state->f10;
            if (n == 0) n = 11;
            else if (n == -1) { n = 11; state->f10 = 0; }
            else if (n == -2) n = 7;
            else n = 14;
            D_001D4CE8 = n;
            goto increment;
        } else goto activate;
        break;
    }
    case 14:
        if (!D_001D9FA0_003B3BF8) break;
    case 4: case 5: case 7:
        if (D_001D52FC_003B4218->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 21: {
        u8 flag;
        if (D_001D5BDC) {
            if (!D_001D9FA0_gp_003B4218) {
                if (D_001D52FC_003B4218->f1A4 & 0x40) goto cancel;
                if (D_001D52FC_003B4218->f1A4 & 0x10) {
                    D_001D4CEC.b1 = 0;
                    D_001D4CEC.b2 = 0;
                    D_001D888C++;
                }
                break;
            }
            flag = D_001D5BDD;
        } else flag = D_001D5BDD_003B4218;
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
        if (D_001D52FC_003B4218->f1A4 & 0x40) {
        cancel:
            func_0039C6E0();
            D_001D4CEC_003B4218.b1 = 0;
            D_001D4CEC_003B4218.b2 = 0;
            D_001D4CEC_003B4218.b5 = 1;
        activate:
            func_003A9308();
        } else if (D_001D52FC_003B4218->f1A4 & 0x10) {
            F_003B2F50 f = D_001D4CEC;
            f.b5 = 1;
            D_001D4CEC_003B4218 = f;
            goto increment;
        }
        break;
    case 6:
        if (D_001D5BDC) {
            if (!D_001D9FA0_gp_003B4218) {
                if (D_001D52FC->f1A4 & 0x40) {
                    F_003B2F50 f;
                    func_0039C6E0();
                    f = D_001D4CEC_003B4218;
                    f.b1 = 0;
                    f.b2 = 0;
                    D_001D4CEC = f;
                    func_003A9308();
                }
            }
            goto test_confirm;
        } else if (!D_001D5BDD_003B4218) {
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
    case 32: break;
    case 1: case 11: case 18:
        if (D_001D4CEC_003B4218.b1 == 0 && D_001D4CEC_003B4218.b2 == 0) {
        increment:
            D_001D888C++;
        }
        break;
    }
}
/* localdecomp:end func_003B4218 */
