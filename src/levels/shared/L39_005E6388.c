#include "common.h"

/* localdecomp:start func_L39_005E6388 */
typedef struct Ent_005E6388 {
    s32 id;
    u8 pad4[0x2C];
} Ent_005E6388;

extern Ent_005E6388 D_L39_0049A318[];
extern s32 D_L39_00243B74[2];
extern f32 D_L39_00245C38;
extern s32 D_001D8470_sda __attribute__((section(".sdata")));
__asm__(".extern D_001D8470_sda, 4");
extern s32 D_001D8448_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8448_sda, 8");

extern s32 func_L01_00517688(void);
extern void func_L39_005E3A10(s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L01_0047E4B0_005E6388(void);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern s32 func_0038E548(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L39_005E7598(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00491AF0(void *);
extern s32 func_003E8348(s32, s32);
extern void func_L39_005E6D80(void);
extern void func_L39_005E7248(void);
extern void func_L01_00516D60(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern s32 func_003B9BD0(s32);
extern void func_L01_004986A8(void *, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L39_005E6388(void) {
    s32 i;
    s32 j;
    s32 *q;
    f32 x;
    f32 r;
    f32 lo = 0.0f;
    f32 hi = 0.49f;
    f32 a6 = 6.0f;
    f32 b11 = 11.0f;
    Ent_005E6388 *p;

    func_L39_005E3A10(func_L01_00517688());
    func_L39_0061C0E0(func_L01_00517688(), 1);
    D_001D8470_sda = 0;
    for (j = 3, q = D_L39_00243B74; j >= 0; j--) {
        *q-- = -1;
    }
    func_L01_0047E4B0_005E6388();
    func_0038E150(0);
    x = (f32)func_0038E548(1.2f, func_00381FF0(0x107), -1) / D_L39_00245C38;
    if (hi < x) {
        x = hi;
    }
    x = (x - lo) / (hi - lo);
    r = func_003C4088(a6, b11, x);
    if (b11 < r) {
        r = b11;
    } else if (r < a6) {
        r = a6;
    }
    func_L39_005E7598(0x10, r, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008,
                      func_00381FF0(0x107), 0xD0006, 0x124, 0xD0007, 0xCD5);
    p = D_L39_0049A318;
    func_L01_00491AF0(p);
    func_003E8348(0x11, 0x1C0000);
    for (; p->id != 0; p++) {
        func_L01_00516AA0(p->id, 0x2000, 1);
    }
    func_L39_005E6D80();
    func_L39_005E7248();
    func_L01_00516D60(0x1C0003, 0);
    func_003E87B8(0x1C0003, 1, 8);
    i = func_003B9BD0(func_L01_00517688());
    func_L01_004986A8((void *)i, D_001D8448_sda[func_L01_00517688()]);
}
/* localdecomp:end func_L39_005E6388 */
