/* NTSC-U draft (Claude wave E): C of func_00135988 as NTSC-U has it, with NTSC-U names and addresses.
 * flags: byte-exact on NTSC-U only with "@ee29 -O2 -G0" (its file's line: "@ee29 @eeas -O2 -G0") (NTSC-U twin "func_00135988").
 * Study aid: it uses inline asm for EE instructions (move), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: sibling of func_00135818 (same ctx at s->f40, same gp-swapped callback table, two `__asm__ __volatile__("move %0, $28
 */
#include "common.h"
/* localdecomp:start func_00135988 */
typedef struct Ctx_135988 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[0x18 - 0xC];
    s32 (*fn)(void *, s32 *, s32);
    s32 pad1C;
    s32 gp;
    u8 pad24[0xC0 - 0x24];
    s32 fC0;
    u8 padC4[0xE8 - 0xC4];
    s32 fE8;
    u8 padEC[0x128 - 0xEC];
    s32 f128;
    s32 pad12C;
    s32 f130;
    u8 pad134[0x184 - 0x134];
    s32 f184;
    u8 pad188[0x878 - 0x188];
    s32 f878;
} Ctx_135988;
typedef struct S_135988 {
    u8 pad0[8];
    s32 f8;
    u8 padC[0x40 - 0xC];
    Ctx_135988 *ctx;
} S_135988;
extern s32 func_00135F08(Ctx_135988 *);
extern s32 func_00134C08(Ctx_135988 *);
extern void func_00136A40(S_135988 *);
extern void func_00136B00(Ctx_135988 *, s32, s32);

s32 func_00135988(S_135988 *s, s32 b, s32 c) {
    Ctx_135988 *ctx = s->ctx;
    s32 r19 = 0;
    s32 r20;
    s32 want;
    s32 loc[8];

    ctx->f130 = 0;
    if (c == -1 || b < c) {
        r19 = 1;
    }
    if (ctx->f8 == 0) {
        s->f8 = 0;
        ctx->f8 = 1;
    }
    if (func_00135560((Obj_00135560 *)ctx, 0) != 0 && r19 != 0) {
        func_00135F08(ctx);
    }
    if (ctx->f878 != 0) {
        return 0;
    }
    ctx->f130 = 1;
    if (func_00134C08(ctx) == 0) {
        func_00136A40(s);
        ctx->f0 = 1;
        return 0;
    }
    want = (ctx->fE8 ^ 1) != 0 ? 1 : 2;
    if (ctx->f184 != want) {
        return -1;
    }
    {
        s32 t = 0;
        if (func_00135560((Obj_00135560 *)ctx, 1) != 0) {
            t = 1;
        }
        r20 = 0;
        if (t != 0 && r19 != 0) {
            if (func_00135F08(ctx) != 0) {
                r20 = 1;
            }
        }
    }
    if (ctx->f878 != 0) {
        return 0;
    }
    func_00136B00(ctx, ctx->f128, ctx->f4);
    ctx->f130 = 0;
    s->f8 = ctx->f128 - ctx->fC0;
    ctx->f128 += 1;
    ctx->f4 += 1;
    if (r19 == 0) {
        loc[0] = 1;
        if (s != 0) {
            Ctx_135988 *t = s->ctx;
            if (t != 0) {
                s32 (*fn)(void *, s32 *, s32) = t->fn;
                if (fn != 0) {
                    s32 old;
                    s32 cur;
                    s32 r;
                    __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(old) : "r"(t->gp) : "memory");
                    r = fn(s, loc, *(s32 *)((u8 *)t + loc[0] * 12 + 0x10));
                    __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(cur) : "r"(old));
                }
            }
        }
    }
    return r20;
}
/* localdecomp:end func_00135988 */
