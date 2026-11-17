#include "common.h"

/* localdecomp:start func_L39_0066F948 */
typedef struct { u8 b[8]; } T8_0066F948;
typedef struct { u8 b[16]; } T16_0066F948;
typedef struct { u8 b[32]; } T32_0066F948;

typedef struct {
    u8 b;
    u8 pad[3];
} B4_0066F948;

typedef struct {
    u8 pad0[0x88];
    B4_0066F948 f88[8];
} Q_0066F948;

typedef struct {
    s32 f0;
    s32 f4;
    u8 b8;
    u8 pad9[3];
    u8 bC;
    u8 pad_D[3];
    s32 f10;
    u8 pad14[4];
    T32_0066F948 f18;
    T8_0066F948 f38;
    u8 pad40[8];
    T8_0066F948 f48;
    T8_0066F948 f50;
    u8 pad58[0x198 - 0x58];
    T16_0066F948 f198;
    u8 pad1A8[0x20C - 0x1A8];
    Q_0066F948 *f20C;
} G_0066F948;

typedef struct {
    u8 b0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
    u8 bC;
    u8 bD;
    u8 pad_E[4];
    u8 b12[8];
    u8 pad1A[2];
    s32 f1C;
    T32_0066F948 f20;
    T16_0066F948 f40;
    T8_0066F948 f50;
    T8_0066F948 f58;
    T8_0066F948 f60;
} P_0066F948;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0xBC - 8];
    u8 bBC;
    u8 padBD[0x170 - 0xBD];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_0066F948;

extern S_0066F948 D_001A5CD0;
extern G_0066F948 D_L39_00352940;
extern s32 D_L39_002405BC;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_0066F948(s32 arg0) {
    P_0066F948 s;
    s32 i;
    s.bC = D_L39_00352940.b8;
    s.bD = D_L39_00352940.bC;
    s.f4 = D_L39_00352940.f0;
    s.f8 = D_L39_00352940.f4;
    s.f1C = -1;
    s.f20 = D_L39_00352940.f18;
    s.f40 = D_L39_00352940.f198;
    s.f50 = D_L39_00352940.f38;
    s.f58 = D_L39_00352940.f48;
    s.f60 = D_L39_00352940.f50;
    D_001A5CD0.bBC = 0;
    for (i = 0; i < 8; i++) {
        s.b12[i] = D_L39_00352940.f20C->f88[i].b;
    }
    if (D_001A5CD0.w170 == 0) {
        func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.w4, arg0, D_L39_002405BC, 0x68, &s);
    }
}
/* localdecomp:end func_L39_0066F948 */
