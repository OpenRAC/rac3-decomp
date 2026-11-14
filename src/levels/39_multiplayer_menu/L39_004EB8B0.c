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

INCLUDE_ASM("asm/levels", func_L39_004EBB10);
