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
    s32 tag;
    s32 f10;
} Item_005103A0;
extern u8 D_L39_0046F408[];

s32 func_L39_005103A0(Ctx_005103A0 *ctx, Item_005103A0 *item, void **args, s32 *out) {
    extern s32 func_L39_00510A78_005103A0(Ctx_005103A0 *, s32, Item_005103A0 *);
    extern s32 func_L39_0050CC90_005103A0(Ctx_005103A0 *, s32, s32, void *, s32);
    extern void func_L39_0050CE50_005103A0(u32 *, Item_005103A0 *);
    extern s32 func_L39_0050D5B0(s32, Item_005103A0 *, s32, s32, s32 *);
    extern void func_L39_0050D780(s32 *);
    extern s32 func_L39_00510B58(Ctx_005103A0 *);
    extern s32 func_L39_00510BA8(Ctx_005103A0 *);
    s32 st;
    u32 skip;
    u32 depth;
    s32 count;
    s32 rc;
    u32 flags;
    s32 num;
    s32 type;
    s32 i;
    u32 d;
    s32 *v;

    *out = 0;
    count = -1;
    depth = ctx->depth;
    st = 0;
    do {
        flags = item->flags & ~0x200;
        if (item->cb != 0) {
            num = item->flags & 0x1FF;
            rc = item->cb(ctx, num, 0, args[item->tag]);
            if (rc != 0) {
                st = ctx->f18;
                func_L39_0050D780(&st);
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
            if (depth < ctx->depth) {
                if (ctx->frames[ctx->depth - 1]->f8 != 0x103) {
                    goto done;
                }
                ctx->depth--;
                rc = func_L39_00510A78_005103A0(ctx, num, item);
                if (rc != 0) {
                    return func_L39_0050D5B0(rc, item, st, -1, out);
                }
                rc = func_L39_0050CC90_005103A0(ctx, 0x103, 0, 0, 0);
                if (rc != 0) {
                    return func_L39_0050D5B0(rc, item, st, -1, out);
                }
                break;
            }
        } else {
            v = args[item->tag];
            if (v != 0) {
                rc = func_L39_0050CC90_005103A0(ctx, 0x100, 0, (void *)v[0], v[1]);
                if (rc != 0) {
                    return func_L39_0050D5B0(rc, item, st, -1, out);
                }
                break;
            }
        }
        if (!(flags & 0x20)) {
            if (item->flags & 0x200) {
                return 0;
            }
            return func_L39_0050D5B0(0x809, item, st, -1, out);
        }
        if ((flags & 0xC0) && !(flags & 0x1000)) {
            rc = func_L39_00510A78_005103A0(ctx, flags & 0x1FF, item);
            if (rc != 0) {
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
            rc = func_L39_005103A0(ctx, item + 1, args, &st);
            if (rc != 0) {
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
            rc = func_L39_0050CC90_005103A0(ctx, 0x103, 0, 0, 0);
            if (rc != 0) {
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
            break;
        }
        if (item[1].flags == 0x103) {
            if (item->flags & 0x200) {
                return 0;
            }
            return func_L39_0050D5B0(0x809, item, st, -1, out);
        }
        if (flags & 0x400) {
            if (item->cb == 0) {
                return func_L39_0050D5B0(0x804, item, st, -1, out);
            }
            type = flags & 0x1FF;
            rc = func_L39_00510A78_005103A0(ctx, type, item);
            if (rc != 0) {
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
            do {
                rc = func_L39_005103A0(ctx, item + 1, args, &st);
                count++;
                if (rc != 0) {
                    return func_L39_0050D5B0(rc, item, st, count, out);
                }
                d = ctx->depth;
                rc = item->cb(ctx, type, 0, args[item->tag]);
                if (rc != 0) {
                    st = ctx->f18;
                    func_L39_0050D780(&st);
                    return func_L39_0050D5B0(rc, item, st, count, out);
                }
            } while (!(d < ctx->depth) || ctx->frames[ctx->depth - 1]->f8 != 0x103);
            ctx->frames[ctx->depth - 1]->f0 = (flags == 0x431 || (flags & 0x3020) == 0x3020) ? (s32)(D_L39_0046F408 + 1) : 0;
            break;
        }
        if (flags - 0x30 < 2 || (flags & 0x1000)) {
            rc = func_L39_00510A78_005103A0(ctx, flags & 0x1FF, item);
            if (rc != 0) {
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
            for (i = 1; item[i].flags != 0x103; i += skip) {
                rc = func_L39_005103A0(ctx, &item[i], args, &st);
                if (rc != 0) {
                    return func_L39_0050D5B0(rc, item, st, -1, out);
                }
                func_L39_0050CE50_005103A0(&skip, &item[i]);
            }
            rc = func_L39_0050CC90_005103A0(ctx, 0x103, 0, (flags == 0x31 || (flags & 0x3020) == 0x3020) ? D_L39_0046F408 + 1 : 0, 0);
            if (rc != 0) {
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
            break;
        }
    } while (0);
done:
    if (depth == 0) {
        if (ctx->depth != 0 && ctx->frames[ctx->depth - 1]->f8 == 0x103) {
            rc = func_L39_00510B58(ctx);
            if (rc != 0) {
                return func_L39_0050D5B0(rc, item, st, -1, out);
            }
        }
        rc = func_L39_00510BA8(ctx);
        if (rc != 0) {
            return func_L39_0050D5B0(rc, item, st, -1, out);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005103A0 */

/* localdecomp:start func_L39_005108A0 */
extern void func_L39_004F7510(void *, void *, s32);

s32 func_L39_005108A0(s8 *out, s32 *outLen, u32 cap, s32 tag, u8 *tagBytes, void *data, u32 len) {
    s32 n;
    s32 l;
    s32 hi;

    hi = tag & 0x1F;
    n = 0;
    if (hi == 0x1F) {
        while (tagBytes[n] & 0x80) {
            n++;
        }
        n++;
    }
    if (len < 0x80) {
        l = 1;
    } else if (len < 0x100) {
        l = 2;
    } else if (len <= 0xFFFF) {
        l = 3;
    } else if (len <= 0xFFFFFF) {
        l = 4;
    } else {
        l = 5;
    }
    *outLen = n + l + 1;
    if (data != 0) {
        *outLen += len;
    }
    if (out == 0) {
        return 0;
    }
    if (cap < *outLen) {
        return 0x802;
    }
    *out++ = tag;
    if (hi == 0x1F) {
        func_L39_004F7510(out, tagBytes, n);
        out += n;
    }
    if (len < 0x80) {
        *out++ = len;
    } else if (len < 0x100) {
        *out++ = 0x81;
        *out++ = len;
    } else if (len <= 0xFFFF) {
        *out++ = 0x82;
        *out++ = len >> 8;
        *out++ = len;
    } else if (len <= 0xFFFFFF) {
        *out++ = 0x83;
        *out++ = len >> 16;
        *out++ = len >> 8;
        *out++ = len;
    } else {
        *out++ = 0x84;
        *out++ = len >> 24;
        *out++ = len >> 16;
        *out++ = len >> 8;
        *out++ = len;
    }
    if (data != 0) {
        func_L39_004F7510(out, data, len);
    }
    return 0;
}
/* localdecomp:end func_L39_005108A0 */

/* localdecomp:start func_L39_00510A78 */
typedef struct { u32 flags; s32 pad[4]; } S_00510A78_Ent;
typedef struct S_00510A78_Obj S_00510A78_Obj;
typedef struct {
    s32 (*fn0)(S_00510A78_Obj *, s8 *, s32);
} S_00510A78_Vt;
struct S_00510A78_Obj {
    S_00510A78_Vt *vt;
    s32 pad[6];
    S_00510A78_Obj *unk1C;
};
typedef struct { u32 n; s32 pad[3]; } S_00510A78_Res;

extern u8 D_L39_0046F408[];
extern void func_L39_0050CE50(S_00510A78_Res *, S_00510A78_Ent *);
extern void func_L39_0050CC90(S_00510A78_Obj *, s32, s32, u8 *, s32);
void func_L39_00510A78(S_00510A78_Obj *arg0, s32 arg1, S_00510A78_Ent *arg2) {
    s8 buf[2];
    S_00510A78_Res res;
    u32 i;

    func_L39_0050CE50(&res, arg2);
    for (i = 0; i < res.n; i++) {
        if (arg2[i].flags & 0x4000) {
            break;
        }
    }
    if (i < res.n) {
        buf[0] = arg1;
        buf[1] = 0x80;
        arg0->unk1C->vt->fn0(arg0->unk1C, buf, 2);
    } else {
        func_L39_0050CC90(arg0, arg1, 0, D_L39_0046F408, 0);
    }
}
/* localdecomp:end func_L39_00510A78 */
