#include "common.h"

/* NTSC-U counterpart of func_L39_005E9FA0 (src/levels/shared/L39_005E9FA0.c) */
/* localdecomp:start func_L39_005E7A30 */
typedef struct { s32 cur; s32 reset; s32 max; } Ent_005E9FA0;
typedef struct {
    u8 pad0[0x14];
    s32 x14[3][4];
    s32 x44[3][4];
    s32 x74[3][4];
    u8 pada4[0xAE - 0xA4];
    u8 xae[16];
} Sel_005E9FA0;
extern s32 func_L01_00513698(void);
extern s32 *func_003B46F0(s32);
extern s32 func_003B4778(s32 *);
extern s32 func_L39_005F0E48(s32, s32, s32);
extern void func_L39_005E87E0(void);
extern u8 *func_L39_006197C0(s32);
extern Ent_005E9FA0 D_L39_0049A558[][4];
extern s32 D_L39_0024C990[] __attribute__((section(".sdata")));
extern Sel_005E9FA0 D_001A5990;
extern s32 D_001A5A50[][8];
extern s32 D_001A5AB0[][8];
extern s32 D_001A5B10[][8];
extern s32 D_001D856C_sda;
__asm__(".extern D_001D856C_sda, 4");

void func_L39_005E7A30(s32 arg) {
    s32 s = 0;
    s32 a = 0;
    s32 j;

    switch (func_L01_00513698()) {
    case 0: s = 0; break;
    case 1: s = 1; break;
    case 2: s = 2; break;
    case 3: s = 3; break;
    default: break;
    }
    a = func_L01_00513698();
    s = func_003B4778(func_003B46F0(s));
    func_L39_005F0E48(3, 0, 0);
    if (s != 3) {
        D_L39_0049A558[s][a].cur++;
        if (D_L39_0049A558[s][a].max < D_L39_0049A558[s][a].cur) {
            D_L39_0049A558[s][a].cur = D_L39_0049A558[s][a].reset;
        }
    }
    switch (D_L39_0049A558[0][a].cur) {
    case 0: D_L39_0024C990[a] = 0; break;
    case 1: D_L39_0024C990[a] = 2; break;
    case 2: D_L39_0024C990[a] = 1; break;
    }
    if (s == 0) {
        func_L39_005E87E0();
    }
    D_001A5990.x14[D_L39_0024C990[a]][a] = D_L39_0049A558[1][a].cur;
    D_001A5990.x44[D_L39_0024C990[a]][a] = D_L39_0049A558[2][a].cur;
    D_001A5990.xae[D_001D856C_sda] = *(u8 *)&D_L39_0049A558[4][a];
    D_001A5990.xae[8] = *(u8 *)&D_L39_0049A558[5][a];
    j = *(s32 *)(func_L39_006197C0(a) + 0x2544);
    D_001A5A50[D_L39_0024C990[a]][j] = D_001A5990.x14[D_L39_0024C990[a]][a];
    D_001A5AB0[D_L39_0024C990[a]][j] = D_001A5990.x44[D_L39_0024C990[a]][a];
    D_001A5B10[D_L39_0024C990[a]][j] = D_001A5990.x74[D_L39_0024C990[a]][a];
}
/* localdecomp:end func_L39_005E7A30 */
