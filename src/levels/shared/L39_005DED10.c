#include "common.h"

/* localdecomp:start func_L39_005DED10 */
extern int D_001D8200_sda;
extern void func_L01_00516AA0(int, int, int);
void func_L39_005DED10(void)
{
    if (D_001D8200_sda != 0) {
        D_001D8200_sda--;
    } else {
        func_L01_00516AA0(0x80000, 1, 0);
    }
}
/* localdecomp:end func_L39_005DED10 */

/* localdecomp:start func_L39_005DED48 */
extern u8 D_L39_00243914;
extern s32 func_L39_006121B0();
void func_L39_005DED48(void) {
    D_L39_00243914 = 0;
    func_L39_006121B0(25);
}
/* localdecomp:end func_L39_005DED48 */

/* localdecomp:start func_L39_005DED68 */
extern s32 D_L39_0024C440[2];
extern s32 D_L39_0024C458;
extern void func_L39_005DE818(void);
extern void func_L39_005DED48(void);
extern u8 func_L04_0051F390[];
extern s32 func_003E6FA0(void *, void *, void *, void *, s32, s32);
void *func_L39_005DED68(s32 a0) {
    void *tbl[1];
    if (D_L39_0024C458 == 0) {
        func_003E6FA0(D_L39_0024C440, func_L39_005DE818, func_L39_005DED48, func_L04_0051F390 + 16, 0, 0);
        D_L39_0024C458 = 1;
    }
    tbl[0] = D_L39_0024C440;
    return tbl[a0];
}
/* localdecomp:end func_L39_005DED68 */

/* localdecomp:start func_L39_005DEDD8 */
extern u8 D_L39_0024392C;
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005DEDD8(void) {
    if (D_L39_0024392C != 0) {
        func_L01_00516AA0(0x60000, 1, 0);
        func_L01_00516AA0(0x60001, 1, 0);
        func_L01_00516AA0(0x60002, 1, 0);
        func_L01_00516AA0(0x60003, 1, 0);
        func_L01_00516AA0(0x60004, 1, 0);
    }
}
/* localdecomp:end func_L39_005DEDD8 */

/* localdecomp:start func_L39_005DEE58 */
extern u8 D_L39_0024392C;
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005DEE58(void) {
    if (D_L39_0024392C != 0) {
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
extern s32 D_L39_00243918[2];
extern u8 D_L39_00243928[8];
extern s32 func_L39_00610490(s32);
extern void func_L39_005DEE58(void);
extern void func_L39_005DEDD8(void);

void func_L39_005DEFC0(s32 idx, s32 a1) {
    if (func_L39_00610490(((s32 (*)(void))func_L39_005E0310)()) == 1) {
        if (D_L39_0024C4F0[idx] != 0 || D_L39_0024C4E8[idx] != 0) {
            D_L39_00243918[idx] = a1;
            D_L39_00243928[idx] = 0;
            func_L39_005DEE58();
        } else {
            func_L39_005DEDD8();
        }
    }
}
/* localdecomp:end func_L39_005DEFC0 */
