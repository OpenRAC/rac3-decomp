/* NTSC-U draft (Claude wave B8): C of func_L39_004F5120, the NTSC-U twin of func_L39_004F5320, with NTSC-U names and addresses.
 * near miss: 68 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "@ee296 @eeas -O2 -G0") (NTSC-U twin "func_L39_004F5120").
 * Worker's note: 138 diff with the neighbours' flags (568 bytes vs retail 544), unchanged; flag sweep in the second try: -fno-gcse alone gives 68 diff and the exact size (544), -O1 108, all other variants 138. Same library family as func_L39_004F5878 (CBC-style block cipher ...
 */
#include "common.h"

/* localdecomp:start func_L39_004F5120 */
typedef struct Block_4F5120 {
    u8 pad0[4];
    u32 *iv;
    u8 *buf;
    u32 size;
} Block_4F5120;

typedef struct Cipher_4F5120 {
    u8 pad0[0xC];
    void (*fn)(void *, u8 *, u8 *);
} Cipher_4F5120;

s32 func_L39_004F5120(Block_4F5120 *blk, Cipher_4F5120 *c, void *key, u8 *dst, u32 *outLen, u8 *src, u32 srcLen) {
    u32 size = blk->size;
    u32 words = size >> 2;
    u8 *buf;
    u32 done = 0;
    u32 i;
    u32 j;
    u8 *s;
    u8 *d;
    u32 *w;
    u8 *b;

    buf = blk->buf;
    while (srcLen >= size) {
        i = 0;
        w = (u32 *)buf;
        s = src;
        for (; i < size; i += 8) {
            w[0] = (s[0] + (s[3] << 24)) + ((s[2] << 16) + (s[1] << 8));
            w[1] = (s[4] + (s[7] << 24)) + ((s[6] << 16) + (s[5] << 8));
            s += 8;
            w += 2;
        }
        c->fn(key, buf, buf);
        for (j = 0; j < words; j++) {
            ((u32 *)buf)[j] ^= blk->iv[j];
        }
        for (j = 0; j < words; j++) {
            blk->iv[j] = ((u32 *)src)[j];
        }
        i = 0;
        b = buf;
        d = dst;
        for (; i < size; i += 8) {
            d[0] = *(u32 *)b;
            d[1] = *(u32 *)b >> 8;
            d[2] = *(u32 *)b >> 16;
            d[3] = *(u32 *)b >> 24;
            d[4] = *(u32 *)(b + 4);
            d[5] = *(u32 *)(b + 4) >> 8;
            d[6] = *(u32 *)(b + 4) >> 16;
            d[7] = *(u32 *)(b + 4) >> 24;
            b += 8;
            d += 8;
        }
        srcLen -= size;
        src += size;
        dst += size;
        done += size;
    }
    *outLen = done;
    return 0;
}
/* localdecomp:end func_L39_004F5120 */
