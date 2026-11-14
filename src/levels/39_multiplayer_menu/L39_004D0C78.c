#include "common.h"

/* declared by functions of L39_004CCE58.c, which this file was cut from */
extern unsigned long D_L39_0046A088[];

/* localdecomp:start func_L39_004D0C78 */
extern unsigned long func_1306F8(unsigned long, unsigned long);

/* newlib rand() */
s32 func_L39_004D0C78(void) {
    D_L39_0046A088[0] = func_1306F8(D_L39_0046A088[0], 0x5851F42D4C957F2DUL) + 1;
    return (D_L39_0046A088[0] >> 32) & 0x7FFFFFFF;
}
/* localdecomp:end func_L39_004D0C78 */

INCLUDE_ASM("asm/levels", func_L39_004D0CE0);

/* localdecomp:start func_L39_004D0D68 */
/* from rac4-decomp's func_003F6470 */
u8 *func_L39_004D0D68(u8 *arg0, u8 *arg1) {
    s32 i;

    for (i = 0; i < 8; i++) {
        arg1[i] ^= arg0[i];
    }
    return arg1;
}
/* localdecomp:end func_L39_004D0D68 */

/* localdecomp:start func_L39_004D0DA8 */
/* best: 81 diff with this while(...){...; break;} form (if form also far). Retail lays the body (key hash, info struct, 4F4F68, 4F6A80) before the three checks (6ED0, 6FA0, 4E58) and enters with "b" to the checks, i.e. a rotated loop, and hoists only &D_L39_0046A090 into $s6; this loop form also hoists &h, arg6 and D_L39_004F48A0. Args: a0->s2, a1->s7, a2..t0->s3..s5, arg5->s1, arg6->fp. */
typedef struct { s32 w[2]; } S8_004D0DA8;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
} S_004D0DA8;
extern S8_004D0DA8 D_L39_00475F78 __attribute__((section(".data")));
extern s32 D_L39_0046A090[];
extern s32 D_L39_004F48A0[];
extern s32 func_L39_004F6ED0(s32 *);
extern s32 func_L39_004F6FA0(s32, void *, s32);
extern s32 func_L39_004F4E58(s32 *);
extern s32 func_L39_004F4F68(s32, void *, S_004D0DA8 *);
extern s32 func_L39_004F6A80(s32, s32, void *, s32);
extern void func_L39_004F6F38(s32 *);

s32 func_L39_004D0DA8(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 *arg4, void *arg5, s32 *arg6) {
    S8_004D0DA8 key = D_L39_00475F78;
    S_004D0DA8 info;
    s32 h = 0;
    s32 ctx = 0;
    s32 ret;

    while ((ret = func_L39_004F6ED0(&h)) == 0 && (ret = func_L39_004F6FA0(h, arg5, arg0)) == 0
           && (ret = func_L39_004F4E58(&ctx)) == 0) {
        info.a = arg2;
        info.b = 0;
        info.c = arg3;
        info.d = (s32)arg4;
        info.e = (s32)func_L39_004D0D68((u8 *)D_L39_0046A090, (u8 *)&key);
        info.f = 0;
        ret = func_L39_004F4F68(ctx, D_L39_004F48A0, &info);
        if (ret == 0) {
            ret = func_L39_004F6A80(ctx, h, arg1, 0);
        }
        break;
    }
    func_L39_004F6F38(&h);
    *arg6 = ctx;
    return ret;
}
/* localdecomp:end func_L39_004D0DA8 */

/* localdecomp:start func_L39_004D0EF8 */
typedef struct { void *p; void *q; s32 r; } S12_004D0EF8;
extern S12_004D0EF8 D_L39_00475F80;
extern u8 D_L39_00475F90[];
extern u8 D_L39_00475F98[];
extern s32 D_L39_0046A090[];
extern s32 D_L39_004F71F0[];
extern s32 func_L39_004D0DA8(s32, void *, s32, s32, s32 *, void *, s32 *);

s32 func_L39_004D0EF8(s32 arg0, s32 *arg1) {
    S12_004D0EF8 a;
    u8 b[8];
    u8 c[8];
    s32 n;
    s32 r1;
    s32 r2;

    a = D_L39_00475F80;
    __builtin_memcpy(b, D_L39_00475F90, 8);
    __builtin_memcpy(c, D_L39_00475F98, 8);
    n = 8;
    r1 = (s32)func_L39_004D0D68((u8 *)D_L39_0046A090, b);
    r2 = (s32)func_L39_004D0D68((u8 *)D_L39_0046A090, c);
    return func_L39_004D0DA8(arg0, &a, r1, r2, &n, D_L39_004F71F0, arg1);
}
/* localdecomp:end func_L39_004D0EF8 */

INCLUDE_ASM("asm/levels", func_L39_004D0FE8);

INCLUDE_ASM("asm/levels", func_L39_004D10D8);

INCLUDE_ASM("asm/levels", func_L39_004D1268);

INCLUDE_ASM("asm/levels", func_L39_004D13F8);

LINKER_REMNANT("asm/levels", func_L39_004D1458);

INCLUDE_ASM("asm/levels", func_L39_004D1460);
