#include "common.h"

typedef struct { u8 pad[0x60]; u8 x60; } V_3D6A28;
typedef struct { u8 pad[0x68]; V_3D6A28 *x68; } M_3D6A28;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_3D6A28 *x18C; } B_3D6A28;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_3D6A28;

typedef struct { s32 x0; f32 x4; s32 x8; f32 xC; u8 pad10[0x20 - 0x10]; s32 x20; s32 x24; u8 pad28[0x3C - 0x28]; s32 x3C; u8 pad40[0x54 - 0x40]; s32 x54; } Src_003D9000;
typedef struct { u8 pad[0x68]; Src_003D9000 *x68; } Req_003D9000;
typedef struct { u8 pad[0x160]; f32 x160; s32 x164; f32 x168; s32 x16C; s32 x170; s32 x174; u8 pad178[0x180 - 0x178]; s32 x180; s32 x184; } Dst_003D9000;
typedef struct { u8 pad[0x68]; Dst_003D9000 *x68; } Obj_003D9000;

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

/* localdecomp:start func_L12_003D88C8 */
/* from the NTSC-U draft nonmatching/levels/func_L12_003D88C8.c (func_L12_003D6AE8), with PAL names */
extern s32 D_L12_001DF0DC;
__asm__(".extern D_L12_001DF0DC, 4");
extern f32 D_L12_001DF0E0;
__asm__(".extern D_L12_001DF0E0, 4");
extern u8 D_L12_001E2780[];
extern u8 D_L12_001D6700[8];
__asm__(".extern D_L12_001D6700, 16");
extern void func_L07_003D89A8(void *, f32, f32, f32, f32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L12_003D88C8(O_3D6A28 *a0, B_3D6A28 *a1) {
    f32 f;
    s32 i;
    u8 *p;

    f = *(f32 *)((u8 *)a0 + 0x2C) / *(f32 *)(*(u8 **)((u8 *)a0 + 0x24) + 0x24);
    for (i = 0; i < D_L12_001DF0DC; i++) {
        func_L07_003D89A8(a0, 0.0f, D_L12_001DF0E0, 1.5f, f, 5, 0x32, 4);
    }
    p = D_L12_001E2780;
    *(s32 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x28) = 0x25;
    *(f32 *)(p + 0x20) = 1.5f;
    func_003A52A0(1, 0, a0);
    func_L01_00451FE0(a0, 0x1FF, D_L12_001D6700, 3.0f, 7.0f, 3.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L12_003D88C8 */

/* localdecomp:start func_L12_003D89F8 */
/* from rac3-decomp's func_L01_003BDC88 (same loop) */
typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} V_003D89F8;
extern u8 *D_L12_001DFD1C;
__asm__(".extern D_L12_001DFD1C, 16");
extern s16 *D_L12_0021DB60[];
extern void func_L01_0044EA78(u8 *, u8 *);
extern void func_L01_0043B840(s32, u8 *);
extern void func_003C2880(void *);
extern s32 func_L01_0043B930(s32);
extern void *func_L01_0043B548(s32, s32);

void func_L12_003D89F8(u8 *a0, s32 flag) {
    u8 *v = *(u8 **)(a0 + 0x68);
    V_003D89F8 *t;

    func_L01_0044EA78(a0, v + 0x1A0);
    func_L01_0044EA78(a0, v + 0x220);
    if (*(s32 *)(v + 0x188) != -1) {
        while (!func_L01_0043B930(*(s32 *)(v + 0x188))) {
            u8 *r = D_L12_001DFD1C + ((*D_L12_0021DB60[*(s32 *)(v + 0x188)] & 0x7FFF) << 8);
            func_L01_0043B840(*(s32 *)(v + 0x188), r);
            func_003C2880(r);
        }
        *(s32 *)(v + 0x188) = -1;
    }
    if (*(void **)(v + 0x18C) != 0) {
        func_003C2880(*(void **)(v + 0x18C));
        *(void **)(v + 0x18C) = 0;
    }
    if (*(s32 *)(v + 0x150) != 0) {
        t = func_L01_0043B548(0x19E1, 0x6C);
        t->f0(a0);
        if (flag) {
            t->f4(a0);
        }
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L12_003D89F8 */

/* localdecomp:start func_L12_003D8B20 */
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L12_003D8B20(void *a0, Dst_003D9000 *a1, s32 a2) {
    if (a1->x170 != 0) {
        if (a2 != 0) {
            func_L01_00456C98(a0, a1->x164, 0, 0, 1, 1, 3, 0, 0, 0, a1->x168, a1->x160 + a1->x160, 1.0f);
        } else {
            func_L01_00456C98(a0, a1->x16C, 0, 0, 1, 1, 3, 0, 0, 0, a1->x160, a1->x168 + a1->x168, 1.0f);
        }
    } else {
        if (a2 != 0) {
            func_L01_00456C98(a0, a1->x164, 0, 0, 0, 1, 1, 0, 0, 0, a1->x168, a1->x160 + a1->x160, 1.0f);
        } else {
            func_L01_00456C98(a0, a1->x16C, 0, 0, 0, 1, 1, 0, 0, 0, a1->x160, a1->x168 + a1->x168, 1.0f);
        }
    }
}
/* localdecomp:end func_L12_003D8B20 */
