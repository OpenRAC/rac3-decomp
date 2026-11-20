#include "common.h"

/* declared by functions of L39_00561630.c, which this file was cut from */
typedef struct {
    u8 pad0[0x18];
    s32 x18;
    u8 pad1C[0x10];
    f32 x2C;
} S_00561630;
typedef struct {
    u8 pad0[0x68];
    S_00561630 *p68;
} O_00561630;

/* localdecomp:start func_L39_005617D8 */
#include "vu0.h"

typedef struct {
    f32 x, y, z;
    u8 pad0C[0x14];
    u8 b20;
} T_005617D8;

typedef struct {
    f32 v[4];
    s16 h10;
    s16 h12;
    void *p14;
    s32 w18;
    s32 w1C;
    f32 f20;
    T_005617D8 *p24;
    f32 f28;
    f32 f2C;
    s32 w30;
} V_005617D8;

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 b20;
    u8 pad21[0x13];
    u16 h34;
    u8 pad36[0x32];
    V_005617D8 *v68;
    u8 pad6C[0x2A];
    u16 h96;
    s32 w98;
    u8 pad9C[0x1C];
    void *pB8;
    u8 padBC[4];
    f32 m[3][4];
} S_005617D8;

typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    void *pDC;
} Slot_005617D8;

extern u8 D_001FE020[];
typedef struct {
    u8 pad0[0x18];
    void *f18;
    u8 pad1C[4];
    f32 v20[4];
} G_005617D8;

extern G_005617D8 D_L39_0025F740;
typedef struct { u8 pad0[0x1C]; u8 *p1C; } M_005617D8;
extern M_005617D8 D_L39_0024CE00 __attribute__((section(".sdata")));
__asm__(".extern D_L39_00242930, 16");
extern s32 D_L39_00242930;

extern s32 func_L39_005F2FA0(s32, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern u8 *func_00382348(s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DB48(f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L39_005F3088(s32);
extern void func_003C2880(void *);
extern void func_L39_00561630(O_00561630 *a0, u8 *a1);

static __inline__ s32 collide_005617D8(s32 team, void *from, void *to, s32 flags, void *ignore, void *out) {
    s32 r;
    func_L39_005FFDF8(team);
    r = func_003D3CB0(from, to, flags, ignore, out);
    func_L39_005FFE78();
    return r;
}

void func_L39_005617D8(S_005617D8 *self) {
    V_005617D8 *v = self->v68;
    f32 np[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 t[4] __attribute__((aligned(16)));
    f32 base[4] __attribute__((aligned(16)));
    f32 step[4] __attribute__((aligned(16)));
    f32 pt[4] __attribute__((aligned(16)));

    switch (self->b20) {
    case 0: {
        T_005617D8 *p;
        G_005617D8 *g;
        f32 *pos;
        s32 hit;

        self->h96++;
        if (func_L39_005F2FA0((s32)self, v->w30) == 0) {
            v->w30 = func_L39_005F33E0(0, 4, self);
        }
        p = v->p24;
        if (p != 0) {
            f32 *q = (f32 *)func_00382348((s32)p);
            if (p->b20 == 0xFE || (p->b20 == 0xFD || (q != 0 && *q <= 0.0f))) {
                v->p24 = 0;
            } else if (self->h96 >= 5) {
                f32 a;
                f32 s;
                t[0] = p->x * 0.0009765625f;
                t[1] = p->y * 0.0009765625f;
                t[2] = p->z * 0.0009765625f;
                t[3] = 0.0f;
                vec_sub_ba(d, t, self->pos);
                func_0038CF68(d, d, 1.0f);
                func_0038CF68(dir, v, 1.0f);
                a = func_0038DB48(func_0038D0C8(func_0038CE68(d, dir)) + 1.5707964f);
                s = 1.0f;
                if (v->f28 < a) {
                    s = v->f28 / a;
                }
                func_003C4098(d, dir, d, s);
                {
                    f32 *r0 = self->m[0];
                    f32 *r1 = self->m[1];
                    f32 *r2 = self->m[2];
                    func_0038CF68(d, d, 1.0f);
                    *(vu0_q *)r0 = *(vu0_q *)d;
                    func_0038CE90(r1, r0, r2);
                    func_0038CE90(r2, r1, r0);
                }
                self->m[0][3] = 0.0f;
                self->m[1][3] = 0.0f;
                self->m[2][3] = 0.0f;
                func_0038CF68(v, d, func_0038CEA8(v));
            }
        }
        vec_add_ba(np, self->pos, v);
        if (v->h12 < 12) {
            v->h12++;
        }
        if (v->f2C > 0.0f) {
            func_L01_00446760(dir, self, 0x10001, &D_L39_00242930, 0.0f);
        } else {
            func_L01_00446760(dir, self, 0x10001, &D_L39_00242930, (f32)v->w18);
        }
        {
            s32 team = -1;
            void *n = v->p14;
            pos = self->pos;
            if (D_L39_0024CE00.p1C != 0) team = *(s32 *)(D_L39_0024CE00.p1C + 0x2548);
            hit = collide_005617D8(team, pos, np, 0, n, dir);
        }
        if (hit != 0 && (g = &D_L39_0025F740)->f18 != self->pB8 && g->f18 != self) {
            self->w98 = 0;
            self->h34 = (self->h34 | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            func_L01_004450F0(self, 1, -1);
            ((void (*)(void *, void *, s32, s32))func_L39_00561630)(self, g->v20, 10, 1);
            func_L39_005F33E0(1, 0, self);
        } else if (func_0038CB00(&v->h10)) {
            self->w98 = 0;
            self->h34 = (self->h34 | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            func_L01_004450F0(self, 1, -1);
            ((void (*)(void *, void *, s32, s32))func_L39_00561630)(self, pos, 10, 1);
            func_L39_005F33E0(1, 0, self);
        } else {
            s32 i;
            func_003C2F58(self, 1, base);
            func_0038CE20(step, v, 0.2f);
            for (i = 0; i < 5; i++) {
                f32 f = func_L39_005B4410(0.1f, 0.3f) * v->f20;
                s32 c = func_L39_005B4398(0xFF);
                func_L01_00443B88(pt, 0.0f, 0.1f);
                vec_add_ba(pt, pt, base);
                func_L01_0046FB40(pt, &D_L39_00242930, 12, v->w1C, c, 0x20, 0, f * 210000.0f, f * 0.2f * 210000.0f, 0.0f, 0);
                vec_add_ab(base, base, step);
            }
        }
        *(vu0_q *)self->pos = *(vu0_q *)np;
        break;
    }
    case 1: {
        s32 h = v->w30;
        if (h != -1) {
            Slot_005617D8 *e = (Slot_005617D8 *)(D_001FE020 + (h << 7));
            if (e->pDC == self && e->bD0 != 0) {
                func_L39_005F3088(h);
            }
        }
        v->w30 = -1;
        if (--v->h12 == -1) {
            func_003C2880(self);
        }
        break;
    }
    }
}
/* localdecomp:end func_L39_005617D8 */
