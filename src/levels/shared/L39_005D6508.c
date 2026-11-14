#include "common.h"

/* localdecomp:start func_L39_005D6508 */
__asm__(".extern D_L39_002412DC, 16");
typedef struct { u8 p0[4]; s32 f4; } O_005D6508;
extern O_005D6508 D_L39_0024CD50 __attribute__((section(".data")));
extern u8 D_L39_00296F80[];
extern u8 D_L39_00296B80[];
extern s32 D_L39_002412DC;
extern u8 D_001A46D4[];
extern void func_L01_00430110(s32);
extern void func_003E9470(void);
extern void func_003E72B8(s32);
extern void *func_003E6C08(void);
extern s32 *func_003B2DC8(s32);
extern s32 func_003E5AA0(void *, u32);
extern s32 func_003E6CD8(void *, u32, s32);
extern s32 func_003B42C0(void);
extern s32 func_003B42F8(s32);
extern s32 func_003B4380(void);
extern s32 func_003B43B0(s32);
extern void func_003E69B0(void *, s32, s32);
extern s32 func_003E6D10(void *, s32, s32, void *, s32);
extern void func_003E6E10(void *, s32);
extern void func_L39_005D6730(void);

s32 func_L39_005D6508(void) {
    s32 ok = 1;
    void *obj;
    s32 i;

    func_L01_00430110(1);
    func_003E9470();
    func_003E72B8(1);
    func_003E6C08();
    if (D_L39_0024CD50.f4 != 0) {
        obj = &D_L39_0024CD50;
    } else {
        obj = func_003E6C08();
    }
    for (i = 0; i < 5; i++) {
        func_003E5AA0(func_003B2DC8(i), i);
        func_003E6CD8(obj, i, (s32)func_003B2DC8(i));
    }
    func_003E69B0(obj, 0, func_003B42C0());
    func_003E69B0(obj, 1, func_003B42F8(0));
    func_003E69B0(obj, 2, func_003B42F8(1));
    func_003E69B0(obj, 3, func_003B42F8(2));
    func_003E69B0(obj, 4, func_003B42F8(3));
    func_003E69B0(obj, 5, func_003B4380());
    func_003E69B0(obj, 6, func_003B43B0(0));
    func_003E69B0(obj, 7, func_003B43B0(1));
    func_003E69B0(obj, 8, func_003B43B0(1));
    func_003E69B0(obj, 9, func_003B43B0(1));
    ok = (ok != 0) & (func_003E6D10(obj, 0, 0x400, D_L39_00296F80, 0x10) != 0);
    ok = (ok != 0) & (func_003E6D10(obj, 1, 0x1E800, D_L39_00296B80, 0x64) != 0);
    func_003E6E10(obj, 0);
    if (D_L39_002412DC != 0x27 && D_001A46D4[0] == 0x27) {
        func_L39_005D6730();
    }
    return ok;
}
/* localdecomp:end func_L39_005D6508 */

/* localdecomp:start func_L39_005D6730 */
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern s32 func_L39_005D9730(s32);
extern s32 func_003E6FE0(s32);
extern s32 func_L01_0047C4A8(s32);
extern void func_003E82F8(s32);
extern s32 func_003E8440(s32);
extern s32 func_L39_005DED68(s32);
extern s32 func_L01_00479578(s32);
extern s32 func_L01_0047B638(s32);
extern s32 func_L39_005E1ED0(s32);
extern s32 func_L01_0047C368(s32);
extern s32 func_L39_005E0310(s32);
extern void func_L39_005D6468(s32, s32);

void func_L39_005D6730(void) {
    s32 i;
    s32 n;

    n = (*D_L39_00241120 < 2) ? 0 : 4;
    func_003E6FE0(func_L39_005D9730(0));
    func_003E6FE0(func_L01_0047C4A8(0));
    func_003E82F8(n);
    func_003E8440(func_L39_005D9730(0));
    func_003E8440(func_L01_0047C4A8(0));
    func_003E8440(func_L39_005DED68(0));
    for (i = 0; i < *D_L39_00241120; i++) {
        func_003E6FE0(func_L01_00479578(i));
        func_003E6FE0(func_L01_0047B638(i));
        func_003E6FE0(func_L39_005E1ED0(i));
        func_003E6FE0(func_L01_0047C368(i));
        func_003E6FE0(func_L39_005E0310(i));
        func_L39_005D6468(i, 0);
        func_003E82F8(i);
        func_003E8440(func_L01_00479578(i));
        func_003E8440(func_L01_0047B638(i));
        func_003E8440(func_L39_005E1ED0(i));
        func_003E8440(func_L01_0047C368(i));
        func_003E8440(func_L39_005E0310(i));
    }
    func_003E82F8(0);
}
/* localdecomp:end func_L39_005D6730 */
