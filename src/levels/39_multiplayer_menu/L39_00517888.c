#include "common.h"

/* localdecomp:start func_L39_00517888 */
typedef struct N_00517888 {
    long len;
    u8 *data;
    s32 fC;
    s32 tag;
    u8 flags;
    u8 hdrlen;
    u8 f16;
    u8 f17;
    struct N_00517888 *parent;
    struct N_00517888 *next;
    struct N_00517888 *child;
    s32 f24;
} N_00517888;

typedef struct S_00517888 {
    u32 count;
    u32 cap;
    N_00517888 *nodes;
    s32 flags;
} S_00517888;

extern s32 func_L39_00518150(S_00517888 *, s32 *);
extern s32 func_L39_00518468(N_00517888 *, u8 *, s32);

s32 func_L39_00517888(S_00517888 *ctx, u8 *buf, long len, long *outlen) {
    s32 idx;
    u8 *p = buf;
    u8 *limit = p + (s32)len;
    u8 *end = limit;
    N_00517888 *cur = 0;
    s32 state = 1;
    s32 indef = 0;
    s32 descend = 1;
    s32 prev = -1;
    N_00517888 *node;
    N_00517888 *parent;
    s32 constructed;
    s32 nindef;

    for (;;) {
        switch (state) {
        case 1:
            state = func_L39_00518150(ctx, &idx);
            if (state != 0) {
                goto done;
            }
            node = &ctx->nodes[idx];
            state = func_L39_00518468(node, p, end - p);
            if (state != 0) {
                goto done;
            }
            nindef = node->flags & 2;
            constructed = node->flags & 0x20;
            p += node->hdrlen;
            if (prev == -1) {
                cur = 0;
            } else {
                cur = &ctx->nodes[prev];
            }
            if (descend) {
                node->parent = cur;
                if (cur != 0) {
                    cur->child = node;
                    if (!indef) {
                        end = cur->data + cur->len;
                        if (end < cur->data) {
                            state = 3;
                            goto done;
                        }
                    }
                    indef = cur->flags & 2;
                } else {
                    indef = 0;
                }
                node->next = 0;
            } else {
                N_00517888 *up = cur->parent;
                node->next = 0;
                node->parent = up;
                cur->next = node;
            }
            cur = node;
            descend = 0;
            prev = idx;
            if (cur->tag == 0 && cur->len == 0 && (cur->flags & 0xC0) == 0) {
                if (indef) {
                    state = 2;
                    cur->parent->len = p - cur->parent->data;
                    break;
                }
                state = 0xB;
                goto done;
            }
            if (constructed && (nindef || node->len != 0)) {
                indef = nindef;
                descend = 1;
            } else {
                p += node->len;
                if (p < buf) {
                    state = 3;
                    goto done;
                }
            }
            if (end < p) {
                state = 2;
                goto done;
            }
            state = (p == end) ? 2 : 1;
            if (nindef && !constructed) {
                state = 0xC;
                goto done;
            }
            break;
        case 2:
            parent = cur->parent;
            descend = 0;
            prev += parent - cur;
            cur = parent;
            if (cur == 0) {
                state = 0;
                if (outlen != 0) {
                    *outlen = p - buf;
                }
                goto done;
            }
            parent = cur->parent;
            if (parent != 0) {
                indef = parent->flags & 2;
                if (indef) {
                    end = limit;
                } else {
                    end = parent->data + parent->len;
                    if (end < parent->data) {
                        state = 3;
                        goto done;
                    }
                }
            } else {
                indef = 0;
                end = limit;
            }
            if (end < p) {
                state = 2;
                goto done;
            }
            state = (end == p) ? 2 : 1;
            break;
        }
    }
done:
    return state;
}
/* localdecomp:end func_L39_00517888 */

LINKER_REMNANT("asm/levels", func_L39_00517B68);

LINKER_REMNANT("asm/levels", func_L39_00517B70);

LINKER_REMNANT("asm/levels", func_L39_00517B78);

/* localdecomp:start func_L39_00517B80 */
typedef struct C_00517B80 {
    u8 pad0[8];
    S_00517888 stk;
    u8 pad18[0x30];
    unsigned long regs[16];
    s32 (*cb)(struct C_00517B80 *, s32, unsigned long *, unsigned long, unsigned long, unsigned long);
    s32 cbarg;
    s32 cur;
    s32 append;
    N_00517888 *node;
} C_00517B80;

extern u8 D_L39_00479A60[];
extern u8 D_L39_00479A68[];
extern void func_L39_005177C0(void *, s32, s32, u8 *, s32, s32, s32);
extern s32 func_L39_00518670(N_00517888 *, long, u8 *);
extern void func_L39_00518440(N_00517888 *, s32);
extern s32 func_L39_00518200(N_00517888 *, N_00517888 *);
extern void func_L39_005181D8(N_00517888 *, N_00517888 *);

s32 func_L39_00517B80(C_00517B80 *ctx, s32 op, s32 ra, s32 rb, s32 rc) {
    unsigned long a, b, c;
    s32 idx;
    s32 ret;
    s32 keep;
    N_00517888 *node;
    u8 *str;

    a = (ra & 0x80) ? *(unsigned long *)((u8 *)ctx + (ra & 0xF) * 8 + 0x48) : ra;
    b = (rb & 0x80) ? *(unsigned long *)((u8 *)ctx + (rb & 0xF) * 8 + 0x48) : rb;
    c = (rc & 0x80) ? *(unsigned long *)((u8 *)ctx + (rc & 0xF) * 8 + 0x48) : rc;
    keep = op & 8;
    if (!keep) {
        ret = func_L39_00518150(&ctx->stk, &idx);
        if (ret != 0) {
            return ret;
        }
        node = &ctx->stk.nodes[idx];
    } else {
        if (ctx->cur < 0) {
            return 2;
        }
        node = &ctx->stk.nodes[ctx->cur];
    }
    switch (op) {
    case 0:
        ctx->node = node;
        if (ctx->cb == 0) {
            return 4;
        }
        ctx->cb(ctx, ctx->cbarg, ctx->regs, a, b, c);
        break;
    case 1:
        ctx->node = node;
        if (ctx->cb == 0) {
            return 4;
        }
        ctx->cb(ctx, ctx->cbarg, ctx->regs, 2, a, b);
        if (node->len != 0 && (node->data[0] & 0x80)) {
            func_L39_00518440(node, 0);
        }
        break;
    case 2:
        func_L39_005177C0(node, a, b, 0, 0, c, 0);
        break;
    case 3:
        func_L39_00518670(node, a, 0);
        break;
    case 4:
        if (a != 0) {
            str = D_L39_00479A60;
        } else {
            str = D_L39_00479A68;
        }
        func_L39_005177C0(node, 0, 1, str, 1, 0, 0);
        return 0;
    case 8:
        node->tag = a;
        node->flags = (b & 0xC0) | (c & 0x2F);
        return 0;
    case 9:
        func_L39_00518440(node, a);
        return 0;
    default:
        return 3;
    }
    if (!keep) {
        if (ctx->cur >= 0) {
            N_00517888 *prev = &ctx->stk.nodes[ctx->cur];
            if (ctx->append) {
                func_L39_00518200(prev, node);
            } else {
                func_L39_005181D8(prev, node);
            }
        }
        ctx->append = 0;
        ctx->cur = idx;
    }
    return 0;
}
/* localdecomp:end func_L39_00517B80 */

/* localdecomp:start func_L39_00517E58 */
typedef struct {
    char _p0[0x30];
    s32 count;
    s32 f34;
    unsigned long *stack;
    s32 f3C;
    s32 f40;
    s32 f44;
    unsigned long regs[16];
} S_00517E58;

extern void *func_L39_004BEF00(void *, s32, s32);

s32 func_L39_00517E58(s32 a0, s32 *buf, s32 n) {
    S_00517E58 *p = (S_00517E58 *)a0;
    s32 i;
    if (p->count + n >= p->f34) {
        unsigned long *s = func_L39_004BEF00(p->stack, (p->f34 * 8) | 6, p->f34 * 8);
        if (s == 0) {
            return 3;
        }
        p->stack = s;
        p->f34 += 6;
    }
    for (i = n - 1; i >= 0; i--) {
        if (buf[i] & 0x80) {
            p->stack[p->count++] = (buf[i] & 0x80) ? *(unsigned long *)((u8 *)p + (buf[i] & 0xF) * 8 + 0x48) : buf[i];
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00517E58 */
