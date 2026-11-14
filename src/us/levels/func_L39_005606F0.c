#include "common.h"

/* NTSC-U counterpart of func_L39_005611A0 (src/levels/shared/L39_005611A0.c): 0.0942478 -> 0.0785398; 76 -> 91 */
/* localdecomp:start func_L39_005606F0 */
#include "vu0.h"
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern f32 D_L39_0024B51C;
__asm__(".extern D_L39_0024B51C, 4");
extern void func_00388830(void *, void *, f32);
extern s32 func_L39_00669F20(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern f32 func_00389380(f32, f32);
extern void func_003BF2F8(f32 *q, void *axis, f32 angle);
extern void func_00389118(void *out, void *a, void *b);
extern void func_003BF360(void *, void *);
extern void func_L39_00560A00(u8 *);
extern u8 *func_L39_006197C0(s32);
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L39_0055FB68(u8 *, u8 *, s32);
extern s32 func_L39_0055F880(u8 *, u8 *);

void func_L39_005606F0(u8 *m) {
    vu0_v4 t;
    s32 i;
    u8 *o;

    switch (m[0x20]) {
    case 0:
        func_00388830(&t, m + 0xE0, 0.75f);
        vec_add_ab(m + 0x10, m + 0x10, &t);
        func_L39_00669F20(m, -1, 1);
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1:
        if (func_L01_00452EC8(m) != 0) {
            *(u16 *)(m + 0x34) &= ~0x41;
        }
        if (*(f32 *)(m + 0xF0) == 0.0f && *(f32 *)(m + 0xF4) == 0.0f) {
            *(f32 *)(m + 0xF8) = func_00389380(*(f32 *)(m + 0xF8), 0.0785398185f);
        } else {
            func_003BF2F8((f32 *)&t, m + 0xE0, 0.0785398185f);
            func_00389118(m + 0xC0, m + 0xC0, &t);
            func_00389118(m + 0xD0, m + 0xD0, &t);
            func_003BF360(m + 0xC0, m + 0xF0);
        }
        if (m[0x31] != 0) {
            func_L39_00560A00(m);
        }
        for (i = 0; i < *D_L39_002412A0; i++) {
            o = func_L39_006197C0(i);
            if (o == 0) continue;
            if (func_L01_0040C018(o + 0xA0, m + 0x10) < D_L39_0024B51C) {
                if (func_L39_0055FB68(o, m, 1) != 0) {
                    *(u16 *)(m + 0x34) |= 0x41;
                    func_L01_00441FB8(m, 2, -1);
                    break;
                }
                if (func_L39_0055F880(o, m) != 0) {
                    func_L01_00441FB8(m, 2, -1);
                    break;
                }
            }
        }
        break;
    case 2:
        *(u16 *)(m + 0x96) += 1;
        if (m[0x31] != 0) {
            func_L39_00560A00(m);
            if (*(f32 *)(m + 0xF0) == 0.0f && *(f32 *)(m + 0xF4) == 0.0f) {
                *(f32 *)(m + 0xF8) = func_00389380(*(f32 *)(m + 0xF8), 0.0785398185f);
            } else {
                func_003BF2F8((f32 *)&t, m + 0xE0, 0.0785398185f);
                func_00389118(m + 0xC0, m + 0xC0, &t);
                func_00389118(m + 0xD0, m + 0xD0, &t);
                func_003BF360(m + 0xC0, m + 0xF0);
            }
        }
        if (*(u16 *)(m + 0x96) >= 0x5B) {
            *(u16 *)(m + 0x34) &= ~0x41;
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 3:
        if (m[0x31] != 0) {
            func_L39_00560A00(m);
        }
        break;
    }
}
/* localdecomp:end func_L39_005606F0 */
