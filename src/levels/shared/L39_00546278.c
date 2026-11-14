#include "common.h"

/* localdecomp:start func_L39_00546278 */
typedef struct Ent_00546278 {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
    f32 f30;
    u8 pad34[4];
    s32 w38;
    u8 pad3C[4];
    f32 f40;
    u8 pad44[4];
    s32 w48;
    u8 pad4C[0x460 - 0x4C];
} Ent_00546278;

typedef struct Aux_00546278 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 pad24CA[0x2534 - 0x24CA];
    void *p2534;
} Aux_00546278;

typedef struct Sub_00546278 {
    u8 pad0[0x2D8];
    Aux_00546278 *p2D8;
    Aux_00546278 *p2DC;
} Sub_00546278;

typedef struct Obj_00546278 {
    u8 pad0[0x384];
    Sub_00546278 *p384;
} Obj_00546278;

typedef struct Self_00546278 {
    u8 pad0[0x68];
    Obj_00546278 *p68;
} Self_00546278;

extern Ent_00546278 D_L39_0024DE80[];
extern s32 func_L01_003F1F20(s32, void *);
extern s32 func_L39_005F33E0(s32, s32, void *);

void func_L39_00546278(Self_00546278 *self) {
    Obj_00546278 *o = self->p68;
    Aux_00546278 *m = o->p384->p2D8;
    s32 idx;

    if (m != 0) {
        if (m->b1A14 != 0) {
            func_L01_003F1F20(0x12, m->p2534);
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->f20 = 0.5f;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->w28 = 0x19;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->w2C = 0;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->f30 = 0.2f;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->w38 = 0x19;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->w2C = 0;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->f40 = 0.02f;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->w48 = 0x19;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DE80))->w2C = 0;
        }
    }
    m = o->p384->p2DC;
    idx = -1;
    if (m != 0) {
        if (m->b1A14 != 0) {
            func_L01_003F1F20(0x12, m->p2534);
            idx = m->b24C9;
        }
    }
    if (idx >= 0) {
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DE80))->w28 = 0x19;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DE80))->w38 = 0x19;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DE80))->f20 = 0.5f;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DE80))->f30 = 0.2f;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DE80))->f40 = 0.02f;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DE80))->w48 = 0x19;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DE80))->w2C = 0;
    }
    func_L39_005F33E0(6, 0, self);
}
/* localdecomp:end func_L39_00546278 */

INCLUDE_ASM("asm/levels", func_L39_00546428);

/* localdecomp:start func_L39_00546B38 */
typedef struct Pl_00546B38 {
    u8 pad0[0x2D0];
    s32 f2D0;
    u8 pad1[0x19E6 - 0x2D4];
    u8 f19E6;
    u8 pad2[0x1A14 - 0x19E7];
    u8 f1A14;
} Pl_00546B38;
typedef struct Obj_00546B38 {
    u8 pad0[0x2D8];
    Pl_00546B38 *f2D8;
    Pl_00546B38 *f2DC;
    u8 pad1[0x328 - 0x2E0];
    s32 f328;
} Obj_00546B38;
typedef struct Pv_00546B38 {
    void *f0;
    u8 pad0[0x62 - 0x4];
    u8 f62;
    u8 pad1[0x308 - 0x63];
    s32 f308[18];
    u8 pad2[0x382 - 0x350];
    u8 f382;
    u8 pad3;
    Obj_00546B38 *f384;
    u8 pad4[0x3AC - 0x388];
    s32 f3AC;
    u8 pad5[0x3D0 - 0x3B0];
    s32 f3D0;
    u8 pad6[0x430 - 0x3D4];
    s8 f430;
    s8 f431;
    s8 f432;
    s8 f433;
    s32 f434;
    s32 f438;
} Pv_00546B38;
typedef struct Cls_00546B38 {
    u8 pad0[0x46];
    u8 f46;
} Cls_00546B38;
typedef struct Self_00546B38 {
    u8 pad0[0x10];
    u8 pos[8];
    f32 f18;
    u8 pad1[0x23 - 0x1C];
    u8 f23;
    Cls_00546B38 *pclass;
    u8 pad2[0x30 - 0x28];
    u8 f30;
    u8 f31;
    s16 f32;
    u16 flags;
    u8 pad3[0x68 - 0x36];
    Pv_00546B38 *pv;
    u8 pad4[0x6F - 0x6C];
    u8 f6F;
    u8 pad5[0x90 - 0x70];
    Obj_00546B38 *f90;
    u8 pad6[0x95 - 0x94];
    u8 state;
    u8 pad7[0x98 - 0x96];
    s32 f98;
    u8 pad8[0xBC - 0x9C];
    u8 fBC;
    u8 pad9;
    u8 fBE;
} Self_00546B38;

extern u8 *D_L39_0024BF5C;
extern Self_00546B38 *D_L39_0024AEC0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AEC0, 4");
extern Self_00546B38 *D_L39_0024AEC0_00546B38[] __attribute__((section(".sdata")));
extern s32 D_L39_0024BB90;
extern u8 D_L39_004997E0[];
__asm__(".extern D_001D5F30_sda, 4");
extern s8 *D_001D5F30_sda;

extern void func_003C2880(void *);
extern void func_L39_00668CD8(void *, void *, f32);
extern void func_L39_00668C90(s32, void *, void *, void *, void *, void *, void *, void *);
extern Obj_00546B38 *func_L39_00666FB8(s32, void *, u32, s32, s32, f32);
extern void func_L39_0061C1E0(void *, s32);
extern void func_L39_00543818(void *);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L39_00546428(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern Pl_00546B38 *func_L39_0061BF38(s32);
extern void func_L39_00543238();
extern void func_L39_00543278();
extern void func_L39_00543410();
extern void func_L01_00423020_00546B38();
extern void func_L39_005437C8();
extern void func_L39_00545B20();
extern void func_L39_00546278();

void func_L39_00546B38(Self_00546B38 *self)
{
    Pv_00546B38 *pv = self->pv;
    Obj_00546B38 *obj;
    s32 v;

    if (pv->f62 == 1) {
        func_003C2880(self);
        return;
    }
    obj = pv->f384;
    switch (self->state) {
    case 0: {
        u8 *mobys = D_L39_0024BF5C;
        s32 i;
        for (i = 0; i < 18; i++) {
            v = pv->f308[i];
            if (v != -1) {
                Self_00546B38 *m = (Self_00546B38 *)(mobys + (v << 8));
                m->f98 = 0;
                m->flags |= 0x41;
            }
        }
        self->f32 = 0x1FF;
        self->f30 = 0xFF;
        if (D_L39_0024AEC0[0] == 0)
            D_L39_0024AEC0[0] = self;
        else if (D_L39_0024AEC0_00546B38[1] == 0)
            D_L39_0024AEC0_00546B38[1] = self;
        func_L39_00668CD8(self, self->pos, 2.5f);
        self->f18 += 1.0f;
        pv->f0 = (u8 *)pv + 0x30;
        self->flags |= 0x5820;
        self->pclass->f46 = 5;
        func_L39_00668C90(1, func_L39_00543238, func_L39_00543278, func_L39_00543410, func_L01_00423020_00546B38, func_L39_005437C8, func_L39_00545B20, func_L39_00546278);
        self->f90 = pv->f384 = func_L39_00666FB8(1, self, 0xFFFFFFFF, 3000, 0x8000000, 2.5f);
        self->fBE &= 0xE7;
        func_L39_0061C1E0(self, -1);
        func_L39_00543818(self);
        if (pv->f3D0 != 0) {
            if (D_001D5F30_sda[0x189] == 0)
                pv->f3D0 = 0;
        }
        if (pv->f3D0 == 0)
            self->fBC = 8;
        pv->f431 = pv->f430 = pv->f432 = -1;
        pv->f433 = -1;
        pv->f434 = 2;
        pv->f438 = 0;
        pv->f382 = 0;
        break;
    }
    case 2:
        if (obj->f2DC == 0 && pv->f3AC >= 0) {
            D_L39_0024BB90 = 0;
            func_L01_003EB5E0(pv->f3AC, 0);
            self->f23 = 0x80;
            self->flags &= 0xF7FF;
            pv->f3AC = -1;
        }
        break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    }
    func_L39_00546428(self);
    if (self->fBC != 10 && self->f31 != 0) {
        if (func_L01_0040E548(D_L39_0024DE80, self->pos) < 484.0f) {
            func_L01_004472C0(self);
            self->f6F = 20;
        }
    }
    if (obj != 0) {
        if (obj->f328 != 0) {
            pv->f382 = obj->f328;
            obj->f328 = 0;
        }
        if (obj->f2D8 != 0) {
            if (obj->f2D8->f1A14 != 0)
                D_L39_0024BB90 = 2;
        }
        if (obj->f2DC != 0) {
            if (obj->f2DC->f1A14 != 0)
                D_L39_0024BB90 = 2;
        }
    }
    if (pv->f382 != 0) {
        Pl_00546B38 *pl = func_L39_0061BF38(pv->f382 - 1);
        if (pl != 0 && pl->f2D0 != 0) {
            u32 w[2];
            u32 c;
            u8 *pp = &pl->f19E6;
            if (pl->f19E6 == 0) {
                c = 0;
            } else {
                s32 n = pl->f19E6;
                s32 k = ((u32)pp - n) & 7;
                s32 i;
                u8 *b = (u8 *)w;
                s32 m = n + 1;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                w[0] ^= (u32)pp;
                w[1] ^= w[0];
                c = w[1];
            }
            if ((c ^ 0x14) != 0) {
                pv->f382 = 0;
                D_L39_0024BB90 = 0;
                return;
            }
        }
        D_L39_0024BB90 = 2;
    }
}
/* localdecomp:end func_L39_00546B38 */
