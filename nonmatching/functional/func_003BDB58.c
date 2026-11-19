/* functional: high. Verified vs PAL asm (arg order a0..a3,t0..t3,stack; s32 truncating float conversions, /2 as signed division). Edge: period==0 makes duration 0, retail's `div` then does not trap (-mno-check-zero-division) and the float divide yields FLT_MAX; host C would trap, callers are expected to pass period>0 (guarded below to keep the integer remainder PS2-like). */
typedef struct { u8 pad0[0x78]; s32 field_78; } P_003BDB58;
extern s32 D_1D9D00[];
extern f32 func_0038D490(f32);
extern s32 func_0038DFB8(f32, s32, s32);
void func_003BDB58(P_003BDB58 *p, s32 b, s32 g, s32 r, s32 a, s32 db, s32 dg, s32 dr, s32 period) {
    s32 duration = (period * 5 + 2) / 6;
    s32 rem = duration != 0 ? D_1D9D00[0] % duration : D_1D9D00[0];
    f32 v = func_0038D490(((f32)rem / (f32)duration + (f32)rem / (f32)duration) * 3.1415927410125732f + -3.1415927410125732f);
    r += (s32)(v * (f32)dr) + dr / 2;
    g += (s32)(v * (f32)dg) + dg / 2;
    b += (s32)(v * (f32)db) + db / 2;
    p->field_78 = func_0038DFB8(0.06000000238418579f, p->field_78, (a << 24) | (r << 16) | (g << 8) | b);
}
