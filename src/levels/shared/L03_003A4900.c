#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003A4900 */
typedef struct Vars_3A4900 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    f32 f10;
    s32 w14;
    s32 w18;
    u8 pad1C[3];
    u8 b1F;
} Vars_3A4900;
typedef struct Cam_3A4900 {
    u8 pad0[0x140];
    vu0_v4 pos;
    u8 pad150[0x10];
    vu0_v4 fwd;
} Cam_3A4900;
extern Cam_3A4900 D_L03_001E2300;

extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern u8 *D_L03_001DFA80;
extern void func_L03_003A4FC8(void *);
extern void func_L03_003A51E0(vu0_v4 *, s32);
extern void func_L03_003A5388(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_004561B8(void *);
extern void func_003A4F28(s32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_0046B458(void *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_L01_004048D0_003A4900(void *, void *);

void func_L03_003A4900(u8 *obj) {
    Vars_3A4900 *v;
    vu0_v4 pos;
    vu0_v4 c;
    vu0_v4 dir;
    vu0_v4 t;
    f32 scale;
    f32 dist;
    f32 f;
    f32 r;
    s32 n;
    s32 k;
    s32 i;
    u8 *rec;
    s32 h;

    v = *(Vars_3A4900 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        func_L03_003A4FC8(obj);
    }
    if (obj[0x95] == 0) {
        return;
    }
    scale = 0.0f;
    if (obj[0x20] != 1) {
        vec_sub_ab(&pos, obj + 0x10, &D_L03_001E2300.pos);
        dist = func_L01_0040E548(obj + 0x10, D_001A4C60);
        if (dist < 2304.0f) {
            if (0.0f < D_L03_001E2300.fwd.x * pos.x + D_L03_001E2300.fwd.y * pos.y) {
                scale = 1.0f - (dist - 576.0f) / 1728.0f;
                scale = (scale > 1.0f ? 1.0f : scale) < 0.0f ? 0.0f : (scale > 1.0f ? 1.0f : scale);
            }
        }
    }
    switch (obj[0x20]) {
    case 1:
        if (func_L01_004561B8(obj)) {
            if (v->w14 >= 0) {
                u8 *r = D_001A30B0 + (v->w14 << 7);
                if (*(u8 **)(r + 0xDC) == obj) {
                    func_003A4F28(v->w14);
                }
            }
            v->w14 = -1;
            func_L01_00456230(obj, 1);
        }
        v->f4 = v->f4 - 0.1f < 0.0f ? 0.0f : v->f4 - 0.1f;
        v->w8 = 0;
        if (func_L01_00456250(obj) == 0) {
            v->wC = 0;
        }
        if (v->wC == 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj)) {
            func_L01_00456230(obj, 0);
        }
        if (v->b1F == 0) {
            u8 *r;
            if (v->w14 == -1 || (r = D_001A30B0 + (v->w14 << 7), *(u8 **)(r + 0xDC) != obj)) {
                v->w14 = func_003A52A0(1, 4, obj);
            }
        }
        v->f4 = 1.0f < v->f4 + 0.05f ? 1.0f : v->f4 + 0.05f;
        v->w8 = v->w18;
        if (func_L01_00456250(obj)) {
            v->wC = 1;
        }
        if (v->wC > 0) {
            func_L01_004450F0(obj, 1, -1);
        }
        if (v->b1F == 0) {
            n = scale * 10.0f;
            for (i = 0; i < n; i++) {
                func_L03_003A51E0(&pos, v->w0);
                *(vu0_q *)&c = *(vu0_q *)(D_L03_001DFA80 + v->w0 * 0x80 + 0x30);
                vec_sub_ab(&t, &c, &pos);
                dir = t;
                r = func_003824E0(0.0f, 0.2f);
                func_0038CE20(&dir, &dir, r * func_003824E0(0.0f, 0.1f));
                r = func_003824E0(0.5f, 1.0f);
                k = func_00382498(-10, 10);
                func_L01_0046B458(&pos, 0x28, 0.1f, r, 0x80802020, 0, k, &dir, 0.0f, 0);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(obj)) {
            if (v->w14 >= 0) {
                if (v->w14 != -1) {
                    rec = D_001A30B0 + (v->w14 << 7);
                    if (*(u8 **)(rec + 0xDC) == obj && rec[0xD0] != 0) {
                        func_003A4F28(v->w14);
                    }
                }
                v->w14 = -1;
            }
            if (v->b1F == 0) {
                v->w14 = func_003A52A0(0, 0, obj);
            }
        }
        v->w8++;
        v->f4 = 0.0f;
        if (v->w8 >= v->w18) {
            v->w14 = -1;
            func_L01_004450F0(obj, 2, -1);
        }
        if (v->wC > 0) {
            if (v->w14 >= 0) {
                if (v->w14 != -1) {
                    rec = D_001A30B0 + (v->w14 << 7);
                    if (*(u8 **)(rec + 0xDC) == obj && rec[0xD0] != 0) {
                        func_003A4F28(v->w14);
                    }
                }
                v->w14 = -1;
            }
            func_L01_004450F0(obj, 1, -1);
        }
        if (v->b1F == 0) {
            n = scale * ((f32)(v->w8 * 10) * 0.5f / (v->w18 != 0 ? (f32)v->w18 : 3.0f));
            for (i = 0; i < n; i++) {
                func_L03_003A51E0(&pos, v->w0);
                qzero(&c);
                k = func_00382498(20, 30);
                r = func_003824E0(0.3f, 0.8f);
                func_L01_0046B458(&pos, k, 0.08f, r, 0x60804040, 0, func_00382498(-6, 6), &c, 0.0f, 0);
            }
        }
        break;
    }
    v->f10 = v->f10 + 0.05235988f;
    if (3.1415927f <= v->f10) {
        v->f10 = v->f10 - 6.2831855f;
    }
    if (0.0f < v->f4) {
        if (v->b1F == 0) {
            func_L01_004048D0_003A4900(func_L03_003A5388, obj);
        }
        *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    } else {
        *(s32 *)(obj + 0x98) = 0;
    }
}
/* localdecomp:end func_L03_003A4900 */

/* localdecomp:start func_L03_003A4FC8 */
typedef struct Vars_3A4FC8 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} Vars_3A4FC8;
typedef struct Rec_3A4FC8 {
    u8 pad0[0x10];
    f32 e10[4];
    f32 e20[4];
    vu0_q pos;
    u8 pad40[0x40];
} Rec_3A4FC8;
extern u8 *D_L03_001DFA80;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[];
extern void func_0038CC88(void *, void *, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern void func_003C2880(void *);
extern void func_L01_003F5E88(void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_003A4FC8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3A4FC8 *vars = *(Vars_3A4FC8 **)(obj + 0x68);
    f32 a;
    f32 b;
    u8 *dir;
    Rec_3A4FC8 *tbl;

    vars->f4 = 1.0f;
    vars->w14 = -1;
    vars->w8 = 0;
    vars->w10 = 0;
    if (vars->w18 < 10) {
        vars->w18 = (s32)((f32)vars->w18 * 50.0f);
    } else {
        vars->w18 = (vars->w18 * 5 + 2) / 6;
    }
    dir = obj + 0xC0;
    tbl = (Rec_3A4FC8 *)D_L03_001DFA80;
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x145;
    *(vu0_q *)(obj + 0x10) = tbl[vars->w0].pos;
    func_0038CC88(dir, &((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0], 0x30);
    a = func_0038CEA8(((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0].e10);
    b = func_0038CEA8(((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0].e20);
    if (b < a) {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * a;
        func_0038CE20(obj + 0xD0, obj + 0xD0, b / a);
    } else {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * b;
        func_0038CE20(obj + 0xD0, obj + 0xD0, a / b);
    }
    func_003C7C38(obj);
    if (D_001BBC40[obj[0xB0] + (D_001D545C << 4)] & 0x80) {
        func_003C2880(obj);
        return;
    }
    func_L01_003F5E88(obj);
    if (vars->wC != 0) {
        vars->f4 = 0.0f;
        func_L01_004450F0(obj, 1, 1);
    } else {
        vars->f4 = 1.0f;
        func_L01_004450F0(obj, 2, 1);
    }
}
/* localdecomp:end func_L03_003A4FC8 */

/* localdecomp:start func_L03_003A51E0 */
extern s32 func_00382498(s32, s32);
extern void func_0038D570(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern vu0_v4 D_L03_002BA370[][4];
extern u8 *D_L03_001DFA80;

void func_L03_003A51E0(vu0_v4 *out, s32 idx) {
    vu0_v4 s[2];
    vu0_v4 m[4];
    vu0_v4 e;
    vu0_v4 r;
    vu0_v4 t;
    s32 n;
    s32 k;

    n = func_00382498(0, 5);
    k = func_00382498(0, 3);
    switch (k) {
    case 0:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][1];
        break;
    case 1:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][2];
        break;
    case 2:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][2];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    case 3:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][1];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    }
    func_0038D570(m, D_L03_001DFA80 + idx * 0x80);
    *(vu0_q *)&m[3] = *(vu0_q *)(D_L03_001DFA80 + idx * 0x80 + 0x30);
    m[3].w = 1.0f;
    vec_sub_ba(&r, &s[1], &s[0]);
    e = r;
    func_0038CE20(&e, &e, func_003824E0(0.0f, 1.0f));
    vec_add_ab(&t, &s[0], &e);
    r = t;
    *out = r;
    func_0038D028(out, out, m);
}
/* localdecomp:end func_L03_003A51E0 */

INCLUDE_ASM("asm/levels", func_L03_003A5388);
