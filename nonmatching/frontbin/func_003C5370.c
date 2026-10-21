/* US draft of func_003C5370 (rac3-uya-decomp func_003BFE08, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C5370 */
extern void func_0038CE90(f32 *, f32 *, s32);
extern void func_0038D810(f32 *, f32 *);
extern void func_0038D5F0(s32, f32 *, s32);
extern void func_0038CC88(s32, f32 *, s32);
void func_003C5370(s32 a, f32 *unused, s32 c) {
    f32 m[12];
    f32 b[4];
    f32 v[4];
    f32 r;
    ((void (*)(f32 *, f32))func_0038CF68)(v, 1.0f);
    func_0038CE90(b, v, a + 0x20);
    ((void (*)(f32 *, f32 *, f32))func_0038CE20)(b, b, 0.5f);
    r = func_0038CEA8((s32)b);
    r = 1.0f - r * r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(r));
    b[3] = -r;
    func_0038D810(b, m);
    func_0038D5F0(a, m, a);
    if (c) func_0038CC88(c, m, 0x30);
}
/* localdecomp:end func_003C5370 */
