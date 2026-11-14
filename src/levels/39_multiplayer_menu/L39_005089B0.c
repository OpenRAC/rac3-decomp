#include "common.h"

/* localdecomp:start func_L39_005089B0 */
typedef struct Sub_005089B0 {
    u8 pad0[0x10];
    void **data;
} Sub_005089B0;

typedef struct Ent_005089B0 {
    void *type;
    void *k1;
    s32 pad8;
    s32 k3;
    Sub_005089B0 *sub;
} Ent_005089B0;

extern u8 D_L39_0046F010[];
extern u8 D_L39_0046F02C[];
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_005089B0(void *ctx, void *k1, void *k2, s32 k3, Ent_005089B0 **list) {
    s32 found = -1;
    s32 i;

    for (i = 0;; i++) {
        if (list[i] == 0) {
            return 0;
        }
        if (found == -1 && list[i]->type == k1 && list[i]->k1 == k2 && list[i]->k3 == k3) {
            found = i;
        }
        if (list[i]->type == D_L39_0046F010) {
            break;
        }
    }
    if (found == -1) {
        return 0;
    }
    if (list[i]->sub->data[found] == 0) {
        return 0;
    }
    return func_L39_004F5EA0(ctx, D_L39_0046F02C, (u8 *)list[found]->sub->data + 0x14);
}
/* localdecomp:end func_L39_005089B0 */

/* localdecomp:start func_L39_00508A98 */
u32 func_L39_00508A98(u8 *buf, u32 len) {
    u32 bits;
    u32 mask;
    u32 c;
    u32 i;
    u32 r;

    for (i = 0; i < len && buf[i] == 0; i++) {
    }
    r = 0;
    if (i != len) {
        c = buf[i++];
        mask = 0x80;
        for (bits = 8; (c & mask) == 0; bits--) {
            mask >>= 1;
        }
        r = (len - i) * 8 + bits;
    }
    return r;
}
/* localdecomp:end func_L39_00508A98 */
