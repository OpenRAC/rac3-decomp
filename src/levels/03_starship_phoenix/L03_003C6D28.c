#include "common.h"
#include "vu0.h"

typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[4]; f32 f2C; } S_003BE830;

INCLUDE_ASM("asm/levels", func_L03_003C6D28);

/* localdecomp:start func_L03_003C6FD0 */
extern s32 D_L03_001DF4C0;
extern u8 D_L03_001E2440[];
extern f32 D_L03_001DEE54;
__asm__(".extern D_L03_001DEE54, 4");
extern f32 D_L03_001DEE58;
__asm__(".extern D_L03_001DEE58, 4");
extern f32 D_L03_001DEE5C;
__asm__(".extern D_L03_001DEE5C, 4");
extern f32 D_L03_001DEE60;
__asm__(".extern D_L03_001DEE60, 4");
extern s32 D_L03_001DEE64;
__asm__(".extern D_L03_001DEE64, 4");
extern s32 D_L03_001DEE68;
__asm__(".extern D_L03_001DEE68, 4");
extern s32 D_L03_001DEE6C;
__asm__(".extern D_L03_001DEE6C, 4");
extern f32 D_L03_001DEE70;
__asm__(".extern D_L03_001DEE70, 4");
extern f32 D_L03_001DEE74;
__asm__(".extern D_L03_001DEE74, 4");
extern s32 D_L03_001DEE78;
__asm__(".extern D_L03_001DEE78, 4");
extern s32 D_L03_001DEE7C;
__asm__(".extern D_L03_001DEE7C, 4");
extern f32 D_L03_001DEE80;
__asm__(".extern D_L03_001DEE80, 4");
extern f32 D_L03_001DEE84;
__asm__(".extern D_L03_001DEE84, 4");
extern s32 D_L03_001DEE88;
__asm__(".extern D_L03_001DEE88, 4");
extern s32 D_L03_001DEE8C;
__asm__(".extern D_L03_001DEE8C, 4");
extern s32 D_L03_001DEE90;
__asm__(".extern D_L03_001DEE90, 4");
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);


/* Ring sprites of the PAL build: the ring brightness runs on (t * 5 + 2) / 6, the 50 Hz time
   of the NTSC-U (0xFF - t) / 255. The helpers are the original's: inline and macro scopes put the
   ring loop over haifa's 100-insn region limit (notes count), so sched1 keeps every block on its
   own (no interblock motion) and loop.c leaves 255 in the loop (the alpha flip stays a branch). */
static inline s32 pal_time(s32 t) { return (t * 5 + 2) / 6; }
static inline f32 pulse(s32 j) {
    s32 t = (D_L03_001DF4C0 + j * 20) & 0xFF;
    {
        s32 p = 212 - pal_time(t);
        {
            f32 f = 0.5f - (f32)p / 212.0f;
            return fabs_asm(f);
        }
    }
}
static inline f32 ring_scale(S_003BE830 *self, s32 j) {
    f32 base = D_L03_001DEE80 + (f32)j * D_L03_001DEE84;
    {
        f32 k = self->f2C / *(f32 *)(self->p24 + 0x24);
        return base * k;
    }
}
#define LERPCOL(a, b, t) ({ s32 _a = (a), _b = (b); f32 _t = (t); func_0038DBD8(_a, _b, _t); })
#define SPRITE(p, c, al, x, y, s) ({ s32 _c = (c), _al = (al); f32 _s = (s); func_L01_0046C2E8(p, _c, _al, x, y, 2, 0, 0, _s); })
static inline void vstep(vu0_v4 *a, vu0_v4 *b) { vec_add_ab(a, a, b); }
static inline s32 ring_alpha(s32 j) {
    s32 v = (u8)D_L03_001DF4C0;
    if (j & 2) v = v << 1;
    if (j & 1) v = 255 - v;
    return v & 0xFF;
}

void func_L03_003C6FD0(S_003BE830 *self) {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 w;
    vu0_v4 q;
    vu0_v4 r;
    s32 i;
    s32 j;

    func_0038D000(&pos, &D_L03_001DEE90, (u8 *)self + 0xC0);
    vec_add_ab(&pos, &pos, (u8 *)self + 0x10);
    if (func_00382468(4) == 0) {
        func_L01_00443B88(&vel, D_L03_001DEE54 * 0.020000001f, D_L03_001DEE58 * 0.020000001f);
        func_L01_0046C470(&pos, &vel, D_L03_001DEE68, D_L03_001DEE70, D_L03_001DEE64, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        for (i = 0; i < 3; i++) {
            func_L01_00443B88(&w, D_L03_001DEE5C * 0.020000001f, D_L03_001DEE60 * 0.020000001f);
            vec_add_ab(&vel, &vel, &w);
            func_L01_0046C470(&pos, &vel, D_L03_001DEE6C, D_L03_001DEE74, D_L03_001DEE64, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&q, D_L03_001E2440, &pos);
    func_0038CF68(&q, &q, -0.300000012f);
    func_0038CF68(&r, &q, 0.100000001f);
    vec_add_ab(&q, &q, &pos);
    for (j = 0; j < 4; j++) {
        s32 col = LERPCOL(D_L03_001DEE78, D_L03_001DEE7C, pulse(j));
        SPRITE(&q, col, ring_alpha(j), D_L03_001DEE8C, D_L03_001DEE88, ring_scale(self, j));
        vstep(&q, &r);
    }
}
/* localdecomp:end func_L03_003C6FD0 */

/* localdecomp:start func_L03_003C72A0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_003C72A0;
extern u8 D_001A4BE0[];
extern u8 D_001D5469;
extern s32 D_L03_001DF2DC;
extern G_003C72A0 D_001CCFD0;
extern void func_003C7C38(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038A238(s32);
extern void func_L01_004ED658(s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);
void func_L03_003C72A0(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 v2[4];
    f32 w2[4];
    u8 *h;
    *(s32 *)(a0 + 0x98) = 0;
    func_003C7C38(a0);
    v[0] = func_0038D098(*(f32 *)(q + 0x2C)) * 2.5f;
    v[1] = func_0038D0B0(*(f32 *)(q + 0x2C)) * 2.5f;
    v[2] = 0.0f;
    vec_add_ab(v, v, q + 0x20);
    qzero(w);
    w[2] = func_0038DAB8(*(f32 *)(q + 0x2C), 3.1415927f);
    func_0038A238(8);
    h = D_001A4BE0;
    if (h[0x25E4] == 3) {
        func_L01_004ED658(0);
    }
    func_L01_004F50C8(v, w, 0x74, 0);
    func_003A52A0(0, 0, a0);
    v2[0] = func_0038D098(*(f32 *)(q + 0x2C)) * 1.25f;
    v2[1] = func_0038D0B0(*(f32 *)(q + 0x2C)) * 1.25f;
    v2[2] = 0.0f;
    v2[0] = v2[0] + func_0038D098(func_0038DAB8(*(f32 *)(q + 0x2C), 1.5707964f)) * 4.0f;
    v2[1] = v2[1] + func_0038D0B0(func_0038DAB8(*(f32 *)(q + 0x2C), 1.5707964f)) * 4.0f;
    vec_add_ab(v2, v2, q + 0x20);
    v2[2] = v2[2] + 1.0f;
    qzero(w2);
    w2[2] = func_0038DB00(*(f32 *)(q + 0x2C), 1.5707964f);
    func_L01_003EB438(0, v2, w2, 1, 0, 0);
    func_L01_003EB350(0, v2);
    func_L01_003EB3C0(0, w2);
    *(u128_t *)(a0 + 0x10) = *(u128_t *)(h + 0x80);
    *(u128_t *)(a0 + 0xF0) = *(u128_t *)(h + 0x90);
    if (a0[0x43] != 1) {
        func_003C3A10(a0, 1, 0, 0);
    }
    func_L01_0050FB40(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(a0 + 0x34) |= 0x8000;
    }
    h[0x25F0] = 1;
    D_L03_001DF2DC = 1;
    a0[0x20] = 2;
    *(s32 *)(q + 0x7C) = 0x32;
    if (D_001CCFD0.i6C == 0) {
        if (D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
            func_003A2B68(0xEB8, 0);
        }
    }
    if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
        func_003A1798();
    }
}
/* localdecomp:end func_L03_003C72A0 */

/* localdecomp:start func_L03_003C7598 */
typedef struct { s32 pad[0x14 / 4]; s32 i14; s32 i18; } S_003C7598;
typedef struct { u8 pad[0x42]; u8 f42; u8 pad43[0x25]; S_003C7598 *p68; } O_003C7598;
typedef struct { u8 pad[0x70]; u128_t v70; } E_003C7598;
extern u8 D_001A4BE0[];
extern E_003C7598 *D_L03_001DFA80;
extern f32 func_L01_004395E0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
void func_L03_003C7598(O_003C7598 *o) {
    S_003C7598 *p = o->p68;
    f32 v[4];
    f32 w[4];
    f32 q1[4];
    f32 q2[4];
    f32 s;
    f32 a;
    if (o->f42 == 1) {
        a = func_L01_004395E0(o);
    } else {
        a = 170.0f;
    }
    s = a / 170.0f;
    if (p->i14 == -1 || p->i18 == -1) {
        u8 *h = D_001A4BE0;
        f32 ang = func_0038DAB8(s * 0.6981317f - 0.34906584f, *(f32 *)(h + 0x98));
        v[0] = func_0038D098(ang) * 5.0f;
        v[1] = func_0038D0B0(ang) * 5.0f;
        v[2] = 0.0f;
        vec_add_ba(v, v, h + 0x80);
        v[2] = v[2] + 1.0f;
        qzero(w);
        w[2] = func_0038DAB8(ang, 3.14159f);
        w[1] = s * -0.17f;
    } else {
        func_0038CDF8(v, (f32 *)((u8 *)D_L03_001DFA80 + (p->i14 << 7) + 0x30), (f32 *)((u8 *)D_L03_001DFA80 + (p->i18 << 7) + 0x30), s);
        *(u128_t *)q1 = D_L03_001DFA80[p->i14].v70;
        *(u128_t *)q2 = D_L03_001DFA80[p->i18].v70;
        w[2] = func_0038DAB8(func_0038DB00(q2[2], q1[2]) * s, q1[2]);
        w[1] = func_0038DAB8(func_0038DB00(q2[1], q1[1]) * s, q1[1]);
        w[0] = func_0038DAB8(func_0038DB00(q2[0], q1[0]) * s, q1[0]);
    }
    func_L01_003EB350(0, v);
    func_L01_003EB3C0(0, w);
}
/* localdecomp:end func_L03_003C7598 */
