#include "common.h"

/* localdecomp:start func_L39_004CA568 */
typedef struct N_4CA568 {
    u8 pad0[0xC];
    struct N_4CA568 *next;
    struct N_4CA568 *prev;
} N_4CA568;

/* from rac4-decomp's func_L00_00506368 */
void func_L39_004CA568(N_4CA568 **head, N_4CA568 *node, N_4CA568 **tail) {
    N_4CA568 *prev;
    N_4CA568 *next;
    if (node != *tail) {
        if (node == *head) {
            *head = node->next;
        }
        prev = node->prev;
        if (prev != 0) {
            prev->next = node->next;
        }
        next = node->next;
        if (next != 0) {
            next->prev = node->prev;
        }
        (*tail)->next = node;
        node->prev = *tail;
        node->next = 0;
        *tail = node;
    }
}
/* localdecomp:end func_L39_004CA568 */

INCLUDE_ASM("asm/levels", func_L39_004CA5D0);

INCLUDE_ASM("asm/levels", func_L39_004CB680);

INCLUDE_ASM("asm/levels", func_L39_004CB698);

INCLUDE_ASM("asm/levels", func_L39_004CB730);

INCLUDE_ASM("asm/levels", func_L39_004CB8D0);

INCLUDE_ASM("asm/levels", func_L39_004CBA18);

INCLUDE_ASM("asm/levels", func_L39_004CBAA8);

INCLUDE_ASM("asm/levels", func_L39_004CBB38);

INCLUDE_ASM("asm/levels", func_L39_004CBCF0);

INCLUDE_ASM("asm/levels", func_L39_004CBDC0);

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

INCLUDE_ASM("asm/levels", func_L39_004CBEE0);

INCLUDE_ASM("asm/levels", func_L39_004CBF60);
