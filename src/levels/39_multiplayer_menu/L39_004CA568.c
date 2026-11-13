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
