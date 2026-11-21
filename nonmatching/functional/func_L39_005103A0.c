/* functional: medium. 315 diffs (register pressure/frame layout differ); written as a goto-structured translation of every block of the asm. Medium confidence: callee semantics inferred (func_L39_00510A78, func_L39_0050CC90, func_L39_0050D5B0), unrun paths read only. */
extern u8 D_L39_0046F408[];
extern s32 func_L39_00510A78(void *, s32, void *);
extern s32 func_L39_0050CC90(void *, s32, s32, s32, s32);
extern void func_L39_0050CE50(u32 *);
extern void func_L39_0050D780(s32 *);
extern s32 func_L39_0050D5B0(s32, void *, s32, s32, s32 *);
extern s32 func_L39_00510B58(void *);
extern s32 func_L39_00510BA8(void *);

typedef struct Frame_005103A0 {
    u32 f0;
    u32 f4;
    u32 f8;
} Frame_005103A0;

typedef struct Ctx_005103A0 {
    char pad0[4];
    u32 depth;
    char pad8[4];
    Frame_005103A0 **frames;
    char pad10[8];
    s32 f18;
} Ctx_005103A0;

typedef struct Item_005103A0 {
    u32 flags;
    u32 f4;
    s32 (*cb)(void *, s32, s32, s32);
    s32 argIdx;
    s32 f10;
} Item_005103A0;

s32 func_L39_005103A0(Ctx_005103A0 *ctx, Item_005103A0 *item, s32 *args, s32 *out) {
    s32 st[4];
    s32 err;
    u32 t;
    u32 n;
    u32 old;
    s32 *v;
    Item_005103A0 *fp;
    Item_005103A0 *top;
    u32 j;
    s32 t2;
    u32 f9;

    *out = 0;
    st[3] = -1;
    st[2] = ctx->depth;
    st[0] = 0;

    t = item->flags & ~0x200;
    if (item->cb == 0) {
        v = (s32 *)args[item->argIdx];
        if (v == 0) {
            goto L444;
        }
        err = func_L39_0050CC90(ctx, 0x100, 0, v[0], v[1]);
        goto after_cc90;
    }
    f9 = item->flags & 0x1FF;
    err = item->cb(ctx, f9, 0, args[item->argIdx]);
    if (err != 0) {
        st[0] = ctx->f18;
        func_L39_0050D780(&st[0]);
        goto E_tail;
    }
    n = ctx->depth;
    if (!(st[2] < n)) {
        goto L444;
    }
    top = (Item_005103A0 *)ctx->frames[n - 1];
    if (top->cb != (void *)0x103) {
        goto L78C;
    }
    ctx->depth = n - 1;
    err = func_L39_00510A78(ctx, f9, item);
    if (err != 0) {
        goto E_tail;
    }
    err = func_L39_0050CC90(ctx, 0x103, 0, 0, 0);
    goto after_cc90;

L444:
    if (!(t & 0x20)) {
        if (item->flags & 0x200) {
            return 0;
        }
        err = 0x809;
        goto E_tail;
    }
    if ((t & 0xC0) != 0) {
        if (!(t & 0x1000)) {
            err = func_L39_00510A78(ctx, t & 0x1FF, item);
            if (err != 0) {
                goto E_tail;
            }
            err = func_L39_005103A0(ctx, item + 1, args, &st[0]);
            if (err != 0) {
                goto E_tail;
            }
            err = func_L39_0050CC90(ctx, 0x103, 0, 0, 0);
            goto after_cc90;
        }
    }
    if (item[1].flags == 0x103) {
        if (item->flags & 0x200) {
            return 0;
        }
        err = 0x809;
        goto E_tail;
    }
    if (t & 0x400) {
        if (item->cb == 0) {
            err = 0x804;
            goto E_tail;
        }
        f9 = t & 0x1FF;
        err = func_L39_00510A78(ctx, f9, item);
        if (err != 0) {
            goto E_tail;
        }
        fp = item + 1;
        do {
            err = func_L39_005103A0(ctx, fp, args, &st[0]);
            st[3]++;
            if (err != 0) {
                goto C_tail;
            }
            old = ctx->depth;
            err = item->cb(ctx, f9, 0, args[item->argIdx]);
            if (err != 0) {
                st[0] = ctx->f18;
                func_L39_0050D780(&st[0]);
                goto C_tail;
            }
            n = ctx->depth;
            if (old < n) {
                top = (Item_005103A0 *)ctx->frames[n - 1];
                if (top->cb == (void *)0x103) {
                    if (t == 0x431 || (t & 0x3020) == 0x3020) {
                        t2 = (s32)(D_L39_0046F408 + 1);
                    } else {
                        t2 = 0;
                    }
                    ((Frame_005103A0 *)top)->f0 = t2;
                    goto L788;
                }
            }
        } while (1);
    }
    if ((u32)(t - 0x30) >= 2 && !(t & 0x1000)) {
        goto L78C;
    }
    err = func_L39_00510A78(ctx, t & 0x1FF, item);
    if (err != 0) {
        goto E_tail;
    }
    if (item[1].flags != 0x103) {
        j = 1;
        do {
            err = func_L39_005103A0(ctx, &item[j], args, &st[0]);
            if (err != 0) {
                goto E_tail;
            }
            func_L39_0050CE50((u32 *)&st[1]);
            j += st[1];
        } while (item[j].flags != 0x103);
    }
    if (t == 0x31 || (t & 0x3020) == 0x3020) {
        t2 = (s32)(D_L39_0046F408 + 1);
    } else {
        t2 = 0;
    }
    err = func_L39_0050CC90(ctx, 0x103, 0, t2, 0);

after_cc90:
    if (err != 0) {
        goto E_tail;
    }
L788:
L78C:
    if (st[2] != 0) {
        return 0;
    }
    n = ctx->depth;
    if (n != 0) {
        top = (Item_005103A0 *)ctx->frames[n - 1];
        if (top->cb == (void *)0x103) {
            err = func_L39_00510B58(ctx);
            if (err != 0) {
                goto E_tail;
            }
        }
    }
    err = func_L39_00510BA8(ctx);
    if (err == 0) {
        return 0;
    }
E_tail:
    return func_L39_0050D5B0(err, item, st[0], -1, out);
C_tail:
    return func_L39_0050D5B0(err, item, st[0], st[3], out);
}
