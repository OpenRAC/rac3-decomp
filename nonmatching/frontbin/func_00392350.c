/* Near miss of func_00392350 with its file's own flags: tools/check.py reports 24 diff
   (the version it replaces: 31).
   What differs: Everything now matches except the `a == 0` arm of the inner if: gcc emits
   `addiu $v0, $v0, 0x7b0` before the `b` and duplicates the `sw $v0, 4($v1)` into that arm
   (tail merging), while retail puts the `addiu` in the branch delay slot and keeps one shared
   `sw $v0, 4($v1)` at the merge point. That makes the function 33 instructions instead of 32
   and shifts the branch offsets (ours `beqz 0x74` / `bnez 0x20` / `b 0x1c`, retail `beqz 0x70`
   / `bnez 0x1c` / `b 0x18`). All 32 retail words otherwise match: lui/lw addressing of
   D_001DA050 (0x1DA050) instead of $gp, the per-store reloads of the...
*/

/* PAL candidate for func_00392350 (frontbin, src/frontbin/38DED0.c).

   Retail reaches the pointer global D_001DA050 with lui/lw (an unsized
   symbol), not through $gp, so the global is used here as unsized arrays
   under per-function aliases at the same address (0x1DA050). The stores go
   through the loaded pointer as u32, so every store may alias the global and
   gcc reloads it, like retail does. The write-back reads and writes through
   their own alias, so no address is kept in a register. */

/* localdecomp:start func_00392350 */
extern int D_001DA050_00392350[];
extern int D_001DA050_00392350_b[];
extern int D_001DA050_00392350_g[];
extern u8 D_1D07B0[], D_1D0900[];
void func_00392350(s32 a) {
    u32 *p = (u32 *)D_001DA050_00392350[0];
    if (p != 0) {
        p[0] = 0x30000015;
        if (a == 0) {
            ((u32 *)D_001DA050_00392350[0])[1] = (u32)D_1D07B0;
        } else {
            ((u32 *)D_001DA050_00392350[0])[1] = (u32)D_1D0900;
        }
        ((u32 *)D_001DA050_00392350[0])[2] = 0;
        ((u32 *)D_001DA050_00392350[0])[3] = 0x50000015;
        D_001DA050_00392350_g[0] = (u32 *)D_001DA050_00392350_b[0] + 4;
    }
}
/* localdecomp:end func_00392350 */
