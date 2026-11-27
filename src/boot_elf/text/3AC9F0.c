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
extern void *func_003AA070();
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

typedef struct { u8 p0[0xB0]; f32 fB0; } S_225980_3A7090;
extern S_225980_3A7090 D_00225900_003AC9F0;
extern s32 D_001D5C78;
extern s32 D_001D52F0;
extern s32 func_003AA068();
extern void func_003AA060(s32);
extern s32 func_003AB260();
extern void func_003877A0();
extern void func_003AA6D8_003AC9F0(s32, f32, f32, s32, f32, f32, f32);
/* localdecomp:start func_003AC9F0 */
void func_003AC9F0(s32 object, s32 alpha, s32 rgb, f32 top, f32 bottom, f32 left, f32 right)
{
    extern s32 func_003AA068();
    extern void func_003AA060(s32);
    extern s32 func_003AB260();
    extern void func_003877A0();
    extern void func_003AA6D8_003AC9F0(s32, f32, f32, s32, f32, f32, f32);
    s32 saved = func_003AA068();
    f32 old, factor, scale, x0, x1, one, neg;
    s32 *parts;
    func_003AA060(0);
    if (D_001D5C78) {
        old = D_00225900_003AC9F0.fB0;
        D_00225900_003AC9F0.fB0 = 0.6200000047683716f;
        one = 1.0f;
        func_003877A0();
        scale = one;
        factor = (bottom - top - 26.0f) / 112.0f;
        factor = factor * 0.3110000193119049f + 0.03750000149011612f;
        if (func_003AB260() == 1) scale = 0.8999999761581421f;
        parts = (s32 *)((u8 *)object + 0x5100);
        neg = -1.0f;
        alpha <<= 24;
        alpha |= rgb;
        func_003AA6D8_003AC9F0(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), left, top, alpha, neg, scale, factor);
        x0 = left + 16.0f;
        parts = (s32 *)((u8 *)parts + (D_001D52F0 << 2));
        func_003AA6D8_003AC9F0(*parts, right, top, alpha, one, scale, factor);
        x1 = right - 16.0f;
        factor = (right - left - 150.0f) / 306.0f;
        factor = factor * 0.43300002813339233f + 0.10199999809265137f;
        parts = (s32 *)((u8 *)object + 0x5110);
        func_003AA6D8_003AC9F0(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), x0, top, alpha, neg, one, factor);
        func_003AA6D8_003AC9F0(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), x1, top, alpha, one, one, factor);
        func_003AA6D8_003AC9F0(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), x0, bottom, alpha, neg, neg, factor);
        parts = (s32 *)((u8 *)parts + (D_001D52F0 << 2));
        func_003AA6D8_003AC9F0(*parts, x1, bottom, alpha, one, neg, factor);
        D_00225900_003AC9F0.fB0 = old;
        func_003877A0();
        func_003AA060(saved);
    }
}
/* localdecomp:end func_003AC9F0 */
