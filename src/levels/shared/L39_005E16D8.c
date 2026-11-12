#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005E16D8);

/* localdecomp:start func_L39_005E1EA0 */
extern s32 func_L01_00517688(void);
extern void func_L39_006121B0(s32);
extern u8 D_L39_00243970[8];
void func_L39_005E1EA0(void) {
    D_L39_00243970[func_L01_00517688()] = 0;
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
extern s32 D_L39_0024C518;
extern s32 D_L39_0024C538;
extern s32 D_L39_0024C558;
extern s32 D_L39_0024C578;
extern s32 D_L39_0024C500[2];
extern s32 D_L39_0024C520[2];
extern s32 D_L39_0024C540[2];
extern s32 D_L39_0024C560[2];
extern V16_3DF9E0 D_L39_002439B0[];
s32 func_L39_005E1ED0(s32 idx) {
    V16_3DF9E0 v;
    if (D_L39_0024C518 == 0) {
        func_003E6FA0(D_L39_0024C500, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_0024C518 = 1;
    }
    if (D_L39_0024C538 == 0) {
        func_003E6FA0(D_L39_0024C520, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_0024C538 = 1;
    }
    if (D_L39_0024C558 == 0) {
        func_003E6FA0(D_L39_0024C540, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_0024C558 = 1;
    }
    if (D_L39_0024C578 == 0) {
        func_003E6FA0(D_L39_0024C560, (s32)func_L39_005E0510, (s32)func_L39_005E1EA0, (s32)func_L39_005E16D8, 0, 0);
        D_L39_0024C578 = 1;
    }
    v = D_L39_002439B0[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L39_005E1ED0 */

/* localdecomp:start func_L39_005E2010 */
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 func_L01_0047C4A8(s32);
extern s32 func_L39_00610490(s32);
extern void func_L01_00516010(s32);
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005E2010(void) {
    func_003E82F8((*D_L39_00241120 < 2) ? 0 : 4);
    if (func_L39_00610490(func_L01_0047C4A8(0)) == 1) {
        func_L01_00516AA0(0x40000, 1, 0);
        func_L01_00516010(func_L01_0047C4A8(0));
    }
}
/* localdecomp:end func_L39_005E2010 */
