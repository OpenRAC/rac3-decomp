#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_003C21A0);

INCLUDE_ASM("asm/levels", func_L03_003C2448);

INCLUDE_ASM("asm/levels", func_L03_003C2718);

/* localdecomp:start func_L03_003C2A10 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 pad[0x14 / 4]; s32 i14; s32 i18; } S_003C2A10;
typedef struct { u8 pad[0x42]; u8 f42; u8 pad43[0x25]; S_003C2A10 *p68; } O_003C2A10;
typedef struct { u8 pad[0x70]; u128_t v70; } E_003C2A10;
extern u8 D_001A4BE0[];
extern E_003C2A10 *D_L03_001DFA80;
extern f32 func_L01_004395E0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
void func_L03_003C2A10(O_003C2A10 *o) {
    S_003C2A10 *p = o->p68;
    f32 v[4];
    f32 w[4];
    f32 q1[4];
    f32 q2[4];
    f32 s;
    f32 a;
    if (o->f42 == 1) {
        a = func_L01_004395E0(o);
    } else {
        a = 170.0f;
    }
    s = a / 170.0f;
    if (p->i14 == -1 || p->i18 == -1) {
        u8 *h = D_001A4BE0;
        f32 ang = func_0038DAB8(s * 0.6981317f - 0.34906584f, *(f32 *)(h + 0x98));
        v[0] = func_0038D098(ang) * 5.0f;
        v[1] = func_0038D0B0(ang) * 5.0f;
        v[2] = 0.0f;
        vec_add_ba(v, v, h + 0x80);
        v[2] = v[2] + 1.0f;
        qzero(w);
        w[2] = func_0038DAB8(ang, 3.14159f);
        w[1] = s * -0.17f;
    } else {
        func_0038CDF8(v, (f32 *)((u8 *)D_L03_001DFA80 + (p->i14 << 7) + 0x30), (f32 *)((u8 *)D_L03_001DFA80 + (p->i18 << 7) + 0x30), s);
        *(u128_t *)q1 = D_L03_001DFA80[p->i14].v70;
        *(u128_t *)q2 = D_L03_001DFA80[p->i18].v70;
        w[2] = func_0038DAB8(func_0038DB00(q2[2], q1[2]) * s, q1[2]);
        w[1] = func_0038DAB8(func_0038DB00(q2[1], q1[1]) * s, q1[1]);
        w[0] = func_0038DAB8(func_0038DB00(q2[0], q1[0]) * s, q1[0]);
    }
    func_L01_003EB350(0, v);
    func_L01_003EB3C0(0, w);
}
/* localdecomp:end func_L03_003C2A10 */
