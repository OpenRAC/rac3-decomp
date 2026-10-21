/* US draft of func_0013D290 (rac3-uya-decomp func_0013D290, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_0013D290 */
extern u8 D_001D52E0[];
extern void func_0013CD28(s32, s32, s32, u8 *);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern s32 func_0013CDF0(s32);
s32 func_0013D290(s32 a, s32 b, s32 c) {
    u8 buf[4];
    buf[0] = 0x20;
    buf[1] = D_001D52E0[0];
    buf[2] = 0;
    buf[3] = 0;
    func_0013CD28(a, b, c, buf);
    func_0013CA28();
    func_0013B620();
    return func_0013CDF0(0);
}
/* localdecomp:end func_0013D290 */
