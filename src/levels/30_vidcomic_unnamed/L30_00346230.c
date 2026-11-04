#include "common.h"

typedef struct S_L30_00346278_inner {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    s32 f20;
} S_L30_00346278_inner;
typedef struct S_L30_00346278 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x4C];
    S_L30_00346278_inner *f68;
} S_L30_00346278;

/* localdecomp:start func_L30_00346230 */
void func_L30_00346278();
void func_L30_00346320(void *);
void func_L30_00346600(void *);

void func_L30_00346230(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        func_L30_00346278();
    }
    func_L30_00346600(arg0);
    func_L30_00346320(arg0);
}
/* localdecomp:end func_L30_00346230 */

/* localdecomp:start func_L30_00346278 */
void func_L30_00346278(S_L30_00346278 *p) {
    s32 six = 6;
    S_L30_00346278_inner *s = p->f68;
    s->f4 = (s->f4 * 5 + 2) / six;
    s->f8 = (s->f8 * 5 + 2) / six;
    s->fC = (s->fC * 5 + 2) / six;
    s->f10 = (s->f10 * 5 + 2) / six;
    s->f14 = (s->f14 * 5 + 2) / six;
    s->f1C = p->f18;
    s->f20 = -1;
}
/* localdecomp:end func_L30_00346278 */

INCLUDE_ASM("asm/levels", func_L30_00346320);

INCLUDE_ASM("asm/levels", func_L30_00346600);

INCLUDE_ASM("asm/levels", func_L30_003467C0);
