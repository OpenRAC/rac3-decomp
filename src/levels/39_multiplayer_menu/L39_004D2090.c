#include "common.h"

/* localdecomp:start func_L39_004D2090 */
static __inline__ u32 rol_004D2090(u32 x, s32 n) {
    return (x << n) | (x >> (32 - n));
}

void func_L39_004D2090(u32 *w, u32 *h) {
    u32 a, b, c, d, e, t;
    s32 i, s;

    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];
    for (i = 0; i < 20; i++) {
        s = i & 0xF;
        if (i >= 16) {
            u32 x = w[(s + 13) & 0xF] ^ w[(s + 8) & 0xF] ^ w[(s + 2) & 0xF] ^ w[s];
            w[s] = rol_004D2090(x, 1);
        }
        t = rol_004D2090(a, 5) + ((b & c) | (~b & d)) + e + w[s] + 0x5A827999;
        e = d;
        d = c;
        c = rol_004D2090(b, 30);
        b = a;
        a = t;
    }
    for (; i < 40; i++) {
        s = i & 0xF;
        if (i >= 16) {
            u32 x = w[(s + 13) & 0xF] ^ w[(s + 8) & 0xF] ^ w[(s + 2) & 0xF] ^ w[s];
            w[s] = rol_004D2090(x, 1);
        }
        t = rol_004D2090(a, 5) + (b ^ c ^ d) + e + w[s] + 0x6ED9EBA1;
        e = d;
        d = c;
        c = rol_004D2090(b, 30);
        b = a;
        a = t;
    }
    for (; i < 60; i++) {
        s = i & 0xF;
        if (i >= 16) {
            u32 x = w[(s + 13) & 0xF] ^ w[(s + 8) & 0xF] ^ w[(s + 2) & 0xF] ^ w[s];
            w[s] = rol_004D2090(x, 1);
        }
        t = rol_004D2090(a, 5) + ((b & (c | d)) | (c & d)) + e + w[s] + 0x8F1BBCDC;
        e = d;
        d = c;
        c = rol_004D2090(b, 30);
        b = a;
        a = t;
    }
    for (; i < 80; i++) {
        s = i & 0xF;
        if (i >= 16) {
            u32 x = w[(s + 13) & 0xF] ^ w[(s + 8) & 0xF] ^ w[(s + 2) & 0xF] ^ w[s];
            w[s] = rol_004D2090(x, 1);
        }
        t = rol_004D2090(a, 5) + (b ^ c ^ d) + e + w[s] + 0xCA62C1D6;
        e = d;
        d = c;
        c = rol_004D2090(b, 30);
        b = a;
        a = t;
    }
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
}
/* localdecomp:end func_L39_004D2090 */

/* localdecomp:start func_L39_004D2468 */
extern void func_L39_004D2050(unsigned int *p);
extern void func_L39_004D2090(u32 *w, u32 *state);

void func_L39_004D2468(u8 *data, s32 len, u8 *out) {
    u32 w[16];
    u32 state[8];
    u8 block[64];
    s32 bits = len * 8;
    s32 i;
    s32 j;
    s32 k;
    u8 *p;
    u8 *q;

    func_L39_004D2050(state);
    while (len >= 48) {
        if (len < 64) {
            p = block;
            for (j = 0; j < len; j++) p[j] = data[j];
            p[len] = 0x80;
            if (63 - len > 0) {
                q = p + len + 1;
                for (k = 0; k < 63 - len; k++) q[k] = 0;
            }
        } else {
            p = data;
        }
        for (i = 0; i < 16; i++) {
            w[i] = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
            p += 4;
        }
        func_L39_004D2090(w, state);
        len -= 64;
        data += 64;
    }
    if (len > 0) {
        p = block;
        for (j = 0; j < len; j++) p[j] = data[j];
        p[len] = 0x80;
        if (55 - len > 0) {
            q = p + len + 1;
            for (k = 0; k < 55 - len; k++) q[k] = 0;
        }
        for (i = 0; i < 14; i++) {
            w[i] = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
            p += 4;
        }
    } else {
        w[0] = len ? 0 : 0x80000000;
        for (i = 1; i < 14; i++) {
            w[i] = 0;
        }
    }
    w[15] = bits;
    w[14] = 0;
    func_L39_004D2090(w, state);
    for (i = 0; i < 5; i++) {
        out[0] = state[i] >> 24;
        out[1] = state[i] >> 16;
        out[2] = state[i] >> 8;
        out[3] = state[i];
        out += 4;
    }
}
/* localdecomp:end func_L39_004D2468 */
