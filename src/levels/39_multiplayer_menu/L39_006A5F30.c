#include "common.h"

typedef struct S_006A5FE0 {
    u8 pad0[0x2B1];
    u8 f2B1;
    u8 pad1[6];
    s32 f2B8;
    s32 f2BC[576];
    s32 fBBC[1];
} S_006A5FE0;

typedef struct S_006A6108 {
    u8 pad0[0xCBC];
    u8 f_CBC;
    u8 pad1[7];
    s32 f_CC4;
    s32 f_CC8[1];
    u8 pad2[0x8FC];
    s32 f_15C8[1];
} S_006A6108;

typedef struct S_L39_006A6078 {
    u8 pad0[0x16CC];
    s32 f16CC;
    s32 f16D0[11];
    s32 f16FC[1];
} S_L39_006A6078;

INCLUDE_ASM("asm/levels", func_L39_006A5F30);

/* localdecomp:start func_L39_006A5FE0 */
extern s32 func_00381FF0(s32);
extern void func_L39_00688340(s32, s32, s32);
extern s32 func_L39_00687800(s32, s32, void *, s32, s32);
extern void func_L39_006A6290(void *, s32, s32);
extern s32 D_L39_00247914[];

void func_L39_006A5FE0(S_006A5FE0 *arg0) {
    s32 *tbl;
    s32 base;
    s32 a;
    s32 r;

    func_L39_00688340(4, 0, 0);
    tbl = arg0->fBBC;
    base = D_L39_00247914[0];
    a = func_00381FF0(0x1647);
    r = func_L39_00687800(base, a, tbl, arg0->f2B8, 0);
    if (r >= 0) {
        func_L39_006A6290(arg0, arg0->f2BC[r], arg0->fBBC[r]);
    }
    arg0->f2B1 = 1;
}
/* localdecomp:end func_L39_006A5FE0 */

/* localdecomp:start func_L39_006A6078 */
extern s32 func_00381FF0(s32);
extern void func_L39_00688340(s32, s32, s32);
extern s32 func_L39_00687800(s32, s32, void *, s32, s32);
extern void func_L39_006A6290(void *, s32, s32);
extern s32 D_L39_00247914[];

void func_L39_006A6078(S_L39_006A6078 *arg0) {
    s32 *tab;
    s32 g;
    s32 a;
    s32 idx;

    func_L39_00688340(4, 0, 0);
    g = D_L39_00247914[0];
    tab = arg0->f16FC;
    a = func_00381FF0(0xFD1);
    idx = func_L39_00687800(g, a, tab, arg0->f16CC, 0);
    if (idx >= 0) {
        func_L39_006A6290(arg0, arg0->f16D0[idx], arg0->f16FC[idx]);
    }
}
/* localdecomp:end func_L39_006A6078 */

/* localdecomp:start func_L39_006A6108 */
extern s32 D_L39_00247914[];


void func_L39_006A6108(S_006A6108 *arg0) {
    s32 g;
    s32 v;
    s32 r;

    func_L39_00688340(4, 0, 0);
    g = D_L39_00247914[0];
    v = func_00381FF0(0x1648);
    r = func_L39_00687800(g, v, arg0->f_15C8, arg0->f_CC4, 0);
    if (r >= 0) {
        func_L39_006A6290(arg0, arg0->f_CC8[r], arg0->f_15C8[r]);
    }
    arg0->f_CBC = 1;
}
/* localdecomp:end func_L39_006A6108 */

INCLUDE_ASM("asm/levels", func_L39_006A61A0);

INCLUDE_ASM("asm/levels", func_L39_006A6290);

INCLUDE_ASM("asm/levels", func_L39_006A6470);

INCLUDE_ASM("asm/levels", func_L39_006A65B8);

INCLUDE_ASM("asm/levels", func_L39_006A6778);

INCLUDE_ASM("asm/levels", func_L39_006A6938);

LINKER_REMNANT("asm/levels", func_L39_006A69A0);

INCLUDE_ASM("asm/levels", func_L39_006A69C0);

LINKER_REMNANT("asm/levels", func_L39_006A6F98);

INCLUDE_ASM("asm/levels", func_L39_006A6FA0);

INCLUDE_ASM("asm/levels", func_L39_006A6FC8);

INCLUDE_ASM("asm/levels", func_L39_006A7178);

INCLUDE_ASM("asm/levels", func_L39_006A72B0);

/* localdecomp:start func_L39_006A74B8 */
s32 func_L39_0068ADC8(s32);
s32 func_L39_005C1A60(s32, s32, s32);
s32 func_L39_0067F168();

/* from rac4-decomp's func_L00_007457B0, renamed */
void func_L39_006A74B8(s32 arg0) {
    func_L39_0067F168();
    func_L39_0068ADC8(arg0);
    func_L39_005C1A60(0, 0, 0x400);
}
/* localdecomp:end func_L39_006A74B8 */

INCLUDE_ASM("asm/levels", func_L39_006A74F8);
