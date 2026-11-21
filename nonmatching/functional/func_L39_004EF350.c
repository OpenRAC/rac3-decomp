/* functional: high. Same calls and argument order as retail (OpenSSL tls1_generate_key_block); retail copies the seed with inline unaligned moves, this uses memcpy builtins; register allocation differs. */
/* OpenSSL's tls1_generate_key_block(s, km, tmp, num) */
extern char D_L39_004789E0[] __attribute__((aligned(8)));
typedef struct S3_004EF350 { u8 pad[0x44]; u8 server_random[32]; u8 client_random[32]; } S3_004EF350;
typedef struct C_004EF350 { u8 pad[0x104]; s32 md5; s32 sha1; } C_004EF350;
typedef struct Sess_004EF350 { u8 pad[0x10]; s32 master_key_length; u8 master_key[48]; } Sess_004EF350;
typedef struct S_004EF350 {
    u8 pad[0x54];
    S3_004EF350 *s3;
    u8 pad58[0xB0 - 0x58];
    Sess_004EF350 *session;
    u8 padB4[0xDC - 0xB4];
    C_004EF350 *ctx;
} S_004EF350;

s32 func_L39_004EF350(S_004EF350 *s, u8 *km, u8 *tmp, s32 num) {
    u8 buf[13 + 32 * 2] __attribute__((aligned(8)));

    __builtin_memcpy(buf, D_L39_004789E0, 13);
    __builtin_memcpy(&buf[13], s->s3->server_random, 32);
    __builtin_memcpy(&buf[13 + 32], s->s3->client_random, 32);
    return func_L39_004EF240(s->ctx->md5, s->ctx->sha1, (s32)buf, 13 + 32 * 2,
                             s->session->master_key, s->session->master_key_length,
                             km, tmp, num);
}
