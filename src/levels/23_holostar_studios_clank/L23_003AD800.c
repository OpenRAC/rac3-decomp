#include "common.h"
typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L23_003AD800);

INCLUDE_ASM("asm/levels", func_L23_003AF6E8);

/* localdecomp:start func_L23_003AF9B8 */
__asm__(".extern D_L23_001DE244, 4");
__asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE244;
extern f32 D_L23_001DE248;
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AF9B8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);

    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    *(f32 *)(v + 0x40) = 1.0f;
    v[0x39] = 0;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 0x4B;
        *(f32 *)(v + 0x30) = 75.0f;
    }
    if (*(s32 *)(v + 0x220) != 0) {
        *(f32 *)(v + 0x30) *= D_L23_001DE244;
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x30);
    }
    *(f32 *)(v + 0x70) = D_L23_001DE248;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0x74) = *(f32 *)(v + 0x70);
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.5f;
    *(f32 *)(v + 0x80) = 1.4835298f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    *(V4 *)(v + 0x250) = *(V4 *)(self + 0x10);
    *(V4 *)(v + 0x290) = *(V4 *)(self + 0x10);
    *(f32 *)(v + 0x24C) = *(f32 *)(self + 0xF8);
    *(s32 *)(v + 0x218) = 0;
    *(s32 *)(v + 0x244) = 0;
    *(s32 *)(v + 0x21C) = 0;
    *(s32 *)(v + 0x240) = 0;
    *(s32 *)(v + 0x228) = 0;
    *(s32 *)(v + 0x2BC) = 0;
    *(s32 *)(v + 0x210) = 0;
    if (self[0x21] != 0xFF)
        func_L01_004450F0(self, 1, 0);
    else
        func_L01_004450F0(self, 4, 2);
}
/* localdecomp:end func_L23_003AF9B8 */

INCLUDE_ASM("asm/levels", func_L23_003AFAF0);

INCLUDE_ASM("asm/levels", func_L23_003AFC40);

INCLUDE_ASM("asm/levels", func_L23_003AFE10);

/* localdecomp:start func_L23_003B0010 */
extern void func_L01_004450F0(void *, s32, s32);
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
extern s32 D_L23_001DF198;

void func_L23_003B0010(s32 idx) {
    u16 *p;
    u8 *e;

    if (idx < 0) {
        return;
    }
    p = D_L23_0021C0E0[idx];
    while ((idx & 0xFF) != 0xFF && idx <= D_L23_001DF198 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[idx])) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        if (e[0x20] == 1) {
            func_L01_004450F0(e, 2, 1);
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B0010 */

/* localdecomp:start func_L23_003B0110 */
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0045A748(void *, void *);
extern void func_L23_003B0200(u8 *, s32, V4 *, u8 *, u8 *, s32);

s32 func_L23_003B0110(u8 *m, V4 *target, s32 mode, f32 speed) {
    u8 *v = *(u8 **)(m + 0x68);
    V4 pos;
    f32 before;
    f32 after;
    if (mode == 0) {
        func_L01_0045AA10(m, speed);
        func_L01_0045BD10(m, speed);
        return 1;
    }
    pos = *target;
    func_L23_003B0200(m, *(s32 *)(v + 0x23C), &pos, v + 0x280, v + 0x248, 0);
    before = func_L01_0040E570(&pos, m + 0x10);
    func_L01_0045A748(m, &pos);
    after = func_L01_0040E570(&pos, m + 0x10);
    return !(before > 1.0f && __builtin_fabsf(after - before) < 0.01f);
}
/* localdecomp:end func_L23_003B0110 */

INCLUDE_ASM("asm/levels", func_L23_003B0200);

INCLUDE_ASM("asm/levels", func_L23_003B0480);

INCLUDE_ASM("asm/levels", func_L23_003B0708);

/* localdecomp:start func_L23_003B08E0 */
void func_0038CAD0(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B08E0(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    func_0038CAD0(temp_s1 + 0x214);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L23_003B08E0 */

/* localdecomp:start func_L23_003B0978 */
extern u8 *func_003C24B0(s32, s32);
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");

u8 *func_L23_003B0978(s32 a0, u128_t *pos, u128_t *target, s32 a3, s32 a4, s32 a5) {
    u8 *m = func_003C24B0(0x1BC8, 0x80);
    u8 *v;

    if (m != 0) {
        m[0x20] = 0;
        m[0x30] = 0xFF;
        v = *(u8 **)(m + 0x68);
        *(u128_t *)(m + 0x10) = *pos;
        *(u128_t *)(v + 0x10) = *target;
        *(s32 *)(v + 0) = a3;
        *(s32 *)(v + 4) = a0;
        *(s32 *)(v + 8) = D_L23_001DEC40 + 150;
        *(s32 *)(v + 0xC) = a5;
    }
    return m;
}
/* localdecomp:end func_L23_003B0978 */

INCLUDE_ASM("asm/levels", func_L23_003B0A20);

INCLUDE_ASM("asm/levels", func_L23_003B0CE0);

INCLUDE_ASM("asm/levels", func_L23_003B0EC0);

/* localdecomp:start func_L23_003B1230 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];

s32 func_L23_003B1230(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CCC)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003B1230 */

INCLUDE_ASM("asm/levels", func_L23_003B12C8);

/* localdecomp:start func_L23_003B1418 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
__asm__(".extern D_L23_001DE2B0, 8");
__asm__(".extern D_L23_001DE2C0, 4");
__asm__(".extern D_L23_001DE2C4, 4");
__asm__(".extern D_L23_001DE2C8, 4");
extern f32 D_L23_001DE2B0[2];
extern s32 D_L23_001DE2C0;
extern u32 D_L23_001DE2C4;
extern f32 D_L23_001DE2C8;

void func_L23_003B1418(void *arg0) {
    V4 v;
    f32 *p;

    p = *(f32 **)((u8 *)arg0 + 0x68);
    if (p != 0) {
        func_0038CE20(&v, D_L23_001DE2B0, p[1]);
        vec_add_ba(&v, &v, (u8 *)arg0 + 0x10);
        func_003D9508(&v, D_L23_001DE2C0, D_L23_001DE2C4, 1, D_L23_001DE2C8, 0.3f, 0.0f);
    }
}
/* localdecomp:end func_L23_003B1418 */

INCLUDE_ASM("asm/levels", func_L23_003B1490);

INCLUDE_ASM("asm/levels", func_L23_003B34F8);

/* localdecomp:start func_L23_003B3908 */
void func_0038CAD0(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B3908(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 9216.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x5A;
    }
    *(u16 *)((u8 *)arg0 + 0x96) = (u16) ((*(u16 *)((u8 *)arg0 + 0x96)) + 1);
    *(s32 *)((u8 *)temp_s1 + 0x31C) = (s32) ((*(s32 *)((u8 *)temp_s1 + 0x31C)) + 1);
    func_0038CAD0(temp_s1 + 0x330);
}
/* localdecomp:end func_L23_003B3908 */

INCLUDE_ASM("asm/levels", func_L23_003B3998);
