#include "common.h"

/* localdecomp:start func_L39_004F1800 */
/* Matches only with ee29check.sh (@ee29 -O2 -G8: 16-byte register save slots, frame 0x170). Log: first draft (buf = tmpbuf; if (i > 256) buf = malloc) 43 diff; if/else form matched. OpenSSL X509_NAME_hash-like (i2d, md5, little-endian first 4 bytes). */
extern s32 func_L39_004FA5B0(void *, void *);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_005051F0(void *, s32, void *);

unsigned long func_L39_004F1800(void *arg0) {
    u8 md[16];
    u8 tmpbuf[256];
    u8 *p;
    u8 *buf;
    s32 i;

    i = func_L39_004FA5B0(arg0, 0);
    if (i > 256) {
        buf = func_L39_004BEED8(i);
    } else {
        buf = tmpbuf;
    }
    p = buf;
    func_L39_004FA5B0(arg0, &p);
    func_L39_005051F0(buf, i, md);
    if (buf != tmpbuf) {
        func_L39_004BEF28(buf);
    }
    return ((unsigned long)md[0]) | ((unsigned long)md[1] << 8) | ((unsigned long)md[2] << 16) | ((unsigned long)md[3] << 24);
}
/* localdecomp:end func_L39_004F1800 */

/* localdecomp:start func_L39_004F18C0 */
extern s32 func_L39_004F3CA8(s32);

typedef struct S_004F18C0 { s32 f0; s32 *f4; } S_004F18C0;

s32 func_L39_004F18C0(S_004F18C0 *p) {
    if (p == 0 || p->f4 == 0) {
        return 0;
    }
    return func_L39_004F3CA8(p->f4[6]);
}
/* localdecomp:end func_L39_004F18C0 */

/* localdecomp:start func_L39_004F18F8 */
extern s32 func_L39_004F9728(s32);

s32 func_L39_004F18F8(s32 **p) {
    return func_L39_004F9728(*p[1]);
}
/* localdecomp:end func_L39_004F18F8 */
