/* functional: high. Codex PAL near miss (188 words differ in context), checked block by block against the assembly: same calls in the same order with the same arguments, same constants (0x28A5A281/0x3CA5A281 colours, 16.0 range, 0.1 scale, /50 blend, 2*sqrt(2(z+1)) sphere-map divisor), same 43-vertex and 38-quad loops and the same globals; differences are register allocation and scheduling. */
/* localdecomp:start func_003A7EF8 */
#include "vu0.h"
typedef struct {
    vu0_q vertex[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long zero, texture, state, tag;
} Draw_003A7EF8;
typedef struct {
    Draw_003A7EF8 draw;
    vu0_v4 matrix[4], direction, projected, normal;
} Work_003A7EF8;
typedef struct { u8 pad[0x140]; f32 x, y; } Camera_003A7EF8;
extern vu0_v4 D_003343D0[], D_003348E0[], D_22D9C0[];
extern f32 D_22DC70[][2], D_22DDC8[][2];
extern s16 D_00334680[][4][2];
extern s32 D_001D5B94;
extern s16 D_16C5A0[];
extern Camera_003A7EF8 D_2222C0;
extern vu0_v4 D_222400;
extern s32 D_001D6EE0, D_001D6EE4, D_001D6EE8;
__asm__(".extern D_001D6EE0, 4");
__asm__(".extern D_001D6EE4, 4");
__asm__(".extern D_001D6EE8, 4");
void func_003A7EF8(u8 *self) {
    extern long func_00389978(s32);
    extern void func_003C3278(void *, s32, void *);
    extern s32 func_0038CEB0(void *);
    extern void func_0038D408(void *, void *, void *);
    extern void func_0038D348(s32, s32, f32);
    extern f32 func_0038D248(void *, void *);
    extern void func_0038D200(f32 *, void *, f32);
    extern void func_003D3158(void *, s32, s32);
    Work_003A7EF8 w;
    vu0_v4 *first = D_003343D0;
    vu0_v4 *second = D_003348E0;
    s32 i, j, enabled;
    void *matrix;
    u32 color;
    f32 blend;
    long texture;
    texture = func_00389978(21);
    color = D_001D5B94 == 2 ? 0x28A5A281 : 0x3CA5A281;
    w.draw.tag = 0x8000000044UL;
    w.draw.state = 0xFF9000000260UL;
    w.draw.texture = texture;
    w.draw.zero = 0;
    w.draw.color[0] = color;
    w.draw.color[1] = color;
    w.draw.color[2] = color;
    w.draw.color[3] = color;
    matrix = w.matrix;
    func_003C3278(self, 0, matrix);
    enabled = 0;
    if (D_001D5B94 == 0 || D_001D5B94 == 2) {
        if (fabs_asm(D_2222C0.x - *(f32 *)(self + 0x10)) < 16.0f &&
            fabs_asm(D_2222C0.y - *(f32 *)(self + 0x14)) < 16.0f) enabled = 1;
    } else enabled = 1;
    if (D_001D5B94 == 6 && D_16C5A0[0] == 2) enabled = 0;
    if (enabled || D_001D6EE0 == 1) {
        vu0_v4 *out, *normal = second;
        f32 *uv, *old_uv;
        D_001D6EE4 = 1;
        func_0038CEB0(&D_001D6EE8);
        blend = (f32)D_001D6EE8 / 50.0f;
        out = D_22D9C0;
        uv = D_22DC70[0];
        old_uv = D_22DDC8[0];
        i = 42;
        do {
            f32 scale, root, x, y;
            func_0038D408(out, first, matrix);
            vec_sub_ab(&w.normal, out, &D_222400);
            func_0038D348((s32)&w.normal, (s32)&w.normal, 1.0f);
            func_0038D408(&w.direction, normal, matrix);
            func_0038D348((s32)&w.direction, (s32)&w.direction, 0.1f);
            func_0038D200(&w.projected.x, &w.direction, func_0038D248(&w.direction, &w.normal) * 2.0f);
            vec_sub_ab(&w.projected, &w.normal, &w.projected);
            func_0038D348((s32)&w.projected, (s32)&w.projected, 1.0f);
            w.projected.z += 1.0f;
            root = sqrt_asm(w.projected.z + w.projected.z);
            scale = root + root;
            if (D_001D6EE0 == 1 || D_001D6EE8 == 0) {
                x = w.projected.x / scale + 0.5f;
                y = w.projected.y / scale + 0.5f;
                uv[0] = x;
                uv[1] = y;
            } else {
                x = w.projected.x / scale + 0.5f;
                y = w.projected.y / scale + 0.5f;
                uv[0] = x + (old_uv[0] - x) * blend;
                uv[1] = y + (old_uv[1] - y) * blend;
            }
            uv += 2; old_uv += 2; normal++; first++; out++;
            i--;
        } while (i >= 0);
        if (D_001D6EE0 == 1) D_001D6EE0 = 2;
    } else {
        if (D_001D6EE4 == 1) {
            vu0_v4 *out;
            f32 *uv, *old_uv;
            D_001D6EE4 = 0;
            out = D_22D9C0;
            uv = D_22DC70[0];
            old_uv = D_22DDC8[0];
            i = 42;
            do {
                old_uv[0] = uv[0];
                old_uv[1] = uv[1];
                func_0038D408(out, first, matrix);
                first++; out++; old_uv += 2; i--; uv += 2;
            } while (i >= 0);
        } else {
            vu0_v4 *out;
            out = D_22D9C0;
            i = 42;
            do {
                func_0038D408(out, first, matrix);
                first++; i--; out++;
            } while (i >= 0);
        }
        D_001D6EE8 = 50;
    }
    i = 0;
    do {
        s32 next = i + 1;
        s16 *indices = (s16 *)D_00334680[i];
        vu0_q *v = w.draw.vertex;
        f32 *tex = w.draw.uv[0];
        j = 3;
        do {
            s32 n = *indices;
            indices += 2;
            *v++ = *(vu0_q *)&D_22D9C0[n];
            tex[0] = D_22DC70[n][0];
            tex[1] = D_22DC70[n][1];
            tex += 2; j--;
        } while (j >= 0);
        func_003D3158(&w.draw, 0, 0);
        i = next;
    } while (i < 38);
}
/* localdecomp:end func_003A7EF8 */
