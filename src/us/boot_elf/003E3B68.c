#include "common.h"

/* NTSC-U version of func_003E3CB0 (boot_elf): 0.02 -> 0.0166667 */

typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3DBEC8;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x7C - 0x64];
    s16 f7C, f7E;
    s32 f80;
    u8 pad84[0x98 - 0x84];
} S_3DBEC8;
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_11B2E8();
typedef int Q_3DCD08 __attribute__((mode(TI)));
typedef struct { Q_3DCD08 a, b; } V2_3DCD08;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DCD08;
typedef struct {
    V4_3DCD08 v0;
    V4_3DCD08 v10;
    V4_3DCD08 v20;
    V4_3DCD08 v30;
    s32 f40;
    s32 f44;
    s32 f48, f4C, f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    f32 f6C;
    s32 f70;
    s32 f74, f78;
    s16 f7C, f7E;
    s32 f80;
    s16 f84, f86;
    s32 f88, f8C, f90, f94;
} S_3DCD08;
typedef struct {
    u8 pad0[0x100];
    s32 f100;
    u8 pad104[0x148 - 0x104];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1A4 - 0x150];
    s32 f1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    s32 f1C0;
    s32 f1C4;
} P_3DCD08;
/* localdecomp:start func_U_003E3B68 */
extern void func_U_003E3B68(f32 *);
__asm__(".extern D_U_001D950C, 4");
extern f32 D_U_001D950C;
extern f32 D_U_002224A0[];
extern void func_U_003C4F38();
extern void func_U_0038DB38();
extern void func_U_0038D918();
void func_U_003E3B68(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_U_003C4F38)(a, D_U_002224A0, *arg0 * (D_U_001D950C * 0.017453292f * 0.0166666675f));
    func_U_0038DB38(a, b);
    func_U_0038D918(D_U_002224A0, b, D_U_002224A0);
}
/* localdecomp:end func_U_003E3B68 */
