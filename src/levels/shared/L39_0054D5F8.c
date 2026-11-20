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

/* localdecomp:start func_L39_0054E010 */
#include "vu0.h"
typedef int Q_0054E010 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0054E010;

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_0054E010;

typedef struct {
    u8 p0[0x10C]; f32 f10C; u8 p110[0x134 - 0x110]; f32 f134; u8 p138[0x13C - 0x138]; f32 f13C;
} Pad_0054E010;

typedef struct O_0054E010 {
    u8 p0[0x14];
    void **vt;
    u8 p18[0x170 - 0x18];
    Q_0054E010 q170;
    u8 p180[0x3B0 - 0x180];
    V_0054E010 v3B0;
    u8 p3C0[0x3E0 - 0x3C0];
    s32 w3E0;
    u8 p3E4[0x474 - 0x3E4];
    s32 w474;
    u8 p478[0x1078 - 0x478];
    s32 w1078;
    u8 p107C[0x122C - 0x107C];
    s32 w122C;
    u8 p1230[0x1250 - 0x1230];
    f32 f1250;
    u8 p1254[0x1280 - 0x1254];
    u16 h1280;
    u8 p1282[0x12C0 - 0x1282];
    f32 f12C0;
    u8 p12C4[0x1338 - 0x12C4];
    s32 w1338;
    s32 w133C;
    u8 p1340[0x19E4 - 0x1340];
    u8 b19E4;
    u8 p19E5;
    u8 b19E6;
    u8 p19E7[0x1A07 - 0x19E7];
    u8 b1A07;
    u8 b1A08;
    u8 p1A09[0x1A0D - 0x1A09];
    u8 b1A0D;
    u8 p1A0E[0x1A14 - 0x1A0E];
    u8 b1A14;
    u8 p1A15[0x1A40 - 0x1A15];
    u8 b1A40[0x2470 - 0x1A40];
    s32 w2470;
    u8 p2474[0x24C9 - 0x2474];
    u8 b24C9;
    u8 p24CA[0x24FE - 0x24CA];
    u8 b24FE;
    u8 p24FF;
    u8 b2500;
    u8 p2501[0x2534 - 0x2501];
    Pad_0054E010 *pad;
    u8 p2538[0x2544 - 0x2538];
    s32 w2544;
} O_0054E010;

typedef struct {
    s16 h0;
    u8 p2[2];
    f32 f4;
    f32 f8;
    f32 fC;
    s32 w10;
    s32 w14;
    u8 p18[0x20 - 0x18];
    s32 w20;
    s32 w24;
    u8 p28[0x2C - 0x28];
    s16 h2C;
    s16 h2E;
    s32 w30;
    u8 p34[0x3C - 0x34];
    O_0054E010 *o;
    V_0054E010 v40;
} M_0054E010;

typedef struct {
    u8 p0[0x10];
    V_0054E010 pos;
    u8 b20;
    u8 p21[0x31 - 0x21];
    u8 b31;
    u8 p32[2];
    u16 h34;
    u8 p36[0x42 - 0x36];
    u8 b42;
    u8 b43;
    u8 p44[0x60 - 0x44];
    u8 b60;
    u8 p61[0x68 - 0x61];
    M_0054E010 *m;
    u8 p6C[0xD0 - 0x6C];
    V_0054E010 vD0;
} Self_0054E010;

typedef struct {
    u8 p0[0x26];
    u8 b26;
    u8 p27[0x2C - 0x27];
    u32 w2C;
    f32 x30, y30, z30;
    f32 x3C, y3C, z3C;
    u8 p48[0x50 - 0x48];
} S_0054E010;

typedef struct {
    u8 p0[0xD0];
    u8 bD0;
    u8 pD1[0xDC - 0xD1];
    void *owner;
} Slot_0054E010;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    V_0054E010 v10;
} Info_0054E010;

extern u8 D_L39_004997E0[];
extern f32 D_L39_0024B0A8[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B0B8[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B0C8[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B0D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0A8, 4");
__asm__(".extern D_L39_0024B0B8, 4");
__asm__(".extern D_L39_0024B0C8, 4");
__asm__(".extern D_L39_0024B0D8, 4");
extern f32 D_L39_0024B700[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B710[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B720[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B730[] __attribute__((section(".sdata")));
extern s32 D_001D7AE8_sda;
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern s32 D_L39_0024BD14[2];
extern f32 D_L39_0025D770[];
typedef struct { u8 pA4[0xA4]; u8 flags[0x100]; } Tab_0054E010;
extern Tab_0054E010 D_001A5810;
extern u8 D_001FE020[];
extern u8 D_L39_00470600[];
extern Info_0054E010 D_L39_002667C0[];

extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004B14C8(s32);
extern void func_L01_00404AD8(void *, void *);
extern void func_L39_0054FAB8(u8 *);
extern s32 func_L39_00620CF8(u8 *, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L39_00639D90(void *);
extern u32 func_L39_005FFD20(void *, void *, s32, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L39_0061C4D0(u8 *, u8 **);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3088(s32);
extern s32 func_L39_006732D0(void *p, s32 a1, s32 a2, s32 a3);
extern void func_L39_00621D60(void *, s32);
extern s32 func_L01_003F2058(void *, void *);
extern u8 *func_L39_0061D1D8(s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L39_00550638(u8 *, f32 *);
extern u8 *func_00382348(void *);
extern void func_L01_00511158(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L39_00632678(u8 *, f32 *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L39_0054F4E0(u8 *, u8 *, s32, s32, s32);
extern void func_L01_003F2278(s32, void *);
extern s32 func_L01_0040E050(void *);
extern void func_L01_00424D88(s32);
extern s32 func_L39_0059EA90(void *, s32, f32, f32);

/* the obfuscated byte at p, decoded (key table D_L39_004997E0) */
static __inline__ u32 decode_0054E010(u8 *p) {
    Buf_0054E010 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

/* player state (o->b19E4, decoded) == 0x1D */
static __inline__ s32 respawning_0054E010(O_0054E010 *o) {
    Buf_0054E010 buf;
    u8 *p = &o->b19E4;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;
    u32 r;

    if (*p == 0) {
        r = 0;
    } else {
        n = *p;
        k = ((u32)p - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)p;
        r = buf.w[1] ^ buf.w[0];
        buf.w[1] = r;
    }
    return (r ^ 0x1D) == 0;
}

/* the player is on this console */
static __inline__ s32 isLocal_0054E010(O_0054E010 *o) {
    return o->b1A14;
}

/* set the local player's camera field of view */
static __inline__ void camera_0054E010(O_0054E010 *o, f32 fov, f32 speed, f32 b) {
    if (o->b1A14 != 0) {
        func_00382810(o->b24C9, 0, 3, fov, speed, b, 0.0f);
    }
}

static __inline__ void vset_0054E010(V_0054E010 *v, f32 *src) {
    v->x = src[0];
    v->y = src[1];
    v->z = src[2];
    v->w = 0.0f;
}

void func_L39_0054E010(u8 *arg0) {
    Self_0054E010 *self = (Self_0054E010 *)arg0;
    V_0054E010 pos0;
    M_0054E010 *m;
    O_0054E010 *o;
    u8 *ent;
    u8 *obj;
    O_0054E010 *hero;
    u8 *q;
    f32 dist;
    f32 f;
    f32 k;
    s32 snd;
    s32 busy;
    s32 idx;
    s32 flag;
    s32 res;
    O_0054E010 *veh;
    s32 fl;
    s32 flag2;

    m = self->m;
    o = m->o;
    if (self->b42 == self->b43 && (self->b60 & 2)) {
        func_L01_00444F38(arg0, 1, 0, 2, 0);
    }
    if (o != 0 && o->w474 == 3) {
        if (self->b20 == 0) {
            return;
        }
        idx = o->b24C9;
        if (isLocal_0054E010(o)) {
            D_L39_0024B710[idx] = D_L39_0024B0A8[idx];
            D_L39_0024B720[idx] = D_L39_0024B0B8[idx];
            D_L39_0024B730[idx] = D_L39_0024B0C8[idx];
            D_L39_0024B700[idx] = D_L39_0024B0D8[idx];
            func_00382810(idx, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
            D_001D7AE8_sda = 0xE0;
            func_L01_004B14C8(1);
        }
        if (m->w10 >= 0) {
            func_L01_00424D88(m->w10);
        }
        m->w10 = -1;
        return;
    }
    pos0 = self->pos;
    if (o != 0 && respawning_0054E010(o) && self->b20 != 0) {
        if (isLocal_0054E010(o)) {
            self->b31 = 0;
            self->h34 |= 1;
            func_L01_00404AD8(func_L39_0054FAB8, arg0);
            if (*D_L39_00241120 == 1) {
                D_L39_0024BD14[1] = 1;
            }
        }
        if (o->b1A08 == 0 && o->f1250 >= 1.0f) {
            m->h2C = 1;
            m->w30 = o->w122C;
        } else {
            m->h2C = 0;
            m->w30 = 0;
        }
        if (o->w2470 == 0 && m->h2C != 0) {
            m->h2E++;
            if (m->h2E >= 0x1A) {
                m->h2E = 0;
            }
            if (m->f4 <= 0.0f && func_L39_00620CF8((u8 *)o, -1) != 0 && m->h2E >= 5 && isLocal_0054E010(o)) {
                func_L01_003F6F20(o->b24C9, self, 0x200000FF, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f,
                                  40.0f, 40.0f);
            }
        }
    } else if (o != 0) {
        if (func_L39_00639D90(o) != 0) {
            u32 c = func_L39_005FFD20(&o->w1338, &o->w133C, 0, 150.0f);

            if (isLocal_0054E010(o)) {
                func_L01_003F6F20(o->b24C9, self, c, 0, 0x20, -1, 4, 0.5f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f,
                                  40.0f);
            }
        }
        if (o != 0 && isLocal_0054E010(o)) {
            D_L39_0024BD14[1] = 0;
        }
    }
    switch (self->b20) {
    case 0:
        m->h0 = 0;
        m->f4 = 0.36666667f;
        self->b20 = 2;
        {
            f32 t = func_0038D160(1.0f, D_L39_0025D770[0]) * 2.0f;

            m->f8 = t;
            m->fC = t + (0.17453292f - t) * 0.25f;
        }
        func_L39_0061C4D0(arg0, (u8 **)&m->o);
        o = m->o;
        if (isLocal_0054E010(o)) {
            s32 n = o->b24C9;

            D_L39_0024B0A8[n] = D_L39_0024B710[n];
            D_L39_0024B0B8[n] = D_L39_0024B720[n];
            D_L39_0024B0C8[n] = D_L39_0024B730[n];
            D_L39_0024B0D8[n] = D_L39_0024B700[n];
        }
        m->w14 = 0;
        m->w10 = -1;
        m->w20 = -1;
        m->w24 = -1;
        m->h2C = 0;
        m->h2E = 0;
        m->w30 = 0;
        break;
    case 1: {
        V_0054E010 a;
        V_0054E010 b;

        flag = 0;
        if ((decode_0054E010(&o->b19E4) ^ 1) == 0) {
            ((void (*)(void *, s32, s32, s32, s32))o->vt[0x34 / 4])(o, 0x1D, 1, 0, 1);
        }
        busy = 0;
        if ((decode_0054E010(&o->b19E4) ^ 1) == 0 || respawning_0054E010(o) || o->b24FE != 0 ||
            o->b2500 != 0) {
            busy = 1;
        }
        if ((u8)busy) {
            if (m->h0 == 0 && isLocal_0054E010(o)) {
                D_001D7AE8_sda = 0;
            }
            m->h0 = 1;
        }
        if (o->w3E0 != 0) {
            o->w1078 = o->w3E0;
        }
        busy = 0;
        if ((decode_0054E010(&o->b19E4) ^ 1) == 0 || respawning_0054E010(o) || o->b24FE != 0 ||
            o->b2500 != 0) {
            busy = 1;
        }
        if ((u8)busy) {
            f32 x;

            if (D_001A5810.flags[o->w2544] != 0) {
                x = -o->pad->f10C;
            } else {
                x = o->pad->f134;
                if (x < o->pad->f13C) {
                    x = -o->pad->f13C;
                }
            }
            if (fabs_asm(x) >= 1.0f) {
                x += x;
            }
            if (x > 0.0f && m->fC > 0.17453292f) {
                s32 snd = m->w20;

                if (snd == -1 || ((Slot_0054E010 *)(D_001FE020 + (snd << 7)))->owner != self ||
                    ((Slot_0054E010 *)(D_001FE020 + (snd << 7)))->bD0 == 0) {
                    m->w20 = func_L39_005F33E0(2, 4, self);
                }
                m->fC -= x * 0.02f;
            } else if (x < 0.0f && m->fC < m->f8) {
                s32 snd = m->w20;

                if (snd == -1 || ((Slot_0054E010 *)(D_001FE020 + (snd << 7)))->owner != self ||
                    ((Slot_0054E010 *)(D_001FE020 + (snd << 7)))->bD0 == 0) {
                    m->w20 = func_L39_005F33E0(3, 4, self);
                }
                m->fC -= x * 0.02f;
            } else {
                snd = m->w20;
                if (snd != -1) {
                    u8 *slot = D_001FE020 + (snd << 7);
                    if (*(Self_0054E010 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
                        func_L39_005F3088(snd);
                    }
                }
                m->w20 = -1;
            }
            if (m->fC > m->f8) {
                m->fC = m->f8;
            } else if (m->fC < 0.17453292f) {
                m->fC = 0.17453292f;
            }
            camera_0054E010(o, m->fC, 0.02f, 0.2f);
            if (isLocal_0054E010(o)) {
                func_L01_004B14C8(0);
            }
            m->o->f12C0 = 200.0f;
            m->o->h1280 |= 0x20;
        } else {
            snd = m->w20;
            if (snd != -1) {
                u8 *slot = D_001FE020 + (snd << 7);
                if (*(Self_0054E010 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
                    func_L39_005F3088(snd);
                }
            }
            m->w20 = -1;
            if (m->h0 != 0) {
                m->fC = m->f8 + (0.17453292f - m->f8) * 0.25f;
                camera_0054E010(o, m->f8, 0.005f, 0.2f);
                m->h0 = 0;
                if (isLocal_0054E010(o)) {
                    D_001D7AE8_sda = 0xE0;
                    func_L01_004B14C8(1);
                }
            }
            m->o->f12C0 = 75.0f;
            m->o->h1280 &= ~0x20;
        }
        k = (m->fC - 0.17453292f) / (m->f8 - 0.17453292f);
        if (isLocal_0054E010(o)) {
            D_L39_0024B710[o->b24C9] = (D_L39_0024B0A8[o->b24C9] - 0.03f) * k + 0.03f;
            D_L39_0024B720[o->b24C9] = (D_L39_0024B0B8[o->b24C9] - 0.4f) * k + 0.4f;
            D_L39_0024B700[o->b24C9] = (D_L39_0024B0D8[o->b24C9] - 0.010471975f) * k + 0.010471975f;
        }
        {
        V_0054E010 pos;
        S_0054E010 s;
        V_0054E010 v;

        res = func_L39_006732D0(o->b1A40, 0, 1, (s32)&s);
        if (res == 8) {
            func_L39_00621D60(o, -1);
            m->w24 = func_L01_003F2058(D_L39_00470600, o->pad);
            ent = func_L39_0061D1D8(s.w2C);
            if (ent != 0) {
                obj = ((u8 * (*)(u8 *))(*(void ***)(ent + 0x14))[0x10 / 4])(ent);
            } else {
                obj = 0;
            }
            hero = 0;
            if (ent != 0 && (ent[3] & 0xF) == 0) {
                hero = (O_0054E010 *)ent;
            }
            veh = 0;
            if (ent != 0 && (ent[3] & 0xF) == 3) {
                veh = (O_0054E010 *)ent;
            }
            if (!isLocal_0054E010(o)) {
                func_003C2F58(self, 0, &pos);
                dist = 0.0f;
                flag2 = 0;
                if (obj != 0) {
                    dist = func_0038CF00(&pos, obj + 0x10);
                }
                if (s.b26 & 0x40) {
                    if (obj != 0) {
                        fl = 1;
                    } else {
                        fl = 0;
                    }
                } else {
                    fl = 1;
                }
                if (s.b26 & 0x80) {
                    if (func_L39_00550638(arg0, (f32 *)&pos) == 0) {
                        flag2 = 1;
                        vset_0054E010(&pos, &s.x30);
                    }
                }
                if (obj == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD || dist > 190.0f) {
                    if (o->b1A08 == 1) {
                        func_0038CF68(&m->v40, &self->vD0, -1.0f);
                    } else if (s.b26 & 0x40) {
                        if (obj != 0 && s.w2C != 0xFFFFFFFF) {
                            vset_0054E010(&v, &s.x3C);
                            vec_add_ab(&m->v40, obj + 0x10, &v);
                        } else {
                            vset_0054E010(&m->v40, &s.x3C);
                        }
                        vec_sub_ab(&m->v40, &m->v40, &pos);
                        func_0038CF68(&m->v40, &m->v40, 1.0f);
                    } else {
                        vset_0054E010(&m->v40, &s.x3C);
                    }
                } else {
                    if (s.b26 & 0x40) {
                        vset_0054E010(&v, &s.x3C);
                        vec_add_ab(&v, &v, obj + 0x10);
                    } else {
                        q = func_00382348(obj);
                        if (q != 0) {
                            if (hero != 0) {
                                f = *(f32 *)(q + 0x10);
                                if ((decode_0054E010(&hero->b19E6) ^ 0xC) == 0) {
                                    f -= 0.1f;
                                } else {
                                    f += 0.5f;
                                }
                                func_L01_00511158(hero, &v, obj + 0x10, f);
                            } else {
                                *(Q_0054E010 *)&v = *(Q_0054E010 *)(obj + 0x10);
                                v.z += *(f32 *)(q + 0x10);
                            }
                        }
                    }
                    {
                    V_0054E010 d;
                    V_0054E010 e;

                    if (flag2 == 0 && func_003D3CB0(&pos, &v, 2, 0, 0) != 0) {
                        vset_0054E010(&e, &s.x30);
                        vec_sub_ab(&d, &e, &pos);
                        func_L01_00511158(o, &pos, &pos, func_L39_00632678((u8 *)o, (f32 *)&d));
                    }
                    if (hero != 0) {
                        *(Q_0054E010 *)&a = hero->q170;
                    } else if (veh != 0) {
                        *(Q_0054E010 *)&a = *(Q_0054E010 *)((u8 *)veh + 0x270);
                    } else {
                        qzero(&a);
                    }
                    flag = 1;
                    func_0038CE20(&a, &a, (f32)(s32)(dist / 32.000004f + 0.9f));
                    vec_add_ba(&b, &v, &a);
                    vec_sub_ab(&d, &b, &pos);
                    func_0038CF68(&m->v40, &d, 1.0f);
                    if (func_0038CE68(&m->v40, &self->vD0) > 0.4f) {
                        func_0038CF68(&m->v40, &self->vD0, -1.0f);
                        flag = 0;
                        func_003C2F58(self, 0, &pos);
                    }
                    }
                }
            } else {
                vset_0054E010(&m->v40, &s.x3C);
                vset_0054E010(&pos, &s.x30);
                if (s.b26 & 0x40) {
                    fl = 1;
                } else {
                    fl = 0;
                }
            }
            func_003C3A10(self, 2, 0, 0);
            snd = m->w20;
            if (snd != -1) {
                u8 *slot = D_001FE020 + (snd << 7);
                if (*(Self_0054E010 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
                    func_L39_005F3088(snd);
                }
            }
            m->w20 = -1;
            func_L39_005F33E0(0, 0, self);
            func_L39_0054F4E0(arg0, (u8 *)&pos, (s32)obj, fl, flag ? (s32)&b : 0);
        } else if (res == 4) {
            func_L39_005F33E0(1, 0, self);
        }
        if ((res != 8 || o->b1A07 == 0) && m->w24 >= 0) {
            func_L01_003F2278(m->w24, o->pad);
            m->w24 = -1;
        }
        }
        break;
    }
    case 2:
        o->b1A0D = 1;
        if (func_L01_0040E050(&m->f4) != 0) {
            o->b1A0D = 0;
            self->b20 = 1;
        }
        break;
    }
    if (m->w14 == 0) {
        return;
    }
    if (func_0038CAD0(&m->w14) != 0) {
        if (m->w10 >= 0) {
            func_L01_00424D88(m->w10);
        }
        m->w10 = -1;
    } else {
        if (m->w10 == -1) {
            m->w10 = ((s32 (*)(void *, f32, f32, s32))func_L39_0059EA90)(&self->pos, 10.0f, 0.0f, 0xFF0000FF);
        }
        if (m->w10 >= 0) {
            V_0054E010 a;
            V_0054E010 b;

            if (o->b1A08 == 1) {
                func_003C2F58(self, 0, &a);
                func_0038CF68(&b, &self->vD0, -1.5f);
            } else {
                func_003C2F58(self, 0, &a);
                func_0038CF68(&b, &o->v3B0, 1.5f);
            }
            vec_add_ab(&D_L39_002667C0[m->w10].v10, &a, &b);
            D_L39_002667C0[m->w10].v10.w = 10.0f;
            {
                f32 t = (f32)m->w14 / 25.0f;

                D_L39_002667C0[m->w10].f4 = t;
                D_L39_002667C0[m->w10].f0 = t * 0.75f;
            }
            D_L39_002667C0[m->w10].f8 = 0.0f;
        }
    }
}
/* localdecomp:end func_L39_0054E010 */

/* localdecomp:start func_L39_0054F4E0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad1[0x24 - 0x22];
    f32 f24;
    u8 pad2[0x30 - 0x28];
    f32 f30;
    u8 pad3[0x80 - 0x34];
} Ent_0054F4E0;

extern Ent_0054F4E0 D_L39_0049C890[];
extern u8 D_L39_004997E0[];
extern u8 D_L39_0025F760[];
__asm__(".extern D_L39_00242930, 16");
extern u8 D_L39_00242930[] __attribute__((section(".sdata")));
extern s32 func_L39_0059EA90(void *, s32, f32, f32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CEA8(void *);
extern u8 *func_L39_00550700(void *, void *, void *, s32, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern u8 *func_L01_00470C78(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 a3, s32 spin,
                             void *velocity, s32 t2, s32 t3, s16 arg8, s32 arg9);

void func_L39_0054F4E0(u8 *self, u8 *pos, s32 a2, s32 a3, s32 a4) {
    vu0_v4 dir;
    vu0_v4 tmp;
    u8 *obj;
    u8 *o;
    u8 *p;
    u8 *r;
    s32 x;
    s32 i;
    s32 j;

    obj = *(u8 **)(self + 0x68);
    o = *(u8 **)(obj + 0x3C);
    *(s32 *)(obj + 0x10) = func_L39_0059EA90(pos, 0xFF0000FF, 10.0f, 0.0f);
    *(s32 *)(obj + 0x14) = 0x19;
    {
        s32 id = 3;
        Ent_0054F4E0 *e;

        if (func_L39_00648AE0(o, id)) {
            e = &D_L39_0049C890[D_L39_0049C890[id].b21];
        } else {
            e = &D_L39_0049C890[id];
        }
        func_L01_00446780(self, pos, 0x110001, 0.3f, e->f30, 1.0f, 0, 1, 0);
    }
    {
        s32 id = 3;
        Ent_0054F4E0 *e;

        if (func_L39_00648AE0(o, id)) {
            e = &D_L39_0049C890[D_L39_0049C890[id].b21];
        } else {
            e = &D_L39_0049C890[id];
        }
        func_0038CF68(&dir, obj + 0x40, e->f24 * 0.020000001f);
    }
    p = o + 0x19E4;
    if (o[0x1A14] != 0 && (({
            u8 *b;
            s32 n;
            s32 m;
            s32 k;
            s32 v;

            if (o[0x19E4] == 0) {
                v = 0;
            } else {
                n = o[0x19E4];
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)&tmp;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                ((u32 *)&tmp)[0] ^= (u32)(o + 0x19E4);
                ((u32 *)&tmp)[1] ^= ((u32 *)&tmp)[0];
                v = ((u32 *)&tmp)[1];
            }
            v;
        }) ^ 0x1D) == 0) {
        r = func_L39_00550700(pos, &dir, *(void **)(obj + 0x3C), a2, 1, a3, 0);
        if (r) {
            *(u8 **)(r + 0xB8) = self;
        }
    } else {
        if (func_003D3CB0(self + 0x10, pos, 0, *(void **)(*(u8 **)(obj + 0x3C) + 0x424), 0)) {
            a4 = 0;
            vec_sub_ba(&tmp, D_L39_0025F760, self + 0x10);
            func_0038CF68(&tmp, &tmp, func_0038CEA8(&tmp) - 0.05f);
            vec_add_ba(pos, &tmp, self + 0x10);
        }
        r = func_L39_00550700(pos, &dir, *(void **)(obj + 0x3C), a2, 0, a3, a4);
        if (r) {
            *(u8 **)(r + 0xB8) = self;
        }
    }
    {
        u8 *b;
        s32 n;
        s32 m;
        s32 k;

        if (o[0x19E4] == 0) {
            x = 0;
        } else {
            n = o[0x19E4];
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)&tmp;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            ((u32 *)&tmp)[0] ^= (u32)p;
            ((u32 *)&tmp)[1] ^= ((u32 *)&tmp)[0];
            x = ((u32 *)&tmp)[1];
        }
    }
    if ((x ^ 0x1D) != 0 || o[0x1A14] == 0) {
        vu0_v4 vel;

        func_003C2F58(self, 0, &tmp);
        for (j = 0; j < 10; j++) {
            func_00382580(&vel, 0.100000009f, 0.200000018f);
            func_L01_00474078(&tmp, &vel, (func_L39_005B43C8(10, 25) * 5 + 2) / 6, 0.075f, 0.25f, 0.5f, 0.5f,
                              0x80408020, 0xFF00, 0, 0);
        }
        func_L01_0046B458(&tmp, 0xE, 3.5f, 0.1f, 0xBF408020, 2, 1, D_L39_00242930, 0.0f, 1);
        func_L01_0046B458(&tmp, 0xE, 2.5f, 0.1f, 0xBF406020, 2, -1, D_L39_00242930, 0.0f, 1);
        func_L01_0046B458(&tmp, 0xE, 1.75f, 0.1f, 0xC0FFFFFF, 2, 1, D_L39_00242930, 0.0f, 1);
        func_L01_0046B458(&tmp, 0xE, 1.25f, 0.1f, 0xB0FFFFFF, 2, -1, D_L39_00242930, 0.0f, 1);
        func_L01_00470C78((u8 *)&tmp, 0x11, 0.71999997f, 0.56f, 0x46787878, 2, 2, D_L39_00242930, 0, 2, 6, 1);
        func_L01_00470C78((u8 *)&tmp, 0x11, 1.36f, 0.56f, 0x46787878, 2, -1, D_L39_00242930, 1, 2, 6, 1);
        func_L01_00470C78((u8 *)&tmp, 0x11, 1.6f, 1.2f, 0x2D787878, 2, 1, D_L39_00242930, 1, 2, 6, 1);
    }
}
/* localdecomp:end func_L39_0054F4E0 */
