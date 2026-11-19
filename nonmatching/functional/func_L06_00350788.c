/* functional: high. check.py at level_06: 247 diffs, all one-instruction shifts (the D_L06_0021CB00 table load schedules differently: retail lui/addiu before the sll, this C lui/addu/lw after) from the first divergence on; instruction sequence and constants otherwise identical. Uses 'long' for the 8-byte copy at +0x38 (ld/sd as retail; u64 gives lq/sq). */
#include "vu0.h"
#include "common.h"
extern s32 D_L06_0021CB00[];
extern u8 *func_003C24B0(s32, s32);
extern void func_L06_00351410(u8 *, u8 *);
extern void func_L06_00351358(u8 *, u8 *);
extern void func_003C7C38(void *);
extern void func_L01_0045BD78(u8 *, f32, f32, f32, f32);
extern void func_L06_0045B1F8(void *, void *, void *, void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);

void func_L06_00350788(Moby_0034F9E8 *m_, void *v_) {
    u8 *m = (u8 *)m_;
    u8 *v = (u8 *)v_;
    u8 *o;

    if (*(s32 *)(v + 0x270) != 0) {
        *(s32 *)(v + 0x358) = 0;
        *(s32 *)(v + 0x338) = 0;
    } else {
        *(s32 *)(v + 0x358) = D_L06_0021CB00[*(s32 *)(v + 0x300)];
        func_L06_00351410(m, v);
    }
    m[0x30] = 0x80;
    *(u16 *)(m + 0x32) = 0x40;
    (*(u8 **)(m + 0x24))[0x46] = 5;
    o = func_003C24B0(0x169B, 0x80);
    *(u8 **)(v + 0x240) = o;
    *(u8 **)(v + 0x260) = o;
    func_L06_00351358(m, v);
    *(u8 **)(*(u8 **)(v + 0x260) + 0xB8) = m;
    *(long *)(*(u8 **)(v + 0x260) + 0x38) = *(long *)(m + 0x38);
    func_L06_00350BB8(m, v);
    func_003C7C38(*(u8 **)(v + 0x260));
    *(u16 *)(*(u8 **)(v + 0x260) + 0x32) = 0x40;
    (*(u8 **)(v + 0x260))[0x30] = 0x80;
    *(u16 *)(*(u8 **)(v + 0x260) + 0x34) |= 0x100;
    v[0x5A] = 0x28;
    *(f32 *)(v + 0x40) = 4.0f;
    v[0x3A] = 8;
    *(s32 *)(v + 0x370) = 0;
    *(s32 *)(v + 0x374) = 0;
    v[0x58] = 0x28;
    v[0x3E] = 1;
    v[0x3F] = 0;
    v[0x39] = 0;
    v[0x38] = 2;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 0x96;
        *(f32 *)(v + 0x30) = 150.0f;
    }
    if (v[0x44] == 0) {
        v[0x44] = 2;
    }
    if (v[0x45] == 0) {
        v[0x45] = 5;
    }
    *(s32 *)(v + 0xA8) |= 0x80;
    v[0x159] = 5;
    *(f32 *)(v + 0x7C) = 1.5f;
    *(f32 *)(v + 0x80) = 1.3962634f;
    v[0x158] = 0x14;
    *(f32 *)(v + 0x74) = 1.2f;
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    *(f32 *)(v + 0x70) = 1.2f;
    func_L01_0045BD78(m, 0.0056000003f, 0.10000001f, 0.010053097f, 0.25132743f);
    *(f32 *)(v + 0x1B8) = 0.1f;
    *(f32 *)(v + 0x1BC) = 0.2f;
    v[0x171] = 0xFF;
    v[0x1D7] = 1;
    *(s32 *)(v + 0x394) = 0;
    *(s32 *)(v + 0x398) = 0;
    v[0x1A8] = 0xFF;
    if (*(s32 *)(v + 0x270) == 0) {
        func_L06_0045B1F8(*(void **)(v + 0x358), m + 0x10, v + 0x344, v + 0x348);
    }
    *(s32 *)(v + 0x350) = 0;
    *(s32 *)(v + 0x324) = 0;
    *(s32 *)(v + 0x330) = 0;
    *(s32 *)(v + 0x334) = 0;
    *(s32 *)(v + 0x384) = 0;
    *(s32 *)(v + 0x388) = 0;
    *(u8 **)(v + 0x4B0) = m;
    *(u8 **)(v + 0x4B4) = v;
    *(u8 **)(v + 0x4D0) = m;
    *(u8 **)(v + 0x4D4) = v;
    *(s32 *)(v + 0x360) = 0;
    *(u8 **)(v + 0x4F8) = v + 0x368;
    *(f32 *)(v + 0x4C4) = *(f32 *)(v + 0x310);
    *(f32 *)(v + 0x4C8) = *(f32 *)(v + 0x314);
    *(u8 **)(v + 0x4D8) = v + 0x220;
    *(f32 *)(v + 0x4E4) = *(f32 *)(v + 0x318);
    *(f32 *)(v + 0x4E8) = *(f32 *)(v + 0x31C);
    *(f32 *)(v + 0x4EC) = *(f32 *)(v + 0x304);
    *(u8 **)(v + 0x4F0) = v + 0x4A0;
    *(u8 **)(v + 0x4F4) = v + 0x364;
    *(u8 **)(v + 0x4B8) = v + 0x220;
    *(f32 *)(v + 0x4CC) = *(f32 *)(v + 0x304);
    func_0038CB78(v + 0x3A0, 0, 0x80);
    func_0038CB78(v + 0x420, 0, 0x80);
    if (*(s32 *)(v + 0x26C) != 0) {
        if (*(s32 *)(v + 0x26C) >= 2) {
            *(s32 *)(v + 0x26C) = 1;
        } else if (*(s32 *)(v + 0x26C) < 0) {
            *(s32 *)(v + 0x26C) = 0;
        }
        func_L01_004450F0(m, 1, 6);
        func_L06_00351930(m, v, 0, 0, 0);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        *(u16 *)(*(u8 **)(v + 0x260) + 0x34) |= 0x41;
        *(u16 *)(*(u8 **)(v + 0x260) + 0x34) &= 0xEFFF;
        *(s32 *)(*(u8 **)(v + 0x260) + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(v + 0x260), 1);
    } else if (*(s32 *)(v + 0x27C) != 0) {
        func_L01_004450F0(m, 1, 4);
        func_L06_00351930(m, v, 2, 0, 0);
    } else {
        func_L01_004450F0(m, 1, 0);
        func_L06_00351930(m, v, 0, 0, 0);
    }
}
