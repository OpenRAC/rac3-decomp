/* US draft of func_00383380 (rac3-uya-decomp func_0037F0D8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00383380 */
extern u8 D_00222A10_00383380[];
extern u8 D_001D9B10_00383380[8];
extern void func_00383338(u8 *);
extern s32 func_00383128(s32, u8 *, u8 *);
extern void func_00382E10(u8 *, s32);
extern void func_00382D48(s32, void *);
extern void func_00382B20(s32);
s32 func_00383380(s32 a) {
    s32 found = 0;
    s32 i;
    u8 *cur = (u8 *)((S_00222500_0037E7D8 *)(a * 0x460 + (s32)D_00222480))->f50;
    u8 *p;
    u8 *q;
    void (*f)(u8 *);
    f32 *src;
    f32 *dst;
    func_00383338(cur);
    p = (u8 *)(a * 0x2100 + (s32)D_00222A10_00383380);
    q = (u8 *)(a * 0x30 + (s32)D_001D9B10_00383380);
    for (i = 0; i < 48; i++) {
        if (*q != 0 && p != cur && func_00383128(a, p, cur) != 0) {
            cur = p;
            found = 1;
        }
        p += 0xB0;
        q++;
    }
    if (found != 0) {
        func_00382E10(cur, 0);
    }
    f = (void (*)(u8 *))D_00380F80[*(s16 *)(cur + 0x8C)].d;
    func_00382D48(a, cur);
    if (f != 0) {
        f(cur);
    }
    src = (f32 *)(cur + 0x30);
    dst = (f32 *)(cur + 0x64);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    func_00382B20(a);
    return -1;
}
/* localdecomp:end func_00383380 */
