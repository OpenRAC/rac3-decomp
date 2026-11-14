#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003DCB60);

INCLUDE_ASM("asm/levels", func_L07_003DCFF8);

INCLUDE_ASM("asm/levels", func_L07_003DD3C8);

INCLUDE_ASM("asm/levels", func_L07_003DD5D8);

INCLUDE_ASM("asm/levels", func_L07_003DD6D8);

/* localdecomp:start func_L07_003DD750 */
/* Vec4f, declared locally: the owning source file includes only common.h. */
typedef struct {
    f32 x, y, z, w;
} V4_3DD750;

typedef struct {
    u8 pad_0[0x10];
    V4_3DD750 v10;      /* 0x10 */
} S_3DD750;

typedef struct {
    u8 pad_0[0x80];
    V4_3DD750 pos;      /* 0x80 */
    u8 pad_90[0x25C0 - 0x90];
    void *moby;         /* 0x25C0 */
} S_3DD750_HERO;

extern S_3DD750_HERO D_001A4BE0;
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern f32 D_001DA978;
extern f32 D_002F3630[];
extern u8 D_L07_001D66B0[8];

extern f32 func_L01_0040E570(void *a, void *b);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446A70(void *a, void *b, s32 c, void *d, void *e, f32 f);

void func_L07_003DD750(S_3DD750 *arg0)
{
    S_3DD750_HERO *h = &D_001A4BE0;

    if (fabsf(arg0->v10.z - h->pos.z) < 0.5f) {
        if (func_L01_0040E570(&arg0->v10, &h->pos) <= 4.0f) {
            f32 v;
            if (func_L01_0041A4F0()) {
                s32 id = D_001D545C;
                if (id == 7 && D_0014275B[0] != 0) v = D_001DA978;
                else v = D_002F3630[id];
            } else {
                v = 1.0f;
            }
            func_L01_00446A70(h->moby, arg0, 1, D_L07_001D66B0,
                          D_L07_001D66B0, v);
        }
    }
}
/* localdecomp:end func_L07_003DD750 */

INCLUDE_ASM("asm/levels", func_L07_003DD838);

INCLUDE_ASM("asm/levels", func_L07_003DDA38);
