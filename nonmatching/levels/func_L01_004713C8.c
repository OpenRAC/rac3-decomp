/* Near miss (61 diffs): store forms and call sequence match, but gcc allocates the s-registers differently (retail: n $s1, vec $s2, a3 $s3, pos $s4, t1 $s5; ours puts t1 in $s3) and schedules the stores differently. Parameters: pos, vec, n, a3, f12-f14 = f0,f1,f2, t0..t3. */
#include "common.h"
#include "vu0.h"
extern u8 *func_L01_004618E0_004713C8(s32);
extern u8 *D_L01_0022121C_004713C8[];
extern s32 func_00443948(s32);
extern void func_L01_00471530();

u8 *func_L01_004713C8(s128 *pos, f32 *vec, s32 n, s32 a3, f32 f0, f32 f1, f32 f2, s32 t0, s32 t1, s32 t2, s32 t3) {
    u8 *p = func_L01_004618E0_004713C8(0x61);
    u8 *s;
    if (p != 0) {
        p[1] = 0;
        *(f32 *)(p + 0xC) = f0;
        *(s128 *)(p + 0x10) = *pos;
        p[9] = 0x44;
        p[3] = 0x48;
        *(s32 *)(p + 4) = (t1 << 24) | a3;
        p[8] = func_00443948(0xFF);
        *(s16 *)(p + 0xA) = n;
        s = p + 0x20;
        p[2] = D_L01_0022121C_004713C8[0][t3];
        *(f32 *)(p + 0x20) = vec[0];
        *(f32 *)(s + 4) = vec[1];
        *(f32 *)(s + 8) = vec[2];
        *(f32 *)(s + 0xC) = f2;
        *(s32 *)(s + 0x1C) = (s32)func_L01_00471530;
        s[0x15] = t0;
        *(f32 *)(s + 0x10) = (f1 - f0) / (f32)n;
        s[0x14] = (t2 - t1) / n;
    }
    return p;
}
