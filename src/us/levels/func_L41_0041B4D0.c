#include "common.h"

/* NTSC-U counterpart of func_L41_0041BDD0 (src/levels/shared/L41_0041B308.c): 25 -> 30 */
/* localdecomp:start func_L41_0041B4D0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0041BDD0;
typedef struct { u8 b[8]; } B8_0041BDD0;
typedef struct { s32 f0; f32 f4; s32 f8; s32 fC; } V_0041BDD0;
typedef struct {
    u8 p0[0x20]; u8 b20;
    u8 p21[0x2C - 0x21]; f32 f2C;
    u8 b30; u8 p31; s16 h32; u16 h34;
    u8 p36[0x68 - 0x36]; V_0041BDD0 *vars;
    u8 p6C[0xA8 - 0x6C]; u8 bA8;
    u8 pA9[0xC0 - 0xA9]; u8 fC0[0x10];
} M_0041BDD0;

extern V4_0041BDD0 D_L41_00242AB0 __attribute__((section(".sdata")));
extern B8_0041BDD0 D_L41_002478F8[];
extern B8_0041BDD0 D_L41_00247900[];
extern s32 D_001A5F78[];
extern s32 D_001D5BCC_sda_0041B4D0;
__asm__(".extern D_001D5BCC_sda_0041B4D0, 4");
extern void func_L41_004894B0(M_0041BDD0 *, s32);
extern M_0041BDD0 *func_L41_0041B8E8(M_0041BDD0 *);
extern s32 func_L03_003F8F68(void *, void *, s32);
extern void func_L41_0041AF90(M_0041BDD0 *);
extern void func_L41_0041B230(void *, s32, u32, f32);
extern void func_L41_0041B870(void *, s32);
extern void func_L40_004C35D0(s32, s32, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004367E8(void *, s32, void *);
extern void func_L41_0041B100(void *, s32, f32, f32, f32);
extern void func_L41_0048F968(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_00487860(void *, s32);
extern void func_003BD360(void *);

void func_L41_0041B4D0(M_0041BDD0 *m) {
    V_0041BDD0 *v = m->vars;
    M_0041BDD0 *t;
    s32 flag;
    s32 id;
    B8_0041BDD0 a;
    B8_0041BDD0 b;
    V4_0041BDD0 pts[2];
    V4_0041BDD0 w;

    if (m->b20 == 0) {
        v->f0 = -1;
        m->b20 = 1;
        m->b30 = 0xFF;
        m->h32 = 0xFF;
        m->h34 |= 0x4041;
        v->f8 = 0;
        func_L41_004894B0(m, v->fC);
    }
    if (v->f0 == -1) {
        flag = 0;
        t = func_L41_0041B8E8(m);
        if (v->f8 > 0) {
            v->f8--;
        }
        if (t != 0 && v->f8 == 0) {
            v->f8 = 0x1E;
            v->f4 = v->f4 - t->f2C;
            if (func_L03_003F8F68(&D_L41_00242AB0, t, 0x10) == 0) {
                if (t->f2C >= 8.0f) {
                    func_L41_0041AF90(m);
                }
                func_L41_0041B230(t, 0x14, 0x80555E6A, 1.0f);
            }
            if (v->f4 <= 0.0f) {
                v->f4 = 0.0f;
                flag = 1;
            }
        }
        m->bA8 = 0xFF;
        if (flag) {
            func_L41_0041B870(m, 0xFA);
        }
    }
    if (v->f0 >= 0 && v->f0 < D_001A5F78[0]) {
        a = D_L41_002478F8[0];
        b = D_L41_00247900[0];
        id = -1;
        switch (D_001D5BCC_sda_0041B4D0) {
        case 0x29:
        case 0x33:
            id = 0x13;
            break;
        case 0x2A:
        case 0x34:
            id = 0x12;
            break;
        case 0x2D:
        case 0x37:
            id = 0x11;
            break;
        }
        if (id != -1) {
            func_L40_004C35D0(id, 0, m, 0);
        }
        func_003886E8(&pts[0], m->fC0, -3.0f);
        func_003886E8(&pts[1], m->fC0, -6.0f);
        func_L01_004367E8(m, 0, &w);
        func_L41_0041B100(&w, 5, 1.0f, 4.0f, 12.0f);
        func_L41_0041B230(&w, 0x14, 0x80555E6A, 1.5f);
        func_L01_004367E8(m, 1, &w);
        func_L41_0041B100(&w, 5, 1.0f, 8.0f, 12.0f);
        func_L41_0041B230(&w, 0x14, 0x80555E6A, 1.5f);
        func_L01_004367E8(m, 2, &w);
        func_L41_0041B100(&w, 5, 1.0f, 4.0f, 12.0f);
        func_L41_0041B230(&w, 0x14, 0x80555E6A, 1.5f);
        func_L41_0048F968(m, pts, &b, &a, 0xFFFF, -1, -1, 1, 0xFFFF, 0xFF, 0);
        func_L40_00487860(m, v->fC);
        func_003BD360(m);
    }
}
/* localdecomp:end func_L41_0041B4D0 */
