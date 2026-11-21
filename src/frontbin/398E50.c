#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00398E50(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00398E50 */
typedef struct { s32 off; s32 size; } E_94060;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060 e[5]; } B_94060;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060;
extern B_94060 *D_001D4B50_00398E50;
extern G_94060 *D_001D9EA0_00398E50;
extern s32 D_001D9EC8[5];
extern u8 D_001D5F50[];
extern u8 D_001D5F60[];
extern u8 D_001D5F70[];
extern u8 D_001D5F80[];
extern u8 D_001D5F90[];
extern s32 D_001D9EA4;
extern s32 D_001D9EA8;
extern s32 D_001D9EAC;
extern s32 D_001D9EB0;
extern Q_94060 D_00227580[];
extern s32 func_003932C0();
extern void func_0038CD28();
extern void func_003990F0();
extern s32 func_003A8678();
extern void func_00393168();
extern void func_11F0A0();
extern void func_00392FD0();
extern void func_00393138();
void func_00398E50(void) {
    B_94060 *b;
    s32 *h;
    s32 *q;
    s32 i;
    s32 r, x, t;
    b = D_001D4B50_00398E50;
    for (i = 0; i < 5; i++) {
        D_001D9EC8[i] = (b->e[i].size + 0x3F) & 0xFFFFFFC0;
    }
    r = (b->f1C + 0x3F) & 0xFFFFFFC0;
    q = (s32 *)D_00227580;
    h = (s32 *)func_003932C0(r, 0, D_001D5F50, 0x39E);
    func_0038CD28(h, (void *)(b->f18 + (s32)b), r);
    x = q[4] + 0x30000;
    D_001D9EA0_00398E50 = (G_94060 *)h;
    D_001D9EA4 = (s32)h + h[1];
    D_001D9EA8 = (s32)h + h[2];
    D_001D9EB0 = (s32)h + h[3];
    D_001D9EAC = (s32)h + h[4];
    if (h[0x15]) {
        u32 s = (u32)((b->e[0].size + 0x3F) & 0xFFFFFFC0) >> 4;
        func_003990F0(0, x);
        D_001D9EA0_00398E50->f94 = func_003A8678((void *)(b->e[0].off + (s32)b), s, s, D_001D5F60);
        func_00393168(0, x, 1);
    }
    if (D_001D9EA0_00398E50->f58) {
        t = func_003932C0(D_001D9EA0_00398E50->f58, 0, D_001D5F50, 0x3CE);
        func_003990F0(1, t);
        func_11F0A0(0);
        func_00392FD0(1, t);
    }
    if (D_001D9EA0_00398E50->f5C) {
        s32 s = ((b->e[2].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        D_001D9EA0_00398E50->f9C = func_003A8678((void *)(b->e[2].off + (s32)b), s, s, D_001D5F70);
    }
    if (D_001D9EA0_00398E50->f60) {
        s32 s = ((b->e[3].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        D_001D9EA0_00398E50->fA0 = func_003A8678((void *)(b->e[3].off + (s32)b), s, s, D_001D5F80);
    }
    if (D_001D9EA0_00398E50->f64) {
        s32 s = ((b->e[4].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        D_001D9EA0_00398E50->fA4 = func_003A8678((void *)(b->e[4].off + (s32)b), s, s, D_001D5F90);
    }
    func_00393138();
}
/* localdecomp:end func_00398E50 */
