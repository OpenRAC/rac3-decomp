#include "common.h"

/* NTSC-U counterpart of func_L05_003DC9E8 (src/levels/05_daxx/L05_003DC5B8.c) */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3DC5B8;
typedef struct {
    char pad0[0x24];
    float f24;
} P_3DC5B8;
typedef struct {
    char pad0[0x10];
    V4_3DC5B8 f10;
    u8 f20;
    char pad1[3];
    P_3DC5B8 *f24;
    char pad2[4];
    float f2C;
    char pad3[0x96 - 0x30];
    u16 f96;
} S_3DC5B8;
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
extern s32 func_0037E1D8(s32);
extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
void func_L05_003DC5B8_003DA590(void *q, s32 a, s32 b, f32 c);
void func_L05_003DC798_003DA590(S_3DC900 *p, f32 c);
s32 func_L01_00447490_003DA590(S_3DC900 *p, s32 a, s32 b);
void func_L01_00441FB8(S_3DC900 *p, s32 a, s32 b);
void func_003C2880(S_3DC900 *p);

/* localdecomp:start func_L05_003DA590 */
extern s32 D_L05_001DF208;
__asm__(".extern D_L05_001DF200, 4");
extern s32 D_L05_001DF200;
__asm__(".extern D_L05_001DF1D0, 4");
extern f32 D_L05_001DF1D0;
extern void func_L01_00441FB8(S_3DC900 *p, s32 a, s32 b);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);

void func_L05_003DA590(S_3DC900 *p) {
    f32 t;
    s32 i;
    s32 r;
    f32 *e;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 tmp;

    if (p->f20 != 0) {
        return;
    }
    (*(u16 *)((u8 *)p + 0x96))++;
    if (D_L05_001DF208 < p->f96) {
        func_L01_00441FB8(p, 1, -1);
        return;
    }
    t = p->f2C / ((S2_3DC798 *)p->f24)->f24;
    for (i = 0; i < 3; i++) {
        if (p->f96 < (&D_L05_001DF200)[i]) {
            r = func_0037E1D8(30);
            e = &(&D_L05_001DF1D0)[i * 4];
            pos = p->pos;
            func_00388830(&tmp, (u8 *)p + 0xC0, t * e[0]);
            vec_add_ba(&pos, &pos, &tmp);
            func_00388830(&tmp, (u8 *)p + 0xD0, t * e[1]);
            vec_add_ab(&pos, &pos, &tmp);
            pos.z += t * e[2];
            qzero(&vel);
            func_00388830(&vel, (u8 *)p + 0xC0, -0.016666668f);
            func_003BF6A8(&vel, 0.016666668f);
            vel.z += 0.050000004f;
            func_L01_00460318(&pos, &vel, 0x80808080, 0x202020, 0x32, r + 0x1E, r + 0x64, 1);
        }
    }
}
/* localdecomp:end func_L05_003DA590 */
