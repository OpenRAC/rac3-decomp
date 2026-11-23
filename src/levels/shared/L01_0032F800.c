#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L01_0032F800 */
typedef int s128_0032F800 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x48];
    s32 w48;
} S_32F800m;
typedef struct {
    u8 pad0[0x68];
    S_32F800m *p68;
} S_32F800;
extern u8 *func_L01_004C80D0(s32 a0);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C47E8(void *, void *);
extern void func_003C2F58(void *, s32, void *);

void func_L01_0032F800(S_32F800 *a0, s128_0032F800 *a1) {
    struct { s128_0032F800 a, b, c, d, e, f, g; } L;
    u8 *r;

    r = func_L01_004C80D0(a0->p68->w48);
    L.a = L.d = *a1;
    L.e = 0;
    ((f32 *)&L.e)[2] = 1.0f;
    func_0038CE90(&L.b, &L.a, &L.e);
    func_0038CF68(&L.b, &L.b, 1.0f);
    func_0038CE90(&L.c, &L.b, &L.a);
    func_003C47E8(r + 0x10, &L.a);
    func_003C2F58(a0, 0, &L.f);
    func_0038D000(&L.d, a1, (u8 *)a0 + 0xC0);
    vec_add_ab(&L.g, &L.d, &L.f);
}
/* localdecomp:end func_L01_0032F800 */

INCLUDE_ASM("asm/levels", func_L01_0032F8E8);

/* localdecomp:start func_L01_0032FB18 */
extern s32 D_L01_00278990[];

void func_L01_0032FB18(void)
{
    int i;
    D_L01_00278990[138] = 5;
    D_L01_00278990[137] = 0;
    D_L01_00278990[136] = 0;
    for (i = 0; i < 64; ++i) {
        D_L01_00278990[i] = 0;
        D_L01_00278990[i + 64] = 0;
    }
    for (i = 7; i >= 0; --i)
        D_L01_00278990[i + 128] = 0;
}
/* localdecomp:end func_L01_0032FB18 */
