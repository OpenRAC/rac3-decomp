/* Near miss of func_003990F0 with its file's own flags: tools/check.py reports 10 diff
   (the version it replaces: 18).
*/

/* Candidate for func_003990F0 (frontbin, PAL).
 *
 * The retail code loads the two globals with a split address (lui %hi / lw %lo),
 * not through $gp.  With the file's own flags (-G8) GCC only emits that form for
 * a global whose size it does not know, so the globals are declared as arrays of
 * unknown size (the project's declaration rule, docs/us/compiler_matrix_findings.md)
 * and read as SYM[0].
 */

/* localdecomp:start func_003990F0 */
typedef struct { s32 off; s32 x4; } E_394300;
typedef struct { u8 pad[0x18]; E_394300 e[1]; } H_394300;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300;
extern H_394300 *D_001D4B50_0039A150[];
extern G_394300 *D_001D9EA0_00392FD0[];
void func_003A0760(u8 *, u32);
void func_003990F0(s32 a, u32 b) {
    H_394300 *h;
    b = (b + 15) & 0xFFFFFFF0;
    if (b) {
        h = D_001D4B50_0039A150[0];
        func_003A0760((u8 *)(h->e[a + 1].off + (s32)h), b);
    }
    D_001D9EA0_00392FD0[0]->arr[a] = 0;
}
/* localdecomp:end func_003990F0 */
