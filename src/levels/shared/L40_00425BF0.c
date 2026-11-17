#include "common.h"

/* localdecomp:start func_L40_00425BF0 */
#include "vu0.h"

typedef union {
    vu0_q q;
    f32 f[4];
} Vec4_00425BF0;

typedef struct {
    Vec4_00425BF0 dir;
    Vec4_00425BF0 start;
    Vec4_00425BF0 end;
} Ray_00425BF0;

typedef struct {
    Vec4_00425BF0 a;
    Vec4_00425BF0 dir;
    Vec4_00425BF0 c;
    Vec4_00425BF0 pos;
} Info_00425BF0;

typedef struct O_00425BF0 O_00425BF0;
typedef struct {
    u8 pad0[0x1C];
    s32 (*check)(O_00425BF0 *, s32);
} VT_00425BF0;
struct O_00425BF0 {
    u8 pad0[0x14];
    VT_00425BF0 *vt;
    u8 pad18[0x28 - 0x18];
    s32 f28;
};

typedef struct {
    u32 a;
    s32 b;
    s32 c;
    s32 d;
} S220_00425BF0;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 f34;
    u8 pad36[2];
    u8 f38;
    u8 pad39[0x3E - 0x39];
    u8 f3E;
    u8 pad3F[0x70 - 0x3F];
    u8 f70[0x10];
    u8 f80[0x70];
    f32 fF0;
    u8 padF4[0x100 - 0xF4];
    u8 f100[0x70];
    f32 f170;
    u8 pad174[0x180 - 0x174];
    u8 f180[0x64];
    f32 f1E4;
    u8 pad1E8[0x1F0 - 0x1E8];
    f32 f1F0;
    u8 pad1F4[0x220 - 0x1F4];
    S220_00425BF0 f220;
    u8 *f230;
    s32 f234;
    s32 f238;
    s32 f23C;
    f32 f240;
    f32 f244;
    f32 f248;
    f32 f24C;
    f32 f250;
    f32 f254;
    f32 f258;
    f32 f25C;
    u8 f260[0x10];
    s32 f270;
    u8 pad274[0x27C - 0x274];
    s32 f27C;
    s32 f280;
    s32 f284;
    s32 f288;
    s32 f28C;
    s32 f290;
    s32 f294;
    s32 f298;
    s32 f29C;
    s32 f2A0;
} V_00425BF0;

typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 f21;
    u8 pad22[0x34 - 0x22];
    u16 f34;
    u8 pad36[0x43 - 0x36];
    u8 f43;
    u8 pad44[0x48 - 0x44];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 f60;
    u8 pad61[0x68 - 0x61];
    V_00425BF0 *vars;
    u8 pad6C[0x78 - 0x6C];
    u32 f78;
    u8 pad7C[0x96 - 0x7C];
    u16 f96;
    s32 f98;
    u8 pad9C[0xBE - 0x9C];
    u8 fBE;
} M_00425BF0;

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0x68 - 0x36];
    s32 *f68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
    u8 pad9C[0x100 - 0x9C];
} P_00425BF0;

typedef struct {
    u8 pad[0x1F8];
    f32 f1F8[1];
} T_00425BF0;

typedef struct {
    u8 pad0[0xD0];
    u8 active;
    u8 padD1[0xDC - 0xD1];
    void *owner;
} E_00425BF0;

extern s32 func_L40_00424B20(V_00425BF0 *);
extern O_00425BF0 *func_L39_0061D7B0(M_00425BF0 *);
extern void func_L40_00424C68(M_00425BF0 *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L40_004897A8(void *, s32);
extern void func_003C2880(void *);
extern O_00425BF0 *func_L39_0066C828(void *, s32, s32);
extern void func_L39_0061C1E0(void *, s32);
extern void func_0038D2D0(void *, f32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C3938(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L40_00424B10(void *);
extern void func_L39_0066B9A0(s32, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3088(s32);
extern void func_L40_004272D0(void *);
extern void func_L40_004271E0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void *func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_L07_003CAE10(void *, void *, void *, s32, void *, s32, u32, f32, f32);
extern void func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L40_00425A10();
extern void func_L40_00427920();

extern s8 *D_L40_00241640;
__asm__(".extern D_L40_00241640, 16");
extern s32 D_L40_0024112C;
__asm__(".extern D_L40_0024112C, 16");
extern P_00425BF0 *D_L40_0024845C;
extern char D_001FE020[];
extern T_00425BF0 D_L40_00357260;
extern int *D_L40_0035746C[];
extern u8 D_L40_00242930[8];
typedef struct { u8 v[1]; } B_00425BF0;
extern B_00425BF0 D_L40_002462C8;
extern B_00425BF0 D_L40_002462C9;
extern B_00425BF0 D_L40_002462CA;
__asm__(".extern D_L40_002462C9, 16");
__asm__(".extern D_L40_002462CA, 16");
extern s32 D_L40_00247750;
extern s32 D_L40_00247784;
extern s32 D_L40_00247788;
extern s32 D_L40_0024778C;
extern s32 D_L40_00247790;
extern s32 D_L40_00247794;
extern s32 D_L40_00247798;
extern s32 D_L40_0024779C;
extern f32 D_L40_002477A0;
extern s32 D_L40_002477A4;
extern s32 D_L40_002477A8;
extern f32 D_L40_002477AC;
extern f32 D_L40_002477B0;
extern f32 D_L40_002477B4;
extern f32 D_L40_002477B8;
extern f32 D_L40_002477BC;
extern f32 D_L40_002477C0;
extern f32 D_L40_002477C4;
extern f32 D_L40_002477C8;

__asm__(".extern D_L40_00247750, 4");
__asm__(".extern D_L40_00247784, 4");
__asm__(".extern D_L40_00247788, 4");
__asm__(".extern D_L40_0024778C, 4");
__asm__(".extern D_L40_00247790, 4");
__asm__(".extern D_L40_00247794, 4");
__asm__(".extern D_L40_00247798, 4");
__asm__(".extern D_L40_0024779C, 4");
__asm__(".extern D_L40_002477A0, 4");
__asm__(".extern D_L40_002477A4, 4");
__asm__(".extern D_L40_002477A8, 4");
__asm__(".extern D_L40_002477AC, 4");
__asm__(".extern D_L40_002477B0, 4");
__asm__(".extern D_L40_002477B4, 4");
__asm__(".extern D_L40_002477B8, 4");
__asm__(".extern D_L40_002477BC, 4");
__asm__(".extern D_L40_002477C0, 4");
__asm__(".extern D_L40_002477C4, 4");
__asm__(".extern D_L40_002477C8, 4");

void func_L40_00425BF0(M_00425BF0 *m) {
    V_00425BF0 *v = m->vars;
    s32 s;
    P_00425BF0 *o;
    O_00425BF0 *p;
    E_00425BF0 *e;
    s32 i;
    Vec4_00425BF0 pos;
    Ray_00425BF0 ray;
    Info_00425BF0 info;
    Vec4_00425BF0 tmp;
    Vec4_00425BF0 at;

    if (m->f96 < 0xFFFF) {
        m->f96++;
    }
    s = func_L40_00424B20(v);
    if (m->state != 0) {
        if (s != v->f27C) {
            p = func_L39_0061D7B0(m);
            v->f27C = s;
            p->f28 = s;
        }
        func_L40_00424C68(m);
        if (m->state != 0 && m->state != 5) {
            if (v->f23C > 0 || v->f230 == 0 || v->f2A0 != 0) {
                func_L01_00404808(func_L40_00425A10, m);
            }
        }
    }
    if (m->state != 5) {
        func_L01_0044ABD0(m, v->f70);
    }

    switch (m->state) {
    case 0:
        if (D_L40_00241640[0x194] == 0) {
            if (v->f284 >= 0) {
                o = D_L40_0024845C;
                o += v->f284;
                o->f98 = 0;
                o->f34 = (o->f34 | 0x41) & ~0x1000;
                func_L39_005F2FF8(o, 1);
                func_L40_004897A8(o, v->f290);
            }
            if (v->f288 >= 0) {
                o = D_L40_0024845C;
                o += v->f288;
                o->f98 = 0;
                o->f34 = (o->f34 | 0x41) & ~0x1000;
                func_L39_005F2FF8(o, 1);
                func_L40_004897A8(o, v->f294);
            }
            if (v->f28C >= 0) {
                o = D_L40_0024845C;
                o += v->f28C;
                o->f98 = 0;
                o->f34 = (o->f34 | 0x41) & ~0x1000;
                func_L39_005F2FF8(o, 1);
                func_L40_004897A8(o, v->f298);
            }
            func_003C2880(m);
            return;
        } else {
            O_00425BF0 *a = func_L39_0066C828(m, -1, 1);
            p = func_L39_0061D7B0(m);
            v->f27C = s;
            a->f28 = s;
            v->f2A0 = 0;
            if (p->vt->check(p, 0)) {
                m->fBE = (m->fBE | 0x10) & ~0x8;
            } else if (p->vt->check(p, 1)) {
                m->fBE = (m->fBE | 0x8) & ~0x10;
            } else {
                m->fBE &= ~0x18;
            }
            m->f34 &= ~0x1000;
            func_L39_0061C1E0(m, -1);
            func_0038D2D0(&pos, 1.0f);
            {
                S220_00425BF0 *q = &v->f220;
                q->a = 0xFFFFFFFF;
                q->c = 0;
                q->d = 0;
                q->b = -1;
            }
            v->f3E = 3;
            v->f234 = 0;
            m->f34 |= 0x4000;
            func_0038CB78(v->f80, 0, 0x80);
            func_0038CB78(v->f100, 0, 0x80);
            func_0038CB78(v->f180, 0, 0x80);
            v->f248 = v->f248 * 0.0174532924f * 0.0200000014f;
            v->f24C = v->f24C * 0.0174532924f * 0.0200000014f;
            v->f244 = v->f244 * 0.0174532924f * 0.0200000014f;
            {
                f32 r = v->f254 * 0.75f;
                v->f258 = r * r;
            }
            v->f30 = v->f34;
            v->fF0 = 1.0f;
            v->f170 = 1.0f;
            v->f280 = -1;
            v->f250 = 0.0f;
            v->f1F0 = 1.0f;
            v->f23C = 0x80;
            v->f29C = -1;
            if (v->f284 >= 0) {
                P_00425BF0 *t = D_L40_0024845C;
                t += v->f284;
                t->f34 |= 0x41;
            }
            if (v->f288 >= 0) {
                P_00425BF0 *t = D_L40_0024845C;
                t += v->f288;
                t->f34 |= 0x41;
            }
            if (v->f28C >= 0) {
                P_00425BF0 *t = D_L40_0024845C;
                t += v->f28C;
                t->f34 |= 0x41;
            }
            func_003C3938(m, 1, 0);
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m)) {
            o = D_L40_0024845C + v->f238;
            if (func_L40_00424B10(o)) {
                func_L39_0066B9A0(o->f68[7], m->f21);
            }
            m->f34 &= ~0x1000;
        }
        if (v->f29C == -1 || (e = (E_00425BF0 *)(D_001FE020 + v->f29C * 128))->owner != m || e->active == 0) {
            v->f29C = func_L39_005F33E0(2, 4, m);
        }
        if (m->f60 & 2) {
            func_003C3938(m, 1, 0);
        }
        if (v->f280 != -1 && (e = (E_00425BF0 *)(D_001FE020 + v->f280 * 128))->owner == m && e->active != 0) {
            func_L39_005F3088(v->f280);
        }
        v->f280 = -1;
        v->f38 = v->f27C;
        func_L40_004272D0(m);
        func_L40_004271E0(m);
        break;
    case 2:
        if (func_L01_004561B8(m)) {
            m->f48 = 1.0f;
            if (m->f43 != 2) {
                func_003C3A10(m, 2, 0, 10);
            }
            if (v->f280 == -1 || (e = (E_00425BF0 *)(D_001FE020 + v->f280 * 128))->owner != m || e->active == 0) {
                v->f280 = func_L39_005F33E0(0, 4, m);
            }
            m->f34 |= 0x1000;
        }
        if (m->f60 & 2) {
            func_003C3938(m, 3, 0);
        }
        func_L40_004272D0(m);
        func_L40_004271E0(m);
        v->f240 += v->f248;
        if (v->f240 > v->f244) {
            v->f240 = v->f244;
        }
        if (v->f240 < 0.0f) {
            v->f240 = 0.0f;
        }
        if (v->f240 >= v->f244) {
            v->f240 = v->f244;
            func_L01_004450F0(m, 3, -1);
        }
        {
            f32 t = func_0038DAB8(v->f250, v->f240);
            v->f250 = t;
            v->f1E4 = t;
        }
        func_L01_0044E850(m, v->f180, 2, 0.0432000011f, 0.432000041f);
        if (v->f29C != -1 && (e = (E_00425BF0 *)(D_001FE020 + v->f29C * 128))->owner == m && e->active != 0) {
            func_L39_005F3088(v->f29C);
        }
        v->f29C = -1;
        break;
    case 4:
        if (func_L01_004561B8(m)) {
            if (m->f43 != 2) {
                func_003C3A10(m, 2, 0, 10);
            }
            m->f48 = -1.0f;
            if (v->f29C == -1 || (e = (E_00425BF0 *)(D_001FE020 + v->f29C * 128))->owner != m || e->active == 0) {
                v->f29C = func_L39_005F33E0(2, 4, m);
            }
            m->f34 &= ~0x1000;
        }
        if (m->f60 & 2) {
            func_003C3938(m, 1, 0);
        }
        func_L40_004272D0(m);
        func_L40_004271E0(m);
        v->f240 -= v->f248;
        if (v->f240 > v->f244) {
            v->f240 = v->f244;
        }
        if (v->f240 < 0.0f) {
            v->f240 = 0.0f;
        }
        if (v->f240 <= 0.0f) {
            v->f240 = 0.0f;
            func_L01_004450F0(m, 1, -1);
        }
        {
            f32 t = func_0038DAB8(v->f250, v->f240);
            v->f250 = t;
            v->f1E4 = t;
        }
        func_L01_0044E850(m, v->f180, 2, 0.0432000011f, 0.432000041f);
        if (v->f280 != -1 && (e = (E_00425BF0 *)(D_001FE020 + v->f280 * 128))->owner == m && e->active != 0) {
            func_L39_005F3088(v->f280);
        }
        v->f280 = -1;
        break;
    case 3:
        if (func_L01_004561B8(m)) {
            m->f34 |= 0x1000;
        }
        if (m->f60 & 2) {
            func_003C3938(m, 3, 0);
        }
        if (v->f29C != -1 && (e = (E_00425BF0 *)(D_001FE020 + v->f29C * 128))->owner == m && e->active != 0) {
            func_L39_005F3088(v->f29C);
        }
        v->f29C = -1;
        func_L40_004272D0(m);
        func_L40_004271E0(m);
        {
            f32 t = func_0038DAB8(v->f250, v->f240);
            v->f250 = t;
            v->f1E4 = t;
        }
        func_L01_0044E850(m, v->f180, 2, 0.0432000011f, 0.432000041f);
        m->f96++;
        if (v->f270 > 0) {
            func_L01_00404A10(func_L40_00427920, m);
        }
        func_003C2F58(m, 3, &pos);
        for (i = 0; i < D_L40_002477A4; i++) {
            ray.start.q = 0;
            ray.start.f[0] = func_L39_005B4410(D_L40_002477AC, D_L40_002477B0);
            ray.start.f[1] = func_L39_005B4410(D_L40_002477AC, D_L40_002477B0);
            ray.start.f[2] = func_L39_005B4410(D_L40_002477B4, D_L40_002477B8);
            ray.dir = ray.start;
            func_0038CF68(&ray.dir, &ray.dir, D_L40_002477A0 * 0.0200000014f);
            func_L39_005C5FC8(&pos, &ray.dir,
                              (D_L40_00247790 << 24) | (D_L40_0024778C << 16) | (D_L40_00247788 << 8) | D_L40_00247784,
                              (D_L40_0024778C << 16) | (D_L40_00247788 << 8) | D_L40_00247784,
                              D_L40_00247794, D_L40_00247798, D_L40_0024779C, D_L40_002477A8);
        }
        if ((D_L40_00247750 * 5 + 2) / 6 < m->f96) {
            v->f270 = 5;
            m->f96 = 0;
            func_003C2EC0(m, 3, &info);
            ray.dir = info.dir;
            ray.start = info.pos;
            func_0038CF68(&ray.dir, &ray.dir, D_L40_002477BC * 0.0200000014f);
            tmp = info.pos;
            at = info.pos;
            vec_add_ab(&ray.end, &tmp, &ray.dir);
            func_L07_003CAE10(&tmp, &ray, m, 4, v->f260, -1, 0xFFFFFFFF, D_L40_002477C0,
                              v->f25C + D_L40_00357260.f1F8[v->f27C] * 2.5f);
            func_L01_0046B458(&at, 7, D_L40_002477C4 * 7.0f, 0.1f, 0xBF204080, 2, 1, D_L40_00242930, 0.0f, 1);
            func_L01_0046B458(&at, 7, D_L40_002477C4 * 5.0f, 0.1f, 0xBF2040A0, 2, -1, D_L40_00242930, 0.0f, 1);
            func_L01_0046B458(&at, 7, D_L40_002477C4 * 3.5f, 0.1f, 0xC0FFFFFF, 2, 1, D_L40_00242930, 0.0f, 1);
            func_L01_0046B458(&at, 7, D_L40_002477C4 * 2.5f, 0.1f, 0xB0FFFFFF, 2, -1, D_L40_00242930, 0.0f, 1);
            func_L01_00470C78(&at, 6, 1.08000004f, 0.840000033f, 0x46787878, 2, 2, D_L40_00242930, 0, 2, 6, 1);
            func_L01_00470C78(&at, 8, 2.0400002f, 0.840000033f, 0x46787878, 2, -1, D_L40_00242930, 1, 2, 6, 1);
            func_L01_00470C78(&at, 8, 2.4000001f, 1.80000007f, 0x2D787878, 2, 1, D_L40_00242930, 1, 2, 6, 1);
        }
        if ((D_L40_0024112C & 0xF) == (((s32)m >> 8) & 0xF)) {
            f32 r = D_L40_002477C8 * D_L40_002477C8;
            if (func_L01_0040E548(&pos, v->f230 + 0x10) < r) {
                func_L01_00446780(m, v->f230 + 0x10, 0x10001, 1, 1, 0, 0.5f,
                                  v->f25C + D_L40_00357260.f1F8[v->f27C] * 2.5f, 1.0f);
            }
        }
        break;
    case 5:
        if (v->f280 != -1 && (e = (E_00425BF0 *)(D_001FE020 + v->f280 * 128))->owner == m && e->active != 0) {
            func_L39_005F3088(v->f280);
        }
        v->f280 = -1;
        if (v->f29C != -1 && (e = (E_00425BF0 *)(D_001FE020 + v->f29C * 128))->owner == m && e->active != 0) {
            func_L39_005F3088(v->f29C);
        }
        v->f29C = -1;
        if (func_L01_004561B8(m)) {
            m->f98 = 0;
            m->f34 = (m->f34 | 0x41) & ~0x1000;
            func_L39_005F2FF8(m, 1);
        }
        break;
    }

    if (v->f238 >= 0) {
        if (func_L40_00424B10(D_L40_0024845C + v->f238)) {
            s32 *state = (D_L40_0024845C + v->f238)->f68;
            int *q = D_L40_0035746C[0] + state[7];
            s32 c = q[0x22];
            if (c >= 0) {
                s32 o = c * 3;
                m->f78 = 0x80000000 | (D_L40_002462CA.v[o] << 16) | (D_L40_002462C9.v[o] << 8) | D_L40_002462C8.v[o];
            } else {
                m->f78 = 0x80FFFFFF;
            }
        }
    }
}
/* localdecomp:end func_L40_00425BF0 */
