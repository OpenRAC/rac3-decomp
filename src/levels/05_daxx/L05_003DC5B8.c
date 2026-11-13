#include "common.h"

/* localdecomp:start func_L05_003DC5B8 */
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

extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L05_003DC520(void *, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L05_003DC5B8(void *q, s32 a, s32 b, f32 c) {
    S_3DC5B8 *p = q;
    V4_3DC5B8 tmp;
    f32 d;

    func_003A52A0(0, 0, p);
    func_L01_00451FE0(p, a, D_L05_001D66B0, 4.0f, 6.0f, 7.0f, 9.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (b != 0) {
        func_L05_003DC520(p, b);
    }
    d = p->f2C / p->f24->f24;
    tmp = p->f10;
    tmp.z = tmp.z + d * 7.5f;
    func_L01_003303B8(&tmp, 1, 0xF, 0, 0, 2, 5, 2, d * 4.0f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 1, 0, 0x1000000, 0, 0x608020, 0x808020, 0x204080, 0x203080, 0, 0, 0x80408020, 0x28001080, 0x808020, 0);
    func_L01_00451E78(p, 1, 0.0f);
}
/* localdecomp:end func_L05_003DC5B8 */

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
void func_L05_003DC5B8(void *q, s32 a, s32 b, f32 c);
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

/* localdecomp:start func_L05_003DC9E8 */
extern s32 D_L05_001DF1C8;
__asm__(".extern D_L05_001DF1C0, 4");
extern s32 D_L05_001DF1C0;
__asm__(".extern D_L05_001DF190, 4");
extern f32 D_L05_001DF190;
extern void func_L01_004450F0(S_3DC900 *p, s32 a, s32 b);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);

void func_L05_003DC9E8(S_3DC900 *p) {
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
    if ((D_L05_001DF1C8 * 5 + 2) / 6 < p->f96) {
        func_L01_004450F0(p, 1, -1);
        return;
    }
    t = p->f2C / ((S2_3DC798 *)p->f24)->f24;
    for (i = 0; i < 3; i++) {
        if (p->f96 < ((&D_L05_001DF1C0)[i] * 5 + 2) / 6) {
            r = func_00382468(30);
            e = &(&D_L05_001DF190)[i * 4];
            pos = p->pos;
            func_0038CF68(&tmp, (u8 *)p + 0xC0, t * e[0]);
            vec_add_ba(&pos, &pos, &tmp);
            func_0038CF68(&tmp, (u8 *)p + 0xD0, t * e[1]);
            vec_add_ab(&pos, &pos, &tmp);
            pos.z += t * e[2];
            qzero(&vel);
            func_0038CF68(&vel, (u8 *)p + 0xC0, -0.0200000014f);
            func_003C4C18(&vel, 0.0200000014f);
            vel.z += 0.0600000024f;
            func_L01_004637C8(&pos, &vel, 0x80808080, 0x202020, 0x2A, r + 0x1E, r + 0x64, 1);
        }
    }
}
/* localdecomp:end func_L05_003DC9E8 */
