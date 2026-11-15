#include "common.h"

/* localdecomp:start func_L39_00533250 */
typedef int u128_00533250 __attribute__((mode(TI)));

typedef struct Priv_00533250 {
    u8 *p0;
    u8 pad4[0x2C];
    f32 f30;
    s16 h34;
    u8 pad36[8];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x160 - 0x44];
    u8 *p160;
    u8 pad164[8];
    s32 w16C;
} Priv_00533250;

extern u8 D_001A5E38[];
extern f32 D_L39_0024AC88;
__asm__(".extern D_L39_0024AC88, 4");

extern void func_L39_005324E8(void);
extern void func_L39_00533210(u8 *);
extern void func_L39_00532BE0(u8 *);
extern void func_L39_00532FE0(u8 *);
extern void func_003C2880(u8 *);
extern void func_L39_0061C1E0(u32, s32);
extern f32 func_L01_004513A8(u8 *, u8 *, u8 *);
extern s32 func_00197498(s32);
extern void func_L39_00668C90(s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L39_00666FB8(f32, s32, u8 *, u32, s32, s32);
extern void func_L01_0043A430(u8 *, s32, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L39_0061BF68(void *);
extern void func_L06_0042B660(f32, u8 *, u8 *);
extern f32 func_L01_00448728(u8 *, f32, u8 *, f32, f32, f32, s32);
extern void func_L39_0066A8C8(u8 *, u8 *);
extern void func_L01_00404A10(void *, void *);

void func_L39_00533250(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *obj = *(u8 **)(p + 0x160);
    Priv_00533250 *q;
    u8 *t;
    u32 v;
    s32 i;

    if (p[0x62] == 1) {
        func_003C2880(a0);
        return;
    }
    switch (a0[0x20]) {
    case 0:
        q = *(Priv_00533250 **)(a0 + 0x68);
        v = 0xFFFFFFFF;
        q->p0 = (u8 *)&q->f30;
        *(u16 *)(a0 + 0x34) |= 0x5020;
        q->b3E = 1;
        q->f30 = 40.0f;
        q->h34 = 40;
        q->f40 = D_L39_0024AC88;
        (*(u8 **)(a0 + 0x24))[0x46] = 5;
        a0[0xBE] &= 0xE7;
        func_L39_0061C1E0((u32)a0, -1);
        func_L01_004513A8(a0 + 0x10, a0, a0 + 0x10);
        if (D_001A5E38[0] != 0) {
            v = func_00197498(3);
        }
        func_L39_00668C90(3, (s32)func_L39_005324E8, 0, 0, 0, 0, 0, 0);
        obj = func_L39_00666FB8(2.0f, 3, a0, v, 3000, 0);
        q->p160 = obj;
        *(u8 **)(a0 + 0x90) = obj;
        for (i = 0; i < 2; i++) {
            if (((u8 *)q)[0x71 + i * 0x40] == 0) {
                func_L01_0043A430(a0, i, (u8 *)q + 0x70 + i * 0x40);
            }
        }
        func_L01_004450F0(a0, 1, -1);
        if (q->w16C == 0) {
            a0[0xBC] = 8;
        }
        break;
    case 1:
        if (D_001A5E38[0] != 0) {
            if (*(u32 *)obj == 0xFFFFFFFF) {
                *(s32 *)obj = func_00197498(3);
            }
        }
        if (*(u32 *)obj != 0xFFFFFFFF) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
    case 5:
        if (a0[0x20] == 2) {
            if (func_L39_0061BF68(*(void **)(obj + 0x2D8)) >= 0) {
                func_L01_004450F0(a0, 4, -1);
            } else {
                t = *(u8 **)(obj + 0x2D8);
                if (t != 0) {
                    *(u128_00533250 *)(obj + 0x250) = *(u128_00533250 *)(a0 + 0x10);
                    *(u128_00533250 *)(obj + 0x260) = *(u128_00533250 *)(a0 + 0xF0);
                    (*(void (**)(u8 *, s32, s32, s32, s32))(*(u8 **)(t + 0x14) + 0x34))(t, 0, 1, 0, 1);
                    func_L01_004450F0(a0, 3, -1);
                }
            }
        }
        break;
    case 3:
        func_L06_0042B660(0.040000003f, a0 + 0x10, obj + 0xB0);
        func_L01_00448728(a0 + 0xF8, *(f32 *)(obj + 0x208), obj + 0x288, 0.036000002f, 0.21600002f, 0.06283186f, 0);
        if (*(s32 *)(obj + 0x2D8) == 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        *(u128_00533250 *)(obj + 0x250) = *(u128_00533250 *)(a0 + 0x10);
        *(u128_00533250 *)(obj + 0x260) = *(u128_00533250 *)(a0 + 0xF0);
        break;
    case 4:
        if ((*(u8 **)(obj + 0x2D0))[0xBC] != 10) {
            if (*(s32 *)(obj + 0x2D8) == 0) {
                func_L01_004450F0(a0, 2, -1);
            } else {
                func_L39_00532FE0(a0);
                func_L39_00532BE0(a0);
                *(u128_00533250 *)(obj + 0x230) = *(u128_00533250 *)(a0 + 0x10);
                *(u128_00533250 *)(obj + 0x240) = *(u128_00533250 *)(a0 + 0xF0);
            }
        }
        break;
    case 6:
    case 7:
        break;
    }
    func_L39_0066A8C8(obj, a0);
    func_L01_00404A10(func_L39_00533210, a0);
}
/* localdecomp:end func_L39_00533250 */
