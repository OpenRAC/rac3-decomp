#include "common.h"

/* localdecomp:start func_L24_00355C18 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x1A0];
    u32 held;
    u32 pressed;
    u8 pad1A8[0x5C0 - 0x1A8];
} Pad_00355C18;
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0045AA30(void *, void *);
extern u8 *func_L24_003B87F0(void *, f32);
extern Pad_00355C18 D_001CD0C0[];
extern s32 D_L24_001E0FD0[] __attribute__((section(".sdata")));
__asm__(".extern D_L24_001DD578, 4");
__asm__(".extern D_L24_001DD57C, 4");
__asm__(".extern D_L24_001DD588, 4");
__asm__(".extern D_L24_001DD58C, 4");
extern f32 D_L24_001DD578;
extern f32 D_L24_001DD57C;
extern f32 D_L24_001DD588;
extern f32 D_L24_001DD58C;

void func_L24_00355C18(u8 *obj, s32 anim, s32 idle, u8 **slots, s32 n, f32 size) {
    f32 v[4];
    s32 i;
    s32 p;
    s32 j;
    u32 btn;
    u8 *m;
    f32 fx;
    f32 fy;
    f32 rx;
    f32 ry;
    s32 ix;
    s32 iy;

    i = 0;
    if (obj == 0) {
        return;
    }
    qzero(v);
    switch (*(s16 *)(obj + 0xAA)) {
    case 0x1B95:
        i = 0;
        break;
    case 0x1B96:
        i = 1;
        break;
    case 0x1B97:
        i = 2;
        break;
    case 0x1B9A:
        i = 3;
        break;
    }
    p = D_L24_001E0FD0[i];
    if (p == -1) {
        return;
    }
    i = p;
    btn = (D_001CD0C0 + i)->held;
    if (btn & 0x1000) {
        v[1] = v[1] - D_L24_001DD57C;
        *(f32 *)(obj + 0xF8) = -1.5707964f;
    } else if (btn & 0x4000) {
        v[1] = v[1] + D_L24_001DD57C;
        *(f32 *)(obj + 0xF8) = 1.5707964f;
    } else if (btn & 0x8000) {
        v[0] = v[0] + D_L24_001DD57C;
        *(f32 *)(obj + 0xF8) = 0.0f;
    } else if (btn & 0x2000) {
        v[0] = v[0] - D_L24_001DD57C;
        *(f32 *)(obj + 0xF8) = 3.1415927f;
    }
    if ((D_001CD0C0 + i)->held & 0xF000) {
        if (obj[0x43] != anim) {
            func_003C3A10(obj, anim, 0, 3);
        }
        func_L01_0045AA30(obj, v);
    } else if (obj[0x43] != idle) {
        func_003C3A10(obj, idle, 0, 3);
    }
    if ((D_001CD0C0 + i)->pressed & 0x40) {
        for (j = 0; j < n; j++) {
            if (slots[j] == 0) {
                slots[j] = func_L24_003B87F0(obj, size);
                if (slots[j] != 0) {
                    fx = (*(f32 *)(slots[j] + 0x10) - D_L24_001DD588) / D_L24_001DD578;
                    fy = (*(f32 *)(slots[j] + 0x14) - D_L24_001DD58C) / D_L24_001DD578;
                    rx = fx - cvtsw_asm(cvtws_asm(fx));
                    ry = fy - cvtsw_asm(cvtws_asm(fy));
                    ix = (s32)((fx - rx) + 0.0001f);
                    iy = (s32)((fy - ry) + 0.0001f);
                    if (0.5f < rx) {
                        *(f32 *)(slots[j] + 0x10) = D_L24_001DD588 + D_L24_001DD578 * (f32)(ix + 1);
                    } else {
                        *(f32 *)(slots[j] + 0x10) = D_L24_001DD588 + D_L24_001DD578 * (f32)ix;
                    }
                    m = slots[j];
                    if (0.5f < ry) {
                        *(f32 *)(m + 0x14) = D_L24_001DD58C + D_L24_001DD578 * (f32)(iy + 1);
                    } else {
                        *(f32 *)(m + 0x14) = D_L24_001DD58C + D_L24_001DD578 * (f32)iy;
                    }
                    *(s32 *)(slots[j] + 0x98) = 0;
                    j = n;
                }
            }
        }
    }
}
/* localdecomp:end func_L24_00355C18 */
