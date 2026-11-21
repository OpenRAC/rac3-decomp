#include "common.h"

/* declared by functions of L39_00515030.c, which this file was cut from */
typedef struct { s32 cap; s32 n; long *d; } S_00515030;

/* localdecomp:start func_L39_00515088 */
/* best 27 diff: loop and tail match. Differs: retail hoists v0=0 into the prologue, expands bits/64 as
   (bits<0 ? bits+63 : bits) (slti/movn) where ours is slt -1<bits, and does not re-set a1 before the call.
   Tried: pointer loop (30), nested if (57). */
s32 func_L39_00515088(s32 bits, S_00515030 *s) {
    s32 words;
    s32 ret;
    s32 i;
    s32 last;
    s32 rest;
    unsigned long *d;

    if (bits <= 0) {
        return 0;
    }
    if (bits >= 0x40) {
        words = bits / 64;
        ret = func_L39_00515030(words, s);
        if (ret != 0) {
            return ret;
        }
        bits -= words * 64;
        if (bits == 0) {
            return 0;
        }
    }
    rest = 64 - bits;
    last = s->n - 1;
    d = (unsigned long *)s->d;
    for (i = 0; i < last; i++) {
        d[i] = (d[i] >> bits) | (d[i + 1] << rest);
    }
    d[last] >>= bits;
    if (d[last] == 0 && last != 0) {
        s->n--;
    }
    return 0;
}
/* localdecomp:end func_L39_00515088 */
