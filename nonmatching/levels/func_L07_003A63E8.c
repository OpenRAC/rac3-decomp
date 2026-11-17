/* Level 7 retry, 2026-11-15: newly reconstructed baseline 30 -> 1 differing
   word; no saved draft or prior measured history existed. Exact size 116 bytes.
   Flags: -O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as.
   Residual +0x5C: addu a0,a3,v1 instead of addu a0,v1,a3. A block-local
   divisor ten fixes the extra moves/materializations. Pointer/TI/aggregate
   address forms either lose the duplicated pointer or regress to 25 words.
   Stop: equivalent negative forms in this function and its sibling; retry only
   with a corresponding twin or new RTL evidence. No divs_nops row needed.
   Recheck: UYA_TOOLCHAIN=~/sn UYA_RUNNER=~/bin/wibo venv/bin/python
   tools/check.py nonmatching/levels/func_L07_003A63E8.c func_L07_003A63E8
   --target level_07. This draft is not linked. */
#include "common.h"
typedef int Q_003A63E8 __attribute__((mode(TI)));
typedef struct P_003A63E8 {
    u8 pad0[0x350];
    Q_003A63E8 a[10];
    Q_003A63E8 b[10];
    u8 head;
    u8 count;
} P_003A63E8;
void func_L07_003A63E8(void *arg0, Q_003A63E8 *arg1, Q_003A63E8 *arg2) {
    P_003A63E8 *p = *(P_003A63E8 **)((u8 *)arg0 + 0x68);
    s32 index;
    if (++p->count > 10) {
        s32 ten = 10;
        p->count = ten;
        p->head = (p->head + 1) % ten;
    }
    index = (p->head + p->count - 1) % 10;
    p->a[index] = *arg1;
    p->b[index] = *arg2;
}
