#include "common.h"

extern s32 func_L39_004F6CA8(void *, void *, void *, void *);
extern s32 func_L39_004F6D38(void *, void *, void *, void *, void *, void *, void *, void *);
extern s32 func_L39_004F6E18(void *, void *, void *, void *, void *, void *);
extern s32 func_L39_004F6ED0(void *);
extern void func_L39_004F6F38(s32 *);
extern s32 func_L39_004F6FA0(void *, s32 (*)(void *), s32);

/* localdecomp:start func_L39_004F88C8 */
typedef struct A_004F88C8 {
    s32 a;
    s32 b;
} A_004F88C8;

extern A_004F88C8 D_00478E50;
extern s32 func_L39_004F4E58(void **);
extern s32 func_L39_004F4F68(void *, s32 (*)(void **), s32);
extern void func_L39_004F4F18(void **);
extern s32 func_L39_00508068(void **);
extern s32 func_L39_00508B30(void **);

s32 func_L39_004F88C8(void *out, s32 bits, s32 a2, s32 a3, void *buf, u32 len, u32 *outlen)
{
    A_004F88C8 alg;
    A_004F88C8 key;
    u32 n1;
    u32 n2;
    void *ctx;
    void *ctx2;
    s32 r;

    alg = D_00478E50;
    ctx = 0;
    ctx2 = 0;
    do {
        r = -1;
        if (bits != 0x80) {
            break;
        }
        if (len < 0x80) {
            break;
        }
        key.b = a3;
        key.a = a2;
        r = func_L39_004F4E58(&ctx);
        if (r != 0) {
            break;
        }
        r = func_L39_004F4F68(ctx, func_L39_00508068, 0);
        if (r != 0) {
            break;
        }
        r = func_L39_004F6ED0((void *)&ctx2);
        if (r != 0) {
            break;
        }
        r = func_L39_004F6FA0(ctx2, (void *)func_L39_00508B30, (s32)&key);
        if (r != 0) {
            break;
        }
        r = func_L39_004F6CA8(ctx, ctx2, &alg, 0);
        if (r != 0) {
            break;
        }
        r = func_L39_004F6D38(ctx, buf, &n1, (void *)len, out, (void *)0x80, 0, 0);
        if (r != 0) {
            break;
        }
        r = func_L39_004F6E18(ctx, (u8 *)buf + n1, &n2, (void *)(len - n1), 0, 0);
        if (r != 0) {
            break;
        }
        *outlen = n1 + n2;
    } while (0);
    if (r != 0) {
        r = -1;
    }
    func_L39_004F4F18(&ctx);
    func_L39_004F6F38((void *)&ctx2);
    return r;
}
/* localdecomp:end func_L39_004F88C8 */
