/* Near miss of func_00389D60 with its file's own flags: tools/check.py reports 9 diff
   (the US draft it started from: 18).
   What differs: Remaining differences (9 diffs): (1) the counter's address form - retail uses
   the non-split form (`lui $a2, %hi` + `lw $a2, %lo($a2)`, and `lui $at` + `sw` for the
   store), which is what `-mno-split-addresses` or `@ps2as` produce; with this file's split-
   address flags gcc always splits the high half into its own register (`lui $v0` + `lw $a2,
   %lo($v0)`) and the neighbouring retail functions of the same file (0x389D00-0x38A040) all
   use the non-split form, so the file's flags look wrong for this range; (2) the two arguments
   are copied with 64-bit `daddu` in retail (they are 64-bit there) but...
*/

/* func_00389D60: push (a, b) into the pair of tables when the counter allows it.
   The counter is reached through an unsized array (not small data), so it is
   addressed with lui/lw instead of $gp.  A second name for the same address is
   used for the store, so the load and the store do not share the address. */

extern s32 D_001D9C08[];
extern s32 D_001D9C08_00389D60s[];
extern s32 D_00226800_00389D60[];
extern s32 D_00226900[];

void func_00389D60(s32 a, s32 b) {
    s32 i = D_001D9C08[0];
    if (i < 64) {
        D_00226800_00389D60[i] = a;
        D_00226900[i] = b;
        D_001D9C08_00389D60s[0] = i + 1;
    }
}
