#include "common.h"

/* localdecomp:start func_L39_00694770 */
typedef struct V_00694770 V_00694770;
typedef struct { V_00694770 *vt; } O_00694770;
struct V_00694770 {
    u8 pad[0x88];
    void (*set)(O_00694770 *, s32);
    s32 (*get)(O_00694770 *);
};
typedef struct {
    u8 pad[0x60];
    V_00694770 *vt;
} OB_00694770;
typedef struct {
    u8 pad0[0x114];
    OB_00694770 *f114;
    u8 pad1[0x290 - 0x118];
    s32 f290;
    u8 pad2[0x2C4 - 0x294];
    s32 f2c4;
    u8 pad3[0x3C8 - 0x2C8];
    s32 f3c8;
} S_00694770;
void func_L39_0068B2F8(s32, s32, s32);

s32 func_L39_00694770(S_00694770 *p, s32 arg1)
{
    if (arg1 == 3 || arg1 == 4) {
        if (p->f290 == 1) {
            func_L39_0068B2F8((s32)p, p->f3c8, 0);
            return 1;
        }
        p->f3c8 = p->f290;
        func_L39_0068B2F8((s32)p, 1, 0);
        return 1;
    }
    if (arg1 == 2) {
        if (p->f290 == 1 && p->f114->vt->get((O_00694770 *)p->f114) == p->f2c4 - 1) {
            p->f114->vt->set((O_00694770 *)p->f114, 0);
            return 1;
        }
        if (p->f290 == 10) {
            func_L39_0068B2F8((s32)p, 8, 0);
            return 1;
        }
    } else if (arg1 == 1) {
        if (p->f290 == 1 && p->f114->vt->get((O_00694770 *)p->f114) == 0) {
            p->f114->vt->set((O_00694770 *)p->f114, p->f2c4 - 1);
            return 1;
        }
        if (p->f290 == 8) {
            func_L39_0068B2F8((s32)p, 10, 0);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00694770 */

/* localdecomp:start func_L39_006948A0 */
typedef struct V_006948A0 V_006948A0;
typedef struct { u8 pad[0x60]; V_006948A0 *vt; } O_006948A0;
struct V_006948A0 {
    u8 pad0[0x1C];
    void (*show)(O_006948A0 *, s32, s32);
    u8 pad1[0xB8 - 0x20];
    void (*setText)(O_006948A0 *, void *);
};
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
typedef struct {
    u8 pad0[0x13C];
    O_006948A0 *f13c;
    u8 pad1[0x2A8 - 0x140];
    s32 f2a8;
    u8 f2ac;
    s32 f2b0;
    s32 f2b4;
    s32 f2b8;
} S_006948A0;
extern G_006948A0 *D_L39_0024D760 __attribute__((section(".data")));
extern void *func_00381FF0(s32);
extern void func_L39_006D0DD0(Q_006948A0 *);

void func_L39_006948A0(S_006948A0 *p)
{
    Q_006948A0 *q = D_L39_0024D760->f38;
    E_006948A0 *e = 0;
    R_006948A0 *r;
    s32 v;
    s32 n;

    if (q->f3ec != 0 && q->f3f0 >= 0) {
        e = &q->entries[q->f3f0];
    }
    if (p->f2ac != 0) {
        if (q->f3f4 == 0) {
            p->f2a8 = q->f3fc;
            func_L39_006D0DD0(q);
            p->f2ac = 0;
        }
        if (p->f2ac != 0) {
            return;
        }
    }
    v = q->f3fc;
    if (p->f2a8 == v) {
        return;
    }
    p->f2a8 = v;
    n = e->f4;
    p->f2b0 = n;
    if (n == 0) {
        p->f13c->vt->setText(p->f13c, func_00381FF0(0x101E));
        p->f13c->vt->show(p->f13c, 2, 0);
    } else {
        r = *e->f8;
        if (r->fc8 != 0) {
            p->f2b4 = r->fcc;
            p->f2b8 = r->fd0;
        } else {
            p->f2b4 = -1;
        }
        p->f13c->vt->setText(p->f13c, r);
        p->f13c->vt->show(p->f13c, 1, 0);
    }
}
/* localdecomp:end func_L39_006948A0 */
