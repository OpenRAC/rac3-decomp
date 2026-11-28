/* PAL near miss: 112 raw positional word differences with @ee29 -O2 -G0 (tools/check.py
 * --target boot_elf; Claude Opus, 2026-11-28, from the 130-word regional study of 2026-11-24).
 * The bit reader's setup and first refill are an inline function that ends with bits = 0
 * (retail fills through its own pointer register, $a2, and sets the reader pointer $s1 only
 * after it): the prologue and the refill loop now match word for word. The post-parse length
 * test jumps to the accumulator reload before the start-code tests (retail's bnel steals that
 * load), and the tail is one return. Remaining: ok/nbits and the packet-header pointer/loop
 * index take each other's saved registers ($s5/$s6, $s2/$s3), and the table-search loop's exit
 * reloads the accumulator once where retail loads it on each of its two paths; both shift the
 * words after them. The $gp switches are CpuSwapGp() at both callback sites and match.
 * Not linked; no full-build match is claimed.
 */
#include "common.h"
#include "cpu.h"
/* localdecomp:start func_00139A70 */
typedef struct Ent_139A70 {
    u64 key;
    u64 mask;
    s32 (*fn)(void *, void *, s32);
    s32 arg;
    s32 gp;
    s32 pad1C;
} Ent_139A70;
typedef struct Ctx_139A70 {
    u8 pad0[0x60];
    Ent_139A70 *tbl;
    s32 count;
} Ctx_139A70;
typedef struct Obj_139A70 {
    u8 pad0[0x40];
    Ctx_139A70 *ctx;
} Obj_139A70;
typedef struct R_139A70 {
    u64 acc;
    u64 bits;
    u8 *cur;
    u8 *rp;
    s32 fill;
    u8 *start;
    u8 *end;
    s32 size;
} R_139A70;
typedef struct H_139A70 {
    u64 code;
    u64 f8;
    u64 f10;
    u64 f18;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
} H_139A70;
typedef struct P_139A70 {
    s32 type;
    u8 *p1;
    u8 *p2;
    s32 size;
    u64 v90;
    u64 v98;
} P_139A70;
typedef struct B_139A70 {
    u8 pk[0x18];
    H_139A70 h;
} B_139A70;
extern void func_00137620(R_139A70 *, B_139A70 *);
extern void func_00137CC8(Ctx_139A70 *, R_139A70 *, H_139A70 *);

static inline void init_139A70(R_139A70 *rd, u8 *buf, u8 *start, s32 size) {
    rd->size = size;
    rd->cur = buf;
    rd->rp = buf;
    rd->bits = 0;
    rd->start = start;
    rd->end = start + size;
    rd->acc = 0;
    rd->fill = 0;
    do {
        s32 fill = rd->fill;
        u8 *q = rd->rp;
        rd->acc |= (u64)*q << (0x38 - fill);
        q++;
        rd->rp = q;
        if (!(q < rd->end)) {
            rd->rp = rd->start;
        }
        rd->fill = fill + 8;
    } while (rd->fill < 0x39);
    rd->bits = 0;
}

s32 func_00139A70(Obj_139A70 *obj, u8 *a1, s32 nbytes, u8 *a3, s32 a4) {
    s32 i;
    R_139A70 rr;
    B_139A70 bb;
    P_139A70 p;
    R_139A70 *r;
    B_139A70 *b;
    s32 arg;
    Ctx_139A70 *ctx;
    Ent_139A70 *tbl;
    s32 ret;
    s32 gp2;
    s32 (*fn)(void *, void *, s32);
    s32 ok;
    s32 nbits;
    u64 acc;

    fn = 0;
    ok = 1;
    nbits = nbytes << 3;
    b = &bb;
    ctx = obj->ctx;
    tbl = ctx->tbl;
    arg = 0;
    ret = 0;
    gp2 = 0;
    init_139A70(&rr, a1, a3, a4);
    r = &rr;
    i = 0;
    if (ctx->count > 0) {
L_T1:
        {
            Ent_139A70 *e = tbl + i;
            if (e->key == 0xBDFF000000ULL) {
                fn = e->fn;
                arg = e->arg;
                gp2 = e->gp;
            }
            i++;
            if (fn == 0 && i < ctx->count) {
                goto L_T1;
            }
        }
    }
    acc = r->acc;
    if ((s32)(acc >> 32) != 0x1BA) {
        goto L_CC;
    }
L_C0:
    func_00137620(r, b);
    acc = r->acc;
L_CC:
    if ((acc >> 40) != 1) {
        goto L_E04;
    }
    if ((s32)(acc >> 32) == 0x1BA) {
        goto L_E04;
    }
    if ((s32)(acc >> 32) == 0x1B9) {
        goto L_E04;
    }
L_F8:
    if (!((s32)r->bits < nbits)) {
        goto L_E04;
    }
    if (ok == 0) {
        goto L_E04;
    }
    func_00137CC8(ctx, r, &b->h);
    if (nbits < (s32)r->bits) {
        goto L_DD0;
    }
    i = 0;
    if (ctx->count > 0) {
L_T2:
        {
            Ent_139A70 *e = tbl + i;
            if (e->key == (b->h.code & e->mask)) {
                void *old;
                u8 *x;
                x = r->cur + (b->h.f28 >> 3);
                p.type = 6;
                if (!(x < r->end)) {
                    x -= r->size;
                }
                p.p1 = x;
                x = r->cur + (b->h.f20 >> 3);
                if (!(x < r->end)) {
                    x -= r->size;
                }
                p.p2 = x;
                p.v90 = b->h.f10;
                p.size = b->h.f24;
                p.v98 = b->h.f18;
                old = CpuSwapGp((void *)e->gp);
                ok = e->fn(obj, &p, e->arg);
                CpuSwapGp(old);
                goto L_T2End;
            }
            i++;
            if (i < ctx->count) {
                goto L_T2;
            }
        }
    }
L_T2End:
    if (i == ctx->count && fn != 0) {
        void *old;
        u8 *x;
        x = r->cur + (b->h.f28 >> 3);
        p.type = 6;
        if (!(x < r->end)) {
            x -= r->size;
        }
        p.p1 = x;
        x = r->cur + (b->h.f20 >> 3);
        if (!(x < r->end)) {
            x -= r->size;
        }
        p.p2 = x;
        p.v90 = b->h.f10;
        p.size = b->h.f24;
        p.v98 = b->h.f18;
        old = CpuSwapGp((void *)gp2);
        ok = fn(obj, &p, arg);
        CpuSwapGp(old);
    }
    if (ok != 0) {
        ret = (s32)(r->bits >> 3);
    }
L_DD0:
    acc = r->acc;
L_D4:
    if ((acc >> 40) != 1) {
        goto L_E04;
    }
    if ((s32)(acc >> 32) == 0x1BA) {
        goto L_E04;
    }
    if ((s32)(acc >> 32) != 0x1B9) {
        goto L_F8;
    }
L_E04:
    if (!(nbits < (s32)r->bits) && (s32)(acc >> 32) == 0x1BA) {
        goto L_C0;
    }
    return ret;
}
/* localdecomp:end func_00139A70 */
