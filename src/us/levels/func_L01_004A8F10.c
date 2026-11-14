#include "common.h"

/* NTSC-U counterpart of func_L01_004AC900 (src/levels/shared/L01_004AC1C0.c) */
/* localdecomp:start func_L01_004A8F10 */
typedef struct { u8 pad0[0x34]; u16 h34; } Obj_4A8F10;
typedef struct {
    Obj_4A8F10 *obj;
    u8 pad4[4];
    s32 w8;
    u8 padC[0x14];
    s16 h20;
    s16 h22;
    u8 pad24[6];
    s16 h2A;
    u8 pad2C[0x40];
    s32 w6C;
} St_4A8F10;
typedef struct { u8 pad0[0x68]; s32 w68; s32 w6C; } Buf_4A8F10;
typedef struct { u8 pad0[0xC]; s32 wC; s32 w10; } Tab_4A8F10;
typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x70];
    s16 h76;
    u8 pad78[0x20];
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} Gs_4A8F10;
typedef struct { u8 pad[0x25E5]; u8 b25E5; } Hero_4A8F10;
extern St_4A8F10 D_0016C580;
extern Gs_4A8F10 D_001CCFD0;
extern Hero_4A8F10 D_001A4BE0;
extern Buf_4A8F10 D_L01_001E6E00;
extern Tab_4A8F10 D_L01_001EA9C0;
extern u8 D_L01_001E1460_004A8F10;
extern u8 D_L01_001E14A0_004A8F10;
__asm__(".extern D_L01_001E1460_004A8F10, 16");
__asm__(".extern D_L01_001E14A0_004A8F10, 16");
extern u8 D_L01_00251480[];
extern s32 D_L01_001E10F0;
__asm__(".extern D_L01_001E10F0, 16");
extern f32 D_L01_001DF9D0;
extern s32 D_L01_001DF9D8;
__asm__(".extern D_L01_001DF9D0, 16");
__asm__(".extern D_L01_001DF9D8, 16");
extern void func_00388440(void *, s32, s32);
extern void func_003A3B00(void);
extern void func_L01_004FC518(s32, s32);
extern void func_L01_0050C8E8(s32);
extern void func_L01_004B5C00(s32);
extern void func_00385B60(s32);
extern void func_0039D6C8(s32);
extern void func_L01_00429998(s32, s32);
extern void func_0039DAE0(s32, s32);
extern void func_003958A0(s32);
extern void func_0039EE68(void);
extern s32 func_0012C908(s32);
extern void func_0039C710(void);

void func_L01_004A8F10(s32 a0) {
    s32 i;
    s32 sel;

    D_0016C580.h22 = -1;
    D_0016C580.h20 = a0;
    D_0016C580.w8 = 0;
    D_0016C580.w6C = 0;
    func_00388440(&D_L01_001E6E00, 0, 0x1E0);
    func_00388440(&D_L01_001E1460_004A8F10, 0, 0x40);
    func_00388440(D_L01_00251480, 0, 0x40);
    func_00388440(D_L01_00251480 + 0x40, 0, 0x40);
    func_00388440(&D_L01_001E14A0_004A8F10, 0, 0x40);
    func_003A3B00();
    D_L01_001E10F0 += -0x60000;
    D_L01_001E6E00.w68 = D_L01_001EA9C0.wC + D_L01_001E10F0;
    D_L01_001E6E00.w6C = D_L01_001EA9C0.w10 + D_L01_001E10F0;
    for (i = 0; i < 1; i++) {
        (&D_L01_001DF9D0)[i] = 1.0f;
        (&D_L01_001DF9D8)[i] = 0;
    }
    func_L01_004FC518(0x65, 2);
    D_001A4BE0.b25E5 = 1;
    func_L01_0050C8E8(0);
    func_L01_004B5C00(1);
    D_0016C580.obj->h34 |= 1;
    if (D_001CCFD0.h4 != 0) {
        func_00385B60(6);
        func_0039D6C8(1);
    }
    if (a0 == 0) {
        sel = 2;
        func_L01_00429998(1, 6);
    } else {
        sel = D_0016C580.h2A == 0;
        func_L01_00429998(0, D_0016C580.h2A == 0 ? 2 : 0);
    }
    func_0039DAE0(sel | 0x1388, 0);
    func_003958A0(0);
    while (D_001CCFD0.h76 != 0 || D_001CCFD0.h9E != 3 || D_001CCFD0.h98 >= 0x1B58) {
        func_0039EE68();
        func_0012C908(0);
    }
    func_0039C710();
}
/* localdecomp:end func_L01_004A8F10 */
