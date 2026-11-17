#include "common.h"

/* localdecomp:start func_L01_00415D40 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L01_001D654C, 4");
__asm__(".extern D_L01_001D6550, 4");
__asm__(".extern D_L01_001D6554, 4");
__asm__(".extern D_L01_001D6558, 1");
extern s32 D_L01_001D654C;
extern s32 D_L01_001D6550;
extern s32 D_L01_001D6554;
extern u8 D_L01_001D6558;
void func_L01_00415D40(s32 a, s32 b, s32 c, u8 d) {
    D_L01_001D654C = a;
    D_L01_001D6550 = b;
    D_L01_001D6554 = c;
    D_L01_001D6558 = d;
}
/* localdecomp:end func_L01_00415D40 */

/* localdecomp:start func_L01_00415D58 */
extern s32 D_L01_001EA700[];
s32 func_L01_00415D58(void) {
    return D_L01_001EA700[0];
}
/* localdecomp:end func_L01_00415D58 */

/* localdecomp:start func_L01_00415D68 */
extern s32 D_L01_001EA748[];

s32 func_L01_00415D68(void) {
    return D_L01_001EA748[0];
}
/* localdecomp:end func_L01_00415D68 */

/* localdecomp:start func_L01_00415D78 */
extern s32 D_L01_001EA700[];
extern s32 func_003A0EA8(s32);
extern void func_0013C1D0(s32);
extern void func_003A1D00(void);
extern void func_0013B620(void);
extern void func_L01_004606A8(s32);

void func_L01_00415D78(void) {
    if (func_003A0EA8(3) == 0) {
        func_0013C1D0(77);
        func_003A1D00();
        func_0013B620();
    }
    func_L01_004606A8(0);
    D_L01_001EA700[0] = 0;
}
/* localdecomp:end func_L01_00415D78 */

/* localdecomp:start func_L01_00415DC8 */
extern s32 D_L01_001EA754[];
void func_L01_00415DC8(s32 a0) {
    D_L01_001EA754[0] = a0;
}
/* localdecomp:end func_L01_00415DC8 */

/* localdecomp:start func_L01_00415DD8 */
typedef struct {
    u8 pad0[0x40];
    s32 x40;
    u8 pad44[0x10];
    s32 x54;
    s32 x58;
    s32 a5C[4];
    s32 a6C[4];
    s16 x7C;
    s16 x7E;
    s32 x80;
    u8 pad84[4];
    s32 x88;
} S_00415DD8;
extern s32 D_001D545C;
extern s32 D_L01_001F3F40[];
__asm__(".extern D_L01_001DFB90, 4");
extern s32 D_L01_001DFB90;
__asm__(".extern D_L02_001D655C, 4");
extern s32 D_L02_001D655C;
extern s32 D_001425AC[];
extern S_00415DD8 D_L01_001EA6C0;
extern s32 D_L01_001D6694;
extern s32 func_L01_0045A6F0(void);
extern void func_0013C1A0(s32);
extern s32 func_L01_00418C50(void);
extern void func_L01_0045F328(s32);
extern void func_L01_004AAD58(s32, s32, s32);
extern void func_L01_00418618(void);

void func_L01_00415DD8(s32 a0, s32 a1) {
    s32 i;
    S_00415DD8 *s;
    s32 r;
    if ((D_001D545C == 8 && D_L01_001F3F40[0] == 1) || (D_001D545C == 0x13 && D_L01_001F3F40[0] == 0)) {
        D_L01_001DFB90 = 2;
        func_L01_00415DC8(2);
    }
    if (D_001D545C == 0x16 || D_001D545C == 0x17) {
        D_L01_001DFB90 = 3;
        func_L01_00415DC8(3);
    }
    D_L02_001D655C = a0;
    if (a0 == 5) {
        D_L01_001EA6C0.x80 = D_001425AC[0];
    } else {
        D_L01_001EA6C0.x80 = 0;
    }
    s = &D_L01_001EA6C0;
    s->x54 = a1;
    s->x7E = a0 == 0xC;
    s->x40 = a0;
    s->x7C = 0;
    s->x58 = 0;
    if (func_L01_0045A6F0() != 3 && func_L01_0045A6F0() != 0x12) {
        r = 1;
    } else {
        r = 0;
    }
    s->x88 = r;
    if (D_L01_001D6694 != 3) {
        func_0013C1A0(0x4D);
        if (func_L01_00418C50() == 0 && a0 != 0xC) {
            func_L01_0045F328(0);
        }
    }
    for (i = 0; i < 4; i++) {
        D_L01_001EA6C0.a5C[i] = 0;
        D_L01_001EA6C0.a6C[i] = 0;
    }
    if (a0 == 10) {
        func_L01_004AAD58(0x12, 0, 0);
    }
    func_L01_00418618();
}
/* localdecomp:end func_L01_00415DD8 */
