#include "common.h"

/* localdecomp:start func_L07_003CB9B8 */
/* from rac3-decomp's func_L01_00395288 (same shape) */
#include "vu0.h"
extern s32 D_L07_001D545C;
extern s32 D_L07_001DE68C;
extern s32 D_L07_001DE690;
__asm__(".extern D_L07_001DE68C, 4");
__asm__(".extern D_L07_001DE690, 4");
extern u8 *D_L07_0021EC98[];
extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L07_003CB9B8(void *a0) {
    f32 v[4];
    s32 i;
    f32 size;
    s32 color;
    u8 *particle;

    for (i = 0; i < 2; i++) {
        func_L01_00443B88(v, 0.08000000566244125f, 0.11000000685453415f);
        v[2] = fabs_asm(v[2]) + func_003824E0(2.0f, 3.5f) * 0.020000001f;
        size = func_003824E0(0.06f, 0.22f);
        color = func_00382468(3) ? D_L07_001DE690 : D_L07_001DE68C;
        switch (D_L07_001D545C) {
        case 41:
        case 45:
        case 47:
            color = func_00382468(3) ? 0x605129 : 0x5A523E;
            break;
        case 12:
        case 18:
        case 40:
        case 42:
        case 43:
        case 44:
            color = func_00382468(3) ? 0x263438 : 0x273538;
            break;
        }
        particle = func_L01_004713C8(a0, v, (func_00382498(90, 150) * 5 + 2) / 6, color, -2, 127, 127,
                                     size * 210000.0f, size * 210000.0f, 0.006240000482648611f, 0);
        if (particle != 0) {
            particle[2] = D_L07_0021EC98[97][func_00382468(3) + 10];
            particle[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L07_003CB9B8 */

/* localdecomp:start func_L07_003CBB88 */
typedef struct {
    u8 r, g, b, a;
} Col_003CBB88;

typedef struct {
    u8 pad0[0x10];
    u8 pos[0x28];
    s32 count;
    Col_003CBB88 *cols;
} Src_003CBB88;

typedef struct {
    u8 pad0[0x68];
    Src_003CBB88 *src;
} Obj_003CBB88;

typedef struct {
    u32 c[4];
} Cols4_003CBB88;

typedef struct {
    u8 pad0[0x24];
    f32 f24;
} Info_003CBB88;

typedef struct {
    u8 pad0[0x24];
    Info_003CBB88 *info;
    u8 pad28[4];
    f32 f2C;
} Part_003CBB88;

typedef struct {
    f32 x, y, z, w;
} Vec_003CBB88;

extern f32 D_L07_001DE698;
extern f32 D_L07_001DE69C;
extern f32 D_L07_001DE6A0;
extern s32 D_L07_001DE6A4;
extern s32 D_L07_001DE6A8;
extern s32 D_L07_001DE6AC;
extern s32 D_L07_001DE6B0;
extern f32 D_L07_001DEF50;
__asm__(".extern D_L07_001DE698, 4");
__asm__(".extern D_L07_001DE69C, 4");
__asm__(".extern D_L07_001DE6A0, 4");
__asm__(".extern D_L07_001DE6A4, 4");
__asm__(".extern D_L07_001DE6A8, 4");
__asm__(".extern D_L07_001DE6AC, 4");
__asm__(".extern D_L07_001DE6B0, 4");
__asm__(".extern D_L07_001DEF50, 4");

extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern Part_003CBB88 *func_L01_003298C8(void *, Vec_003CBB88 *, s32, s32, s32, u32, Cols4_003CBB88 *, s32, s32, s32, f32, f32);

void func_L07_003CBB88(Obj_003CBB88 *obj) {
    Src_003CBB88 *src = obj->src;
    Vec_003CBB88 vel;
    Cols4_003CBB88 cols;
    Cols4_003CBB88 tmp;
    f32 speed;
    f32 yaw;
    u32 raw;
    s32 b;
    s32 a;
    s32 i;
    Part_003CBB88 *part;

    raw = 0;
    speed = func_003824E0(10.0f, 20.0f) * 0.020000001f * D_L07_001DE698;
    yaw = func_00382538();
    func_00382760(&vel, speed, yaw, func_003824E0(0.43633232f, 0.7853982f));

    tmp.c[0] = ((s32)(f32)D_L07_001DE6B0 << 24) | ((s32)(f32)D_L07_001DE6AC << 16) | ((s32)(f32)D_L07_001DE6A8 << 8) | (s32)(f32)D_L07_001DE6A4;
    tmp.c[1] = ((s32)((f32)D_L07_001DE6B0 * 0.75f) << 24) | ((s32)((f32)D_L07_001DE6AC * 0.75f) << 16) | ((s32)((f32)D_L07_001DE6A8 * 0.75f) << 8) | (s32)((f32)D_L07_001DE6A4 * 0.75f);
    tmp.c[2] = ((s32)((f32)D_L07_001DE6B0 * 0.5f) << 24) | ((s32)((f32)D_L07_001DE6AC * 0.5f) << 16) | ((s32)((f32)D_L07_001DE6A8 * 0.5f) << 8) | (s32)((f32)D_L07_001DE6A4 * 0.5f);
    tmp.c[3] = ((s32)((f32)D_L07_001DE6B0 * 0.25f) << 24) | ((s32)((f32)D_L07_001DE6AC * 0.25f) << 16) | ((s32)((f32)D_L07_001DE6A8 * 0.25f) << 8) | (s32)((f32)D_L07_001DE6A4 * 0.25f);
    cols = tmp;

    if (src->cols != 0) {
        i = func_00382468(src->count);
        raw = (src->cols[i].a << 24) | (src->cols[i].b << 16) | (src->cols[i].g << 8) | src->cols[i].r;
        cols.c[0] = ((s32)(f32)D_L07_001DE6B0 << 24) | ((s32)(f32)src->cols[i].b << 16) | ((s32)(f32)src->cols[i].g << 8) | (s32)(f32)src->cols[i].r;
        cols.c[1] = ((s32)((f32)D_L07_001DE6B0 * 0.75f) << 24) | ((s32)(src->cols[i].b * 0.75f) << 16) | ((s32)(src->cols[i].g * 0.75f) << 8) | (s32)(src->cols[i].r * 0.75f);
        cols.c[2] = ((s32)((f32)D_L07_001DE6B0 * 0.5f) << 24) | ((s32)(src->cols[i].b * 0.5f) << 16) | ((s32)(src->cols[i].g * 0.5f) << 8) | (s32)(src->cols[i].r * 0.5f);
        cols.c[3] = ((s32)((f32)D_L07_001DE6B0 * 0.25f) << 24) | ((s32)(src->cols[i].b * 0.25f) << 16) | ((s32)(src->cols[i].g * 0.25f) << 8) | (s32)(src->cols[i].r * 0.25f);
    }
    b = 0;
    a = 0;
    if (func_00382468(3) != 0 && D_L07_001DEF50 < 0.8f) {
        b = 1;
        a = 2;
    }
    part = func_L01_003298C8(src->pos, &vel, func_00382498(100, 125), a, b, raw, &cols, 0, 50, 120, 1.0f, 14.6f);
    if (part != 0) {
        part->f2C = part->info->f24 * func_003824E0(D_L07_001DE69C, D_L07_001DE6A0);
    }
}
/* localdecomp:end func_L07_003CBB88 */

/* localdecomp:start func_L07_003CC0C0 */
#include "vu0.h"
extern s32 D_L07_001DE6B4;
extern s32 D_L07_001DE6B8;
extern s32 D_L07_001DE6BC;
extern s32 D_L07_001DE6C0;
extern s32 D_L07_001DE6C4;
extern s32 D_L07_001DE6C8;
extern s32 D_L07_001DE6CC;
extern f32 D_L07_001DE6D0;
extern s32 D_L07_001DE6D4;
extern s32 D_L07_001DE6D8;
extern f32 D_L07_001DE6DC;
extern f32 D_L07_001DE6E0;
extern f32 D_L07_001DE6E4;
extern f32 D_L07_001DE6E8;
__asm__(".extern D_L07_001DE6B4, 4");
__asm__(".extern D_L07_001DE6B8, 4");
__asm__(".extern D_L07_001DE6BC, 4");
__asm__(".extern D_L07_001DE6C0, 4");
__asm__(".extern D_L07_001DE6C4, 4");
__asm__(".extern D_L07_001DE6C8, 4");
__asm__(".extern D_L07_001DE6CC, 4");
__asm__(".extern D_L07_001DE6D0, 4");
__asm__(".extern D_L07_001DE6D4, 4");
__asm__(".extern D_L07_001DE6D8, 4");
__asm__(".extern D_L07_001DE6DC, 4");
__asm__(".extern D_L07_001DE6E0, 4");
__asm__(".extern D_L07_001DE6E4, 4");
__asm__(".extern D_L07_001DE6E8, 4");
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L07_003CC0C0(void *a0) {
    vu0_v4 w;
    vu0_v4 v;
    s32 i;

    for (i = 0; i < D_L07_001DE6D4; i++) {
        *(vu0_q *)&v = 0;
        v.x = func_003824E0(D_L07_001DE6DC, D_L07_001DE6E0);
        v.y = func_003824E0(D_L07_001DE6DC, D_L07_001DE6E0);
        v.z = func_003824E0(D_L07_001DE6E4, D_L07_001DE6E8);
        w = v;
        func_0038CF68(&w, &w, D_L07_001DE6D0 * 0.020000001f);
        func_L01_004637C8(a0, &w,
                          (D_L07_001DE6C0 << 24) | (D_L07_001DE6BC << 16) | (D_L07_001DE6B8 << 8) | D_L07_001DE6B4,
                          (D_L07_001DE6BC << 16) | (D_L07_001DE6B8 << 8) | D_L07_001DE6B4,
                          D_L07_001DE6C4, D_L07_001DE6C8, D_L07_001DE6CC, D_L07_001DE6D8);
    }
}
/* localdecomp:end func_L07_003CC0C0 */

/* localdecomp:start func_L07_003CC1C0 */
extern f32 D_L07_001DEF50_003CC1C0;
extern s32 D_L07_001DE694;
__asm__(".extern D_L07_001DE694, 4");
extern s32 func_00382468(s32);
void func_L07_003CB9B8(void *);
extern void func_L07_003CBB88_003CC1C0(void *);
void func_L07_003CC0C0(void *);

void func_L07_003CC1C0(void *a0) {
    s32 n = D_L07_001DE694;
    u8 *q = *(u8 **)((u8 *)a0 + 0x68);
    void *p;
    s32 i;

    if (0.7f < D_L07_001DEF50_003CC1C0 && D_L07_001DEF50_003CC1C0 < 0.85f) {
        n--;
    } else if (0.85f < D_L07_001DEF50_003CC1C0) {
        n -= 2;
    }
    p = q + 0x10;
    for (i = 0; i < n; i++) {
        if (func_00382468(4) != 0) {
            func_L07_003CB9B8(p);
        } else {
            func_L07_003CBB88_003CC1C0(a0);
        }
    }
    func_L07_003CC0C0(p);
}
/* localdecomp:end func_L07_003CC1C0 */
