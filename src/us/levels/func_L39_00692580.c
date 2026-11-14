#include "common.h"

/* NTSC-U counterpart of func_L39_00694C70 (src/levels/39_multiplayer_menu/L39_00694C70.c): 750 -> 900 */
extern void *func_0037DF98(s32);

/* localdecomp:start func_L39_00692580 */
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
extern G_00694C70 *D_L39_0024D860_00692580;
extern char D_L39_00248058[];
extern s32 func_00388398(void *);
extern s32 func_L39_006CC290(void *, s32);
extern void func_L39_00687030(S_00694C70 *, s32 *);
extern s32 func_L39_006D0790(s32 *, s32 *, s32 *);
extern u8 *func_L39_006D0A30(s32 *, s32, s32);
extern s32 func_L39_006D46C0(s32, s32, s32, s32 *);
extern int func_00120048(char *, char *, ...);

void func_L39_00692580(S_00694C70 *p)
{
    s32 *s = D_L39_0024D860_00692580->f38;
    s32 a;
    s32 b;
    s32 st[100];
    char buf[16];

    func_00388398(&p->f3cc);
    if (p->f3cc > 0) {
        return;
    }
    func_L39_006CC290(s, 0);
    p->f3cc = 900;
    func_L39_00687030(p, s + 1);
    if (func_L39_006D0790(s, &a, &b)) {
        u8 *r = func_L39_006D0A30(s, b, a);
        if (r) {
            p->f12c->vt->text(p->f12c, (char *)(r + 0x20));
            p->f134->vt->set(p->f134, 3, 0);
        } else {
            D_L39_0024D860_00692580->f14 = 0;
            p->f12c->vt->text(p->f12c, (char *)func_0037DF98(0x1328));
            p->f134->vt->set(p->f134, 2, 0);
        }
    } else {
        p->f134->vt->set(p->f134, 2, 0);
        p->f12c->vt->text(p->f12c, (char *)func_0037DF98(0x1328));
    }
    if (func_L39_006D46C0(D_L39_0024D860_00692580->f44, *s, 1, st)) {
        func_00120048(buf, D_L39_00248058, st[2], st[3]);
        p->f124->vt->text(p->f124, buf);
        func_00120048(buf, D_L39_00248058, st[0], st[1]);
        p->f128->vt->text(p->f128, buf);
    } else {
        p->f124->vt->clear(p->f124);
        p->f128->vt->clear(p->f128);
    }
}
/* localdecomp:end func_L39_00692580 */
