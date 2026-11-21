#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AF2A0.c's earlier functions */
extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern void func_003AFFA8();
extern void func_003AFDD0();

extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA088_003AFDD0;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA09C_003AFDD0;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA0B0_003AFDD0;
extern s32 D_001DA0B4_003AFDD0;
extern s32 D_001DA0B8_003AFDD0;
extern s32 D_001DA0C8_003AFDD0;
extern u8 D_001DC8B0[1];
extern void func_003B1308();
extern void func_135B50();
extern s32 func_003B2478(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003B0070_003AFDD0();
extern void func_003B2580_003AFDD0();
extern void func_003B0FF0_003AFDD0();
extern void func_003B1108_003AFDD0();
extern void func_003B2BF8();
extern void func_003B27C8();
extern s32 func_11EC20();
extern void func_11FD40();
extern void func_003B1400_003AFDD0();
extern void func_12D4D8();
extern void func_003B0D60();
extern s32 func_11EB30();
extern void func_003B0F50();
extern void func_11F9A8();
typedef struct { s32 f0; void *f4; s32 f8; s32 fC; void *f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 pad[3]; } S_3AA828;
/* localdecomp:start func_003AFDD0 */
/* from boot_elf's twin func_003B0188 (names through config/frontend_pairs.tsv) */
void func_003AFDD0(s32 a, s32 b, s32 c) {
    S_3AA828 s;
    s32 t;
    *(volatile u32 *)0x1000E000 |= 3;
    *(volatile u32 *)0x1000E010 = 4;
    func_003B1308(D_001DA09C_003AFDD0);
    func_135B50();
    func_003B2478(D_001DA0B4_003AFDD0, D_001DA098, 0xEC800, D_001DA0A4, D_001DA094, 0x100, D_001DA0AC, 0x200);
    func_003B0070_003AFDD0(D_001DA0B8_003AFDD0, D_001DA0A0, 0xC000, 3);
    func_003B2580_003AFDD0(D_001DA0B4_003AFDD0, 0, 0, func_003B0FF0_003AFDD0, D_001DA09C_003AFDD0);
    func_003B2580_003AFDD0(D_001DA0B4_003AFDD0, 3, c, func_003B1108_003AFDD0, D_001DA09C_003AFDD0);
    func_003B2BF8(D_001DA088_003AFDD0, (D_001DA08C & 0xFFFFFFF) | 0x20000000, D_001DA090, 2);
    s.f4 = func_003B27C8;
    s.fC = 0x4000;
    s.f14 = 1;
    s.f10 = D_001DC8B0;
    s.f20 = 0;
    s.f8 = D_001DA0A8;
    t = func_11EC20(&s);
    D_001DA0C8_003AFDD0 = t;
    func_11FD40(t, D_001DA0B4_003AFDD0);
    func_003B1400_003AFDD0(D_001DA0B0_003AFDD0, a, b);
    func_12D4D8(func_003B0D60);
    t = func_11EB30(2, func_003B0F50, 0);
    *(s32 *)(D_001DA0B4_003AFDD0 + 0xB0) = t;
    func_11F9A8(2);
}
/* localdecomp:end func_003AFDD0 */

typedef struct { u8 pad[0xB0]; s32 wB0; } S_AAA00;
extern void *D_001DA09C;
extern void *D_001DA088;
extern void *D_001DA0C8;
extern S_AAA00 *D_001DA0B4;
extern void *D_001DA0B8_003AFFA8;
extern void *D_001DA0B0;
extern u8 D_0013D208[];
extern s32 func_003B1320();
extern s32 func_003B2C50();
extern void func_11EC70(void *);
extern void func_11EC30(void *);
extern void func_11EB50(s32, s32);
extern void func_12D4D8(u8 *);
extern s32 func_003B25E8();
extern s32 func_003B0108();
extern s32 func_003B1418();
/* localdecomp:start func_003AFFA8 */
/* func_003AFFA8 (frontbin). From boot_elf's func_003B0360 (its twin) */
/* Log: PAL draft (arrays for the lui globals, literal 0x13D208): 2 diff with the file's flags.
 * Plain declarations of the file: MATCH with --mode S --as ps2as only. In mode N (the file's
 * flags) D_0013D208's address is one `la` macro that gcc cannot put in the jal delay slot
 * (19 diff, tried small/sized/.data/.sdata aliases). The lui form of D_001DA09C and the
 * first D_001DA0B4 comes from Ps2EeAs (late .extern sizes), not from the C. */
extern s32 func_11F940(s32);
/* from boot_elf's func_003B0360 */
void func_003AFFA8(void) {
    func_003B1320(D_001DA09C);
    func_003B2C50(D_001DA088);
    func_11EC70(D_001DA0C8);
    func_11EC30(D_001DA0C8);
    func_11F940(2);
    func_11EB50(2, D_001DA0B4->wB0);
    func_12D4D8(D_0013D208);
    func_003B25E8(D_001DA0B4);
    func_003B0108(D_001DA0B8_003AFFA8);
    func_003B1418(D_001DA0B0);
    *(volatile u32 *)0x1000E000 &= ~2;
}
/* localdecomp:end func_003AFFA8 */

/* localdecomp:start func_003B0040 */
s32 func_003B0040(void) {
}
/* localdecomp:end func_003B0040 */
