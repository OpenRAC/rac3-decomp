#include "common.h"

/* declared by functions of L39_0053DA40.c, which this file was cut from */
extern void func_003C2880(void *);

/* localdecomp:start func_L39_0053E740 */
/* Log: matched after 4 rounds. The switch (not an if chain) gives retail's block layout; D_L39_00242930 needs
 * section(".sdata") to be loaded with one la per call; the callee func_L01_00446780 is declared with its floats first
 * (same registers as the int-first form, but it reorders the argument set-up the way retail has it). */
#include "vu0.h"

typedef struct {
    vu0_v4 f0;
    s32 f10;
    f32 f14;
    u8 pad18[0xC];
    s32 f24;
} S_0053E740;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 f10;
    u8 f20;
    u8 pad21[0x47];
    S_0053E740 *f68;
    u8 pad6C[0x3E];
    u16 fAA;
    u8 padAC[0x14];
    vu0_v4 fC0;
    vu0_v4 fD0;
    vu0_v4 fE0;
} O_0053E740;

typedef struct {
    u8 pad0[0x1A];
    u16 f1A;
    u8 pad1C[0x14];
} C_0053E740;

extern s32 D_L39_0025F758 __attribute__((section(".data")));
extern f32 D_L39_00242930[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AE20, 4");
__asm__(".extern D_L39_0024AE40, 4");
__asm__(".extern D_L39_0024AE44, 4");
extern f32 D_L39_0024AE20;
extern s32 D_L39_0024AE40;
extern s32 D_L39_0024AE44;

extern void func_L01_00446780(f32, f32, f32, void *, void *, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_L01_0046B458(void *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);
extern void func_003C2880(void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L39_0053EA08(void);

void func_L39_0053E740(O_0053E740 *a0) {
    S_0053E740 *s = a0->f68;
    vu0_v4 v0;
    C_0053E740 c;
    vu0_v4 v40;
    vu0_v4 v50;
    f32 r;

    s->f24 = s->f24 + 1;
    if (s->f24 > 240) {
        func_L01_00446780(0.6f, s->f14, 0.0f, a0, &a0->f10, 0x10001, 0, 1, 0);
        func_L01_004450F0(a0, 1, -1);
    }
    switch (a0->f20) {
    case 0:
        vec_add_ba(&v0, &a0->f10, &s->f0);
        func_L01_00446760(&c, a0, 1, s, s->f14);
        c.f1A = a0->fAA;
        if (func_003D3CB0(&a0->f10, &v0, 0, a0, &c) != 0 || func_L01_003FB640(&a0->f10, 0, a0, 0.3f) != 0) {
            if (D_L39_0025F758 == 0 || D_L39_0025F758 != s->f10) {
                func_L01_00446780(0.6f, s->f14, 0.0f, a0, &a0->f10, 0x10001, 0, 1, 0);
                func_L01_004450F0(a0, 1, -1);
                return;
            }
        }
        a0->f10 = v0;
        func_0038CE20(&v40, s, -0.5f);
        qzero(&v50);
        break;
    case 1:
        r = func_L39_005B4410(8.0f, 10.0f);
        func_L01_0046B458(&a0->f10, 12, D_L39_0024AE40, 0, 10, D_L39_00242930, r * 0.3f, r, 0.0f, 0);
        func_L01_0046B458(&a0->f10, 12, D_L39_0024AE44, 1, -10, D_L39_00242930, r * 0.04f, r * 0.4f, 0.0f, 0);
        func_003C2880(a0);
        return;
    }
    func_0038D890(&a0->fE0, &a0->fE0, &a0->fD0, D_L39_0024AE20 * 0.017453292f);
    func_0038D890(&a0->fC0, &a0->fC0, &a0->fD0, D_L39_0024AE20 * 0.017453292f);
    func_L01_00404A10(func_L39_0053EA08, a0);
}
/* localdecomp:end func_L39_0053E740 */
