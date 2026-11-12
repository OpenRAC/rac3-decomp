#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003CF3E8 */
typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0xF]; u8 f30; } O_003CF3E8;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } G_003CF3E8;
extern u8 D_00142700[];
extern u8 D_001A4C60[];
extern G_003CF3E8 *D_001D52FC;
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L02_003E71A8(f32, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00415D40(s32, s32, s32, s32);
extern void func_L01_00415C98(s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
void func_L03_003CF3E8(O_003CF3E8 *o) {
    f32 d[4];
    u8 *h;
    s32 a, b;
    switch (o->f20) {
    case 0:
        if (D_00142700[0] == 0) {
            func_003C2880(o);
        } else {
            o->f30 = 0x10;
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 1:
        if (func_L02_003E71A8(2.5f, (u8 *)o + 0x10, D_001A4C60) != 0) {
            h = D_001A4C60 - 0x80;
            if (*(s32 *)(h + 0x360) != 0) {
                vec_sub_ab(d, (u8 *)o + 0x10, D_001A4C60);
                if (func_0038CE68(d, (u8 *)o + 0xC0) < 0.1f) {
                    if (func_0038CE68((u8 *)o + 0xC0, *(u8 **)(h + 0x25C0) + 0xC0) < 0.1f) {
                        func_L01_00452560(0, 4, 0x18CE, 1, 0, 0, 0);
                        if (D_001D52FC->f1A4 & 0x10) {
                            a = func_00381FF0(0x8DE);
                            b = func_00381FF0(0x18CB);
                            func_L01_00415D40(a, 0, b, 1);
                            func_L01_00415C98(0x40, 0);
                            func_003A0EC0(4, 1, 10, 0, 0);
                        }
                    }
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L03_003CF3E8 */
