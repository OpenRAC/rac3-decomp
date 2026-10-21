/* Near miss of func_00393898 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 8).
   What differs: 3 words still differ, all from the address materialization: retail is split-
   address code (`lui $v0, %hi(D_00331AE0)` / `sd $ra,0($sp)` / `addiu $v1, $v0,
   %lo(D_00331AE0)`), but this file's `-mno-split-addresses` makes gcc emit the address as one
   `la` pseudo, which the assembler expands into `lui $v1, %hi(D)` + `addiu $v1, $v1, %lo(D)`
   (both halves in one register, adjacent, so the `$ra` save cannot fall between them). The
   split form is unreachable in N mode from plain C.
*/

/* US draft of func_00393898 (rac3-uya-decomp func_003937D8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */

/* localdecomp:start func_00393898 */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern void func_00393728();
s32 func_00393898(s32 id) {
    S_38ED78 *p = D_00331AE0;
    s32 i;
    for (i = 0; i < 13; i++) {
        if (p[i].id == id) break;
    }
    if (i < 13) {
        func_00393728(i, 0xFFFF, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00393898 */
