/* US draft of func_003C5728 (rac3-uya-decomp func_003C55C8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C5728 */
extern void func_0038D270(f32 *, f32 *, s32);
extern void func_0038DBF0(f32 *, f32 *);
extern void func_0038D9D0(s32, f32 *, s32);
extern void func_0038D068(s32, f32 *, s32);
void func_003C5728(s32 a, f32 *unused, s32 c) {
    f32 m[12];
    f32 b[4];
    f32 v[4];
    f32 r;
    ((void (*)(f32 *, f32))func_0038D348)(v, 1.0f);
    func_0038D270(b, v, a + 0x20);
    ((void (*)(f32 *, f32 *, f32))func_0038D200)(b, b, 0.5f);
    r = func_0038D288((s32)b);
    r = 1.0f - r * r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(r));
    b[3] = -r;
    func_0038DBF0(b, m);
    func_0038D9D0(a, m, a);
    if (c) func_0038D068(c, m, 0x30);
}
/* localdecomp:end func_003C5728 */
