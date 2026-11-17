#include "common.h"

typedef struct { u8 pad0[0x98]; s32 f98; } Slot_3626F0;

/* localdecomp:start func_L04_00362568 */
typedef struct {
    u8 pad0[0x47];
    u8 b47;
    u8 *p48;
} S_362568;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_L04_001D67AC_00362568;
__asm__(".extern D_L04_001D67AC_00362568, 4");
extern s32 D_L04_001D67AC;
__asm__(".extern D_L04_001D67AC, 16");
extern s32 D_L04_001D67B4_00362568;
__asm__(".extern D_L04_001D67B4_00362568, 4");
extern s32 D_L04_001D67B4;
__asm__(".extern D_L04_001D67B4, 16");
extern s32 D_L04_001D67C0_00362568;
__asm__(".extern D_L04_001D67C0_00362568, 4");
extern s32 D_L04_001D67C0;
__asm__(".extern D_L04_001D67C0, 16");
extern s32 D_L04_001DD6C8;
__asm__(".extern D_L04_001DD6C8, 4");
extern void func_L01_00459C50(s32);
extern void func_003C2880(s32);
extern void func_L01_004443E8(u8 *, s32, s32);
void func_L04_00362568(u8 *a0) {
    S_362568 *s = *(S_362568 **)(a0 + 0x68);
    if (s == 0) {
        return;
    }
    if (D_001D545C_sda == 4 && s->p48 != 0 && (*(s16 *)(s->p48 + 0xAA) == 0x185E || *(s16 *)(s->p48 + 0xAA) == 0x11C1)) {
        D_L04_001D67AC_00362568 = D_L04_001D67AC + 1;
        if (D_L04_001D67AC_00362568 >= 0x19) {
            func_L01_00459C50(6);
        }
    } else if (D_001D545C_sda == 0xC && s->p48 != 0 && s->b47 == 9) {
        D_L04_001D67B4_00362568 = D_L04_001D67B4 + 1;
        if (D_L04_001D67B4_00362568 >= 0x14) {
            func_L01_00459C50(0xF);
        }
    } else if (D_001D545C_sda == 0x12 && s->p48 != 0 && (*(s16 *)(s->p48 + 0xAA) == 0x185E || *(s16 *)(s->p48 + 0xAA) == 0x11C1)) {
        D_L04_001D67C0_00362568 = D_L04_001D67C0 + 1;
        if (D_L04_001D67C0_00362568 >= 0x14) {
            func_L01_00459C50(0x15);
        }
    }
    if (*(s32 *)((u8 *)s + 0x2FC) != 0) {
        func_003C2880(*(s32 *)((u8 *)s + 0x2FC));
        *(s32 *)((u8 *)s + 0x2FC) = 0;
        *(s32 *)((u8 *)s + 0x240) = 0;
    }
    if (*(s32 *)((u8 *)s + 0x4F8) != 0 && s->b47 == 0x6F) {
        D_L04_001DD6C8++;
        if (D_L04_001DD6C8 >= 10) {
            func_L01_00459C50(0xD);
        }
    }
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L04_00362568 */

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

/* localdecomp:start func_L04_00362B98 */
extern u8 *func_L01_00449050(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L04_00362B98(u8 *a0, u8 *a1) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *r = func_L01_00449050(a0, a1);
    u8 *c = *(u8 **)(a1 + 0x68);
    u8 *x = *(u8 **)(*(u8 **)(r + 8) + 0x68);
    f32 f;
    v[0x25D] = c[0x80];
    *(s32 *)(v + 0x2E0) = *(s32 *)(c + 0x0);
    f = *(f32 *)(c + 0x4);
    if (f > 0.0f) {
        *(f32 *)(v + 0x2E4) = f;
    }
    *(s32 *)(v + 0x2E8) = *(s32 *)(c + 0x8);
    f = *(f32 *)(c + 0xC);
    if (f > 0.0f) {
        *(f32 *)(v + 0x2EC) = f;
    }
    *(s32 *)(v + 0x300) = *(s32 *)(c + 0x14);
    *(s32 *)(v + 0x304) = *(s32 *)(c + 0x20);
    *(s32 *)(v + 0x38C) = *(s32 *)(c + 0x68);
    *(s32 *)(v + 0x308) = *(s32 *)(c + 0x24);
    *(s32 *)(v + 0x30C) = *(s32 *)(c + 0x10);
    *(s32 *)(v + 0x310) = *(s32 *)(c + 0x28);
    *(s32 *)(v + 0x314) = *(s32 *)(c + 0x2C);
    *(s32 *)(v + 0x318) = *(s32 *)(c + 0x1C);
    *(s32 *)(v + 0x31C) = *(s32 *)(c + 0x18);
    *(s32 *)(v + 0x4D0) = *(s32 *)(c + 0x74);
    *(s32 *)(v + 0x4D4) = *(s32 *)(c + 0x78);
    *(s32 *)(v + 0x500) = *(s32 *)(c + 0x88);
    *(s32 *)(v + 0x374) = *(s32 *)(x + 0x78);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
}
/* localdecomp:end func_L04_00362B98 */
