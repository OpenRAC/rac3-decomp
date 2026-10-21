#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005E16D8);

/* localdecomp:start func_L39_005E1EA0 */
extern s32 func_L01_00517688(void);
extern void func_L39_006121B0(s32);
extern u8 D_L39_001D8260[8];
void func_L39_005E1EA0(void) {
    D_L39_001D8260[func_L01_00517688()] = 0;
    func_L39_006121B0(21);
}
/* localdecomp:end func_L39_005E1EA0 */

/* localdecomp:start func_L39_005E1ED0 */
extern s32 func_L39_005E1ED0(s32);
extern void func_L39_005E16D8();

typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_L39_005E0510(s32);
extern void func_L39_005E1EA0(void);
extern void func_L39_005E16D8(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L39_001E0E08;
extern s32 D_L39_001E0E28;
extern s32 D_L39_001E0E48;
extern s32 D_L39_001E0E68;
extern s32 D_L39_001E0DF0[2];
extern s32 D_L39_001E0E10[2];
extern s32 D_L39_001E0E30[2];
extern s32 D_L39_001E0E50[2];
extern V16_3DF9E0 D_L39_002439B0[];
s32 func_L39_005E1ED0(s32 idx) {
    V16_3DF9E0 v;
    if (D_L39_001E0E08 == 0) {
        func_003E6FA0(D_L39_001E0DF0, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_001E0E08 = 1;
    }
    if (D_L39_001E0E28 == 0) {
        func_003E6FA0(D_L39_001E0E10, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_001E0E28 = 1;
    }
    if (D_L39_001E0E48 == 0) {
        func_003E6FA0(D_L39_001E0E30, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_001E0E48 = 1;
    }
    if (D_L39_001E0E68 == 0) {
        func_003E6FA0(D_L39_001E0E50, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_001E0E68 = 1;
    }
    v = D_L39_002439B0[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L39_005E1ED0 */

INCLUDE_ASM("asm/levels", func_L39_005E2010);
