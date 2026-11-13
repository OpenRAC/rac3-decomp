#include "common.h"

/* localdecomp:start func_L39_0066FA90 */
typedef struct { u8 b[8]; } B8_0066FA90;
typedef struct { u8 b[16]; } B16_0066FA90;
typedef struct { u8 b[32]; } B32_0066FA90;
typedef struct {
    u8 b0;
    u8 p1[3];
    s32 w4;
    s32 w8;
    u8 bC;
    u8 bD;
    s16 hE;
    s16 h10;
    u8 b12[8];
    u8 p1A[2];
    s32 w1C;
    B32_0066FA90 c20;
    B16_0066FA90 c40;
    B8_0066FA90 c50;
    B8_0066FA90 c58;
    B8_0066FA90 c60;
} P_0066FA90;
typedef struct {
    u8 p0[0x88];
    s32 arr[8];
} T20C_0066FA90;
typedef struct {
    u8 p0[8];
    s32 w8;
    s32 wC;
} T210_0066FA90;
typedef struct {
    B32_0066FA90 c0;
    B8_0066FA90 c20;
    u8 p28[8];
    B8_0066FA90 c30;
    B8_0066FA90 c38;
    u8 p40[0x180 - 0x40];
    B16_0066FA90 c180;
} Q_0066FA90;
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    u8 p14[4];
    Q_0066FA90 q;
    u8 p1A8[0x20C - 0x1A8 - 0x0];
    T20C_0066FA90 *p20C;
    T210_0066FA90 *p210;
} S_0066FA90;
extern S_0066FA90 D_L39_00352940;
extern u8 D_001A64A4[];
extern u8 D_001A5D8C[];
extern void func_L39_00670D90(s32);

void func_L39_0066FA90(P_0066FA90 *pkt) {
    s32 i;
    if (pkt->bC == 0x81) {
        return;
    }
    if (pkt->bC == 0x80) {
        D_001A64A4[0] = 0x40;
    } else if (pkt->bC == 0x82) {
        Q_0066FA90 *q = &D_L39_00352940.q;
        q->c0 = pkt->c20;
        q->c180 = pkt->c40;
        q->c20 = pkt->c50;
        q->c30 = pkt->c58;
        q->c38 = pkt->c60;
        D_L39_00352940.p210->wC = pkt->h10;
        D_L39_00352940.p210->w8 = pkt->hE;
        D_L39_00352940.w10 = pkt->w1C;
        func_L39_00670D90(pkt->b0);
    } else {
        D_L39_00352940.w8 = pkt->bC;
        D_L39_00352940.wC = pkt->bD;
        D_L39_00352940.w0 = pkt->w4;
        D_L39_00352940.w4 = pkt->w8;
        D_001A5D8C[0] = 0;
        for (i = 0; i < 8; i++) {
            D_L39_00352940.p20C->arr[i] = pkt->b12[i];
        }
    }
}
/* localdecomp:end func_L39_0066FA90 */

INCLUDE_ASM("asm/levels", func_L39_0066FC08);

INCLUDE_ASM("asm/levels", func_L39_0066FF08);
