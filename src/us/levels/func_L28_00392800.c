#include "common.h"

/* NTSC-U counterpart of func_L28_00394320. */
/* localdecomp:start func_L28_00392800 */
typedef int q_00392800 __attribute__((mode(TI)));
__asm__(".extern D_L28_001DEC9C, 4");
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
typedef struct { u8 pad[0x464]; u8 arr[1]; } T_392800;
extern T_392800 D_L28_00234A80_00392800;
extern u8 D_001BBE90[];
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_004412D0(u8 *, s32, s32);
extern void func_003BD360(void *);
s32 func_L28_00392800(void *arg) {
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
    *(f32 *)(st + 0x9C) = 0.00272222236f;
    func_L01_00458A70(a0, 0.0111111114f, 0.100000009f, 0.00698131742f, 0.209439531f);
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
    func_L01_00441FB8(a0, 1, 0);
    if (*(s32 *)(st + 0x300) != -1 || *(s32 *)(st + 0x318) != -1) {
        func_L01_00441FB8(a0, 0xC, 3);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004A6DF8(a0, 1);
    }
    if (*(s32 *)(st + 0x330) != 0) {
        func_L01_00441FB8(a0, 0xC, 4);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004A6DF8(a0, 1);
    }
    h = *(u16 *)(a0 + 0xB2);
    if (D_L28_00234A80_00392800.arr[(s16)h] == 0) {
        v = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
        if ((((h & 1) ? v >> 4 : v) & 7) == 0) goto zero;
    }
    if (*(s32 *)(st + 0x300) != -1) {
        m = D_L28_001DEC9C;
        m += *(s32 *)(st + 0x300) << 8;
        func_L01_004412D0(m, 0, 3);
        func_003BD360(m);
    }
    if (*(s32 *)(st + 0x318) != -1) {
        m = D_L28_001DEC9C;
        m += *(s32 *)(st + 0x318) << 8;
        func_L01_004412D0(m, 0, 3);
        func_003BD360(m);
    }
    return 1;
zero:
    *(q_00392800 *)(st + 0x2E0) = *(q_00392800 *)(a0 + 0x10);
    *(s32 *)(st + 0x340) = 0;
    *(s32 *)(st + 0x344) = 0;
    return 0;
}
/* localdecomp:end func_L28_00392800 */
