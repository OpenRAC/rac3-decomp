#include "common.h"

typedef struct { u8 pad[0x34]; s32 frame; } S_Game;
typedef struct { u8 pad[0xB0]; } S_Rec;

/* declared by functions of L10_00407268.c, which this file was cut from */
extern s32 D_L10_001D6C50;

/* localdecomp:start func_L10_00407750 */
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4C18(void *, f32);
extern void func_L01_0040C8A0(void *, void *);
extern s32 D_L10_001D6C50;
__asm__(".extern D_L10_001D6C50, 4");

void func_L10_00407750(void *obj, void *rec_) {
    u8 *rec = (u8 *)rec_;
    s32 d;

    if (obj != 0) {
        func_003C2F58(obj, 0, rec);
        func_003C4C18(rec, 0.1f);
        func_003C2F58(obj, 1, rec + 0x10);
    }
    d = D_L10_001D6C50;
    *(s32 *)(rec + 0x24) = 0x7F7F7F7F;
    *(s32 *)(rec + 0x20) = 0x7F7F7F7F;
    *(s32 *)(rec + 0x2C) = 0x7F7F2000;
    *(s32 *)(rec + 0x28) = 0x7F7F2000;
    if (d != 0) {
        func_L01_0040C8A0(rec, (void *)d);
    }
}
/* localdecomp:end func_L10_00407750 */

INCLUDE_ASM("asm/levels", func_L10_004077E0);
