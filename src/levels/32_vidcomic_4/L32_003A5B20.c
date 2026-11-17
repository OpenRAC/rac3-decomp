#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L01_004450F0(s32, s32, s32);
s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_L32_001DFE1C;

/* declared by functions of L32_003A44A8.c, which this file was cut from */
extern u8 D_L32_001DEB30[2];
void func_L32_003A52A8(void *, s32);

/* localdecomp:start func_L32_003A5B20 */
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern s32 func_L01_004561B8(void *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A5B20(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(s + 0x90) = 0;
    }
    *(s32 *)(s + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, s + 0x90, s + 0x140, D_L32_001DE9D4, D_L32_001DE9D4, D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    if (a0[0x60] & 2) {
        func_L32_003A52A8(a0, a1);
    }
}
/* localdecomp:end func_L32_003A5B20 */

/* localdecomp:start func_L32_003A5BC0 */
extern s32 D_L32_001DEA58;
extern s32 D_L32_001DE9BC;
extern u8 D_L32_001DEB30[2];
__asm__(".extern D_L32_001DEB30, 2");
extern f32 D_L32_001DEAB0;
__asm__(".extern D_L32_001DEA58, 4");
__asm__(".extern D_L32_001DE9BC, 4");
__asm__(".extern D_L32_001DEAB0, 4");
extern s32 func_L01_004561B8(void *);
extern u8 *func_L32_003C4F70(vu0_q *);
extern s32 func_0038CAD0(void *);
extern void func_L32_003A5850(void *arg0);

void func_L32_003A5BC0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    vu0_v4 v;
    s32 t;

    if (func_L01_004561B8(arg0) != 0) {
        t = D_L32_001DEA58;
        *(s32 *)(p + 0x128) = D_L32_001DE9BC;
        *(s32 *)(p + 0xA8) = t;
        D_L32_001DEB30[*(s32 *)(p + 0xF8) != 1] = 1;
        v = *(vu0_v4 *)((u8 *)arg0 + 0x10);
        v.x = (*(f32 *)((u8 *)arg0 + 0x10) + *(f32 *)(p + 0x17C)) * 0.5f;
        v.z = *(f32 *)(p + 0x174) + D_L32_001DEAB0;
        *(u8 **)(p + 0x168) = func_L32_003C4F70((vu0_q *)&v);
    }
    if (func_0038CAD0(p + 0xA8) != 0) {
        func_L32_003A5850(arg0);
    }
}
/* localdecomp:end func_L32_003A5BC0 */

/* localdecomp:start func_L32_003A5C78 */
extern f32 D_001DE9D4_sda, D_001DEA88_sda, D_001DEA50_sda;
__asm__(".extern D_001DE9D4_sda, 4");
__asm__(".extern D_001DEA88_sda, 4");
__asm__(".extern D_001DEA50_sda, 4");
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A5850(void *arg0);

void func_L32_003A5C78(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);

    *(s32 *)(d + 0x110) = func_L30_0034D1E8(obj, obj + 0x10, d + 0x90, d + 0x140, D_001DE9D4_sda, D_001DE9D4_sda, D_001DEA88_sda, 0.0f, 0.0f, D_001DEA50_sda, 1, 1, 1, 0);
    if (obj[0x60] & 2) {
        func_L32_003A5850(obj);
    }
}
/* localdecomp:end func_L32_003A5C78 */

/* localdecomp:start func_L32_003A5CF8 */
extern f32 D_L32_001DE8E8;
extern f32 D_L32_001DE918;
extern f32 D_L32_001DE91C;
extern f32 D_L32_001DE920;
extern f32 D_L32_001DE928;
extern f32 D_L32_001DE92C;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA40;
extern f32 D_L32_001DEA88;

extern f32 func_L32_00348900(u8 *);
extern void func_L32_00349630(void *, void *, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A5CF8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 d;
    f32 x;

    d = func_L32_00348900(a0);
    if (func_L01_004561B8(a0) != 0) {
        x = D_L32_001DE928;
        if (*(f32 *)(a0 + 0xF8) == D_L32_001DE8E8) {
            x = -x;
        }
        *(f32 *)(v + 0x98) = D_L32_001DE92C;
        *(f32 *)(v + 0x90) = x;
    }
    func_L32_00349630(a0, a0 + 0x10, D_L32_001DE9D4, *(f32 *)(v + 0x98), *(f32 *)(v + 0x148),
                      D_L32_001DE920, D_L32_001DE91C, 0.0f, -1.0f);
    *(s32 *)(v + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, v + 0x90, v + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                            D_L32_001DEA88,
                                            (a0[0x42] != a0[0x43] || d < D_L32_001DE91C) ? D_L32_001DE928 : 0.0f, 0.0f, D_L32_001DEA40, 1, 1, 1, 0);
    if ((a0[0x60] & 2) || D_L32_001DE918 <= d) {
        *(f32 *)(a0 + 0x48) = 0.0f;
        func_L32_003A52A8(a0, 0x42);
    }
}
/* localdecomp:end func_L32_003A5CF8 */
