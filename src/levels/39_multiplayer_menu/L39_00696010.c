#include "common.h"

/* declared by functions of L39_00695FC0.c, which this file was cut from */
typedef struct S_00695FC0_T { s32 f0; u8 pad[0x30]; u8 f34; } S_00695FC0_T;
typedef struct S_00695FC0_G { u8 pad[0x38]; S_00695FC0_T *f38; } S_00695FC0_G;
extern S_00695FC0_G *D_L39_0024D760;

/* localdecomp:start func_L39_00696010 */
typedef struct S_00696010_E {
    u8 pad[0x1C];
    s32 f1C;
    u8 pad2[8];
    u8 f28[1];
} S_00696010_E;
typedef struct S_00696010_L {
    s32 f0;
    s32 f4;
    S_00696010_E **f8;
} S_00696010_L;
typedef struct S_00696010_T {
    u8 pad[0x45C];
    u8 f45C;
    u8 pad1[3];
    s32 f460;
    u8 f464;
    u8 pad2[7];
    s32 f46C;
    u8 pad3[4];
    S_00696010_L f474[1];
} S_00696010_T;
typedef struct S_00696010_W S_00696010_W;
typedef struct S_00696010_V {
    u8 pad[0x20];
    void (*f20)(S_00696010_W *, s32, s32);
    u8 pad1[0x48];
    s32 (*f6C)(S_00696010_W *, s32, u8 **);
    u8 pad2[0x18];
    void (*f88)(S_00696010_W *, s32);
    s32 (*f8C)(S_00696010_W *);
} S_00696010_V;
struct S_00696010_W {
    u8 pad[0x60];
    S_00696010_V *f60;
};
typedef struct S_00696010_O {
    u8 pad[0x118];
    S_00696010_W *f118;
    u8 pad1[0x190];
    u8 f2AC;
    u8 pad2[3];
    s32 f2B0;
    u8 pad3[0x50];
    s32 f304;
    s32 f308[64];
} S_00696010_O;
extern u8 D_L39_00247FC0[];
extern void func_L39_006D1B40(S_00696010_T *);
extern s32 func_00120884(u8 *);
extern void func_L39_005958F8(u8 *, u8 *, s32);
extern u8 *func_00381FF0(s32);
extern void func_L39_0068A4A8(S_00696010_O *, s32, s32, s32, f32, f32, f32, f32);

static __inline__ void fill_00696010(S_00696010_O *o, u8 **names)
{
    u8 bufs[64][0x50];
    u8 **np;
    u8 *q;
    s32 j;

    j = 0;
    if (j < o->f304) {
        np = names;
        q = bufs[0];
        do {
            func_L39_005958F8(q, *np, func_00120884(*np));
            *np = q;
            j++;
            np++;
            q += 0x50;
        } while (j < o->f304);
    }
}

void func_L39_00696010(S_00696010_O *o)
{
    S_00696010_T *t = (S_00696010_T *)D_L39_0024D760->f38;
    S_00696010_L *list = 0;
    s32 cnt;
    s32 n;
    u8 *names[64];
    s32 sel;
    s32 cur;
    s32 r;
    s32 i;

    if (t->f45C != 0 && t->f460 >= 0) {
        list = &t->f474[t->f460];
    }
    if (o->f2AC == 1 && t->f464 == 0) {
        o->f2B0 = t->f46C;
        func_L39_006D1B40(t);
        o->f2AC = 0;
    }
    if (list == 0 || t->f46C == o->f2B0) {
        return;
    }
    o->f2B0 = t->f46C;
    cnt = 64;
    if (list->f4 <= 63) {
        cnt = list->f4;
    }
    o->f304 = cnt;
    sel = -1;
    r = o->f118->f60->f8C(o->f118);
    if (r != -1) {
        sel = o->f308[r];
    }
    cur = 0;
    for (i = 0; i < o->f304; i++) {
        S_00696010_E *e = list->f8[i];
        names[i] = e->f28;
        o->f308[i] = e->f1C;
        if (sel == e->f1C) {
            cur = i;
        }
    }
    if (o->f304 > 0) {
        fill_00696010(o, names);
        o->f118->f60->f6C(o->f118, o->f304, names);
        o->f118->f60->f88(o->f118, cur);
        o->f118->f60->f20(o->f118, 3, 0);
        n = o->f304;
        if (n > 8) {
            n = 8;
        }
        func_L39_0068A4A8(o, 0, n, 0x332299DE, 0.274f, 0.2528f, 0.053f, 0.32500002f);
    } else {
        u8 *empty[2] = { D_L39_00247FC0, func_00381FF0(0x101D) };
        o->f118->f60->f6C(o->f118, 2, empty);
        o->f118->f60->f20(o->f118, 2, 0);
        func_L39_0068A4A8(o, 0, 0, 0x332299DE, 0.274f, 0.2528f, 0.053f, 0.32500002f);
    }
}
/* localdecomp:end func_L39_00696010 */

LINKER_REMNANT("asm/levels", func_L39_006962F8);
