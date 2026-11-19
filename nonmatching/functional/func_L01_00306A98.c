/* functional: high. Draft verified line by line against PAL's assembly (alpha, both colour sets, flame quad setup, matrix, scaling); only bytes differ (363 diff). func_0038CF68 and func_003D2DA0 are declared with void* here; the file declares them later with S_0030CD20 / S_35A8A0 pointers, so those must be reconciled. */
typedef struct { u8 pad[0x11]; u8 index; } State_00306A98;
typedef struct { u8 pad0; u8 level; u8 pad2[0xEE]; } Row_00306A98;
typedef struct {
    f32 vertex[4][4];
    s32 color[4];
    f32 uv[4][2];
    long tag, texture, mode, clamp;
} Packet_00306A98;
extern State_00306A98 D_1425C0;
extern Row_00306A98 D_L01_002C5600[];
extern vu0_v4 D_L01_001E29C0;
void func_L01_00306A98(s32 arg)
{
    extern void func_L01_00307058(s32, f32 *, f32 *, s32, f32);
    extern long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_003D2DA0(void *, f32 *, s32);
    f32 matrix[4][4];
    vu0_v4 delta;
    vu0_v4 direction;
    Pool_003068B8 *pool;
    s32 i, j, next;
    s32 alpha;
    s32 color;
    for (i = 0; i < 10; i = next) {
        next = i + 1;
        pool = (Pool_003068B8 *)(i * sizeof(Pool_003068B8) + (u32)D_L01_001DC5C8);
        if (pool->active != 1) continue;
        if (pool->phase == 1) alpha = (s32)(pool->strength * 64.0f * 2.0f);
        else alpha = 64;
        if (D_L01_002C5600[D_1425C0.index].level >= 4) {
            func_L01_00307058(arg, (f32 *)&pool->flame_pos[0], (f32 *)pool, (alpha << 24) | 0x802020, 0.35f);
            func_L01_00307058(arg, (f32 *)&pool->flame_pos[0], (f32 *)pool, (alpha << 24) | 0xFFFFFF, 0.075f);
            continue;
        }
        color = alpha << 24;
        func_L01_00307058(arg, (f32 *)&pool->flame_pos[0], (f32 *)pool, color | 0x103080, 0.35f);
        func_L01_00307058(arg, (f32 *)&pool->flame_pos[0], (f32 *)pool, color | 0xFFFFFF, 0.075f);
        for (j = 0; j < 2; j++) {
            Packet_00306A98 *dst = (Packet_00306A98 *)((u8 *)pool + 0x2A0 + j * 0x90);
            Packet_00306A98 *src = (Packet_00306A98 *)((u8 *)pool + 0x60 + j * 0x90);
            f32 *pos = (f32 *)&pool->flame_pos[j];
            dst->texture = func_00389598(23);
            dst->mode = 0xFF9000000260L;
            dst->tag = 0;
            dst->clamp = ((long)(j % 2 + 1) << 2) | 0x8000000040L;
            if (D_L01_002C5600[D_1425C0.index].level >= 4) {
                dst->color[3] = 0x803010;
                dst->color[1] = 0x803010;
                dst->color[0] = color + 0x803010;
                dst->color[2] = color + 0x803010;
            } else {
                dst->color[3] = 0x103080;
                dst->color[1] = 0x103080;
                dst->color[0] = color + 0x103080;
                dst->color[2] = color + 0x103080;
            }
            if (*(s32 *)((u8 *)pool + 0x4E0 + j * 4) != 0) {
                dst->uv[0][0] = pool->u[j] + 0.0f;
                dst->uv[0][1] = 0.0f;
                dst->uv[1][0] = pool->u[j] + 1.0f;
                dst->uv[1][1] = 0.0f;
                dst->uv[2][0] = pool->u[j] + 0.0f;
                dst->uv[2][1] = 1.0f;
                dst->uv[3][0] = pool->u[j] + 1.0f;
                dst->uv[3][1] = 1.0f;
            } else {
                dst->uv[0][0] = pool->u[j] + 0.0f;
                dst->uv[0][1] = 1.0f;
                dst->uv[1][0] = pool->u[j] + 1.0f;
                dst->uv[1][1] = 1.0f;
                dst->uv[2][0] = pool->u[j] + 0.0f;
                dst->uv[2][1] = 0.0f;
                dst->uv[3][0] = pool->u[j] + 1.0f;
                dst->uv[3][1] = 0.0f;
            }
            vec_sub_ba(&delta, &D_L01_001E29C0, pos);
            func_003C5180(pos, &direction, 1);
            func_0038CF68(matrix[0], &delta, 1.0f);
            func_0038CE90(matrix[1], matrix[0], &direction);
            func_0038CF68(matrix[1], matrix[1], 1.0f);
            func_0038CE90(matrix[2], matrix[1], matrix[0]);
            matrix[3][0] = pos[0];
            matrix[3][1] = pos[1];
            matrix[3][2] = pos[2];
            matrix[3][3] = 1.0f;
            if (pool->phase == 1) {
                func_0038CE20(dst->vertex[0], src->vertex[0], 0.5f);
                func_0038CE20(dst->vertex[1], src->vertex[1], 0.5f);
                func_0038CE20(dst->vertex[2], src->vertex[2], 0.5f);
                func_0038CE20(dst->vertex[3], src->vertex[3], 0.5f);
            } else {
                func_0038CE20(dst->vertex[0], src->vertex[0], pool->strength);
                func_0038CE20(dst->vertex[1], src->vertex[1], pool->strength);
                func_0038CE20(dst->vertex[2], src->vertex[2], pool->strength);
                func_0038CE20(dst->vertex[3], src->vertex[3], pool->strength);
            }
            func_003D2DA0(dst, matrix[0], 0);
        }
    }
}
