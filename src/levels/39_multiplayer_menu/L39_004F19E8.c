#include "common.h"

/* localdecomp:start func_L39_004F19E8 */
/* OpenSSL 0.9.6 X509_STORE_new (x509_lu.c) */
typedef struct {
    s32 cache;
    void *certs;
    void *get_cert_methods;
    void *verify;
    void *verify_cb;
    struct { void *sk; s32 dummy; } ex_data;
    s32 references;
    s32 depth;
} STORE_004F19E8;

extern void *func_L39_004BEED8(s32);
extern void *func_L39_004BCA88(void *, void *);
extern void *func_L39_004CC228(void *);
extern void *func_0011D534(void *, s32, u32);
extern void func_L39_004DEF48(void *, void *, void *);
extern s32 func_L39_004F1960(void *);
extern s32 func_L39_004F19A0(void *, void *);
extern void *D_L39_0046D4FC __attribute__((section(".data")));

STORE_004F19E8 *func_L39_004F19E8(void) {
    STORE_004F19E8 *ret;

    if ((ret = func_L39_004BEED8(sizeof(STORE_004F19E8))) == 0) {
        return 0;
    }
    ret->certs = func_L39_004BCA88(func_L39_004F1960, func_L39_004F19A0);
    ret->cache = 1;
    ret->get_cert_methods = func_L39_004CC228(0);
    ret->verify = 0;
    ret->verify_cb = 0;
    func_0011D534(&ret->ex_data, 0, sizeof(ret->ex_data));
    ret->references = 1;
    func_L39_004DEF48(D_L39_0046D4FC, ret, &ret->ex_data);
    return ret;
}
/* localdecomp:end func_L39_004F19E8 */

INCLUDE_ASM("asm/levels", func_L39_004F1A90);

INCLUDE_ASM("asm/levels", func_L39_004F1AD0);
