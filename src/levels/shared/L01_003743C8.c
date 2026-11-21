#include "common.h"

/* localdecomp:start func_L01_003743C8 */
#include "vu0.h"

typedef struct {
    vu0_v4 vertices[4];   /* 0x00 */
    u32 colors[4];        /* 0x40 */
    f32 values[8];        /* 0x50 */
    u8 pad70[0x20];
} Prim_003743C8;

__asm__(".extern D_L01_001DDA44, 4");
extern s32 D_L01_001DDA44;
extern u8 D_L01_001E29C0[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(f32, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_003743C8(void *object) {
    vu0_v4 basis[4];
    Prim_003743C8 prim;
    vu0_v4 disp;
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
    func_0038CF68(-1.0f, &basis[0], vars + 0x40);
    vec_sub_ba(&basis[1], D_L01_001E29C0, obj + 0x10);
    func_0038CE90(&basis[2], &basis[1], &basis[0]);
    func_0038CF68(width, &basis[2], &basis[2]);
    func_0038CF68(height, &basis[0], &basis[0]);
    *(s32 *)&basis[0].w = 0;
    *(s32 *)&basis[1].w = 0;
    *(s32 *)&basis[2].w = 0;
    if (D_L01_001DDA44) {
        func_003D93B0(&prim, 0x3F, 1, 0x80);
    } else {
        func_003D93B0(&prim, 0x3E, 1, 0x80);
    }
    prim.values[0] = 0;
    prim.values[1] = 0;
    prim.values[2] = 0;
    prim.values[3] = 1;
    prim.values[4] = 1;
    prim.values[5] = 0;
    prim.values[6] = 1;
    prim.values[7] = 1;
    for (i = 0; i < 4; i++) {
        qzero(&prim.vertices[i]);
        if (i < 2) prim.vertices[i].x = 0;
        else prim.vertices[i].x = 1;
        prim.vertices[i].y = 0;
        if (i & 1) prim.vertices[i].z = 1;
        else prim.vertices[i].z = -1;
        prim.vertices[i].w = 1;
        prim.colors[i] = 0x7FFFFFFF;
    }
    {
        f32 offset = -1.0f;
        if (D_L01_001DDA44) offset = -2.0f;
        *(vu0_q *)&disp = 0;
        disp.y = offset;
    }
    func_0038D000(&basis[3], &disp, obj + 0xC0);
    vec_add_ba(&basis[3], &basis[3], vars + 0x10);
    basis[3].w = 1.0f;
    func_003D2DA0(&prim, basis, 0);
}
/* localdecomp:end func_L01_003743C8 */
