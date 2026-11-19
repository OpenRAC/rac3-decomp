#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034ACA8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034ACA8;

typedef struct {
    u8 pad0[0x10];
    V4_0034ACA8 pos;
    u8 state;
    u8 pad21[0x34 - 0x21];
    u16 flags34;
    u8 pad36[0x68 - 0x36];
    void *vars;
} Obj_0034ACA8;

typedef struct {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1C[0x20 - 0x1C];
} Slot_0034ACA8;

typedef struct {
    u8 pad0[0x158];
    u8 *w158;
} Vars_0034ACA8;

typedef struct {
    u8 pad0[0x68];
    Vars_0034ACA8 *vars;
} Moby_0034ACA8;

__asm__(".extern D_L31_001DD2C8, 4");
__asm__(".extern D_L31_001DD2A8, 4");
extern s32 D_L31_001DD2C8[8] __attribute__((section(".sdata")));
extern s32 D_L31_001DD2A8[8] __attribute__((section(".sdata")));
extern Slot_0034ACA8 D_L31_001F01C0[];
extern void func_L01_00424D88(s32);

void func_L31_0034ACA8(Moby_0034ACA8 *m) {
    Obj_0034ACA8 **list = *(Obj_0034ACA8 ***)(m->vars->w158 + 0x68);
    s32 i;

    for (i = 0; list != 0 && i < 8; i++) {
        if (D_L31_001DD2C8[i] >= 0) {
            s32 h = D_L31_001DD2A8[D_L31_001DD2C8[i]];
            Obj_0034ACA8 *o = list[i];
            if (o == 0 || o->state == 0xFE || o->state == 0xFD || (o->flags34 & 2) || o->vars == 0) {
                if (h != -1) {
                    func_L01_00424D88(h);
                    D_L31_001DD2A8[D_L31_001DD2C8[i]] = -1;
                }
            } else {
                V4_0034ACA8 pos = o->pos;
                if (h >= 0) {
                    Slot_0034ACA8 *s = &D_L31_001F01C0[h];
                    s->x = pos.x;
                    s->y = pos.y;
                    s->z = pos.z;
                }
            }
        }
    }
}
/* localdecomp:end func_L31_0034ACA8 */

/* localdecomp:start func_L31_0034ADF0 */
#include "vu0.h"
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034ADF0;
typedef struct {
    u8 pad0[0x68];
    void **vars;
} Owner_0034ADF0;
typedef struct {
    u8 pad0[0x158];
    Owner_0034ADF0 *owner;
    s32 x15C;
} Vars_0034ADF0;
typedef struct {
    u8 pad0[0x68];
    Vars_0034ADF0 *vars;
    u8 pad6C[0xC0 - 0x6C];
    f32 xC0;
} Moby_0034ADF0;

__asm__(".extern D_L31_001DD308, 4");
__asm__(".extern D_L31_001DD30C, 4");
__asm__(".extern D_L31_001DD310, 4");
extern f32 D_L31_001DD308;
extern f32 D_L31_001DD30C;
extern f32 D_L31_001DD310;
__asm__(".extern D_L31_001DD2A8, 8");
extern s32 D_L31_001DD2A8[] __attribute__((section(".sdata")));
extern void *D_L31_001E12D0[] __attribute__((section(".sdata")));
extern u8 D_L31_001D66B0[8];
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L31_0034ABB8(Moby_0034ADF0 *, s32);

void func_L31_0034ADF0(Moby_0034ADF0 *m, V4_0034ADF0 *base, s32 idx) {
    Vars_0034ADF0 *v = m->vars;
    void **slots = v->owner->vars;
    V4_0034ADF0 vel;
    V4_0034ADF0 off;
    V4_0034ADF0 pos;
    s32 type;
    void *r;

    func_00382580(&vel, D_L31_001DD308 * 0.6f * 0.0200000014f, D_L31_001DD308 * 0.0200000014f);
    func_0038CE20(&off, &m->xC0, -(D_L31_001DD30C * 0.0200000014f));
    vec_add_ab(&vel, &vel, &off);
    vel.z += func_003824E0(D_L31_001DD310 * 0.5f, D_L31_001DD310) * 0.0200000014f;
    vel.y = func_003824E0(-1.0f, 1.0f) * 0.0200000014f;
    qzero(&pos);
    type = 1;
    if (idx == 0) {
        type = 13;
        pos.x = m->xC0 * 12.0f;
    } else if (idx == 13) {
        type = 0;
    } else {
        pos.x = m->xC0 * 2.0f;
    }
    vec_add_ba(&pos, &pos, base);
    r = func_L01_003F79D8(m, 2, 0x165E, type, &pos, D_L31_001D66B0, &vel, 0xFF, 30.0f, 15.0f, 0xB4, 0, 0x80);
    D_L31_001E12D0[idx] = r;
    if (!(idx & 1)) {
        if (D_L31_001DD2A8[v->x15C] == -1) {
            void **e = slots + idx;

            *e = r;
            func_L31_0034ABB8(m, idx);
        }
    }
}
/* localdecomp:end func_L31_0034ADF0 */

/* localdecomp:start func_L31_0034AFD8 */
#include "vu0.h"
typedef int u128_0034AFD8 __attribute__((mode(TI)));

typedef struct {
    u8 b[16];
} Col_0034AFD8;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 s34;
    u8 pad36[0x70 - 0x36];
    Col_0034AFD8 c70;
    u8 pad80[0xD4 - 0x80];
    s32 timer;
    u8 padD8[0xE8 - 0xD8];
    s32 wE8;
    s32 wEC;
    s32 wF0;
    u8 padF4[0xFC - 0xF4];
    s32 sound;
    u8 pad100[0x118 - 0x100];
    s32 w118;
    u8 pad11C[0x154 - 0x11C];
    s32 w154;
    u8 *w158;
    u8 pad15C[0x160 - 0x15C];
    s32 w160;
} Vars_0034AFD8;

typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x68 - 0x21];
    Vars_0034AFD8 *vars;
} Moby_0034AFD8;

typedef struct {
    u128_0034AFD8 q0;
    u128_0034AFD8 q10;
    u128_0034AFD8 q20;
    u128_0034AFD8 q30;
    u128_0034AFD8 q40;
    u128_0034AFD8 q50;
    u128_0034AFD8 q60;
    u128_0034AFD8 q70;
    u8 pad80[0x10];
    s32 w90;
} S_0034AFD8;

__asm__(".extern D_L31_001DD2A0, 4");
__asm__(".extern D_L31_001DD25C, 4");
__asm__(".extern D_L31_001DD260, 4");
__asm__(".extern D_L31_001DD250, 4");
__asm__(".extern D_L31_001DD254, 4");
__asm__(".extern D_L31_001DD240, 4");
extern s32 D_L31_001DD2A0;
extern f32 D_L31_001DD25C;
extern f32 D_L31_001DD260;
extern s32 D_L31_001DD250;
extern s32 D_L31_001DD254;
extern s32 D_L31_001DD240;
extern f32 D_L31_001E12B4;
extern s32 D_001A71A0[];
extern u8 D_001A30B0[];
extern u8 D_00142732 __attribute__((section(".data")));
extern u8 D_001426D7 __attribute__((section(".data")));
extern u8 D_001A6718 __attribute__((section(".data")));
extern u8 D_001A4C60[];
extern u8 D_L31_00284110[];
extern S_0034AFD8 D_001A4CD0;
extern u8 *D_L31_001DF79C;

extern void func_L31_0034D088(Moby_0034AFD8 *);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L31_0034C5A0(Moby_0034AFD8 *, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern void func_L31_0034CC30(Moby_0034AFD8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern u8 *func_L31_003B3D38(s32 n, u8 **arr, s32 unused, f32 x, s32 c, s32 d, f32 y);
extern void func_003A4F28(s32);
extern void func_L31_0034BCA8(Moby_0034AFD8 *);
extern void func_L31_0034ACA8(Moby_0034ACA8 *);
extern void func_L31_0034CB80(Moby_0034AFD8 *);
extern s32 func_00382380(void *, s32, s32);
extern void func_003C2C98(void *, void *);
extern void func_L01_0043A430(u8 *, s32, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L31_0034B580(Moby_0034AFD8 *);
extern s32 func_L30_004CF4B0(s32, s32);
extern void func_L31_0034D390(Moby_0034AFD8 *, s32);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L31_0034BF90(Moby_0034AFD8 *);
extern void func_L31_0034CA18(Moby_0034AFD8 *);

void func_L31_0034AFD8(Moby_0034AFD8 *m) {
    Vars_0034AFD8 *v = m->vars;
    Col_0034AFD8 c;
    u8 *list[14];
    s32 i;
    s32 j;
    u8 *p;
    u8 *e;

    switch (m->state) {
    case 1:
        func_L31_0034D088(m);
        break;
    case 2:
        if (func_L01_004561B8((u8 *)m)) {
            v->timer = v->w118 = D_L31_001E12B4 / func_003C4088(D_L31_001DD25C, D_L31_001DD260, 1.0f - v->f30 / v->s34);
        }
        if (v->timer > v->w118) {
            v->timer = v->w118;
        }
        func_L31_0034C5A0(m, (f32)(v->w118 - v->timer) / v->w118);
        if (func_0038CAD0(&v->timer)) {
            if (v->w154 == 0) {
                func_L31_0034B580(m);
            } else {
                func_L31_0034CC30(m);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8((u8 *)m)) {
            v->timer = v->w118 = D_L31_001E12B4 / func_003C4088(D_L31_001DD25C, D_L31_001DD260, 1.0f - v->f30 / v->s34);
        }
        if (v->timer > v->w118) {
            v->timer = v->w118;
        }
        func_L31_0034C5A0(m, (f32)(v->w118 - v->timer) / v->w118);
        if (func_0038CAD0(&v->timer)) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 66:
        if (func_L01_004561B8((u8 *)m)) {
            func_L01_004AAC98(0, 0, D_001A71A0[0], 0x165E);
        }
        if (func_0038CAD0(&v->timer)) {
            u8 *q = *(u8 **)(v->w158 + 0x68);
            if (q != 0) {
                q[0x4B] = 1;
            }
            if (v->w154 == 0) {
                D_00142732 = 1;
            }
            func_L31_0034CC30(m);
        }
        break;
    case 4:
        if (func_L01_004561B8((u8 *)m)) {
            v->timer = D_L31_001DD250;
            func_L01_004AAC98(3, 0, D_001A71A0[0], 0x165E);
            if (v->sound == -1 || *(Moby_0034AFD8 **)((e = D_001A30B0 + (v->sound << 7)) + 0xDC) != m ||
                e[0xD0] == 0) {
                v->sound = func_003A52A0(5, 4, m);
            }
            c = v->c70;
            func_L01_0043B9E8((u8 *)m, c.b[4], c.b[5], c.b[6]);
            for (j = 13; j >= 0; j--) {
                list[j] = 0;
            }
            list[0] = (u8 *)m;
            v->w158 = func_L31_003B3D38(14, list, 100, 1.0f, 7, 5, 280.0f);
        }
        if (func_0038CAD0(&v->timer)) {
            v->timer = D_L31_001DD254;
            if (v->sound != -1 && *(Moby_0034AFD8 **)((e = D_001A30B0 + (v->sound << 7)) + 0xDC) == m &&
                e[0xD0] != 0) {
                func_003A4F28(v->sound);
            }
            v->sound = -1;
            func_L01_004450F0(m, 0x42, -1);
        } else {
            func_L31_0034BCA8(m);
            func_L31_0034ACA8((Moby_0034ACA8 *)m);
        }
        break;
    case 0:
        func_L31_0034CB80(m);
        if (D_001426D7 & 0x10) {
            func_L01_004450F0(m, 0x42, -1);
        } else {
            func_L01_004450F0(m, 5, -1);
        }
        break;
    case 5:
        if (func_00382380(D_001A4C60, v->wF0, 0)) {
            p = D_L31_00284110;
            for (i = 0; i < 31; i++) {
                if (p[1] != 0) {
                    func_003C2C98(m, p);
                }
                func_L01_0043A430((u8 *)m, i, p);
                p += 0x40;
            }
            if (v->w154 == 0) {
                func_L01_004450F0(m, 6, -1);
            } else if ((D_001A6718 ^ 1) & 1) {
                func_L31_0034B580(m);
            }
        }
        break;
    case 6:
        if (func_L01_004561B8((u8 *)m)) {
            func_L30_004CF4B0(0x74, 1);
            qzero(&D_001A4CD0.q0);
            qzero(&D_001A4CD0.q20);
            qzero(&D_001A4CD0.q30);
            qzero(&D_001A4CD0.q40);
            qzero(&D_001A4CD0.q70);
            D_001A4CD0.w90 = 0;
            func_L31_0034D390(m, 1);
            func_L01_00456230(D_L31_001DF79C + (v->wE8 << 8), 1);
            func_L01_00456230(D_L31_001DF79C + (v->wEC << 8), 1);
            v->timer = D_L31_001DD240;
            func_L01_0045F1E8(v->w160, -1);
        }
        if (func_0038CAD0(&v->timer)) {
            func_L30_004CF4B0(0x9A, 1);
            func_L31_0034B580(m);
        }
        break;
    }
    if (D_L31_001DD2A0 != 0) {
        v->timer++;
    }
    if (m->state != 0xFD && m->state != 0xFE && m->state != 0xFF) {
        func_L31_0034BF90(m);
        func_L31_0034CA18(m);
    }
}
/* localdecomp:end func_L31_0034AFD8 */
