/* Near miss of func_003AC1D8 with its file's own flags: tools/check.py reports 27 diff
   (the version it replaces: 30).
   What differs: The C body now matches retail exactly (the mode-1 draw call is PAL's
   func_0038FA18, not the US func_0038B1E8: that fixed the last 3 diffs, 30 -> 27). All 27
   remaining diffs are the callee-saved save/restore area, which the file's own flags decide,
   not the C: retail keeps the 10 saved registers ($s0-$s7, $fp, $ra) in 16-byte slots saved
   with sq/lq (frame 0x2B0, slots 0x210..0x2A0 ascending, $ra highest), while -fopt-stack (SN-
   only cc1 option "Optimise stack frame") packs the same 10 registers into 8-byte slots saved
   with sd/ld (frame 0x260, slots 0x210..0x258); the three incoming...
*/

/* func_003AC1D8 (frontbin, PAL 0x003AC1D8): US draft of rac3-uya-decomp func_003A6C30
   (commit 13cf5c5) with PAL call targets.
   PAL difference: the mode-1 draw call is func_0038FA18 (US func_0038B1E8); the mode-0 and
   mode-2 calls are func_00391130 / func_003911B8 (US func_0038C8F8 / func_0038C980). */

/* localdecomp:start func_003AC1D8 */
typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern char D_001D8388[], D_001D8398[], D_001D83A8[], D_001D83E0[], D_001D8418[], D_001D8420[], D_001D8430[];
extern s32 func_11B2E8();
extern void func_00391130();
extern void func_003911B8();
extern void func_0038FA18();
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_003AC638(s32, s32, s32, f32, f32, f32, f32);
void func_003AC1D8(s32 a0, W_3A6C30 *p, s32 a2, s32 a3, s32 mode, s32 center, s32 a6, s32 a7, s32 x, s32 y, u8 b) {
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
    case 0: func_00391130(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FA18)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_003911B8(p, a2, buf, a6); break;
    }
    if (center != 0) {
        s32 c = (*(s32 *)0x1D4BC4 - p->hE) >> 1;
        p->h0 = c;
        p->h2 = p->h0 + p->hE;
        p->hA = c + (p->hE >> 1);
    }
    switch (mode) {
    case 0: func_00391130(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FA18)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_003911B8(p, a2, buf, a6); break;
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
    func_0038C3B0(t, bo, l, r, 0x60, 0x600E5092);
    func_003AC638(a0, 0x60, 0x332299DE, t, bo, l, r);
    p->h18 = 2;
    p->h12 |= 0x20;
    p->h1A = 2;
    switch (mode) {
    case 0: func_00391130(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FA18)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_003911B8(p, a2, buf, a6); break;
    }
    p->h12 = saved;
}
/* localdecomp:end func_003AC1D8 */
