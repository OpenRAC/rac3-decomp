#include "common.h"

/* localdecomp:start func_L39_004E18B8 */
extern void *func_L39_00505060(void *);
extern s32 func_L39_00505270(char *, s32, s32);
extern void *func_L39_004DF698(void);
extern u8 *func_L39_00504DF8(void *);
extern s32 func_L39_00504E00(void *, void *, u8 *, u8 *, s32, s32, u8 *, u8 *);
extern s32 func_L39_004DE650(void *, void *, u8 *, u8 *);
extern void func_L39_00504B90(void *, u8 *, s32 *, u8 *, s32);
extern s32 func_L39_00504C80(void *, u8 *, s32 *);
extern void func_L39_004DE868(void *);
extern void *func_0011D534(void *, s32, s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* OpenSSL PEM_do_header, on an EVP_CIPHER_CTX */
s32 func_L39_004E18B8(void *ctx, u8 *data, long *plen, s32 (*callback)(char *, s32, s32)) {
    s32 i, j, o, klen;
    long len;
    u8 key[32];
    char buf[1024];

    len = *plen;
    if (func_L39_00505060(ctx) == 0) {
        return 1;
    }
    if (callback == 0) {
        klen = func_L39_00505270(buf, 1024, 0);
    } else {
        klen = callback(buf, 1024, 0);
    }
    if (klen <= 0) {
        func_L39_004BC6C8(9, 0x6A, 0x68, 0, 0);
        return 0;
    }
    if (!func_L39_00504E00(func_L39_00505060(ctx), func_L39_004DF698(), func_L39_00504DF8(ctx), (u8 *)buf,
                           klen, 1, key, 0)) {
        return 0;
    }
    j = (s32)len;
    if (!func_L39_004DE650(ctx, 0, key, 0)) {
        return 0;
    }
    func_L39_00504B90(ctx, data, &i, data, j);
    o = func_L39_00504C80(ctx, &data[i], &j);
    func_L39_004DE868(ctx);
    func_0011D534(buf, 0, sizeof(buf));
    func_0011D534(key, 0, sizeof(key));
    j += i;
    if (!o) {
        func_L39_004BC6C8(9, 0x6A, 0x65, 0, 0);
        return 0;
    }
    *plen = j;
    return 1;
}
/* localdecomp:end func_L39_004E18B8 */
