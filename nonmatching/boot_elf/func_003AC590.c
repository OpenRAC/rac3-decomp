/* Near miss of func_003AC590 with its file's own flags: tools/check.py reports 22 diff
   (the version it replaces: 25).
   What differs: 22 diffs left, all in the callee-saved save/restore area: gcc 2.95.3 puts the
   16-byte slots in descending register order ($ra lowest at 0x210, $s0 highest at 0x2a0) and
   saves $ra with `sd`, where retail has $s0 lowest at 0x210 ascending to $ra highest at 0x2a0
   with `sq`; every other word of the function (prologue body, all code, the epilogue) matches
   retail exactly.
*/

/* US draft of func_003AC590 (rac3-uya-decomp func_003AC3F0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_0038FD40 (PAL: func_0038FDF8). */


/* localdecomp:start func_003AC590 */
typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern char D_001D8388[], D_001D8398[], D_001D83A8[], D_001D83E0[], D_001D8418[], D_001D8420[], D_001D8430[];
extern s32 func_11B2E8();
extern void func_00391510();
extern void func_00391598();
extern void func_0038FDF8();
extern void func_0038C790(s32, s32, s32, s32, s32, s32);
extern void func_003AC9F0(s32, s32, s32, f32, f32, f32, f32);
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
