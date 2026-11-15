#include "common.h"

/* localdecomp:start func_L39_004C3D60 */
/* OpenSSL's SSL_write: shutdown & SSL_SENT_SHUTDOWN -> rwstate = SSL_NOTHING, SSLerr, method->ssl_write */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
typedef struct S_004C3D60 S_004C3D60;
typedef struct V_004C3D60 {
    char _p0[0x20];
    s32 (*ssl_write)(S_004C3D60 *s, const void *buf, s32 num);
} V_004C3D60;
struct S_004C3D60 {
    char _p0[0x8];
    V_004C3D60 *method;
    char _pC[0x18 - 0xC];
    s32 rwstate;
    char _p1C[0x2C - 0x1C];
    s32 shutdown;
};

s32 func_L39_004C3D60(S_004C3D60 *s, const void *buf, s32 num) {
    if (s->shutdown & 1) {
        s->rwstate = 1;
        func_L39_004BC6C8(0x14, 0xD1, 0xCF, 0, 0);
        return -1;
    }
    return s->method->ssl_write(s, buf, num);
}
/* localdecomp:end func_L39_004C3D60 */

/* localdecomp:start func_L39_004C3DC0 */
/* OpenSSL's SSL_shutdown (with an extra options bit 0x40000 that allows it during the handshake) */
typedef struct S_004C3DC0 S_004C3DC0;
typedef struct V_004C3DC0 {
    char _p0[0x24];
    s32 (*ssl_shutdown)(S_004C3DC0 *s);
} V_004C3DC0;
struct S_004C3DC0 {
    char _p0[0x8];
    V_004C3DC0 *method;
    char _pC[0x100 - 0xC];
    unsigned long options;
};
extern s32 func_L39_004C4EE0(S_004C3DC0 *);

s32 func_L39_004C3DC0(S_004C3DC0 *s) {
    if (s != 0 && (!(func_L39_004C4EE0(s) & 0x3000) || (s->options & 0x40000))) {
        return s->method->ssl_shutdown(s);
    }
    return 1;
}
/* localdecomp:end func_L39_004C3DC0 */
