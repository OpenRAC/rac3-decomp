#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 ids[3];
} Grp_003326D8;

typedef struct { u8 pad[0x44]; s32 ids[3]; } Grp_00332298;

/* localdecomp:start func_L07_00332098 */
typedef struct { u8 pad[4]; u8 *rows; u8 gap[8]; } T_332098;
typedef struct { u8 pad[0x50]; s32 ids[8]; u8 gap[0x2E]; u8 mode, index; } V_332098;
extern T_332098 D_L07_002B0D40_00332098[];
extern u8 *D_L07_001DF41C_00332098;
extern s32 func_L07_00333B90(void);
extern s32 func_L07_00333BF8(u8 *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern s32 func_L02_003A02D8(void *, s32);
extern s32 func_L07_003A24C8(void);
extern void func_L07_003A2380(u8, void *, s32, s32);
void func_L07_00332098(u8 *self) {
    V_332098 *v = *(V_332098 **)(self + 0x68);
    u8 *row = D_L07_002B0D40_00332098[v->mode].rows + v->index * 12;
    s32 special, count, start, i, accum;
    if (!row[0]) return;
    count = 8 - func_L07_00333B90();
    special = row[0] == 2;
    if (special && func_L07_00333BF8(self)) special = 0;
    if (!count) return;
    start = func_00382468(8);
    accum = 4;
    for (i = 0; i < 8; i++) {
        s32 index, activate;
        u8 *obj;
        if ((v->index & 1) != (i & 1)) continue;
        index = start + i;
        accum += count;
        if (index >= 8) index -= 8;
        activate = 0;
        if (accum >= 8) { accum -= 8; activate = 1; }
        obj = D_L07_001DF41C_00332098 + (v->ids[index] << 8);
        if (special) {
            if (func_L02_003A02D8(obj, 1)) {
                if (func_L07_003A24C8())
                    func_L07_003A2380(func_00382498(37, 38), self, 0, 100);
                special = 0;
            }
        } else if (activate) func_L02_003A02D8(obj, 0);
    }
}
/* localdecomp:end func_L07_00332098 */

/* localdecomp:start func_L07_00332230 */
extern u8 *D_L07_001DF41C_00332230;
extern void func_L07_003A3BB0(u8 *p, s32 a1);

void func_L07_00332230(u8 *a0, s32 a1) {
    s32 *p = (s32 *)(*(u8 **)(a0 + 0x68) + 0x50);
    s32 i;

    for (i = 7; i >= 0; i--) {
        func_L07_003A3BB0(D_L07_001DF41C_00332230 + ((*p) << 8), a1);
        p++;
    }
}
/* localdecomp:end func_L07_00332230 */

/* localdecomp:start func_L07_00332298 */
extern s32 D_L07_001DF458_00332298;
extern u8 *D_L07_001DF41C_00332298;
extern u16 *D_L07_0021C020[];
extern s32 *func_L07_00333B20_00332298(u8 *e);
extern void func_L07_00333D40(s32 a, u8 *e);

void func_L07_00332298(u8 *a0) {
    Grp_00332298 *o = *(Grp_00332298 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    s32 i;

    for (i = 0; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L07_001DF458_00332298 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = D_L07_001DF41C_00332298 + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            func_L07_00333D40(func_L07_00333B20_00332298(e)[1], e);
        }
    }
}
/* localdecomp:end func_L07_00332298 */

/* localdecomp:start func_L07_003323F8 */
typedef struct { u8 pad[4]; u8 *rows; u8 gap[8]; } T_3323F8;
typedef struct { u8 pad[0x44]; s32 groups[3]; u8 gap[0x4E]; u8 mode, index; } V_3323F8;
extern T_3323F8 D_L07_002B0D40_003323F8[];
extern u8 D_L07_001DCEB8;
__asm__(".extern D_L07_001DCEB8, 1");
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458_003323F8;
extern u8 *D_L07_001DF41C_003323F8;
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L07_003A2380(u8, void *, s32, s32);
extern u8 *func_L07_00333B20(u8 *);
void func_L07_003323F8(u8 *self) {
    V_3323F8 *v = *(V_3323F8 **)(self + 0x68);
    u8 *row = D_L07_002B0D40_003323F8[v->mode].rows + v->index * 12;
    u8 *values = &D_L07_001DCEB8 + row[1] * 3;
    s32 said = 0;
    s32 i;
    for (i = 0; i < 3; i++) {
        u16 *p;
        if (v->index && values[i] != 1) {
            u8 *previous = &D_L07_001DCEB8 + (D_L07_002B0D40_003323F8[v->mode].rows + v->index * 12)[-11] * 3;
            if (values[i] != previous[i] && !said && func_00382468(2)) {
            switch (i) {
                case 0:
                    if (values[0] == 2)
                        func_L07_003A2380(func_00382498(35,36), self, 0,100);
                    else
                        func_L07_003A2380(func_00382498(29,30), self, 0,100);
                    break;
                case 1:
                    func_L07_003A2380(func_00382498(31,32), self, 0,100);
                    break;
                case 2:
                    func_L07_003A2380(func_00382498(33,34), self, 0,100);
                    break;
            }
            said = 1;
            }
        }
        for (p = D_L07_0021C020[v->groups[i]];
             (v->groups[i] & 255) != 255 && v->groups[i] <= D_L07_001DF458_003323F8 && p;
             p++) {
            u8 *obj;
            u8 *r;
            if (((s16 *)p)[-1] < 0 && p != D_L07_0021C020[v->groups[i]]) break;
            obj = D_L07_001DF41C_003323F8 + ((*p & 0x7FFF) << 8);
            if (!obj) break;
            r = (u8 *)func_L07_00333B20(obj);
            r[8] = values[i];
        }
    }
}
/* localdecomp:end func_L07_003323F8 */

/* localdecomp:start func_L07_003326D8 */
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458[];
extern u8 *D_L07_001DF41C[];
extern u8 *func_L07_00333B20(u8 *);

s32 func_L07_003326D8(u8 *a0) {
    Grp_003326D8 *o = *(Grp_003326D8 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *r;
    s32 i = 0;

    for (; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= *(s32 *)0x1DF458 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = *(u8 **)0x1DF41C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            r = func_L07_00333B20(e);
            if (e[0x20] != r[8])
                return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003326D8 */

/* localdecomp:start func_L07_00332848 */
typedef struct {
    s32 f0;
    s32 f4;
} E_332848;

typedef struct {
    u8 pad0[0x8A];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_332848;

typedef struct {
    u8 pad0[0xBF];
    u8 fBF;
} B_332848;

typedef struct {
    u8 pad0[0x68];
    B_332848 *p68;
} O_332848;

extern u8 D_001425C0[];
extern s32 D_001427F0_00332848[];
extern E_332848 D_L07_002B0EB0_00332848[];
extern T_332848 D_L07_002C72C0[];
extern s32 D_L07_001E0CD0[] __attribute__((section(".sdata")));

void func_L07_00332848(u8 *a0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        s32 idx = D_L07_002B0EB0_00332848[i].f0;
        s32 v = D_001427F0_00332848[idx];
        u8 t = D_001425C0[idx];
        T_332848 *e = &D_L07_002C72C0[t];

        D_L07_001E0CD0[i] = v;
        D_001427F0_00332848[idx] = e->f8A;
    }
    ((O_332848 *)a0)->p68->fBF = 1;
}
/* localdecomp:end func_L07_00332848 */

/* localdecomp:start func_L07_003328D0 */
typedef struct { s32 idx; s32 x; } E_003328D0;
extern E_003328D0 D_L07_002B0EB0_003328D0[];
extern s32 D_L07_001E0CD0[] __attribute__((section(".sdata")));
extern s32 D_001427F0_003328D0[];

void func_L07_003328D0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 i;

    if (p[0xBF] != 0) {
        for (i = 0; i < 16; i++) {
            s32 k = D_L07_002B0EB0_003328D0[i].idx;
            D_001427F0_003328D0[k] = D_L07_001E0CD0[i];
        }
        p[0xBF] = 0;
    }
}
/* localdecomp:end func_L07_003328D0 */

/* localdecomp:start func_L07_00332928 */
void func_L07_00332928(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *q = p + 0x8F;
    s32 i;
    for (i = 15; i >= 0; i--) {
        *q-- = i;
    }
}
/* localdecomp:end func_L07_00332928 */

/* localdecomp:start func_L07_00332958 */
typedef struct {
    u8 pad0[0x80];
    u8 order[0x10];
    u8 pad90[0x20];
    u8 cur;
    u8 idx;
    u16 fB2;
    u16 fB4;
} Ent_00332958;

typedef struct {
    s32 f0;
    u8 f4;
    u8 pad5[3];
} Row_00332958;

typedef struct {
    u16 h;
    u16 pad;
} Half_00332958;

extern Row_00332958 D_L07_002B0EB0[];
extern u8 D_00142CA0[];
extern Half_00332958 D_001427F0[];
extern void func_L07_00334968(u8 *arg0, s32 arg1);
extern s32 func_00382468(s32);

s32 func_L07_00332958(u8 *a0) {
    Ent_00332958 *o = *(Ent_00332958 **)(a0 + 0x68);
    Row_00332958 *r;
    u8 *p;
    s32 n;
    u8 t;
    s32 i;

    if (o->idx == 0xFF) {
        o->cur = 0;
        p = o->order;
    } else {
        o->cur = o->order[o->idx];
        p = o->order;
    }

    for (;;) {
        n = o->idx + 1;
        o->idx = n;
        if ((u8)n >= 16) {
            o->idx = 0;
            func_L07_00334968(p, 16);
            if (o->order[0] == o->cur) {
                i = func_00382468(15) + 1;
                t = p[i];
                o->order[0] = t;
                p[i] = o->cur;
            }
        }
        r = &D_L07_002B0EB0[p[o->idx]];
        if (D_00142CA0[r->f0] != 0)
            break;
    }
    r = &D_L07_002B0EB0[o->cur];
    o->fB2 = D_001427F0[r->f0].h;
    o->fB4 = r->f4;
    return r->f0;
}
/* localdecomp:end func_L07_00332958 */

/* localdecomp:start func_L07_00332A90 */
typedef struct {
    u8 pad0[0x44];
    s32 ids[3];
} Grp_00332A90;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
} Sub_00332A90;

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x3];
    Sub_00332A90 *f24;
    u8 pad28[0x70];
    s32 f98;
} Ent_00332A90;

extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458_00332A90;
extern u8 *D_L07_001DF41C_00332A90;

s32 func_L07_00332A90(u8 *a0) {
    Grp_00332A90 *o = *(Grp_00332A90 **)(a0 + 0x68);
    Ent_00332A90 *e;
    u16 *q;
    s32 i;
    s32 r = 0;

    for (i = 0; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L07_001DF458_00332A90 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = (Ent_00332A90 *)(D_L07_001DF41C_00332A90 + ((*q & 0x7FFF) << 8));
            if (e == 0)
                break;
            if (e->f20 != 1) {
                r = 1;
                e->f98 = e->f24->f10;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L07_00332A90 */

/* localdecomp:start func_L07_00332BE0 */
typedef struct { u8 pad[0x44]; s32 ids[3]; } Grp_00332BE0;
typedef struct { u8 pad[0x98]; s32 f98; } Ent_00332BE0;

extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458_00332BE0;
extern u8 *D_L07_001DF41C_00332BE0;

void func_L07_00332BE0(u8 *a0) {
    Grp_00332BE0 *o = *(Grp_00332BE0 **)(a0 + 0x68);
    u16 *q;
    Ent_00332BE0 *e;
    s32 i;

    for (i = 0; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L07_001DF458_00332BE0 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = (Ent_00332BE0 *)(D_L07_001DF41C_00332BE0 + ((*q & 0x7FFF) << 8));
            if (e == 0)
                break;
            e->f98 = 0;
        }
    }
}
/* localdecomp:end func_L07_00332BE0 */
