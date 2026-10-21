/* Near miss of func_0039A148 with its file's own flags: tools/check.py reports 42 diff
   (the version it replaces: 57).
*/

/* PAL candidate for func_0039A148 (rac3-uya-decomp func_0039A030, commit 13cf5c5).
   Retail reaches the counters with two different address forms: the else
   branch's counter and the if branch's read go through lui/lo, the if
   branch's write goes through $gp.  An unsized array declaration is never
   small data (so it gets lui/lo); the sized one the file already declares
   is (so it gets $gp).  Retail builds the counter's address again for every
   access (no commoning of the %hi part), so each access gets its own
   unsized alias. */

/* localdecomp:start func_0039A148 */
typedef struct { u8 p[0x2D]; u8 b2D; } S_4F78;
extern u8 D_002DB190[];
extern s16 D_002DAFB0[];
extern s32 D_002DA740[];
extern s32 D_002DDC30[];
extern s32 D_001DA480_0039A148[];
extern s32 D_001DA480_b_0039A148[];
extern s32 D_001DA480_l_0039A148[];
extern s32 D_001DA480_s_0039A148[];
extern s32 D_001DA484_0039A148[];
extern s32 D_001DA484_b_0039A148[];
extern void func_00399E28(s32, s32, void *, s32);
extern void func_003CD318();
void func_0039A148(S_4F78 *a, s32 b, void *c, s32 d) {
    if (a == 0) {
        func_003CD318(d, 1);
        D_002DB190[d] = D_001DA484_b_0039A148[0];
        D_001DA484 = D_001DA484_0039A148[0] + 1;
    } else {
        D_002DAFB0[D_001DA480_0039A148[0]] = d;
        D_002DB190[d] = D_001DA480_b_0039A148[0];
        D_002DA740[D_001DA480_0039A148[0]] = (s32)a;
        D_002DDC30[D_001DA480_0039A148[0]] = a->b2D << 10;
        if (a->b2D == 0xFF) D_002DDC30[D_001DA480_0039A148[0]] = 0x100000;
        func_00399E28((s32)a, b, c, d);
        func_003CD318(d, 0);
        D_001DA480_s_0039A148[0] = D_001DA480_l_0039A148[0] + 1;
    }
}
/* localdecomp:end func_0039A148 */
