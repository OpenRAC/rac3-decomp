/* US draft of func_0039FA88 (rac3-uya-decomp func_0039AAF0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039FA88 */
typedef struct { u8 p0[0xC]; s32 fC; s32 f10; s32 f14; u8 p1[0x10]; s32 f28; } S_39AAF0;
extern S_39AAF0 D_0022CF80_0039FA88;
extern u32 D_001D545C;
extern s32 D_00143140[];
extern s32 func_003895E8();
extern void func_0039FB48();
void func_0039FA88(void *arg0) {
    S_39AAF0 *p = &D_0022CF80_0039FA88;
    s32 r;
    if (p->f10 != 0) {
        if (p->f28 == 0) {
            func_0038CB78(arg0, 0, 0x800);
            return;
        }
        func_0039F978(D_001D545C);
        r = func_003895E8(arg0, 0x800, p->f14, p->fC);
        if (r == -1) func_0039FB48(arg0);
        if (D_00143140[D_001D545C] < r) D_00143140[D_001D545C] = r;
    }
}
/* localdecomp:end func_0039FA88 */
