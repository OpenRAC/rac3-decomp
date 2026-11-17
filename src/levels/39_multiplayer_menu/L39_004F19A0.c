#include "common.h"

/* localdecomp:start func_L39_004F19A0 */
/* OpenSSL 0.9.6 x509_object_cmp (x509_lu.c); the lhash comparator func_L39_004F19E8 passes to lh_new */
typedef struct {
    s32 type;
    union {
        char *ptr;
        void *x509;
    } data;
} OBJ_004F19A0;

extern s32 func_L39_004F1678(void *, void *);

s32 func_L39_004F19A0(void *va, void *vb) {
    OBJ_004F19A0 *a = va;
    OBJ_004F19A0 *b = vb;
    s32 ret;

    ret = a->type - b->type;
    if (ret) {
        return ret;
    }
    switch (a->type) {
    case 1:
        ret = func_L39_004F1678(a->data.x509, b->data.x509);
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004F19A0 */
