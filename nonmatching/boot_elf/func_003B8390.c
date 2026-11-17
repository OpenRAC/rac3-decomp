/* PAL near miss (Codex wave 7): held at landing (da6b7b64): the C matches on its own (tools/check.py MATCH), but its file does not assemble with it in the full build.
 */
#include "common.h"
/* localdecomp:start func_003B8390 */
void func_003B8390(void) {
    extern void func_0038E530(s32);
    char *text;
    s32 left = 0, right = 0, show = 1;
    T_3B2AF8 copy, box;
    
    s32 a, b;
    func_0038E530(0);
    text = (char *)D_001D8B48;
    switch (D_001D4CE8_003B8390) {
    case 8:
        left = func_003823D0(0x8e3); right = func_003823D0(0x8df);
        text = func_003823D0(0x1a3); break;
    case 14:
        if (!D_001D9FA0_003B8390) break;
        goto msg196;
    case 15:
        left = func_003823D0(0x8e3); right = func_003823D0(0x8df);
        text = (char *)func_00382468(0x1a0); break;
    case 33:
        left = func_003823D0(0x8e3); right = func_003823D0(0x8df);
        text = (char *)func_00382468(0x1a9); break;
    case 12: case 13: case 31: case 32: text = (char *)func_00382468(0x1af); break;
    case 9: case 10: text = (char *)func_00382468(0x1ad); break;
    case 16: case 17: text = (char *)func_00382468(0x1ae); break;
    case 25: case 29: text = (char *)func_00382468(0x1ab); break;
    case 23: case 30: text = (char *)func_00382468(0x1ac); break;
    case 19: text = (char *)func_00382468(0x1b0); left=func_003823D0(0x8de); break;
    case 20: text = (char *)func_00382468(0x1b2); left=func_003823D0(0x8de); break;
    case 3: text = (char *)func_00382468(0x194); break;
    case 21: {
        if (D_001D9FA0_003B8390) goto msg196;
        if (D_001D5BDC_003B8390) {
            char *dst=D_00280AF0, *fmt=D_001D8B50;
            func_11B2E8(dst,fmt,func_003823D0(0x199),1,1,func_003823D0(0x19a));
            text=dst;
            left=func_003823D0(0x8e2); right=func_003823D0(0x8df);
        } else {
            char *dst=D_00280AF0, *fmt=D_001D8B50;
            func_11B2E8(dst,fmt,func_00382468(0x199),1,1,func_00382468(0x19a));
            text=dst;
            left=func_003823D0(0x8e2);
        }
        break;
    }
    case 24:
        if (D_001D5BDC_003B8390) text=(char *)func_00382468(0x1b2);
        else text=(char *)func_00382468(0x1b3);
        left=func_003823D0(0x8de); break;
    case 22: text=(char *)func_00382468(0x1b1); left=func_003823D0(0x8de); break;
    case 27: {
        char *dst, *fmt;
        left=func_003823D0(0x8e2); right=func_003823D0(0x8df);
        dst=D_00280AF0; fmt=D_001D8B50;
        func_11B2E8(dst,fmt,func_00382468(0x1a2),1,1,func_00382468(0x19a));
            text=dst; break;
    }
    case 26:
        left=func_003823D0(0x8e2); right=func_003823D0(0x8df);
        text=(char *)func_00382468(0x1a5); break;
    case 4: case 5: case 6:
        if (D_001D5BDC_003B8390 && !D_001D9FA0_003B8390) {
            left=func_003823D0(0x8e2); right=func_003823D0(0x8df);
            text=(char *)func_00382468(0x19c);
        } else if (D_001D5BDD) {
            left=func_003823D0(0x8e3); text=(char *)func_00382468(0x19c);
        } else {
            if (D_001D9FA0_003B8390) text=(char *)func_00382468(0x196);
            else text=(char *)func_00382468(0x19e);
            left=func_003823D0(0x197);
        }
        break;
    case 7:
    msg196: text=(char *)func_00382468(0x196); left=func_003823D0(0x197); break;
    default: show=0; break;
    }
    if (show) {
        func_0011A264(&box,0,0x1c);
        box.f2=D_001D4BC4; box.f4=0x60; box.f6=0x1a0; box.f8=0x100;
        box.fA=0x68; box.f10=0x10; box.f12=1;
        copy=box;
        func_0038E530(1);
        func_003AF7C0(&copy,0x8066ccff,(void *)text,1,1,-1,0,(void *)left,(void *)right,0);
    }
}
/* localdecomp:end func_003B8390 */
