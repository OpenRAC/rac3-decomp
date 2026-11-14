#include "common.h"

/* localdecomp:start func_L39_005E9580 */
extern s32 func_L01_00513698(void);
extern s32 func_003B46F0(s32);
extern s32 func_003B4778(s32);
extern void func_L39_005F0E48(s32, s32, s32);
extern u8 *func_L39_006197C0(s32);
typedef struct { u8 pad[0x74]; s32 values[8][4]; } Settings_005E9580;
extern Settings_005E9580 D_001A5990;
extern s32 D_L39_0024C990[4] __attribute__((section(".sdata")));
extern s32 D_001A5B10[][8];

void func_L39_005E9580(s32 buttons) {
    s32 mode = 0;
    s32 player;
    s32 selected;
    switch (selected = func_L01_00513698()) {
        case 0: mode = selected; break;
        case 1: mode = 1; break;
        case 2: mode = 2; break;
        case 3: mode = 3; break;

    }
    player = func_L01_00513698();
    selected = func_003B4778(func_003B46F0(mode));
    if (selected == 3) {
        if (buttons & 0x8000) {
            s32 value = D_001A5990.values[D_L39_0024C990[player]][player] - 2;
            D_001A5990.values[D_L39_0024C990[player]][player] = value > -1 ? value : 0;
            func_L39_005F0E48(3, 0, 0);
        } else if (buttons & 0x2000) {
            s32 value = D_001A5990.values[D_L39_0024C990[player]][player] + 2;
            D_001A5990.values[D_L39_0024C990[player]][player] = value < 101 ? value : 100;
            func_L39_005F0E48(3, 0, 0);
        }
        {
            s32 index = *(s32 *)(func_L39_006197C0(player) + 0x2544);
            D_001A5B10[D_L39_0024C990[player]][index] = D_001A5990.values[D_L39_0024C990[player]][player];
        }
    }
}
/* localdecomp:end func_L39_005E9580 */
