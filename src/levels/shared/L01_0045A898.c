#include "common.h"

/* localdecomp:start func_L01_0045A898 */
#include "vu0.h"
extern s32 D_L01_001DFB40;
extern u8 *func_L01_0045B958(u8 *);
extern void func_L01_0045B908(u8 *, u8 *);
extern void func_L01_0045B6C8(u8 *, u8 *, f32);
extern void func_L01_0045B8D8(u8 *, u8 *);
extern void func_L01_0045AAD8(u8 *, u8 *, u8 *, void *, void *, f32);
extern void func_L01_0045AF28(u8 *, u8 *);
extern void func_L01_0045B110(u8 *, u8 *, u8 *);
extern void func_L01_0045BB60(u8 *, u8 *, f32);
extern void func_L01_0045C240(void);

s32 func_L01_0045A898(f32 *a0, f32 *a1, f32 c) {
    u8 *a = (u8 *)a0;
    u8 *b = (u8 *)a1;
    u8 *o;
    f32 v1[4] __attribute__((aligned(16)));
    f32 v2[4] __attribute__((aligned(16)));
    f32 z;

    o = func_L01_0045B958(a);
    if (o == 0) {
        return 8;
    }
    if (D_L01_001DFB40 != *(s32 *)(o + 0xBC)) {
        *(s32 *)(o + 0x98) = *(s32 *)(o + 0x94);
        *(s32 *)(o + 0x94) = 0;
        if (!(*(s32 *)(o + 0x38) & 0x100)) {
            func_L01_0045B908(a, o);
        }
        if (D_L01_001DFB40 - *(s32 *)(o + 0xBC) >= 2 || *(s32 *)(o + 0xBC) == 0) {
            z = 0.0f;
            func_L01_0045B6C8(a, o, z);
            *(s32 *)(o + 0x9C) &= ~2;
            *(u8 *)(o + 0xEA) = 0xFF;
            *(f32 *)(o + 0xB4) = z;
            qzero(o + 0xA0);
            *(s32 *)(o + 0x80) = 0;
        }
        *(s32 *)(o + 0xBC) = D_L01_001DFB40;
        func_L01_0045B8D8(a, o);
        func_L01_0045AAD8(a, o, b, v1, v2, c);
        func_L01_0045AF28(a, o);
        func_L01_0045B110(a, o, b);
        func_L01_0045BB60(a, o, c);
        func_L01_0045C240();
    }
    return *(s32 *)(o + 0x94);
}
/* localdecomp:end func_L01_0045A898 */
