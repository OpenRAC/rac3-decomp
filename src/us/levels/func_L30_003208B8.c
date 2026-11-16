#include "common.h"

/* NTSC-U counterpart of func_L30_00320EE8 (src/levels/30_vidcomic_unnamed/L30_00320EE8.c) */
/* localdecomp:start func_L30_003208B8 */
#include "vu0.h"

typedef struct V_00320EE8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00320EE8;

__asm__(".extern D_L30_001DF71C_003208B8, 16");
extern u8 *D_L30_001DF71C_003208B8;
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_004493C0(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388730(void *, void *);
extern void func_003BF838(void *, void *, void *, void *);

void func_L30_003208B8(u8 *arg0) {
    u8 *o = *(u8 **)(arg0 + 0x68);
    V_00320EE8 v;
    V_00320EE8 w;
    V_00320EE8 dir;
    V_00320EE8 d;
    f32 dist;

    switch (arg0[0x20]) {
    case 0:
        *(s32 *)(o + 0x6C) |= 4;
        *(s16 *)(arg0 + 0x7C) = 3;
        func_L01_00441FB8(arg0, 1, -1);
        break;
    case 1:
        func_L01_004493C0(arg0, D_L30_001DF71C_003208B8 + (*(s32 *)(o + 0xF0) << 8), arg0 + 0x10, arg0 + 0xF0,
                          (u8 *)&v, (u8 *)&w);
        v.z = 0.0f;
        vec_sub_ba(&d, &v, arg0 + 0x10);
        v = d;
        dir = d;
        v.z = 0.0f;
        w.x = func_00388960(*(f32 *)(arg0 + 0xF8) + 4.712389f);
        w.y = func_00388978(*(f32 *)(arg0 + 0xF8) + 4.712389f);
        w.z = 0.0f;
        dist = func_00388730(&v, &w);
        dir.x = func_00388960(*(f32 *)(arg0 + 0xF8)) * (dist / 10.0f);
        dir.y = func_00388978(*(f32 *)(arg0 + 0xF8)) * (dist / 10.0f);
        dir.z = 0.0f;
        func_003BF838(o + 0x30, &dir, arg0 + 0xF0, arg0 + 0xF0);
        *(f32 *)(arg0 + 0x48) = dist / 0.016666668f;
        break;
    }
}
/* localdecomp:end func_L30_003208B8 */
