/* PAL near miss (Claude wave S2/pal): near miss: 17 words differ (the worker's best count).
 * Worker's note: 17 diff, register allocation only: body and instruction mix equal retail (8 records of 8 bytes at D_001A4BE0+0x274C inside the hero struct: if func_0038CB00(p) == 2 { t = h2; h0 = 0; t == 0x1B ? func_L01_004E11C0(D_001A4BE0[0x147F],1,1,0x32) : ...
 */
#include "common.h"

/* localdecomp:start func_L01_004F5010 */
extern s32 func_0038CB00(void *);
extern void func_L01_004E11C0(s32, s32, s32, s32);

void func_L01_004F5010(void) {
    u8 *tbl = (u8 *)&D_001A4BE0 + 0x2750;
    u8 *p = tbl;
    u8 *q = tbl + 2;
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (func_0038CB00(p) == 2) {
            s32 t = *(s16 *)(q - 4);

            *(s16 *)(q - 6) = 0;
            if (t == 0x1B) {
                func_L01_004E11C0(((u8 *)&D_001A4BE0)[0x147F], 1, 1, 0x32);
            } else {
                func_L01_004F4E70(t, *(s16 *)q);
            }
        }
        p += 8;
        q += 8;
    }
}
/* localdecomp:end func_L01_004F5010 */
