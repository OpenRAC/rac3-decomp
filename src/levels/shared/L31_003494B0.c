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

/* localdecomp:start func_L31_003494B0 */
typedef int u128_003494B0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x24];
    f32 unk24;
} Cls_003494B0;

typedef struct {
    u8 pad0[0xA0];
    s32 unkA0;
    u8 padA4[0xB8 - 0xA4];
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
} Vars_003494B0;

typedef struct {
    u8 pad0[0x10];
    u128_003494B0 pos;
    u8 pad20[0x24 - 0x20];
    Cls_003494B0 *cls;
    u8 pad28[0x2C - 0x28];
    f32 scale;
    u8 unk30;
    u8 pad31;
    s16 unk32;
    u8 pad34[0x68 - 0x34];
    Vars_003494B0 *vars;
} Moby_003494B0;

extern Moby_003494B0 *func_003C24B0(s32, s32);
extern void func_L31_00348FE8(void *, s32);

Moby_003494B0 *func_L31_003494B0(u128_003494B0 *pos, s32 a1) {
    Moby_003494B0 *m = func_003C24B0(0x1644, 0xD0);
    Vars_003494B0 *v;

    if (m == 0) {
        return 0;
    }
    m->unk30 = 0xFF;
    m->unk32 = 0x40;
    m->scale = m->cls->unk24 * 1.5f;
    v = m->vars;
    m->pos = *pos;
    v->unkA0 = 3;
    v->unkC0 = a1;
    v->unkBC = -1;
    v->unkB8 = 0;
    func_L31_00348FE8(m, 0);
    return m;
}
/* localdecomp:end func_L31_003494B0 */

/* localdecomp:start func_L31_00349560 */
typedef struct {
    u8 pad0[0x28];
    s32 unk28;
    s32 unk2C;
    f32 unk30;
    u8 pad34[0x40 - 0x34];
    u8 unk40[4];
    s32 unk44;
} Vars_00349560;

typedef struct {
    u8 pad0[0x10];
    f32 unk10[4];
    u8 unk20;
    u8 pad21[0x48 - 0x21];
    f32 unk48;
    u8 pad4C[0x68 - 0x4C];
    Vars_00349560 *vars;
    u8 pad6C[0xF0 - 0x6C];
    f32 unkF0[4];
} Moby_00349560;

extern s32 D_L31_001DF340 __attribute__((section(".data")));
extern s32 D_L31_001DD0D4;
extern f32 D_L31_001DD098;
__asm__(".extern D_L31_001DD0D4, 4");
__asm__(".extern D_L31_001DD098, 4");
extern void func_L31_00349A18(void);
extern void func_L31_003496E8(void *);
extern void func_L31_00349D18(Obj_00349D18 *o, f32 *out1, f32 *out2, f32 t);
extern void func_L31_00349DD0(void *, f32);
extern void func_L31_003498F8(u8 *);
extern void func_L30_0034DAC0(void *);
extern void func_L31_00349830(s32);
extern void func_L31_00349868(u8 *);

void func_L31_00349560(Moby_00349560 *m) {
    Vars_00349560 *v = m->vars;

    if (v->unk44 != 0) {
        return;
    }
    if (m->unk20 == 0) {
        func_L31_00349A18();
    }
    func_L31_003496E8(m);
    switch (m->unk20) {
    case 1:
        func_L31_00349D18((Obj_00349D18 *)m, m->unk10, m->unkF0,
                          v->unk28 ? (v->unk2C ? 1.0f - v->unk30 : v->unk30) : v->unk30);
        if (D_L31_001DF340 % D_L31_001DD0D4 == 0) {
            func_L31_00349DD0(m, v->unk28 ? (v->unk2C ? 1.0f - v->unk30 : v->unk30) : v->unk30);
        }
        func_L31_003498F8((u8 *)m);
        break;
    case 2:
        if (D_L31_001DF340 % D_L31_001DD0D4 == 0) {
            func_L31_00349DD0(m, v->unk28 ? (v->unk2C ? 1.0f - v->unk30 : v->unk30) : v->unk30);
        }
        func_L31_003498F8((u8 *)m);
        break;
    case 0x42:
        func_L30_0034DAC0(v->unk40);
        break;
    }
    func_L31_00349830((s32)m);
    func_L31_00349868((u8 *)m);
    m->unk48 = D_L31_001DD098;
}
/* localdecomp:end func_L31_00349560 */

INCLUDE_ASM("asm/levels", func_L31_003496E8);

/* localdecomp:start func_L31_00349830 */
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);
void func_L31_00349830(s32 a0) {
    func_L30_0034CB68(a0, D_L31_001D66B0, 1, -1, 0, 0, D_L31_001DD09C, D_L31_001DD0A0);
}
/* localdecomp:end func_L31_00349830 */

/* localdecomp:start func_L31_00349868 */
typedef int u128_00349868 __attribute__((mode(TI)));
typedef union {
    u128_00349868 q;
    f32 f[4];
} Pos_00349868;

typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    u8 pad34[0x40 - 0x34];
    u8 unk40[0x10];
} Vars_00349868;

extern f32 D_L31_001DD0A8;
extern f32 D_L31_001DD0BC;
extern s32 D_L31_001DD0B4;
extern s32 D_L31_001DD0B8;
extern f32 D_L31_001DD0C0;
extern f32 D_L31_001DD0C4;
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);

void func_L31_00349868(u8 *m) {
    Pos_00349868 pos;
    Vars_00349868 *v;
    f32 r;
    s32 c;

    v = *(Vars_00349868 **)(m + 0x68);
    pos.q = *(u128_00349868 *)(m + 0x10);
    pos.f[2] += D_L31_001DD0A8 * 0.5f;
    r = func_0038D0B0(func_0038DB48(D_L31_001DD0BC * v->unk30));
    c = func_0038DBD8(r * 0.5f + 0.5f, D_L31_001DD0B4, D_L31_001DD0B8);
    func_L30_0034CF28(&pos, v->unk40, c, D_L31_001DD0C0, D_L31_001DD0C4);
}
/* localdecomp:end func_L31_00349868 */

INCLUDE_ASM("asm/levels", func_L31_003498F8);

INCLUDE_ASM("asm/levels", func_L31_00349A18);
