#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* declared by functions of L39_004EB840.c, which this file was cut from */
extern s32 func_L39_004EC250(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004EC1B8 */
extern s32 func_L39_004EC250(s32, s32, s32, s32, s32);

s32 func_L39_004EC1B8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 n;
    s32 m;

    n = func_L39_004EC250(a0, a1, a3, a4, a5);
    if (n == 0) {
        return 0;
    }
    m = func_L39_004EC250(a0, a2, a3, a4, a5 + n);
    if (m == 0) {
        return 0;
    }
    return n + m;
}
/* localdecomp:end func_L39_004EC1B8 */

/* localdecomp:start func_L39_004EC250 */
extern s32 func_L39_00505120(void *, void *);
extern u32 func_L39_004DE8E8(void *);
extern void *func_L39_00505050(void *);
extern s32 func_L39_004DD690(void *, void *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, void *, u32 *);
extern u8 D_L39_0046D3C0[];
extern u8 D_L39_0046D3F0[];

/* OpenSSL's ssl3_handshake_mac */
s32 func_L39_004EC250(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *s = (u8 *)a0;
    u8 *sender = (u8 *)a2;
    u8 *p = (u8 *)a4;
    u8 md_buf[32];
    u32 i;
    u32 ret;
    s32 n, npad;

    if (func_L39_00505120(*(void **)(s + 0x128), (void *)a1) == 0) {
        return 0;
    }
    n = func_L39_004DE8E8(*(void **)(s + 0x128));
    npad = (48 / n) * n;
    if (sender != 0) {
        func_L39_004DD778(*(void **)(s + 0x128), sender, a3);
    }
    func_L39_004DD778(*(void **)(s + 0x128), *(u8 **)(s + 0xB0) + 0x14, *(s32 *)(*(u8 **)(s + 0xB0) + 0x10));
    func_L39_004DD778(*(void **)(s + 0x128), D_L39_0046D3C0, npad);
    func_L39_004DD7A8(*(void **)(s + 0x128), md_buf, &i);

    func_L39_004DD690(*(void **)(s + 0x128), func_L39_00505050(*(void **)(s + 0x128)));
    func_L39_004DD778(*(void **)(s + 0x128), *(u8 **)(s + 0xB0) + 0x14, *(s32 *)(*(u8 **)(s + 0xB0) + 0x10));
    func_L39_004DD778(*(void **)(s + 0x128), D_L39_0046D3F0, npad);
    func_L39_004DD778(*(void **)(s + 0x128), md_buf, i);
    func_L39_004DD7A8(*(void **)(s + 0x128), p, &ret);
    return ret;
}
/* localdecomp:end func_L39_004EC250 */

/* localdecomp:start func_L39_004EC378 */
extern s32 func_L39_004DD690(void *, void *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, void *, u32 *);
extern u8 D_L39_0046D3C0[];
extern u8 D_L39_0046D3F0[];

typedef struct Rec_004EC378 {
    s32 type;
    u32 length;
    s32 off;
    u8 *data;
    u8 *input;
} Rec_004EC378;

/* OpenSSL's ssl3_mac */
s32 func_L39_004EC378(u8 *ssl, u8 *md, s32 send) {
    Rec_004EC378 *rec;
    u8 *mac_sec, *seq;
    void *ctx;
    u8 *p, rec_char;
    u32 md_size;
    s32 npad, i;

    if (send) {
        rec = (Rec_004EC378 *)(*(u8 **)(ssl + 0x54) + 0xCC);
        mac_sec = *(u8 **)(ssl + 0x54) + 0x30;
        seq = *(u8 **)(ssl + 0x54) + 0x28;
        ctx = *(void **)(ssl + 0x78);
        md_size = *(u32 *)(ssl + 0x74);
    } else {
        rec = (Rec_004EC378 *)(*(u8 **)(ssl + 0x54) + 0xB4);
        mac_sec = *(u8 **)(ssl + 0x54) + 0x14;
        seq = *(u8 **)(ssl + 0x54) + 0xC;
        ctx = *(void **)(ssl + 0x6C);
        md_size = *(u32 *)(ssl + 0x68);
    }

    npad = (48 / md_size) * md_size;

    func_L39_004DD690(ctx, 0);
    func_L39_004DD778(ctx, mac_sec, md_size);
    func_L39_004DD778(ctx, D_L39_0046D3C0, npad);
    func_L39_004DD778(ctx, seq, 8);
    rec_char = rec->type;
    func_L39_004DD778(ctx, &rec_char, 1);
    p = md;
    *p++ = rec->length >> 8;
    *p++ = rec->length;
    func_L39_004DD778(ctx, md, 2);
    func_L39_004DD778(ctx, rec->input, rec->length);
    func_L39_004DD7A8(ctx, md, 0);

    func_L39_004DD690(ctx, 0);
    func_L39_004DD778(ctx, mac_sec, md_size);
    func_L39_004DD778(ctx, D_L39_0046D3F0, npad);
    func_L39_004DD778(ctx, md, md_size);
    func_L39_004DD7A8(ctx, md, &md_size);

    for (i = 7; i >= 0; i--) {
        ++seq[i];
        if (seq[i] != 0) {
            break;
        }
    }
    return md_size;
}
/* localdecomp:end func_L39_004EC378 */

/* localdecomp:start func_L39_004EC548 */
extern s32 func_L39_004DD690(void *, void *);
extern s32 func_120884(const char *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, void *, u32 *);
extern char *D_L39_0046D420[];

s32 func_L39_004EC548(u8 *s, u8 *out, u8 *p, s32 len) {
    u8 buf[32];
    u32 n;
    s32 i;
    s32 ret;

    ret = 0;
    for (i = 0; i < 3; i++) {
        if (func_L39_004DD690(*(void **)(s + 0x128), *(void **)(*(u8 **)(s + 0xDC) + 0x108)) == 0) {
            return 0;
        }
        func_L39_004DD778(*(void **)(s + 0x128), D_L39_0046D420[i], func_120884(D_L39_0046D420[i]));
        func_L39_004DD778(*(void **)(s + 0x128), p, len);
        func_L39_004DD778(*(void **)(s + 0x128), *(u8 **)(s + 0x54) + 0x64, 0x20);
        func_L39_004DD778(*(void **)(s + 0x128), *(u8 **)(s + 0x54) + 0x44, 0x20);
        func_L39_004DD7A8(*(void **)(s + 0x128), buf, &n);
        if (func_L39_004DD690(*(void **)(s + 0x128), *(void **)(*(u8 **)(s + 0xDC) + 0x104)) == 0) {
            return 0;
        }
        func_L39_004DD778(*(void **)(s + 0x128), p, len);
        func_L39_004DD778(*(void **)(s + 0x128), buf, n);
        func_L39_004DD7A8(*(void **)(s + 0x128), out, &n);
        out += n;
        ret += n;
    }
    return ret;
}
/* localdecomp:end func_L39_004EC548 */

/* localdecomp:start func_L39_004EC6A8 */
/* OpenSSL's ssl3_alert_code (s3_lib.c): an SSL_AD_* alert to its SSL3_AD_* code */
s32 func_L39_004EC6A8(s32 code) {
    switch (code) {
    case 0: return 0;
    case 10: return 10;
    case 20: return 20;
    case 21: return 20;
    case 22: return 20;
    case 30: return 30;
    case 40: return 40;
    case 41: return 41;
    case 42: return 42;
    case 43: return 43;
    case 44: return 44;
    case 45: return 45;
    case 46: return 46;
    case 47: return 47;
    case 48: return 42;
    case 49: return 40;
    case 50: return 40;
    case 51: return 40;
    case 60: return 40;
    case 70: return 40;
    case 71: return 40;
    case 80: return 40;
    case 90: return 40;
    case 100: return -1;
    default: return -1;
    }
}
/* localdecomp:end func_L39_004EC6A8 */
