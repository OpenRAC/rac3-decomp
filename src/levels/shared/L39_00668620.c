#include "common.h"

/* localdecomp:start func_L39_00668620 */
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D48;
extern s32 D_L39_001DAAE8;
extern E_665D48 D_L39_00337700[];
E_665D48 *func_L39_00668620(s32 a0) {
    s32 i;
    E_665D48 *p;
    for (i = 0; i < D_L39_001DAAE8; i++) {
        p = &D_L39_00337700[i];
        if (p->w2D0 == a0) return p;
    }
    return 0;
}
/* localdecomp:end func_L39_00668620 */

INCLUDE_ASM("asm/levels", func_L39_00668660);

INCLUDE_ASM("asm/levels", func_L39_00668BD8);

INCLUDE_ASM("asm/levels", func_L39_00668C90);

/* localdecomp:start func_L39_00668CD8 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern Vec4 D_L39_0025F760;
extern s32 func_003D3CB0(Vec4 *, Vec4 *, s32, s32, s32);

void func_L39_00668CD8(s32 arg0, Vec4 *arg1)
{
    Vec4 a;
    Vec4 b;

    a.q = arg1->q;
    b.q = a.q;
    b.f[2] -= 10.0f;
    a.f[2] += 10.0f;
    if (func_003D3CB0(&a, &b, 4, arg0, 0)) {
        arg1->q = D_L39_0025F760.q;
    } else {
        arg1->q = b.q;
    }
}
/* localdecomp:end func_L39_00668CD8 */

INCLUDE_ASM("asm/levels", func_L39_00668D60);

INCLUDE_ASM("asm/levels", func_L39_006692A0);

INCLUDE_ASM("asm/levels", func_L39_0066A028);

INCLUDE_ASM("asm/levels", func_L39_0066A398);

INCLUDE_ASM("asm/levels", func_L39_0066A490);

INCLUDE_ASM("asm/levels", func_L39_0066A690);

INCLUDE_ASM("asm/levels", func_L39_0066A8C8);

INCLUDE_ASM("asm/levels", func_L39_0066AA50);

INCLUDE_ASM("asm/levels", func_L39_0066ACA8);

INCLUDE_ASM("asm/levels", func_L39_0066ADA0);

INCLUDE_ASM("asm/levels", func_L39_0066AFA0);

INCLUDE_ASM("asm/levels", func_L39_0066B6F8);

INCLUDE_ASM("asm/levels", func_L39_0066B700);

INCLUDE_ASM("asm/levels", func_L39_0066B7C8);

/* localdecomp:start func_L39_0066B870 */
typedef struct { s32 id; u8 pad[44]; } S_00668F68;
extern S_00668F68 D_L39_0033B990[];

s32 func_L39_0066B870(s32 id) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if (D_L39_0033B990[i].id == id) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_0066B870 */

INCLUDE_ASM("asm/levels", func_L39_0066B8A8);

INCLUDE_ASM("asm/levels", func_L39_0066B958);

INCLUDE_ASM("asm/levels", func_L39_0066B9A0);

INCLUDE_ASM("asm/levels", func_L39_0066BA78);
