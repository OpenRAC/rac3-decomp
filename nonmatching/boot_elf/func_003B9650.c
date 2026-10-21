/* US draft of func_003B9650 (rac3-uya-decomp func_003B9578, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override). */


/* localdecomp:start func_003B9650 */
/* MATCH */
__asm__(".extern D_001D8BA0, 4");
__asm__(".extern D_001D8BA4, 4");
__asm__(".extern D_001D8BA8, 4");
__asm__(".extern D_001D8BAC, 4");
__asm__(".extern D_001D8BB0, 4");
__asm__(".extern D_001D8BB4, 4");
__asm__(".extern D_001D8B60, 8");
extern f32 D_001D8BA0, D_001D8BA4, D_001D8BA8, D_001D8BAC, D_001D8BB0, D_001D8BB4;
extern f32 D_001D8B60[2];
extern f32 D_001D8B64[];
extern f32 D_001D8B68[];
extern f32 D_001D8B6C[];
extern void func_003BB348(s32, void *, void *);
extern s32 func_003B5418(s32);
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8F50(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E8700(s32, s32);
s32 func_003B9650(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f, s32 a8, s32 a9,
                  s32 a10, s32 a11, s32 a12, s32 a13) {
    f32 hi;
    f32 lo;
    s32 ok, i;
    long base; s32 id;
    lo = f;
    func_0038E530(0);
    hi = 1.0f;
    func_003BB348(a9, &hi, &lo);
    ok = func_003B5418(a1) != 0;
    { s32 t = func_003E92A8(a4, 0x35, 0x331465B7, D_001D8BA0, D_001D8BA4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E92A8(a5, 0x36, 0x802299DE, D_001D8BA0, D_001D8BA4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E92A8(a2, 0x33, 0x332299DE, D_001D8BA0, D_001D8BA4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E92A8(a3, 0x34, 0x332299DE, D_001D8BA0, D_001D8BA4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E94F0(a6, 0x331465B7, 0, D_001D8BA0, D_001D8BA4, D_001D8BA8, D_001D8BAC) != 0; ok = ok & t; }
    { s32 t = func_003E9628(a8, 0x332299DE, D_001D8BA0, D_001D8BA4, D_001D8BA8, D_001D8BAC, D_001D8BB0, D_001D8BB4) != 0; ok = ok & t; }
    { s32 t = func_003E8F50(a1, a2, a3, a4, a5, a6, a8) != 0; ok = ok & t; }
    { s32 t = func_003E93A0(a7, a9, 0x8066CCFF, 0.5f, 0.0745f, hi, hi) != 0; ok = ok & t; }
    { s32 t = func_003E89E8(a1, a7) != 0; ok = ok & t; }
    { s32 t = func_003E7BF0(a7, 0x40, 1) != 0; ok = ok & t; }
    if (a10 != 0) {
        { s32 t = func_003E93A0(a10, a11 ? func_003823D0(a11) : 0, 0x8066CCFF, 0.1675f, 0.932f, 0.9f, 0.9f) != 0; ok = ok & t; }
        { s32 t = func_003E7BF0(a10, 0x40, 1) != 0; ok = ok & t; }
        { s32 t = func_003E89E8(a1, a10) != 0; ok = ok & t; }
    }
    if (a12 != 0) {
        { s32 t = func_003E93A0(a12, a13 ? func_003823D0(a13) : 0, 0x8066CCFF, 0.8325f, 0.932f, 0.9f, 0.9f) != 0; ok = ok & t; }
        { s32 t = func_003E7BF0(a12, 0x40, 1) != 0; ok = ok & t; }
        { s32 t = func_003E89E8(a1, a12) != 0; ok = ok & t; }
    }
    base = 0x590000;
    for (i = 0; i < 4; i++) {
        id = i + (s32)base;
        { s32 t = func_003E94F0(id, 0x332299DE, 0, D_001D8B60[i * 4], D_001D8B64[i * 4], D_001D8B68[i * 4], D_001D8B6C[i * 4]) != 0; ok = ok & t; }
        { s32 t = func_003E8200(id, 0xED5A) != 0; ok = ok & t; }
        { s32 t = func_003E89E8(a1, id) != 0; ok = ok & t; }
    }
    {
        s32 t = func_003E8700(a0, a1) != 0;
        return ok & t;
    }
}
/* localdecomp:end func_003B9650 */
