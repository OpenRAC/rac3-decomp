#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0041BFE8);

/* localdecomp:start func_L01_0041C170 */
extern u8 *D_L01_001DFD18;
extern s32 D_L01_001DFD40[];
#define D_L01_001DFD40 (D_L01_001DFD40[0])
extern s32 D_L01_001DFD48[];
#define D_L01_001DFD48 (D_L01_001DFD48[0])
extern s32 D_L01_001DFD4C[];
#define D_L01_001DFD4C (D_L01_001DFD4C[0])
extern s32 D_L01_001DFD50[];
#define D_L01_001DFD50 (D_L01_001DFD50[0])

extern void func_L01_004B11E0(void *, s32, s32, s32, s32);
extern void func_003A0760(void *, u8 *);
extern void func_00392FD0(s32, u8 *);

void func_L01_0041C170(s32 arg0, u8 *arg1, void *arg2) {
    if (*(s32 *)(D_L01_001DFD18 + 84) != 0) {
        s32 n = *(s32 *)(D_L01_001DFD18 + 84);
        func_L01_004B11E0(arg2, *(s32 *)(D_L01_001DFD18 + 148), 0, D_L01_001DFD40 / 16, 0);
        func_003A0760(arg2, arg1);
        func_00392FD0(0, arg1);
        arg1 += n;
    }
    if (*(s32 *)(D_L01_001DFD18 + 92) != 0) {
        s32 n = *(s32 *)(D_L01_001DFD18 + 92);
        func_L01_004B11E0(arg2, *(s32 *)(D_L01_001DFD18 + 156), 0, D_L01_001DFD48 / 16, 0);
        func_003A0760(arg2, arg1);
        func_00392FD0(2, arg1);
        arg1 += n;
    }
    if (arg0 == 0 || arg0 == 2) {
        if (*(s32 *)(D_L01_001DFD18 + 96) != 0) {
            s32 n = *(s32 *)(D_L01_001DFD18 + 96);
            func_L01_004B11E0(arg2, *(s32 *)(D_L01_001DFD18 + 160), 0, D_L01_001DFD4C / 16, 0);
            func_003A0760(arg2, arg1);
            func_00392FD0(3, arg1);
            arg1 += n;
        }
    }
    if ((u32)(arg0 - 1) < 2) {
        u8 *p = *(u8 * volatile *)&D_L01_001DFD18;
        if (*(s32 *)(p + 100) != 0) {
            func_L01_004B11E0(arg2, *(s32 *)(p + 164), 0, D_L01_001DFD50 / 16, 0);
            func_003A0760(arg2, arg1);
            func_00392FD0(4, arg1);
        }
    }
}
/* localdecomp:end func_L01_0041C170 */
