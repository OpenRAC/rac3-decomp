/* func_003EF2E0 (frontbin), near miss. FE-A1 2026-11-22 (175, frontbin; the boot_elf Codex wave 6 draft 177), NM-FE6
   2026-11-22 (lead: 187), PASS-P5 2026-11-23: 146 differences (tools/check.py) with its file's line
   (src/frontbin/3EE160.c: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses
   @ps2as), the same with --no-context and with --version us. Its twin, boot_elf func_003EF698, is this C with the
   names moved, with the same counts. Unlike func_003EF7F8, split addresses change nothing (--mode S: the same).
   Draws the object's texture as a quad over the rectangle and, with flag 0x40, an offset backdrop in the
   object's background colour first. The colours are 16-byte structs passed by value (by reference under EABI).
   PASS-P5: the backdrop colour `b` is declared at function scope and set from the returning inline inside the
   branch, and the second call rebuilds the colour from `col`'s fields. This gives retail's frame (0x90) and
   four 16-byte slots (175 -> 146).
   Left:
   - retail keeps sp+0x10 in $s3 from just after the first call and passes it to the second func_003972A0
     call; ours keeps sp+0x20 in a saved register and passes it to both calls (their arguments share one temp
     slot before reload, and GCSE holds its address across the calls, the mechanism PASS-P5 removed from
     func_003EF7F8). Retail's second argument shares the slot of the entry's colour temporary instead;
   - the backdrop: retail stores the background colour four times at 0x10, word-copies it to 0x30 (through
     four registers) and ldl/sdl-copies that to the argument at 0x20; ours builds it at 0x20 and makes two
     ldl/sdl copies (0x20 -> 0x10 -> 0x20). The second call: retail copies col (0x00) by words to 0x20, then
     ldl/sdl to 0x10; ours copies to 0x30, then to 0x20;
   - the order of the float loads of the first block (r[1] first in ours).
   Tried without gain (PASS-P5, about 80 compiles): the colour inline returning a compound literal (185-189); the
   draw helper taking four u32s with the backdrop chained or built through the inline (182-195); `b` chained in
   the branch or at function scope (162-189); the helper copying its parameter into a local, or taking a pointer
   (185-195); the colour declared and assigned apart (no change). */
#include "common.h"
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
extern f32 D_001D9698;
extern f32 D_001D969C;
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
    Col_3EF2E0 b;
    if (func_003EDAF8(o, 0x40)) {
        b = col_3EF2E0(o->bg, o->bg, o->bg, o->bg);
        draw_3EF2E0(tex, b, r[0] + o->ox, r[1] + o->oy, r[2] + o->ox, r[3] + o->oy, o->depth);
    }
    draw_3EF2E0(tex, col_3EF2E0(col.c0, col.c1, col.c2, col.c3), r[0], r[1], r[2], r[3], o->depth);
}
/* localdecomp:end func_003EF2E0 */
