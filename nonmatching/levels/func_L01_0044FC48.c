#include "common.h"

/* Tables of sound/particle ids copied to the stack before use; the local copy keeps the ids
 * from changing under the calls below. */
typedef struct {
    s32 v[38];
} Tbl_L01_0044FC48;

extern Tbl_L01_0044FC48 D_L01_002BC250;

/* PAL callers pass a table entry to the playback and spawn helpers; the id in $a2 of the
 * second call and the 0x96 mode word differ from the NTSC twin's. */
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_L01_0044FC48 */
void func_L01_0044FC48(s32 idx, u8 flag)
{
    Tbl_L01_0044FC48 tbl;

    tbl = D_L01_002BC250;
    if (flag != 0) {
        func_L01_00451F60(tbl.v[idx], -1, 0);
    } else if (tbl.v[idx] != 0) {
        func_L01_00452560(0, 0xF, tbl.v[idx], 0x96, 0, 0, 0);
    }
}
/* localdecomp:end func_L01_0044FC48 */
