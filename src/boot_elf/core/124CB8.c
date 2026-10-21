#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00124CB8(void);
/* --- end of declarations from other files --- */

/* declarations of 124988.c's earlier functions (tools/port_from_us.py) */
typedef struct { s32 pad0; s32 f4; s32 f8; s32 fc; s32 f10; void *f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; s32 f2c; s32 f30; void *f34; } S_124988;
extern s32 D_0013E310[];
extern s32 D_0013E314[];
extern u8 D_00150DC0[];
extern u8 D_00150DD0[];
extern s32 func_0011EE20(void *);
extern u32 D_0013E300[4];
extern u32 D_0013E2F8;
extern void func_00124B80(u32, u32);
extern u32 func_00124A68(u32, u32, void *);
extern void func_00124A28(void);
extern void func_001249F0(void);
extern void func_0011EED0(s32 *);
extern void func_0011EEC0(s32 *);

/* localdecomp:start func_00124CB8 */
typedef struct { u32 a; u32 b; } P_124CB8;
extern P_124CB8 D_0013EAC0[3];
extern u8 D_0013E318[];
extern void func_00124BE8(u32, u32);
extern void func_00124BF8(u32, void *, s32);
extern u32 func_00124C40(u32);
extern void func_0011F0A0(s32);
void func_00124CB8(void) {
    u32 i;
    P_124CB8 *p;
    if (func_00124C50() == 0) {
        return;
    }
    func_00124BE8(D_0013EAC0[0].a, D_0013EAC0[0].b);
    func_00124BF8(0x80074000, D_0013E318, 0x7A8);
    func_0011F0A0(0);
    func_0011F0A0(2);
    func_00124BE8(D_0013EAC0[1].a, D_0013EAC0[1].b);
    for (i = 2, p = &D_0013EAC0[2]; i < 3; i++, p++) {
        func_00124BE8(p->a, func_00124C40(p->a));
    }
}
/* localdecomp:end func_00124CB8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124D64);

ASM_FUNC("asm/boot_elf/handwritten", func_00124D68);
