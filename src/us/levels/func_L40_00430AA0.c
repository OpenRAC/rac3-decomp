#include "common.h"

/* localdecomp:start func_L40_00430AA0 */
extern void func_L39_00660240(u8 *, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern u8 *func_L39_006197C0(s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern s32 *D_L40_002412A0;
typedef struct { u8 pad[0x128]; s32 now; } Time105;
extern Time105 D_001A5E50;
typedef struct { u8 pad[0x58]; f32 values[8]; } Stats105;
extern Stats105 D_L40_003573E0;
__asm__(".extern D_L40_003573E0, 16");

static __inline__ f32 maximum105(f32 a, f32 b) {
    return a > b ? a : b;
}

void func_L40_00430AA0(u8 *self, u8 *packet) {
    u8 *vars = *(u8 **)(self + 0x68);
    u8 bytes[8];
    f32 amount;
    s32 i;
    s32 now;
    u8 *player;
    switch (*(u32 *)packet & 15) {
    case 0:
        func_L39_00660240(packet, bytes, 8);
        { s32 j;
          for (j = 0; j < 8; j++) {
            D_L40_003573E0.values[j] += bytes[j];
          }
        }
        if (self[0x20] != 2) func_L01_00441FB8(self, 2, -1);
        *(f32 *)(vars + 0x30) = 0;
        *(s32 *)(vars + 0x80) = 1;
        break;
    case 1:
        func_L39_00660240(packet, &amount, 4);
        func_L39_00660240(packet, bytes, 8);
        { s32 j;
          for (j = 0; j < 8; j++) {
            D_L40_003573E0.values[j] += bytes[j];
          }
        }
        if (!*(s32 *)(vars + 0x80) && *(s32 *)(vars + 0x84) < *(s32 *)(packet + 4)) {
            *(f32 *)(vars + 0x30) = maximum105(*(f32 *)(vars + 0x30) - amount, 0.0f);
        }
        now = D_001A5E50.now;
        if (now - *(s32 *)(vars + 0x90) <= 10000) break;
        *(s32 *)(vars + 0x90) = now;
        for (i = 0; i < *D_L40_002412A0; i++) {
            player = func_L39_006197C0(i);
            if (player && *(s32 *)(player + 0x2548) == *(s32 *)(vars + 0x88)) {
                func_L01_0044ECE0(0x1739, -1, player[0x24C9]);
            }
        }
        break;
    }
}
/* localdecomp:end func_L40_00430AA0 */
