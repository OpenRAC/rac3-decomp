#include "common.h"

/* NTSC-U counterpart of func_L40_003D9530 (src/levels/shared/L40_003D88A8.c): 8 -> 10 */
extern void func_L39_005F08F8(void *, s32);
extern void func_L40_003D9328(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L40_0053CE30(void *);
extern void func_L39_005F08F8(void *, s32);
extern void *D_L40_003575EC[];

/* localdecomp:start func_L40_003D9328 */
typedef struct { u8 pad[0x88]; s32 a[1]; } S_003D9530;
extern void *D_L40_003575EC[];
extern void func_L40_003D9168(u8 *, u8 *, s32);
extern void func_L40_0053CE30(void *);
extern void func_L39_00669B68(s32);
extern void func_L39_005F08F8(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00451078(void *, void *);

void func_L40_003D9328(u8 *a0) {
    u8 *r;
    u8 *m;
    s32 v;

    r = *(u8 **)(a0 + 0x68);
    m = *(u8 **)(a0 + 0x90);
    v = *(s32 *)m;
    *(s32 *)(m + 0x18) = ((S_003D9530 *)D_L40_003575EC[0])->a[*(s32 *)(r + 0x1A0)];
    func_L40_003D9168(a0, r, v);
    if (r[0x3E] == 2) {
        func_L40_0053CE30(a0);
        func_L39_00669B68(v);
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(a0, 1);
        func_L01_00441FB8(a0, 0x25, -1);
    }
    switch (a0[0x20]) {
    case 2:
        if (func_L01_00452EC8(a0) != 0 && a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 10);
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    case 1:
        if (func_L01_00452EC8(a0) != 0 && a0[0x43] != 0) {
            func_003BE4F0(a0, 0, 0, 10);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0) != 0 && a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, 10);
        }
        if (func_L01_00451078(a0, r + 0xE0) & 2) {
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L40_003D9328 */
