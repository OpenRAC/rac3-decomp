#include "common.h"

/* localdecomp:start func_L39_004BCDE0 */
typedef struct S_004BCDE0 {
    u8 _00[0x88];
    long f88;
    long f90;
    u8 _98[8];
    s32 fA0;
} S_004BCDE0;
extern s32 **func_L39_004BD178(S_004BCDE0 *, s32, s32 *);

s32 func_L39_004BCDE0(S_004BCDE0 *self, s32 a1) {
    s32 local[4];
    s32 *p;

    self->fA0 = 0;
    p = *func_L39_004BD178(self, a1, local);
    if (p == 0) {
        self->f90++;
        return 0;
    }
    self->f88++;
    return *p;
}
/* localdecomp:end func_L39_004BCDE0 */

INCLUDE_ASM("asm/levels", func_L39_004BCE38);

/* localdecomp:start func_L39_004BCE40 */
typedef void (*Fn_4BCE40)(void *value, void *context);
typedef struct Node_4BCE40 {
    void *value;
    struct Node_4BCE40 *next;
} Node_4BCE40;
typedef struct {
    Node_4BCE40 **buckets;
    char pad[8];
    int count;
} Tab_4BCE40;

void func_L39_004BCE40(Tab_4BCE40 *tab, Fn_4BCE40 fn, void *ctx) {
    int i;
    Node_4BCE40 *n;
    for (i = tab->count - 1; i >= 0; i--) {
        n = tab->buckets[i];
        while (n != 0) {
            void *v = n->value;
            n = n->next;
            fn(v, ctx);
        }
    }
}
/* localdecomp:end func_L39_004BCE40 */
