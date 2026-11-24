#include "common.h"

/* localdecomp:start func_L01_00374630 */
extern s32 func_0038CAD0(void *);
extern void func_L01_003743C8(void *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_00374630(u8 *obj) {
    u8 *v = *(u8 **)(obj + 104);
    u8 *m;

    if (func_0038CAD0(v + 84) != 0) {
        return;
    }
    func_L01_003743C8(obj);
    func_L01_003743C8(obj);
    m = v + 16;
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 11, 0x3F204090, 1, 0.9f, 0.08f, 0.0f);
    func_003D9508(m, 65, 0x3F909090, 1, 1.0f, 0.0f, func_003824E0(30.0f, 60.0f) * 0.017453292f);
}
/* localdecomp:end func_L01_00374630 */

LINKER_REMNANT("asm/levels", func_L01_00374770);

/* localdecomp:start func_L01_00374790 */
typedef int u128_374790 __attribute__((mode(TI)));

typedef struct {
    f32 dir_pos[4];   /* 0x00 */
    f32 pad10[4];
    u128_374790 color;     /* 0x20 */
    f32 f30;
    s32 x34;
    void *owner;      /* 0x38 */
    u8 pad3c[0x4C - 0x3C];
    s32 x4c;
    u8 pad50[4];
    s32 x54;
    u8 pad58[4];
    s32 x5c;
    u8 pad60[4];
    s32 x64;
    f32 size;         /* 0x68 */
    s32 x6c;
    f32 x70;
    f32 x74;
    s32 x78;
    s32 x7c;
    s32 x80;
    u8 pad84[8];
    s32 x8c;
    f32 f90;
    s32 x94;
} R_374790;

typedef struct {
    u8 pad0[0x10];
    u128_374790 pos;       /* 0x10 */
    u8 x20;
    u8 pad21[0xF];
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 flags;        /* 0x34 */
    u8 pad36[0x68 - 0x36];
    R_374790 *state;  /* 0x68 */
    u8 pad6c[0x98 - 0x6C];
    s32 x98;
} M_374790;

extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(f32, void *, void *);
extern s32 func_L01_004C85C8(void *, f32, f32, f32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004AA7E8(void *, s32);
typedef struct { s32 w[0x2900 / 4]; } Hw_374790;
extern Hw_374790 D_001A4BE0;

/* rift_spawn: spawn the Rift Inducer's rift (class 0x186B) from the gun */
M_374790 *func_L01_00374790(void *owner, u128_374790 *pos, u128_374790 *dir, f32 size) {
    M_374790 *m = (M_374790 *)func_003C24B0(0x186B, 0x700);
    R_374790 *r;
    u128_374790 *mpos;
    u128_374790 col;

    if (m != 0) {
        m->x20 = 0;
        m->x32 = 0xFF;
        m->x30 = 0xFF;
        mpos = &m->pos;
        r = m->state;
        m->pos = *pos;
        *(u128_374790 *)r = *dir;
        r->owner = owner;
        r->f30 = func_00382538();
        r->x34 = 0;
        func_L01_004C7D98(mpos, &r->pad10);
        func_0038CF68(0.1f, &r->pad10, &r->pad10);
        col = *(u128_374790 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xD0);
        r->size = size;
        r->x4c = 0;
        r->x54 = 0;
        r->x5c = 0;
        r->x78 = 0;
        r->x7c = 0;
        r->x80 = 0;
        r->x64 = -1;
        r->x70 = 2.25f;
        r->x74 = 2.25f;
        r->x6c = -1;
        r->color = col;
        r->x8c = func_L01_004C85C8(m, 1.0f, 1.0f, 1.0f, 0);
        r->f90 = func_003824E0(7.0f, 23.0f);
        r->x94 = 0;
        m->x98 = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    return m;
}
/* localdecomp:end func_L01_00374790 */

/* localdecomp:start func_L01_00374908 */
typedef struct S_3738B0 S_3738B0;

typedef struct {
    u8 pad0[0x54];
    S_3738B0 *w54;
} S_3738B0m;

struct S_3738B0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    S_3738B0m *p68;
};

/* the six rift slots are reached from the first one: a scalar here, so the compiler leaves its address to the assembler (lui/addiu in one register) */
extern S_3738B0 *D_L01_001E10E0;
extern f32 func_L01_0040E548(f32 *a0, f32 *a1);

void func_L01_00374908(S_3738B0 *a0, S_3738B0 *a1) {
    S_3738B0m *m;
    S_3738B0m *q;
    S_3738B0 **pp;
    f32 d;
    s32 i;

    if (a0 == 0 || a1 == 0) {
        return;
    }
    m = a0->p68;
    for (i = 0; i < 6; i++) {
        pp = &D_L01_001E10E0 + i;
        if (*pp == 0) {
            continue;
        }
        q = (*pp)->p68;
        if (q == 0 || q->w54 != a1) {
            continue;
        }
        if (m == 0) {
            return;
        }
        d = func_L01_0040E548(a0->pos, a1->pos);
        if (d < func_L01_0040E548((*pp)->pos, a1->pos)) {
            m->w54 = a1;
            q->w54 = 0;
        }
        return;
    }
    m->w54 = a1;
}
/* localdecomp:end func_L01_00374908 */

INCLUDE_ASM("asm/levels", func_L01_003749E8);

LINKER_REMNANT("asm/levels", func_L01_00376170);
