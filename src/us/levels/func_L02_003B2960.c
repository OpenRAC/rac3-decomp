#include "common.h"

/* NTSC-U counterpart of func_L02_003B4A98 (src/levels/shared/L02_003B4A98.c) */
#include "vu0.h"

/* localdecomp:start func_L02_003B2960 */
typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[4]; f32 f2C; } S_003BE830;
extern s32 D_L02_001DE540;
extern u8 D_L02_001E1300_003B2960[];
extern f32 D_L02_001DDF54;
__asm__(".extern D_L02_001DDF54, 4");
extern f32 D_L02_001DDF58;
__asm__(".extern D_L02_001DDF58, 4");
extern f32 D_L02_001DDF5C;
__asm__(".extern D_L02_001DDF5C, 4");
extern f32 D_L02_001DDF60;
__asm__(".extern D_L02_001DDF60, 4");
extern s32 D_L02_001DDF64;
__asm__(".extern D_L02_001DDF64, 4");
extern s32 D_L02_001DDF68;
__asm__(".extern D_L02_001DDF68, 4");
extern s32 D_L02_001DDF6C;
__asm__(".extern D_L02_001DDF6C, 4");
extern f32 D_L02_001DDF70;
__asm__(".extern D_L02_001DDF70, 4");
extern f32 D_L02_001DDF74;
__asm__(".extern D_L02_001DDF74, 4");
extern s32 D_L02_001DDF78;
__asm__(".extern D_L02_001DDF78, 4");
extern s32 D_L02_001DDF7C;
__asm__(".extern D_L02_001DDF7C, 4");
extern f32 D_L02_001DDF80;
__asm__(".extern D_L02_001DDF80, 4");
extern f32 D_L02_001DDF84;
__asm__(".extern D_L02_001DDF84, 4");
extern s32 D_L02_001DDF88;
__asm__(".extern D_L02_001DDF88, 4");
extern s32 D_L02_001DDF8C;
__asm__(".extern D_L02_001DDF8C, 4");
extern s32 D_L02_001DDF90;
__asm__(".extern D_L02_001DDF90, 4");
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);


/* Ring sprites of the PAL build: the ring brightness runs on (t * 5 + 2) / 6, the 50 Hz time
   of the NTSC-U (0xFF - t) / 255. The helpers are the original's: inline and macro scopes put the
   ring loop over haifa's 100-insn region limit (notes count), so sched1 keeps every block on its
   own (no interblock motion) and loop.c leaves 255 in the loop (the alpha flip stays a branch). */
static inline f32 pulse(s32 j) {
    s32 t = (D_L02_001DE540 + j * 20) & 0xFF;
    {
        s32 p = 255 - t;
        {
            f32 f = 0.5f - (f32)p / 255.0f;
            return fabs_asm(f);
        }
    }
}
static inline f32 ring_scale(S_003BE830 *self, s32 j) {
    f32 base = D_L02_001DDF80 + (f32)j * D_L02_001DDF84;
    {
        f32 k = self->f2C / *(f32 *)(self->p24 + 0x24);
        return base * k;
    }
}
#define LERPCOL(a, b, t) ({ s32 _a = (a), _b = (b); f32 _t = (t); func_003894A0(_a, _b, _t); })
#define SPRITE(p, c, al, x, y, s) ({ s32 _c = (c), _al = (al); f32 _s = (s); func_L01_00468C38(p, _c, _al, x, y, 2, 0, 0, _s); })
static inline void vstep(vu0_v4 *a, vu0_v4 *b) { vec_add_ab(a, a, b); }
static inline s32 ring_alpha(s32 j) {
    s32 v = (u8)D_L02_001DE540;
    if (j & 2) v = v << 1;
    if (j & 1) v = 255 - v;
    return v & 0xFF;
}

void func_L02_003B2960(S_003BE830 *self) {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 w;
    vu0_v4 q;
    vu0_v4 r;
    s32 i;
    s32 j;

    func_003888C8(&pos, &D_L02_001DDF90, (u8 *)self + 0xC0);
    vec_add_ab(&pos, &pos, (u8 *)self + 0x10);
    if (func_0037E1D8(4) == 0) {
        func_L01_00440A88(&vel, D_L02_001DDF54 * 0.016666668f, D_L02_001DDF58 * 0.016666668f);
        func_L01_00468DC0(&pos, &vel, D_L02_001DDF68, D_L02_001DDF70, D_L02_001DDF64, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        for (i = 0; i < 3; i++) {
            func_L01_00440A88(&w, D_L02_001DDF5C * 0.016666668f, D_L02_001DDF60 * 0.016666668f);
            vec_add_ab(&vel, &vel, &w);
            func_L01_00468DC0(&pos, &vel, D_L02_001DDF6C, D_L02_001DDF74, D_L02_001DDF64, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&q, D_L02_001E1300_003B2960, &pos);
    func_00388830(&q, &q, -0.300000012f);
    func_00388830(&r, &q, 0.100000001f);
    vec_add_ab(&q, &q, &pos);
    for (j = 0; j < 4; j++) {
        s32 col = LERPCOL(D_L02_001DDF78, D_L02_001DDF7C, pulse(j));
        SPRITE(&q, col, ring_alpha(j), D_L02_001DDF8C, D_L02_001DDF88, ring_scale(self, j));
        vstep(&q, &r);
    }
}
/* localdecomp:end func_L02_003B2960 */
