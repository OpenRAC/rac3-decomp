#include "common.h"

/* NTSC-U counterpart of func_L39_00549510 (src/levels/shared/L39_00548E60.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L39_00548BE0 */
#include "vu0.h"

extern u8 D_L39_004998A0[];
extern u8 *D_L39_002638C0[];
typedef struct { u8 pad0[0x18]; u8 *f18; } D_0025F740_00549510;
extern D_0025F740_00549510 D_L39_0025F840;
typedef struct { f32 r, g, b, pad; vu0_v4 pos; } Light_00549510;
extern Light_00549510 D_L39_002668C0_00548BE0[];
typedef struct { u8 pad0[0x21]; s8 b21; u8 pad22[0x28 - 0x22]; f32 f28; u8 pad2C[0x80 - 0x2C]; } Cfg_00549510;
extern Cfg_00549510 D_L39_0049C950[];
extern u8 D_L39_00470600_00548BE0[];
typedef struct { u8 pad[0x50]; } Ent_00549510;

extern void func_L39_00619D58(u8 *, u8 **);
extern s32 func_L01_0040BB20(void *);
extern void func_L01_00441E00(u8 *, s32, s32, s32, s32);
extern void func_L39_006719D8(u8 *);
extern s32 func_L39_005FD580(f32, f32 *, s32 *, s32);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void *func_L39_00644AA0(void *, s32, s32, f32, f32, f32, f32, f32, s32);
extern u8 *func_0037E0B8(void *);
extern s32 func_L39_00637548(void *);
extern s32 func_00388398(void *);
extern f32 func_003887C8(void *, void *);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L39_00670988(void *, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern s32 func_L39_005B6970(void *);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_00549708(u8 *, void *);
extern void func_L39_0061F5C0(void *, s32);
extern s32 func_L01_003F0118(void *, void *);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L01_003F0338(s32, void *);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L39_0059CF60(void *, f32, f32, f32, f32, f32);
extern s32 func_003883C8(void *);
extern void func_L01_00421FE0(s32);

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
            *bp++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        return buf[1];
    }
}

static __inline__ void radius_00549510(u8 *v, u8 *m) {
    u8 *info = func_0037E0B8(m);
    if (info == 0) {
        *(f32 *)(v + 0x28) = 0.1f;
    } else {
        *(f32 *)(v + 0x28) = *(f32 *)(info + 0x10);
    }
}

static __inline__ Cfg_00549510 *cfgAt_00549510(s32 i) {
    return &D_L39_0049C950[i];
}

static __inline__ void light_00549510(s32 i, void *pos, f32 a, f32 c, f32 d, f32 e) {
    Light_00549510 *l = &D_L39_002668C0_00548BE0[i];
    l->pos = *(vu0_v4 *)pos;
    l->pos.w = a;
    l->r = c;
    l->g = d;
    l->b = e;
}

static __inline__ void sprite_00549510(u8 *g, u8 *self, u32 col, void *pos, s32 id, f32 scale) {
    if (g[0x1A14] != 0) {
        func_L01_003F4D78(g[0x24C9], self, col, pos, id, -1, 4, scale, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    }
}

/* the target search of func_L39_00644AA0 with its last argument 0 */
static __inline__ u8 *aim_00549510(u8 *g, vu0_v4 *from, vu0_v4 *dir, f32 a, f32 b, f32 r, f32 c, f32 d) {
    return func_L39_00644AA0(g, (s32)from, (s32)dir, a, b, r, c, d, 0);
}

void func_L39_00548BE0(u8 *self) {
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
    f32 cg;
    f32 cb;
    Cfg_00549510 *cfg;
    vu0_v4 *dir;

    v = *(u8 **)(self + 0x68);
    if (self[0x20] == 0) {
        func_L39_00619D58(self, (u8 **)(v + 0x40));
        self[0x20] = 1;
        *(s16 *)(v + 0x2C) = -1;
        *(s32 *)(v + 0x34) = 5;
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
    func_L39_00548548(self);
    func_L01_0040BB20(v + 0x10);
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
            func_L01_00441E00(self, 1, 0, 2, 0);
        }
    }
    if (*(s32 *)(g + 0x3E0) != 0) {
        *(s32 *)(g + 0x1078) = *(s32 *)(g + 0x3E0);
    }
    if (g[0x1A14] == 0) {
        func_L39_006719D8(g);
    }
    *(f32 *)(v + 0x44) = 0.0f;
    target = 0;
    if (*(s32 *)(g + 0x1310) != 0) {
        if (g[0x1A14] != 0) {
            if (*(s32 *)(v + 0x38) == 0) {
                *(s32 *)(v + 0x20) = 0;
                *(s32 *)(v + 0x34) = 5;
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
                sprite_00549510(g, self, func_L39_005FD580(150.0f, (f32 *)(g + 0x1338), (s32 *)(g + 0x133C), 1), 0, 0x27, 0.7f);
                target = *(u8 **)(g + 0x122C);
            } else {
                sprite_00549510(g, self, func_L39_005FD580(150.0f, (f32 *)(g + 0x1338), (s32 *)(g + 0x133C), 0), 0, 0x27, 0.7f);
                target = 0;
            }
        }
    } else if (g[0x1A14] != 0) {
        *(s32 *)(v + 0x38) = 0;
        if (g[0x1A08] != 0) {
            func_003886E8(&a, self + 0xD0, -1.0f);
        } else {
            a = *(vu0_v4 *)(g + 0x3B0);
        }
        func_003886E8(&b, *(u8 **)(g + 0x2524) + 0xE0, 0.75f);
        vec_add_ab(&b, g + 0xA0, &b);
        dir = &a;
        target = aim_00549510(g, &b, dir, 0.31415927f, 0.29670596f, 75.0f, 0.31415927f, 0.31415927f);
        *(f32 *)(v + 0x44) = 0.5f;
    }
    if (g[0x1A08] != 0) {
        func_003886E8(&a, self + 0xD0, -1.0f);
        target = 0;
    }
    if (*(u8 **)(v + 0x20) != 0) {
        info = func_0037E0B8(*(u8 **)(v + 0x20));
        c = *(u8 **)(v + 0x20);
        if (c == 0 || c[0x20] == 0xFE || c[0x20] == 0xFD || (info != 0 && *(f32 *)info <= 0.0f) ||
            c[0x31] == 0 || (g[0x1A08] != 0 && func_L39_00637548(g) == 0)) {
            *(u8 **)(v + 0x20) = 0;
            *(s32 *)(v + 0x34) = 5;
        } else if (target != *(u8 **)(v + 0x20)) {
            if (func_00388398(v + 0x24) != 0) {
                *(u8 **)(v + 0x20) = 0;
                *(s32 *)(v + 0x34) = 5;
            }
        } else {
            *(s32 *)(v + 0x24) = 5;
            d = func_003887C8(*(void **)(g + 0x2530), target + 0x10) / 150.0f;
            radius_00549510(v, target);
            func_003886E8(&w, target + 0xE0, *(f32 *)(v + 0x28));
            vec_add_ab(&w, target + 0x10, &w);
            sprite_00549510(g, self, func_003894A0(0xFF0FFFFF, 0xFF0F0FFF, *(f32 *)(v + 0x44)), &w, 0x26, fabs_asm(0.9f - d * 0.65f));
            *(u8 **)(g + 0x1078) = target;
        }
    } else if (g[0x1A14] != 0 && target == *(u8 **)(v + 0x30)) {
        if (func_00388398(v + 0x34) != 0) {
            *(u8 **)(v + 0x20) = target;
            *(s32 *)(v + 0x24) = 5;
            radius_00549510(v, target);
        }
    } else {
        *(s32 *)(v + 0x34) = 5;
    }
    *(u8 **)(v + 0x30) = target;
    cur = *(u8 **)(v + 0x20);
    st = func_L39_00670988(g + 0x1A40, 0, 1, (s32)&ent);
    if (st == 8) {
        if (self[0x43] == 0) {
            func_003BE4F0(self, 1, 0, 4);
        }
        *(s32 *)(v + 0x48) = 1;
        if (cur == 0) {
            func_003886E8(&pos, self + 0xD0, -1.0f);
            vec_add_ab(&pos, &pos, self + 0x10);
            func_003886E8(&off, self + 0xC0, 0.275f);
            vec_add_ab(&pos, &pos, &off);
            n = func_003CF790(&pos, 1, *(void **)(g + 0x2524), 0, 1.0f);
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    u8 *m = D_L39_002638C0[i];
                    u8 *mi = func_0037E0B8(m);
                    u8 *t;
                    if (m[0x31] != 0 && *(s16 *)(m + 0x32) > 0 && m != 0 && m[0x20] != 0xFE && m[0x20] != 0xFD &&
                        *(s16 *)(m + 0xAA) != 0xC87 && *(s16 *)(m + 0xAA) != 0xECC && mi != 0 &&
                        (*(f32 *)mi > 0.0f || func_L39_005B6970(m) != 0)) {
                        t = *(u8 **)(m + 0x24);
                        if (t == 0 || t[0x46] != 5) {
                            cur = D_L39_0025F840.f18;
                            *(u8 **)(v + 0x20) = cur;
                            break;
                        }
                    }
                }
            }
        }
        func_L39_005F0CE0(0, 0, self);
        *(s16 *)(v + 0x2E) = 0xF;
        func_L39_005487B8(self);
        func_L39_00549708(self, &ent);
        func_L39_0061F5C0(g, -1);
        func_003BE4F0(self, 2, 0, 0);
        *(s32 *)(v + 0x3C) = func_L01_003F0118(D_L39_00470600_00548BE0, *(void **)(g + 0x2534));
        if (func_L39_00646268(g, 4) != 0) {
            cfg = cfgAt_00549510(D_L39_0049C950[4].b21);
        } else {
            cfg = cfgAt_00549510(4);
        }
        *(f32 *)(v + 0x10) = 1.0f / cfg->f28;
    } else if (st == 4) {
        if (*(s32 *)(v + 0x48) == 1) {
            func_L39_005F0CE0(1, 0, self);
            *(s32 *)(v + 0x48) = 0;
        }
    }
    if ((st != 8 || g[0x1A07] == 0) && *(s32 *)(v + 0x3C) >= 0) {
        func_L01_003F0338(*(s32 *)(v + 0x3C), *(void **)(g + 0x2534));
        *(s32 *)(v + 0x3C) = -1;
    }
    if (self[0x42] != 2 && *(s16 *)(v + 0x2E) > 0) {
        n = *(s16 *)(v + 0x2E);
        if (n > 12) {
            f32 t = (f32)(15 - n);
            cr = t * 0.33333334f;
            cg = t * 0.8f * 0.33333334f;
            cb = t * 0.5f * 0.33333334f;
        } else {
            f32 t = (f32)n;
            cr = t * 0.083333336f;
            cg = t * 0.8f * 0.083333336f;
            cb = t * 0.5f * 0.083333336f;
        }
        if (g[0x1A08] != 0) {
            func_003886E8(&off, self + 0xD0, -1.0f);
            func_003BDA38(self, 0, &pos);
        } else {
            off = *(vu0_v4 *)(g + 0x3B0);
            func_003BDA38(self, 0, &pos);
        }
        vec_add_ba(&pos, &pos, &off);
        func_003886E8(&off2, *(u8 **)(g + 0x2524) + 0xE0, 0.3f);
        vec_add_ab(&pos, &pos, &off2);
        if (*(s16 *)(v + 0x2C) == -1) {
            *(s16 *)(v + 0x2C) = func_L39_0059CF60(&pos, 8.0f, 0.0f, cr, cg, cb);
        } else {
            light_00549510(*(s16 *)(v + 0x2C), &pos, 8.0f, cr, cg, cb);
        }
        func_003883C8(v + 0x2E);
    } else if (*(s16 *)(v + 0x2C) != -1) {
        func_L01_00421FE0(*(s16 *)(v + 0x2C));
        *(s16 *)(v + 0x2C) = -1;
        *(s16 *)(v + 0x2E) = 0;
    }
    if (self[0x43] == 2) {
        if (*(s16 *)(v + 0x2C) != -1) {
            func_L01_00421FE0(*(s16 *)(v + 0x2C));
        }
        *(s16 *)(v + 0x2C) = -1;
        *(s16 *)(v + 0x2E) = 0;
    }
    }
}
/* localdecomp:end func_L39_00548BE0 */
