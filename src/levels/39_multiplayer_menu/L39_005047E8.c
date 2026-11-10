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

/* localdecomp:start func_L39_005047E8 */
extern u8 D_L39_0046EB18[];

/* OpenSSL's EVP_DecodeBlock */
s32 func_L39_005047E8(u8 *t, u8 *f, s32 n) {
    s32 i, ret = 0, a, b, c, d;
    u64 l;

    while ((D_L39_0046EB18[*f & 0x7F] == 0xE0) && (n > 0)) {
        f++;
        n--;
    }
    while ((n > 3) && ((D_L39_0046EB18[f[n - 1] & 0x7F] | 0x13) == 0xF3)) {
        n--;
    }
    if (n % 4 != 0) {
        return -1;
    }
    for (i = 0; i < n; i += 4) {
        a = D_L39_0046EB18[*(f++) & 0x7F];
        b = D_L39_0046EB18[*(f++) & 0x7F];
        c = D_L39_0046EB18[*(f++) & 0x7F];
        d = D_L39_0046EB18[*(f++) & 0x7F];
        if ((a & 0x80) || (b & 0x80) || (c & 0x80) || (d & 0x80)) {
            return -1;
        }
        l = (((u64)a << 18) | ((u64)b << 12) | ((u64)c << 6) | ((u64)d));
        *(t++) = (u8)(l >> 16) & 0xFF;
        *(t++) = (u8)(l >> 8) & 0xFF;
        *(t++) = (u8)(l) & 0xFF;
        ret += 3;
    }
    return ret;
}
/* localdecomp:end func_L39_005047E8 */

/* localdecomp:start func_L39_00504970 */
s32 func_L39_00504970(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 r;

    *arg2 = 0;
    if (*arg0 != 0) {
        r = func_L39_005047E8((u8 *)arg1, (u8 *)(arg0 + 2), *arg0);
        if (r < 0) {
            return -1;
        }
        *arg0 = 0;
        *arg2 = r;
        return 1;
    }
    return 1;
}
/* localdecomp:end func_L39_00504970 */

/* localdecomp:start func_L39_005049D8 */
typedef struct {
    char pad0[0x88];
    s32 f88[0x10];
    s32 fC8[0x10];
    char pad108[0x80];
    s32 f188;
} S_005049D8;

extern S_005049D8 *func_L39_004BC8B0();

void func_L39_005049D8(s32 a0, s32 a1) {
    S_005049D8 *p = func_L39_004BC8B0();
    s32 i = p->f188;

    if (i == 0) {
        i = 15;
    }
    p->f88[i] = a0;
    p->fC8[p->f188] = a1;
}
/* localdecomp:end func_L39_005049D8 */
