/* Near miss of func_0038BA30 with its file's own flags: tools/check.py reports 150 diff
   (the version it replaces: 155).
   What differs: the globals are now reached through lui/%lo exactly as retail does (the draft
   reached them through $gp small data), but gcc hoists the "lui" of a split address to the top
   of the function, so the instruction order and the register allocation differ from retail
   (146 diffs): the frame is 0x40 instead of 0x50, x/y2/t0 land in different registers, and the
   lui/lw pairs sit in front of the float multiplies instead of in the middle of them.
*/

/* Candidate for func_0038BA30 (frontbin, PAL retail).
 *
 * The US draft (rac3-uya-decomp func_003872F8, commit 13cf5c5) matched only with
 * @ps2as; its declarations were "names moved to PAL addresses", which turned the
 * globals into sized scalars.  With the file's own flags (-mvu0-use-vf0-vf2 -O2
 * -G8 -fopt-stack -mno-check-zero-division) a sized scalar is small data and gcc
 * reaches it through $gp:
 *
 *   lw   $t4, -0x7ce0($gp)      # D_001D4BD0
 *   lw   $t5, -0x7cdc($gp)      # D_001D4BD4
 *   lw   $v1, -0x2860($gp)      # D_001DA050
 *
 * Retail reaches all three through lui/%lo instead:
 *
 *   lui  $12, 0x1d
 *   lw   $12, 0x4bd0($12)       # D_001D4BD0
 *   lui  $13, 0x1d
 *   lw   $13, 0x4bd4($13)       # D_001D4BD4
 *   lui  $4,  0x1e
 *   lw   $4,  -0x5fb0($4)       # D_001DA050
 *
 * An unsized array is never small data, so the globals are declared unsized
 * here.  D_001D4BD0/D_001D4BD4 are the plain names the file already uses for
 * them (src/frontbin/382380.c declares them as arrays for func_0038C310), and
 * D_001DA050 needs a name of its own because the file's own declaration of the
 * plain D_001DA050 is a sized scalar.
 *
 * The addressing form now matches retail exactly; what is left is that gcc
 * hoists the "lui" of a split address to the top of the function and
 * re-allocates the registers around it, so the instruction order differs
 * (see work/RESULTS.md).
 */

/* localdecomp:start func_0038BA30 */
extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern s32 D_001DA050_0038BA30[];
s32 func_0038BA30(s32 x, s32 y, s32 w, s32 h, long t0, long t1, long t2, s32 snap,
                  f32 sx, f32 sy, f32 sw, f32 sh, f32 dx, f32 dy) {
    s32 x2, y2;
    s32 U0, U1, V0, V1, U0d, U1d, V0d, V1d;
    long clamp;
    long *p;
    s32 ox, oy, ddx, ddy;
    s32 tx0, tx1;
    f32 ex, ey;
    ex = sx + sw;
    dy = dy * 16.0f;
    dx = dx * 16.0f;
    ox = D_001D4BD0[0];
    U0 = (s32)(sx * 16.0f) + ox - 8;
    ddx = (s32)dx;
    tx0 = x << 4;
    U0d = U0 + ddx;
    U1 = (s32)(ex * 16.0f) + ox - 8;
    oy = D_001D4BD4[0];
    U1d = U1 + ddx;
    ddy = (s32)dy;
    x2 = x + w;
    ey = sy + sh;
    V0 = (s32)(sy * 16.0f) + oy - 8;
    y2 = y + h;
    V1 = (s32)(ey * 16.0f) + oy - 8;
    V0d = V0 + ddy;
    V1d = V1 + ddy;
    tx1 = x2 << 4;
    if (U0 > 0x9000 || U1 < 0x7000 || V0 > 0x9000 || V1 < 0x7000) return 0;
    if (snap) {
        U0 = (U0 & 0xFFF0) + 8;
        U1 = (U1 & 0xFFF0) + 8;
        V0 = (V0 & 0xFFF0) + 8;
        V1 = (V1 & 0xFFF0) + 8;
        U0d = (U0d & 0xFFF0) + 8;
        U1d = (U1d & 0xFFF0) + 8;
        V0d = (V0d & 0xFFF0) + 8;
        V1d = (V1d & 0xFFF0) + 8;
    }
    clamp = 0xA | ((long)x << 4) | ((long)(x2 - 1) << 14) | ((long)y << 24) | ((long)(y2 - 1) << 34);
    p = (long *)D_001DA050_0038BA30[0];
    p[0] = t2;
    p[1] = 0x154;
    p[2] = clamp;
    p[3] = t1;
    p[4] = (y << 20) + tx0;
    p[5] = (long)U0d | ((long)V0d << 16);
    p[6] = (y << 20) + tx1;
    p[7] = (long)U1d | ((long)V0d << 16);
    p[8] = (y2 << 20) + tx0;
    p[9] = (long)U0d | ((long)V1d << 16);
    p[10] = (y2 << 20) + tx1;
    p[11] = (long)U1d | ((long)V1d << 16);
    p[12] = t2;
    p[13] = 0x154;
    p[14] = clamp;
    p[15] = t0;
    p[16] = (y << 20) + tx0;
    p[17] = (long)U0 | ((long)V0 << 16);
    p[18] = (y << 20) + tx1;
    p[19] = (long)U1 | ((long)V0 << 16);
    p[20] = (y2 << 20) + tx0;
    p[21] = (long)U0 | ((long)V1 << 16);
    p[22] = (y2 << 20) + tx1;
    p[23] = (long)U1 | ((long)V1 << 16);
    D_001DA050_0038BA30[0] += 0xC0;
    return 1;
}
/* localdecomp:end func_0038BA30 */
