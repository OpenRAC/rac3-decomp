/* Near miss of func_00391328 with its file's own flags: tools/check.py reports 2 diff
   (the version it replaces: 21).
*/

/* func_00391328: frontbin, src/frontbin/38DED0.c.
   The plain name D_001D5520 is sized, so gcc reaches it through $gp; retail reads
   the same address with lui/lw, so the read uses an unsized alias (never small data). */

extern s32 D_00143950[];
extern s32 D_001D5520;
extern s32 D_001D5520_00391328[];
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);

void func_00391328(void) {
    s32 v;
    func_12A950();
    v = D_00143950[0];
    if (v) D_001D5520 = 0;
    if (D_001D5520_00391328[0]) {
        func_12BEE8(0, 0, 0x50, 1);
    } else {
        func_12BEE8(0, 1, v ? 3 : 2, 0);
    }
}
