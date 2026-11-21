#include "common.h"

/* NTSC-U counterpart of func_L39_00576E48 (src/levels/shared/L39_00576E48.c): the resident table D_001A5810 is D_001A5990 on NTSC-U; level data moved */
/* localdecomp:start func_L39_00576108 */
extern s32 D_L39_00241298;
extern void (*D_L39_0024BB40[])(void);
extern void (*D_L39_0024BB50[])(void);
extern s32 D_L39_0024C094;
extern s32 D_L39_0024CB38[];
extern s32 D_L39_0024CB48[];
extern s32 D_L39_0024CB58[];
extern s32 D_L39_0024CB98[];
extern s32 D_L39_0024CB68[];
extern s32 D_L39_0024CB78[];
extern s32 D_L39_0024CB88[];
extern s32 D_L39_0024CAE4;
extern s32 D_L39_0024CAE8;
extern s32 D_L39_0024CAF4;
extern s32 D_L39_0024CB1C;
extern s32 D_L39_0024CB10;
extern s32 D_L39_0024CB14;
extern s32 D_L39_0024CB18;

extern s32 D_001A5990[];
extern f32 D_L39_0024BC4C;
extern f32 D_L39_0024B910[] __attribute__((section(".sdata")));
extern void func_L39_00619DA8(void);
extern void func_L01_00400DF8(s32);
extern void func_L39_00587B70(s32);
extern void func_003A3DA0(s32);
extern void func_L39_005FA660(void);
extern void func_003A3C00(void);


void func_L39_00576108(s32 a, s32 b, s32 c, s32 d)
{
    f32 t;
    s32 i;
    s32 j;

    D_L39_00241298 = a;
    func_L39_00619DA8();
    if (D_L39_0024BB40[a] != 0) {
        D_L39_0024BB40[a]();
    }
    func_L01_00400DF8(b);
    if (c == 0) {
        D_L39_0024C094 = 1;
    }
    i = D_L39_00241298;
    D_L39_0024CAE4 = D_L39_0024CB38[i];
    D_L39_0024CAE8 = D_L39_0024CB48[i];
    D_L39_0024CAF4 = D_L39_0024CB58[i];
    D_L39_0024CB1C = D_L39_0024CB98[i];
    D_L39_0024CB10 = D_L39_0024CB68[i];
    D_L39_0024CB14 = D_L39_0024CB78[i];
    D_L39_0024CB18 = D_L39_0024CB88[i];
    t = (f32)*(volatile u32 *)0x10000800 / (D_001A5990[0] != 0 ? 11520.0f : 9600.0f);
    func_L39_00587B70(a);
    D_L39_0024B910[a] = D_L39_0024BC4C - t;
    j = D_L39_00241298;
    D_L39_0024CB68[j] = D_L39_0024CB10;
    D_L39_0024CB78[j] = D_L39_0024CB14;
    D_L39_0024CB88[j] = D_L39_0024CB18;
    if (j != 0) {
        D_L39_0024CAE4 = D_L39_0024CB38[0];
        D_L39_0024CAE8 = D_L39_0024CB48[0];
        D_L39_0024CAF4 = D_L39_0024CB58[0];
        D_L39_0024CB1C = D_L39_0024CB98[0];
        D_L39_0024CB10 = D_L39_0024CB68[0];
        D_L39_0024CB14 = D_L39_0024CB78[0];
        D_L39_0024CB18 = D_L39_0024CB88[0];
    }
    if (d == 0) {
        func_003A3DA0(1);
        func_L39_005FA660();
        func_003A3C00();
    }
    if (D_L39_0024BB50[a] != 0) {
        D_L39_0024BB50[a]();
    }
}
/* localdecomp:end func_L39_00576108 */
