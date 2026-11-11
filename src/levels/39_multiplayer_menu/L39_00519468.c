#include "common.h"

/* localdecomp:start func_L39_00519468 */
s32 func_L39_00519468(s32 arg0) {
    switch (arg0) {
    case 0: return 0;
    case -0x1F4: return 0x74;
    case -0x1F5: return 0x71;
    case -0x1F6: return 0x10;
    case -0x1F7: return 0x73;
    case -0x1F8: return 0xC;
    case -0x1FA ... -0x1F9: return 0x7D;
    case -0x1FB: return 0x7F;
    case -0x1FC: return 0x80;
    case -0x1FD: return 0x6E;
    case -0x1FE: return 0x68;
    case -0x1FF: return 0x6F;
    case -0x201 ... -0x200: return 0x16;
    case -0x202: return 0x76;
    }
    return -1;
}
/* localdecomp:end func_L39_00519468 */

/* localdecomp:start func_L39_00519568 */
typedef struct N_00519568 N_00519568;
struct N_00519568 { N_00519568 *next; char p4[4]; s32 id; char pad[0x48]; N_00519568 *f54; char p58[4]; N_00519568 *f5C; };
typedef struct L_00519568 { N_00519568 *head; s32 pad[3]; } L_00519568;
extern L_00519568 D_0046F550;
s32 func_L39_00519568(void) {
    s32 i;
    N_00519568 *n;
    N_00519568 *c;
    for (i = 0; ; i++) {
    for (n = D_0046F550.head; n != 0; n = n->next) {
        if (i == n->id) break;
        for (c = n->f54; c != 0; c = c->next) {
            if (i == c->id) break;
        }
        if (c != 0) break;
        for (c = n->f5C; c != 0; c = c->next) {
            if (i == c->id) break;
        }
        if (c != 0) break;
    }
    if (n == 0) break;
    }
    return i;
}
/* localdecomp:end func_L39_00519568 */

LINKER_REMNANT("asm/levels", func_L39_005195E0);

/* localdecomp:start func_L39_00519600 */
typedef struct N_00519600 N_00519600;
struct N_00519600 { N_00519600 *next; s32 p4[2]; s32 c; s32 f10; s32 pad[0x10]; N_00519600 *f54; s32 p58; N_00519600 *f5C; };
typedef struct P_00519600 { s32 p0[5]; s32 f14[0x10]; s32 f54; } P_00519600;
extern P_00519600 *func_L39_005190E8(s32);
extern N_00519600 *func_L39_00519388(s32);
extern s32 func_L39_005192A8(P_00519600 *, s32);
extern void func_L39_005190C8(void);
extern s32 func_L39_00519058(void);
extern s32 func_148A68(void *, s32, s32, s32);
s32 func_L39_00519600(s32 arg0, s32 arg1) {
    P_00519600 *p;
    N_00519600 *n;
    N_00519600 *c;
    s32 r;

    p = func_L39_005190E8(0);
    if (p == 0) return -1;
    n = func_L39_00519388(arg0);
    if (n == 0) return func_L39_005192A8(p, 9);
    if (n->c != 0) {
        func_L39_005190C8();
        r = func_148A68(p->f14, p->f54, n->c, arg1);
        if (func_L39_00519058() < 0) return func_L39_005192A8(p, -1);
        if (r < 0) return func_L39_005192A8(p, func_L39_00519468(r));
    } else {
        n->f10 = 1;
    }
    for (c = n->f54; c != 0; c = c->next) {
        if (c->c != 0) {
            func_L39_005190C8();
            func_148A68(p->f14, p->f54, c->c, arg1);
            if (func_L39_00519058() < 0) return func_L39_005192A8(p, -1);
        }
    }
    for (c = n->f5C; c != 0; c = c->next) {
        if (c->c != 0) {
            func_L39_005190C8();
            func_148A68(p->f14, p->f54, c->c, arg1);
            if (func_L39_00519058() < 0) return func_L39_005192A8(p, -1);
        }
    }
    func_L39_005192A8(p, 0);
    return 0;
}
/* localdecomp:end func_L39_00519600 */

/* localdecomp:start func_L39_005197A8 */
typedef struct N_005197A8 {
    struct N_005197A8 *next;
    struct N_005197A8 *prev;
    s32 pad[0x12];
    void *p50;
} N_005197A8;
extern N_005197A8 *D_L39_0046F548 __attribute__((section(".data")));
extern N_005197A8 *D_L39_0046F54C __attribute__((section(".data")));
extern s32 D_L39_0046F544 __attribute__((section(".data")));
void func_00148CF0(void *);
void func_L39_00519018(void *);
void func_L39_005197A8(N_005197A8 *arg0) {
    N_005197A8 *prev = arg0->prev;
    N_005197A8 *next = arg0->next;
    if (prev != 0) {
        prev->next = arg0->next;
        next = arg0->next;
        prev = arg0->prev;
    } else {
        D_L39_0046F548 = next;
    }
    if (next != 0) {
        next->prev = prev;
    } else {
        D_L39_0046F54C = prev;
    }
    func_00148CF0((char *)arg0 + 0x14);
    func_L39_00519018(arg0->p50);
    func_L39_00519018(arg0);
    D_L39_0046F544 = D_L39_0046F544 - 1;
}
/* localdecomp:end func_L39_005197A8 */

/* localdecomp:start func_L39_00519828 */
typedef struct N_00519828 {
    struct N_00519828 *next;
    struct N_00519828 *prev;
    struct N_00519828 *key;
} N_00519828;
extern s32 D_L39_0046F540 __attribute__((section(".data")));
N_00519828 *func_00126150(void);
void func_00126270(s32);
s32 func_L39_00519828(N_00519828 *arg0) {
    N_005197A8 *p;
    if (arg0 == 0) {
        arg0 = func_00126150();
    }
    if (func_L39_00519058() < 0) {
        return -1;
    }
    if ((s32)arg0 == -1) {
        while ((p = D_L39_0046F548) != 0) {
            func_L39_005197A8(p);
        }
    } else {
        for (p = D_L39_0046F548; p != 0; p = p->next) {
            if (arg0 == ((N_00519828 *)p)->key) {
                func_L39_005197A8(p);
                break;
            }
        }
    }
    if (D_L39_0046F544 <= 0) {
        func_00126270(D_L39_0046F540);
        D_L39_0046F540 = -1;
        return 0;
    }
    func_L39_005190C8();
    return 0;
}
/* localdecomp:end func_L39_00519828 */

INCLUDE_ASM("asm/levels", func_L39_00519910);
