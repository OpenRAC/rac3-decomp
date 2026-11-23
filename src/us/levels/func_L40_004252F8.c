#include "common.h"

/* NTSC-U counterpart of func_L40_00425BF0 with 60 Hz timing. */
/* localdecomp:start func_L40_004252F8 */
#include "vu0.h"

typedef union {
    vu0_q q;
    f32 f[4];
} Vec4_004252F8;

typedef struct {
    Vec4_004252F8 dir;
    Vec4_004252F8 start;
    Vec4_004252F8 end;
} Ray_004252F8;

typedef struct {
    Vec4_004252F8 a;
    Vec4_004252F8 dir;
    Vec4_004252F8 c;
    Vec4_004252F8 pos;
} Info_004252F8;

typedef struct O_004252F8 O_004252F8;
typedef struct {
    u8 pad0[0x1C];
    s32 (*check)(O_004252F8 *, s32);
} VT_004252F8;
struct O_004252F8 {
    u8 pad0[0x14];
    VT_004252F8 *vt;
    u8 pad18[0x28 - 0x18];
    s32 f28;
};

typedef struct {
    u32 a;
    s32 b;
    s32 c;
    s32 d;
} S220_004252F8;

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
    S220_004252F8 f220;
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
} V_004252F8;

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
    V_004252F8 *vars;
    u8 pad6C[0x78 - 0x6C];
    u32 f78;
    u8 pad7C[0x96 - 0x7C];
    u16 f96;
    s32 f98;
    u8 pad9C[0xBE - 0x9C];
    u8 fBE;
} M_004252F8;

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0x68 - 0x36];
    s32 *f68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
    u8 pad9C[0x100 - 0x9C];
} P_004252F8;

typedef struct {
    u8 pad[0x1F8];
    f32 f1F8[1];
} T_004252F8;

typedef struct {
    u8 pad0[0xD0];
    u8 active;
    u8 padD1[0xDC - 0xD1];
    void *owner;
} E_004252F8;

extern s32 func_L40_00424228(V_004252F8 *);
extern O_004252F8 *func_L39_0061B038(M_004252F8 *);
extern void func_L40_00424370(M_004252F8 *);
extern void func_L01_00402498(void *, void *);
extern void func_L01_004479A8(void *, void *);
extern void func_L39_005F08F8(void *, s32);
extern void func_L40_00487860(void *, s32);
extern void func_003BD360(void *);
extern O_004252F8 *func_L39_00669F20(void *, s32, s32);
extern void func_L39_00619A68(void *, s32);
extern void func_00388B98(void *, f32);
extern void func_00388440(void *, s32, s32);
extern void func_003BE418(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L40_00424218(void *);
extern void func_L39_00669098(s32, s32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_005F0988(s32);
extern void func_L40_004269C0(void *);
extern void func_L40_004268D0(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_L39_005B2510(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void *func_L39_005C3D70(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_L07_003C9438(void *, void *, void *, s32, void *, s32, u32, f32, f32);
extern void func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_0046D570(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L40_00425118();
extern void func_L40_00427000();

extern s8 *D_L40_002417C0;
__asm__(".extern D_L40_002417C0, 16");
extern s32 D_L40_002412AC;
__asm__(".extern D_L40_002412AC, 16");
extern P_004252F8 *D_L40_002485DC;
extern char D_L40_001FE1A0[];
extern T_004252F8 D_L40_003573E0;
extern int *D_L40_003575EC[];
extern u8 D_L40_00242AB0[8];
typedef struct { u8 v[1]; } B_004252F8;
extern B_004252F8 D_L40_00246448;
extern B_004252F8 D_L40_00246449;
extern B_004252F8 D_L40_0024644A;
__asm__(".extern D_L40_00246449, 16");
__asm__(".extern D_L40_0024644A, 16");
extern s32 D_L40_002478D0;
extern s32 D_L40_00247904;
extern s32 D_L40_00247908;
extern s32 D_L40_0024790C;
extern s32 D_L40_00247910;
extern s32 D_L40_00247914;
extern s32 D_L40_00247918;
extern s32 D_L40_0024791C;
extern f32 D_L40_00247920;
extern s32 D_L40_00247924;
extern s32 D_L40_00247928;
extern f32 D_L40_0024792C;
extern f32 D_L40_00247930;
extern f32 D_L40_00247934;
extern f32 D_L40_00247938;
extern f32 D_L40_0024793C;
/* These three fields have different PAL and NTSC-U linker bindings. */
extern f32 D_L40_00247940_004252F8;
extern f32 D_L40_00247944_004252F8;
extern f32 D_L40_00247948_004252F8;

__asm__(".extern D_L40_002478D0, 4");
__asm__(".extern D_L40_00247904, 4");
__asm__(".extern D_L40_00247908, 4");
__asm__(".extern D_L40_0024790C, 4");
__asm__(".extern D_L40_00247910, 4");
__asm__(".extern D_L40_00247914, 4");
__asm__(".extern D_L40_00247918, 4");
__asm__(".extern D_L40_0024791C, 4");
__asm__(".extern D_L40_00247920, 4");
__asm__(".extern D_L40_00247924, 4");
__asm__(".extern D_L40_00247928, 4");
__asm__(".extern D_L40_0024792C, 4");
__asm__(".extern D_L40_00247930, 4");
__asm__(".extern D_L40_00247934, 4");
__asm__(".extern D_L40_00247938, 4");
__asm__(".extern D_L40_0024793C, 4");
__asm__(".extern D_L40_00247940_004252F8, 4");
__asm__(".extern D_L40_00247944_004252F8, 4");
__asm__(".extern D_L40_00247948_004252F8, 4");

void func_L40_004252F8(M_004252F8 *m) {
    V_004252F8 *v = m->vars;
    s32 s;
    P_004252F8 *o;
    O_004252F8 *p;
    E_004252F8 *e;
    s32 i;
    Vec4_004252F8 pos;
    Ray_004252F8 ray;
    Info_004252F8 info;
    Vec4_004252F8 tmp;
    Vec4_004252F8 at;

    if (m->f96 < 0xFFFF) {
        m->f96++;
    }
    s = func_L40_00424228(v);
    if (m->state != 0) {
        if (s != v->f27C) {
            p = func_L39_0061B038(m);
            v->f27C = s;
            p->f28 = s;
        }
        func_L40_00424370(m);
        if (m->state != 0 && m->state != 5) {
            if (v->f23C > 0 || v->f230 == 0 || v->f2A0 != 0) {
                func_L01_00402498(func_L40_00425118, m);
            }
        }
    }
    if (m->state != 5) {
        func_L01_004479A8(m, v->f70);
    }

    switch (m->state) {
    case 0:
        if (D_L40_002417C0[0x194] == 0) {
            if (v->f284 >= 0) {
                o = D_L40_002485DC;
                o += v->f284;
                o->f98 = 0;
                o->f34 = (o->f34 | 0x41) & ~0x1000;
                func_L39_005F08F8(o, 1);
                func_L40_00487860(o, v->f290);
            }
            if (v->f288 >= 0) {
                o = D_L40_002485DC;
                o += v->f288;
                o->f98 = 0;
                o->f34 = (o->f34 | 0x41) & ~0x1000;
                func_L39_005F08F8(o, 1);
                func_L40_00487860(o, v->f294);
            }
            if (v->f28C >= 0) {
                o = D_L40_002485DC;
                o += v->f28C;
                o->f98 = 0;
                o->f34 = (o->f34 | 0x41) & ~0x1000;
                func_L39_005F08F8(o, 1);
                func_L40_00487860(o, v->f298);
            }
            func_003BD360(m);
            return;
        } else {
            O_004252F8 *a = func_L39_00669F20(m, -1, 1);
            p = func_L39_0061B038(m);
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
            func_L39_00619A68(m, -1);
            func_00388B98(&pos, 1.0f);
            {
                S220_004252F8 *q = &v->f220;
                q->a = 0xFFFFFFFF;
                q->c = 0;
                q->d = 0;
                q->b = -1;
            }
            v->f3E = 3;
            v->f234 = 0;
            m->f34 |= 0x4000;
            func_00388440(v->f80, 0, 0x80);
            func_00388440(v->f100, 0, 0x80);
            func_00388440(v->f180, 0, 0x80);
            v->f248 = v->f248 * 0.0174532924f * 0.0166666675f;
            v->f24C = v->f24C * 0.0174532924f * 0.0166666675f;
            v->f244 = v->f244 * 0.0174532924f * 0.0166666675f;
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
                P_004252F8 *t = D_L40_002485DC;
                t += v->f284;
                t->f34 |= 0x41;
            }
            if (v->f288 >= 0) {
                P_004252F8 *t = D_L40_002485DC;
                t += v->f288;
                t->f34 |= 0x41;
            }
            if (v->f28C >= 0) {
                P_004252F8 *t = D_L40_002485DC;
                t += v->f28C;
                t->f34 |= 0x41;
            }
            func_003BE418(m, 1, 0);
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_00452EC8(m)) {
            o = D_L40_002485DC + v->f238;
            if (func_L40_00424218(o)) {
                func_L39_00669098(o->f68[7], m->f21);
            }
            m->f34 &= ~0x1000;
        }
        if (v->f29C == -1 || (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f29C * 128))->owner != m || e->active == 0) {
            v->f29C = func_L39_005F0CE0(2, 4, m);
        }
        if (m->f60 & 2) {
            func_003BE418(m, 1, 0);
        }
        if (v->f280 != -1 && (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f280 * 128))->owner == m && e->active != 0) {
            func_L39_005F0988(v->f280);
        }
        v->f280 = -1;
        v->f38 = v->f27C;
        func_L40_004269C0(m);
        func_L40_004268D0(m);
        break;
    case 2:
        if (func_L01_00452EC8(m)) {
            m->f48 = 1.0f;
            if (m->f43 != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
            if (v->f280 == -1 || (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f280 * 128))->owner != m || e->active == 0) {
                v->f280 = func_L39_005F0CE0(0, 4, m);
            }
            m->f34 |= 0x1000;
        }
        if (m->f60 & 2) {
            func_003BE418(m, 3, 0);
        }
        func_L40_004269C0(m);
        func_L40_004268D0(m);
        v->f240 += v->f248;
        if (v->f240 > v->f244) {
            v->f240 = v->f244;
        }
        if (v->f240 < 0.0f) {
            v->f240 = 0.0f;
        }
        if (v->f240 >= v->f244) {
            v->f240 = v->f244;
            func_L01_00441FB8(m, 3, -1);
        }
        {
            f32 t = func_00389380(v->f250, v->f240);
            v->f250 = t;
            v->f1E4 = t;
        }
        func_L01_0044B5C8(m, v->f180, 2, 0.03f, 0.3f);
        if (v->f29C != -1 && (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f29C * 128))->owner == m && e->active != 0) {
            func_L39_005F0988(v->f29C);
        }
        v->f29C = -1;
        break;
    case 4:
        if (func_L01_00452EC8(m)) {
            if (m->f43 != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
            m->f48 = -1.0f;
            if (v->f29C == -1 || (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f29C * 128))->owner != m || e->active == 0) {
                v->f29C = func_L39_005F0CE0(2, 4, m);
            }
            m->f34 &= ~0x1000;
        }
        if (m->f60 & 2) {
            func_003BE418(m, 1, 0);
        }
        func_L40_004269C0(m);
        func_L40_004268D0(m);
        v->f240 -= v->f248;
        if (v->f240 > v->f244) {
            v->f240 = v->f244;
        }
        if (v->f240 < 0.0f) {
            v->f240 = 0.0f;
        }
        if (v->f240 <= 0.0f) {
            v->f240 = 0.0f;
            func_L01_00441FB8(m, 1, -1);
        }
        {
            f32 t = func_00389380(v->f250, v->f240);
            v->f250 = t;
            v->f1E4 = t;
        }
        func_L01_0044B5C8(m, v->f180, 2, 0.03f, 0.3f);
        if (v->f280 != -1 && (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f280 * 128))->owner == m && e->active != 0) {
            func_L39_005F0988(v->f280);
        }
        v->f280 = -1;
        break;
    case 3:
        if (func_L01_00452EC8(m)) {
            m->f34 |= 0x1000;
        }
        if (m->f60 & 2) {
            func_003BE418(m, 3, 0);
        }
        if (v->f29C != -1 && (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f29C * 128))->owner == m && e->active != 0) {
            func_L39_005F0988(v->f29C);
        }
        v->f29C = -1;
        func_L40_004269C0(m);
        func_L40_004268D0(m);
        {
            f32 t = func_00389380(v->f250, v->f240);
            v->f250 = t;
            v->f1E4 = t;
        }
        func_L01_0044B5C8(m, v->f180, 2, 0.03f, 0.3f);
        m->f96++;
        if (v->f270 > 0) {
            func_L01_004026A0(func_L40_00427000, m);
        }
        func_003BDA38(m, 3, &pos);
        for (i = 0; i < D_L40_00247924; i++) {
            ray.start.q = 0;
            ray.start.f[0] = func_L39_005B2510(D_L40_0024792C, D_L40_00247930);
            ray.start.f[1] = func_L39_005B2510(D_L40_0024792C, D_L40_00247930);
            ray.start.f[2] = func_L39_005B2510(D_L40_00247934, D_L40_00247938);
            ray.dir = ray.start;
            func_00388830(&ray.dir, &ray.dir, D_L40_00247920 * 0.0166666675f);
            func_L39_005C3D70(&pos, &ray.dir,
                              (D_L40_00247910 << 24) | (D_L40_0024790C << 16) | (D_L40_00247908 << 8) | D_L40_00247904,
                              (D_L40_0024790C << 16) | (D_L40_00247908 << 8) | D_L40_00247904,
                              D_L40_00247914, D_L40_00247918, D_L40_0024791C, D_L40_00247928);
        }
        if (D_L40_002478D0 < m->f96) {
            v->f270 = 5;
            m->f96 = 0;
            func_003BD9A0(m, 3, &info);
            ray.dir = info.dir;
            ray.start = info.pos;
            func_00388830(&ray.dir, &ray.dir, D_L40_0024793C * 0.0166666675f);
            tmp = info.pos;
            at = info.pos;
            vec_add_ab(&ray.end, &tmp, &ray.dir);
            func_L07_003C9438(&tmp, &ray, m, 4, v->f260, -1, 0xFFFFFFFF, D_L40_00247940_004252F8,
                              v->f25C + D_L40_003573E0.f1F8[v->f27C] * 2.5f);
            func_L01_00467DA8(&at, 9, D_L40_00247944_004252F8 * 7.0f, 0.1f, 0xBF204080, 2, 1, D_L40_00242AB0, 0.0f, 1);
            func_L01_00467DA8(&at, 9, D_L40_00247944_004252F8 * 5.0f, 0.1f, 0xBF2040A0, 2, -1, D_L40_00242AB0, 0.0f, 1);
            func_L01_00467DA8(&at, 9, D_L40_00247944_004252F8 * 3.5f, 0.1f, 0xC0FFFFFF, 2, 1, D_L40_00242AB0, 0.0f, 1);
            func_L01_00467DA8(&at, 9, D_L40_00247944_004252F8 * 2.5f, 0.1f, 0xB0FFFFFF, 2, -1, D_L40_00242AB0, 0.0f, 1);
            func_L01_0046D570(&at, 7, 1.08000004f, 0.840000033f, 0x46787878, 2, 2, D_L40_00242AB0, 0, 2, 6, 1);
            func_L01_0046D570(&at, 10, 2.0400002f, 0.840000033f, 0x46787878, 2, -1, D_L40_00242AB0, 1, 2, 6, 1);
            func_L01_0046D570(&at, 10, 2.4000001f, 1.80000007f, 0x2D787878, 2, 1, D_L40_00242AB0, 1, 2, 6, 1);
        }
        if ((D_L40_002412AC & 0xF) == (((s32)m >> 8) & 0xF)) {
            f32 r = D_L40_00247948_004252F8 * D_L40_00247948_004252F8;
            if (func_L01_0040C018(&pos, v->f230 + 0x10) < r) {
                func_L01_00443648(m, v->f230 + 0x10, 0x10001, 1, 1, 0, 0.5f,
                                  v->f25C + D_L40_003573E0.f1F8[v->f27C] * 2.5f, 1.0f);
            }
        }
        break;
    case 5:
        if (v->f280 != -1 && (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f280 * 128))->owner == m && e->active != 0) {
            func_L39_005F0988(v->f280);
        }
        v->f280 = -1;
        if (v->f29C != -1 && (e = (E_004252F8 *)(D_L40_001FE1A0 + v->f29C * 128))->owner == m && e->active != 0) {
            func_L39_005F0988(v->f29C);
        }
        v->f29C = -1;
        if (func_L01_00452EC8(m)) {
            m->f98 = 0;
            m->f34 = (m->f34 | 0x41) & ~0x1000;
            func_L39_005F08F8(m, 1);
        }
        break;
    }

    if (v->f238 >= 0) {
        if (func_L40_00424218(D_L40_002485DC + v->f238)) {
            s32 *state = (D_L40_002485DC + v->f238)->f68;
            int *q = D_L40_003575EC[0] + state[7];
            s32 c = q[0x22];
            if (c >= 0) {
                s32 o = c * 3;
                m->f78 = 0x80000000 | (D_L40_0024644A.v[o] << 16) | (D_L40_00246449.v[o] << 8) | D_L40_00246448.v[o];
            } else {
                m->f78 = 0x80FFFFFF;
            }
        }
    }
}
/* localdecomp:end func_L40_004252F8 */
