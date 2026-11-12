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

INCLUDE_ASM("asm/levels", func_L28_00394320);

/* localdecomp:start func_L28_00394618 */
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_00394618;
extern S_00394618 D_L28_00234A80;
extern u8 D_1BBE90[];
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
        v = D_1BBE90[((s16)id >> 1) + (D_001D545C << 10)];
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
                if (((D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] >> 4) & 7) != 7)
                    D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 0x10;
            } else {
                if ((D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] & 7) != 7)
                    D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 1;
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
