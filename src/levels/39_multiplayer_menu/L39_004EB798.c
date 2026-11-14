#include "common.h"

/* localdecomp:start func_L39_004EB798 */
typedef struct {
    s32 type;
} PKEY_004EB798;

extern PKEY_004EB798 *func_L39_004BBDE0(void *);
extern s32 func_L39_004BBD08(void *);

/* OpenSSL's ssl_cert_type(X509 *x, EVP_PKEY *pkey) */
s32 func_L39_004EB798(void *x, PKEY_004EB798 *pkey) {
    PKEY_004EB798 *pk;
    s32 ret = -1;
    s32 i, j;

    if (pkey == 0) {
        pk = func_L39_004BBDE0(x);
    } else {
        pk = pkey;
    }
    if (pk != 0) {
        i = pk->type;
        if (i == 6) {
            ret = 0;
        } else if (i == 0x74) {
            ret = 2;
        } else if (i == 0x1C) {
            if (x == 0) {
                ret = 4;
            } else {
                j = func_L39_004BBD08(x);
                if (j == 6) {
                    ret = 3;
                } else if (j == 0x74) {
                    ret = 4;
                } else {
                    ret = -1;
                }
            }
        } else {
            ret = -1;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004EB798 */
