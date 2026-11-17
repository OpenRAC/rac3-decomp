#include "common.h"

/* localdecomp:start func_L39_00603658 */
typedef struct { u8 b[8]; } V8_00603658;
typedef struct { u8 b[24]; } V24_00603658;
typedef struct { f32 x, y; } F2_00603658;
typedef struct { s32 v[6]; } I6_00603658;
typedef struct {
    f32 *pos;            /* 0x0 */
    u8 p4[4];
    u32 *col;            /* 0x8 */
    u32 *c;              /* 0xC */
    u8 r1[0x3C];         /* 0x10 */
    u8 r2[0x13C];        /* 0x4C */
    s32 f188;
    s32 f18C;
    s32 f190;
    u8 p194[8];
    s32 f19C;
    u8 p1A0[4];
    s32 f1A4;
    u8 p1A8[8];
    f32 f1B0;
    u8 p1B4[4];
    s32 f1B8[1];
} O_00603658;
__asm__(".extern D_L39_002454B4, 4");
extern V8_00603658 D_L39_002454A0 __attribute__((section(".data")));
extern V8_00603658 D_L39_002454A8 __attribute__((section(".data")));
extern V24_00603658 D_L39_002454B8;
extern V24_00603658 D_L39_002454D0;
extern s32 *D_L39_00241120;
extern s32 D_L39_00241470;
extern f32 D_L39_002454B0;
extern f32 D_L39_002454B4;
extern f32 D_L39_00241150[] __attribute__((section(".sdata")));
extern void func_0038C310(s32, s32, s32, s32, s32, void *);
extern void func_0038E150(s32);
extern void func_0038E7E8(unsigned long, s32, s32, f32, f32, f32, f32, s32, s32, unsigned long, f32, f32);
extern void func_003AAED0(void *, f32, f32, f32, f32);
extern void func_003AAFF8(void *, f32, f32, f32, f32);
extern void func_L39_006015C0(void *);

static __inline__ u32 setAlpha_00603658(u32 c, s32 a) {
    return (c & 0xFFFFFF) | (a << 24);
}

void func_L39_00603658(O_00603658 *o) {
    u32 colors[4];
    F2_00603658 A;
    F2_00603658 B;
    I6_00603658 C1;
    I6_00603658 C2;
    f32 s;
    f32 sc;
    s32 ix, iy;
    s32 i, save, step;
    u32 c;
    s32 al;
    c = *o->col;
    al = c >> 24;
    if (al > 0x60) al = 0x60;
    c = setAlpha_00603658(c, al);
    colors[0] = c; colors[1] = c; colors[2] = c; colors[3] = c;
    func_0038C310((s32)(o->pos[0] - o->f188), (s32)(o->pos[1] - o->f18C),
                  (s32)(o->pos[0] + o->f188 + 2.0f), (s32)(o->pos[1] + o->f18C),
                  0xFFFFF0, colors);
    *(V8_00603658 *)&A = D_L39_002454A0;
    *(V8_00603658 *)&B = D_L39_002454A8;
    s = 1.0f;
    if (o->f1A4 == 0) {
        s = (*D_L39_00241120 >= 3) ? D_L39_002454B4 : D_L39_002454B0;
    }
    sc = 1.0f;
    if (*D_L39_00241120 >= 2) {
        sc = D_L39_00241150[*D_L39_00241120 - 1] / D_L39_00241150[0];
    }
    step = 16;
    i = 0;
    func_003AAED0(o->r1, o->pos[0] - o->f188 - A.x, o->pos[1] - o->f18C - A.y, 0.0f, 0.0f);
    func_003AAFF8(o->r1, -s, s, 0.0f, 0.0f);
    func_L39_006015C0(o->r1);
    func_003AAED0(o->r1, o->pos[0] + o->f188 + A.x + 1.0f, o->pos[1] - o->f18C - A.y, 0.0f, 0.0f);
    func_003AAFF8(o->r1, s, s, 0.0f, 0.0f);
    func_L39_006015C0(o->r1);
    func_003AAED0(o->r2, o->pos[0] + o->f188 + B.x, o->pos[1] - o->f18C - B.y, 0.0f, 0.0f);
    func_003AAFF8(o->r2, s, s, 0.0f, 0.0f);
    func_L39_006015C0(o->r2);
    func_003AAED0(o->r2, o->pos[0] - o->f188 - B.x + 1.0f, o->pos[1] - o->f18C - B.y, 0.0f, 0.0f);
    func_003AAFF8(o->r2, -s, s, 0.0f, 0.0f);
    func_L39_006015C0(o->r2);
    func_003AAED0(o->r2, o->pos[0] + o->f188 + B.x, o->pos[1] - o->f18C - B.y + o->f1B0, 0.0f, 0.0f);
    func_003AAFF8(o->r2, s, -s, 0.0f, 0.0f);
    func_L39_006015C0(o->r2);
    func_003AAED0(o->r2, o->pos[0] - o->f188 - B.x + 1.0f, o->pos[1] - o->f18C - B.y + o->f1B0, 0.0f, 0.0f);
    func_003AAFF8(o->r2, -s, -s, 0.0f, 0.0f);
    func_L39_006015C0(o->r2);
    ix = (s32)(o->pos[0] - o->f188 + o->f19C);
    iy = (s32)(o->pos[1] - o->f18C);
    *(V24_00603658 *)&C1 = D_L39_002454B8;
    *(V24_00603658 *)&C2 = D_L39_002454D0;
    switch (o->f1A4) {
    case 0:
        if (o->f1B8[0] != 0 && o->f190 > 0) {
            for (; i < o->f190; i++) {
                save = D_L39_00241470;
                func_0038E150(1);
                func_0038E7E8(*o->c, o->f1B8[i], -1, (f32)(ix + C2.v[2]), (f32)(iy + C2.v[3] + i * step), 1.0f, 1.0f,
                              0, 1, 0x80000000, 2.0f, 2.0f);
                func_0038E150(save);
            }
        }
        break;
    case 1:
        if (o->f1B8[0] != 0 && o->f190 > 0) {
            for (; i < o->f190; i++) {
                func_0038E150(1);
                if (*D_L39_00241120 >= 2) {
                    func_0038E7E8(*o->c, o->f1B8[i], -1, (f32)ix + C1.v[2], (f32)iy + C1.v[3] + (f32)(i * step), sc, sc,
                                  0, 1, 0x80000000, 1.0f, 1.0f);
                } else {
                    func_0038E7E8(*o->c, o->f1B8[i], -1, (f32)(ix + C1.v[2]), (f32)(iy + C1.v[3] + i * step + 2), 1.0f, 1.0f,
                                  0, 1, 0x80000000, 2.0f, 2.0f);
                }
            }
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_L39_00603658 */
