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

INCLUDE_ASM("asm/levels", func_L39_004EC250);

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

INCLUDE_ASM("asm/levels", func_L39_004EC6A8);
