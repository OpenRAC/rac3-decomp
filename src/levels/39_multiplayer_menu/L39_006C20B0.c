#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006C20B0);

INCLUDE_ASM("asm/levels", func_L39_006C2C40);

INCLUDE_ASM("asm/levels", func_L39_006C30A0);

INCLUDE_ASM("asm/levels", func_L39_006C3670);

INCLUDE_ASM("asm/levels", func_L39_006C3778);

INCLUDE_ASM("asm/levels", func_L39_006C38E0);

INCLUDE_ASM("asm/levels", func_L39_006C3AA8);

INCLUDE_ASM("asm/levels", func_L39_006C40A8);

INCLUDE_ASM("asm/levels", func_L39_006C4148);

/* localdecomp:start func_L39_006C4308 */
__asm__(".extern D_L39_00240640, 16");

typedef struct {
    char pad0[4];
    s32 w4;
    char pad8[0x164];
    s32 w16C;
} S_1A5CD0_006C4308;

typedef struct {
    s32 f0;
    u8 b4;
    u8 b5;
    u8 b6;
    char pad[0x11];
} S_006C4308;

extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern S_1A5CD0_006C4308 D_001A5CD0;
extern s32 D_L39_00240640;

void func_L39_006C4308(u8 *p, s32 a1, s32 a2) {
    S_006C4308 s;

    *(s32 *)(p + 0x2B8) = a1;
    s.f0 = a2;
    s.b6 = 1;
    s.b5 = 0;
    s.b4 = 0;
    func_0014AD08(0x50, D_001A5CD0.w4, D_001A5CD0.w16C, D_L39_00240640, 0x20, &s);
}
/* localdecomp:end func_L39_006C4308 */

INCLUDE_ASM("asm/levels", func_L39_006C4360);

INCLUDE_ASM("asm/levels", func_L39_006C4448);

INCLUDE_ASM("asm/levels", func_L39_006C45C8);

INCLUDE_ASM("asm/levels", func_L39_006C46F0);

INCLUDE_ASM("asm/levels", func_L39_006C4788);

LINKER_REMNANT("asm/levels", func_L39_006C47F8);

INCLUDE_ASM("asm/levels", func_L39_006C4818);

LINKER_REMNANT("asm/levels", func_L39_006C5510);

/* localdecomp:start func_L39_006C5518 */
extern u8 D_L39_0047EAA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006C5518(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EAA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006C5518 */

INCLUDE_ASM("asm/levels", func_L39_006C5540);

/* localdecomp:start func_L39_006C5B30 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006C5B30(void *);

extern void func_L39_0067F168();
void func_L39_006C5B30(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006C5B30 */

INCLUDE_ASM("asm/levels", func_L39_006C5B60);

INCLUDE_ASM("asm/levels", func_L39_006C5CC8);
