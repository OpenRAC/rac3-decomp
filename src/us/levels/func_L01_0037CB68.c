#include "common.h"
#include "vu0.h"
/* NTSC-U counterpart of func_L01_0037DC70 (src/levels/shared/L01_0037C798.c): 5 -> 6, 0x16 -> 0x1A, 0x11 -> 0x14, 8 -> 10 (twice), 3 -> 4 */
/* localdecomp:start func_L01_0037CB68 */
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x47]; u8 *p68; u8 p6C[0x3E]; u16 hAA;
} M_37DC70;
typedef struct {
    vu0_v4 v0; vu0_v4 v10; u8 p20[0x14]; s32 w34; u8 p38[4]; f32 f3C; s32 w40; u8 p44[4]; s32 w48; s32 w4C;
} St_37DC70;
typedef struct { u8 p0[0xAA]; s16 hAA; } H_37DC70;
typedef struct { u8 p0[0x18]; H_37DC70 *w18; u8 p1C[4]; vu0_v4 v20; } T_37DC70;
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_37DC70;
typedef struct { u8 p0; u8 b1; u8 p2[0xEE]; } Row_37DC70;
extern T_37DC70 D_U_001EAA80;
extern vu0_v4 D_U_001EAAA0;
extern vu0_v4 D_001A52D0;
extern u8 D_001425C0[];
extern Row_37DC70 D_U_002C5640[];
extern s32 D_U_001E1E20;
extern f32 D_U_001E1E38;
extern f32 D_U_001E1E3C;
typedef struct { s32 a; s32 b; } G_37DC70;
extern G_37DC70 D_U_001E1E10;
extern s32 D_U_001DFBC0;
extern s32 D_U_002B3B40[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern s32 func_003D4D00_0037DC70(void *, s32, void *, void *, f32);
extern s32 func_0038CAD0(s32 *);
extern void func_003C2880(void *);
extern void func_L01_004026A0_0037CB68(void *, void *);
extern void func_L01_0037D1E0();
extern void func_L01_0037D518();
extern void func_L01_0037D568();

void func_L01_0037CB68(M_37DC70 *m) {
    s32 *p;
    vu0_v4 old;
    vu0_v4 v10;
    vu0_v4 vA0;
    S_37DC70 sB0;
    vu0_v4 v60;
    M_37DC70 *hit;
    s32 i;
    s32 off;

    p = (s32 *)m->p68;
    if (m->b20 != 0) {
        return;
    }
    old = m->pos;
    if (p[18] != 0) {
        vec_add_ab(&m->pos, &m->pos, (p + 4));
    } else {
        vec_add_ab(&m->pos, &m->pos, p);
    }
    p[13]++;
    if (((Row_37DC70 *)((u8 *)D_U_002C5640 + D_001425C0[0x6F] * 0xF0))->b1 == 0) {
        if (p[19] == 0) {
            if (!(m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
                  m->pos.z < 2.0f || 1021.0f < m->pos.z)) {
                if (func_003D3CB0(&old, &m->pos, 0, m, 0)) {
                    p[19] = 1;
                    v10 = D_U_001EAAA0;
                    vA0 = D_001A52D0;
                    func_0038CE20(&vA0, &vA0, 1.0f);
                    vA0.w = 5627.925f;
                    func_L01_00443628(&sB0, m, p[16], &vA0, ((f32 *)p)[15]);
                    sB0.b19 = 1;
                    sB0.h1A = m->hAA;
                    sB0.b18 = 0;
                    func_003D4D00_0037DC70(&v10, 0, m, &sB0, 0.6f);
                    if (p[18] != 0) {
                        func_0038CF68((p + 4), (p + 4), -0.2f);
                        vec_add_ab(&v60, &v10, (p + 4));
                    } else {
                        func_0038CF68(p, p, -0.2f);
                        vec_add_ab(&v60, &v10, p);
                    }
                }
            }
        }
    } else {
        hit = 0;
        for (i = 0; i < 6; i++) {
            if (m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
                m->pos.z < 2.0f || 1021.0f < m->pos.z) {
                continue;
            }
            if (func_003D3CB0(&old, &m->pos, 0, hit, 0)) {
                T_37DC70 *t = &D_U_001EAA80;
                if (t->w18 != 0 && t->w18->hAA == 0x1CF7) {
                    break;
                }
                v10 = t->v20;
                hit = (M_37DC70 *)t->w18;
                vA0 = D_001A52D0;
                func_0038CE20(&vA0, &vA0, 1.75f);
                vA0.w = 5627.925f;
                func_L01_00443628(&sB0, m, p[16], &vA0, ((f32 *)p)[15]);
                sB0.b18 = 0;
                sB0.h1A = m->hAA;
                sB0.b19 = 1;
                off = D_001425C0[0x6F] * 0xF0;
                if (((Row_37DC70 *)((u8 *)D_U_002C5640 + off))->b1 >= 3) {
                    func_003D4D00_0037DC70(&v10, 0, m, &sB0, 2.5f);
                } else {
                    func_003D4D00_0037DC70(&v10, 0, m, &sB0, 0.8f);
                }
                if (p[18] != 0) {
                    func_0038CF68((p + 4), (p + 4), -0.2f);
                    vec_add_ab(&v60, &v10, (p + 4));
                } else {
                    func_0038CF68(p, p, -0.2f);
                    vec_add_ab(&v60, &v10, p);
                }
            }
        }
    }
    if (func_0038CAD0(&D_U_001E1E20) == 0 && ((Row_37DC70 *)((u8 *)D_U_002C5640 + D_001425C0[0x6F] * 0xF0))->b1 >= 3) {
        if (D_U_001E1E20 >= 6) {
            D_U_001E1E38 += 0.05f;
            D_U_001E1E3C += 0.05f;
        } else {
            D_U_001E1E38 -= 0.05f;
            D_U_001E1E3C -= 0.05f;
        }
        func_L01_004026A0_0037CB68(func_L01_0037D1E0, m);
    }
    if (p[13] >= 0x1A) {
        func_003C2880(m);
        return;
    }
    if (p[18] != 0) {
        if (p[13] < 0x14) {
            func_L01_004026A0_0037CB68(func_L01_0037D518, m);
            func_L01_004026A0_0037CB68(func_L01_0037D568, m);
        }
        if (p[13] == 10) {
            D_U_001E1E10.a = 2;
            D_U_001E1E10.b = D_U_001DFBC0;
        }
    } else {
        if (p[13] < 10) {
            func_L01_004026A0_0037CB68(func_L01_0037D518, m);
            func_L01_004026A0_0037CB68(func_L01_0037D568, m);
        }
        if (p[13] == 4) {
            D_U_001E1E10.a = 2;
            D_U_001E1E10.b = D_U_001DFBC0;
        }
        D_U_002B3B40[3] = ((0xBF - p[13] * 15) << 24) | 0x808080;
        D_U_002B3B40[4] = ((0xBF - p[13] * 15) << 24) | 0x8080B4;
    }
}
