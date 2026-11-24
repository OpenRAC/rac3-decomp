#include "common.h"


/* localdecomp:start func_L03_003A1370 */
#include "vu0.h"
typedef struct S_003A2B48 S_003A2B48;
typedef struct G_003A2B48 {
    u8 pad0[0x25C0];
    S_003A2B48 *q;
} G_003A2B48;
extern G_003A2B48 D_001A4BE0;

typedef struct { u8 p0[0xC]; f32 fC; u8 p10[4]; f32 f14; f32 f18; f32 f1C; f32 f20; } S_3A2BB8;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x14]; u16 f34; u8 p36[0x32]; S_3A2BB8 *s; u8 p6C[0x74]; vu0_q vE0; } M_3A2BB8;


extern u8 D_L03_0021F318[];
extern s32 D_L03_001DE430[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DE430, 8");
extern f32 func_U_003FA0E8(f32, f32);
extern f32 func_U_003F95E8(f32);
extern f32 func_U_003F9600(f32);
extern void func_U_003F9310(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_U_0042DBF0(f32, f32);
extern s32 func_U_0042DBA8(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

#define BB8_FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
/* one burst at angle `ang` on the ring of radius s->r; NEWV recomputes the velocity */
#define BB8_BURST(ang, r, lo, hi, NEWV) \
    { \
        pos.x = func_U_003F95E8(ang) * s->r; \
        pos.y = func_U_003F9600(ang) * s->r; \
        pos.z = 0.0f; \
        vec_add_ba(&pos, &pos, &m->pos); \
        pos.z = pos.z + 0.15f; \
        a = (s32)func_L01_00440918(2.0f, 5.0f); \
        f = func_U_0042DBF0(0.1f, 0.2f); \
        NEWV \
        func_L01_0046DCB8(&pos, &v, func_U_0042DBA8(lo, hi), f * 210000.0f, D_L03_001DE430[0], a, 0x7F, 0x7F, 2100.0f, -0.0008333333535119891f, 1); \
        a = -(a * 2); \
        p = func_L01_0046DCB8(&pos, &v, func_U_0042DBA8(lo, hi), f * 2.0f * 210000.0f, D_L03_001DE430[1], a, 0x30, 0x30, 4200.0f, -0.0008333333535119891f, 0); \
        if (p != 0) { \
            p[2] = **(u8 **)(D_L03_0021F318 + 0xD4); \
        } \
    }
#define BB8_NEWV v = m->vE0; func_U_003F9310(&v, &v, 0.03333333507180214f);
#define BB8_SAMEV

void func_L03_003A1370(M_3A2BB8 *m) {
    vu0_v4 pos;
    vu0_q v;
    S_3A2BB8 *s;
    f32 b;
    s32 a;
    f32 f;
    u8 *p;

    s = m->s;
    b = func_U_003FA0E8(s->f18, 0.7853982f);
    BB8_BURST(s->f18, f1C, 40, 45, BB8_NEWV)
    BB8_BURST(func_U_003FA0E8(s->f18, 3.1415927f), f1C, 40, 45, BB8_SAMEV)
    BB8_BURST(func_U_003FA0E8(s->f18, 4.712389f), f1C, 40, 45, BB8_SAMEV)
    BB8_BURST(func_U_003FA0E8(s->f18, 1.5707964f), f1C, 40, 45, BB8_SAMEV)
    BB8_BURST(b, f20, 20, 25, BB8_NEWV)
    BB8_BURST(func_U_003FA0E8(b, 3.1415927f), f20, 20, 25, BB8_SAMEV)
    BB8_BURST(func_U_003FA0E8(b, 4.712389f), f20, 20, 25, BB8_SAMEV)
    BB8_BURST(func_U_003FA0E8(b, 1.5707964f), f20, 20, 25, BB8_SAMEV)

    s->f18 = func_U_003FA0E8(s->f18, s->f14);
    s->f1C = s->f1C - 0.0066666672937572f;
    s->f14 = s->f14 + 0.0012120342580601573f;
    if (s->f1C < 0.1f) s->f1C = 0.1f;
    s->f20 = s->f20 - 0.0016666668234393f;
    if (s->f20 < 0.2f) s->f20 = 0.2f;
    if (s->f1C < 0.3f) {
        BB8_FLD(&D_001A4BE0, s16, 0x2888) = 1;
        BB8_FLD(&D_001A4BE0, f32, 0x22D0) = BB8_FLD(&D_001A4BE0, f32, 0x22D4) = s->fC;
        BB8_FLD(&D_001A4BE0, f32, 0x22D8) = 1.0f;
        s->fC = s->fC - 0.02500000223517418f;
    }
}
/* localdecomp:end func_L03_003A1370 */
