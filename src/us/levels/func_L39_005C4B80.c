#include "common.h"

/* NTSC-U counterpart of func_L39_005C6E90 (src/levels/shared/L39_005C6E90.c): calls func_0019D650, NTSC-U data addresses */
/* localdecomp:start func_L39_005C4B80 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005C4B80;

typedef struct {
    V_005C4B80 v;
    s32 color;
    s32 endcolor;
    u8 a;
    u8 c;
    u8 b;
    u8 life;
    f32 size;
} Q_005C4B80;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 color;
    u8 f8;
    u8 f9;
    s16 life;
    f32 fC;
    V_005C4B80 pos;
    Q_005C4B80 q;
} P_005C4B80;

extern f32 D_L39_0024BC48;
extern f32 D_L39_0024BC4C;
extern u8 *D_L39_00296944[];
extern s32 func_L39_005B2498(s32);
extern void *func_003C7B98(s32);
extern s32 func_0019D650(void);
extern f32 func_L39_005B2510(f32, f32);
extern void func_00388830(void *, void *, f32);

/* from rac2-decomp's func_002BBCB0 */
void *func_L39_005C4B80(V_005C4B80 *pos, V_005C4B80 *vel, s32 color, s32 endcolor, s32 life, s32 a,
                        s32 b, f32 size, f32 jitter, s32 c) {
    P_005C4B80 *p;
    Q_005C4B80 *q;
    V_005C4B80 u;
    V_005C4B80 t;

    if (life == 0) {
        return 0;
    }
    if ((0.85f < D_L39_0024BC48 || 0.85f < D_L39_0024BC4C) && func_L39_005B2498(3) == 0) {
        return 0;
    }
    if ((0.9f < D_L39_0024BC48 || 0.9f < D_L39_0024BC4C) && func_L39_005B2498(2) == 0) {
        return 0;
    }
    if ((1.0f < D_L39_0024BC48 || 1.0f < D_L39_0024BC4C) && func_L39_005B2498(1) == 0) {
        return 0;
    }
    p = func_003C7B98(0xB);
    if (p != 0) {
        p->pos = *pos;
        p->color = color;
        p->f9 = 0xA4;
        p->f3 = func_L39_005B2498(100) < 20 ? 0x44 : 0x48;
        p->f1 = 0;
        p->fC = 0;
        p->f8 = func_0019D650();
        p->f2 = *D_L39_00296944[0];
        q = &p->q;
        t = (V_005C4B80){0};
        t.x = func_L39_005B2510(-1.0f, 1.0f);
        t.y = func_L39_005B2510(-1.0f, 1.0f);
        t.z = func_L39_005B2510(-1.0f, 1.0f);
        u = t;
        func_00388830(&u, &u, jitter);
        vec_add_ab(&q->v, vel, &u);
        q->v.w = jitter * 0.75f;
        p->life = life;
        q->life = life;
        q->a = a;
        q->size = size;
        q->color = color;
        q->endcolor = endcolor;
        q->b = b;
        q->c = c;
    }
    return p;
}
/* localdecomp:end func_L39_005C4B80 */
