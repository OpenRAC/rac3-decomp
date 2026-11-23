#include "common.h"

/* NTSC-U counterpart of func_L07_003CBB88 (src/levels/shared/L07_003CB9B8.c): 60 Hz speed scale (1/60), lifetime 120-150 frames */
/* localdecomp:start func_L07_003CA188 */
typedef struct {
    u8 r, g, b, a;
} Col_003CA188;

typedef struct {
    u8 pad0[0x10];
    u8 pos[0x28];
    s32 count;
    Col_003CA188 *cols;
} Src_003CA188;

typedef struct {
    u8 pad0[0x68];
    Src_003CA188 *src;
} Obj_003CA188;

typedef struct {
    u32 c[4];
} Cols4_003CA188;

typedef struct {
    u8 pad0[0x24];
    f32 f24;
} Info_003CA188;

typedef struct {
    u8 pad0[0x24];
    Info_003CA188 *info;
    u8 pad28[4];
    f32 f2C;
} Part_003CA188;

typedef struct {
    f32 x, y, z, w;
} Vec_003CA188;

extern f32 D_L07_001DE6D8;
extern f32 D_L07_001DE6DC;
extern f32 D_L07_001DE6E0;
extern s32 D_L07_001DE6E4;
extern s32 D_L07_001DE6E8;
extern s32 D_L07_001DE6EC;
extern s32 D_L07_001DE6F0_003CA188;
extern f32 D_L07_001DEF50;
__asm__(".extern D_L07_001DE6D8, 4");
__asm__(".extern D_L07_001DE6DC, 4");
__asm__(".extern D_L07_001DE6E0, 4");
__asm__(".extern D_L07_001DE6E4, 4");
__asm__(".extern D_L07_001DE6E8, 4");
__asm__(".extern D_L07_001DE6EC, 4");
__asm__(".extern D_L07_001DE6F0_003CA188, 4");
__asm__(".extern D_L07_001DEF50, 4");

extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern Part_003CA188 *func_L01_00329470(void *, Vec_003CA188 *, s32, s32, s32, u32, Cols4_003CA188 *, s32, s32, s32, f32, f32);

void func_L07_003CA188(Obj_003CA188 *obj) {
    Src_003CA188 *src = obj->src;
    Vec_003CA188 vel;
    Cols4_003CA188 cols;
    Cols4_003CA188 tmp;
    f32 speed;
    f32 yaw;
    u32 raw;
    s32 b;
    s32 a;
    s32 i;
    Part_003CA188 *part;

    raw = 0;
    speed = func_0037E250(10.0f, 20.0f) * 0.016666668f * D_L07_001DE6D8;
    yaw = func_0037E2A8();
    func_0037E4B8(&vel, speed, yaw, func_0037E250(0.43633232f, 0.7853982f));

    tmp.c[0] = ((s32)(f32)D_L07_001DE6F0_003CA188 << 24) | ((s32)(f32)D_L07_001DE6EC << 16) | ((s32)(f32)D_L07_001DE6E8 << 8) | (s32)(f32)D_L07_001DE6E4;
    tmp.c[1] = ((s32)((f32)D_L07_001DE6F0_003CA188 * 0.75f) << 24) | ((s32)((f32)D_L07_001DE6EC * 0.75f) << 16) | ((s32)((f32)D_L07_001DE6E8 * 0.75f) << 8) | (s32)((f32)D_L07_001DE6E4 * 0.75f);
    tmp.c[2] = ((s32)((f32)D_L07_001DE6F0_003CA188 * 0.5f) << 24) | ((s32)((f32)D_L07_001DE6EC * 0.5f) << 16) | ((s32)((f32)D_L07_001DE6E8 * 0.5f) << 8) | (s32)((f32)D_L07_001DE6E4 * 0.5f);
    tmp.c[3] = ((s32)((f32)D_L07_001DE6F0_003CA188 * 0.25f) << 24) | ((s32)((f32)D_L07_001DE6EC * 0.25f) << 16) | ((s32)((f32)D_L07_001DE6E8 * 0.25f) << 8) | (s32)((f32)D_L07_001DE6E4 * 0.25f);
    cols = tmp;

    if (src->cols != 0) {
        i = func_0037E1D8(src->count);
        raw = (src->cols[i].a << 24) | (src->cols[i].b << 16) | (src->cols[i].g << 8) | src->cols[i].r;
        cols.c[0] = ((s32)(f32)D_L07_001DE6F0_003CA188 << 24) | ((s32)(f32)src->cols[i].b << 16) | ((s32)(f32)src->cols[i].g << 8) | (s32)(f32)src->cols[i].r;
        cols.c[1] = ((s32)((f32)D_L07_001DE6F0_003CA188 * 0.75f) << 24) | ((s32)(src->cols[i].b * 0.75f) << 16) | ((s32)(src->cols[i].g * 0.75f) << 8) | (s32)(src->cols[i].r * 0.75f);
        cols.c[2] = ((s32)((f32)D_L07_001DE6F0_003CA188 * 0.5f) << 24) | ((s32)(src->cols[i].b * 0.5f) << 16) | ((s32)(src->cols[i].g * 0.5f) << 8) | (s32)(src->cols[i].r * 0.5f);
        cols.c[3] = ((s32)((f32)D_L07_001DE6F0_003CA188 * 0.25f) << 24) | ((s32)(src->cols[i].b * 0.25f) << 16) | ((s32)(src->cols[i].g * 0.25f) << 8) | (s32)(src->cols[i].r * 0.25f);
    }
    b = 0;
    a = 0;
    if (func_0037E1D8(3) != 0 && D_L07_001DEF50 < 0.8f) {
        b = 1;
        a = 2;
    }
    part = func_L01_00329470(src->pos, &vel, func_0037E208(120, 150), a, b, raw, &cols, 0, 50, 120, 1.0f, 14.6f);
    if (part != 0) {
        part->f2C = part->info->f24 * func_0037E250(D_L07_001DE6DC, D_L07_001DE6E0);
    }
}
/* localdecomp:end func_L07_003CA188 */
