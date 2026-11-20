#include "common.h"

/* NTSC-U counterpart of func_003B7FD8 (src/frontbin/3B7FD8.c): text ids one lower, case 21's else arm reads 0x198 through func_U_0037DF98 */
/* localdecomp:start func_U_003B2AF8 */
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3B2AF8;
extern s32 D_001D4CE8;
extern u8 D_U_001DA020;
extern u8 D_U_001D5BDC;
extern u8 D_U_001D5BDD;
extern u16 D_001D4BC4;
extern char D_U_001D8B78[];
extern char D_U_001D8B80[];
extern char D_U_0027CB70[];
extern char *func_U_0037E030(s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_U_003A9E60(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern void func_11B2E8();
extern s32 func_U_0037DF98(s32);
extern void func_U_00389920(s32);

void func_U_003B2AF8(void) {
    char *text;
    s32 left = 0, right = 0, show = 1;
    T_3B2AF8 copy, box;
    
    s32 a, b;
    func_U_00389920(0);
    text = (char *)D_U_001D8B78;
    switch (D_001D4CE8) {
    case 8:
        left = func_U_0037DF98(0x8e3); right = func_U_0037DF98(0x8df);
        text = func_U_0037DF98(0x1a3); break;
    case 14:
        if (!D_U_001DA020) break;
        goto msg196;
    case 15:
        left = func_U_0037DF98(0x8e3); right = func_U_0037DF98(0x8df);
        text = (char *)func_U_0037E030(0x19f); break;
    case 33:
        left = func_U_0037DF98(0x8e3); right = func_U_0037DF98(0x8df);
        text = (char *)func_U_0037E030(0x1a8); break;
    case 12: case 13: case 31: case 32: text = (char *)func_U_0037E030(0x1af); break;
    case 9: case 10: text = (char *)func_U_0037E030(0x1ad); break;
    case 16: case 17: text = (char *)func_U_0037E030(0x1ae); break;
    case 25: case 29: text = (char *)func_U_0037E030(0x1ab); break;
    case 23: case 30: text = (char *)func_U_0037E030(0x1ac); break;
    case 19: text = (char *)func_U_0037E030(0x1b0); left=func_U_0037DF98(0x8de); break;
    case 20: text = (char *)func_U_0037E030(0x1b2); left=func_U_0037DF98(0x8de); break;
    case 3: text = (char *)func_U_0037E030(0x194); break;
    case 21: {
        if (D_U_001DA020) goto msg196;
        if (D_U_001D5BDC) {
            char *dst=D_U_0027CB70, *fmt=D_U_001D8B80;
            func_11B2E8(dst,fmt,func_U_0037DF98(0x198),1,1,func_U_0037DF98(0x19a));
            text=dst;
            left=func_U_0037DF98(0x8e2); right=func_U_0037DF98(0x8df);
        } else {
            char *dst=D_U_0027CB70, *fmt=D_U_001D8B80;
            func_11B2E8(dst,fmt,func_U_0037DF98(0x198),1,1,func_U_0037E030(0x19a));
            text=dst;
            left=func_U_0037DF98(0x8e2);
        }
        break;
    }
    case 24:
        if (D_U_001D5BDC) text=(char *)func_U_0037E030(0x1b2);
        else text=(char *)func_U_0037E030(0x1b3);
        left=func_U_0037DF98(0x8de); break;
    case 22: text=(char *)func_U_0037E030(0x1b1); left=func_U_0037DF98(0x8de); break;
    case 27: {
        char *dst, *fmt;
        left=func_U_0037DF98(0x8e2); right=func_U_0037DF98(0x8df);
        dst=D_U_0027CB70; fmt=D_U_001D8B80;
        func_11B2E8(dst,fmt,func_U_0037E030(0x1a1),1,1,func_U_0037E030(0x19a));
            text=dst; break;
    }
    case 26:
        left=func_U_0037DF98(0x8e2); right=func_U_0037DF98(0x8df);
        text=(char *)func_U_0037E030(0x1a5); break;
    case 4: case 5: case 6:
        if (D_U_001D5BDC && !D_U_001DA020) {
            left=func_U_0037DF98(0x8e2); right=func_U_0037DF98(0x8df);
            text=(char *)func_U_0037E030(0x19b);
        } else if (D_U_001D5BDD) {
            left=func_U_0037DF98(0x8e3); text=(char *)func_U_0037E030(0x19b);
        } else {
            if (D_U_001DA020) text=(char *)func_U_0037E030(0x195);
            else text=(char *)func_U_0037E030(0x19d);
            left=func_U_0037DF98(0x197);
        }
        break;
    case 7:
    msg196: text=(char *)func_U_0037E030(0x195); left=func_U_0037DF98(0x197); break;
    default: show=0; break;
    }
    if (show) {
        func_0011A264(&box,0,0x1c);
        box.f2=D_001D4BC4; box.f4=0x60; box.f6=0x1a0; box.f8=0x100;
        box.fA=0x68; box.f10=0x10; box.f12=1;
        copy=box;
        func_U_00389920(1);
        func_U_003A9E60(&copy,0x8066ccff,(void *)text,1,1,-1,0,(void *)left,(void *)right,0);
    }
}
/* localdecomp:end func_U_003B2AF8 */
