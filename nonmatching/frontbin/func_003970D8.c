/* Near miss of func_003970D8 with its file's own flags: tools/check.py reports 2 diff
   (the US draft it started from: 91).
   What differs: only the 64-bit draw tag's two middle instructions differ: gcc (ee-gcc2953,
   file flags `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-
   addresses`) materialises the merged constant 0x7400000000008001 as `lui $t3,0x7400; dsll32
   $t3,$t3,0; ori $t3,$t3,0x8001`, retail has `ori $t3,$zero,0xe800; dsll32 $t3,$t3,0xf; ori
   $t3,$t3,0x8001`; everything else (all lui/lw global accesses, register allocation,
   instruction order, frame, the jal) is byte-identical (2 diff lines out of 106).
*/

/* func_003970D8 (PAL frontbin).
   Retail reaches the globals through lui/lw, so they are declared as unsized
   arrays (never small data); every use gets its own alias so gcc keeps the
   address in the lui/lw form instead of hoisting it into a register. */

/* localdecomp:start func_003970D8 */
extern u32 *D_001DA050_003970D8[];
extern u32 *D_001DA050_q_003970D8[];
extern u32 *D_001DA050_w_003970D8[];
extern u32 *D_001DA050_e_003970D8[];
extern u32 *D_001DA050_z_003970D8[];
extern s32 D_001D4BD0_003970D8[];
extern s32 D_001D4BD0_b_003970D8[];
extern s32 D_001D4BD4_003970D8[];
extern s32 D_001D4BD4_b_003970D8[];
extern s32 D_001D9E94_003970D8[];
extern s32 D_001D9E94_b_003970D8[];
extern s32 func_00396A38_003970D8();
void func_003970D8(s32 tex, s32 x, s32 y, s32 w, s32 h, s32 alpha) {
    unsigned long *q;
    *(u32 *)D_001DA050_003970D8[0] = 0x10000005;
    *(u32 *)(D_001DA050_003970D8[0] + 1) = 0;
    *(u32 *)(D_001DA050_003970D8[0] + 2) = 0;
    *(u32 *)(D_001DA050_003970D8[0] + 3) = 0x50000005;
    q = (unsigned long *)(D_001DA050_q_003970D8[0] + 4);
    D_001DA050_w_003970D8[0] = (u32 *)q;
    q[0] = (0xE800L << 47) | 0x8001L;
    q[1] = 0x5353106;
    q[2] = func_00396A38_003970D8(tex);
    q[3] = 0x156;
    q[4] = ((long)alpha << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0_003970D8[0] - 8) | ((long)(y * 16 + D_001D4BD4_003970D8[0] - 8) << 16)) | ((long)D_001D9E94_003970D8[0] << 32);
    q[7] = (h << 20) + (w << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0_b_003970D8[0] - 8) | ((long)((y + h) * 16 + D_001D4BD4_b_003970D8[0] - 8) << 16)) | ((long)D_001D9E94_b_003970D8[0] << 32);
    q[9] = 0;
    D_001DA050_z_003970D8[0] = D_001DA050_e_003970D8[0] + 0x14;
}
/* localdecomp:end func_003970D8 */
