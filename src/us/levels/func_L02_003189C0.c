#include "common.h"

/* NTSC-U counterpart of func_L02_00318F28 (src/levels/shared/L02_00318910.c) */
extern u8 D_001A4BE0[];
extern u8 D_L02_0021E158[];
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];

/* localdecomp:start func_L02_003189C0 */
#include "vu0.h"

typedef struct { u8 p0[0x18]; f32 f18; f32 f1C; u8 p20[0x24]; f32 f44; f32 f48; f32 f4C; } S_318F28;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x14]; u16 f34; u8 p36[0x32]; S_318F28 *s; u8 p6C[0x74]; vu0_q vE0; } M_318F28;

extern u8 D_001A4BE0[];
extern u8 D_L02_0021E158[];
extern s32 D_L02_001DC6F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6F0, 8");
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

#define F28_FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
/* one burst at angle `ang` on the ring of radius s->r; NEWV recomputes the velocity */
#define F28_BURST(ang, r, lo, hi, NEWV) \
    { \
        pos.x = func_00388960(ang) * s->r; \
        pos.y = func_00388978(ang) * s->r; \
        pos.z = 0.0f; \
        vec_add_ba(&pos, &pos, &m->pos); \
        pos.z = pos.z + 0.15f; \
        a = (s32)func_L01_00440918(2.0f, 5.0f); \
        f = func_0037E250(0.1f, 0.2f); \
        NEWV \
        func_L01_0046DCB8(&pos, &v, func_0037E208(lo, hi), f * 210000.0f, D_L02_001DC6F0[0], a, 0x7F, 0x7F, 2100.0f, -0.00083333335f, 1); \
        a = -(a * 2); \
        p = func_L01_0046DCB8(&pos, &v, func_0037E208(lo, hi), f * 2.0f * 210000.0f, D_L02_001DC6F0[1], a, 0x30, 0x30, 4200.0f, -0.00083333335f, 0); \
        if (p != 0) { \
            p[2] = **(u8 **)(D_L02_0021E158 + 0xD4); \
        } \
    }
#define F28_NEWV v = m->vE0; func_00388830(&v, &v, 0.033333335f);
#define F28_SAMEV

void func_L02_003189C0(M_318F28 *m) {
    vu0_v4 pos;
    vu0_q v;
    S_318F28 *s;
    f32 b;
    s32 a;
    f32 f;
    u8 *p;

    s = m->s;
    if (m->f34 & 1) return;
    b = func_00389380(s->f44, 0.7853982f);
    F28_BURST(s->f44, f4C, 40, 45, F28_NEWV)
    F28_BURST(func_00389380(s->f44, 3.1415927f), f4C, 40, 45, F28_SAMEV)
    F28_BURST(func_00389380(s->f44, 4.712389f), f4C, 40, 45, F28_SAMEV)
    F28_BURST(func_00389380(s->f44, 1.5707964f), f4C, 40, 45, F28_SAMEV)
    F28_BURST(b, f18, 20, 25, F28_NEWV)
    F28_BURST(func_00389380(b, 3.1415927f), f18, 20, 25, F28_SAMEV)
    F28_BURST(func_00389380(b, 4.712389f), f18, 20, 25, F28_SAMEV)
    F28_BURST(func_00389380(b, 1.5707964f), f18, 20, 25, F28_SAMEV)

    s->f44 = func_00389380(s->f44, s->f48);
    s->f4C = s->f4C - 0.0066666673f;
    s->f48 = s->f48 + 0.0012120343f;
    if (s->f4C < 0.1f) s->f4C = 0.1f;
    s->f18 = s->f18 - 0.0016666668f;
    if (s->f18 < 0.2f) s->f18 = 0.2f;
    if (s->f4C < 0.3f) {
        F28_FLD(D_001A4BE0, s16, 0x2888) = 1;
        F28_FLD(D_001A4BE0, f32, 0x22D0) = F28_FLD(D_001A4BE0, f32, 0x22D4) = s->f1C;
        F28_FLD(D_001A4BE0, f32, 0x22D8) = 1.0f;
        s->f1C = s->f1C - 0.025000002f;
    }
}
/* localdecomp:end func_L02_003189C0 */
