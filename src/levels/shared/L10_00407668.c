#include "common.h"

typedef struct { u8 pad[0x34]; s32 frame; } S_Game;
typedef struct { u8 pad[0xB0]; } S_Rec;

/* localdecomp:start func_L10_00407668 */
extern s32 D_L10_001D6C50;
extern u8 D_L10_001EE410[];
extern void func_L01_0040C7A0(u8 *, s32);
void func_L10_00407668(s32 a0) {
    s32 i;
    u8 *p;
    if (D_L10_001D6C50 != 0 && a0 != 0) {
        for (i = 0; i < 3; i++) {
            p = D_L10_001EE410 + i * 176;
            *(u32 *)(p + 32) = 0x7F7F7F7F;
            *(u32 *)(p + 36) = 0x7F7F7F7F;
            *(u32 *)(p + 40) = 0x7F7F2000;
            *(u32 *)(p + 44) = 0x7F7F2000;
            func_L01_0040C7A0(p, D_L10_001D6C50);
        }
    }
}
/* localdecomp:end func_L10_00407668 */

/* localdecomp:start func_L10_004076F8 */
extern s32 D_L10_001D6C50;
extern u8 D_L10_001EE410[];
typedef struct {
    u8 data[176];
} Slot4043A0;

extern void func_L01_0040C948(Slot4043A0 *, void *);

void func_L10_004076F8(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if ((*(void * *)&D_L10_001D6C50) != 0) {
            func_L01_0040C948(&((Slot4043A0 *)&D_L10_001EE410)[i], (*(void * *)&D_L10_001D6C50));
        }
    }
}
/* localdecomp:end func_L10_004076F8 */
