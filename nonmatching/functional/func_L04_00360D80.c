/* functional: medium. Written from the PAL asm only. Update callback of the Marcadia boss-type object (a0 = object, state at +0x68): runs the first-frame setup (func_L04_00361208) until it reports ready, handles the two-part mob pair (this object and the linked one at state+0x2FC: shared flag bits 0x40/0x1/0x1000, owner copy of +0x98), the wake-up/despawn rules by world (D_001D545C: 2 = freeze both, 7/13/0x16 special cases), the one-time spawn of the child object type 0x16E5 (with per-world size/damage scaled by D_002F1D90/D_002F1F70 tables in worlds 4, 9, 0x10), and then the main per-frame work (func_L04_00361DF8) or, failing that, the hit test and its reaction. Unsure: the roles of flags 0x41/0x1000 on +0x34, of the two gp float constants used in world 7, and of D_0014275B/D_0014275C (byte flags); func_L01_00456500's second argument is the register retail leaves (state+0x4EC), made explicit. */
#include "common.h"
#include "vu0.h"

extern s32 D_001D6694;
extern s32 D_001D545C;
extern s32 D_001DD7A4;
extern f32 D_001DA8B0;
extern f32 D_001DA8B8;
extern u8 D_0014275B;
extern u8 D_0014275C;
extern f32 D_L04_002F1D90[];
extern f32 D_L04_002F1F70[];
extern vu0_v4 D_L04_001E27C0;
extern vu0_v4 D_L04_001D66B0;
extern u8 D_L04_001DD7D8[];
extern s32 func_L04_00361208(void *);
extern s32 func_L04_00361DF8(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7C38(void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00446058(void *, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern void func_L04_00362490(void *, s32);
extern s32 func_L04_004C1158(void *, void *);
extern void func_L04_003626F0(void *);

void func_L04_00360D80(void *op) {
    u8 *o = op;
    u8 *m = *(u8 **)(o + 0x68);
    u8 *c, *p;
    u16 f;
    s32 world, v, k;
    f32 f1, f0;

    if (o[0x20] == 0) {
        if (func_L04_00361208(o) == 0) return;
    }
    if (D_001D6694 == 2) {
        if (((o[0x34] ^ 1) & 1) == 0) return;
        f = *(u16 *)(o + 0x34);
        *(s32 *)(o + 0x98) = 0;
        f |= 0x41;
        f &= 0xEFFF;
        *(u16 *)(o + 0x34) = f;
        func_L01_004AA7E8(o, 1);
        c = *(u8 **)(m + 0x2FC);
        *(u16 *)(c + 0x34) |= 0x41;
        c = *(u8 **)(m + 0x2FC);
        *(u16 *)(c + 0x34) &= 0xEFFF;
        c = *(u8 **)(m + 0x2FC);
        *(s32 *)(c + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(m + 0x2FC), 1);
        *(s32 *)(m + 0x514) = 1;
        return;
    }
    if (*(s32 *)(m + 0x514) != 0) {
        f = *(u16 *)(o + 0x34) & 0xFFBE;
        *(u16 *)(o + 0x34) = f;
        p = *(u8 **)(o + 0x24);
        f |= *(u16 *)(p + 0x44) & 0x1000;
        *(u16 *)(o + 0x34) = f;
        *(s32 *)(o + 0x98) = *(s32 *)(p + 0x10);
        c = *(u8 **)(m + 0x2FC);
        *(u16 *)(c + 0x34) &= 0xFFBE;
        c = *(u8 **)(m + 0x2FC);
        p = *(u8 **)(c + 0x24);
        *(u16 *)(c + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        c = *(u8 **)(m + 0x2FC);
        *(s32 *)(c + 0x98) = *(s32 *)(*(u8 **)(c + 0x24) + 0x10);
        *(s32 *)(m + 0x514) = 0;
    }
    if (o[0x95] != 5) {
        if (*(f32 *)(m + 0x30) <= 0.0f) {
            *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
            func_003C7C38(o);
            func_L01_00446A70(o, o, 0x10000, o + 0x10, &D_L04_001D66B0, 100.0f);
        }
    }
    if (*(s32 *)(m + 0x4EC) != -1 && o[0x95] != 7 && o[0x20] != 0 && D_001D545C == 0xD) {
        if (func_L01_00456500(&D_L04_001E27C0, *(s32 *)(m + 0x4EC)) == 0) {
            f = *(u16 *)(o + 0x34);
            *(s32 *)(o + 0x98) = 0;
            f |= 0x41;
            f &= 0xEFFF;
            *(u16 *)(o + 0x34) = f;
            func_L01_004AA7E8(o, 1);
            return;
        }
        f = *(u16 *)(o + 0x34) & 0xFFBE;
        *(u16 *)(o + 0x34) = f;
        p = *(u8 **)(o + 0x24);
        f |= *(u16 *)(p + 0x44) & 0x1000;
        *(u16 *)(o + 0x34) = f;
        *(s32 *)(o + 0x98) = *(s32 *)(p + 0x10);
    }
    c = *(u8 **)(m + 0x2FC);
    if (*(u16 *)(o + 0x34) & 1) {
        if (c != 0) *(u16 *)(c + 0x34) |= 1;
    } else {
        if (c != 0) *(u16 *)(c + 0x34) &= 0xFFFE;
    }
    v = D_001DD7A4;
    if ((v != 0 || D_0014275C != 0 || D_001D545C == 0x16) && *(s32 *)(m + 0x4FC) == 0) {
        world = D_001D545C;
        if (world == 0x16) {
            func_L01_00446058(o, 0x1F05, 0x16E5);
        } else {
            func_L01_00446058(o, 0x1BA2, 0x16E5);
            world = D_001D545C;
            if (world == 0x10 || world == 4 || world == 9) {
                *(s16 *)(m + 0x34) = 0x2D;
                m[0x44] = 0x23;
                if (func_L01_0041A4F0() != 0) {
                    f1 = (f32)*(s16 *)(m + 0x34);
                    if (D_001D545C == 7 && D_0014275B == 0) {
                        f0 = D_L04_002F1D90[D_001D545C];
                    } else if (D_001D545C == 7) {
                        f0 = D_001DA8B0;
                    } else {
                        f0 = D_L04_002F1D90[D_001D545C];
                    }
                    *(s16 *)(m + 0x34) = (s16)(s32)(f1 * f0);
                    f1 = (f32)m[0x44];
                    if (D_001D545C == 7 && D_0014275B == 0) {
                        f0 = D_L04_002F1F70[D_001D545C];
                    } else if (D_001D545C == 7) {
                        f0 = D_001DA8B8;
                    } else {
                        f0 = D_L04_002F1F70[D_001D545C];
                    }
                    m[0x44] = (u8)(s32)(f1 * f0);
                }
                m[0x45] = m[0x44];
                m[0x46] = m[0x44];
                *(f32 *)(m + 0x30) = (f32)*(s16 *)(m + 0x34);
            }
        }
        *(s16 *)(o + 0xAA) = 0x16E5;
        *(s32 *)(m + 0x4FC) = 1;
    } else if (D_0014275C == 0 && *(s32 *)(m + 0x518) == 0) {
        world = D_001D545C;
        if (world == 0xD || world == 0x10 || world == 0xC) {
            *(s32 *)(m + 0x518) = 1;
            func_L01_00446058(o, 0x1F04, 0x16E5);
            *(s16 *)(o + 0xAA) = 0x16E5;
        }
    }
    if (func_L04_00361DF8(o) != 0) {
        func_L04_00362490(o, 1);
        return;
    }
    if (func_L04_004C1158(o, D_L04_001DD7D8) != 0) {
        func_L04_003626F0(o);
    }
}
