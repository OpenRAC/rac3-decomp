#include "common.h"

/* localdecomp:start func_L24_00432C00 */
typedef unsigned char BatchA_A18_u8;
typedef int BatchA_A18_s32;
extern BatchA_A18_s32 func_L01_004463F8(BatchA_A18_s32 a0, BatchA_A18_s32 a1, BatchA_A18_s32 a2);
extern BatchA_A18_s32 D_L24_0021D600[];

/* from rac2-decomp's func_L18_0033B628, renamed */
BatchA_A18_s32 func_L24_00432C00(BatchA_A18_s32 a0, BatchA_A18_s32 a1, BatchA_A18_s32 a2) {
    BatchA_A18_u8 *p;
    if (a1 != -1) {
        p = (BatchA_A18_u8 *)D_L24_0021D600[a1];
        if (p != 0) {
            if (*(BatchA_A18_s32 *)p != 0) {
                return func_L01_004463F8(a0, (BatchA_A18_s32)(p + 0x10), *(BatchA_A18_s32 *)p);
            }
        }
    }
    return a2;
}
/* localdecomp:end func_L24_00432C00 */
