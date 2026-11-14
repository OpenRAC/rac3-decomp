#include "common.h"

/* declared by functions of L39_004D7740.c, which this file was cut from */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_L39_004DBA08(void);

/* localdecomp:start func_L39_004DD858 */
void func_L39_004BC6C8(s32, s32, s32, s32, s32);
void *func_L39_004DBA08(void);
s32 func_L39_004DD858(s32 arg0) {
    s32 (*fn)(s32) = *(s32 (**)(s32))((u8 *)func_L39_004DBA08() + 0x28);
    if (fn == 0) {
        func_L39_004BC6C8(0xA, 0x6B, 0xE, 0, 0);
        return -1;
    }
    return fn(arg0);
}
/* localdecomp:end func_L39_004DD858 */

/* localdecomp:start func_L39_004DD8B0 */
s32 func_L39_004DD8B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*f)(s32, s32, s32, s32) = *(s32 (**)(s32, s32, s32, s32))((char *)func_L39_004DBA08() + 0x2C);

    if (f == 0) {
        func_L39_004BC6C8(0xA, 0x6A, 0xE, 0, 0);
        return -1;
    }
    return f(arg0, arg1, arg2, arg3);
}
/* localdecomp:end func_L39_004DD8B0 */

/* localdecomp:start func_L39_004DD938 */
s32 func_L39_004DD938(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 (*f)(s32, s32, s32, s32, s32, s32) = *(s32 (**)(s32, s32, s32, s32, s32, s32))((char *)func_L39_004DBA08() + 0x30);

    if (f == 0) {
        func_L39_004BC6C8(0xA, 0x69, 0xE, 0, 0);
        return -1;
    }
    return f(arg0, arg1, arg2, arg3, arg4, arg5);
}
/* localdecomp:end func_L39_004DD938 */

/* localdecomp:start func_L39_004DD9E0 */
s32 func_L39_004DD9E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 (*f)(s32, s32, s32, s32, s32, s32) = *(s32 (**)(s32, s32, s32, s32, s32, s32))((char *)func_L39_004DBA08() + 0x34);

    if (f == 0) {
        func_L39_004BC6C8(0xA, 0x6C, 0xE, 0, 0);
        return -1;
    }
    return f(arg0, arg1, arg2, arg3, arg4, arg5);
}
/* localdecomp:end func_L39_004DD9E0 */

/* localdecomp:start func_L39_004DDA88 */
void func_L39_004DDA88(void *arg0) {
    void (*fn)(void *) = *(void (**)(void *))((u8 *)func_L39_004DBA08() + 0x24);
    if (fn == 0) {
        func_L39_004BC6C8(0xA, 0x67, 0xE, 0, 0);
        return;
    }
    fn(arg0);
}
/* localdecomp:end func_L39_004DDA88 */

LINKER_REMNANT("asm/levels", func_L39_004DDAE0);

/* localdecomp:start func_L39_004DDAE8 */
extern s32 func_L39_00504410(void);
extern void func_L39_00504460(s32);
extern void func_L39_00504488(s32);
extern void func_L39_005044B0(s32);
extern void func_L39_005044D8(s32);
extern void func_L39_00504500(s32);
extern s32 func_L39_004DDB78(void *);
extern char *func_L39_004DDB48(char *);
extern void func_L39_004EE670();
extern void func_L39_004EE958();
extern void func_L39_004ED228();

s32 func_L39_004DDAE8(void) {
    func_L39_00504410();
    func_L39_00504460((s32)func_L39_004DDB78);
    func_L39_00504488((s32)func_L39_004EE670);
    func_L39_005044B0((s32)func_L39_004EE958);
    func_L39_005044D8((s32)func_L39_004ED228);
    func_L39_00504500((s32)func_L39_004DDB48);
    return 1;
}
/* localdecomp:end func_L39_004DDAE8 */

/* localdecomp:start func_L39_004DDB48 */
extern s32 func_L39_004DF4A8();
extern char *func_L39_005013E0();
extern char *func_L39_004F9278(s32 (*i2d)(), char *(*d2i)(), char *x);

char *func_L39_004DDB48(char *x) {
    return func_L39_004F9278(func_L39_004DF4A8, func_L39_005013E0, x);
}
/* localdecomp:end func_L39_004DDB48 */

/* localdecomp:start func_L39_004DDB78 */
/* OpenSSL's DSA_size (crypto/dsa/dsa_lib.c) */
typedef struct {
    s32 length;
    s32 type;
    u8 *data;
    long flags;
} ASN1I_004DDB78;

extern s32 func_L39_004FC158(void *);
extern s32 func_L39_004F9340(void *, u8 **);
extern s32 func_L39_004FA1A0(s32 constructed, s32 length, s32 tag);

s32 func_L39_004DDB78(void *r) {
    s32 ret, i;
    ASN1I_004DDB78 bs;
    u8 buf[4];

    i = func_L39_004FC158(((void **)r)[4]);
    bs.length = (i + 7) / 8;
    bs.data = buf;
    bs.type = 2;
    buf[0] = 0xFF;
    i = func_L39_004F9340(&bs, 0);
    i += i;
    ret = func_L39_004FA1A0(1, i, 0x10);
    return ret;
}
/* localdecomp:end func_L39_004DDB78 */

LINKER_REMNANT("asm/levels", func_L39_004DDBE8);

/* localdecomp:start func_L39_004DDBF0 */
extern char D_L39_0046B670[];

void *func_L39_004DDBF0(void) {
    return D_L39_0046B670;
}
/* localdecomp:end func_L39_004DDBF0 */

/* localdecomp:start func_L39_004DDC00 */
/* OpenSSL's des_ede3_init_key (crypto/evp/e_des3.c) */
typedef struct {
    u64 ks[0x180 / 8];
} KS_004DDC00;

typedef struct {
    KS_004DDC00 ks1;
    KS_004DDC00 ks2;
    KS_004DDC00 ks3;
} EDE_004DDC00;

typedef struct {
    void *cipher;
    s32 encrypt;
    s32 buf_len;
    u8 oiv[32];
    u8 iv[32];
    u8 buf[32];
    s32 num;
    void *app_data;
    s32 key_len;
    EDE_004DDC00 *cipher_data;
} CTX_004DDC00;

typedef u8 DESCB_004DDC00[8];

extern void func_L39_004ECE38(void *, void *);

void func_L39_004DDC00(CTX_004DDC00 *ctx, u8 *key, u8 *iv) {
    DESCB_004DDC00 *deskey = (DESCB_004DDC00 *)key;
    EDE_004DDC00 *dat = ctx->cipher_data;

    if (iv != 0) {
        __builtin_memcpy(&ctx->oiv[0], iv, 8);
    }
    __builtin_memcpy(&ctx->iv[0], &ctx->oiv[0], 8);
    if (deskey != 0) {
        func_L39_004ECE38(&deskey[0], &dat->ks1);
        func_L39_004ECE38(&deskey[1], &dat->ks2);
        dat->ks3 = dat->ks1;
    }
}
/* localdecomp:end func_L39_004DDC00 */

INCLUDE_ASM("asm/levels", func_L39_004DDCB8);

INCLUDE_ASM("asm/levels", func_L39_004DDD40);

/* localdecomp:start func_L39_004DDD68 */
extern u8 D_L39_0046B6A0[];

void *func_L39_004DDD68(void) {
    return D_L39_0046B6A0;
}
/* localdecomp:end func_L39_004DDD68 */

INCLUDE_ASM("asm/levels", func_L39_004DDD78);

INCLUDE_ASM("asm/levels", func_L39_004DDDB8);

/* localdecomp:start func_L39_004DDDD8 */
extern char D_L39_0046B6D0[];

void *func_L39_004DDDD8(void) {
    return D_L39_0046B6D0;
}
/* localdecomp:end func_L39_004DDDD8 */

LINKER_REMNANT("asm/levels", func_L39_004DDDE8);

INCLUDE_ASM("asm/levels", func_L39_004DDDF8);

INCLUDE_ASM("asm/levels", func_L39_004DDEC0);

/* localdecomp:start func_L39_004DDEE0 */
extern char D_L39_0046B760[];

void *func_L39_004DDEE0(void) {
    return D_L39_0046B760;
}
/* localdecomp:end func_L39_004DDEE0 */

/* localdecomp:start func_L39_004DDEF0 */
void func_L39_004DDEF0(s32 *arg0) {
    arg0[0x78 / 4] = 0;
    arg0[0x74 / 4] = 0;
}
/* localdecomp:end func_L39_004DDEF0 */

INCLUDE_ASM("asm/levels", func_L39_004DDF00);

INCLUDE_ASM("asm/levels", func_L39_004DDF20);

INCLUDE_ASM("asm/levels", func_L39_004DDF90);

/* localdecomp:start func_L39_004DDFB0 */
extern char D_L39_0046B790[];

void *func_L39_004DDFB0(void) {
    return D_L39_0046B790;
}
/* localdecomp:end func_L39_004DDFB0 */

LINKER_REMNANT("asm/levels", func_L39_004DDFC0);

/* localdecomp:start func_L39_004DDFC8 */
/* OpenSSL's ERR_STATE_free (crypto/err/err.c) with err_clear_data inlined; no NULL check in this build */
typedef struct S_004DDFC8 {
    u64 pid;
    u64 err_buffer[16];
    char *err_data[16];
    s32 err_data_flags[16];
    char *err_file[16];
    s32 err_line[16];
    s32 top;
    s32 bottom;
} S_004DDFC8;

extern void func_L39_004BEF28(void *);

void func_L39_004DDFC8(s32 arg0) {
    S_004DDFC8 *s = (S_004DDFC8 *)arg0;
    s32 i;

    for (i = 0; i < 16; i++) {
        if (s->err_data[i] != 0 && (s->err_data_flags[i] & 1)) {
            func_L39_004BEF28(s->err_data[i]);
            s->err_data[i] = 0;
        }
        s->err_data_flags[i] = 0;
    }
    func_L39_004BEF28(s);
}
/* localdecomp:end func_L39_004DDFC8 */

INCLUDE_ASM("asm/levels", func_L39_004DE050);

/* localdecomp:start func_L39_004DE0C8 */
/* The file declares func_L39_004BC8B0 later as returning S_004DE150 * (the error-stack
   struct of func_L39_004DE150); forward-declare that tag so the two declarations agree. */
struct S_004DE150;
extern struct S_004DE150 *func_L39_004BC8B0(void);

void func_L39_004DE0C8(void) {
    s32 *es = (s32 *)func_L39_004BC8B0();
    es[0x18C / 4] = 0;
    es[0x188 / 4] = 0;
}
/* localdecomp:end func_L39_004DE0C8 */

/* localdecomp:start func_L39_004DE0F0 */
extern u64 func_L39_004DE150(s32 inc, char **file, s32 *line, char **data, s32 *flags);

u64 func_L39_004DE0F0(void) {
    return func_L39_004DE150(1, 0, 0, 0, 0);
}
/* localdecomp:end func_L39_004DE0F0 */

/* localdecomp:start func_L39_004DE120 */
extern u64 func_L39_004DE150(s32 inc, char **file, s32 *line, char **data, s32 *flags);

u64 func_L39_004DE120(void) {
    return func_L39_004DE150(0, 0, 0, 0, 0);
}
/* localdecomp:end func_L39_004DE120 */

/* localdecomp:start func_L39_004DE150 */
typedef struct S_004DE150 {
    u64 pid;
    u64 err_buffer[16];
    char *err_data[16];
    s32 err_data_flags[16];
    char *err_file[16];
    s32 err_line[16];
    s32 top;
    s32 bottom;
} S_004DE150;

extern S_004DE150 *func_L39_004BC8B0(void);
extern char D_L39_004762B0[];
extern char D_L39_004762B8[];

u64 func_L39_004DE150(s32 inc, char **file, s32 *line, char **data, s32 *flags) {
    S_004DE150 *es;
    s32 i;
    u64 ret;

    es = func_L39_004BC8B0();

    if (es->bottom == es->top) {
        return 0;
    }
    i = (es->bottom + 1) % 16;

    ret = es->err_buffer[i];
    if (inc) {
        es->bottom = i;
        es->err_buffer[i] = 0;
    }

    if ((file != 0) && (line != 0)) {
        if (es->err_file[i] == 0) {
            *file = D_L39_004762B0;
            *line = 0;
        } else {
            *file = es->err_file[i];
            *line = es->err_line[i];
        }
    }

    if (data != 0) {
        if (es->err_data[i] == 0) {
            *data = D_L39_004762B8;
            if (flags != 0) {
                *flags = 0;
            }
        } else {
            *data = es->err_data[i];
            if (flags != 0) {
                *flags = es->err_data_flags[i];
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004DE150 */

/* localdecomp:start func_L39_004DE280 */
extern char D_L39_004762C0[];
extern void *func_L39_004DBA08(void);
extern s32 func_L39_004BEDB0(void);
extern s32 func_L39_004BECC0(void);
extern s32 func_L39_004BCD28(s32, void *);
extern void func_L39_004BCBB0(void *);
extern void func_L39_004DDFC8(s32);

typedef struct {
    char _p0[0x8];
    s32 f8;
} S_004DE280;
typedef struct {
    char _p0[0x30];
    long f30;
} S2_004DE280;
typedef struct {
    long f0;
    char _p8[0x188];
} B_004DE280;

void func_L39_004DE280(s32 arg0) {
    B_004DE280 buf;
    S_004DE280 *p = (S_004DE280 *)func_L39_004DBA08();
    s32 r;

    if (p->f8 != 0) {
        if (arg0 == 0) {
            arg0 = func_L39_004BEDB0();
        }
        buf.f0 = arg0;
        ((void (*)(s32, s32, char *, s32))func_L39_004BECC0)(9, 1, D_L39_004762C0, 0x27C);
        r = func_L39_004BCD28(p->f8, &buf);
        if (((S2_004DE280 *)p->f8)->f30 == 0) {
            func_L39_004BCBB0((S2_004DE280 *)p->f8);
            p->f8 = 0;
        }
        ((void (*)(s32, s32, char *, s32))func_L39_004BECC0)(10, 1, D_L39_004762C0, 0x28E);
        if (r != 0) {
            func_L39_004DDFC8(r);
        }
    }
}
/* localdecomp:end func_L39_004DE280 */

/* localdecomp:start func_L39_004DE348 */
/* OpenSSL's ERR_add_error_data (crypto/err/err.c) */
typedef char *va_list_004DE348;
extern void *func_L39_004BEED8(s32);
extern void *func_L39_004BEF00(void *, s32, s32);
extern void func_L39_004BEF28(void *);
extern s32 func_00120884(char *);
extern char *func_001202F4(char *, char *);
extern void func_L39_005049D8(char *, s32);

void func_L39_004DE348(s32 num, ...) {
    va_list_004DE348 args;
    s32 i, n, s;
    char *str, *p, *a;

    s = 64;
    str = func_L39_004BEED8(s + 1);
    if (str == 0) {
        return;
    }
    str[0] = '\0';

    args = (char *)__builtin_next_arg(num)
           - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);

    n = 0;
    for (i = 0; i < num; i++) {
        args += 8;
        a = *(char **)(args - 8);
        if (a != 0) {
            n += func_00120884(a);
            if (n > s) {
                p = func_L39_004BEF00(str, n + 20 + 1, s + 1);
                s = n + 20;
                if (p == 0) {
                    func_L39_004BEF28(str);
                    return;
                }
                str = p;
            }
            func_001202F4(str, a);
        }
    }
    func_L39_005049D8(str, 3);
}
/* localdecomp:end func_L39_004DE348 */

/* localdecomp:start func_L39_004DE458 */
/* OpenSSL's EVP_CIPHER_CTX reset: clears the context and (re)allocates cipher_data */
typedef struct {
    s32 nid;
    s32 block_size;
    s32 key_len;
    s32 iv_len;
    void *init;
    void *do_cipher;
    void *cleanup;
    s32 ctx_size;
} M_004DE458;

typedef struct {
    M_004DE458 *cipher;
    s32 encrypt;
    s32 buf_len;
    u8 oiv[32];
    u8 iv[32];
    u8 buf[32];
    s32 num;
    void *app_data;
    s32 key_len;
    void *cipher_data;
    s32 f7C;
    s32 f80;
    s32 f84;
    s64 f88;
} C_004DE458;

extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *);
extern void *func_L39_004BEED8(s32);

s32 func_L39_004DE458(void *arg0) {
    C_004DE458 *ctx = arg0;

    ctx->encrypt = 1;
    ctx->buf_len = 0;
    func_0011D534(ctx->oiv, 0, 32);
    func_0011D534(ctx->iv, 0, 32);
    func_0011D534(ctx->buf, 0, 32);
    ctx->num = 0;
    if (ctx->cipher != 0 && ctx->key_len != ctx->cipher->ctx_size) {
        if (ctx->cipher_data != 0) {
            func_0011D534(ctx->cipher_data, 0, ctx->key_len);
            func_L39_004BEF28(ctx->cipher_data);
        }
        ctx->cipher_data = func_L39_004BEED8(ctx->cipher->ctx_size);
        if (ctx->cipher_data == 0) {
            func_L39_004BC6C8(6, 0x6C, 0x21, 0, 0);
            return 0;
        }
        ctx->key_len = ctx->cipher->ctx_size;
    }
    if (ctx->cipher_data != 0) {
        func_0011D534(ctx->cipher_data, 0, ctx->key_len);
    }
    ctx->f80 = 0;
    ctx->f88 = 0;
    return 1;
}
/* localdecomp:end func_L39_004DE458 */

/* localdecomp:start func_L39_004DE550 */
extern s32 func_L39_004DE458(void *);
extern void func_L39_004BEF28(void *);
extern void *func_L39_004BEED8(s32);

void *func_L39_004DE550(void) {
    void *p = func_L39_004BEED8(0x90);
    s32 *obj = p;
    if (obj != 0) {
        obj[0] = 0; obj[0x78 / 4] = 0; obj[0x74 / 4] = 0; obj[0x7C / 4] = 0; obj[0x80 / 4] = 0; *(s64 *)&obj[0x88 / 4] = 0;
        if (func_L39_004DE458(obj) != 0) return obj;
    }
    if (p != 0) func_L39_004BEF28(p);
    func_L39_004BC6C8(6, 0x6D, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DE550 */

/* localdecomp:start func_L39_004DE5D0 */
/* OpenSSL's EVP_EncryptInit (crypto/evp/evp_enc.c) */
typedef struct C_004DE5D0 C_004DE5D0;
typedef struct {
    s32 nid;
    s32 block_size;
    s32 key_len;
    s32 iv_len;
    void (*init)(C_004DE5D0 *, u8 *, u8 *, s32);
} M_004DE5D0;
struct C_004DE5D0 {
    M_004DE5D0 *cipher;
    s32 encrypt;
    s32 buf_len;
};

extern s32 func_L39_00504A58(void *, void *);

s32 func_L39_004DE5D0(C_004DE5D0 *ctx, M_004DE5D0 *cipher, u8 *key, u8 *iv) {
    s32 ret;
    s32 enc = 1;
    if (cipher != 0 && func_L39_00504A58(ctx, cipher) == 0) {
        ret = 0;
    } else {
        ctx->cipher->init(ctx, key, iv, enc);
        ret = 1;
        ctx->encrypt = enc;
        ctx->buf_len = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_004DE5D0 */

/* localdecomp:start func_L39_004DE650 */
/* OpenSSL's EVP_DecryptInit (crypto/evp/evp_enc.c) */
typedef struct C_004DE650 C_004DE650;
typedef struct {
    s32 nid;
    s32 block_size;
    s32 key_len;
    s32 iv_len;
    s32 (*init)(C_004DE650 *, u8 *, u8 *, s32);
} M_004DE650;
struct C_004DE650 {
    M_004DE650 *cipher;
    s32 encrypt;
    s32 buf_len;
};

extern s32 func_L39_00504A58(void *, void *);

s32 func_L39_004DE650(C_004DE650 *ctx, M_004DE650 *cipher, u8 *key, u8 *iv) {
    s32 ret;
    if (cipher != 0 && func_L39_00504A58(ctx, cipher) == 0) {
        ret = 0;
    } else {
        ctx->cipher->init(ctx, key, iv, 0);
        ret = 1;
        ctx->encrypt = 0;
        ctx->buf_len = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_004DE650 */

/* localdecomp:start func_L39_004DE6D0 */
extern void *func_0011D380(void *, const void *, unsigned int);

typedef struct S_004DE6D0 S_004DE6D0;
typedef struct {
    s32 f0;
    s32 f4;
    char _p8[0x14 - 0x8];
    void (*f14)(S_004DE6D0 *, s32, u8 *, s32);
} V_004DE6D0;
struct S_004DE6D0 {
    V_004DE6D0 *f0;
    s32 f4;
    s32 f8;
    char _pC[0x4C - 0xC];
    u8 f4C[32];
};

void func_L39_004DE6D0(S_004DE6D0 *self, s32 out, s32 *outLen, u8 *in, s32 len) {
    s32 i, j, bl;

    i = self->f8;
    bl = self->f0->f4;
    *outLen = 0;
    if ((len == 0) && (i != bl)) {
        return;
    }
    if (i != 0) {
        if (i + len < bl) {
            func_0011D380((u8 *)(i + (s32)self) + 0x4C, in, len);
            self->f8 += len;
            return;
        } else {
            j = bl - i;
            if (j != 0) {
                func_0011D380((u8 *)(i + (s32)self) + 0x4C, in, j);
            }
            self->f0->f14(self, out, self->f4C, bl);
            len -= j;
            in += j;
            out += bl;
            *outLen += bl;
        }
    }
    i = len % bl;
    len -= i;
    if (len > 0) {
        self->f0->f14(self, out, in, len);
        *outLen += len;
    }
    if (i != 0) {
        func_0011D380(self->f4C, &(in[len]), i);
    }
    self->f8 = i;
}
/* localdecomp:end func_L39_004DE6D0 */

/* localdecomp:start func_L39_004DE828 */
typedef struct S_004DE828 {
    char _p0[0x78];
    void *f78;
} S_004DE828;

extern void func_L39_004DE868(void *);
extern void func_L39_004BEF28(void *);

void func_L39_004DE828(void *arg0) {
    S_004DE828 *p = arg0;

    func_L39_004DE868(p);
    if (p->f78 != 0) {
        func_L39_004BEF28(p->f78);
    }
    func_L39_004BEF28(p);
}
/* localdecomp:end func_L39_004DE828 */

/* localdecomp:start func_L39_004DE868 */
extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *);

typedef struct S_004DE868 S_004DE868;
typedef struct {
    char _p0[0x18];
    void (*f18)(S_004DE868 *);
} V_004DE868;
struct S_004DE868 {
    V_004DE868 *f0;
    char _p4[0x74 - 0x4];
    s32 f74;
    void *f78;
    char _p7C[0x90 - 0x7C];
};

void func_L39_004DE868(void *p) {
    S_004DE868 *ctx = p;

    if (ctx->f0 != 0 && ctx->f0->f18 != 0) {
        ctx->f0->f18(ctx);
    }
    if (ctx->f78 != 0) {
        func_0011D534(ctx->f78, 0, ctx->f74);
        func_L39_004BEF28(ctx->f78);
        ctx->f78 = 0;
        ctx->f74 = 0;
    }
    func_0011D534(ctx, 0, sizeof(S_004DE868));
}
/* localdecomp:end func_L39_004DE868 */
