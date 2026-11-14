#include "common.h"

/* NTSC-U counterpart of func_L07_003BB840 (src/levels/07_annihilation_nation/L07_003BB360.c) */
/* localdecomp:start func_L07_003B9F50 */
typedef struct Hero_3BB840 {
    u8 pad0[0x2808];
    u8 *target;
    u8 pad280C[0x2850 - 0x280C];
    s32 health;
} Hero_3BB840;
extern Hero_3BB840 D_001A4BE0;
extern s32 D_00142660[];
__asm__(".extern D_00142660, 16");
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L07_003A0BC0(s32, void *, s32, s32);

void func_L07_003B9F50(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *target;

    if ((D_00142660[2] >> 3) >= D_001A4BE0.health) {
        switch (func_0037E1D8(3)) {
        case 0:
            if (!(*(u16 *)(vars + 0xA4) & 0x40)) {
                func_L07_003A0BC0(0x59, obj, 0, 0x78);
                *(u16 *)(vars + 0xA4) |= 0x40;
                return;
            }
        case 1:
            if (!(*(u16 *)(vars + 0xA4) & 0x80)) {
                func_L07_003A0BC0(0x5A, obj, 0, 0x78);
                *(u16 *)(vars + 0xA4) |= 0x80;
                return;
            }
            break;
        }
    }
    if ((D_00142660[2] >> 2) >= D_001A4BE0.health) {
        switch (func_0037E1D8(3)) {
        case 0:
            if (!(*(u16 *)(vars + 0xA4) & 0x100)) {
                func_L07_003A0BC0(0x57, obj, 0, 0x78);
                *(u16 *)(vars + 0xA4) |= 0x100;
                return;
            }
        case 1:
            if (!(*(u16 *)(vars + 0xA4) & 0x200)) {
                func_L07_003A0BC0(0x58, obj, 0, 0x78);
                *(u16 *)(vars + 0xA4) |= 0x200;
                return;
            }
            break;
        }
    }
    target = D_001A4BE0.target;
    if (target != 0) {
        switch (*(s16 *)(target + 0xAA)) {
        case 0x197E:
            if (func_0037E1D8(5) == 0) {
                func_L07_003A0BC0(0x5B, obj, 0, 0x78);
                return;
            }
        case 0x1A85:
        case 0x1ADB:
        case 0x1B36:
        case 0x1D88:
        case 0x1D89:
        case 0x1D8B:
            func_L07_003A0BC0((u8)func_0037E208(0x54, 0x56), obj, 0, 0x78);
            return;
        }
    }
    func_L07_003A0BC0((u8)func_0037E208(0x52, 0x53), obj, 0, 0x78);
}
/* localdecomp:end func_L07_003B9F50 */
