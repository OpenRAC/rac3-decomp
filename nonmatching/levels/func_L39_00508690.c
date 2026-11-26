/* PAL near miss (k6 agent 2, 2026-11-26), written from retail (no earlier draft). Flags: the file's (`@ee296 @eeas -O2 -G0`, Sony's
 * ee-gcc 2.96 and ee-as), checked with tools/check.py at level 39: 50 = 50 instructions, 24 aligned rows differ, all in the second loop.
 * What matched the first part: the first loop as gotos (retail computes items[i] as i << 2 each time: no strength reduction, which every
 * for/while/do form here gets), the type key in a local set at the top (retail forms `la D_L39_0046F010` once, before the loop), and the two
 * -1 stores as one chained assignment. Left: in the second loop retail reloads src[i] in the body (`lw $a0, 0($v0)` after the test's
 * `lw $v1`, whose register then takes the constant 1 in the bne slot: bne, not bnel), where this C reuses the test's load; and the
 * register pairs dst/src ($t4/$t3 in retail) and j / i*4 ($t1/$t0) are swapped. Declaration order, a while/for second loop (strength-
 * reduced, worse), a separate index for the second loop, `dst[j] = 1` and a u32 compare made no difference.
 */
#include "common.h"
/* localdecomp:start func_L39_00508690 */
typedef struct { void *type; u8 pad4[0xC]; void *data; } Item_00508690;
typedef struct { u8 pad0[0x10]; s32 *data; } Inner_00508690;
typedef struct { u8 pad0[0x10]; Inner_00508690 *inner; } Ctx_00508690;
extern u8 D_L39_0046F010[];
s32 func_L39_00508690(Ctx_00508690 *ctx, s32 n, Item_00508690 **items, void *type) {
    s32 *dst;
    s32 *src;
    Item_00508690 *p;
    void *key;
    s32 i, j;

    key = D_L39_0046F010;
    dst = ctx->inner->data;
    dst[n - 1] = dst[n - 2] = -1;
    i = 0;
find:
    p = items[i];
    i++;
    if (p == 0) {
        return 0;
    }
    if (p->type != key) {
        goto find;
    }
    src = ((Inner_00508690 *)p->data)->data;
    i = 0;
    j = 0;
    goto test;
body:
        if (src[i] == 1) {
            dst[j] = src[i];
        }
        i++;
        j++;
        if (items[i]->type == type) {
            j++;
        }
test:
    if (src[i] != -1) {
        goto body;
    }
    return 0;
}
/* localdecomp:end func_L39_00508690 */
