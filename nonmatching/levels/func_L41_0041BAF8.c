/* NTSC-U draft (Claude wave K): C of func_L41_0041B230, the NTSC-U twin of func_L41_0041BAF8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 134 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L41_0041B230", whose code is not the PAL one).
 * Worker's note: 18 words off (134 diff) with @ps2as (float lui/ori); local order v0,t,v20 fixes stack; extra saved reg (fp) in ours: retail frees s0 after copying n to s3 loop counter and reuses it for q+0x20; D_L41_002412A0 as pointer array for lui form
 */
#include "common.h"

/* localdecomp:start func_L41_0041B230 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_0041B230 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0041B230;

extern f32 D_L41_0024A280[];
extern s32 *D_L41_002412A0[];

extern s32 func_L39_005BC958(void *, s32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern s32 func_L39_005B24C8(s32, s32);

void func_L41_0041B230(f32 *pos, s32 n, u32 col, f32 scale) {
    V_0041B230 v0;
    f32 t[4];
    V_0041B230 v20;
    f32 base;
    f32 fa;
    f32 fb;
    s32 sign;
    s32 i;
    u8 *q;
    u8 *r;

    *(u128_t *)&v0 = *(u128_t *)pos;
    v0.w = 5.0f;
    if (func_L39_005BC958(&v0, 0, 128.0f) == -1) {
        return;
    }
    base = func_00388A28(D_L41_0024A280[0] - pos[0], D_L41_0024A280[1] - pos[1]);
    if (!(*D_L41_002412A0[0] < 3)) {
        n = n / 3;
    }
    sign = 1;
    if (n > 0) for (i = n; i != 0; i--) {
        sign = -sign;
        t[0] = pos[0] + func_L39_005B2568(0.0f, 1.0f) * scale;
        t[1] = pos[1] + func_L39_005B2568(0.0f, 1.0f) * scale;
        t[2] = pos[2] + func_L39_005B2568(0.0f, 1.0f) * scale;
        fa = func_L39_005B2510(0.016666668f, 0.033333335f) * scale;
        fb = func_L39_005B2568(0.0f, 1.3962634f);
        func_0037E4B8(&v20, fa, func_00389380(base, func_L39_005B2568(0.0f, 1.5707964f)), fb);
        q = func_L01_004633E8(t, 0.0f, 1.0f, 1.05f, scale * 1.5f * 210000.0f, sign, &v20, col, 0);
        if (q != 0) {
            *(s16 *)(q + 0xA) = func_L39_005B24C8(40, 70);
            r = q + 0x20;
            q[9] = 0x44;
            *(s32 *)(r + 4) = 3;
            *(f32 *)(r + 0x1C) = (f32)func_L39_005B24C8(1, 10);
            r[0xA] = 0x40;
            q[3] = 0x44;
            r[0xB] = q[0xA];
        }
    }
}
/* localdecomp:end func_L41_0041B230 */
