#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;

/* localdecomp:start func_L01_00311C60 */
typedef struct {
    u8 pad0[0x24];
    s32 w24;
} S_00311C60;
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} S_1CFEC0_00311C60;
extern s32 D_001A1ED0[];
extern S_1CFEC0_00311C60 D_001CFEC0_00311C60[];
extern void func_003A9440(s32 reg, long value);
extern void func_0038AF30(s32, s32, s32, s32, s32);

void func_L01_00311C60(S_311A18 *a0) {
    S_00311C60 *m = (S_00311C60 *)a0->p68;

    if (m->w24 != 0) {
        func_003A9440(0x4E, (D_001A1ED0[2] >> 13) | 0x1000000 | 0x100000000);
        func_0038AF30(0, D_001CFEC0_00311C60->h152, 0, D_001CFEC0_00311C60->h150, (m->w24 << 24) | 0xFFFFFF);
        func_003A9440(0x4E, 0x1000000 | (D_001A1ED0[2] >> 13));
    }
}
/* localdecomp:end func_L01_00311C60 */

/* localdecomp:start func_L01_00311D08 */



extern s32 func_L01_00457458(s32 a0, s32 a1);
extern void func_L01_003119E0();
extern void func_003C2880(S_311A18 *a0);
extern s32 func_0038DC20(s128 *a0, f32 f12);
extern void func_L01_00311DE8(S_311A18 *a0);
extern void func_L01_00312030_00311D08(S_311A18 *a0);
extern void func_L01_00311C60(S_311A18 *a0);
extern void func_L01_00312270(S_311A18 *a0);
extern void func_L01_003126C8(S_311A18 *a0);
extern void func_L01_00312D70(S_311A18 *a0);

void func_L01_00311D08(S_311A18 *o) {
    S_311A18m *m;
    s128 v;

    m = o->p68;
    if (o == 0) {
        return;
    }
    if (o->b20 == 254) {
        return;
    }
    if (o->b20 == 253) {
        return;
    }
    if (m == 0) {
        return;
    }
    if (func_L01_00457458(o->hAA, m->w28) == 0) {
        func_L01_003119E0();
        func_003C2880(o);
        return;
    }
    v = o->q10;
    ((f32 *)&v)[3] = 2.0f;
    if (func_0038DC20(&v, 100.0f) == -1) {
        return;
    }
    if (o->b20 != 6) {
        func_L01_00311DE8(o);
        func_L01_00312030_00311D08(o);
        func_L01_00311C60(o);
    }
    func_L01_00312270(o);
    func_L01_003126C8(o);
    func_L01_00312D70(o);
}
/* localdecomp:end func_L01_00311D08 */

/* localdecomp:start func_L01_00311DE8 */
#include "vu0.h"

typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_311DE8_00311DE8;
extern long func_00389598(s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern s32 D_L01_001DC6AC_00311DE8, D_L01_001DC6B0_00311DE8, D_L01_001DC6B4_00311DE8, D_L01_001DC6B8_00311DE8, D_L01_001DC6BC_00311DE8, D_L01_001DC6C0_00311DE8, D_L01_001DC6C4_00311DE8;
extern f32 D_L01_001DC6C8_00311DE8;
__asm__(".extern D_L01_001DC6AC_00311DE8, 4");
__asm__(".extern D_L01_001DC6B0_00311DE8, 4");
__asm__(".extern D_L01_001DC6B4_00311DE8, 4");
__asm__(".extern D_L01_001DC6B8_00311DE8, 4");
__asm__(".extern D_L01_001DC6BC_00311DE8, 4");
__asm__(".extern D_L01_001DC6C0_00311DE8, 4");
__asm__(".extern D_L01_001DC6C4_00311DE8, 4");
__asm__(".extern D_L01_001DC6C8_00311DE8, 4");
extern s16 D_L01_002A83F0_00311DE8[][4][2];
extern vu0_v4 D_L01_002A7EF0_00311DE8[];
extern f32 D_L01_002A87F0_00311DE8[][2];

void func_L01_00311DE8(S_311A18 *o) {
    S_311DE8_00311DE8 s;
    vu0_v4 mat[3];
    vu0_v4 v;
    u8 *m;
    s32 c;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    m = (u8 *)o->p68;
    s.x78 = func_00389598(D_L01_001DC6C0_00311DE8);
    s.x88 = (long)D_L01_001DC6AC_00311DE8 | ((long)D_L01_001DC6B0_00311DE8 << 2) | ((long)D_L01_001DC6B4_00311DE8 << 4) |
            ((long)D_L01_001DC6B8_00311DE8 << 6) | ((long)D_L01_001DC6BC_00311DE8 << 32);
    s.x80 = 0xFF9000000260L;
    qzero(&mat[0]);
    qzero(&mat[1]);
    qzero(&mat[2]);
    s.x70 = 0;
    mat[0].x = *(f32 *)(m + 0x10) + *(f32 *)(m + 0x10);
    mat[1].y = *(f32 *)(m + 0x10) + *(f32 *)(m + 0x10);
    mat[2].z = *(f32 *)(m + 0x10) * 0.25f;
    c = D_L01_001DC6C4_00311DE8 + (*(s32 *)(m + 0x24) << 24);
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    func_003C5180(&o->q10, &v, 1);
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 4; j++) {
            a = D_L01_002A83F0_00311DE8[i][j][0];
            b = D_L01_002A83F0_00311DE8[i][j][1];
            func_0038CE20(&s.m[j], &D_L01_002A7EF0_00311DE8[a], D_L01_001DC6C8_00311DE8);
            s.uv[j][0] = D_L01_002A87F0_00311DE8[b][0];
            s.uv[j][1] = D_L01_002A87F0_00311DE8[b][1];
            func_0038D000(&s.m[j], &s.m[j], mat);
            func_0038D000(&s.m[j], &s.m[j], (u8 *)o + 0xC0);
            vec_add_ab(&s.m[j], &s.m[j], &o->q10);
            func_0038CF68(&v, &v, 0.5f);
            vec_add_ab(&s.m[j], &s.m[j], &v);
        }
        func_003D2DA0(&s, 0, 0);
    }
}
/* localdecomp:end func_L01_00311DE8 */

/* localdecomp:start func_L01_00312030 */
#include "vu0.h"

typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_312030_00312030;
extern long func_00389598(s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern s32 D_L01_001DC6AC_00312030, D_L01_001DC6B0_00312030, D_L01_001DC6B4_00312030, D_L01_001DC6B8_00312030, D_L01_001DC6BC_00312030, D_L01_001DC6C0_00312030, D_L01_001DC6C4_00312030;
extern f32 D_L01_001DC6C8_00312030;
__asm__(".extern D_L01_001DC6AC_00312030, 4");
__asm__(".extern D_L01_001DC6B0_00312030, 4");
__asm__(".extern D_L01_001DC6B4_00312030, 4");
__asm__(".extern D_L01_001DC6B8_00312030, 4");
__asm__(".extern D_L01_001DC6BC_00312030, 4");
__asm__(".extern D_L01_001DC6C0_00312030, 4");
__asm__(".extern D_L01_001DC6C4_00312030, 4");
__asm__(".extern D_L01_001DC6C8_00312030, 4");
extern s16 D_L01_002A83F0_00312030[][4][2];
extern vu0_v4 D_L01_002A7EF0_00312030[];
extern f32 D_L01_002A87F0_00312030[][2];

void func_L01_00312030(S_311A18 *o) {
    S_312030_00312030 s;
    vu0_v4 mat[3];
    vu0_v4 v;
    u8 *m;
    s32 c;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    m = (u8 *)o->p68;
    s.x78 = func_00389598(D_L01_001DC6C0_00312030);
    s.x88 = (long)D_L01_001DC6AC_00312030 | ((long)D_L01_001DC6B0_00312030 << 2) | ((long)D_L01_001DC6B4_00312030 << 4) |
            ((long)D_L01_001DC6B8_00312030 << 6) | ((long)D_L01_001DC6BC_00312030 << 32);
    s.x80 = 0xFF9000000260L;
    qzero(&mat[0]);
    qzero(&mat[1]);
    qzero(&mat[2]);
    s.x70 = 0;
    mat[0].x = *(f32 *)(m + 0x10);
    mat[1].y = *(f32 *)(m + 0x10);
    mat[2].z = *(f32 *)(m + 0x10) * 0.125f;
    c = D_L01_001DC6C4_00312030 + (*(s32 *)(m + 0x24) << 24);
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    func_003C5180(&o->q10, &v, 1);
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 4; j++) {
            a = D_L01_002A83F0_00312030[i][j][0];
            b = D_L01_002A83F0_00312030[i][j][1];
            func_0038CE20(&s.m[j], &D_L01_002A7EF0_00312030[a], D_L01_001DC6C8_00312030);
            s.uv[j][0] = D_L01_002A87F0_00312030[b][0];
            s.uv[j][1] = D_L01_002A87F0_00312030[b][1];
            func_0038D000(&s.m[j], &s.m[j], mat);
            func_0038D000(&s.m[j], &s.m[j], (u8 *)o + 0xC0);
            vec_add_ab(&s.m[j], &s.m[j], &o->q10);
            func_0038CF68(&v, &v, 0.5f);
            vec_add_ab(&s.m[j], &s.m[j], &v);
        }
        func_003D2DA0(&s, 0, 0);
    }
}
/* localdecomp:end func_L01_00312030 */

/* localdecomp:start func_L01_00312270 */
#include "vu0.h"

typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_312270_00312270;
extern long func_00389598(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern f32 func_0038D098(f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern s32 D_L01_001DC6CC_00312270, D_L01_001DC6D0_00312270, D_L01_001DC6D4_00312270, D_L01_001DC6D8_00312270, D_L01_001DC6DC_00312270, D_L01_001DC6E0_00312270, D_L01_001DC6E4_00312270;
extern f32 D_L01_001DC6E8_00312270, D_L01_001DC6A0_00312270, D_L01_001DC6A4_00312270;
__asm__(".extern D_L01_001DC6CC_00312270, 4");
__asm__(".extern D_L01_001DC6D0_00312270, 4");
__asm__(".extern D_L01_001DC6D4_00312270, 4");
__asm__(".extern D_L01_001DC6D8_00312270, 4");
__asm__(".extern D_L01_001DC6DC_00312270, 4");
__asm__(".extern D_L01_001DC6E0_00312270, 4");
__asm__(".extern D_L01_001DC6E4_00312270, 4");
__asm__(".extern D_L01_001DC6E8_00312270, 4");
__asm__(".extern D_L01_001DC6A0_00312270, 4");
__asm__(".extern D_L01_001DC6A4_00312270, 4");
extern s16 D_L01_002A9780_00312270[][4][2];
extern vu0_v4 D_L01_002A8AA0_00312270[];
extern f32 D_L01_002AA500_00312270[][2];
extern vu0_v4 D_L01_001E2A40_00312270;

void func_L01_00312270(S_311A18 *o) {
    S_312270_00312270 s;
    vu0_v4 mat[3];
    vu0_v4 dir;
    vu0_v4 ctr;
    vu0_v4 e1;
    vu0_v4 e2;
    vu0_v4 *p;
    u8 *m;
    s32 c;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    m = (u8 *)o->p68;
    s.x78 = func_00389598(D_L01_001DC6E0_00312270);
    s.x88 = (long)D_L01_001DC6CC_00312270 | ((long)D_L01_001DC6D0_00312270 << 2) | ((long)D_L01_001DC6D4_00312270 << 4) |
            ((long)D_L01_001DC6D8_00312270 << 6) | ((long)D_L01_001DC6DC_00312270 << 32);
    s.x80 = 0xFF9000000260L;
    s.x70 = 0;
    c = D_L01_001DC6E4_00312270 + (*(s32 *)(m + 0x1C) << 24);
    qzero(&mat[0]);
    qzero(&mat[1]);
    qzero(&mat[2]);
    mat[0].x = 1.0f;
    s.c[3] = c;
    s.c[2] = c;
    s.c[1] = c;
    s.c[0] = c;
    mat[1].y = 1.0f;
    mat[2].z = *(f32 *)(m + 0x10) * 0.865f;
    for (i = 0; i < 215; i++) {
        for (j = 0; j < 4; j++) {
            a = D_L01_002A9780_00312270[i][j][0];
            b = D_L01_002A9780_00312270[i][j][1];
            p = &D_L01_002A8AA0_00312270[a];
            func_0038CE20(&s.m[j], p, D_L01_001DC6E8_00312270);
            s.uv[j][0] = D_L01_002AA500_00312270[b][0] + D_L01_001DC6A0_00312270;
            s.uv[j][1] = D_L01_002AA500_00312270[b][1] + D_L01_001DC6A4_00312270;
            if (p->z == -0.001052f) {
                s.c[j] = D_L01_001DC6E4_00312270;
            } else {
                s.c[j] = D_L01_001DC6E4_00312270 | (*(s32 *)(m + 0x1C) << 24);
            }
        }
        func_0038D000(&s.m[0], &s.m[0], mat);
        func_0038D000(&s.m[1], &s.m[1], mat);
        func_0038D000(&s.m[2], &s.m[2], mat);
        func_0038D000(&s.m[3], &s.m[3], mat);
        qzero(&ctr);
        for (j = 0; j < 4; j++) {
            s.uv[j][0] -= s.m[j].z * 0.125f;
            s.m[j].x *= func_0038D098(s.m[j].z) + 2.0f;
            s.m[j].y *= func_0038D098(s.m[j].z) + 2.0f;
            func_0038D000(&s.m[j], &s.m[j], (u8 *)o + 0xC0);
            s.m[j].x += ((f32 *)&o->q10)[0];
            s.m[j].y += ((f32 *)&o->q10)[1];
            s.m[j].z += ((f32 *)&o->q10)[2];
            vec_add_ba(&ctr, &ctr, &s.m[j]);
        }
        func_0038CE20(&ctr, &ctr, 0.25f);
        vec_sub_ab(&dir, &ctr, &D_L01_001E2A40_00312270);
        func_0038CF68(&dir, &dir, 1.0f);
        vec_sub_ab(&e1, &s.m[2], &s.m[0]);
        vec_sub_ab(&e2, &s.m[2], &s.m[1]);
        func_0038CE90(&ctr, &e1, &e2);
        func_0038CF68(&ctr, &ctr, 1.0f);
        if (0.0f < func_0038CE68(&dir, &ctr)) {
            func_003D2DA0(&s, 0, 0);
        }
    }
}
/* localdecomp:end func_L01_00312270 */

/* localdecomp:start func_L01_003126C8 */
#include "vu0.h"

typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_3126C8_003126C8;
extern long func_00389598(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern f32 func_0038CED8(void *);
extern f32 func_L01_004451A8_003126C8(f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern u8 *func_L01_00312DD8_003126C8(s32, s32, f32, f32, void *);
extern s32 D_L01_001DC6EC_003126C8, D_L01_001DC6F0_003126C8, D_L01_001DC6F4_003126C8, D_L01_001DC6F8_003126C8, D_L01_001DC6FC_003126C8, D_L01_001DC700_003126C8, D_L01_001DC704_003126C8;
extern f32 D_L01_001DC708_003126C8, D_L01_001DC6A4_003126C8;
__asm__(".extern D_L01_001DC6EC_003126C8, 4");
__asm__(".extern D_L01_001DC6F0_003126C8, 4");
__asm__(".extern D_L01_001DC6F4_003126C8, 4");
__asm__(".extern D_L01_001DC6F8_003126C8, 4");
__asm__(".extern D_L01_001DC6FC_003126C8, 4");
__asm__(".extern D_L01_001DC700_003126C8, 4");
__asm__(".extern D_L01_001DC704_003126C8, 4");
__asm__(".extern D_L01_001DC708_003126C8, 4");
__asm__(".extern D_L01_001DC6A4_003126C8, 4");
extern s16 D_L01_002AB460_003126C8[][4][2];
extern vu0_v4 D_L01_002AAC00_003126C8[];
extern f32 D_L01_002ABD60_003126C8[][2];
extern vu0_v4 D_L01_001E2A40_003126C8;
extern s32 D_L01_001E1730_003126C8;
extern u8 **D_L01_001E1738_003126C8;

void func_L01_003126C8(S_311A18 *o) {
    S_3126C8_003126C8 s;
    vu0_v4 mat[3];
    vu0_v4 dir;
    vu0_v4 ctr;
    vu0_v4 pos;
    vu0_v4 e1;
    vu0_v4 e2;
    u8 *m;
    u8 *q;
    f32 t;
    s32 c;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    m = (u8 *)o->p68;
    s.x78 = func_00389598(D_L01_001DC700_003126C8);
    qzero(&mat[0]);
    qzero(&mat[1]);
    qzero(&mat[2]);
    s.x80 = 0xFF9000000260L;
    s.x88 = (long)D_L01_001DC6EC_003126C8 | ((long)D_L01_001DC6F0_003126C8 << 2) | ((long)D_L01_001DC6F4_003126C8 << 4) |
            ((long)D_L01_001DC6F8_003126C8 << 6) | ((long)D_L01_001DC6FC_003126C8 << 32);
    s.x70 = 0;
    mat[0].x = *(f32 *)(m + 0x10) * 0.0625f + 1.0f;
    mat[1].y = *(f32 *)(m + 0x10) * 0.0625f + 1.0f;
    mat[2].z = 1.0f;
    c = D_L01_001DC704_003126C8 + (*(s32 *)(m + 0x1C) << 24);
    s.c[3] = c;
    s.c[2] = c;
    s.c[1] = c;
    s.c[0] = c;
    for (i = 0; i < 143; i++) {
        for (j = 0; j < 4; j++) {
            a = D_L01_002AB460_003126C8[i][j][0];
            b = D_L01_002AB460_003126C8[i][j][1];
            func_0038CE20(&s.m[j], &D_L01_002AAC00_003126C8[a], D_L01_001DC708_003126C8);
            s.uv[j][0] = D_L01_002ABD60_003126C8[b][0];
            s.uv[j][1] = D_L01_002ABD60_003126C8[b][1] - D_L01_001DC6A4_003126C8;
        }
        qzero(&ctr);
        for (j = 0; j < 4; j++) {
            func_0038D000(&s.m[j], &s.m[j], mat);
            t = 1.5f - func_0038CED8(&s.m[j]) / 1.5f;
            t = 0.0f < t ? t : 0.0f;
            s.m[j].z += func_L01_004451A8_003126C8(t / 1.5f) * 1.5f * *(f32 *)(m + 0x10) * 0.00825f;
            s.m[j].z += *(f32 *)(m + 0x10) * 0.15f;
            func_0038D000(&s.m[j], &s.m[j], (u8 *)o + 0xC0);
            s.m[j].x += ((f32 *)&o->q10)[0];
            s.m[j].y += ((f32 *)&o->q10)[1];
            s.m[j].z += ((f32 *)&o->q10)[2];
            vec_add_ba(&ctr, &ctr, &s.m[j]);
        }
        func_0038CE20(&ctr, &ctr, 0.25f);
        pos = ctr;
        vec_sub_ba(&dir, &ctr, &D_L01_001E2A40_003126C8);
        func_0038CF68(&dir, &dir, 1.0f);
        vec_sub_ab(&e1, &s.m[2], &s.m[0]);
        vec_sub_ab(&e2, &s.m[2], &s.m[1]);
        func_0038CE90(&ctr, &e1, &e2);
        func_0038CF68(&ctr, &ctr, 1.0f);
        if (0.0f < func_0038CE68(&dir, &ctr)) {
            q = D_L01_001E1738_003126C8[i];
            if (q == 0) {
                if (o->b20 != 6) {
                    D_L01_001E1738_003126C8[i] = func_L01_00312DD8_003126C8(D_L01_001E1730_003126C8, 1, 0.0f, 0.0f, &pos);
                }
            } else if (*(s32 *)(q + 0x7C) == 0) {
                if (o->b20 != 6) {
                    D_L01_001E1738_003126C8[i] = func_L01_00312DD8_003126C8(D_L01_001E1730_003126C8, 1, 0.0f, 0.0f, &pos);
                } else {
                    D_L01_001E1738_003126C8[i] = 0;
                }
            }
            if (D_L01_001E1738_003126C8[i] != 0) {
                *(vu0_v4 *)D_L01_001E1738_003126C8[i] = pos;
            }
            func_003D2DA0(&s, 0, 0);
        }
    }
}
/* localdecomp:end func_L01_003126C8 */

/* localdecomp:start func_L01_00312B60 */
typedef union {
    s128 q;
    f32 f[4];
} V_00312B60;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_00382538(void);
extern void func_L01_00312DD8(void *, s32, f32, f32, s32);
extern f32 func_0038DAB8(f32, f32);
extern u8 *D_L01_001E1730_00312B60;
__asm__(".extern D_L01_001E1730_00312B60, 16");

void func_L01_00312B60(u8 *owner, s32 id, V_00312B60 *pos, V_00312B60 *vel, f32 scale) {
    V_00312B60 temp;
    u8 *base = D_L01_001E1730_00312B60;
    s32 i = 0, j;
    f32 angle;
    for (i = 0; i <= 0; i++) {
        u8 *p = base + i * 0x50;
        if (*(u8 **)(p + 0x30) == 0) {
            *(u8 **)(p + 0x30) = owner;
            *(s32 *)(p + 0x34) = id;
            *(f32 *)(p + 0x3C) = scale;
            *(s32 *)(p + 0x38) = 0;
            *(s128 *)p = vel->q;
            *(s128 *)(p + 0x20) = pos->q;
            *(f32 *)(p + 0x28) = *(f32 *)(owner + 0x18);
            func_0038CF68(&temp, vel, 2.0f);
            vec_add_ab(&temp, &temp, p + 0x20);
            func_0038CE90(p + 0x10, p + 0x20, &temp);
            angle = func_00382538();
            for (j = 47; j >= 0; j--) {
                func_L01_00312DD8(p, 2, angle, 0.0f, 0);
                angle = func_0038DAB8(angle, 0.13368479907512665f);
            }
            *(s32 *)(p + 0x40) = 0;
            *(s32 *)(p + 0x44) = 0;
            return;
        }
    }
}
/* localdecomp:end func_L01_00312B60 */
