#include "common.h"

/* NTSC-U counterpart of func_L31_003480E0 (src/levels/shared/L31_003480E0.c) */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003480E0;
typedef struct {
    u8 pad0[0x44];
    u8 b44;
    u8 pad45[0x4B];
    V4_003480E0 move;
    u8 padA0[0x10];
    f32 fB0;
    f32 fB4;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    f32 fC4;
    u8 fC8[4];
} Vars_003480E0;
typedef struct {
    u8 pad0[0x10];
    V4_003480E0 pos;
    u8 state;
    u8 pad21[0x22];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x14];
    u8 flags;
    u8 pad61[7];
    Vars_003480E0 *vars;
    u8 pad6C[0x28];
    u8 b94;
    u8 pad95;
    u16 h96;
    s32 f98;
    u8 pad9C[0x24];
    u8 fC0[0x30];
    u8 fF0[8];
    f32 fF8;
} Moby_003480E0;

/* localdecomp:start func_L31_003475D0 */
#include "vu0.h"
/* Vidcomic 1 actor state machine (levels 31 and 36). States 6 and 8 read the hero's x as a float (D_001A4C60_x, another
 * spelling of D_001A4C60) while func_L31_00348770 gets the position vector: two symbols, so gcse does not share one
 * %hi register across those states (retail rebuilds it there; s0 holds it in states 4, 7 and 9). */


extern f32 D_001A4C60[];
extern f32 D_001A4C60_x[];
extern s32 D_L31_001DD03C_003475D0;
__asm__(".extern D_L31_001DD03C_003475D0, 4");
extern f32 D_L31_001DD040_003475D0;
__asm__(".extern D_L31_001DD040_003475D0, 4");
extern f32 D_L31_001DD044_003475D0;
__asm__(".extern D_L31_001DD044_003475D0, 4");
extern f32 D_L31_001DD04C_003475D0;
__asm__(".extern D_L31_001DD04C_003475D0, 4");
extern f32 D_L31_001DD054_003475D0;
__asm__(".extern D_L31_001DD054_003475D0, 4");
extern f32 D_L31_001DD058_003475D0;
__asm__(".extern D_L31_001DD058_003475D0, 4");
extern f32 D_L31_001DD064_003475D0;
__asm__(".extern D_L31_001DD064_003475D0, 4");
extern f32 D_L31_001DD070_003475D0;
__asm__(".extern D_L31_001DD070_003475D0, 4");
extern f32 D_L31_001DD07C_003475D0;
__asm__(".extern D_L31_001DD07C_003475D0, 4");
extern f32 D_L31_001DD080_003475D0;
__asm__(".extern D_L31_001DD080_003475D0, 4");
extern f32 D_L31_001DD084_003475D0;
__asm__(".extern D_L31_001DD084_003475D0, 4");
extern f32 D_L31_001DD0A8_003475D0;
__asm__(".extern D_L31_001DD0A8_003475D0, 4");
extern f32 D_L31_001DD0B8_003475D0;
__asm__(".extern D_L31_001DD0B8_003475D0, 4");
extern f32 D_L31_001DD0BC_003475D0;
__asm__(".extern D_L31_001DD0BC_003475D0, 4");
extern f32 D_L31_001DD0C0_003475D0;
__asm__(".extern D_L31_001DD0C0_003475D0, 4");
extern f32 D_L31_001DD0C4_003475D0;
__asm__(".extern D_L31_001DD0C4_003475D0, 4");
extern f32 D_L31_001DD0C8_003475D0;
__asm__(".extern D_L31_001DD0C8_003475D0, 4");
extern f32 D_L31_001DD0CC_003475D0;
__asm__(".extern D_L31_001DD0CC_003475D0, 4");

extern void func_L31_00348388();
extern void func_L31_00348488(void *, s32);
extern void func_L31_00348078();
extern s32 func_L01_00452EC8(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L31_00346DD8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L30_0034BC88(void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L31_003A2A00(void *, s32);
extern void func_L30_0034CBE0(void *);
extern void func_003BD360(void *);
extern s32 func_L31_00345CF0(void *, void *, s32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_00388BD0(void *, void *);
extern s32 func_L31_00345C88(void *, f32, f32, f32);
extern s32 func_L31_00348770(void *, void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern f32 func_L31_00348690(void *);
extern f32 func_L31_003487A0(void *);
extern void func_L31_00346000(void *, f32, f32, f32, f32, f32, void *);
extern s32 func_L31_00424720(void *, f32, f32);
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00453210(void *, s32);

void func_L31_003475D0(Moby_003480E0 *m) {
    Vars_003480E0 *v = m->vars;

    if (m->state == 0) {
        func_L31_00348388(m);
        func_L31_00348488(m, v->fB8 ? 0xA : 3);
    }
    func_L31_00348078(m);
    switch (m->state) {
    case 1:
        if (func_L01_00452EC8(m)) {
            func_0039FE80(0, 0, m);
        }
        if (m->flags & 2) {
            func_L31_00348488(m, 8);
        }
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 1.0f, 0.0f, 1);
        if (func_L01_0044AF40(m, D_L31_001DD04C_003475D0)) {
            V4_003480E0 d;
            vec_sub_ba(&d, D_001A4C60, &m->pos);
            func_00388830(&d, &d, 1.0f);
            func_L30_0034BC88(m, &d, 1, 2, 0, 0, (f32)v->b44, v->fC4);
        }
        break;
    case 0x42:
        if (func_L01_00452EC8(m)) {
            func_L31_003A2A00(m, -1);
            func_L30_0034CBE0(v->fC8);
            func_003BD360(m);
        }
        break;
    case 2:
        if (func_L01_00452EC8(m)) {
            m->f98 = 0;
            func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 0.0f, D_L31_001DD070_003475D0, 1);
        }
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 0.0f, D_L31_001DD070_003475D0, 1);
        if (m->flags & 2) {
            func_L31_00348488(m, 0x42);
        }
        break;
    case 3:
        func_L01_00452EC8(m);
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, D_L31_001DD0C0_003475D0, D_L31_001DD0C4_003475D0, D_L31_001DD0C8_003475D0, 0.0f, D_L31_001DD0A8_003475D0, 1);
        if (func_L31_00345CF0(m, &m->pos, 1, v->fB4)) {
            func_L31_00348488(m, 7);
        }
        break;
    case 4:
        func_L01_00452EC8(m);
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 1.0f, 0.0f, 1);
        if ((m->flags & 2) && m->b43 == 7) {
            func_003BE4F0(m, 1, 0, 1);
            m->h96 = 0;
        }
        if (m->b43 == 1 && m->h96 == 1) {
            m->fF8 = func_00389380(m->fF8, 3.1415927f);
            func_00388BD0(m->fC0, m->fF0);
        }
        if (func_L01_0044AF40(m, D_L31_001DD080_003475D0) && m->b43 == 1) {
            if (func_L31_00345C88(m, 3.1415927f, 0.0f, D_L31_001DD07C_003475D0) && func_L31_00348770(m, D_001A4C60)) {
                func_L31_00348488(m, 8);
            } else if (func_L31_00348770(m, D_001A4C60)) {
                func_L31_00348488(m, 4);
            } else if (func_0037E0F0(&m->pos, v->fC0, 0)) {
                func_L31_00348488(m, 6);
            } else {
                func_L31_00348488(m, 5);
            }
        }
        break;
    case 5:
        func_L01_00452EC8(m);
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 1.0f, 0.0f, 1);
        if (func_L31_00345C88(m, 3.1415927f, 0.0f, D_L31_001DD07C_003475D0) && func_L31_00348770(m, D_001A4C60)) {
            func_L31_00348488(m, 8);
        }
        if (m->flags & 2) {
            func_L31_00348488(m, 4);
        }
        break;
    case 6: {
        f32 a;
        if (func_L01_00452EC8(m)) {
            f32 b;
            if (m->b94 == 8) {
                b = D_001A4C60_x[0];
            } else {
                b = func_L31_00348690(m);
            }
            v->fB0 = b;
        }
        m->f48 = D_L31_001DD040_003475D0 * fabs_asm(v->move.x) / D_L31_001DD0C0_003475D0;
        if (!func_0037E0F0(&m->pos, v->fC0, 0)) {
            func_L31_00348488(m, 5);
        }
        if (!func_L31_00345CF0(m, &m->pos, 1, v->fB4)) {
            func_L31_00348488(m, 3);
        }
        a = func_L31_003487A0(m);
        func_L31_00346000(m, a, D_L31_001DD044_003475D0, D_L31_001DD0C0_003475D0, D_L31_001DD0B8_003475D0, D_L31_001DD0BC_003475D0, &v->move);
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, D_L31_001DD0C0_003475D0, D_L31_001DD0C4_003475D0, D_L31_001DD0C8_003475D0, 0.0f, D_L31_001DD0A8_003475D0, 1);
        if (fabs_asm(v->move.x) < D_L31_001DD0CC_003475D0 && m->b43 == 6 && a != v->fB0) {
            func_003BE4F0(m, 1, 0, D_L31_001DD03C_003475D0);
        }
        if (D_L31_001DD0CC_003475D0 <= fabs_asm(v->move.x) && m->b43 != 6) {
            func_003BE4F0(m, 6, 0, D_L31_001DD03C_003475D0);
        }
        if (m->b43 != 6) {
            m->f48 = 1.0f;
        }
        if (func_L31_00348770(m, D_001A4C60)) {
            if (func_L31_00345C88(m, 3.1415927f, 0.0f, D_L31_001DD07C_003475D0)) {
                func_L31_00348488(m, 8);
            } else {
                func_L31_00348488(m, 4);
            }
        }
        if (fabs_asm(v->fB0 - m->pos.x) < D_L31_001DD044_003475D0) {
            func_L31_00348488(m, 4);
        }
        break;
    }
    case 7:
        func_L01_00452EC8(m);
        if (!func_L31_00345CF0(m, &m->pos, 1, v->fB4)) {
            func_L31_00348488(m, 3);
        }
        if (m->flags & 2) {
            if (func_L31_00345C88(m, 3.1415927f, 0.0f, D_L31_001DD07C_003475D0) && func_L31_00348770(m, D_001A4C60)) {
                func_L31_00348488(m, 8);
            } else if (!func_L31_00348770(m, D_001A4C60)) {
                func_L31_00348488(m, 6);
            } else {
                func_L31_00348488(m, 4);
            }
        }
        break;
    case 8: {
        f32 a;
        func_L01_00452EC8(m);
        a = func_L31_003487A0(m);
        func_L31_00346000(m, a, D_L31_001DD044_003475D0, D_L31_001DD0C0_003475D0, D_L31_001DD0B8_003475D0, D_L31_001DD0BC_003475D0, &v->move);
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, D_L31_001DD0C0_003475D0, D_L31_001DD0C4_003475D0, D_L31_001DD0C8_003475D0, 0.0f, D_L31_001DD0A8_003475D0, 1);
        m->f48 = D_L31_001DD040_003475D0 * fabs_asm(v->move.x) / D_L31_001DD0C0_003475D0;
        if (fabs_asm(v->move.x) < D_L31_001DD0CC_003475D0 && m->b43 == 6 && a != D_001A4C60_x[0]) {
            func_003BE4F0(m, 1, 0, D_L31_001DD03C_003475D0);
        }
        if (D_L31_001DD0CC_003475D0 <= fabs_asm(v->move.x) && m->b43 != 6) {
            func_003BE4F0(m, 6, 0, D_L31_001DD03C_003475D0);
        }
        if (m->b43 != 6) {
            m->f48 = 1.0f;
        }
        if (!func_L31_00345C88(m, 3.1415927f, 0.0f, D_L31_001DD07C_003475D0)) {
            func_L31_00348488(m, 4);
        }
        if (!func_L31_00348770(m, D_001A4C60)) {
            func_L31_00348488(m, 6);
        }
        if (func_L31_00424720(m, D_L31_001DD054_003475D0, D_L31_001DD058_003475D0)) {
            func_L31_00348488(m, 1);
        }
        if (!func_L31_00345CF0(m, &m->pos, 1, v->fB4)) {
            func_L31_00348488(m, 3);
        }
        break;
    }
    case 9:
        if (func_L01_00452EC8(m)) {
            func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 0.0f, D_L31_001DD064_003475D0, 1);
        }
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 0.0f, D_L31_001DD064_003475D0, 1);
        if (m->flags & 2) {
            if (func_L31_00345C88(m, 3.1415927f, 0.0f, D_L31_001DD07C_003475D0) && func_L31_00348770(m, D_001A4C60)) {
                func_L31_00348488(m, 8);
            } else if (!func_L31_00348770(m, D_001A4C60)) {
                func_L31_00348488(m, 6);
            } else {
                func_L31_00348488(m, 4);
            }
        }
        break;
    case 10:
        func_L01_00452EC8(m);
        if (func_L01_00452F60(m) || func_L01_00453210(D_001A4C60, v->fBC)) {
            func_L31_00348488(m, 8);
        }
        func_L31_00346DD8(m, &m->pos, &v->move, D_L31_001DD084_003475D0, v->fB4, 0.0f, 0.0f, D_L31_001DD0C8_003475D0, 1.0f, 0.0f, 1);
        break;
    }
}
/* localdecomp:end func_L31_003475D0 */
