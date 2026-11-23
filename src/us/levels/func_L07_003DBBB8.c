#include "common.h"

/* NTSC-U effect update with unscaled frame steps. */
/* localdecomp:start func_L07_003DBBB8 */
extern f32 D_L07_001DE9A0;
extern f32 D_L07_001DE9B0;
extern void *D_L07_001DE9A8;
extern s32 D_L07_001DE9AC;
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DE9A0, 4");
__asm__(".extern D_L07_001DE9B0, 4");
__asm__(".extern D_L07_001DE9A8, 4");
__asm__(".extern D_L07_001DE9AC, 4");
__asm__(".extern D_L07_001DF41C, 16");
void func_L07_003DBBB8(u8 *obj) {
    extern void func_L01_00441FB8(void *, s32, s32);
    extern s32 func_L01_00452EC8(void *);
    extern void func_L01_004A72A8(s32, s32, void *, s32);
    extern void func_L01_004A6D70(s32, void *);
    extern f32 func_003BE6A8(f32, f32, f32);
    extern f32 func_00389410(f32);
    extern void *func_003894A0(void *, s32, f32);
    u8 *v = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        *(void **)(obj + 0x78) = D_L07_001DE9A8;
        *(u16 *)(obj + 0x34) |= 0x10;
        func_L01_00441FB8(obj, 1, -1);
    }
    switch (obj[0x20]) {
    case 2:
        if (obj[0xBE] & 4) func_L01_00441FB8(obj, 3, -1);
        break;
    case 3:
        if (func_L01_00452EC8(obj)) func_L01_004A72A8(0, 0x114, obj, 0x1D6B);
        *(f32 *)(v + 0x10) += D_L07_001DE9A0;
        if (*(f32 *)(v + 0x10) >= 1.0f) {
            *(f32 *)(v + 0x10) = 1.0f;
            func_L01_004A6D70(0, obj);
            func_L01_00441FB8(obj, 4, -1);
        }
        *(f32 *)(obj + 0xF0) = func_00389410(func_003BE6A8(0.0f, *(f32 *)(v + 0x18), *(f32 *)(v + 0x10)));
        break;
    case 4: {
        s32 index;
        u8 *m;
        m = D_L07_001DF41C + ((*(u8 *)((s32)v + v[0x1C] + 8) == 1 ? *(s32 *)v : *(s32 *)(v + 4)) << 8);
        m[0xBE] |= 4;
        *(f32 *)(v + 0x14) = 0.0f;
        func_L01_00441FB8(obj, 5, -1);
        break;
    }
    case 1:
        break;
    case 5: {
        f32 phase;
        *(f32 *)(v + 0x14) += D_L07_001DE9B0;
        if (*(f32 *)(v + 0x14) >= 2.0f) *(f32 *)(v + 0x14) -= 2.0f;
        if (*(f32 *)(v + 0x14) > 1.0f) phase = 2.0f - *(f32 *)(v + 0x14);
        else phase = *(f32 *)(v + 0x14);
        *(void **)(obj + 0x78) = func_003894A0(D_L07_001DE9A8, D_L07_001DE9AC, phase);
        break;
    }
    }
}
/* localdecomp:end func_L07_003DBBB8 */
