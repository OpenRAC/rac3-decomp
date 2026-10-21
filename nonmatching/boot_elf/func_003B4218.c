/* Near miss of func_003B4218 with its file's own flags: tools/check.py reports 241 diff
   (the version it replaces: 253).
*/

/* PAL candidate for func_003B4218 (rac3-uya-decomp func_003B4068).
   The retail PAL binary was assembled with Ps2EeAs: it expands a global
   access into lui/lw unless it already knows the symbol is small, and it
   falls back to $gp for an access that sits in a branch delay slot.  With
   the file's own flags (the default assembler) one symbol gets one form, so
   the globals retail reaches with lui/lw are declared here as unsized
   arrays (never small data); the ones retail reaches through $gp keep
   their plain sized declaration. */

/* localdecomp:start func_003B4218 */
extern s32 D_001D4CE8_003B4218[];
extern u32 D_001D4CEC_003B4218[];
extern u8 D_001D5BDC_003B4218[];
extern u8 D_001D5BDD_003B4218[];
extern P_003B2F50 *D_001D52FC_003B4218[];
extern u8 D_001E9FA0_003B4218[];
extern u8 D_001D9FA0_g_003B4218;
void func_003B4218(void) {
    u32 p;
    switch (D_001D4CE8_003B4218[0]) {
    case 3:
        if (D_001D52FC_003B4218[0]->f1A4 & 0x40) {
            D_001D4CEC.b0 = 0;
            D_001D888C++;
        }
        break;
    case 8:
        p = D_001D52FC_003B4218[0]->f1A4;
        if (p & 0x20) {
            D_001D4CEC.b3 = 1;
        } else if (p & 0x10) {
            if (D_001D5BDD) { func_003A9308(); break; }
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (D_001D5BDC_003B4218[0] == 0) D_001D888C++;
        }
        break;
    case 15:
        p = D_001D52FC_003B4218[0]->f1A4;
        if (p & 0x20) {
            ((void (*)(long))func_0039C050)(0);
        } else if (p & 0x10) {
            if (D_001D5BDD) { func_003A9308(); break; }
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (D_001D5BDC_003B4218[0] == 0) D_001D888C++;
        }
        break;
    case 22:
        if (D_001D52FC_003B4218[0]->f1A4 & 0x40) {
            D_001D4CEC.b6 = 0;
            D_001D4CEC.b10 = 0;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            /* both arms merge; retail keeps the dead D_001D5BDC load */
            if (D_001D5BDC_003B4218[0] == 0) D_001D888C++; else D_001D888C++;
        }
        break;
    case 19: case 20: case 24: {
        S_142430_003AE8A8 *e = (S_142430_003AE8A8 *)&D_00142430;
        if (e->f8 != 2) { func_003A9308(); break; }
        if (e->f10 == 0) D_001D4CE8 = 11;
        else if (e->f10 == -1) { e->f10 = 0; D_001D4CE8 = 11; }
        else if (e->f10 == -2) D_001D4CE8 = 7;
        else D_001D4CE8 = 14;
        D_001D888C++;
        break;
    }
    case 14:
        if (D_001E9FA0_003B4218[0] == 0) break;
        if (D_001D52FC_003B4218[0]->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 4: case 5: case 7:
        if (D_001D52FC_003B4218[0]->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 21:
        if (D_001D5BDC_003B4218[0] != 0 && D_001D9FA0_g_003B4218 == 0) {
            p = D_001D52FC_003B4218[0]->f1A4;
            if (p & 0x40) goto L_26;
            if (p & 0x10) {
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                D_001D888C++;
            }
        } else if (D_001D5BDD) {
            if (D_001D52FC->f1A4 & 0x40) func_003A9308();
        } else if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 26: case 27:
        p = D_001D52FC_003B4218[0]->f1A4;
        if (p & 0x40) {
        L_26:
            func_0039C6E0();
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D4CEC.b5 = 1;
            func_003A9308();
        } else if (p & 0x10) {
            D_001D4CEC.b5 = 1;
            D_001D888C++;
        }
        break;
    case 6:
        if (D_001D5BDC_003B4218[0] != 0) {
            if (D_001D9FA0_g_003B4218 == 0 && (D_001D52FC->f1A4 & 0x40)) {
                func_0039C6E0();
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                func_003A9308();
            }
            if (D_001D52FC->f1A4 & 0x10) {
                D_001D4CEC.b5 = 1;
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                D_001D888C++;
            }
        } else if (D_001D5BDD) {
            if (D_001D52FC->f1A4 & 0x20) func_003A9308();
        } else if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 1: case 11: case 18:
        if (!D_001D4CEC.b1 && !D_001D4CEC.b2) D_001D888C++;
        break;
    case 2: case 9: case 10: case 12: case 13: case 16: case 17: case 23: case 25:
    case 28: case 29: case 30: case 31: case 32:
        break;
    }
}
/* localdecomp:end func_003B4218 */
