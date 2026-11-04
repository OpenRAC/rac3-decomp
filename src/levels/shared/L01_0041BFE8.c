#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 x24;
    u8 pad28[0x90 - 0x28];
} Entry_0041BFE8;

/* localdecomp:start func_L01_0041BFE8 */
extern Entry_0041BFE8 D_L01_002E60D0[];
extern s32 D_L01_001DFD00;
extern s32 D_L01_001DFD04;
extern u8 *D_L01_001DFD78;
extern u8 *D_L01_001DFD7C;
extern u8 *D_L01_001DFD80;
extern s32 D_L01_001DFD84;
extern s32 D_L01_001DFD8C;
extern s32 D_L01_001DFD90;
extern s32 D_L01_001DFD94;
extern s32 D_L01_001DFD98;
extern s32 D_L01_001DFD9C;
extern char D_L01_001D68A8[];
extern void func_00393348(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003932C0(s32, s32, char *, s32);
extern void func_0038CBA0(void *, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_00393B58(s32);

void func_L01_0041BFE8(void)
{
    int *base = (int *)D_L01_002E60D0;
    int *q;
    int i = 0;

    D_L01_001DFD00 = 0;
    D_L01_001DFD04 = 0;
    do {
        q = base + 9;
        q[16] = -1;
        q[-1] = 0x10000;
        func_00393348(i, 0xffff, 0, 0, 0, 0, 1);
        i++;
        q[22] = 0;
        q[18] = -6;
        q[-8] = 0;
        q[0] = 0;
        base = q + 27;
    } while (i < 13);
    if (D_L01_001DFD78 == 0) {
        char *file = D_L01_001D68A8;
        D_L01_001DFD78 = (u8 *)func_003932C0(0, 0, file, 0x17E);
        D_L01_001DFD84 = func_003932C0(0, 0, file, 0x17F);
        D_L01_001DFD8C = func_003932C0(0, 0, file, 0x180);
    }
    D_L01_001DFD7C = D_L01_001DFD78;
    D_L01_001DFD80 = D_L01_001DFD78;
    if (D_L01_001DFD78 != 0) {
        func_0038CBA0(D_L01_001DFD78, 0);
        D_L01_001DFD90 = 0;
        D_L01_001DFD94 = 0;
        D_L01_001DFD98 = D_L01_001DFD8C;
        D_L01_001DFD9C = D_L01_001DFD8C;
        func_0038CB78((void *)D_L01_001DFD8C, 0, 0);
    }
    D_L01_001DFD78[0x20] = 0xFF;
    func_00393B58(0);
}
/* localdecomp:end func_L01_0041BFE8 */

/* localdecomp:start func_L01_0041C170 */
extern u8 *D_L01_001DFD18;
extern s32 D_L01_001DFD40[];
#define D_L01_001DFD40 (D_L01_001DFD40[0])
extern s32 D_L01_001DFD48[];
#define D_L01_001DFD48 (D_L01_001DFD48[0])
extern s32 D_L01_001DFD4C[];
#define D_L01_001DFD4C (D_L01_001DFD4C[0])
extern s32 D_L01_001DFD50[];
#define D_L01_001DFD50 (D_L01_001DFD50[0])

extern void func_L01_004B11E0(void *, s32, s32, s32, s32);
extern void func_003A0760(void *, u8 *);
extern void func_00392FD0(s32, u8 *);

void func_L01_0041C170(s32 arg0, u8 *arg1, void *arg2) {
    if (*(s32 *)(D_L01_001DFD18 + 84) != 0) {
        s32 n = *(s32 *)(D_L01_001DFD18 + 84);
        func_L01_004B11E0(arg2, *(s32 *)(D_L01_001DFD18 + 148), 0, D_L01_001DFD40 / 16, 0);
        func_003A0760(arg2, arg1);
        func_00392FD0(0, arg1);
        arg1 += n;
    }
    if (*(s32 *)(D_L01_001DFD18 + 92) != 0) {
        s32 n = *(s32 *)(D_L01_001DFD18 + 92);
        func_L01_004B11E0(arg2, *(s32 *)(D_L01_001DFD18 + 156), 0, D_L01_001DFD48 / 16, 0);
        func_003A0760(arg2, arg1);
        func_00392FD0(2, arg1);
        arg1 += n;
    }
    if (arg0 == 0 || arg0 == 2) {
        if (*(s32 *)(D_L01_001DFD18 + 96) != 0) {
            s32 n = *(s32 *)(D_L01_001DFD18 + 96);
            func_L01_004B11E0(arg2, *(s32 *)(D_L01_001DFD18 + 160), 0, D_L01_001DFD4C / 16, 0);
            func_003A0760(arg2, arg1);
            func_00392FD0(3, arg1);
            arg1 += n;
        }
    }
    if ((u32)(arg0 - 1) < 2) {
        u8 *p = *(u8 * volatile *)&D_L01_001DFD18;
        if (*(s32 *)(p + 100) != 0) {
            func_L01_004B11E0(arg2, *(s32 *)(p + 164), 0, D_L01_001DFD50 / 16, 0);
            func_003A0760(arg2, arg1);
            func_00392FD0(4, arg1);
        }
    }
}
/* localdecomp:end func_L01_0041C170 */
