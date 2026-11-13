#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00606D28);

/* localdecomp:start func_L39_00606E40 */
extern s32 func_003ABDD8(u8 *, s32);
extern void func_003AB4A0(void *, s32, s32, s32, s32);
extern void func_003ABD18(void *, s32);
extern void func_003ABBE0(void *, s32);
extern void func_003ABBE8(void *, s32);
extern void func_003AB530(void *, s32, s32);
extern void func_003AB548(void *, s32, s32);
extern void func_L01_004CD640(void *, s32);
extern void func_L01_004CD620(void *, s32);
extern void func_L39_006044E0(void *, s32, s32);
extern void func_L39_006023D8(void *, s32);
extern u8 *D_L39_00242A50;
__asm__(".extern D_L39_00242A50, 16");
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern s32 D_L39_002456C8[];

typedef struct { u8 pad[0x50D0]; s32 a[4]; s32 b[4]; } S_00606E40;
void func_L39_00606E40(u8 *p, s32 a, s32 b) {
    S_00606E40 *sp = (S_00606E40 *)p;
    s32 i, j;
    u32 k;
    u8 *r;

    for (i = 0; i < 4; i++) {
        sp->a[i] = func_003ABDD8(D_L39_00242A50 + 0x7090, 0xC);
        sp->b[i] = func_003ABDD8(D_L39_00242A50 + 0x7090, 0xD);
    }
    if (D_L39_002412DC != 39) {
        for (j = 0; j < 4; j++) {
            r = p + j * 0x618;
            for (k = 0; k < 26; k++) {
                func_003AB4A0(r, 0x16, 1, (s32)D_L39_002456C8, b);
                func_003ABD18(r, 5);
                func_003ABBE0(r, 100);
                func_003ABBE8(r, 0);
                func_003AB530(r, 0x706EC8FF, 0x706EC8FF);
                func_003AB548(r, 0x80808080, 0x80808080);
                ((void (*)(void *, u32))func_L01_004CD640)(r, 0x80000000);
                func_L01_004CD620(r, 1);
                r += 0x3C;
            }
            func_L39_006044E0(p + (j * 0xB50 + 0x18A0), a, b);
            func_L39_006023D8(p + (j * 0x230 + 0x45E0), b);
        }
    }
    *(s32 *)(p + 0x189C) = b;
}
/* localdecomp:end func_L39_00606E40 */
