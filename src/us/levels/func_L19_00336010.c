#include "common.h"

/* NTSC-U counterpart of func_L19_00336A48 (src/levels/19_thran_asteroid_belt/L19_00336A48.c): 400 -> 480 */
typedef struct { f32 x, y, z, w; } V_336A48 __attribute__((aligned(16)));

/* localdecomp:start func_L19_00336010 */
__asm__(".extern D_L19_001DCDE0, 4");
__asm__(".extern D_L19_001DCDC0, 8");
__asm__(".extern D_L19_001DCDB8, 8");
__asm__(".extern D_L19_001DCDB0, 8");
extern s32 D_L19_001DCDE0;
extern u8 D_L19_001DCDC0[8];
extern u8 D_L19_001DCDB8[8];
extern u8 D_L19_001DCDB0[8];
extern f32 D_L19_001E1010_00336010;
extern f32 D_L19_001D7EC4_00336010;
extern u8 *func_L01_00444358(u8 *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L19_004485D0(u8 *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L19_00336220(u8 *);
extern void func_L01_00456960(s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

void func_L19_00336010(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *h;
    V_336A48 a;
    V_336A48 *pa;
    V_336A48 b;
    s32 r;
    s32 res;

    switch (obj[0x20]) {
    case 0:
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (*(s32 *)p == 0) {
            h = func_L01_00444358(obj, 0x8010000, 0);
            if (h != 0) {
                pa = &a;
                a = *(V_336A48 *)(obj + 0x10);
                a.z = a.z + 0.5f;
                r = 1;
                if (*(u8 **)(h + 0x20) != 0) {
                    b = *(V_336A48 *)(*(u8 **)(h + 0x20) + 0x10);
                    b.z = b.z + 0.5f;
                    if (func_0038CF00(&b, pa) < 64.0f) {
                        res = func_003D3CB0(&b, pa, 2, obj, 0);
                        r = 0;
                        if (res == 0)
                            r = 1;
                    }
                }
                if (r != 0)
                    func_L01_00441FB8(obj, 2, -1);
            }
        }
        obj[0xA8] = 0xFF;
        break;
    case 2:
        func_003A52A0(0, 0, obj);
        func_L19_004485D0(obj, D_L19_001DCDC0, D_L19_001DCDB8, D_L19_001DCDB0, 0xFFF, -1, D_L19_001DCDE0, 0x10, 0xFFFF, 0xFF, 0);
        func_L19_00336220(obj);
        *(s32 *)(p + 4) = 0x1E0;
        func_L01_00456960(0x16);
        if (D_L19_001DCDE0 >= 0)
            *(u16 *)(obj + 0x7C) = (1 << D_L19_001DCDE0) | 0x8000;
        else
            *(u16 *)(obj + 0x34) |= 0x41;
        func_L01_00441FB8(obj, 3, -1);
        break;
    case 3:
        if (func_0038CAD0(p + 4) != 0) {
            D_L19_001D7EC4_00336010 = D_L19_001E1010_00336010;
            func_003C2880(obj);
        }
        break;
    }
}
/* localdecomp:end func_L19_00336010 */
