#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
extern u8 D_1A4C60[];

/* localdecomp:start func_L32_003A3E70 */
void func_L32_003A3038(void *);
void func_L32_003A3888(void *, s32);
extern s32 D_L32_001DE6E0;
extern s32 D_L32_001DE6E4;

void func_L32_003A3E70(void *arg0) {
    if ((D_L32_001DE6E4 - (*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x78))) < D_L32_001DE6E0) {
        func_L32_003A3888(arg0, D_L32_001DE6E0);
    }
    func_L32_003A3038(arg0);
}
/* localdecomp:end func_L32_003A3E70 */

/* localdecomp:start func_L32_003A3EC8 */
extern u8 D_00142732[];
extern void func_L32_003A4F18(void);
extern void func_L32_003A52A8(void *, s32);
extern void func_L32_003A45D8(void *);
extern void func_L32_003A5720(void *);
extern void func_L32_003A5B20(void *, s32);
extern void func_L32_003A5BC0(void *);
extern void func_L32_003A5C78(void *);
extern void func_L32_003A5CF8(u8 *);
extern void func_L32_003A5E48(void *);
extern void func_L32_003A6168(void *);
extern void func_L32_003A6308(void *);
extern void func_L32_003A63E0(void *);
extern void func_L32_003A6608(void *);
extern void func_L32_003A66B0(void *);
extern void func_L32_003A6920(void *);
extern void func_L32_003A6D70(void *);
extern void func_L32_003A70A0(u8 *);
extern void func_L32_003A7210(void *);
extern void func_L32_003A77D8(u8 *);
extern void func_L32_003A7948(void *);
extern void func_L32_003A7C88(u8 *);
extern void func_L32_003A7E18(void *);

void func_L32_003A3EC8(u8 *a0) {
    if (a0[0x20] == 0) {
        func_L32_003A4F18();
        func_L32_003A52A8(a0, 0x13);
    }
    func_L32_003A45D8(a0);
    func_L32_003A5720(a0);
    switch (a0[0x20]) {
    case 0x42:
        D_00142732[0] = 1;
        break;
    case 1:
        func_L32_003A5BC0(a0);
        break;
    case 2:
        func_L32_003A5C78(a0);
        break;
    case 3:
        func_L32_003A5CF8(a0);
        break;
    case 4:
        func_L32_003A5E48(a0);
        break;
    case 5:
        func_L32_003A6168(a0);
        break;
    case 6:
        func_L32_003A6308(a0);
        break;
    case 7:
        func_L32_003A63E0(a0);
        break;
    case 8:
        func_L32_003A6608(a0);
        break;
    case 9:
        func_L32_003A66B0(a0);
        break;
    case 10:
        func_L32_003A5B20(a0, 0xB);
        break;
    case 11:
        func_L32_003A6920(a0);
        break;
    case 12:
        func_L32_003A5B20(a0, 0x11);
        break;
    case 13:
        func_L32_003A6D70(a0);
        break;
    case 14:
        func_L32_003A70A0(a0);
        break;
    case 15:
    case 16:
        func_L32_003A7210(a0);
        break;
    case 17:
        func_L32_003A77D8(a0);
        break;
    case 18:
        func_L32_003A7948(a0);
        break;
    case 19:
        func_L32_003A7C88(a0);
        break;
    case 20:
        func_L32_003A5B20(a0, 0x15);
        break;
    case 21:
        func_L32_003A7E18(a0);
        break;
    case 22:
        func_L32_003A5B20(a0, 6);
        break;
    }
}
/* localdecomp:end func_L32_003A3EC8 */
