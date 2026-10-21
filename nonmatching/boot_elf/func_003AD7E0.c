/* US draft of func_003AD7E0 (rac3-uya-decomp func_003AD640, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AD7E0 */
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
extern u8 func_003AD8F0_003AD7E0[];
extern u8 func_003AD928_003AD7E0[];
void func_003AD7E0(S_3A7E80 *s) {
    f32 f;
    s->f18 = 0;
    s->b28 = 0;
    f = s->f18;
    s->f2C = 0;
    s->f80 = 0;
    s->f24 = 0.005f;
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003AD8F0_003AD7E0)(s, 0, f, f, f, f, f);
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003AD8F0_003AD7E0)(s, 1, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    s->f84 = 2;
    ((void (*)(void *, s32, f32, f32))func_003AD928_003AD7E0)(s, 0, f, f);
    s->f20 = 0;
    s->f1C = 1;
}
/* localdecomp:end func_003AD7E0 */
