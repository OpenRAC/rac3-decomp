#include "common.h"

/* localdecomp:start func_L39_00557600 */
#include "vu0.h"

extern u8 D_L39_00272590[];
extern s32 *D_L39_00271B40[];
extern s32 D_L39_00271F00[];
extern u8 *func_003C24B0(s32, s32);
extern void func_003C25D8(u8 *, s32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L39_00557D20(s32);
extern u8 *func_00382348(void *);
extern void func_L39_005B49A8(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_003C7C38(u8 *);

u8 *func_L39_00557600(u8 *a0, s32 a1) {
    u8 *m;
    u8 *state;
    u8 *q;
    u8 old;
    m = func_003C24B0(0x10AE, 0x200);
    if (m != 0) {
        state = *(u8 **)(m + 0x68);
        old = m[0x22];
        func_003C25D8(m, 0x10AD);
        m[0x22] = D_L39_00272590[0x10AD];
        *(s32 **)(m + 0x24) = D_L39_00271B40[m[0x22]];
        *(s32 *)(m + 0x64) = D_L39_00271F00[old];
        *(u8 **)(m + 0x68) = state;
        m[0x30] = 0x7F;
        *(s16 *)(m + 0x32) = 0x7F;
        m[0x31] = 1;
        *(f32 *)(m + 0x48) = func_L39_005B4410(0.85f, 1.15f);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.9f;
        *(vu0_q *)(m + 0x10) = *(vu0_q *)(a0 + 0x10);
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = func_L39_005B44C8();
        m[0x20] = 0;
        *(s16 *)(state + 0x166) = 0;
        *(s16 *)(state + 0x164) = func_L39_005B43C8(100, 250);
        *(s32 *)(state + 0x180) = 500;
        *(s32 *)(state + 0x184) = 25;
        *(s32 *)(state + 0x18C) = a1;
        *(s32 *)(state + 0x16C) = 0;
        *(s32 *)(state + 0x188) = 0;
        m[0x20] = 4;
        *(u8 **)(state + 0x1C) = state + 0x30;
        *(f32 *)(state + 0x64) = 0.5f;
        *(f32 *)(state + 0x34) = 0.25f;
        *(f32 *)(state + 0x30) = 0.45f;
        *(f32 *)(state + 0x60) = 2.0943951f;
        *(f32 *)(state + 0x5C) = 0.00392f;
        *(f32 *)(state + 0x38) = 0.75f;
        *(f32 *)(state + 0x3C) = 1.0f;
        *(f32 *)(state + 0x40) = 1.5707964f;
        func_L01_0045BD78(m, 0.00080000004f, 0.0150000006f, 0.0050265486f, 0.25132743f);
        func_L39_00557D20((s32)m);
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        *(f32 *)(state + 0x178) = 4.0f;
        *(s32 *)(state + 0x170) = -1;
        q = func_00382348(a0);
        q[0x17] = 0x8F;
        if (*(u16 *)(m + 0x34) & 0x1000) {
            func_L39_005B49A8(a0, 0, 3);
        }
        if (q != 0 && q[0xE] == 1) {
            q[0xE] = 2;
        } else {
            func_003C2880(a0);
        }
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L39_00557600 */
