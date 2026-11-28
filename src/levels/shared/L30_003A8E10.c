#include "common.h"
#include "vu0.h"

/* declared by functions of L30_003A8D68.c, which this file was cut from */
extern s32 D_L30_001DEAB0;
extern s32 D_L30_001DEAB4;
extern vu0_q D_L30_002A2560[];

/* localdecomp:start func_L30_003A8E10 */
__asm__(".extern D_L30_001DEAB0, 4");
__asm__(".extern D_L30_001DEAB4, 4");
__asm__(".extern D_L30_001DEAD8, 4");
__asm__(".extern D_L30_001DEAB8, 4");
__asm__(".extern D_L30_001DEABC, 4");
__asm__(".extern D_L30_001DEAC0, 4");
__asm__(".extern D_L30_001DEAC4, 4");
__asm__(".extern D_L30_001DEAC8, 4");
__asm__(".extern D_L30_001DEACC, 4");
__asm__(".extern D_L30_001DF2C0, 4");
extern u8 D_001A4BE0[], D_001A4C60[];
extern s32 D_L30_001DF2C0;
extern f32 D_L30_001DEAD8, D_L30_001DEAC8, D_L30_001DEAC4, D_L30_001DEACC, D_L30_001DEAB8, D_L30_001DEABC, D_L30_001DEAC0;
extern f32 D_L30_001E1BC4, D_L30_001E1BC0, D_L30_001E1BCC, D_L30_001E1BC8;
typedef struct {
    s32 id;
    u8 pad[0x18];
    f32 weight;
} Row_003A8E10;

typedef struct {
    vu0_v4 pos;
    vu0_v4 acc;
    f32 vel[3];
    f32 total_weight;
    Row_003A8E10 rows[32];
} State_003A8E10;

void func_L30_003A8E10(u8 *m, vu0_v4 *out, vu0_v4 *input, u8 *other) {
    extern s32 func_L01_00456500(void *, s32);
    extern s32 func_L30_0034D8D8(void *, f32);
    extern void func_L30_003A9508(void *, void *, void *);
    extern f32 func_L30_003A9928(s32, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004482A0(void *, void *, f32, f32, f32, f32);
    extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
    extern f32 func_L30_0034DA70(s32, f32, f32, f32);
    vu0_v4 original, tmp, delta;
    f32 a, b, c, d, e, f, g, h;
    u8 *hero = D_001A4BE0;
    State_003A8E10 *v = *(State_003A8E10 **)(m + 0x68);
    s32 i, j, k;

    *out = *input;
    v->total_weight = 0;
    original = *input;
    if (*(s32 *)(hero + 0x25c4) == 159 || *(s32 *)(hero + 0x25c4) == 161 || *(s32 *)(hero + 0x25c4) == 160) return;
    for (i = 0; i < 32; i++) {
        if (v->rows[i].id != -1 && func_L01_00456500(D_001A4C60, v->rows[i].id) && v->rows[i].weight > 0.0f) {
            f32 weight, blend;
            func_L30_003A9508(&v->rows[i], &tmp, &D_L30_002A2560[i]);
            weight = v->rows[i].weight * func_L30_003A9928(v->rows[i].id, D_001A4C60);
            blend = weight / (weight + v->total_weight);
            func_0038CE20(&tmp, &tmp, blend);
            func_0038CE20(&v->acc, &v->acc, 1.0f - blend);
            vec_add_ab(&v->acc, &v->acc, &tmp);
            v->total_weight += weight;
        }
    }
    for (i = 0; i < 32; i++) {
        if (v->rows[i].id != -1 && !func_L01_00456500(D_001A4C60, v->rows[i].id)) {
            D_L30_002A2560[i] = *(vu0_q *)&v->acc;
        }
    }
    if (!func_L30_0034D8D8(D_001A4C60, D_L30_001DEAD8) || D_L30_001DF2C0 < 20) {
        *out = v->acc;
        v->vel[0] = 0; v->vel[1] = 0; v->vel[2] = 0;
    } else {
        func_L01_004482A0(&out->x, &v->vel[0], v->acc.x, D_L30_001DEAC8, D_L30_001DEAC4, D_L30_001DEACC);
        func_L01_004482A0(&out->y, &v->vel[1], v->acc.y, D_L30_001DEAC8, D_L30_001DEAC4, D_L30_001DEACC);
        func_L01_004482A0(&out->z, &v->vel[2], v->acc.z, D_L30_001DEAC8, D_L30_001DEAC4, D_L30_001DEACC);
    }
    if (D_L30_001DEAB0 && D_L30_001DF2C0 > 20) {
        f32 x, z, scale;
        u8 *hero = D_001A4BE0;
        func_L30_0034CDC0(&a, &b, &c, &d, D_L30_001DEAB8);
        func_L30_0034CDC0(&e, &f, &g, &h, D_L30_001DEABC);
        x = out->x - (e + f) * 0.5f;
        z = out->z - (g + h) * 0.5f;
        a += x; b += x; e += x; f += x; c += z; d += z; g += z; h += z;
        tmp = *out;
        if (*(f32 *)(hero + 0x80) < a) {
            scale = 1.0f + (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(0, *(f32 *)(hero + 0x80), e, a);
            func_L01_004482A0(&out->x, &v->vel[0], out->x - (a - *(f32 *)(hero + 0x80)), scale * D_L30_001DEAC8, D_L30_001DEAC4, scale * D_L30_001DEACC);
        }
        if (*(f32 *)(hero + 0x88) < c && *(f32 *)(hero + 0x2f8) > 2.0f && *(s32 *)(hero + 0x25c4) != 161) {
            scale = 1.0f + (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(0, *(f32 *)(hero + 0x88), g, c);
            func_L01_004482A0(&out->z, &v->vel[2], out->z - (c - *(f32 *)(hero + 0x88)), scale * D_L30_001DEAC8, D_L30_001DEAC4, scale * D_L30_001DEACC);
        }
        {
        u8 *hero = D_001A4BE0;
        if (b < *(f32 *)(hero + 0x80)) {
            scale = 1.0f + (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(1, *(f32 *)(hero + 0x80), b, f);
            func_L01_004482A0(&out->x, &v->vel[0], out->x + (*(f32 *)(hero + 0x80) - b), scale * D_L30_001DEAC8, D_L30_001DEAC4, scale * D_L30_001DEACC);
        }
        if (*(f32 *)(hero + 0x88) > d) {
            scale = 1.0f + (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(1, *(f32 *)(hero + 0x88), d, h);
            func_L01_004482A0(&out->z, &v->vel[2], out->z + (*(f32 *)(hero + 0x88) - d), scale * D_L30_001DEAC8, D_L30_001DEAC4, scale * D_L30_001DEACC);
        }
        }
        vec_sub_ba(&delta, out, &tmp);
        for (k = 0; k < 32; k++) {
            if (v->rows[k].id != -1 && func_L01_00456500(D_001A4C60, v->rows[k].id)) {
                vec_add_ab(&D_L30_002A2560[k], &D_L30_002A2560[k], &delta);
            }
        }
    }
    if (D_L30_001DEAB4 && other && *(u8 **)(other + 0x68)) {
        *out = *(vu0_v4 *)(*(u8 **)(other + 0x68) + 0xc0);
        v->vel[0] = 0; v->vel[1] = 0; v->vel[2] = 0;
    }
    if (D_L30_001E1BC4 > 0.0f) { if (out->x < D_L30_001E1BC4) out->x = D_L30_001E1BC4; D_L30_001E1BC4 = 0.0f; }
    if (D_L30_001E1BC0 > 0.0f) { if (out->x > D_L30_001E1BC0) out->x = D_L30_001E1BC0; D_L30_001E1BC0 = 0.0f; }
    if (D_L30_001E1BCC > 0.0f) { if (out->z < D_L30_001E1BCC) out->z = D_L30_001E1BCC; D_L30_001E1BCC = 0.0f; }
    if (D_L30_001E1BC8 > 0.0f) { if (out->z > D_L30_001E1BC8) out->z = D_L30_001E1BC8; D_L30_001E1BC8 = 0.0f; }
    *input = *out;
    v->pos = *(vu0_v4 *)D_001A4C60;
}
/* localdecomp:end func_L30_003A8E10 */
