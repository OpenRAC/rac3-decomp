#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003B27D0);

/* localdecomp:start func_L03_003B2828 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2828(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003B2828 */

/* localdecomp:start func_L03_003B2848 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2848(s32 arg0) {
    func_L01_00445130(arg0, 4, -1);
}
/* localdecomp:end func_L03_003B2848 */

/* localdecomp:start func_L03_003B2868 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2868(s32 arg0) {
    func_L01_00445130(arg0, 3, -1);
}
/* localdecomp:end func_L03_003B2868 */

/* localdecomp:start func_L03_003B2888 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2888(s32 arg0) {
    func_L01_00445130(arg0, 6, -1);
}
/* localdecomp:end func_L03_003B2888 */

/* localdecomp:start func_L03_003B28A8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad[0x100]; u128_t v; char pad2[0x14]; int flag; } S_003B28A8;
typedef struct { char pad[0x68]; S_003B28A8 *p; } O_003B28A8;
void func_L03_003B28A8(O_003B28A8 *o, u128_t *src) {
    S_003B28A8 *s = o->p;
    if (src == 0) { s->flag = 0; return; }
    s->flag = 1;
    s->v = src[1];
}
/* localdecomp:end func_L03_003B28A8 */

INCLUDE_ASM("asm/levels", func_L03_003B28D0);

INCLUDE_ASM("asm/levels", func_L03_003B2B30);

/* localdecomp:start func_L03_003B2B88 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2B88(s32 arg0) {
    func_L01_00445130(arg0, 4, -1);
}
/* localdecomp:end func_L03_003B2B88 */

/* localdecomp:start func_L03_003B2BA8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2BA8(s32 arg0) {
    func_L01_00445130(arg0, 3, -1);
}
/* localdecomp:end func_L03_003B2BA8 */

/* localdecomp:start func_L03_003B2BC8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2BC8(s32 arg0) {
    func_L01_00445130(arg0, 2, -1);
}
/* localdecomp:end func_L03_003B2BC8 */

/* localdecomp:start func_L03_003B2BE8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2BE8(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003B2BE8 */

/* localdecomp:start func_L03_003B2C08 */
typedef struct { char pad[0x100]; u128_t v; char pad2[0x14]; int flag; } S_003B2C08;
typedef struct { char pad[0x68]; S_003B2C08 *p; } O_003B2C08;
void func_L03_003B2C08(O_003B2C08 *o, u128_t *src) {
    S_003B2C08 *s = o->p;
    if (src == 0) { s->flag = 0; return; }
    s->flag = 1;
    s->v = src[1];
}
/* localdecomp:end func_L03_003B2C08 */
