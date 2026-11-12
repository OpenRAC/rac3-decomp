#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0066C038);

INCLUDE_ASM("asm/levels", func_L39_0066C110);

/* localdecomp:start func_L39_0066C1F0 */
typedef struct {
    u8 pad[0];
    s32 id;
    u8 pad2[45];
    u8 active;
    u8 pad3[18];
} Ent_006698E8;

extern Ent_006698E8 D_L39_0033ABA0[50];

Ent_006698E8 *func_L39_0066C1F0(s32 id) {
    Ent_006698E8 *p;

    p = D_L39_0033ABA0;
    do {
        if (p->active == 1 && p->id == id) {
            return p;
        }
        p++;
    } while ((s32)p < (s32)&D_L39_0033ABA0[50]);
    return 0;
}
/* localdecomp:end func_L39_0066C1F0 */

/* localdecomp:start func_L39_0066C238 */
extern Ent_006698E8 D_L39_0033ABA0[50];
typedef struct {
    u8 pad[28];
    s32 id;
    u8 pad2[17];
    u8 active;
    u8 pad3[18];
} Ent_00669930;


Ent_00669930 *func_L39_0066C238(s32 id) {
    Ent_00669930 *p;

    p = ((Ent_00669930 *)&D_L39_0033ABA0);
    do {
        if (p->active == 1 && p->id == id) {
            return p;
        }
        p++;
    } while ((s32)p < (s32)&((Ent_00669930 *)&D_L39_0033ABA0)[50]);
    return 0;
}
/* localdecomp:end func_L39_0066C238 */

/* localdecomp:start func_L39_0066C280 */
extern int D_001A5CD8[];
int func_L39_0066C280(int a0, int a1, int a2, int a3, int *p)
{
    int *q;
    if (p == 0) {
        return -1;
    }
    q = p + 2;
    p[1] = D_001A5CD8[0];
    p[2] = a0;
    q[1] = a1;
    q[3] = a3;
    q[2] = a2;
    return 0x18;
}
/* localdecomp:end func_L39_0066C280 */

/* localdecomp:start func_L39_0066C2B8 */
typedef struct Node006699B0 {
    u8 pad[128];
    struct Node006699B0 *prev;
    struct Node006699B0 *next;
} Node006699B0;

extern Node006699B0 *D_L39_0024CF68;
extern Node006699B0 *D_L39_0024CF6C;
extern Node006699B0 *D_L39_0024CF6C_b;

Node006699B0 *func_L39_0066C2B8(void) {
    Node006699B0 *n = D_L39_0024CF68;
    Node006699B0 *h;
    if (n != 0 && n->next != 0) {
        D_L39_0024CF68 = n->next;
        h = D_L39_0024CF6C;
        n->next->prev = 0;
        n->prev = 0;
        n->next = h;
        if (h != 0) {
            h->prev = n;
        }
        D_L39_0024CF6C_b = n;
        return n;
    }
    return 0;
}
/* localdecomp:end func_L39_0066C2B8 */

INCLUDE_ASM("asm/levels", func_L39_0066C310);

/* localdecomp:start func_L39_0066C370 */
typedef struct Node00669A68 {
    u8 pad[128];
    struct Node00669A68 *prev;
    struct Node00669A68 *next;
} Node00669A68;

extern Node00669A68 *D_L39_0024CF60;

Node00669A68 *func_L39_0066C370(Node00669A68 **head) {
    Node00669A68 *n = D_L39_0024CF60;
    if (n != 0 && n->next != 0) {
        D_L39_0024CF60 = n->next;
        n->next->prev = 0;
        n->prev = 0;
        n->next = *head;
        if (*head != 0) {
            (*head)->prev = n;
        }
        *head = n;
        return n;
    }
    return 0;
}
/* localdecomp:end func_L39_0066C370 */

/* localdecomp:start func_L39_0066C3C8 */
Node00669A68 *func_L39_0066C3C8(Node00669A68 *n, Node00669A68 **head)
{
    Node00669A68 *next = n->next;

    if (n->prev != 0) {
        n->prev->next = next;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    if (*head == n) {
        *head = n->next;
    }
    D_L39_0024CF60->prev = n;
    n->next = D_L39_0024CF60;
    n->prev = 0;
    D_L39_0024CF60 = n;
    return next;
}
/* localdecomp:end func_L39_0066C3C8 */

/* localdecomp:start func_L39_0066C420 */
void func_L39_0066C420(void) {

}
/* localdecomp:end func_L39_0066C420 */

/* localdecomp:start func_L39_0066C428 */
typedef struct { s32 id; u8 pad[12]; } S_00669B20;
extern S_00669B20 D_L39_0033B8F0[];

s32 func_L39_0066C428(s32 id) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (D_L39_0033B8F0[i].id == id) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_0066C428 */
