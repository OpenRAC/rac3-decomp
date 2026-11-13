#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_006CC158(void *, s32);

/* localdecomp:start func_L39_006BBB38 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_0024D764, 16");
extern u8 D_L39_0024D764;
extern u8 *D_L39_0024D760;
void func_L39_006CC120(void *);
void func_L39_006CC930(void *);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
void func_L39_0068B2F8(void *, s32, s32);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);
void func_L39_006CC158(void *, s32);

void func_L39_006BBB38(u8 *arg0) {
    u8 buf[0x1E0];

    D_L39_0024D764 = 0;
    *(s32 *)(arg0 + 0x318) = 0;
    func_L39_006CC120(buf);
    func_L39_006CC930(buf);
    *(u8 *)(*(u8 **)(D_L39_0024D760 + 0x4C) + 0x168) = 0;
    *(u8 *)(*(u8 **)(D_L39_0024D760 + 0x70) + 0x10) = 0;
    func_L39_0068A2D0(arg0, 0, 3, 3, 0.0f, 0.0f);
    func_L39_0068B2F8(arg0, 4, 0);
    func_L39_0067F168();
    func_L39_0068ADC8(arg0);
    func_L39_006CC158(buf, 2);
}
/* localdecomp:end func_L39_006BBB38 */

/* localdecomp:start func_L39_006BBBE0 */
long func_L39_006BBBE0(void *arg0) {
    long r = 0;

    if (*(s32 *)((u8 *)arg0 + 0x2A8) != -1) {
        s32 t = *(s32 *)((u8 *)arg0 + 0x2F0) != 0;
        r = t;
    }
    return r;
}
/* localdecomp:end func_L39_006BBBE0 */

INCLUDE_ASM("asm/levels", func_L39_006BBC08);

INCLUDE_ASM("asm/levels", func_L39_006BBD80);

INCLUDE_ASM("asm/levels", func_L39_006BD290);

INCLUDE_ASM("asm/levels", func_L39_006BD408);

INCLUDE_ASM("asm/levels", func_L39_006BD788);

/* localdecomp:start func_L39_006BD988 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern u8 D_001A5CD0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006DC148(void *, s32);
void func_L39_006DAFC8(void *);
s32 func_L39_006DBD58(void *, s32, void *, void *);
void func_L04_00523E58(void *);

void func_L39_006BD988(u8 *arg0) {
    u8 *g = D_001A5CD0;
    u8 *s1 = *(u8 **)(D_L39_0024D760 + 0x4C);
    u8 *s2 = *(u8 **)(D_L39_0024D760 + 0x70);

    if ((u32)(*(s32 *)(g + 0x7C) - 0x28) < 0x3C) {
        if (func_L39_006BBBE0(arg0)) {
            if (*(s32 *)(arg0 + 0x318) == 0
                && (s32)func_00130760(func_0012DCB0(), 0x24000) - *(s32 *)(s1 + 0x1A0) >= 0x3A99
                && s1[0x199] == 0 && s2[0x1C] == 0 && s1[0x15D] == 0) {
                *(s32 *)(arg0 + 0x318) = 1;
                if (func_L39_006DC148(s1, *(s32 *)(g + 0x7C))) {
                    func_L39_006DAFC8(s1);
                } else {
                    *(s32 *)(arg0 + 0x318) = 0;
                }
            } else if (s1[0x199] == 0 && *(s32 *)(arg0 + 0x318) != 0) {
                *(s32 *)(arg0 + 0x2F8) = func_L39_006DBD58(s1, *(s32 *)(arg0 + 0x2A8), arg0 + 0x2FC, arg0 + 0x300);
                func_L04_00523E58(s1);
                *(s32 *)(arg0 + 0x318) = 0;
            }
        }
    }
}
/* localdecomp:end func_L39_006BD988 */

/* localdecomp:start func_L39_006BDAB8 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long arg0, long arg1);
extern void func_00195410(void);
s32 func_L39_006DB948(void *, s32, s32, s32, s32);

s32 func_L39_006BDAB8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *a = *(u8 **)(D_L39_0024D760 + 0x4C);
    u8 *b = *(u8 **)(D_L39_0024D760 + 0x70);
    s32 ok = 1;
    s32 start;
    s32 tries;

    a[0x168] = 0;
    b[0x10] = 0;
    start = func_00130760(func_0012DCB0(), 0x24000);
    (void)&start;
    while (a[0x199] && b[0x1C] && a[0x15D]) {
        func_00195410();
        if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
            ok = 0;
            goto end;
        }
    }
    end:;
    if (ok) {
        if (*(s32 *)(arg0 + 0x318)) {
            func_L04_00523E58(a);
            *(s32 *)(arg0 + 0x318) = 0;
        }
        ok = func_L39_006DC148(a, arg3);
    }
    for (tries = 2; tries != 0; tries--) {
        if (!ok) {
            continue;
        }
        ok = ((s32 (*)(void *))func_L39_006DAFC8)(a);
        if (!ok) {
            continue;
        }
        start = func_00130760(func_0012DCB0(), 0x24000);
        while (a[0x199]) {
            func_00195410();
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start >= 15001) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ok = func_L39_006DB948(a, arg3, arg2, -1, 0);
            if (ok) {
                break;
            }
        }
    }
    func_L04_00523E58(a);
{
    s32 lim = 10000;
    u8 on = 1;
    a[0x168] = on;
    *(s32 *)(a + 0x16C) = lim;
    b[0x10] = on;
    *(s32 *)(b + 0x14) = lim;
}
    return ok;
}
/* localdecomp:end func_L39_006BDAB8 */

/* localdecomp:start func_L39_006BDCC8 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern void func_L39_006BD408(s32);

/* from rac4-decomp's func_01EEFA5C */
s32 func_L39_006BDCC8(void) {
    func_L39_006BD408(D_L39_00247914[0xE0 / 4]);
    return 1;
}
/* localdecomp:end func_L39_006BDCC8 */
