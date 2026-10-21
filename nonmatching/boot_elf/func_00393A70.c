/* US draft of func_00393A70 (rac3-uya-decomp func_003939B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00393A70 */
typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_00332230[];
extern f32 D_00332290[];
void func_00393A70(S_38EE58 *o, s32 *px, s32 *py, s32 v, s32 d) {
    s32 dx = 0;
    s32 dy = 0;
    f32 sc;
    u32 fl;
    if (o->f7C) v -= d; else v += d;
    if (v < 0) v = 0;
    if (v >= 0x18) v = 0x17;
    if (o->f7C) sc = D_00332230[v]; else sc = D_00332290[v];
    fl = o->f60;
    if (fl & 1) dy = -(s32)(sc * ((f32)o->f5C + 52.0f) + 0.5f);
    else if (fl & 2) dy = (s32)(sc * ((f32)o->f5C + 52.0f) + 0.5f);
    else if (fl & 4) dx = -(s32)(sc * ((f32)o->f58 + 20.0f) + 0.5f);
    else if (fl & 8) dx = (s32)(sc * ((f32)o->f58 + 20.0f) + 0.5f);
    *px += dx;
    *py += dy;
}
/* localdecomp:end func_00393A70 */
