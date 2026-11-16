/* PAL near miss (Codex wave 8): near miss: 13 words differ with the file's flags.
 * Worker's note: 13 diff: build/codex/w439/func_L01_003743C8.02.log; all scalar/primitive code matches; remaining global VU load address and ordinary instructions interleaved within retail VU sequences, fixed file lacks vf0-vf2 flag
 */
#include "common.h"
/* localdecomp:start func_L01_003743C8 */
#include "vu0.h"
typedef struct {
    vu0_v4 vertices[4];
    u32 colors[4];
    f32 values[8];
    u8 pad70[0x20];
} Primitive_003743C8;
typedef union { vu0_q q; f32 f[4]; } Vector_003743C8;
__asm__(".extern D_L01_001DDA44, 4");
extern s32 D_L01_001DDA44;
extern vu0_v4 D_L01_001E29C0;
void func_L01_003743C8(void *object) {
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003D2DA0(void *, void *, s32);
    vu0_v4 basis[4];
    Primitive_003743C8 primitive;
    Vector_003743C8 displacement;
    u8 *obj = object;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 width, height;
    s32 i;
    if (D_L01_001DDA44) {
        width = func_003824E0(0.75f, 0.95f);
        height = func_003824E0(2.0f, 2.5f);
    } else {
        width = func_003824E0(0.275f, 0.475f);
        height = func_003824E0(1.0f, 1.3f);
    }
    func_0038CF68(&basis[0], vars + 0x40, -1.0f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(basis[1]) : "m"(*(vu0_v4 *)(obj + 16)), "m"(D_L01_001E29C0) : "vf1", "vf2");
    func_0038CE90(&basis[2], &basis[1], &basis[0]);
    func_0038CF68(&basis[2], &basis[2], width);
    func_0038CF68(&basis[0], &basis[0], height);
    *(s32 *)&basis[0].w = 0;
    *(s32 *)&basis[1].w = 0;
    *(s32 *)&basis[2].w = 0;
    if (D_L01_001DDA44) {
        func_003D93B0(&primitive, 0x3F, 1, 0x80);
    } else {
        func_003D93B0(&primitive, 0x3E, 1, 0x80);
    }
    primitive.values[0] = 0;
    primitive.values[1] = 0;
    primitive.values[2] = 0;
    primitive.values[3] = 1;
    primitive.values[4] = 1;
    primitive.values[5] = 0;
    primitive.values[6] = 1;
    primitive.values[7] = 1;
    for (i = 0; i < 4; i++) {
        qzero(&primitive.vertices[i]);
        if (i < 2) primitive.vertices[i].x = 0;
        else primitive.vertices[i].x = 1;
        primitive.vertices[i].y = 0;
        if (i & 1) primitive.vertices[i].z = 1;
        else primitive.vertices[i].z = -1;
        primitive.vertices[i].w = 1;
        primitive.colors[i] = 0x7FFFFFFF;
    }
    {
        f32 offset = -1.0f;
        if (D_L01_001DDA44) offset = -2.0f;
        displacement.q = 0;
        displacement.f[1] = offset;
    }
    func_0038D000(&basis[3], &displacement, obj + 0xC0);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(basis[3]) : "m"(*(vu0_v4 *)(vars + 16)), "m"(basis[3]) : "vf1", "vf2");
    basis[3].w = 1.0f;
    func_003D2DA0(&primitive, basis, 0);
}
/* localdecomp:end func_L01_003743C8 */
