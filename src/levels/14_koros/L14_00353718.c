#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_00353718 */
__asm__(".extern D_L14_001DD570, 4");
extern s32 D_L14_001DD570;
__asm__(".extern D_L14_001DD578, 4");
extern s32 D_L14_001DD578;
__asm__(".extern D_L14_001DD550, 4");
extern s32 D_L14_001DD550;
__asm__(".extern D_L14_001DD588, 4");
extern s32 D_L14_001DD588;
__asm__(".extern D_L14_001DD580, 4");
extern s32 D_L14_001DD580;
__asm__(".extern D_L14_001DD584, 4");
extern s32 D_L14_001DD584;
extern void func_L14_003AD768(void *);
void func_L14_00353718(u8 *a0) {
    s32 *s = *(s32 **)(a0 + 0x68);
    s32 x, y;
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
        x = D_L14_001DD580;
        y = D_L14_001DD584;
        s[5] = (s32)&D_L14_001DD570;
        s[4] = (s32)&D_L14_001DD578;
        s[3] = 2;
        s[1] = (s32)&D_L14_001DD550;
        s[7] = y;
        s[2] = (s32)&D_L14_001DD588;
        s[6] = x;
        s[0] = 0;
        s[8] = x;
    }
    func_L14_003AD768(a0);
}
/* localdecomp:end func_L14_00353718 */

/* localdecomp:start func_L14_00353790 */
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
extern void func_0038CF68(void *, void *, f32);
void func_L14_00353790(u8 *a0) {
    vu0_v4 buf10;
    vu0_v4 v20;
    vu0_v4 *v10;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 7, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        v10 = &buf10;
        *v10 = *(vu0_v4 *)(a0 + 0x10);
        buf10.z += 1.5f;
        func_0038CF68(&v20, a0 + 0xD0, 1.0f);
        vec_add_ab(v10, v10, &v20);
        func_L01_00429840(a0, v10, 5, 0, &D_L14_001D66B0, 0x463C5028, 0, 0xA7, 1.0f, 30.0f, 1.5f, 2.5f);
        func_L01_00451E78(a0, 1, 0.0f);
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00353790 */

/* localdecomp:start func_L14_00353910 */
extern u8 D_L14_001D66B0;
extern void func_L02_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
void func_L14_00353910(void *a0, void *pos, void *dir, s32 n) {
    vu0_v4 p;
    vu0_v4 d;
    p = *(vu0_v4 *)pos;
    d = *(vu0_v4 *)dir;
    func_L02_00429840(a0, &p, 5, 0, &D_L14_001D66B0, 0xC850C828, 0, 0x7D, 0.0f, 10.0f, 0.8f, 1.2f);
    func_L02_003E2E38(a0, &p, 0.0f, &D_L14_001D66B0, 10, 0, 0.050000004f, 1.5f, 3.0f, 1.0f, 1);
}
/* localdecomp:end func_L14_00353910 */

/* localdecomp:start func_L14_003539E0 */
extern u8 D_L14_001D66B0;
extern vu0_v4 D_L14_001D66B0_v __attribute__((section(".sdata")));
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L14_00353910(void *, void *, void *, s32);
void func_L14_003539E0(u8 *a0) {
    vu0_v4 a;
    vu0_v4 c;
    vu0_v4 b;
    f32 t;
    f32 u;
    s32 n;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        t = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        n = (s32)(t * 15.0f);
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 7, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        b = *(vu0_v4 *)(a0 + 0xD0);
        vec_sub_ab(&b, &D_L14_001D66B0_v, &b);
        func_0038CDF8((f32 *)&c, (f32 *)(a0 + 0xC0), (f32 *)&b, 0.5f);
        func_0038CF68(&c, &c, 1.0f);
        vec_add_ba(&a, a0 + 0x10, &c);
        func_L14_00353910(a0, &a, &c, n);
        a.z += t * 1.1f;
        func_L14_00353910(a0, &a, &c, n);
        u = (t + t) * 1.1f;
        a.z -= u;
        func_L14_00353910(a0, &a, &c, n);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_003539E0 */

/* localdecomp:start func_L14_00353BC8 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_00353BC8(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 7, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x963C6428, 0, 0x7D, 2.0f, 10.0f, 1.5f, 2.0f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00353BC8 */

/* localdecomp:start func_L14_00353CD0 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_00353CD0(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 7, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x963C6428, 0, 0x7D, 2.0f, 10.0f, 1.5f, 2.0f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00353CD0 */

/* localdecomp:start func_L14_00353DD8 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_00353DD8(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 1, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x963C6428, 0, 0x7D, 2.0f, 10.0f, 1.5f, 2.0f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00353DD8 */
