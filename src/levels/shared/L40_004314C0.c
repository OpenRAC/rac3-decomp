#include "common.h"

/* declared by functions of L40_00430928.c, which this file was cut from */
extern u8 *func_L39_0066DD30(s32, s32, s32);

/* localdecomp:start func_L40_004314C0 */
extern u8 *func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(u8 *a0, s32 a1, s32 a2);
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
extern void func_L39_006626E8(u8 *a0);

void func_L40_004314C0(s32 id, s32 value) {
    u8 *p;

    func_L39_00662AA0(func_L39_0066DCC8(id, 0, 0, 250), value, 8);
    p = func_L39_0066DD30(id, 1, 0);
    if (p != 0 && p[85] != 0) {
        func_L39_006626E8(p);
    }
}
/* localdecomp:end func_L40_004314C0 */

/* localdecomp:start func_L40_00431540 */
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L40_00431540(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00431540 */
