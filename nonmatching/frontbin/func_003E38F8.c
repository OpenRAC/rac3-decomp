/* US draft of func_003E38F8 (rac3-uya-decomp func_003DE3A8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003E38F8 */
__asm__(".extern D_001D94CC, 4");
extern f32 D_001D94CC;
extern f32 D_00222420[];
extern void func_003C4CE8();
extern void func_0038D810();
extern void func_0038D5F0();
void func_003E38F8(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_003C4CE8)(a, D_00222420, *arg0 * (D_001D94CC * 0.017453292f * 0.016666668f));
    func_0038D810(a, b);
    func_0038D5F0(D_00222420, b, D_00222420);
}
/* localdecomp:end func_003E38F8 */
