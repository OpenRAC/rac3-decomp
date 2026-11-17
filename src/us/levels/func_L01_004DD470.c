#include "common.h"

/* localdecomp:start func_L01_004DD470 */
extern u8 D_001A605F[];
extern void func_L01_004DD4B0(s32, s32, s32, s32);
extern void func_L01_004F11B8(s32, s32, s32);

/* Calls func_L01_004DD4B0 with the byte at D_001A605F, 0, 1 and 0x32, then calls
 * func_L01_004F11B8(0x1B, 7, 0). */
void func_L01_004DD470(void) {
    func_L01_004DD4B0(D_001A605F[0], 0, 1, 0x32);
    func_L01_004F11B8(0x1B, 7, 0);
}
/* localdecomp:end func_L01_004DD470 */
