#include "common.h"

/* localdecomp:start func_L39_004DB168 */
typedef struct {
    s32 f0;
    void *data;
    s32 size;
} S_004DB168;

extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *);

/* clear and free a buffer holder (memset then Free) */
void func_L39_004DB168(S_004DB168 *p) {
    if (p != 0) {
        if (p->data != 0) {
            func_0011D534(p->data, 0, p->size);
            func_L39_004BEF28(p->data);
        }
        func_L39_004BEF28(p);
    }
}
/* localdecomp:end func_L39_004DB168 */

INCLUDE_ASM("asm/levels", func_L39_004DB1C0);
