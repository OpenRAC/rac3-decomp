#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L31_003A4280);

INCLUDE_ASM("asm/levels", func_L31_003A4410);

/* localdecomp:start func_L31_003A5110 */
typedef int u128_3A3890 __attribute__((mode(TI)));
extern f32 func_0038CF00(void *, void *);
void func_L31_003A5110(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    f32 d = func_0038CF00(s1 + 384, s1 + 400);
    if (d < func_0038CF00(s1 + 384, s1 + 416)) {
        *(u128_3A3890 *)(s1 + 384) = *(u128_3A3890 *)(s1 + 416);
    } else {
        *(u128_3A3890 *)(s1 + 384) = *(u128_3A3890 *)(s1 + 400);
    }
}
/* localdecomp:end func_L31_003A5110 */

/* localdecomp:start func_L31_003A5178 */
/* func_L31_003A5178: from the staged near miss. The fabs is include/vu0.h's fabs_asm: retail loads
   the gp float before abs.s, which __builtin_fabsf schedules first. */
extern f32 D_L31_001DE960;
extern f32 func_L31_003A5B00(void *, f32 *);
extern f32 func_0038DB00(f32, f32);

int func_L31_003A5178(void *m, f32 *pos) {
    f32 r = func_L31_003A5B00(m, pos);
    f32 d = func_0038DB00(*(f32 *)((u8 *)m + 0xF8), r);

    if (fabs_asm(d) > D_L31_001DE960) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L31_003A5178 */

INCLUDE_ASM("asm/levels", func_L31_003A51C8);

INCLUDE_ASM("asm/levels", func_L31_003A5238);

/* localdecomp:start func_L31_003A53F8 */
typedef struct {
    char pad0[0x1C8];
    int mode;
} Vars;

typedef struct {
    char pad0[0x10];
    float x;
    float y;
    float z;
    char pad1C[0x68 - 0x1C];
    Vars *vars;
} Moby;

typedef struct {
    char pad0[0x80];
    float pos[4];
} Player;

extern Player D_001A4BE0;
extern float D_L31_001DE9F4;
extern float D_L31_001DE9F8;
extern int func_L31_003A5178(void *, float *);

int func_L31_003A53F8(Moby *m) {
    float range;

    if (m->vars->mode == 2) {
        range = D_L31_001DE9F4;
    } else {
        range = D_L31_001DE9F8;
    }
    if (fabs_asm(m->x - D_001A4BE0.pos[0]) < range &&
        fabs_asm(m->z - D_001A4BE0.pos[2]) < range &&
        func_L31_003A5178(m, D_001A4BE0.pos) != 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L31_003A53F8 */

INCLUDE_ASM("asm/levels", func_L31_003A5488);

INCLUDE_ASM("asm/levels", func_L31_003A55A0);
