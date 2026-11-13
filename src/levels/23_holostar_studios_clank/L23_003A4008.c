#include "common.h"
typedef struct { u8 pad0[0x1A84]; s32 x1A84; u8 pad1A88[0x10]; s32 x1A98; } H_3A4008;

/* localdecomp:start func_L23_003A4008 */
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern H_3A4008 D_001A4BE0;
extern char D_L23_001DE020[];
extern char D_L23_001E12F0[8];
__asm__(".extern D_L23_001E12F0, 8");
extern char D_L23_001E1300[8];
__asm__(".extern D_L23_001E1300, 8");
extern char D_L23_001E1310[8];
__asm__(".extern D_L23_001E1310, 8");
s32 func_L01_00516AA0(s32, s32, s32);
extern f32 D_L23_001DE000;
__asm__(".extern D_L23_001DE000, 4");
extern s32 func_L01_005169C8(s32, f32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00516FD8(s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_005170B8(s32, s32);

void func_L23_003A4008(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *m = D_L23_001DF15C + (*(s32 *)(v + 0xC) << 8);
    u8 *mv = *(u8 **)(m + 0x68);
    f32 f;

    func_L01_005169C8(0x730002, 1.0f - *(f32 *)(v + 0x20));
    func_0011B2E8(D_L23_001E12F0, D_L23_001DE020, D_001A4BE0.x1A84);
    func_L01_00516FD8(0x730005, (s32)D_L23_001E12F0);
    f = 1.0f - (f32)D_001A4BE0.x1A98 / 150.0f;
    if (1.0f < f)
        f = 1.0f;
    else if (f < 0.0f)
        f = 0.0f;
    func_L01_005169C8(0x730012, f);
    func_L01_005169C8(0x730007, 1.0f - *(f32 *)(v + 0x24));
    func_0011B2E8(D_L23_001E1300, D_L23_001DE020, (s32)*(f32 *)(mv + 0x30));
    func_L01_00516FD8(0x73000A, (s32)D_L23_001E1300);
    if (m[0x20] == 2)
        func_003C4138((f32 *)(v + 0x174), D_L23_001DE000, 0.01986755f);
    else
        func_003C4138((f32 *)(v + 0x174), 1.0f, 0.01986755f);
    func_L01_005170B8(0x730006, func_0038DBD8(0x1465B7, 0x331465B7, *(f32 *)(v + 0x174)));
    func_L01_005170B8(0x730007, func_0038DBD8(0x66CCFF, 0x8066CCFF, *(f32 *)(v + 0x174)));
    func_L01_005170B8(0x730008, func_0038DBD8(0x2299DE, 0x332299DE, *(f32 *)(v + 0x174)));
    func_L01_005170B8(0x730009, func_0038DBD8(0x66CCFF, 0x8066CCFF, *(f32 *)(v + 0x174)));
    func_L01_005170B8(0x73000A, func_0038DBD8(0x66CCFF, 0x8066CCFF, *(f32 *)(v + 0x174)));
    func_0011B2E8(D_L23_001E1310, D_L23_001DE020, *(s32 *)(mv + 0x388));
    if (*(s32 *)(mv + 0x388) > 0)
        func_003C4138((f32 *)(v + 0x170), 1.0f, 0.01986755f);
    else
        func_003C4138((f32 *)(v + 0x170), 0.0f, 0.01986755f);
    if (*(f32 *)(v + 0x170) <= 0.0f) {
        func_L01_00516AA0(0x73000B, 1, 0);
        func_L01_00516AA0(0x73000C, 1, 0);
        func_L01_00516AA0(0x73000D, 1, 0);
        func_L01_00516AA0(0x73000E, 1, 0);
    } else {
        func_L01_005170B8(0x73000B, func_0038DBD8(0x1465B7, 0x331465B7, *(f32 *)(v + 0x170)));
        func_L01_005170B8(0x73000C, func_0038DBD8(0x2299DE, 0x332299DE, *(f32 *)(v + 0x170)));
        func_L01_005170B8(0x73000D, func_0038DBD8(0x66CCFF, 0x8066CCFF, *(f32 *)(v + 0x170)));
        func_L01_005170B8(0x73000E, func_0038DBD8(0x66CCFF, 0x8066CCFF, *(f32 *)(v + 0x170)));
        func_L01_00516AA0(0x73000B, 1, 1);
        func_L01_00516AA0(0x73000C, 1, 1);
        func_L01_00516AA0(0x73000D, 1, 1);
        func_L01_00516AA0(0x73000E, 1, 1);
    }
    func_L01_00516FD8(0x73000E, (s32)D_L23_001E1310);
}
/* localdecomp:end func_L23_003A4008 */
