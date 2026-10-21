#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005DED10);

/* localdecomp:start func_L39_005DED48 */
extern u8 D_L39_001D8204;
extern s32 func_L39_006121B0();
void func_L39_005DED48(void) {
    D_L39_001D8204 = 0;
    func_L39_006121B0(25);
}
/* localdecomp:end func_L39_005DED48 */

/* localdecomp:start func_L39_005DED68 */
extern s32 D_L39_001E0D30[2];
extern s32 D_L39_001E0D48;
extern void func_L39_005DE818(void);
extern void func_L39_005DED48(void);
extern u8 func_L04_0051F390[];
extern s32 func_003E6FA0(void *, void *, void *, void *, s32, s32);
void *func_L39_005DED68(s32 a0) {
    void *tbl[1];
    if (D_L39_001E0D48 == 0) {
        func_003E6FA0(D_L39_001E0D30, func_L39_005DE818, func_L39_005DED48, func_L04_0051F390 + 16, 0, 0);
        D_L39_001E0D48 = 1;
    }
    tbl[0] = D_L39_001E0D30;
    return tbl[a0];
}
/* localdecomp:end func_L39_005DED68 */

/* localdecomp:start func_L39_005DEDD8 */
extern u8 D_L39_001D821C;
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005DEDD8(void) {
    if (D_L39_001D821C != 0) {
        func_L01_00516AA0(0x60000, 1, 0);
        func_L01_00516AA0(0x60001, 1, 0);
        func_L01_00516AA0(0x60002, 1, 0);
        func_L01_00516AA0(0x60003, 1, 0);
        func_L01_00516AA0(0x60004, 1, 0);
    }
}
/* localdecomp:end func_L39_005DEDD8 */

/* localdecomp:start func_L39_005DEE58 */
extern u8 D_L39_001D821C;
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005DEE58(void) {
    if (D_L39_001D821C != 0) {
        func_L01_00516AA0(0x60000, 1, 1);
        func_L01_00516AA0(0x60001, 1, 1);
        func_L01_00516AA0(0x60002, 1, 1);
        func_L01_00516AA0(0x60003, 1, 1);
        func_L01_00516AA0(0x60004, 1, 1);
    }
}
/* localdecomp:end func_L39_005DEE58 */

/* localdecomp:start func_L39_005DEED8 */
extern u8 D_L39_0024C4E8[];
extern u8 D_L39_0024C4F0[];

s32 func_L39_005DEED8(s32 a0) {
    s32 r = 0;
    if (D_L39_0024C4E8[a0] != 0 || D_L39_0024C4F0[a0] != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_005DEED8 */

INCLUDE_ASM("asm/levels", func_L39_005DEF18);

/* localdecomp:start func_L39_005DEF78 */
extern u8 D_L39_0024C4E8[];
void func_L39_005DEF78(s32 i, u8 v) {
    D_L39_0024C4E8[i] = v;
}
/* localdecomp:end func_L39_005DEF78 */

/* localdecomp:start func_L39_005DEF90 */
extern u8 D_L39_0024C4F0[];
u8 func_L39_005DEF90(s32 i) {
    return D_L39_0024C4F0[i];
}
/* localdecomp:end func_L39_005DEF90 */

/* localdecomp:start func_L39_005DEFA8 */
extern u8 D_L39_0024C4F0[];
void func_L39_005DEFA8(s32 i, u8 v) {
    D_L39_0024C4F0[i] = v;
}
/* localdecomp:end func_L39_005DEFA8 */

/* localdecomp:start func_L39_005DEFC0 */
extern s32 func_L39_005E0310(s32 idx);
extern u8 D_L39_0024C4F0[];
extern u8 D_L39_0024C4E8[];
extern s32 D_L39_001D8208[2];
extern u8 D_L39_001D8218[8];
extern s32 func_L39_00610490(s32);
extern void func_L39_005DEE58(void);
extern void func_L39_005DEDD8(void);

void func_L39_005DEFC0(s32 idx, s32 a1) {
    if (func_L39_00610490(((s32 (*)(void))func_L39_005E0310)()) == 1) {
        if (D_L39_0024C4F0[idx] != 0 || D_L39_0024C4E8[idx] != 0) {
            D_L39_001D8208[idx] = a1;
            D_L39_001D8218[idx] = 0;
            func_L39_005DEE58();
        } else {
            func_L39_005DEDD8();
        }
    }
}
/* localdecomp:end func_L39_005DEFC0 */

INCLUDE_ASM("asm/levels", func_L39_005DF060);

INCLUDE_ASM("asm/levels", func_L39_005DF510);

INCLUDE_ASM("asm/levels", func_L39_005DF8F8);

/* localdecomp:start func_L39_005E02F0 */
extern u8 D_L39_001D821C;
extern s32 func_L39_006121B0();
void func_L39_005E02F0(void) {
    D_L39_001D821C = 0;
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
extern s32 D_L39_001E0D68;
extern s32 D_L39_001E0D88;
extern s32 D_L39_001E0DA8;
extern s32 D_L39_001E0DC8;
extern s32 D_L39_001E0D50[2];
extern s32 D_L39_001E0D70[2];
extern s32 D_L39_001E0D90[2];
extern s32 D_L39_001E0DB0[2];
extern V16_3DF9E0 D_L39_00243940[];
s32 func_L39_005E0310(s32 idx) {
    V16_3DF9E0 v;
    if (D_L39_001E0D68 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_001E0D50, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_001E0D68 = 1;
    }
    if (D_L39_001E0D88 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_001E0D70, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_001E0D88 = 1;
    }
    if (D_L39_001E0DA8 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_001E0D90, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_001E0DA8 = 1;
    }
    if (D_L39_001E0DC8 == 0) {
        ((s32 (*)(s32 *, s32, s32, s32, s32, s32))func_003E6FA0)(D_L39_001E0DB0, (s32)func_L39_005DF060, (s32)func_L39_005E02F0, (s32)func_L39_005DF8F8, 0, 0);
        D_L39_001E0DC8 = 1;
    }
    v = D_L39_00243940[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L39_005E0310 */
