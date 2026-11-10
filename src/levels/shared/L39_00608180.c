#include "common.h"

/* localdecomp:start func_L39_00608180 */
extern void func_00194D68(s32, s32, s32, s32, s32);
typedef struct { s32 f0, f4; s32 f8, fC, f10; s32 f14, f18; u8 p1C[0x2C]; s32 f48, f4C; u8 p50[0xC]; s32 f5C; } Type1;

/* from rac4-decomp's func_004EF790, renamed */
void func_L39_00608180(Type1 *a) {
    if (a->f4 != 3) {
        func_00194D68(a->f48, (a->f4C / 1024) * 1024, a->f48 + a->f5C, 0, 0);
    } else {
        func_00194D68(a->f48, (a->f4C / 1024) * 1024, a->f5C, a->f14, a->f18);
    }
    a->f0 = 2;
}
/* localdecomp:end func_L39_00608180 */

/* localdecomp:start func_L39_00608220 */
typedef struct {
    s32 f0;
    char _p4[0x2C];
    s32 f30;
    char _p34[4];
    s32 f38;
    s32 f3C;
    char _p40[4];
    s32 f44;
    char _p48[8];
    s32 f50;
    char _p54[4];
    s32 f58;
    s32 f5C;
} S1_00608220;

extern s32 func_00194D08(void);

/* from rac2-decomp's func_0034F918 */
void func_L39_00608220(S1_00608220 *arg0) {
    func_00194D08();
    arg0->f0 = 0;
    arg0->f30 = 0;
    arg0->f38 = 0;
    arg0->f3C = 0;
    arg0->f44 = 0;
    arg0->f50 = 0;
    arg0->f58 = 0;
    arg0->f5C = 0;
}
/* localdecomp:end func_L39_00608220 */
