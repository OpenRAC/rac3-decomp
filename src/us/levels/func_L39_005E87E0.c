#include "common.h"

/* NTSC-U counterpart of func_L39_005EAD50 (src/levels/shared/L39_005EAD50.c) */
/* localdecomp:start func_L39_005E87E0 */
typedef struct S_005EAD50 {
    u8 pad[0x5C0];
} S_005EAD50;

typedef struct A_005EAD50 {
    u8 pad0[0x14];
    s32 a14[3][4];
    s32 a44[3][4];
    s32 a74[3][4];
    u8 padA4[0xAE - 0xA4];
    u8 bAE[16];
} A_005EAD50;
extern s32 D_001D856C_sda;
extern A_005EAD50 D_001A5990;
extern s32 D_L39_0024C990[] __attribute__((section(".sdata")));
extern S_005EAD50 D_L39_00225900[];
extern s32 func_L01_00513698(void);
typedef struct { u8 pad[0x2534]; S_005EAD50 *m; } P_005EAD50;
extern P_005EAD50 *func_L39_006197C0(s32);
typedef struct { s32 f0; s32 f4; s32 f8; } E_005EAD50;
extern E_005EAD50 D_L39_0049A558_005E87E0[][4];
void func_L39_005E87E0(void) {
    s32 n;
    s32 i;
    P_005EAD50 *q;

    D_001D856C_sda = 0;
    n = func_L01_00513698();
    q = func_L39_006197C0(n);
    i = D_L39_0024C990[n];
    D_001D856C_sda = q->m - D_L39_00225900;
    D_L39_0049A558_005E87E0[1][n].f0 = D_001A5990.a14[i][n];
    D_L39_0049A558_005E87E0[2][n].f0 = D_001A5990.a44[i][n];
    if (D_001A5990.a74[i][n] < 0x32) {
        D_L39_0049A558_005E87E0[3][n].f0 = 0;
    } else if (D_001A5990.a74[i][n] < 0x58) {
        D_L39_0049A558_005E87E0[3][n].f0 = 1;
    } else {
        D_L39_0049A558_005E87E0[3][n].f0 = 2;
    }
    D_L39_0049A558_005E87E0[4][n].f0 = D_001A5990.bAE[D_001D856C_sda];
    D_L39_0049A558_005E87E0[5][n].f0 = D_001A5990.bAE[8];
}
/* localdecomp:end func_L39_005E87E0 */
