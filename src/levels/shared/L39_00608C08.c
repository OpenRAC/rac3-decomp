#include "common.h"
#include "cpu.h"

/* localdecomp:start func_L39_00608C08 */
extern u32 D_L39_0024CC18[2];
extern s32 D_001FC454[];
extern void func_003A1028(u32, s32);

void func_L39_00608C08(void *a0, int a1, int a2, int a3, int t0)
{
    u8 *p = (u8 *)a0;
    int rows = a3 >> 4;
    int cols = t0 >> 4;
    int i, j;
    u32 *q;
    int off;
    unsigned long c00, c10, c18, c28, c38, c40;

    *(unsigned long *)(p + 0x00) = 0x10000003;
    *(unsigned long *)(p + 0x08) = 0;
    *(unsigned long *)(p + 0x10) = 0x1000000000000002UL;
    *(unsigned long *)(p + 0x18) = 0xE;
    *(unsigned long *)(p + 0x20) = ((unsigned long)((long)D_001FC454[0] >> 8) << 32) | 0x8000000000000UL;
    *(unsigned long *)(p + 0x28) = 0x50;
    *(unsigned long *)(p + 0x30) = 0x1000000010UL;
    *(unsigned long *)(p + 0x38) = 0x52;

    p += 0x40;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            c00 = 0x10000004;
            c10 = 0x1000000000000002UL;
            c18 = 0xE;
            c28 = 0x51;
            c38 = 0x53;
            c40 = 0x0800000000000040UL;
            *(unsigned long *)(p + 0x00) = c00;
            *(unsigned long *)(p + 0x08) = 0;
            *(unsigned long *)(p + 0x10) = c10;
            *(unsigned long *)(p + 0x18) = c18;
            *(unsigned long *)(p + 0x20) = (((unsigned long)(i << 4)) << 32) | (((unsigned long)(j << 4)) << 48);
            *(unsigned long *)(p + 0x28) = c28;
            *(unsigned long *)(p + 0x30) = 0;
            *(unsigned long *)(p + 0x38) = c38;
            *(unsigned long *)(p + 0x40) = c40;
            *(unsigned long *)(p + 0x48) = 0;
            *(u32 *)(p + 0x50) = 0x30000040;
            *(u32 *)(p + 0x54) = a1 & 0x0FFFFFFF;
            *(unsigned long *)(p + 0x58) = 0;
            a1 += 0x400;
            p += 0x60;
        }
    }

    off = a2 << 2;
    *(u32 *)(p + 0x00) = 0x20000000;
    q = (u32 *)((u8 *)D_L39_0024CC18 + off);
    *(u32 *)(p + 0x04) = *q;
    *(u32 *)(p + 0x08) = 0;
    *(u32 *)(p + 0x0C) = 0;
    func_003A1028((*q & 0x0FFFFFFF) | 0x20000000, 1);
}
/* localdecomp:end func_L39_00608C08 */

/* localdecomp:start func_L39_00608DB0 */
extern s32 D_L39_002413A0;
__asm__(".extern D_L39_002413A0, 16");
extern volatile s32 D_L39_0024CC24;
__asm__(".extern D_L39_0024CC24, 16");
extern volatile s32 D_L39_0024CC28;
__asm__(".extern D_L39_0024CC28, 16");
extern volatile s32 D_L39_0024CC2C;
__asm__(".extern D_L39_0024CC2C, 16");
extern volatile s32 D_L39_0024CC30;
__asm__(".extern D_L39_0024CC30, 16");
extern volatile s32 D_L39_0024CC34;
__asm__(".extern D_L39_0024CC34, 16");
extern volatile s32 D_L39_0024CC38;
__asm__(".extern D_L39_0024CC38, 16");
extern s32 D_L39_0024CBE0;
extern u32 *func_0013AB50(s32);
extern void func_0013AE38(u32 *, s32 *);
extern s32 func_001331A0(int, int);
typedef struct { s32 state; u8 pad4[0x3C]; u8 buf0[0x13F00]; u8 buf1[0x13F00]; } Sw_00608DB0;
extern Sw_00608DB0 *func_003B2D40(s32);

s32 func_L39_00608DB0(void)
{
    u32 *t = func_0013AB50(2);
    Sw_00608DB0 *s;
    s32 v;

    D_L39_0024CC34 = D_L39_002413A0 ? D_L39_0024CC34 ^ 1 : (*(volatile unsigned long *)0x12001000 >> 13) & 1;
    if (D_L39_0024CC28 != 0) {
        D_L39_0024CC2C++;
        D_L39_0024CC38 = func_001331A0(1, 0);
        if (D_L39_0024CC38 == 0) {
            s = func_003B2D40(D_L39_0024CBE0);
            if (s == 0) {
                CpuSync();
                CpuEnableInt();
                return 0;
            }
            if (D_L39_0024CC34 == 0 && s->state == 2) {
                func_001331A0(0, 0);
                func_003A1028((D_L39_0024CC18[0] & 0x0FFFFFFF) | 0x20000000, 0);
                func_0013AE38(t, (s32 *)s->buf0);
                s->state = 1;
                D_L39_0024CC24++;
            } else if (D_L39_0024CC34 == 1 && s->state == 1) {
                func_001331A0(0, 0);
                func_003A1028((D_L39_0024CC18[1] & 0x0FFFFFFF) | 0x20000000, 0);
                func_0013AE38(t, (s32 *)s->buf1);
                s->state = 0;
                D_L39_0024CC24++;
                D_L39_0024CC30 = 1;
            }
        }
    }
    CpuSync();
    CpuEnableInt();
    return 0;
}
/* localdecomp:end func_L39_00608DB0 */
