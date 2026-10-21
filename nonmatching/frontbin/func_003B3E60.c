/* US draft of func_003B3E60 (rac3-uya-decomp func_003AE8A8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B3E60 */
__asm__(".extern D_001D888C, 4");
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
typedef struct { u8 pad0[8]; s32 f8; u8 pad0c[4]; s32 f10; } S_142430_003AE8A8;
extern s32 D_001D4CE8;
extern F_003B2F50 D_001D4CEC;
extern s32 D_001D888C;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern u8 D_001D9FA0_003AE438;
extern P_003B2F50 *D_001D52FC;
extern S_003ADCB0 D_00142430;
extern s32 func_0039BC70(s32, s32);
extern void func_0039C300(void);
extern void func_003A8F50(void);
void func_003B3E60(void) {
    u32 p;
    switch (D_001D4CE8) {
    case 3:
        if (D_001D52FC->f1A4 & 0x40) {
            D_001D4CEC.b0 = 0;
            D_001D888C++;
        }
        break;
    case 8:
        p = D_001D52FC->f1A4;
        if (p & 0x20) {
            D_001D4CEC.b3 = 1;
        } else if (p & 0x10) {
            if (D_001D5BDD) { func_003A8F50(); break; }
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (D_001D5BDC == 0) D_001D888C++;
        }
        break;
    case 15:
        p = D_001D52FC->f1A4;
        if (p & 0x20) {
            func_0039BC70(0, 0);
        } else if (p & 0x10) {
            if (D_001D5BDD) { func_003A8F50(); break; }
            D_001D4CEC.b5 = 1;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (D_001D5BDC == 0) D_001D888C++;
        }
        break;
    case 22:
        if (D_001D52FC->f1A4 & 0x40) {
            D_001D4CEC.b6 = 0;
            D_001D4CEC.b10 = 0;
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            /* both arms merge; retail keeps the dead D_001D5BDC load */
            if (D_001D5BDC == 0) D_001D888C++; else D_001D888C++;
        }
        break;
    case 19: case 20: case 24: {
        S_142430_003AE8A8 *e = (S_142430_003AE8A8 *)&D_00142430;
        if (e->f8 != 2) { func_003A8F50(); break; }
        if (e->f10 == 0) D_001D4CE8 = 11;
        else if (e->f10 == -1) { e->f10 = 0; D_001D4CE8 = 11; }
        else if (e->f10 == -2) D_001D4CE8 = 7;
        else D_001D4CE8 = 14;
        D_001D888C++;
        break;
    }
    case 14:
        if (D_001D9FA0_003AE438 == 0) break;
    case 4: case 5: case 7:
        if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 21:
        if (D_001D5BDC != 0 && D_001D9FA0_003AE438 == 0) {
            p = D_001D52FC->f1A4;
            if (p & 0x40) goto L_26;
            if (p & 0x10) {
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                D_001D888C++;
            }
        } else if (D_001D5BDD) {
            if (D_001D52FC->f1A4 & 0x40) func_003A8F50();
        } else if (D_001D52FC->f1A4 & 0x10) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D888C++;
        }
        break;
    case 26: case 27:
        p = D_001D52FC->f1A4;
        if (p & 0x40) {
        L_26:
            func_0039C300();
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D4CEC.b5 = 1;
            func_003A8F50();
        } else if (p & 0x10) {
            D_001D4CEC.b5 = 1;
            D_001D888C++;
        }
        break;
    case 6:
        if (D_001D5BDC != 0) {
            if (D_001D9FA0_003AE438 == 0 && (D_001D52FC->f1A4 & 0x40)) {
                func_0039C300();
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                func_003A8F50();
            }
            if (D_001D52FC->f1A4 & 0x10) {
                D_001D4CEC.b5 = 1;
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                D_001D888C++;
            }
        } else if (D_001D5BDD) {
            if (D_001D52FC->f1A4 & 0x20) func_003A8F50();
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
/* localdecomp:end func_003B3E60 */
