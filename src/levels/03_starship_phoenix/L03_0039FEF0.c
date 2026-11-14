#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x20]; u8 st; u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; void *p68;
} S_0039E470;
typedef struct {
    u8 pad0[0x23]; u8 b23;
} T_0039E470;
typedef struct {
    u8 pad0[0x144]; s16 h144;
    u8 pad146[0x250 - 0x146]; void *p250;
    u8 pad254[0x268 - 0x254]; s16 h268;
    u8 pad26A[0x300 - 0x26A]; T_0039E470 *p300;
    u8 pad304[0x309 - 0x304]; u8 b309; s16 h30A; f32 f30C; u8 b310;
} P_0039E470;

typedef struct {
    u8 pad0[0x39];
    u8 b39;
    u8 pad3A[0x6];
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x25];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 pad83[0x3];
    u8 b86;
    u8 pad87[0x5];
    f32 f8C;
    f32 f90;
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    f32 fAC;
    u8 padB0[0x8];
    u8 bB8;
    u8 padB9[0x2F];
    u8 bE8;
    u8 bE9;
    u8 padEA[0x1];
    u8 bEB;
    u8 padEC[0x64];
    f32 f150;
    f32 f154;
    f32 f158;
    f32 f15C;
    f32 f160;
    u8 pad164[0x18];
    f32 f17C;
    f32 f180;
    f32 f184;
    s32 w188;
    u8 pad18C[0xB0];
    s32 w23C;
    u8 pad240[0x14];
    void * p254;
    void * p258;
    u8 pad25C[0x11];
    u8 b26D;
    u8 pad26E[0x92];
    s32 w300;
} P_0039E748;

typedef struct {
    u8 pad0[0x44]; u8 b44;
    u8 pad45[0x70 - 0x45]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x144 - 0x138]; s16 s144;
    u8 pad146[0x188 - 0x146]; s32 i188;
    u8 pad18C[0x250 - 0x18C]; void *p250;
    u8 pad254[0x268 - 0x254]; s16 s268; s16 s26A; u8 pad26C[4]; u8 a270[0x80];
    u8 a2F0[0x10]; u8 *p300;
    u8 pad304[0x30C - 0x304]; f32 f30C; u8 a310[0x10];
} P_003A05D0;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st;
    u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; P_003A05D0 *p;
    u8 pad6C[0xBC - 0x6C]; u8 bBC;
} S_003A05D0;
void func_0038D2D0(void *, float);
void func_003D9740(void *, int, int, int, int, float);
void func_L03_0039FEF0(void *, s32);

typedef struct {
    u8 pad0[0x39];
    u8 b39;
    u8 pad3A[0x6];
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x25];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 pad83[0x3];
    u8 b86;
    u8 pad87[0x5];
    f32 f8C;
    f32 f90;
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    f32 fAC;
    u8 padB0[0x8];
    u8 bB8;
    u8 padB9[0x2F];
    u8 bE8;
    u8 bE9;
    u8 padEA[0x1];
    u8 bEB;
    u8 padEC[0x64];
    f32 f150;
    f32 f154;
    f32 f158;
    f32 f15C;
    f32 f160;
    u8 pad164[0x18];
    f32 f17C;
    f32 f180;
    f32 f184;
    s32 w188;
    u8 pad18C[0xB0];
    s32 w23C;
    u8 pad240[0x14];
    void * p254;
    void * p258;
    u8 pad25C[0xE];
    s16 h26A;
    u8 pad26C[0x1];
    u8 b26D;
    u8 pad26E[0x92];
    s32 w300;
} P_003A0BF8;

typedef struct {
    u8 pad[0x20];
    f32 speed, acceleration, limit;
    u8 pad2C[0xC];
    s32 flags;
} Move_39E708;
typedef struct {
    u8 pad[0x150];
    Move_39E708 move;
    u8 pad18C[0x2F0 - 0x18C];
    u8 list[0x440 - 0x2F0];
    vu0_v4 destination;
    u8 pad450[0xA];
    u8 flag;
} Vars_39E708;
typedef struct {
    u8 pad[0x10];
    vu0_v4 pos;
    u8 pad20[0x14];
    u16 flags;
    u8 pad36[0xD];
    u8 animation;
    u8 pad44[0x24];
    Vars_39E708 *vars;
    u8 pad6C[0x54];
    vu0_v4 forward;
} Object_39E708;

/* localdecomp:start func_L03_0039FEF0 */
/* PAL port of the NTSC-U match src/us/levels/func_L03_0039E708.c */
#include "vu0.h"


extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L03_0032DA08(void *);
extern void func_L03_0032D6B8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045BD78(u8*a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_0044E318(void *, void *);
extern void func_L01_0044E340(void *, s32, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_0039FEF0(void *obj_, s32 state) {
    Object_39E708 *obj = obj_;
    Vars_39E708 *v = obj->vars;
    vu0_v4 vec;
    void *list;
    switch (state) {
    case 1:
        if (obj->animation != 2) func_003C3A10(obj, 2, 0, 0);
        break;
    case 2:
        if (obj->animation != 2) func_003C3A10(obj, 2, 0, 0);
    case 3:
        obj->flags |= 0x5000;
        break;
    case 4:
        break;
    case 5:
        func_L03_0032DA08(obj);
        if (obj->animation != 2) func_003C3A10(obj, 2, 0, 2);
        break;
    case 6: {
        Move_39E708 *m = &v->move;
        m->speed = 0.016f;
        m->limit = 0.16000001f;
        m->acceleration = 0.016f;
        m->flags &= ~0x10;
        if (obj->animation != 3) func_003C3A10(obj, 3, 0, 2);
        break;
    }
    case 7:
        func_L03_0032D6B8(obj);
        if (obj->animation != 4) func_003C3A10(obj, 4, 0, 2);
        break;
    case 8:
        if (obj->animation != 5) func_003C3A10(obj, 5, 0, 2);
        break;
    case 9: {
        Move_39E708 *m;
        func_L03_0032D6B8(obj);
        m = &v->move;
        m->speed = 0.0012f;
        m->limit = 0.060000002f;
        m->acceleration = 0.0012f;
        m->flags |= 0x10;
        if (obj->animation != 0) func_003C3A10(obj, 0, 0, 7);
        break;
    }
    case 10:
        v->flag = 0;
        if (obj->animation != 6) func_003C3A10(obj, 6, 0, 7);
        break;
    case 11:
        func_0038CF68(&vec, &obj->forward, 6.0f);
        list = v->list;
        vec_add_ba(&v->destination, &obj->pos, &vec);
        func_L01_0045BD78(obj, 0.120000005f, 1.0000001f,
                         0.0012566372f, 0.06283186f);
        v->move.flags |= 0x10;
        func_L01_0044E318(obj, list);
        func_L01_0044E340(list, 0x40, 1, 1.1f);
        func_L01_0044E340(list, 0x30, 2, 1.1f);
        func_L01_0044E340(list, 0x20, 3, 1.1f);
        func_L01_0044E340(list, 0x10, 4, 1.1f);
        if (obj->animation != 7) func_003C3A10(obj, 7, 0, 2);
        break;
    case 12:
        if (obj->animation != 8) func_003C3A10(obj, 8, 0, 2);
        break;
    case 13: {
        Move_39E708 *m = &v->move;
        m->speed = 0.0012f;
        m->limit = 0.060000002f;
        m->acceleration = 0.0012f;
        m->flags |= 0x10;
        if (obj->animation != 1) func_003C3A10(obj, 1, 5, 2);
        break;
    }
    case 14: {
        Move_39E708 *m = &v->move;
        m->speed = 0.00080000004f;
        m->limit = 0.040000003f;
        m->acceleration = 0.00080000004f;
        m->flags |= 0x10;
        if (obj->animation != 0) func_003C3A10(obj, 0, 0, 2);
        break;
    }
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L03_0039FEF0 */

/* localdecomp:start func_L03_003A02B0 */
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
f32 func_L03_0032DC08(s32, void *, void *, f32);
void func_L01_0045A7A8(void *, void *, f32);
void func_L03_0032D6B8(void *);

void func_L03_003A02B0(void *arg0, f32 arg1) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    f32 ang;
    void *p;
    if (*(s32 *)(s + 0x188) & 0x10) {
        p = (u8 *)arg0 + 0xF8;
        ang = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)((u8 *)arg0 + 0x10), *(f32 *)(s + 0x134) - *(f32 *)((u8 *)arg0 + 0x14));
        func_L01_00448890(p, s + 0x204, 0, ang, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    }
    func_L03_0032FAF0((f32 *)(s + 0x440), (f32 *)(s + 0x130), *(f32 *)(s + 0x264), arg1);
    ang = func_0038DB00(*(f32 *)(s + 0x260), *(f32 *)(s + 0x264));
    ang = func_L03_0032DC08(*(s32 *)(s + 0x250), arg0, s + 0x440, ang * 0.15f);
    func_L01_0045A7A8(arg0, s + 0x440, ang);
    func_L03_0032D6B8(arg0);
}
/* localdecomp:end func_L03_003A02B0 */

/* localdecomp:start func_L03_003A0398 */
#include "vu0.h"
typedef struct { u8 pad0[0x44]; u8 b44; u8 pad45[0x415]; u8 b45A; } P_003A0398;
typedef struct { u8 pad0[0x25C0]; s32 w25C0; } T_003A0398;
extern s32 D_L03_001ED280[];
extern T_003A0398 D_001A4BE0_003A0398;
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L03_0032DBC0(void *);
extern s32 func_L03_0032DBD0(void *, s32);
extern s32 func_L01_00446780(void *, void *, s32, s32, f32, f32, f32, s32, s32);
s32 func_L03_003A0398(void *a) {
    P_003A0398 *p = *(P_003A0398 **)((u8 *)a + 0x68);
    vu0_v4 v;
    vu0_v4 w;
    s32 s;
    s32 n;
    s32 i;
    f32 f20;
    func_003C2F58(a, 0, &v);
    func_0038CF68(&w, (u8 *)a + 0xC0, 0.25f);
    vec_add_ab(&v, &v, &w);
    s = func_L03_0032DBC0(a);
    f20 = p->b44;
    n = func_L01_00446780(a, &v, s, func_L03_0032DBD0(a, 7), 0.25f, f20, 1.0f, 1, 0);
    for (i = 0; i < n; i++) {
        if (D_L03_001ED280[i] == D_001A4BE0_003A0398.w25C0) {
            p->b45A = 1;
            break;
        }
    }
    return n;
}
/* localdecomp:end func_L03_003A0398 */

/* localdecomp:start func_L03_003A04D0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A04D0;
typedef struct { f32 pad[10]; f32 f28; f32 f2c; V4_003A04D0 v30; } S_003A04D0;

void func_L03_003A04D0(void *arg0) {
    S_003A04D0 s;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 t;
    func_0038D2D0(&s, 0.75f);
    s.v30 = *(V4_003A04D0 *)((u8 *)arg0 + 0x10);
    s.f28 = -0.85f;
    s.v30.z += 0.85f;
    t = *(f32 *)(p + 0x454) + 0.096f;
    *(f32 *)(p + 0x454) = t;
    if (1.0f < t) {
        *(f32 *)(p + 0x454) = t - 1.0f;
    }
    func_003D9740(&s, 0x28,
                  ((s32)((p[0x45B] / 15.0f) * 255.0f) << 24) | 0xFF4040, 5, 1, *(f32 *)(p + 0x454));
}
/* localdecomp:end func_L03_003A04D0 */

/* localdecomp:start func_L03_003A05D0 */
extern void func_L03_003A0BF8(void *);
extern void func_L03_003A0DA0();
extern void func_L03_003A1158(void *, s32);
extern void func_L03_003A13E8(void *, f32);
extern void func_L03_003A14D0(void *, void *, void *, s32);
extern void func_L03_003A1600(void *);
extern void func_L03_0039DB68(void *, void *, f32, f32, void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0045A9F0(void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_0045AA10(void *, f32);
extern s32 func_L03_0032D598(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_004395E0(void *);
extern s32 func_L03_0032DB58(void *);
extern s16 func_L03_0032D8C0(void *);
extern void func_L03_0032DA08(void *);
extern s32 func_L03_0032DBC0(void *);
extern s32 func_L03_0032DBD0(void *, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);

void func_L03_003A05D0(S_003A05D0 *s) {
    P_003A05D0 *p;
    char buf[16];
    f32 f20;
    f32 d;
    u8 *v;
    s32 r;
    s32 t;

    func_L03_003A0BF8(s);
    func_L03_003A0DA0(s);
    p = s->p;
    switch (s->st) {
    case 2:
        if (func_L01_004561B8(s)) {
            p->f30C = 1.0f / (f32)p->s268;
        }
        s->b23 = (s32)((1.0f - p->f30C * (f32)p->s268) * 128.0f);
        if (func_0038CB00(&p->s268)) {
            s->b23 = 0x80;
            func_L03_003A1158(s, 3);
        }
        if (p->p300 != 0) {
            p->p300[0x23] = s->b23;
        }
        break;
    case 3:
        func_L01_0045A9F0(s);
        func_L03_003A1158(s, 5);
    case 4:
        if (func_L01_00454370(s, p->a70) & 2) {
            func_L03_003A1158(s, 5);
        }
        break;
    case 5:
        func_L01_0045A9F0(s);
        if (func_L03_0032D598(p->p250, s)) {
            if (func_L01_0040E570(&s->x, &p->f130) < 64.0f) {
                func_L03_003A1158(s, 9);
            } else {
                func_L03_003A1158(s, 6);
            }
        } else {
            func_L03_003A1158(s, 0xE);
        }
        break;
    case 6:
        p->i188 &= ~0x10;
        d = func_0038D160(p->f130 - s->x, p->f134 - s->y);
        func_L01_0045AA10(s, d);
        if (s->b60 & 2) {
            func_L03_003A1158(s, 7);
        }
        break;
    case 7:
        func_L03_003A13E8(s, 3.0f);
        if (p->s144 != 1 || !func_L03_0032D598(p->p250, s) || func_L01_0040E570(&s->x, &p->f130) < 16.0f) {
            func_L03_003A1158(s, 8);
        }
        break;
    case 8:
        if (s->b60 & 2) {
            if (p->s144 != 1) {
                func_L03_003A1158(s, 5);
            } else if (func_L03_0032D598(p->p250, s)) {
                if (func_L01_0040E570(&s->x, &p->f130) < 64.0f) {
                    func_L03_003A1158(s, 9);
                } else {
                    func_L03_003A1158(s, 6);
                }
            } else {
                func_L03_003A1158(s, 0xE);
            }
        }
        break;
    case 9:
        func_L03_003A13E8(s, 5.0f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0032DA08(s);
            func_L03_003A1158(s, 5);
        } else if (!func_L03_0032D598(p->p250, s)) {
            func_L03_0032DA08(s);
            func_L03_003A1158(s, 0xE);
        } else if (func_L01_0040E570(&s->x, &p->f130) < 64.0f) {
            if (p->s26A == -1) {
                p->s26A = func_L03_0032D8C0(s);
            }
            if (func_L03_0032DB58(s)) {
                func_L03_003A1158(s, 0xA);
            }
        } else {
            p->i188 &= ~0x10;
            func_L03_0032DA08(s);
            func_L03_003A1158(s, 5);
        }
        break;
    case 10: {
        u8 *v8 = p->a2F0;
        func_L03_003A13E8(s, 5.0f);
        r = func_L01_004561B8(s);
        func_L03_003A14D0(s, v8, 0, r & 0xFF);
        func_L01_00404808(func_L03_003A1600, s);
        if (func_0038CB00(p->a310)) {
            func_L03_003A1158(s, 0xB);
        }
        break;
    }
    case 11:
        func_L03_003A13E8(s, 5.0f);
        if (func_L01_0044E1B8(s, 15.0f) && p->p300 != 0) {
            u8 *v9 = p->a2F0;
            s32 t9;
            func_L03_003A14D0(s, v9, buf, 0);
            f20 = p->b44;
            t9 = func_L03_0032DBC0(s);
            r = func_L03_0032DBD0(s, 2);
            func_L03_0039DB68(buf, v9, 0.120000005f, f20, s, t9, r);
        } else {
            if (func_L01_004395E0(s) < 15.0f) {
                func_L03_003A14D0(s, p->a2F0, 0, 0);
                func_L01_00404808(func_L03_003A1600, s);
            }
        }
        if (s->b60 & 2) {
            func_L03_0032DA08(s);
            func_L03_003A1158(s, 0xC);
        }
        break;
    case 12:
        func_L03_003A13E8(s, 5.0f);
        switch (s->bBC) {
        case 0:
            break;
        case 1:
            func_L03_003A1158(s, 0xD);
            break;
        case 2:
        case -1:
            func_L03_003A1158(s, 5);
            break;
        }
        break;
    case 13:
        if (s->b60 & 2) {
            func_L03_003A1158(s, 5);
        }
        break;
    case 14:
        func_L03_003A13E8(s, 8.0f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_003A1158(s, 5);
        } else if (func_L03_0032D598(p->p250, s)) {
            p->i188 &= ~0x10;
            func_L03_003A1158(s, 6);
        }
        break;
    case 1:
        break;
    }
    func_L01_00451DF8(s, p->a270, 1, 1, 1.5f);
}
/* localdecomp:end func_L03_003A05D0 */

/* localdecomp:start func_L03_003A0BF8 */
void func_L03_003A1050(void *);
void func_L03_003A10A8(void *);
extern void func_L01_0045BD78(u8*a0, f32 a, f32 b, f32 c, f32 d);
void func_L03_003A0BF8(void *a) {
    P_003A0BF8 *p;
    if (*(u8 *)((u8 *)a + 0x20) == 0) {
        p = *(P_003A0BF8 **)((u8 *)a + 0x68);
        p->bB8 = 0xFF;
        p->b39 = 0;
        p->w23C = 0;
        p->b80 = 4;
        p->b81 = 7;
        p->b82 = 7;
        p->bE8 = 5;
        p->bE9 = 5;
        p->fAC = 0.150000006f;
        p->bEB = 0xFF;
        p->b86 = 0xFF;
        p->f8C = 0.300000012f;
        p->f90 = 0.0200000014f;
        p->f94 = 0.0100000007f;
        p->f98 = 0.0140000004f;
        p->f9C = 0.000800000038f;
        p->b58 = 0x14;
        p->b5A = 0xE;
        p->f40 = 1.0f;
        p->f160 = 1.57079637f;
        p->f180 = 0.244346097f;
        p->f17C = 0.196000025f;
        p->fA0 = 0.5f;
        p->fA4 = 0.5f;
        p->f150 = 0.5f;
        p->f154 = 0.5f;
        p->f158 = 0.5f;
        p->f15C = 0.5f;
        p->f184 = 0.5f;
        p->p254 = func_L03_003A10A8;
        p->p258 = func_L03_003A1050;
        p->b26D = 2;
        func_L01_0045BD78(a, 0.00120000006f, 0.0600000024f, 0.00125663716f, 0.0628318563f);
        p->h26A = -1;
        func_L03_003A1050(a);
        p->w300 = 0;
    }
}
/* localdecomp:end func_L03_003A0BF8 */

/* localdecomp:start func_L03_003A0DA0 */
typedef struct {
    u8 pad0[0x30]; f32 f30;
    u8 pad34[0x3E - 0x34]; u8 b3E; u8 pad3F[0x5E - 0x3F]; u8 b5E; u8 pad5F; u8 b60;
    u8 pad61[0x70 - 0x61]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x228 - 0x138]; s32 i228;
    u8 pad22C[0x270 - 0x22C]; u8 a270[0x68];
    f32 f2D8; u8 pad2DC[0x300 - 0x2DC]; u8 *p300; u8 pad304[0x312 - 0x304]; u8 b312;
} P_003A0DA0;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st; u8 pad21[0x10]; u8 f31;
    u8 pad32[0x68 - 0x32]; P_003A0DA0 *p; u8 pad6C[3]; u8 b6F; u8 pad70[0x88]; f32 fF8;
} S_003A0DA0;
void func_L01_00404808(void *, void *);
s32 func_L01_00452FB0_003A0DA0(void *, void *, s32, s32, s32);
void func_L03_0032DA08(void *);
void func_L03_0032DDC8(void *, s32, s32);
void func_L03_0032DF10(void *);
void func_003A52A0(s32, s32, void *);
void func_L03_0032FBC8(void *);
void func_003C2F58(void *, s32, void *);
void func_003C2EC0(void *, s32, void *);
void func_0038D590(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_003C7C38(void *);
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
void func_L01_0044E850(void *, void *, s32, f32, f32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
void func_L03_003A16D8(void *);
extern u8 D_L03_001E24C0[];
void func_L03_003A0DA0(S_003A0DA0 *s) {
    P_003A0DA0 *p;
    char buf[0x40];
    f32 one;
    f32 a;
    p = s->p;
    if (s->st == 1) return;
    if (p->i228 == 1) {
        func_L01_00404808(func_L03_003A16D8, s);
        if (p->b312 < 15) p->b312++;
    } else if (p->b312 != 0) {
        func_L01_00404808(func_L03_003A16D8, s);
        p->b312--;
    }
    if (func_L01_00452FB0_003A0DA0(s, p->a70, 0, 0, 0)) func_L03_0032DA08(s);
    if (p->f30 <= 0.0f) {
        func_L03_0032DDC8(s, 15, 2);
        func_L03_0032DF10(s);
        func_003A52A0(6, 0, s);
        return;
    }
    if (p->b5E != 0 || p->b60 != 0 || p->b3E == 2) {
        func_L03_0032DF10(s);
        return;
    }
    func_L03_0032FBC8(s);
    if (p->p300 != 0) {
        one = 1.0f;
        func_003C2F58(s, 0, p->p300 + 0x10);
        func_003C2EC0(s, 0, buf);
        func_0038D590(p->p300 + 0xC0, buf);
        func_0038CF68(p->p300 + 0xC0, p->p300 + 0xC0, one);
        func_0038CF68(p->p300 + 0xD0, p->p300 + 0xD0, one);
        func_0038CF68(p->p300 + 0xE0, p->p300 + 0xE0, one);
        func_003C7C38(p->p300);
    }
    if (s->st >= 6) {
        a = func_0038DB00(func_0038D160(p->f130 - s->x, p->f134 - s->y), s->fF8);
        p->f2D8 = a;
        if (a > 1.04719758f) p->f2D8 = 1.04719758f; else if (a < -1.04719758f) p->f2D8 = -1.04719758f;
    }
    func_L01_0044E850(s, p->a270, 1, 0.0432000011f, 0.432000041f);
    if (s->f31 != 0) {
        if (func_L01_0040E548(D_L03_001E24C0, &s->x) < 576.0f) {
            func_L01_004472C0(s);
            s->b6F = 22;
        }
    }
}
/* localdecomp:end func_L03_003A0DA0 */

/* localdecomp:start func_L03_003A1050 */
void func_003C2880(s32);
void func_L03_0032FD50(void *);
void func_L03_003A1158(void *, s32);

void func_L03_003A1050(void *arg0) {
    s32 temp_a0;
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s1 + 0x300);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s1 + 0x300) = 0;
    }
    func_L03_0032FD50(arg0);
    func_L03_003A1158(arg0, 1);
}
/* localdecomp:end func_L03_003A1050 */

/* localdecomp:start func_L03_003A10A8 */
void *func_003C24B0(s32, s32);
void func_003C7C38(void *);
void func_L01_0044A7D0(u8 *);
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L03_0032FE10(void *);
void func_L03_003A1158(void *, s32);

void func_L03_003A10A8(void *arg0) {
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_v0 = func_003C24B0(0x18FB, 0x80);
    *(void **)((u8 *)temp_s0 + 0x300) = temp_v0;
    if (temp_v0 != 0) {
        *(u16 *)((u8 *)temp_v0 + 0x34) = (u16) ((*(u16 *)((u8 *)temp_v0 + 0x34)) | 0x100);
        *(u16 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x32) = (u16) (*(u16 *)((u8 *)arg0 + 0x32));
        *(u8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x31) = (u8) (*(u8 *)((u8 *)arg0 + 0x31));
        *(s8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x30) = 0;
        temp_v0_2 = *(void **)((u8 *)temp_s0 + 0x300);
        *(void **)((u8 *)temp_s0 + 0x240) = temp_v0_2;
        func_L01_0044A7D0(temp_v0_2);
        func_003C7C38((*(void **)((u8 *)temp_s0 + 0x300)));
    }
    func_L01_004AAC98(4, 4, arg0, 0x197C);
    func_L03_0032FE10(arg0);
    func_L03_003A1158(arg0, 2);
}
/* localdecomp:end func_L03_003A10A8 */
