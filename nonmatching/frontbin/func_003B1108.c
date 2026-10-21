/* Near miss of func_003B1108 with its file's own flags: tools/check.py reports 12 diff
   (the version it replaces: 33).
   What differs: Both D_001DA0B8 loads now reach the global through %hi/%lo (lui + lo) instead
   of $gp, and the whole function matches otherwise (52 instructions, same frame, same delay
   slots). What is left: GCC puts the %hi base of each load in its own register ($a2 for the
   first load, $v1 for the second) instead of coalescing it with the destination $a0, so we get
   `lui $a2, 0x1e` + `lw $a0, -0x5f48($a2)` and `lui $v1, 0x1e` + `lw $a0, -0x5f48($v1)` where
   retail has `lui $a0, 0x1e` + `lw $a0, -0x5f48($a0)` twice (12 diff). Cause: with this file's
   flags (split addresses on) ee-gcc 2.95.3 always expands a...
*/

/* func_003B1108 (frontbin, PAL).
   The US draft (rac3-uya-decomp func_003ABB60, commit 13cf5c5) matched only with `@ps2as`;
   with this file's own flags it must reach D_001DA0B8 through lui/lw instead of $gp.
   Retail reaches it with %hi/%lo, so the global is declared without a size (the "_r"
   spelling: an incomplete type cannot go into small data under -G8), which keeps GCC
   from using the $gp-relative form the sized declaration gives.
   The two accesses get separate names ("_r1", "_r2"): retail reloads the address for
   each of them (lui+lw twice), while one name would let GCC keep a single address
   computation alive across the calls in between (that costs a $s4 and a bigger frame). */

/* localdecomp:start func_003B1108 */
extern s32 D_001DA0B8_r1[];
extern s32 D_001DA0B8_r2[];
extern s32 func_003B11D8();
s32 func_003B1108(s32 unused, O_ABB60 *obj, u8 *buf) {
    s32 v[4];
    s32 a0, a1, a2, a3;
    s32 t, q, q2, w, res;
    u32 p, end;
    t = *(s32 *)(buf + 0x50008);
    p = obj->f8 + 4;
    end = (u32)buf + t;
    p = (p >= end) ? p - t : p;
    q = obj->fC - 4;
    w = end - p;
    w = (q < w) ? q : w;
    q2 = q - w;
    func_003B0218(D_001DA0B8_r1[0], v, &v[1], &v[2], &v[3]);
    a1 = v[1];
    a0 = v[0];
    a2 = v[2];
    a3 = v[3];
    res = func_003B11D8(a0, a1, a2, a3, p, w, buf, q2);
    func_003B02E8(D_001DA0B8_r2[0], res);
    return res > 0;
}
/* localdecomp:end func_003B1108 */
