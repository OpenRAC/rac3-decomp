/* Near miss of func_00393690 with its file's own flags: tools/check.py reports 27 diff
   (the US draft it started from: 78).
   What differs: Only the table-address materialization differs: mine builds the base as the
   N-mode adjacent pair `lui $v1,0x33` + `addiu $v1,$v1,0x2230` (base in $v1, index in $v0)
   with the index scale after it, retail splits it as `lui $v0,0x33` / `sll $v1,$a3,2` / `addiu
   $v0,$v0,0x2230` (base $v0, index $v1) and adds with `addu $v1,$v1,$v0` (index+base) instead
   of `addu $v0,$v1,$v0`; everything else (clamps, float math, sign handling, the *px/*py
   updates and all register choices outside this block) now matches retail byte for byte (27
   diffs, was 78 for the US draft).
*/

/* Candidate for func_00393690 (PAL retail).
   The table pick is written so that each branch arm builds the table base and
   the byte-scaled index, and the sum plus the load happen after the branch,
   the way retail does. */


/* localdecomp:start func_00393690 */
typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_00332230[];
extern f32 D_00332290[];
void func_00393690(S_38EE58 *o, s32 *px, s32 *py, s32 v, s32 d) {
    s32 dx = 0;
    s32 dy = 0;
    f32 sc;
    u32 fl;
    u8 *tbl;
    s32 idx;
    if (o->f7C) v -= d; else v += d;
    if (v < 0) v = 0;
    if (v >= 0x18) v = 0x17;
    if (o->f7C) { tbl = (u8 *)D_00332230; idx = v * 4; }
    else { tbl = (u8 *)D_00332290; idx = v * 4; }
    sc = *(f32 *)(tbl + idx);
    fl = o->f60;
    if (fl & 1) dy = -(s32)(sc * ((f32)o->f5C + 52.0f) + 0.5f);
    else if (fl & 2) dy = (s32)(sc * ((f32)o->f5C + 52.0f) + 0.5f);
    else if (fl & 4) dx = -(s32)(sc * ((f32)o->f58 + 20.0f) + 0.5f);
    else if (fl & 8) dx = (s32)(sc * ((f32)o->f58 + 20.0f) + 0.5f);
    *px += dx;
    *py += dy;
}
/* localdecomp:end func_00393690 */
