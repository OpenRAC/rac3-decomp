#include "common.h"

/* NTSC-U counterpart of func_L39_0051E370 (src/levels/shared/L39_0051E370.c) */
/* localdecomp:start func_L39_0051DF48 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0051E370;

typedef struct {
    u8 pad0[0x2524];
    void *f2524;
    u8 pad2528[0x1C];
    s32 f2544;
} P_0051E370;

typedef struct {
    u8 pad0[0x10];
    f32 f10;
    s32 f14;
    f32 f18;
    s32 f1C;
    u8 pad20[4];
    s32 f24;
    s32 f28;
    s32 f2C;
    P_0051E370 *f30;
    u8 pad34[0xC];
    V_0051E370 f40;
} Vars_0051E370;

typedef struct {
    u8 pad0[0x10];
    V_0051E370 pos;
    u8 b20;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0x32];
    Vars_0051E370 *vars;
    u8 pad6C[0x3E];
    s16 oclass;
} M_0051E370;

typedef struct {
    V_0051E370 v;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    u16 s1A;
    u8 pad1C[4];
    s32 f20;
    u8 pad24[4];
    s32 f28;
    u8 pad2C[4];
} Hit_0051E370;

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2C;
    u8 pad30[0x430];
} Cam_0051E370;

typedef struct {
    u8 pad0[0x21];
    s8 b33;
    u8 pad22[0x12];
    f32 f34;
    u8 pad38[0x48];
} Ent_0051E370;

typedef struct {
    u8 pad0[0x2548];
    s32 f2548;
} Pl_0051E370;

extern s32 func_L01_00454168(s32, s32);
extern void func_003BD360(void *);
extern s32 func_L01_00453FC0(void *, s32, void *);
extern char *func_L01_00454190(s32, s32);
extern void func_L39_0051EB60(void *, void *);
extern s32 func_L39_005BC958(void *, s32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CF790(s32, s32, f32, s32, s32);
extern void func_L39_005FD6D8(void);
extern u8 *func_0037E0B8(void *);
extern s32 func_L01_004435E8(char *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern s32 func_00388398(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L39_0051F250(void);

extern Cam_0051E370 D_L39_0024DF80[];
extern Pl_0051E370 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern Ent_0051E370 D_L39_0049C950[];
extern M_0051E370 *D_L39_002638C0[];
extern f32 D_L39_0024A9A4;
__asm__(".extern D_L39_0024A9A4, 4");
extern f32 D_L39_0024A9A0;
__asm__(".extern D_L39_0024A9A0, 4");

void func_L39_0051DF48(M_0051E370 *m) {
    Vars_0051E370 *v = m->vars;
    V_0051E370 pos;
    V_0051E370 sphere;
    V_0051E370 dir;
    V_0051E370 from;
    V_0051E370 to;
    Hit_0051E370 hit;
    u8 tmp[0x10];
    f32 f;
    f32 t;

    if (m->b20 != 0 && func_L01_00454168(m->oclass, v->f28) == 0) {
        func_003BD360(m);
        return;
    }

    switch (m->b20) {
    case 0:
        m->b20 = 1;
        v->f14 = 0x14;
        v->f10 = 0.0f;
        v->f18 = 0.6666667f;
        v->f1C = 0x7F;
        v->f24 = 0x6F;
        v->f28 = func_L01_00453FC0(m, 0, tmp);
        func_L01_00454190(m->oclass, v->f28);
        pos = m->pos;
        pos.z += 1.0f;
        func_L39_0051EB60(m, &m->pos);
        if (v->f30 != 0) {
            sphere = pos;
            sphere.w = 2.0f;
            if (func_L39_005BC958(&sphere, 0, 100.0f) != -1) {
                (D_L39_0024DF80 + v->f30->pad0[0x24C9])->f20 = 0.45f;
                (D_L39_0024DF80 + v->f30->pad0[0x24C9])->f28 = 0x28;
                (D_L39_0024DF80 + v->f30->pad0[0x24C9])->f2C = 0;
            }
        }
    case 1: {
        s32 n;
        s32 i;
        Pl_0051E370 *pl;
        s32 arg;
        Ent_0051E370 *e;
        Ent_0051E370 *tab;
        Ent_0051E370 *q;

        v->f24 -= 5;
        if (v->f24 < 0) {
            v->f24 = 0;
        }
        v->f10 += v->f18;
        func_00388830(&sphere, &v->f40, (1.0f - (f32)v->f14 / 20.0f) * 10.0f);
        vec_add_ab(&sphere, &sphere, &m->pos);
        t = (1.0f - (f32)v->f14 / 20.0f) * 12.0f + 0.001f;
        arg = v->f30->f2544;
        if (D_L39_0024CF20[arg] != 0) {
            arg = D_L39_0024CF20[arg]->f2548;
        } else {
            arg = -1;
        }
        func_L39_005FD658(arg);
        n = func_003CF790((s32)&sphere, 0, t, (s32)m, 0);
        func_L39_005FD6D8();
        {
            for (i = 0; i < n; i++) {
                M_0051E370 *o;
                tab = D_L39_0049C950;
                q = &tab[5];
                if (func_0037E0B8(D_L39_002638C0[i]) == 0 && !((D_L39_002638C0[i])->f34 & 0x4000)) {
                    goto next;
                }
                if (((v->f30 == 0 || D_L39_002638C0[i] == v->f30->f2524) && (D_L39_002638C0[i])->oclass != 0x1068) || (D_L39_002638C0[i])->oclass == 0xA5A) {
                    goto next;
                }
                func_00388830(&dir, &v->f40, -1.0f);
                vec_add_ba(&from, &dir, &m->pos);
                vec_add_ab(&to, &dir, &D_L39_002638C0[i]->pos);
                if (D_L39_002638C0[i]->oclass == 0x1C57 || D_L39_002638C0[i]->oclass == 0x1A63) {
                    vec_add_ab(&to, &to, &dir);
                }
                if (func_L01_004435E8((char *)D_L39_002638C0[i]) == 0 && func_003CE740(&from, &to, 2, D_L39_002638C0[i], 0) != 0) {
                    goto next;
                }
                o = D_L39_002638C0[i];
                if (o->oclass != 0x1E41 && fabs_asm(m->pos.z - o->pos.z) > 4.0f) {
                    goto next;
                }
                vec_sub_ab(&dir, &o->pos, &m->pos);
                func_00388830(&dir, &dir, 1.0f);
                func_00388830(&hit, &hit, 1.0f);
                if (func_L39_00646268((u8 *)v->f30, 5) != 0) {
                    e = &D_L39_0049C950[q->b33];
                } else {
                    e = &tab[5];
                }
                func_L01_00443628(&hit, m, 0x1030001, &dir, e->f34);
                hit.v = dir;
                hit.f20 = 1;
                hit.v.w = 5627.9248f;
                hit.b18 = 5;
                hit.b19 = 3;
                hit.s1A = (D_L39_002638C0[i])->oclass;
                hit.f28 = v->f2C;
                func_L01_00443840(D_L39_002638C0[i], &hit);
            next:;
            }
        }
        if (func_00388398(&v->f14) != 0) {
            m->b20 = 2;
            v->f14 = 0x28;
        }
        break;
    }
    case 2:
        v->f10 += v->f18;
        f = (f32)v->f14 / 40.0f;
        if (func_00388398(&v->f14) != 0) {
            if (v->f1C != 0) {
                v->f1C--;
            } else {
                v->f1C = 0;
                m->b20 = 6;
            }
        } else {
            v->f1C = f * 127.0f;
        }
        break;
    case 6:
        v->f10 += v->f18;
        func_003BD360(m);
        return;
    }

    D_L39_0024A9A4 -= 0.04f;
    if (D_L39_0024A9A0 < -8.0f) {
        D_L39_0024A9A0 += 8.0f;
    }
    if (D_L39_0024A9A4 < -8.0f) {
        D_L39_0024A9A4 += 8.0f;
    }
    func_L01_004026A0(func_L39_0051F250, m);
}
/* localdecomp:end func_L39_0051DF48 */
