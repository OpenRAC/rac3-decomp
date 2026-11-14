#include "common.h"

/* NTSC-U counterpart of func_L40_00421300 (src/levels/shared/L40_00420998.c) */
/* localdecomp:start func_L40_00420A60 */
typedef struct N_00421300 {
    u8 p0[8];
    s32 type;
    s32 wC;
    s32 time;
    s32 w14;
    s32 data[3];
    u8 p24[0x84 - 0x24];
    struct N_00421300 *next;
} N_00421300;
typedef struct { s32 w[3]; } B_00421300;
typedef struct { u8 pad[0x128]; s32 w128; } G_00421300;

extern G_00421300 D_001A5E50;
extern u8 D_L40_001FE1A0[];
typedef struct { f32 x, y, z, w; } V_00421300;
__asm__(".extern D_L40_00242AB0, 16");
extern V_00421300 D_L40_00242AB0 __attribute__((section(".sdata")));
extern void func_L01_0044ED60(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern s32 func_L39_005F0CE0(s32, s32, u8 *);
extern void func_L39_005F0988(s32);
extern void func_L40_0053CE30(u8 *);
extern s32 func_L40_0053B368(s32);
extern void func_L39_005F08F8(void *, s32);
extern N_00421300 *func_L39_00669AC0(N_00421300 *, N_00421300 **);

void func_L40_00420A60(s32 a0, u8 *self) {
    u8 *mv = *(u8 **)(self + 0x90);
    N_00421300 *p = *(N_00421300 **)(mv + 0x38);
    u8 *v = *(u8 **)(self + 0x68);
    s32 *q;
    s32 idx;
    u8 *slot;

    while (p != 0) {
        q = &p->type;
        if (q[2] > D_001A5E50.w128) {
            p = p->next;
            continue;
        }
        switch (p->type) {
        case 1:
            switch (q[3]) {
            case 0:
                func_L01_00441FB8(self, 2, -1);
                *(B_00421300 *)(v + 0x2D0) = *(B_00421300 *)p->data;
                break;
            case 1:
                *(s32 *)(v + 0x450) = p->data[0];
                p = func_L39_00669AC0(p, (N_00421300 **)(mv + 0x38));
                continue;
            default:
                continue;
            }
            break;
        case 2:
            func_L01_0044ED60(self, 15, &D_L40_00242AB0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L39_005F0CE0(2, 0, self);
            idx = *(s32 *)(v + 0x2AC);
            if (idx != -1) {
                slot = D_L40_001FE1A0 + (idx << 7);
                if (*(u8 **)(slot + 0xDC) == self && slot[0xD0]) {
                    func_L39_005F0988(idx);
                }
            }
            *(s32 *)(v + 0x2AC) = -1;
            func_L40_0053CE30(self);
            func_L40_0053B368(a0);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F08F8(self, 1);
            func_L01_00441FB8(self, 0x25, -1);
            return;
        default:
            p = func_L39_00669AC0(p, (N_00421300 **)(mv + 0x38));
            continue;
        }
        p = func_L39_00669AC0(p, (N_00421300 **)(mv + 0x38));
    }
}
/* localdecomp:end func_L40_00420A60 */
