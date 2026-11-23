#include "common.h"

/* localdecomp:start func_L39_004CC440 */
typedef struct { s32 n; void *p; } S_004CC440;
extern void *func_0011D534(void *, s32, u32);

void func_L39_004CC440(S_004CC440 *arg0) {
    if (arg0 != 0 && arg0->n > 0) {
        func_0011D534(arg0->p, 0, arg0->n * 4);
        arg0->n = 0;
    }
}
/* localdecomp:end func_L39_004CC440 */

/* localdecomp:start func_L39_004CC480 */
typedef struct { s32 n; void **p; } S_004CC480;
void func_L39_004CC480(S_004CC480 *a0, void (*fn)(void *)) {
    s32 i;
    if (a0 != 0) {
        for (i = 0; i < a0->n; i++) {
            if (a0->p[i] != 0) {
                fn(a0->p[i]);
            }
        }
        func_L39_004CC440((void *)a0);
    }
}
/* localdecomp:end func_L39_004CC480 */

/* localdecomp:start func_L39_004CC510 */
extern void func_L39_004CC480();
extern void func_L39_004CC538(void *);

void func_L39_004CC510(void *arg0, void (*arg1)(void *)) {
    func_L39_004CC480(arg0, arg1);
    func_L39_004CC538(arg0);
}
/* localdecomp:end func_L39_004CC510 */

/* localdecomp:start func_L39_004CC538 */
typedef struct { void *f0; void *f4; } S_004CC538;
extern void func_L39_004BEF28(void *);

void func_L39_004CC538(void *arg0) {
    S_004CC538 *p = arg0;
    if (p != 0) {
        if (p->f4 != 0) {
            func_L39_004BEF28(p->f4);
        }
        func_L39_004BEF28(p);
    }
}
/* localdecomp:end func_L39_004CC538 */

/* localdecomp:start func_L39_004CC588 */
extern void *func_L39_004CC5B8(void);

void *func_L39_004CC588(s32 id) {
    void *r;
    if (id == 0x301) {
        r = func_L39_004CC5B8();
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_004CC588 */

/* localdecomp:start func_L39_004CC5B8 */
typedef struct {
    s32 version;
    void *ssl_new;
    void *ssl_clear;
    void *ssl_free;
    void *ssl_accept;
    void *ssl_connect;
    void *pad18[13];
    void *get_ssl_method;
    void *pad50[3];
} SSL_METHOD_004CC5B8;

extern s32 D_L39_0046576C __attribute__((section(".data")));
extern SSL_METHOD_004CC5B8 D_L39_00443800;
extern void *func_L39_004CC718(void);
extern s32 func_L39_004C63A8(void *);
extern void *func_L39_004CC588(s32);

/* OpenSSL's TLSv1_client_method */
void *func_L39_004CC5B8(void) {
    if (D_L39_0046576C) {
        D_L39_0046576C = 0;
        D_L39_00443800 = *(SSL_METHOD_004CC5B8 *)func_L39_004CC718();
        D_L39_00443800.ssl_connect = func_L39_004C63A8;
        D_L39_00443800.get_ssl_method = func_L39_004CC588;
    }
    return &D_L39_00443800;
}
/* localdecomp:end func_L39_004CC5B8 */

/* localdecomp:start func_L39_004CC710 */
s32 func_L39_004CC710(void) {
    return 7200;
}
/* localdecomp:end func_L39_004CC710 */

/* localdecomp:start func_L39_004CC718 */
extern char D_L39_004657D0[];

void *func_L39_004CC718(void) {
    return D_L39_004657D0;
}
/* localdecomp:end func_L39_004CC718 */

/* localdecomp:start func_L39_004CC728 */
typedef struct S_004CC728 S_004CC728;
typedef struct { u8 pad[8]; void (*fn)(S_004CC728 *); } V_004CC728;
struct S_004CC728 { u8 pad[8]; V_004CC728 *vt; };
extern s32 func_L39_004C24C8(S_004CC728 *);

s32 func_L39_004CC728(S_004CC728 *arg0) {
    if (func_L39_004C24C8(arg0) == 0) {
        return 0;
    }
    arg0->vt->fn(arg0);
    return 1;
}
/* localdecomp:end func_L39_004CC728 */

/* localdecomp:start func_L39_004CC770 */
extern void func_L39_004C2588(void *);
void func_L39_004CC770(void *a0) { func_L39_004C2588(a0); }
/* localdecomp:end func_L39_004CC770 */

/* localdecomp:start func_L39_004CC778 */
/* OpenSSL t1_lib.c's tls1_clear: ssl3_clear(s), then s->version = TLS1_VERSION */
typedef struct S_004CC778 {
    s32 version;
} S_004CC778;

extern void func_L39_004C2648(S_004CC778 *);

void func_L39_004CC778(S_004CC778 *s) {
    func_L39_004C2648(s);
    s->version = 0x301;
}
/* localdecomp:end func_L39_004CC778 */

/* localdecomp:start func_L39_004CC7A8 */
extern void func_L39_004E4CA8(s32);
extern void func_L01_00415DC8(s32);
extern void func_L01_0047DAD0(s32);
extern void func_L39_004E5250(s32);
extern void func_L39_004E52A0(s32);
extern void func_L39_004E4CB8();
extern void func_L39_004E4D18();
extern void func_L39_004E4DC8();
extern void func_L39_004E4E78();
extern void func_L39_004E4ED8();

s32 func_L39_004CC7A8(void) {
    func_L39_004E4CA8((s32)func_L39_004E4CB8);
    func_L01_00415DC8((s32)func_L39_004E4D18);
    func_L01_0047DAD0((s32)func_L39_004E4DC8);
    func_L39_004E5250((s32)func_L39_004E4E78);
    func_L39_004E52A0((s32)func_L39_004E4ED8);
    return 1;
}
/* localdecomp:end func_L39_004CC7A8 */

/* localdecomp:start func_L39_004CC800 */
typedef struct S_004CC800_inner {
    u8 pad0[0x14];
    s32 field14;
} S_004CC800_inner;

typedef struct S_004CC800 {
    s32 pad0;
    S_004CC800_inner *field4;
} S_004CC800;

s32 func_L39_004CC800(S_004CC800 *arg0) {
    return arg0->field4->field14;
}
/* localdecomp:end func_L39_004CC800 */

/* localdecomp:start func_L39_004CC810 */
typedef struct { s32 num; void **data; } STACK_004CC810;
typedef struct { s32 length; s32 type; u8 *data; } ASN1_STRING_004CC810;
typedef struct { s32 pad0; void *object; ASN1_STRING_004CC810 *value; } NE_004CC810;
typedef struct { s32 pad0; STACK_004CC810 *entries; } NAME_004CC810;
typedef struct { s32 length; char *data; s32 max; } BUF_004CC810;

extern char D_L39_00475F40[];
extern char D_L39_00465830[];
extern void *func_L39_004DB110(void);
extern s32 func_L39_004DB1C0(void *, s32);
extern void func_L39_004DB168(void *);
extern s32 func_L39_004E0C88(void *);
extern char *func_L39_004E0B10(s32);
extern s32 func_L39_004D9CA0(char *, s32, void *);
extern s32 func_00120884(const char *);
extern void *func_0011D380(void *, const void *, unsigned int);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004BEF28(void *);

/* OpenSSL's X509_NAME_oneline */
char *func_L39_004CC810(NAME_004CC810 *a, char *buf, s32 len) {
    NE_004CC810 *ne;
    s32 i;
    s32 n, lold, l, l1, l2, num, j, type;
    char *s;
    char *p;
    u8 *q;
    BUF_004CC810 *b = 0;
    s32 gs_doit[4];
    char tmp_buf[80];

    if (a == 0) {
        return D_L39_00475F40;
    }
    if (buf == 0) {
        if ((b = func_L39_004DB110()) == 0) goto err;
        if (!func_L39_004DB1C0(b, 200)) goto err;
        b->data[0] = '\0';
        len = 200;
    }

    len--;
    l = 0;
    for (i = 0; i < a->entries->num; i++) {
        ne = a->entries->data[i];
        n = func_L39_004E0C88(ne->object);
        if ((n == 0) || ((s = func_L39_004E0B10(n)) == 0)) {
            func_L39_004D9CA0(tmp_buf, sizeof(tmp_buf), ne->object);
            s = tmp_buf;
        }
        l1 = func_00120884(s);

        type = ne->value->type;
        num = ne->value->length;
        q = ne->value->data;

        if ((type == 27) && ((num % 4) == 0)) {
            gs_doit[0] = gs_doit[1] = gs_doit[2] = gs_doit[3] = 0;
            for (j = 0; j < num; j++)
                if (q[j] != 0) gs_doit[j & 3] = 1;

            if (gs_doit[0] | gs_doit[1] | gs_doit[2])
                gs_doit[0] = gs_doit[1] = gs_doit[2] = gs_doit[3] = 1;
            else {
                gs_doit[0] = gs_doit[1] = gs_doit[2] = 0;
                gs_doit[3] = 1;
            }
        } else
            gs_doit[0] = gs_doit[1] = gs_doit[2] = gs_doit[3] = 1;

        for (l2 = j = 0; j < num; j++) {
            if (!gs_doit[j & 3]) continue;
            l2++;
            if ((q[j] < ' ') || (q[j] > '~')) l2 += 3;
        }

        lold = l;
        l += 1 + l1 + 1 + l2;
        if (b != 0) {
            if (!func_L39_004DB1C0(b, l + 1)) goto err;
            p = &(b->data[lold]);
        } else if (l > len) {
            break;
        } else
            p = &(buf[lold]);
        *(p++) = '/';
        func_0011D380(p, s, (unsigned int)l1);
        p += l1;
        *(p++) = '=';

        q = ne->value->data;

        for (j = 0; j < num; j++) {
            if (!gs_doit[j & 3]) continue;
            n = q[j];
            if ((n < ' ') || (n > '~')) {
                *(p++) = '\\';
                *(p++) = 'x';
                *(p++) = D_L39_00465830[(n >> 4) & 0x0f];
                *(p++) = D_L39_00465830[n & 0x0f];
            } else
                *(p++) = n;
        }
        *p = '\0';
    }
    if (b != 0) {
        p = b->data;
        func_L39_004BEF28(b);
    } else
        p = buf;
    return p;
err:
    func_L39_004BC6C8(11, 0xE6, 0x21, 0, 0);
    if (b != 0) func_L39_004DB168(b);
    return 0;
}
/* localdecomp:end func_L39_004CC810 */
