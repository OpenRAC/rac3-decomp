#include "common.h"

/* localdecomp:start func_L39_00576E48 */
extern s32 D_L39_00241118;
extern void (*D_L39_0024BA40[])(void);
extern void (*D_L39_0024BA50[])(void);
extern s32 D_L39_0024BF94;
extern s32 D_L39_0024CA38[];
extern s32 D_L39_0024CA48[];
extern s32 D_L39_0024CA58[];
extern s32 D_L39_0024CA98[];
extern s32 D_L39_0024CA68[];
extern s32 D_L39_0024CA78[];
extern s32 D_L39_0024CA88[];
extern s32 D_L39_0024C9E4;
extern s32 D_L39_0024C9E8;
extern s32 D_L39_0024C9F4;
extern s32 D_L39_0024CA1C;
extern s32 D_L39_0024CA10;
extern s32 D_L39_0024CA14;
extern s32 D_L39_0024CA18;

extern s32 D_001A5810[];
extern f32 D_L39_0024BB4C;
extern f32 D_L39_0024B810[] __attribute__((section(".sdata")));
extern void func_L39_0061C520(void);
extern void func_L01_00403168(s32);
extern void func_L39_00588CE0(s32);
extern void func_003A92F0(s32);
extern void func_L39_005FCDF8(void);
extern void func_003A9150(void);


void func_L39_00576E48(s32 a, s32 b, s32 c, s32 d)
{
    f32 t;
    s32 i;
    s32 j;

    D_L39_00241118 = a;
    func_L39_0061C520();
    if (D_L39_0024BA40[a] != 0) {
        D_L39_0024BA40[a]();
    }
    func_L01_00403168(b);
    if (c == 0) {
        D_L39_0024BF94 = 1;
    }
    i = D_L39_00241118;
    D_L39_0024C9E4 = D_L39_0024CA38[i];
    D_L39_0024C9E8 = D_L39_0024CA48[i];
    D_L39_0024C9F4 = D_L39_0024CA58[i];
    D_L39_0024CA1C = D_L39_0024CA98[i];
    D_L39_0024CA10 = D_L39_0024CA68[i];
    D_L39_0024CA14 = D_L39_0024CA78[i];
    D_L39_0024CA18 = D_L39_0024CA88[i];
    t = (f32)*(volatile u32 *)0x10000800 / (D_001A5810[0] != 0 ? 11520.0f : 9600.0f);
    func_L39_00588CE0(a);
    D_L39_0024B810[a] = D_L39_0024BB4C - t;
    j = D_L39_00241118;
    D_L39_0024CA68[j] = D_L39_0024CA10;
    D_L39_0024CA78[j] = D_L39_0024CA14;
    D_L39_0024CA88[j] = D_L39_0024CA18;
    if (j != 0) {
        D_L39_0024C9E4 = D_L39_0024CA38[0];
        D_L39_0024C9E8 = D_L39_0024CA48[0];
        D_L39_0024C9F4 = D_L39_0024CA58[0];
        D_L39_0024CA1C = D_L39_0024CA98[0];
        D_L39_0024CA10 = D_L39_0024CA68[0];
        D_L39_0024CA14 = D_L39_0024CA78[0];
        D_L39_0024CA18 = D_L39_0024CA88[0];
    }
    if (d == 0) {
        func_003A92F0(1);
        func_L39_005FCDF8();
        func_003A9150();
    }
    if (D_L39_0024BA50[a] != 0) {
        D_L39_0024BA50[a]();
    }
}
/* localdecomp:end func_L39_00576E48 */
