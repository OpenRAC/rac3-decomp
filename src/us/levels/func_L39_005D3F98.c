#include "common.h"

/* NTSC-U counterpart of func_L39_005D6508 (src/levels/shared/L39_005D6508.c) */
/* localdecomp:start func_L39_005D3F98 */
__asm__(".extern D_L39_0024145C, 16");
typedef struct { u8 p0[4]; s32 f4; } O_005D6508;
extern O_005D6508 D_L39_0024CE50 __attribute__((section(".data")));
extern u8 D_L39_00297080[];
extern u8 D_L39_00296C80[];
extern s32 D_L39_0024145C;
extern u8 D_001A4854[];
extern void func_L01_0042D280(s32);
extern void func_003E3F08(void);
extern void func_003E1D68(s32);
extern void *func_003E16B8(void);
extern s32 *func_003AD820(s32);
extern s32 func_003E0550(void *, u32);
extern s32 func_003E1788(void *, u32, s32);
extern s32 func_003AED08(void);
extern s32 func_003AED40(s32);
extern s32 func_003AEDC8(void);
extern s32 func_003AEDF8(s32);
extern void func_003E1460(void *, s32, s32);
extern s32 func_003E17C0(void *, s32, s32, void *, s32);
extern void func_003E18C0(void *, s32);
extern void func_L39_005D41C0(void);

s32 func_L39_005D3F98(void) {
    s32 ok = 1;
    void *obj;
    s32 i;

    func_L01_0042D280(1);
    func_003E3F08();
    func_003E1D68(0);
    func_003E16B8();
    if (D_L39_0024CE50.f4 != 0) {
        obj = &D_L39_0024CE50;
    } else {
        obj = func_003E16B8();
    }
    for (i = 0; i < 5; i++) {
        func_003E0550(func_003AD820(i), i);
        func_003E1788(obj, i, (s32)func_003AD820(i));
    }
    func_003E1460(obj, 0, func_003AED08());
    func_003E1460(obj, 1, func_003AED40(0));
    func_003E1460(obj, 2, func_003AED40(1));
    func_003E1460(obj, 3, func_003AED40(2));
    func_003E1460(obj, 4, func_003AED40(3));
    func_003E1460(obj, 5, func_003AEDC8());
    func_003E1460(obj, 6, func_003AEDF8(0));
    func_003E1460(obj, 7, func_003AEDF8(1));
    func_003E1460(obj, 8, func_003AEDF8(1));
    func_003E1460(obj, 9, func_003AEDF8(1));
    ok = (ok != 0) & (func_003E17C0(obj, 0, 0x400, D_L39_00297080, 0x10) != 0);
    ok = (ok != 0) & (func_003E17C0(obj, 1, 0x1E800, D_L39_00296C80, 0x64) != 0);
    func_003E18C0(obj, 0);
    if (D_L39_0024145C != 0x27 && D_001A4854[0] == 0x27) {
        func_L39_005D41C0();
    }
    return ok;
}
/* localdecomp:end func_L39_005D3F98 */
