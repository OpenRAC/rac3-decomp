/* US draft of func_0013C908 (rac3-uya-decomp func_0013C908, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013C908 */
__asm__(".extern D_001D4DE0, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DC0, 8");
__asm__(".extern D_001D4DC8, 8");
__asm__(".extern D_001D4DD8, 8");
void func_0013C908(void) {
    s32 idx;

    func_0013B8B0((s32 *)D_001D4DD8[D_001D4DE0], *D_001D4DC0[D_001D4DE0]);
    while (func_00122A10(&D_1D4900) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0011F0A0(0);
    }
    func_00122810(&D_1D4900, 0x4D, 1, D_001D4DC0[D_001D4DE0], 0x1000 - D_001D4DC8[D_001D4DE0],
                  D_001D4DD8[D_001D4DE0], *D_001D4DC0[D_001D4DE0] * 4 + 8, 0, 0);
    idx = D_001D4DE0 != 1;
    D_001D4DE0 = idx;
    *D_001D4DC0[idx] = 0;
    D_001D4DC8[idx] = 0xFFC;
}
/* localdecomp:end func_0013C908 */
