#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0055E798);

INCLUDE_ASM("asm/levels", func_L39_0055F3C0);

INCLUDE_ASM("asm/levels", func_L39_0055F808);

INCLUDE_ASM("asm/levels", func_L39_0055F8D8);

INCLUDE_ASM("asm/levels", func_L39_0055FAE8);

INCLUDE_ASM("asm/levels", func_L39_0055FC98);

INCLUDE_ASM("asm/levels", func_L39_0055FF88);

/* localdecomp:start func_L39_005601D0 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_005601D0(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L39_005601D0 */

/* localdecomp:start func_L39_005601F8 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_005601F8(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L39_005601F8 */

/* localdecomp:start func_L39_00560220 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_00560220(s32 a0) {
    return func_L39_0066DD30(a0, 2, 0) != 0;
}
/* localdecomp:end func_L39_00560220 */

/* localdecomp:start func_L39_00560248 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L39_00560248(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L39_00560248 */

/* localdecomp:start func_L39_00560290 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
void func_L39_00560290(u8 *a0) {
    u16 buf;
    void *h = ((void * (*)(void *a0, s32 a1, s32 a2, s32 a3))func_L39_0066DCC8)(a0, 1, 0, 250);
    u8 *s = *(u8 **)(a0 + 104);
    buf = *(u16 *)(s + 8);
    ((void (*)(void *a0, void *a1, s32 a2))func_L39_00662AA0)(h, &buf, 2);
    buf = *(u16 *)(s + 10);
    ((void (*)(void *a0, void *a1, s32 a2))func_L39_00662AA0)(h, &buf, 2);
}
/* localdecomp:end func_L39_00560290 */

/* localdecomp:start func_L39_00560308 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
void func_L39_00560308(s32 a0) {
    ((void (*)(s32, s32, s32, s32))func_L39_0066DCC8)(a0, 2, 0, 250);
}
/* localdecomp:end func_L39_00560308 */

INCLUDE_ASM("asm/levels", func_L39_00560330);

INCLUDE_ASM("asm/levels", func_L39_00560618);

INCLUDE_ASM("asm/levels", func_L39_005607A0);

INCLUDE_ASM("asm/levels", func_L39_00560868);

INCLUDE_ASM("asm/levels", func_L39_00560FC0);

/* localdecomp:start func_L39_00561158 */
typedef struct {
    u8 pad0[0x68];
    s32 x68;
} func_005606A8_t;

s32 func_L39_00561158(func_005606A8_t *a, s32 *b, s32 *c) {
    s32 v = a->x68;
    *c = 16;
    *b = v;
    return 0;
}
/* localdecomp:end func_L39_00561158 */

/* localdecomp:start func_L39_00561170 */
extern void func_L39_0066CA98(u8 *);
void func_L39_00561170(u8 *a0) {
    if (a0[32] == 5) {
        func_L39_0066CA98(a0);
    }
}
/* localdecomp:end func_L39_00561170 */

INCLUDE_ASM("asm/levels", func_L39_005611A0);

INCLUDE_ASM("asm/levels", func_L39_005614B0);

INCLUDE_ASM("asm/levels", func_L39_00561630);

INCLUDE_ASM("asm/levels", func_L39_005617D8);

INCLUDE_ASM("asm/levels", func_L39_00561D28);
