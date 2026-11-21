#include "common.h"

/* NTSC-U counterpart of func_L03_003C4288 (src/levels/03_starship_phoenix/L03_003C3FE0.c) */
#include "vu0.h"
extern u8 D_L03_001E24C0_003C2450[];
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);

/* localdecomp:start func_L03_003C2450 */
typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[4]; f32 f2C; } S_003BE830;
extern s32 D_L03_001DF540;
extern u8 D_L03_001E24C0_003C2450[];
extern f32 D_L03_001DEDA4;
__asm__(".extern D_L03_001DEDA4, 4");
extern f32 D_L03_001DEDA8;
__asm__(".extern D_L03_001DEDA8, 4");
extern f32 D_L03_001DEDAC;
__asm__(".extern D_L03_001DEDAC, 4");
extern f32 D_L03_001DEDB0;
__asm__(".extern D_L03_001DEDB0, 4");
extern s32 D_L03_001DEDB4_003C2450;
__asm__(".extern D_L03_001DEDB4_003C2450, 4");
extern s32 D_L03_001DEDB8_003C2450;
__asm__(".extern D_L03_001DEDB8_003C2450, 4");
extern s32 D_L03_001DEDBC_003C2450;
__asm__(".extern D_L03_001DEDBC_003C2450, 4");
extern f32 D_L03_001DEDC0_003C2450;
__asm__(".extern D_L03_001DEDC0_003C2450, 4");
extern f32 D_L03_001DEDC4_003C2450;
__asm__(".extern D_L03_001DEDC4_003C2450, 4");
extern s32 D_L03_001DEDC8_003C2450;
__asm__(".extern D_L03_001DEDC8_003C2450, 4");
extern s32 D_L03_001DEDCC_003C2450;
__asm__(".extern D_L03_001DEDCC_003C2450, 4");
extern f32 D_L03_001DEDD0_003C2450;
__asm__(".extern D_L03_001DEDD0_003C2450, 4");
extern f32 D_L03_001DEDD4_003C2450;
__asm__(".extern D_L03_001DEDD4_003C2450, 4");
extern s32 D_L03_001DEDD8_003C2450;
__asm__(".extern D_L03_001DEDD8_003C2450, 4");
extern s32 D_L03_001DEDDC_003C2450;
__asm__(".extern D_L03_001DEDDC_003C2450, 4");
extern s32 D_L03_001DEDE0_003C2450;
__asm__(".extern D_L03_001DEDE0_003C2450, 4");
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
static inline s32 pal_time(s32 t) { return (t * 5 + 2) / 6; }
static inline f32 pulse(s32 j) {
    s32 t = (D_L03_001DF540 + j * 20) & 0xFF;
    {
        s32 p = 255 - t;
        {
            f32 f = 0.5f - (f32)p / 255.0f;
            return fabs_asm(f);
        }
    }
}
static inline f32 ring_scale(S_003BE830 *self, s32 j) {
    f32 base = D_L03_001DEDD0_003C2450 + (f32)j * D_L03_001DEDD4_003C2450;
    {
        f32 k = self->f2C / *(f32 *)(self->p24 + 0x24);
        return base * k;
    }
}
#define LERPCOL(a, b, t) ({ s32 _a = (a), _b = (b); f32 _t = (t); func_003894A0(_a, _b, _t); })
#define SPRITE(p, c, al, x, y, s) ({ s32 _c = (c), _al = (al); f32 _s = (s); func_L01_00468C38(p, _c, _al, x, y, 2, 0, 0, _s); })
static inline void vstep(vu0_v4 *a, vu0_v4 *b) { vec_add_ab(a, a, b); }
static inline s32 ring_alpha(s32 j) {
    s32 v = (u8)D_L03_001DF540;
    if (j & 2) v = v << 1;
    if (j & 1) v = 255 - v;
    return v & 0xFF;
}

void func_L03_003C2450(S_003BE830 *self) {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 w;
    vu0_v4 q;
    vu0_v4 r;
    s32 i;
    s32 j;

    func_003888C8(&pos, &D_L03_001DEDE0_003C2450, (u8 *)self + 0xC0);
    vec_add_ab(&pos, &pos, (u8 *)self + 0x10);
    if (func_0037E1D8(4) == 0) {
        func_L01_00440A88(&vel, D_L03_001DEDA4 * 0.016666668f, D_L03_001DEDA8 * 0.016666668f);
        func_L01_00468DC0(&pos, &vel, D_L03_001DEDB8_003C2450, D_L03_001DEDC0_003C2450, D_L03_001DEDB4_003C2450, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        for (i = 0; i < 3; i++) {
            func_L01_00440A88(&w, D_L03_001DEDAC * 0.016666668f, D_L03_001DEDB0 * 0.016666668f);
            vec_add_ab(&vel, &vel, &w);
            func_L01_00468DC0(&pos, &vel, D_L03_001DEDBC_003C2450, D_L03_001DEDC4_003C2450, D_L03_001DEDB4_003C2450, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&q, D_L03_001E24C0_003C2450, &pos);
    func_00388830(&q, &q, -0.300000012f);
    func_00388830(&r, &q, 0.100000001f);
    vec_add_ab(&q, &q, &pos);
    for (j = 0; j < 4; j++) {
        s32 col = LERPCOL(D_L03_001DEDC8_003C2450, D_L03_001DEDCC_003C2450, pulse(j));
        SPRITE(&q, col, ring_alpha(j), D_L03_001DEDDC_003C2450, D_L03_001DEDD8_003C2450, ring_scale(self, j));
        vstep(&q, &r);
    }
}
/* localdecomp:end func_L03_003C2450 */
