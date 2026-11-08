/* near miss (level 3, Starship Phoenix): 101 differences, cascading from two things: the prologue (retail loads the lbu after the four sd and the move, with the object field load in the bnez delay slot and a shared jump target that leaves $4 untouched; the C hoists the lbu) and the tail (a shared jal func_L01_004450F0 whose $a1 is set in the delay slot of a b, plus a separate (a,1,-1) call); four control-flow shapes tried; float stores, lq/sq, constants and offsets look right */
#include "common.h"

/* localdecomp:start func_L03_00396E00 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    char pad0[0x30];
    f32 f30, f34, f38, f3C, f40;
    char pad44[8];
    f32 f4C, f50, f54, f58, f5C, f60, f64;
    char pad68[0xB8];
    u128_t v120;
    char pad130[0x10];
    int i140;
    char pad144[8];
    int i14C;
    char pad150[0xC];
    short s15C;
    short s15E;
    char pad160[0x10];
    int i170;
    char pad174[8];
    u8 b17C;
} S_00396E00;
typedef struct {
    char pad0[0x10];
    f32 f10, f14, f18;
    char pad24[0x4C];
    S_00396E00 *p68;
} O_00396E00;
extern u8 D_001426E8;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u128_t *D_L03_0021D8C0[];
__asm__(".extern D_L03_0021D8C0, 16");
extern void func_003C2880(void *);
extern f32 func_003C3D30(void *, int, int, f32);
extern void func_L03_00397138(void *);
extern void func_L01_004450F0(void *, int, int);

void func_L03_00396E00(void *a) {
    O_00396E00 *o = a;
    S_00396E00 *s = o->p68;
    u128_t *t;
    if (D_001426E8 == 0 ? s->b17C == 1 : s->b17C == 2) {
        func_003C2880(a);
        func_003C2880(D_L03_001DF99C + (s->i140 << 8));
        return;
    }
    if (s->i14C == -1) {
        func_L01_004450F0(a, 1, -1);
        return;
    }
    t = D_L03_0021D8C0[s->i14C];
    if (*(int *)t >= 2) {
        s->i170 = 0;
        s->s15C = 1;
        s->s15E = 1;
        *(u128_t *)((char *)a + 0x10) = t[1];
        o->f18 = func_003C3D30((char *)a + 0x10, 0, 0, 0.5f);
        s->f54 = 0.0050265486f;
        s->v120 = t[s->s15C + 1];
        s->f30 = 0.6f;
        s->f34 = 0.4f;
        s->f3C = 1.0f;
        s->f40 = 1.4835298f;
        s->f60 = 0.34906584f;
        s->f5C = 0.00392f;
        s->f64 = 0.01f;
        s->f58 = 0.050000004f;
        s->f4C = 0.25132743f;
        s->f38 = 1.0f;
        s->f50 = 0.0050265486f;
        func_L03_00397138(a);
        func_L01_004450F0(a, 2, -1);
    } else {
        func_L01_004450F0(a, 1, -1);
    }
}
/* localdecomp:end func_L03_00396E00 */
