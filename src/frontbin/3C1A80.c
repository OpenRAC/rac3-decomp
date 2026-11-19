#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3C0CA0.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_00389240();
extern void func_00389370();

/* localdecomp:start func_003C1A80 */
typedef struct {
    char n0[0x10];
    char n1[0x10];
    char n2[0x10];
    f32 f30;
    s32 f34, f38, f3C, f40, f44, f48, f4C;
    f32 f50;
} S_003C1A80;
extern S_003C1A80 D_002D2060_003C1A80;
__asm__(".extern D_001D9048, 4");
__asm__(".extern D_001D904C, 4");
__asm__(".extern D_001D9050, 4");
__asm__(".extern D_001D9054, 4");
__asm__(".extern D_001D9058, 4");
__asm__(".extern D_001D905C, 4");
__asm__(".extern D_001D9060, 4");
__asm__(".extern D_001D9064, 4");
__asm__(".extern D_001D9068, 4");
__asm__(".extern D_001D906C, 4");
__asm__(".extern D_001D9070, 4");
__asm__(".extern D_001D9074, 4");
__asm__(".extern D_001D9078, 4");
__asm__(".extern D_001D907C, 4");
__asm__(".extern D_001D9080, 4");
extern f32 D_001D9048, D_001D904C, D_001D9050, D_001D9054, D_001D9058, D_001D905C;
extern f32 D_001D9060, D_001D9064, D_001D9068, D_001D906C, D_001D9070, D_001D9074;
extern s32 D_001D9078;
extern f32 D_001D907C, D_001D9080;
__asm__(".extern D_001D4BC4, 16");
__asm__(".extern D_001D4BC0, 16");
extern s32 D_001D4BC4;
extern s32 D_001D4BC0;
extern void func_00389240(s32);
extern void func_00389370(void);
extern void func_00390F50(s32, s32, unsigned long, u8 *, s32, f32);
extern char D_001D9098[], D_001D90A0[], D_001D90A8[];
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_0038B120(s32, s32, s32, s32, s32, s32, s32, s32, f32, long, long);
extern void func_0038AF30(s32, s32, s32, s32, long);
extern void func_11B2E8();
extern s32 func_11B868(char *);
extern s32 func_00390D48(char *, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

/* from rac3-decomp NTSC-U's func_003BC568 */
void func_003C1A80(void) {
    if (D_002D2060_003C1A80.f40 == 0) {
        s32 h = D_001D4BC4;
        s32 w = D_001D4BC0;
        s32 cx = w / 2;
        s32 cy = h / 2;
        s32 b = D_001D904C * (f32)h;
        s32 a = D_001D9048 * (f32)h;
        f32 t1, t2, x;
        func_00389240(1);
        func_0038B4D0(0, 0, w, h, 0, 0, 0x100, 0x100, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0x808080, func_00389598(0x20));
        x = D_002D2060_003C1A80.f30 + D_002D2060_003C1A80.f30;
        if (1.0f < x) t1 = 1.0f; else t1 = x;
        x = (D_002D2060_003C1A80.f30 - 0.5f) * 2.0f;
        if (x < 0.0f) t2 = 0.0f; else t2 = x;
        func_0038B120(cx - a / 2, cy - a / 2, a, a, 0, 0, 0x100, 0x100, D_002D2060_003C1A80.f50, ((s32)(t2 * 128.0f) << 24) | 0x808080, func_00389598(0x22));
        func_0038B120(cx - b / 2, cy - b / 2, b, b, 0, 0, 0x100, 0x100, D_001D9050, ((s32)(t1 * 128.0f) << 24) | 0x808080, func_00389598(0x21));
        func_00389370();
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
        unit = D_001D9060 * fh;
        funit = unit;
        fw = D_001D4BC0;
        cy = fh * 0.5f;
        bw = D_001D9074 * funit;
        cx = fw * 0.5f;
        fbw = bw;
        icon = D_001D9064 * fbw;
        sc = D_001D9080 * funit;
        left = cx - (s32)((0.5f - D_001D9068) * fbw);
        right = cx + (s32)((0.5f - D_001D906C) * fbw);
        lh = (f32)((s32)((0.5f - D_001D9070) * funit) + 1) * 0.25f;
        sc14 = sc * 1.4f;
        sc11 = sc * 1.1f;
        lineh = D_001D907C * funit;
        lh2 = lh >> 1;
        func_00389240(1);
        hh = D_001D4BC4;
        hw = D_001D4BC0;
        h2 = hh >> 1;
        w2 = hw >> 1;
        func_0038AF30(0, hh, 0, hw, (s32)0x80000000);
        func_0038AF30(h2, h2 + (s32)((0.5f - D_001D9054) * funit), w2 - (s32)((0.5f - D_001D9058) * fbw), w2 + (s32)((0.5f - D_001D905C) * fbw), ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0x400000);
        func_0038B4D0(w2 - (bw >> 1), h2 - (unit >> 1), bw, unit >> 1, 0, 0, 0x100, 0x100, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0x808080, func_00389598(D_002D2060_003C1A80.f44 - 7));
        func_0038B4D0(w2 - (bw >> 1), h2, bw, unit >> 1, 0, 0, 0x100, 0x100, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0x808080, func_00389598(0x16));
        func_11B2E8(s30, D_001D9098, D_002D2060_003C1A80.f3C / 3000, D_002D2060_003C1A80.f3C / 50 % 60);
        if (D_002D2060_003C1A80.f48 < 2) {
            func_11B2E8(s20, D_001D90A0);
            scale = sc11;
            func_11B2E8(s10, D_001D90A8, D_002D2060_003C1A80.f34);
        } else if (D_002D2060_003C1A80.f48 >= 3) {
            func_11B2E8(s20, D_001D90A8, D_002D2060_003C1A80.f38);
            scale = sc11;
            func_11B2E8(s10, D_001D90A0);
        } else {
            s32 q = D_002D2060_003C1A80.f4C / 3;
            s32 v = 0;
            if (D_002D2060_003C1A80.f34 > 0) v = (f32)D_002D2060_003C1A80.f38 * (f32)(D_002D2060_003C1A80.f34 - q) / (f32)D_002D2060_003C1A80.f34;
            func_11B2E8(s20, D_001D90A8, v);
            func_11B2E8(s10, D_001D90A8, q);
            scale = func_003C4088(sc11, sc14, (f32)(D_002D2060_003C1A80.f4C % 3) / 3.0f);
        }
        {
            s32 r2 = right - icon;
            func_00390F50(left + (func_00390D48(D_002D2060_003C1A80.n2, func_11B868(D_002D2060_003C1A80.n2), sc) >> 1), cy + lh2, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0xFFFFFF, D_002D2060_003C1A80.n2, func_11B868(D_002D2060_003C1A80.n2), sc);
            func_00390F50(r2 - (func_00390D48(s30, func_11B868(s30), sc) >> 1), cy + lh2, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0xFFFFFF, s30, func_11B868(s30), sc);
            func_00390F50(left + (func_00390D48(D_002D2060_003C1A80.n0, func_11B868(D_002D2060_003C1A80.n0), sc) >> 1), cy + lh + lh2, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0xFFFFFF, D_002D2060_003C1A80.n0, func_11B868(D_002D2060_003C1A80.n0), sc);
            func_0038B4D0(right - (icon >> 1), cy + lh + lh2, icon, icon, 0, 0, 0x40, 0x40, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0x808080, func_00389598(0x1D));
            func_00390F50(r2 - (func_00390D48(s10, func_11B868(s10), sc) >> 1), cy + lh + lh2, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0xFFFFFF, s10, func_11B868(s10), sc);
            func_0038B4D0(left, cy + lh * 2 + lh2, right - left, lineh, 0, 0, 1, 1, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0xFFFFFF, func_00389598(0x16));
            func_00390F50(left + (func_00390D48(D_002D2060_003C1A80.n1, func_11B868(D_002D2060_003C1A80.n1), sc) >> 1), cy + (lh * 2 + lh), ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0xFFFFFF, D_002D2060_003C1A80.n1, func_11B868(D_002D2060_003C1A80.n1), sc);
            func_0038B4D0(right - (icon >> 1), cy + (lh * 2 + lh), icon, icon, 0, 0, 0x20, 0x20, ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0x808080, func_00389598(0x1F));
            func_00390F50(right - D_001D9078 - icon - (func_00390D48(s20, func_11B868(s20), scale) >> 1), cy + (lh * 2 + lh), ((s32)(D_002D2060_003C1A80.f30 * 128.0f) << 24) | 0xFFFFFF, s20, func_11B868(s20), scale);
        }
        func_00389370();
    }
}
/* localdecomp:end func_003C1A80 */
TEXT_PADDING(2);
