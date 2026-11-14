#include "common.h"

typedef struct { u8 b[16]; } V16_48DCD8;

/* localdecomp:start func_L39_005E94F8 */
extern void func_L39_005E9658(void);
extern void func_L01_00490370(void);
extern void func_L39_005E9B28(void *);
extern void func_L01_0047ECB0_005E94F8(void);
extern void func_L01_0047ECB8_005E94F8(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L39_0024C800;
extern s32 D_L39_0024C820;
extern s32 D_L39_0024C840;
extern s32 D_L39_0024C860;
extern s32 D_L39_0024C7E8[2];
extern s32 D_L39_0024C808[2];
extern s32 D_L39_0024C828[2];
extern s32 D_L39_0024C848[2];
extern V16_48DCD8 D_L39_00243D38[];
s32 func_L39_005E94F8(s32 idx) {
    V16_48DCD8 v;
    if (D_L39_0024C800 == 0) {
        func_003E6FA0(D_L39_0024C7E8, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_0024C800 = 1;
    }
    if (D_L39_0024C820 == 0) {
        func_003E6FA0(D_L39_0024C808, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_0024C820 = 1;
    }
    if (D_L39_0024C840 == 0) {
        func_003E6FA0(D_L39_0024C828, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_0024C840 = 1;
    }
    if (D_L39_0024C860 == 0) {
        func_003E6FA0(D_L39_0024C848, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_0024C860 = 1;
    }
    v = D_L39_00243D38[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L39_005E94F8 */

INCLUDE_ASM("asm/levels", func_L39_005E9658);

INCLUDE_ASM("asm/levels", func_L39_005E9B28);
