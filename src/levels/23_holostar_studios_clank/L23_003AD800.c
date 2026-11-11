#include "common.h"
typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L23_003AD800);

INCLUDE_ASM("asm/levels", func_L23_003AF6E8);

INCLUDE_ASM("asm/levels", func_L23_003AF9B8);

INCLUDE_ASM("asm/levels", func_L23_003AFAF0);

INCLUDE_ASM("asm/levels", func_L23_003AFC40);

INCLUDE_ASM("asm/levels", func_L23_003AFE10);

INCLUDE_ASM("asm/levels", func_L23_003B0010);

INCLUDE_ASM("asm/levels", func_L23_003B0110);

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

INCLUDE_ASM("asm/levels", func_L23_003B1418);

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
