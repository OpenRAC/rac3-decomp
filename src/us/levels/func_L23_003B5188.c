#include "common.h"

/* NTSC-U counterpart of func_L23_003B6AD0 (src/levels/23_holostar_studios_clank/L23_003B3BB8.c): 0.02 -> 0.0166667 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
#include "vu0.h"
#include "structs/hero.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L23_003B5188 */
/* 29 diff */
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L03_0043C598(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004412D0(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);

void func_L23_003B5188(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    Vec4 d;
    Vec4 p;

    d.v[0] = func_00388960(*(f32 *)(v + 0x2F8)) * (*(f32 *)(v + 0x2FC) * 0.0166666675f);
    d.v[1] = func_00388978(*(f32 *)(v + 0x2F8)) * (*(f32 *)(v + 0x2FC) * 0.0166666675f);
    d.v[2] = 0.0f;
    func_L03_0043C598((s32)m, 0x3FF, (u8 *)&d, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0.05f);
    func_L01_004412D0(m, 0, 3);
    func_0039FE80(3, 0, m);
    p = *(Vec4 *)(m + 0x10);
    p.v[2] += 0.2f;
    func_L01_0032FE90((u8 *)&p, 1, 10, 20, 0, 4, 20, 2, 0.2f, 0.0f, 0.0f, 0.0f,
        1, 1, 1, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003BD360(m);
}
/* localdecomp:end func_L23_003B5188 */
