/* near miss (level 31: body matches with @ps2as and a divs_nops row, 1 diff left (jr delay slot remnant)) */
#include "common.h"

/* localdecomp:start func_L31_003DFE98 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DFE98;

extern long func_00389598(s32);
extern void func_0038C138(long *, s32 *, s32 *, long, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);

void func_L31_003DFE98(s32 a0, s32 a1, s32 rad_out, s32 rad_in, s32 *a4, s32 *a5, s32 a6, s32 steps, f32 x, f32 y) {
    long q[4];
    V4_3DFE98 va;
    V4_3DFE98 vb;
    long col;
    long mask = 0xFFFFF000L << 24;
    f32 step;
    f32 ang0;
    f32 ang1;
    s32 i;
    f32 ca;
    f32 sa;
    f32 cb;
    f32 sb;

    col = func_00389598(a6);
    step = (y - x) / (f32)steps;
    ang0 = func_0038DAB8(x, 1.5707964f);
    ang1 = func_0038DAB8(ang0, step);
    for (i = 15; i >= 0; i--) {
        va.x = func_0038D098(ang0);
        va.y = func_0038D0B0(ang0);
        va.z = 0;
        vb.x = func_0038D098(ang1);
        vb.y = func_0038D0B0(ang1);
        vb.z = 0;
        ang0 = ang1;
        q[0] = ((long)(s32)(va.x * (f32)rad_out) + a0) + (((long)(s32)(va.y * (f32)rad_out) + a1) << 16) + mask;
        q[1] = ((long)(s32)(va.x * (f32)rad_in) + a0) + (((long)(s32)(va.y * (f32)rad_in) + a1) << 16) + mask;
        q[2] = ((long)(s32)(vb.x * (f32)rad_out) + a0) + (((long)(s32)(vb.y * (f32)rad_out) + a1) << 16) + mask;
        q[3] = ((long)(s32)(vb.x * (f32)rad_in) + a0) + (((long)(s32)(vb.y * (f32)rad_in) + a1) << 16) + mask;
        func_0038C138(q, a5, a4, col, 1);
        ang1 = func_0038DAB8(ang0, step);
    }
}
/* localdecomp:end func_L31_003DFE98 */
