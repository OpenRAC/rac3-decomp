#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern s32 D_L30_001DF2C0;
extern f32 func_0038D098(f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

/* declared by functions of L30_00350EF0.c, which this file was cut from */
extern u8 D_L30_001E1380;
extern void func_L30_003510C8(u8 *, u8 *);

/* localdecomp:start func_L30_003510C8 */
#include "vu0.h"
typedef int q_003510C8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003510C8;
typedef struct {
    u8 p0[0x10];
    V_003510C8 pos;   /* 0x10 */
    u8 p20[0x68 - 0x20];
    u8 *vars;         /* 0x68 */
} M_003510C8;
typedef struct {
    M_003510C8 *moby; /* 0x0 */
    void *p4;
    s16 h8;
    u16 hA;
    u8 pC[4];
    f32 f10;
    f32 f14;
    f32 f18;
} A_003510C8;
typedef struct {
    u8 p0[4];
    s32 i4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    V_003510C8 v10;
    V_003510C8 v20;
    u8 p30[0x3C - 0x30];
    f32 f3C;
} O_003510C8;
typedef struct { u8 p0[0x18]; void *hit; } C_003510C8;

__asm__(".extern D_L30_001DD860, 4");
__asm__(".extern D_L30_001DD864, 4");
__asm__(".extern D_L30_001DD874, 4");
__asm__(".extern D_L30_001DD878, 4");
__asm__(".extern D_L30_001DD87C, 4");
__asm__(".extern D_L30_001DD880, 4");
__asm__(".extern D_L30_001DD884, 4");
__asm__(".extern D_L30_001DD890, 4");
__asm__(".extern D_L30_001DD898, 4");
__asm__(".extern D_L30_001DD8A0, 4");
__asm__(".extern D_L30_001DD8A4, 4");
__asm__(".extern D_L30_001DD8A8, 4");
__asm__(".extern D_L30_001DD8E0, 4");
__asm__(".extern D_L30_001DD8E4, 4");
__asm__(".extern D_L30_001DD8E8, 4");
__asm__(".extern D_L30_001DD8EC, 4");
extern f32 D_L30_001DD860;
extern f32 D_L30_001DD864;
extern f32 D_L30_001DD874;
extern u32 D_L30_001DD878;
extern u32 D_L30_001DD87C;
extern f32 D_L30_001DD880;
extern f32 D_L30_001DD884;
extern f32 D_L30_001DD890;
extern f32 D_L30_001DD898;
extern f32 D_L30_001DD8A0;
extern f32 D_L30_001DD8A4;
extern f32 D_L30_001DD8A8;
extern f32 D_L30_001DD8E0;
extern f32 D_L30_001DD8E4;
extern f32 D_L30_001DD8E8;
extern f32 D_L30_001DD8EC;
extern s32 D_L30_001E138C;
extern C_003510C8 D_L30_001E9000;
__asm__(".extern D_L30_001DF2C0, 16");
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);
extern O_003510C8 *func_L30_00442950(void *, void *, s32, s32);
extern s32 func_0038DBD8(f32, u32, u32);

void func_L30_003510C8(u8 *arg0, u8 *arg1) {
    O_003510C8 *o = (O_003510C8 *)arg0;
    A_003510C8 *a = (A_003510C8 *)arg1;
    M_003510C8 *m;
    u8 *vars;
    void *g;
    f32 t;
    V_003510C8 *pos;
    V_003510C8 p;
    V_003510C8 w;

    if (a == 0) return;
    m = a->moby;
    g = a->p4;
    vars = m->vars;
    if (m == 0) return;
    if (g == 0) return;
    if (a->hA & 1) {
        V_003510C8 off;
        f32 ang;
        f32 dir;
        f32 s;
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        *(q_003510C8 *)&o->v10 = *(q_003510C8 *)&m->pos;
        off.x = func_0038D098(ang) * D_L30_001DD898;
        off.z = func_0038D0B0(ang) * D_L30_001DD898;
        off.y = 0.0f;
        vec_add_ba(&o->v10, &o->v10, &off);
        dir = func_0038DAB8(func_0038DB48(func_003824E0(-D_L30_001DD864, D_L30_001DD864)), *(f32 *)(vars + 0x18));
        a->f18 = func_003824E0(0.0f, 1.0f);
        s = func_003824E0(D_L30_001DD8A0, D_L30_001DD8A4);
        w.x = func_0038D098(dir) * s;
        w.z = func_0038D0B0(dir) * s;
        w.y = 0.0f;
        a->f14 = w.z;
        a->f10 = w.x;
        a->h8 += (s32)(5.0f / s);
        o->hA = a->h8;
    }
    pos = &o->v10;
    t = func_L03_0034B148(o->hA, a->h8, 0.0f);
    *(q_003510C8 *)&p = *(q_003510C8 *)pos;
    p.x += a->f10;
    p.z += a->f14;
    if ((D_L30_001DF2C0 & 0xF) == (((s32)o >> 8) & 0xF) &&
        func_003D3CB0(pos, &p, 1, m, 0) != 0 && D_L30_001E9000.hit != 0) {
        qzero(&w);
        w.x = a->f10;
        w.z = a->f14;
        func_L30_0034CB68((s32)a->moby, (u8 *)&w, 0, -1, (s32)pos, 0, D_L30_001DD860, D_L30_001DD874);
    }
    *(q_003510C8 *)&o->v10 = *(q_003510C8 *)&p;
    a->f18 += func_003C4088(D_L30_001DD8E8, D_L30_001DD8EC, t);
    if (a->f18 >= 1.0f) {
        O_003510C8 *n;
        f32 ang;
        f32 s;
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        s = func_003824E0(0.0f, func_003C4088(D_L30_001DD8E4, D_L30_001DD8E0, t));
        a->f18 -= 1.0f;
        n = func_L30_00442950(m, &D_L30_001E1380, func_00382498(*(s16 *)(&D_L30_001E1380 + 2), *(s16 *)&D_L30_001E1380), D_L30_001E138C);
        if (n != 0) {
            w.x = func_0038D098(ang) * s;
            w.z = func_0038D0B0(ang) * s;
            w.y = 0.0f;
            n->v10.x = w.x + o->v10.x;
            n->v10.y = o->v10.y;
            n->v10.z = w.z + o->v10.z;
            n->v20.x = n->v10.x;
            n->v20.y = n->v10.y;
            n->v20.z = n->v10.z;
            n->f3C = a->f10 * D_L30_001DD8A8;
        }
    }
    a->f14 += D_L30_001DD884;
    o->i4 = func_0038DBD8((f32)o->hA / (f32)a->h8, D_L30_001DD87C, D_L30_001DD878);
    o->i4 = (o->i4 & 0xFFFFFF) + ((s32)(func_L03_0034B148(a->h8 - o->hA, a->h8, D_L30_001DD880) * 128.0f) << 24);
    o->b8 = 0;
    o->fC = D_L30_001DD890;
}
/* localdecomp:end func_L30_003510C8 */
