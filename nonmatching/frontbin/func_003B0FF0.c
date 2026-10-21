/* Near miss of func_003B0FF0 with its file's own flags: tools/check.py reports 18 diff
   (the version it replaces: 49).
*/

/* Candidate for func_003B0FF0 (PAL retail, frontbin).
   Retail reaches the global at 0x001DA0B4 through two address forms: the
   lui/lw form (three ordinary uses) and the $gp form (the branch-likely delay
   slot).  Under the file's own flags the form follows the declaration's size
   hint, so the address has two names: one hinted big (lui/lw) and one small
   scalar reached through $gp. */

/* localdecomp:start func_003B0FF0 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; unsigned long f10; unsigned long f18; } O_ABA48;
extern s32 D_001DA0B4_003B0FF0;
extern s32 D_001DA0B4_lui;
extern s32 D_001DA0B4_gp;
__asm__(".extern D_001DA0B4_lui, 16");
__asm__(".extern D_001DA0B4_gp, 4");
extern u8 D_001D87C8[];
extern s32 func_003B25A0_003B0FF0();
extern s32 func_003B2648_003B0FF0();
extern s32 func_003B0040();
extern s32 func_003B25C0_003B0FF0();
extern s32 func_003B11D8();
s32 func_003B0FF0(s32 unused, O_ABA48 *obj, u8 *buf) {
    s32 v[4];
    s32 t, p, q, w, q2, n, g;
    t = *(s32 *)(buf + 0x50008);
    p = obj->f8;
    q = obj->fC;
    w = (s32)buf + t - p;
    w = (q < w) ? q : w;
    q2 = q - w;
    func_003B25A0(D_001DA0B4_lui, &v[0], &v[1], &v[2], &v[3]);
    n = func_003B11D8((v[0] & 0xFFFFFFF) | 0x20000000, v[1], (v[2] & 0xFFFFFFF) | 0x20000000, v[3], p, w, buf, q2);
    if (n > 0) {
        if (func_003B2648(D_001DA0B4_lui, obj->f10, obj->f18, v[0], n) == 0) {
            func_003B0040(D_001D87C8);
            g = D_001DA0B4_lui;
        } else {
            g = D_001DA0B4_gp;
        }
    } else {
        g = D_001DA0B4_lui;
    }
    func_003B25C0(g, n);
    return n > 0;
}
/* localdecomp:end func_003B0FF0 */
