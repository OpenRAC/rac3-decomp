#include "common.h"

typedef struct { u8 pad[0x60]; u8 x60; } V_3D6A28;
typedef struct { u8 pad[0x68]; V_3D6A28 *x68; } M_3D6A28;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_3D6A28 *x18C; } B_3D6A28;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_3D6A28;

typedef struct { s32 x0; f32 x4; s32 x8; f32 xC; u8 pad10[0x20 - 0x10]; s32 x20; s32 x24; u8 pad28[0x3C - 0x28]; s32 x3C; u8 pad40[0x54 - 0x40]; s32 x54; } Src_003D9000;
typedef struct { u8 pad[0x68]; Src_003D9000 *x68; } Req_003D9000;
typedef struct { u8 pad[0x160]; f32 x160; s32 x164; f32 x168; s32 x16C; s32 x170; s32 x174; u8 pad178[0x180 - 0x178]; s32 x180; s32 x184; } Dst_003D9000;
typedef struct { u8 pad[0x68]; Dst_003D9000 *x68; } Obj_003D9000;

INCLUDE_ASM("asm/levels", func_L12_003D7BE8);

INCLUDE_ASM("asm/levels", func_L12_003D84A0);

/* localdecomp:start func_L12_003D8808 */
extern void func_L01_0044ABD0(O_3D6A28 *, void *);
extern s32 func_L01_00452FB0(O_3D6A28 *, void *, s32, s32, s32);
extern void func_L12_003D88C8(O_3D6A28 *, B_3D6A28 *);
extern void func_L01_00456BD0(O_3D6A28 *, s32);
s32 func_L12_003D8808(O_3D6A28 *a0, B_3D6A28 *a1) {
    if (a1->x18C != 0 && a1->x18C->x68->x60 != 0) {
        func_L01_0044ABD0(a0, a1->x70);
        a0->xA8 = 255;
    } else {
        s32 r = func_L01_00452FB0(a0, a1->x70, 0, 0, 0);
        if (r != 0) {
            if (r == 4 || r == 5) {
                func_L12_003D88C8(a0, a1);
                return 0;
            }
        }
    }
    if (a1->x170 != 0) {
        func_L01_00456BD0(a0, 1);
    } else {
        func_L01_00456BD0(a0, 3);
    }
    return 1;
}
/* localdecomp:end func_L12_003D8808 */

INCLUDE_ASM("asm/levels", func_L12_003D88C8);

INCLUDE_ASM("asm/levels", func_L12_003D89F8);

INCLUDE_ASM("asm/levels", func_L12_003D8B20);

INCLUDE_ASM("asm/levels", func_L12_003D8C30);

INCLUDE_ASM("asm/levels", func_L12_003D8DB8);

/* localdecomp:start func_L12_003D9000 */
extern void func_003C3938(void *a0, s32 a1, s32 a2);

void func_L12_003D9000(Obj_003D9000 *a0, Req_003D9000 *a1) {
    Dst_003D9000 *d = a0->x68;
    Src_003D9000 *s = a1->x68;
    d->x164 = s->x0;
    if (0.0f < s->x4) {
        d->x160 = s->x4;
    }
    d->x16C = s->x8;
    if (0.0f < s->xC) {
        d->x168 = s->xC;
    }
    d->x170 = s->x3C;
    d->x174 = s->x54;
    d->x180 = s->x20;
    d->x184 = s->x24;
    func_003C3938(a0, 1, 0);
}
/* localdecomp:end func_L12_003D9000 */
