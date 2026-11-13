#include "common.h"

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
