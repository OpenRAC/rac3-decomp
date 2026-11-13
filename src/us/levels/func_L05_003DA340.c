#include "common.h"

/* NTSC-U counterpart of func_L05_003DC798 (src/levels/05_daxx/L05_003DC5B8.c): 0.02 -> 0.0166667; 133 -> 160; 83 -> 100 */
/* localdecomp:start func_L05_003DA340 */
#include "vu0.h"
typedef struct {
    char pad0[0x10];
    vu0_v4 pos;
    u8 f20;
    char pad21[3];
    void *f24;
    char pad28[4];
    f32 f2C;
    char pad30[0x66];
    u16 f96;
} S_3DC900;
typedef struct {
    char pad0[0x24];
    f32 f24;
} S2_3DC798;

extern s32 func_00382468(s32);
extern void func_00382580(void *, f32, f32);
extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L05_003DA340(S_3DC900 *p, f32 c) {
    f32 t = p->f2C / ((S2_3DC798 *)p->f24)->f24;
    s32 r = func_00382468(100);
    s32 i;
    vu0_v4 out;
    vu0_v4 pos = p->pos;
    vu0_v4 vel;
    vu0_v4 tmp;
    qzero(&vel);
    pos.z += t * 7.5f;
    for (i = 0; i < t * 100.0f; i++) {
        vel.z = 0.0166666675f;
        func_00382580(&tmp, t * 4.5f, t * 5.5f);
        vec_add_ab(&out, &pos, &tmp);
        func_L01_00460318(&out, &vel, 0x80B0B0B0, 0x606060, func_00382468(0xA0) + 0x64, r + 0x12C, r + 0x190, 0);
    }
}
/* localdecomp:end func_L05_003DA340 */
