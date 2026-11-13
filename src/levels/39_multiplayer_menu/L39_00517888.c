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

INCLUDE_ASM("asm/levels", func_L39_00517B64);

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
