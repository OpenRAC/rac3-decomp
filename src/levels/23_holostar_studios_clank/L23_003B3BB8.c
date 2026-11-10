#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_003B3BB8);

INCLUDE_ASM("asm/levels", func_L23_003B3EA8);

INCLUDE_ASM("asm/levels", func_L23_003B4108);

/* localdecomp:start func_L23_003B44E8 */
void func_L23_003B44E8(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x390) = 0;
}
/* localdecomp:end func_L23_003B44E8 */

INCLUDE_ASM("asm/levels", func_L23_003B44F8);

INCLUDE_ASM("asm/levels", func_L23_003B48D0);

INCLUDE_ASM("asm/levels", func_L23_003B4AD0);

INCLUDE_ASM("asm/levels", func_L23_003B5068);

/* localdecomp:start func_L23_003B51C0 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern f32 func_L01_0040E570(void *a, void *b);
extern s32 func_00382498(s32 a, s32 b);

u8 *func_L23_003B51C0(u8 *object, u8 *skip, f32 radius) {
    u8 *list[64];
    s32 n = 0;
    u16 *p;
    u8 *e;
    if (object == 0)
        return 0;
    {
        p = D_L23_0021C0E0[object[0x21]];
        while (object[0x21] != 0xFF && object[0x21] <= D_L23_001DF198 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[object[0x21]])) {
            e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (n < 0x40 && e != skip && e[0x20] < 3 && func_L01_0040E570(object + 0x10, e + 0x10) < radius) {
                list[n++] = e;
            }
            p++;
        }
    }
    if (n > 0)
        return list[func_00382498(0, n - 1)];
    return 0;
}
/* localdecomp:end func_L23_003B51C0 */

INCLUDE_ASM("asm/levels", func_L23_003B5318);

INCLUDE_ASM("asm/levels", func_L23_003B54A0);

INCLUDE_ASM("asm/levels", func_L23_003B5538);

INCLUDE_ASM("asm/levels", func_L23_003B5628);

/* localdecomp:start func_L23_003B5760 */
extern void func_L23_003B67B0(void *owner, void *p, int z, float f, float g);

void func_L23_003B5760(unsigned char *owner)
{
    func_L23_003B67B0(owner, owner + 0x10, 0, *(float *)(owner + 0xF8), 0.0f);
}
/* localdecomp:end func_L23_003B5760 */

/* localdecomp:start func_L23_003B5788 */
extern void func_L23_003B67B0(void *, void *, int, float, float);

void func_L23_003B5788(char *obj, float x) {
    func_L23_003B67B0(obj, *(char **)(obj + 0x68) + 0x320, 3, *(float *)(obj + 0xF8), x);
}
/* localdecomp:end func_L23_003B5788 */

INCLUDE_ASM("asm/levels", func_L23_003B57B8);

INCLUDE_ASM("asm/levels", func_L23_003B6390);

INCLUDE_ASM("asm/levels", func_L23_003B65F0);

INCLUDE_ASM("asm/levels", func_L23_003B67B0);

INCLUDE_ASM("asm/levels", func_L23_003B6990);

/* localdecomp:start func_L23_003B6A80 */
void func_0038CAD0(s32);

void func_L23_003B6A80(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CAD0(temp_s0 + 0x2C0);
    func_0038CAD0(temp_s0 + 0x2C4);
    func_0038CAD0(temp_s0 + 0x300);
}
/* localdecomp:end func_L23_003B6A80 */

INCLUDE_ASM("asm/levels", func_L23_003B6AD0);

/* localdecomp:start func_L23_003B6C90 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern void func_L01_004450F0(void *a0, s32 a1, s32 a2);

void func_L23_003B6C90(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L23_0021C0E0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L23_001DF198 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[a0[0x21]])) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && a0[0x95] == 2) {
            func_L01_004450F0(e, 6, 3);
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B6C90 */

/* localdecomp:start func_L23_003B6D78 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
__asm__(".extern D_L23_001DF198, 16");
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B6D78(s32 a0) {
    u16 *p;
    u8 *e;

    p = D_L23_0021C0E0[a0];
    if ((a0 & 0xFF) == 0xFF || a0 > D_L23_001DF198 || p == 0) {
        return;
    }
    for (;;) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && e[0x95] == 1) {
            func_L01_004450F0(e, 4, 2);
        }
        p++;
        if ((a0 & 0xFF) == 0xFF) {
            return;
        }
        if (a0 > D_L23_001DF198) {
            return;
        }
        if (p == 0) {
            return;
        }
        if ((s16)p[-1] >= 0) {
            continue;
        }
        if (p == D_L23_0021C0E0[a0]) {
            continue;
        }
        return;
    }
}
/* localdecomp:end func_L23_003B6D78 */
