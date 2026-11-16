#include "common.h"

INCLUDE_ASM("asm/levels", func_L28_003930D0);

/* localdecomp:start func_L28_003941D8 */
extern s32 func_L28_00394320(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L02_0034FD58(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L28_00394618(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_003941D8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L28_00394320(a0) != 0) return 1;
    }
    if (st[0x3E] == 2) {
        func_L28_00394618(a0);
        return 1;
    }
    if (func_L01_00452FB0(a0, st + 0x160, 0, 0, 0) != 0) func_L02_0034FD58(a0);
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_00394618(a0);
        return 1;
    }
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        func_L01_00456C98(a0, *(s32 *)(st + 0x324), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x328), 10.0f, 1.0f);
    } else {
        func_L01_00456BD0(a0, 3);
        func_L01_00456C98(a0, *(s32 *)(st + 0x324), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x328), 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L28_003941D8 */

/* localdecomp:start func_L28_00394320 */
/* func_L28_00394320 */
#include "common.h"
typedef int q_00394320 __attribute__((mode(TI)));
__asm__(".extern D_L28_001DEC9C, 4");
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
typedef struct { u8 pad[0x464]; u8 arr[1]; } T_394320;
extern T_394320 D_L28_00234A80_00394320;
extern u8 D_001BBE90[];
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_003C2880(void *);
s32 func_L28_00394320(void *arg) {
    u8 *a0 = arg;
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *m;
    u16 h;
    s32 v;
    st[0x170] = 0xB;
    st[0x1A8] = 2;
    st[0x171] = 8;
    st[0x176] = 8;
    *(f32 *)(st + 0x19C) = 0.15000001f;
    st[0x1DB] = 0xFF;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x194) = 0.5f;
    st[0x1D7] = 1;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    *(f32 *)(st + 0x34C) = *(f32 *)(a0 + 0x18);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.25f;
    *(f32 *)(st + 0x70) = 2.6f;
    *(f32 *)(st + 0x74) = 0.5f;
    *(f32 *)(st + 0x78) = 0.5f;
    *(f32 *)(st + 0x7C) = 1.0f;
    *(f32 *)(st + 0x80) = 0.7853982f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, 0.016f, 0.120000005f, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 0x14;
        *(f32 *)(st + 0x30) = 20.0f;
    }
    st[0x39] = 1;
    st[0x3E] = 1;
    st[0x64] = 0;
    st[0x3F] = 0;
    *(f32 *)(st + 0x40) = 2.0f;
    func_L01_004450F0(a0, 1, 0);
    if (*(s32 *)(st + 0x300) != -1 || *(s32 *)(st + 0x318) != -1) {
        func_L01_004450F0(a0, 0xC, 3);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    if (*(s32 *)(st + 0x330) != 0) {
        func_L01_004450F0(a0, 0xC, 4);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    h = *(u16 *)(a0 + 0xB2);
    if (D_L28_00234A80_00394320.arr[(s16)h] == 0) {
        v = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
        if ((((h & 1) ? v >> 4 : v) & 7) == 0) goto zero;
    }
    if (*(s32 *)(st + 0x300) != -1) {
        m = D_L28_001DEC9C;
        m += *(s32 *)(st + 0x300) << 8;
        func_L01_004443E8(m, 0, 3);
        func_003C2880(m);
    }
    if (*(s32 *)(st + 0x318) != -1) {
        m = D_L28_001DEC9C;
        m += *(s32 *)(st + 0x318) << 8;
        func_L01_004443E8(m, 0, 3);
        func_003C2880(m);
    }
    return 1;
zero:
    *(q_00394320 *)(st + 0x2E0) = *(q_00394320 *)(a0 + 0x10);
    *(s32 *)(st + 0x340) = 0;
    *(s32 *)(st + 0x344) = 0;
    return 0;
}
/* localdecomp:end func_L28_00394320 */

/* localdecomp:start func_L28_00394618 */
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_00394618;
extern S_00394618 D_L28_00234A80;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004443E8(u8 *, s32, s32);
void func_L28_00394618(void *self) {
    u8 *a0 = self;
    u8 *m;
    s32 id;
    s32 id2;
    s32 v;
    id = *(u16 *)(a0 + 0xB2);
    if (D_L28_00234A80.spent[(s16)id] == 0) {
        v = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
        if (id & 1)
            v = (v >> 4) & 7;
        else
            v = v & 7;
        if (v == 0) {
            m = func_003C24B0(0x8C4, 0x80);
            func_L01_00456160(m, a0);
            *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.5f;
            id2 = *(u16 *)(a0 + 0xB2);
            if (id2 & 1) {
                if (((D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] >> 4) & 7) != 7)
                    D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 0x10;
            } else {
                if ((D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] & 7) != 7)
                    D_001BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 1;
            }
        }
    }
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L28_00394618 */

/* localdecomp:start func_L28_00394768 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L28_00394768(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    u16 value;

    func_0038CAD0(v + 0x32C);
    func_0038CB00(v + 0x33C);
    value = *(u16 *)(self + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(self + 0x96) = value + 1;
    }
    func_L01_00451DF8(self, v + 0x260, 3, 1, 2.5f);
}
/* localdecomp:end func_L28_00394768 */
