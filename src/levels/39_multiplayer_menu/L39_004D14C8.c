#include "common.h"

/* localdecomp:start func_L39_004D14C8 */
s32 func_L39_004D14C8(s32 a0) {
    return func_L39_004D1480(a0);
}
/* localdecomp:end func_L39_004D14C8 */

/* localdecomp:start func_L39_004D14E0 */
/* best: 81 diff (file flags). Retail layout = while-loop (body first, cond chain at bottom, body ends in break).
 * Differs: loop.c hoists &h0 (spilled to 0x3c), a6 spilled to 0x38, D_L39_004F48A0 lui hoisted into $fp;
 * retail only hoists D_L39_0046A090 into $s6. Plain nested-if version gives wrong block order. */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
} S_004D14E0;

typedef struct {
    u8 b[8];
} N_004D14E0;

extern N_004D14E0 D_L39_00476000 __attribute__((section(".data")));
extern u8 D_L39_0046A090[];
extern u8 D_L39_004F48A0[];
extern s32 func_L39_004D0D68(void *, void *);
extern s32 func_L39_004F4F68(s32, void *, void *);
extern s32 func_L39_004F6CA8(s32, s32, s32, s32);
extern s32 func_L39_004F6ED0(s32 *);
extern s32 func_L39_004F6FA0(s32, s32, s32);
extern s32 func_L39_004F4E58(s32 *);
extern void func_L39_004F6F38(s32 *);

s32 func_L39_004D14E0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 *a6) {
    N_004D14E0 name;
    S_004D14E0 info;
    s32 h0;
    s32 h1;
    s32 ret;

    name = D_L39_00476000;
    h0 = 0;
    h1 = 0;
    while ((ret = func_L39_004F6ED0(&h0)) == 0
           && (ret = func_L39_004F6FA0(h0, a5, a0)) == 0
           && (ret = func_L39_004F4E58(&h1)) == 0) {
        info.a = a2;
        info.b = 0;
        info.c = a3;
        info.d = a4;
        info.e = func_L39_004D0D68(D_L39_0046A090, &name);
        info.f = 0;
        ret = func_L39_004F4F68(h1, D_L39_004F48A0, &info);
        if (ret == 0) {
            ret = func_L39_004F6CA8(h1, h0, a1, 0);
        }
        break;
    }
    func_L39_004F6F38(&h0);
    *a6 = h1;
    return ret;
}
/* localdecomp:end func_L39_004D14E0 */

/* localdecomp:start func_L39_004D1630 */
typedef struct { s32 w[3]; } S12_004D1630;
typedef struct { s32 w[2]; } S8_004D1630;
extern S12_004D1630 D_L39_00476008;
extern S8_004D1630 D_L39_00476018 __attribute__((section(".data")));
extern S8_004D1630 D_L39_00476020 __attribute__((section(".data")));
extern s32 D_L39_004F71F0[];
extern s32 func_L39_004D0D68(void *, void *);

s32 func_L39_004D1630(s32 arg0, s32 *arg1) {
    S12_004D1630 a;
    S8_004D1630 b;
    S8_004D1630 c;
    s32 n;
    S8_004D1630 *pb = &b;
    S8_004D1630 *pc = &c;
    s32 r1;
    s32 r2;

    a = D_L39_00476008;
    *pb = D_L39_00476018;
    *pc = D_L39_00476020;
    n = 8;
    r1 = func_L39_004D0D68(D_L39_0046A090, pb);
    r2 = func_L39_004D0D68(D_L39_0046A090, pc);
    return func_L39_004D14E0(arg0, (s32)&a, r1, r2, (s32)&n, (s32)D_L39_004F71F0, arg1);
}
/* localdecomp:end func_L39_004D1630 */

INCLUDE_ASM("asm/levels", func_L39_004D1720);

INCLUDE_ASM("asm/levels", func_L39_004D19A0);

INCLUDE_ASM("asm/levels", func_L39_004D1B30);

INCLUDE_ASM("asm/levels", func_L39_004D1B98);
