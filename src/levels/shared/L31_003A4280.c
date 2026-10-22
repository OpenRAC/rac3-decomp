#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L31_003A5178);

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
extern int func_L31_003A5178(Moby *, float *);

int func_L31_003A53F8(Moby *m) {
    float range;

    if (m->vars->mode == 2) {
        range = D_L31_001DE9F4;
    } else {
        range = D_L31_001DE9F8;
    }
    if (__builtin_fabsf(m->x - D_001A4BE0.pos[0]) < range &&
        __builtin_fabsf(m->z - D_001A4BE0.pos[2]) < range &&
        func_L31_003A5178(m, D_001A4BE0.pos) != 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L31_003A53F8 */

INCLUDE_ASM("asm/levels", func_L31_003A5488);

INCLUDE_ASM("asm/levels", func_L31_003A55A0);

INCLUDE_ASM("asm/levels", func_L31_003A5818);

/* localdecomp:start func_L31_003A5888 */
extern s32 D_L31_001DF340;
extern void func_L30_0034CCD0(s32 a0, f32 *a1, f32 *a2, f32 *a3, f32 *t0);
s32 func_L31_003A5888(u8 *a0, f32 r) {
    f32 b[4];
    func_L30_0034CCD0(*(s32 *)(*(u8 **)(a0 + 104) + 436), &b[0], &b[1], &b[2], &b[3]);
    if (b[1] + r < *(f32 *)(a0 + 16) || *(f32 *)(a0 + 16) < b[0] - r
        || b[3] + r < *(f32 *)(a0 + 24) || *(f32 *)(a0 + 24) < b[2] - r) {
        if (D_L31_001DF340 >= 6) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L31_003A5888 */

/* localdecomp:start func_L31_003A5948 */
void func_L31_003A5948(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x1C4) = 0;
}
/* localdecomp:end func_L31_003A5948 */
