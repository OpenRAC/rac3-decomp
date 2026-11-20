#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3BF5B0.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BF8E0(s32 a0, u8 *src);

/* localdecomp:start func_003BF988 */
typedef struct {
    u128_t q0;
    u128_t q10;
    f32 f20; f32 f24; f32 f28; s32 w2C; s32 w30; s32 w34; s32 w38; s32 w3C; s32 w40; s32 w44; s32 w48; s32 w4C;
} P_003BF988;
extern void func_003BF8E0(s32, u8 *);
extern void func_003A8308(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_003BF988(s32 a0, u128_t *a1, u128_t *a2) {
    P_003BF988 p;
    s32 c, r;

    func_003A8308(a0, 0x502020);
    c = func_0038DBD8(0x7F2F00, 0x800000, func_003824E0(0.0f, 1.0f));
    p.w2C = c;
    p.w30 = c;
    c = func_00382498(0x1F, 0x3F);
    p.w34 = c;
    p.w38 = c;
    p.f28 = func_003824E0(0.1f, 0.8f);
    p.q0 = *a1;
    p.q10 = *a2;
    p.f24 = func_00382538();
    p.f20 = func_003824E0(90.0f, 180.0f) * 0.017453292f * 0.020000001f;
    r = func_00382498(150, 180);
    p.w4C = 5;
    p.w3C = 1;
    r = (r * 5 + 2) / 6;
    p.w44 = r;
    p.w40 = r;
    func_003BF8E0(a0, (u8 *)&p);
}
/* localdecomp:end func_003BF988 */
