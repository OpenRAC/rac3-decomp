/* NTSC-U draft (Claude wave K): C of func_L01_003AFB88, the NTSC-U twin of func_L01_003B1358, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details) (NTSC-U twin "func_L01_003AFB88", whose code is not the PAL one).
 * Worker's note: best TOTAL 107 aligned words (retail 254, ours 248), 3 compiles. Flags: PAL line has @ps2as but not -mvu0-use-vf0-vf2 (vec_add_ab/ba), best status flags. Decoded: p=o->p68 particle state (f34,f38 age,f3C,w4C,w50, v0/v10/v20 vectors); age f38+=1; f20 fade ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003AFB88 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_003AFB88 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003AFB88;

typedef struct C_003AFB88 {
    u8 pad00[0x1A];
    u16 h1A;
    u8 pad1C[0x14];
} C_003AFB88;

typedef struct P_003AFB88 {
    V_003AFB88 v0;
    V_003AFB88 v10;
    V_003AFB88 v20;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0xC];
    s32 w4C;
    s32 w50;
} P_003AFB88;

typedef struct G_003AFB88 {
    u8 pad00[0x18];
    u8 *w18;
    u8 pad1C[4];
    V_003AFB88 v20;
} G_003AFB88;

extern u8 D_L01_001D66B0[];
extern G_003AFB88 D_L01_001EAA80;
extern void func_L01_003B0078(void);

extern f32 func_0037E2A8(void);
extern void func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern s32 func_003CE740(void *, void *, s32, s32, void *);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_003B0540(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern void func_003BD360(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_003B05E8(void *);

static inline void Bounce(u8 *o, P_003AFB88 *p, V_003AFB88 *s5, f32 f20, s32 id, f32 miss) {
    V_003AFB88 b;
    C_003AFB88 c;
    V_003AFB88 d;
    V_003AFB88 e;
    V_003AFB88 a;
    G_003AFB88 *g;
    f32 f12;
    p->f34 = p->f34 + 0.33333334f;
    func_00388830(s5, &p->v20, p->f34);
    func_00388830(&b, &p->v20, 0.06666667f);
    func_L01_00443628(&c, o, 0x10000, &b, f20);
    c.h1A = *(u16 *)(o + 0xAA);
    vec_add_ba(&p->v10, &p->v0, &p->v10);
    func_00388830(&d, &p->v20, -0.33333334f);
    vec_add_ab(&d, &d, &p->v10);
    if (func_003CE740(s5, &a, 0x10, *(s32 *)(o + 0xB8), &c) != 0) {
        g = &D_L01_001EAA80;
        if (!((s32)g->w18 == *(s32 *)(o + 0xB8)) && (g->w18 == 0 || *(s16 *)(g->w18 + 0xAA) != id)) {
            V_003AFB88 *s0 = &g->v20;
            p->v10 = g->v20;
            if (func_L01_00452F60(o) == 0) {
                func_L01_003B0540(s0, 0x14, p->w4C);
                func_L01_00452F40(o, 1);
            }
            func_003BD360(o);
            return;
        }
        f12 = miss;
    } else {
        f12 = miss;
    }
    func_00388830(&e, &p->v20, f12);
    vec_add_ab(&p->v0, &p->v0, &e);
    func_L01_004026A0(func_L01_003B0078, o);
}

void func_L01_003AFB88(u8 *o) {
    P_003AFB88 *p;
    V_003AFB88 a;
    f32 f2;
    f32 f20;
    f32 f;
    s32 t;

    p = *(P_003AFB88 **)(o + 0x68);
    f20 = p->f3C;
    f2 = p->f38 + 1.0f;
    p->f38 = f2;
    if (84.0f < f2) {
        f20 = f20 * (1.0f - (f2 - 84.0f) / 6.0f);
    }
    if (2.0f < f2) {
        a = p->v10;
    } else {
        a = p->v0;
    }
    t = (s32)func_0037E2A8();
    func_L01_00466F98(&p->v10, D_L01_001D66B0, 4, 0x60, p->w50, t, 210000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    f = p->f38;
    if (f < 15.0f) {
        Bounce(o, p, &p->v10, f20, 0x1C7F, 0.33333334f);
    } else if (f < 90.0f) {
        if (0.33333334f < func_00388800(p, &p->v10)) {
            Bounce(o, p, &p->v10, f20, 0x1625, 0.8333334f);
        }
    } else {
        func_L01_003B05E8(&p->v10);
        func_003BD360(o);
    }
}
/* localdecomp:end func_L01_003AFB88 */
