#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EB8B0 */
/* OpenSSL's ssl3_generate_key_block (s3_enc.c), EVP contexts made with EVP_MD_CTX_create */
typedef struct {
    u8 pad0[0x10];
    s32 master_key_length;
    u8 master_key[0x30];
} S_SESS_004EB8B0;
typedef struct {
    u8 pad0[0x44];
    u8 server_random[0x20];
    u8 client_random[0x20];
} S_S3_004EB8B0;
typedef struct {
    u8 pad0[0x54];
    S_S3_004EB8B0 *s3;
    u8 pad58[0xB0 - 0x58];
    S_SESS_004EB8B0 *session;
} S_SSL_004EB8B0;

extern void *func_L39_004DE940(void);
extern void *func_L39_004DF698(void);
extern void *func_L39_004DF6A8(void);
extern s32 func_L39_004DD690(void *, void *);
extern s32 func_L39_004DE8E8(void *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, void *, u32 *);
extern void func_L39_004DE9B8(void *);
extern void *func_11D380(void *, const void *, u32);
extern void *func_11D534(void *, s32, u32);

void func_L39_004EB8B0(S_SSL_004EB8B0 *s, u8 *km, s32 num)
{
    void *m5;
    void *s1;
    u8 buf[16];
    u8 smd[32];
    u32 len;
    u8 c = 'A';
    s32 i, j, k;
    s32 md5_size, sha_size;

    k = 0;
    m5 = func_L39_004DE940();
    s1 = func_L39_004DE940();
    func_L39_004DD690(m5, func_L39_004DF698());
    func_L39_004DD690(s1, func_L39_004DF6A8());
    md5_size = func_L39_004DE8E8(m5);
    sha_size = func_L39_004DE8E8(s1);
    for (i = 0; i < num; i += md5_size) {
        k++;
        for (j = 0; j < k; j++)
            buf[j] = c;
        c++;
        func_L39_004DD690(s1, 0);
        func_L39_004DD778(s1, buf, k);
        func_L39_004DD778(s1, s->session->master_key, s->session->master_key_length);
        func_L39_004DD778(s1, s->s3->server_random, 32);
        func_L39_004DD778(s1, s->s3->client_random, 32);
        func_L39_004DD7A8(s1, smd, &len);

        func_L39_004DD690(m5, 0);
        func_L39_004DD778(m5, s->session->master_key, s->session->master_key_length);
        func_L39_004DD778(m5, smd, sha_size);
        if (i + md5_size > num) {
            func_L39_004DD7A8(m5, smd, &len);
            func_11D380(km, smd, num - i);
        } else {
            func_L39_004DD7A8(m5, km, &len);
        }
        km += md5_size;
    }
    func_11D534(smd, 0, sha_size);
    func_L39_004DE9B8(m5);
    func_L39_004DE9B8(s1);
}
/* localdecomp:end func_L39_004EB8B0 */

/* localdecomp:start func_L39_004EBB10 */
/* OpenSSL 0.9.x tls1_change_cipher_state (t1_enc.c) */
typedef struct X_004EBB10 { s32 mac_size; void *md_ctx; void *cipher_ctx; } X_004EBB10;
typedef struct C_004EBB10 { char pad[0x10]; unsigned long algorithms; unsigned long algo_strength; } C_004EBB10;
typedef struct S3_004EBB10 {
    char pad0[0xC]; u8 read_sequence[8];
    u8 read_mac_secret[0x14];
    u8 write_sequence[8];
    u8 write_mac_secret[0x14];
    u8 server_random[0x20];
    u8 client_random[0x20];
    char pad1[0x15C - 0x84]; C_004EBB10 *new_cipher;
    char pad2[0x184 - 0x160]; s32 key_block_length;
    u8 *key_block;
    void *new_sym_enc;
    void *new_hash;
} S3_004EBB10;
typedef struct Sess_004EBB10 { s32 f0; s32 key_arg_length; } Sess_004EBB10;
typedef struct S_004EBB10 {
    char pad0[0x54]; S3_004EBB10 *s3;
    char pad1[0x10]; X_004EBB10 read; X_004EBB10 write;
    void *f80;
    char pad3[0x2C]; Sess_004EBB10 *session;
} S_004EBB10;
extern s32 func_L39_004DE550(void);
extern s32 func_L01_00494120(void *);
extern s32 func_L39_004DE458(s32);
extern s32 func_L39_004DE8F8(void *);
extern s32 func_L01_004CC758(void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_00504B50(s32 *, s32, s32, s32, s32);

s32 func_L39_004EBB10(S_004EBB10 *s, s32 which) {
    u8 tmp1[32];
    u8 iv1[32];
    u8 *mac_secret;
    s32 cc;
    u8 *p, *ms, *key, *iv, *er1, *er2;
    void *c, *m, *ctx;
    X_004EBB10 *dd;
    s32 _exp, n, i, j, k;

    c = s->s3->new_sym_enc;
    m = s->s3->new_hash;
    _exp = (s32)(s->s3->new_cipher->algorithms >> 20) & 1;
    if (which & 1) {
        func_11D534(s->s3->read_sequence, 0, 8);
        dd = &s->read;
        mac_secret = s->s3->read_mac_secret;
    } else {
        func_11D534(s->s3->write_sequence, 0, 8);
        dd = &s->write;
        mac_secret = s->s3->write_mac_secret;
    }
    if (dd->cipher_ctx == 0) {
        if ((dd->cipher_ctx = func_L39_004DE550()) == 0) goto err;
    }
    if (dd->md_ctx == 0) {
        if ((dd->md_ctx = func_L39_004DE940()) == 0) goto err;
    }
    s->f80 = func_L39_004DE9B8;
    if (!func_L39_004DD690(dd->md_ctx, m)) goto err;
    dd->mac_size = func_L01_00494120(m);
    cc = (s32)dd->cipher_ctx;
    if (!func_L39_004DE458(cc)) goto err;

    p = s->s3->key_block;
    i = func_L01_00494120(m);
    if (_exp) {
        j = s->s3->new_cipher->algo_strength & 0xFF;
    } else {
        j = func_L39_004DE8F8(c);
    }
    k = func_L01_004CC758(c);
    if (which == 0x12 || which == 0x21) {
        ms = &p[0]; n = i + i;
        key = &p[n]; n += j + j;
        iv = &p[n]; n += k + k;
        er1 = s->s3->client_random;
        er2 = s->s3->server_random;
    } else {
        n = i;
        ms = &p[n]; n += i + j;
        key = &p[n]; n += j + k;
        iv = &p[n]; n += k;
        er1 = s->s3->server_random;
        er2 = s->s3->client_random;
    }
    if (n > s->s3->key_block_length) {
        func_L39_004BC6C8(0x14, 0x81, 0x9D, 0, 0);
        goto err2;
    }
    func_11D380(mac_secret, ms, i);
    if (_exp) {
        ctx = func_L39_004DE940();
        func_L39_004DD690(ctx, func_L39_004DF698());
        func_L39_004DD778(ctx, key, j);
        func_L39_004DD778(ctx, er1, 32);
        func_L39_004DD778(ctx, er2, 32);
        func_L39_004DD7A8(ctx, tmp1, 0);
        key = tmp1;
        if (k > 0) {
            func_L39_004DD690(ctx, 0);
            func_L39_004DD778(ctx, er1, 32);
            func_L39_004DD778(ctx, er2, 32);
            func_L39_004DD7A8(ctx, iv1, 0);
            iv = iv1;
        }
        func_L39_004DE9B8(ctx);
    }
    s->session->key_arg_length = 0;
    if (!((s32 (*)(s32 *, s32, s32, s32, s32))func_L39_00504B50)((s32 *)cc, (s32)c, (s32)key, (s32)iv, which & 2)) goto err2;
    func_11D534(tmp1, 0, 32);
    func_11D534(iv1, 0, 32);
    return 1;
err:
    func_L39_004BC6C8(0x14, 0x81, 0x21, 0, 0);
err2:
    return 0;
}
/* localdecomp:end func_L39_004EBB10 */
