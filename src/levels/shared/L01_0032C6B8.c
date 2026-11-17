#include "common.h"
#include "vu0.h"


INCLUDE_ASM("asm/levels", func_L01_0032C6B8);

INCLUDE_ASM("asm/levels", func_L01_0032C7A0);

/* localdecomp:start func_L01_0032C9F0 */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 q0;
    s128 q10;
    f32 f20;
    s32 w24;
    u8 pad28[0x30 - 0x28];
} S_277090;
typedef struct {
    s32 a[0x40];
    s32 b[0x40];
    s32 c[8];
    s32 w220;
    s32 w224;
    s32 w228;
} S_276E60;
extern S_277090 D_L01_00277090[];
extern S_276E60 D_L01_00276E60[];

void func_L01_0032C9F0(void) {
    s32 i;
    S_276E60 *p;

    for (i = 99; i >= 0; i--) {
        D_L01_00277090[i].w24 = 0;
    }
    p = D_L01_00276E60;
    p->w228 = 5;
    p->w224 = 0;
    p->w220 = 0;
    for (i = 0; i < 64; i++) {
        p->a[i] = 0;
        p->b[i] = 0;
    }
    for (i = 7; i >= 0; i--) {
        D_L01_00276E60->c[i] = 0;
    }
}
/* localdecomp:end func_L01_0032C9F0 */

/* localdecomp:start func_L01_0032CA80 */
extern void func_L01_004CAE90(void *a0);

void func_L01_0032CA80(void) {
    func_L01_004CAE90(D_L01_00276E60);
}
/* localdecomp:end func_L01_0032CA80 */

/* localdecomp:start func_L01_0032CAA0 */
typedef struct {
    u8 pad0[0x66];
    u16 h66;
} S_32CAA0m;
typedef struct {
    u8 pad0[0x68];
    S_32CAA0m *p68;
} S_32CAA0;
extern void func_003C2F58(void *, s32, void *);

void func_L01_0032CAA0(S_32CAA0 *a0, s128 *a1) {
    s128 v;
    S_32CAA0m *m;
    S_277090 *e;
    s32 i;

    m = a0->p68;
    func_003C2F58(a0, 1, &v);
    for (i = 0; i < 100; i++) {
        if (D_L01_00277090[i].w24 == 0) {
            e = &D_L01_00277090[i];
            m->h66++;
            e->w24 = (s32)a0;
            e->f20 = 100.0f;
            e->q10 = *a1;
            e->q0 = v;
            break;
        }
    }
}
/* localdecomp:end func_L01_0032CAA0 */

INCLUDE_ASM("asm/levels", func_L01_0032CB38);

/* localdecomp:start func_L01_0032CE18 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0032DB08(void *, void *, void *);

void func_L01_0032CE18(void *a0) {
    u8 v[16];
    S_277090 *e;
    s32 i;

    for (i = 0; i < 100; i++) {
        e = &D_L01_00277090[i];
        if (e->w24 == (s32)a0) {
            func_0038CF68(v, &e->q10, 2.1f);
            vec_sub_ba(v, e, v);
            func_L01_0032DB08(a0, e, v);
        }
    }
}
/* localdecomp:end func_L01_0032CE18 */

INCLUDE_ASM("asm/levels", func_L01_0032CEB8);

/* localdecomp:start func_L01_0032CF48 */
typedef struct { u8 p0[0x68]; u8 *w68; } M_32CAB0;
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032D348(M_32CAB0 *);
extern void func_L01_0032CE18(void *);

void func_L01_0032CF48(M_32CAB0 *m) {
    if (func_0038CAD0(m->w68 + 68) == 0) {
        func_L01_0032D348(m);
    }
    func_L01_0032CE18(m);
}
/* localdecomp:end func_L01_0032CF48 */

INCLUDE_ASM("asm/levels", func_L01_0032CF90);

INCLUDE_ASM("asm/levels", func_L01_0032D348);

INCLUDE_ASM("asm/levels", func_L01_0032D7E8);

INCLUDE_ASM("asm/levels", func_L01_0032DB08);

INCLUDE_ASM("asm/levels", func_L01_0032DED0);

/* localdecomp:start func_L01_0032E2B0 */
void func_L01_0032E2B0(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 8U) {
        *(u8 *)((u8 *)arg0 + 0x20) = 8U;
    }
}
/* localdecomp:end func_L01_0032E2B0 */

INCLUDE_ASM("asm/levels", func_L01_0032E2D0);

INCLUDE_ASM("asm/levels", func_L01_0032EE48);

INCLUDE_ASM("asm/levels", func_L01_0032EF88);

INCLUDE_ASM("asm/levels", func_L01_0032F020);

/* localdecomp:start func_L01_0032F0D8 */
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
extern s32 D_L01_001EAA1C[];

void func_L01_0032F0D8(u8 *a0) {
    f32 v[4];

    func_003C2F58(a0, 0, v);
    if (func_L01_003FB640(v, 2, a0, 0.25f) && D_L01_001EAA1C[0] > 0) {
        a0[32] = 8;
    }
}
/* localdecomp:end func_L01_0032F0D8 */

INCLUDE_ASM("asm/levels", func_L01_0032F138);

INCLUDE_ASM("asm/levels", func_L01_0032F1B8);

INCLUDE_ASM("asm/levels", func_L01_0032F3E0);

INCLUDE_ASM("asm/levels", func_L01_0032F4E0);
