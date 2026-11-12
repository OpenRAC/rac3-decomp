#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

/* localdecomp:start func_L39_00504E00 */
/* from OpenSSL's EVP_BytesToKey (1.1.0 shape, no asserts, only the first Init checked) */
typedef struct S_00504E00 {
    u8 pad[8];
    s32 key_len;
    s32 iv_len;
} S_00504E00;

extern void *func_L39_004DE940(void);
extern s32 func_L39_004DD690(void *, void *);
extern void func_L39_004DD778(void *, void *, u32);
extern void func_L39_004DD7A8(void *, void *, u32 *);
extern void func_L39_004DE9B8(void *);
extern void func_0011D534(void *, s32, s32);

s32 func_L39_00504E00(S_00504E00 *type, void *md, void *salt, u8 *data, s32 datal, s32 count, u8 *key, u8 *iv) {
    void *c;
    u8 md_buf[20];
    s32 niv, nkey, addmd = 0;
    u32 mds = 0, i;

    nkey = type->key_len;
    niv = type->iv_len;
    if (data == 0) {
        return nkey;
    }
    c = func_L39_004DE940();
    if (c == 0) {
        return 0;
    }
    for (;;) {
        if (!func_L39_004DD690(c, md)) {
            func_L39_004DE9B8(c);
            return 0;
        }
        if (++addmd != 1) {
            func_L39_004DD778(c, md_buf, mds);
        }
        func_L39_004DD778(c, data, datal);
        if (salt != 0) {
            func_L39_004DD778(c, salt, 8);
        }
        func_L39_004DD7A8(c, md_buf, &mds);
        for (i = 1; i < (u32)count; i++) {
            func_L39_004DD690(c, md);
            func_L39_004DD778(c, md_buf, mds);
            func_L39_004DD7A8(c, md_buf, &mds);
        }
        i = 0;
        if (nkey) {
            for (;;) {
                if (nkey == 0) break;
                if (i == mds) break;
                if (key != 0) {
                    *(key++) = md_buf[i];
                }
                nkey--;
                i++;
            }
        }
        if (niv && (i != mds)) {
            for (;;) {
                if (niv == 0) break;
                if (i == mds) break;
                if (iv != 0) {
                    *(iv++) = md_buf[i];
                }
                niv--;
                i++;
            }
        }
        if ((nkey == 0) && (niv == 0)) break;
    }
    func_L39_004DE9B8(c);
    func_0011D534(md_buf, 0, 20);
    return type->key_len;
}
/* localdecomp:end func_L39_00504E00 */
