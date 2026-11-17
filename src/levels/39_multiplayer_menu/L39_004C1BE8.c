#include "common.h"

/* localdecomp:start func_L39_004C1BE8 */
void func_L39_004C1BA8();
extern u8 D_L39_00464A68[];

void *func_L39_004C1BE8(void) {
    func_L39_004C1BA8();
    return D_L39_00464A68;
}
/* localdecomp:end func_L39_004C1BE8 */

/* localdecomp:start func_L39_004C1C10 */
s32 func_L39_004C1C10(void) {
    return 8;
}
/* localdecomp:end func_L39_004C1C10 */

/* localdecomp:start func_L39_004C1C18 */
typedef struct { u8 pad[0x28]; } S_004C1C18;
extern S_004C1C18 D_L39_00464928[];

S_004C1C18 *func_L39_004C1C18(u32 arg0) {
    if (arg0 >= 8) {
        return 0;
    }
    return &D_L39_00464928[7 - arg0];
}
/* localdecomp:end func_L39_004C1C18 */

/* localdecomp:start func_L39_004C1C50 */
typedef struct {
    u8 _p0[0x48];
    s32 f48;
} I_004C1C50;

typedef struct {
    u8 _p0[0x50];
    I_004C1C50 *f50;
} S_004C1C50;

s32 func_L39_004C1C50(S_004C1C50 *a0) {
    return a0->f50->f48;
}
/* localdecomp:end func_L39_004C1C50 */
