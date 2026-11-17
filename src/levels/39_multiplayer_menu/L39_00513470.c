#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00512A40_Big;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00513808(void *, void *, void *);
extern s32 func_L39_00510F60(void *, void *);

/* localdecomp:start func_L39_00513470 */
typedef struct { s32 cap; s32 n; long *d; } BN_00513470;
/* defined later in this file, on S_00515030 (the same layout) */
extern s32 func_L39_00515030();

extern void func_L39_005128F8(void *);
extern s32 func_L39_00514EB8(s32, void *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00510EF0(void *, void *);
extern s32 func_L39_00512A40(s32, void *);
extern s32 func_L39_00514AA0(void *, void *);
extern s32 func_L39_00511188(long, void *);
extern s32 func_L39_00513AD8(long, void *);
extern s32 func_L39_00513B90(void *, void *, void *, void *);
extern s32 func_L39_00514CF8(s32, void *);
extern void func_L39_00515088(s32, void *);
extern s32 func_L39_00511480(s32, void *);
extern s32 func_L39_005151E8(void *, s32 *);

s32 func_L39_00513470(BN_00513470 *a, BN_00513470 *b, BN_00513470 *q, BN_00513470 *r) {
    BN_00513470 t;
    BN_00513470 u;
    s32 shift;
    s32 err;
    s32 na;
    s32 nb;
    s32 i;

    func_L39_005128E8((s32 *)&t);
    func_L39_005128E8((s32 *)&u);
    do {
        if (q->cap <= 0) {
            if ((err = func_L39_00512A40(2, q)) != 0) break;
        }
        *q->d = 0;
        q->n = 1;
        if (func_L39_00510F60(a, b) < 0) {
            err = func_L39_00510EF0(a, r);
            break;
        }
        if ((err = func_L39_005151E8(b, &shift)) != 0) break;
        err = 0x106;
        if (shift == 0x40) break;
        if (shift > 0) {
            if ((err = func_L39_00514EB8(shift, b)) != 0) break;
            if ((err = func_L39_00514EB8(shift, a)) != 0) break;
        }
        na = a->n;
        nb = b->n;
        if ((err = func_L39_00510EF0(a, r)) != 0) break;
        if (nb < na) {
            if ((err = func_L39_00515030(na - nb, r)) != 0) break;
        } else {
            *q->d = 1;
            q->n = 1;
            if ((err = func_L39_00514AA0(b, r)) != 0) break;
        }
        if ((err = func_L39_00512A40(na, &u)) != 0) break;
        if ((err = func_L39_00512A40(2, &t)) != 0) break;
        for (i = na - nb - 1; i >= 0; i--) {
            if (func_L39_00510F60(r, b) >= 0) {
                if ((err = func_L39_00514AA0(b, r)) != 0) break;
                if ((err = func_L39_00511188(1, q)) != 0) break;
            }
            if ((err = func_L39_00513AD8(a->d[i], r)) != 0) break;
            if ((err = func_L39_00514CF8(1, q)) != 0) break;
            if (nb < r->n) {
                if ((err = func_L39_00513B90(r, b, &t, &u)) != 0) break;
                while (func_L39_00510F60(&u, r) > 0) {
                    if ((err = func_L39_00511480(1, &t)) != 0) break;
                    if ((err = func_L39_00514AA0(b, &u)) != 0) break;
                }
                if (err != 0) break;
                if ((err = func_L39_00511188(*t.d, q)) != 0) break;
                if ((err = func_L39_00514AA0(&u, r)) != 0) break;
            }
        }
        if (err != 0) break;
        if (shift > 0) {
            func_L39_00515088(shift, r);
            func_L39_00515088(shift, a);
            func_L39_00515088(shift, b);
        }
        if (func_L39_00510F60(r, b) < 0) break;
        if ((err = func_L39_00514AA0(b, r)) != 0) break;
        err = func_L39_00511188(1, q);
    } while (0);
    func_L39_005128F8(&t);
    func_L39_005128F8(&u);
    return err;
}
/* localdecomp:end func_L39_00513470 */

INCLUDE_ASM("asm/levels", func_L39_00513808);

INCLUDE_ASM("asm/levels", func_L39_00513AD8);

INCLUDE_ASM("asm/levels", func_L39_00513B90);
