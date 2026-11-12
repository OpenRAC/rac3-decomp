#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003DC5B8);

/* localdecomp:start func_L05_003DC798 */
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
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L05_003DC798(S_3DC900 *p, f32 c) {
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
        vel.z = 0.0200000014f;
        func_00382580(&tmp, t * 4.5f, t * 5.5f);
        vec_add_ab(&out, &pos, &tmp);
        func_L01_004637C8(&out, &vel, 0x80B0B0B0, 0x606060, func_00382468(0x85) + 0x53, r + 0x12C, r + 0x190, 0);
    }
}
/* localdecomp:end func_L05_003DC798 */

/* localdecomp:start func_L05_003DC900 */
void func_L05_003DC5B8(S_3DC900 *p, s32 a, s32 b, f32 c);
void func_L05_003DC798(S_3DC900 *p, f32 c);
s32 func_L01_00447490(S_3DC900 *p, s32 a, s32 b);
void func_L01_004450F0(S_3DC900 *p, s32 a, s32 b);
void func_003C2880(S_3DC900 *p);

void func_L05_003DC900(S_3DC900 *p) {
    switch (p->f20) {
    case 0:
        if (func_L01_00447490(p, -1, 0) != 0) {
            func_L05_003DC5B8(p, 0x1FF, 0x1EA7, 7.5f);
            func_L01_004450F0(p, 2, -1);
        }
        break;
    case 1: {
        s32 v = p->f96 + 1;
        p->f96 = v;
        if ((u16)v >= 0x1E) {
            func_L01_004450F0(p, 2, -1);
        }
        break;
    }
    case 2:
        func_L05_003DC798(p, 7.5f);
        func_L01_004450F0(p, 3, -1);
        break;
    case 3:
        func_003C2880(p);
        break;
    }
}
/* localdecomp:end func_L05_003DC900 */

INCLUDE_ASM("asm/levels", func_L05_003DC9E8);
