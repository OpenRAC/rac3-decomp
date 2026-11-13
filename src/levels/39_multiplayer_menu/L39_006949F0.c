#include "common.h"

/* declared by functions of L39_00694418.c, which this file was cut from */
typedef struct {
    u8 pad[0xC8];
    u8 fc8;
    s32 fcc;
    s32 fd0;
} R_006948A0;
typedef struct {
    s32 f0;
    s32 f4;
    R_006948A0 **f8;
} E_006948A0;
typedef struct {
    u8 pad0[0x3EC];
    u8 f3ec;
    s32 f3f0;
    u8 f3f4;
    u8 pad1[0x3FC - 0x3F5];
    s32 f3fc;
    u8 pad2[0x404 - 0x400];
    E_006948A0 entries[1];
} Q_006948A0;
typedef struct { u8 pad[0x38]; Q_006948A0 *f38; } G_006948A0;
extern void *func_00381FF0(s32);

/* localdecomp:start func_L39_006949F0 */
typedef struct {
    u8 pad[0x1C];
    s32 id;
    char name[1];
} I_006949F0;
typedef struct {
    s32 f0;
    s32 count;
    I_006949F0 **items;
} E_006949F0;
typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 pad1[0x3B4 - 0x3C];
    u8 f3b4;
    u8 pad2[3];
    s32 f3b8;
    u8 f3bc;
    u8 pad3[7];
    s32 f3c4;
    u8 pad4[4];
    E_006949F0 ent[1];
} M_006949F0;
typedef struct L_006949F0 L_006949F0;
typedef struct {
    u8 pad0[0x20];
    s32 (*mode)(L_006949F0 *, s32, s32);
    u8 pad1[0x6C - 0x24];
    void (*items)(L_006949F0 *, s32, char **);
    u8 pad2[0x88 - 0x70];
    void (*select)(L_006949F0 *, s32);
    s32 (*get)(L_006949F0 *);
} LV_006949F0;
struct L_006949F0 {
    u8 pad[0x60];
    LV_006949F0 *vt;
};
typedef struct {
    u8 pad0[0x114];
    L_006949F0 *f114;
    u8 pad1[0x2BC - 0x118];
    u8 f2bc;
    u8 pad2[3];
    s32 f2c0;
    s32 f2c4;
    s32 f2c8[65];
} S_006949F0;
extern char D_L39_00247EE0[];
extern G_006948A0 *D_L39_0024D760_006949F0;
extern void func_L39_006D08E8(M_006949F0 *);
extern s32 func_00120884(void *);
extern void func_L39_005958F8(char *, char *, s32);

void func_L39_006949F0(S_006949F0 *p)
{
    M_006949F0 *m = (M_006949F0 *)D_L39_0024D760_006949F0->f38;
    E_006949F0 *e = 0;
    s32 sel;
    s32 i;
    s32 j;
    s32 k;
    s32 idx;
    s32 n;
    s32 c;
    char *names[64];

    if (m->f3b4 && m->f3b8 >= 0) {
        e = &m->ent[m->f3b8];
    }
    if (p->f2bc && !m->f3bc) {
        p->f2c0 = m->f3c4;
        func_L39_006D08E8(m);
        p->f2bc = 0;
    }
    if (e == 0) {
        return;
    }
    if (m->f3c4 == p->f2c0) {
        return;
    }
    p->f2c0 = m->f3c4;
    n = 64;
    if (e->count < 64) n = e->count;
    p->f2c4 = n;
    sel = -1;
    i = p->f114->vt->get(p->f114);
    if (i != -1) {
        sel = p->f2c8[i];
    }
    k = 1;
    p->f2c8[0] = m->f38;
    idx = 0;
    for (j = 0; j < p->f2c4; j++) {
        I_006949F0 *it = e->items[j];
        if (it->id == p->f2c8[0]) {
            names[0] = it->name;
        } else {
            names[k] = it->name;
            p->f2c8[k] = it->id;
            k++;
        }
        if (sel == it->id) {
            idx = k;
        }
    }
    if (p->f2c4 > 0) {
        {
            char bufs[64][0x50];

            for (c = 0; c < p->f2c4; c++) {
                func_L39_005958F8(bufs[c], names[c], func_00120884(names[c]));
                names[c] = bufs[c];
            }
            p->f114->vt->mode(p->f114, 3, 0);
            p->f114->vt->items(p->f114, p->f2c4, names);
            p->f114->vt->select(p->f114, idx);

        }
    } else {
        char *list[2] = { D_L39_00247EE0, (char *)func_00381FF0(0x101B) };
        p->f114->vt->mode(p->f114, 2, 0);
        p->f114->vt->items(p->f114, 2, list);
        p->f114->vt->select(p->f114, idx);
    }
}
/* localdecomp:end func_L39_006949F0 */
