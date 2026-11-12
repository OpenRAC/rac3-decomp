#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003ECC40);

INCLUDE_ASM("asm/levels", func_L04_003ECE58);

INCLUDE_ASM("asm/levels", func_L04_003ECF50);

/* localdecomp:start func_L04_003ED190 */
extern u8 D_L04_001D66B0[8];
__asm__(".extern D_L04_001D66B0, 16");
extern f32 D_001DF410_sda;
__asm__(".extern D_001DF410_sda, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_L04_003ECF50(void *, void *, void *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_ED190;
typedef int u128_t __attribute__((mode(TI)));

void func_L04_003ED190(void *o) {
    V4_ED190 dst;
    V4_ED190 src;
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_003A52A0(0, 0, o);
        func_L01_00451FE0(o, 31, D_L04_001D66B0, 255, 180, 0, 0, 35, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        *(u128_t *)&src = 0;
        src.z = D_001DF410_sda;
        dst = src;
        func_L04_003ECF50(o, (u8 *)o + 0x10, &dst);
        func_L01_00451E78(o, 1, 0.0f);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L04_003ED190 */
