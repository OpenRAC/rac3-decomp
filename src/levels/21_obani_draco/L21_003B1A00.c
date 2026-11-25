#include "common.h"
#include "vu0.h"

/* declared by functions of L21_003B0F18.c, which this file was cut from */
void func_L21_003B1B58(void *, void *);

/* localdecomp:start func_L21_003B1A00 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);

typedef unsigned long u_long_003B1A00;

typedef struct {
    f32 w[0x1C];
    f32 h70;
    void *owner;
    s16 h78;
    s16 h7A;
    f32 h7C;
} S_003B1A00;

u8 *func_L21_003B1A00(u8 *arg0, vu0_v4 *pos, f32 a, f32 b) {
    vu0_v4 v;
    u8 *m;
    S_003B1A00 *s;
    s32 i;

    v = *pos;
    m = func_003C24B0(0x1C6D, 0x80);
    if (m != 0) {
        m[0x30] = 0x7F;
        *(s16 *)(m + 0x32) = 0x7F;
        m[0x31] = 1;
        s = *(S_003B1A00 **)(m + 0x68);
        *(u_long_003B1A00 *)(m + 0x38) = *(u_long_003B1A00 *)(arg0 + 0x38);
        *(vu0_v4 *)(m + 0x10) = v;
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = a;
        s->h70 = 0.20000002f;
        s->owner = arg0;
        s->h7C = b;
        s->h78 = 0;
        s->h7A = 0;
        for (i = 0; i < 0x1C; i++) {
            s->w[i] = func_003824E0(-4.0f, 4.0f) * 0.4f / 100.0f;
            if (i == 0 || i == 0x1B) {
                s->w[i] = 0.0f;
            }
        }
        func_L21_003B1B58(m, s);
    }
    return m;
}
/* localdecomp:end func_L21_003B1A00 */

/* localdecomp:start func_L21_003B1B58 */
#include "vu0.h"
typedef struct {
    vu0_v4 dir;
    void *owner;
    s32 flags;
    u8 a;
    u8 b;
    u16 id;
    f32 f;
    s32 g;
} Hit_003B1B58;
typedef union {
    Hit_003B1B58 hit;
    vu0_v4 v[4];
} U_003B1B58;
extern u8 *D_L21_001EC4C0[];
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382760(void *, f32, f32, f32);

static inline f32 Angle_003B1B58(u8 *e, u8 *m) {
    extern f32 func_0038D160(f32, f32);
    return func_0038D160(*(f32 *)(e + 0x10) - *(f32 *)(m + 0x10), *(f32 *)(e + 0x14) - *(f32 *)(m + 0x14));
}

void func_L21_003B1B58(void *arg0, void *arg1) {
    extern s32 func_003D4D00(f32, void *, s32, void *, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_00446978(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    U_003B1B58 tmp;
    u8 *m = arg0;
    S_003B1A00 *s = arg1;
    f32 r;
    f32 dz;
    f32 lim;
    f32 ang;
    f32 sgn;
    f32 a0;
    f32 a1;
    s32 n;
    s32 i;
    s32 k;
    s32 j;

    r = s->h70 * s->h7A;
    if (r < 0.75f) r = 0.75f;
    n = func_003D4D00(r, m + 0x10, 0x10, s->owner, 0);
    for (i = 0; i < n; i++) {
        if (D_L21_001EC4C0[i] == s->owner) continue;
        if (s->h7A > 0) {
            if (0.7417649f < func_0038DBA0(Angle_003B1B58(D_L21_001EC4C0[i], m),
                                           *(f32 *)(m + 0xF8))) continue;
            dz = *(f32 *)(D_L21_001EC4C0[i] + 0x18) - *(f32 *)(m + 0x18);
            if (0.2f < dz) continue;
            if (dz < -2.0f) continue;
            lim = r * 0.95f;
            if (func_L01_0040E570(m + 0x10, D_L21_001EC4C0[i] + 0x10) < lim * lim) continue;
        }
        tmp.hit.owner = s->owner;
        tmp.hit.flags = 0x430001;
        tmp.hit.f = s->h7C;
        tmp.hit.g = 0x430000;
        tmp.hit.a = 2;
        tmp.hit.b = 3;
        tmp.hit.id = *(u16 *)(m + 0xAA);
        ang = Angle_003B1B58(D_L21_001EC4C0[i], m);
        tmp.hit.dir.x = func_0038D098(ang);
        tmp.hit.dir.y = func_0038D0B0(ang);
        tmp.hit.dir.z = 1.0f;
        tmp.hit.dir.w = 5627.9248f;
        func_L01_00446978(D_L21_001EC4C0[i], &tmp.hit);
    }
    for (k = 0; k < 2; k++) {
        sgn = (k & 1) ? 1.0f : -1.0f;
        j = 0;
        do {
            vu0_q qp, qv;
            a0 = func_0038DB48(j * sgn * 0.69813168f / 5.0f);
            a1 = func_0038DB48((j + 1) * sgn * 0.69813168f / 5.0f);
            func_00382760(&tmp.v[0], r, func_0038DAB8(a0, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            func_00382760(&tmp.v[1], r, func_0038DAB8(a1, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(tmp.v[0]));
            *(vu0_q *)&tmp.v[3] = qp;
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[0]) : "j"(qv));
            *(vu0_q *)&tmp.v[2] = qv;
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(tmp.v[1]));
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(tmp.v[3]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qp) : "j"(qp), "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[1]) : "j"(qp));
            *(vu0_q *)&tmp.v[2] = qp;
            if (func_003D3CB0(&tmp.v[0], &tmp.v[1], 0x12, s->owner, 0) != 0) {
                func_00382760(&tmp.v[2], 0.40000004f, *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            }
            j++;
        } while (j < 5);
    }
}
/* localdecomp:end func_L21_003B1B58 */

/* localdecomp:start func_L21_003B1F10 */
typedef struct {
    vu0_v4 m[4];
    s32 col[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} __attribute__((aligned(16))) Q_003B1F10;

extern s32 D_L21_001DE8C0;
extern f32 func_L01_0040F518(f32, f32);
extern void func_0038D328(void *, void *);
extern long func_00389598(s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003D2DA0(void *, void *, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);

void func_L21_003B1F10(u8 *arg0) {
    Q_003B1F10 q;
    vu0_v4 mtx[4];
    vu0_v4 rot;
    S_003B1A00 *s;
    f32 r;
    f32 scroll;
    f32 p0, p1;
    f32 y0, y1;
    f32 amp;
    f32 a;
    f32 lat0, lat1, lat, tilt, prevLat, prevTilt;
    s32 c0, c1;
    s32 i, j, k, m;

    s = *(S_003B1A00 **)(arg0 + 0x68);
    r = s->h70 * (f32)s->h7A;
    scroll = func_L01_0040F518((f32)D_L21_001DE8C0, 25.333334f) / 25.333334f;
    rot = *(vu0_v4 *)(arg0 + 0xF0);
    rot.x = 0.0f;
    func_0038D328(mtx, &rot);
    mtx[3] = *(vu0_v4 *)(arg0 + 0x10);
    q.x78 = func_00389598(0xE);
    q.x80 = 0xFF9000000260L;
    q.x88 = 0x8000000048L;
    q.x70 = 0;
    for (i = 0; i < 5; i++) {
        p0 = (f32)i * 0.06981317f / 5.0f - 0.034906585f;
        p1 = (f32)(i + 1) * 0.06981317f / 5.0f - 0.034906585f;
        for (j = 0; j < 10; j++) {
            y0 = func_0038DB48((f32)j * 1.3962634f / 10.0f) - 0.6981317f;
            y1 = func_0038DB48((f32)(j + 1) * 1.3962634f / 10.0f) - 0.6981317f;
            q.uv[0] = scroll + (func_0038D098(y0) + 1.0f) * 0.5f;
            q.uv[2] = scroll + (func_0038D098(y1) + 1.0f) * 0.5f;
            q.uv[4] = scroll + (func_0038D098(y0) + 1.0f) * 0.5f;
            q.uv[6] = scroll + (func_0038D098(y1) + 1.0f) * 0.5f;
            q.uv[1] = (func_0038D0B0(p0) + 1.0f) * 0.5f;
            q.uv[3] = (func_0038D0B0(p0) + 1.0f) * 0.5f;
            q.uv[5] = (func_0038D0B0(p1) + 1.0f) * 0.5f;
            q.uv[7] = (func_0038D0B0(p1) + 1.0f) * 0.5f;
            if (s->h78 != 0) {
                amp = (f32)s->h78 / 15.0f * 64.0f;
            } else {
                amp = 64.0f;
            }
            c0 = (s32)(amp * func_0038D0B0((f32)i * 3.1415927f / 5.0f));
            c1 = (s32)(amp * func_0038D0B0((f32)(i + 1) * 3.1415927f / 5.0f));
            q.col[0] = j != 0 ? (c0 << 24) | 0x320078 : 0x320078;
            q.col[1] = j != 9 ? (c0 << 24) | 0x320078 : 0x320078;
            q.col[2] = j != 0 ? (c1 << 24) | 0x320078 : 0x320078;
            q.col[3] = j != 9 ? (c1 << 24) | 0x320078 : 0x320078;
            func_00382760(&q.m[0], r, y0, p0);
            func_00382760(&q.m[1], r, y1, p0);
            func_00382760(&q.m[2], r, y0, p1);
            func_00382760(&q.m[3], r, y1, p1);
            q.m[0].w = 1.0f;
            q.m[1].w = 1.0f;
            q.m[2].w = 1.0f;
            q.m[3].w = 1.0f;
            func_003D2DA0(&q, mtx, 0);
        }
    }
    q.x78 = func_00389598(0x38);
    for (k = 0; k < 3; k++) {
        prevTilt = prevLat = 0.0f;
        for (m = 0; m < 28; m++) {
            lat0 = func_0038DB48((f32)m * 1.3962634f / 28.0f) - 0.6981317f;
            lat1 = func_0038DB48((f32)(m + 1) * 1.3962634f / 28.0f) - 0.6981317f;
            lat = func_003824E0(lat0, lat1);
            if (m == 0) {
                prevLat = lat0;
            } else if (m == 27) {
                lat = lat1;
            }
            q.uv[1] = 0.0f;
            q.uv[3] = 0.0f;
            q.uv[5] = 1.0f;
            q.uv[7] = 1.0f;
            q.uv[0] = (f32)m / 28.0f;
            q.uv[4] = (f32)m / 28.0f;
            q.uv[2] = (f32)(m + 1) / 28.0f;
            q.uv[6] = (f32)(m + 1) / 28.0f;
            if (s->h78 != 0) {
                a = q.uv[5] - (f32)s->h78 / 15.0f;
            } else {
                a = q.uv[1];
            }
            if (a < 0.0f) {
                a = 0.0f;
            }
            q.col[0] = q.col[1] = q.col[2] = q.col[3] = func_0038DBD8(0xFF701050, 0xFF0000, a);
            tilt = s->w[m] * 0.017453292f * func_003824E0(-1.0f, 1.0f) * (f32)s->h7A * 3.0f;
            if (0.027925268f < tilt) {
                tilt = 0.027925268f;
            }
            if (tilt < -0.027925268f) {
                tilt = -0.027925268f;
            }
            if (m == 0) {
                prevTilt = 0.0f;
            }
            func_00382760(&q.m[0], r, prevLat, prevTilt);
            func_00382760(&q.m[1], r, lat, tilt);
            func_00382760(&q.m[2], r, prevLat, prevTilt);
            func_00382760(&q.m[3], r, lat, tilt);
            prevTilt = tilt;
            prevLat = lat;
            q.m[2].z -= 0.15f;
            q.m[3].z -= 0.15f;
            q.m[0].w = 1.0f;
            q.m[1].w = 1.0f;
            q.m[2].w = 1.0f;
            q.m[3].w = 1.0f;
            func_003D2DA0(&q, mtx, 0);
        }
    }
}
/* localdecomp:end func_L21_003B1F10 */

/* localdecomp:start func_L21_003B2688 */
extern s32 D_001D6694;
extern u8 D_1A30B0[];
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003A4F28(s32);
extern void func_003C2880(void *);

typedef struct {
    vu0_v4 dir;
    s32 sound;
    s32 life;
} S_003B2688;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    S_003B2688 *pvar;
    u8 pad6C[0x96 - 0x6C];
    u16 age;
} M_003B2688;

void func_L21_003B2688(M_003B2688 *m) {
    S_003B2688 *s;
    u8 *e;
    s32 idx;
    vu0_v4 v;
    vu0_v4 w[2];
    vu0_v4 p;

    s = m->pvar;
    if (s->sound == -1) {
        goto spawn;
    }
    e = D_1A30B0 + (s->sound << 7);
    if (*(M_003B2688 **)(e + 0xDC) != m || e[0xD0] == 0) {
spawn:
        if (D_001D6694 != 2) {
            s->sound = func_L01_004AAC98(0, 4, m, 0x1A9C);
        }
    }
    func_0038CF68(&v, s, 0.3f);
    vec_add_ba(&m->pos, &m->pos, &v);
    func_0038CE20(&w[0], &v, -0.5f);
    qzero(&w[1]);
    func_L01_0046FB40(&m->pos, w, 5, 0x808080, 3, 0x4F, 0,
                      func_003824E0(0.5f, 0.75f) * 210000.0f, func_003824E0(0.2f, 0.4f) * 210000.0f, 0.0f, 0);
    p = m->pos;
    p.x += func_L01_00443A18(0.0f, 0.15f);
    p.y += func_L01_00443A18(0.0f, 0.15f);
    p.z += func_L01_00443A18(0.0f, 0.15f);
    func_L01_0046FB40(&p, w, 5, 0x808080, 7, 0x5F, 0,
                      func_003824E0(0.5f, 0.75f) * 210000.0f, func_003824E0(0.1f, 0.3f) * 210000.0f, 0.0f, 0);
    p.x += func_L01_00443A18(0.0f, 0.15f);
    p.y += func_L01_00443A18(0.0f, 0.15f);
    p.z += func_L01_00443A18(0.0f, 0.15f);
    func_L01_0046FB40(&p, w, 5, 0x808080, 0xC, 0x7F, 0,
                      func_003824E0(0.5f, 0.75f) * 210000.0f, func_003824E0(0.2f, 0.4f) * 210000.0f, 0.0f, 0);
    func_L01_00446780(m, &m->pos, 1, 0, 1, 0, 0.2f, 20.0f, 0.5f);
    m->age++;
    if ((s->life * 5 + 2) / 6 < m->age) {
        idx = s->sound;
        if (idx != -1) {
            e = D_1A30B0 + (idx << 7);
            if (*(M_003B2688 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        s->sound = -1;
        func_003C2880(m);
    }
}
/* localdecomp:end func_L21_003B2688 */
