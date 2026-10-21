#include "common.h"

/* localdecomp:start func_L01_004792D8 */
extern s32 D_L01_001D8054;

void func_L01_004792D8(s32 a) {
    D_L01_001D8054 = a;
}
/* localdecomp:end func_L01_004792D8 */

/* localdecomp:start func_L01_004792E0 */
s32 func_L01_004792E0(s32 a) {
    s32 r = 0x10006;
    if (a == 0) {
        r = 0x10005;
    }
    return r;
}
/* localdecomp:end func_L01_004792E0 */

INCLUDE_ASM("asm/levels", func_L01_004792F8);

INCLUDE_ASM("asm/levels", func_L01_00479390);

/* localdecomp:start func_L01_00479558 */
extern u8 D_L01_001D8058;
extern s32 func_L01_00517918();
void func_L01_00479558(void) {
    D_L01_001D8058 = 0;
    func_L01_00517918(5);
}
/* localdecomp:end func_L01_00479558 */

/* localdecomp:start func_L01_00479578 */
extern s32 func_L01_00479578(s32);
extern void func_L01_00479390();

typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_L01_00478BD0(s32);
extern void func_L01_00479558(void);
extern void func_L01_00479390(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0308;
extern s32 D_L01_001E0328;
extern s32 D_L01_001E0348;
extern s32 D_L01_001E0368;
extern s32 D_L01_001E02F0[2];
extern s32 D_L01_001E0310[2];
extern s32 D_L01_001E0330[2];
extern s32 D_L01_001E0350[2];
extern V16_3DF9E0 D_L01_001D8090[];
s32 func_L01_00479578(s32 idx) {
    V16_3DF9E0 v;
    if (D_L01_001E0308 == 0) {
        func_003E6FA0(D_L01_001E02F0, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0308 = 1;
    }
    if (D_L01_001E0328 == 0) {
        func_003E6FA0(D_L01_001E0310, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0328 = 1;
    }
    if (D_L01_001E0348 == 0) {
        func_003E6FA0(D_L01_001E0330, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0348 = 1;
    }
    if (D_L01_001E0368 == 0) {
        func_003E6FA0(D_L01_001E0350, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0368 = 1;
    }
    v = D_L01_001D8090[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_00479578 */

INCLUDE_ASM("asm/levels", func_L01_004796B8);

INCLUDE_ASM("asm/levels", func_L01_00479738);

LINKER_REMNANT("asm/levels", func_L01_00479AA8);

INCLUDE_ASM("asm/levels", func_L01_00479AB0);
