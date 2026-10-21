/* US draft of func_003EDD40 (rac3-uya-decomp func_003E87D8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003EDD40 */
extern f32 D_001D9698;
extern f32 D_001D969C;
extern void func_003A9500(s32, s32, s32, s32);
void func_003EDD40(f32 a, f32 b, f32 c, f32 d) {
    func_003A9500((s32)(a * D_001D9698), (s32)(c * D_001D9698), (s32)(b * D_001D969C), (s32)(d * D_001D969C));
}
/* localdecomp:end func_003EDD40 */
