#include "common.h"

typedef struct { u8 b[16]; } V16_48DCD8;

/* localdecomp:start func_L39_005E94F8 */
extern void func_L39_005E9658(void);
extern void func_L01_00490370(void);
extern void func_L39_005E9B28(void);
extern void func_L01_0047ECB0_005E94F8(void);
extern void func_L01_0047ECB8_005E94F8(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L39_001E10F0;
extern s32 D_L39_001E1110;
extern s32 D_L39_001E1130;
extern s32 D_L39_001E1150;
extern s32 D_L39_001E10D8[2];
extern s32 D_L39_001E10F8[2];
extern s32 D_L39_001E1118[2];
extern s32 D_L39_001E1138[2];
extern V16_48DCD8 D_L39_00243D38[];
s32 func_L39_005E94F8(s32 idx) {
    V16_48DCD8 v;
    if (D_L39_001E10F0 == 0) {
        func_003E6FA0(D_L39_001E10D8, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_001E10F0 = 1;
    }
    if (D_L39_001E1110 == 0) {
        func_003E6FA0(D_L39_001E10F8, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_001E1110 = 1;
    }
    if (D_L39_001E1130 == 0) {
        func_003E6FA0(D_L39_001E1118, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_001E1130 = 1;
    }
    if (D_L39_001E1150 == 0) {
        func_003E6FA0(D_L39_001E1138, (s32)func_L39_005E9658, (s32)func_L01_00490370, (s32)func_L39_005E9B28, (s32)func_L01_0047ECB0_005E94F8, (s32)func_L01_0047ECB8_005E94F8);
        D_L39_001E1150 = 1;
    }
    v = D_L39_00243D38[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L39_005E94F8 */

INCLUDE_ASM("asm/levels", func_L39_005E9658);

INCLUDE_ASM("asm/levels", func_L39_005E9B28);
