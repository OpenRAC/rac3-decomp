#include "common.h"

/* localdecomp:start func_L39_0053D7E0 */
s32 func_L39_0053D7E0(s32 a0) {
    s32 r = 0;
    if (*(s16 *)(a0 + 170) == 3262) {
        r = *(s32 *)(*(s32 *)(a0 + 104) + 64) != 0;
    }
    return r;
}
/* localdecomp:end func_L39_0053D7E0 */

/* localdecomp:start func_L39_0053D808 */
s32 func_L39_0053D808(u8 *a0) {
    s32 r = 0;
    if (*(s16 *)(a0 + 170) == 3262) {
        r = *(s32 *)(*(u8 **)(a0 + 104) + 184) >= 3;
    }
    return r;
}
/* localdecomp:end func_L39_0053D808 */

LINKER_REMNANT("asm/levels", func_L39_0053D830);

INCLUDE_ASM("asm/levels", func_L39_0053D838);

/* localdecomp:start func_L39_0053D8E8 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_0053D8E8(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L39_0053D8E8 */

/* localdecomp:start func_L39_0053D910 */
extern void func_L39_0066DCC8(s32, s32, s32, s32);
void func_L39_0053D910(s32 a0) {
    func_L39_0066DCC8(a0, 0, 0, 250);
}
/* localdecomp:end func_L39_0053D910 */

/* localdecomp:start func_L39_0053D938 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_0053D938(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L39_0053D938 */

/* localdecomp:start func_L39_0053D960 */
extern void func_L39_0066DCC8(s32, s32, s32, s32);
typedef struct {
    u8 pad[136];
    s32 f88[1];
} S_352C4C;

extern S_352C4C *D_L39_00352B4C[];
extern s32 func_L39_005B4398(s32);
extern void func_L39_00662AA0(void *, void *, s32);

void func_L39_0053D960(u8 *m) {
    void *h;
    s32 v;
    s32 x;
    s32 buf[2];

    h = ((void * (*)(void *a0, s32 a1, s32 a2, s32 a3))func_L39_0066DCC8)(m, 1, 0, 2500);
    v = D_L39_00352B4C[0]->f88[*(s32 *)(*(u8 **)(m + 104) + 28)];
    if (v == 0) {
        x = 1;
    } else if (v == 1) {
        x = 0;
    } else {
        x = func_L39_005B4398(2);
    }
    buf[0] = x;
    func_L39_00662AA0(h, buf, 4);
}
/* localdecomp:end func_L39_0053D960 */

/* localdecomp:start func_L39_0053D9E8 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_0053D9E8(s32 a0) {
    return func_L39_0066DD30(a0, 2, 0) != 0;
}
/* localdecomp:end func_L39_0053D9E8 */

/* localdecomp:start func_L39_0053DA10 */
extern void func_L39_0066DCC8(s32, s32, s32, s32);
void func_L39_0053DA10(s32 a0) {
    func_L39_0066DCC8(a0, 2, 0, 250);
}
/* localdecomp:end func_L39_0053DA10 */
