#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EB0B0 */
typedef struct {
    s32 pad0;
    u8 *f4;
} S1_004EB0B0;

typedef struct {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[8];
    S1_004EB0B0 *f3C;
    s32 f40;
    s32 f44;
} S_004EB0B0;

extern void func_L39_004CA180(void *, s32);

void func_L39_004EB0B0(S_004EB0B0 *a0, s32 a1, s32 a2) {
    if (a0->f30 == a1) {
        *a0->f3C->f4 = 1;
        a0->f40 = 1;
        a0->f30 = a2;
        a0->f44 = 0;
    }
    func_L39_004CA180(a0, 0x14);
}
/* localdecomp:end func_L39_004EB0B0 */
