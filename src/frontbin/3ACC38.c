#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { f32 x, y; } V2_003A7690;
typedef struct { s32 a, b, c, d, e, f; } T6_003A7690;
typedef struct {
    f32 *pos;        
    u8 pad4[4];
    u32 *color;      
    u32 *font;       
    u8 sub10[0x3C];  
    u8 sub4C[0x13C]; 
    s32 w;           
    s32 h;           
    s32 count;       
    u8 pad194[8];
    s32 xoff;        
    u8 pad1A0[4];
    s32 mode;        
    u8 pad1A8[8];
    f32 f1B0;        
    u8 pad1B4[4];
    s32 text[1];     
} O_003A7690;
extern V2_003A7690 D_001D8440[];
extern V2_003A7690 D_001D8448[];
extern f32 D_001D8450;
extern T6_003A7690 D_001D8458[];
extern T6_003A7690 D_001D8470[];
extern s32 D_001D55E8;
extern void func_0038C310_003ACC38(s32, s32, s32, s32, s32, u32 *);
extern void func_003AAED0(void *, f32, f32, f32, f32);
extern void func_003AAFF8(void *, f32, f32, f32, f32);
extern void func_003AB398(void *);
extern void func_0038E150(s32);
extern void func_0038E7E8_003ACC38(unsigned long, s32, s32, f32, f32, f32, f32, s32, s32, unsigned long, f32, f32);
/* localdecomp:start func_003ACC38 */
void func_003ACC38(void *arg0) {
    O_003A7690 *o = arg0;
    u32 cols[4];
    V2_003A7690 a, b;
    T6_003A7690 t1, t2;
    f32 s;
    u32 c, alpha;
    s32 ix, iy, i, lh;

    alpha = *o->color >> 24;
    if ((s32)alpha > 0x60) alpha = 0x60;
    c = *o->color & 0xFFFFFF;
    c |= alpha << 24;
    cols[0] = c;
    cols[1] = c;
    cols[2] = c;
    cols[3] = c;
    func_0038C310_003ACC38(o->pos[0] - o->w, o->pos[1] - o->h, o->pos[0] + o->w + 2.0f, o->pos[1] + o->h, 0xFFFFF0, cols);
    a = D_001D8440[0];
    b = D_001D8448[0];
    s = 1.0f;
    if (o->mode == 0) s = D_001D8450;
    lh = 16;
    i = 0;
    func_003AAED0(o->sub10, o->pos[0] - o->w - a.x, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003AAFF8(o->sub10, -s, s, 0.0f, 0.0f);
    func_003AB398(o->sub10);
    func_003AAED0(o->sub10, o->pos[0] + o->w + a.x + 1.0f, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003AAFF8(o->sub10, s, s, 0.0f, 0.0f);
    func_003AB398(o->sub10);
    func_003AAED0(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003AAFF8(o->sub4C, s, s, 0.0f, 0.0f);
    func_003AB398(o->sub4C);
    func_003AAED0(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003AAFF8(o->sub4C, -s, s, 0.0f, 0.0f);
    func_003AB398(o->sub4C);
    func_003AAED0(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003AAFF8(o->sub4C, s, -s, 0.0f, 0.0f);
    func_003AB398(o->sub4C);
    func_003AAED0(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003AAFF8(o->sub4C, -s, -s, 0.0f, 0.0f);
    func_003AB398(o->sub4C);
    ix = o->pos[0] - o->w + o->xoff;
    iy = o->pos[1] - o->h;
    t1 = D_001D8458[0];
    t2 = D_001D8470[0];
    switch (o->mode) {
    case 0:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                s32 old = D_001D55E8;
                func_0038E150(1);
                func_0038E7E8_003ACC38(*o->font, o->text[i], -1, ix + t2.c, iy + t2.d + i * lh, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
                func_0038E150(old);
            }
        }
        break;
    case 1:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                func_0038E150(1);
                func_0038E7E8_003ACC38(*o->font, o->text[i], -1, ix + t1.c, iy + t1.d + i * lh + 2, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
            }
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_003ACC38 */
