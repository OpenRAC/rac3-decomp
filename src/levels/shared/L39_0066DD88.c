#include "common.h"

/* localdecomp:start func_L39_0066DD88 */
s32 func_L39_0066DD88(u8 *a0, s32 a1) {
    return *(s32 *)(a0 + 0x28) == a1;
}
/* localdecomp:end func_L39_0066DD88 */

/* localdecomp:start func_L39_0066DD98 */
void func_L39_0066DD98(void) {

}
/* localdecomp:end func_L39_0066DD98 */

/* localdecomp:start func_L39_0066DDA0 */
void func_L39_0066DDA0(void) {

}
/* localdecomp:end func_L39_0066DDA0 */

/* localdecomp:start func_L39_0066DDA8 */
typedef void (*F_66B4A0)(s32, s32);

typedef struct {
    u8 pad0[0xC];
    F_66B4A0 fnC;
} S_66B4A0c;

typedef struct {
    u8 pad0[0x18];
    s32 w18;
} S_66B4A0b;

typedef struct {
    s32 w0;
    u8 pad4[0x10 - 0x4];
    s32 w10;
    F_66B4A0 fn14;
    s32 w18;
} S_66B4A0;

extern S_66B4A0b *func_L39_0061D1D8(s32 a0);
extern S_66B4A0c *func_L39_005C1018(s32 a0);

void func_L39_0066DDA8(S_66B4A0 *a0) {
    S_66B4A0c *r;
    a0->w10 = func_L39_0061D1D8(a0->w0)->w18;
    r = func_L39_005C1018(a0->w10);
    if (r != 0) {
        a0->fn14 = r->fnC;
        a0->fn14(a0->w10, 1);
    } else {
        a0->fn14 = 0;
    }
    a0->w18 = 0;
}
/* localdecomp:end func_L39_0066DDA8 */

INCLUDE_ASM("asm/levels", func_L39_0066DE08);

INCLUDE_ASM("asm/levels", func_L39_0066DEB0);

/* localdecomp:start func_L39_0066DF40 */
typedef struct Node0066B638 {
    u8 pad[32];
    struct Node0066B638 *prev;
    struct Node0066B638 *next;
} Node0066B638;

extern Node0066B638 *D_L39_0024CF78;
extern Node0066B638 *D_L39_0024CF7C;
extern Node0066B638 *D_L39_0024CF7C_b;

Node0066B638 *func_L39_0066DF40(void) {
    Node0066B638 *n = D_L39_0024CF78;
    Node0066B638 *h;
    if (n != 0 && n->next != 0) {
        D_L39_0024CF78 = n->next;
        h = D_L39_0024CF7C;
        n->next->prev = 0;
        n->prev = 0;
        n->next = h;
        if (h != 0) {
            h->prev = n;
        }
        D_L39_0024CF7C_b = n;
        return n;
    }
    return 0;
}
/* localdecomp:end func_L39_0066DF40 */

/* localdecomp:start func_L39_0066DF98 */
extern Node0066B638 *D_L39_0024CF78_b;

typedef struct S_0066DF98 {
    u8 pad0[0x20];
    struct S_0066DF98 *prev;
    struct S_0066DF98 *next;
    s32 w28;
    s32 w2C;
    s32 w30;
} S_0066DF98;

S_0066DF98 *func_L39_0066DF98(S_0066DF98 *n) {
    S_0066DF98 *r = n->next;
    if (n->w28 != 0) {
        n->w28 = 0;
    }
    n->w2C = 0;
    n->w30 = 0;
    if (n->prev != 0) {
        n->prev->next = n->next;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    if ((S_0066DF98 *)D_L39_0024CF7C_b == n) {
        D_L39_0024CF7C = (Node0066B638 *)n->next;
    }
    {
        S_0066DF98 *h = (S_0066DF98 *)D_L39_0024CF78_b;
        h->prev = n;
        n->next = h;
        n->prev = 0;
        D_L39_0024CF78_b = (Node0066B638 *)n;
    }
    return r;
}
/* localdecomp:end func_L39_0066DF98 */

INCLUDE_ASM("asm/levels", func_L39_0066E010);

INCLUDE_ASM("asm/levels", func_L39_0066E100);

/* localdecomp:start func_L39_0066E338 */
extern Node0066B638 *D_L39_0024CF7C;
typedef struct S_0066BA18 { u8 pad[36]; struct S_0066BA18 *next; u8 pad2[48]; s32 id; } S_0066BA18;

S_0066BA18 *func_L39_0066E338(s32 id) {
    S_0066BA18 *p = ((S_0066BA18 * *)&D_L39_0024CF7C)[0];
    while (p != 0) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return 0;
}
/* localdecomp:end func_L39_0066E338 */
