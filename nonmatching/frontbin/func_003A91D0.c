/* US draft of func_003A91D0 (rac3-uya-decomp func_003A3C80, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A91D0 */
__asm__(".extern D_001D8014_003A91D0, 4");
__asm__(".extern D_001DA060_g_003A91D0, 4");
extern s32 D_001D8014_003A91D0;
extern s32 D_001DA060_g_003A91D0;
extern s32 D_001DA060_003A91D0;
extern s32 D_001DA058_003A91D0;
extern s32 D_001DA05C_003A91D0;
extern s32 D_001DA048_003A91D0[];
extern u32 *D_001DA050_003A91D0;
extern s32 *func_12D650();
extern void func_12D938();
extern void func_11F0A0();
extern void func_003D9DA8();
extern void func_003A9150();
extern void func_003A92F0(s32);
void func_003A91D0(void) {
    s32 t;
    s32 flags;
    s32 lim;
    s32 c;
    s32 *r;
    t = (s32)D_001DA050_003A91D0 - D_001DA048_003A91D0[D_001DA05C_003A91D0];
    flags = D_001D8014_003A91D0 | 0x1F;
    lim = D_001DA060_003A91D0;
    if (t >= lim) lim = t;
    D_001D8014_003A91D0 = flags;
    c = D_001DA058_003A91D0 < t;
    D_001DA060_g_003A91D0 = lim;
    if (c == 0 || D_001DA05C_003A91D0 == 0) {
        D_001DA050_003A91D0[0] = 0x70000000;
        D_001DA050_003A91D0[1] = 0;
        D_001DA050_003A91D0[2] = 0;
        D_001DA050_003A91D0[3] = 0;
        r = func_12D650(1);
        *r |= 0xC0;
        func_11F0A0(0);
        func_12D938(r, D_001DA048_003A91D0[D_001DA05C_003A91D0]);
        if (c != 0) {
            func_003A92F0(1);
            func_003A9150();
        }
    } else {
        *(volatile s32 *)&D_001D8014_003A91D0 = 0;
        func_003D9DA8();
    }
}
/* localdecomp:end func_003A91D0 */
