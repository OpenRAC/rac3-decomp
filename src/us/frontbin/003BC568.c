#include "common.h"

/* NTSC-U counterpart of func_003C1A80 (src/frontbin/3C1A80.c): 60 Hz clock (/3600, /60 % 60), countdown in quarters (/4, % 4, * 0.25f) */
/* localdecomp:start func_U_003BC568 */
typedef struct {
    char n0[0x10];
    char n1[0x10];
    char n2[0x10];
    f32 f30;
    s32 f34, f38, f3C, f40, f44, f48, f4C;
    f32 f50;
} S_003BC568;
extern S_003BC568 D_U_002CE0E0;
__asm__(".extern D_U_001D9078, 4");
__asm__(".extern D_U_001D907C, 4");
__asm__(".extern D_U_001D9080, 4");
__asm__(".extern D_U_001D9084, 4");
__asm__(".extern D_U_001D9088, 4");
__asm__(".extern D_U_001D908C, 4");
__asm__(".extern D_U_001D9090, 4");
__asm__(".extern D_U_001D9094, 4");
__asm__(".extern D_U_001D9098, 4");
__asm__(".extern D_U_001D909C, 4");
__asm__(".extern D_U_001D90A0, 4");
__asm__(".extern D_U_001D90A4, 4");
__asm__(".extern D_U_001D90A8, 4");
__asm__(".extern D_U_001D90AC, 4");
__asm__(".extern D_U_001D90B0, 4");
extern f32 D_U_001D9078, D_U_001D907C, D_U_001D9080, D_U_001D9084, D_U_001D9088, D_U_001D908C;
extern f32 D_U_001D9090, D_U_001D9094, D_U_001D9098, D_U_001D909C, D_U_001D90A0, D_U_001D90A4;
extern s32 D_U_001D90A8;
extern f32 D_U_001D90AC, D_U_001D90B0;
__asm__(".extern D_001D4BC4, 16");
__asm__(".extern D_001D4BC0, 16");
extern s32 D_001D4BC4;
extern s32 D_001D4BC0;
extern void func_U_00384B68(s32);
extern void func_U_00384C98(void);
extern void func_U_0038C718(s32, s32, unsigned long, u8 *, s32, f32);
extern char D_U_001D90C8[], D_U_001D90D0[], D_U_001D90D8[];
extern long func_U_00384EC0(s32);
extern void func_U_00386D98(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_U_003869E8(s32, s32, s32, s32, s32, s32, s32, s32, f32, long, long);
extern void func_U_003867F8(s32, s32, s32, s32, long);
extern void func_11B2E8();
extern s32 func_11B868(char *);
extern s32 func_U_0038C510(char *, s32, f32);
extern f32 func_U_003BEB48(f32, f32, f32);

void func_U_003BC568(void) {
    if (D_U_002CE0E0.f40 == 0) {
        s32 h = D_001D4BC4;
        s32 w = D_001D4BC0;
        s32 cx = w / 2;
        s32 cy = h / 2;
        s32 b = D_U_001D907C * (f32)h;
        s32 a = D_U_001D9078 * (f32)h;
        f32 t1, t2, x;
        func_U_00384B68(1);
        func_U_00386D98(0, 0, w, h, 0, 0, 0x100, 0x100, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0x808080, func_U_00384EC0(0x20));
        x = D_U_002CE0E0.f30 + D_U_002CE0E0.f30;
        if (1.0f < x) t1 = 1.0f; else t1 = x;
        x = (D_U_002CE0E0.f30 - 0.5f) * 2.0f;
        if (x < 0.0f) t2 = 0.0f; else t2 = x;
        func_U_003869E8(cx - a / 2, cy - a / 2, a, a, 0, 0, 0x100, 0x100, D_U_002CE0E0.f50, ((s32)(t2 * 128.0f) << 24) | 0x808080, func_U_00384EC0(0x22));
        func_U_003869E8(cx - b / 2, cy - b / 2, b, b, 0, 0, 0x100, 0x100, D_U_001D9080, ((s32)(t1 * 128.0f) << 24) | 0x808080, func_U_00384EC0(0x21));
        func_U_00384C98();
    } else {
        char s10[0x10];
        char s20[0x10];
        char s30[0x10];
        f32 sc11;
        f32 sc;
        s32 cy;
        s32 icon;
        f32 funit;
        s32 left;
        s32 right;
        f32 fw;
        f32 fbw;
        s32 lh;
        s32 cx;
        f32 sc14;
        f32 fh;
        s32 lh2;
        s32 unit;
        s32 lineh;
        s32 bw;
        f32 scale;
        s32 hh, hw;
        s32 h2, w2;
        fh = D_001D4BC4;
        unit = D_U_001D9090 * fh;
        funit = unit;
        fw = D_001D4BC0;
        cy = fh * 0.5f;
        bw = D_U_001D90A4 * funit;
        cx = fw * 0.5f;
        fbw = bw;
        icon = D_U_001D9094 * fbw;
        sc = D_U_001D90B0 * funit;
        left = cx - (s32)((0.5f - D_U_001D9098) * fbw);
        right = cx + (s32)((0.5f - D_U_001D909C) * fbw);
        lh = (f32)((s32)((0.5f - D_U_001D90A0) * funit) + 1) * 0.25f;
        sc14 = sc * 1.4f;
        sc11 = sc * 1.1f;
        lineh = D_U_001D90AC * funit;
        lh2 = lh >> 1;
        func_U_00384B68(1);
        hh = D_001D4BC4;
        hw = D_001D4BC0;
        h2 = hh >> 1;
        w2 = hw >> 1;
        func_U_003867F8(0, hh, 0, hw, (s32)0x80000000);
        func_U_003867F8(h2, h2 + (s32)((0.5f - D_U_001D9084) * funit), w2 - (s32)((0.5f - D_U_001D9088) * fbw), w2 + (s32)((0.5f - D_U_001D908C) * fbw), ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0x400000);
        func_U_00386D98(w2 - (bw >> 1), h2 - (unit >> 1), bw, unit >> 1, 0, 0, 0x100, 0x100, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0x808080, func_U_00384EC0(D_U_002CE0E0.f44 - 7));
        func_U_00386D98(w2 - (bw >> 1), h2, bw, unit >> 1, 0, 0, 0x100, 0x100, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0x808080, func_U_00384EC0(0x16));
        func_11B2E8(s30, D_U_001D90C8, D_U_002CE0E0.f3C / 3600, D_U_002CE0E0.f3C / 60 % 60);
        if (D_U_002CE0E0.f48 < 2) {
            func_11B2E8(s20, D_U_001D90D0);
            scale = sc11;
            func_11B2E8(s10, D_U_001D90D8, D_U_002CE0E0.f34);
        } else if (D_U_002CE0E0.f48 >= 3) {
            func_11B2E8(s20, D_U_001D90D8, D_U_002CE0E0.f38);
            scale = sc11;
            func_11B2E8(s10, D_U_001D90D0);
        } else {
            s32 q = D_U_002CE0E0.f4C / 4;
            s32 v = 0;
            if (D_U_002CE0E0.f34 > 0) v = (f32)D_U_002CE0E0.f38 * (f32)(D_U_002CE0E0.f34 - q) / (f32)D_U_002CE0E0.f34;
            func_11B2E8(s20, D_U_001D90D8, v);
            func_11B2E8(s10, D_U_001D90D8, q);
            scale = func_U_003BEB48(sc11, sc14, (f32)(D_U_002CE0E0.f4C % 4) / 4.0f);
        }
        {
            s32 r2 = right - icon;
            func_U_0038C718(left + (func_U_0038C510(D_U_002CE0E0.n2, func_11B868(D_U_002CE0E0.n2), sc) >> 1), cy + lh2, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0xFFFFFF, D_U_002CE0E0.n2, func_11B868(D_U_002CE0E0.n2), sc);
            func_U_0038C718(r2 - (func_U_0038C510(s30, func_11B868(s30), sc) >> 1), cy + lh2, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0xFFFFFF, s30, func_11B868(s30), sc);
            func_U_0038C718(left + (func_U_0038C510(D_U_002CE0E0.n0, func_11B868(D_U_002CE0E0.n0), sc) >> 1), cy + lh + lh2, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0xFFFFFF, D_U_002CE0E0.n0, func_11B868(D_U_002CE0E0.n0), sc);
            func_U_00386D98(right - (icon >> 1), cy + lh + lh2, icon, icon, 0, 0, 0x40, 0x40, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0x808080, func_U_00384EC0(0x1D));
            func_U_0038C718(r2 - (func_U_0038C510(s10, func_11B868(s10), sc) >> 1), cy + lh + lh2, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0xFFFFFF, s10, func_11B868(s10), sc);
            func_U_00386D98(left, cy + lh * 2 + lh2, right - left, lineh, 0, 0, 1, 1, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0xFFFFFF, func_U_00384EC0(0x16));
            func_U_0038C718(left + (func_U_0038C510(D_U_002CE0E0.n1, func_11B868(D_U_002CE0E0.n1), sc) >> 1), cy + (lh * 2 + lh), ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0xFFFFFF, D_U_002CE0E0.n1, func_11B868(D_U_002CE0E0.n1), sc);
            func_U_00386D98(right - (icon >> 1), cy + (lh * 2 + lh), icon, icon, 0, 0, 0x20, 0x20, ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0x808080, func_U_00384EC0(0x1F));
            func_U_0038C718(right - D_U_001D90A8 - icon - (func_U_0038C510(s20, func_11B868(s20), scale) >> 1), cy + (lh * 2 + lh), ((s32)(D_U_002CE0E0.f30 * 128.0f) << 24) | 0xFFFFFF, s20, func_11B868(s20), scale);
        }
        func_U_00384C98();
    }
}
/* localdecomp:end func_U_003BC568 */
