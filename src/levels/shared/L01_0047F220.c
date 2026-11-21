#include "common.h"

/* localdecomp:start func_L01_0047F220 */
extern u8 D_L01_001D82C0;
extern s32 func_00381FF0(s32);
extern s32 func_003B9700(s32, s32, s32, s32, s32);
extern s32 func_003B97B0(void);
extern s32 func_L01_00498110_0047F220(void);
extern void *func_L01_0043B548(s32, s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00516090_0047F220(s32);
extern s32 func_L01_00516D60(s32, s32);

s32 func_L01_0047F220(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 r;
    void **p;

    switch (D_L01_001D82C0) {
    case 0:
        return 0;
    case 1:
        a = func_00381FF0(2274);
        b = func_00381FF0(2271);
        c = func_00381FF0(4145);
        func_003B9700(0, a, b, c, 0);
        D_L01_001D82C0 = 2;
        return 1;
    case 2:
        if (func_003B97B0() != 0) {
            return 1;
        }
        r = func_L01_00498110_0047F220();
        if (r == 1) {
            p = func_L01_0043B548(6747, 4);
            if (p != 0) {
                ((void (*)(void))*p)();
            }
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_0047F220(func_L01_0047FE28());
            D_L01_001D82C0 = 0;
            func_L01_00516D60(0xD000B, 1);
            func_L01_00516D60(0xD0025, 1);
            return 1;
        }
        if (r == 2) {
            D_L01_001D82C0 = 0;
            func_L01_00516D60(0xD000B, 1);
            func_L01_00516D60(0xD0025, 1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0047F220 */

/* localdecomp:start func_L01_0047F370 */
extern u8 D_L01_001D82C0;
extern s32 func_L01_00516D60(s32, s32);

void func_L01_0047F370(void) {
    D_L01_001D82C0 = 1;
    func_L01_00516D60(0xD000B, 0);
    func_L01_00516D60(0xD0025, 0);
}
/* localdecomp:end func_L01_0047F370 */

/* localdecomp:start func_L01_0047F3B0 */
extern s32 func_L01_00486980_0047F3B0(void);
extern void func_L01_00517748_0047F3B0(s32);

void func_L01_0047F3B0(void) {
    func_L01_00517748_0047F3B0(func_L01_00486980_0047F3B0());
}
/* localdecomp:end func_L01_0047F3B0 */

/* localdecomp:start func_L01_0047F3D8 */
extern s32 func_L01_00487EB0_0047F3D8(void);
extern void func_L01_00517748_0047F3D8(s32);

void func_L01_0047F3D8(void) {
    func_L01_00517748_0047F3D8(func_L01_00487EB0_0047F3D8());
}
/* localdecomp:end func_L01_0047F3D8 */

/* localdecomp:start func_L01_0047F400 */
extern s32 func_L01_0048EE70_0047F400(void);

void func_L01_0047F400(void) {
    func_L01_00517748(func_L01_0048EE70_0047F400());
}
/* localdecomp:end func_L01_0047F400 */

/* localdecomp:start func_L01_0047F428 */
extern s32 func_L01_00489FD0_0047F428(void);

void func_L01_0047F428(void) {
    func_L01_00517748(func_L01_00489FD0_0047F428());
}
/* localdecomp:end func_L01_0047F428 */

/* localdecomp:start func_L01_0047F450 */
extern s32 func_L01_0048D8D8_0047F450(void);

void func_L01_0047F450(void) {
    func_L01_00517748(func_L01_0048D8D8_0047F450());
}
/* localdecomp:end func_L01_0047F450 */

/* localdecomp:start func_L01_0047F478 */
extern void func_L01_00516090_0047F478(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00517748(s32);

extern s32 func_L01_00492870(void);
/* no prototype: func_0047C878 passes an arg */

void func_L01_0047F478(void) {
    ((s32 (*)())func_L01_00517748)(func_L01_00492870());
    ((void (*)(void *p))func_L01_00516090_0047F478)(((void * (*)())func_L01_0047FE28)());
}
/* localdecomp:end func_L01_0047F478 */

/* localdecomp:start func_L01_0047F4B0 */
extern void func_L01_00516090_0047F4B0(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00517748(s32);

extern s32 func_L01_004A1128(void);
/* no prototype: func_0047C878 passes an arg */

void func_L01_0047F4B0(void) {
    ((s32 (*)())func_L01_00517748)(func_L01_004A1128());
    ((void (*)(void *p))func_L01_00516090_0047F4B0)(((void * (*)())func_L01_0047FE28)());
}
/* localdecomp:end func_L01_0047F4B0 */

/* localdecomp:start func_L01_0047F4E8 */
extern s32 func_L01_004914D0(s32);
extern void func_L01_00517748(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00516090_0047F4E8(s32);
void func_L01_0047F4E8(void) {
    func_L01_00517748(func_L01_004914D0(0));
    func_L01_00516090_0047F4E8(func_L01_0047FE28());
}
/* localdecomp:end func_L01_0047F4E8 */
