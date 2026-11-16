/* NTSC-U draft (Claude wave E): C of func_00139A70 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_00139A70").
 * Study aid: it uses inline asm for EE instructions (move), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: MPEG-PS-style packet loop (bit reader R at sp+0, 0x1BA/0x1B9 start codes, 0xBDFF000000 table entry, two gp-swapped callbacks). @ee29 (the file's own flags): frame 0x150, 9 s-regs + spill slots 0xA0..0xAC all match; 64 of 252 aligned words still differ ...
 */
#include "common.h"
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

static inline void fill_139A70(R_139A70 *rd) {
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
}

s32 func_00139A70(Obj_139A70 *obj, u8 *a1, s32 nbytes, u8 *a3, s32 a4) {
    s32 i = 0;
    R_139A70 rr;
    B_139A70 bb;
    P_139A70 p;
    R_139A70 *r;
    B_139A70 *b;
    s32 arg = 0;
    Ctx_139A70 *ctx = obj->ctx;
    Ent_139A70 *tbl = ctx->tbl;
    s32 ret = 0;
    s32 gp2 = 0;
    s32 (*fn)(void *, void *, s32) = 0;
    s32 ok = 1;
    s32 nbits = nbytes << 3;
    u64 acc;

    rr.size = a4;
    rr.cur = a1;
    rr.rp = a1;
    rr.start = a3;
    rr.end = a3 + a4;
    rr.acc = 0;
    rr.bits = 0;
    rr.fill = 0;
    fill_139A70(&rr);
    r = &rr;
    b = &bb;
    r->bits = 0;
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
        acc = r->acc;
        goto L_D4;
    }
    i = 0;
    if (ctx->count > 0) {
L_T2:
        {
            Ent_139A70 *e = tbl + i;
            if (e->key == (b->h.code & e->mask)) {
                s32 old;
                s32 cur;
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
                __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(old) : "r"(e->gp) : "memory");
                ok = e->fn(obj, &p, e->arg);
                __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(cur) : "r"(old));
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
        s32 old;
        s32 cur;
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
        __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(old) : "r"(gp2) : "memory");
        ok = fn(obj, &p, arg);
        __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(cur) : "r"(old));
    }
    if (ok != 0) {
        ret = (s32)(r->bits >> 3);
    }
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
    if (nbits < (s32)r->bits) {
        return ret;
    }
    if ((s32)(acc >> 32) == 0x1BA) {
        goto L_C0;
    }
    return ret;
}
/* localdecomp:end func_00139A70 */
