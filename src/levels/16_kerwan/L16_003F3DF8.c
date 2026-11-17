#include "common.h"

/* localdecomp:start func_L16_003F3DF8 */
#include "vu0.h"
extern u8 *D_001E015C;
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C5060(void *, void *, void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038D000(void *, void *, void *);

void func_L16_003F3DF8(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *o = D_001E015C + *(s32 *)st * 256;
    vu0_v4 v;

    if (o == 0) {
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x43) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
    }
    if (obj[0x20] == 0) {
        *(f32 *)(st + 0x10) = func_0038DAB8(*(f32 *)(obj + 0xF0), -*(f32 *)(o + 0xF0));
        *(f32 *)(st + 0x14) = func_0038DAB8(*(f32 *)(obj + 0xF4), -*(f32 *)(o + 0xF4));
        *(f32 *)(st + 0x18) = func_0038DAB8(*(f32 *)(obj + 0xF8), -*(f32 *)(o + 0xF8));
        vec_sub_ba(&v, obj + 0x10, o + 0x10);
        func_003C5060(o, st + 0x20, &v, 0);
        func_L01_004450F0(obj, 1, -1);
    } else {
        func_0038D000(&v, st + 0x20, o + 0xC0);
        vec_add_ab(obj + 0x10, &v, o + 0x10);
        *(f32 *)(obj + 0xF0) = func_0038DAB8(*(f32 *)(st + 0x10), *(f32 *)(o + 0xF0));
        *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(st + 0x14), *(f32 *)(o + 0xF4));
        *(f32 *)(obj + 0xF8) = func_0038DAB8(*(f32 *)(st + 0x18), *(f32 *)(o + 0xF8));
    }
}
/* localdecomp:end func_L16_003F3DF8 */
