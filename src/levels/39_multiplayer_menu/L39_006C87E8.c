#include "common.h"

/* localdecomp:start func_L39_006C87E8 */
typedef struct {
    u8 pad[0x18];
    s32 id;
    char name[1];
} I_006C87E8;
typedef struct {
    s32 f0;
    s32 count;
    I_006C87E8 **items;
} E_006C87E8;
typedef struct {
    u8 f0;
    u8 pad0[7];
    s32 f8;
    u8 pad1;
    u8 fd;
    u8 pad2[6];
    E_006C87E8 e;
} M_006C87E8;
typedef struct L_006C87E8 L_006C87E8;
typedef struct {
    u8 pad0[0x20];
    void (*mode)(L_006C87E8 *, s32, s32);
    u8 pad1[0x6C - 0x24];
    void (*items)(L_006C87E8 *, s32, char **);
    u8 pad2[0x88 - 0x70];
    void (*select)(L_006C87E8 *, s32);
    s32 (*get)(L_006C87E8 *);
} LV_006C87E8;
struct L_006C87E8 {
    u8 pad[0x60];
    LV_006C87E8 *vt;
};
typedef struct {
    u8 pad0[0x114];
    L_006C87E8 *f114;
    u8 pad1[0x2AC - 0x118];
    u8 f2ac;
    u8 pad2[3];
    s32 f2b0;
    s32 f2b4;
    s32 f2b8[50];
} S_006C87E8;
typedef struct {
    u8 pad[0x78];
    M_006C87E8 *f78;
} G_006C87E8;
__asm__(".extern D_L39_0024D760, 16");
extern G_006C87E8 *D_L39_0024D760;
extern f32 D_L39_00249854;
extern f32 D_L39_00249858;
extern f32 D_L39_00249868[];
extern f32 D_L39_00249874 __attribute__((section(".data")));
extern s32 func_L39_006D7018(void *);
extern void func_L39_0068A4A8(S_006C87E8 *, s32, s32, s32, f32, f32, f32, f32);

void func_L39_006C87E8(S_006C87E8 *p)
{
    M_006C87E8 *m = D_L39_0024D760->f78;
    E_006C87E8 *e = 0;
    s32 sel;
    s32 i;
    s32 j;
    s32 k;
    s32 idx;
    char *names[50];

    if (m->fd) {
        e = &m->e;
    }
    if (p->f2ac == 1 && m->f0 == 0) {
        func_L39_006D7018(m);
        p->f2b0 = m->f8;
        p->f2ac = 0;
    }
    if (e == 0) {
        return;
    }
    if (m->f8 == p->f2b0) {
        return;
    }
    p->f2b0 = m->f8;
    p->f2b4 = e->count;
    if (p->f2b4 > 50) {
        p->f2b4 = 50;
    }
    idx = 0;
    i = p->f114->vt->get(p->f114);
    sel = -1;
    if (i != -1) {
        sel = p->f2b8[i];
    }
    k = 0;
    for (j = 0; j < p->f2b4; j++) {
        I_006C87E8 *it = e->items[j];
        if (it->id >= 0) {
            names[k] = it->name;
            if (sel == it->id) {
                idx = k;
            }
            p->f2b8[k] = it->id;
            k++;
        }
    }
    p->f2b4 = k;
    p->f114->vt->items(p->f114, k, names);
    p->f114->vt->select(p->f114, idx);
    if (p->f2b4 > 0) {
        p->f114->vt->mode(p->f114, 3, 0);
    } else {
        p->f114->vt->mode(p->f114, 2, 0);
    }
    func_L39_0068A4A8(p, 0, k < 8 ? k : 7, 0x332299DE, D_L39_00249868[0], D_L39_00249854,
                      D_L39_00249858, D_L39_00249874);
}
/* localdecomp:end func_L39_006C87E8 */

/* localdecomp:start func_L39_006C89D8 */
typedef struct VT_006C89D8 {
    u8 pad0[0x20];
    void (*fn20)(void *, s32, s32);
    u8 pad24[0x6C - 0x24];
    void (*fn6C)(void *, s32, void *);
    u8 pad70[0x88 - 0x70];
    void (*fn88)(void *, s32);
    s32 (*fn8C)(void *);
} VT_006C89D8;
typedef struct Obj_006C89D8 {
    u8 pad0[0x60];
    VT_006C89D8 *vt;
} Obj_006C89D8;
typedef struct Ent_006C89D8 {
    u8 pad0[0x18];
    s32 id;
    u8 name[1];
} Ent_006C89D8;
typedef struct Self_006C89D8 {
    u8 pad0[0x114];
    Obj_006C89D8 *obj;
    u8 pad118[0x2B0 - 0x118];
    s32 key;
    s32 count;
    s32 ids[60];
    s32 mode;
} Self_006C89D8;
typedef struct List_006C89D8 {
    u8 pad0[4];
    s32 count;
    Ent_006C89D8 **items;
} List_006C89D8;
__asm__(".extern D_L39_0024D760, 16");
extern f32 D_001DE144_sda;
extern f32 D_001DE148_sda;
extern s32 func_00381FF0(s32);

void func_L39_006C89D8(Self_006C89D8 *self)
{
    void *names[52];
    u8 *e;
    List_006C89D8 *p;
    Ent_006C89D8 *q;
    s32 n, id, i, cnt, sel, idx, cur, x, v;

    e = (u8 *)((s32 *)D_L39_0024D760)[0x78 / 4];
    p = 0;
    if (e[0xD] != 0) {
        p = (List_006C89D8 *)(e + 0x14);
    }
    if (p == 0) {
        return;
    }
    v = *(s32 *)(e + 8);
    if (v == self->key) {
        return;
    }
    self->key = v;
    names[0] = (void *)func_00381FF0(0xFBF);
    self->ids[0] = 0;
    n = p->count;
    self->count = n;
    if (n > 50) {
        self->count = 50;
    }
    sel = 0;
    idx = self->obj->vt->fn8C(self->obj);
    cur = -1;
    if (idx != -1) {
        cur = self->ids[idx];
    }
    x = *(s32 *)((u8 *)((s32 *)D_L39_0024D760)[0x30 / 4] + 0x28);
    cnt = 1;
    for (i = 0; i < self->count; i++) {
        q = p->items[i];
        if (self->mode == 3 && q->id == x) {
            continue;
        }
        names[cnt] = q->name;
        id = q->id;
        self->ids[cnt] = id;
        if (cur == id) {
            sel = cnt;
        }
        cnt++;
    }
    self->count = cnt;
    self->obj->vt->fn6C(self->obj, cnt, names);
    self->obj->vt->fn88(self->obj, sel);
    if (self->count > 0) {
        self->obj->vt->fn20(self->obj, 3, 0);
    } else {
        self->obj->vt->fn20(self->obj, 2, 0);
    }
    func_L39_0068A4A8((S_006C87E8 *)self, 0, cnt < 8 ? cnt : 7, 0x332299DE,
                      D_L39_00249868[0], D_001DE144_sda, D_001DE148_sda, D_L39_00249874);
}
/* localdecomp:end func_L39_006C89D8 */

LINKER_REMNANT("asm/levels", func_L39_006C8BD0);
