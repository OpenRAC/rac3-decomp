/* PAL near miss (k6 agent 2, 2026-11-26), written from retail (no earlier draft). Flags: the file's line plus -fno-strength-reduce
 * (`@ee296 @eeas -O2 -G0 -fno-strength-reduce`; func_L39_00508470, 005084A8, 00508540, 005085B0 and 00508620, the file's other C,
 * still match with it). With it the first loop is a plain for (;;) and matches retail exactly (no strength reduction of items[i],
 * the type key `la` hoisted, the loop head aligned); without it every loop form is strength-reduced. checked with tools/check.py at
 * level 39: 20 aligned rows, all in the second loop, written here with gotos (retail: no test copy, the -1 and 1 constants
 * materialised in the loop, src[i] reloaded in the body, the body label aligned). A permuter run (tools/permuter_engine.py)
 * found that `do { goto test; } while (0);` in place of `goto test;` leaves 2 words (the src load and `move $t0, $zero` swap
 * around the `b`): a loop note around the entry jump gives the alignment, the reload and the constants. That is not plausible
 * source, so it is not used; a real while/for second loop gets its exit test copied and its constants hoisted (35+ rows).
 * A second permuter run reached MATCH with the first loop as for (;;), `src = ...` after `i = 0; j = 0;`, and a dead
 * `items++; items--;` in the test block before `goto body` (items no longer invariant there): also not plausible, but it says
 * the original second loop treats items (or what is indexed with i*4 there) as changing inside the loop.
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
    for (;;) {
        p = items[i];
        i++;
        if (p == 0) {
            return 0;
        }
        if (p->type == key) {
            break;
        }
    }
    i = 0;
    j = 0;
    src = ((Inner_00508690 *)p->data)->data;
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
