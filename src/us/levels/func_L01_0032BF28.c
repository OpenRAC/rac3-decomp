#include "common.h"

/* NTSC-U counterpart of func_L01_0032C390 (src/levels/shared/L01_0032B408.c) */
#include "vu0.h"
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void *func_0037E0B8(void *);
extern void func_L01_004C41E8(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L01_0032BF28 */
typedef struct { u8 pad[0x15]; u8 index; } State_0032C390;
typedef struct { u8 pad[0x4C]; f32 speed, delay; u8 tail[0x9C]; } Row_0032C390;
extern State_0032C390 D_001425C0;
extern Row_0032C390 D_L01_002C5640[];
extern s32 D_L01_001DCE88;
__asm__(".extern D_L01_001DCE88, 4");
extern void func_L01_004C6F70(void *, void *, void *);
extern void func_L01_0032C608(void *, void *);
extern s32 func_003BF5E0(void *);


void func_L01_0032BF28(u8 *m) {
    vu0_v4 direction, target, delta, reference, forward;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *desc;
    f32 scale;
    func_003BDA38(m, 1, &reference);
    func_L01_004C41E8(m + 0x10, &direction);
    if (*(f32 *)(p + 0x5C) == 0.0f && *(s32 *)(p + 0x50) && *(u8 **)(p + 0x68)) {
        desc = func_0037E0B8(*(u8 **)(p + 0x68));
        target = *(vu0_v4 *)(*(u8 **)(p + 0x68) + 0x10);
        if (desc) {
            func_003886E8(&forward, *(u8 **)(p + 0x68) + 0xE0, *(f32 *)(desc + 0x10));
            vec_add_ab(&target, &target, &forward);
        } else {
            target = *(vu0_v4 *)(*(u8 **)(*(u8 **)(p + 0x68) + 0x24) + 0x30);
            scale = *(f32 *)(*(u8 **)(p + 0x68) + 0x2C) * 0.0009765625f;
            func_003886E8(&target, &target, scale);
            target.w *= scale;
            vec_add_ab(&target, *(u8 **)(p + 0x68) + 0x10, &target);
        }
        vec_sub_ab(&delta, &target, &reference);
        func_00388830(&delta, &delta, D_001425C0.index[D_L01_002C5640].speed * 0.016666668f);
        func_L01_004C6F70(&delta, &delta, &reference);
        func_L01_0032C608(m, &delta);
        func_0039FE80(0, 0, m);
        *(s32 *)(p + 0x40) = D_L01_001DCE88;
        *(s32 *)(p + 0x44) = 6;
        if (!func_003BF5E0(*(u8 **)(p + 0x68))) (*(u16 *)(p + 0x64))--;
        if (*(s16 *)(p + 0x64) <= 0) m[0x20] = 8;
        *(f32 *)(p + 0x5C) = 1.0f / D_L01_002C5640[D_001425C0.index].delay;
    }
}
/* localdecomp:end func_L01_0032BF28 */
