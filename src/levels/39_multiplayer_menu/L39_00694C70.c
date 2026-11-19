#include "common.h"

/* declared by functions of L39_00694418.c, which this file was cut from */
extern void *func_00381FF0(s32);

/* localdecomp:start func_L39_00694C70 */
typedef struct W_00694C70 W_00694C70;
typedef struct {
    u8 pad0[0x1C];
    void (*set)(W_00694C70 *, s32, s32);
    u8 pad1[0xB4 - 0x20];
    void (*clear)(W_00694C70 *);
    void (*text)(W_00694C70 *, char *);
} WV_00694C70;
struct W_00694C70 {
    u8 pad[0x60];
    WV_00694C70 *vt;
            char *str;
};
typedef struct {
    u8 pad0[0x124];
    W_00694C70 *f124;
    W_00694C70 *f128;
    W_00694C70 *f12c;
    u8 pad1[4];
    W_00694C70 *f134;
    u8 pad2[0x3CC - 0x138];
    s32 f3cc;
} S_00694C70;
typedef struct {
    u8 pad0[0x14];
    s32 f14;
    u8 pad1[0x38 - 0x18];
    s32 *f38;
    u8 pad2[0x44 - 0x3C];
    s32 f44;
} G_00694C70;
extern G_00694C70 *D_L39_0024D760_00694C70;
extern char D_L39_00247EF8[];
extern s32 func_0038CAD0(void *);
extern s32 func_L39_006CEA18(void *, s32);
extern void func_L39_00689BD8(S_00694C70 *, s32 *);
extern s32 func_L39_006D2F18(s32 *, s32 *, s32 *);
extern u8 *func_L39_006D31B8(s32 *, s32, s32);
extern s32 func_L39_006D6E50(s32, s32, s32, s32 *);
extern int func_00120048(char *, char *, ...);

void func_L39_00694C70(S_00694C70 *p)
{
    s32 *s = D_L39_0024D760_00694C70->f38;
    s32 a;
    s32 b;
    s32 st[100];
    char buf[16];

    func_0038CAD0(&p->f3cc);
    if (p->f3cc > 0) {
        return;
    }
    func_L39_006CEA18(s, 0);
    p->f3cc = 750;
    func_L39_00689BD8(p, s + 1);
    if (func_L39_006D2F18(s, &a, &b)) {
        u8 *r = func_L39_006D31B8(s, b, a);
        if (r) {
            p->f12c->vt->text(p->f12c, (char *)(r + 0x20));
            p->f134->vt->set(p->f134, 3, 0);
        } else {
            D_L39_0024D760_00694C70->f14 = 0;
            p->f12c->vt->text(p->f12c, (char *)func_00381FF0(0x1328));
            p->f134->vt->set(p->f134, 2, 0);
        }
    } else {
        p->f134->vt->set(p->f134, 2, 0);
        p->f12c->vt->text(p->f12c, (char *)func_00381FF0(0x1328));
    }
    if (func_L39_006D6E50(D_L39_0024D760_00694C70->f44, *s, 1, st)) {
        func_00120048(buf, D_L39_00247EF8, st[2], st[3]);
        p->f124->vt->text(p->f124, buf);
        func_00120048(buf, D_L39_00247EF8, st[0], st[1]);
        p->f128->vt->text(p->f128, buf);
    } else {
        p->f124->vt->clear(p->f124);
        p->f128->vt->clear(p->f128);
    }
}
/* localdecomp:end func_L39_00694C70 */

LINKER_REMNANT("asm/levels", func_L39_00694E60);

/* localdecomp:start func_L39_00694E78 */
typedef struct {
    s32 f0;
    char pad4[0x44];
    u8 f48;
    char pad49[3];
    s32 f4C;
} A_00694E78;
typedef struct {
    s32 f0;
    char pad4[0x44];
    char f48[0x400];
    char pad448[8];
} B_00694E78;
typedef struct {
    s32 f0;
    char pad4[0x34];
    s32 f38;
    s32 f3C;
    f32 f40;
    f32 f44;
    s32 f48;
    s32 f4C;
    A_00694E78 *f50;
    B_00694E78 *f54;
    char pad58[0x1D0 - 0x58];
} C_00694E78;

extern u8 D_L39_0047CB68[];
extern u8 D_L39_00247F58[];
extern u8 D_L39_00247F60[];
void *func_L39_00688388(void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void *func_00381FF0(s32);
void func_00120D28(char *, char *, s32);
void func_L39_00689670(void *, C_00694E78 *);

static __inline__ void item_00694E78(void *it, s32 name, f32 x, f32 y, f32 w, f32 h)
{
    *(s32 *)it = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
}

static __inline__ void label_00694E78(A_00694E78 *it, s32 name, f32 x, f32 y, f32 w, f32 h, s32 n)
{
    item_00694E78(it, name, x, y, w, h);
    it->f0 = 4;
    it->f4C = n;
    it->f48 = 0;
}

static __inline__ void text_00694E78(B_00694E78 *it, s32 name, f32 x, f32 y, f32 w, f32 h, char *str)
{
    item_00694E78(it, name, x, y, w, h);
    it->f0 = 9;
    if (str == 0) {
        it->f48[0] = 0;
    } else {
        func_00120D28(it->f48, str, 0x3FF);
        it->f48[0x3FF] = 0;
    }
}

void *func_L39_00694E78(u8 *p)
{
    A_00694E78 a;
    B_00694E78 b;
    C_00694E78 c;
    C_00694E78 *pc;

    func_L39_00688388(p);
    *(u8 **)(p + 0x60) = D_L39_0047CB68;
    *(u8 **)(p + 0x2A4) = p + 0x2BC;
    label_00694E78(&a, (s32)D_L39_00247F58, 0.5f, 0.27f, 0.8f, 0.25f, 0x24);
    text_00694E78(&b, (s32)D_L39_00247F60, 0.5f, 0.635f, 0.78f, 0.41f, func_00381FF0(0x1010));
    pc = &c;
    item_00694E78(pc, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pc->f48 = 0x2E;
    c.f4C = 0;
    c.f38 = 0;
    c.f3C = 0;
    pc->f40 = 1.0f;
    pc->f44 = 1.0f;
    c.f54 = &b;
    c.f4C = 2;
    c.f50 = &a;
    func_L39_00689670(p, pc);
    return p;
}
/* localdecomp:end func_L39_00694E78 */

LINKER_REMNANT("asm/levels", func_L39_00694FF8);
