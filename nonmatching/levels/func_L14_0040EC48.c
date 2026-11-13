/* func_L14_0040EC48: near miss, 115 diff: file already VU0 + @ps2as; frame, FP registers ($f20-$f28 with sz + sz kept in $f23) and call order match; left: saved-register choice (retail keeps &p in $s6, &q in $s3, the count in $s4, 6 in $s5, 0xF2 in $fp and 0x44 in $s7; this C takes &q twice into $s6/$s7, so 0xF2 is not hoisted and the rest shifts)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
typedef struct {
    u8 pad[0x184];
    u8 *p184;
} S_40EC48;
extern S_40EC48 D_L14_0021F958;
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0044FB80(void *, void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, u32, u32, s32, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
void func_L14_0040EC48(vu0_v4 *pos) {
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 d;
    s32 r;
    s32 n;
    s32 life;
    s32 life2;
    s32 k;
    s32 c;
    f32 spd;
    f32 sz;
    f32 rad;
    f32 a;
    u8 *e;
    vu0_v4 *pp;
    f32 sz2;
    p = *pos;
    pp = &p;
    r = func_00382498(15, 20);
    spd = func_003824E0(0.0f, 0.035f);
    if (r > 0) {
        n = r;
        do {
            life = (func_00382498(100, 150) * 5 + 2) / 6;
            sz = func_003824E0(1.0f, 2.0f);
            sz2 = sz + sz;
            q = *pp;
            rad = func_003824E0(0.6f, 3.0f);
            a = func_003824E0(-3.1415927f, 3.1415927f);
            func_L01_0044FB80(&q, &q, rad, a, func_003824E0(-3.1415927f, 3.1415927f));
            vec_sub_ab(&d, &q, pp);
            func_0038CF68(&d, &d, spd);
            k = func_00382498(-1, 1);
            e = func_L01_00475C60(&q, &d, life, k, 0x7F407FFF, 0x001020FF, 0, sz * 210000.0f, sz2 * 210000.0f, 0.0f);
            if (e != 0) {
                e[9] = 0xF2;
                e[2] = D_L14_0021F958.p184[3];
                if (func_00382468(2) == 0) {
                    e[3] = 0x44;
                }
            }
            if (func_00382468(2) == 0) {
                func_0038CF68(&d, &d, func_003824E0(0.1f, 0.3f));
                c = (s32)func_L01_00443A18(2.0f, 5.0f);
                life2 = (func_00382498(40, 65) * 5 + 2) / 6;
                e = func_L01_004713C8(&q, &d, life2, 0x7F407FFF, c, 0x7F, 0x7F, 1, func_003824E0(0.5f, 1.0f) * 210000.0f, 0.0f, 0.0f);
                if (e != 0) {
                    e[9] = 0xF2;
                    if (func_00382468(2) == 0) {
                        e[3] = 0x44;
                    }
                }
            }
        } while (--n != 0);
    }
}
