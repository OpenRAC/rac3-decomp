#include "common.h"
#include "vu0.h"

/* declared by functions of L05_003AFC08.c, which this file was cut from */
extern f32 func_003824E0(f32, f32);

/* localdecomp:start func_L05_003B1A40 */
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_00382538(void);
extern s32 func_L05_0043F7E0(void *, void *, void *, void *, void *, void *, void *, f32);
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x370];
    vu0_v4 v380;
    u8 pad390[0x98];
    f32 scale;
} G_003B1A40;
extern G_003B1A40 D_L05_001E2700_003B1A40;
extern u8 D_L05_001D9AE0[8];
extern f32 D_001DE7B0_sda[2];
__asm__(".extern D_001DE7B0_sda, 4");

void func_L05_003B1A40(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    vu0_v4 *src = &D_L05_001E2700_003B1A40.v380;
    vu0_v4 dir;
    vu0_v4 base;
    vu0_v4 tgt;
    f32 t[2];
    vu0_v4 hit[2];
    s32 i;
    s32 best;
    f32 r;
    f32 c;

    r = func_003824E0(-0.5f, 0.5f);
    func_0038D890(&dir, src, D_L05_001D9AE0, r * D_L05_001E2700_003B1A40.scale);
    *(vu0_q *)&base = *(vu0_q *)&D_L05_001E2700_003B1A40.pos;
    dir.z = 0;
    func_0038CF68(&dir, &dir, 300.0f);
    vec_add_ab(&tgt, &base, &dir);
    func_L05_0043F7E0(&hit[0], &hit[1], &t[0], &t[1], &base, &tgt, D_001DE7B0_sda, *(f32 *)(p + 0x28C));
    best = -1;
    for (i = 0; i < 2; i++) {
        if (0.0f < t[i]) {
            best = i;
        }
    }
    if (best == -1) {
        *(f32 *)(p + 0x27C) = func_00382538();
    } else {
        *(f32 *)(p + 0x27C) = func_0038D160(hit[best].x - D_001DE7B0_sda[0], hit[best].y - D_001DE7B0_sda[1]);
    }
    c = 1.76f;
    *(f32 *)(p + 0x290) = func_003824E0(-c, c) + 22.0f;
    c = 1.1f;
    *(f32 *)(p + 0x284) = func_003824E0(-c, c) + 5.5f;
}
/* localdecomp:end func_L05_003B1A40 */
