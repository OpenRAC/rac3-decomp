#include "common.h"

typedef struct S_0066C4D8 {
    u8 pad0[8];
    s32 f8;
    u8 pad1[0x11C];
    s32 f128;
} S_0066C4D8;

typedef struct {
    s32 kind;
    s32 id;
    s32 lim;
    s32 val;
} Sub_0066C650;
typedef struct {
    s32 pad0;
    s32 pad1;
    Sub_0066C650 s;
} S_0066C650;
typedef struct {
    u8 pad[0x30];
    u8 flag;
    u8 pad2[11];
    s32 f3C;
    s32 f40;
} Ent_0066C650;

/* localdecomp:start func_L39_0066C4D8 */
extern s32 func_L39_0061CF78(s32);
extern S_0066C4D8 D_001A5CD0;

s32 func_L39_0066C4D8(s32 arg0) {
    s32 i;
    S_0066C4D8 *p;

    if (func_L39_0061CF78(arg0) != 0) {
        return 0;
    }
    i = arg0 + 1;
    p = &D_001A5CD0;
    while (i != arg0) {
        if (i >= 8) {
            i = 0;
        }
        if (i == p->f8) {
            return 1;
        }
        if (func_L39_0061CF78(i) != 0) {
            break;
        }
        i++;
    }
    func_L39_0061CF78(i);
    return 0;
}
/* localdecomp:end func_L39_0066C4D8 */

/* localdecomp:start func_L39_0066C558 */
extern void *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, void *, s32, s32, void *);

void func_L39_0066C558(void *arg0) {
    void *n = func_L39_0066C2B8();
    if (n != 0) {
        *(s32 *)n = func_L39_0066C280(6, arg0, D_001A5CD0.f128, D_001A5CD0.f8, n);
    }
}
/* localdecomp:end func_L39_0066C558 */

/* localdecomp:start func_L39_0066C5B0 */
typedef struct {
    s32 f0;
    u8 pad4[0x2C];
    u8 f30;
    u8 f31;
    u8 pad32[10];
    s32 f3C;
    s32 f40;
} Ent_0066C5B0;

extern Ent_0066C5B0 D_L39_0033ABA0[];
extern s32 func_L39_0066C4D8(s32);
extern void func_L39_0066C558(void *);

void func_L39_0066C5B0(void) {
    s32 i;

    for (i = 0; i < 50; i++) {
        u8 f = D_L39_0033ABA0[i].f31;
        if (f == 1 && func_L39_0066C4D8(D_L39_0033ABA0[i].f3C) != 0) {
            D_L39_0033ABA0[i].f30 = f;
            D_L39_0033ABA0[i].f3C = D_001A5CD0.f8;
            func_L39_0066C558((void *)D_L39_0033ABA0[i].f0);
        }
    }
}
/* localdecomp:end func_L39_0066C5B0 */

/* localdecomp:start func_L39_0066C650 */
extern Ent_0066C650 *func_L39_0066C1F0(s32);
extern s32 D_001A5CD8[];

void func_L39_0066C650(S_0066C650 *p) {
    Ent_0066C650 *e;
    Sub_0066C650 *s;
    s32 val;

    s = &p->s;
    if (s->kind != 6) {
        return;
    }
    val = s->val;
    e = func_L39_0066C1F0(s->id);
    if (e == 0) {
        return;
    }
    if (e->f40 < s->lim) {
        e->f3C = val;
    } else {
        if (e->f40 != s->lim) {
            return;
        }
        if (e->f3C == val) {
            return;
        }
        if (e->f3C < val) {
            return;
        }
        e->f3C = val;
    }
    if (val == D_001A5CD8[0]) {
        e->flag = 1;
    }
    e->f40 = s->lim;
}
/* localdecomp:end func_L39_0066C650 */

/* localdecomp:start func_L39_0066C6F0 */
void func_L39_0066C6F0(void) {

}
/* localdecomp:end func_L39_0066C6F0 */

/* localdecomp:start func_L39_0066C6F8 */
void func_L39_0066C6F8(void) {

}
/* localdecomp:end func_L39_0066C6F8 */

/* localdecomp:start func_L39_0066C700 */
s32 func_L39_0066C700(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x40));
}
/* localdecomp:end func_L39_0066C700 */
