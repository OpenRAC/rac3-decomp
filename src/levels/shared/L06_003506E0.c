#include "common.h"

/* localdecomp:start func_L06_003506E0 */
extern void func_L06_00350BB8(void *arg0, u8 *arg1);
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad1[52 - 33];
    u16 flags;
    u8 pad2[104 - 54];
    void *vars;
} Moby_0034F9E8;
extern u8 D_L06_001DD340[];
extern void func_L06_00350788(Moby_0034F9E8 *, void *);
extern s32 func_L06_00351C48(Moby_0034F9E8 *, void *);
extern s32 func_L04_004C1158(Moby_0034F9E8 *, void *);
extern void func_L06_003528B8(Moby_0034F9E8 *, void *);
extern void func_L06_00352AA0(Moby_0034F9E8 *, void *);
extern void func_L06_00354D48(Moby_0034F9E8 *, void *);
void func_L06_003506E0(Moby_0034F9E8 *m) {
    void *v;
    if (m->flags & 2) return;
    v = m->vars;
    if (m->state == 0) func_L06_00350788(m, v);
    if (func_L06_00351C48(m, v) == 0) return;
    if (func_L04_004C1158(m, D_L06_001DD340)) {
        ((void (*)(Moby_0034F9E8 *, void *))func_L06_00350BB8)(m, v);
        func_L06_003528B8(m, v);
        func_L06_00352AA0(m, v);
        func_L06_00354D48(m, v);
    }
}
/* localdecomp:end func_L06_003506E0 */

INCLUDE_ASM("asm/levels", func_L06_00350788);

/* localdecomp:start func_L06_00350BB8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 m[4];
} Mtx4;

extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_0038D590(void *, Mtx4 *);
extern void func_003C48A8(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);

void func_L06_00350BB8(void *arg0, u8 *arg1) {
    Mtx4 m;

    func_003C2EC0(arg0, 0, &m);
    *(Vec4 *)(*(u8 **)(arg1 + 608) + 16) = m.m[3];
    func_0038D590(*(u8 **)(arg1 + 608) + 192, &m);
    func_003C48A8(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    if (*(f32 *)(arg1 + 880) != 0.0f) {
        *(f32 *)(*(u8 **)(arg1 + 608) + 248) = func_0038DAB8(*(f32 *)(*(u8 **)(arg1 + 608) + 248), *(f32 *)(arg1 + 880));
        func_0038D308(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    }
}
/* localdecomp:end func_L06_00350BB8 */

INCLUDE_ASM("asm/levels", func_L06_00350C50);

INCLUDE_ASM("asm/levels", func_L06_00350D60);

INCLUDE_ASM("asm/levels", func_L06_00350E28);

INCLUDE_ASM("asm/levels", func_L06_00350FD0);

INCLUDE_ASM("asm/levels", func_L06_00351220);

INCLUDE_ASM("asm/levels", func_L06_003512D0);

INCLUDE_ASM("asm/levels", func_L06_00351358);

INCLUDE_ASM("asm/levels", func_L06_00351390);

INCLUDE_ASM("asm/levels", func_L06_00351410);

INCLUDE_ASM("asm/levels", func_L06_00351508);

/* localdecomp:start func_L06_00351628 */
extern s32 D_L06_001DD2F0;
extern s32 D_L06_001DD2F4[];
extern void func_003C2F58(s32, s32, s32);

void func_L06_00351628(s32 a0, u8 *obj, s32 a2, s32 a3) {
    func_003C2F58(*(s32 *)(obj + 0x260), D_L06_001DD2F0, a2);
    func_003C2F58(*(s32 *)(obj + 0x260), D_L06_001DD2F4[0], a3);
}
/* localdecomp:end func_L06_00351628 */

/* localdecomp:start func_L06_00351678 */
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CAD0(void *);

void func_L06_00351678(u8 *moby, u8 *vars) {
    f32 r = 7.0f;
    f32 x = *(f32 *)(vars + 784);
    if (x < r) {
        r = x;
    } else if (r < x * 0.5f) {
        r = x * 0.5f;
    }
    r = r * r;
    if (func_L01_0040E570(moby + 16, vars + 544) < r) {
        func_0038CAD0(vars + 632);
    } else {
        *(int *)(vars + 632) = 150;
    }
}
/* localdecomp:end func_L06_00351678 */

INCLUDE_ASM("asm/levels", func_L06_00351718);

/* localdecomp:start func_L06_00351728 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038CF38(void *a0, void *a1);
extern s32 func_L06_0045AFF8(void *a0, s32 a1, void *a2);
extern f32 func_0038CF00(void *a0, void *a1);
void func_L06_00351728(u8 *a0, u8 *a1, u128_t *a2, s32 *a3, f32 *t0) {
    if (*(s32 *)(a1 + 624) != 0) {
        *a2 = *(u128_t *)(a0 + 16);
        *a3 = 0;
        *t0 = func_0038CF38(a0 + 16, a1 + 544);
    } else {
        *a3 = func_L06_0045AFF8(a2, *(s32 *)(a1 + 856), a1 + 544);
        *t0 = func_0038CF00(a1 + 544, a2);
    }
}
/* localdecomp:end func_L06_00351728 */

INCLUDE_ASM("asm/levels", func_L06_003517C0);
