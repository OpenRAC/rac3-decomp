#include "common.h"

typedef struct { u8 pad0[0x98]; s32 f98; } Slot_3626F0;

INCLUDE_ASM("asm/levels", func_L04_00362568);

/* localdecomp:start func_L04_003626F0 */
extern void func_0038CAD0(void *p);
extern void func_0038CB00(void *p);
extern void func_003C7C38(void *p);
extern void func_L01_00451DF8(void *a, void *b, s32 c, s32 d, f32 e);
extern void func_L01_0044E850(void *a, void *b, s32 c, f32 d, f32 e);

void func_L04_003626F0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    Slot_3626F0 **p = (Slot_3626F0 **)(s + 0x4B0);
    s32 i;
    func_0038CAD0(s + 0x2F0);
    func_0038CB00(s + 0x2F4);
    for (i = 7; i >= 0; i--) {
        if (*p != 0) {
            (*p)->f98 = 0;
            func_003C7C38(*p);
        }
        p++;
    }
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_00451DF8(a0, s + 0x260, 2, 1, 2.5f);
    func_L01_0044E850(a0, s + 0x390, 1, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L04_003626F0 */

/* localdecomp:start func_L04_003627C8 */
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;
extern void func_L01_00445BE0(s32 a, s32 b);

void func_L04_003627C8(u8 *object) {
    u16 *p;
    u8 *e;
    s16 t;
    if (object[0x21] == 0xFF)
        return;
    func_L01_00445BE0(object[0x21], 0);
    p = D_L04_0021C9A0[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L04_001DFDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[object[0x21]])) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        t = *(s16 *)(e + 0xAA);
        if (t == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2F8) = 1;
        else if (t == 0x16BD)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2E8) = 1;
        else if (t == 0x1B39)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x3E4) = 1;
        p++;
    }
}
/* localdecomp:end func_L04_003627C8 */

INCLUDE_ASM("asm/levels", func_L04_003628D8);

INCLUDE_ASM("asm/levels", func_L04_003629A8);

/* localdecomp:start func_L04_00362B88 */
void func_L04_00362B88(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x378) = 0;
}
/* localdecomp:end func_L04_00362B88 */

INCLUDE_ASM("asm/levels", func_L04_00362B98);
