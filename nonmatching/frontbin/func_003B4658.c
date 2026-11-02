/* Draft from the NTSC decomp (commit 13cf5c5; THIRD_PARTY_NOTICES.md).
 * NTSC-U frontbin: 0x003AF0A0, 40 bytes; shared PAL name: func_003B4658.
 * Best user check: 2 differing words, the table store and return-pointer move
 * reversed. The simpler original struct-based draft is retained below.
 * Four user checks with the owning file's flags:
 *   field0, table, zeros: 2 differences (retained).
 *   table, field0, zeros: 5 differences, setup/register allocation changed.
 *   table, field0 from an initialized local, zeros: the same 5 differences.
 *   field0, zeros, table: the same 2 differences as the retained draft.
 * No improvement across these checks; attempt stopped, not integrated.
 * The earlier pointer-array draft needed -mno-split-addresses, which is not
 * the owning file's flag set. The flags used for all four checks were:
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division.
 * The caller initializes four objects with stride 0x14. Only field offsets and
 * initial values are confirmed; the table at +4 appears to be a virtual table.
 */
#include "common.h"

/* localdecomp:start func_003B4658 */
typedef struct {
    s32 field0;
    u8 *table;
    s32 field8;
    s32 fieldC;
    s32 field10;
} Object_003B4658;

extern u8 D_001D88D8[];

void **func_003B4658(void **p) {
    Object_003B4658 *object = (Object_003B4658 *)p;

    object->field0 = 1;
    object->table = D_001D88D8;
    object->field8 = 0;
    object->fieldC = 0;
    object->field10 = 0;
    return p;
}
/* localdecomp:end func_003B4658 */
