#include "common.h"

/* localdecomp:start func_L39_004FA4E8 */
extern void func_L39_004BEF28(void *);

typedef struct S_004FA4E8 {
    s32 length;
    s32 type;
    void *data;
} S_004FA4E8;

void func_L39_004FA4E8(S_004FA4E8 *a) {
    if (a == 0) return;
    if (a->data != 0) func_L39_004BEF28(a->data);
    func_L39_004BEF28(a);
}
/* localdecomp:end func_L39_004FA4E8 */
