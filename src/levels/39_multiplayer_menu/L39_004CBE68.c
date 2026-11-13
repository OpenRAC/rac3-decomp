#include "common.h"

/* localdecomp:start func_L39_004CBE68 */
typedef struct S_004CBE68 {
    u8 pad0[0x28];
    struct S_004CBE68 *f28;
    struct S_004CBE68 *f2C;
    u8 pad30[0xC4 - 0x30];
    struct S_004CBE68 *fC4;
    struct S_004CBE68 *fC8;
} S_004CBE68;

void func_L39_004CBE68(S_004CBE68 *a0, S_004CBE68 *a1)
{
    S_004CBE68 *next = a1->fC8;
    S_004CBE68 *prev;

    if (next != 0 && (prev = a1->fC4) != 0) {
        if (next == (S_004CBE68 *)&a0->f2C) {
            if (prev == (S_004CBE68 *)&a0->f28) {
                a0->f28 = 0;
                a0->f2C = 0;
            } else {
                a0->f2C = prev;
                a1->fC4->fC8 = next;
            }
        } else if (prev == (S_004CBE68 *)&a0->f28) {
            a0->f28 = next;
            a1->fC8->fC4 = prev;
        } else {
            next->fC4 = prev;
            a1->fC4->fC8 = a1->fC8;
        }
        a1->fC8 = 0;
        a1->fC4 = 0;
    }
}
/* localdecomp:end func_L39_004CBE68 */
