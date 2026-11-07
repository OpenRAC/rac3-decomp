#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_003A0EE8);

INCLUDE_ASM("asm/levels", func_L02_003A2320);

INCLUDE_ASM("asm/levels", func_L02_003A23C8);

/* localdecomp:start func_L02_003A2620 */
typedef struct S_3A2620 {
    u16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8 pad[4];
    s32 fC;
} S_3A2620;
typedef struct T_3A2620 {
    u8 pad[0x20];
    u8 state;
    u8 pad2[0x47];
    S_3A2620 *p;
} T_3A2620;
extern u8 D_001A4C60[];
extern void func_L02_003A2708(void *arg0);
extern int func_L01_00456500(void *a, int b);
extern int func_0038CB00(void *a);
extern int func_00382468(int a);
extern void func_L02_003A23C8(int a, int b);

void func_L02_003A2620(T_3A2620 *arg0) {
    S_3A2620 *q;
    int r;
    int s;
    func_L02_003A2708(arg0);
    q = arg0->p;
    s = arg0->state;
    if (s != 2) {
        if (s < 3) {
            if (s == 1) {
                if (q->fC != -1) {
                    if (func_L01_00456500(D_001A4C60, q->fC) != 0) {
                        arg0->state = 2;
                    }
                }
            }
        }
    } else {
        if (func_L01_00456500(D_001A4C60, q->fC) == 0) {
            arg0->state = 1;
        } else if (func_0038CB00(&q->f2) != 0) {
            do {
                r = func_00382468(3);
            } while (r == q->f4);
            func_L02_003A23C8(r, q->f6);
            q->f2 = q->f0;
            q->f4 = r;
        }
    }
}
/* localdecomp:end func_L02_003A2620 */

/* localdecomp:start func_L02_003A2708 */
void func_L02_003A2708(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s16 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 4) = -1;
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L02_003A2708 */
