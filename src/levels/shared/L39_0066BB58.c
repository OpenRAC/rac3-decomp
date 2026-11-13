#include "common.h"

/* localdecomp:start func_L39_0066BB58 */
typedef struct N_0066BB58 N_0066BB58;
struct N_0066BB58 {
    s32 pad0[2];
    s32 f8;
    s32 fC;
    u8 pad10[0x74];
    N_0066BB58 *f84;
};
extern N_0066BB58 *D_L39_0024CF64;
extern void func_L39_0066C3C8(N_0066BB58 *, N_0066BB58 **);
void func_L39_0066BB58(s32 id) {
    N_0066BB58 *p = D_L39_0024CF64;
    while (p != 0) {
        s32 *q = &p->f8;
        if (*q == 0 && q[1] == id) {
            func_L39_0066C3C8(p, &D_L39_0024CF64);
            return;
        }
        p = p->f84;
    }
}
/* localdecomp:end func_L39_0066BB58 */

INCLUDE_ASM("asm/levels", func_L39_0066BBB8);

/* localdecomp:start func_L39_0066BD80 */
extern u8 D_1A5CD0[];
extern s32 *D_L39_0024CF6C;
extern s32 *D_L39_0024CF6C_b;
extern s32 func_14AD08();
extern void func_L39_0066C110(s32, s32, s32, s32 *);
extern s32 *func_L39_0066C310(s32 *);

void func_L39_0066BD80(s32 n) {
    u8 *b;
    s32 *q;
    s32 i;

    q = D_L39_0024CF6C;
    i = 0;
    if (q != 0) {
        b = D_1A5CD0;
        do {
            if (*(s32 *)(b + 0x170) == 0) {
                func_14AD08(b[0x7D4] | 0x50, *(s32 *)(b + 4), -1, *(s32 *)0x2405C4, q[0], q);
            }
            func_L39_0066C110(0, 0, 0, q);
            i++;
            q = func_L39_0066C310(q);
            if (i >= n) {
                D_L39_0024CF6C_b = q;
                break;
            }
        } while (q != 0);
    }
}
/* localdecomp:end func_L39_0066BD80 */

INCLUDE_ASM("asm/levels", func_L39_0066BE40);
