/* Near miss of func_003BBD20 with its file's own flags: tools/check.py reports 25 diff
   (the version it replaces: 31).
*/

/* Candidate for func_003BBD20 (boot_elf, PAL retail).
   Plain C: explicit pointer for the sound table, plain do-while poll loop. */


/* localdecomp:start func_003BBD20 */
extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C[];
void func_003BBD20(void) {
    u32 i;
    s32 r;
    s32 *p;
    func_0013CA20();
    i = 1;
    if (i < D_001D8CE0) {
        p = D_001DA1F4;
        do {
            func_0013BF00(*p);
            p++;
            i++;
        } while (i < D_001D8CE0);
    }
    func_0013CA28();
    do {
        r = func_0013B620();
    } while (r);
    func_0013BED0();
    D_001D4B4C[0] = 0;
}
/* localdecomp:end func_003BBD20 */
