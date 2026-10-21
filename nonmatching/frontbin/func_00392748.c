/* Near miss of func_00392748 with its file's own flags: tools/check.py reports 65 diff
   (the version it replaces: 71).
   What differs: Split hi/lo addressing for the cursor is solved: declaring it as an array of
   unknown size (`extern u32 *D_001DA050_g[]`, same address 0x001DA050) makes the compiler emit
   retail's `lui %hi(sym); lw/sw %lo(sym)($reg)` instead of the gp-relative `lw off($gp)`,
   while the scalar `D_001DA050` (kept from the file's declarations) gives retail's final gp-
   relative store `sw $v0, -0x2860($gp)` in the return slot (that pair now matches exactly).
   Still differ: (1) the a0 conditional - retail keeps one store at the merge point with the
   two addresses computed in the branches and the cursor reloaded in...
*/

/* PAL candidate for func_00392748 (frontbin).
   Retail addresses the cursor with split hi/lo pairs (lui %hi(sym); lw %lo(sym)($reg)),
   which this compiler only does for symbols whose size it does not know, so the cursor
   is declared as an array.  D_001DA050_g is the same address as D_001DA050 (0x001DA050);
   the scalar declaration of D_001DA050 gives the gp-relative store in the last slot. */

extern u32 *D_001DA050;
extern u32 *D_001DA050_g[];
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];

void func_00392748(s32 a0) {
    ((u32 *)D_001DA050_g[0])[0] = 0x30000002;
    if (a0 != 0) {
        ((u32 *)D_001DA050_g[0])[1] = (u32)&D_001D7370;
    } else {
        ((u32 *)D_001DA050_g[0])[1] = (u32)&D_001D7390;
    }
    ((u32 *)D_001DA050_g[0])[2] = 0;
    ((u32 *)D_001DA050_g[0])[3] = 0x50000002;
    D_001DA050_g[0] = (u32 *)D_001DA050_g[0] + 4;
    ((u32 *)D_001DA050_g[0])[0] = 0x30000029;
    ((u32 *)D_001DA050_g[0])[1] = (u32)&D_001D02D0;
    ((u32 *)D_001DA050_g[0])[2] = 0;
    ((u32 *)D_001DA050_g[0])[3] = 0x50000029;
    D_001DA050_g[0] = (u32 *)D_001DA050_g[0] + 4;
    ((u32 *)D_001DA050_g[0])[0] = 0x30000003;
    ((u32 *)D_001DA050_g[0])[1] = (u32)&D_001D7300;
    ((u32 *)D_001DA050_g[0])[2] = 0;
    ((u32 *)D_001DA050_g[0])[3] = 0x50000003;
    D_001DA050 = (u32 *)D_001DA050_g[0] + 4;
}
