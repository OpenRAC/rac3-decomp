#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_00360D80);

INCLUDE_ASM("asm/levels", func_L04_00361208);

INCLUDE_ASM("asm/levels", func_L04_00361948);

INCLUDE_ASM("asm/levels", func_L04_00361BD0);

INCLUDE_ASM("asm/levels", func_L04_00361D20);

INCLUDE_ASM("asm/levels", func_L04_00361DB8);

INCLUDE_ASM("asm/levels", func_L04_00361DF8);

/* localdecomp:start func_L04_00362490 */
typedef struct {
    void (*fn0)(void *);
    void (*fn4)(void *);
} Iface;

typedef struct {
    char pad0[0x240];
    s32 unk240;
    char pad244[0x250 - 0x244];
    s32 unk250;
    char pad254[0x2FC - 0x254];
    void *unk2FC;
    char pad300[0x4E0 - 0x300];
    s32 unk4E0;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Moby;

extern void func_003C2880(void *);
extern Iface *func_L01_0043B548(s32, s32);
extern void func_L04_00362DF0(Moby *);

void func_L04_00362490(Moby *m, s32 arg1) {
    Vars *v = m->vars;
    Iface *it;

    if (v->unk2FC != 0) {
        func_003C2880(v->unk2FC);
        v->unk2FC = 0;
        v->unk240 = 0;
    }
    if (v->unk250 != 0) {
        it = func_L01_0043B548(6625, 108);
        it->fn0(m);
        if (arg1 != 0) {
            it->fn4(m);
        }
    } else if (v->unk4E0 != 0) {
        func_L04_00362DF0(m);
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L04_00362490 */
