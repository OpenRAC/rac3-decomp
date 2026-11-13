#include "common.h"

/* localdecomp:start func_L39_004DD378 */
typedef struct R_004DD378 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 *data;
    s32 len;
    s32 f14;
    s32 f18;
    s32 f1C;
} R_004DD378;
typedef struct C_004DD378 {
    s32 f0;
    void *store;
    s32 f8;
    void *src;
} C_004DD378;
extern s32 func_L39_004E4AE8(void *container, u32 category, u32 key, s32 *cursor, R_004DD378 **output, u32 flags);
extern void func_L39_004E4568(R_004DD378 *);
extern s32 func_L39_004E3000(void *, R_004DD378 *, s32, s32);
extern void func_L39_004E4748(R_004DD378 *);
extern s32 func_L39_004E48A8(void *, s32, s32, s32, u8 *, s32, s32);

s32 func_L39_004DD378(void *arg0, s32 key, u8 **data, s32 *len) {
    C_004DD378 *c = arg0;
    R_004DD378 *found = 0;
    R_004DD378 rec;
    s32 first = 1;

retry:
    if (func_L39_004E4AE8(c->store, 0x12, key, 0, &found, 0) == 0) {
        if (data != 0) {
            *data = found->data;
        }
        if (len != 0) {
            *len = found->len;
        }
        return 0;
    }
    if (c->src == 0 || !first) {
        goto fail;
    }
    first = 0;
    func_L39_004E4568(&rec);
    if (func_L39_004E3000(c->src, &rec, key, 0) != 0) {
        goto fail;
    }
    if (rec.len == 0) {
        func_L39_004E4748(&rec);
        goto fail;
    }
    if (func_L39_004E48A8(c->store, 0x12, key, 2, rec.data, rec.len, 0x12) != 0) {
        func_L39_004E4748(&rec);
        goto fail;
    }
    func_L39_004E4748(&rec);
    goto retry;
fail:
    if (data != 0) {
        *data = 0;
    }
    if (len != 0) {
        *len = 0;
    }
    return 1;
}
/* localdecomp:end func_L39_004DD378 */

INCLUDE_ASM("asm/levels", func_L39_004DD4C0);
