#include "common.h"

/* NTSC-U counterpart of func_L05_0032B630 (src/levels/05_daxx/L05_0032ADD0.c) */
#include "vu0.h"
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(void *, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L05_0032AD10 */
#include "vu0.h"
typedef struct {
    char pad0[0x10];
    vu0_v4 pos;
} S_32B630;
typedef struct {
    char pad0[0x5C];
    u8 *f5C;
} S_220758_32B630;
extern S_220758_32B630 D_L05_002207D8;
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(void *, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L05_0032AD10(S_32B630 *p) {
    vu0_v4 a;
    vu0_v4 b;
    s32 n;
    s32 cnt;
    f32 s;
    s32 r;
    u8 *q;
    n = func_0037E208(12, 15);
    if (n > 0) {
        cnt = n;
        do {
            a = p->pos;
            func_003BF6A8(&a, 1.85f);
            vec_sub_ba(&b, &a, &p->pos);
            func_00388830(&b, &b, 0.0333333351f);
            func_003BF6A8(&b, 0.0050000004f);
            a.z = 20.85f;
            s = func_0037E250(1.0f, 2.0f) * 210000.0f;
            r = func_0037E208(35, 60);
            q = func_L01_0046C468(&a, &b, r, 0x40B4B4B4, func_0037E1D8(2) != 0 ? 1 : -1, 12, 0, 0, s, s * 0.5f, 0.003f);
            if (q != 0) {
                q[2] = *D_L05_002207D8.f5C;
                q[3] = 0x44;
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L05_0032AD10 */
