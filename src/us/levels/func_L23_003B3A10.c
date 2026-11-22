#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
#include "vu0.h"
typedef struct { V4 pos[2]; s32 color0; s32 x24; s32 color1; s32 x2C; } Sparks;

/* NTSC-U counterpart of func_L23_003B5318. */
/* localdecomp:start func_L23_003B3A10 */
extern struct Moby *D_L23_001DE450;
__asm__(".extern D_L23_001DE450, 4");
extern u8 *func_L23_003B38B8(u8 *, u8 *, f32);
__asm__(".extern D_L23_001DE3F0, 4");
__asm__(".extern D_L23_001DE440, 4");
__asm__(".extern D_L23_001DE454, 4");
__asm__(".extern D_L23_001DE458, 8");
extern s32 D_L23_001DE3F0;
extern s32 D_L23_001DE440;
extern s32 D_L23_001DE454;
extern u8 *D_L23_001DE458[2];
extern Sparks D_L23_002A3B00;
extern s32 func_00388398(void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_0040A2D0(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00402498(void *, void *);
void func_L23_003B3C30(void);

void func_L23_003B3A10(void)
{
    func_00388398(&D_L23_001DE454);
    if (D_L23_001DE454 <= 0) {
        D_L23_001DE458[0] = D_L23_001DE458[1];
        if (D_L23_001DE458[1] == 0 || func_0037E1D8(10) == 0)
            D_L23_001DE458[0] = func_L23_003B38B8((u8 *)D_L23_001DE450, 0, 1000000.0f);
        D_L23_001DE458[1] = func_L23_003B38B8(D_L23_001DE458[0], D_L23_001DE458[0], 16.0f);
        if (D_L23_001DE458[0] != 0 && D_L23_001DE458[1] != 0) {
            func_L01_0040A2D0(&D_L23_002A3B00, &D_L23_001DE3F0);
            D_L23_002A3B00.color0 = 0x606060;
            D_L23_002A3B00.x24 = 0x7070;
            D_L23_002A3B00.color1 = 0x6060;
            D_L23_002A3B00.x2C = 0x204040;
            func_003886E8(&D_L23_002A3B00.pos[0], &D_L23_001DE440,
                          *(f32 *)(D_L23_001DE458[0] + 0x2C) / *(f32 *)(*(u8 **)(D_L23_001DE458[0] + 0x24) + 0x24));
            vec_add_ab(&D_L23_002A3B00.pos[0], &D_L23_002A3B00.pos[0], D_L23_001DE458[0] + 0x10);
            func_003886E8(&D_L23_002A3B00.pos[1], &D_L23_001DE440,
                          *(f32 *)(D_L23_001DE458[1] + 0x2C) / *(f32 *)(*(u8 **)(D_L23_001DE458[1] + 0x24) + 0x24));
            vec_add_ab(&D_L23_002A3B00.pos[1], &D_L23_002A3B00.pos[1], D_L23_001DE458[1] + 0x10);
        }
        D_L23_001DE454 = 10;
    }
    if (D_L23_001DE458[0] != 0 && D_L23_001DE458[1] != 0)
        func_L01_00402498(func_L23_003B3C30, D_L23_001DE450);
}
/* localdecomp:end func_L23_003B3A10 */
