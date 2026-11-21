/* functional: medium. Written from the PAL asm only. First-frame setup of the Marcadia boss-type object (called by func_L04_00360D80 while o[0x20] == 0): clears the state's counters, finds up to eight linked child objects of type 0x1BAF in the object list (D_001DFD9C..D_001DFDA0) and arms them, reads the placement/world-table anchors into +0x320/+0x330/+0x36C, fills the many attack/behaviour constants of the state block (+0x170..+0x1DC, +0x70..+0xA0), optionally spawns the paired type 0x194E object, resets the state byte, and then, depending on the state flags (+0x250 / +0x374 / +0x4E0 ...), either turns into the type 0x19E1 handler and returns 0 (killing the pair), or sets up the animation channels and returns 1. Unsure: the roles of the state fields (kept as raw offsets). In world 0x10 with +0x4E4 set, func_003D3CB0 is called with a second vector (sp+0x10) that retail never writes (its stack content); here that vector is left uninitialised as in retail, which the gate must cover. */
#include "common.h"
#include "vu0.h"

extern s32 D_001D545C;
extern s32 D_001DD6C8;
extern u8 *D_001DFD9C;
extern u8 *D_001DFDA0;
extern u8 *D_001DFE80;
extern vu0_v4 D_L04_001E95A0;
extern s32 func_00382468(s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void *func_L01_0043B548(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L04_00362DF0(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L04_00361208(void *op) {
    u8 *o = op;
    u8 *m = *(u8 **)(o + 0x68);
    u8 *p, *c, *ent, *r;
    vu0_v4 a, b;
    s32 cnt = 0;
    s32 i, world;
    u16 f;
    f32 f20;

    D_001DD6C8 = 0;
    *(s32 *)(m + 0x50C) = 0;
    if (*(s32 *)(m + 0x4E4) != 0) *(s32 *)(m + 0x4A4) = 1;
    *(s32 *)(m + 0x4D8) = 0;
    m[0x3F] = 0;
    for (i = 7; i >= 0; i--) {
        *(s32 *)(m + 0x4B0 + i * 4) = 0;
    }
    if (*(s16 *)(o + 0xAA) == 0x1BA2) {
        *(s32 *)(m + 0x364) = 0x1BA2;
        func_L01_00446058(o, 0x1BA2, 0x16E5);
    } else {
        *(s32 *)(m + 0x364) = 0x16E5;
    }
    p = D_001DFD9C;
    while (p < D_001DFDA0) {
        if (*(s16 *)(p + 0xAA) == 0x1BAF) {
            *(u8 **)(m + 0x4B0 + cnt * 4) = p;
            *(s32 *)(p + 0x98) = 0;
            f = *(u16 *)(p + 0x34);
            cnt++;
            f |= 0x41;
            f &= 0xEFFF;
            *(u16 *)(p + 0x34) = f;
            func_L01_004AA7E8(p, 1);
            if (cnt >= 8) break;
        }
        p += 0x100;
    }
    if ((func_00382468(2) != 0 || *(s32 *)(m + 0x4F0) != 0) && *(s32 *)(m + 0x4F0) != -1) {
        *(u16 *)(o + 0x34) |= 0x8000;
    }
    p = *(u8 **)(o + 0x24);
    *(f32 *)(o + 0x2C) = *(f32 *)(p + 0x24);
    *(vu0_v4 *)(m + 0x490) = *(vu0_v4 *)(o + 0x10);
    if (*(s32 *)(m + 0x304) != -1) {
        ent = D_001DFE80 + (*(s32 *)(m + 0x304) << 7);
        *(vu0_v4 *)(m + 0x320) = *(vu0_v4 *)(ent + 0x30);
        func_0038CF68(m + 0x330, ent + 0x10, 1.0f);
        *(f32 *)(m + 0x36C) = *(f32 *)(ent + 0x78);
    } else {
        *(vu0_v4 *)(m + 0x320) = *(vu0_v4 *)(o + 0x10);
        *(vu0_v4 *)(m + 0x330) = *(vu0_v4 *)(o + 0xD0);
        *(f32 *)(m + 0x36C) = *(f32 *)(o + 0xF8);
    }
    if (*(s32 *)(m + 0x30C) != -1) *(s32 *)(m + 0x318) = 1;
    if (*(s32 *)(m + 0x4E4) != 0) *(s32 *)(m + 0x318) = 1;
    m[0x1A8] = 5;
    m[0x170] = 0x19;
    m[0x171] = 0xF;
    m[0x172] = 0x11;
    m[0x1CE] = 6;
    m[0x1CF] = 0xC;
    m[0x176] = 0x12;
    m[0x1D8] = 0;
    m[0x1DB] = 0x14;
    m[0x1CC] = 0;
    m[0x1CD] = 0;
    m[0x1D9] = 0;
    m[0x1DA] = 0;
    m[0x1D7] = 1;
    m[0x1A9] = 1;
    *(f32 *)(m + 0x180) = 0.0200000014f;
    *(f32 *)(m + 0x184) = 0.0100000007f;
    *(f32 *)(m + 0x188) = 0.0140000004f;
    *(f32 *)(m + 0x18C) = 0.000800000038f;
    *(f32 *)(m + 0x190) = 2.5f;
    *(f32 *)(m + 0x194) = 0.75f;
    *(f32 *)(m + 0x19C) = 0.35f;
    *(f32 *)(m + 0x17C) = 0.3f;
    if (D_001D545C == 0xC) *(s16 *)(m + 0x1AA) = 0x280B;
    *(f32 *)(m + 0x1A0) = *(f32 *)(o + 0x18) - 10.0f;
    if (*(s32 *)(m + 0x250) != 0) *(f32 *)(m + 0x210) = 1.0f;
    if (D_001D545C == 0xC) *(f32 *)(m + 0x210) = 0.5f;
    *(s32 *)(m + 0x1DC) = *(s32 *)(m + 0x4DC);
    if (D_001D545C == 0xD) *(f32 *)(m + 0x1A0) = *(f32 *)(o + 0x18) - 30.0f;
    f20 = 0.7f;
    *(u8 **)(m + 0xBC) = m + 0x390;
    *(f32 *)(m + 0x70) = f20;
    *(f32 *)(m + 0x74) = 0.3f;
    *(f32 *)(m + 0x78) = 1.0f;
    *(f32 *)(m + 0x7C) = 2.0f;
    *(f32 *)(m + 0x80) = 1.48352981f;
    *(f32 *)(m + 0xA0) = 0.34906584f;
    *(f32 *)(m + 0x9C) = 0.008f;
    func_L01_0045BD78(o, 0.0064000003f, 0.120000005f, 0.0100530973f, 0.251327425f);
    m[0x58] = 0x14;
    m[0x5A] = 0xE;
    if (*(s32 *)(m + 0x4E4) != 0) {
        *(u32 *)(m + 0xA8) |= 4;
        *(f32 *)(m + 0x7C) = f20;
        *(f32 *)(m + 0x78) = f20;
        *(u16 *)(o + 0x34) |= 0x100;
        *(f32 *)(m + 0x80) = 12.566371f;
        *(s32 *)(m + 0x318) = 1;
        *(u32 *)(m + 0xA8) |= 1;
    }
    if (*(s16 *)(m + 0x34) == 0) {
        *(s16 *)(m + 0x34) = 0x14;
        *(f32 *)(m + 0x30) = 20.0f;
    }
    *(f32 *)(m + 0x40) = 1.2f;
    m[0x39] = 1;
    m[0x38] = 1;
    if (*(s32 *)(m + 0x4E0) == 0) {
        c = func_003C24B0(0x194E, 0x80);
        *(u8 **)(m + 0x2FC) = c;
        if (c != 0) {
            func_L01_00456160(c, o);
            *(u16 *)(*(u8 **)(m + 0x2FC) + 0x32) = *(u16 *)(o + 0x32);
            *(u8 **)(m + 0x240) = *(u8 **)(m + 0x2FC);
        }
    }
    m[0x3E] = 1;
    m[0x5E] = 0;
    m[0x5F] = 0;
    *(s32 *)(m + 0x2F0) = 0;
    *(s16 *)(m + 0x2F4) = 0;
    *(s32 *)(m + 0x2F8) = 0;
    *(s32 *)(m + 0x360) = 0;
    if (*(s32 *)(m + 0x250) > 0) {
        r = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(m + 0x250) = -1;
        if (o[0x43] != 0) func_003C3A10(o, 0, 0, 0);
        m[0x25E] = 0x1C;
        m[0x25F] = 9;
        (*(void (**)(void *))r)(o);
        if (*(u8 **)(m + 0x2FC) != 0) {
            func_003C2880(*(u8 **)(m + 0x2FC));
            *(s32 *)(m + 0x240) = 0;
            *(s32 *)(m + 0x2FC) = 0;
        }
        return 0;
    }
    if (*(s32 *)(m + 0x374) != 0) {
        if (*(s32 *)(m + 0x380) != 0) {
            *(vu0_v4 *)(m + 0x320) = *(vu0_v4 *)(o + 0x10);
        }
        func_L01_004450F0(o, 0x1A, 7);
        f = *(u16 *)(o + 0x34);
        *(s32 *)(o + 0x98) = 0;
        f |= 0x41;
        f &= 0xEFFF;
        *(u16 *)(o + 0x34) = f;
        func_L01_004AA7E8(o, 1);
        c = *(u8 **)(m + 0x2FC);
        if (c != 0) {
            *(u16 *)(c + 0x34) |= 0x41;
            c = *(u8 **)(m + 0x2FC);
            *(u16 *)(c + 0x34) &= 0xEFFF;
            c = *(u8 **)(m + 0x2FC);
            *(s32 *)(c + 0x98) = 0;
            func_L01_004AA7E8(*(u8 **)(m + 0x2FC), 1);
        }
    } else if (*(s32 *)(m + 0x4E0) != 0) {
        func_L04_00362DF0(o);
    } else {
        func_L01_004450F0(o, 1, 1);
        if (o[0x43] != 0) func_003C3A10(o, 0, 0, 0);
        if (*(s32 *)(m + 0x4A0) != 0 && o[0x43] != 4) func_003C3A10(o, 4, 0, 0);
        if (*(long *)(m + 0x310) != -1) func_L01_004450F0(o, 5, 6);
        if (*(s32 *)(m + 0x300) != -1) {
            func_L01_004450F0(o, 2, -1);
        } else if (*(s32 *)(m + 0x318) == 0) {
            func_L01_004450F0(o, 4, -1);
        }
    }
    if (D_001D545C == 0x10 && *(s32 *)(m + 0x4E4) != 0) {
        func_0038CF68(&a, o + 0xE0, 2.0f);
        func_0038CF68(&a, o + 0xE0, -1.0f);
        if (func_003D3CB0(&a, &b, 0, o, 0) != 0) {
            *(vu0_v4 *)(o + 0x10) = D_L04_001E95A0;
        }
    }
    return 1;
}
