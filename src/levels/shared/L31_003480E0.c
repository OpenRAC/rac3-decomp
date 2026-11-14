#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

INCLUDE_ASM("asm/levels", func_L31_003480E0);

/* localdecomp:start func_L31_00348BD8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00348BD8;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x70 - 0x34];
    u8 f70[7];
    u8 f77;
    u8 pad78[0x90 - 0x78];
    V4_00348BD8 f90;
    u8 padA0[4];
    s32 fA4;
    u8 padA8[0xC8 - 0xA8];
    u8 fC8[4];
    s32 fCC;
} P_00348BD8;

typedef struct {
    u8 pad0[0xAA];
    s16 fAA;
} C_00348BD8;

typedef struct {
    u8 pad0[0x10];
    V4_00348BD8 f10;
    C_00348BD8 *f20;
    u8 pad24[0x2C - 0x24];
    f32 f2C;
} T_00348BD8;

typedef struct {
    u8 pad0[0x14];
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    u8 f20;
    u8 pad21[0x68 - 0x21];
    P_00348BD8 *f68;
    u8 pad6C[0x94 - 0x6C];
    u8 f94;
    u8 pad95;
    u16 f96;
    u8 pad98[0xA8 - 0x98];
    u8 fA8;
} M_00348BD8;

extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
extern void *func_L01_00447490(void *, u32, s32);
extern void func_003C4A40(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_00348FE8(void *, s32);
extern void func_L31_003473F0(void *, f32, f32);

extern s32 D_L31_001DF340;
extern s32 D_L31_001DD050;
extern s32 D_L31_001DD048;
extern s32 D_L31_001DD04C;
extern s32 D_L31_001DD064;
extern f32 D_L31_001DD05C;
extern f32 D_L31_001DD060;
extern s32 D_L31_001DD054;
extern s32 D_L31_001DD058;
extern f32 D_L31_001DD02C;
extern f32 D_L31_001DD020;
extern f32 D_L31_001DD074;
extern f32 D_L31_001DD070;
typedef struct {
    u8 pad0[0x84];
    f32 f84;
    u8 pad88[0x25C0 - 0x88];
    C_00348BD8 *f25C0;
} G_00348BD8;
extern G_00348BD8 D_001A4BE0;
__asm__(".extern D_L31_001DD050, 4");
__asm__(".extern D_L31_001DD048, 4");
__asm__(".extern D_L31_001DD04C, 4");
__asm__(".extern D_L31_001DD064, 4");
__asm__(".extern D_L31_001DD05C, 4");
__asm__(".extern D_L31_001DD060, 4");
__asm__(".extern D_L31_001DD054, 4");
__asm__(".extern D_L31_001DD058, 4");
__asm__(".extern D_L31_001DD02C, 4");
__asm__(".extern D_L31_001DD020, 4");
__asm__(".extern D_L31_001DD074, 4");
__asm__(".extern D_L31_001DD070, 4");

void func_L31_00348BD8(M_00348BD8 *o) {
    P_00348BD8 *p = o->f68;
    T_00348BD8 *t;
    V4_00348BD8 tmp;
    V4_00348BD8 a;
    V4_00348BD8 b;
    f32 f;

    func_0038CAD0(&p->fA4);
    func_L01_0044ABD0(o, p->f70);
    func_003C2F58(o, 1, &a);
    p->fCC = func_0038DBD8(D_L31_001DD048, D_L31_001DD04C,
        func_0038D098((f32)(D_L31_001DF340 % D_L31_001DD050) / (f32)D_L31_001DD050 * 6.2831855f) * 0.5f + 0.5f);
    f = func_003C4088(D_L31_001DD05C, D_L31_001DD060,
        func_0038D098((f32)(D_L31_001DF340 % D_L31_001DD064) / (f32)D_L31_001DD064 * 6.2831855f) * 0.5f + 0.5f);
    if (o->f20 != 0x42) {
        if (o->f94 != 4 || D_L31_001DD054 < o->f96 || o->f96 < D_L31_001DD058) {
            func_L30_0034CF28(&a, p->fC8, p->fCC, f, 0.0f);
        }
    }
    t = func_L01_00447490(o, 0x10000, 0);
    if (t != 0) {
        o->fA8 = 0xFF;
        if (0.0f < t->f2C && t->f20->fAA != 0x1644 && o->f20 != 0x42 && o->f20 != 2 && p->fA4 <= 0) {
            p->f77 = 0xFF;
            p->f30 = 0.0f;
            p->fA4 = 0xC;
            func_003C4A40(o, p->f70);
            func_003A52A0(5, 0, o);
            if (p->f30 <= 0.0f) {
                if (t->f20 == D_001A4BE0.f25C0) {
                    func_0038CF68(&tmp, &t->f10, D_L31_001DD02C);
                    __asm__ __volatile__(
                        "lqc2 $vf1, 0x90(%0)\n"
                        "lqc2 $vf2, 0(%1)\n"
                        "vadd.xyz $vf1, $vf1, $vf2\n"
                        "sqc2 $vf1, 0x90(%0)\n"
                        : : "r"(p), "r"(&tmp) : "memory");
                }
                func_L31_00348FE8(o, 2);
            } else {
                if (t->f20 == D_001A4BE0.f25C0) {
                    func_0038CF68(&tmp, &t->f10, D_L31_001DD020);
                    __asm__ __volatile__(
                        "lqc2 $vf1, 0x90(%0)\n"
                        "lqc2 $vf2, 0(%1)\n"
                        "vadd.xyz $vf1, $vf1, $vf2\n"
                        "sqc2 $vf1, 0x90(%0)\n"
                        : : "r"(p), "r"(&tmp) : "memory");
                }
                func_L31_00348FE8(o, 9);
            }
        }
    }
    o->f14 = D_001A4BE0.f84;
    if (o->f96 <= 0xFFFE) {
        o->f96++;
    }
    func_003C2F58(o, 4, &b);
    b.z = o->f18;
    if (o->f20 != 0x42 && o->f20 != 2) {
        func_L31_003473F0(&b, D_L31_001DD074, D_L31_001DD070);
    }
}
/* localdecomp:end func_L31_00348BD8 */

/* localdecomp:start func_L31_00348EE8 */
typedef struct {
    u8 pad0[0x24];
    f32 unk24;
} Cls_00348EE8;

typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    s16 unk34;
    u8 pad36[0x44 - 0x36];
    u8 unk44;
    u8 pad45[0x7C - 0x45];
    s16 unk7C;
    s16 unk7E;
    u8 unk80[0xB4 - 0x80];
    f32 unkB4;
    u8 padB8[0xC4 - 0xB8];
    f32 unkC4;
    s32 unkC8;
    s32 unkCC;
} Vars_00348EE8;

typedef struct {
    u8 pad0[0x24];
    Cls_00348EE8 *cls;
    u8 pad28[0x2C - 0x28];
    f32 scale;
    u8 pad30[0x68 - 0x30];
    Vars_00348EE8 *vars;
} Moby_00348EE8;

__asm__(".extern D_L31_001DD06C, 4");
__asm__(".extern D_L31_001DD010, 4");
__asm__(".extern D_L31_001DD048, 4");
extern f32 D_L31_001DD06C;
extern f32 D_L31_001DD010;
extern s32 D_L31_001DD048;
extern void func_L31_00346998(void *, void *);

void func_L31_00348EE8(Moby_00348EE8 *m) {
    Vars_00348EE8 *v = m->vars;

    if (v->unk34 <= 0.0f) {
        v->unk34 = 2;
    }
    v->unk30 = v->unk34;
    if (v->unk44 <= 0.0f) {
        v->unk44 = 1;
    }
    v->unk7C = 4;
    v->unk7E = 15;
    func_L31_00346998(m, v->unk80);
    v->unkB4 = D_L31_001DD06C * m->scale / m->cls->unk24;
    v->unkC4 = D_L31_001DD010 * m->scale / m->cls->unk24;
    v->unkC8 = -1;
    v->unkCC = D_L31_001DD048;
}
/* localdecomp:end func_L31_00348EE8 */
