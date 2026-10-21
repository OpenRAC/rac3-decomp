/* US draft of func_003B36C8 (rac3-uya-decomp func_003AE120, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B36C8 */
__asm__(".extern D_001D545C_gp_003B36C8, 4");
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B36C8;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern void func_003A3FE0(void);
extern s32 func_003A2750(s32);
extern void func_0013BFE0(s32);
extern void func_003A8F50(void);
void func_003B36C8(void) {
    s32 v;
    D_001425AC[0] = 1;
    func_003A3FE0();
    func_003A2750(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003B36C8;
    if (D_001D545C < 2 && D_001D5571 == 0) {
        func_003A8F50();
        return;
    }
    *(volatile s32 *)&D_001D5B74 = 1;
    *(volatile s32 *)&D_001D9D04 = v;
}
/* localdecomp:end func_003B36C8 */
