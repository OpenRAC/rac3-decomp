/* NTSC-U draft (Claude wave B): C of func_L39_004F7070, the NTSC-U twin of func_L39_004F7270, with NTSC-U names and addresses.
 * near miss: 12 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "@ee296 @eeas -O2 -G0") (NTSC-U twin "func_L39_004F7070").
 * Worker's note: 12 diff: sibling call (ld ra; j func_L39_00508420; addiu sp) that SN 2.95.3 never emits (no -foptimize-sibling-calls; ee29 and Sony 2.96 cc1 give jal too, see wiki 'Code from another compiler'); C is: if (func_L39_005082A8(x, obj, D_L39_0046EAB8) == 0) return ...
 */
#include "common.h"

/* localdecomp:start func_L39_004F7070 */
extern s32 func_L39_005082A8(void *a, void *b, void *tag);
extern s32 func_L39_00508420(void *p);
extern u8 D_L39_0046EAB8[];

s32 func_L39_004F7070(void **obj, void *x) {
    if (func_L39_005082A8(x, obj, D_L39_0046EAB8) == 0) {
        return func_L39_00508420(*obj);
    }
}
/* localdecomp:end func_L39_004F7070 */
