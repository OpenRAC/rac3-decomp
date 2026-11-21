#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037BCF8 */
typedef struct { vu0_v4 row[3]; } Basis_0037BCF8;
typedef struct { vu0_v4 vertex[4]; s32 rgba[4]; f32 uv[8]; u8 state[32]; } Quad_0037BCF8;
extern f32 D_L01_001D7C50[][4] __attribute__((section(".data")));
void func_L01_0037BCF8(u8 *self, void *position, s32 texture, s32 colour, s32 mode, f32 size, f32 length, f32 angle) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Quad_0037BCF8 quad;
    vu0_v4 matrix[4];
    vu0_v4 offset;
    vu0_v4 turn[3];
    s32 i;
    f32 *src, *dst;
    func_003D93B0(&quad, texture, mode, 128);
    quad.rgba[0] = quad.rgba[1] = quad.rgba[2] = quad.rgba[3] = colour;
    quad.uv[0] = 0.0f;
    quad.uv[1] = 0.0f;
    quad.uv[2] = 0.0f;
    quad.uv[3] = 1.0f;
    quad.uv[4] = 1.0f;
    quad.uv[5] = 0.0f;
    quad.uv[6] = 1.0f;
    quad.uv[7] = 1.0f;
    matrix[3] = *(vu0_v4 *)position;
    *(Basis_0037BCF8 *)matrix = *(Basis_0037BCF8 *)(self + 0xC0);
    if (angle != 0.0f) {
        *(vu0_q *)&offset = 0;
        offset.x = angle;
        func_0038D308(turn, &offset);
        func_0038D5F0(matrix, matrix, turn);
    }
    i = 3;
    func_0038CE20(&offset, matrix, length);
    vec_add_ab(&matrix[3], &matrix[3], &offset);
    src = D_L01_001D7C50[0];
    dst = (f32 *)quad.vertex;
    do {
        func_0038CE20(dst, src, size);
        src += 4;
        i--;
        func_0038D028(dst, dst, matrix);
        dst += 4;
    } while (i >= 0);
    func_003D2DA0(&quad, 0, 0);
}
/* localdecomp:end func_L01_0037BCF8 */
