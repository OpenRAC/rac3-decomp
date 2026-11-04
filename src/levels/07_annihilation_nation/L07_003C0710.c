#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003C0710);

INCLUDE_ASM("asm/levels", func_L07_003C0BE8);

/* localdecomp:start func_L07_003C0D00 */
void func_L01_003EB5E0(s32, s32);
void func_L01_004450F0(s32, s32, s32);
void func_L01_005003D0(s32, s32);

void func_L07_003C0D00(s32 arg0) {
    func_L01_005003D0(0, 1);
    func_L01_003EB5E0(0, 2);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003C0D00 */

INCLUDE_ASM("asm/levels", func_L07_003C0D48);

INCLUDE_ASM("asm/levels", func_L07_003C0E08);

INCLUDE_ASM("asm/levels", func_L07_003C0E58);

INCLUDE_ASM("asm/levels", func_L07_003C0ED8);

INCLUDE_ASM("asm/levels", func_L07_003C0F40);

INCLUDE_ASM("asm/levels", func_L07_003C0FC8);

INCLUDE_ASM("asm/levels", func_L07_003C1120);

INCLUDE_ASM("asm/levels", func_L07_003C1138);

INCLUDE_ASM("asm/levels", func_L07_003C12A8);

INCLUDE_ASM("asm/levels", func_L07_003C1360);

/* localdecomp:start func_L07_003C1430 */
extern u8 D_001D5551[];

u8 func_L07_003C1430(s32 arg0) {
    u8 var_v0;

    var_v0 = 1;
    if (arg0 == 0) {
        var_v0 = D_001D5551[0];
    }
    return var_v0;
}
/* localdecomp:end func_L07_003C1430 */

INCLUDE_ASM("asm/levels", func_L07_003C1448);

INCLUDE_ASM("asm/levels", func_L07_003C1528);

INCLUDE_ASM("asm/levels", func_L07_003C17C0);

INCLUDE_ASM("asm/levels", func_L07_003C19C8);

INCLUDE_ASM("asm/levels", func_L07_003C1AF8);

INCLUDE_ASM("asm/levels", func_L07_003C1B40);

INCLUDE_ASM("asm/levels", func_L07_003C1B88);

/* localdecomp:start func_L07_003C1C08 */
extern u8 D_001426E0[];

s32 func_L07_003C1C08(s32 arg0) {
    if (D_001426E0[arg0 + 0x8E] == 0) {
        switch (arg0) {
        case 0:
            return 0x1504;
        case 1:
            return 0xC3B;
        case 2:
            return 0x129A;
        case 3:
            return 0x129B;
        }
    }
    return -1;
}
/* localdecomp:end func_L07_003C1C08 */

INCLUDE_ASM("asm/levels", func_L07_003C1C88);

/* localdecomp:start func_L07_003C1D58 */
extern u8 D_001A4BE0[];
extern f32 func_L01_0040E570(u8 *, u8 *);

s32 func_L07_003C1D58(u8 *a0) {
    s32 r = 0;

    if (D_001A4BE0[0x25E4] == 0) {
        if (*(s16 *)&D_001A4BE0[0x288C] == 0) {
            if (func_L01_0040E570(D_001A4BE0 + 0x80, a0 + 0x10) < 25.0f) {
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L07_003C1D58 */

/* localdecomp:start func_L07_003C1DC8 */
void func_L01_00479200(s32);
void func_L01_0047B3D8(void);
void func_L01_0047B948(void);
void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
void func_L01_003EB350(s32, void *);
void func_L01_003EB3C0(s32, void *);

extern u8 D_L07_001E1EC0[];
extern s32 D_001DE560;
extern s32 D_001DE570;

void func_L07_003C1DC8(s32 arg0) {
    func_L01_00479200(arg0);
    func_L01_0047B3D8();
    func_L01_0047B948();
    func_L01_003EB438(0, D_L07_001E1EC0, D_L07_001E1EC0 + 0x10, 2, 0xA7, 0);
    func_L01_003EB350(0, &D_001DE560);
    func_L01_003EB3C0(0, &D_001DE570);
    func_L01_004450F0(arg0, 3, -1);
}
/* localdecomp:end func_L07_003C1DC8 */

INCLUDE_ASM("asm/levels", func_L07_003C1E48);

INCLUDE_ASM("asm/levels", func_L07_003C1E80);

INCLUDE_ASM("asm/levels", func_L07_003C1EB8);
