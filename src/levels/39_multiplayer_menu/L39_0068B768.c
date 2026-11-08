#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

INCLUDE_ASM("asm/levels", func_L39_0068B768);

INCLUDE_ASM("asm/levels", func_L39_0068B828);

/* localdecomp:start func_L39_0068B8A0 */
extern s32 D_001DC3F4_sda;

void func_L39_0068B8A0(void) {
    D_001DC3F4_sda = 3;
}
/* localdecomp:end func_L39_0068B8A0 */

INCLUDE_ASM("asm/levels", func_L39_0068B8B0);

INCLUDE_ASM("asm/levels", func_L39_0068B950);

/* localdecomp:start func_L39_0068BA10 */
extern int func_L39_0059A1F0(void);
extern int D_001DC3F4_sda;

void func_L39_0068BA10(void)
{
    switch (func_L39_0059A1F0()) {
    case 2:
        D_001DC3F4_sda = 6;
        break;
    default:
        D_001DC3F4_sda = 7;
    }
}
/* localdecomp:end func_L39_0068BA10 */

/* localdecomp:start func_L39_0068BA40 */
extern s32 D_001DC3F4_sda;
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern void func_L39_0068B460(void);
extern void func_L01_004792D8(void (*)(void));
extern void func_L39_005BF798(int, int, int, int, int);
extern void func_L39_00689A70(void);

void func_L39_0068BA40(Obj *a)
{
    VT *v;
    func_L01_004792D8(func_L39_0068B460);
    func_L39_005BF798(0x12, 1, 1, 0, 0);
    v = a->vt;
    D_00241440 = 2;
    v->fn(a);
    func_L39_00689A70();
    D_001DC3F4_sda = 3;
}
/* localdecomp:end func_L39_0068BA40 */

/* localdecomp:start func_L39_0068BAB0 */
void func_L39_0067CE08();
extern s32 D_001DC3F4_sda;

s32 func_L39_0068BAB0(void) {
    func_L39_0067CE08();
    D_001DC3F4_sda = 3;
    return 1;
}
/* localdecomp:end func_L39_0068BAB0 */

INCLUDE_ASM("asm/levels", func_L39_0068BAD8);

INCLUDE_ASM("asm/levels", func_L39_0068C0E0);
