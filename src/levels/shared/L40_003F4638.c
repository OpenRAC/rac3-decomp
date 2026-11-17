#include "common.h"

/* localdecomp:start func_L40_003F4638 */
typedef struct { f32 x, y, z; } V3_003F4638;
__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;
extern s32 func_L40_0053F2D8(u8 *msg);
extern u8 *func_L40_0053F570(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_0038CB78(void *, s32, s32);
extern s32 func_L40_0053D8C8(s32 id, s32 a1, s32 a2, s32 a3);
extern void func_003C7C38(u8 *m);
extern void func_L40_003D3D80(u8 *m, s32 cls);
extern void func_L40_00413158(u8 *m, s32 cls);
extern void func_L40_003F47B0();
extern void func_L40_003F3C60();

u8 *func_L40_003F4638(s32 a0, s32 a1, u8 *msg) {
    s32 index = *(s32 *)(msg + 0x18);
    s32 *h = (s32 *)(msg + 8);
    u8 *m;
    u8 *v;
    s32 save;
    s32 *mode;

    m = func_L40_0053F570(0x1A1B, h[1], *(s32 *)(msg + 4), func_L40_0053F2D8(msg), index);
    if (m != 0) {
        {
            u8 *p = *(u8 **)(m + 0x24);
            *(u16 *)(m + 0x34) &= 0xFFBE;
            *(u16 *)(m + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
            *(s32 *)(m + 0x98) = *(s32 *)(p + 0x10);
        }
        *(V3_003F4638 *)(m + 0x10) = *(V3_003F4638 *)(msg + 0x1C);
        *(u8 *)(m + 0x30) = 0x7F;
        mode = D_L40_00241120;
        *(u16 *)(m + 0x34) |= 0x20;
        *(u16 *)(m + 0x32) = 0x7F;
        v = *(u8 **)(m + 0x68);
        if (*mode >= 2) {
            *(u8 *)(m + 0x62) = 1;
        }
        {
            u8 *p = *(u8 **)(m + 0x24);
            *(u16 *)(m + 0x34) &= 0xFFBE;
            *(u16 *)(m + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
            *(s32 *)(m + 0x98) = *(s32 *)(p + 0x10);
        }
        *(u8 *)(m + 0x20) = 0;
        *(s32 *)(v + 0x2A4) = 0;
        save = *(s32 *)(v + 0x2AC);
        func_0038CB78(v + 0x1F0, 0, 0x10C);
        *(s32 *)(v + 0x2A0) = 2;
        func_L40_0053D8C8(0x1A1B, (s32)func_L40_003F47B0, (s32)func_L40_003F3C60, (s32)func_L40_003F4638);
        *(s32 *)(v + 0x2AC) = save;
        *(u8 *)(v + 0x3E) = 1;
        func_L40_003D3D80(m, 0x1A1B);
        func_L40_00413158(m, 0x1A1B);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L40_003F4638 */

INCLUDE_ASM("asm/levels", func_L40_003F47B0);

/* localdecomp:start func_L40_003F51A0 */
extern u8 D_L40_00249FC0[];
extern void func_L40_003F4080(u8 *, u8 *);
extern s32 func_L40_003F54B8(u8 *, u8 *, u8 *, s32, s32);
extern f32 func_L01_0040E548(u8 *, u8 *);
extern void func_L01_004472C0(u8 *);
void func_L40_003F51A0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *s0 = **(u8 ***)(a0 + 144);
    func_L40_003F4080(s0, a0);
    func_L40_003F54B8(a0, s1 + 304, s0, 0, 0);
    if (a0[49] != 0 && func_L01_0040E548(D_L40_00249FC0, a0 + 16) < 256.0f) {
        func_L01_004472C0(a0);
        a0[111] = 15;
    }
}
/* localdecomp:end func_L40_003F51A0 */
