#include "common.h"

/* declared by functions of L39_005DED10.c, which this file was cut from */
extern s32 func_L39_006121B0();
extern s32 func_003E6FA0(void *, void *, void *, void *, s32, s32);
extern u8 D_L39_0024392C;
extern s32 func_L39_005E0310(s32 idx);

/* localdecomp:start func_L39_005E02F0 */
extern u8 D_L39_0024392C;
extern s32 func_L39_006121B0();
void func_L39_005E02F0(void) {
    D_L39_0024392C = 0;
    func_L39_006121B0(24);
}
/* localdecomp:end func_L39_005E02F0 */

/* localdecomp:start func_L39_005E0310 */
extern s32 func_003E6FA0(void *, void *, void *, void *, s32, s32);
extern s32 func_L39_005E0310(s32);
extern void func_L39_005DF8F8();

typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_L39_005DF060(s32);
extern void func_L39_005E02F0(void);
extern void func_L39_005DF8F8(void);
extern s32 D_L39_0024C478;
extern s32 D_L39_0024C498;
extern s32 D_L39_0024C4B8;
extern s32 D_L39_0024C4D8;
extern s32 D_L39_0024C460[2];
extern s32 D_L39_0024C480[2];
extern s32 D_L39_0024C4A0[2];
extern s32 D_L39_0024C4C0[2];
extern V16_3DF9E0 D_L39_00243940[];
s32 func_L39_005E0310(s32 idx) {
    V16_3DF9E0 v;
    if (D_L39_0024C478 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_0024C460, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_0024C478 = 1;
    }
    if (D_L39_0024C498 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_0024C480, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_0024C498 = 1;
    }
    if (D_L39_0024C4B8 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_0024C4A0, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_0024C4B8 = 1;
    }
    if (D_L39_0024C4D8 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_0024C4C0, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_0024C4D8 = 1;
    }
    v = D_L39_00243940[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L39_005E0310 */
