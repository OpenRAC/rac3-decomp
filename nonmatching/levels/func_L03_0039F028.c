/* near miss (level 3, Starship Phoenix): 165 differences: the same particle-loop family as func_L03_00399F38 (interblock motion of the loop decrement) plus the register choice for the hoisted &p0/&d pointers; a first draft with every constant and call right */
#include "common.h"

/* localdecomp:start func_L03_0039F028 */
#include "vu0.h"
typedef struct { u8 pad0[0x16C]; u8 *p16C; } T_0039F028;
extern T_0039F028 D_L03_0021F298;
__asm__(".extern D_L03_0021F298, 16");
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(f32 *v, f32 r);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);

void func_L03_0039F028(void *arg, void *src, void *dir, f32 r) {
    vu0_v4 p0;
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 t;
    vu0_v4 vel;
    int n;
    p0 = *(vu0_v4 *)src;
    d = *(vu0_v4 *)dir;
    n = (s32)(r * 8.0f);
    if (n > 0) {
        int j = n;
        do {
            f32 k = func_003824E0(0.0f, r);
            s32 life;
            f32 sz;
            u8 *p;
            func_0038CE20(&t, &d, k);
            vec_add_ba(&pos, &p0, &t);
            func_003C4C18(&pos.x, k * 0.19f + 0.01f);
            *(vu0_q *)&vel = 0;
            vel.z = k * 0.120000005f + 0.20000002f;
            life = func_00382498(4, 6);
            sz = k * 294000.0f + 126000.01f;
            p = func_L01_0046A610(&pos, &vel, life, 0x7F, 0xFF4040, func_00382468(2) != 0 ? 3 : -3, sz, -sz / (f32)life, 1.0f, 0.0f, 0.0f);
            j--;
            if (p != 0) {
                p[2] = D_L03_0021F298.p16C[1];
            }
        } while (j != 0);
    }
    if (func_00382468(20) == 0) {
        f32 sz;
        func_0038CF68(&pos, &d, func_003824E0(0.060000002f, 0.16000001f));
        func_003C4C18(&pos.x, 0.020000001f);
        sz = func_003824E0(21000.0f, 63000.004f);
        func_L01_004739D8(&p0, &pos, 0x80A02020, 0x20808080, func_00382498(0x21, 0x32), 0, sz);
    }
}
/* localdecomp:end func_L03_0039F028 */
