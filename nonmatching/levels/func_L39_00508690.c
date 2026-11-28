/* Wave 13 (r32, 2026-11-28) replaces the earlier draft of this function (k6 agent 2, from retail). */
/* PAL near miss (wave 13b r32, 2026-11-28), from the k6 draft. Under the file's own line (@ee296 @eeas -O2 -G0, no
 * -fno-strength-reduce) this gives 2 diff (the draft: 40). What changed: the found block (i = 0; j = 0; src = ...; and the
 * jump to the second loop's test) now sits INSIDE the first for (;;), and the jump is wrapped in do { } while (0). The
 * nested loop note makes the first loop non-innermost, so loop.c no longer accepts the constant reset i = 0 as a biv
 * set (-dL: 'Reg 91: biv discarded, not induction variable'): the first loop is not strength-reduced and matches
 * retail word for word (loop head aligned, i*4 recomputed), without any flag change. The phony loop note before
 * body: also stops CSE following the jump into the body (src[i] reloaded, constants -1/1 kept in the loop). Still
 * differs: 2 words, the src load (lw t3, 0x10(v0)) and the PRE-inserted i*4 = 0 (move t0, zero) swap around the b.
 * Tried for those: statement orders of i/j/src (4 orders), declaration orders, i = j = 0 / j = i = 0, src without a
 * local (15), src load inside the do-while (3). The do { goto test; } while (0) is a study aid, not plausible
 * source: the original probably had a nested loop construct there (a real nested while/for is optimized: 40, the
 * constants hoisted; the plain goto layout without the note: 39).
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
    s32 i, j;

    dst = ctx->inner->data;
    dst[n - 1] = dst[n - 2] = -1;
    i = 0;
    for (;;) {
        p = items[i];
        i++;
        if (p == 0) {
            return 0;
        }
        if (p->type == D_L39_0046F010) {
            i = 0;
            j = 0;
            src = ((Inner_00508690 *)p->data)->data;
            do {
                goto test;
            } while (0);
        }
    }
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
