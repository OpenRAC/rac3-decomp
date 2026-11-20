#include "common.h"

/* NTSC-U counterpart of func_003F0038 (src/frontbin/3EE160.c): the size is passed unscaled (no 1.0769231 for PAL) */
/* localdecomp:start func_U_003EAAD0 */
typedef struct { u8 pad[0x20]; void (*f20)(void *, s32, f32 *, s32); } V_003EAAD0;
typedef struct {
    u8 p0[8]; V_003EAAD0 *vt; u8 pC[0x14]; f32 f20, f24; u32 f28; u8 p2C[0x10]; s32 f3C; u8 p40[0x10]; u32 f50; u8 p54[8]; f32 f5C, f60;
} O_003EAAD0;
extern f32 D_U_001D96D8;
extern f32 D_U_001D96DC;
extern f32 D_U_001D96F4;
extern void func_U_00389FB8_003EAAD0(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern void func_U_003E8788(void *a, f32 *b);
extern s32 func_U_003E8590(void *, s32);
void func_U_003EAAD0(O_003EAAD0 *p, s32 a1) {
    f32 r[4];
    f32 cy, cx, s, d;
    f32 ox, oy, z;
    s32 has;
    unsigned long a0, a5; s32 a1_; f32 e;
    if (p->f3C == 0) return;
    z = 0.0f; ox = 0.0f; has = 0; oy = 0.0f;
    p->vt->f20(p, a1, r, 1);
    func_U_003E8788(p, r);
    cx = r[0] + (r[2] - r[0]) * 0.5f;
    cy = r[1] + (r[3] - r[1]) * 0.5f;
    if (func_U_003E8590(p, 0x40)) {
        ox = p->f20;
        has = 1;
        oy = p->f24;
    }
    s = p->f60;
    d = D_U_001D96F4 * s;
    a5 = p->f28; a1_ = p->f3C; e = p->f5C; a0 = p->f50;
    if (has) {
        func_U_00389FB8_003EAAD0(a0, a1_, -1, 1, has, a5,
            (f32)(s32)(cx * D_U_001D96D8), (f32)(s32)((cy - d) * D_U_001D96DC),
            e, s, ox * D_U_001D96D8, oy * D_U_001D96DC);
    } else {
        func_U_00389FB8_003EAAD0(a0, a1_, -1, 1, has, a5,
            (f32)(s32)(cx * D_U_001D96D8), (f32)(s32)((cy - d) * D_U_001D96DC),
            e, s, z, z);
    }
}
/* localdecomp:end func_U_003EAAD0 */
