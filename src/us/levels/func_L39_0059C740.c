#include "common.h"

/* NTSC-U counterpart of func_L39_0059DAD0 (src/levels/39_multiplayer_menu/L39_0059DAD0.c) */
/* localdecomp:start func_L39_0059C740 */
typedef struct { s32 a; u16 b; } S_0059DAD0;
extern S_0059DAD0 D_L39_00242D10 __attribute__((section(".data")));
extern void *D_L39_0024BE94;
extern void *D_001E0600_sda;
__asm__(".extern D_001E0600_sda, 4");
extern u8 D_L39_00241360[];
extern void func_00193128(void *);
extern void func_L39_0059C5E8(void *, s32, void *);

void func_L39_0059C740(void)
{
    void *argv[4];
    u8 buf[0x20];
    u8 *name = D_L39_00241360;

    D_L39_0024BE94 = buf;
    *(s32 *)buf = D_L39_00242D10.a;
    *(u16 *)(buf + 4) = D_L39_00242D10.b;
    D_001E0600_sda = argv;
    func_00193128(buf + 5);
    func_L39_0059C5E8(name, 2, &D_001E0600_sda);
}
/* localdecomp:end func_L39_0059C740 */
