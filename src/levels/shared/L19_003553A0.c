#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003553A0);

/* localdecomp:start func_L19_003556B0 */
s32 func_L19_003556B0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (a0[32] == 2) {
        return *(s32 *)(p + 16);
    }
    return 0;
}
/* localdecomp:end func_L19_003556B0 */

INCLUDE_ASM("asm/levels", func_L19_003556D0);

/* localdecomp:start func_L19_00355720 */
typedef struct {
    char pad0[0x10];
    int count;
    char pad14[0x1C - 0x14];
    int arg;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Obj;

extern void func_003A52A0(int, int, Obj *);
extern void func_L01_004450F0(Obj *, int, int);

void func_L19_00355720(Obj *obj, int arg) {
    Vars *v = obj->vars;
    int n;

    v->arg = arg;
    n = v->count - 1;
    v->count = n;
    if (n == 2) {
        func_003A52A0(0, 0, obj);
    } else if (n == 1) {
        func_003A52A0(1, 0, obj);
    } else if (n == 0) {
        func_003A52A0(2, 0, obj);
        func_L01_004450F0(obj, 3, -1);
    }
}
/* localdecomp:end func_L19_00355720 */

INCLUDE_ASM("asm/levels", func_L19_003557B0);

/* localdecomp:start func_L19_00355ED0 */
extern void func_L01_004450F0(Obj *, int, int);
extern void func_003C2880(u8 *);
extern s32 func_L19_0044A0C0(u8 *, u8 *, u8 *, s32);
void func_L19_00355ED0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        if (p == 0) {
            func_003C2880(a0);
        } else {
            *(s32 *)(p + 1152) = func_L19_0044A0C0(a0, p, p + 128, 32);
            ((void (*)(u8 *, s32, s32))func_L01_004450F0)(a0, 1, -1);
        }
    }
}
/* localdecomp:end func_L19_00355ED0 */

/* localdecomp:start func_L19_00355F40 */
typedef struct {
    u8 pad0[12];
    u16 flags;
    u8 pad1[18];
} Slot354F48;

typedef struct {
    u8 pad0[128];
    Slot354F48 slots[32];
    s32 count;
} Vars354F48;

extern u8 *D_L19_001DF71C[];
extern void func_L19_00355ED0(u8 *);
extern s32 func_L19_0044A9A0(s32, Slot354F48 *, s32, s32 *);

void func_L19_00355F40(s32 idx, s32 arg, s32 on) {
    u8 *m = D_L19_001DF71C[0] + (idx << 8);
    Vars354F48 *v;
    s32 slot;

    v = *(Vars354F48 **)(m + 104);
    if (m[32] == 0) {
        func_L19_00355ED0(m);
    }
    slot = -1;
    if (func_L19_0044A9A0(arg, v->slots, v->count, &slot) != 0) {
        if (on != 0) {
            *(u16 *)((u8 *)v + (slot << 5) + 140) &= ~1;
        } else {
            *(u16 *)((u8 *)v + (slot << 5) + 140) |= 1;
        }
    }
}
/* localdecomp:end func_L19_00355F40 */

LINKER_REMNANT("asm/levels", func_L19_00355FF0);

/* localdecomp:start func_L19_00356008 */
extern u8 *D_L19_001DF71C[];
extern void func_L19_00356030(s32);
void func_L19_00356008(s32 a0) {
    func_L19_00356030(((s32 *)&D_L19_001DF71C)[0] + (a0 << 8));
}
/* localdecomp:end func_L19_00356008 */

INCLUDE_ASM("asm/levels", func_L19_00356030);

INCLUDE_ASM("asm/levels", func_L19_00356088);
