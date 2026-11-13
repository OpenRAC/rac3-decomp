#include "common.h"

/* localdecomp:start func_L39_004BCA88 */
/* OpenSSL lh_new, natural form. */
typedef struct {
    void **b;
    s32 (*comp)(void *, void *);
    unsigned long (*hash)(void *);
    unsigned int num_nodes;
    unsigned int num_alloc_nodes;
    unsigned int p;
    unsigned int pmax;
    char _p1C[4];
    unsigned long up_load;
    unsigned long down_load;
    unsigned long num_items;
    unsigned long num_expands;
    unsigned long num_expand_reallocs;
    unsigned long num_contracts;
    unsigned long num_contract_reallocs;
    unsigned long num_hash_calls;
    unsigned long num_comp_calls;
    unsigned long num_insert;
    unsigned long num_replace;
    unsigned long num_delete;
    unsigned long num_no_delete;
    unsigned long num_retrieve;
    unsigned long num_retrieve_miss;
    unsigned long num_hash_comps;
    int error;
} LH_004BCA88;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_1205B0(void *, void *);
extern unsigned long func_L39_004BD280(void *);

LH_004BCA88 *func_L39_004BCA88(unsigned long (*h)(void *), s32 (*c)(void *, void *)) {
    LH_004BCA88 *ret;
    int i;

    ret = func_L39_004BEED8(sizeof(LH_004BCA88));
    if (ret == 0) {
        goto err0;
    }
    ret->b = func_L39_004BEED8(sizeof(void *) * 16);
    if (ret->b == 0) {
        goto err1;
    }
    for (i = 0; i < 16; i++) {
        ret->b[i] = 0;
    }
    ret->comp = (c == 0) ? func_1205B0 : c;
    ret->hash = (h == 0) ? func_L39_004BD280 : h;
    ret->num_nodes = 16 / 2;
    ret->num_alloc_nodes = 16;
    ret->p = 0;
    ret->pmax = 16 / 2;
    ret->up_load = 512;
    ret->down_load = 256;
    ret->num_items = 0;
    ret->num_expands = 0;
    ret->num_expand_reallocs = 0;
    ret->num_contracts = 0;
    ret->num_contract_reallocs = 0;
    ret->num_hash_calls = 0;
    ret->num_comp_calls = 0;
    ret->num_insert = 0;
    ret->num_replace = 0;
    ret->num_delete = 0;
    ret->num_no_delete = 0;
    ret->num_retrieve = 0;
    ret->num_retrieve_miss = 0;
    ret->num_hash_comps = 0;
    ret->error = 0;
    return ret;
err1:
    func_L39_004BEF28(ret);
err0:
    return 0;
}
/* localdecomp:end func_L39_004BCA88 */

INCLUDE_ASM("asm/levels", func_L39_004BCBB0);

/* localdecomp:start func_L39_004BCC38 */
/* OpenSSL lh_insert, natural form (LH_004BCA88 is the file's LHASH). */
typedef struct LN_004BCC38 {
    void *data;
    struct LN_004BCC38 *next;
    unsigned long hash;
} LN_004BCC38;

extern void func_L39_004BCED8(LH_004BCA88 *);
extern LN_004BCC38 **func_L39_004BD178(LH_004BCA88 *, void *, unsigned long *);

void *func_L39_004BCC38(LH_004BCA88 *lh, void *data) {
    unsigned long hash;
    LN_004BCC38 *nn, **rn;
    void *ret;

    lh->error = 0;
    if (lh->up_load <= (lh->num_items * 256 / lh->num_nodes)) {
        func_L39_004BCED8(lh);
    }
    rn = func_L39_004BD178(lh, data, &hash);
    if (*rn == 0) {
        if ((nn = (LN_004BCC38 *)func_L39_004BEED8(sizeof(LN_004BCC38))) == 0) {
            lh->error++;
            return 0;
        }
        nn->data = data;
        nn->next = 0;
        nn->hash = hash;
        *rn = nn;
        ret = 0;
        lh->num_insert++;
        lh->num_items++;
    } else {
        ret = (*rn)->data;
        (*rn)->data = data;
        lh->num_replace++;
    }
    return ret;
}
/* localdecomp:end func_L39_004BCC38 */
