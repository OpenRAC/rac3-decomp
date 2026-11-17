#include "common.h"

typedef struct { u8 pad[0x60]; u8 x60; } V_3D6A28;
typedef struct { u8 pad[0x68]; V_3D6A28 *x68; } M_3D6A28;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_3D6A28 *x18C; } B_3D6A28;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_3D6A28;

typedef struct { s32 x0; f32 x4; s32 x8; f32 xC; u8 pad10[0x20 - 0x10]; s32 x20; s32 x24; u8 pad28[0x3C - 0x28]; s32 x3C; u8 pad40[0x54 - 0x40]; s32 x54; } Src_003D9000;
typedef struct { u8 pad[0x68]; Src_003D9000 *x68; } Req_003D9000;
typedef struct { u8 pad[0x160]; f32 x160; s32 x164; f32 x168; s32 x16C; s32 x170; s32 x174; u8 pad178[0x180 - 0x178]; s32 x180; s32 x184; } Dst_003D9000;
typedef struct { u8 pad[0x68]; Dst_003D9000 *x68; } Obj_003D9000;

/* localdecomp:start func_L12_003D8DB8 */
#include "vu0.h"

typedef struct {
    vu0_v4 q[4];
    s32 k[4];
    f32 e0[4];
    f32 f0[4];
    u8 pad[0x20];
} S_003D8DB8;

extern f32 D_L12_001DF0E4;
__asm__(".extern D_L12_001DF0E4, 4");
extern vu0_v4 D_L12_001E2700;
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L12_003D8DB8(u8 *self) {
    vu0_v4 mat[4];
    vu0_v4 m[4];
    vu0_v4 t;
    S_003D8DB8 obj;
    f32 sa;
    f32 sb;
    s32 i;

    if (func_0038CAD0(*(u8 **)(self + 0x68) + 0x198) != 0) {
        return;
    }
    sa = func_003824E0(0.75f, 0.95f);
    sb = func_003824E0(2.0f, 2.5f);
    func_003C2EC0(self, 3, m);
    func_0038CF68(&t, &m[1], D_L12_001DF0E4);
    vec_add_ba(&m[3], &m[3], &t);
    func_0038CF68(&mat[0], &m[1], -1.0f);
    vec_sub_ba(&mat[1], &D_L12_001E2700, &m[3]);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], sa);
    func_0038CF68(&mat[0], &mat[0], sb);
    mat[0].w = 0.0f;
    mat[1].w = 0.0f;
    mat[2].w = 0.0f;
    func_003D93B0(&obj, 0x3F, 1, 0x80);
    obj.e0[0] = 0.0f;
    obj.e0[1] = 0.0f;
    obj.e0[2] = 0.0f;
    obj.e0[3] = 1.0f;
    obj.f0[0] = 1.0f;
    obj.f0[1] = 0.0f;
    obj.f0[2] = 1.0f;
    obj.f0[3] = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&obj.q[i]);
        obj.q[i].x = (i < 2) ? 0.0f : 1.0f;
        obj.q[i].y = 0.0f;
        obj.q[i].z = (i & 1) ? 1.0f : -1.0f;
        obj.q[i].w = 1.0f;
        obj.k[i] = 0x7FFFFFFF;
    }
    mat[3] = m[3];
    mat[3].w = 1.0f;
    func_003D2DA0(&obj, mat, 0);
    func_003D2DA0(&obj, mat, 0);
    func_003D2DA0(&obj, mat, 0);
    func_003D2DA0(&obj, mat, 0);
    func_003D2DA0(&obj, mat, 0);
    func_003D2DA0(&obj, mat, 0);
}
/* localdecomp:end func_L12_003D8DB8 */
