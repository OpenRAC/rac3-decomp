#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

/* localdecomp:start func_L40_003F2158 */
float func_L40_003F2158(int n, float a, float b)
{
    return (float)n * a + (float)((n - 1) * n) * b * 0.5f;
}
/* localdecomp:end func_L40_003F2158 */

/* localdecomp:start func_L40_003F2198 */
f32 func_L40_003F2198(s32 arg0, f32 fparg0) {
    return -fparg0 / (f32) (arg0 - 1);
}
/* localdecomp:end func_L40_003F2198 */

INCLUDE_ASM("asm/levels", func_L40_003F21B8);
