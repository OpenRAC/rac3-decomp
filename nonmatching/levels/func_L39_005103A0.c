/* PAL draft (k8-a6, 2026-11-27): 315 words differ with the file's flags (@ee296 @eeas -O2 -G0).
 * Structured C of the BER/DER item encoder (a recursive walk over 0x14-byte item rows ended by a
 * 0x103 row; callback per item, constructed tags 0x20, sequences 0x30/0x31, 0x400 repeated items,
 * errors through func_L39_0050D5B0 with codes 0x804 / 0x809). The control flow is meant to be
 * retail's block for block (read from the listing); callees whose later definitions in
 * L39_005103A0.c have other types are declared through _005103A0 suffix aliases.
 * Left: retail keeps `depth` and `count` in stack slots 0x8 / 0xC next to the two address-taken
 * locals (st 0x0, skip 0x4) and `out` in $s7; here `out` is spilled and count lives in $fp.
 * Retail's entry branches to the item->cb test placed at the end of the function (a rotated
 * loop head: `b`, body = the cb == 0 arm, test at the bottom), so the original probably had a
 * loop around the item walk; this draft has plain if/else.
 */
#include "common.h"

/* localdecomp:start func_L39_005103A0 */
typedef struct { s32 f0; s32 f4; s32 f8; } Frame_005103A0;
typedef struct {
    s32 f0;
    u32 depth;
    s32 f8;
    Frame_005103A0 **frames;
    s32 f10;
    s32 f14;
    s32 f18;
} Ctx_005103A0;
typedef struct Item_005103A0 {
    u32 flags;
    s32 f4;
    s32 (*cb)(Ctx_005103A0 *, s32, s32, void *);
    s32 argIdx;
    s32 f10;
} Item_005103A0;
extern u8 D_L39_0046F408[];
extern s32 func_L39_00510A78_005103A0(Ctx_005103A0 *, s32, Item_005103A0 *);
extern s32 func_L39_0050CC90_005103A0(Ctx_005103A0 *, s32, s32, void *, s32);
extern void func_L39_0050CE50_005103A0(s32 *, Item_005103A0 *);
extern s32 func_L39_0050D5B0_005103A0(s32, Item_005103A0 *, s32, s32, s32 *);
extern void func_L39_0050D780_005103A0(s32 *);
extern s32 func_L39_00510B58_005103A0(Ctx_005103A0 *);
extern s32 func_L39_00510BA8_005103A0(Ctx_005103A0 *);

s32 func_L39_005103A0(Ctx_005103A0 *ctx, Item_005103A0 *item, void **args, s32 *out) {
    s32 st;
    s32 skip;
    u32 depth;
    s32 count;
    s32 err;
    u32 tag;
    s32 num;
    s32 i;
    u32 d, n;
    s32 *v;

    *out = 0;
    count = -1;
    depth = ctx->depth;
    st = 0;
    tag = item->flags & ~0x200;
    if (item->cb != 0) {
        num = item->flags & 0x1FF;
        err = item->cb(ctx, num, 0, args[item->argIdx]);
        if (err != 0) {
            st = ctx->f18;
            func_L39_0050D780_005103A0(&st);
            goto fail;
        }
        n = ctx->depth;
        if (depth < n) {
            if (ctx->frames[n - 1]->f8 != 0x103) {
                goto done;
            }
            ctx->depth = n - 1;
            err = func_L39_00510A78_005103A0(ctx, num, item);
            if (err != 0) {
                goto fail;
            }
            err = func_L39_0050CC90_005103A0(ctx, 0x103, 0, 0, 0);
            goto check;
        }
    } else {
        v = args[item->argIdx];
        if (v != 0) {
            err = func_L39_0050CC90_005103A0(ctx, 0x100, 0, (void *)v[0], v[1]);
            goto check;
        }
    }
    if (tag & 0x20) {
        if ((tag & 0xC0) && !(tag & 0x1000)) {
            err = func_L39_00510A78_005103A0(ctx, tag & 0x1FF, item);
            if (err != 0) {
                goto fail;
            }
            err = func_L39_005103A0(ctx, item + 1, args, &st);
            if (err != 0) {
                goto fail;
            }
            err = func_L39_0050CC90_005103A0(ctx, 0x103, 0, 0, 0);
            goto check;
        }
        if (item[1].flags != 0x103) {
            if (tag & 0x400) {
                if (item->cb == 0) {
                    return func_L39_0050D5B0_005103A0(0x804, item, st, -1, out);
                }
                num = tag & 0x1FF;
                err = func_L39_00510A78_005103A0(ctx, num, item);
                if (err != 0) {
                    goto fail;
                }
                do {
                    err = func_L39_005103A0(ctx, item + 1, args, &st);
                    count++;
                    if (err != 0) {
                        goto fail_n;
                    }
                    d = ctx->depth;
                    err = item->cb(ctx, num, 0, args[item->argIdx]);
                    if (err != 0) {
                        st = ctx->f18;
                        func_L39_0050D780_005103A0(&st);
                        goto fail_n;
                    }
                    n = ctx->depth;
                } while (!(d < n) || ctx->frames[n - 1]->f8 != 0x103);
                ctx->frames[n - 1]->f0 = (tag == 0x431 || (tag & 0x3020) == 0x3020) ? (s32)(D_L39_0046F408 + 1) : 0;
                goto done;
            }
            if (tag - 0x30 < 2 || (tag & 0x1000)) {
                err = func_L39_00510A78_005103A0(ctx, tag & 0x1FF, item);
                if (err != 0) {
                    goto fail;
                }
                for (i = 1; item[i].flags != 0x103; i += skip) {
                    err = func_L39_005103A0(ctx, &item[i], args, &st);
                    if (err != 0) {
                        goto fail;
                    }
                    func_L39_0050CE50_005103A0(&skip, &item[i]);
                }
                err = func_L39_0050CC90_005103A0(ctx, 0x103, 0,
                    (tag == 0x31 || (tag & 0x3020) == 0x3020) ? D_L39_0046F408 + 1 : 0, 0);
                goto check;
            }
            goto done;
        }
    }
    if (item->flags & 0x200) {
        return 0;
    }
    return func_L39_0050D5B0_005103A0(0x809, item, st, -1, out);
check:
    if (err != 0) {
        goto fail;
    }
done:
    if (depth != 0) {
        return 0;
    }
    n = ctx->depth;
    if (n != 0 && ctx->frames[n - 1]->f8 == 0x103) {
        err = func_L39_00510B58_005103A0(ctx);
        if (err != 0) {
            goto fail;
        }
    }
    err = func_L39_00510BA8_005103A0(ctx);
    if (err == 0) {
        return 0;
    }
fail:
    return func_L39_0050D5B0_005103A0(err, item, st, -1, out);
fail_n:
    return func_L39_0050D5B0_005103A0(err, item, st, count, out);
}
/* localdecomp:end func_L39_005103A0 */
