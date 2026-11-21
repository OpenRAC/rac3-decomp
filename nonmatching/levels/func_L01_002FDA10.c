/* PAL near miss (haiku-w3): 79 words differ with the file's flags as checked; with divs_nops row "func_L01_002FDA10 2" (retail has nop nop before div.s, row missing from config/levels/divs_nops.txt) only 2 words differ: VU0 origin (input+0x20) and attached (input+0x30) loads take the other vf register, the scheduler issues the attached copy first */
#include "common.h"
/* localdecomp:start func_L01_002FDA10 */
#include "vu0.h"
void func_L01_002FDA10(u8 *owner, void *in) {
    extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_002FDC18(void *, s32, void *, s32);
    Effect_002FD530 *input = (Effect_002FD530 *)in;
    vu0_q points[25];
    vu0_v4 a, b, random, end;
    vu0_q *out = points;
    s32 i;
    for (i = 0; i < 24; i++, out++) {
        vu0_q qo, qe, qr, qv;
        *(vu0_q *)&a = *(vu0_q *)input->pos;
        __asm__("lqc2 %0, %1" : "=j"(qo) : "m"(*(vu0_v4 *)input->origin));
        vec_copy(&end, input->attached);
        *(vu0_q *)&b = *(vu0_q *)input->second;
        __asm__("lqc2 %0, %1" : "=j"(qr) : "m"(*(vu0_v4 *)&a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qr), "j"(qo));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&a) : "j"(qr));
        __asm__("lqc2 %0, %1" : "=j"(qe) : "m"(*(vu0_v4 *)&end));
        __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(*(vu0_v4 *)&b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qv), "j"(qe));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&b) : "j"(qr));
        func_L01_00445208(out, input->origin, input->attached, &a, &b, (f32)i / 23.0f);
        random.w = 0.0f;
        random.x = func_003824E0(-1.0f, 1.0f);
        random.y = func_003824E0(-1.0f, 1.0f);
        random.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&random, &random, 0.075f);
        vec_add_ab(out, out, &random);
    }
    if (input->timer >= 6) func_L01_002FDC18(owner, func_00382498(64, 128), points, 25);
    else func_L01_002FDC18(owner, func_00382498(0, 64), points, 25);
}
/* localdecomp:end func_L01_002FDA10 */
