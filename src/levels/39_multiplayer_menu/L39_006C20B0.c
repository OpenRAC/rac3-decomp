#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006C20B0);

INCLUDE_ASM("asm/levels", func_L39_006C2C40);

INCLUDE_ASM("asm/levels", func_L39_006C30A0);

INCLUDE_ASM("asm/levels", func_L39_006C3670);

INCLUDE_ASM("asm/levels", func_L39_006C3778);

INCLUDE_ASM("asm/levels", func_L39_006C38E0);

INCLUDE_ASM("asm/levels", func_L39_006C3AA8);

/* localdecomp:start func_L39_006C40A8 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern s32 func_0038CAD0(void *);
extern void func_L39_006CEA18(void *, s32);
extern s32 func_L39_006D2F18(void *, void *, void *);
extern void func_L39_006C3778(void *, s32, s32, s32);

s32 func_L39_006C40A8(u8 *obj) {
    s32 buf[2];
    void *h = *(void **)(D_L39_0024D760 + 0x38);
    func_0038CAD0(obj + 0x2C4);
    if (*(s32 *)(obj + 0x2C4) <= 0) {
        s32 r;
        func_L39_006CEA18(h, 0);
        if (*(s32 *)(obj + 0x2CC) == 2) {
            if (func_L39_006D2F18(h, &buf[0], &buf[1]) == 0) {
                func_L39_006C3778(obj, 1, 0, -1);
                return 1;
            }
            r = 0x2EE;
        } else {
            r = 0x7530;
        }
        *(s32 *)(obj + 0x2C4) = r;
    }
    return 0;
}
/* localdecomp:end func_L39_006C40A8 */

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
