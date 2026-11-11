#include "common.h"

/* localdecomp:start func_L22_00318A60 */
extern u8 D_001A4C60[];
extern u8 D_001A7E18[];
extern s32 D_001DC64C;
__asm__(".extern D_001DC64C, 4");
extern s32 D_001DF8C0;
extern s32 D_001D4CF0;
__asm__(".extern D_001D4CF0, 4");
extern s32 D_001D545C_00318A60;
__asm__(".extern D_001D545C_00318A60, 16");
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_0043B510(s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004B0EE0(void);
void func_L22_00318A60(u8 *self) {
    s32 *st = *(s32 **)(self + 0x68);
    u8 *p;
    s32 t, m;
    if (self[0x20] == 0) {
        self[0x30] = 0xFF;
        self[0x20] = 1;
    }
    if (func_00382380(D_001A4C60, *st, 0) != 0 && D_001DC64C == 0) {
        p = D_001A7E18;
        D_001DC64C = 1;
        m = 1 << D_001D545C_00318A60;
        if ((*(s32 *)(p + 0x80C) & m) == 0) {
            func_L01_0041A5B0(0xD04, 0xAB);
        }
        if (*(u16 *)(p + 0x9C30) == 0) {
            *(u16 *)(p + 0x9C30) = 1;
        }
    }
    if (func_L01_00456250(self) != 0) {
        func_L01_0043B510(self[0xB0]);
        func_L01_00456230(self, 0);
    }
    t = D_001DF8C0;
    if (t < 0x1E) {
        if (D_001D4CF0 == 0x14) {
            func_L01_004B0EE0();
        }
    }
}
/* localdecomp:end func_L22_00318A60 */
