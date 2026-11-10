/* near miss (level 3, Starship Phoenix): 157 differences from scheduling and register allocation (every call and argument matches, needs @ps2as which the file has): retail saves s2 then s3 and keeps the arg0->f68 pointer in s3, the C keeps it in s2; retail reloads D_L03_001E0B24 for each of two (int)(f*256+0.5f+0.0f) style arguments with dead lw D_L03_001E0B20 loads between them, the C interleaves them; locals, a static inline helper and 0.0f*D did not help (4 compiles only) */
#include "common.h"

/* localdecomp:start func_L03_00330530 */
typedef struct S_00330530 { u8 pad00[0x68]; u8 *f68; } S_00330530;
extern s32 func_00381FF0(s32);
extern void func_0011B2E8();
extern void func_003910C0(u16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_0038FA18(u16 *, long, char *, s32, unsigned long, f32, f32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern u8 D_L03_001DD168[];
extern u8 D_L03_001DD170[];
extern f32 D_L03_001E0B24;
extern s32 D_L03_001E0B20;
extern s32 D_001D4BC8;
__asm__(".extern D_001D4BC8, 16");
extern s32 D_L03_001D64E8;

void func_L03_00330530(S_00330530 *arg0) {
    char buf[0x400];
    u16 m[16];
    s32 *s1 = (s32 *)arg0->f68;
    s32 s = s1[0x108 / 4];
    s32 h, w;
    s32 xx, yy;

    if (s == -1) return;
    if (s == -2) {
        func_0011B2E8(buf, D_L03_001DD168, func_00381FF0(0x269));
    } else if (s == 0) {
        func_0011B2E8(buf, D_L03_001DD168, func_00381FF0(0x58B));
    } else {
        s32 a = func_00381FF0(0x269);
        s32 b = func_00381FF0(0x125C);
        s32 c = func_00381FF0(0x282);
        func_0011B2E8(buf, D_L03_001DD170, a, b, s1[0x108 / 4], c);
    }
    m[12] = 2;
    m[13] = 2;
    xx = (s32)(D_L03_001E0B24 * 256.0f + 0.5f + 0.0f);
    yy = (s32)(D_L03_001E0B24 * 384.0f + 0.5f + 0.0f);
    func_003910C0(m, xx, yy, D_001D4BC8 - 0x90, D_001D4BC8 + 0x90, D_001D4BC8, 0x140, 0x10, 1, 0x27);
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
    w = ((s16)m[6] >> 1) + 8;
    h = ((s16)m[7] >> 1) + 8;
    func_0038C3B0(((s16)m[5]) - h, ((s16)m[5]) + h, ((s16)m[4]) - w, ((s16)m[4]) + w, 0x33, 0x331465B7);
    func_L01_00436020(0x33, 0x332299DE, (s16)m[5] - h, (s16)m[5] + h, (s16)m[4] - w, (s16)m[4] + w);
    m[9] &= 0xFFFB;
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
    D_L03_001D64E8 = 1;
}
/* localdecomp:end func_L03_00330530 */
