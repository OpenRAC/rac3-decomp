#include "common.h"

/* func_L39_004E3FC0 (first draft, fresh entry; wave 13b r31): an RSA-style "mode 4 or 9" operation of
   level 39's crypto library (siblings func_L39_004E3B68 / func_L39_004E3CB8). 57 diff under the file's
   line (p10/check.py). Calls, arguments, frame (a at sp+0, b at sp+0x20, a7 spilled at 0x40, ret at 0x44)
   and the register map (s0 ctx/len, s1 key, s2 &b, s3 blind, s4 flen, s5 tlen, s6 from, s7 to, fp outlen)
   are retail's.
   - Prototype correction needed: the file declares `extern void func_L39_004FC780(s32, u32, N_004E3B68 *)`,
     but retail tests v0 after the jal (BN_bin2bn, defined `void *func_L39_004FC780(const u8 *, s32, ...)`
     in L39_004FC3C8.c). This draft uses the same cast as the matched sibling func_L39_004E3CB8; without a
     corrected prototype the test cannot be written.
   - Retail keeps ret in a stack slot: ee29's local-alloc doubles a pseudo's live length for every
     constant set (.lreg dump: ret 55 -> 220 insns with two `ret = 1`), and ret only drops below outlen
     and a7 with three constant sets (x8 = 440). With only the two sets retail stores (start, length
     error), ret takes s7 and outlen/to are spilled instead (91 diff). This draft adds the third set on
     the blind == 0 path (behaviour unchanged: ret is already 1 there), which gives retail's allocation.
   - What still differs: that extra `ret = 1` keeps its `li v0,1` (blind == 0 branches to the shared
     store instead of straight past the free), and the error block is folded into the store after the
     f4 call (dbr: `bnez -> sw` with li in the slot) where retail keeps `b L_14C; sw v0,0x44(sp)` with
     the li in both check branches' slots; one instruction longer, the rest shifted. Also tried: ret = 1
     after the mode check, no store on the error path, nested ifs, split length checks (two error blocks:
     60 diff, both folded into the f4 store), `n <= len` block, f4 returning long (adds dsll/dsra). */

/* localdecomp:start func_L39_004E3FC0 */
typedef struct V_004E3FC0 {
    s32 _p0;
    s32 (*f4)(u8 *, u32 *, u8 *, s32, s32, s32);
} V_004E3FC0;

typedef struct K_004E3FC0 {
    s32 f0;
    s32 f4[17];
    s32 f48;
    s32 f4C;
    s32 _p50;
    s32 f54;
    V_004E3FC0 *f58;
} K_004E3FC0;

typedef struct S_004E3FC0 {
    s32 _p0[2];
    K_004E3FC0 *f8;
} S_004E3FC0;

s32 func_L39_004E3FC0(void *ctx, s32 mode, u8 *to, u32 *outlen, s32 tlen, void *from, s32 flen, s32 a7) {
    N_004E3B68 a;
    N_004E3B68 b;
    K_004E3FC0 *key;
    B_004E3CB8 *blind;
    s32 len;
    s32 n;
    s32 ret;

    ret = 1;
    blind = 0;
    if (mode != 4 && mode != 9) {
        return 2;
    }
    func_L39_004FC370(&a);
    func_L39_004FC370(&b);
    key = ((S_004E3FC0 *)ctx)->f8;
    len = (func_L39_004FC158(key->f4) + 7) / 8;
    if ((u32)tlen < (u32)len || (u32)len < (u32)flen) {
        ret = 1;
        goto done;
    }
    blind = func_L39_004FC3C8();
    if (blind == 0) {
        ret = 1;
        goto done;
    }
    blind->f10C = key->f4C;
    if (((void *(*)(s32, u32, N_004E3B68 *))func_L39_004FC780)((s32)from, flen, &a) == 0) {
        goto done;
    }
    ret = func_L39_004FCE30(key->f54, &b, &a, 0, 0, blind);
    if (ret != 0) {
        goto done;
    }
    n = func_L39_004FC8C0(&b, (s32)to);
    if (len < n) {
        goto done;
    }
    ret = key->f58->f4(to, outlen, to, n, len, a7);
done:
    if (blind != 0) {
        func_L39_004FC448(blind);
    }
    func_L39_004FC228(&b);
    func_L39_004FC228(&a);
    return ret;
}
/* localdecomp:end func_L39_004E3FC0 */
