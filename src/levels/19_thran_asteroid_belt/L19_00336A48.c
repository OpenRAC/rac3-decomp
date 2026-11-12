#include "common.h"

typedef struct { f32 x, y, z, w; } V_336A48 __attribute__((aligned(16)));

/* localdecomp:start func_L19_00336A48 */
__asm__(".extern D_001DCDA0, 4");
__asm__(".extern D_001DCD80, 8");
__asm__(".extern D_001DCD78, 8");
__asm__(".extern D_001DCD70, 8");
extern s32 D_001DCDA0;
extern u8 D_001DCD80[8];
extern u8 D_001DCD78[8];
extern u8 D_001DCD70[8];
extern f32 D_L19_001E1010;
extern f32 D_L19_001D7EC4;
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L19_0044BFC8(u8 *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L19_00336C58(u8 *);
extern void func_L01_00459C50(s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

void func_L19_00336A48(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *h;
    V_336A48 a;
    V_336A48 *pa;
    V_336A48 b;
    s32 r;
    s32 res;

    switch (obj[0x20]) {
    case 0:
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (*(s32 *)p == 0) {
            h = func_L01_00447490(obj, 0x8010000, 0);
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
                    func_L01_004450F0(obj, 2, -1);
            }
        }
        obj[0xA8] = 0xFF;
        break;
    case 2:
        func_003A52A0(0, 0, obj);
        func_L19_0044BFC8(obj, D_001DCD80, D_001DCD78, D_001DCD70, 0xFFF, -1, D_001DCDA0, 0x10, 0xFFFF, 0xFF, 0);
        func_L19_00336C58(obj);
        *(s32 *)(p + 4) = 0x190;
        func_L01_00459C50(0x16);
        if (D_001DCDA0 >= 0)
            *(u16 *)(obj + 0x7C) = (1 << D_001DCDA0) | 0x8000;
        else
            *(u16 *)(obj + 0x34) |= 0x41;
        func_L01_004450F0(obj, 3, -1);
        break;
    case 3:
        if (func_0038CAD0(p + 4) != 0) {
            D_L19_001D7EC4 = D_L19_001E1010;
            func_003C2880(obj);
        }
        break;
    }
}
/* localdecomp:end func_L19_00336A48 */

/* localdecomp:start func_L19_00336C58 */
extern f32 D_L19_001D7EC4;
extern f32 D_L19_001E1010;
extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L02_00428520(void *, f32 *, f32, f32, f32);
extern void func_L19_00465AD0(f32 *, f32 *, s32);

void func_L19_00336C58(u8 *a0)
{
    f32 v[4];
    f32 buf[4];
    s32 i;
    f32 f14;
    f32 f20;
    f32 f21;

    D_L19_001E1010 = D_L19_001D7EC4;
    D_L19_001D7EC4 = 0.99f;
    for (i = 0xC7; i >= 0; i--) {
        func_L01_00443B88(buf, 0.020000001f, 0.28000003f);
        __asm__("abs.s %0, %1" : "=f"(f14) : "f"(buf[2]));
        buf[2] = f14 + 0.10000001f;
        f21 = func_003824E0(-5.0f, 5.0f);
        f20 = func_003824E0(-5.0f, 5.0f);
        f14 = func_003824E0(10.0f, 25.0f);
        func_L02_00428520(a0, v, f21, f20, f14);
        func_L19_00465AD0(v, buf, 0x190);
    }
}
/* localdecomp:end func_L19_00336C58 */
