#include "common.h"

/* localdecomp:start func_L39_0054D5F8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054D5F8;
typedef struct {
    u8 p0[0x18]; u8 *w18; u8 p1C[0x20 - 0x1C]; V4_0054D5F8 v20; u8 p30[0x34 - 0x30]; s32 w34; s32 w38; f32 f3C;
    u8 p40[0x50 - 0x40]; V4_0054D5F8 v50;
} P_0054D5F8;
typedef struct {
    u8 p0[0x10]; V4_0054D5F8 pos; u8 b20; u8 p21[0x30 - 0x21]; u8 b30; u8 b31; s16 h32; u16 h34;
    u8 p36[0x68 - 0x36]; P_0054D5F8 *p68; u8 p6C[0xB8 - 0x6C]; s32 wB8;
} O_0054D5F8;

extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_0054DD90(void *, u8 *);

void *func_L39_0054D5F8(V4_0054D5F8 *arg0, V4_0054D5F8 *arg1, V4_0054D5F8 *arg2, s32 arg3, s32 arg4, u8 *arg5) {
    V4_0054D5F8 tmp;
    O_0054D5F8 *obj;
    P_0054D5F8 *p;
    V4_0054D5F8 *pos;

    obj = (O_0054D5F8 *)func_003C24B0(0x1093, 0x80);
    if (obj != 0) {
        p = obj->p68;
        obj->wB8 = arg4;
        obj->b20 = 0;
        obj->b30 = 0xFF;
        obj->h32 = 0xFF;
        obj->b31 = 1;
        obj->h34 |= 0x41;
        pos = &obj->pos;
        func_0038CF68(&p->v20, arg1, 0.16000001f);
        *(vu0_q *)pos = *(vu0_q *)arg2;
        func_0038CF68(&tmp, &p->v20, -1.5f);
        vec_add_ab(&p->v50, arg0, &tmp);
        p->w34 = arg3;
        p->w18 = arg5;
        p->f3C = 0.058823530f;
        p->w38 = 0x11;
        func_L39_0054DD90(pos, arg5);
    }
    return obj;
}
/* localdecomp:end func_L39_0054D5F8 */

/* localdecomp:start func_L39_0054D728 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054D728;
typedef int Q_0054D728 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x20]; V4_0054D728 v20; u8 p30[0x38 - 0x30]; u8 t38[0x50 - 0x38]; V4_0054D728 v50;
} P_0054D728;
typedef struct {
    u8 p0[0x10]; V4_0054D728 pos; u8 b20; u8 p21[0x68 - 0x21]; P_0054D728 *p68;
} O_0054D728;

extern f32 D_L39_0024B09C __attribute__((section(".sdata")));
extern f32 D_L39_0024B0A0 __attribute__((section(".sdata")));
extern f32 D_L39_0024B0A4 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B09C, 4");
__asm__(".extern D_L39_0024B0A0, 4");
__asm__(".extern D_L39_0024B0A4, 4");
extern u8 D_L39_00242930[] __attribute__((section(".sdata")));
extern u8 *D_L39_002968EC __attribute__((section(".data")));
extern void func_L39_005BC330(void *, void *, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern s32 func_L39_005B4398(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00404A10(void *, void *);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L39_0054D9D8(void *);

void func_L39_0054D728(O_0054D728 *o) {
    V4_0054D728 old;
    V4_0054D728 t;
    V4_0054D728 cur;
    V4_0054D728 s;
    f32 res[4];
    P_0054D728 *p;
    u8 *r;
    s32 k;

    p = o->p68;
    *(Q_0054D728 *)&old = *(Q_0054D728 *)&o->pos;
    func_L39_005BC330(&o->pos, &t, 1);
    *(Q_0054D728 *)&cur = *(Q_0054D728 *)&o->pos;
    if (o->b20 == 0) {
        vec_add_ab(&p->v50, &p->v50, &p->v20);
        if (func_0038CAD0(p->t38) != 0) {
            func_003C2880(o);
            return;
        }
        *(Q_0054D728 *)&s = *(Q_0054D728 *)&o->pos;
        s.w = 0.5f;
        if (func_L39_005BE900(&s, (s32)res, D_L39_0024B0A4) > 0) {
            if (res[0] < D_L39_0024B09C * D_L39_0024B09C) {
                k = func_L39_005B4398(0xFF);
                r = func_L01_0046FB40(&o->pos, D_L39_00242930, 2, 0x202080, k, 0x40, 0x10, 420000.0f, 420000.0f, 0.0f, 0);
                if (r != 0) {
                    r[2] = *D_L39_002968EC;
                }
                k = (k + 0x80) % 0xFF;
                r = func_L01_0046FB40(&o->pos, D_L39_00242930, 2, 0x202080, k, 0x40, 0x10, 420000.0f, 420000.0f, 0.0f, 0);
                if (r != 0) {
                    r[2] = *D_L39_002968EC;
                }
            } else if (res[0] < D_L39_0024B0A0 * D_L39_0024B0A0) {
                k = func_L39_005B4398(0xFF);
                r = func_L01_0046FB40(&o->pos, D_L39_00242930, 2, 0x202080, k, 0x40, 0x10, 420000.0f, 420000.0f, 0.0f, 0);
                if (r != 0) {
                    r[2] = *D_L39_002968EC;
                }
            }
            func_L01_00404A10(func_L39_0054D9D8, o);
        }
    }
    if (o->pos.x < 2.0f || o->pos.x > 1021.0f || o->pos.y < 2.0f || o->pos.y > 1021.0f || o->pos.z < 2.0f || o->pos.z > 1021.0f) {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L39_0054D728 */

/* localdecomp:start func_L39_0054D9D8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054D9D8;
typedef struct {
    V4_0054D9D8 v[4];
    u32 col[4];
    f32 uv[8];
    u8 p70[0x20];
} __attribute__((aligned(16))) Prim_0054D9D8;
typedef struct {
    u8 p0[0x18]; u8 *w18; u8 p1C[0x30 - 0x1C]; f32 f30; u8 p34[0x38 - 0x34]; s32 i38; f32 f3C;
    u8 p40[0x50 - 0x40]; V4_0054D9D8 v50;
} P_0054D9D8;
typedef struct {
    u8 p0[0x10]; V4_0054D9D8 pos; u8 b20; u8 p21[0x68 - 0x21]; P_0054D9D8 *p68;
} O_0054D9D8;

extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);

void func_L39_0054D9D8(void *arg0) {
    O_0054D9D8 *o = arg0;
    Prim_0054D9D8 q;
    V4_0054D9D8 dir;
    V4_0054D9D8 fwd;
    V4_0054D9D8 end;
    V4_0054D9D8 side;
    P_0054D9D8 *p;
    f32 a;
    s32 i;

    if (o == 0 || o->b20 == 0xFE || o->b20 == 0xFD) {
        return;
    }
    p = o->p68;
    if (p == 0) {
        return;
    }
    a = (f32)p->i38 * p->f3C;
    func_003D93B0(&q, 0x17, 0, 0x80);
    q.col[1] = ((s32)(a * 64.0f) << 24) | 0x108080;
    q.col[0] = ((s32)(a * 64.0f) << 24) | 0x108080;
    q.col[3] = ((s32)(a * 64.0f) << 24) | 0x101080;
    q.col[2] = ((s32)(a * 64.0f) << 24) | 0x101080;
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = 1.0f;
    q.uv[4] = 1.0f;
    q.uv[5] = 0.0f;
    q.uv[6] = 1.0f;
    q.uv[7] = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i * 2] = q.uv[i * 2] - p->f30;
        if (q.uv[i * 2] <= 7.0f) {
            q.uv[i * 2] = q.uv[i * 2] + 7.0f;
        }
    }
    p->f30 = p->f30 + 0.1f;
    if (4.0f <= p->f30) {
        p->f30 = p->f30 - 4.0f;
    }
    vec_sub_ab(&dir, &o->pos, p->w18 + 0x23A0);
    vec_sub_ba(&fwd, &p->v50, &o->pos);
    func_0038CE20(&fwd, &fwd, 0.5f);
    vec_add_ba(&end, &o->pos, &fwd);
    func_0038CE90(&side, &dir, &fwd);
    func_0038CF68(&side, &side, 0.1f);
    vec_add_ba(&q.v[0], &o->pos, &side);
    vec_sub_ab(&q.v[1], &o->pos, &side);
    vec_add_ba(&q.v[2], &end, &side);
    vec_sub_ab(&q.v[3], &end, &side);
    func_003D2DA0(&q, 0, 0);
    q.col[0] = q.col[2];
    q.col[1] = q.col[3];
    q.col[3] = 0x108080;
    q.col[2] = 0x108080;
    *(vu0_q *)&q.v[0] = *(vu0_q *)&q.v[2];
    *(vu0_q *)&q.v[1] = *(vu0_q *)&q.v[3];
    vec_add_ba(&q.v[2], &q.v[2], &fwd);
    vec_add_ab(&q.v[3], &q.v[3], &fwd);
    func_003D2DA0(&q, 0, 0);
    func_003D93B0(&q, 0xE, 1, 0x80);
    q.col[1] = ((s32)(a * 64.0f) << 24) | 0x40FF;
    q.col[0] = ((s32)(a * 64.0f) << 24) | 0x40FF;
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = 1.0f;
    q.uv[4] = 1.0f;
    q.uv[5] = 0.0f;
    q.uv[6] = 1.0f;
    q.uv[7] = 1.0f;
    q.col[3] = 0x40FF;
    q.col[2] = 0x40FF;
    func_0038CF68(&side, &side, 0.6f);
    vec_add_ba(&q.v[0], &o->pos, &side);
    vec_sub_ab(&q.v[1], &o->pos, &side);
    vec_add_ab(&end, &o->pos, &fwd);
    vec_add_ba(&end, &end, &fwd);
    vec_add_ab(&q.v[2], &end, &side);
    vec_sub_ab(&q.v[3], &end, &side);
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L39_0054D9D8 */

/* localdecomp:start func_L39_0054DD90 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054DD90;
typedef int Q_0054DD90 __attribute__((mode(TI)));

extern f32 D_L39_0024B090 __attribute__((section(".sdata")));
extern f32 D_L39_0024B094 __attribute__((section(".sdata")));
extern f32 D_L39_0024B098 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B090, 4");
__asm__(".extern D_L39_0024B094, 4");
__asm__(".extern D_L39_0024B098, 4");
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_0054DD90(void *pos, u8 *arg1) {
    V4_0054DD90 *arg0 = pos;
    V4_0054DD90 d;
    V4_0054DD90 s;
    V4_0054DD90 v;
    V4_0054DD90 pos;
    f32 res[4];
    f32 ang;
    f32 scale;
    f32 pitch;
    s32 n;
    f32 speed;
    s32 life;
    s32 i;
    f32 yaw;

    n = 15;
    vec_sub_ab(&d, arg1 + 0x23A0, arg0);
    ang = func_0038D160(d.x, d.y);
    *(Q_0054DD90 *)&s = *(Q_0054DD90 *)arg0;
    s.w = 0.5f;
    if (func_L39_005BE900(&s, (s32)res, D_L39_0024B098) > 0) {
        if (!(res[0] < D_L39_0024B090 * D_L39_0024B090)) {
            if (res[0] < D_L39_0024B094 * D_L39_0024B094) {
                n = 10;
            } else {
                n = 5;
            }
        }
    } else {
        n = 0;
    }
    for (i = 0; i < n; i++) {
        scale = func_L39_005B4410(0.5f, 1.0f);
        life = func_L39_005B4468(1.0f, 2.0f);
        speed = func_L39_005B4410(0.05f, 0.2f) * 210000.0f;
        pitch = func_L39_005B4410(0.0f, 1.3962634f);
        yaw = func_0038DAB8(ang, func_L39_005B4468(0.0f, 1.3962634f));
        func_00382760(&v, scale * 0.020000001f, yaw, pitch);
        pos.x = arg0->x + func_L39_005B4468(0.0f, 0.1f);
        pos.y = arg0->y + func_L39_005B4468(0.0f, 0.1f);
        pos.z = arg0->z + func_L39_005B4468(0.0f, 0.1f);
        speed = func_L39_005B4410(0.05f, 0.2f) * 210000.0f;
        func_L01_0046A610(&pos, &v, 0x19, 0x7F, 0x7F7F7F, life, speed, 500.0f, 1.0f, 0.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_0054DD90 */

INCLUDE_ASM("asm/levels", func_L39_0054E010);

INCLUDE_ASM("asm/levels", func_L39_0054F4E0);
