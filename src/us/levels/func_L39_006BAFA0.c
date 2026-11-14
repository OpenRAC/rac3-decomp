#include "common.h"

/* NTSC-U counterpart of func_L39_006BDAB8 (src/levels/39_multiplayer_menu/L39_006BBB38.c) */
extern u8 *D_L39_0024D860;
extern u8 *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006D95F0(void *, s32);
void func_L39_006D8470(void *);
void func_L04_0051FB50(void *);

/* localdecomp:start func_L39_006BAFA0 */
__asm__(".extern D_L39_0024D860, 16");
extern u8 *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long arg0, long arg1);
extern void func_00195500(void);
s32 func_L39_006D8DF0(void *, s32, s32, s32, s32);

s32 func_L39_006BAFA0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *a = *(u8 **)(D_L39_0024D860 + 0x4C);
    u8 *b = *(u8 **)(D_L39_0024D860 + 0x70);
    s32 ok = 1;
    s32 start;
    s32 tries;

    a[0x168] = 0;
    b[0x10] = 0;
    start = func_00130760(func_0012DCB0(), 0x24000);
    (void)&start;
    while (a[0x199] && b[0x1C] && a[0x15D]) {
        func_00195500();
        if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
            ok = 0;
            goto end;
        }
    }
    end:;
    if (ok) {
        if (*(s32 *)(arg0 + 0x318)) {
            func_L04_0051FB50(a);
            *(s32 *)(arg0 + 0x318) = 0;
        }
        ok = func_L39_006D95F0(a, arg3);
    }
    for (tries = 2; tries != 0; tries--) {
        if (!ok) {
            continue;
        }
        ok = ((s32 (*)(void *))func_L39_006D8470)(a);
        if (!ok) {
            continue;
        }
        start = func_00130760(func_0012DCB0(), 0x24000);
        while (a[0x199]) {
            func_00195500();
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start >= 15001) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ok = func_L39_006D8DF0(a, arg3, arg2, -1, 0);
            if (ok) {
                break;
            }
        }
    }
    func_L04_0051FB50(a);
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
/* localdecomp:end func_L39_006BAFA0 */
