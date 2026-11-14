#include "common.h"

typedef struct { u8 pad[0x34]; s32 frame; } S_Game;
typedef struct { u8 pad[0xB0]; } S_Rec;

INCLUDE_ASM("asm/levels", func_L10_00407268);

INCLUDE_ASM("asm/levels", func_L10_00407378);

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

INCLUDE_ASM("asm/levels", func_L10_00407750);

INCLUDE_ASM("asm/levels", func_L10_004077E0);

/* localdecomp:start func_L10_004079E0 */
/* PAL port of the NTSC-U match src/us/levels/func_L10_00404678.c */

extern S_Game D_L10_001E5F00;

extern u8 D_L10_001EE410[];
extern void *func_L10_00406780(s32);
extern void func_L10_00407668(s32);
extern void func_L10_004077E0(void *);
extern void func_L10_00407750(void *, void *);
extern s32 func_00382468(s32);
extern void func_L01_00404808(void *, void *);
extern void func_L10_004076F8(void);

void func_L10_004079E0(s32 *c) {
    void *obj;
    s32 i;

    obj = func_L10_00406780(c[0]);
    if (obj == 0) {
        return;
    }
    if (D_L10_001E5F00.frame == (c[1] * 5 + 2) / 6) {
        func_L10_00407668(obj);
    }
    if (D_L10_001E5F00.frame >= (c[5] * 5 + 2) / 6 && D_L10_001E5F00.frame <= (c[1] * 5 + 2) / 6) {
        func_L10_004077E0(obj);
    } else if (D_L10_001E5F00.frame >= (c[3] * 5 + 2) / 6 && D_L10_001E5F00.frame <= (c[6] * 5 + 2) / 6) {
        if (func_00382468(c[7]) == 0) {
            func_L10_004077E0(obj);
        }
    } else if (D_L10_001E5F00.frame >= (c[1] * 5 + 2) / 6 && D_L10_001E5F00.frame <= (c[4] * 5 + 2) / 6) {
        if (func_00382468(c[8]) == 0) {
            func_L10_004077E0(obj);
            for (i = 0; i < 3; i++) {
                func_L10_00407750(obj, &((S_Rec *)D_L10_001EE410)[i]);
                func_L01_00404808(func_L10_004076F8, 0);
            }
        }
    }
    if ((D_L10_001E5F00.frame >= (c[1] * 5 + 2) / 6 && D_L10_001E5F00.frame <= (c[2] * 5 + 2) / 6) || (D_L10_001E5F00.frame >= (c[3] * 5 + 2) / 6 && D_L10_001E5F00.frame <= (c[4] * 5 + 2) / 6)) {
        if (func_00382468(c[9]) == 0) {
            for (i = 0; i < 3; i++) {
                func_L10_00407750(obj, &((S_Rec *)D_L10_001EE410)[i]);
                func_L01_00404808(func_L10_004076F8, 0);
            }
        }
    }
}
/* localdecomp:end func_L10_004079E0 */
