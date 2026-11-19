#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;

/* localdecomp:start func_L01_0045D0B0 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
extern s32 D_L01_0021F6C0[];
extern s32 func_L01_004463F8(u8 *, u8 *, s32);
extern s32 func_L01_00476F10(s32, f32, u8 *, f32 *);

s32 func_L01_0045D0B0(u8 *a) {
    u8 *o;
    u8 *e;
    u8 *p;
    f32 buf[4];

    o = ((u8 * (*)(u8 *))func_L01_0045B958)(a);
    if (o == 0 || *(s32 *)(o + 60) == -1) {
        return 0;
    }
    e = ((u8 * *)&D_L01_0021F6C0)[*(s32 *)(o + 60)];
    p = a + 16;
    if (func_L01_004463F8(p, e + 16, *(s32 *)e) != 0) {
        if (func_L01_00476F10(*(s32 *)(o + 60), *(f32 *)o, p, buf) == 0) {
            return 1;
        }
    }
    *(s32 *)(o + 156) |= 1;
    return 0;
}
/* localdecomp:end func_L01_0045D0B0 */
