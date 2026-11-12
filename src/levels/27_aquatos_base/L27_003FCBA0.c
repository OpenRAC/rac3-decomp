#include "common.h"

/* localdecomp:start func_L27_003FCBA0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_FCBA0;
typedef int u128_FCBA0 __attribute__((mode(TI)));
typedef struct { s16 h0; s16 h2; f32 f4; f32 f8; f32 fC; f32 f10; s32 f14; s32 f18; s32 f1C; } S_FCBA0;
extern S_FCBA0 D_L27_001D6C20;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L27_003FCBA0(void *arg0, s32 arg1) {
    u8 m[0x40] __attribute__((aligned(16)));
    V4_FCBA0 pos;
    V4_FCBA0 vec;
    S_FCBA0 cfg;
    u8 *r;
    V4_FCBA0 *pp;
    s32 y;
    s32 x;
    s32 z;
    *(u128_FCBA0 *)&vec = 0;
    vec.z = -1.0f;
    cfg = D_L27_001D6C20;
    func_003C2EC0(arg0, arg1, m);
    pos = *(V4_FCBA0 *)(m + 0x30);
    func_0038D028(&vec, &vec, m);
    func_0038CF68(&vec, &vec, func_003824E0(cfg.f10, cfg.fC));
    pp = &pos;
    x = cfg.h0 + func_00382468(cfg.h2);
    y = (s32)cfg.f8;
    z = (s32)cfg.f4 + func_00382468(2);
    r = func_L01_004637C8(pp, &vec, cfg.f14, cfg.f18, x, y, z, 0);
    if (r) r[9] = 0x40;
    r = func_L01_004637C8(pp, &vec, 0x80002080, cfg.f18, (s32)((f32)(cfg.h0 + func_00382468(cfg.h2)) * 0.75f), (s32)cfg.f8 >> 1, (s32)cfg.f4 >> 1, 1);
    if (r) r[9] = 0x40;
}
/* localdecomp:end func_L27_003FCBA0 */
