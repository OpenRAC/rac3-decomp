/* func_L07_00351148: NEAR 49 diff with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division). Frame, calls, stores and the lq/sq copies match; the diff is register choice: gcc copies the first call's returned pointer into $v1 (retail uses $v0 for the lh and the store) and the field stores are scheduled differently. Tried: a local for the lh, reordering the stores, returning-pointer reuse (which fixed the frame). */
#include "common.h"

typedef struct { u32 w[4]; } __attribute__((aligned(16))) V4;

extern u8 *func_00382348(u8 *);
extern u8 *func_L01_00448FF0(u8 *);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_00351148(u8 *a0) {
    u8 *p;
    u8 *r;

    a0[0x7F] = 0;
    p = *(u8 **)(a0 + 0x68);
    r = func_00382348(a0);
    *(f32 *)r = (f32)*(s16 *)(r + 4);
    r = func_L01_00448FF0(a0);
    r[8] = 0;
    *(u16 *)(r + 0x38) = 0;
    r[7] = 0;
    r[9] = 0;
    func_L01_00456C98(a0, -1, 0, 0, 0, 0, 3, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    *(s32 *)(a0 + 0x98) = 0;
    a0[0xA8] = 0xFF;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x43) & 0xEFFF;
    func_L01_004AA7E8(a0, 1);
    *(V4 *)(a0 + 0x10) = *(V4 *)(p + 0x260);
    *(V4 *)(a0 + 0xF0) = *(V4 *)(p + 0x270);
    func_L01_004450F0(a0, 7, 4);
}
