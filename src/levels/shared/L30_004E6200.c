#include "common.h"

typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;

extern S_004E6988 D_001A4BE0;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L30_004CF4B0(s32, s32);

typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E6D08;
typedef struct {
    u8 pad0[0xC08];
    s32 w_C08;
    u8 pad1[0x1AC0 - 0xC0C];
    s32 w_1AC0;
    u8 pad2[0x25C0 - 0x1AC4];
    P_004E6D08 *p_25C0;
    s32 w_25C4;
    u8 pad3[0x25CC - 0x25C8];
    s32 w_25CC;
    u8 pad4[0x25E9 - 0x25D0];
    u8 b_25E9;
    u8 pad5[0x25EB - 0x25EA];
    u8 b_25EB;
} S_004E6D08;

typedef struct Hero_4E5BF0 {
    u8 pad0[0x208];
    s16 h208;
    u8 pad20A[0x1B08 - 0x20A];
    s32 w1B08;
} Hero_4E5BF0;
typedef struct Slot_4E5BF0 {
    u8 pad0[0x58];
    f32 rate;
    u8 pad5C[4];
    s32 busy;
    u8 pad64[0xC];
} Slot_4E5BF0;

/* declared by functions of L30_004E5370.c, which this file was cut from */
extern f32 func_0038D160(f32, f32);

/* localdecomp:start func_L30_004E6200 */
#include "vu0.h"

typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[0x24 - 0x20];
    f32 f24;
    s32 w28;
    u8 pad2C[0x34 - 0x2C];
    s32 w34;
    void *p38;
} Ledge_004E6200;

typedef struct {
    vu0_v4 v0;
    u8 pad10[0x20 - 0x10];
    vu0_v4 v20;
    u8 pad30[0x118 - 0x30];
    f32 f118;
    u8 pad11C[0x1B8 - 0x11C];
    s32 w1B8;
    u8 pad1BC[0x1D0 - 0x1BC];
    s16 h1D0;
    u8 pad1D2[0x284 - 0x1D2];
    f32 f284;
    u8 pad288[0x2E0 - 0x288];
    vu0_v4 v2E0;
    u8 pad2F0[0x33C - 0x2F0];
    f32 f33C;
    u8 pad340[0x46E - 0x340];
    u8 b46E;
    u8 pad46F[0x500 - 0x46F];
    Ledge_004E6200 ledge;
    u8 pad540[0x25C0 - 0x540];
    void *p25C0;
    s32 w25C4;
    u8 pad25C8[0x25CC - 0x25C8];
    s32 w25CC;
} Hero_004E6200;

typedef struct {
    u8 pad0[0x18];
    void *p18;
    u8 pad1C[0x20 - 0x1C];
    vu0_v4 v20;
    u8 pad30[0x40 - 0x30];
    vu0_v4 v40;
} C_004E6200;

extern C_004E6200 D_L30_001E9000_004E6200;
__asm__(".extern D_L30_001E9000_004E6200, 80");

extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern f32 func_L01_00511848(void *);
extern f32 func_L01_005114B0(void *);
extern void func_L01_00511508(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern u8 *func_00382348(void *);
extern u8 *func_003C4D58(u8 *);


s32 func_L30_004E6200(s8 *pos_, s8 *rot, s8 *out_) {
    vu0_v4 *pos = (vu0_v4 *)pos_;
    Ledge_004E6200 *out = (Ledge_004E6200 *)out_;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 tmp;
    vu0_v4 dir;
    vu0_v4 e;
    vu0_v4 g;
    vu0_v4 h;
    vu0_v4 k;
    vu0_v4 n;
    vu0_v4 m;
    vu0_v4 o;
    vu0_v4 w;
    vu0_v4 u;
    vu0_v4 t;
    vu0_v4 s;
    vu0_v4 r;
    vu0_v4 q;
    vu0_v4 x;
    s32 ok;
    s32 i;
    s32 j;
    s32 hit;
    s32 found;
    s32 t2;
    void *obj;
    f32 back;
    f32 down;
    f32 len;
    f32 dot;
    f32 step;
    f32 limit;
    f32 f;

    if (out != 0 && ((Hero_004E6200 *)&D_001A4BE0)->w25C4 != 0xA8) {
        out->w28 = 0;
    }
    if (((Hero_004E6200 *)&D_001A4BE0)->h1D0 != 0) {
        return 0;
    }
    ok = 0;
    if ((((Hero_004E6200 *)&D_001A4BE0)->w25CC == 4 && ((Hero_004E6200 *)&D_001A4BE0)->w1B8 >= 9 && (((Hero_004E6200 *)&D_001A4BE0)->b46E != 0 || ((Hero_004E6200 *)&D_001A4BE0)->f118 < 0.10000001f))
        || ((Hero_004E6200 *)&D_001A4BE0)->w25CC == 2) {
        ok = 1;
    }
    if (out != &((Hero_004E6200 *)&D_001A4BE0)->ledge) {
        ok = 1;
    }
    if (ok) {

        a = *pos;
        func_0038CF68(&tmp, &((Hero_004E6200 *)&D_001A4BE0)->v0, ((Hero_004E6200 *)&D_001A4BE0)->f284);
        down = -0.7f;
        vec_add_ba(&a, &a, &tmp);
        func_0038CF68(&tmp, &((Hero_004E6200 *)&D_001A4BE0)->v20, 2.8500001f);
        back = -2.5f;
        vec_add_ba(&b, &a, &tmp);
        func_0038CF68(&tmp, &((Hero_004E6200 *)&D_001A4BE0)->v20, 2.15f);
        vec_add_ab(&c, &a, &tmp);
        func_0038CF68(&d, &((Hero_004E6200 *)&D_001A4BE0)->v0, 0.125f);
        i = 0;
        hit = 0;
        for (; i < 4; i++) {
            vec_add_ab(&b, &b, &d);
            vec_add_ab(&c, &c, &d);
            if (func_003D3CB0(&b, &c, 4, ((Hero_004E6200 *)&D_001A4BE0)->p25C0, 0)) {
                t2 = func_003D5630();
                if (t2 != 9 && t2 != 12 && t2 != 0 && func_L01_00511848(&D_L30_001E9000_004E6200.v40) < 0.34906584f) {
                    hit = 1;
                }
            }
            if (hit) {
                break;
            }
        }
        obj = 0;
        if (hit) {

            if (D_L30_001E9000_004E6200.p18 != 0) {
                u8 *m1;
                u8 *m2;
                hit = 0;
                m1 = func_00382348(D_L30_001E9000_004E6200.p18);
                m2 = func_003C4D58(D_L30_001E9000_004E6200.p18);
                if (m1 != 0 && (*(u16 *)(m1 + 0x1E) & 1)) {
                    hit = 1;
                } else if (m2 != 0) {
                    hit = *(s32 *)(m2 + 0x3C) & 1;
                }
                if (!hit) {
                    return 0;
                }
                obj = D_L30_001E9000_004E6200.p18;
            }
            if (out != 0) {
                out->p38 = D_L30_001E9000_004E6200.p18;
            }
            *(vu0_q *)&e = *(vu0_q *)&D_L30_001E9000_004E6200.v20;
            vec_sub_ba(&dir, &e, pos);
            if (func_L01_005114B0(&dir) > 2.7f) {
                return 0;
            }
            func_0038CF68(&g, &((Hero_004E6200 *)&D_001A4BE0)->v20, 0.005f);
            vec_add_ab(&g, &g, &e);
            func_0038CF68(&h, &((Hero_004E6200 *)&D_001A4BE0)->v0, -1.0f);
            vec_add_ab(&h, &h, &g);
            if (func_003D3CB0(&h, &g, 2, ((Hero_004E6200 *)&D_001A4BE0)->p25C0, 0)) {
                if (D_L30_001E9000_004E6200.p18 == 0 || D_L30_001E9000_004E6200.p18 != obj) {
                    return 0;
                }
            }
            if (out != 0) {
                func_0038CF68(&k, &((Hero_004E6200 *)&D_001A4BE0)->v20, 0.6f);
                vec_add_ab(&k, &k, &e);
                if (func_L01_003FB640(&k, 4, ((Hero_004E6200 *)&D_001A4BE0)->f284, ((Hero_004E6200 *)&D_001A4BE0)->p25C0)) {
                    out->w34 |= 1;
                } else {
                    out->w34 &= ~1;
                }
            }
            len = func_L01_005114B0(&dir);
            if (len + ((Hero_004E6200 *)&D_001A4BE0)->f33C < 4.1f) {
                return 0;
            }
            if (len < 0.5f) {
                return 0;
            }
            {
                *(vu0_q *)&m = 0;
                m.x = 1.0f;
                m.z = down;
                func_0038D000(&m, &m, ((Hero_004E6200 *)&D_001A4BE0));
                found = 0;
                vec_add_ab(&m, &m, &e);
                vec_sub_ab(&k, pos, &m);
                func_L01_00511508(&k, &k, 0.0f);
                vec_add_ab(&k, &k, &m);
                func_0038CF68(&n, &((Hero_004E6200 *)&D_001A4BE0)->v20, -down / 5.0f);
                for (j = 0; j < 5; j++) {
                    if (func_003D3CB0(&k, &m, 2, 0, 0)) {
                        func_0038CF68(&o, &D_L30_001E9000_004E6200.v40, 1.0f);
                        found = 1;
                        func_L01_00511508(&o, &o, 0.0f);
                        break;
                    }
                    vec_add_ab(&k, &k, &n);
                    vec_add_ab(&m, &m, &n);
                }
                if (!found) {
                    return 0;
                }
                dot = func_0038CE68(((Hero_004E6200 *)&D_001A4BE0), &o);
                if (!(dot < func_0038D098(1.3962634f))) {
                    return 0;
                }
                q = e;
                step = 0.03f;
                func_0038CF68(&r, &((Hero_004E6200 *)&D_001A4BE0)->v2E0, -0.05f);
                limit = 2.4f;
                func_0038CF68(&s, &o, step);
                f = 0.0f;
                vec_add_ab(&t, &s, &r);
                vec_sub_ab(&s, &s, &r);
                vec_add_ab(&w, &q, &s);
                vec_add_ab(&u, &q, &t);
                do {
                    if (!func_003D3CB0(&u, &w, 2, ((Hero_004E6200 *)&D_001A4BE0)->p25C0, 0)) {
                        if (out != 0) {
                            out->v10 = q;
                            func_0038CF68(&x, &o, 0.9f);
                            func_0038CF68(out, &((Hero_004E6200 *)&D_001A4BE0)->v2E0, -back);
                            vec_add_ab(&out->v0, &x, &out->v0);
                            vec_add_ab(&out->v0, &out->v10, &out->v0);
                            out->f24 = func_0038D160(o.x, o.y);
                            out->w28 = 1;
                        }
                        return 1;
                    }
                    f += step;
                    *(vu0_q *)&q = *(vu0_q *)&D_L30_001E9000_004E6200.v20;
                    vec_add_ab(&u, &q, &t);
                    vec_add_ab(&w, &q, &s);
                } while (f < limit);
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L30_004E6200 */
