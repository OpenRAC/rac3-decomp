#include "common.h"

typedef struct S_006A5FE0 {
    u8 pad0[0x2B1];
    u8 f2B1;
    u8 pad1[6];
    s32 f2B8;
    s32 f2BC[576];
    s32 fBBC[1];
} S_006A5FE0;

typedef struct S_006A6108 {
    u8 pad0[0xCBC];
    u8 f_CBC;
    u8 pad1[7];
    s32 f_CC4;
    s32 f_CC8[1];
    u8 pad2[0x8FC];
    s32 f_15C8[1];
} S_006A6108;

typedef struct S_L39_006A6078 {
    u8 pad0[0x16CC];
    s32 f16CC;
    s32 f16D0[11];
    s32 f16FC[1];
} S_L39_006A6078;

/* declared by functions of L39_006A5F30.c, which this file was cut from */
extern s32 func_00381FF0(s32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_006A6290(void *, s32, s32);

/* localdecomp:start func_L39_006A61A0 */
typedef struct S_006A61A0 {
    u8 pad0[0x48];
    s32 f48;
} S_006A61A0;

extern S_006A61A0 *D_001E2050_sda;
extern u8 D_L39_00248838[];
extern s32 D_L39_00247914_61A0;
extern s32 func_L39_00687450(s32, u8 *, u8 *, s32, s32, s32, s32);
extern S_006A61A0 *func_L39_006D9A40(s32, u8 *);
extern s32 func_00120048(u8 *, s32, ...);
extern void func_L39_006872E8(s32, u8 *, u8 *, s32, s32, f32);

void func_L39_006A61A0(void *arg0) {
    u8 name[0x30];
    u8 buf[0x50];
    S_006A61A0 *r;

    name[0] = 0;
    func_L39_00688340(4, 0, 0);
    func_L39_00687450(D_L39_00247914_61A0, D_L39_00248838, name, 0, 0x21, 0, 0);
    if (name[0] != 0) {
        r = func_L39_006D9A40(D_001E2050_sda->f48, name);
        if (r != 0 && r->f48 >= 0) {
            ((void (*)(void *, s32, u8 *))func_L39_006A6290)(arg0, r->f48, name);
        } else {
            func_00120048(buf, func_00381FF0(0x1175), name);
            func_L39_006872E8(D_L39_00247914_61A0, buf, D_L39_00248838, 4, 0, 0.6f);
        }
    }
}
/* localdecomp:end func_L39_006A61A0 */

/* localdecomp:start func_L39_006A6290 */
/* best: 38 diff with the file's flags; 10 diff with --mode S --as ps2as (scheduling only:
 * li 0x56 in $v1 vs $v0, and the order of the last call's argument loads). Under the file's mode,
 * retail's 0.6f is lui/ori/mtc1 but mine is a $gp literal; s4/s5 get swapped too. ee29: 44 diff.
 * The flag test written as one && chain fixed the bnel/sltu shape. */
typedef struct Q_006A6290 {
    u8 pad0[0x40];
    s32 f40;
} Q_006A6290;

typedef struct G_006A6290 {
    u8 pad0[0x30];
    u8 *f30;
    u8 pad1[0x14];
    void *f48;
} G_006A6290;

__asm__(".extern D_L39_0024D760, 16");
extern G_006A6290 *D_L39_0024D760;
extern u8 D_L39_00248838[];
extern u8 D_L39_00248840[];
extern u8 D_L39_00248848[];
extern u8 D_L39_00248858[];
extern u8 D_001A5DCE[];
extern s32 D_L39_00247914_6290;
extern s32 func_0019B5C8(void);
extern void *func_0011D534(void *, s32, s32);
extern Q_006A6290 *func_L39_006D98C8(void *, s32);
extern Q_006A6290 *func_L39_006D9328(void *, s32);
extern s32 func_L39_006A6938(s32, s32);
extern void func_L39_006D9E68(void *, s32, u8 *, s32);
extern void func_L39_006872E8(s32, u8 *, u8 *, s32, s32, f32);

void func_L39_006A6290(void *arg0, s32 arg1, s32 arg2) {
    u8 buf[0x40];
    u8 msg[0x50];
    void *o;
    Q_006A6290 *q;
    Q_006A6290 *t;
    s32 r;
    s32 state;
    s32 flag;

    state = 0;
    r = func_0019B5C8();
    func_0011D534(buf, 0x20, 0x40);
    buf[0] = 0x56;
    func_00120048(buf + 1, (s32)D_L39_00248840, r);
    func_00120048(buf + 9, (s32)D_L39_00248848, (s32)D_001A5DCE);
    func_00120048(buf + 0x19, (s32)D_L39_00248858, (s32)(D_L39_0024D760->f30 + 4));
    o = D_L39_0024D760->f48;
    q = func_L39_006D98C8(o, arg1);
    t = func_L39_006D9328(o, arg1);
    if (q) {
        if (q->f40 == 0) {
            state = 3;
        } else if (q->f40 == 1) {
            state = 2;
        } else {
            state = 0;
        }
    } else if (t) {
        state = t->f40;
    }
    flag = 0;
    if (!func_L39_006A6938((s32)arg0, arg1) && state != 3 && state != 0) {
        flag = 1;
    }
    if (flag) {
        func_L39_006D9E68((void *)D_001E2050_sda->f48, arg1, buf, 0);
        func_00120048(msg, func_00381FF0(0x164A), arg2);
    } else {
        s32 s = func_00381FF0(0x1854);

        if (state == 0) {
            func_00120048(msg, func_00381FF0(0x1855));
        } else {
            func_00120048(msg, s, arg2);
        }
    }
    func_L39_006872E8(D_L39_00247914_6290, msg, D_L39_00248838, 4, 0, 0.6f);
}
/* localdecomp:end func_L39_006A6290 */

INCLUDE_ASM("asm/levels", func_L39_006A6470);

INCLUDE_ASM("asm/levels", func_L39_006A65B8);

INCLUDE_ASM("asm/levels", func_L39_006A6778);

/* localdecomp:start func_L39_006A6938 */
typedef struct { u8 pad0[0xE0]; s16 f_E0[8]; u8 pad1[0x150 - 0xF0]; s32 f_150[8]; } S_006A6938;
typedef struct { u8 pad0[0x34]; s32 f34; } G_006A6938;
extern S_006A6938 *D_L39_00241640_006A6938;
extern G_006A6938 D_001A5CD0;

s32 func_L39_006A6938(s32 a0, s32 a1)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640_006A6938->f_E0[i] >= 0 && (D_L39_00241640_006A6938->f_150[i] == a1 || D_001A5CD0.f34 == a1)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006A6938 */

LINKER_REMNANT("asm/levels", func_L39_006A69A0);

/* localdecomp:start func_L39_006A69C0 */
typedef struct B_006A69C0 {
    s32 type;
    u8 text[0x34];
    f32 c[4];
} B_006A69C0;

typedef struct E7_006A69C0 {
    B_006A69C0 b;
    u8 label[0x50];
} E7_006A69C0;

typedef struct E1_006A69C0 {
    B_006A69C0 b;
    u8 pad[8];
} E1_006A69C0;

typedef struct E4_006A69C0 {
    B_006A69C0 b;
    u8 f48;
    s32 f4C;
} E4_006A69C0;

typedef struct E12_006A69C0 {
    B_006A69C0 b;
    s32 f48;
    f32 f4C;
    s32 f50;
    f32 f54;
    s32 f58;
    s32 f5C;
} E12_006A69C0;

typedef struct R_006A69C0 {
    B_006A69C0 b;
    s32 f48;
    s32 n;
    void *items[0x60];
} R_006A69C0;

extern u8 D_L39_002488C0[];
extern f32 D_L39_004B0490[4];
extern f32 D_L39_004B04D8[4];
extern f32 D_L39_004B04F0[4];
extern f32 D_L39_004B0520[4];
extern f32 D_L39_004B0568[4];
extern f32 D_L39_004B05C8[12];
extern const f32 D_L39_004B0638[13];
extern u8 D_L39_0047DA80[];
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_00120D28(s32, s32, s32);
extern void func_L39_00689670(void *, void *);

static __inline__ void set_006A69C0(E7_006A69C0 *e, u8 *s, f32 x, f32 y, f32 z, f32 w) {
    if (s != 0) {
        func_00120D28((s32)e->label, (s32)s, 0x4F);
        e->label[0x4F] = 0;
    } else {
        e->label[0] = 0;
    }
    if (s != 0) {
        func_00120D28((s32)e->b.text, (s32)s, 0x33);
        e->b.text[0x33] = 0;
    } else {
        e->b.text[0] = 0;
    }
    e->b.c[0] = x;
    e->b.c[1] = y;
    e->b.c[2] = z;
    e->b.c[3] = w;
}

static __inline__ void lab_006A69C0(B_006A69C0 *t, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, (s32)text, x, y, w, h);
}

static __inline__ void L7_init_006A69C0(E7_006A69C0 *t, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006A69C0(&t->b, text, x, y, w, h);
    t->b.type = 7;
    if (text != 0) {
        func_00120D28((s32)t->label, (s32)text, 0x4F);
        t->label[0x4F] = 0;
    } else {
        t->label[0] = 0;
    }
}

static __inline__ void L1_init_006A69C0(E1_006A69C0 *t, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006A69C0(&t->b, text, x, y, w, h);
    t->b.type = 1;
}

static __inline__ void L4_init_006A69C0(E4_006A69C0 *t, u8 *text, f32 x, f32 y, f32 w, f32 h, s32 sel) {
    lab_006A69C0(&t->b, text, x, y, w, h);
    t->b.type = 4;
    t->f4C = sel;
    t->f48 = 0;
}

static __inline__ void R_init_006A69C0(R_006A69C0 *t) {
    lab_006A69C0(&t->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->f48 = 0x2E;
    t->n = 0;
    t->b.c[0] = 0;
    t->b.c[1] = 0;
    t->b.c[2] = 1.0f;
    t->b.c[3] = 1.0f;
}

static __inline__ void H_init_006A69C0(E12_006A69C0 *t, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006A69C0(&t->b, text, x, y, w, h);
    t->b.type = 12;
    t->f58 = -1;
    t->f50 = 0;
    t->f48 = 0;
    t->f54 = 1.0f;
    t->f4C = 1.0f;
    t->f5C = 0x706EC8FF;
}

typedef struct O_006A69C0 {
    u8 pad0[0x60];
    u8 *vtbl;
    u8 pad64[0x2A4 - 0x64];
    u8 *f2A4;
    u8 pad2A8[0x494 - 0x2A8];
    u8 f494[1];
} O_006A69C0;

void *func_L39_006A69C0(O_006A69C0 *const p) {
    R_006A69C0 root;
    E7_006A69C0 a;
    E1_006A69C0 b;
    E7_006A69C0 c;
    E1_006A69C0 d;
    E4_006A69C0 e;
    E7_006A69C0 f[5];
    E7_006A69C0 g[40];
    E12_006A69C0 h[16];
    s32 i;
    s32 row;

    func_L39_00688388(p);
    p->vtbl = D_L39_0047DA80;
    p->f2A4 = p->f494;

    R_init_006A69C0(&root);
    L7_init_006A69C0(&a, D_L39_002488C0, D_L39_004B0490[0], D_L39_004B0490[1], D_L39_004B0490[2], D_L39_004B0490[3]);
    root.items[0] = &a;
    L1_init_006A69C0(&b, D_L39_002488C0, D_L39_004B04D8[0], D_L39_004B04D8[1], D_L39_004B04D8[2], D_L39_004B04D8[3]);
    L7_init_006A69C0(&c, D_L39_002488C0, D_L39_004B04F0[0], D_L39_004B04F0[1], D_L39_004B04F0[2], D_L39_004B04F0[3]);
    root.items[1] = &b;
    root.items[2] = &c;
    L1_init_006A69C0(&d, D_L39_002488C0, D_L39_004B0520[0], D_L39_004B0520[1], D_L39_004B0520[2], D_L39_004B0520[3]);
    root.items[3] = &d;
    L4_init_006A69C0(&e, D_L39_002488C0, D_L39_004B0568[0], D_L39_004B0568[1], D_L39_004B0568[2], D_L39_004B0568[3], -1);
    root.items[4] = &e;

    {
        E7_006A69C0 *q = f;
        s32 n = 4;
        do {
            L7_init_006A69C0(q, D_L39_002488C0, 1.0f, 1.0f, 1.0f, 1.0f);
            q++;
        } while (--n != -1);
    }
    {
        E7_006A69C0 *q = g;
        s32 n = 39;
        do {
            L7_init_006A69C0(q, D_L39_002488C0, 1.0f, 1.0f, 1.0f, 1.0f);
            q++;
        } while (--n != -1);
    }
    {
        E12_006A69C0 *q = h;
        s32 n = 15;
        do {
            H_init_006A69C0(q, 0, 1.0f, 1.0f, 1.0f, 1.0f);
            q++;
        } while (--n != -1);
    }
    for (i = 0; i < 16; i++) {
        h[i].f58 = 0xED3D;
        root.items[5 + i] = &h[i];
    }
    for (i = 0; i < 5; i++) {
        set_006A69C0(&f[i], D_L39_002488C0, D_L39_004B05C8[2 + i], D_L39_004B05C8[0], D_L39_004B05C8[7 + i], D_L39_004B05C8[1]);
        root.items[21 + i] = &f[i];
    }
    for (row = 0; row < 8; row++) {
        f32 y = D_L39_004B0638[0] + D_L39_004B0638[12] * (f32)row;
        for (i = 0; i < 5; i++) {
            set_006A69C0(&g[row * 5 + i], D_L39_002488C0, D_L39_004B0638[2 + i], y, D_L39_004B0638[7 + i], D_L39_004B0638[1]);
            root.items[row * 5 + 26 + i] = &g[row * 5 + i];
        }
    }
    root.n = 0x42;
    func_L39_00689670(p, &root);
    return p;
}
/* localdecomp:end func_L39_006A69C0 */

LINKER_REMNANT("asm/levels", func_L39_006A6F98);

/* localdecomp:start func_L39_006A6FA0 */
/* Retail stores D_L39_0047DA80 at object+0x60 and tail-calls-like func_L39_00688400; see the report. */
extern u8 D_L39_0047DA80[];
extern void func_L39_00688400(u8 *, s32);

void func_L39_006A6FA0(void *object, s32 flags)
{
    u8 *p = (u8 *)object;
    *(void **)(p + 0x60) = D_L39_0047DA80;
    func_L39_00688400(p, flags);
}
/* localdecomp:end func_L39_006A6FA0 */

/* localdecomp:start func_L39_006A6FC8 */
typedef struct P_006A6FC8 {
    s16 f0;
    s16 f2;
} P_006A6FC8;

typedef struct G_006A6FC8 {
    u8 pad0[0x120];
    s32 f120[8];
    P_006A6FC8 f140[8];
    u8 pad160[0x48];
    s32 f1A8;
    u8 pad1AC[0xC];
    s16 f1B8[8];
    u8 pad1C8[0x644];
    s32 f80C;
} G_006A6FC8;

typedef struct M_006A6FC8 {
    u8 pad0[0x19D];
    s8 f19D;
} M_006A6FC8;

typedef struct S_006A6FC8 {
    u8 pad0[0x2A8];
    u8 names[8][0x10];
} S_006A6FC8;

extern G_006A6FC8 D_001FD7E8;
extern M_006A6FC8 *D_L39_00241640;
extern s32 func_00120884(u8 *);

s32 func_L39_006A6FC8(void *arg, s32 a, s32 b) {
    S_006A6FC8 *arg0 = arg;
    s32 da;
    s32 db;
    s32 sa;
    s32 sb;

    if (func_00120884(arg0->names[a]) == 0 && func_00120884(arg0->names[b]) == 0) {
        return 0;
    }
    if (func_00120884(arg0->names[a]) == 0) {
        return 1;
    }
    if (func_00120884(arg0->names[b]) == 0) {
        return 0;
    }
    da = D_001FD7E8.f140[a].f0 - D_001FD7E8.f1B8[a];
    db = D_001FD7E8.f140[b].f0 - D_001FD7E8.f1B8[b];
    sa = D_001FD7E8.f140[a].f2;
    sb = D_001FD7E8.f140[b].f2;
    if (D_001FD7E8.f1A8 == -1 || (D_001FD7E8.f80C == 2 && D_L39_00241640->f19D == 0)) {
        if (da < db) {
            return 1;
        }
        if (da == db) {
            return sb < sa;
        }
        return 0;
    }
    if (D_001FD7E8.f120[a] != D_001FD7E8.f1A8 && D_001FD7E8.f120[b] == D_001FD7E8.f1A8) {
        return 1;
    }
    if (D_001FD7E8.f120[a] != D_001FD7E8.f120[b]) {
        return 0;
    }
    if (da < db) {
        return 1;
    }
    if (da == db) {
        return sb < sa;
    }
    return 0;
}
/* localdecomp:end func_L39_006A6FC8 */

/* localdecomp:start func_L39_006A7178 */
typedef struct E_006A7178 {
    u8 name[0x20];
} E_006A7178;

typedef struct G_006A7178 {
    E_006A7178 e[8];
    u8 pad100[0xA8];
    s32 f1A8;
} G_006A7178;

typedef struct S_006A7178 {
    u8 pad0[0x2A8];
    u8 names[8][0x10];
    u8 pad328[0x128];
    s32 order[8];
} S_006A7178;

extern G_006A6FC8 D_001FD7E8;
extern void func_001206F4(u8 *, u8 *);
extern s32 func_L39_006A6FC8(void *, s32, s32);

void func_L39_006A7178(S_006A7178 *arg0) {
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 8; i++) {
        if (((G_006A7178 *)&D_001FD7E8)->e[i].name[0] != 0) {
            func_001206F4(arg0->names[i], ((G_006A7178 *)&D_001FD7E8)->e[i].name);
        } else {
            arg0->names[i][0] = 0;
        }
        arg0->order[i] = i;
    }
    if (D_001FD7E8.f1A8 != -1) {
        for (i = 0; i < 8; i++) {
            for (j = i + 1; j < 8; j++) {
                if (func_L39_006A6FC8(arg0, arg0->order[i], arg0->order[j]) != 0) {
                    t = arg0->order[i];
                    arg0->order[i] = arg0->order[j];
                    arg0->order[j] = t;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006A7178 */

INCLUDE_ASM("asm/levels", func_L39_006A72B0);
