/* US draft of func_003B9EC8 (rac3-uya-decomp func_003B49E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B9EC8 */
typedef struct { u8 p0[0x10]; s32 f10; s32 f14; s32 f18; u8 p1C[4]; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; u8 p58[4]; f32 f5C; f32 f60; u8 p64[8]; f32 f6C; f32 f70; u8 p74[0x28]; u32 f9C; f32 fA0; f32 fA4; u8 pA8[4]; f32 fAC; } S_3B49E8;
extern void func_003E9450();
extern s32 func_003E81F0(s32, f32, f32);
extern void func_003E8E18_003B9EC8(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8958(s32, s32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E9138_003B9EC8(s32, u32, f32, f32, f32, f32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E8348(s32, s32);
void func_003B9EC8(S_3B49E8 *o) {
    s32 j, i;
    u32 k;
    f32 t;
    func_003B9E90((u8 *)o);
    func_003E9450(0x4F00A8);
    func_003E81F0(0x4F00A8, 0.5f, 0.5f);
    func_003E8E18_003B9EC8(0x4F00A8, 1);
    func_003E9450(0x4F00AE);
    func_003E8630(0x4F00A8, 0x4F00AE);
    for (j = 0; j < o->f14; j++) {
        func_003E9450(func_003B9E80((s32)o, j));
        func_003E8630(0x4F00A8, func_003B9E80((s32)o, j));
        for (i = 0; i < o->f10 + 2; i++) {
            func_003E8FE8(func_003B9E50(o, j, i), func_003B9E30(o, j, i), 0x8066CCFF, o->a20[j], o->f50 + (f32)i * o->f54, o->fAC, o->fAC);
            func_003E8898(func_003B9E50(o, j, i), o->a40[j], o->a30[j]);
            func_003E8958(func_003B9E50(o, j, i), 1);
            func_003E7AC8(func_003B9E50(o, j, i), 1);
            func_003E8630(func_003B9E80((s32)o, j), func_003B9E50(o, j, i));
        }
    }
    t = o->f60 - o->fA0;
    if (t < 0.0f) t = 0.0f;
    func_003E9450(0x4F00AD);
    func_003E8630(0x4F00A8, 0x4F00AD);
    o->f9C = o->f10 + 3;
    for (k = 0; k < o->f9C; k++) {
        func_003E9138_003B9EC8(func_003B9E70((s32)o, k), 0x331465B7, o->f5C, o->f50 + (f32)(k - 1) * o->f54 + o->f70, t, o->fA4, 0);
        func_003E8630(0x4F00AD, func_003B9E70((s32)o, k));
    }
    func_003E9138_003B9EC8(0x4F00AF, 0x706EC8FF, 0.5f, 0.5f, 1.0f, 0.1f, 0);
    func_003E8630(0x4F00AE, 0x4F00AF);
    func_003E8EF0(0x4F00B0, 0x80, 0x331465B7, 0.5f, 0.5f, 1.0f, 0.6f, o->f6C);
    func_003E8EF0(0x4F00B1, 0x80, 0x331465B7, 0.5f, 0.5f, 1.0f, -0.6f, o->f6C);
    func_003E8A08(0x4F00AE, 0x4F00B0, 0x4F00B1);
    func_003E9138_003B9EC8(0x4F00B3, 0x70000000, 0.5f, 0.5f, 0.25f, 0.25f, 0);
    func_003E7A18(0x4F00B3, 0);
    func_003E8630(0x4F00A8, 0x4F00B3);
    func_003E8348(o->f18, 0x4F00A8);
}
/* localdecomp:end func_003B9EC8 */
