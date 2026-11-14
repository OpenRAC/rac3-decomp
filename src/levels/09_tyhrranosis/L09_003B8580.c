#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L09_003B8580);

INCLUDE_ASM("asm/levels", func_L09_003BBB58);

INCLUDE_ASM("asm/levels", func_L09_003BBF10);

INCLUDE_ASM("asm/levels", func_L09_003BC288);

INCLUDE_ASM("asm/levels", func_L09_003BC450);

INCLUDE_ASM("asm/levels", func_L09_003BC790);

INCLUDE_ASM("asm/levels", func_L09_003BC7F0);

INCLUDE_ASM("asm/levels", func_L09_003BCE10);

/* localdecomp:start func_L09_003BD360 */
extern u8 *D_L09_0021E640[];
__asm__(".extern D_L09_0021E640, 16");

s32 func_L09_003BD360(s32 a0, s32 a1, s8 *a2, s32 *a3) {
    u8 *p1;
    u8 *p2;
    f32 d;
    p1 = D_L09_0021E640[a3[a0]] + (a1 << 4);
    p2 = D_L09_0021E640[a3[a2[2]]] + (a2[3] << 4);
    d = fabs_asm(*(f32 *)(p1 + 0x10) - *(f32 *)(p2 + 0x10));
    d = d + fabs_asm(*(f32 *)(p1 + 0x14) - *(f32 *)(p2 + 0x14));
    return (s32)d;
}
/* localdecomp:end func_L09_003BD360 */

INCLUDE_ASM("asm/levels", func_L09_003BD3E8);

INCLUDE_ASM("asm/levels", func_L09_003BD560);

/* localdecomp:start func_L09_003BD860 */
s32 func_L09_003BD860(void *arg0) {
    s32 var_a0;
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    var_a0 = 1;
    if (!(((*(f32 *)((u8 *)temp_v0 + 0x30)) + 1.0f) <= ((f32) (*(s16 *)((u8 *)temp_v0 + 0x34)) * (*(f32 *)((u8 *)temp_v0 + 0xD4C))))) {
        var_a0 = 0;
    }
    return var_a0;
}
/* localdecomp:end func_L09_003BD860 */

INCLUDE_ASM("asm/levels", func_L09_003BD8A8);

INCLUDE_ASM("asm/levels", func_L09_003BDB90);

INCLUDE_ASM("asm/levels", func_L09_003BDED0);

INCLUDE_ASM("asm/levels", func_L09_003BE168);

INCLUDE_ASM("asm/levels", func_L09_003BE228);

INCLUDE_ASM("asm/levels", func_L09_003BE330);

INCLUDE_ASM("asm/levels", func_L09_003BE450);

INCLUDE_ASM("asm/levels", func_L09_003BE5D0);

INCLUDE_ASM("asm/levels", func_L09_003BE910);

INCLUDE_ASM("asm/levels", func_L09_003BEB30);

INCLUDE_ASM("asm/levels", func_L09_003BEC20);

INCLUDE_ASM("asm/levels", func_L09_003BED10);

INCLUDE_ASM("asm/levels", func_L09_003BEDA8);

/* localdecomp:start func_L09_003BEF00 */
/* PAL port of the NTSC-U match src/us/levels/func_L09_003BD680.c */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(void *, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L09_003BC790(void *, s32, s32, s32, s32);
extern s32 func_L09_003BD560(void *, s32, s32, s32, s32);

extern u8 D_001A4C60[];

s32 func_L09_003BEF00(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s16 *h = (s16 *)(p + 0xD34);

    if (*(unsigned long *)(p + 0xD40) & 0x50000) {
        p[0xD42] &= 0xFE;
        func_L01_004450F0(a0, 0xD, -1);
        func_L01_00445188(a0, 1);
        return 0;
    }
    if (func_0038CB00(p + 0xD38)) {
        func_L09_003BC790(a0, a1, a2, a3, 1);
        return 0;
    }
    if (func_0038CF38(a0 + 0x10, D_001A4C60) > 25.0f) {
        *h = 0;
        return 1;
    }
    if ((*h)++ >= 500) {
        *h = 0;
        return 1;
    }
    if (p[0xD42] & 2) {
        func_L09_003BD560(a0, a1, a2, a3, 1);
    }
    return 0;
}
/* localdecomp:end func_L09_003BEF00 */

INCLUDE_ASM("asm/levels", func_L09_003BF038);

INCLUDE_ASM("asm/levels", func_L09_003BF0E0);

/* localdecomp:start func_L09_003BF2F8 */
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C6FE0(void *);
extern void func_003C7C38(void *);
extern void func_0038D590(void *, void *);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(void *);

void func_L09_003BF2F8(u8 *a0) {
    u128_t buf[4];
    u8 *e = D_L09_001E009C + (*(s32 *)(*(u8 **)(a0 + 0x68) + 0xCD0) << 8);
    u8 *t;
    func_003C2EC0(a0, 1, buf);
    *(u128_t *)(e + 0x10) = buf[3];
    func_0038CE20(buf, buf, -1.0f);
    func_003C6FE0(e);
    if (!(*(u16 *)(e + 0x34) & 4))
        func_003C7C38(e);
    t = e + 0xC0;
    func_0038D590(t, buf);
    func_L01_00448E10(t);
    func_003C7DD8(e);
    if ((*(u16 *)(a0 + 0x34) & 1) && a0[0x95] == 0)
        *(u16 *)(e + 0x34) |= 0x41;
    else
        *(u16 *)(e + 0x34) &= 0xFFBE;
    *(u16 *)(e + 0x34) |= 4;
}
/* localdecomp:end func_L09_003BF2F8 */

INCLUDE_ASM("asm/levels", func_L09_003BF3E0);

INCLUDE_ASM("asm/levels", func_L09_003BF5F0);

INCLUDE_ASM("asm/levels", func_L09_003BF890);

/* localdecomp:start func_L09_003BF9B8 */
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
__asm__(".extern D_001A4C60, 16");
extern u8 D_001A4C60[];

s32 func_L09_003BF9B8(u8 *a0) {
    u8 *v = a0 + 0xC0;
    vu0_v4 buf[2];

    func_0038CE20(buf, v, 5.0f);
    vec_add_ba(buf, a0 + 0x10, buf);
    vec_sub_ba(&buf[1], buf, D_001A4C60);
    *(s32 *)((u8 *)buf + 0x18) = 0;
    return func_0038CE68(v, &buf[1]) > 0.0f;
}
/* localdecomp:end func_L09_003BF9B8 */

INCLUDE_ASM("asm/levels", func_L09_003BFA48);

INCLUDE_ASM("asm/levels", func_L09_003BFC90);
