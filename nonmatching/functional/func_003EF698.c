/* functional: high. Draws a textured UI rectangle for object o over rect[0..3] (x0,y0,x1,y1): if flag 0x40 is set (func_003EDEB0) first draws a backdrop copy offset by (o+0x20,o+0x24) tinted with o->background in all four corners, then draws the normal copy tinted with o's colours c0..c3; each as func_00397680(texture, colour, centre x, centre y, half width, half height, depth) with coordinates scaled by D_001D9698/D_001D969C and truncated to integers (EE cvt.w.s truncates). Draft verified against PAL asm (fields 0x20/24/28/2C/38..44/48/4A, 0.5 half-size, argument order). Colour struct passed by value as in the draft; retail passes a pointer to a stack copy (same thing for this compiler). */
typedef struct { u32 c0, c1, c2, c3; } Color_003EF698;
typedef struct {
    u8 pad0[0x20];
    f32 offset_x, offset_y;
    u32 background;
    f32 depth;
    u8 pad30[8];
    u32 c0, c1, c2, c3;
    u16 texture, frame;
} Obj_003EF698;
extern f32 D_001D9698;
extern f32 D_001D969C;
static __inline__ Color_003EF698 color_003EF698(u32 a, u32 b, u32 c, u32 d) {
    Color_003EF698 v;
    v.c0 = a; v.c1 = b; v.c2 = c; v.c3 = d;
    return v;
}
void func_003EF698(Obj_003EF698 *o, f32 *rect) {
    extern f32 func_0038DF28(f32);
    extern void func_00397680(s32, Color_003EF698, f32, f32, f32, f32, f32);
    extern s32 func_00396D48(s32, s32);
    extern s32 func_003EDEB0(void *, s32);
    s32 texture;
    Color_003EF698 color;
    texture = func_00396D48(o->texture, o->frame);
    color = color_003EF698(o->c0, o->c1, o->c2, o->c3);
    if (func_003EDEB0(o, 0x40)) {
        Color_003EF698 background;
        f32 x0, y0, x1, y1, half_x, half_y;
        x0 = rect[0] + o->offset_x;
        x1 = rect[2] + o->offset_x;
        y0 = rect[1] + o->offset_y;
        y1 = rect[3] + o->offset_y;
        half_x = (x1 - x0) * 0.5f;
        half_y = (y1 - y0) * 0.5f;
        background.c0 = o->background; background.c1 = o->background;
        background.c2 = o->background; background.c3 = o->background;
        func_00397680(texture, color_003EF698(background.c0, background.c1, background.c2, background.c3),
            (f32)(s32)((x0 + half_x) * D_001D9698), (f32)(s32)((y0 + half_y) * D_001D969C),
            (f32)(s32)(half_x * D_001D9698), (f32)(s32)(half_y * D_001D969C), func_0038DF28(o->depth));
    }
    {
        f32 x0, y0, x1, y1, half_x, half_y;
        x0 = rect[0]; x1 = rect[2]; y0 = rect[1]; y1 = rect[3];
        half_x = (x1 - x0) * 0.5f;
        half_y = (y1 - y0) * 0.5f;
        func_00397680(texture, color_003EF698(color.c0, color.c1, color.c2, color.c3),
            (f32)(s32)((x0 + half_x) * D_001D9698), (f32)(s32)((y0 + half_y) * D_001D969C),
            (f32)(s32)(half_x * D_001D9698), (f32)(s32)(half_y * D_001D969C), func_0038DF28(o->depth));
    }
}
