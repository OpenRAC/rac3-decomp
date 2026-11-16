/* NTSC-U draft (Claude wave S/us): C of func_L39_004F7210, the NTSC-U twin of func_L39_004F7410, with NTSC-U names and addresses.
 * near miss: 7 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" (the file's line: "@ee296 @eeas -O2 -G0") (NTSC-U twin "func_L39_004F7210").
 * Worker's note: 7 diff with @ee29 (frame 0x20, sd ra at 0x10, sw zero,4(s0) one slot late), 8 diff with SN 2.95.3 (jal+jr, frame 0x10 right, sw zero,4(s0) in the jal slot): library-region wall. Retail ends in a sibling call (ld ra; ld s0; j func_L39_004F7420; addiu ...
 */
#include "common.h"

/* localdecomp:start func_L39_004F7210 */
typedef struct {
    s32 f0;
    s32 f4;
    void (*f8)(s32);
} Obj_L39_004F7210;

extern void func_L39_004F72E8(s32, s32, s32);
extern void func_L39_004F7420(s32);

void func_L39_004F7210(Obj_L39_004F7210 *obj) {
    if (obj->f8 != 0) {
        obj->f8(obj->f0);
    }
    func_L39_004F72E8(obj->f0, 0, obj->f4);
    obj->f4 = 0;
    func_L39_004F7420(obj->f0);
}
/* localdecomp:end func_L39_004F7210 */
