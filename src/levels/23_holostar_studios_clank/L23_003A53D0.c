#include "common.h"
typedef struct {
    u8 pad0[0xAA];
    s16 xAA;
} Moby_3A5590;
typedef struct {
    u8 pad0[0x64];
    void *update;
} Spawn_3A5590;
typedef struct {
    u8 pad0[0x98];
    f32 x98;
    u8 pad9C[0x110 - 0x9C];
    u8 x110[0x10];
    u8 pad120[0x258 - 0x120];
    f32 x258;
    u8 pad25C[0x2A8 - 0x25C];
    s32 x2A8;
    u8 x2AC[0x24];
    u8 x2D0[0x10];
} S_3A53D0;
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A5750;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3A5750;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3A5750 paths[1]; } Paths_3A5750;
typedef struct { u8 pad0[0x30]; V4_3A5750 pos; u8 pad40[0x40]; } Node_3A5750;

/* localdecomp:start func_L23_003A53D0 */
extern f32 D_L23_001DE0A0;
__asm__(".extern D_L23_001DE0A0, 4");
extern f32 D_L23_001DE088;
__asm__(".extern D_L23_001DE088, 4");
extern s32 D_L23_001DEC40;
extern f32 func_003824E0(f32, f32);
extern s32 func_L23_003A5750(u8 *, s32, f32 *, void *, void *, s32);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_003C5060(void *, void *, void *, void *);
extern f32 func_0038D160(f32, f32);


void func_L23_003A53D0(u8 *m, f32 *out, f32 speed, f32 scale)
{
    S_3A53D0 *v = *(S_3A53D0 **)(m + 0x68);
    f32 t[4];

    v->x98 = scale * D_L23_001DE0A0;
    out[2] = v->x258 + func_003824E0(-D_L23_001DE088, D_L23_001DE088);
    if (m[0x95] == 0) {
        out[2] += 3.0f;
    }
    if (m[0x95] == 1) {
        out[2] += 2.5f;
    }
    if (m[0x20] == 3) {
        out[2] += 2.0f;
    }
    if (v->x258 - *(f32 *)(m + 0x18) > D_L23_001DE088) {
        out[0] = *(f32 *)(m + 0x10);
        out[1] = *(f32 *)(m + 0x14);
    }
    if ((D_L23_001DEC40 & 0x1F) == (((s32)m >> 8) & 0x1F)) {
        func_L23_003A5750(m, v->x2A8, out, v->x2D0, v->x2AC, 0);
    }
    func_L01_0045A748(m, out);
    func_L01_0045BD10(m, speed);
    if (m[0x31] != 0) {
        func_003C5060(m, t, v->x110, 0);
        *(f32 *)(m + 0xF0) = func_0038D160(v->x98, t[1]) / -2.5f;
        *(f32 *)(m + 0xF4) = func_0038D160(v->x98, t[0]) / 2.5f;
    }
}
/* localdecomp:end func_L23_003A53D0 */

/* localdecomp:start func_L23_003A5590 */
extern float D_L23_001DE028;
__asm__(".extern D_L23_001DE028, 4");
extern f32 D_L23_001DE05C;
__asm__(".extern D_L23_001DE05C, 4");
extern f32 D_L23_001DE060;
__asm__(".extern D_L23_001DE060, 4");
extern void func_L01_00439880(void *, u16 *, s32 *);
extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern Spawn_3A5590 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_002FFF00(void);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L23_003A5590(u8 *self)
{
    f32 vec[4];
    u16 id;
    s32 count;
    Spawn_3A5590 *s;

    func_L01_00439880(self, &id, &count);
    while (count > 0) {
        count--;
        func_L01_00443B88(vec, D_L23_001DE05C, D_L23_001DE060);
        vec[2] = func_003824E0(-D_L23_001DE05C, D_L23_001DE05C);
        s = func_L01_003F79D8(self, 1, ((Moby_3A5590 *)self)->xAA, count, self + 0x10, self + 0xF0, vec, 0xFF, 30.0f, 15.0f, 0xB4, 0, 0x80);
        s->update = func_L01_002FFF00;
    }
    func_003A52A0(1, 0, self);
    func_L01_003303B8(self + 0x10, 0, 10, 10, 0, 10, 40, 2, D_L23_001DE028 * 3.0f, 0.0f, 0.0f, 2.0f,
                      1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_L01_004450F0(self, 7, 4);
}
/* localdecomp:end func_L23_003A5590 */

/* localdecomp:start func_L23_003A5750 */
#include "vu0.h"
extern Paths_3A5750 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3A5750 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");
extern f32 D_L23_001DE08C;
__asm__(".extern D_L23_001DE08C, 4");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);

s32 func_L23_003A5750(u8 *m, s32 idx, f32 *out, void *a3, void *a4, s32 flag)
{
    V4_3A5750 *home = a3;
    s32 *cur = a4;
    Path_3A5750 *path;
    V4_3A5750 pos;
    V4_3A5750 tgt;
    V4_3A5750 dir;
    f32 d;
    f32 nd;
    f32 lim;
    s32 best;
    s32 i;
    s32 id;
    Node_3A5750 *e;

    if (idx >= 0 && idx < D_L23_001DED4C->count) {
    path = &D_L23_001DED4C->paths[idx];
    pos = *(V4_3A5750 *)(m + 0x10);
    tgt = *(V4_3A5750 *)out;
    d = func_L01_0040E570(&pos, &tgt);
    vec_sub_ab(&dir, &tgt, &pos);
    func_0038CE20(&dir, &dir, sqrt_asm(d));
    if (flag == 0 && func_003D3CB0(&pos, &tgt, 2, m, 0) == 0) {
        *cur = -1;
        *home = *(V4_3A5750 *)out;
        return 1;
    }
    lim = d * 10.0f;
    best = -1;
    for (i = 0; i < path->count; i++) {
        id = path->ids[i];
        e = &D_L23_001DF240[id];
        if (id == *cur)
            continue;
        if (func_00382380(&pos, id, 0) != 0) {
            *cur = path->ids[i];
            continue;
        }
        nd = func_L01_0040E570(&tgt, &e->pos);
        if (lim < nd)
            continue;
        if (func_003D3CB0(&pos, &e->pos, 0, m, 0) != 0)
            continue;
        lim = nd;
        best = i;
    }
    if (best < 0) {
        if (func_L01_0040E570(out, home) > D_L23_001DE08C)
            *(V4_3A5750 *)out = *home;
        else
            return 0;
    } else {
        *(V4_3A5750 *)out = D_L23_001DF240[path->ids[best]].pos;
    }
    }
    return 1;
}
/* localdecomp:end func_L23_003A5750 */
