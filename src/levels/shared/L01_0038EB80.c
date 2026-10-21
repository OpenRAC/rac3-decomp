#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} G391938A;
typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G391938B;
typedef struct {
    u8 pad0[36];
    s32 unk24;
} V391938;
typedef struct {
    u8 pad0[104];
    V391938 *pVars;
} M391938;
typedef int s128 __attribute__((mode(TI)));
typedef union {
    s128 q;
    f32 f[4];
} V_003919E0;
typedef struct { u8 pad0[48]; s32 id; u8 pad1[28]; } Ent_00312A80;
typedef struct {
    u8 pad0[52];
    f32 f34;
    u8 pad38[72 - 56];
    f32 f48;
    u8 pad4C[96 - 76];
    s32 w60;
    u8 pad64[104 - 100];
    s32 w68;
    u8 pad6C[112 - 108];
    s32 w70;
    u8 pad74[124 - 116];
    s32 w7C;
} S_393258;

INCLUDE_ASM("asm/levels", func_L01_0038EB80);

INCLUDE_ASM("asm/levels", func_L01_0038F3F8);

INCLUDE_ASM("asm/levels", func_L01_0038F728);

/* localdecomp:start func_L01_0038FCA8 */
void func_L01_0038FCA8(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_0038FCA8 */

INCLUDE_ASM("asm/levels", func_L01_0038FCB8);

INCLUDE_ASM("asm/levels", func_L01_003900F8);

INCLUDE_ASM("asm/levels", func_L01_00390240);

INCLUDE_ASM("asm/levels", func_L01_00390358);

INCLUDE_ASM("asm/levels", func_L01_00390A40);

INCLUDE_ASM("asm/levels", func_L01_00390AB8);

LINKER_REMNANT("asm/levels", func_L01_003912D0);

INCLUDE_ASM("asm/levels", func_L01_003912E0);

INCLUDE_ASM("asm/levels", func_L01_00391610);

/* localdecomp:start func_L01_003916E0 */
extern s32 D_L01_001DDFE8;

void func_L01_003916E0(void) { D_L01_001DDFE8 = 0; }
/* localdecomp:end func_L01_003916E0 */

INCLUDE_ASM("asm/levels", func_L01_003916E8);

INCLUDE_ASM("asm/levels", func_L01_00391938);

INCLUDE_ASM("asm/levels", func_L01_00391A80);

INCLUDE_ASM("asm/levels", func_L01_00391BD0);

INCLUDE_ASM("asm/levels", func_L01_00391D88);

INCLUDE_ASM("asm/levels", func_L01_00391EC8);

INCLUDE_ASM("asm/levels", func_L01_00391F98);

/* localdecomp:start func_L01_00392040 */
void func_L01_00392040(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00392040 */

/* localdecomp:start func_L01_003920C8 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_003920C8(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_003920C8 */

INCLUDE_ASM("asm/levels", func_L01_00392130);

/* localdecomp:start func_L01_003922E0 */
s32 func_L01_003922E0(s32 n) {
    s32 a = 16;
    if (n % a != 0) {
        n = ((s32)((f32)n / (f32)a) + 1) * a;
    }
    return n;
}
/* localdecomp:end func_L01_003922E0 */

INCLUDE_ASM("asm/levels", func_L01_00392328);

INCLUDE_ASM("asm/levels", func_L01_00392908);

/* localdecomp:start func_L01_00392A78 */
extern s32 D_L01_001DE000;

void func_L01_00392A78(void) { D_L01_001DE000 = 0; }
/* localdecomp:end func_L01_00392A78 */

INCLUDE_ASM("asm/levels", func_L01_00392A80);

INCLUDE_ASM("asm/levels", func_L01_00392A90);

/* localdecomp:start func_L01_00392D80 */




extern G391938A D_001A1ED0;
extern G391938B D_001CFEC0;
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, s32);

void func_L01_00392D80(M391938 *m) {
    V391938 *v = m->pVars;

    if (v->unk24 != 0) {
        func_003A9440(78, (long)((D_001A1ED0.unk8 >> 13) | 0x1000000) | 0x100000000);
        func_0038AF30(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, (v->unk24 << 24) | 0xFFFFFF);
        func_003A9440(78, 0x1000000 | (D_001A1ED0.unk8 >> 13));
    }
}
/* localdecomp:end func_L01_00392D80 */

/* localdecomp:start func_L01_00392E28 */
extern void func_L01_00393E90(s32 id);
extern void func_L01_00392D80(M391938 *m);


extern s32 func_L01_00457458(s32, s32);
extern void func_L01_00392A80(void);
extern void func_003C2880(u8 *);
extern s32 func_L01_00459590(V_003919E0 *, s32, f32);
extern void func_L01_00392F08(u8 *);
extern void func_L01_00393150(u8 *);
extern void func_L01_00393390(u8 *);
extern void func_L01_003937E8(u8 *);

void func_L01_00392E28(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    V_003919E0 t;
    if (a0 == 0) {
        return;
    }
    if (a0[32] == 254) {
        return;
    }
    if (a0[32] == 253) {
        return;
    }
    if (v == 0) {
        return;
    }
    if (func_L01_00457458(*(s16 *)(a0 + 170), *(s32 *)(v + 40)) == 0) {
        func_L01_00392A80();
        func_003C2880(a0);
        return;
    }
    t.q = *(s128 *)(a0 + 16);
    t.f[3] = 2.0f;
    if (func_L01_00459590(&t, 0, 100.0f) == -1) {
        return;
    }
    if (a0[32] != 6) {
        func_L01_00392F08(a0);
        func_L01_00393150(a0);
        ((void (*)(u8 *))func_L01_00392D80)(a0);
    }
    func_L01_00393390(a0);
    func_L01_003937E8(a0);
    ((void (*)(u8 *))func_L01_00393E90)(a0);
}
/* localdecomp:end func_L01_00392E28 */

INCLUDE_ASM("asm/levels", func_L01_00392F08);

INCLUDE_ASM("asm/levels", func_L01_00393150);

INCLUDE_ASM("asm/levels", func_L01_00393390);

INCLUDE_ASM("asm/levels", func_L01_003937E8);

INCLUDE_ASM("asm/levels", func_L01_00393C80);

/* localdecomp:start func_L01_00393DA8 */
extern u8 *D_L01_001E2018;
extern s32 func_0038CAD0(void *);
extern s32 func_0013D3E0(void);
extern void func_L01_00393EF8(void *, s32, f32, f32, s32);
extern void func_L01_00394390(void *);

void func_L01_00393DA8(s32 a0) {
    s32 i;
    for (i = 0; i < 1; i++) {
        u8 *e = (u8 *)(i * 80 + (s32)D_L01_001E2018);
        if (*(s32 *)(e + 48) == a0) {
            if (func_0038CAD0(e + 52) != 0) {
                if (*(s32 *)(e + 56) == 0) {
                    *(s32 *)(e + 48) = 0;
                }
            } else if (!(func_0013D3E0() & 1)) {
                func_L01_00393EF8(e, 0, 0.0f, 0.0f, 0);
                func_L01_00393EF8(e, 0, 0.0f, 0.0f, 0);
            }
            func_L01_00394390(e);
        }
    }
}
/* localdecomp:end func_L01_00393DA8 */

/* localdecomp:start func_L01_00393E90 */
extern void func_L01_003946B8(s32 id);
extern u8 *D_L01_001E2018;
void func_L01_00393E90(s32 id) {
    s32 i;
    for (i = 0; i < 1; i++) {
        if ((*(Ent_00312A80 * *)&D_L01_001E2018)[i].id == id) ((void (*)(Ent_00312A80 *))func_L01_003946B8)(&(*(Ent_00312A80 * *)&D_L01_001E2018)[i]);
    }
}
/* localdecomp:end func_L01_00393E90 */

INCLUDE_ASM("asm/levels", func_L01_00393EF8);

INCLUDE_ASM("asm/levels", func_L01_00394390);

/* localdecomp:start func_L01_003946B8 */

extern S_393258 *D_L01_001E201C;
extern void func_L01_00394828(S_393258 *a0, f32 f12, s32 a1, s32 a2, f32 f13, s32 a3, s32 t0, f32 f14);

void func_L01_003946B8(s32 id) {
    s32 i;
    S_393258 *p;
    for (i = 0; i < 300; i++) {
        if (D_L01_001E201C[i].w7C == id) {
            p = &D_L01_001E201C[i];
            func_L01_00394828(p, p->f48, p->w68, p->w60, p->f34, 46, p->w70, 0.25f);
        }
    }
}
/* localdecomp:end func_L01_003946B8 */

/* localdecomp:start func_L01_00394738 */
void func_L01_00394738(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00394738 */

/* localdecomp:start func_L01_003947C0 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_003947C0(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_003947C0 */

INCLUDE_ASM("asm/levels", func_L01_00394828);

INCLUDE_ASM("asm/levels", func_L01_003949E8);

INCLUDE_ASM("asm/levels", func_L01_00394AF0);

INCLUDE_ASM("asm/levels", func_L01_00395020);

INCLUDE_ASM("asm/levels", func_L01_00395288);

LINKER_REMNANT("asm/levels", func_L01_00395480);

/* localdecomp:start func_L01_00395498 */
s32 func_L01_00395498(s32 n) {
    s32 a = 16;
    if (n % a != 0) {
        n = ((s32)((f32)n / (f32)a) + 1) * a;
    }
    return n;
}
/* localdecomp:end func_L01_00395498 */

INCLUDE_ASM("asm/levels", func_L01_003954E0);

/* localdecomp:start func_L01_003968E8 */
void func_L01_003968E8(u8 *a) {
    a[0x20] = 5;
}
/* localdecomp:end func_L01_003968E8 */

INCLUDE_ASM("asm/levels", func_L01_003968F8);

LINKER_REMNANT("asm/levels", func_L01_00396B68);
