#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0039C300(void);
extern s32 D_001D8A18;
extern void func_003B8A38(s32);
extern void func_003B6888(void);
extern void func_003B68B0(void);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B8430(void);
extern void func_003B7FD8(void);


typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3B2AF8;
extern s32 D_001D4CE8_003B7FD8;
extern u8 D_001D9FA0_003B7FD8;
extern u8 D_001D5BDC_003B7FD8;
extern u8 D_001D5BDD;
extern u16 D_001D4BC4;
extern char D_001D8B48[];
extern char D_001D8B50[];
extern char D_00280AF0[];
extern char *func_00382088(s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_003AF408(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern void func_11B2E8();
/* localdecomp:start func_003B7FD8 */
extern s32 func_00381FF0(s32);
extern void func_0038E150(s32);

void func_003B7FD8(void) {
    char *text;
    s32 left = 0, right = 0, show = 1;
    T_3B2AF8 copy, box;
    
    s32 a, b;
    func_0038E150(0);
    text = (char *)D_001D8B48;
    switch (D_001D4CE8_003B7FD8) {
    case 8:
        left = func_00381FF0(0x8e3); right = func_00381FF0(0x8df);
        text = func_00381FF0(0x1a3); break;
    case 14:
        if (!D_001D9FA0_003B7FD8) break;
        goto msg196;
    case 15:
        left = func_00381FF0(0x8e3); right = func_00381FF0(0x8df);
        text = (char *)func_00382088(0x1a0); break;
    case 33:
        left = func_00381FF0(0x8e3); right = func_00381FF0(0x8df);
        text = (char *)func_00382088(0x1a9); break;
    case 12: case 13: case 31: case 32: text = (char *)func_00382088(0x1af); break;
    case 9: case 10: text = (char *)func_00382088(0x1ad); break;
    case 16: case 17: text = (char *)func_00382088(0x1ae); break;
    case 25: case 29: text = (char *)func_00382088(0x1ab); break;
    case 23: case 30: text = (char *)func_00382088(0x1ac); break;
    case 19: text = (char *)func_00382088(0x1b0); left=func_00381FF0(0x8de); break;
    case 20: text = (char *)func_00382088(0x1b2); left=func_00381FF0(0x8de); break;
    case 3: text = (char *)func_00382088(0x194); break;
    case 21: {
        if (D_001D9FA0_003B7FD8) goto msg196;
        if (D_001D5BDC_003B7FD8) {
            char *dst=D_00280AF0, *fmt=D_001D8B50;
            func_11B2E8(dst,fmt,func_00381FF0(0x199),1,1,func_00381FF0(0x19a));
            text=dst;
            left=func_00381FF0(0x8e2); right=func_00381FF0(0x8df);
        } else {
            char *dst=D_00280AF0, *fmt=D_001D8B50;
            func_11B2E8(dst,fmt,func_00382088(0x199),1,1,func_00382088(0x19a));
            text=dst;
            left=func_00381FF0(0x8e2);
        }
        break;
    }
    case 24:
        if (D_001D5BDC_003B7FD8) text=(char *)func_00382088(0x1b2);
        else text=(char *)func_00382088(0x1b3);
        left=func_00381FF0(0x8de); break;
    case 22: text=(char *)func_00382088(0x1b1); left=func_00381FF0(0x8de); break;
    case 27: {
        char *dst, *fmt;
        left=func_00381FF0(0x8e2); right=func_00381FF0(0x8df);
        dst=D_00280AF0; fmt=D_001D8B50;
        func_11B2E8(dst,fmt,func_00382088(0x1a2),1,1,func_00382088(0x19a));
            text=dst; break;
    }
    case 26:
        left=func_00381FF0(0x8e2); right=func_00381FF0(0x8df);
        text=(char *)func_00382088(0x1a5); break;
    case 4: case 5: case 6:
        if (D_001D5BDC_003B7FD8 && !D_001D9FA0_003B7FD8) {
            left=func_00381FF0(0x8e2); right=func_00381FF0(0x8df);
            text=(char *)func_00382088(0x19c);
        } else if (D_001D5BDD) {
            left=func_00381FF0(0x8e3); text=(char *)func_00382088(0x19c);
        } else {
            if (D_001D9FA0_003B7FD8) text=(char *)func_00382088(0x196);
            else text=(char *)func_00382088(0x19e);
            left=func_00381FF0(0x197);
        }
        break;
    case 7:
    msg196: text=(char *)func_00382088(0x196); left=func_00381FF0(0x197); break;
    default: show=0; break;
    }
    if (show) {
        func_0011A264(&box,0,0x1c);
        box.f2=D_001D4BC4; box.f4=0x60; box.f6=0x1a0; box.f8=0x100;
        box.fA=0x68; box.f10=0x10; box.f12=1;
        copy=box;
        func_0038E150(1);
        func_003AF408(&copy,0x8066ccff,(void *)text,1,1,-1,0,(void *)left,(void *)right,0);
    }
}
/* localdecomp:end func_003B7FD8 */

/* localdecomp:start func_003B8430 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
__asm__(".extern D_001D8A40, 4");
__asm__(".extern D_001D8A18, 4");
extern void func_003A5348(s32, s32, s32);
extern s32 D_001D8A40;
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
