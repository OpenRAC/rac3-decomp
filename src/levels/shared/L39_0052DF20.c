#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0052DF20);

/* localdecomp:start func_L39_0052E550 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} S_0052E550;

extern S_0052E550 D_L39_0025F740;
__asm__(".extern D_L39_0024AB90, 16");
extern vu0_v4 D_L39_0024AB90 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024ABA0, 16");
extern vu0_v4 D_L39_0024ABA0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024ABB0, 16");
extern vu0_v4 D_L39_0024ABB0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_00242930, 16");
extern vu0_v4 D_L39_00242930 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AB80, 8");
extern vu0_v4 D_L39_0024AB80[] __attribute__((section(".sdata")));

extern void func_0038D000(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_00446E38(void *, void *, f32, s32, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern u8 *func_L39_0061D7B0(void *);
extern s32 func_L39_005B8928(void *);
extern u8 *func_00382348(void *);

s32 func_L39_0052E550(u8 *a0, vu0_v4 *p1, vu0_v4 *p2, vu0_v4 *p3, s32 *out, s32 idx, vu0_v4 *outv, f32 maxlen, f32 unused, f32 rad) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 cc;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 v50;
    vu0_v4 v60;
    u8 *g;
    u8 *c;
    u8 *r;
    u8 *q;
    s32 result;
    s32 retry;
    s32 flag;
    f32 t;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 k;
    f32 len;
    s32 kind;

    g = *(u8 **)(a0 + 0x68);
    c = *(u8 **)(g + 0x6D0);
    func_0038D000(&d, &D_L39_0024AB80[idx], a0 + 0xC0);
    vec_add_ba(&b, &d, a0 + 0x10);
    *outv = b;
    vec_add_ab(&d, &b, p2);
    *out = 0;
    a = *p2;
    result = 0;
    retry = 0;
    kind = 0;
    flag = 0;
    vec_add_ab(&cc, &b, &a);
    t = func_L01_00446E38(&b, &cc, 1.0f, 0x84, a0);
    if (t <= 0.0f) {
        if (func_L01_003FB640(&b, 4, a0, 1.0f) != 0) {
            vec_sub_ab(&d, &D_L39_0025F740.v30, &b);
            vec_add_ab(p1, p1, &d);
        }
    } else if (t < 1.0f) {
retry_hit:
        {
            result = 1;
            *(vu0_q *)p3 = *(vu0_q *)&D_L39_0025F740.v20;
            g[0x714] = 1;
            if (D_L39_0025F740.f18 != 0) {
                r = func_L39_0061D7B0(D_L39_0025F740.f18);
                if (r != 0 && (r[3] & 0xF) == 2) {
                    if (*(s16 *)(D_L39_0025F740.f18 + 0xAA) == 0x109F || *(s16 *)(D_L39_0025F740.f18 + 0xAA) == 0x109D) {
                        q = func_00382348(D_L39_0025F740.f18);
                        if (q != 0) {
                            func_L01_00446A70(D_L39_0025F740.f18, 0, 0x10000, a0 + 0x10, c + 0x270, *(s16 *)(q + 4));
                            flag = 1;
                        }
                    }
                } else if (func_L39_005B8928(D_L39_0025F740.f18) != 0) {
                    func_L01_00446A70(D_L39_0025F740.f18, a0, 0x10000, &D_L39_0025F740.v20, &D_L39_00242930, 5.0f);
                    flag = 1;
                }
                D_L39_0025F740.v40.z = 0.0f;
            }
            if (0.0f < D_L39_0025F740.v40.z) {
                D_L39_0025F740.v40.z = 0.0f;
            }
            func_0038CF68(&e, &D_L39_0025F740.v40, 1.0f);
            dx = func_0038CE68(&e, a0 + 0xC0);
            dy = func_0038CE68(&e, a0 + 0xD0);
            dz = func_0038CE68(&e, a0 + 0xE0);
            if (idx == 0) {
                if (dx < 0.0f && 0.0f < dy && *(f32 *)(a0 + 0xE8) < 0.707f) {
                    func_0038CE20(&e, a0 + 0xC0, -1.0f);
                } else if (0.0f < dx && dy < 0.0f) {
                    func_0038CE20(&e, a0 + 0xD0, -1.0f);
                } else if (0.5f < dz && 0.0f < dy) {
                    e = *(vu0_v4 *)(a0 + 0xE0);
                }
            } else if (idx == 2) {
                if (0.0f < dx && 0.0f < dy) {
                    func_0038CE20(&e, a0 + 0xC0, 1.0f);
                } else if (dx < 0.0f && dy < 0.0f) {
                    func_0038CE20(&e, a0 + 0xD0, -1.0f);
                } else if (0.5f < dz && 0.0f < dy) {
                    e = *(vu0_v4 *)(a0 + 0xE0);
                }
            } else if (idx == 1) {
                if (dx < 0.0f && dy < 0.0f && *(f32 *)(a0 + 0xE8) < 0.707f) {
                    func_0038CE20(&e, a0 + 0xC0, -1.0f);
                } else if (0.0f < dx && 0.0f < dy) {
                    func_0038CE20(&e, a0 + 0xD0, 1.0f);
                } else if (0.5f < dz && dy < 0.0f) {
                    e = *(vu0_v4 *)(a0 + 0xE0);
                }
            } else if (idx == 3) {
                if (0.0f < dx && dy < 0.0f) {
                    func_0038CE20(&e, a0 + 0xC0, 1.0f);
                } else if (dx < 0.0f && 0.0f < dy) {
                    func_0038CE20(&e, a0 + 0xD0, 1.0f);
                } else if (0.5f < dz && dy < 0.0f) {
                    e = *(vu0_v4 *)(a0 + 0xE0);
                }
            }
            k = func_0038CE68(&a, &e) * -1.01f;
            func_0038CE20(&cc, &a, t);
            vec_add_ba(&b, &b, &cc);
            func_0038CE20(&d, &e, k * (1.0f - t));
            vec_add_ba(p1, p1, &d);
            func_0038CE20(&d, &e, k);
            if (flag == 0) {
                vec_add_ab(p2, p2, &d);
            }
            if (kind == 12) {
                if (0.0f < p2->z) {
                    p2->z = 0.0f;
                }
            }
            len = func_0038CEA8(p2);
            if (maxlen < len) {
                func_0038CE20(p2, p2, maxlen / len);
                len = maxlen;
            } else if (len < maxlen) {
                maxlen = len;
            }
            if (0.0f < *(f32 *)(c + 0x310)) {
                *(f32 *)(c + 0x310) = len;
            } else if (len < maxlen) {
                *(f32 *)(c + 0x310) = -len;
            }
            func_0038D028(&d, &e, c + 0x1B0);
            func_0038CE20(&d, &d, len * 0.01f);
            vec_add_ba(g + 0x660 + idx * 16, g + 0x660 + idx * 16, &d);
            if (retry == 0) {
                func_0038CE20(&a, p2, 1.0f - t);
                vec_add_ab(&cc, &b, &a);
                t = func_L01_00446E38(&b, &cc, rad, 0x84, a0);
                if (t < 1.0f && 0.0f <= t) {
                    retry = 1;
                    goto retry_hit;
                }
            }
        }
    }
    v60 = b;
    switch (idx) {
    case 0:
        func_0038D000(&d, &D_L39_0024ABB0, a0 + 0xC0);
        break;
    case 1:
        func_0038D000(&d, &D_L39_0024ABA0, a0 + 0xC0);
        break;
    case 2:
        func_0038D000(&d, &D_L39_0024AB90, a0 + 0xC0);
        break;
    case 3:
        func_0038D000(&d, D_L39_0024AB80, a0 + 0xC0);
        break;
    }
    vec_add_ab(&v50, &d, a0 + 0x10);
    t = func_L01_00446E38(&v50, &v60, 1.0f, 0x84, a0);
    if (0.0f < t) {
        vec_sub_ba(&d, &v50, &v60);
        func_0038CE20(&d, &d, 1.0f - t);
        vec_add_ba(p1, p1, &d);
    }
    return result;
}
/* localdecomp:end func_L39_0052E550 */

INCLUDE_ASM("asm/levels", func_L39_0052EE60);

/* localdecomp:start func_L39_00530490 */
#include "vu0.h"

typedef int Q_00530490 __attribute__((mode(TI)));

extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_00448690(void *, s32, f32, f32);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern void func_L39_0052EE60(u8 *);

void func_L39_00530490(u8 *a0) {
    vu0_v4 v;
    u8 *g;
    u8 *s;
    u8 *c;
    u8 *t;
    f32 len;
    f32 sc;
    f32 k;
    f32 ang;

    g = *(u8 **)(a0 + 0x68);
    s = *(u8 **)(g + 0x720);
    c = *(u8 **)(g + 0x6D0);
    if (s == 0) {
        return;
    }
    if (a0[0xBC] == 0xB && (*(u16 *)(g + 0x710) & 8)) {
        return;
    }
    if (!(*(s32 *)(c + 0x2F8) & 2)) {
        t = *(u8 **)(c + 0x2D8);
        if (t != 0 && t[0x1A14] == 0 && (*(s32 *)(*(u8 **)(t + 0x2558) + 0x1AC) & 4)) {
            vec_sub_ab(&v, t + 0x4D30, a0 + 0x10);
            len = func_0038CEA8(&v);
            sc = 0.0f;
            if (len < 1.5f) {
                sc = 1.0f;
            } else if (len < 3.0f) {
                sc = 1.75f;
            } else if (len < 5.0f) {
                sc = 2.5f;
            }
            if (0.0f < sc) {
                func_0038CE20(&v, &v, sc / 10.0f);
            }
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
            ang = func_0038DBA0(*(f32 *)(a0 + 0xF8), *(f32 *)(c + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            func_L01_00448690(a0 + 0xF8, 0, *(f32 *)(t + 0x4D68), k * 0.017453292f * 0.020000001f);
        } else {
            vec_sub_ba(&v, c + 0x1F0, a0 + 0x10);
            func_0038CE20(&v, &v, 0.1f);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
            ang = func_0038DBA0(*(f32 *)(a0 + 0xF8), *(f32 *)(c + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            func_L01_00448690(a0 + 0xF8, 0, *(f32 *)(c + 0x208), k * 0.017453292f * 0.020000001f);
        }
    }
    if (*(s32 *)(c + 0x2F8) & 2) {
        *(Q_00530490 *)(a0 + 0x10) = *(Q_00530490 *)(c + 0xB0);
        func_L01_00448728(a0 + 0xF0, *(f32 *)(c + 0x200), g + 0x650, *(f32 *)(s + 0x1C) * 1.44f, *(f32 *)(s + 0x20) * 1.44f, *(f32 *)(s + 0x4) * 0.020000001f, 0);
        func_L01_00448728(a0 + 0xF4, *(f32 *)(c + 0x204), g + 0x654, *(f32 *)(s + 0x1C) * 1.44f, *(f32 *)(s + 0x20) * 1.44f, *(f32 *)(s + 0x4) * 0.020000001f, 0);
        func_L01_00448728(a0 + 0xF8, *(f32 *)(c + 0x208), g + 0x658, *(f32 *)(s + 0x1C) * 1.44f, *(f32 *)(s + 0x20) * 1.44f, *(f32 *)(s + 0x4) * 0.020000001f, 0);
    } else {
        func_L39_0052EE60(a0);
    }
}
/* localdecomp:end func_L39_00530490 */
