/* func_003EFBB0 (boot_elf), FE-A1 2026-11-22: near miss, from Flavius's functional draft
   (nonmatching/functional/func_003EFBB0.c) with plain division and the visibility test as one expression.
   220 differences (tools/check.py) with its file's line (src/boot_elf/text/3EF658.c: -mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as), the same with --no-context (the functional
   draft: 244). Its frontbin twin func_003EF7F8 (3EE160.c, same flags) is the same code, not compiled here.
   The file has -mno-check-zero-division, so retail's four `div` have no zero test: plain `/`.
   Left: retail lays the jump table's cases out as 0, 4, 2, 3, 1 (the source order 0, 4, 2, 3, 1 aligns the code
   better but gives 222); it copies the colour struct into the call's slot at sp+0x10 through a temporary at sp+0x20
   (frame 0x70) where ours passes the local; register choice of the four alphas. */
/* localdecomp:start func_003EFBB0 */
typedef struct { u32 c0, c1, c2, c3; } Color_003EFBB0;
typedef struct VT_003EFBB0 {
    u8 pad[0x20];
    void (*fill)(void *o, s32 a1, f32 *rect, s32 one);
} VT_003EFBB0;
typedef struct CVT_003EFBB0 {
    u8 pad[8];
    void (*fade)(void *c, s32 v);
} CVT_003EFBB0;
typedef struct { s32 f0; CVT_003EFBB0 *vt4; } Child_003EFBB0;
typedef struct {
    u8 pad0[8];
    VT_003EFBB0 *vt;
    u8 padC[0x14];
    f32 offx, offy;
    s32 background;
    u8 pad2C[0xC];
    u32 col0, col1, col2, col3;
    u16 count;
    u8 pad4A[2];
    u8 max, t, state;
    u8 pad4F;
    Child_003EFBB0 *child;
} Obj_003EFBB0;
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
extern s32 func_003EDEB0(void *, s32);
extern void func_003EE0A8(void *, f32 *);
extern s32 func_003EF998(void *, f32 *);
extern void func_003EF698(void *, f32 *);
extern void func_0038C6F0(s32, s32, s32, s32, s32, Color_003EFBB0);

void func_003EFBB0(Obj_003EFBB0 *o, s32 a1)
{
    f32 rect[4];
    s32 invisible = 0;
    u32 c0 = o->col0, c1 = o->col1, c2 = o->col2, c3 = o->col3;
    u32 al0, al1, al2, al3;
    s32 diff;

    if (o->child != 0) {
        al0 = c0 >> 24;
        al1 = c1 >> 24;
        al2 = c2 >> 24;
        al3 = c3 >> 24;
        if (o->state < 5) {
            switch (o->state) {
            case 0:
                o->t = 0;
                goto scaled;
            case 4:
                o->t = o->t + 1;
                if (o->max < o->t) {
                    o->t = o->max;
                    o->state = 2;
                }
                goto fade;
            case 1:
                o->t = o->t - 1;
                if (o->t == 0) {
                    o->state = 0;
                    o->t = 0;
                }
                goto fade;
            case 2:
                o->child->vt4->fade(o->child, o->count - 1);
                o->state = 3;
                /* fall through to state 3 */
            case 3:
                o->t = o->max;
                if ((o->child->f0 ^ 2) == 0) {
                    o->state = 1;
                }
                al3 = 0;
                al2 = 0;
                al1 = 0;
                al0 = 0;
                goto scaled;
            }
        }
        goto scaled;
    fade:
        diff = o->max - o->t;
        al3 = (u8)((s32)(al3 * diff) / o->max);
        al0 = (u8)((s32)(al0 * diff) / o->max);
        al1 = (u8)((s32)(al1 * diff) / o->max);
        al2 = (u8)((s32)(al2 * diff) / o->max);
    scaled:
        invisible = al0 == 0 && al1 == 0 && al2 == 0 && al3 == 0;
        o->col0 = (al0 << 24) | (c0 & 0xFFFFFF);
        o->col1 = (al1 << 24) | (c1 & 0xFFFFFF);
        o->col2 = (al2 << 24) | (c2 & 0xFFFFFF);
        o->col3 = (al3 << 24) | (c3 & 0xFFFFFF);
    }

    o->vt->fill(o, a1, rect, 1);
    func_003EE0A8(o, rect);
    if (!invisible) {
        s32 more = 1;

        if (o->count != 0) {
            if (o->child != 0) {
                more = func_003EF998(o, rect);
            } else {
                func_003EF698(o, rect);
                more = 0;
            }
        }
        if (more != 0) {
            if (func_003EDEB0(o, 0x40)) {
                Color_003EFBB0 bg;
                f32 x0 = rect[0] + o->offx, x1 = rect[2] + o->offx;
                f32 y0 = rect[1] + o->offy, y1 = rect[3] + o->offy;

                bg.c0 = bg.c1 = bg.c2 = bg.c3 = o->background;
                func_0038C6F0((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                              (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, bg);
            }
            {
                Color_003EFBB0 col;

                col.c0 = o->col0;
                col.c1 = o->col1;
                col.c2 = o->col2;
                col.c3 = o->col3;
                func_0038C6F0((s32)(rect[0] * D_001D9698), (s32)(rect[1] * D_001D969C),
                              (s32)(rect[2] * D_001D9698), (s32)(rect[3] * D_001D969C), 0, col);
            }
        }
    }
    if (o->child != 0) {
        o->col3 = c3;
        o->col0 = c0;
        o->col1 = c1;
        o->col2 = c2;
    }
}
/* localdecomp:end func_003EFBB0 */
