#include "common.h"

/* func_L39_004ED888 (first draft, fresh entry; wave 13b r31): OpenSSL 0.9.x SHA1_Update with the block
   function taken from c->block (the file's SHA1_Init func_L39_004ED820 sets it, SHA1_Final func_L39_004EE378
   calls it). 2 diff under the file's line (p10/check.py): the 4-word inner loop of the while (len >= 64)
   body. Written as OpenSSL's for (sw = SHA_LBLOCK/4; sw; sw--), ee29 keeps retail's counter (4, -1, bnez)
   but strength-reduces data differently (two data+1 givs, 20 diff). Written counting up,
   for (sw = 0; sw < 4; sw++), loop.c reverses the counter first and then picks retail's data givs
   (a3 = data+12, a2 = data+1 recomputed): everything matches except the reversed counter itself,
   "addiu t1,zero,3" and "bgez t1" where retail has "addiu t1,zero,4" and "bnez t1" (check_dbra_loop's
   GE form; retail looks like its NE form). Tried: sw <= 3, sw != 4 (370), sw += 4 to 16 (3), counter update at
   the top of the body (2), down-count forms sw > 0 / sw >= 1 / sw-- > 0 / while (sw--) / do-while / sw = 3
   down to >= 0 (20-159), comma-expression c2nl, register, declaration orders, len -= 64 moved, p[i] stores,
   data[i] reads, p = c->data moved. */

/* localdecomp:start func_L39_004ED888 */
/* OpenSSL 0.9.x SHA1_Update (sha_dgst.c, public source); ULONG is u64, sha1_block is c->block */
typedef struct {
    u64 h0, h1, h2, h3, h4;
    u64 Nl, Nh;
    u64 data[16];
    s32 num;
    void (*block)();
} S_004ED888;

void func_L39_004ED888(S_004ED888 *c, u8 *data, u64 len) {
    u64 *p;
    s32 ew, ec, sw, sc;
    u64 l;

    if (len == 0) {
        return;
    }

    l = (c->Nl + (len << 3)) & 0xffffffff;
    if (l < c->Nl) {
        c->Nh++;
    }
    c->Nh += (len >> 29);
    c->Nl = l;

    if (c->num != 0) {
        p = c->data;
        sw = c->num >> 2;
        sc = c->num & 0x03;

        if ((c->num + len) >= 64) {
            l = p[sw];
            switch (sc) {
            case 0: l = ((u64)(*(data++))) << 24;
            case 1: l |= ((u64)(*(data++))) << 16;
            case 2: l |= ((u64)(*(data++))) << 8;
            case 3: l |= ((u64)(*(data++)));
            }
            p[sw++] = l;
            for (; sw < 16; sw++) {
                l = ((u64)(*(data++))) << 24;
                l |= ((u64)(*(data++))) << 16;
                l |= ((u64)(*(data++))) << 8;
                l |= ((u64)(*(data++)));
                p[sw] = l;
            }
            len -= (64 - c->num);

            c->block(c, p, 64);
            c->num = 0;
        } else {
            c->num += (s32)len;
            if ((sc + len) < 4) {
                l = p[sw];
                switch (sc) {
                case 0: l = ((u64)(*(data++))) << 24;
                    if (--len == 0) break;
                case 1: l |= ((u64)(*(data++))) << 16;
                    if (--len == 0) break;
                case 2: l |= ((u64)(*(data++))) << 8;
                }
                p[sw] = l;
            } else {
                ew = (c->num >> 2);
                ec = (c->num & 0x03);
                l = p[sw];
                switch (sc) {
                case 0: l = ((u64)(*(data++))) << 24;
                case 1: l |= ((u64)(*(data++))) << 16;
                case 2: l |= ((u64)(*(data++))) << 8;
                case 3: l |= ((u64)(*(data++)));
                }
                p[sw++] = l;
                for (; sw < ew; sw++) {
                    l = ((u64)(*(data++))) << 24;
                    l |= ((u64)(*(data++))) << 16;
                    l |= ((u64)(*(data++))) << 8;
                    l |= ((u64)(*(data++)));
                    p[sw] = l;
                }
                if (ec) {
                    l = 0;
                    data += ec;
                    switch (ec) {
                    case 3: l = ((u64)(*(--data))) << 8;
                    case 2: l |= ((u64)(*(--data))) << 16;
                    case 1: l |= ((u64)(*(--data))) << 24;
                    }
                    p[sw] = l;
                }
            }
            return;
        }
    }
    p = c->data;
    while (len >= 64) {
        for (sw = 0; sw < 4; sw++) {
            l = ((u64)(*(data++))) << 24;
            l |= ((u64)(*(data++))) << 16;
            l |= ((u64)(*(data++))) << 8;
            l |= ((u64)(*(data++)));
            *(p++) = l;
            l = ((u64)(*(data++))) << 24;
            l |= ((u64)(*(data++))) << 16;
            l |= ((u64)(*(data++))) << 8;
            l |= ((u64)(*(data++)));
            *(p++) = l;
            l = ((u64)(*(data++))) << 24;
            l |= ((u64)(*(data++))) << 16;
            l |= ((u64)(*(data++))) << 8;
            l |= ((u64)(*(data++)));
            *(p++) = l;
            l = ((u64)(*(data++))) << 24;
            l |= ((u64)(*(data++))) << 16;
            l |= ((u64)(*(data++))) << 8;
            l |= ((u64)(*(data++)));
            *(p++) = l;
        }
        p = c->data;
        c->block(c, p, 64);
        len -= 64;
    }
    ec = (s32)len;
    c->num = ec;
    ew = (ec >> 2);
    ec &= 0x03;

    for (sw = 0; sw < ew; sw++) {
        l = ((u64)(*(data++))) << 24;
        l |= ((u64)(*(data++))) << 16;
        l |= ((u64)(*(data++))) << 8;
        l |= ((u64)(*(data++)));
        p[sw] = l;
    }
    l = 0;
    data += ec;
    switch (ec) {
    case 3: l = ((u64)(*(--data))) << 8;
    case 2: l |= ((u64)(*(--data))) << 16;
    case 1: l |= ((u64)(*(--data))) << 24;
    }
    p[sw] = l;
}
/* localdecomp:end func_L39_004ED888 */
