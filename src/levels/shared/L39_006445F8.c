#include "common.h"

/* localdecomp:start func_L39_006445F8 */
/* from this repo's func_L01_004E5520 (same code in level 1) */
typedef unsigned long u64l;
typedef struct {
    u64l a;
    u64l b;
    u64l c;
    u64l d;
} E_006445F8;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u64l x10;
    u64l data[1];
} H_006445F8;
extern E_006445F8 D_L39_002FA500[];
extern E_006445F8 D_L39_002FA508[];
extern E_006445F8 D_L39_002FA510[];
extern u64l func_L01_0040E8B0(u8 *, f32);

void func_L39_006445F8(s32 a0, s32 *list, H_006445F8 *out, u8 *src, s32 pad) {
    u64l *p;
    u64l *q;
    s32 n, nb, nc, j, k, sz, i, tot;
    u64l v;

    out->x10 = 0x7FFF000000000000;
    p = out->data;
    for (n = 1; list[n] >= 0; n++) {
        *p++ = D_L39_002FA500[list[n]].a;
    }
    for (i = 0; i < pad; i++, n++) {
        *p++ = 0x7FFF000000000000;
    }
    nb = 0;
    k = 1;
    sz = n * 8;
    for (; list[k] >= 0; k++) {
        u64l w = D_L39_002FA508[list[k]].a;
        if (w != 0x100010001000) {
            *p = w;
            nb++;
            ((u16 *)p)[3] = k | 0x8000;
            p++;
        }
    }
    tot = n + nb;
    nc = 0;
    for (j = 1; list[j] >= 0; j++) {
        v = D_L39_002FA510[list[j]].a;
        if (v != (func_L01_0040E8B0(*(u8 **)(src + 24) + j * 16, 1.0f) & 0xFFFFFFFFFFFF)) {
            *p = v;
            nc++;
            ((u16 *)p)[3] = j;
            p++;
        }
    }
    if ((s32)p & 0xF) {
        *p++ = 0;
    }
    out->h0 = 0;
    out->h2 = 0;
    out->h4 = 0;
    q = p - 2;
    out->h6 = ((s32)q - (s32)out) >> 4;
    out->h8 = sz;
    out->hA = nb;
    out->hC = tot * 8;
    out->hE = nc;
}
/* localdecomp:end func_L39_006445F8 */
