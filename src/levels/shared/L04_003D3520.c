#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003D3520);

INCLUDE_ASM("asm/levels", func_L04_003D37F8);

INCLUDE_ASM("asm/levels", func_L04_003D3A30);

/* localdecomp:start func_L04_003D3AC8 */
typedef void (*Fn_003CF2A0)(u8 *);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);
typedef struct { u8 pad0[0x10]; s32 w10; } Q_3D3AC8;
typedef struct { u8 pad0[0x24]; Q_3D3AC8 *w24; u8 pad28[0x98 - 0x28]; s32 w98; } R_3D3AC8;
typedef struct {
    u8 pad0[0x19E0];
    s32 w19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    R_3D3AC8 *w25C0;
    u8 pad25C4[0x25E5 - 0x25C4];
    u8 b25E5;
} G_3D3AC8;
typedef struct { u8 pad0[0x20]; u8 b20; u8 padBC[0xBC - 0x21]; u8 bBC; } M_3D3AC8;
extern G_3D3AC8 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern void func_L01_003EB5E0(s32, s32);
extern void func_L04_003D3EE0(void);
extern void func_L04_0050CB28(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
void func_L04_003D3AC8(M_3D3AC8 *m) {
    u8 t = m->b20;
    if (t == 2) {
        func_L01_003EB5E0(0, 0);
        func_L04_003D3EE0();
        D_001A4BE0.w25C0->w98 = D_001A4BE0.w25C0->w24->w10;
        D_001A4BE0.b25E5 = 0;
        func_L04_0050CB28(0, 1);
        D_001A4BE0.w19E0 = 0;
        m->bBC = t;
        func_L01_004450F0(m, 1, -1);
        func_L01_00456230(m, 0);
        func_003C3A10(m, 0, 0, 1);
    }
    (*func_L01_0043B548(0x19E1, 0x6C))((u8 *)m);
}
/* localdecomp:end func_L04_003D3AC8 */

INCLUDE_ASM("asm/levels", func_L04_003D3B90);

/* localdecomp:start func_L04_003D3EE0 */
extern void func_L01_00517918(s32);
void func_L04_003D3EE0(void) {
    func_L01_00517918(13);
}
/* localdecomp:end func_L04_003D3EE0 */

/* localdecomp:start func_L04_003D3F00 */
extern f32 D_L04_001DEC04;
extern f32 D_L04_001DEBF8;
extern void func_L01_00517538(s32 a0, f32 a1, f32 a2);

void func_L04_003D3F00(void *a0, u8 *a1)
{
    f32 t = *(f32 *)(a1 + 48) / (f32)*(s16 *)(a1 + 52);

    func_L01_00517538(0x490004, D_L04_001DEC04 * t, D_L04_001DEBF8);
    func_L01_00517538(0x490005, D_L04_001DEC04 * t, D_L04_001DEBF8);
}
/* localdecomp:end func_L04_003D3F00 */

INCLUDE_ASM("asm/levels", func_L04_003D3F68);
