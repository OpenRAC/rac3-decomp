#include "common.h"

/* NTSC-U counterpart of func_003BF988 (src/frontbin/3BF988.c): 1/60.0f per frame for 0.02f, the random count used as it is (no (r * 5 + 2) / 6) */
/* localdecomp:start func_U_003BA490 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q0;
    u128_t q10;
    f32 f20; f32 f24; f32 f28; s32 w2C; s32 w30; s32 w34; s32 w38; s32 w3C; s32 w40; s32 w44; s32 w48; s32 w4C;
} P_003BA490;
extern void func_U_003BA3E8(s32, u8 *);
extern void func_U_003A2EE0(s32, s32);
extern f32 func_U_0037E250(f32, f32);
extern f32 func_U_0037E2A8(void);
extern s32 func_U_0037E208(s32, s32);
extern s32 func_U_003894A0(s32, s32, f32);

void func_U_003BA490(s32 a0, u128_t *a1, u128_t *a2) {
    P_003BA490 p;
    s32 c, r;

    func_U_003A2EE0(a0, 0x502020);
    c = func_U_003894A0(0x7F2F00, 0x800000, func_U_0037E250(0.0f, 1.0f));
    p.w2C = c;
    p.w30 = c;
    c = func_U_0037E208(0x1F, 0x3F);
    p.w34 = c;
    p.w38 = c;
    p.f28 = func_U_0037E250(0.1f, 0.8f);
    p.q0 = *a1;
    p.q10 = *a2;
    p.f24 = func_U_0037E2A8();
    p.f20 = func_U_0037E250(90.0f, 180.0f) * 0.017453292f * 0.016666668f;
    r = func_U_0037E208(150, 180);
    p.w44 = r;
    p.w40 = r;
    p.w4C = 5;
    p.w3C = 1;
    func_U_003BA3E8(a0, (u8 *)&p);
}
/* localdecomp:end func_U_003BA490 */
