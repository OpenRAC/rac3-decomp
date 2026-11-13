#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0055E798);

INCLUDE_ASM("asm/levels", func_L39_0055F3C0);

/* localdecomp:start func_L39_0055F808 */
typedef struct O_0055F808 {
    u8 pad0[0xE8];
    f32 fE8;
    u8 padEC[0x160 - 0xEC];
    f32 f160;
    u8 pad164[0x1E0 - 0x164];
    f32 f1E0;
    u8 pad1E4[0x210 - 0x1E4];
    f32 f210;
    f32 f214;
} O_0055F808;
typedef struct A_0055F808 {
    u8 pad0[0xF8];
    f32 fF8;
} A_0055F808;
__asm__(".extern D_L39_0024B3D0, 4");
__asm__(".extern D_L39_0024B3D4, 4");
__asm__(".extern D_L39_0024B3D8, 4");
__asm__(".extern D_L39_0024B3DC, 4");
extern f32 D_L39_0024B3D0;
extern f32 D_L39_0024B3D4;
extern f32 D_L39_0024B3D8;
extern f32 D_L39_0024B3DC;
extern f32 func_0038DB00(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L39_0055F808(A_0055F808 *a0, O_0055F808 *a1)
{
    a1->fE8 = func_0038DB00(a1->f210, a0->fF8);
    func_L01_0044E850(a0, (u8 *)a1 + 0x80, 0, D_L39_0024B3D0 * 1.44f, D_L39_0024B3D4 * 1.44f);
    a1->f160 = a1->f214;
    func_L01_0044E850(a0, (u8 *)a1 + 0x100, 2, D_L39_0024B3D8 * 1.44f, D_L39_0024B3DC * 1.44f);
    a1->f1E0 = a1->f214 * 0.35f;
    func_L01_0044E850(a0, (u8 *)a1 + 0x180, 3, D_L39_0024B3D8 * 1.44f, D_L39_0024B3DC * 1.44f);
}
/* localdecomp:end func_L39_0055F808 */

INCLUDE_ASM("asm/levels", func_L39_0055F8D8);
