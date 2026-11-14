#include "common.h"

/* localdecomp:start func_L39_004D7508 */
extern void func_L39_004B4AA0(void *);
extern void func_L39_004D73E0(void *, void *, void *);
extern void func_L39_004B4420(void *);
s32 func_L39_004D7508(void *a, void *b, void *c) {
    func_L39_004B4AA0(c);
    func_L39_004D73E0(a, b, c);
    func_L39_004B4420((u8 *)c + 4);
    return 0x28;
}
/* localdecomp:end func_L39_004D7508 */

/* localdecomp:start func_L39_004D7568 */
extern u8 D_L39_004543E4[];
extern s32 D_L39_00464668 __attribute__((section(".data")));
extern s32 func_L39_004B40C8(u8 *);
extern s32 func_L39_004B4108(u8 *);
extern s32 func_L39_004CCF68(u8 *, u8 *);
extern s32 func_L39_004CDC00(void);
extern s32 func_L39_004B4620(u8 *);
extern s32 func_L39_004CD8E8(u8 *);
extern s32 func_L39_004CDA00(u8 *);
s32 func_L39_004D7568(u8 *buf) {
    u8 *p;
    u8 *k;
    u8 *src;
    s32 r;
    u32 i;
    u8 tmp[16];

    p = buf + func_L39_004B40C8(buf);
    p += func_L39_004B4108(p);
    k = D_L39_004543E4; src = k + 0x10000; r = func_L39_004CCF68(k, src);
    if (r < 0) return r;
    for (i = 0; i < 256; i++) {
        p[i] = src[i];
    }
    p += r;
    r = func_L39_004CDC00();
    if (r < 0) {
        tmp[0] = 0;
        return func_L39_004B4620(tmp);
    }
    if (r > 0 && !(D_L39_00464668 & 1)) {
        r = func_L39_004CD8E8(p);
        if (r < 0) return r;
        p += r;
        r = func_L39_004CDA00(p);
        if (r < 0) return r;
        p += r;
    }
    return p - buf;
}
/* localdecomp:end func_L39_004D7568 */

INCLUDE_ASM("asm/levels", func_L39_004D7658);

/* localdecomp:start func_L39_004D76B0 */
extern s32 func_L39_004B4BA0(u8 *);
extern s32 func_L39_004B4C88(u8 *, u8 *);

s32 func_L39_004D76B0(u8 *a0, u8 *a1)
{
    u8 *p = a0;

    p += func_L39_004B4BA0(p);
    p += func_L39_004B4C88(p, a1);
    return p - a0;
}
/* localdecomp:end func_L39_004D76B0 */
