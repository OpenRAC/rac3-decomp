#include "common.h"

/* localdecomp:start func_L39_004F1918 */
s32 func_L39_004F1918(void *arg0) {
    return *(*(s32 **)((u8 *)((*(void **)((u8 *)arg0 + 4))) + 0x10));
}
/* localdecomp:end func_L39_004F1918 */

/* localdecomp:start func_L39_004F1928 */
s32 func_L39_004F1928(void *arg0) {
    return (*(s32 **)((u8 *)((*(void **)((u8 *)arg0 + 4))) + 0x10))[1];
}
/* localdecomp:end func_L39_004F1928 */

/* localdecomp:start func_L39_004F1938 */
extern s32 func_L39_004E0C88(u32);
extern s32 func_L39_004E1160(s32);

s32 func_L39_004F1938(void *arg0) {
    return func_L39_004E1160(func_L39_004E0C88(**(u32 **)((u8 *)arg0 + 8)));
}
/* localdecomp:end func_L39_004F1938 */

INCLUDE_ASM("asm/levels", func_L39_004F1960);

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

INCLUDE_ASM("asm/levels", func_L39_004F19E8);

INCLUDE_ASM("asm/levels", func_L39_004F1A90);

INCLUDE_ASM("asm/levels", func_L39_004F1AD0);
