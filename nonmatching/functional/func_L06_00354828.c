/* functional: medium. check.py at level_06: ~100 instruction diffs, scheduling/register shifts (retail keeps a dead recompute of the clamped ratio; omitted). Rewritten from the PAL assembly using the NTSC-U draft only as a shape guide: constants (0.06f,0.01f,0x32,157500/315000), callees and D_L06_0021E4D8 are the PAL ones. */
#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00354828;
typedef struct { u8 pad[0x5C]; u8 *p5C; } S_00354828;
extern S_00354828 D_L06_0021E4D8;
__asm__(".extern D_L06_0021E4D8, 16");
extern f32 func_003C3D30(void *, s32, void *, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L06_00354828(s32 a0, s32 a1, V4_00354828 *a2, s32 a3) {
    V4_00354828 s;
    V4_00354828 p;
    V4_00354828 q;
    f32 d;
    f32 r;
    f32 t;
    s32 n;
    u8 *b;

    s = *a2;
    p = *a2;
    t = func_003C3D30(&s, 0, 0, 0.5f);
    d = s.z - t;
    p.z = t;
    if (d > 0.0f && d < 20.0f) {
        r = (d - 10.0f) / 10.0f;
        if (r > 1.0f) {
            r = 1.0f;
        } else if (r < 0.0f) {
            r = 0.0f;
        }
        n = 64 - (s32)(r * 64.0f);
        if (n >= 15 && a3 > 0) {
            do {
                q.x = func_0038D098(func_00382538()) * 0.06f;
                q.y = func_0038D0B0(func_00382538()) * 0.06f;
                q.z = 0.01f;
                b = func_L01_0046FB40(&p, &q, 0x32, 0x303234, func_00382468(3), n, 0, 0, 157500.0f, 315000.0f, 0.0f);
                if (b != 0) {
                    b[2] = *D_L06_0021E4D8.p5C;
                    b[3] = 0x48;
                }
                a3--;
            } while (a3 != 0);
        }
    }
}
