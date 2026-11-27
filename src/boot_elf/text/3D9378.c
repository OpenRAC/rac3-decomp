#include "common.h"
#include "vu0.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D96F0(void);
/* --- end of declarations from other files --- */

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
