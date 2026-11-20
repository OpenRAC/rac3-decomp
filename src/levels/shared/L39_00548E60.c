#include "common.h"

/* localdecomp:start func_L39_00548E60 */
#include "vu0.h"
extern void func_L01_0040E020(void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005B4398(s32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, void *, f32, u32, s32);

void func_L39_00548E60(u8 *self) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 vel;
    s32 i;
    s32 j;
    s32 k;
    s32 life;
    f32 size;

    if (self[0xBC] == 0) {
        return;
    }
    func_L01_0040E020(self + 0xBC);
    func_0038CE20(&pos, self + 0xD0, 0.1f);
    vec_add_ba(&pos, &pos, self + 0x10);
    func_0038CE20(&off, self + 0xC0, 0.275f);
    vec_add_ab(&pos, &pos, &off);
    func_0038CE20(&vel, self + 0xD0, 0.120000005f);
    for (i = 0; i < 4; i++) {
        u8 *p;
        k = func_L39_005B4398(0x10);
        if (func_L39_005B4398(2) != 0) {
            k = -k;
        }
        p = func_L01_004669B0(&pos, 0.04f, 1.0f, 0.9f, k, &vel, 52500.0f, 0x7F204080, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            *(s16 *)(p + 0xA) = 7;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
    }
    k = 0x10;
    size = 15750.001f;
    life = 2;
    for (j = 0; j < 3; j++) {
        u8 *p;
        p = func_L01_004669B0(&pos, 0.02f, 1.0f, 1.0f, k, &vel, size, 0x7FFFFFFF, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s16 *)(p + 0xA) = life;
            p[8] = func_L39_005B4398(0xFF);
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
        k = -k;
        life <<= 1;
        size -= 3150.0f;
    }
}
/* localdecomp:end func_L39_00548E60 */

/* localdecomp:start func_L39_005490D0 */
#include "vu0.h"

extern f32 D_L39_0024AFE0;
__asm__(".extern D_L39_0024AFE0, 4");
extern f32 D_L39_0024AFE4;
__asm__(".extern D_L39_0024AFE4, 4");
extern s32 D_L39_0024AFE8;
__asm__(".extern D_L39_0024AFE8, 4");
extern s32 D_L39_0024AFEC;
__asm__(".extern D_L39_0024AFEC, 4");
extern s32 D_L39_0024AFF0;
__asm__(".extern D_L39_0024AFF0, 4");
extern f32 D_L39_0024AFF4;
__asm__(".extern D_L39_0024AFF4, 4");
extern f32 D_L39_0024AFF8;
__asm__(".extern D_L39_0024AFF8, 4");
extern f32 D_L39_0024AFFC;
__asm__(".extern D_L39_0024AFFC, 4");
extern f32 D_L39_0024B000;
__asm__(".extern D_L39_0024B000, 4");
extern f32 D_L39_0024B004;
__asm__(".extern D_L39_0024B004, 4");
extern f32 D_L39_0024B008;
__asm__(".extern D_L39_0024B008, 4");

extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_004660F8(void *, void *);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_005490D0(u8 *a0) {
    vu0_v4 q;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    u8 *s;
    u8 *p;
    s32 i;
    f32 ang;
    s32 life;
    s32 spin;
    f32 f;
    vu0_v4 *c;
    s32 col;

    s = *(u8 **)(*(u8 **)(a0 + 0x68) + 0x40);
    if (s == 0) {
        return;
    }
    *(vu0_q *)&v20 = 0;
    v20.x = 0.3f;
    v20.y = -1.0f;
    v20.w = 1.0f;
    col = 0x307F7F7F;
    func_0038D000(&v20, &v20, a0 + 0xC0);
    ang = 0.0f;
    vec_add_ab(&v30, a0 + 0x10, &v20);
    a0[0xBC] = 5;
    func_0038D890(&v20, s + 0x380, s + 0x390, 0.34906584f);
    v10 = v20;
    for (i = 19; i >= 0; i--) {
        ang = func_0038DAB8(ang, func_L39_005B4410(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_L39_005B4410(0.120000005f, 0.36f));
        p = func_L01_004660F8(&v30, &v40);
        if (p != 0) {
            c = (vu0_v4 *)(p + 0x30);
            func_0038CE20(&v40, &v10, 0.75f);
            vec_add_ab(p + 0x10, &v30, &v40);
            *(vu0_v4 *)(p + 0x20) = v30;
            c->w = 2.0f;
            *(f32 *)(p + 0x1C) = 0.05f;
            *(f32 *)(p + 0x2C) = 0.5f;
            *(s32 *)(p + 0x4) = col;
            *(s32 *)(p + 0xC) = col;
        }
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, s + 0x380, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
    func_0038D890(&v20, s + 0x380, s + 0x390, D_L39_0024AFE0 * 0.017453292f);
    ang = 0.0f;
    v10 = v20;
    qzero(&v60);
    if (*(s32 *)(s + 0x2D0) != 0) {
        func_0038CE20(&v60, s + 0x140, 1.7f);
    }
    for (i = 0; i < 20; i++) {
        ang = func_0038DAB8(ang, func_L39_005B4410(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_L39_005B4410(D_L39_0024AFF8 * 0.020000001f, D_L39_0024AFFC * 0.020000001f));
        vec_add_ab(&v40, &v40, &v60);
        life = (D_L39_0024AFF0 * 5 + 2) / 6;
        spin = func_L39_005B4468(1.0f, 2.0f);
        v50.x = v30.x + func_L39_005B4468(0.0f, D_L39_0024AFE4);
        v50.y = v30.y + func_L39_005B4468(0.0f, D_L39_0024AFE4);
        v50.z = v30.z + func_L39_005B4468(0.0f, D_L39_0024AFE4);
        f = func_L39_005B4410(D_L39_0024B000, D_L39_0024B004);
        vec_sub_ab(&v50, &v50, &v40);
        func_L01_0046A610(&v50, &v40, life, D_L39_0024AFE8, D_L39_0024AFEC, spin,
                          f * 210000.0f, D_L39_0024B008, D_L39_0024AFF4, 0.0f, 0.0f);
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, s + 0x380, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
}
/* localdecomp:end func_L39_005490D0 */

/* localdecomp:start func_L39_00549510 */
#include "vu0.h"

extern u8 D_L39_004997E0[];
extern u8 *D_L39_002637C0[];
typedef struct { u8 pad0[0x18]; u8 *f18; } D_0025F740_00549510;
extern D_0025F740_00549510 D_L39_0025F740;
typedef struct { f32 r, g, b, pad; vu0_v4 pos; } Light_00549510;
extern Light_00549510 D_L39_002667C0[];
typedef struct { u8 pad0[0x21]; s8 b21; u8 pad22[0x28 - 0x22]; f32 f28; u8 pad2C[0x80 - 0x2C]; } Cfg_00549510;
extern Cfg_00549510 D_L39_0049C890[];
extern u8 D_L39_00470500[];
typedef struct { u8 pad[0x50]; } Ent_00549510;

extern void func_L39_0061C4D0(u8 *, u8 **);
extern s32 func_L01_0040E050(void *);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_L39_00674320(u8 *);
extern s32 func_L39_005FFD20(f32, f32 *, s32 *, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void *func_L39_006472D0(void *, s32, s32, f32, f32, f32, f32, f32, s32);
extern u8 *func_00382348(void *);
extern s32 func_L39_00639D90(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L39_006732D0(void *, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_L39_005B8928(void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_0054A028(u8 *, void *);
extern void func_L39_00621D60(void *, s32);
extern s32 func_L01_003F2058(void *, void *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L01_003F2278(s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L39_0059EBC8(void *, f32, f32, f32, f32, f32);
extern s32 func_0038CB00(void *);
extern void func_L01_00424D88(s32);

static __inline__ s32 decode_00549510(u8 *p) {
    u32 buf[2];
    u8 *bp;
    s32 i;
    if (*p == 0) {
        return 0;
    } else {
        s32 n = *p;
        s32 m = n + 1;
        s32 k = ((s32)p - n) & 7;
        bp = (u8 *)buf;
        for (i = 0; i < 40; i += 5) {
            *bp++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        return buf[1];
    }
}

static __inline__ void radius_00549510(u8 *v, u8 *m) {
    u8 *info = func_00382348(m);
    if (info == 0) {
        *(f32 *)(v + 0x28) = 0.1f;
    } else {
        *(f32 *)(v + 0x28) = *(f32 *)(info + 0x10);
    }
}

static __inline__ Cfg_00549510 *cfgAt_00549510(s32 i) {
    return &D_L39_0049C890[i];
}

static __inline__ void light_00549510(s32 i, void *pos, f32 a, f32 c, f32 d, f32 e) {
    Light_00549510 *l = &D_L39_002667C0[i];
    l->pos = *(vu0_v4 *)pos;
    l->pos.w = a;
    l->r = c;
    l->g = d;
    l->b = e;
}

static __inline__ void sprite_00549510(u8 *g, u8 *self, u32 col, void *pos, s32 id, f32 scale) {
    if (g[0x1A14] != 0) {
        func_L01_003F6F20(g[0x24C9], self, col, pos, id, -1, 4, scale, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    }
}

/* the target search of func_L39_006472D0 with its last argument 0 */
static __inline__ u8 *aim_00549510(u8 *g, vu0_v4 *from, vu0_v4 *dir, f32 a, f32 b, f32 r, f32 c, f32 d) {
    return func_L39_006472D0(g, (s32)from, (s32)dir, a, b, r, c, d, 0);
}

void func_L39_00549510(u8 *self) {
    u8 *v;
    u8 *g;
    u8 *target;
    u8 *cur;
    u8 *info;
    u8 *c;
    s32 x;
    s32 i;
    s32 st;
    s32 n;
    f32 f;
    f32 d;
    f32 cr;
    f32 cb;
    f32 cg;
    Cfg_00549510 *cfg;
    vu0_v4 *dir;

    v = *(u8 **)(self + 0x68);
    if (self[0x20] == 0) {
        func_L39_0061C4D0(self, (u8 **)(v + 0x40));
        self[0x20] = 1;
        *(s16 *)(v + 0x2C) = -1;
        *(s32 *)(v + 0x34) = 4;
        *(s32 *)(v + 0x3C) = -1;
        *(s16 *)(v + 0x2E) = 0;
        *(s32 *)(v + 0x20) = 0;
        *(s32 *)(v + 0x30) = 0;
        *(s32 *)(v + 0x38) = 0;
    }
    g = *(u8 **)(v + 0x40);
    if (g == 0) {
        return;
    }
    func_L39_00548E60(self);
    func_L01_0040E050(v + 0x10);
    x = decode_00549510(g + 0x19E4);
    if ((x ^ 1) == 0) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x1D, 0, 0, 1);
    }
    {
    vu0_v4 w;
    vu0_v4 a;
    vu0_v4 b;
    Ent_00549510 ent;
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 off2;
    if (self[0x42] == self[0x43]) {
        if (self[0x60] & 2) {
            func_L01_00444F38(self, 1, 0, 2, 0);
        }
    }
    if (*(s32 *)(g + 0x3E0) != 0) {
        *(s32 *)(g + 0x1078) = *(s32 *)(g + 0x3E0);
    }
    if (g[0x1A14] == 0) {
        func_L39_00674320(g);
    }
    *(f32 *)(v + 0x44) = 0.0f;
    target = 0;
    if (*(s32 *)(g + 0x1310) != 0) {
        if (g[0x1A14] != 0) {
            if (*(s32 *)(v + 0x38) == 0) {
                *(s32 *)(v + 0x20) = 0;
                *(s32 *)(v + 0x34) = 4;
            }
            *(s32 *)(v + 0x38) = 1;
            f = (*(f32 *)(g + 0x1250) - 0.85f) / 0.14999998f;
            if (f > 1.0f) {
                f = 1.0f;
            } else if (f < 0.0f) {
                f = 0.0f;
            }
            *(f32 *)(v + 0x44) = f;
            if (f != 0.0f) {
                sprite_00549510(g, self, func_L39_005FFD20(150.0f, (f32 *)(g + 0x1338), (s32 *)(g + 0x133C), 1), 0, 0x27, 0.7f);
                target = *(u8 **)(g + 0x122C);
            } else {
                sprite_00549510(g, self, func_L39_005FFD20(150.0f, (f32 *)(g + 0x1338), (s32 *)(g + 0x133C), 0), 0, 0x27, 0.7f);
                target = 0;
            }
        }
    } else if (g[0x1A14] != 0) {
        *(s32 *)(v + 0x38) = 0;
        if (g[0x1A08] != 0) {
            func_0038CE20(&a, self + 0xD0, -1.0f);
        } else {
            a = *(vu0_v4 *)(g + 0x3B0);
        }
        func_0038CE20(&b, *(u8 **)(g + 0x2524) + 0xE0, 0.75f);
        vec_add_ab(&b, g + 0xA0, &b);
        dir = &a;
        target = aim_00549510(g, &b, dir, 0.31415927f, 0.29670596f, 75.0f, 0.31415927f, 0.31415927f);
        *(f32 *)(v + 0x44) = 0.5f;
    }
    if (g[0x1A08] != 0) {
        func_0038CE20(&a, self + 0xD0, -1.0f);
        target = 0;
    }
    if (*(u8 **)(v + 0x20) != 0) {
        info = func_00382348(*(u8 **)(v + 0x20));
        c = *(u8 **)(v + 0x20);
        if (c == 0 || c[0x20] == 0xFE || c[0x20] == 0xFD || (info != 0 && *(f32 *)info <= 0.0f) ||
            c[0x31] == 0 || (g[0x1A08] != 0 && func_L39_00639D90(g) == 0)) {
            *(u8 **)(v + 0x20) = 0;
            *(s32 *)(v + 0x34) = 4;
        } else if (target != *(u8 **)(v + 0x20)) {
            if (func_0038CAD0(v + 0x24) != 0) {
                *(u8 **)(v + 0x20) = 0;
                *(s32 *)(v + 0x34) = 4;
            }
        } else {
            *(s32 *)(v + 0x24) = 4;
            d = func_0038CF00(*(void **)(g + 0x2530), target + 0x10) / 150.0f;
            radius_00549510(v, target);
            func_0038CE20(&w, target + 0xE0, *(f32 *)(v + 0x28));
            vec_add_ab(&w, target + 0x10, &w);
            sprite_00549510(g, self, func_0038DBD8(0xFF0FFFFF, 0xFF0F0FFF, *(f32 *)(v + 0x44)), &w, 0x26, fabs_asm(0.9f - d * 0.65f));
            *(u8 **)(g + 0x1078) = target;
        }
    } else if (g[0x1A14] != 0 && target == *(u8 **)(v + 0x30)) {
        if (func_0038CAD0(v + 0x34) != 0) {
            *(u8 **)(v + 0x20) = target;
            *(s32 *)(v + 0x24) = 4;
            radius_00549510(v, target);
        }
    } else {
        *(s32 *)(v + 0x34) = 4;
    }
    *(u8 **)(v + 0x30) = target;
    cur = *(u8 **)(v + 0x20);
    st = func_L39_006732D0(g + 0x1A40, 0, 1, (s32)&ent);
    if (st == 8) {
        if (self[0x43] == 0) {
            func_003C3A10(self, 1, 0, 3);
        }
        *(s32 *)(v + 0x48) = 1;
        if (cur == 0) {
            func_0038CE20(&pos, self + 0xD0, -1.0f);
            vec_add_ab(&pos, &pos, self + 0x10);
            func_0038CE20(&off, self + 0xC0, 0.275f);
            vec_add_ab(&pos, &pos, &off);
            n = func_003D4D00(&pos, 1, *(void **)(g + 0x2524), 0, 1.0f);
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    u8 *m = D_L39_002637C0[i];
                    u8 *mi = func_00382348(m);
                    u8 *t;
                    if (m[0x31] != 0 && *(s16 *)(m + 0x32) > 0 && m != 0 && m[0x20] != 0xFE && m[0x20] != 0xFD &&
                        *(s16 *)(m + 0xAA) != 0xC87 && *(s16 *)(m + 0xAA) != 0xECC && mi != 0 &&
                        (*(f32 *)mi > 0.0f || func_L39_005B8928(m) != 0)) {
                        t = *(u8 **)(m + 0x24);
                        if (t == 0 || t[0x46] != 5) {
                            cur = D_L39_0025F740.f18;
                            *(u8 **)(v + 0x20) = cur;
                            break;
                        }
                    }
                }
            }
        }
        func_L39_005F33E0(0, 0, self);
        *(s16 *)(v + 0x2E) = 0xC;
        func_L39_005490D0(self);
        func_L39_0054A028(self, &ent);
        func_L39_00621D60(g, -1);
        func_003C3A10(self, 2, 0, 0);
        *(s32 *)(v + 0x3C) = func_L01_003F2058(D_L39_00470500, *(void **)(g + 0x2534));
        if (func_L39_00648AE0(g, 4) != 0) {
            cfg = cfgAt_00549510(D_L39_0049C890[4].b21);
        } else {
            cfg = cfgAt_00549510(4);
        }
        *(f32 *)(v + 0x10) = 1.0f / cfg->f28;
    } else if (st == 4) {
        if (*(s32 *)(v + 0x48) == 1) {
            func_L39_005F33E0(1, 0, self);
            *(s32 *)(v + 0x48) = 0;
        }
    }
    if ((st != 8 || g[0x1A07] == 0) && *(s32 *)(v + 0x3C) >= 0) {
        func_L01_003F2278(*(s32 *)(v + 0x3C), *(void **)(g + 0x2534));
        *(s32 *)(v + 0x3C) = -1;
    }
    if (self[0x42] != 2 && *(s16 *)(v + 0x2E) > 0) {
        n = *(s16 *)(v + 0x2E);
        if (n > 10) {
            f32 t = (f32)(12 - n);
            cr = t * 0.5f;
            cb = t * 0.5f * 0.5f;
            cg = t * 0.8f * 0.5f;
        } else {
            f32 t = (f32)n;
            cr = t * 0.1f;
            cg = t * 0.8f * 0.1f;
            cb = t * 0.5f * 0.1f;
        }
        if (g[0x1A08] != 0) {
            func_0038CE20(&off, self + 0xD0, -1.0f);
            func_003C2F58(self, 0, &pos);
        } else {
            off = *(vu0_v4 *)(g + 0x3B0);
            func_003C2F58(self, 0, &pos);
        }
        vec_add_ba(&pos, &pos, &off);
        func_0038CE20(&off2, *(u8 **)(g + 0x2524) + 0xE0, 0.3f);
        vec_add_ab(&pos, &pos, &off2);
        if (*(s16 *)(v + 0x2C) == -1) {
            *(s16 *)(v + 0x2C) = func_L39_0059EBC8(&pos, 8.0f, 0.0f, cr, cg, cb);
        } else {
            light_00549510(*(s16 *)(v + 0x2C), &pos, 8.0f, cr, cg, cb);
        }
        func_0038CB00(v + 0x2E);
    } else if (*(s16 *)(v + 0x2C) != -1) {
        func_L01_00424D88(*(s16 *)(v + 0x2C));
        *(s16 *)(v + 0x2C) = -1;
        *(s16 *)(v + 0x2E) = 0;
    }
    if (self[0x43] == 2) {
        if (*(s16 *)(v + 0x2C) != -1) {
            func_L01_00424D88(*(s16 *)(v + 0x2C));
        }
        *(s16 *)(v + 0x2C) = -1;
        *(s16 *)(v + 0x2E) = 0;
    }
    }
}
/* localdecomp:end func_L39_00549510 */
