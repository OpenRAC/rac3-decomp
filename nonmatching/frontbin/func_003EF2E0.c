/* func_003EF2E0 (frontbin), FE-A1 2026-11-22: new C, near miss. 175 differences (tools/check.py) with its file's line
   (src/frontbin/3EE160.c: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as),
   the same with --no-context. Its boot_elf twin func_003EF698 (3EF658.c, same flags) is the same code: this C with
   the names moved is 175 there too.
   Draws the object's texture as a quad over the rectangle (and, with flag 0x40, an offset backdrop in the object's
   background colour first). The two colour arguments are 16-byte structs passed by value, built through an inline
   that returns the struct, as retail's ldl/ldr copies through stack temporaries show.
   Left: retail keeps &temp (sp+0x10) in $s3 from the prologue on and passes it to the second call (frame 0x90; ours
   0x80 without $s3), copies the background colour into four registers before storing the call's temporary, and
   orders the float loads of the first block differently. Tried: the background as a local with chained or separate
   field stores, the colour copy through another make() call, a pointer to the colour (no change). */
/* localdecomp:start func_003EF2E0 */
typedef struct { u32 c0, c1, c2, c3; } Col_3EF2E0;
typedef struct {
    u8 pad0[0x20];
    f32 ox, oy;
    u32 bg;
    f32 depth;
    u8 pad30[8];
    u32 c0, c1, c2, c3;
    u16 tex, frame;
} Obj_3EF2E0;
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
extern f32 func_0038DB48(f32);
extern void func_003972A0(s32, Col_3EF2E0, f32, f32, f32, f32, f32);
extern s32 func_00396968(s32, s32);
extern s32 func_003EDAF8(void *, s32);
static __inline__ Col_3EF2E0 col_3EF2E0(u32 a, u32 b, u32 c, u32 d) {
    Col_3EF2E0 v;
    v.c0 = a; v.c1 = b; v.c2 = c; v.c3 = d;
    return v;
}
static __inline__ void draw_3EF2E0(s32 tex, Col_3EF2E0 c, f32 x0, f32 y0, f32 x1, f32 y1, f32 depth) {
    f32 hx = (x1 - x0) * 0.5f;
    f32 hy = (y1 - y0) * 0.5f;
    func_003972A0(tex, c, (f32)(s32)((x0 + hx) * D_001D9698), (f32)(s32)((y0 + hy) * D_001D969C),
                  (f32)(s32)(hx * D_001D9698), (f32)(s32)(hy * D_001D969C), func_0038DB48(depth));
}
void func_003EF2E0(Obj_3EF2E0 *o, f32 *r) {
    s32 tex = func_00396968(o->tex, o->frame);
    Col_3EF2E0 col = col_3EF2E0(o->c0, o->c1, o->c2, o->c3);
    if (func_003EDAF8(o, 0x40)) {
        Col_3EF2E0 b = col_3EF2E0(o->bg, o->bg, o->bg, o->bg);
        draw_3EF2E0(tex, b, r[0] + o->ox, r[1] + o->oy, r[2] + o->ox, r[3] + o->oy, o->depth);
    }
    draw_3EF2E0(tex, col, r[0], r[1], r[2], r[3], o->depth);
}
/* localdecomp:end func_003EF2E0 */
