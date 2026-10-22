#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    u8 pad0[208];
    s32 table[35];
    s32 index;
} Obj329158;

INCLUDE_ASM("asm/levels", func_L05_00328BF8);

/* localdecomp:start func_L05_00328E98 */

void func_L05_00328E98(u8 *obj, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 432) = a;
    *(Vec4 *)(obj + 448) = b;
}
/* localdecomp:end func_L05_00328E98 */

/* localdecomp:start func_L05_00328EC0 */

extern void func_L05_00328E98(u8 *obj, Vec4 a, Vec4 b);

void func_L05_00328EC0(u8 *obj, u8 *target, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 16) = a;
    *(Vec4 *)(obj + 240) = b;
    func_L05_00328E98(target, a, b);
}
/* localdecomp:end func_L05_00328EC0 */

INCLUDE_ASM("asm/levels", func_L05_00328F00);

INCLUDE_ASM("asm/levels", func_L05_00328FF8);

INCLUDE_ASM("asm/levels", func_L05_00329050);

INCLUDE_ASM("asm/levels", func_L05_00329120);

INCLUDE_ASM("asm/levels", func_L05_003293B0);

INCLUDE_ASM("asm/levels", func_L05_00329618);

INCLUDE_ASM("asm/levels", func_L05_003296F8);

INCLUDE_ASM("asm/levels", func_L05_003298C0);

/* localdecomp:start func_L05_00329A78 */

extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 D_L05_001DC8A0[2];

void func_L05_00329A78(s32 a0, Obj329158 *obj) {
    func_L01_00452560(0, 9, D_L05_001DC8A0[obj->table[obj->index]], 1, 0, 0, 0);
}
/* localdecomp:end func_L05_00329A78 */

INCLUDE_ASM("asm/levels", func_L05_00329AD0);

INCLUDE_ASM("asm/levels", func_L05_00329B00);

/* localdecomp:start func_L05_00329B98 */
extern u16 D_001A7466[];
extern void func_L05_00329B00(s32, char *);
void func_L05_00329B98(s32 a0, char *a1) {
    func_L05_00329B00(a0, a1);
    D_001A7466[0] = *(u16 *)(a1 + 124);
}
/* localdecomp:end func_L05_00329B98 */

INCLUDE_ASM("asm/levels", func_L05_00329BC8);

/* localdecomp:start func_L05_00329C58 */
void func_L05_00329C58(s32 arg0, void *arg1) {
    *(s32 *)((u8 *)arg1 + 0x80) = 1;
}
/* localdecomp:end func_L05_00329C58 */

/* localdecomp:start func_L05_00329C68 */
extern void func_L05_00329C88(s32, u8 *);
void func_L05_00329C68(s32 a0, u8 *a1) {
    *(s32 *)(a1 + 128) = 0;
    func_L05_00329C88(a0, a1);
}
/* localdecomp:end func_L05_00329C68 */

INCLUDE_ASM("asm/levels", func_L05_00329C88);

INCLUDE_ASM("asm/levels", func_L05_00329CA0);

INCLUDE_ASM("asm/levels", func_L05_00329DA8);

INCLUDE_ASM("asm/levels", func_L05_00329ED0);

INCLUDE_ASM("asm/levels", func_L05_0032A0B0);

INCLUDE_ASM("asm/levels", func_L05_0032A238);

INCLUDE_ASM("asm/levels", func_L05_0032A360);
