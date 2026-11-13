#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003D3388 */
typedef struct { u8 pad[0x25C0]; u8 *x25C0; } H_3D3388;
typedef struct { u8 pad[0x5C4]; u16 x5C4; u16 x5C6; u32 x5C8; } G_3D3388;
extern H_3D3388 D_001A4BE0;
extern G_3D3388 D_001A7E18;
extern u8 D_00142CC3[];
extern s32 D_00142660[];
extern u8 *D_001A71A0[];
__asm__(".extern D_001D4C38, 4");
extern s32 D_001D4C38;
__asm__(".extern D_001D52FC, 4");
extern u8 *D_001D52FC;
__asm__(".extern D_L19_001DEC60, 4");
extern f32 D_L19_001DEC60;
__asm__(".extern D_L19_001DEC64, 4");
extern f32 D_L19_001DEC64;
extern u8 *D_L19_001DF71C;
extern u8 D_L19_001DEC68[];
extern u8 D_L19_001DEC70[];
extern u8 D_L19_001DEC80[];
extern u8 D_L19_001DEC90[];
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_00452658(s32, s32);
extern s32 func_L19_004438B0(u8 *);
extern void func_L01_004366A0(void *, s32);

void func_L19_003D3388(u8 *obj) {
    vu0_v4 d;
    f32 dot;
    f32 top;
    f32 dist;
    G_3D3388 *g;
    u32 n;
    s32 s;

    switch (obj[0x20]) {
    case 0:
        if (D_00142CC3[0] != 0)
            *(u16 *)(obj + 0x7C) &= ~1;
        else
            *(u16 *)(obj + 0x7C) |= 1;
        obj[0x95] = 0;
        *(u16 *)(obj + 0x96) = 0;
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (D_00142CC3[0] != 0) {
            *(u16 *)(obj + 0x7C) &= ~1;
            break;
        }
        if ((obj[0x7C] ^ 1) & 1) {
            func_L01_004450F0(obj, 3, -1);
            break;
        }
        vec_sub_ab(&d, obj + 0x10, D_001A4BE0.x25C0 + 0x10);
        dot = func_0038CE68(&d, D_001A4BE0.x25C0 + 0xC0);
        top = *(f32 *)(obj + 0x18) + D_L19_001DEC60;
        dist = func_0038CF38(obj + 0x10, D_001A4BE0.x25C0 + 0x10);
        if (0.0f < dot && *(f32 *)(D_001A4BE0.x25C0 + 0x18) <= top && dist < D_L19_001DEC64) {
            g = &D_001A7E18;
            if (g->x5C4 != 0) {
                n = (D_001D4C38 * 5 + 2) / 6;
                if (g->x5C8 + g->x5C6 >= n - 2) {
                    g->x5C6 = g->x5C6 + 1;
                    if (g->x5C6 >= 3000) {
                        func_L01_0041A5B0(0xCD1, 0x7B);
                        g->x5C6 = 0;
                    }
                } else {
                    if (g->x5C8 < n)
                        g->x5C8 = n;
                    g->x5C6 = 0;
                }
            } else {
                func_L01_0041A5B0(0xCD1, 0x7B);
            }
            if (D_00142660[0] >= 250000) {
                if (func_L01_00452560(0, 0, 0xF02, 1, 0, 0, 0) != 0 && (*(u32 *)(D_001D52FC + 0x1A4) & 0x10)) {
                    func_L01_00456230(D_L19_001DF71C + (**(s32 **)(obj + 0x68) << 8), 1);
                    *(u16 *)(obj + 0x7C) &= ~1;
                    func_L01_00452658(0, 0);
                    func_L01_004450F0(obj, 3, -1);
                    D_00142660[0] -= 250000;
                }
            } else {
                func_L01_00452560(0, 0, 0xF03, 1, 0, 0, 0);
            }
        }
        break;
    case 2:
        break;
    }
    if (func_L19_004438B0(obj) != 0) {
        if (D_001A71A0[0][0x42] == 13)
            s = 1;
        else
            s = (*(u32 *)(D_001D52FC + 0x1A0) & 0x40) ? 2 : 0;
        if (s != obj[0x95]) {
            obj[0x95] = s;
            *(u16 *)(obj + 0x96) = 0;
        } else if (s != 0) {
            *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
        }
        if (*(u16 *)(obj + 0x96) == 7500) {
            if (obj[0x95] == 1)
                func_L01_004366A0(D_L19_001DEC68, 100);
            else if (obj[0x95] == 2)
                func_L01_004366A0(D_L19_001DEC70, 100);
        } else if (*(u16 *)(obj + 0x96) == 9000) {
            if (obj[0x95] == 1)
                func_L01_004366A0(D_L19_001DEC80, 100);
            else if (obj[0x95] == 2)
                func_L01_004366A0(D_L19_001DEC90, 100);
            *(u16 *)(obj + 0x96) = 0;
        }
    } else {
        *(u16 *)(obj + 0x96) = 0;
    }
}
/* localdecomp:end func_L19_003D3388 */
