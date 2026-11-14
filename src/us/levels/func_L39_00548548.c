#include "common.h"

/* NTSC-U counterpart of func_L39_00548E60 (src/levels/shared/L39_00548E60.c): 7 -> 8; 0.12 -> 0.1 */
/* localdecomp:start func_L39_00548548 */
#include "vu0.h"
extern void func_L01_0040BAF0(void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005B2498(s32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, s32, void *, f32, u32, s32);

void func_L39_00548548(u8 *self) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 vel;
    s32 i;
    s32 j;
    s32 k;
    s32 life;
    f32 size;

    if (self[0xBC] == 0) {
        return;
    }
    func_L01_0040BAF0(self + 0xBC);
    func_003886E8(&pos, self + 0xD0, 0.1f);
    vec_add_ba(&pos, &pos, self + 0x10);
    func_003886E8(&off, self + 0xC0, 0.275f);
    vec_add_ab(&pos, &pos, &off);
    func_003886E8(&vel, self + 0xD0, 0.100000009f);
    for (i = 0; i < 4; i++) {
        u8 *p;
        k = func_L39_005B2498(0x10);
        if (func_L39_005B2498(2) != 0) {
            k = -k;
        }
        p = func_L01_004633E8(&pos, 0.04f, 1.0f, 0.9f, k, &vel, 52500.0f, 0x7F204080, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            *(s16 *)(p + 0xA) = 8;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
    }
    k = 0x10;
    size = 15750.001f;
    life = 2;
    for (j = 0; j < 3; j++) {
        u8 *p;
        p = func_L01_004633E8(&pos, 0.02f, 1.0f, 1.0f, k, &vel, size, 0x7FFFFFFF, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s16 *)(p + 0xA) = life;
            p[8] = func_L39_005B2498(0xFF);
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
        k = -k;
        life <<= 1;
        size -= 3150.0f;
    }
}
/* localdecomp:end func_L39_00548548 */
