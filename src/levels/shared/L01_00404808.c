#include "common.h"

/* localdecomp:start func_L01_00404808 */
extern s32 D_L01_001DF988;
extern s32 D_L01_001E8480_00404808[];
extern s32 D_L01_001E8580[];

void func_L01_00404808(s32 a0, s32 a1) {
    s32 n = D_L01_001DF988;

    if (n < 0x40) {
        D_L01_001E8480_00404808[n] = a0;
        D_L01_001E8580[n] = a1;
        D_L01_001DF988 = n + 1;
    }
}
/* localdecomp:end func_L01_00404808 */

/* localdecomp:start func_L01_00404858 */
extern void func_L01_00404858(void);
extern s32 D_L01_001E8580[];

extern s32 D_L01_001DF988;
extern void (*D_L01_001E8480[])(s32);
void func_L01_00404858(void) {
    s32 i;
    for (i = 0; i < D_L01_001DF988; i++) D_L01_001E8480[i](D_L01_001E8580[i]);
}
/* localdecomp:end func_L01_00404858 */

/* localdecomp:start func_L01_004048D0 */
/* Ported from rac2-decomp rac2-decomp/src/game/0027B948.c:163-170. */
typedef void (*DrawCallback_004048D0)(int);
extern int D_L01_001DF990_004048D0[] __attribute__((section(".sdata")));
extern DrawCallback_004048D0 D_L01_001E8880_004048D0[];
extern int D_L01_001E8980_004048D0[];

void func_L01_004048D0(DrawCallback_004048D0 first, int second) {
    int index = D_L01_001DF990_004048D0[0];
    if (index < 64) {
        D_L01_001E8880_004048D0[index] = first;
        D_L01_001E8980_004048D0[index] = second;
        D_L01_001DF990_004048D0[0] = index + 1;
    }
}
/* localdecomp:end func_L01_004048D0 */

/* localdecomp:start func_L01_00404920 */
extern void func_L01_00404920(void);
extern s32 D_L01_001E8980[];

extern s32 D_L01_001DF990;
extern void (*D_L01_001E8880[])(s32);
void func_L01_00404920(void) {
    s32 i;
    for (i = 0; i < D_L01_001DF990; i++) D_L01_001E8880[i](D_L01_001E8980[i]);
}
/* localdecomp:end func_L01_00404920 */

/* localdecomp:start func_L01_00404998 */
extern void func_L01_00404998(void);
extern s32 D_L01_001E8B80[];

extern s32 D_L01_001DF994;
extern void (*D_L01_001E8A80[])(s32);
void func_L01_00404998(void) {
    s32 i;
    for (i = 0; i < D_L01_001DF994; i++) D_L01_001E8A80[i](D_L01_001E8B80[i]);
}
/* localdecomp:end func_L01_00404998 */

/* localdecomp:start func_L01_00404A10 */
/* Ported from rac2-decomp rac2-decomp/src/game/0027B948.c:163-170. */
typedef void (*Callback_00404A10)(int);

void func_L01_00404A10(Callback_00404A10 first, int second) {
    extern int D_L01_001DF98C_00404A10;
    extern Callback_00404A10 D_L01_001E8680_00404A10[];
    extern int D_L01_001E8780_00404A10[];

    int index = D_L01_001DF98C_00404A10;
    if (index < 64) {
        D_L01_001E8680_00404A10[index] = first;
        D_L01_001E8780_00404A10[index] = second;
        D_L01_001DF98C_00404A10 = index + 1;
    }
}
/* localdecomp:end func_L01_00404A10 */

/* localdecomp:start func_L01_00404A60 */
extern void func_L01_00404A60(void);
extern s32 D_L01_001E8780[];

extern s32 D_L01_001DF98C;
extern void (*D_L01_001E8680[])(s32);
void func_L01_00404A60(void) {
    s32 i;
    for (i = 0; i < D_L01_001DF98C; i++) D_L01_001E8680[i](D_L01_001E8780[i]);
}
/* localdecomp:end func_L01_00404A60 */

/* localdecomp:start func_L01_00404AD8 */
typedef void (*Callback_00404AD8)(int);
extern int D_L01_001DF9B8[] __attribute__((section(".sdata")));
extern Callback_00404AD8 D_L01_001DF998[] __attribute__((section(".sdata")));
extern int D_L01_001DF9A8[] __attribute__((section(".sdata")));
void func_L01_00404AD8(Callback_00404AD8 callback, int argument) {
    int index = D_L01_001DF9B8[0];
    if (index < 4) {
        D_L01_001DF998[index] = callback;
        D_L01_001DF9A8[index] = argument;
        D_L01_001DF9B8[0] = index + 1;
    }
}
/* localdecomp:end func_L01_00404AD8 */
