#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003D89F8(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D89F8();
/* --- end of declarations from other files --- */

/* declarations of 3D6C70.c's earlier functions (tools/port_from_us.py) */
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D4BD0_003D6F78;
extern s32 D_001D4BD4_003D6F78;
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D7790(s32, s32, s32, s32, s32);
extern void func_003D7790(s32, s32, s32, s32, s32);
extern void func_003D7790(s32, s32, s32, s32, s32);

/* localdecomp:start func_003D80E8 */
extern s32 func_003D6DD8(s32 *, s32);
extern void func_003D81A0(void);
extern void func_003D88B8(void);
__asm__(".extern D_001D5608, 4");
__asm__(".extern D_001D5610, 4");
__asm__(".extern D_001D5614, 4");
__asm__(".extern D_001D561C, 4");
extern s32 D_001D5608, D_001D5610, D_001D5614, D_001D561C;
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];
void func_003D80E8(void) {
    s32 p, r1, r2, r3;
    D_001D5608 = 0x3FA000;
    D_001D560C = 0x3FE000;
    D_001D5624 = 0x400000;
    p = 0x379000;
    r1 = func_003D6DD8(&p, 0x40000);
    p = 0x379000;
    D_001D5614 = r1;
    r2 = func_003D6DD8(&p, 0x40000);
    D_001D561C = r2;
    r3 = func_003D6DD8(&p, 0x40000);
    D_001D5620 = r3;
    D_001D5610 = D_001A1ED4[0];
    func_003D81A0();
    func_003D88B8();
    D_001D55EC = D_001D55EC | 1;
}
/* localdecomp:end func_003D80E8 */

/* localdecomp:start func_003D81A0 */
__asm__(".extern D_001D936C, 1");
__asm__(".extern D_001D9350, 4");
__asm__(".extern D_001D9354, 4");
__asm__(".extern D_001D9358, 4");
__asm__(".extern D_001D935C, 4");
extern s32 D_001D0A50[];
extern s32 D_001D5600, D_001D5604, D_001D5608_003D81A0, D_001D5610_003D81A0, D_001D5614_003D81A0, D_001D561C_003D81A0, D_001D5620, D_001D55F0;
extern u8 D_001D936C;
extern s32 D_001D9350, D_001D9354, D_001D9358, D_001D935C;
extern void func_003D6DF8(long **, s32, s32, s32, s32, s32);
extern void func_003D7668(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D72A0(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D7C08(s32, s32, s32);
extern void func_003D7C30(s32, s32, s32);
extern void func_003D7C58(s32, s32, s32);
extern void func_003D7C98(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D81A0(void) {
    long *d = (long *)D_001D0A50;
    long *p;
    s32 lw, lh, v;
    d[0] = 0x5000000000000001UL;
    d[1] = 0xEEEEEEEEEEEEEEEEUL;
    d[2] = 0;
    d[3] = 0x3F;
    d[4] = 0xA0000000A0UL;
    d[5] = 0x19;
    d[6] = 0x100000000UL;
    d[7] = 0x4F;
    d[8] = 0x60;
    d[9] = 0x15;
    d[10] = 5;
    d[11] = 9;
    d[12] = 0x3000000000000001UL;
    d[13] = 0xEEEEEEEEEEEEEEEEUL;
    d[14] = (D_001D5614_003D81A0 >> 13) | 0x40000;
    d[15] = 0x4D;
    d[16] = 0xFF000000FF0000UL;
    d[17] = 0x41;
    d[18] = 0x3040C;
    d[19] = 0x48;
    d[20] = 0x2400000000000001UL;
    d[21] = 1;
    d[22] = 0;
    d[23] = 0x306;
    p = d + 24;
    func_003D6DF8(&p, 0xA0, 0xA0, 0x10A0, 0x10A0, 0);
    *p++ = 0x5000000000000001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    v = D_001D5600;
    if (v & (v - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lw = 0x1E - t; }
    }
    v = D_001D5604;
    if (v & (v - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lh = 0x1E - t; }
    }
    *p++ = ((long)D_001D5610_003D81A0 >> 8) | (((long)D_001D5600 >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *p++ = 7;
    *p++ = (D_001D5614_003D81A0 >> 13) | 0x40000;
    *p++ = 0x4D;
    *p++ = 0xFF000000FF0000UL;
    *p++ = 0x41;
    *p++ = 0x3040D;
    *p++ = 0x48;
    *p++ = 0x8000000088UL;
    *p++ = 0x43;
    *p++ = 0x2400000000000001UL;
    *p++ = 1;
    *p++ = D_001D9350 | ((long)D_001D9354 << 8) | ((long)D_001D9358 << 16) | ((long)D_001D935C << 24);
    *p++ = 0x316;
    func_003D6E98(&p, 0x98, 0x98, 0, 0, 0x1098, 0x1098, D_001D5600 << 4, D_001D5604 << 4);
    *p++ = 0x1000000000008001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    *p++ = 0;
    *p++ = 0x3F;
    *p++ = 0x1000000000000001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    *p++ = 0x30802;
    *p++ = 0x48;
    if (D_001D936C == 1) {
        func_003D7C08((s32)&p, D_001D5614_003D81A0, D_001D5620);
        func_003D7C08((s32)&p, D_001D5614_003D81A0, D_001D5620);
    }
    func_003D7668((u8 **)&p, D_001D5614_003D81A0, 0x100, 0x100, D_001D5620, 0x80, 0x80);
    func_003D7C30((s32)&p, D_001D5620, D_001D561C_003D81A0);
    if (D_001D936C == 1) {
        func_003D7C30((s32)&p, D_001D5620, D_001D561C_003D81A0);
    }
    func_003D7668((u8 **)&p, D_001D561C_003D81A0, 0x80, 0x80, D_001D5620, 0x40, 0x40);
    func_003D7C58((s32)&p, D_001D5620, D_001D561C_003D81A0);
    func_003D7C58((s32)&p, D_001D5620, D_001D561C_003D81A0);
    func_003D7C58((s32)&p, D_001D5620, D_001D561C_003D81A0);
    func_003D72A0(&p, D_001D561C_003D81A0, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0, 0, 0);
    func_003D72A0(&p, D_001D5608_003D81A0, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0, 0, 0);
    func_003D7C98(&p, D_001D5620, 0x40, 0x40, 1, 6, 6, D_001D561C_003D81A0, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0,
                  0x400, 0x400, 0x10, 0, 0x410, 0x400, 0, 0x10, 0x400, 0x410, 0x10, 0x10, 0x410, 0x410);
    func_003D7C98(&p, D_001D561C_003D81A0, 0x40, 0x40, 1, 6, 6, D_001D5608_003D81A0, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0,
                  0x400, 0x400, 0x10, 0, 0x410, 0x400, 0, 0x10, 0x400, 0x410, 0x10, 0x10, 0x410, 0x410);
    D_001D55F0 = (u8 *)p - (u8 *)d;
}
/* localdecomp:end func_003D81A0 */

/* localdecomp:start func_003D88B8 */
__asm__(".extern D_001D9360, 4");
extern s32 D_001D5608_003D88B8, D_001D5620, D_001D561C_003D88B8, D_001D9360, D_001D55F4;
extern u8 D_001D2A50[];
extern void func_003D7668(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7C08();
extern void func_003D6F78(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D88B8(void) {
    u8 *p = D_001D2A50;
    func_003D7668(&p, D_001D5608_003D88B8, 0x40, 0x40, D_001D5620, 0x80, 0x80);
    func_003D7668(&p, D_001D5620, 0x80, 0x80, D_001D561C_003D88B8, 0x100, 0x100);
    func_003D7C08(&p, D_001D561C_003D88B8, D_001D5620);
    func_003D6F78(&p, D_001D561C_003D88B8, 0x100, 0x100, 1, 0, D_001D9360);
    D_001D55F4 = p - D_001D2A50;
}
/* localdecomp:end func_003D88B8 */

/* localdecomp:start func_003D8978 */
extern s32 D_001D55F0;
extern u32 *D_001DA050;
__asm__(".extern D_001D934C, 4");
extern s32 D_001D934C;
extern s32 D_001D0A50[];
void func_003D8978(void) {
    D_001D934C = 0x6000;
    D_001DA050[0] = (D_001D55F0 >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D0A50;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55F0 >> 4) | 0x50000000;
    D_001DA050 += 4;
}
/* localdecomp:end func_003D8978 */

/* localdecomp:start func_003D89F8 */
__asm__(".extern D_001D934C, 4");
extern u32 *D_001DA050;
extern s32 D_001D55F4;
extern u8 D_001D2A50[];
extern s32 D_001D934C;
void func_003D89F8(void) {
    D_001DA050[0] = (D_001D55F4 >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D2A50;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55F4 >> 4) | 0x50000000;
    D_001D934C = 0;
    D_001DA050 += 4;
}
/* localdecomp:end func_003D89F8 */

/* localdecomp:start func_003D8A70 */
extern s32 D_001A1ED0[];
void func_003D8A70(unsigned long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    *(*pp)++ = 0x7000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = ((long)(a1 - 1) << 16) | ((long)(a2 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = ((long)D_001A1ED0[2] >> 13) | ((long)a3 << 16) | 0xFF00000001000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x30802;
    *(*pp)++ = 0x48;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000 | 0x100000000UL;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x80000000A4UL;
    *(*pp)++ = 0x43;
    *(*pp)++ = 0x4400000000000001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x346;
    *(*pp)++ = 0xFFFFFFFFUL;
    *(*pp)++ = (long)a4 | ((long)a5 << 16);
    *(*pp)++ = (long)a6 | ((long)a7 << 16);
    *(*pp)++ = 0x3000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D8A70 */

/* localdecomp:start func_003D8D50 */
extern s32 D_001A1ED0[];
void func_003D8D50(unsigned long **pp, s32 a1) {
    s32 i;
    s32 x0, x1;
    long step0, step1; /* steps kept in registers, not folded into the adds */
    *(*pp)++ = 0x8000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = (D_001A1ED0[1] >> 13) | 0x2080000 | 0x3FFF00000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000 | 0x100000000UL;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x30000;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = 0x33F000001FF0000UL;
    *(*pp)++ = 0x41;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x15;
    if (a1) {
        *(*pp)++ = (D_001A1ED0[2] >> 8) | 0x2B220000 | 0x680000000UL;
        *(*pp)++ = 7;
    } else {
        *(*pp)++ = 7;
        *(*pp)++ = (D_001A1ED0[2] >> 8) | 0x2B220000 | 0xE80000000UL;
    }
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    if (a1) {
        *(*pp)++ = 0x3F80000040808080UL;
    } else {
        *(*pp)++ = 0x3F80000080808080UL;
    }
    *(*pp)++ = 0x316;
    *(*pp)++ = 0x4400000000008020UL;
    *(*pp)++ = 0x5353;
    x0 = 8;
    x1 = 8;
    step0 = 0x10;
    step1 = 0x10;
    for (i = 0; i < 32; i++) {
        *(*pp)++ = ((x0 << 4) - 0x78) | 0x80000;
        *(*pp)++ = x1 << 4;
        *(*pp)++ = ((x0 << 4) + 8) | 0x34080000;
        *(*pp)++ = ((x1 << 4) + 0x80) | 0x34000000;
        x0 += step0;
        x1 += step1;
    }
}
/* localdecomp:end func_003D8D50 */

typedef struct { s32 f0; s32 f4; s32 f8; } T_3D3780;
extern T_3D3780 D_001A1ED0_003D90A8;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D90A8);

/* localdecomp:start func_003D9378 */
__asm__(".extern D_001D5634_003D9378, 4");
extern s32 D_001D5600_003D9378;
extern s32 D_001D5604_003D9378;
extern s32 D_001D5628_003D9378;
extern s32 D_001D5630_003D9378;
extern s32 D_001D5634_003D9378;
extern s32 D_001D55F8_003D9378;
extern u8 D_001D3650_003D9378[];
extern void func_003D7668(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7C08();
void func_003D9378(void) {
    u8 *p;
    unsigned long *q = (unsigned long *)D_001D3650_003D9378;
    q[0] = 0x5000000000000001UL;
    q[1] = 0xEEEEEEEEEEEEEEEEUL;
    q[2] = 0;
    q[3] = 0x3F;
    q[4] = 0xA0000000A0UL;
    q[5] = 0x19;
    q[6] = 0x100000000UL;
    q[7] = 0x4F;
    q[8] = 0x60;
    q[9] = 0x15;
    q[10] = 5;
    q[11] = 9;
    p = D_001D3650_003D9378 + 0x60;
    func_003D7668(&p, D_001D5630_003D9378, D_001D5600_003D9378, D_001D5604_003D9378, D_001D5628_003D9378, 0x100, 0x100);
    func_003D7C08(&p, D_001D5628_003D9378, D_001D5634_003D9378);
    func_003D7C08(&p, D_001D5628_003D9378, D_001D5634_003D9378);
    D_001D55F8_003D9378 = p - D_001D3650_003D9378;
}
/* localdecomp:end func_003D9378 */

extern s32 D_001D5600_003D94B8;
extern s32 D_001D5604_003D94B8;
extern s32 D_001D5628_003D94B8;
extern s32 D_001D55FC_003D94B8;
extern u8 D_001D3EF0[];
extern s32 func_003D90A8();
extern void func_003D6F78(u8 **, s32, s32, s32, s32, s32, s32);
/* localdecomp:start func_003D94B8 */
__asm__(".extern D_001D5600_003D94B8, 16");
__asm__(".extern D_001D5604_003D94B8, 16");
__asm__(".extern D_001D5628_003D94B8, 16");
__asm__(".extern D_001D55FC_003D94B8, 16");
extern s32 func_003D8A70();
extern s32 func_003D8D50();
void func_003D94B8(void) {
    u8 *p;
    p = D_001D3EF0;
    func_003D8A70(&p, D_001D5600_003D94B8, D_001D5604_003D94B8, D_001D5600_003D94B8 >> 6, 0, 0, (D_001D5600_003D94B8 + 1) << 4, (D_001D5604_003D94B8 + 1) << 4);
    func_003D8D50(&p, 1);
    func_003D90A8(&p, D_001D5600_003D94B8, D_001D5604_003D94B8, D_001D5600_003D94B8 >> 6, 0, 0, (D_001D5600_003D94B8 + 1) << 4, (D_001D5604_003D94B8 + 1) << 4, 0xFF82FF);
    func_003D6F78(&p, D_001D5628_003D94B8, 0x100, 0x100, 0, 1, 0x80);
    D_001D55FC_003D94B8 = (s32)p - (s32)D_001D3EF0;
}
/* localdecomp:end func_003D94B8 */

/* localdecomp:start func_003D95A8 */
__asm__(".extern D_001D5634, 4");
__asm__(".extern D_001D5630, 4");
extern s32 func_003D6DD8();
extern void func_003D9378(void);
extern void func_003D94B8(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628;
extern s32 D_001A1ED4[];
extern s32 D_001D55EC;
void func_003D95A8(void) {
    s32 spv[4];
    spv[0] = 0x37C000;
    D_001D5634 = func_003D6DD8(spv, 0x40000);
    D_001D5628 = func_003D6DD8(spv, 0x40000);
    D_001D5630 = D_001A1ED4[0];
    func_003D9378();
    func_003D94B8();
    D_001D55EC |= 2;
}
/* localdecomp:end func_003D95A8 */

/* localdecomp:start func_003D9618 */
extern u32 *D_001DA050;
extern s32 D_001D55F8;
extern s32 D_001D55FC;
extern u8 D_001D3650[];
extern u8 D_001D3EF0[];
void func_003D9618(void) {
    D_001DA050[0] = (D_001D55F8 >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D3650;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55F8 >> 4) | 0x50000000;
    D_001DA050 += 4;
    D_001DA050[0] = (D_001D55FC >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D3EF0;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55FC >> 4) | 0x50000000;
    D_001DA050 += 4;
}
/* localdecomp:end func_003D9618 */

/* localdecomp:start func_003D96F0 */
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0;
extern S_1CFEC0 D_1CFEC0;
extern s32 D_001D5604;
extern s32 D_001D5600;
extern void func_003D80E8();
extern void func_003D95A8();
void func_003D96F0(void) {
    S_1CFEC0 *p = &D_1CFEC0;
    D_001D5600 = p->h150;
    D_001D5604 = p->h152;
    func_003D80E8();
    func_003D95A8();
}
/* localdecomp:end func_003D96F0 */
