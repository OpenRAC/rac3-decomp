/* Level 7 retry, 2026-11-15: newly reconstructed baseline 30 -> 1 differing
   word; no saved draft or prior measured history existed. Exact size 116 bytes.
   Flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
   Residual +0x5C: addu a0,a3,v1 instead of addu a0,v1,a3. A block-local
   divisor ten fixes the extra moves/materializations. Pointer/TI/aggregate
   address forms either lose the duplicated pointer or regress to 25 words.
   Stop: equivalent negative forms in this function and its sibling; retry only
   with a corresponding twin or new RTL evidence. No divs_nops row needed.
   Recheck: UYA_TOOLCHAIN=~/sn UYA_RUNNER=~/bin/wibo venv/bin/python
   tools/check.py nonmatching/levels/func_L07_00353D98.c func_L07_00353D98
   --target level_07. This draft is not linked. */
#include "common.h"

typedef int Quad_00353D98 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x320];
    Quad_00353D98 a[10];
    Quad_00353D98 b[10];
    u8 pad460[8];
    u8 first;
    u8 count;
} Queue_00353D98;
typedef struct {
    u8 pad0[0x68];
    Queue_00353D98 *p68;
} Object_00353D98;

void func_L07_00353D98(Object_00353D98 *self, Quad_00353D98 *a, Quad_00353D98 *b) {
    Queue_00353D98 *p = self->p68;
    s32 i;
    if (++p->count > 10) {
        s32 ten = 10;
        p->count = ten;
        p->first = (p->first + 1) % ten;
    }
    i = (p->first + p->count - 1) % 10;
    p->a[i] = *a;
    p->b[i] = *b;
}
