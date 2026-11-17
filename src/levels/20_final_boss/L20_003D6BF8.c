#include "common.h"

/* localdecomp:start func_L20_003D6BF8 */
extern void func_003C2880(void *);
extern void func_L01_003F2AF8(s32, s32);
extern s32 func_0039EC28(s32, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern u8 D_0014270F __attribute__((section(".data")));
extern s32 D_001D545C;
extern s32 D_L20_001DEBF0;
__asm__(".extern D_L20_001DEBF0, 4");
extern s32 D_L20_001DFD40;
void func_L20_003D6BF8(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);

    if (*(s32 *)(p + 0x2F8) != 0) {
        func_003C2880(*(void **)(p + 0x2F8));
        *(s32 *)(p + 0x2F8) = 0;
    }
    if (*(s32 *)(p + 0x2FC) != 0) {
        func_003C2880(*(void **)(p + 0x2FC));
        *(s32 *)(p + 0x2FC) = 0;
    }
    if (*(u8 **)(p + 0x618) != 0)
        *(s32 *)(*(u8 **)(p + 0x618) + 0x98) = 0;
    if (*(u8 **)(p + 0x67C) != 0)
        *(s32 *)(*(u8 **)(p + 0x67C) + 0x98) = 0;
    if (*(s32 *)(p + 0x648) != 0) {
        func_L01_003F2AF8(0, *(s32 *)(p + 0x644));
        *(s32 *)(p + 0x648) = 0;
    }
    D_0014270F = 1;
    D_L20_001DEBF0 = 1;
    func_0039EC28(0, D_001D545C);
    if (D_L20_001DFD40 > 100)
        func_L01_0045F1E8(*(s32 *)(p + 0x668), *(s32 *)(p + 0x66C));
    else
        func_L01_0045F1E8(*(s32 *)(p + 0x668), -1);
    if (D_L20_001DFD40 >= 6 || (*(unsigned long *)(a0 + 0xB0) & 0xFFFFFFFF00000000UL) == 0)
        func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L20_003D6BF8 */

/* localdecomp:start func_L20_003D6D18 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern u8 D_L20_001E2E80[];

void func_L20_003D6D18(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    func_0038CAD0(v + 0x2D0);
    func_0038CB00(v + 0x2D4);
    func_0038CAD0(v + 0x664);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_00451DF8(a0, v + 0x240, 10, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L20_001E2E80, a0 + 0x10) < 8100.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x54;
        }
    }
    func_L01_0044E850(a0, v + 0x330, 4, 0.0432f, 0.43200004f);
    func_L01_0044E850(a0, v + 0x3B0, 5, 0.0432f, 0.43200004f);
    func_L01_0044E850(a0, v + 0x430, 6, 0.0432f, 0.43200004f);
    func_L01_0044E850(a0, v + 0x4B0, 7, 0.0432f, 0.43200004f);
    func_L01_0044E850(a0, v + 0x530, 8, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L20_003D6D18 */
