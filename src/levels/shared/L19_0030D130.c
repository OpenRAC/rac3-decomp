#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_0030D130 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0030D130;

extern s32 D_L19_001DF720[] __attribute__((section(".sdata")));
extern s32 D_L19_001DF240[] __attribute__((section(".sdata")));
extern s32 D_L19_001DC5CC[] __attribute__((section(".sdata")));
__asm__(".extern D_L19_001DC5C8, 4");
extern s32 D_L19_001DC5C8;
__asm__(".extern D_L19_001DC5D0, 2");
extern u16 D_L19_001DC5D0;
__asm__(".extern D_L19_001DC5D4, 2");
extern u16 D_L19_001DC5D4;
__asm__(".extern D_L19_001DC5D8, 4");
extern s32 D_L19_001DC5D8;
__asm__(".extern D_L19_001DC5DC, 4");
extern f32 D_L19_001DC5DC;
__asm__(".extern D_L19_001DC5E0, 4");
extern f32 D_L19_001DC5E0;
__asm__(".extern D_L19_001DC5E4, 4");
extern f32 D_L19_001DC5E4;
__asm__(".extern D_L19_001DC5E8, 4");
extern f32 D_L19_001DC5E8;
extern u8 D_L19_001D66F0[] __attribute__((section(".sdata")));

void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
void func_L19_0030D388(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, f32, f32, f32, f32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00456230(void *, s32);

void func_L19_0030D130(u8 *object) {
    V4_0030D130 offset, velocity;

    switch (object[0x20]) {
    case 0:
        if ((s32)object < D_L19_001DF720[0]) {
            *(s32 *)(object + 0x9C) = 15;
            func_L01_004450F0(object, 3, -1);
        } else {
            *(u16 *)(object + 0x7C) = D_L19_001DC5D0;
            func_L01_004450F0(object, 1, -1);
        }
        break;
    case 1:
        if (object[0x31]) {
            func_L01_00404808(func_L19_0030D388, object);
            *(s32 *)(object + 0x78) = func_0038DBD8(D_L19_001DC5C8, D_L19_001DC5CC[0],
                (func_0038D0B0((f32)(D_L19_001DF240[0] % 150) / 150.0f * 6.28318f - 3.14159f) + 1.0f) * 0.5f);
        }
        if (func_L01_00447490(object, 0x10000, 0)) {
            *(u128_t *)&offset = 0;
            *(u128_t *)&velocity = 0;
            offset.z = 0.5f;
            velocity.z = 0.060000002f;
            vec_add_ba(&offset, &offset, object + 0x10);
            func_L02_00429840(object, &offset, 5, 1, &velocity, 0.333f, 3.0f, 0.5f, 1.0f, 0x504040C0, 0, 180);
            func_L01_00451FE0(object, D_L19_001DC5D8, D_L19_001D66F0, 255, 180, 0, 0, 35, 0, 3,
                D_L19_001DC5DC, D_L19_001DC5E0, D_L19_001DC5E4, D_L19_001DC5E8, -1.0f, -1.0f, 1.0f, 1.0f);
            func_003A52A0(0, 0, object);
            *(u16 *)(object + 0x7C) = D_L19_001DC5D4;
            func_L01_00456230(object, 1);
            *(s32 *)(object + 0x9C) = 15;
            *(u16 *)(object + 0x34) |= 2;
            func_L01_004450F0(object, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L19_0030D130 */

/* localdecomp:start func_L19_0030D388 */
#include "vu0.h"

typedef struct {
    u128_t vertices[4];
    u32 colors[4];
    f32 uv[4][2];
    unsigned long zero;
    unsigned long texture;
    unsigned long prim;
    unsigned long mode;
} Packet_0030D388;

extern u8 D_L19_001E1F40[];
extern vu0_v4 D_L19_001E2080;
extern f32 D_L19_0026DD40[][4];
extern f32 D_L19_002AA0F0[][4];
extern f32 D_L19_002AAB90[][4];
extern f32 D_L19_002AAF20[][4];
extern f32 D_L19_002AA8F0[][4];
extern f32 D_L19_0026DB70[][2];
extern f32 D_L19_002AA720[][2];
extern s16 D_L19_002AA480[][8];
__asm__(".extern D_L19_001DC608, 4");
extern f32 D_L19_001DC608;
__asm__(".extern D_L19_001DC600, 4");
extern s32 D_L19_001DC600;
__asm__(".extern D_L19_001DC5EC, 4");
extern s32 D_L19_001DC5EC;
__asm__(".extern D_L19_001DC5F0, 4");
extern s32 D_L19_001DC5F0;
__asm__(".extern D_L19_001DC5F4, 4");
extern s32 D_L19_001DC5F4;
__asm__(".extern D_L19_001DC5F8, 4");
extern s32 D_L19_001DC5F8;
__asm__(".extern D_L19_001DC5FC, 4");
extern s32 D_L19_001DC5FC;
__asm__(".extern D_L19_001DC604, 4");
extern u32 D_L19_001DC604;

extern void func_0038CF68(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

/* from rac1-decomp's draw_gadgebot_spawn_container: transform src by the matrix into dst */
static __inline__ void TransformPoint_0030D388(f32 *dst, f32 *src, f32 (*m)[4]) {
    func_0038D028(dst, src, m);
}

/* from rac1-decomp's draw_gadgebot_spawn_container */
void func_L19_0030D388(void *arg0) {
    u8 *moby = arg0;
    Packet_0030D388 quad;
    f32 matrix[3][4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 direction[4] __attribute__((aligned(16)));
    f32 facePos[4] __attribute__((aligned(16)));
    f32 normal[4] __attribute__((aligned(16)));
    f32 projected[4] __attribute__((aligned(16)));
    s32 near;
    s32 i;
    f32 scale;
    f32 length;
    f32 *g;

    scale = *(f32 *)(moby + 0x2C) / *(f32 *)(*(u8 **)(moby + 0x24) + 0x24);
    func_0038CF68(matrix[0], moby + 0xC0, scale);
    func_0038CF68(matrix[1], moby + 0xD0, scale);
    func_0038CF68(matrix[2], moby + 0xE0, scale);
    pos[0] = *(f32 *)(moby + 0x10);
    pos[1] = *(f32 *)(moby + 0x14);
    pos[2] = *(f32 *)(moby + 0x18);
    pos[3] = 1.0f;
    near = 0;
    g = (f32 *)D_L19_001E1F40;
    if (fabs_asm(g[0x140 / 4] - pos[0]) < 16.0f && fabs_asm(g[0x144 / 4] - *(f32 *)(moby + 0x14)) < 16.0f) {
        near = 1;
    }
    if (near) {
        for (i = 0; i < 57; i++) {
            func_0038D028(D_L19_0026DD40[i], D_L19_002AA0F0[i], matrix);
            vec_sub_ab(direction, D_L19_0026DD40[i], &D_L19_001E2080);
            func_0038CF68(direction, direction, 1.0f);
            func_0038D028(normal, D_L19_002AAB90[i], matrix);
            func_0038CF68(normal, normal, D_L19_001DC608);
            scale = func_0038CE68(normal, direction);
            func_0038CE20(projected, normal, scale + scale);
            vec_sub_ab(projected, direction, projected);
            func_0038CF68(projected, projected, 1.0f);
            projected[2] += 1.0f;
            length = sqrt_asm(projected[2] + projected[2]);
            D_L19_0026DB70[i][0] = projected[0] / (length + length) + 0.5f;
            D_L19_0026DB70[i][1] = projected[1] / (length + length) + 0.5f;
        }
    } else {
        for (i = 0; i < 57; i++) {
            func_0038D028(D_L19_0026DD40[i], D_L19_002AA0F0[i], matrix);
        }
    }
    quad.texture = func_00389598(D_L19_001DC600);
    quad.prim = 0xFF9000000260L;
    quad.mode = (long)D_L19_001DC5EC | (long)D_L19_001DC5F0 << 2 | (long)D_L19_001DC5F4 << 4 |
                (long)D_L19_001DC5F8 << 6 | (long)D_L19_001DC5FC << 32;
    quad.zero = 0;
    quad.colors[3] = D_L19_001DC604;
    quad.colors[2] = D_L19_001DC604;
    quad.colors[1] = D_L19_001DC604;
    quad.colors[0] = D_L19_001DC604;
    i = 0;
    do {
        f32 *center = facePos;
        TransformPoint_0030D388(center, D_L19_002AAF20[i], matrix);
        vec_sub_ab(direction, center, &D_L19_001E2080);
        func_0038CF68(direction, direction, 1.0f);
        func_0038D000(center, D_L19_002AA8F0[i], matrix);
        if (!(0.0f < func_0038CE68(direction, center))) {
            s16 *idx = D_L19_002AA480[i];
            s32 j;
            for (j = 0; j < 4; j++, idx += 2) {
                s16 v = idx[0];
                quad.vertices[j] = *(u128_t *)D_L19_0026DD40[v];
                if (near) {
                    quad.uv[j][0] = D_L19_0026DB70[v][0];
                    quad.uv[j][1] = D_L19_0026DB70[v][1];
                } else {
                    quad.uv[j][0] = D_L19_002AA720[idx[1]][0];
                    quad.uv[j][1] = D_L19_002AA720[idx[1]][1];
                }
            }
            func_003D2DA0(&quad, 0, 0);
        }
        i++;
    } while (i < 42);
}
/* localdecomp:end func_L19_0030D388 */
