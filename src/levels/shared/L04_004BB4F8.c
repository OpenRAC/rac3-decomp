#include "common.h"

/* localdecomp:start func_L04_004BB4F8 */
typedef struct {
    f32 x, y, z, w;
} V_4B77C8;

extern u8 D_L04_001E2840[];
extern void func_L01_004464C8(V_4B77C8 *, s32, s32, u8 *);
extern f32 func_L01_0040E548(V_4B77C8 *, u8 *);

s32 func_L04_004BB4F8(s32 a0, s32 a1, f32 r) {
    V_4B77C8 v;
    func_L01_004464C8(&v, a0, a1, D_L04_001E2840);
    return r * r < func_L01_0040E548(&v, D_L04_001E2840);
}
/* localdecomp:end func_L04_004BB4F8 */
