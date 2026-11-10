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

INCLUDE_ASM("asm/levels", func_L39_00519600);

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

INCLUDE_ASM("asm/levels", func_L39_00519828);

INCLUDE_ASM("asm/levels", func_L39_00519910);
