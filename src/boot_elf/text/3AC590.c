#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3ABF50.c's earlier functions (tools/port_from_us.py) */
extern void func_00121760();
extern void func_003AA070();
extern char D_001D8230[];
extern char D_001D8270[];
extern char D_001D82A0[];
extern s32 D_001D5C84;
typedef struct { s32 k, v; } E_3A6830;
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D82F8[];
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D8320[];
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;
extern u8 *func_003AB5D0(u8 *);
typedef struct {
    s32 *p0; s32 *p4; s32 *p8; s32 *pC;
    u8 sub10[0x3C]; u8 sub4C[0x3C]; u8 b88; u8 pad89[0x188 - 0x89];
    s32 f188, f18C, f190; u8 pad194[4]; s32 f198; u8 pad19C[8];
    s32 f1A4, f1A8, f1AC; u8 pad1B0[4]; s32 f1B4; u8 f1B8[0x78];
} O_3A6A00;
extern s32 D_001D5C78;
extern u8 D_001D8370[], D_001D8380[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2740(s32, s32);
extern void func_003AB608();
extern void func_003AB7E0(u8 *, u8 *, s32);
extern void func_003AB810(void *, f32);
extern void func_003AB2B8(void *, s32);
extern s32 func_003AB270(void *);

typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern char D_001D8388[], D_001D8398[], D_001D83A8[], D_001D83E0[], D_001D8418[], D_001D8420[], D_001D8430[];
extern s32 func_11B2E8();
extern void func_00391510();
extern void func_00391598();
extern void func_0038C790(s32, s32, s32, s32, s32, s32);
extern void func_003AC9F0(s32, s32, s32, f32, f32, f32, f32);
/* localdecomp:start func_003AC590 */
extern void func_0038FDF8();
void func_003AC590(s32 a0, W_3A6C30 *p, s32 a2, s32 a3, s32 mode, s32 center, s32 a6, s32 a7, s32 x, s32 y, u8 b) {
    char buf[0x200];
    s32 saved = (s16)p->h12;
    s32 dx, dy, l, r, t, bo, cx, cy;
    p->h12 |= 3;
    if (x != 0) {
        if (y != 0) {
            if (b != 0) {
                if (a7 != 0) func_11B2E8(buf, D_001D8388, a3, 1, x, 1, y);
                else func_11B2E8(buf, D_001D8398, a3, 1, 1, x, 1, y);
            } else {
                if (a7 != 0) func_11B2E8(buf, D_001D83A8, a3, 1, x, y);
                else func_11B2E8(buf, D_001D83E0, a3, 1, 1, x, y);
            }
        } else {
            if (a7 != 0) func_11B2E8(buf, D_001D8418, a3, 1, x);
            else func_11B2E8(buf, D_001D8420, a3, 1, 1, x);
        }
    } else {
        func_11B2E8(buf, D_001D8430, a3);
    }
    p->h12 |= 4;
    switch (mode) {
    case 0: func_00391510(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FDF8)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_00391598(p, a2, buf, a6); break;
    }
    if (center != 0) {
        s32 c = (*(s32 *)0x1D4BC4 - p->hE) >> 1;
        p->h0 = c;
        p->h2 = p->h0 + p->hE;
        p->hA = c + (p->hE >> 1);
    }
    switch (mode) {
    case 0: func_00391510(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FDF8)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_00391598(p, a2, buf, a6); break;
    }
    dx = (p->hC >> 1) + 10;
    dy = (p->hE >> 1) + 5;
    p->h12 &= ~4;
    cx = p->h8;
    cy = p->hA;
    t = cy - dy;
    l = cx - dx;
    r = cx + dx;
    bo = cy + dy;
    func_0038C790(t, bo, l, r, 0x60, 0x600E5092);
    func_003AC9F0(a0, 0x60, 0x332299DE, t, bo, l, r);
    p->h18 = 2;
    p->h12 |= 0x20;
    p->h1A = 2;
    switch (mode) {
    case 0: func_00391510(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FDF8)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_00391598(p, a2, buf, a6); break;
    }
    p->h12 = saved;
}
/* localdecomp:end func_003AC590 */
