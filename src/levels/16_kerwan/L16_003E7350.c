#include "common.h"

INCLUDE_ASM("asm/levels", func_L16_003E7350);

/* localdecomp:start func_L16_003E7C00 */
#include "vu0.h"

extern s32 D_L16_001DFC40;
__asm__(".extern D_L16_001DFC40, 16");
extern s32 D_L16_001DF560;
__asm__(".extern D_L16_001DF560, 4");
extern s32 D_L16_001DF5A0;
__asm__(".extern D_L16_001DF5A0, 4");
extern s32 D_L16_001DF5F8;
__asm__(".extern D_L16_001DF5F8, 4");
extern s32 D_L16_001DF5F4;
__asm__(".extern D_L16_001DF5F4, 4");
extern f32 D_L16_001DF550;
__asm__(".extern D_L16_001DF550, 4");
extern s32 D_L16_001DF54C;
__asm__(".extern D_L16_001DF54C, 4");
extern f32 D_L16_001DF554;
__asm__(".extern D_L16_001DF554, 4");
extern f32 D_L16_001DF544;
__asm__(".extern D_L16_001DF544, 4");
extern f32 D_L16_001DF548;
__asm__(".extern D_L16_001DF548, 4");
extern s32 D_L16_001DF53C;
__asm__(".extern D_L16_001DF53C, 4");
extern s32 D_L16_001DF540;
__asm__(".extern D_L16_001DF540, 4");
extern void func_L01_0040C948(void *, void *);
extern long func_00389598(s32);
extern void func_0038D328(void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern void func_0038D2A0(void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C;
    long x70, x78, x80, x88;
} S_003E7C00;

typedef struct {
    u8 pad0[0xC];
    f32 f0C;
    vu0_v4 pos;
    s32 c20;
    s32 pad24;
    s32 c28;
    u8 pad2C[0xB0 - 0x2C];
} E_003E7C00;

extern E_003E7C00 D_002A3830[];

typedef struct {
    f32 f0;
    u8 pad4[0x14];
    f32 size;
    s32 first;
} St_003E7C00;

void func_L16_003E7C00(u8 *self)
{
    St_003E7C00 *st;
    S_003E7C00 s;
    vu0_v4 mat[4];
    vu0_v4 rot;
    E_003E7C00 *q;
    s32 i;
    s32 j;
    s32 c;
    f32 f;

    st = *(St_003E7C00 **)(self + 0x68);
    if (st == 0)
        return;
    if (self[0x20] == 2) {
        for (i = 0; i < 32; i++)
            func_L01_0040C948(&D_002A3830[st->first + i], &D_L16_001DF560);
        s.x78 = func_00389598(D_L16_001DF5F8);
        c = D_L16_001DF5F4;
        c = (c & 0xFFFFFF) | (self[0x23] << 24);
        s.x80 = 0xFF9000000260L;
        s.x70 = 4;
        s.x88 = ((long)0x80 << 32) | 0x48;
        s.x50 = 0.0f;
        s.x54 = 0.0f;
        s.x58 = 0.0f;
        s.x5C = 1.0f;
        s.x60 = 1.0f;
        s.x64 = 0.0f;
        s.x68 = 1.0f;
        s.x6C = 1.0f;
        s.c4C = c;
        s.c48 = c;
        s.c44 = c;
        s.c40 = c;
        qzero(&s.m[0]);
        s.m[0].x = -st->size;
        s.m[0].y = -st->size;
        s.m[0].w = 1.0f;
        qzero(&s.m[1]);
        s.m[1].x = st->size;
        s.m[1].y = -st->size;
        s.m[1].w = 1.0f;
        qzero(&s.m[2]);
        s.m[2].x = -st->size;
        s.m[2].y = st->size;
        s.m[2].w = 1.0f;
        qzero(&s.m[3]);
        s.m[3].x = st->size;
        s.m[3].y = st->size;
        s.m[3].w = 1.0f;

        qzero(&rot);
        rot.z = (f32)(D_L16_001DFC40 % 240) / 120.0f * 3.1415927f - 3.1415927f;
        func_0038D328(mat, &rot);
        *(vu0_q *)&mat[3] = *(vu0_q *)(self + 0x10);
        func_003D2DA0(&s, mat, 1);

        qzero(&rot);
        rot.z = -((f32)(D_L16_001DFC40 % 240) / 120.0f * 3.1415927f - 3.1415927f);
        func_0038D328(mat, &rot);
        *(vu0_q *)&mat[3] = *(vu0_q *)(self + 0x10);
        func_003D2DA0(&s, mat, 1);

        func_0038D2A0(mat);
        *(vu0_q *)&mat[3] = *(vu0_q *)(self + 0x10);
        func_003D2DA0(&s, mat, 1);
    } else {
        for (j = 0; j < 32; j++) {
            q = &D_002A3830[st->first + j];
            if (0.0f < q->f0C) {
                func_L01_0040C948(q, &D_L16_001DF5A0);
            } else {
                func_L01_0040C948(q, &D_L16_001DF560);
                func_003D9508(&D_002A3830[st->first + j].pos, D_L16_001DF54C, func_0038DBD8(D_002A3830[st->first + j].c20, D_002A3830[st->first + j].c28, func_003824E0(0.0f, 1.0f)) | 0x60000000, 1, D_L16_001DF550 * func_003824E0(0.75f, 1.25f), D_L16_001DF554, func_003824E0(-3.1415927f, 3.1415927f));
            }
            func_003D9508(&D_002A3830[st->first + j], D_L16_001DF54C, func_0038DBD8(D_002A3830[st->first + j].c20, D_002A3830[st->first + j].c28, func_003824E0(0.0f, 1.0f)) | 0x60000000, 1, D_L16_001DF550 * func_003824E0(0.75f, 1.25f), D_L16_001DF554, func_003824E0(-3.1415927f, 3.1415927f));
        }
        f = func_003824E0(D_L16_001DF544, D_L16_001DF548);
        func_003D9508(self + 0x10, D_L16_001DF53C, D_L16_001DF540, 1, st->size * st->f0 + f, 0.0f, 0.0f);
    }
}
/* localdecomp:end func_L16_003E7C00 */
