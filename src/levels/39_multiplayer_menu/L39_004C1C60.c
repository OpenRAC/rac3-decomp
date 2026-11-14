#include "common.h"

/* localdecomp:start func_L39_004C1C60 */
/* OpenSSL ssl2_new (s2_lib.c), without the record buffers */
extern void *func_L39_004BEED8(s32);
extern void *func_11D534(void *, s32, s32);
extern void func_L39_004C1D38(void *);

typedef struct {
    u8 _p0[0x30];
    void *f30;
    void *f34;
} I_004C1C60;

typedef struct {
    u8 _p0[0x50];
    I_004C1C60 *f50;
} S_004C1C60;

s32 func_L39_004C1C60(S_004C1C60 *a0) {
    I_004C1C60 *p = func_L39_004BEED8(0x130);
    if (p != 0) {
        func_11D534(p, 0, 0x130);
        p->f30 = 0;
        p->f34 = 0;
        a0->f50 = p;
        func_L39_004C1D38(a0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004C1C60 */

/* localdecomp:start func_L39_004C1CC8 */
/* OpenSSL ssl2_free (s2_lib.c) */
extern void func_L39_004BEF28(void *);
extern void *func_11D534(void *, s32, s32);

typedef struct {
    u8 _p0[0x30];
    void *f30;
    void *f34;
} I_004C1CC8;

typedef struct {
    u8 _p0[0x50];
    I_004C1CC8 *f50;
} S_004C1CC8;

void func_L39_004C1CC8(S_004C1CC8 *a0) {
    I_004C1CC8 *p = a0->f50;
    if (p->f30 != 0) {
        func_L39_004BEF28(p->f30);
    }
    if (p->f34 != 0) {
        func_L39_004BEF28(p->f34);
    }
    func_11D534(p, 0, 0x130);
    func_L39_004BEF28(p);
    a0->f50 = 0;
}
/* localdecomp:end func_L39_004C1CC8 */

/* localdecomp:start func_L39_004C1D38 */
/* OpenSSL ssl2_clear (s2_lib.c) */
extern void *func_11D534(void *, s32, s32);

typedef struct {
    s32 two_byte_header;
    s32 clear_text;
    u8 _p8[0x28];
    u8 *rbuf;
    u8 *wbuf;
    u8 _p38[0x10];
    s32 f48;
    u8 _p4C[0x130 - 0x4C];
} S2_004C1D38;

typedef struct {
    s32 version;
    u8 _p4[0x44];
    u8 *packet;
    u32 packet_length;
    S2_004C1D38 *s2;
} SSL_004C1D38;

void func_L39_004C1D38(void *arg) {
    SSL_004C1D38 *s = arg;
    S2_004C1D38 *s2;
    u8 *rbuf, *wbuf;

    s2 = s->s2;

    rbuf = s2->rbuf;
    wbuf = s2->wbuf;

    func_11D534(s2, 0, sizeof(*s2));

    s2->rbuf = rbuf;
    s2->wbuf = wbuf;
    s2->clear_text = 1;
    s->packet = s2->rbuf;
    s->version = 2;
    s->packet_length = 0;
    s->s2->f48 = 0;
}
/* localdecomp:end func_L39_004C1D38 */
