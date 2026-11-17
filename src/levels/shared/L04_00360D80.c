#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L04_00360D80);

INCLUDE_ASM("asm/levels", func_L04_00361208);

INCLUDE_ASM("asm/levels", func_L04_00361948);

/* localdecomp:start func_L04_00361BD0 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L02_00431568(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 D_L04_001DD6E0;
__asm__(".extern D_L04_001DD6E0, 4");
extern f32 D_L04_001DD6CC;
__asm__(".extern D_L04_001DD6CC, 4");

void func_L04_00361BD0(u8 *a0, u8 *a1, f32 t) {
    vu0_v4 p;
    vu0_v4 d;
    f32 x;
    f32 lim;

    func_0038CF68(&p, a1 + 0x330, D_L04_001DD6CC * t);
    vec_add_ab(&p, &p, a1 + 0x320);
    vec_sub_ab(&d, a1 + 0x220, &p);
    x = 3.1415927f - func_0038DBA0(*(f32 *)(a1 + 0x36C), func_0038D160(d.x, d.y));
    lim = D_L04_001DD6E0 * 0.017453292f;
    if (lim < x) {
        x = lim;
    }
    if (0.0f < func_0038CE68(a1 + 0x330, &d)) {
        x = func_0038DB00(*(f32 *)(a1 + 0x36C), x);
    } else {
        x = func_0038DAB8(*(f32 *)(a1 + 0x36C), x);
    }
    func_L02_00431568(a0, &p, 0x10, func_0038D160(p.x - *(f32 *)(a0 + 0x10), p.y - *(f32 *)(a0 + 0x14)), -1.0f, -1.0f, -1.0f);
    func_L01_0045BD10(a0, x);
}
/* localdecomp:end func_L04_00361BD0 */

/* localdecomp:start func_L04_00361D20 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 D_L04_001DD6E0;
__asm__(".extern D_L04_001DD6E0, 4");

s32 func_L04_00361D20(void *a0, u8 *a1) {
    vu0_v4 d;
    if (*(s32 *)(a1 + 0x308) == 0) {
        return 0;
    }
    if (a1[0x5F] != 0) {
        return 0;
    }
    vec_sub_ba(&d, a1 + 0x220, a1 + 0x320);
    if (3.1415927f - func_0038DBA0(*(f32 *)(a1 + 0x36C), func_0038D160(d.x, d.y)) < D_L04_001DD6E0 * 0.017453292f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00361D20 */

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
