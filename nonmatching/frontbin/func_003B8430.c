/* US draft of func_003B8430 (rac3-uya-decomp func_003B2F50, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B8430 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
__asm__(".extern D_001D8A40, 4");
__asm__(".extern D_001D8A18, 4");
extern F_003B2F50 D_001D4CEC;
extern u8 D_001D9FA0_003B8430;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC_003B8430;
extern s32 D_001D4CE8_003B8430;
extern P_003B2F50 *D_001D52FC_003B8430;
extern u8 D_001D5BDD;
extern void func_0039BFD8(void);
extern void func_0039BFF0(void);
extern void func_0039BE90(void);
extern void func_0039C220(s32);
extern void func_003C0CC0(void);
extern u8 func_0039BEA8(void);
extern void func_0039C060(void);
extern s32 func_0039BC70(s32, s32);
extern void func_003A8F50(void);
extern void func_003B6510();
extern s32 D_00142438[];

void func_003B8430(void) {
    s32 t1, t2, t3, t4, t5, t6;

    if (D_001D52FC_003B8430->f1A4 & 0x50) {
        func_003A5348(4, 0, 0);
    }
    switch (D_001D4CE8_003B8430) {
    case 3:
        if (D_001D52FC_003B8430->f1A4 & 0x40) {
            D_001D4CEC.b0 = 0;
            D_001D8A40 = 5;
        }
        break;
    case 8:
        t1 = D_001D52FC_003B8430->f1A4;
        if (t1 & 0x20) {
            D_001D4CEC.b3 = 1;
            break;
        }
        if (t1 & 0x10) {
            if (D_001D5BDD != 0) {
                func_003B8A38(-1);
                func_003A8F50();
                return;
            }
            func_0039BFD8();
            func_0039BFF0();
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (D_001D5BDC_003B8430 != 0) {
                D_001D8A40 = 2;
            } else {
                D_001D8A40 = 6;
            }
        }
        break;
    case 15:
        t2 = D_001D52FC_003B8430->f1A4;
        if (t2 & 0x20) {
            func_0039BE90();
            return;
        }
        if (!(t2 & 0x10)) break;
        if (D_001D5BDD != 0) {
            if (D_00142438[0] != 2) {
                func_003B8A38(-1);
                func_003A8F50();
                return;
            }
            D_001D8A40 = 6;
            break;
        }
        if (D_001D5BDC_003B8430 != 0) {
            D_001D8A40 = 5;
        } else {
            D_001D8A40 = 6;
            func_0039BFF0();
        }
        func_0039BFD8();
        return;
    case 33:
        t3 = D_001D52FC_003B8430->f1A4;
        if (t3 & 0x20) {
            func_0039BE90();
            return;
        }
        if (!(t3 & 0x10)) return;
        func_0039BFD8();
        func_0039BFF0();
        if (D_001D5BDD != 0) {
            func_0039C220(D_001D8AA8);
            func_003C0CC0();
            func_003B6888();
        }
        return;
    case 22:
        if (D_001D52FC_003B8430->f1A4 & 0x40) {
            func_0039BFD8();
            func_0039BFF0();
            func_0039BEA8();
            D_001D4CEC.b6 = 0;
            D_001D4CEC.b10 = 0;
            if (D_001D5BDC_003B8430 != 0) {
                D_001D8A40 = D_001D8A40 + 1;
            }
        }
        break;
    case 19:
    case 20:
    case 24:
        if (!(D_001D52FC_003B8430->f1A4 & 0x40)) break;
        if (D_001D5BDD != 0) return;
        if (D_001D5BDC_003B8430 != 0) {
            D_001D8A40 = 6;
            func_0039BFF0();
            func_0039C060();
            return;
        }
        D_001D4CEC.b6 = 0;
        D_001D4CEC.b10 = 0;
        D_001D4CEC.b1 = 0;
        D_001D4CEC.b2 = 0;
        D_001D8A40 = 5;
        break;
    case 1:
        if (*(s32 *)&D_001D4CEC & 6) return;
        if (D_001D5BDD != 0) {
            D_001D8A40 = 6;
        } else {
            D_001D8A40 = 4;
        }
        break;
    case 18:
        if (*(s32 *)&D_001D4CEC & 6) return;
        if (D_001D5BDD != 0) {
            D_001D8A40 = 4;
        } else {
            D_001D8A40 = 4;
        }
        break;
    case 14:
        if (D_001D8A18 == 2) {
            func_0039BC70(0, 0);
        } else if (D_001D9FA0_003B8430 == 0) {
            D_001D8A40 = 4;
            break;
        }
    case 4:
    case 5:
    case 7:
        if (D_001D8A18 == 2 || D_001D8A18 == 0) {
            func_003B68B0();
        }
        if (!(D_001D52FC_003B8430->f1A4 & 0x10)) return;
        func_0039BFD8();
        func_0039BFF0();
        D_001D8A40 = 6;
        break;
    case 21:
        if (D_001D5BDC_003B8430 != 0 && D_001D9FA0_003B8430 == 0) {
            t4 = D_001D52FC_003B8430->f1A4;
            if (t4 & 0x40) {
                func_0039C300();
                func_0039BE90();
                func_0039BFF0();
                func_003A8F50();
                return;
            }
            if (t4 & 0x10) {
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                func_0039BFD8();
                D_001D8A40 = 6;
            }
            break;
        }
        if (D_001D5BDD != 0) {
            if (D_001D52FC_003B8430->f1A4 & 0x40) {
                func_003B8A38(-1);
                func_003A8F50();
            }
            return;
        }
        t5 = D_001D52FC_003B8430->f1A4;
        if (((t5 & 0x40) && D_001D9FA0_003B8430 == 0) || ((t5 & 0x10) && D_001D9FA0_003B8430 != 0)) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D8A40 = 6;
        }
        break;
    case 26:
    case 27:
        t6 = D_001D52FC_003B8430->f1A4;
        if (t6 & 0x40) {
            func_0039C300();
            func_0039BE90();
            func_0039BFF0();
            func_003A8F50();
            return;
        }
        if (!(t6 & 0x10)) return;
        func_0039BFD8();
        func_0039BFF0();
        D_001D8A40 = 6;
        break;
    case 6:
        if (D_001D5BDC_003B8430 != 0) {
            if (D_001D9FA0_003B8430 == 0) {
                if (D_001D52FC_003B8430->f1A4 & 0x40) {
                    func_0039C300();
                    D_001D4CEC.b1 = 0;
                    D_001D4CEC.b2 = 0;
                    func_003B6510();
                }
                if (!(D_001D52FC_003B8430->f1A4 & 0x10)) return;
                func_0039BFD8();
                func_0039BFF0();
                D_001D8A40 = 6;
                break;
            }
            if (!(D_001D52FC_003B8430->f1A4 & 0x10)) return;
            func_0039BFD8();
            func_0039BFF0();
            D_001D8A40 = 6;
            break;
        }
        if (D_001D5BDD != 0) {
            if (!(D_001D52FC_003B8430->f1A4 & 0x20)) return;
            func_003B8A38(-1);
            func_003A8F50();
            return;
        }
        if (!(D_001D52FC_003B8430->f1A4 & 0x10)) return;
        func_0039BFD8();
        func_0039BFF0();
        D_001D8A40 = 6;
        break;
    case 11:
        if (*(s32 *)&D_001D4CEC & 6) return;
        D_001D8A40 = 5;
        break;
    }
}
/* localdecomp:end func_003B8430 */
