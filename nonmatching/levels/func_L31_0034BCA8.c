/* func_L31_0034BCA8 (Claude wave 14 r64, 2026-11-28). First draft kept here. */
/* func_L31_0034BCA8, first draft (fresh entry, wave 14 r64). Plain C under the file's own line; needs the
 * divs metadata 2 2 2 (three div.s with two nops each, no row in config/levels/divs_nops.txt yet).
 * Everything matches except the integer-part test: retail truncates pos once in the FPU (cvt.w.s, then
 * mov.s to keep a copy) and converts it back twice (cvt.s.w f0 for the != 0 test, cvt.s.w f1 for frac),
 * with two sub.s. The vu0.h helper cvtsw_asm is an inline function, so both uses carry the header's
 * line and gcc merges them into one cvt.s.w/sub.s (4 words shorter, then the colour loop's .p2align 3
 * pads a nop): tried frac reassign, empty-then/else, label, do-while(0), two cvtws_asm, -= form: same
 * bytes. D_L31_001E12D0 needs section(".sdata") (as the file's siblings declare it) for retail's
 * sll-before-lui order; col.x = col.y = col.z gives retail's x, z, y store order. */
#include "common.h"

/* localdecomp:start func_L31_0034BCA8 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034BCA8;

typedef struct {
    void *owner;
    u8 pad4[0x4];
    s32 w8;
} Cv_0034BCA8;

typedef struct {
    u8 pad0[0x68];
    Cv_0034BCA8 *vars;
} Child_0034BCA8;

typedef struct {
    u8 pad0[0xD4];
    s32 timer;
    u8 padD8[0x158 - 0xD8];
    Child_0034BCA8 *child;
} Vars_0034BCA8;

typedef struct {
    u8 pad0[0x68];
    Vars_0034BCA8 *vars;
} Moby_0034BCA8;

typedef struct {
    vu0_q colour;
    u8 pad10[0x30];
} Row_0034BCA8;

__asm__(".extern D_L31_001DD250, 4");
__asm__(".extern D_L31_001DD1FC, 4");
extern s32 D_L31_001DD250;
extern f32 D_L31_001DD1FC;
extern void *D_L31_001E12D0[] __attribute__((section(".sdata")));
extern Row_0034BCA8 D_L31_00284130[];

void func_L31_0034BCA8(Moby_0034BCA8 *m) {
    extern s32 func_L01_003303B8(V4_0034BCA8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                                 s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                                 s32, s32);
    extern void func_L31_0034ADF0(Moby_0034BCA8 *, V4_0034BCA8 *, s32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CE20(void *, void *, f32);
    Vars_0034BCA8 *v = m->vars;
    Cv_0034BCA8 *cv = v->child->vars;
    V4_0034BCA8 a;
    V4_0034BCA8 b;
    V4_0034BCA8 col;
    f32 p;
    f32 pos;
    f32 frac;
    f32 d;
    f32 t;
    s32 idx;
    s32 seg;
    s32 i;

    p = 1.0f - (f32)v->timer / (f32)D_L31_001DD250;
    idx = p / 0.0714286f;
    pos = (1.0f - p) * 30.0f;
    if ((cv != 0 && D_L31_001E12D0[idx] == 0) || (cv->owner == m && cv->w8 == 0)) {
        seg = pos;
        func_003C2F58(m, seg, &a);
        func_003C2F58(m, seg + 1, &b);
        t = cvtws_asm(pos);
        if (pos - cvtsw_asm(t) != 0.0f) {
            frac = pos - cvtsw_asm(t);
            func_0038CE20(&b, &b, frac);
            func_0038CE20(&a, &a, 1.0f - frac);
            vec_add_ab(&a, &a, &b);
        }
        func_L01_003303B8(&a, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                          1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L31_0034ADF0(m, &a, idx);
    }
    for (i = 0; i < 30; i++) {
        d = i;
        if (pos < d) {
            D_L31_00284130[i].colour = *(vu0_q *)D_L31_001D66B0;
        } else {
            d = fabs_asm(d - pos) / D_L31_001DD1FC;
            if (1.0f < d) {
                d = 1.0f;
            }
            col.x = col.y = col.z = d;
            D_L31_00284130[i].colour = *(vu0_q *)&col;
        }
    }
}
/* localdecomp:end func_L31_0034BCA8 */
