#include "common.h"

/* declared by functions of L39_004CA568.c, which this file was cut from */
typedef struct S_004CBE68 {
    u8 pad0[0x28];
    struct S_004CBE68 *f28;
    struct S_004CBE68 *f2C;
    u8 pad30[0xC4 - 0x30];
    struct S_004CBE68 *fC4;
    struct S_004CBE68 *fC8;
} S_004CBE68;

/* localdecomp:start func_L39_004CBEE0 */
void func_L39_004CBEE0(S_004CBE68 *list, S_004CBE68 *node) {
    S_004CBE68 *head;
    if (node->fC8 != 0 && node->fC4 != 0) {
        func_L39_004CBE68(list, node);
    }
    head = list->f28;
    if (head == 0) {
        list->f28 = node;
        list->f2C = node;
        node->fC4 = (S_004CBE68 *)&list->f28;
        node->fC8 = (S_004CBE68 *)&list->f2C;
    } else {
        node->fC8 = head;
        head->fC4 = node;
        node->fC4 = (S_004CBE68 *)&list->f28;
        list->f28 = node;
    }
}
/* localdecomp:end func_L39_004CBEE0 */

INCLUDE_ASM("asm/levels", func_L39_004CBF60);
