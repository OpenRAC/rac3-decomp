#include "common.h"

/* localdecomp:start func_L39_004C1EE0 */
/* OpenSSL 0.9.6 ssl2_put_cipher_by_char (s2_lib.c) */
typedef struct {
    s32 valid;
    const char *name;
    long id;
} CIPHER_004C1EE0;

s32 func_L39_004C1EE0(CIPHER_004C1EE0 *c, u8 *p) {
    long l;

    if (p != 0) {
        l = c->id;
        if ((l & 0xff000000) != 0x02000000) return 0;
        p[0] = ((u8)(l >> 16L)) & 0xFF;
        p[1] = ((u8)(l >> 8L)) & 0xFF;
        p[2] = ((u8)(l)) & 0xFF;
    }
    return 3;
}
/* localdecomp:end func_L39_004C1EE0 */

/* localdecomp:start func_L39_004C1F30 */
s32 func_L39_004C1F30(s32 *arg0) {
    arg0[11] = 3;
    return 1;
}
/* localdecomp:end func_L39_004C1F30 */
