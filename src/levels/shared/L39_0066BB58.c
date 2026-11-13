#include "common.h"

/* localdecomp:start func_L39_0066BB58 */
typedef struct N_0066BB58 N_0066BB58;
struct N_0066BB58 {
    s32 pad0[2];
    s32 f8;
    s32 fC;
    u8 pad10[0x74];
    N_0066BB58 *f84;
};
extern N_0066BB58 *D_L39_0024CF64;
extern void func_L39_0066C3C8(N_0066BB58 *, N_0066BB58 **);
void func_L39_0066BB58(s32 id) {
    N_0066BB58 *p = D_L39_0024CF64;
    while (p != 0) {
        s32 *q = &p->f8;
        if (*q == 0 && q[1] == id) {
            func_L39_0066C3C8(p, &D_L39_0024CF64);
            return;
        }
        p = p->f84;
    }
}
/* localdecomp:end func_L39_0066BB58 */

/* localdecomp:start func_L39_0066BBB8 */
typedef struct N_0066BBB8 {
    s32 w0;
    s32 w4;
    s32 type;
    s32 wC;
    s32 time;
    s32 n;
    s32 data[(0x84 - 0x18) / 4];
    struct N_0066BBB8 *next;
} N_0066BBB8;
typedef struct { s32 id; s32 a; s32 data[10]; } E_0066BBB8;
typedef struct { s32 id; s32 w4; s32 w8; s32 (*fn)(s32, s32, N_0066BBB8 *); } H_0066BBB8;
typedef struct { u8 pad[0x128]; s32 w128; } G_0066BBB8;
extern E_0066BBB8 D_L39_0033B990[];
extern H_0066BBB8 D_L39_0033B8F0[];
extern G_0066BBB8 D_001A5CD0;
extern struct N_0066BB58 *D_L39_0024CF64;
extern void func_L39_0066C3C8(struct N_0066BB58 *, struct N_0066BB58 **);
extern s32 func_L39_0066C428(s32);
extern s32 func_L39_0066C038(void);
void func_L39_0066BBB8(void) {
    N_0066BBB8 *p;
    s32 *q;
    s32 *src;
    s32 i;
    s32 j;
    s32 idx;
    for (p = (N_0066BBB8 *)D_L39_0024CF64; p != 0; ) {
        q = &p->type;
        switch (p->type) {
        default:
            p = p->next;
            continue;
        case 0:
            if (q[2] > D_001A5CD0.w128) {
                p = p->next;
                continue;
            }
            idx = func_L39_0066C428(q[3]);
            if (idx < 0) {
                continue;
            }
            (*D_L39_0033B8F0[idx].fn)(q[1], q[3], p);
            break;
        case 3:
            if (q[2] > D_001A5CD0.w128) {
                p = p->next;
                continue;
            }
            for (i = 0; i < 40; i++) {
                if (D_L39_0033B990[i].id == 0) {
                    break;
                }
            }
            if (i == 40) {
                i = func_L39_0066C038();
                if (i == -1) {
                    return;
                }
            }
            src = &q[4];
            D_L39_0033B990[i].id = q[1];
            D_L39_0033B990[i].a = q[3];
            for (j = 0; j < q[3]; j++) {
                D_L39_0033B990[i].data[j] = *src++;
            }
            break;
        }
        p = ((N_0066BBB8 *(*)(N_0066BBB8 *, void *))func_L39_0066C3C8)(p, &D_L39_0024CF64);
    }
}
/* localdecomp:end func_L39_0066BBB8 */

/* localdecomp:start func_L39_0066BD80 */
extern u8 D_1A5CD0[];
extern s32 *D_L39_0024CF6C;
extern s32 *D_L39_0024CF6C_b;
extern s32 func_14AD08();
extern void func_L39_0066C110(s32, s32, s32, s32 *);
extern s32 *func_L39_0066C310(s32 *);

void func_L39_0066BD80(s32 n) {
    u8 *b;
    s32 *q;
    s32 i;

    q = D_L39_0024CF6C;
    i = 0;
    if (q != 0) {
        b = D_1A5CD0;
        do {
            if (*(s32 *)(b + 0x170) == 0) {
                func_14AD08(b[0x7D4] | 0x50, *(s32 *)(b + 4), -1, *(s32 *)0x2405C4, q[0], q);
            }
            func_L39_0066C110(0, 0, 0, q);
            i++;
            q = func_L39_0066C310(q);
            if (i >= n) {
                D_L39_0024CF6C_b = q;
                break;
            }
        } while (q != 0);
    }
}
/* localdecomp:end func_L39_0066BD80 */

INCLUDE_ASM("asm/levels", func_L39_0066BE40);
