#include "common.h"

/* NTSC-U counterpart of func_L39_0052A2B8 (src/levels/shared/L39_0052A2B8.c) */
/* localdecomp:start func_L39_00529D78 */
#include "vu0.h"
struct Self_0052AA00;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0052A2B8;
typedef struct {
    V4_0052A2B8 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long tag[4];
} Q_0052A2B8;
typedef struct {
    u8 pad0[0x14];
    u8 *f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    u8 *f24;
    f32 f28;
    s32 f2C;
    u32 f30;
} P_0052A2B8;
extern u8 *D_L39_002969EC __attribute__((section(".data")));
extern unsigned long func_L39_00588720(int);
extern void func_003BDA38(struct Self_0052AA00 *, s32, void *);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L39_005B24C8(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003D3FA0(void *, s32, u32, s32, f32, f32, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00389410(f32);
extern void func_003CD830(void *, s32, s32);

/* from rac2-decomp's func_L01_0038EF40 (the wavy link strip), here drawn twice with sparks */
void func_L39_00529D78(struct Self_0052AA00 *self) {
    u8 *a0 = (u8 *)self;
    Q_0052A2B8 q;
    V4_0052A2B8 start;
    V4_0052A2B8 cur;
    V4_0052A2B8 end;
    V4_0052A2B8 dir;
    V4_0052A2B8 side;
    V4_0052A2B8 up;
    V4_0052A2B8 tmp;
    V4_0052A2B8 to;
    V4_0052A2B8 off;
    V4_0052A2B8 pos;
    V4_0052A2B8 vel;
    P_0052A2B8 *pv;
    u8 *tgt;
    s32 i;
    s32 n;
    f32 ang;
    f32 dang;
    f32 width;
    f32 len;
    f32 t;
    f32 step;
    f32 wave;
    f32 s;
    f32 sn;
    f32 a;
    f32 amp;
    f32 sc;
    u8 *r;
    s32 k;
    unsigned long tex;
    unsigned long t2 = 0xFF9000000260;
    unsigned long t3 = 0xFF00000044;

    if (a0 == 0) {
        return;
    }
    pv = *(P_0052A2B8 **)(a0 + 0x68);
    if (pv == 0) {
        return;
    }
    pv->f28 += 0.2f;
    tgt = pv->f24;
    if (pv->f28 >= 3.0f) {
        pv->f28 = 0.0f;
    }
    for (i = 0; i < 2; i++) {
        if (i == 1) {
            pv->f2C = 14;
            pv->f30 = 0x3020FF20;
            width = 0.11f;
        } else {
            pv->f2C = 0x45;
            pv->f30 = 0x80208040;
            width = 0.05f;
        }
        tex = func_L39_00588720(pv->f2C);
        q.col[3] = pv->f30;
        q.col[2] = pv->f30;
        q.col[1] = pv->f30;
        q.col[0] = pv->f30;
        q.tag[1] = tex;
        q.tag[2] = t2;
        q.tag[0] = 0;
        q.tag[3] = t3;
        q.uv[0][0] = pv->f28 + 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = pv->f28 + 1.0f;
        q.uv[1][1] = 0.0f;
        q.uv[2][0] = pv->f28 + 0.0f;
        q.uv[2][1] = 1.0f;
        q.uv[3][0] = pv->f28 + 1.0f;
        q.uv[3][1] = 1.0f;
        func_003BDA38(self, 1, &end);
        start = *(V4_0052A2B8 *)(pv->f14 + 0x10);
        cur = start;
        dang = func_00388A28(*(f32 *)(tgt + 0x23A0) - *(f32 *)(a0 + 0x10),
                            *(f32 *)(tgt + 0x23A4) - *(f32 *)(a0 + 0x14));
        n = func_L39_005B2568(2.0f, 5.0f);
        pos.x = *(f32 *)(a0 + 0x10) + func_L39_005B2510(-0.01f, 0.01f);
        pos.y = *(f32 *)(a0 + 0x14) + func_L39_005B2510(-0.01f, 0.01f);
        pos.z = *(f32 *)(a0 + 0x18) + func_L39_005B2510(-0.01f, 0.01f);
        s = func_L39_005B2510(0.4f, 0.6f);
        sc = func_L39_005B2510(4.5f, 6.0f);
        ang = func_00389380(dang, func_L39_005B2568(0.0f, 1.3962634f));
        sc *= 0.016666668f;
        vel.x = func_00388960(ang);
        vel.x *= sc;
        vel.y = func_00388978(ang);
        vel.y *= sc;
        vel.z = 0.0f;
        vel.z = func_L39_005B2510(0.0f, 0.5f);
        vel.z *= 0.016666668f;
        func_L01_0046DCB8(&start, &vel, func_L39_005B24C8(15, 25), 0x40FF7F, n, 0x7F, 0x7F,
                          s * 210000.0f, 2100.0f, 0.0044444446f, 6);
        n = -(n * 2);
        k = func_L39_005B24C8(15, 25);
        s *= 3.0f;
        r = func_L01_0046DCB8(&start, &vel, k, 0xFF20, n, 0x30, 0x30,
                              s * 210000.0f, 4200.0f, 0.0044444446f, 0);
        if (r != 0) {
            r[2] = *D_L39_002969EC;
        }
        func_003D3FA0(&start, 0x31, 0x2F208040, 1, 0.25f, 0.125f, 0.0f);
        func_003D3FA0(&start, 0x31, 0x2F208040, 1, 0.4f, 0.124f, 0.0f);
        func_003D3FA0(&start, 0xB, 0x2F007F00, 1, 0.55f, 0.123f, 0.0f);
        vec_sub_ab(&dir, &end, &start);
        len = func_00388770(&dir);
        tmp = dir;
        tmp.z -= 0.1f;
        func_00388758(&side, &dir, &tmp);
        func_00388758(&up, &dir, &side);
        q.v[0] = start;
        q.v[2] = start;
        q.v[2].z += width;
        q.v[0].z -= width;
        amp = func_00388960(func_00389410(pv->f18));
        t = 0.0f;
        while (t < len) {
            step = 0.4f;
            if (len - t < step) {
                step = len - t;
            }
            t += step;
            a = t * 3.1415927f;
            sn = func_00388978(a / len);
            wave = func_00388978(func_00389410(a / pv->f1C)) * sn;
            wave *= amp;
            wave *= pv->f20;
            func_00388830(&dir, &dir, step);
            vec_add_ab(&cur, &cur, &dir);
            q.v[1] = cur;
            q.v[3] = cur;
            vec_sub_ba(&to, tgt + 0x23A0, &cur);
            func_00388758(&off, &to, &dir);
            func_00388830(&off, &off, width);
            vec_add_ab(&q.v[1], &q.v[1], &off);
            vec_sub_ab(&q.v[3], &q.v[3], &off);
            func_00388830(&tmp, &side, wave);
            vec_add_ab(&q.v[1], &q.v[1], &tmp);
            vec_add_ab(&q.v[3], &q.v[3], &tmp);
            func_003CD830(&q, 0, 1);
            start = cur;
            q.v[0] = q.v[1];
            q.v[2] = q.v[3];
        }
    }
}
/* localdecomp:end func_L39_00529D78 */
