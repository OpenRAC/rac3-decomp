/* func_L24_00355C18: 148 differences, a first draft (level 24, file L24_00355C18.c; needs @ps2as on that file's line
   for its inline float constants, which is safe there as the file has no other C, and a config/levels/divs_nops.txt
   row 'func_L24_00355C18 2 2'; neither is committed with this draft). The pad-driven movement and grid-snapped spawn
   (pad index by class 0x1B96/0x1B97/0x1B9A through D_L24_001E0FD0, D-pad direction from D_001CD0C0's +0x1A0,
   func_L01_0045AA30 move, func_L24_003B87F0 spawn into the first free slot, snapped to the D_L24_001DD578 grid) is
   complete, but retail's case tree tests 0x1B96 first (ours 0x1B97, the middle case, as gcc's balancing picks), and
   retail hoists 0.5f/0.0001f into $f20/$f21 with the size parameter in $f22 (frame 0x60, ours 0x50). An extra case and
   an if chain were worse. */
#include "common.h"
#include "vu0.h"
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0045AA30(void *, void *);
extern u8 *func_L24_003B87F0(void *, f32);
extern u8 D_001CD0C0[];
extern s32 D_L24_001E0FD0[];
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
    btn = *(u32 *)(D_001CD0C0 + p * 0x5C0 + 0x1A0);
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
    if (*(u32 *)(D_001CD0C0 + p * 0x5C0 + 0x1A0) & 0xF000) {
        if (obj[0x43] != anim) {
            func_003C3A10(obj, anim, 0, 3);
        }
        func_L01_0045AA30(obj, v);
    } else if (obj[0x43] != idle) {
        func_003C3A10(obj, idle, 0, 3);
    }
    if (*(u32 *)(D_001CD0C0 + p * 0x5C0 + 0x1A4) & 0x40) {
        for (i = 0; i < n; i++) {
            if (slots[i] == 0) {
                m = func_L24_003B87F0(obj, size);
                slots[i] = m;
                if (m != 0) {
                    fx = (*(f32 *)(m + 0x10) - D_L24_001DD588) / D_L24_001DD578;
                    fy = (*(f32 *)(m + 0x14) - D_L24_001DD58C) / D_L24_001DD578;
                    rx = fx - (f32)(s32)fx;
                    ry = fy - (f32)(s32)fy;
                    ix = (s32)((fx - rx) + 0.0001f);
                    iy = (s32)((fy - ry) + 0.0001f);
                    if (0.5f < rx) {
                        ix++;
                    }
                    *(f32 *)(m + 0x10) = D_L24_001DD588 + D_L24_001DD578 * (f32)ix;
                    if (0.5f < ry) {
                        *(f32 *)(slots[i] + 0x14) = D_L24_001DD58C + D_L24_001DD578 * (f32)(iy + 1);
                    } else {
                        *(f32 *)(slots[i] + 0x14) = D_L24_001DD58C + D_L24_001DD578 * (f32)iy;
                    }
                    *(s32 *)(slots[i] + 0x98) = 0;
                    i = n;
                }
            }
        }
    }
}
