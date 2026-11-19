#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[3];
    u8 b3;
    s32 w4;
    u8 pad8[2];
    s16 hA;
    s32 wC;
    vu0_v4 v10;
    vu0_v4 v20;
} P_0034FC30;
typedef struct {
    u8 *moby;
    s32 w4;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 padB;
    f32 fC;
} Q_0034FC30;

/* localdecomp:start func_L30_0034F1A8 */
#include "vu0.h"
typedef int u128_34F1A8 __attribute__((mode(TI)));
typedef struct { f32 x0; u8 pad4[4]; f32 x8; u8 padC[4]; s32 x10; f32 x14; s32 x18; f32 x1C; } V_34F1A8;
typedef struct { u8 pad[0x10]; u128_34F1A8 pos; u8 pad20[0x10]; u8 x30; u8 pad31[0x34 - 0x31]; u16 x34; u8 pad36[0x68 - 0x36]; V_34F1A8 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_34F1A8;
__asm__(".extern D_L30_001DD5FC, 4");
__asm__(".extern D_L30_001DD608, 4");
__asm__(".extern D_L30_001DD614, 4");
__asm__(".extern D_L30_001DD618, 4");
extern f32 D_L30_001DD5FC;
extern s32 D_L30_001DD608;
extern f32 D_L30_001DD614;
extern f32 D_L30_001DD618;
extern u128_34F1A8 D_L30_001E9020_0034F1A8;
extern void *func_003C24B0_0034F1A8(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DB30(O_34F1A8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

O_34F1A8 *func_L30_0034F1A8(u128_34F1A8 *pos, f32 ang) {
    O_34F1A8 *o = func_003C24B0_0034F1A8(0x1678, 0x80);
    V_34F1A8 *v;

    if (o == 0) {
        return 0;
    }
    o->pos = *pos;
    o->x30 = 255;
    v = o->x68;
    qzero(v);
    v->x0 = func_0038D098(ang) * D_L30_001DD614;
    v->x8 = (func_0038D0B0(ang) + D_L30_001DD618) * D_L30_001DD614;
    v->x10 = 0;
    v->x14 = ang;
    v->x18 = D_L30_001DD608;
    v->x1C = ang;
    if (func_L30_0034DB30(o) != 0) {
        o->pos = D_L30_001E9020_0034F1A8;
        v->x10++;
        func_003A52A0(0, 0, o);
        v->x0 *= -D_L30_001DD5FC;
    }
    o->x98 = 0;
    o->x34 = (o->x34 | 0x41) & ~0x1000;
    func_L01_004AA7E8(o, 1);
    func_L01_004450F0(o, 0, -1);
    return o;
}
/* localdecomp:end func_L30_0034F1A8 */

INCLUDE_ASM("asm/levels", func_L30_0034F2D8);

INCLUDE_ASM("asm/levels", func_L30_0034F5D8);

/* localdecomp:start func_L30_0034F998 */
extern s32 D_L30_001DD608;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
typedef struct {
    u8 *moby;
    s32 w4;
    u8 b8;
    u8 b9;
    u16 hA;
} Q_0034F998; /* the object Q_0034FC30 describes, read here with bytes 0xA-0xB as one u16 */
typedef struct {
    u8 pad0[0x18];
    s32 x18;
    f32 f1C;
} V_0034F998;
__asm__(".extern D_L30_001DD664, 4");
__asm__(".extern D_L30_001DD668, 4");
__asm__(".extern D_L30_001DD66C, 4");
__asm__(".extern D_L30_001DD678, 4");
__asm__(".extern D_L30_001DD67C, 4");
__asm__(".extern D_L30_001DD688, 4");
extern s32 D_L30_001DD664;
extern s32 D_L30_001DD668;
extern s32 D_L30_001DD66C;
extern f32 D_L30_001DD678;
extern f32 D_L30_001DD67C;
extern f32 D_L30_001DD688;
extern u8 D_L30_001E12C0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD608, 4");
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L30_0034F998(P_0034FC30 *p, Q_0034F998 *q) {
    u8 *o;
    u8 *sys;
    V_0034F998 *v;
    vu0_v4 c;
    f32 t;
    f32 a;
    f32 b;
    f32 a2;
    f32 b2;
    f32 k;
    s32 flag;

    if (q == 0) {
        return;
    }
    o = q->moby;
    v = *(V_0034F998 **)(o + 0x68);
    sys = D_L30_001E12C0;
    if (o == 0 || v == 0 || sys == 0) {
        return;
    }
    t = 1.0f - p->hA * 0.25f / q->b8;
    a = (D_L30_001DD678 + 1.0f) * t;
    if (1.0f < a) {
        a = 1.0f;
    }
    b = (D_L30_001DD678 + 1.0f) * t - D_L30_001DD678;
    if (b < 0.0f) {
        b = 0.0f;
    }
    flag = q->hA & 1;
    c.x = func_0038D098(v->f1C) * D_L30_001DD67C;
    c.z = func_0038D0B0(v->f1C) * D_L30_001DD67C;
    c.y = 0.0f;
    if (flag) {
        vec_add_ab(&c, o + 0x10, &c);
    } else {
        vec_sub_ab(&c, o + 0x10, &c);
    }
    a2 = func_0038DAB8(func_0038DAB8(v->f1C, 3.1415927f), a * 6.2831855f);
    b2 = func_0038DAB8(func_0038DAB8(v->f1C, 3.1415927f), b * 6.2831855f);
    p->v10.x = func_0038D098(a2) * D_L30_001DD67C;
    p->v10.z = func_0038D0B0(a2) * D_L30_001DD67C;
    p->v10.y = 0.0f;
    vec_add_ba(&p->v10, &p->v10, &c);
    p->v20.x = func_0038D098(b2) * D_L30_001DD67C;
    p->v20.z = func_0038D0B0(b2) * D_L30_001DD67C;
    p->v20.y = 0.0f;
    vec_add_ba(&p->v20, &p->v20, &c);
    p->v20.w = 1.0f;
    p->v10.w = D_L30_001DD688;
    k = 1.0f - (f32)v->x18 / (f32)D_L30_001DD608;
    if (0.5f < k) {
        p->w4 = p->wC = func_0038DBD8(D_L30_001DD668, D_L30_001DD664, (k - 0.5f) * 2.0f);
    } else {
        p->w4 = p->wC = func_0038DBD8(D_L30_001DD66C, D_L30_001DD668, k * 2.0f);
    }
}
/* localdecomp:end func_L30_0034F998 */

/* localdecomp:start func_L30_0034FC30 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
__asm__(".extern D_L30_001DD68C, 4");
__asm__(".extern D_L30_001DD690, 4");
__asm__(".extern D_L30_001DD69C, 4");
__asm__(".extern D_L30_001DD6A0, 4");
__asm__(".extern D_L30_001DD6AC, 4");
__asm__(".extern D_L30_001DD6B0, 4");
__asm__(".extern D_L30_001DD6B4, 4");
__asm__(".extern D_L30_001DD6B8, 1");
extern s32 D_L30_001DD68C;
extern s32 D_L30_001DD690;
extern f32 D_L30_001DD69C;
extern f32 D_L30_001DD6A0;
extern f32 D_L30_001DD6AC;
extern f32 D_L30_001DD6B0;
extern f32 D_L30_001DD6B4;
extern u8 D_L30_001DD6B8;
extern u8 D_L30_001E12E0[] __attribute__((section(".sdata")));
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

void func_L30_0034FC30(P_0034FC30 *p, Q_0034FC30 *q) {
    u8 *o;
    u8 *sys;
    void *v;
    f32 fade;
    f32 r;
    s32 c;

    if (q == 0) {
        return;
    }
    o = q->moby;
    v = *(void **)(o + 0x68);
    sys = D_L30_001E12E0;
    if (o == 0 || v == 0 || sys == 0) {
        return;
    }
    if (q->b9 & 1) {
        q->fC = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        p->w4 = func_L30_0034DBA0(D_L30_001DD68C, D_L30_001DD690);
        p->wC = func_L30_0034DBA0(D_L30_001DD68C, D_L30_001DD690);
        p->b3 = D_L30_001DD6B8;
    }
    fade = func_L03_0034B148(p->hA, q->b8 << 2, D_L30_001DD6B4);
    r = func_003C4088(D_L30_001DD6A0, D_L30_001DD69C, q->bA * 0.00390625f);
    p->v10.x = func_0038D098(q->fC) * (r * fade);
    p->v10.z = func_0038D0B0(q->fC) * (r * fade);
    p->v10.y = 0.0f;
    vec_add_ba(&p->v10, &p->v10, o + 0x10);
    p->v20.x = func_0038D098(q->fC) * (-r * fade);
    p->v20.z = func_0038D0B0(q->fC) * (-r * fade);
    p->v20.y = 0.0f;
    vec_add_ba(&p->v20, &p->v20, o + 0x10);
    p->v10.w = D_L30_001DD6AC;
    p->v20.w = 1.0f;
    c = (s32)((1.0f - func_L03_0034B148(p->hA, q->b8 << 2, D_L30_001DD6B0)) * 128.0f) << 24;
    p->w4 = (p->w4 & 0xFFFFFF) + c;
    p->wC = (p->wC & 0xFFFFFF) + c;
}
/* localdecomp:end func_L30_0034FC30 */

/* localdecomp:start func_L30_0034FE30 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
__asm__(".extern D_L30_001DD6BC, 4");
__asm__(".extern D_L30_001DD6C0, 4");
__asm__(".extern D_L30_001DD6C4, 4");
__asm__(".extern D_L30_001DD6C8, 4");
__asm__(".extern D_L30_001DD6D4, 4");
__asm__(".extern D_L30_001DD6D8, 4");
__asm__(".extern D_L30_001DD6E4, 4");
extern s32 D_L30_001DD6BC;
extern s32 D_L30_001DD6C0;
extern f32 D_L30_001DD6C4;
extern f32 D_L30_001DD6C8;
extern f32 D_L30_001DD6D4;
extern f32 D_L30_001DD6D8;
extern f32 D_L30_001DD6E4;
extern u8 D_L30_001E1300[] __attribute__((section(".sdata")));
extern s32 func_0038DBD8(s32, s32, f32);

void func_L30_0034FE30(P_0034FC30 *p, Q_0034FC30 *q) {
    u8 *o;
    u8 *sys;
    void *v;
    f32 t;
    f32 a;
    f32 b;
    f32 w;

    if (q == 0) {
        return;
    }
    o = q->moby;
    v = *(void **)(o + 0x68);
    sys = D_L30_001E1300;
    if (o == 0 || v == 0 || sys == 0) {
        return;
    }
    if (q->b9 & 1) {
        q->fC = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
    }
    t = 1.0f - p->hA * 0.25f / q->b8;
    a = (D_L30_001DD6D4 + 1.0f) * t;
    if (1.0f < a) {
        a = 1.0f;
    }
    b = (D_L30_001DD6D4 + 1.0f) * t - D_L30_001DD6D4;
    if (b < 0.0f) {
        b = 0.0f;
    }
    w = D_L30_001DD6C8 * q->bA * 0.00390625f;
    p->v10.x = func_0038D098(q->fC) * (D_L30_001DD6D8 * a + w);
    p->v10.z = func_0038D0B0(q->fC) * (D_L30_001DD6D8 * a + w);
    p->v10.y = 0.0f;
    vec_add_ba(&p->v10, &p->v10, o + 0x10);
    p->v20.x = func_0038D098(q->fC) * (D_L30_001DD6D8 * b + w);
    p->v20.z = func_0038D0B0(q->fC) * (D_L30_001DD6D8 * b + w);
    p->v20.y = 0.0f;
    vec_add_ba(&p->v20, &p->v20, o + 0x10);
    p->v10.w = D_L30_001DD6E4;
    p->v20.w = D_L30_001DD6C4;
    p->w4 = func_0038DBD8(D_L30_001DD6C0, D_L30_001DD6BC, a);
    p->wC = func_0038DBD8(D_L30_001DD6C0, D_L30_001DD6BC, b);
}
/* localdecomp:end func_L30_0034FE30 */
