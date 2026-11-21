#include "vu0.h"
#include "common.h"

/* declared by functions of L06_003506E0.c, which this file was cut from */
extern void func_L06_00350BB8(void *arg0, u8 *arg1);
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad1[52 - 33];
    u16 flags;
    u8 pad2[104 - 54];
    void *vars;
} Moby_0034F9E8;
extern void func_L06_00350788(Moby_0034F9E8 *, void *);

/* localdecomp:start func_L06_00350788 */
extern void *D_L06_0021CB00[];
extern void func_L06_00351410_00350788(Moby_0034F9E8 *, void *);
extern void *func_003C24B0(s32, s32);
extern void func_L06_00351358(void *, void *);
extern void func_003C7C38(void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L06_0045B1F8(void *, void *, void *, void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L06_00351930(u8 *, u8 *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L06_00350788(Moby_0034F9E8 *m, void *vars) {
    u8 *v = vars;
    u8 *mb = (u8 *)m;
    s32 n;

    if (*(s32 *)(v + 0x270) != 0) {
        *(s32 *)(v + 0x358) = 0;
        *(s32 *)(v + 0x338) = 0;
    } else {
        *(void **)(v + 0x358) = D_L06_0021CB00[*(s32 *)(v + 0x300)];
        func_L06_00351410_00350788(m, v);
    }
    mb[0x30] = 0x80;
    *(s16 *)(mb + 0x32) = 0x40;
    (*(u8 **)(mb + 0x24))[0x46] = 5;
    {
        u8 *ship = func_003C24B0(0x169B, 0x80);
        *(u8 **)(v + 0x260) = ship;
        *(u8 **)(v + 0x240) = ship;
    }
    func_L06_00351358(m, v);
    *(Moby_0034F9E8 **)(*(u8 **)(v + 0x260) + 0xB8) = m;
    *(long *)(*(u8 **)(v + 0x260) + 0x38) = *(long *)(mb + 0x38);
    func_L06_00350BB8(m, v);
    func_003C7C38(*(u8 **)(v + 0x260));
    *(s16 *)(*(u8 **)(v + 0x260) + 0x32) = 0x40;
    *(*(u8 **)(v + 0x260) + 0x30) = 0x80;
    *(u16 *)(*(u8 **)(v + 0x260) + 0x34) |= 0x100;
    *(s32 *)(v + 0x370) = 0;
    *(s32 *)(v + 0x374) = 0;
    v[0x58] = 0x28;
    v[0x5A] = 0x28;
    *(f32 *)(v + 0x40) = 4.0f;
    v[0x3A] = 8;
    v[0x3E] = 1;
    v[0x3F] = 0;
    v[0x39] = 0;
    v[0x38] = 2;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 150;
        *(f32 *)(v + 0x30) = 150.0f;
    }
    if (v[0x44] == 0) {
        v[0x44] = 2;
    }
    if (v[0x45] == 0) {
        v[0x45] = 5;
    }
    v[0x159] = 5;
    *(f32 *)(v + 0x70) = 1.2f;
    *(f32 *)(v + 0x74) = 1.2f;
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.5f;
    *(f32 *)(v + 0x80) = 1.3962634f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    *(u32 *)(v + 0xA8) |= 0x80;
    v[0x158] = 0x14;
    func_L01_0045BD78(m, 0.0056000003f, 0.10000001f, 0.010053097f, 0.25132743f);
    *(s32 *)(v + 0x394) = 0;
    *(s32 *)(v + 0x398) = 0;
    v[0x1A8] = 0xFF;
    v[0x171] = 0xFF;
    v[0x1D7] = 1;
    *(f32 *)(v + 0x1B8) = 0.1f;
    *(f32 *)(v + 0x1BC) = 0.2f;
    if (*(s32 *)(v + 0x270) == 0) {
        func_L06_0045B1F8(*(void **)(v + 0x358), mb + 0x10, v + 0x344, v + 0x348);
    }
    *(s32 *)(v + 0x350) = 0;
    *(s32 *)(v + 0x324) = 0;
    *(s32 *)(v + 0x330) = 0;
    *(s32 *)(v + 0x334) = 0;
    *(s32 *)(v + 0x384) = 0;
    *(s32 *)(v + 0x388) = 0;
    *(void **)(v + 0x4B0) = m;
    *(void **)(v + 0x4B4) = v;
    *(void **)(v + 0x4B8) = v + 0x220;
    *(f32 *)(v + 0x4C4) = *(f32 *)(v + 0x310);
    *(f32 *)(v + 0x4C8) = *(f32 *)(v + 0x314);
    *(f32 *)(v + 0x4CC) = *(f32 *)(v + 0x304);
    *(void **)(v + 0x4D0) = m;
    *(void **)(v + 0x4D4) = v;
    *(void **)(v + 0x4D8) = v + 0x220;
    *(f32 *)(v + 0x4E4) = *(f32 *)(v + 0x318);
    *(f32 *)(v + 0x4E8) = *(f32 *)(v + 0x31C);
    *(f32 *)(v + 0x4EC) = *(f32 *)(v + 0x304);
    *(void **)(v + 0x4F0) = v + 0x4A0;
    *(void **)(v + 0x4F4) = v + 0x364;
    *(void **)(v + 0x4F8) = v + 0x368;
    *(s32 *)(v + 0x360) = 0;
    func_0038CB78(v + 0x3A0, 0, 0x80);
    func_0038CB78(v + 0x420, 0, 0x80);
    n = *(s32 *)(v + 0x26C);
    if (n != 0) {
        if (n >= 2) {
            *(s32 *)(v + 0x26C) = 1;
        } else if (n < 0) {
            *(s32 *)(v + 0x26C) = 0;
        }
        func_L01_004450F0(m, 1, 6);
        func_L06_00351930(mb, v, 0, 0, 0);
        m->flags = (m->flags | 0x41) & ~0x1000;
        *(s32 *)(mb + 0x98) = 0;
        func_L01_004AA7E8(m, 1);
        *(u16 *)(*(u8 **)(v + 0x260) + 0x34) |= 0x41;
        *(u16 *)(*(u8 **)(v + 0x260) + 0x34) &= ~0x1000;
        *(s32 *)(*(u8 **)(v + 0x260) + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(v + 0x260), 1);
    } else if (*(s32 *)(v + 0x27C) != 0) {
        func_L01_004450F0(m, 1, 4);
        func_L06_00351930(mb, v, 2, 0, 0);
    } else {
        func_L01_004450F0(m, 1, 0);
        func_L06_00351930(mb, v, 0, 0, 0);
    }
}
/* localdecomp:end func_L06_00350788 */
