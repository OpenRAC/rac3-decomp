#include "common.h"

/* NTSC-U counterpart of func_003BFD40 (src/boot_elf/text/3BFD40.c): the frame step is 1/60.0f and the lifetime is not rescaled to 50 Hz */
/* localdecomp:start func_U_003BFC50 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t start, end;
    f32 f20, f24, f28;
    s32 color0, color1;
    s32 min, max;
    s32 flag;
    s32 time0, time1, owner, kind;
} Particle_003BFC50;
extern f32 func_U_003828E0(f32, f32);
extern s32 func_U_00382898(s32, s32);
extern void func_U_003A85C0(s32, s32);
extern s32 func_U_0038DF00(s32, s32, f32);
extern f32 func_U_00382938(void);
extern void func_U_003BFBA8(s32, u8 *);

void func_U_003BFC50(s32 owner, u128_t *start, u128_t *end) {
    Particle_003BFC50 p;

    func_U_003A85C0(owner, 0x502020);
    p.color1 = p.color0 = func_U_0038DF00(0x7F2F00, 0x800000, func_U_003828E0(0.0f, 1.0f));
    p.max = p.min = func_U_00382898(31, 63);
    p.f28 = func_U_003828E0(0.1f, 0.8f);
    p.start = *start;
    p.end = *end;
    p.f24 = func_U_00382938();
    p.f20 = func_U_003828E0(90.0f, 180.0f) * 0.017453292f * 0.016666668f;
    p.time0 = p.time1 = func_U_00382898(150, 180);
    p.kind = 5;
    p.flag = 1;
    func_U_003BFBA8(owner, (u8 *)&p);
}
/* localdecomp:end func_U_003BFC50 */
