#include "common.h"

/* NTSC-U counterpart of func_L05_0032B3B8 (src/levels/05_daxx/L05_0032ADD0.c) */
void func_L01_004450F0_0032AA98(s32, s32, s32);
typedef int Q_32B290 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32B290;
void func_L05_0032AA98(u8 *);

/* localdecomp:start func_L05_0032AA98 */
#include "vu0.h"
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003BF6A8(void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L05_00468C10(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);

void func_L05_0032AA98(u8 *o) {
    vu0_v4 v;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 *pp;
    vu0_v4 *vp;
    s32 n;
    s32 cnt;
    s32 sgn;
    s32 big;
    s32 cnt2;
    s32 col;
    s32 a;
    f32 sp;
    f32 r;
    f32 f;

    *(vu0_q *)&v = *(vu0_q *)(o + 0xE0);
    func_00388830(&v, &v, 1.2f);
    vec_add_ba(&v, o + 0x10, &v);
    n = func_0037E208(0x50, 0x6E);
    if (n > 0) {
        cnt = n;
        vp = &vel;
        pp = &pos;
        do {
            sgn = 1;
            big = 0;
            sp = func_0037E250(4.0f, 15.0f) * 0.016666668f;
            r = func_0037E2A8();
            func_0037E4B8(vp, sp, r, func_0037E250(0.5235988f, 1.5707964f));
            *(vu0_q *)&pos = *(vu0_q *)(o + 0xE0);
            func_00388830(pp, pp, func_0037E250(0.0f, 4.0f));
            func_003BF6A8(pp, 0.5f);
            vec_add_ba(&pos, o + 0x10, &pos);
            pos.z -= 0.5f;
            cnt2 = (vel.z + vel.z) / 0.005f;
            if (func_0037E1D8(2) != 0) {
                sgn = -1;
            }
            if (func_0037E1D8(3) == 0) {
                big = func_0037E208(1, 3);
            }
            a = 0x7F;
            col = 0x806060;
            f = func_0037E250(0.1f, 0.7f) * 210000.0f;
            if (big != 0) {
                f *= 0.5f;
                a = 0x60;
                col = 0x606060;
            }
            func_L05_00468C10(pp, vp, cnt2, col, sgn, a, a, f, 21000.0f, 0.005f, big, 0);
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L05_0032AA98 */
