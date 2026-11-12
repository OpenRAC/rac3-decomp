/* near miss (level 5): 9 differences with -mvu0-use-vf0-vf2 and @ps2as on its file (it has neither yet); every instruction is right, only the order of two argument moves before the func_L01_0046FB40 call (retail move $a1 then $a0, ours $a0 then $a1) and so the registers of its result and of the byte store that follows (retail $a1/$a0, ours $a0/$v0); prototype variants, declaration permutations and a struct-typed result gave nothing */
#include "common.h"

/* localdecomp:start func_L05_0032B630 */
#include "vu0.h"
typedef struct {
    char pad0[0x10];
    vu0_v4 pos;
} S_32B630;
typedef struct {
    char pad0[0x5C];
    u8 *f5C;
} S_220758_32B630;
extern S_220758_32B630 D_L05_00220758;
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L05_0032B630(S_32B630 *p) {
    vu0_v4 a;
    vu0_v4 b;
    s32 n;
    s32 cnt;
    f32 s;
    s32 r;
    u8 *q;
    n = func_00382498(12, 15);
    if (n > 0) {
        cnt = n;
        do {
            a = p->pos;
            func_003C4C18(&a, 1.85f);
            vec_sub_ba(&b, &a, &p->pos);
            func_0038CF68(&b, &b, 0.0400000028f);
            func_003C4C18(&b, 0.0060000005f);
            a.z = 20.85f;
            s = func_003824E0(1.0f, 2.0f) * 210000.0f;
            r = (func_00382498(35, 60) * 5 + 2) / 6;
            q = func_L01_0046FB40(&a, &b, r, 0x40B4B4B4, func_00382468(2) != 0 ? 1 : -1, 12, 0, 0, s, s * 0.5f, 0.003f);
            if (q != 0) {
                q[3] = 0x44;
                q[2] = *D_L05_00220758.f5C;
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L05_0032B630 */
