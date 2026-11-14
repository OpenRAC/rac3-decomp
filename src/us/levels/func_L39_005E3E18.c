#include "common.h"

/* NTSC-U counterpart of func_L39_005E6388 (src/levels/shared/L39_005E6388.c): 8 -> 10 */
/* localdecomp:start func_L39_005E3E18 */
typedef struct Ent_005E6388 {
    s32 id;
    u8 pad4[0x2C];
} Ent_005E6388;

extern Ent_005E6388 D_L39_0049A3D8[];
extern s32 D_L39_00243CDC[2];
extern f32 D_L39_00245DB8;
extern s32 D_001D8458_sda_005E3E18 __attribute__((section(".sdata")));
__asm__(".extern D_001D8458_sda_005E3E18, 4");
extern s32 D_001D8430_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8430_sda, 8");

extern s32 func_L01_00513698(void);
extern void func_L39_005E14A0(s32);
extern void func_L39_00619968(s32, s32);
extern void func_L01_0047AC50_005E3E18(void);
extern void func_00389920(s32);
extern s32 func_0037DF98(s32);
extern s32 func_00389D18(f32, s32, s32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_L39_005E5028(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0048E2F8(void *);
extern s32 func_003E2DE0(s32, s32);
extern void func_L39_005E4810(void);
extern void func_L39_005E4CD8(void);
extern void func_L01_00512D70(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern s32 func_003B46F0(s32);
extern void func_L01_00494E68(void *, s32);
extern s32 func_L01_00512AB0(s32, s32, s32);

void func_L39_005E3E18(void) {
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

    func_L39_005E14A0(func_L01_00513698());
    func_L39_00619968(func_L01_00513698(), 1);
    D_001D8458_sda_005E3E18 = 0;
    for (j = 3, q = D_L39_00243CDC; j >= 0; j--) {
        *q-- = -1;
    }
    func_L01_0047AC50_005E3E18();
    func_00389920(0);
    x = (f32)func_00389D18(1.2f, func_0037DF98(0x107), -1) / D_L39_00245DB8;
    if (hi < x) {
        x = hi;
    }
    x = (x - lo) / (hi - lo);
    r = func_003BEB48(a6, b11, x);
    if (b11 < r) {
        r = b11;
    } else if (r < a6) {
        r = a6;
    }
    func_L39_005E5028(0x10, r, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008,
                      func_0037DF98(0x107), 0xD0006, 0x124, 0xD0007, 0xCD5);
    p = D_L39_0049A3D8;
    func_L01_0048E2F8(p);
    func_003E2DE0(0x11, 0x1C0000);
    for (; p->id != 0; p++) {
        func_L01_00512AB0(p->id, 0x2000, 1);
    }
    func_L39_005E4810();
    func_L39_005E4CD8();
    func_L01_00512D70(0x1C0003, 0);
    func_003E3250(0x1C0003, 1, 10);
    i = func_003B46F0(func_L01_00513698());
    func_L01_00494E68((void *)i, D_001D8430_sda[func_L01_00513698()]);
}
/* localdecomp:end func_L39_005E3E18 */
